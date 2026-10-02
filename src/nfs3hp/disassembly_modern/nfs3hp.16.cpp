#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_452db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452db0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452db1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452db2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452db4  e8f780ffff             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00452db9  ba0c965300             -mov edx, 0x53960c
    cpu.edx = 5477900 /*0x53960c*/;
    // 00452dbe  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00452dc1  e8fa700900             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 00452dc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452dc8  7508                   -jne 0x452dd2
    if (!cpu.flags.zf)
    {
        goto L_0x00452dd2;
    }
    // 00452dca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452dcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452dd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452dd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00452dd2:
    // 00452dd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00452dd4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452dd5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452dd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_452de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452de0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452de1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452de2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452de4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00452de6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00452de8  83f901                 +cmp ecx, 1
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
    // 00452deb  0f825e000000           -jb 0x452e4f
    if (cpu.flags.cf)
    {
        goto L_0x00452e4f;
    }
    // 00452df1  7608                   -jbe 0x452dfb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00452dfb;
    }
    // 00452df3  83f903                 +cmp ecx, 3
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
    // 00452df6  744b                   -je 0x452e43
    if (cpu.flags.zf)
    {
        goto L_0x00452e43;
    }
    // 00452df8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452df9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452dfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00452dfb:
    // 00452dfb  e8c018ffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 00452e00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452e02  7522                   -jne 0x452e26
    if (!cpu.flags.zf)
    {
        goto L_0x00452e26;
    }
    // 00452e04  e8a7ffffff             -call 0x452db0
    cpu.esp -= 4;
    sub_452db0(app, cpu);
    if (cpu.terminate) return;
    // 00452e09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452e0b  7407                   -je 0x452e14
    if (cpu.flags.zf)
    {
        goto L_0x00452e14;
    }
    // 00452e0d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452e12  eb05                   -jmp 0x452e19
    goto L_0x00452e19;
L_0x00452e14:
    // 00452e14  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00452e19:
    // 00452e19  a394e85500             -mov dword ptr [0x55e894], eax
    app->getMemory<x86::reg32>(x86::reg32(5630100) /* 0x55e894 */) = cpu.eax;
    // 00452e1e  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00452e23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00452e26:
    // 00452e26  83f801                 +cmp eax, 1
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
    // 00452e29  7509                   -jne 0x452e34
    if (!cpu.flags.zf)
    {
        goto L_0x00452e34;
    }
    // 00452e2b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00452e2d  740c                   -je 0x452e3b
    if (cpu.flags.zf)
    {
        goto L_0x00452e3b;
    }
    // 00452e2f  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 00452e32  eb07                   -jmp 0x452e3b
    goto L_0x00452e3b;
L_0x00452e34:
    // 00452e34  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00452e36  7403                   -je 0x452e3b
    if (cpu.flags.zf)
    {
        goto L_0x00452e3b;
    }
    // 00452e38  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x00452e3b:
    // 00452e3b  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00452e40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00452e43:
    // 00452e43  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00452e45  7403                   -je 0x452e4a
    if (cpu.flags.zf)
    {
        goto L_0x00452e4a;
    }
    // 00452e47  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x00452e4a:
    // 00452e4a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00452e4f:
    // 00452e4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_452e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452e62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452e63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452e64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452e66  e825c90400             -call 0x49f790
    cpu.esp -= 4;
    sub_49f790(app, cpu);
    if (cpu.terminate) return;
    // 00452e6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452e6d  7509                   -jne 0x452e78
    if (!cpu.flags.zf)
    {
        goto L_0x00452e78;
    }
    // 00452e6f  e80cca0400             -call 0x49f880
    cpu.esp -= 4;
    sub_49f880(app, cpu);
    if (cpu.terminate) return;
    // 00452e74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452e76  7458                   -je 0x452ed0
    if (cpu.flags.zf)
    {
        goto L_0x00452ed0;
    }
L_0x00452e78:
    // 00452e78  b8c0010000             -mov eax, 0x1c0
    cpu.eax = 448 /*0x1c0*/;
    // 00452e7d  e8cee90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452e82  a360466600             -mov dword ptr [0x664660], eax
    app->getMemory<x86::reg32>(x86::reg32(6702688) /* 0x664660 */) = cpu.eax;
    // 00452e87  b8c1010000             -mov eax, 0x1c1
    cpu.eax = 449 /*0x1c1*/;
    // 00452e8c  e8bfe90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452e91  a364466600             -mov dword ptr [0x664664], eax
    app->getMemory<x86::reg32>(x86::reg32(6702692) /* 0x664664 */) = cpu.eax;
    // 00452e96  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 00452e9b  e8b0e90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452ea0  a36c466600             -mov dword ptr [0x66466c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702700) /* 0x66466c */) = cpu.eax;
    // 00452ea5  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 00452eaa  e8a1e90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452eaf  68e02d4500             -push 0x452de0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4533728 /*0x452de0*/;
    cpu.esp -= 4;
    // 00452eb4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452eb6  b96c466600             -mov ecx, 0x66466c
    cpu.ecx = 6702700 /*0x66466c*/;
    // 00452ebb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452ebd  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00452ec2  ba60466600             -mov edx, 0x664660
    cpu.edx = 6702688 /*0x664660*/;
    // 00452ec7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452ec9  a370466600             -mov dword ptr [0x664670], eax
    app->getMemory<x86::reg32>(x86::reg32(6702704) /* 0x664670 */) = cpu.eax;
    // 00452ece  eb38                   -jmp 0x452f08
    goto L_0x00452f08;
L_0x00452ed0:
    // 00452ed0  b8c2010000             -mov eax, 0x1c2
    cpu.eax = 450 /*0x1c2*/;
    // 00452ed5  e876e90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452eda  a360466600             -mov dword ptr [0x664660], eax
    app->getMemory<x86::reg32>(x86::reg32(6702688) /* 0x664660 */) = cpu.eax;
    // 00452edf  b8f9000000             -mov eax, 0xf9
    cpu.eax = 249 /*0xf9*/;
    // 00452ee4  e867e90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452ee9  68802d4500             -push 0x452d80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4533632 /*0x452d80*/;
    cpu.esp -= 4;
    // 00452eee  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452ef0  b96c466600             -mov ecx, 0x66466c
    cpu.ecx = 6702700 /*0x66466c*/;
    // 00452ef5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452ef7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00452efc  ba60466600             -mov edx, 0x664660
    cpu.edx = 6702688 /*0x664660*/;
    // 00452f01  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452f03  a36c466600             -mov dword ptr [0x66466c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702700) /* 0x66466c */) = cpu.eax;
L_0x00452f08:
    // 00452f08  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00452f0a  e8c117ffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 00452f0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00452f11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_452f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452f20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452f21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452f22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452f23  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452f25  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452f2a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00452f2c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00452f2e  8915b0d36f00           -mov dword ptr [0x6fd3b0], edx
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.edx;
    // 00452f34  89150cd56f00           -mov dword ptr [0x6fd50c], edx
    app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */) = cpu.edx;
    // 00452f3a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00452f3f  891de0227a00           -mov dword ptr [0x7a22e0], ebx
    app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */) = cpu.ebx;
    // 00452f45  668915da227a00         -mov word ptr [0x7a22da], dx
    app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */) = cpu.dx;
    // 00452f4c  e87ffcffff             -call 0x452bd0
    cpu.esp -= 4;
    sub_452bd0(app, cpu);
    if (cpu.terminate) return;
    // 00452f51  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00452f56  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_452f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452f60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452f61  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452f63  e898320400             -call 0x496200
    cpu.esp -= 4;
    sub_496200(app, cpu);
    if (cpu.terminate) return;
    // 00452f68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452f6a  7405                   -je 0x452f71
    if (cpu.flags.zf)
    {
        goto L_0x00452f71;
    }
    // 00452f6c  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
L_0x00452f71:
    // 00452f71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_452f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452f80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452f81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452f82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452f83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00452f84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00452f85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452f86  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452f88  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00452f8a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00452f8c  8b0de0227a00           -mov ecx, dword ptr [0x7a22e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
    // 00452f92  8915b0d36f00           -mov dword ptr [0x6fd3b0], edx
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.edx;
    // 00452f98  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00452f9a  7405                   -je 0x452fa1
    if (cpu.flags.zf)
    {
        goto L_0x00452fa1;
    }
    // 00452f9c  e83f360500             -call 0x4a65e0
    cpu.esp -= 4;
    sub_4a65e0(app, cpu);
    if (cpu.terminate) return;
L_0x00452fa1:
    // 00452fa1  66833dde227a0000       +cmp word ptr [0x7a22de], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004318) /* 0x7a22de */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00452fa9  7430                   -je 0x452fdb
    if (cpu.flags.zf)
    {
        goto L_0x00452fdb;
    }
    // 00452fab  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 00452fb0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00452fb5  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 00452fba  ba74466600             -mov edx, 0x664674
    cpu.edx = 6702708 /*0x664674*/;
    // 00452fbf  e88ce80700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452fc4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452fc6  a374466600             -mov dword ptr [0x664674], eax
    app->getMemory<x86::reg32>(x86::reg32(6702708) /* 0x664674 */) = cpu.eax;
    // 00452fcb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00452fcd  e8ae1affff             -call 0x444a80
    cpu.esp -= 4;
    sub_444a80(app, cpu);
    if (cpu.terminate) return;
    // 00452fd2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00452fd4  66891dde227a00         -mov word ptr [0x7a22de], bx
    app->getMemory<x86::reg16>(x86::reg32(8004318) /* 0x7a22de */) = cpu.bx;
L_0x00452fdb:
    // 00452fdb  ba14965300             -mov edx, 0x539614
    cpu.edx = 5477908 /*0x539614*/;
    // 00452fe0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00452fe2  e859fafeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00452fe7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452fe9  744f                   -je 0x45303a
    if (cpu.flags.zf)
    {
        goto L_0x0045303a;
    }
    // 00452feb  8a152eeb5500           -mov dl, byte ptr [0x55eb2e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */);
    // 00452ff1  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00452ff4  740c                   -je 0x453002
    if (cpu.flags.zf)
    {
        goto L_0x00453002;
    }
    // 00452ff6  c705b8d36f0003000000   -mov dword ptr [0x6fd3b8], 3
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = 3 /*0x3*/;
    // 00453000  eb38                   -jmp 0x45303a
    goto L_0x0045303a;
L_0x00453002:
    // 00453002  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 00453005  742c                   -je 0x453033
    if (cpu.flags.zf)
    {
        goto L_0x00453033;
    }
    // 00453007  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 0045300c  8a1d2feb5500           -mov bl, byte ptr [0x55eb2f]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5630767) /* 0x55eb2f */);
    // 00453012  893db8d36f00           -mov dword ptr [0x6fd3b8], edi
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edi;
    // 00453018  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0045301b  741d                   -je 0x45303a
    if (cpu.flags.zf)
    {
        goto L_0x0045303a;
    }
    // 0045301d  ba2c965300             -mov edx, 0x53962c
    cpu.edx = 5477932 /*0x53962c*/;
    // 00453022  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453024  e817fafeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453029  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045302b  740d                   -je 0x45303a
    if (cpu.flags.zf)
    {
        goto L_0x0045303a;
    }
    // 0045302d  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00453031  eb07                   -jmp 0x45303a
    goto L_0x0045303a;
L_0x00453033:
    // 00453033  c74064202f4500         -mov dword ptr [eax + 0x64], 0x452f20
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4534048 /*0x452f20*/;
L_0x0045303a:
    // 0045303a  ba44965300             -mov edx, 0x539644
    cpu.edx = 5477956 /*0x539644*/;
    // 0045303f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453041  e8faf9feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453046  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453048  7407                   -je 0x453051
    if (cpu.flags.zf)
    {
        goto L_0x00453051;
    }
    // 0045304a  c74064402d4500         -mov dword ptr [eax + 0x64], 0x452d40
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4533568 /*0x452d40*/;
L_0x00453051:
    // 00453051  ba5c965300             -mov edx, 0x53965c
    cpu.edx = 5477980 /*0x53965c*/;
    // 00453056  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453058  e8e3f9feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045305d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045305f  7407                   -je 0x453068
    if (cpu.flags.zf)
    {
        goto L_0x00453068;
    }
    // 00453061  c74064602e4500         -mov dword ptr [eax + 0x64], 0x452e60
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4533856 /*0x452e60*/;
L_0x00453068:
    // 00453068  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045306f  743c                   -je 0x4530ad
    if (cpu.flags.zf)
    {
        goto L_0x004530ad;
    }
    // 00453071  ba14965300             -mov edx, 0x539614
    cpu.edx = 5477908 /*0x539614*/;
    // 00453076  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453078  e8c3f9feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045307d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045307f  7404                   -je 0x453085
    if (cpu.flags.zf)
    {
        goto L_0x00453085;
    }
    // 00453081  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00453085:
    // 00453085  ba44965300             -mov edx, 0x539644
    cpu.edx = 5477956 /*0x539644*/;
    // 0045308a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045308c  e8aff9feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453091  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453093  7404                   -je 0x453099
    if (cpu.flags.zf)
    {
        goto L_0x00453099;
    }
    // 00453095  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00453099:
    // 00453099  ba70965300             -mov edx, 0x539670
    cpu.edx = 5478000 /*0x539670*/;
    // 0045309e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004530a0  e89bf9feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004530a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004530a7  7404                   -je 0x4530ad
    if (cpu.flags.zf)
    {
        goto L_0x004530ad;
    }
    // 004530a9  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004530ad:
    // 004530ad  e82e310400             -call 0x4961e0
    cpu.esp -= 4;
    sub_4961e0(app, cpu);
    if (cpu.terminate) return;
    // 004530b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004530b4  a36c277a00             -mov dword ptr [0x7a276c], eax
    app->getMemory<x86::reg32>(x86::reg32(8005484) /* 0x7a276c */) = cpu.eax;
    // 004530b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4530c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004530c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004530c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004530c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004530c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004530c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004530c5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004530c7  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004530cd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004530cf  e8dc61feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 004530d4  8b3554bb6f00           -mov esi, dword ptr [0x6fbb54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
    // 004530da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004530dc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004530de  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004530e0  7404                   -je 0x4530e6
    if (cpu.flags.zf)
    {
        goto L_0x004530e6;
    }
    // 004530e2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004530e4  eb63                   -jmp 0x453149
    goto L_0x00453149;
L_0x004530e6:
    // 004530e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004530e8  745d                   -je 0x453147
    if (cpu.flags.zf)
    {
        goto L_0x00453147;
    }
    // 004530ea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004530ec  e8cf64feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 004530f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004530f3  7424                   -je 0x453119
    if (cpu.flags.zf)
    {
        goto L_0x00453119;
    }
    // 004530f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004530f7  e89461feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004530fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004530fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004530fe  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453103  6884965300             -push 0x539684
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478020 /*0x539684*/;
    cpu.esp -= 4;
    // 00453108  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0045310e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045310f  e87cc50800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453114  83c414                 +add esp, 0x14
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
    // 00453117  eb1a                   -jmp 0x453133
    goto L_0x00453133;
L_0x00453119:
    // 00453119  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045311a  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 0045311f  6894965300             -push 0x539694
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478036 /*0x539694*/;
    cpu.esp -= 4;
    // 00453124  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0045312a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045312b  e860c50800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453130  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00453133:
    // 00453133  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00453139  e822dd0800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0045313e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453140  7405                   -je 0x453147
    if (cpu.flags.zf)
    {
        goto L_0x00453147;
    }
    // 00453142  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00453147:
    // 00453147  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00453149:
    // 00453149  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045314b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045314c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045314d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045314e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045314f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453150  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_453160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453162  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453163  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453164  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453165  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453167  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0045316d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045316f  e83c61feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453174  8b3554bb6f00           -mov esi, dword ptr [0x6fbb54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
    // 0045317a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045317c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045317e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00453180  7404                   -je 0x453186
    if (cpu.flags.zf)
    {
        goto L_0x00453186;
    }
    // 00453182  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00453184  eb6b                   -jmp 0x4531f1
    goto L_0x004531f1;
L_0x00453186:
    // 00453186  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453188  7508                   -jne 0x453192
    if (!cpu.flags.zf)
    {
        goto L_0x00453192;
    }
    // 0045318a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045318c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045318d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045318e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045318f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453190  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453191  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00453192:
    // 00453192  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00453194  e82764feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00453199  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045319b  7424                   -je 0x4531c1
    if (cpu.flags.zf)
    {
        goto L_0x004531c1;
    }
    // 0045319d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045319f  e8ec60feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004531a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004531a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004531a6  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 004531ab  68a0965300             -push 0x5396a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478048 /*0x5396a0*/;
    cpu.esp -= 4;
    // 004531b0  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004531b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004531b7  e8d4c40800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004531bc  83c414                 +add esp, 0x14
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
    // 004531bf  eb1a                   -jmp 0x4531db
    goto L_0x004531db;
L_0x004531c1:
    // 004531c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004531c2  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 004531c7  68b0965300             -push 0x5396b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478064 /*0x5396b0*/;
    cpu.esp -= 4;
    // 004531cc  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004531d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004531d3  e8b8c40800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004531d8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004531db:
    // 004531db  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004531e1  e87adc0800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 004531e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004531e8  7405                   -je 0x4531ef
    if (cpu.flags.zf)
    {
        goto L_0x004531ef;
    }
    // 004531ea  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004531ef:
    // 004531ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004531f1:
    // 004531f1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004531f3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004531f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004531f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004531f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004531f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004531f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_453200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453200  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453201  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453202  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453203  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453204  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453206  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0045320c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045320e  e89d60feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453213  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453215  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00453217  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453219  745d                   -je 0x453278
    if (cpu.flags.zf)
    {
        goto L_0x00453278;
    }
    // 0045321b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045321d  e89e63feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00453222  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453224  7424                   -je 0x45324a
    if (cpu.flags.zf)
    {
        goto L_0x0045324a;
    }
    // 00453226  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00453228  e86360feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 0045322d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045322e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045322f  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453234  68bc965300             -push 0x5396bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478076 /*0x5396bc*/;
    cpu.esp -= 4;
    // 00453239  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0045323f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453240  e84bc40800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453245  83c414                 +add esp, 0x14
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
    // 00453248  eb1a                   -jmp 0x453264
    goto L_0x00453264;
L_0x0045324a:
    // 0045324a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045324b  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453250  68cc965300             -push 0x5396cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478092 /*0x5396cc*/;
    cpu.esp -= 4;
    // 00453255  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0045325b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045325c  e82fc40800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453261  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00453264:
    // 00453264  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0045326a  e8f1db0800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0045326f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453271  7405                   -je 0x453278
    if (cpu.flags.zf)
    {
        goto L_0x00453278;
    }
    // 00453273  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00453278:
    // 00453278  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045327a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045327c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045327d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045327e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045327f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453280  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_453290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453291  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453292  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453293  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453294  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453296  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0045329c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045329e  e80d60feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 004532a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004532a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004532a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004532a9  745d                   -je 0x453308
    if (cpu.flags.zf)
    {
        goto L_0x00453308;
    }
    // 004532ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004532ad  e80e63feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 004532b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004532b4  7424                   -je 0x4532da
    if (cpu.flags.zf)
    {
        goto L_0x004532da;
    }
    // 004532b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004532b8  e8d35ffeff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004532bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004532be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004532bf  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 004532c4  68dc965300             -push 0x5396dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478108 /*0x5396dc*/;
    cpu.esp -= 4;
    // 004532c9  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004532cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004532d0  e8bbc30800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004532d5  83c414                 +add esp, 0x14
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
    // 004532d8  eb1a                   -jmp 0x4532f4
    goto L_0x004532f4;
L_0x004532da:
    // 004532da  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004532db  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 004532e0  68ec965300             -push 0x5396ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478124 /*0x5396ec*/;
    cpu.esp -= 4;
    // 004532e5  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004532eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004532ec  e89fc30800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004532f1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004532f4:
    // 004532f4  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004532fa  e861db0800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 004532ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453301  7405                   -je 0x453308
    if (cpu.flags.zf)
    {
        goto L_0x00453308;
    }
    // 00453303  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00453308:
    // 00453308  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045330a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045330c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045330d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045330e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045330f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453310  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_453320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453322  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453323  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453324  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00453325  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453326  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453328  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0045332b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045332d  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00453332  e8795ffeff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453337  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00453339  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045333b  0f84ef000000           -je 0x453430
    if (cpu.flags.zf)
    {
        goto L_0x00453430;
    }
    // 00453341  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00453346  e87562feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 0045334b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045334d  7424                   -je 0x453373
    if (cpu.flags.zf)
    {
        goto L_0x00453373;
    }
    // 0045334f  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00453354  e8375ffeff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 00453359  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045335a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045335b  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453360  6884965300             -push 0x539684
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478020 /*0x539684*/;
    cpu.esp -= 4;
    // 00453365  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 00453368  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453369  e822c30800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045336e  83c414                 +add esp, 0x14
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
    // 00453371  eb17                   -jmp 0x45338a
    goto L_0x0045338a;
L_0x00453373:
    // 00453373  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453374  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453379  6894965300             -push 0x539694
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478036 /*0x539694*/;
    cpu.esp -= 4;
    // 0045337e  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 00453381  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453382  e809c30800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453387  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0045338a:
    // 0045338a  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0045338f  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 00453392  e859230400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00453397  baf8965300             -mov edx, 0x5396f8
    cpu.edx = 5478136 /*0x5396f8*/;
    // 0045339c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045339e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004533a0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004533a2  e899f6feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004533a7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004533a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004533ab  7437                   -je 0x4533e4
    if (cpu.flags.zf)
    {
        goto L_0x004533e4;
    }
    // 004533ad  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 004533b2  40                     -inc eax
    (cpu.eax)++;
    // 004533b3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004533b4  6808975300             -push 0x539708
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478152 /*0x539708*/;
    cpu.esp -= 4;
    // 004533b9  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 004533bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004533bd  e8cec20800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004533c2  8b4742                 -mov eax, dword ptr [edi + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(66) /* 0x42 */);
    // 004533c5  8d55ac                 -lea edx, [ebp - 0x54]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 004533c8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004533cb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004533ce  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004533d1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004533d3  e808be0900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 004533d8  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004533db  e8b02f0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004533e0  66894744               -mov word ptr [edi + 0x44], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x004533e4:
    // 004533e4  ba10975300             -mov edx, 0x539710
    cpu.edx = 5478160 /*0x539710*/;
    // 004533e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004533eb  e850f6feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004533f0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004533f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004533f4  7433                   -je 0x453429
    if (cpu.flags.zf)
    {
        goto L_0x00453429;
    }
    // 004533f6  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 004533fb  40                     -inc eax
    (cpu.eax)++;
    // 004533fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004533fd  6820975300             -push 0x539720
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478176 /*0x539720*/;
    cpu.esp -= 4;
    // 00453402  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 00453405  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453406  8d55ac                 -lea edx, [ebp - 0x54]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 00453409  e882c20800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045340e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453411  8b5942                 -mov ebx, dword ptr [ecx + 0x42]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(66) /* 0x42 */);
    // 00453414  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453416  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00453419  e8c2bd0900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 0045341e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00453420  e86b2f0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00453425  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x00453429:
    // 00453429  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045342b  e860e40800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00453430:
    // 00453430  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453432  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453433  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453434  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453435  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453436  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453437  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453438  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_453440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453442  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453443  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453445  833d7c95550000         +cmp dword ptr [0x55957c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045344c  7413                   -je 0x453461
    if (cpu.flags.zf)
    {
        goto L_0x00453461;
    }
    // 0045344e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00453453  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00453455  891d80955500           -mov dword ptr [0x559580], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */) = cpu.ebx;
    // 0045345b  890d7c955500           -mov dword ptr [0x55957c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */) = cpu.ecx;
L_0x00453461:
    // 00453461  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453463  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453464  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453465  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453466  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_453470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453470  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453471  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453472  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453474  833d7c95550001         +cmp dword ptr [0x55957c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045347b  7411                   -je 0x45348e
    if (cpu.flags.zf)
    {
        goto L_0x0045348e;
    }
    // 0045347d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00453482  890d80955500           -mov dword ptr [0x559580], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */) = cpu.ecx;
    // 00453488  890d7c955500           -mov dword ptr [0x55957c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */) = cpu.ecx;
L_0x0045348e:
    // 0045348e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453490  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453491  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453492  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4534a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004534a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004534a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004534a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004534a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004534a5  833d7c95550002         +cmp dword ptr [0x55957c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004534ac  7416                   -je 0x4534c4
    if (cpu.flags.zf)
    {
        goto L_0x004534c4;
    }
    // 004534ae  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004534b3  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004534b8  891d80955500           -mov dword ptr [0x559580], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */) = cpu.ebx;
    // 004534be  890d7c955500           -mov dword ptr [0x55957c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */) = cpu.ecx;
L_0x004534c4:
    // 004534c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004534c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4534d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004534d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004534d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004534d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004534d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004534d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004534d7  ba28975300             -mov edx, 0x539728
    cpu.edx = 5478184 /*0x539728*/;
    // 004534dc  e82fae0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004534e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004534e3  7416                   -je 0x4534fb
    if (cpu.flags.zf)
    {
        goto L_0x004534fb;
    }
    // 004534e5  ba30975300             -mov edx, 0x539730
    cpu.edx = 5478192 /*0x539730*/;
    // 004534ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004534ec  e81fae0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004534f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004534f3  7406                   -je 0x4534fb
    if (cpu.flags.zf)
    {
        goto L_0x004534fb;
    }
    // 004534f5  890d78955500           -mov dword ptr [0x559578], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */) = cpu.ecx;
L_0x004534fb:
    // 004534fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_453500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453501  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453503  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453505  ba3c975300             -mov edx, 0x53973c
    cpu.edx = 5478204 /*0x53973c*/;
    // 0045350a  a178955500             -mov eax, dword ptr [0x559578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */);
    // 0045350f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00453514  e8f7ad0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00453519  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045351b  750b                   -jne 0x453528
    if (!cpu.flags.zf)
    {
        goto L_0x00453528;
    }
    // 0045351d  8b0dbcd26f00           -mov ecx, dword ptr [0x6fd2bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 00453523  e9a8000000             -jmp 0x4535d0
    goto L_0x004535d0;
L_0x00453528:
    // 00453528  ba44975300             -mov edx, 0x539744
    cpu.edx = 5478212 /*0x539744*/;
    // 0045352d  a178955500             -mov eax, dword ptr [0x559578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */);
    // 00453532  e8d9ad0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00453537  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453539  7512                   -jne 0x45354d
    if (!cpu.flags.zf)
    {
        goto L_0x0045354d;
    }
    // 0045353b  8b0d28d36f00           -mov ecx, dword ptr [0x6fd328]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
    // 00453541  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453543  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 00453549  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045354a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045354b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045354c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045354d:
    // 0045354d  ba4c975300             -mov edx, 0x53974c
    cpu.edx = 5478220 /*0x53974c*/;
    // 00453552  a178955500             -mov eax, dword ptr [0x559578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */);
    // 00453557  e8b4ad0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0045355c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045355e  752c                   -jne 0x45358c
    if (!cpu.flags.zf)
    {
        goto L_0x0045358c;
    }
    // 00453560  8b15d4d46f00           -mov edx, dword ptr [0x6fd4d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 00453566  83fa03                 +cmp edx, 3
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
    // 00453569  7e0f                   -jle 0x45357a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045357a;
    }
    // 0045356b  8d4afc                 -lea ecx, [edx - 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0045356e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453570  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 00453576  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453577  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453578  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453579  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045357a:
    // 0045357a  8b0dbcd26f00           -mov ecx, dword ptr [0x6fd2bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 00453580  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453582  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 00453588  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453589  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045358a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045358b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045358c:
    // 0045358c  ba58975300             -mov edx, 0x539758
    cpu.edx = 5478232 /*0x539758*/;
    // 00453591  a178955500             -mov eax, dword ptr [0x559578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */);
    // 00453596  e875ad0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0045359b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045359d  750c                   -jne 0x4535ab
    if (!cpu.flags.zf)
    {
        goto L_0x004535ab;
    }
    // 0045359f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004535a1  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 004535a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004535ab:
    // 004535ab  ba64975300             -mov edx, 0x539764
    cpu.edx = 5478244 /*0x539764*/;
    // 004535b0  a178955500             -mov eax, dword ptr [0x559578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */);
    // 004535b5  e856ad0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004535ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004535bc  750c                   -jne 0x4535ca
    if (!cpu.flags.zf)
    {
        goto L_0x004535ca;
    }
    // 004535be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004535c0  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 004535c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004535ca:
    // 004535ca  8b0da8955500           -mov ecx, dword ptr [0x5595a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */);
L_0x004535d0:
    // 004535d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004535d2  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 004535d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4535e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004535e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004535e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004535e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004535e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004535e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004535e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004535e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004535e8  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004535eb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004535ed  e86ecefbff             -call 0x410460
    cpu.esp -= 4;
    sub_410460(app, cpu);
    if (cpu.terminate) return;
    // 004535f2  e809ffffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 004535f7  83f8ff                 +cmp eax, -1
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
    // 004535fa  740a                   -je 0x453606
    if (cpu.flags.zf)
    {
        goto L_0x00453606;
    }
    // 004535fc  e8fffeffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 00453601  a394476600             -mov dword ptr [0x664794], eax
    app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */) = cpu.eax;
L_0x00453606:
    // 00453606  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 0045360b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00453610  e89b5cfeff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453615  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00453617  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 0045361c  891588955500           -mov dword ptr [0x559588], edx
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = cpu.edx;
    // 00453622  a398476600             -mov dword ptr [0x664798], eax
    app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */) = cpu.eax;
    // 00453627  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 0045362c  ba64975300             -mov edx, 0x539764
    cpu.edx = 5478244 /*0x539764*/;
    // 00453631  a384955500             -mov dword ptr [0x559584], eax
    app->getMemory<x86::reg32>(x86::reg32(5608836) /* 0x559584 */) = cpu.eax;
    // 00453636  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453638  e803f4feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045363d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045363f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00453641  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453643  7421                   -je 0x453666
    if (cpu.flags.zf)
    {
        goto L_0x00453666;
    }
    // 00453645  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 0045364a  e811fbffff             -call 0x453160
    cpu.esp -= 4;
    sub_453160(app, cpu);
    if (cpu.terminate) return;
    // 0045364f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453651  740f                   -je 0x453662
    if (cpu.flags.zf)
    {
        goto L_0x00453662;
    }
    // 00453653  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045365a  7506                   -jne 0x453662
    if (!cpu.flags.zf)
    {
        goto L_0x00453662;
    }
    // 0045365c  806204fe               +and byte ptr [edx + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 00453660  eb04                   -jmp 0x453666
    goto L_0x00453666;
L_0x00453662:
    // 00453662  804e0401               -or byte ptr [esi + 4], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00453666:
    // 00453666  ba70975300             -mov edx, 0x539770
    cpu.edx = 5478256 /*0x539770*/;
    // 0045366b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045366d  e8cef3feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453672  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00453674  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453676  7418                   -je 0x453690
    if (cpu.flags.zf)
    {
        goto L_0x00453690;
    }
    // 00453678  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 0045367d  e87efbffff             -call 0x453200
    cpu.esp -= 4;
    sub_453200(app, cpu);
    if (cpu.terminate) return;
    // 00453682  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453684  7406                   -je 0x45368c
    if (cpu.flags.zf)
    {
        goto L_0x0045368c;
    }
    // 00453686  806204fe               +and byte ptr [edx + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 0045368a  eb04                   -jmp 0x453690
    goto L_0x00453690;
L_0x0045368c:
    // 0045368c  804a0401               -or byte ptr [edx + 4], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00453690:
    // 00453690  ba78975300             -mov edx, 0x539778
    cpu.edx = 5478264 /*0x539778*/;
    // 00453695  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453697  e8a4f3feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045369c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045369e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004536a0  7418                   -je 0x4536ba
    if (cpu.flags.zf)
    {
        goto L_0x004536ba;
    }
    // 004536a2  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004536a7  e8e4fbffff             -call 0x453290
    cpu.esp -= 4;
    sub_453290(app, cpu);
    if (cpu.terminate) return;
    // 004536ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004536ae  7406                   -je 0x4536b6
    if (cpu.flags.zf)
    {
        goto L_0x004536b6;
    }
    // 004536b0  806204fe               +and byte ptr [edx + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 004536b4  eb04                   -jmp 0x4536ba
    goto L_0x004536ba;
L_0x004536b6:
    // 004536b6  804a0401               -or byte ptr [edx + 4], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004536ba:
    // 004536ba  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004536bc  0f84df000000           -je 0x4537a1
    if (cpu.flags.zf)
    {
        goto L_0x004537a1;
    }
    // 004536c2  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 004536c7  e8f45efeff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 004536cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004536ce  7424                   -je 0x4536f4
    if (cpu.flags.zf)
    {
        goto L_0x004536f4;
    }
    // 004536d0  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 004536d5  e8b65bfeff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004536da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004536db  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004536dc  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 004536e1  6884965300             -push 0x539684
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478020 /*0x539684*/;
    cpu.esp -= 4;
    // 004536e6  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004536e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004536ea  e8a1bf0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004536ef  83c414                 +add esp, 0x14
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
    // 004536f2  eb17                   -jmp 0x45370b
    goto L_0x0045370b;
L_0x004536f4:
    // 004536f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004536f5  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 004536fa  6894965300             -push 0x539694
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478036 /*0x539694*/;
    cpu.esp -= 4;
    // 004536ff  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00453702  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453703  e888bf0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453708  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0045370b:
    // 0045370b  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00453710  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00453713  e8d81f0400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00453718  baf8965300             -mov edx, 0x5396f8
    cpu.edx = 5478136 /*0x5396f8*/;
    // 0045371d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045371f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00453721  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453723  e818f3feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453728  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045372a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045372c  742d                   -je 0x45375b
    if (cpu.flags.zf)
    {
        goto L_0x0045375b;
    }
    // 0045372e  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 00453733  40                     -inc eax
    (cpu.eax)++;
    // 00453734  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453735  6808975300             -push 0x539708
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478152 /*0x539708*/;
    cpu.esp -= 4;
    // 0045373a  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045373d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045373e  e84dbf0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453743  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453746  8d55b0                 -lea edx, [ebp - 0x50]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00453749  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045374b  e890ba0900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453750  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00453752  e8392c0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00453757  66894744               -mov word ptr [edi + 0x44], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x0045375b:
    // 0045375b  ba10975300             -mov edx, 0x539710
    cpu.edx = 5478160 /*0x539710*/;
    // 00453760  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453762  e8d9f2feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453767  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453769  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045376b  742d                   -je 0x45379a
    if (cpu.flags.zf)
    {
        goto L_0x0045379a;
    }
    // 0045376d  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 00453772  40                     -inc eax
    (cpu.eax)++;
    // 00453773  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453774  6820975300             -push 0x539720
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478176 /*0x539720*/;
    cpu.esp -= 4;
    // 00453779  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045377c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045377d  e80ebf0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453782  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453785  8d55b0                 -lea edx, [ebp - 0x50]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00453788  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045378a  e851ba0900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 0045378f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00453791  e8fa2b0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00453796  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x0045379a:
    // 0045379a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045379c  e8efe00800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004537a1:
    // 004537a1  ba32000000             -mov edx, 0x32
    cpu.edx = 50 /*0x32*/;
    // 004537a6  8b1d4cbb6f00           -mov ebx, dword ptr [0x6fbb4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004537ac  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004537b1  e83a5e0700             -call 0x4c95f0
    cpu.esp -= 4;
    sub_4c95f0(app, cpu);
    if (cpu.terminate) return;
    // 004537b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004537b8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004537ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4537d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004537d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004537d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004537d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004537d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004537d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004537d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004537d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004537d8  8b0d7c955500           -mov ecx, dword ptr [0x55957c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 004537de  8b1d84955500           -mov ebx, dword ptr [0x559584]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5608836) /* 0x559584 */);
    // 004537e4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004537e6  39d9                   +cmp ecx, ebx
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
    // 004537e8  7411                   -je 0x4537fb
    if (cpu.flags.zf)
    {
        goto L_0x004537fb;
    }
    // 004537ea  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004537ef  890d84955500           -mov dword ptr [0x559584], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608836) /* 0x559584 */) = cpu.ecx;
    // 004537f5  893580955500           -mov dword ptr [0x559580], esi
    app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */) = cpu.esi;
L_0x004537fb:
    // 004537fb  8b3d94476600           -mov edi, dword ptr [0x664794]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00453801  3b3d98476600           +cmp edi, dword ptr [0x664798]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453807  7407                   -je 0x453810
    if (cpu.flags.zf)
    {
        goto L_0x00453810;
    }
    // 00453809  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 0045380e  eb16                   -jmp 0x453826
    goto L_0x00453826;
L_0x00453810:
    // 00453810  833d8095550000         +cmp dword ptr [0x559580], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453817  740d                   -je 0x453826
    if (cpu.flags.zf)
    {
        goto L_0x00453826;
    }
    // 00453819  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045381b  891d80955500           -mov dword ptr [0x559580], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */) = cpu.ebx;
    // 00453821  e8fafaffff             -call 0x453320
    cpu.esp -= 4;
    sub_453320(app, cpu);
    if (cpu.terminate) return;
L_0x00453826:
    // 00453826  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00453828  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453829  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045382a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045382b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045382c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045382d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045382e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_453830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453830  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453831  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453833  e8585c0700             -call 0x4c9490
    cpu.esp -= 4;
    sub_4c9490(app, cpu);
    if (cpu.terminate) return;
    // 00453838  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045383a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045383b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_453840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453840  90                     -nop 
    ;
    // 00453841  90                     -nop 
    ;
    // 00453842  90                     -nop 
    ;
    // 00453843  90                     -nop 
    ;
    // 00453844  90                     -nop 
    ;
    // 00453845  90                     -nop 
    ;
    // 00453846  90                     -nop 
    ;
    // 00453847  90                     -nop 
    ;
    // 00453848  90                     -nop 
    ;
    // 00453849  90                     -nop 
    ;
    // 0045384a  90                     -nop 
    ;
    // 0045384b  90                     -nop 
    ;
    // 0045384c  90                     -nop 
    ;
    // 0045384d  90                     -nop 
    ;
    // 0045384e  90                     -nop 
    ;
    // 0045384f  90                     -nop 
    ;
    // 00453850  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453851  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453853  ff0588955500           -inc dword ptr [0x559588]
    (app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */))++;
    // 00453859  ff057c476600           -inc dword ptr [0x66477c]
    (app->getMemory<x86::reg32>(x86::reg32(6702972) /* 0x66477c */))++;
    // 0045385f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453861  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453862  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_453864(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453864  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00453865  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453867  81ec0c010000           -sub esp, 0x10c
    (cpu.esp) -= x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 0045386d  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453872  e8395afeff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453877  8b0d88955500           -mov ecx, dword ptr [0x559588]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
    // 0045387d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045387f  83f901                 +cmp ecx, 1
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
    // 00453882  7e0e                   -jle 0x453892
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00453892;
    }
    // 00453884  8d59ff                 -lea ebx, [ecx - 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00453887  891d88955500           -mov dword ptr [0x559588], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = cpu.ebx;
    // 0045388d  e99f000000             -jmp 0x453931
    goto L_0x00453931;
L_0x00453892:
    // 00453892  c7058895550014000000   -mov dword ptr [0x559588], 0x14
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = 20 /*0x14*/;
L_0x0045389c:
    // 0045389c  8b3d88955500           -mov edi, dword ptr [0x559588]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
    // 004538a2  4f                     -dec edi
    (cpu.edi)--;
    // 004538a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004538a4  6880975300             -push 0x539780
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478272 /*0x539780*/;
    cpu.esp -= 4;
    // 004538a9  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004538ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004538ad  893d88955500           -mov dword ptr [0x559588], edi
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = cpu.edi;
    // 004538b3  e8d8bd0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004538b8  8a65f4                 -mov ah, byte ptr [ebp - 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004538bb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004538be  80fc20                 +cmp ah, 0x20
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004538c1  7504                   -jne 0x4538c7
    if (!cpu.flags.zf)
    {
        goto L_0x004538c7;
    }
    // 004538c3  c645f430               -mov byte ptr [ebp - 0xc], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 48 /*0x30*/;
L_0x004538c7:
    // 004538c7  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004538cc  e8ef5cfeff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 004538d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004538d3  742b                   -je 0x453900
    if (cpu.flags.zf)
    {
        goto L_0x00453900;
    }
    // 004538d5  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004538d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004538d9  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004538de  e8ad59feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004538e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004538e4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004538e5  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 004538ea  6884975300             -push 0x539784
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478276 /*0x539784*/;
    cpu.esp -= 4;
    // 004538ef  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004538f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004538f6  e895bd0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004538fb  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004538fe  eb1e                   -jmp 0x45391e
    goto L_0x0045391e;
L_0x00453900:
    // 00453900  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453903  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453904  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453905  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 0045390a  6894975300             -push 0x539794
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478292 /*0x539794*/;
    cpu.esp -= 4;
    // 0045390f  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00453915  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453916  e875bd0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045391b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0045391e:
    // 0045391e  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00453924  e837d50800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00453929  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045392b  0f846bffffff           -je 0x45389c
    if (cpu.flags.zf)
    {
        goto L_0x0045389c;
    }
L_0x00453931:
    // 00453931  ff057c476600           -inc dword ptr [0x66477c]
    (app->getMemory<x86::reg32>(x86::reg32(6702972) /* 0x66477c */))++;
    // 00453937  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453939  61                     -popal 
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
    // 0045393a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045393c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_45393e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045393e  90                     -nop 
    ;
    // 0045393f  90                     -nop 
    ;
    // 00453940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453941  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453942  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453943  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453944  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00453945  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453946  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453948  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045394b  e8a064ffff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00453950  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00453952  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00453959  740f                   -je 0x45396a
    if (cpu.flags.zf)
    {
        goto L_0x0045396a;
    }
    // 0045395b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00453960  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00453965  e896dffdff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x0045396a:
    // 0045396a  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 0045396f  83f801                 +cmp eax, 1
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
    // 00453972  7214                   -jb 0x453988
    if (cpu.flags.cf)
    {
        goto L_0x00453988;
    }
    // 00453974  0f86a7000000           -jbe 0x453a21
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00453a21;
    }
    // 0045397a  83f802                 +cmp eax, 2
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
    // 0045397d  0f84e2010000           -je 0x453b65
    if (cpu.flags.zf)
    {
        goto L_0x00453b65;
    }
    // 00453983  e967020000             -jmp 0x453bef
    goto L_0x00453bef;
L_0x00453988:
    // 00453988  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045398a  7409                   -je 0x453995
    if (cpu.flags.zf)
    {
        goto L_0x00453995;
    }
    // 0045398c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045398e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045398f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453990  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453991  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453992  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453993  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453994  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00453995:
    // 00453995  be9a000000             -mov esi, 0x9a
    cpu.esi = 154 /*0x9a*/;
    // 0045399a  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0045399d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045399f  7407                   -je 0x4539a8
    if (cpu.flags.zf)
    {
        goto L_0x004539a8;
    }
    // 004539a1  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 004539a6  eb05                   -jmp 0x4539ad
    goto L_0x004539ad;
L_0x004539a8:
    // 004539a8  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x004539ad:
    // 004539ad  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004539b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004539b3  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 004539b8  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004539bb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004539bd  0560010000             -add eax, 0x160
    (cpu.eax) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 004539c2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004539c4  e887de0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004539c9  e8c2e7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 004539ce  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004539d0  7407                   -je 0x4539d9
    if (cpu.flags.zf)
    {
        goto L_0x004539d9;
    }
    // 004539d2  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 004539d7  eb05                   -jmp 0x4539de
    goto L_0x004539de;
L_0x004539d9:
    // 004539d9  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x004539de:
    // 004539de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004539df  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004539e2  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004539e7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004539e9  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004539ee  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004539f1  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004539f3  e8b860feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 004539f8  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 004539fd  e88ee7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453a02  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00453a05  43                     -inc ebx
    (cpu.ebx)++;
    // 00453a06  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453a09  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00453a0c  837df007               +cmp dword ptr [ebp - 0x10], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453a10  0f8dd9010000           -jge 0x453bef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453bef;
    }
    // 00453a16  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453a18  748e                   -je 0x4539a8
    if (cpu.flags.zf)
    {
        goto L_0x004539a8;
    }
    // 00453a1a  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453a1f  eb8c                   -jmp 0x4539ad
    goto L_0x004539ad;
L_0x00453a21:
    // 00453a21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453a23  be9a000000             -mov esi, 0x9a
    cpu.esi = 154 /*0x9a*/;
    // 00453a28  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00453a2b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453a2d  7407                   -je 0x453a36
    if (cpu.flags.zf)
    {
        goto L_0x00453a36;
    }
    // 00453a2f  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453a34  eb05                   -jmp 0x453a3b
    goto L_0x00453a3b;
L_0x00453a36:
    // 00453a36  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453a3b:
    // 00453a3b  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453a40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453a41  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 00453a46  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453a49  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453a4b  0568010000             -add eax, 0x168
    (cpu.eax) += x86::reg32(x86::sreg32(360 /*0x168*/));
    // 00453a50  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453a52  e8f9dd0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453a57  e834e7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453a5c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453a5e  7407                   -je 0x453a67
    if (cpu.flags.zf)
    {
        goto L_0x00453a67;
    }
    // 00453a60  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453a65  eb05                   -jmp 0x453a6c
    goto L_0x00453a6c;
L_0x00453a67:
    // 00453a67  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453a6c:
    // 00453a6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453a6d  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453a70  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453a75  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453a77  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453a7c  83c211                 -add edx, 0x11
    (cpu.edx) += x86::reg32(x86::sreg32(17 /*0x11*/));
    // 00453a7f  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453a81  e82a60feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453a86  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453a8b  e800e7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453a90  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453a93  41                     -inc ecx
    (cpu.ecx)++;
    // 00453a94  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453a97  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00453a9a  837df403               +cmp dword ptr [ebp - 0xc], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453a9e  7d0b                   -jge 0x453aab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453aab;
    }
    // 00453aa0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453aa2  7492                   -je 0x453a36
    if (cpu.flags.zf)
    {
        goto L_0x00453a36;
    }
    // 00453aa4  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453aa9  eb90                   -jmp 0x453a3b
    goto L_0x00453a3b;
L_0x00453aab:
    // 00453aab  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453aad  7407                   -je 0x453ab6
    if (cpu.flags.zf)
    {
        goto L_0x00453ab6;
    }
    // 00453aaf  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453ab4  eb05                   -jmp 0x453abb
    goto L_0x00453abb;
L_0x00453ab6:
    // 00453ab6  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
L_0x00453abb:
    // 00453abb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453abc  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453ac1  baa2000000             -mov edx, 0xa2
    cpu.edx = 162 /*0xa2*/;
    // 00453ac6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453ac8  b86b010000             -mov eax, 0x16b
    cpu.eax = 363 /*0x16b*/;
    // 00453acd  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453acf  e87cdd0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453ad4  e8b7e6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453ad9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00453adb  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453ade  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00453ae1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453ae3  7407                   -je 0x453aec
    if (cpu.flags.zf)
    {
        goto L_0x00453aec;
    }
    // 00453ae5  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453aea  eb05                   -jmp 0x453af1
    goto L_0x00453af1;
L_0x00453aec:
    // 00453aec  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453af1:
    // 00453af1  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453af6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453af7  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 00453afc  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453aff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453b01  056c010000             -add eax, 0x16c
    (cpu.eax) += x86::reg32(x86::sreg32(364 /*0x16c*/));
    // 00453b06  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453b08  e843dd0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453b0d  e87ee6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453b12  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453b14  7407                   -je 0x453b1d
    if (cpu.flags.zf)
    {
        goto L_0x00453b1d;
    }
    // 00453b16  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453b1b  eb05                   -jmp 0x453b22
    goto L_0x00453b22;
L_0x00453b1d:
    // 00453b1d  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453b22:
    // 00453b22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453b23  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453b26  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453b2b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453b2d  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453b32  83c214                 -add edx, 0x14
    (cpu.edx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00453b35  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453b37  e8745ffeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453b3c  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453b41  e84ae6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453b46  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453b49  42                     -inc edx
    (cpu.edx)++;
    // 00453b4a  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453b4d  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00453b50  837df802               +cmp dword ptr [ebp - 8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453b54  0f8d95000000           -jge 0x453bef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453bef;
    }
    // 00453b5a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453b5c  748e                   -je 0x453aec
    if (cpu.flags.zf)
    {
        goto L_0x00453aec;
    }
    // 00453b5e  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453b63  eb8c                   -jmp 0x453af1
    goto L_0x00453af1;
L_0x00453b65:
    // 00453b65  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00453b67  be9a000000             -mov esi, 0x9a
    cpu.esi = 154 /*0x9a*/;
    // 00453b6c  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00453b6f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453b71  7407                   -je 0x453b7a
    if (cpu.flags.zf)
    {
        goto L_0x00453b7a;
    }
    // 00453b73  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453b78  eb05                   -jmp 0x453b7f
    goto L_0x00453b7f;
L_0x00453b7a:
    // 00453b7a  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453b7f:
    // 00453b7f  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453b84  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453b85  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 00453b8a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453b8d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453b8f  056f010000             -add eax, 0x16f
    (cpu.eax) += x86::reg32(x86::sreg32(367 /*0x16f*/));
    // 00453b94  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453b96  e8b5dc0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453b9b  e8f0e5ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453ba0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453ba2  7407                   -je 0x453bab
    if (cpu.flags.zf)
    {
        goto L_0x00453bab;
    }
    // 00453ba4  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453ba9  eb05                   -jmp 0x453bb0
    goto L_0x00453bb0;
L_0x00453bab:
    // 00453bab  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453bb0:
    // 00453bb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453bb1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453bb4  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453bb9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453bbb  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453bc0  83c20a                 -add edx, 0xa
    (cpu.edx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00453bc3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453bc5  e8e65efeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453bca  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453bcf  e8bce5ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453bd4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453bd7  40                     -inc eax
    (cpu.eax)++;
    // 00453bd8  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453bdb  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00453bde  837dfc07               +cmp dword ptr [ebp - 4], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453be2  7d0b                   -jge 0x453bef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453bef;
    }
    // 00453be4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453be6  7492                   -je 0x453b7a
    if (cpu.flags.zf)
    {
        goto L_0x00453b7a;
    }
    // 00453be8  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453bed  eb90                   -jmp 0x453b7f
    goto L_0x00453b7f;
L_0x00453bef:
    // 00453bef  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453bf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_453940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00453940;
    // 0045393e  90                     -nop 
    ;
    // 0045393f  90                     -nop 
    ;
L_entry_0x00453940:
    // 00453940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453941  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453942  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453943  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453944  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00453945  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453946  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453948  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045394b  e8a064ffff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00453950  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00453952  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00453959  740f                   -je 0x45396a
    if (cpu.flags.zf)
    {
        goto L_0x0045396a;
    }
    // 0045395b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00453960  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00453965  e896dffdff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x0045396a:
    // 0045396a  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 0045396f  83f801                 +cmp eax, 1
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
    // 00453972  7214                   -jb 0x453988
    if (cpu.flags.cf)
    {
        goto L_0x00453988;
    }
    // 00453974  0f86a7000000           -jbe 0x453a21
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00453a21;
    }
    // 0045397a  83f802                 +cmp eax, 2
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
    // 0045397d  0f84e2010000           -je 0x453b65
    if (cpu.flags.zf)
    {
        goto L_0x00453b65;
    }
    // 00453983  e967020000             -jmp 0x453bef
    goto L_0x00453bef;
L_0x00453988:
    // 00453988  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045398a  7409                   -je 0x453995
    if (cpu.flags.zf)
    {
        goto L_0x00453995;
    }
    // 0045398c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045398e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045398f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453990  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453991  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453992  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453993  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453994  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00453995:
    // 00453995  be9a000000             -mov esi, 0x9a
    cpu.esi = 154 /*0x9a*/;
    // 0045399a  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0045399d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045399f  7407                   -je 0x4539a8
    if (cpu.flags.zf)
    {
        goto L_0x004539a8;
    }
    // 004539a1  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 004539a6  eb05                   -jmp 0x4539ad
    goto L_0x004539ad;
L_0x004539a8:
    // 004539a8  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x004539ad:
    // 004539ad  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004539b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004539b3  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 004539b8  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004539bb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004539bd  0560010000             -add eax, 0x160
    (cpu.eax) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 004539c2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004539c4  e887de0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004539c9  e8c2e7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 004539ce  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004539d0  7407                   -je 0x4539d9
    if (cpu.flags.zf)
    {
        goto L_0x004539d9;
    }
    // 004539d2  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 004539d7  eb05                   -jmp 0x4539de
    goto L_0x004539de;
L_0x004539d9:
    // 004539d9  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x004539de:
    // 004539de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004539df  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004539e2  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004539e7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004539e9  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004539ee  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004539f1  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004539f3  e8b860feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 004539f8  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 004539fd  e88ee7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453a02  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00453a05  43                     -inc ebx
    (cpu.ebx)++;
    // 00453a06  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453a09  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00453a0c  837df007               +cmp dword ptr [ebp - 0x10], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453a10  0f8dd9010000           -jge 0x453bef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453bef;
    }
    // 00453a16  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453a18  748e                   -je 0x4539a8
    if (cpu.flags.zf)
    {
        goto L_0x004539a8;
    }
    // 00453a1a  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453a1f  eb8c                   -jmp 0x4539ad
    goto L_0x004539ad;
L_0x00453a21:
    // 00453a21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453a23  be9a000000             -mov esi, 0x9a
    cpu.esi = 154 /*0x9a*/;
    // 00453a28  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00453a2b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453a2d  7407                   -je 0x453a36
    if (cpu.flags.zf)
    {
        goto L_0x00453a36;
    }
    // 00453a2f  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453a34  eb05                   -jmp 0x453a3b
    goto L_0x00453a3b;
L_0x00453a36:
    // 00453a36  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453a3b:
    // 00453a3b  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453a40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453a41  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 00453a46  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453a49  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453a4b  0568010000             -add eax, 0x168
    (cpu.eax) += x86::reg32(x86::sreg32(360 /*0x168*/));
    // 00453a50  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453a52  e8f9dd0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453a57  e834e7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453a5c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453a5e  7407                   -je 0x453a67
    if (cpu.flags.zf)
    {
        goto L_0x00453a67;
    }
    // 00453a60  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453a65  eb05                   -jmp 0x453a6c
    goto L_0x00453a6c;
L_0x00453a67:
    // 00453a67  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453a6c:
    // 00453a6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453a6d  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453a70  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453a75  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453a77  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453a7c  83c211                 -add edx, 0x11
    (cpu.edx) += x86::reg32(x86::sreg32(17 /*0x11*/));
    // 00453a7f  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453a81  e82a60feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453a86  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453a8b  e800e7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453a90  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453a93  41                     -inc ecx
    (cpu.ecx)++;
    // 00453a94  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453a97  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00453a9a  837df403               +cmp dword ptr [ebp - 0xc], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453a9e  7d0b                   -jge 0x453aab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453aab;
    }
    // 00453aa0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453aa2  7492                   -je 0x453a36
    if (cpu.flags.zf)
    {
        goto L_0x00453a36;
    }
    // 00453aa4  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453aa9  eb90                   -jmp 0x453a3b
    goto L_0x00453a3b;
L_0x00453aab:
    // 00453aab  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453aad  7407                   -je 0x453ab6
    if (cpu.flags.zf)
    {
        goto L_0x00453ab6;
    }
    // 00453aaf  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453ab4  eb05                   -jmp 0x453abb
    goto L_0x00453abb;
L_0x00453ab6:
    // 00453ab6  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
L_0x00453abb:
    // 00453abb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453abc  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453ac1  baa2000000             -mov edx, 0xa2
    cpu.edx = 162 /*0xa2*/;
    // 00453ac6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453ac8  b86b010000             -mov eax, 0x16b
    cpu.eax = 363 /*0x16b*/;
    // 00453acd  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453acf  e87cdd0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453ad4  e8b7e6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453ad9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00453adb  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453ade  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00453ae1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453ae3  7407                   -je 0x453aec
    if (cpu.flags.zf)
    {
        goto L_0x00453aec;
    }
    // 00453ae5  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453aea  eb05                   -jmp 0x453af1
    goto L_0x00453af1;
L_0x00453aec:
    // 00453aec  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453af1:
    // 00453af1  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453af6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453af7  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 00453afc  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453aff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453b01  056c010000             -add eax, 0x16c
    (cpu.eax) += x86::reg32(x86::sreg32(364 /*0x16c*/));
    // 00453b06  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453b08  e843dd0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453b0d  e87ee6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453b12  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453b14  7407                   -je 0x453b1d
    if (cpu.flags.zf)
    {
        goto L_0x00453b1d;
    }
    // 00453b16  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453b1b  eb05                   -jmp 0x453b22
    goto L_0x00453b22;
L_0x00453b1d:
    // 00453b1d  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453b22:
    // 00453b22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453b23  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453b26  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453b2b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453b2d  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453b32  83c214                 -add edx, 0x14
    (cpu.edx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00453b35  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453b37  e8745ffeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453b3c  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453b41  e84ae6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453b46  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453b49  42                     -inc edx
    (cpu.edx)++;
    // 00453b4a  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453b4d  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00453b50  837df802               +cmp dword ptr [ebp - 8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453b54  0f8d95000000           -jge 0x453bef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453bef;
    }
    // 00453b5a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453b5c  748e                   -je 0x453aec
    if (cpu.flags.zf)
    {
        goto L_0x00453aec;
    }
    // 00453b5e  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453b63  eb8c                   -jmp 0x453af1
    goto L_0x00453af1;
L_0x00453b65:
    // 00453b65  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00453b67  be9a000000             -mov esi, 0x9a
    cpu.esi = 154 /*0x9a*/;
    // 00453b6c  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00453b6f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453b71  7407                   -je 0x453b7a
    if (cpu.flags.zf)
    {
        goto L_0x00453b7a;
    }
    // 00453b73  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453b78  eb05                   -jmp 0x453b7f
    goto L_0x00453b7f;
L_0x00453b7a:
    // 00453b7a  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453b7f:
    // 00453b7f  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453b84  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453b85  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 00453b8a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453b8d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453b8f  056f010000             -add eax, 0x16f
    (cpu.eax) += x86::reg32(x86::sreg32(367 /*0x16f*/));
    // 00453b94  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453b96  e8b5dc0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453b9b  e8f0e5ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453ba0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453ba2  7407                   -je 0x453bab
    if (cpu.flags.zf)
    {
        goto L_0x00453bab;
    }
    // 00453ba4  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453ba9  eb05                   -jmp 0x453bb0
    goto L_0x00453bb0;
L_0x00453bab:
    // 00453bab  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453bb0:
    // 00453bb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453bb1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453bb4  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453bb9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453bbb  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453bc0  83c20a                 -add edx, 0xa
    (cpu.edx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00453bc3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453bc5  e8e65efeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453bca  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453bcf  e8bce5ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453bd4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453bd7  40                     -inc eax
    (cpu.eax)++;
    // 00453bd8  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453bdb  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00453bde  837dfc07               +cmp dword ptr [ebp - 4], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453be2  7d0b                   -jge 0x453bef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453bef;
    }
    // 00453be4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453be6  7492                   -je 0x453b7a
    if (cpu.flags.zf)
    {
        goto L_0x00453b7a;
    }
    // 00453be8  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453bed  eb90                   -jmp 0x453b7f
    goto L_0x00453b7f;
L_0x00453bef:
    // 00453bef  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453bf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_453c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453c00  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00453c01  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00453c03  baa4975300             -mov edx, 0x5397a4
    cpu.edx = 5478308 /*0x5397a4*/;
    // 00453c08  e833eefeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453c0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453c0f  7407                   -je 0x453c18
    if (cpu.flags.zf)
    {
        goto L_0x00453c18;
    }
    // 00453c11  c7406450384500         -mov dword ptr [eax + 0x64], 0x453850
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4536400 /*0x453850*/;
L_0x00453c18:
    // 00453c18  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453c1a  bab0975300             -mov edx, 0x5397b0
    cpu.edx = 5478320 /*0x5397b0*/;
    // 00453c1f  e81ceefeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453c24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453c26  7407                   -je 0x453c2f
    if (cpu.flags.zf)
    {
        goto L_0x00453c2f;
    }
    // 00453c28  c7406464384500         -mov dword ptr [eax + 0x64], 0x453864
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4536420 /*0x453864*/;
L_0x00453c2f:
    // 00453c2f  61                     -popal 
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
    // 00453c30  eb01                   -jmp 0x453c33
    goto L_0x00453c33;
    // 00453c32  90                     -nop 
    ;
L_0x00453c33:
    // 00453c33  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00453c34  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453c36  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00453c39  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00453c3b  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453c40  e86b56feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453c45  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453c47  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00453c49  0f8488020000           -je 0x453ed7
    if (cpu.flags.zf)
    {
        goto L_0x00453ed7;
    }
    // 00453c4f  8b1588955500           -mov edx, dword ptr [0x559588]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
    // 00453c55  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453c56  6880975300             -push 0x539780
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478272 /*0x539780*/;
    cpu.esp -= 4;
    // 00453c5b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453c5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c5f  e82cba0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453c64  8a65ec                 -mov ah, byte ptr [ebp - 0x14]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453c67  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453c6a  80fc20                 +cmp ah, 0x20
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00453c6d  7504                   -jne 0x453c73
    if (!cpu.flags.zf)
    {
        goto L_0x00453c73;
    }
    // 00453c6f  c645ec30               -mov byte ptr [ebp - 0x14], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 48 /*0x30*/;
L_0x00453c73:
    // 00453c73  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453c78  e84359feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00453c7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453c7f  7428                   -je 0x453ca9
    if (cpu.flags.zf)
    {
        goto L_0x00453ca9;
    }
    // 00453c81  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453c84  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c85  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453c8a  e80156feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 00453c8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453c91  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453c96  6884975300             -push 0x539784
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478276 /*0x539784*/;
    cpu.esp -= 4;
    // 00453c9b  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453c9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c9f  e8ecb90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453ca4  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00453ca7  eb1b                   -jmp 0x453cc4
    goto L_0x00453cc4;
L_0x00453ca9:
    // 00453ca9  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453cac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453cad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453cae  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453cb3  6894975300             -push 0x539794
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478292 /*0x539794*/;
    cpu.esp -= 4;
    // 00453cb8  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453cbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453cbc  e8cfb90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453cc1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00453cc4:
    // 00453cc4  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453cc7  e894d10800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00453ccc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453cce  0f857a000000           -jne 0x453d4e
    if (!cpu.flags.zf)
    {
        goto L_0x00453d4e;
    }
    // 00453cd4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00453cd9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453cda  6880975300             -push 0x539780
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478272 /*0x539780*/;
    cpu.esp -= 4;
    // 00453cdf  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453ce2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453ce3  891d88955500           -mov dword ptr [0x559588], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = cpu.ebx;
    // 00453ce9  e8a2b90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453cee  8a75ec                 -mov dh, byte ptr [ebp - 0x14]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453cf1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453cf4  80fe20                 +cmp dh, 0x20
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
    // 00453cf7  7504                   -jne 0x453cfd
    if (!cpu.flags.zf)
    {
        goto L_0x00453cfd;
    }
    // 00453cf9  c645ec30               -mov byte ptr [ebp - 0x14], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 48 /*0x30*/;
L_0x00453cfd:
    // 00453cfd  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453d02  e8b958feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00453d07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453d09  7428                   -je 0x453d33
    if (cpu.flags.zf)
    {
        goto L_0x00453d33;
    }
    // 00453d0b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453d0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d0f  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453d14  e87755feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 00453d19  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453d1b  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453d20  6884975300             -push 0x539784
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478276 /*0x539784*/;
    cpu.esp -= 4;
    // 00453d25  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453d28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d29  e862b90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453d2e  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00453d31  eb1b                   -jmp 0x453d4e
    goto L_0x00453d4e;
L_0x00453d33:
    // 00453d33  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453d36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d37  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453d38  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453d3d  6894975300             -push 0x539794
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478292 /*0x539794*/;
    cpu.esp -= 4;
    // 00453d42  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453d45  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d46  e845b90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453d4b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00453d4e:
    // 00453d4e  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00453d53  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453d56  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00453d5b  e890190400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00453d60  babc975300             -mov edx, 0x5397bc
    cpu.edx = 5478332 /*0x5397bc*/;
    // 00453d65  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00453d67  e874b40900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453d6c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00453d6e  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 00453d73  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00453d76  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 00453d7b  e810b40900             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 00453d80  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00453d83  e818700900             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00453d88  803d1050560008         +cmp byte ptr [0x565010], 8
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
    // 00453d8f  7507                   -jne 0x453d98
    if (!cpu.flags.zf)
    {
        goto L_0x00453d98;
    }
    // 00453d91  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00453d96  eb02                   -jmp 0x453d9a
    goto L_0x00453d9a;
L_0x00453d98:
    // 00453d98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00453d9a:
    // 00453d9a  e811b40900             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 00453d9f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453da2  e869cc0900             -call 0x4f0a10
    cpu.esp -= 4;
    sub_4f0a10(app, cpu);
    if (cpu.terminate) return;
    // 00453da7  833d8895550001         +cmp dword ptr [0x559588], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453dae  0f8e92000000           -jle 0x453e46
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00453e46;
    }
    // 00453db4  68ad4121ff             -push 0xff2141ad
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280369581 /*0xff2141ad*/;
    cpu.esp -= 4;
    // 00453db9  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00453dbe  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00453dc3  ba39000000             -mov edx, 0x39
    cpu.edx = 57 /*0x39*/;
    // 00453dc8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453dca  e8c1cc0900             -call 0x4f0a90
    cpu.esp -= 4;
    sub_4f0a90(app, cpu);
    if (cpu.terminate) return;
    // 00453dcf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453dd1  e8bada0800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00453dd6  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453ddb  68c4975300             -push 0x5397c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478340 /*0x5397c4*/;
    cpu.esp -= 4;
    // 00453de0  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453de3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453de4  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00453de9  e8a2b80800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453dee  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453df1  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453df4  bb82010000             -mov ebx, 0x182
    cpu.ebx = 386 /*0x182*/;
    // 00453df9  e8f2180400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00453dfe  bad0975300             -mov edx, 0x5397d0
    cpu.edx = 5478352 /*0x5397d0*/;
    // 00453e03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453e05  e8d6b30900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453e0a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00453e0c  e8afcb0900             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 00453e11  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453e13  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453e18  e873da0800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00453e1d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e1f  e81cecfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e26  7406                   -je 0x453e2e
    if (cpu.flags.zf)
    {
        goto L_0x00453e2e;
    }
    // 00453e28  66c740440000           -mov word ptr [eax + 0x44], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
L_0x00453e2e:
    // 00453e2e  bae0975300             -mov edx, 0x5397e0
    cpu.edx = 5478368 /*0x5397e0*/;
    // 00453e33  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e35  e806ecfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e3c  7469                   -je 0x453ea7
    if (cpu.flags.zf)
    {
        goto L_0x00453ea7;
    }
    // 00453e3e  66c740440000           -mov word ptr [eax + 0x44], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 00453e44  eb61                   -jmp 0x453ea7
    goto L_0x00453ea7;
L_0x00453e46:
    // 00453e46  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453e4b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e4d  e8eeebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e52  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453e54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e56  741b                   -je 0x453e73
    if (cpu.flags.zf)
    {
        goto L_0x00453e73;
    }
    // 00453e58  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453e5d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453e5f  e87cb30900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453e64  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00453e66  e8a5d9ffff             -call 0x451810
    cpu.esp -= 4;
    sub_451810(app, cpu);
    if (cpu.terminate) return;
    // 00453e6b  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
    // 00453e6f  806105ef               -and byte ptr [ecx + 5], 0xef
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x00453e73:
    // 00453e73  bae0975300             -mov edx, 0x5397e0
    cpu.edx = 5478368 /*0x5397e0*/;
    // 00453e78  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e7a  e8c1ebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e7f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453e81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e83  741b                   -je 0x453ea0
    if (cpu.flags.zf)
    {
        goto L_0x00453ea0;
    }
    // 00453e85  bae8975300             -mov edx, 0x5397e8
    cpu.edx = 5478376 /*0x5397e8*/;
    // 00453e8a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453e8c  e84fb30900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453e91  b202                   -mov dl, 2
    cpu.dl = 2 /*0x2*/;
    // 00453e93  e878d9ffff             -call 0x451810
    cpu.esp -= 4;
    sub_451810(app, cpu);
    if (cpu.terminate) return;
    // 00453e98  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
    // 00453e9c  80490510               -or byte ptr [ecx + 5], 0x10
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00453ea0:
    // 00453ea0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453ea2  e8e9d90800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00453ea7:
    // 00453ea7  ba70975300             -mov edx, 0x539770
    cpu.edx = 5478256 /*0x539770*/;
    // 00453eac  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453eae  e88debfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453eb3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453eb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453eb7  7411                   -je 0x453eca
    if (cpu.flags.zf)
    {
        goto L_0x00453eca;
    }
    // 00453eb9  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453ebc  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00453ebf  b200                   -mov dl, 0
    cpu.dl = 0 /*0x0*/;
    // 00453ec1  e84ad9ffff             -call 0x451810
    cpu.esp -= 4;
    sub_451810(app, cpu);
    if (cpu.terminate) return;
    // 00453ec6  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x00453eca:
    // 00453eca  e8c16e0900             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00453ecf  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453ed2  e829c00900             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
L_0x00453ed7:
    // 00453ed7  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00453edc  a394955500             -mov dword ptr [0x559594], eax
    app->getMemory<x86::reg32>(x86::reg32(5608852) /* 0x559594 */) = cpu.eax;
    // 00453ee1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453ee3  a37c476600             -mov dword ptr [0x66477c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702972) /* 0x66477c */) = cpu.eax;
    // 00453ee8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453eea  61                     -popal 
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
    // 00453eeb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453eed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_453c33(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00453c33;
    // 00453c00  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00453c01  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00453c03  baa4975300             -mov edx, 0x5397a4
    cpu.edx = 5478308 /*0x5397a4*/;
    // 00453c08  e833eefeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453c0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453c0f  7407                   -je 0x453c18
    if (cpu.flags.zf)
    {
        goto L_0x00453c18;
    }
    // 00453c11  c7406450384500         -mov dword ptr [eax + 0x64], 0x453850
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4536400 /*0x453850*/;
L_0x00453c18:
    // 00453c18  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453c1a  bab0975300             -mov edx, 0x5397b0
    cpu.edx = 5478320 /*0x5397b0*/;
    // 00453c1f  e81ceefeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453c24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453c26  7407                   -je 0x453c2f
    if (cpu.flags.zf)
    {
        goto L_0x00453c2f;
    }
    // 00453c28  c7406464384500         -mov dword ptr [eax + 0x64], 0x453864
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4536420 /*0x453864*/;
L_0x00453c2f:
    // 00453c2f  61                     -popal 
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
    // 00453c30  eb01                   -jmp 0x453c33
    goto L_0x00453c33;
    // 00453c32  90                     -nop 
    ;
L_0x00453c33:
L_entry_0x00453c33:
    // 00453c33  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00453c34  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453c36  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00453c39  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00453c3b  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453c40  e86b56feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453c45  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453c47  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00453c49  0f8488020000           -je 0x453ed7
    if (cpu.flags.zf)
    {
        goto L_0x00453ed7;
    }
    // 00453c4f  8b1588955500           -mov edx, dword ptr [0x559588]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
    // 00453c55  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453c56  6880975300             -push 0x539780
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478272 /*0x539780*/;
    cpu.esp -= 4;
    // 00453c5b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453c5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c5f  e82cba0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453c64  8a65ec                 -mov ah, byte ptr [ebp - 0x14]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453c67  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453c6a  80fc20                 +cmp ah, 0x20
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00453c6d  7504                   -jne 0x453c73
    if (!cpu.flags.zf)
    {
        goto L_0x00453c73;
    }
    // 00453c6f  c645ec30               -mov byte ptr [ebp - 0x14], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 48 /*0x30*/;
L_0x00453c73:
    // 00453c73  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453c78  e84359feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00453c7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453c7f  7428                   -je 0x453ca9
    if (cpu.flags.zf)
    {
        goto L_0x00453ca9;
    }
    // 00453c81  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453c84  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c85  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453c8a  e80156feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 00453c8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453c91  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453c96  6884975300             -push 0x539784
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478276 /*0x539784*/;
    cpu.esp -= 4;
    // 00453c9b  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453c9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c9f  e8ecb90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453ca4  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00453ca7  eb1b                   -jmp 0x453cc4
    goto L_0x00453cc4;
L_0x00453ca9:
    // 00453ca9  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453cac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453cad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453cae  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453cb3  6894975300             -push 0x539794
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478292 /*0x539794*/;
    cpu.esp -= 4;
    // 00453cb8  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453cbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453cbc  e8cfb90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453cc1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00453cc4:
    // 00453cc4  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453cc7  e894d10800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00453ccc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453cce  0f857a000000           -jne 0x453d4e
    if (!cpu.flags.zf)
    {
        goto L_0x00453d4e;
    }
    // 00453cd4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00453cd9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453cda  6880975300             -push 0x539780
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478272 /*0x539780*/;
    cpu.esp -= 4;
    // 00453cdf  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453ce2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453ce3  891d88955500           -mov dword ptr [0x559588], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = cpu.ebx;
    // 00453ce9  e8a2b90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453cee  8a75ec                 -mov dh, byte ptr [ebp - 0x14]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453cf1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453cf4  80fe20                 +cmp dh, 0x20
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
    // 00453cf7  7504                   -jne 0x453cfd
    if (!cpu.flags.zf)
    {
        goto L_0x00453cfd;
    }
    // 00453cf9  c645ec30               -mov byte ptr [ebp - 0x14], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 48 /*0x30*/;
L_0x00453cfd:
    // 00453cfd  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453d02  e8b958feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00453d07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453d09  7428                   -je 0x453d33
    if (cpu.flags.zf)
    {
        goto L_0x00453d33;
    }
    // 00453d0b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453d0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d0f  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453d14  e87755feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 00453d19  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453d1b  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453d20  6884975300             -push 0x539784
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478276 /*0x539784*/;
    cpu.esp -= 4;
    // 00453d25  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453d28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d29  e862b90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453d2e  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00453d31  eb1b                   -jmp 0x453d4e
    goto L_0x00453d4e;
L_0x00453d33:
    // 00453d33  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453d36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d37  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453d38  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453d3d  6894975300             -push 0x539794
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478292 /*0x539794*/;
    cpu.esp -= 4;
    // 00453d42  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453d45  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d46  e845b90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453d4b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00453d4e:
    // 00453d4e  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00453d53  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453d56  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00453d5b  e890190400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00453d60  babc975300             -mov edx, 0x5397bc
    cpu.edx = 5478332 /*0x5397bc*/;
    // 00453d65  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00453d67  e874b40900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453d6c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00453d6e  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 00453d73  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00453d76  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 00453d7b  e810b40900             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 00453d80  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00453d83  e818700900             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00453d88  803d1050560008         +cmp byte ptr [0x565010], 8
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
    // 00453d8f  7507                   -jne 0x453d98
    if (!cpu.flags.zf)
    {
        goto L_0x00453d98;
    }
    // 00453d91  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00453d96  eb02                   -jmp 0x453d9a
    goto L_0x00453d9a;
L_0x00453d98:
    // 00453d98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00453d9a:
    // 00453d9a  e811b40900             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 00453d9f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453da2  e869cc0900             -call 0x4f0a10
    cpu.esp -= 4;
    sub_4f0a10(app, cpu);
    if (cpu.terminate) return;
    // 00453da7  833d8895550001         +cmp dword ptr [0x559588], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453dae  0f8e92000000           -jle 0x453e46
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00453e46;
    }
    // 00453db4  68ad4121ff             -push 0xff2141ad
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280369581 /*0xff2141ad*/;
    cpu.esp -= 4;
    // 00453db9  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00453dbe  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00453dc3  ba39000000             -mov edx, 0x39
    cpu.edx = 57 /*0x39*/;
    // 00453dc8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453dca  e8c1cc0900             -call 0x4f0a90
    cpu.esp -= 4;
    sub_4f0a90(app, cpu);
    if (cpu.terminate) return;
    // 00453dcf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453dd1  e8bada0800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00453dd6  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453ddb  68c4975300             -push 0x5397c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478340 /*0x5397c4*/;
    cpu.esp -= 4;
    // 00453de0  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453de3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453de4  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00453de9  e8a2b80800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453dee  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453df1  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453df4  bb82010000             -mov ebx, 0x182
    cpu.ebx = 386 /*0x182*/;
    // 00453df9  e8f2180400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00453dfe  bad0975300             -mov edx, 0x5397d0
    cpu.edx = 5478352 /*0x5397d0*/;
    // 00453e03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453e05  e8d6b30900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453e0a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00453e0c  e8afcb0900             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 00453e11  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453e13  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453e18  e873da0800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00453e1d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e1f  e81cecfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e26  7406                   -je 0x453e2e
    if (cpu.flags.zf)
    {
        goto L_0x00453e2e;
    }
    // 00453e28  66c740440000           -mov word ptr [eax + 0x44], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
L_0x00453e2e:
    // 00453e2e  bae0975300             -mov edx, 0x5397e0
    cpu.edx = 5478368 /*0x5397e0*/;
    // 00453e33  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e35  e806ecfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e3c  7469                   -je 0x453ea7
    if (cpu.flags.zf)
    {
        goto L_0x00453ea7;
    }
    // 00453e3e  66c740440000           -mov word ptr [eax + 0x44], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 00453e44  eb61                   -jmp 0x453ea7
    goto L_0x00453ea7;
L_0x00453e46:
    // 00453e46  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453e4b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e4d  e8eeebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e52  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453e54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e56  741b                   -je 0x453e73
    if (cpu.flags.zf)
    {
        goto L_0x00453e73;
    }
    // 00453e58  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453e5d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453e5f  e87cb30900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453e64  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00453e66  e8a5d9ffff             -call 0x451810
    cpu.esp -= 4;
    sub_451810(app, cpu);
    if (cpu.terminate) return;
    // 00453e6b  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
    // 00453e6f  806105ef               -and byte ptr [ecx + 5], 0xef
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x00453e73:
    // 00453e73  bae0975300             -mov edx, 0x5397e0
    cpu.edx = 5478368 /*0x5397e0*/;
    // 00453e78  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e7a  e8c1ebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e7f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453e81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e83  741b                   -je 0x453ea0
    if (cpu.flags.zf)
    {
        goto L_0x00453ea0;
    }
    // 00453e85  bae8975300             -mov edx, 0x5397e8
    cpu.edx = 5478376 /*0x5397e8*/;
    // 00453e8a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453e8c  e84fb30900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453e91  b202                   -mov dl, 2
    cpu.dl = 2 /*0x2*/;
    // 00453e93  e878d9ffff             -call 0x451810
    cpu.esp -= 4;
    sub_451810(app, cpu);
    if (cpu.terminate) return;
    // 00453e98  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
    // 00453e9c  80490510               -or byte ptr [ecx + 5], 0x10
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00453ea0:
    // 00453ea0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453ea2  e8e9d90800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00453ea7:
    // 00453ea7  ba70975300             -mov edx, 0x539770
    cpu.edx = 5478256 /*0x539770*/;
    // 00453eac  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453eae  e88debfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453eb3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453eb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453eb7  7411                   -je 0x453eca
    if (cpu.flags.zf)
    {
        goto L_0x00453eca;
    }
    // 00453eb9  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453ebc  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00453ebf  b200                   -mov dl, 0
    cpu.dl = 0 /*0x0*/;
    // 00453ec1  e84ad9ffff             -call 0x451810
    cpu.esp -= 4;
    sub_451810(app, cpu);
    if (cpu.terminate) return;
    // 00453ec6  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x00453eca:
    // 00453eca  e8c16e0900             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00453ecf  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453ed2  e829c00900             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
L_0x00453ed7:
    // 00453ed7  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00453edc  a394955500             -mov dword ptr [0x559594], eax
    app->getMemory<x86::reg32>(x86::reg32(5608852) /* 0x559594 */) = cpu.eax;
    // 00453ee1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453ee3  a37c476600             -mov dword ptr [0x66477c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702972) /* 0x66477c */) = cpu.eax;
    // 00453ee8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453eea  61                     -popal 
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
    // 00453eeb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453eed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_453eee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453eee  90                     -nop 
    ;
    // 00453eef  90                     -nop 
    ;
    // 00453ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453ef2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453ef3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453ef4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453ef6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453ef8  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00453efd  8b1594955500           -mov edx, dword ptr [0x559594]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608852) /* 0x559594 */);
    // 00453f03  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 00453f09  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00453f0b  39d0                   +cmp eax, edx
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
    // 00453f0d  7e32                   -jle 0x453f41
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00453f41;
    }
    // 00453f0f  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453f14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453f16  e825ebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453f1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453f1d  7404                   -je 0x453f23
    if (cpu.flags.zf)
    {
        goto L_0x00453f23;
    }
    // 00453f1f  80700510               -xor byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) ^= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00453f23:
    // 00453f23  bae0975300             -mov edx, 0x5397e0
    cpu.edx = 5478368 /*0x5397e0*/;
    // 00453f28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453f2a  e811ebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453f2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453f31  7404                   -je 0x453f37
    if (cpu.flags.zf)
    {
        goto L_0x00453f37;
    }
    // 00453f33  80700510               -xor byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) ^= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00453f37:
    // 00453f37  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00453f3c  a394955500             -mov dword ptr [0x559594], eax
    app->getMemory<x86::reg32>(x86::reg32(5608852) /* 0x559594 */) = cpu.eax;
L_0x00453f41:
    // 00453f41  833d7c47660000         +cmp dword ptr [0x66477c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702972) /* 0x66477c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453f48  7407                   -je 0x453f51
    if (cpu.flags.zf)
    {
        goto L_0x00453f51;
    }
    // 00453f4a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453f4c  e8e2fcffff             -call 0x453c33
    cpu.esp -= 4;
    sub_453c33(app, cpu);
    if (cpu.terminate) return;
L_0x00453f51:
    // 00453f51  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00453f53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f54  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_453ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00453ef0;
    // 00453eee  90                     -nop 
    ;
    // 00453eef  90                     -nop 
    ;
L_entry_0x00453ef0:
    // 00453ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453ef2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453ef3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453ef4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453ef6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453ef8  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00453efd  8b1594955500           -mov edx, dword ptr [0x559594]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608852) /* 0x559594 */);
    // 00453f03  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 00453f09  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00453f0b  39d0                   +cmp eax, edx
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
    // 00453f0d  7e32                   -jle 0x453f41
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00453f41;
    }
    // 00453f0f  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453f14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453f16  e825ebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453f1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453f1d  7404                   -je 0x453f23
    if (cpu.flags.zf)
    {
        goto L_0x00453f23;
    }
    // 00453f1f  80700510               -xor byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) ^= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00453f23:
    // 00453f23  bae0975300             -mov edx, 0x5397e0
    cpu.edx = 5478368 /*0x5397e0*/;
    // 00453f28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453f2a  e811ebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453f2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453f31  7404                   -je 0x453f37
    if (cpu.flags.zf)
    {
        goto L_0x00453f37;
    }
    // 00453f33  80700510               -xor byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) ^= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00453f37:
    // 00453f37  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00453f3c  a394955500             -mov dword ptr [0x559594], eax
    app->getMemory<x86::reg32>(x86::reg32(5608852) /* 0x559594 */) = cpu.eax;
L_0x00453f41:
    // 00453f41  833d7c47660000         +cmp dword ptr [0x66477c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702972) /* 0x66477c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453f48  7407                   -je 0x453f51
    if (cpu.flags.zf)
    {
        goto L_0x00453f51;
    }
    // 00453f4a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453f4c  e8e2fcffff             -call 0x453c33
    cpu.esp -= 4;
    sub_453c33(app, cpu);
    if (cpu.terminate) return;
L_0x00453f51:
    // 00453f51  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00453f53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f54  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_453f58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453f58  90                     -nop 
    ;
    // 00453f59  90                     -nop 
    ;
    // 00453f5a  90                     -nop 
    ;
    // 00453f5b  90                     -nop 
    ;
    // 00453f5c  90                     -nop 
    ;
    // 00453f5d  90                     -nop 
    ;
    // 00453f5e  90                     -nop 
    ;
    // 00453f5f  90                     -nop 
    ;
    // 00453f60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453f61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453f62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453f63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453f64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00453f65  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453f66  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453f68  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00453f6b  e8805effff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00453f70  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00453f73  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00453f7a  740f                   -je 0x453f8b
    if (cpu.flags.zf)
    {
        goto L_0x00453f8b;
    }
    // 00453f7c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00453f81  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00453f86  e875d9fdff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x00453f8b:
    // 00453f8b  bf87000000             -mov edi, 0x87
    cpu.edi = 135 /*0x87*/;
    // 00453f90  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00453f92  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453f96  7407                   -je 0x453f9f
    if (cpu.flags.zf)
    {
        goto L_0x00453f9f;
    }
    // 00453f98  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453f9d  eb14                   -jmp 0x453fb3
    goto L_0x00453fb3;
L_0x00453f9f:
    // 00453f9f  3b358c955500           +cmp esi, dword ptr [0x55958c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453fa5  7507                   -jne 0x453fae
    if (!cpu.flags.zf)
    {
        goto L_0x00453fae;
    }
    // 00453fa7  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
    // 00453fac  eb05                   -jmp 0x453fb3
    goto L_0x00453fb3;
L_0x00453fae:
    // 00453fae  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453fb3:
    // 00453fb3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453fb4  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453fb9  8d5617                 -lea edx, [esi + 0x17]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(23) /* 0x17 */);
    // 00453fbc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453fbe  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453fc3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00453fc5  e8e65afeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453fca  83c70f                 -add edi, 0xf
    (cpu.edi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453fcd  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453fd2  46                     -inc esi
    (cpu.esi)++;
    // 00453fd3  e8b8e1ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453fd8  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453fdb  7d0d                   -jge 0x453fea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453fea;
    }
    // 00453fdd  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453fe1  74bc                   -je 0x453f9f
    if (cpu.flags.zf)
    {
        goto L_0x00453f9f;
    }
    // 00453fe3  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453fe8  ebc9                   -jmp 0x453fb3
    goto L_0x00453fb3;
L_0x00453fea:
    // 00453fea  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453fec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453fed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453fee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453fef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ff0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ff1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ff2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_453f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00453f60;
    // 00453f58  90                     -nop 
    ;
    // 00453f59  90                     -nop 
    ;
    // 00453f5a  90                     -nop 
    ;
    // 00453f5b  90                     -nop 
    ;
    // 00453f5c  90                     -nop 
    ;
    // 00453f5d  90                     -nop 
    ;
    // 00453f5e  90                     -nop 
    ;
    // 00453f5f  90                     -nop 
    ;
L_entry_0x00453f60:
    // 00453f60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453f61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453f62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453f63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453f64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00453f65  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453f66  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453f68  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00453f6b  e8805effff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00453f70  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00453f73  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00453f7a  740f                   -je 0x453f8b
    if (cpu.flags.zf)
    {
        goto L_0x00453f8b;
    }
    // 00453f7c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00453f81  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00453f86  e875d9fdff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x00453f8b:
    // 00453f8b  bf87000000             -mov edi, 0x87
    cpu.edi = 135 /*0x87*/;
    // 00453f90  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00453f92  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453f96  7407                   -je 0x453f9f
    if (cpu.flags.zf)
    {
        goto L_0x00453f9f;
    }
    // 00453f98  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453f9d  eb14                   -jmp 0x453fb3
    goto L_0x00453fb3;
L_0x00453f9f:
    // 00453f9f  3b358c955500           +cmp esi, dword ptr [0x55958c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453fa5  7507                   -jne 0x453fae
    if (!cpu.flags.zf)
    {
        goto L_0x00453fae;
    }
    // 00453fa7  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
    // 00453fac  eb05                   -jmp 0x453fb3
    goto L_0x00453fb3;
L_0x00453fae:
    // 00453fae  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453fb3:
    // 00453fb3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453fb4  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453fb9  8d5617                 -lea edx, [esi + 0x17]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(23) /* 0x17 */);
    // 00453fbc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453fbe  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453fc3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00453fc5  e8e65afeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453fca  83c70f                 -add edi, 0xf
    (cpu.edi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453fcd  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453fd2  46                     -inc esi
    (cpu.esi)++;
    // 00453fd3  e8b8e1ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453fd8  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453fdb  7d0d                   -jge 0x453fea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453fea;
    }
    // 00453fdd  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453fe1  74bc                   -je 0x453f9f
    if (cpu.flags.zf)
    {
        goto L_0x00453f9f;
    }
    // 00453fe3  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453fe8  ebc9                   -jmp 0x453fb3
    goto L_0x00453fb3;
L_0x00453fea:
    // 00453fea  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453fec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453fed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453fee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453fef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ff0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ff1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ff2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_454000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454002  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454003  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00454004  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454005  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454007  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0045400d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045400f  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00454012  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00454017  e89452feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 0045401c  8b158c955500           -mov edx, dword ptr [0x55958c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
    // 00454022  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00454025  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00454028  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 0045402d  83c217                 -add edx, 0x17
    (cpu.edx) += x86::reg32(x86::sreg32(23 /*0x17*/));
    // 00454030  e87b5afeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00454035  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00454038  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045403a  7406                   -je 0x454042
    if (cpu.flags.zf)
    {
        goto L_0x00454042;
    }
    // 0045403c  837df800               +cmp dword ptr [ebp - 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454040  7507                   -jne 0x454049
    if (!cpu.flags.zf)
    {
        goto L_0x00454049;
    }
L_0x00454042:
    // 00454042  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00454044  e9b9010000             -jmp 0x454202
    goto L_0x00454202;
L_0x00454049:
    // 00454049  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0045404e  baf0975300             -mov edx, 0x5397f0
    cpu.edx = 5478384 /*0x5397f0*/;
    // 00454053  e838730900             -call 0x4eb390
    cpu.esp -= 4;
    sub_4eb390(app, cpu);
    if (cpu.terminate) return;
    // 00454058  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045405a  7508                   -jne 0x454064
    if (!cpu.flags.zf)
    {
        goto L_0x00454064;
    }
    // 0045405c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045405e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045405f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454060  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454061  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454062  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454063  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00454064:
    // 00454064  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00454067  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00454069  49                     -dec ecx
    (cpu.ecx)--;
    // 0045406a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045406c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0045406e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00454070  49                     -dec ecx
    (cpu.ecx)--;
    // 00454071  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454073  83f904                 +cmp ecx, 4
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
    // 00454076  7d0a                   -jge 0x454082
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00454082;
    }
    // 00454078  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045407a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045407c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045407d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045407e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045407f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454080  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454081  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00454082:
    // 00454082  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00454085  8d0419                 -lea eax, [ecx + ebx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebx * 1);
    // 00454088  8d78fe                 -lea edi, [eax - 2]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-2) /* -0x2 */);
    // 0045408b  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00454090  e82b55feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00454095  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454097  742a                   -je 0x4540c3
    if (cpu.flags.zf)
    {
        goto L_0x004540c3;
    }
    // 00454099  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 0045409e  e8ed51feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004540a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004540a4  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004540a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004540a8  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 004540ad  68dc965300             -push 0x5396dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478108 /*0x5396dc*/;
    cpu.esp -= 4;
    // 004540b2  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 004540b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004540b9  e8d2b50800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004540be  83c414                 +add esp, 0x14
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
    // 004540c1  eb1d                   -jmp 0x4540e0
    goto L_0x004540e0;
L_0x004540c3:
    // 004540c3  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004540c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004540c7  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 004540cc  68ec965300             -push 0x5396ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478124 /*0x5396ec*/;
    cpu.esp -= 4;
    // 004540d1  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 004540d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004540d8  e8b3b50800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004540dd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004540e0:
    // 004540e0  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 004540e6  e875cd0800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 004540eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004540ed  7508                   -jne 0x4540f7
    if (!cpu.flags.zf)
    {
        goto L_0x004540f7;
    }
    // 004540ef  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004540f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004540f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004540f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004540f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004540f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004540f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004540f7:
    // 004540f7  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 004540fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004540ff  e8ec150400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00454104  baf8975300             -mov edx, 0x5397f8
    cpu.edx = 5478392 /*0x5397f8*/;
    // 00454109  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045410b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045410d  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00454110  e8fba10900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00454115  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454117  7523                   -jne 0x45413c
    if (!cpu.flags.zf)
    {
        goto L_0x0045413c;
    }
    // 00454119  833d8c95550003         +cmp dword ptr [0x55958c], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454120  751a                   -jne 0x45413c
    if (!cpu.flags.zf)
    {
        goto L_0x0045413c;
    }
    // 00454122  ba00985300             -mov edx, 0x539800
    cpu.edx = 5478400 /*0x539800*/;
    // 00454127  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00454129  e842b10900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 0045412e  ba08985300             -mov edx, 0x539808
    cpu.edx = 5478408 /*0x539808*/;
    // 00454133  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00454135  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00454137  e970000000             -jmp 0x4541ac
    goto L_0x004541ac;
L_0x0045413c:
    // 0045413c  baf8975300             -mov edx, 0x5397f8
    cpu.edx = 5478392 /*0x5397f8*/;
    // 00454141  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00454144  e8c7a10900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00454149  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045414b  751e                   -jne 0x45416b
    if (!cpu.flags.zf)
    {
        goto L_0x0045416b;
    }
    // 0045414d  833d8c95550004         +cmp dword ptr [0x55958c], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454154  7515                   -jne 0x45416b
    if (!cpu.flags.zf)
    {
        goto L_0x0045416b;
    }
    // 00454156  ba10985300             -mov edx, 0x539810
    cpu.edx = 5478416 /*0x539810*/;
    // 0045415b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045415d  e80eb10900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 00454162  ba18985300             -mov edx, 0x539818
    cpu.edx = 5478424 /*0x539818*/;
    // 00454167  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00454169  eb3f                   -jmp 0x4541aa
    goto L_0x004541aa;
L_0x0045416b:
    // 0045416b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045416c  6820985300             -push 0x539820
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478432 /*0x539820*/;
    cpu.esp -= 4;
    // 00454171  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00454177  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00454178  e813b50800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045417d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00454180  8d95f0feffff           -lea edx, [ebp - 0x110]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00454186  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454188  e8e3b00900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 0045418d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045418e  6828985300             -push 0x539828
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478440 /*0x539828*/;
    cpu.esp -= 4;
    // 00454193  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00454195  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 0045419b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045419c  e8efb40800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004541a1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004541a4  8d95f0feffff           -lea edx, [ebp - 0x110]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
L_0x004541aa:
    // 004541aa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004541ac:
    // 004541ac  e8bfb00900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 004541b1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004541b4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004541b6  833e00                 +cmp dword ptr [esi], 0
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
    // 004541b9  7408                   -je 0x4541c3
    if (cpu.flags.zf)
    {
        goto L_0x004541c3;
    }
    // 004541bb  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004541be  833800                 +cmp dword ptr [eax], 0
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
    // 004541c1  751f                   -jne 0x4541e2
    if (!cpu.flags.zf)
    {
        goto L_0x004541e2;
    }
L_0x004541c3:
    // 004541c3  babc975300             -mov edx, 0x5397bc
    cpu.edx = 5478332 /*0x5397bc*/;
    // 004541c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004541ca  e8a1b00900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 004541cf  ba30985300             -mov edx, 0x539830
    cpu.edx = 5478448 /*0x539830*/;
    // 004541d4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004541d6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004541d8  e893b00900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 004541dd  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004541e0  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004541e2:
    // 004541e2  833e00                 +cmp dword ptr [esi], 0
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
    // 004541e5  7408                   -je 0x4541ef
    if (cpu.flags.zf)
    {
        goto L_0x004541ef;
    }
    // 004541e7  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004541ea  833800                 +cmp dword ptr [eax], 0
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
    // 004541ed  7511                   -jne 0x454200
    if (!cpu.flags.zf)
    {
        goto L_0x00454200;
    }
L_0x004541ef:
    // 004541ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004541f1  e89ad60800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004541f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004541f8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004541fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004541fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004541fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004541fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004541fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004541ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00454200:
    // 00454200  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00454202:
    // 00454202  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00454204  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454205  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454206  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454207  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454208  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454209  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_454210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454210  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454212  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454213  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454214  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454216  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00454218  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0045421a  8b358c955500           -mov esi, dword ptr [0x55958c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
L_0x00454220:
    // 00454220  e8dbfdffff             -call 0x454000
    cpu.esp -= 4;
    sub_454000(app, cpu);
    if (cpu.terminate) return;
    // 00454225  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454227  7531                   -jne 0x45425a
    if (!cpu.flags.zf)
    {
        goto L_0x0045425a;
    }
    // 00454229  8b158c955500           -mov edx, dword ptr [0x55958c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
    // 0045422f  42                     -inc edx
    (cpu.edx)++;
    // 00454230  89158c955500           -mov dword ptr [0x55958c], edx
    app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */) = cpu.edx;
    // 00454236  83fa06                 +cmp edx, 6
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454239  7e0a                   -jle 0x454245
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454245;
    }
    // 0045423b  c7058c95550001000000   -mov dword ptr [0x55958c], 1
    app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */) = 1 /*0x1*/;
L_0x00454245:
    // 00454245  3b358c955500           +cmp esi, dword ptr [0x55958c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045424b  7507                   -jne 0x454254
    if (!cpu.flags.zf)
    {
        goto L_0x00454254;
    }
    // 0045424d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045424f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454250  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454251  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454252  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454253  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00454254:
    // 00454254  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00454256  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454258  ebc6                   -jmp 0x454220
    goto L_0x00454220;
L_0x0045425a:
    // 0045425a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045425b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045425c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045425d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045425e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_454260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454260  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454261  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454262  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454263  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454264  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454265  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454267  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045426a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045426c  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454271  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00454276  a398476600             -mov dword ptr [0x664798], eax
    app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */) = cpu.eax;
    // 0045427b  89158c955500           -mov dword ptr [0x55958c], edx
    app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */) = cpu.edx;
    // 00454281  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00454284  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00454287  e884ffffff             -call 0x454210
    cpu.esp -= 4;
    sub_454210(app, cpu);
    if (cpu.terminate) return;
    // 0045428c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045428e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454290  7447                   -je 0x4542d9
    if (cpu.flags.zf)
    {
        goto L_0x004542d9;
    }
    // 00454292  ba38985300             -mov edx, 0x539838
    cpu.edx = 5478456 /*0x539838*/;
    // 00454297  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454299  e8a2e7feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045429e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004542a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004542a2  740e                   -je 0x4542b2
    if (cpu.flags.zf)
    {
        goto L_0x004542b2;
    }
    // 004542a4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004542a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004542a9  e8e2200800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004542ae  66894344               -mov word ptr [ebx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x004542b2:
    // 004542b2  ba44985300             -mov edx, 0x539844
    cpu.edx = 5478468 /*0x539844*/;
    // 004542b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004542b9  e882e7feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004542be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004542c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004542c2  740e                   -je 0x4542d2
    if (cpu.flags.zf)
    {
        goto L_0x004542d2;
    }
    // 004542c4  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004542c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004542c9  e8c2200800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004542ce  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x004542d2:
    // 004542d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004542d4  e8b7d50800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004542d9:
    // 004542d9  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004542de  ba34000000             -mov edx, 0x34
    cpu.edx = 52 /*0x34*/;
    // 004542e3  8b1d4cbb6f00           -mov ebx, dword ptr [0x6fbb4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004542e9  a390955500             -mov dword ptr [0x559590], eax
    app->getMemory<x86::reg32>(x86::reg32(5608848) /* 0x559590 */) = cpu.eax;
    // 004542ee  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004542f3  e8f8520700             -call 0x4c95f0
    cpu.esp -= 4;
    sub_4c95f0(app, cpu);
    if (cpu.terminate) return;
    // 004542f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004542fa  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004542fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004542fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004542fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004542ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454300  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454301  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_454310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454312  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454313  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454314  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00454315  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454316  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454318  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045431b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045431d  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00454322  8b1594476600           -mov edx, dword ptr [0x664794]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454328  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045432a  39d0                   +cmp eax, edx
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
    // 0045432c  740a                   -je 0x454338
    if (cpu.flags.zf)
    {
        goto L_0x00454338;
    }
    // 0045432e  be09000000             -mov esi, 9
    cpu.esi = 9 /*0x9*/;
    // 00454333  e990000000             -jmp 0x4543c8
    goto L_0x004543c8;
L_0x00454338:
    // 00454338  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0045433d  8b1590955500           -mov edx, dword ptr [0x559590]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608848) /* 0x559590 */);
    // 00454343  81c258020000           -add edx, 0x258
    (cpu.edx) += x86::reg32(x86::sreg32(600 /*0x258*/));
    // 00454349  39d0                   +cmp eax, edx
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
    // 0045434b  0f8e77000000           -jle 0x4543c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004543c8;
    }
    // 00454351  8b1d8c955500           -mov ebx, dword ptr [0x55958c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
    // 00454357  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045435a  43                     -inc ebx
    (cpu.ebx)++;
    // 0045435b  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0045435e  891d8c955500           -mov dword ptr [0x55958c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */) = cpu.ebx;
    // 00454364  e8a7feffff             -call 0x454210
    cpu.esp -= 4;
    sub_454210(app, cpu);
    if (cpu.terminate) return;
    // 00454369  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045436b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045436d  744f                   -je 0x4543be
    if (cpu.flags.zf)
    {
        goto L_0x004543be;
    }
    // 0045436f  ba38985300             -mov edx, 0x539838
    cpu.edx = 5478456 /*0x539838*/;
    // 00454374  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454376  e8c5e6feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045437b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045437d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045437f  7412                   -je 0x454393
    if (cpu.flags.zf)
    {
        goto L_0x00454393;
    }
    // 00454381  8b5042                 -mov edx, dword ptr [eax + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(66) /* 0x42 */);
    // 00454384  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00454387  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045438a  e801200800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 0045438f  66894344               -mov word ptr [ebx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x00454393:
    // 00454393  ba44985300             -mov edx, 0x539844
    cpu.edx = 5478468 /*0x539844*/;
    // 00454398  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045439a  e8a1e6feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045439f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004543a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004543a3  7412                   -je 0x4543b7
    if (cpu.flags.zf)
    {
        goto L_0x004543b7;
    }
    // 004543a5  8b5042                 -mov edx, dword ptr [eax + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(66) /* 0x42 */);
    // 004543a8  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004543ab  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004543ae  e8dd1f0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004543b3  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x004543b7:
    // 004543b7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004543b9  e8d2d40800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004543be:
    // 004543be  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004543c3  a390955500             -mov dword ptr [0x559590], eax
    app->getMemory<x86::reg32>(x86::reg32(5608848) /* 0x559590 */) = cpu.eax;
L_0x004543c8:
    // 004543c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004543ca  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004543cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4543e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004543e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004543e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004543e3  e8a8500700             -call 0x4c9490
    cpu.esp -= 4;
    sub_4c9490(app, cpu);
    if (cpu.terminate) return;
    // 004543e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004543ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4543f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004543f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004543f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004543f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004543f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004543f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004543f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004543f7  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004543fa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004543fc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004543fe  6850985300             -push 0x539850
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478480 /*0x539850*/;
    cpu.esp -= 4;
    // 00454403  68b42d7a00             -push 0x7a2db4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007092 /*0x7a2db4*/;
    cpu.esp -= 4;
    // 00454408  685c985300             -push 0x53985c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478492 /*0x53985c*/;
    cpu.esp -= 4;
    // 0045440d  8d4594                 -lea eax, [ebp - 0x6c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-108) /* -0x6c */);
    // 00454410  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00454411  e87ab20800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00454416  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00454419  8d4594                 -lea eax, [ebp - 0x6c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-108) /* -0x6c */);
    // 0045441c  e86f68ffff             -call 0x44ac90
    cpu.esp -= 4;
    sub_44ac90(app, cpu);
    if (cpu.terminate) return;
    // 00454421  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00454424  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454426  e8654efeff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 0045442b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045442d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0045442f:
    // 0045442f  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 00454431  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00454433  7420                   -je 0x454455
    if (cpu.flags.zf)
    {
        goto L_0x00454455;
    }
    // 00454435  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00454437  fec0                   -inc al
    (cpu.al)++;
    // 00454439  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0045443e  f680f04e560040         +test byte ptr [eax + 0x564ef0], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 64 /*0x40*/));
    // 00454445  740b                   -je 0x454452
    if (cpu.flags.zf)
    {
        goto L_0x00454452;
    }
    // 00454447  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00454449  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0045444b  e890c60900             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 00454450  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
L_0x00454452:
    // 00454452  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00454453  ebda                   -jmp 0x45442f
    goto L_0x0045442f;
L_0x00454455:
    // 00454455  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0045445a  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0045445f  bae0000000             -mov edx, 0xe0
    cpu.edx = 224 /*0xe0*/;
    // 00454464  b820010000             -mov eax, 0x120
    cpu.eax = 288 /*0x120*/;
    // 00454469  e822ad0900             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 0045446e  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00454471  e82a690900             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00454476  803d1050560008         +cmp byte ptr [0x565010], 8
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
    // 0045447d  7507                   -jne 0x454486
    if (!cpu.flags.zf)
    {
        goto L_0x00454486;
    }
    // 0045447f  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00454484  eb02                   -jmp 0x454488
    goto L_0x00454488;
L_0x00454486:
    // 00454486  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00454488:
    // 00454488  e823ad0900             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 0045448d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045448f  7441                   -je 0x4544d2
    if (cpu.flags.zf)
    {
        goto L_0x004544d2;
    }
    // 00454491  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00454494  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00454496  e8d5ad0900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 0045449b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045449d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045449f  7431                   -je 0x4544d2
    if (cpu.flags.zf)
    {
        goto L_0x004544d2;
    }
    // 004544a1  bbe0000000             -mov ebx, 0xe0
    cpu.ebx = 224 /*0xe0*/;
    // 004544a6  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004544a9  8b5102                 -mov edx, dword ptr [ecx + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004544ac  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004544af  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004544b2  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004544b4  b820010000             -mov eax, 0x120
    cpu.eax = 288 /*0x120*/;
    // 004544b9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004544bb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004544bd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004544c0  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004544c2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004544c4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004544c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004544c8  e8f3af0900             -call 0x4ef4c0
    cpu.esp -= 4;
    sub_4ef4c0(app, cpu);
    if (cpu.terminate) return;
    // 004544cd  e8be680900             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
L_0x004544d2:
    // 004544d2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004544d5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004544d7  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004544da  e8b11e0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004544df  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004544e1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004544e4  e817ba0900             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 004544e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004544eb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004544ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004544ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004544ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004544f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004544f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004544f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_454500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454501  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454503  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454505  833d6c29660009         +cmp dword ptr [0x66296c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695276) /* 0x66296c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045450c  742d                   -je 0x45453b
    if (cpu.flags.zf)
    {
        goto L_0x0045453b;
    }
    // 0045450e  e8edefffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 00454513  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454515  740a                   -je 0x454521
    if (cpu.flags.zf)
    {
        goto L_0x00454521;
    }
    // 00454517  e8e4efffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 0045451c  a388476600             -mov dword ptr [0x664788], eax
    app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */) = cpu.eax;
L_0x00454521:
    // 00454521  8b0dd4d46f00           -mov ecx, dword ptr [0x6fd4d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 00454527  83f903                 +cmp ecx, 3
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
    // 0045452a  7e05                   -jle 0x454531
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454531;
    }
    // 0045452c  8d41fc                 -lea eax, [ecx - 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0045452f  eb05                   -jmp 0x454536
    goto L_0x00454536;
L_0x00454531:
    // 00454531  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
L_0x00454536:
    // 00454536  a384476600             -mov dword ptr [0x664784], eax
    app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */) = cpu.eax;
L_0x0045453b:
    // 0045453b  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
    // 00454540  a38c476600             -mov dword ptr [0x66478c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702988) /* 0x66478c */) = cpu.eax;
    // 00454545  a184476600             -mov eax, dword ptr [0x664784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */);
    // 0045454a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045454c  a390476600             -mov dword ptr [0x664790], eax
    app->getMemory<x86::reg32>(x86::reg32(6702992) /* 0x664790 */) = cpu.eax;
    // 00454551  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
    // 00454556  e895feffff             -call 0x4543f0
    cpu.esp -= 4;
    sub_4543f0(app, cpu);
    if (cpu.terminate) return;
    // 0045455b  a3ac955500             -mov dword ptr [0x5595ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5608876) /* 0x5595ac */) = cpu.eax;
    // 00454560  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454562  a184476600             -mov eax, dword ptr [0x664784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */);
    // 00454567  e884feffff             -call 0x4543f0
    cpu.esp -= 4;
    sub_4543f0(app, cpu);
    if (cpu.terminate) return;
    // 0045456c  a3b0955500             -mov dword ptr [0x5595b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5608880) /* 0x5595b0 */) = cpu.eax;
    // 00454571  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454573  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454574  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454575  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454576  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_454580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454580  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454581  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454582  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454583  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454584  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454586  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00454589  833d6c29660009         +cmp dword ptr [0x66296c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695276) /* 0x66296c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454590  742d                   -je 0x4545bf
    if (cpu.flags.zf)
    {
        goto L_0x004545bf;
    }
    // 00454592  e869efffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 00454597  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454599  740a                   -je 0x4545a5
    if (cpu.flags.zf)
    {
        goto L_0x004545a5;
    }
    // 0045459b  e860efffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 004545a0  a388476600             -mov dword ptr [0x664788], eax
    app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */) = cpu.eax;
L_0x004545a5:
    // 004545a5  8b0dd4d46f00           -mov ecx, dword ptr [0x6fd4d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 004545ab  83f903                 +cmp ecx, 3
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
    // 004545ae  7e05                   -jle 0x4545b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004545b5;
    }
    // 004545b0  8d41fc                 -lea eax, [ecx - 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004545b3  eb05                   -jmp 0x4545ba
    goto L_0x004545ba;
L_0x004545b5:
    // 004545b5  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
L_0x004545ba:
    // 004545ba  a384476600             -mov dword ptr [0x664784], eax
    app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */) = cpu.eax;
L_0x004545bf:
    // 004545bf  68b42d7a00             -push 0x7a2db4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007092 /*0x7a2db4*/;
    cpu.esp -= 4;
    // 004545c4  6864985300             -push 0x539864
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478500 /*0x539864*/;
    cpu.esp -= 4;
    // 004545c9  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004545cc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004545ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004545cf  891dd4955500           -mov dword ptr [0x5595d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */) = cpu.ebx;
    // 004545d5  891d74955500           -mov dword ptr [0x559574], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608820) /* 0x559574 */) = cpu.ebx;
    // 004545db  e8b0b00800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004545e0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004545e3  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004545e6  e8a566ffff             -call 0x44ac90
    cpu.esp -= 4;
    sub_44ac90(app, cpu);
    if (cpu.terminate) return;
    // 004545eb  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 004545f2  7407                   -je 0x4545fb
    if (cpu.flags.zf)
    {
        goto L_0x004545fb;
    }
    // 004545f4  ba74985300             -mov edx, 0x539874
    cpu.edx = 5478516 /*0x539874*/;
    // 004545f9  eb05                   -jmp 0x454600
    goto L_0x00454600;
L_0x004545fb:
    // 004545fb  ba7c985300             -mov edx, 0x53987c
    cpu.edx = 5478524 /*0x53987c*/;
L_0x00454600:
    // 00454600  e8dbab0900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454605  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454607  e8841d0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 0045460c  a3b8955500             -mov dword ptr [0x5595b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5608888) /* 0x5595b8 */) = cpu.eax;
    // 00454611  b884985300             -mov eax, 0x539884
    cpu.eax = 5478532 /*0x539884*/;
    // 00454616  e895170800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045461b  66a39c476600           -mov word ptr [0x66479c], ax
    app->getMemory<x86::reg16>(x86::reg32(6703004) /* 0x66479c */) = cpu.ax;
    // 00454621  b88c985300             -mov eax, 0x53988c
    cpu.eax = 5478540 /*0x53988c*/;
    // 00454626  e885170800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045462b  66a3a2476600           -mov word ptr [0x6647a2], ax
    app->getMemory<x86::reg16>(x86::reg32(6703010) /* 0x6647a2 */) = cpu.ax;
    // 00454631  b894985300             -mov eax, 0x539894
    cpu.eax = 5478548 /*0x539894*/;
    // 00454636  e875170800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045463b  66a3a0476600           -mov word ptr [0x6647a0], ax
    app->getMemory<x86::reg16>(x86::reg32(6703008) /* 0x6647a0 */) = cpu.ax;
    // 00454641  b89c985300             -mov eax, 0x53989c
    cpu.eax = 5478556 /*0x53989c*/;
    // 00454646  e865170800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045464b  66a39e476600           -mov word ptr [0x66479e], ax
    app->getMemory<x86::reg16>(x86::reg32(6703006) /* 0x66479e */) = cpu.ax;
    // 00454651  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454653  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00454655  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454656  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454657  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454658  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454659  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_454660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454660  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454661  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454662  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454663  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454665  8b1570955500           -mov edx, dword ptr [0x559570]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608816) /* 0x559570 */);
    // 0045466b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045466d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0045466f  7510                   -jne 0x454681
    if (!cpu.flags.zf)
    {
        goto L_0x00454681;
    }
    // 00454671  b928975300             -mov ecx, 0x539728
    cpu.ecx = 5478184 /*0x539728*/;
    // 00454676  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0045467b  890d24925500           -mov dword ptr [0x559224], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607972) /* 0x559224 */) = cpu.ecx;
L_0x00454681:
    // 00454681  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454682  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454683  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454684  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_454690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454691  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454692  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454693  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454694  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454695  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454697  8b1570955500           -mov edx, dword ptr [0x559570]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608816) /* 0x559570 */);
    // 0045469d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045469f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004546a1  740f                   -je 0x4546b2
    if (cpu.flags.zf)
    {
        goto L_0x004546b2;
    }
    // 004546a3  c7052492550030975300   -mov dword ptr [0x559224], 0x539730
    app->getMemory<x86::reg32>(x86::reg32(5607972) /* 0x559224 */) = 5478192 /*0x539730*/;
    // 004546ad  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
L_0x004546b2:
    // 004546b2  8b1d8c476600           -mov ebx, dword ptr [0x66478c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6702988) /* 0x66478c */);
    // 004546b8  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
    // 004546bd  39d8                   +cmp eax, ebx
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
    // 004546bf  7415                   -je 0x4546d6
    if (cpu.flags.zf)
    {
        goto L_0x004546d6;
    }
    // 004546c1  8b15ac955500           -mov edx, dword ptr [0x5595ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608876) /* 0x5595ac */);
    // 004546c7  a38c476600             -mov dword ptr [0x66478c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702988) /* 0x66478c */) = cpu.eax;
    // 004546cc  e81ffdffff             -call 0x4543f0
    cpu.esp -= 4;
    sub_4543f0(app, cpu);
    if (cpu.terminate) return;
    // 004546d1  a3ac955500             -mov dword ptr [0x5595ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5608876) /* 0x5595ac */) = cpu.eax;
L_0x004546d6:
    // 004546d6  8b3590476600           -mov esi, dword ptr [0x664790]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6702992) /* 0x664790 */);
    // 004546dc  a184476600             -mov eax, dword ptr [0x664784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */);
    // 004546e1  39f0                   +cmp eax, esi
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
    // 004546e3  7415                   -je 0x4546fa
    if (cpu.flags.zf)
    {
        goto L_0x004546fa;
    }
    // 004546e5  8b15b0955500           -mov edx, dword ptr [0x5595b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608880) /* 0x5595b0 */);
    // 004546eb  a390476600             -mov dword ptr [0x664790], eax
    app->getMemory<x86::reg32>(x86::reg32(6702992) /* 0x664790 */) = cpu.eax;
    // 004546f0  e8fbfcffff             -call 0x4543f0
    cpu.esp -= 4;
    sub_4543f0(app, cpu);
    if (cpu.terminate) return;
    // 004546f5  a3b0955500             -mov dword ptr [0x5595b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5608880) /* 0x5595b0 */) = cpu.eax;
L_0x004546fa:
    // 004546fa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004546fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004546fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004546fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004546ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454700  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454701  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_454710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454710  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454711  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454713  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454715  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454716  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_454730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00454730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454731  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454732  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454733  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454735  8b0d70955500           -mov ecx, dword ptr [0x559570]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608816) /* 0x559570 */);
    // 0045473b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045473d  83f904                 +cmp ecx, 4
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
    // 00454740  7734                   -ja 0x454776
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00454776;
    }
    // 00454742  ff248d18474500         -jmp dword ptr [ecx*4 + 0x454718]
    cpu.ip = app->getMemory<x86::reg32>(4540184 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00454749:
    // 00454749  e8e24ffeff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0045474e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454750  7524                   -jne 0x454776
    if (!cpu.flags.zf)
    {
        goto L_0x00454776;
    }
    // 00454752  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00454757  eb1d                   -jmp 0x454776
    goto L_0x00454776;
  case 0x00454759:
    // 00454759  e8d24ffeff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0045475e  83f801                 +cmp eax, 1
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
    // 00454761  7513                   -jne 0x454776
    if (!cpu.flags.zf)
    {
        goto L_0x00454776;
    }
    // 00454763  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00454765  eb0f                   -jmp 0x454776
    goto L_0x00454776;
  case 0x00454767:
    // 00454767  e8c44ffeff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0045476c  83f802                 +cmp eax, 2
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
    // 0045476f  7505                   -jne 0x454776
    if (!cpu.flags.zf)
    {
        goto L_0x00454776;
    }
  [[fallthrough]];
  case 0x00454771:
    // 00454771  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00454776:
    // 00454776  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454778  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454779  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045477a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045477b  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_454780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454784  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00454785  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454786  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454788  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0045478b  e86056ffff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00454790  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454792  7407                   -je 0x45479b
    if (cpu.flags.zf)
    {
        goto L_0x0045479b;
    }
    // 00454794  ba964a0000             -mov edx, 0x4a96
    cpu.edx = 19094 /*0x4a96*/;
    // 00454799  eb05                   -jmp 0x4547a0
    goto L_0x004547a0;
L_0x0045479b:
    // 0045479b  ba40e4ff00             -mov edx, 0xffe440
    cpu.edx = 16770112 /*0xffe440*/;
L_0x004547a0:
    // 004547a0  e82b44feff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 004547a5  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004547a8  8b15504f5500           -mov edx, dword ptr [0x554f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590864) /* 0x554f50 */);
    // 004547ae  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004547b0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004547b2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004547b4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x004547b7:
    // 004547b7  3b75f8                 +cmp esi, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004547ba  7d0f                   -jge 0x4547cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004547cb;
    }
    // 004547bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004547be  e86dffffff             -call 0x454730
    cpu.esp -= 4;
    sub_454730(app, cpu);
    if (cpu.terminate) return;
    // 004547c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004547c5  7401                   -je 0x4547c8
    if (cpu.flags.zf)
    {
        goto L_0x004547c8;
    }
    // 004547c7  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004547c8:
    // 004547c8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004547c9  ebec                   -jmp 0x4547b7
    goto L_0x004547b7;
L_0x004547cb:
    // 004547cb  a1d4955500             -mov eax, dword ptr [0x5595d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */);
    // 004547d0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004547d2  83f812                 +cmp eax, 0x12
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
    // 004547d5  7d0a                   -jge 0x4547e1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004547e1;
    }
    // 004547d7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004547d9  891dd4955500           -mov dword ptr [0x5595d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */) = cpu.ebx;
    // 004547df  eb60                   -jmp 0x454841
    goto L_0x00454841;
L_0x004547e1:
    // 004547e1  833dd495550000         +cmp dword ptr [0x5595d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004547e8  7e57                   -jle 0x454841
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454841;
    }
    // 004547ea  bb9d000000             -mov ebx, 0x9d
    cpu.ebx = 157 /*0x9d*/;
    // 004547ef  a19a476600             -mov eax, dword ptr [0x66479a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703002) /* 0x66479a */);
    // 004547f4  bab9000000             -mov edx, 0xb9
    cpu.edx = 185 /*0xb9*/;
    // 004547f9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004547fc  b90f000000             -mov ecx, 0xf
    cpu.ecx = 15 /*0xf*/;
    // 00454801  e88a310800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454806  ba9b000000             -mov edx, 0x9b
    cpu.edx = 155 /*0x9b*/;
    // 0045480b  b8b7000000             -mov eax, 0xb7
    cpu.eax = 183 /*0xb7*/;
    // 00454810  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00454812  e8297a0400             -call 0x49c240
    cpu.esp -= 4;
    sub_49c240(app, cpu);
    if (cpu.terminate) return;
    // 00454817  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454819  7426                   -je 0x454841
    if (cpu.flags.zf)
    {
        goto L_0x00454841;
    }
    // 0045481b  bb9d000000             -mov ebx, 0x9d
    cpu.ebx = 157 /*0x9d*/;
    // 00454820  a19e476600             -mov eax, dword ptr [0x66479e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703006) /* 0x66479e */);
    // 00454825  bab9000000             -mov edx, 0xb9
    cpu.edx = 185 /*0xb9*/;
    // 0045482a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045482d  e85e310800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454832  833d5846660000         +cmp dword ptr [0x664658], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702680) /* 0x664658 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454839  7406                   -je 0x454841
    if (cpu.flags.zf)
    {
        goto L_0x00454841;
    }
    // 0045483b  ff0dd4955500           -dec dword ptr [0x5595d4]
    (app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */))--;
L_0x00454841:
    // 00454841  a1d4955500             -mov eax, dword ptr [0x5595d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */);
    // 00454846  83c012                 -add eax, 0x12
    (cpu.eax) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 00454849  39f8                   +cmp eax, edi
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
    // 0045484b  7d57                   -jge 0x4548a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004548a4;
    }
    // 0045484d  bb9c010000             -mov ebx, 0x19c
    cpu.ebx = 412 /*0x19c*/;
    // 00454852  a1a0476600             -mov eax, dword ptr [0x6647a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703008) /* 0x6647a0 */);
    // 00454857  bab9000000             -mov edx, 0xb9
    cpu.edx = 185 /*0xb9*/;
    // 0045485c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045485f  b90f000000             -mov ecx, 0xf
    cpu.ecx = 15 /*0xf*/;
    // 00454864  e827310800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454869  ba9a010000             -mov edx, 0x19a
    cpu.edx = 410 /*0x19a*/;
    // 0045486e  b8b7000000             -mov eax, 0xb7
    cpu.eax = 183 /*0xb7*/;
    // 00454873  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00454875  e8c6790400             -call 0x49c240
    cpu.esp -= 4;
    sub_49c240(app, cpu);
    if (cpu.terminate) return;
    // 0045487a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045487c  7426                   -je 0x4548a4
    if (cpu.flags.zf)
    {
        goto L_0x004548a4;
    }
    // 0045487e  bb9c010000             -mov ebx, 0x19c
    cpu.ebx = 412 /*0x19c*/;
    // 00454883  a19c476600             -mov eax, dword ptr [0x66479c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703004) /* 0x66479c */);
    // 00454888  bab9000000             -mov edx, 0xb9
    cpu.edx = 185 /*0xb9*/;
    // 0045488d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00454890  e8fb300800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454895  833d5846660000         +cmp dword ptr [0x664658], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702680) /* 0x664658 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045489c  7406                   -je 0x4548a4
    if (cpu.flags.zf)
    {
        goto L_0x004548a4;
    }
    // 0045489e  ff05d4955500           -inc dword ptr [0x5595d4]
    (app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */))++;
L_0x004548a4:
    // 004548a4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004548a6  bf9b000000             -mov edi, 0x9b
    cpu.edi = 155 /*0x9b*/;
    // 004548ab  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004548ae  8b35d4955500           -mov esi, dword ptr [0x5595d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5608916) /* 0x5595d4 */);
L_0x004548b4:
    // 004548b4  3b75f8                 +cmp esi, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004548b7  0f8df6000000           -jge 0x4549b3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004549b3;
    }
    // 004548bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004548bf  e86cfeffff             -call 0x454730
    cpu.esp -= 4;
    sub_454730(app, cpu);
    if (cpu.terminate) return;
    // 004548c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004548c6  0f84e1000000           -je 0x4549ad
    if (cpu.flags.zf)
    {
        goto L_0x004549ad;
    }
    // 004548cc  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004548cf  83fa12                 +cmp edx, 0x12
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004548d2  0f8dd5000000           -jge 0x4549ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004549ad;
    }
    // 004548d8  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004548db  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004548de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004548df  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004548e1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004548e6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004548e8  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004548eb  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004548f0  e8bb51feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 004548f5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004548f7  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
    // 004548fc  e88fd8ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00454901  a174955500             -mov eax, dword ptr [0x559574]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608820) /* 0x559574 */);
    // 00454906  8b148598955500         -mov edx, dword ptr [eax*4 + 0x559598]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608856) /* 0x559598 */ + cpu.eax * 4);
    // 0045490d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045490f  e84c46feff             -call 0x438f60
    cpu.esp -= 4;
    sub_438f60(app, cpu);
    if (cpu.terminate) return;
    // 00454914  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00454916  83f814                 +cmp eax, 0x14
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454919  7e05                   -jle 0x454920
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454920;
    }
    // 0045491b  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
L_0x00454920:
    // 00454920  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00454927  742d                   -je 0x454956
    if (cpu.flags.zf)
    {
        goto L_0x00454956;
    }
    // 00454929  69d29a000000           -imul edx, edx, 0x9a
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(154 /*0x9a*/)));
    // 0045492f  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00454934  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454936  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454939  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045493b  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00454940  8d988c010000           -lea ebx, [eax + 0x18c]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(396) /* 0x18c */);
    // 00454946  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454948  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045494a  e891a20600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 0045494f  ba59010000             -mov edx, 0x159
    cpu.edx = 345 /*0x159*/;
    // 00454954  eb35                   -jmp 0x45498b
    goto L_0x0045498b;
L_0x00454956:
    // 00454956  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045495d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045495f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00454961  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00454964  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00454966  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00454968  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0045496d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454970  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00454972  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00454977  8d9884010000           -lea ebx, [eax + 0x184]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(388) /* 0x184 */);
    // 0045497d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045497f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454981  e85aa20600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 00454986  ba45010000             -mov edx, 0x145
    cpu.edx = 325 /*0x145*/;
L_0x0045498b:
    // 0045498b  a1b8955500             -mov eax, dword ptr [0x5595b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608888) /* 0x5595b8 */);
    // 00454990  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00454992  e8f92f0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454997  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 0045499c  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 004549a1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004549a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004549a5  e836a20600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 004549aa  83c70f                 +add edi, 0xf
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004549ad:
    // 004549ad  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004549ae  e901ffffff             -jmp 0x4548b4
    goto L_0x004548b4;
L_0x004549b3:
    // 004549b3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004549b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004549bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4549c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004549c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004549c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004549c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004549c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004549c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004549c5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004549c7  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004549ca  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004549cf  e88c5cffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004549d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004549d6  0f8409020000           -je 0x454be5
    if (cpu.flags.zf)
    {
        goto L_0x00454be5;
    }
    // 004549dc  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004549de  eb05                   -jmp 0x4549e5
    goto L_0x004549e5;
L_0x004549e0:
    // 004549e0  83fb04                 +cmp ebx, 4
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
    // 004549e3  7d53                   -jge 0x454a38
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00454a38;
    }
L_0x004549e5:
    // 004549e5  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 004549ec  a188476600             -mov eax, dword ptr [0x664788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702984) /* 0x664788 */);
    // 004549f1  8b9698955500           -mov edx, dword ptr [esi + 0x559598]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5608856) /* 0x559598 */);
    // 004549f7  e86445feff             -call 0x438f60
    cpu.esp -= 4;
    sub_438f60(app, cpu);
    if (cpu.terminate) return;
    // 004549fc  89442ed4               -mov dword ptr [esi + ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-44) /* -0x2c */ + cpu.ebp * 1) = cpu.eax;
    // 00454a00  83f814                 +cmp eax, 0x14
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454a03  7e08                   -jle 0x454a0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454a0d;
    }
    // 00454a05  c7442ed414000000       -mov dword ptr [esi + ebp - 0x2c], 0x14
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-44) /* -0x2c */ + cpu.ebp * 1) = 20 /*0x14*/;
L_0x00454a0d:
    // 00454a0d  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 00454a14  a184476600             -mov eax, dword ptr [0x664784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702980) /* 0x664784 */);
    // 00454a19  8b9698955500           -mov edx, dword ptr [esi + 0x559598]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5608856) /* 0x559598 */);
    // 00454a1f  e83c45feff             -call 0x438f60
    cpu.esp -= 4;
    sub_438f60(app, cpu);
    if (cpu.terminate) return;
    // 00454a24  89442ee4               -mov dword ptr [esi + ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-28) /* -0x1c */ + cpu.ebp * 1) = cpu.eax;
    // 00454a28  83f814                 +cmp eax, 0x14
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454a2b  7e08                   -jle 0x454a35
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454a35;
    }
    // 00454a2d  c7442ee414000000       -mov dword ptr [esi + ebp - 0x1c], 0x14
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-28) /* -0x1c */ + cpu.ebp * 1) = 20 /*0x14*/;
L_0x00454a35:
    // 00454a35  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00454a36  eba8                   -jmp 0x4549e0
    goto L_0x004549e0;
L_0x00454a38:
    // 00454a38  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00454a3a  e9ec000000             -jmp 0x454b2b
    goto L_0x00454b2b;
L_0x00454a3f:
    // 00454a3f  3b4c2ad4               +cmp ecx, dword ptr [edx + ebp - 0x2c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-44) /* -0x2c */ + cpu.ebp * 1)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454a43  7d08                   -jge 0x454a4d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00454a4d;
    }
    // 00454a45  a1bc955500             -mov eax, dword ptr [0x5595bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608892) /* 0x5595bc */);
    // 00454a4a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00454a4d:
    // 00454a4d  8b54b5d4               -mov edx, dword ptr [ebp + esi*4 - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */ + cpu.esi * 4);
    // 00454a51  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00454a58  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00454a5a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00454a5d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00454a5f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00454a62  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00454a67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454a69  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454a6c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00454a6e  ba47010000             -mov edx, 0x147
    cpu.edx = 327 /*0x147*/;
    // 00454a73  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00454a78  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00454a7a  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00454a7f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454a81  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00454a83  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454a85  e856a10600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 00454a8a  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00454a91  740d                   -je 0x454aa0
    if (cpu.flags.zf)
    {
        goto L_0x00454aa0;
    }
    // 00454a93  bad6000000             -mov edx, 0xd6
    cpu.edx = 214 /*0xd6*/;
    // 00454a98  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00454a9b  8d5f0e                 -lea ebx, [edi + 0xe]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(14) /* 0xe */);
    // 00454a9e  eb0a                   -jmp 0x454aaa
    goto L_0x00454aaa;
L_0x00454aa0:
    // 00454aa0  bad6000000             -mov edx, 0xd6
    cpu.edx = 214 /*0xd6*/;
    // 00454aa5  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00454aa8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00454aaa:
    // 00454aaa  e8e12e0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454aaf  8b54b5e4               -mov edx, dword ptr [ebp + esi*4 - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */ + cpu.esi * 4);
    // 00454ab3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00454aba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00454abc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00454abf  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00454ac1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00454ac4  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00454ac9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454acb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00454ace  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00454ad0  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00454ad5  8d98af010000           -lea ebx, [eax + 0x1af]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(431) /* 0x1af */);
    // 00454adb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454add  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454adf  e8fca00600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 00454ae4  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00454aeb  7412                   -je 0x454aff
    if (cpu.flags.zf)
    {
        goto L_0x00454aff;
    }
    // 00454aed  ba81010000             -mov edx, 0x181
    cpu.edx = 385 /*0x181*/;
    // 00454af2  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00454af5  8d5f0e                 -lea ebx, [edi + 0xe]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(14) /* 0xe */);
    // 00454af8  e8932e0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00454afd  eb0f                   -jmp 0x454b0e
    goto L_0x00454b0e;
L_0x00454aff:
    // 00454aff  ba54010000             -mov edx, 0x154
    cpu.edx = 340 /*0x154*/;
    // 00454b04  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00454b07  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00454b09  e8522a0800             -call 0x4d7560
    cpu.esp -= 4;
    sub_4d7560(app, cpu);
    if (cpu.terminate) return;
L_0x00454b0e:
    // 00454b0e  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00454b13  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00454b18  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454b1a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454b1c  e8bfa00600             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 00454b21  46                     -inc esi
    (cpu.esi)++;
    // 00454b22  83fe04                 +cmp esi, 4
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
    // 00454b25  0f8d82000000           -jge 0x454bad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00454bad;
    }
L_0x00454b2b:
    // 00454b2b  8a25583a7a00           -mov ah, byte ptr [0x7a3a58]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */);
    // 00454b31  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454b33  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00454b36  7405                   -je 0x454b3d
    if (cpu.flags.zf)
    {
        goto L_0x00454b3d;
    }
    // 00454b38  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
L_0x00454b3d:
    // 00454b3d  8d1c36                 -lea ebx, [esi + esi]
    cpu.ebx = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00454b40  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 00454b45  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00454b47  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00454b4a  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00454b4f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00454b51  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00454b53  8dbb27010000           -lea edi, [ebx + 0x127]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(295) /* 0x127 */);
    // 00454b59  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00454b60  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00454b62  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00454b65  8b80c4955500           -mov eax, dword ptr [eax + 0x5595c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5608900) /* 0x5595c4 */);
    // 00454b6b  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00454b6d  ba7a010000             -mov edx, 0x17a
    cpu.edx = 378 /*0x17a*/;
    // 00454b72  e8d9cc0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00454b77  e814d6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00454b7c  a1b8955500             -mov eax, dword ptr [0x5595b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608888) /* 0x5595b8 */);
    // 00454b81  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00454b84  a1c0955500             -mov eax, dword ptr [0x5595c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608896) /* 0x5595c0 */);
    // 00454b89  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00454b8c  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00454b8f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00454b92  8b4c2ae4               -mov ecx, dword ptr [edx + ebp - 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */ + cpu.ebp * 1);
    // 00454b96  3b4c28d4               +cmp ecx, dword ptr [eax + ebp - 0x2c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-44) /* -0x2c */ + cpu.ebp * 1)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454b9a  0f8e9ffeffff           -jle 0x454a3f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454a3f;
    }
    // 00454ba0  a1b4955500             -mov eax, dword ptr [0x5595b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608884) /* 0x5595b4 */);
    // 00454ba5  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00454ba8  e9a0feffff             -jmp 0x454a4d
    goto L_0x00454a4d;
L_0x00454bad:
    // 00454bad  8b35ac955500           -mov esi, dword ptr [0x5595ac]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5608876) /* 0x5595ac */);
    // 00454bb3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00454bb5  7411                   -je 0x454bc8
    if (cpu.flags.zf)
    {
        goto L_0x00454bc8;
    }
    // 00454bb7  bb4e000000             -mov ebx, 0x4e
    cpu.ebx = 78 /*0x4e*/;
    // 00454bbc  ba7a000000             -mov edx, 0x7a
    cpu.edx = 122 /*0x7a*/;
    // 00454bc1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00454bc3  e8c82d0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00454bc8:
    // 00454bc8  8b3db0955500           -mov edi, dword ptr [0x5595b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5608880) /* 0x5595b0 */);
    // 00454bce  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00454bd0  7411                   -je 0x454be3
    if (cpu.flags.zf)
    {
        goto L_0x00454be3;
    }
    // 00454bd2  bb4e000000             -mov ebx, 0x4e
    cpu.ebx = 78 /*0x4e*/;
    // 00454bd7  ba63010000             -mov edx, 0x163
    cpu.edx = 355 /*0x163*/;
    // 00454bdc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00454bde  e8ad2d0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00454be3:
    // 00454be3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00454be5:
    // 00454be5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00454be7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454be8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454be9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454bea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454beb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454bec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_454bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454bf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454bf1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454bf2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454bf3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454bf5  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00454bfb  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00454c00  e85b5affff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00454c05  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454c07  0f84d2000000           -je 0x454cdf
    if (cpu.flags.zf)
    {
        goto L_0x00454cdf;
    }
    // 00454c0d  68b42d7a00             -push 0x7a2db4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007092 /*0x7a2db4*/;
    cpu.esp -= 4;
    // 00454c12  6864985300             -push 0x539864
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478500 /*0x539864*/;
    cpu.esp -= 4;
    // 00454c17  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00454c1d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00454c1e  e86daa0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00454c23  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00454c26  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00454c2c  e85f60ffff             -call 0x44ac90
    cpu.esp -= 4;
    sub_44ac90(app, cpu);
    if (cpu.terminate) return;
    // 00454c31  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00454c33  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00454c3a  7462                   -je 0x454c9e
    if (cpu.flags.zf)
    {
        goto L_0x00454c9e;
    }
    // 00454c3c  baa4985300             -mov edx, 0x5398a4
    cpu.edx = 5478564 /*0x5398a4*/;
    // 00454c41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454c43  e898a50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454c48  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454c4a  e841170800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454c4f  baac985300             -mov edx, 0x5398ac
    cpu.edx = 5478572 /*0x5398ac*/;
    // 00454c54  a3b4955500             -mov dword ptr [0x5595b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5608884) /* 0x5595b4 */) = cpu.eax;
    // 00454c59  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454c5b  e880a50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454c60  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454c62  e829170800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454c67  bab4985300             -mov edx, 0x5398b4
    cpu.edx = 5478580 /*0x5398b4*/;
    // 00454c6c  a3b8955500             -mov dword ptr [0x5595b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5608888) /* 0x5595b8 */) = cpu.eax;
    // 00454c71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454c73  e868a50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454c78  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454c7a  e811170800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454c7f  babc985300             -mov edx, 0x5398bc
    cpu.edx = 5478588 /*0x5398bc*/;
    // 00454c84  a3bc955500             -mov dword ptr [0x5595bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5608892) /* 0x5595bc */) = cpu.eax;
    // 00454c89  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454c8b  e850a50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454c90  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00454c92  e8f9160800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454c97  a3c0955500             -mov dword ptr [0x5595c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5608896) /* 0x5595c0 */) = cpu.eax;
    // 00454c9c  eb41                   -jmp 0x454cdf
    goto L_0x00454cdf;
L_0x00454c9e:
    // 00454c9e  bac4985300             -mov edx, 0x5398c4
    cpu.edx = 5478596 /*0x5398c4*/;
    // 00454ca3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454ca5  e836a50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454caa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454cac  e8df160800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454cb1  bacc985300             -mov edx, 0x5398cc
    cpu.edx = 5478604 /*0x5398cc*/;
    // 00454cb6  a3b4955500             -mov dword ptr [0x5595b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5608884) /* 0x5595b4 */) = cpu.eax;
    // 00454cbb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454cbd  e81ea50900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00454cc2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454cc4  e8c7160800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00454cc9  8b0db4955500           -mov ecx, dword ptr [0x5595b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608884) /* 0x5595b4 */);
    // 00454ccf  a3b8955500             -mov dword ptr [0x5595b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5608888) /* 0x5595b8 */) = cpu.eax;
    // 00454cd4  a3c0955500             -mov dword ptr [0x5595c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5608896) /* 0x5595c0 */) = cpu.eax;
    // 00454cd9  890dbc955500           -mov dword ptr [0x5595bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608892) /* 0x5595bc */) = cpu.ecx;
L_0x00454cdf:
    // 00454cdf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00454ce1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454ce2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454ce3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454ce4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_454cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454cf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454cf1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454cf2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454cf4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454cf6  e8b57c0100             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00454cfb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00454cfe  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00454d01  e8daf90000             -call 0x4646e0
    cpu.esp -= 4;
    sub_4646e0(app, cpu);
    if (cpu.terminate) return;
    // 00454d06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_454d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454d10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454d11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454d12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454d13  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454d15  bad4985300             -mov edx, 0x5398d4
    cpu.edx = 5478612 /*0x5398d4*/;
    // 00454d1a  e821ddfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00454d1f  baf04c4500             -mov edx, 0x454cf0
    cpu.edx = 4541680 /*0x454cf0*/;
    // 00454d24  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00454d26  e8957d0100             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00454d2b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00454d2d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454d2f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00454d31  e81a7c0100             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 00454d36  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454d38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d39  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454d3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_454d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454d40  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00454d41  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454d43  bae0985300             -mov edx, 0x5398e0
    cpu.edx = 5478624 /*0x5398e0*/;
    // 00454d48  e86361ffff             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00454d4d  e8eedcfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00454d52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454d54  7417                   -je 0x454d6d
    if (cpu.flags.zf)
    {
        goto L_0x00454d6d;
    }
    // 00454d56  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00454d58  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454d5d  0fb78400dc635500       -movzx eax, word ptr [eax + eax + 0x5563dc]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5596124) /* 0x5563dc */ + cpu.eax * 1));
    // 00454d65  e8e6ca0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00454d6a  89423c                 -mov dword ptr [edx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */) = cpu.eax;
L_0x00454d6d:
    // 00454d6d  61                     -popal 
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
    // 00454d6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_454d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454d70  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00454d71  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454d73  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454d78  40                     -inc eax
    (cpu.eax)++;
    // 00454d79  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00454d7c  a394476600             -mov dword ptr [0x664794], eax
    app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */) = cpu.eax;
    // 00454d81  e8baffffff             -call 0x454d40
    cpu.esp -= 4;
    sub_454d40(app, cpu);
    if (cpu.terminate) return;
    // 00454d86  61                     -popal 
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
    // 00454d87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454d89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_454d8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454d8a  90                     -nop 
    ;
    // 00454d8b  90                     -nop 
    ;
    // 00454d8c  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00454d8d  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454d8f  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454d94  48                     -dec eax
    (cpu.eax)--;
    // 00454d95  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00454d98  a394476600             -mov dword ptr [0x664794], eax
    app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */) = cpu.eax;
    // 00454d9d  e89effffff             -call 0x454d40
    cpu.esp -= 4;
    sub_454d40(app, cpu);
    if (cpu.terminate) return;
    // 00454da2  61                     -popal 
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
    // 00454da3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454da5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_454da6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454da6  90                     -nop 
    ;
    // 00454da7  90                     -nop 
    ;
    // 00454da8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454da9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454daa  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454dac  8b1580476600           -mov edx, dword ptr [0x664780]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6702976) /* 0x664780 */);
    // 00454db2  891594476600           -mov dword ptr [0x664794], edx
    app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */) = cpu.edx;
    // 00454db8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00454dba  891598476600           -mov dword ptr [0x664798], edx
    app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */) = cpu.edx;
    // 00454dc0  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454dc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454dc3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454dc4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_454dc6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454dc6  90                     -nop 
    ;
    // 00454dc7  90                     -nop 
    ;
    // 00454dc8  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00454dc9  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454dcb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00454dcd  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454dd2  a380476600             -mov dword ptr [0x664780], eax
    app->getMemory<x86::reg32>(x86::reg32(6702976) /* 0x664780 */) = cpu.eax;
    // 00454dd7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00454dd9  891594476600           -mov dword ptr [0x664794], edx
    app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */) = cpu.edx;
    // 00454ddf  891598476600           -mov dword ptr [0x664798], edx
    app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */) = cpu.edx;
    // 00454de5  bad4985300             -mov edx, 0x5398d4
    cpu.edx = 5478612 /*0x5398d4*/;
    // 00454dea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454dec  e84fdcfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00454df1  baf04c4500             -mov edx, 0x454cf0
    cpu.edx = 4541680 /*0x454cf0*/;
    // 00454df6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00454df8  e8c37c0100             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00454dfd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00454dff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00454e01  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00454e03  e8487b0100             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 00454e08  bac47b5300             -mov edx, 0x537bc4
    cpu.edx = 5471172 /*0x537bc4*/;
    // 00454e0d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454e0f  e82cdcfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00454e14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454e16  7407                   -je 0x454e1f
    if (cpu.flags.zf)
    {
        goto L_0x00454e1f;
    }
    // 00454e18  c740648c4d4500         -mov dword ptr [eax + 0x64], 0x454d8c
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4541836 /*0x454d8c*/;
L_0x00454e1f:
    // 00454e1f  babc7b5300             -mov edx, 0x537bbc
    cpu.edx = 5471164 /*0x537bbc*/;
    // 00454e24  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454e26  e815dcfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00454e2b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454e2d  0f844b890000           -je 0x45d77e
    if (cpu.flags.zf)
    {
        return sub_45d77e(app, cpu);
    }
    // 00454e33  c74064704d4500         -mov dword ptr [eax + 0x64], 0x454d70
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4541808 /*0x454d70*/;
    // 00454e3a  e801ffffff             -call 0x454d40
    cpu.esp -= 4;
    sub_454d40(app, cpu);
    if (cpu.terminate) return;
    // 00454e3f  61                     -popal 
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
    // 00454e40  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00454e42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
/* data blob: 9090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090901e001900140010000c000800040000000c00000008000000060000000500000004000000030000000200000001000000140000000f0000000c0000000a0000000800000004000000030000000200000008000000070000000600000005000000040000000300000002000000010000000a00000009000000080000000700000006000000050000000300000002000000100000000800000006000000000000000000000000000000000000000000000014000000100000000c00000000000000000000000000000000000000000000000100000004000000080000000a00000014000000280000003c0000005000000002000000080000001000000014000000190000003c0000004b00000064000000 */
void Application::sub_455020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455020  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455021  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455023  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455025  742a                   -je 0x455051
    if (cpu.flags.zf)
    {
        goto L_0x00455051;
    }
    // 00455027  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0045502e  7421                   -je 0x455051
    if (cpu.flags.zf)
    {
        goto L_0x00455051;
    }
    // 00455030  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455037  7e18                   -jle 0x455051
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455051;
    }
    // 00455039  8b80f0010000           -mov eax, dword ptr [eax + 0x1f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 0045503f  66833c45ca227a0000     +cmp word ptr [eax*2 + 0x7a22ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004298) /* 0x7a22ca */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00455048  7407                   -je 0x455051
    if (cpu.flags.zf)
    {
        goto L_0x00455051;
    }
    // 0045504a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045504f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455050  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00455051:
    // 00455051  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455053  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455054  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_455060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455060  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455061  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455063  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455064  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_455070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455072  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455073  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455074  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455075  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455076  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455078  e8039f0700             -call 0x4cef80
    cpu.esp -= 4;
    sub_4cef80(app, cpu);
    if (cpu.terminate) return;
    // 0045507d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045507f  0f85ab000000           -jne 0x455130
    if (!cpu.flags.zf)
    {
        goto L_0x00455130;
    }
    // 00455085  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0045508a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045508c  e87f0b0000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 00455091  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00455093:
    // 00455093  3b35307d6700           +cmp esi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455099  7d40                   -jge 0x4550db
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004550db;
    }
    // 0045509b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045509d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045509f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004550a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004550a3  e8280c0000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 004550a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004550aa  742c                   -je 0x4550d8
    if (cpu.flags.zf)
    {
        goto L_0x004550d8;
    }
    // 004550ac  8b9020020000           -mov edx, dword ptr [eax + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 004550b2  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004550b5  668b1475104f4500       -mov dx, word ptr [esi*2 + 0x454f10]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(4542224) /* 0x454f10 */ + cpu.esi * 2);
    // 004550bd  6689144d2ed46f00       -mov word ptr [ecx*2 + 0x6fd42e], dx
    app->getMemory<x86::reg16>(x86::reg32(7328814) /* 0x6fd42e */ + cpu.ecx * 2) = cpu.dx;
    // 004550c5  8b8020020000           -mov eax, dword ptr [eax + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 004550cb  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004550ce  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004550d0  66013c454ed46f00       +add word ptr [eax*2 + 0x6fd44e], di
    {
        auto tmp1 = app->getMemory<x86::reg16>(x86::reg32(7328846) /* 0x6fd44e */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) == (1 & (tmp2 >> 15));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004550d8:
    // 004550d8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004550d9  ebb8                   -jmp 0x455093
    goto L_0x00455093;
L_0x004550db:
    // 004550db  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004550e0  b80ed46f00             -mov eax, 0x6fd40e
    cpu.eax = 7328782 /*0x6fd40e*/;
    // 004550e5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004550ea  e81db60800             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004550ef  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004550f1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004550f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004550f5  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004550f7  e8140b0000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 004550fc  eb05                   -jmp 0x455103
    goto L_0x00455103;
L_0x004550fe:
    // 004550fe  83fe08                 +cmp esi, 8
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
    // 00455101  7f26                   -jg 0x455129
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00455129;
    }
L_0x00455103:
    // 00455103  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00455105  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00455107  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00455109  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045510b  e8c00b0000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455110  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455112  7412                   -je 0x455126
    if (cpu.flags.zf)
    {
        goto L_0x00455126;
    }
    // 00455114  8b8020020000           -mov eax, dword ptr [eax + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 0045511a  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0045511d  66893c450ed46f00       -mov word ptr [eax*2 + 0x6fd40e], di
    app->getMemory<x86::reg16>(x86::reg32(7328782) /* 0x6fd40e */ + cpu.eax * 2) = cpu.di;
    // 00455125  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00455126:
    // 00455126  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455127  ebd5                   -jmp 0x4550fe
    goto L_0x004550fe;
L_0x00455129:
    // 00455129  66ff050cd46f00         -inc word ptr [0x6fd40c]
    (app->getMemory<x86::reg16>(x86::reg32(7328780) /* 0x6fd40c */))++;
L_0x00455130:
    // 00455130  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455131  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455132  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455133  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455134  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455135  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455136  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_455140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455142  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455143  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455144  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455145  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455146  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455148  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045514d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045514f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00455151  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00455156  e8b50a0000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 0045515b  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00455160  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455162  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455164  e8670b0000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455169  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045516b  7426                   -je 0x455193
    if (cpu.flags.zf)
    {
        goto L_0x00455193;
    }
    // 0045516d  833d307d670001         +cmp dword ptr [0x677d30], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455174  7e1d                   -jle 0x455193
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455193;
    }
    // 00455176  8bb020020000           -mov esi, dword ptr [eax + 0x220]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 0045517c  8b7610                 -mov esi, dword ptr [esi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0045517f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455181  66891475ded36f00       -mov word ptr [esi*2 + 0x6fd3de], dx
    app->getMemory<x86::reg16>(x86::reg32(7328734) /* 0x6fd3de */ + cpu.esi * 2) = cpu.dx;
    // 00455189  c780c402000002000000   -mov dword ptr [eax + 0x2c4], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */) = 2 /*0x2*/;
L_0x00455193:
    // 00455193  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00455198  b8bed36f00             -mov eax, 0x6fd3be
    cpu.eax = 7328702 /*0x6fd3be*/;
    // 0045519d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004551a2  e865b50800             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004551a7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004551a9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004551ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004551ad  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004551af  e85c0a0000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 004551b4  eb18                   -jmp 0x4551ce
    goto L_0x004551ce;
L_0x004551b6:
    // 004551b6  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 004551bc  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004551bf  66893c45bed36f00       -mov word ptr [eax*2 + 0x6fd3be], di
    app->getMemory<x86::reg16>(x86::reg32(7328702) /* 0x6fd3be */ + cpu.eax * 2) = cpu.di;
    // 004551c7  47                     -inc edi
    (cpu.edi)++;
L_0x004551c8:
    // 004551c8  46                     -inc esi
    (cpu.esi)++;
    // 004551c9  83fe08                 +cmp esi, 8
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
    // 004551cc  7f32                   -jg 0x455200
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00455200;
    }
L_0x004551ce:
    // 004551ce  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004551d0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004551d2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004551d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004551d6  e8f50a0000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 004551db  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004551dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004551df  74e7                   -je 0x4551c8
    if (cpu.flags.zf)
    {
        goto L_0x004551c8;
    }
    // 004551e1  f6800002000008         +test byte ptr [eax + 0x200], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 8 /*0x8*/));
    // 004551e8  74cc                   -je 0x4551b6
    if (cpu.flags.zf)
    {
        goto L_0x004551b6;
    }
    // 004551ea  8b8020020000           -mov eax, dword ptr [eax + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 004551f0  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004551f3  66833c45ded36f0000     +cmp word ptr [eax*2 + 0x6fd3de], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(7328734) /* 0x6fd3de */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004551fc  74ca                   -je 0x4551c8
    if (cpu.flags.zf)
    {
        goto L_0x004551c8;
    }
    // 004551fe  ebb6                   -jmp 0x4551b6
    goto L_0x004551b6;
L_0x00455200:
    // 00455200  66ff05bcd36f00         -inc word ptr [0x6fd3bc]
    (app->getMemory<x86::reg16>(x86::reg32(7328700) /* 0x6fd3bc */))++;
    // 00455207  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455208  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455209  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045520a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045520b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045520c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045520d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_455210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455210  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455212  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455213  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455214  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455215  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455217  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045521a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0045521d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00455223  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00455225:
    // 00455225  3b1d9cfd5e00           +cmp ebx, dword ptr [0x5efd9c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225308) /* 0x5efd9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045522b  7d4a                   -jge 0x455277
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455277;
    }
    // 0045522d  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 00455234  8b86c8fa5e00           -mov eax, dword ptr [esi + 0x5efac8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6224584) /* 0x5efac8 */);
    // 0045523a  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00455241  7431                   -je 0x455274
    if (cpu.flags.zf)
    {
        goto L_0x00455274;
    }
    // 00455243  e8d8fdffff             -call 0x455020
    cpu.esp -= 4;
    sub_455020(app, cpu);
    if (cpu.terminate) return;
    // 00455248  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045524a  7528                   -jne 0x455274
    if (!cpu.flags.zf)
    {
        goto L_0x00455274;
    }
    // 0045524c  6902ac090000           -imul eax, dword ptr [edx], 0x9ac
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx))) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455252  b9ac090000             -mov ecx, 0x9ac
    cpu.ecx = 2476 /*0x9ac*/;
    // 00455257  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045525a  8bb6c8fa5e00           -mov esi, dword ptr [esi + 0x5efac8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6224584) /* 0x5efac8 */);
    // 00455260  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00455262  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455263  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00455265  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00455268  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0045526a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0045526c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0045526f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00455271  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455272  ff02                   +inc dword ptr [edx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.edx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00455274:
    // 00455274  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455275  ebae                   -jmp 0x455225
    goto L_0x00455225;
L_0x00455277:
    // 00455277  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455279  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045527a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045527b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045527c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045527d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045527e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_455280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455282  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455283  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455284  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455285  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455287  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045528a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0045528d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00455293  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00455295:
    // 00455295  3b1d9cfd5e00           +cmp ebx, dword ptr [0x5efd9c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225308) /* 0x5efd9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045529b  7d4a                   -jge 0x4552e7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004552e7;
    }
    // 0045529d  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 004552a4  8b86c8fa5e00           -mov eax, dword ptr [esi + 0x5efac8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6224584) /* 0x5efac8 */);
    // 004552aa  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 004552b1  7431                   -je 0x4552e4
    if (cpu.flags.zf)
    {
        goto L_0x004552e4;
    }
    // 004552b3  e868fdffff             -call 0x455020
    cpu.esp -= 4;
    sub_455020(app, cpu);
    if (cpu.terminate) return;
    // 004552b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004552ba  7528                   -jne 0x4552e4
    if (!cpu.flags.zf)
    {
        goto L_0x004552e4;
    }
    // 004552bc  6902ac090000           -imul eax, dword ptr [edx], 0x9ac
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx))) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 004552c2  b9ac090000             -mov ecx, 0x9ac
    cpu.ecx = 2476 /*0x9ac*/;
    // 004552c7  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004552ca  8bb6c8fa5e00           -mov esi, dword ptr [esi + 0x5efac8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6224584) /* 0x5efac8 */);
    // 004552d0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004552d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004552d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004552d5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004552d8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004552da  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004552dc  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004552df  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004552e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552e2  ff02                   +inc dword ptr [edx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.edx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004552e4:
    // 004552e4  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004552e5  ebae                   -jmp 0x455295
    goto L_0x00455295;
L_0x004552e7:
    // 004552e7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004552e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004552ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4552f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004552f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004552f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004552f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004552f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004552f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004552f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004552f6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004552f8  833db8d36f0002         +cmp dword ptr [0x6fd3b8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004552ff  753f                   -jne 0x455340
    if (!cpu.flags.zf)
    {
        goto L_0x00455340;
    }
    // 00455301  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00455306  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455308  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0045530a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045530c  e8ff080000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
L_0x00455311:
    // 00455311  3b35307d6700           +cmp esi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455317  7d27                   -jge 0x455340
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455340;
    }
    // 00455319  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045531b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045531d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045531f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455321  e8aa090000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455326  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455328  7413                   -je 0x45533d
    if (cpu.flags.zf)
    {
        goto L_0x0045533d;
    }
    // 0045532a  f6800002000080         +test byte ptr [eax + 0x200], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 128 /*0x80*/));
    // 00455331  740a                   -je 0x45533d
    if (cpu.flags.zf)
    {
        goto L_0x0045533d;
    }
    // 00455333  c780c402000002000000   -mov dword ptr [eax + 0x2c4], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */) = 2 /*0x2*/;
L_0x0045533d:
    // 0045533d  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045533e  ebd1                   -jmp 0x455311
    goto L_0x00455311;
L_0x00455340:
    // 00455340  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00455345  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455347  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00455349  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0045534e  e8bd080000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 00455353  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00455358  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045535a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045535c  e86f090000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455361  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455363  745f                   -je 0x4553c4
    if (cpu.flags.zf)
    {
        goto L_0x004553c4;
    }
    // 00455365  8bb038020000           -mov esi, dword ptr [eax + 0x238]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(568) /* 0x238 */);
    // 0045536b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0045536d  83c63c                 -add esi, 0x3c
    (cpu.esi) += x86::reg32(x86::sreg32(60 /*0x3c*/));
L_0x00455370:
    // 00455370  3b3d307d6700           +cmp edi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455376  7d21                   -jge 0x455399
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455399;
    }
    // 00455378  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0045537d  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00455382  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00455384  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455386  e845090000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 0045538b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045538d  7407                   -je 0x455396
    if (cpu.flags.zf)
    {
        goto L_0x00455396;
    }
    // 0045538f  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455390  89b038020000           -mov dword ptr [eax + 0x238], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(568) /* 0x238 */) = cpu.esi;
L_0x00455396:
    // 00455396  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455397  ebd7                   -jmp 0x455370
    goto L_0x00455370;
L_0x00455399:
    // 00455399  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0045539b:
    // 0045539b  3b3d307d6700           +cmp edi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004553a1  7d21                   -jge 0x4553c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004553c4;
    }
    // 004553a3  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004553a8  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004553ad  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004553af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004553b1  e81a090000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 004553b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004553b8  7407                   -je 0x4553c1
    if (cpu.flags.zf)
    {
        goto L_0x004553c1;
    }
    // 004553ba  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004553bb  89b038020000           -mov dword ptr [eax + 0x238], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(568) /* 0x238 */) = cpu.esi;
L_0x004553c1:
    // 004553c1  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004553c2  ebd7                   -jmp 0x45539b
    goto L_0x0045539b;
L_0x004553c4:
    // 004553c4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004553c9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004553cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004553cd  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004553d2  e839080000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 004553d7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004553d9:
    // 004553d9  3b35307d6700           +cmp esi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004553df  7d1b                   -jge 0x4553fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004553fc;
    }
    // 004553e1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004553e3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004553e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004553e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004553e9  e8e2080000             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 004553ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004553f0  7406                   -je 0x4553f8
    if (cpu.flags.zf)
    {
        goto L_0x004553f8;
    }
    // 004553f2  89b8bc020000           -mov dword ptr [eax + 0x2bc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(700) /* 0x2bc */) = cpu.edi;
L_0x004553f8:
    // 004553f8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004553f9  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004553fa  ebdd                   -jmp 0x4553d9
    goto L_0x004553d9;
L_0x004553fc:
    // 004553fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004553fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004553fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004553ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455400  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455401  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455402  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_455410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455411  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455412  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455413  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455414  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455416  833da0d36f0000         +cmp dword ptr [0x6fd3a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328672) /* 0x6fd3a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045541d  0f85af000000           -jne 0x4554d2
    if (!cpu.flags.zf)
    {
        goto L_0x004554d2;
    }
    // 00455423  e8782a0700             -call 0x4c7ea0
    cpu.esp -= 4;
    sub_4c7ea0(app, cpu);
    if (cpu.terminate) return;
    // 00455428  e8a393ffff             -call 0x44e7d0
    cpu.esp -= 4;
    sub_44e7d0(app, cpu);
    if (cpu.terminate) return;
    // 0045542d  e8dea0ffff             -call 0x44f510
    cpu.esp -= 4;
    sub_44f510(app, cpu);
    if (cpu.terminate) return;
    // 00455432  ba307d6700             -mov edx, 0x677d30
    cpu.edx = 6782256 /*0x677d30*/;
    // 00455437  b8b0476600             -mov eax, 0x6647b0
    cpu.eax = 6703024 /*0x6647b0*/;
    // 0045543c  e8cffdffff             -call 0x455210
    cpu.esp -= 4;
    sub_455210(app, cpu);
    if (cpu.terminate) return;
    // 00455441  ba347d6700             -mov edx, 0x677d34
    cpu.edx = 6782260 /*0x677d34*/;
    // 00455446  b870e26600             -mov eax, 0x66e270
    cpu.eax = 6742640 /*0x66e270*/;
    // 0045544b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045544d  e82efeffff             -call 0x455280
    cpu.esp -= 4;
    sub_455280(app, cpu);
    if (cpu.terminate) return;
    // 00455452  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455454  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00455456  e8b5070000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 0045545b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00455460  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00455462  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455464  e8a7070000             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 00455469  e882feffff             -call 0x4552f0
    cpu.esp -= 4;
    sub_4552f0(app, cpu);
    if (cpu.terminate) return;
    // 0045546e  833db8d36f0001         +cmp dword ptr [0x6fd3b8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455475  7505                   -jne 0x45547c
    if (!cpu.flags.zf)
    {
        goto L_0x0045547c;
    }
    // 00455477  e8f4fbffff             -call 0x455070
    cpu.esp -= 4;
    sub_455070(app, cpu);
    if (cpu.terminate) return;
L_0x0045547c:
    // 0045547c  833db8d36f0002         +cmp dword ptr [0x6fd3b8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455483  7505                   -jne 0x45548a
    if (!cpu.flags.zf)
    {
        goto L_0x0045548a;
    }
    // 00455485  e8b6fcffff             -call 0x455140
    cpu.esp -= 4;
    sub_455140(app, cpu);
    if (cpu.terminate) return;
L_0x0045548a:
    // 0045548a  e821a5ffff             -call 0x44f9b0
    cpu.esp -= 4;
    sub_44f9b0(app, cpu);
    if (cpu.terminate) return;
    // 0045548f  e8ec9a0700             -call 0x4cef80
    cpu.esp -= 4;
    sub_4cef80(app, cpu);
    if (cpu.terminate) return;
    // 00455494  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455496  751e                   -jne 0x4554b6
    if (!cpu.flags.zf)
    {
        goto L_0x004554b6;
    }
    // 00455498  e853beffff             -call 0x4512f0
    cpu.esp -= 4;
    sub_4512f0(app, cpu);
    if (cpu.terminate) return;
    // 0045549d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045549f  e87c93ffff             -call 0x44e820
    cpu.esp -= 4;
    sub_44e820(app, cpu);
    if (cpu.terminate) return;
    // 004554a4  8b35b0d36f00           -mov esi, dword ptr [0x6fd3b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 004554aa  83fe01                 +cmp esi, 1
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
    // 004554ad  7507                   -jne 0x4554b6
    if (!cpu.flags.zf)
    {
        goto L_0x004554b6;
    }
    // 004554af  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004554b1  e86a93ffff             -call 0x44e820
    cpu.esp -= 4;
    sub_44e820(app, cpu);
    if (cpu.terminate) return;
L_0x004554b6:
    // 004554b6  e835a1ffff             -call 0x44f5f0
    cpu.esp -= 4;
    sub_44f5f0(app, cpu);
    if (cpu.terminate) return;
    // 004554bb  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004554c2  7e0e                   -jle 0x4554d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004554d2;
    }
    // 004554c4  e8b79a0700             -call 0x4cef80
    cpu.esp -= 4;
    sub_4cef80(app, cpu);
    if (cpu.terminate) return;
    // 004554c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004554cb  7505                   -jne 0x4554d2
    if (!cpu.flags.zf)
    {
        goto L_0x004554d2;
    }
    // 004554cd  e88efbffff             -call 0x455060
    cpu.esp -= 4;
    sub_455060(app, cpu);
    if (cpu.terminate) return;
L_0x004554d2:
    // 004554d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004554d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004554d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004554d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004554d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4554e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004554e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004554e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004554e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004554e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004554e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004554e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004554e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004554ea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004554ec  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004554ef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004554f1:
    // 004554f1  3b048d307d6700         +cmp eax, dword ptr [ecx*4 + 0x677d30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.ecx * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004554f8  7d28                   -jge 0x455522
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455522;
    }
    // 004554fa  69d0ac090000           -imul edx, eax, 0x9ac
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455500  69d9c09a0000           -imul ebx, ecx, 0x9ac0
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(39616 /*0x9ac0*/)));
    // 00455506  8d3413                 -lea esi, [ebx + edx]
    cpu.esi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00455509  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045550c  3bbea0496600           +cmp edi, dword ptr [esi + 0x6649a0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6703520) /* 0x6649a0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455512  750b                   -jne 0x45551f
    if (!cpu.flags.zf)
    {
        goto L_0x0045551f;
    }
    // 00455514  b8b0476600             -mov eax, 0x6647b0
    cpu.eax = 6703024 /*0x6647b0*/;
    // 00455519  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0045551b  01d0                   +add eax, edx
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
    // 0045551d  eb05                   -jmp 0x455524
    goto L_0x00455524;
L_0x0045551f:
    // 0045551f  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455520  ebcf                   -jmp 0x4554f1
    goto L_0x004554f1;
L_0x00455522:
    // 00455522  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00455524:
    // 00455524  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455526  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455527  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455528  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455529  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045552a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045552b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_455530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455530  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455531  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455532  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455534  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455536  742a                   -je 0x455562
    if (cpu.flags.zf)
    {
        goto L_0x00455562;
    }
    // 00455538  8b8820020000           -mov ecx, dword ptr [eax + 0x220]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 0045553e  8b4910                 -mov ecx, dword ptr [ecx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00455541  8b0c4d2cd46f00         -mov ecx, dword ptr [ecx*2 + 0x6fd42c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328812) /* 0x6fd42c */ + cpu.ecx * 2);
    // 00455548  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0045554b  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0045554d  8b8020020000           -mov eax, dword ptr [eax + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 00455553  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455556  8b04454cd46f00         -mov eax, dword ptr [eax*2 + 0x6fd44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328844) /* 0x6fd44c */ + cpu.eax * 2);
    // 0045555d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455560  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00455562:
    // 00455562  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455563  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_455570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455570  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455571  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455572  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455573  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455575  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00455577  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0045557a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045557c  743b                   -je 0x4555b9
    if (cpu.flags.zf)
    {
        goto L_0x004555b9;
    }
    // 0045557e  8b90f0010000           -mov edx, dword ptr [eax + 0x1f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 00455584  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045558b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045558d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00455590  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00455592  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00455595  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455597  052cd56f00             -add eax, 0x6fd52c
    (cpu.eax) += x86::reg32(x86::sreg32(7329068 /*0x6fd52c*/));
    // 0045559c  8d7034                 -lea esi, [eax + 0x34]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0045559f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004555a0:
    // 004555a0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004555a2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004555a4  3c00                   +cmp al, 0
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
    // 004555a6  7410                   -je 0x4555b8
    if (cpu.flags.zf)
    {
        goto L_0x004555b8;
    }
    // 004555a8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004555ab  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004555ae  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004555b1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004555b4  3c00                   +cmp al, 0
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
    // 004555b6  75e8                   -jne 0x4555a0
    if (!cpu.flags.zf)
    {
        goto L_0x004555a0;
    }
L_0x004555b8:
    // 004555b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004555b9:
    // 004555b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4555c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004555c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004555c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004555c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004555c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004555c5  8b80bc020000           -mov eax, dword ptr [eax + 0x2bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(700) /* 0x2bc */);
    // 004555cb  83c02f                 -add eax, 0x2f
    (cpu.eax) += x86::reg32(x86::sreg32(47 /*0x2f*/));
    // 004555ce  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004555d0  e87bc20700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004555d5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004555d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004555d8:
    // 004555d8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004555da  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004555dc  3c00                   +cmp al, 0
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
    // 004555de  7410                   -je 0x4555f0
    if (cpu.flags.zf)
    {
        goto L_0x004555f0;
    }
    // 004555e0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004555e3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004555e6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004555e9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004555ec  3c00                   +cmp al, 0
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
    // 004555ee  75e8                   -jne 0x4555d8
    if (!cpu.flags.zf)
    {
        goto L_0x004555d8;
    }
L_0x004555f0:
    // 004555f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004555f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_455600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455600  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455601  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455602  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455603  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455605  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00455607  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0045560a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045560c  7442                   -je 0x455650
    if (cpu.flags.zf)
    {
        goto L_0x00455650;
    }
    // 0045560e  8b90f0010000           -mov edx, dword ptr [eax + 0x1f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 00455614  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045561b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045561d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00455620  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00455622  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00455625  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455627  052cd56f00             -add eax, 0x6fd52c
    (cpu.eax) += x86::reg32(x86::sreg32(7329068 /*0x6fd52c*/));
    // 0045562c  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0045562f  e81c3cfeff             -call 0x439250
    cpu.esp -= 4;
    sub_439250(app, cpu);
    if (cpu.terminate) return;
    // 00455634  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00455636  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00455637:
    // 00455637  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00455639  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045563b  3c00                   +cmp al, 0
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
    // 0045563d  7410                   -je 0x45564f
    if (cpu.flags.zf)
    {
        goto L_0x0045564f;
    }
    // 0045563f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00455642  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00455645  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00455648  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045564b  3c00                   +cmp al, 0
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
    // 0045564d  75e8                   -jne 0x455637
    if (!cpu.flags.zf)
    {
        goto L_0x00455637;
    }
L_0x0045564f:
    // 0045564f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00455650:
    // 00455650  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455651  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455652  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455653  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_455660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455660  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455661  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455662  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455663  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455665  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00455667  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0045566a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045566c  7444                   -je 0x4556b2
    if (cpu.flags.zf)
    {
        goto L_0x004556b2;
    }
    // 0045566e  8b90f0010000           -mov edx, dword ptr [eax + 0x1f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 00455674  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0045567b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045567d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00455680  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00455682  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00455685  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455687  052cd56f00             -add eax, 0x6fd52c
    (cpu.eax) += x86::reg32(x86::sreg32(7329068 /*0x6fd52c*/));
    // 0045568c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045568e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00455691  e81a44feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00455696  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00455698  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00455699:
    // 00455699  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0045569b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045569d  3c00                   +cmp al, 0
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
    // 0045569f  7410                   -je 0x4556b1
    if (cpu.flags.zf)
    {
        goto L_0x004556b1;
    }
    // 004556a1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004556a4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004556a7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004556aa  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004556ad  3c00                   +cmp al, 0
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
    // 004556af  75e8                   -jne 0x455699
    if (!cpu.flags.zf)
    {
        goto L_0x00455699;
    }
L_0x004556b1:
    // 004556b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004556b2:
    // 004556b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004556b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004556b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004556b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4556c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004556c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004556c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004556c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004556c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004556c5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004556c7  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004556ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004556cc  7447                   -je 0x455715
    if (cpu.flags.zf)
    {
        goto L_0x00455715;
    }
    // 004556ce  8b90f0010000           -mov edx, dword ptr [eax + 0x1f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004556d4  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004556db  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004556dd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004556e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004556e2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004556e5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004556e7  052cd56f00             -add eax, 0x6fd52c
    (cpu.eax) += x86::reg32(x86::sreg32(7329068 /*0x6fd52c*/));
    // 004556ec  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004556f1  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004556f4  e8b743feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 004556f9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004556fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004556fc:
    // 004556fc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004556fe  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00455700  3c00                   +cmp al, 0
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
    // 00455702  7410                   -je 0x455714
    if (cpu.flags.zf)
    {
        goto L_0x00455714;
    }
    // 00455704  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00455707  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045570a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045570d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00455710  3c00                   +cmp al, 0
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
    // 00455712  75e8                   -jne 0x4556fc
    if (!cpu.flags.zf)
    {
        goto L_0x004556fc;
    }
L_0x00455714:
    // 00455714  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00455715:
    // 00455715  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455716  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455717  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455718  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_455720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455720  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455721  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455722  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455724  83ec04                 +sub esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00455727  8b80b8020000           -mov eax, dword ptr [eax + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(696) /* 0x2b8 */);
    // 0045572d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00455730  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00455733  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00455735  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00455737  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00455739  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0045573a  7353                   -jae 0x45578f
    if (!cpu.flags.cf)
    {
        goto L_0x0045578f;
    }
    // 0045573c  8b0d68bc6f00           -mov ecx, dword ptr [0x6fbc68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322728) /* 0x6fbc68 */);
    // 00455742  83f903                 +cmp ecx, 3
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
    // 00455745  7405                   -je 0x45574c
    if (cpu.flags.zf)
    {
        goto L_0x0045574c;
    }
    // 00455747  83f904                 +cmp ecx, 4
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
    // 0045574a  7516                   -jne 0x455762
    if (!cpu.flags.zf)
    {
        goto L_0x00455762;
    }
L_0x0045574c:
    // 0045574c  b857010000             -mov eax, 0x157
    cpu.eax = 343 /*0x157*/;
    // 00455751  e8fac00700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00455756  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00455759  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045575a  d80d10995300           +fmul dword ptr [0x539910]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5478672) /* 0x539910 */));
    // 00455760  eb14                   -jmp 0x455776
    goto L_0x00455776;
L_0x00455762:
    // 00455762  b856010000             -mov eax, 0x156
    cpu.eax = 342 /*0x156*/;
    // 00455767  e8e4c00700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0045576c  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0045576f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455770  d80d14995300           -fmul dword ptr [0x539914]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5478676) /* 0x539914 */));
L_0x00455776:
    // 00455776  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00455779  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0045577c  6800995300             -push 0x539900
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478656 /*0x539900*/;
    cpu.esp -= 4;
    // 00455781  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455782  e8099f0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00455787  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0045578a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045578c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045578d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045578e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045578f:
    // 0045578f  680c995300             -push 0x53990c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478668 /*0x53990c*/;
    cpu.esp -= 4;
    // 00455794  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455795  e8f69e0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045579a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045579d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045579f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004557a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004557a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4557b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004557b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004557b1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004557b3  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 004557b6  740d                   -je 0x4557c5
    if (cpu.flags.zf)
    {
        goto L_0x004557c5;
    }
    // 004557b8  f6800002000002         +test byte ptr [eax + 0x200], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 2 /*0x2*/));
    // 004557bf  7504                   -jne 0x4557c5
    if (!cpu.flags.zf)
    {
        goto L_0x004557c5;
    }
L_0x004557c1:
    // 004557c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004557c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004557c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004557c5:
    // 004557c5  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004557c8  7409                   -je 0x4557d3
    if (cpu.flags.zf)
    {
        goto L_0x004557d3;
    }
    // 004557ca  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004557d1  74ee                   -je 0x4557c1
    if (cpu.flags.zf)
    {
        goto L_0x004557c1;
    }
L_0x004557d3:
    // 004557d3  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004557d6  7409                   -je 0x4557e1
    if (cpu.flags.zf)
    {
        goto L_0x004557e1;
    }
    // 004557d8  f6800002000002         +test byte ptr [eax + 0x200], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 2 /*0x2*/));
    // 004557df  75e0                   -jne 0x4557c1
    if (!cpu.flags.zf)
    {
        goto L_0x004557c1;
    }
L_0x004557e1:
    // 004557e1  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004557e4  7409                   -je 0x4557ef
    if (cpu.flags.zf)
    {
        goto L_0x004557ef;
    }
    // 004557e6  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004557ed  75d2                   -jne 0x4557c1
    if (!cpu.flags.zf)
    {
        goto L_0x004557c1;
    }
L_0x004557ef:
    // 004557ef  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 004557f2  7408                   -je 0x4557fc
    if (cpu.flags.zf)
    {
        goto L_0x004557fc;
    }
    // 004557f4  3b98c4020000           +cmp ebx, dword ptr [eax + 0x2c4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004557fa  75c5                   -jne 0x4557c1
    if (!cpu.flags.zf)
    {
        goto L_0x004557c1;
    }
L_0x004557fc:
    // 004557fc  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004557ff  7408                   -je 0x455809
    if (cpu.flags.zf)
    {
        goto L_0x00455809;
    }
    // 00455801  3b98c4020000           +cmp ebx, dword ptr [eax + 0x2c4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455807  74b8                   -je 0x4557c1
    if (cpu.flags.zf)
    {
        goto L_0x004557c1;
    }
L_0x00455809:
    // 00455809  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0045580e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045580f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_455840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00455840  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455841  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455842  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455843  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455844  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455845  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455847  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00455849  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0045584b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0045584d  a118965500             -mov eax, dword ptr [0x559618]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608984) /* 0x559618 */);
    // 00455852  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455854  83f808                 +cmp eax, 8
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
    // 00455857  0f8758030000           -ja 0x455bb5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 0045585d  ff248510584500         -jmp dword ptr [eax*4 + 0x455810]
    cpu.ip = app->getMemory<x86::reg32>(4544528 + cpu.eax * 4); goto dynamic_jump;
  case 0x00455864:
    // 00455864  8b9320020000           -mov edx, dword ptr [ebx + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 0045586a  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 00455870  83c234                 -add edx, 0x34
    (cpu.edx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00455873  83c034                 +add eax, 0x34
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(52 /*0x34*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00455876  e845460900             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 0045587b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045587d  e933030000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x00455882:
    // 00455882  8bb3d4020000           -mov esi, dword ptr [ebx + 0x2d4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(724) /* 0x2d4 */);
    // 00455888  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045588a  743f                   -je 0x4558cb
    if (cpu.flags.zf)
    {
        goto L_0x004558cb;
    }
    // 0045588c  8bb9d4020000           -mov edi, dword ptr [ecx + 0x2d4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(724) /* 0x2d4 */);
    // 00455892  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00455894  7435                   -je 0x4558cb
    if (cpu.flags.zf)
    {
        goto L_0x004558cb;
    }
    // 00455896  39f7                   +cmp edi, esi
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
    // 00455898  7d05                   -jge 0x45589f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045589f;
    }
    // 0045589a  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0045589f:
    // 0045589f  8bbbd4020000           -mov edi, dword ptr [ebx + 0x2d4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(724) /* 0x2d4 */);
    // 004558a5  3bb9d4020000           +cmp edi, dword ptr [ecx + 0x2d4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(724) /* 0x2d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004558ab  7d05                   -jge 0x4558b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004558b2;
    }
    // 004558ad  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004558b2:
    // 004558b2  8bb3d4020000           -mov esi, dword ptr [ebx + 0x2d4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(724) /* 0x2d4 */);
    // 004558b8  3bb1d4020000           +cmp esi, dword ptr [ecx + 0x2d4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(724) /* 0x2d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004558be  0f85f1020000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 004558c4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004558c6  e9ea020000             -jmp 0x455bb5
    goto L_0x00455bb5;
L_0x004558cb:
    // 004558cb  83b9d402000000         +cmp dword ptr [ecx + 0x2d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(724) /* 0x2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004558d2  740a                   -je 0x4558de
    if (cpu.flags.zf)
    {
        goto L_0x004558de;
    }
    // 004558d4  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004558d9  e9d7020000             -jmp 0x455bb5
    goto L_0x00455bb5;
L_0x004558de:
    // 004558de  83bbd402000000         +cmp dword ptr [ebx + 0x2d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(724) /* 0x2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004558e5  740a                   -je 0x4558f1
    if (cpu.flags.zf)
    {
        goto L_0x004558f1;
    }
    // 004558e7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004558ec  e9c4020000             -jmp 0x455bb5
    goto L_0x00455bb5;
L_0x004558f1:
    // 004558f1  8bb3cc020000           -mov esi, dword ptr [ebx + 0x2cc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 004558f7  3bb1cc020000           +cmp esi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004558fd  7e05                   -jle 0x455904
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455904;
    }
    // 004558ff  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455904:
    // 00455904  8bbbcc020000           -mov edi, dword ptr [ebx + 0x2cc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 0045590a  3bb9cc020000           +cmp edi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455910  7d05                   -jge 0x455917
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455917;
    }
    // 00455912  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455917:
    // 00455917  8bb3cc020000           -mov esi, dword ptr [ebx + 0x2cc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 0045591d  3bb1cc020000           +cmp esi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455923  0f858c020000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455929  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0045592b  e985020000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x00455930:
    // 00455930  8bbbc8020000           -mov edi, dword ptr [ebx + 0x2c8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(712) /* 0x2c8 */);
    // 00455936  3bb9c8020000           +cmp edi, dword ptr [ecx + 0x2c8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045593c  7e05                   -jle 0x455943
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455943;
    }
    // 0045593e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455943:
    // 00455943  8bb3c8020000           -mov esi, dword ptr [ebx + 0x2c8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(712) /* 0x2c8 */);
    // 00455949  3bb1c8020000           +cmp esi, dword ptr [ecx + 0x2c8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045594f  7d05                   -jge 0x455956
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455956;
    }
    // 00455951  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455956:
    // 00455956  8bbbc8020000           -mov edi, dword ptr [ebx + 0x2c8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(712) /* 0x2c8 */);
    // 0045595c  3bb9c8020000           +cmp edi, dword ptr [ecx + 0x2c8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455962  0f854d020000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455968  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0045596a  e946020000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x0045596f:
    // 0045596f  8bb3cc020000           -mov esi, dword ptr [ebx + 0x2cc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 00455975  3bb1cc020000           +cmp esi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045597b  7e05                   -jle 0x455982
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455982;
    }
    // 0045597d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455982:
    // 00455982  8bbbcc020000           -mov edi, dword ptr [ebx + 0x2cc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 00455988  3bb9cc020000           +cmp edi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045598e  7d05                   -jge 0x455995
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455995;
    }
    // 00455990  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455995:
    // 00455995  8bb3cc020000           -mov esi, dword ptr [ebx + 0x2cc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(716) /* 0x2cc */);
    // 0045599b  3bb1cc020000           +cmp esi, dword ptr [ecx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004559a1  0f850e020000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 004559a7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004559a9  e907020000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x004559ae:
    // 004559ae  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 004559b4  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004559b7  8b34454cd46f00         -mov esi, dword ptr [eax*2 + 0x6fd44c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328844) /* 0x6fd44c */ + cpu.eax * 2);
    // 004559be  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 004559c4  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004559c7  8b04454cd46f00         -mov eax, dword ptr [eax*2 + 0x6fd44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328844) /* 0x6fd44c */ + cpu.eax * 2);
    // 004559ce  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004559d1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004559d4  39c6                   +cmp esi, eax
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
    // 004559d6  7d05                   -jge 0x4559dd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004559dd;
    }
    // 004559d8  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x004559dd:
    // 004559dd  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 004559e3  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004559e6  8b34454cd46f00         -mov esi, dword ptr [eax*2 + 0x6fd44c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328844) /* 0x6fd44c */ + cpu.eax * 2);
    // 004559ed  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 004559f3  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004559f6  8b04454cd46f00         -mov eax, dword ptr [eax*2 + 0x6fd44c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328844) /* 0x6fd44c */ + cpu.eax * 2);
    // 004559fd  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00455a00  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455a03  39c6                   +cmp esi, eax
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
    // 00455a05  7e05                   -jle 0x455a0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455a0c;
    }
    // 00455a07  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455a0c:
    // 00455a0c  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 00455a12  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455a15  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00455a1b  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455a1e  668b047d4ed46f00       -mov ax, word ptr [edi*2 + 0x6fd44e]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(7328846) /* 0x6fd44e */ + cpu.edi * 2);
    // 00455a26  663b04754ed46f00       +cmp ax, word ptr [esi*2 + 0x6fd44e]
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(7328846) /* 0x6fd44e */ + cpu.esi * 2)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00455a2e  7504                   -jne 0x455a34
    if (!cpu.flags.zf)
    {
        goto L_0x00455a34;
    }
    // 00455a30  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00455a32  eb08                   -jmp 0x455a3c
    goto L_0x00455a3c;
L_0x00455a34:
    // 00455a34  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00455a36  0f8579010000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
L_0x00455a3c:
    // 00455a3c  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455a43  740e                   -je 0x455a53
    if (cpu.flags.zf)
    {
        goto L_0x00455a53;
    }
    // 00455a45  f6830002000004         +test byte ptr [ebx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455a4c  7505                   -jne 0x455a53
    if (!cpu.flags.zf)
    {
        goto L_0x00455a53;
    }
    // 00455a4e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455a53:
    // 00455a53  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455a5a  0f8555010000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455a60  f6830002000004         +test byte ptr [ebx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455a67  0f8448010000           -je 0x455bb5
    if (cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455a6d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00455a72  e93e010000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x00455a77:
    // 00455a77  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 00455a7d  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455a80  8b34452cd46f00         -mov esi, dword ptr [eax*2 + 0x6fd42c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328812) /* 0x6fd42c */ + cpu.eax * 2);
    // 00455a87  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00455a8d  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455a90  8b04452cd46f00         -mov eax, dword ptr [eax*2 + 0x6fd42c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328812) /* 0x6fd42c */ + cpu.eax * 2);
    // 00455a97  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00455a9a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455a9d  39c6                   +cmp esi, eax
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
    // 00455a9f  7d05                   -jge 0x455aa6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455aa6;
    }
    // 00455aa1  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455aa6:
    // 00455aa6  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 00455aac  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455aaf  8b34452cd46f00         -mov esi, dword ptr [eax*2 + 0x6fd42c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328812) /* 0x6fd42c */ + cpu.eax * 2);
    // 00455ab6  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00455abc  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455abf  8b04452cd46f00         -mov eax, dword ptr [eax*2 + 0x6fd42c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328812) /* 0x6fd42c */ + cpu.eax * 2);
    // 00455ac6  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00455ac9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455acc  39c6                   +cmp esi, eax
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
    // 00455ace  7e05                   -jle 0x455ad5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455ad5;
    }
    // 00455ad0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455ad5:
    // 00455ad5  8b8120020000           -mov eax, dword ptr [ecx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(544) /* 0x220 */);
    // 00455adb  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455ade  8b8320020000           -mov eax, dword ptr [ebx + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00455ae4  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00455ae7  668b047d2ed46f00       -mov ax, word ptr [edi*2 + 0x6fd42e]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(7328814) /* 0x6fd42e */ + cpu.edi * 2);
    // 00455aef  663b04752ed46f00       +cmp ax, word ptr [esi*2 + 0x6fd42e]
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(7328814) /* 0x6fd42e */ + cpu.esi * 2)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00455af7  7504                   -jne 0x455afd
    if (!cpu.flags.zf)
    {
        goto L_0x00455afd;
    }
    // 00455af9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00455afb  eb08                   -jmp 0x455b05
    goto L_0x00455b05;
L_0x00455afd:
    // 00455afd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00455aff  0f85b0000000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
L_0x00455b05:
    // 00455b05  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455b0c  740e                   -je 0x455b1c
    if (cpu.flags.zf)
    {
        goto L_0x00455b1c;
    }
    // 00455b0e  f6830002000004         +test byte ptr [ebx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455b15  7505                   -jne 0x455b1c
    if (!cpu.flags.zf)
    {
        goto L_0x00455b1c;
    }
    // 00455b17  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455b1c:
    // 00455b1c  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455b23  0f858c000000           -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455b29  f6830002000004         +test byte ptr [ebx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00455b30  0f847f000000           -je 0x455bb5
    if (cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455b36  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00455b3b  e975000000             -jmp 0x455bb5
    goto L_0x00455bb5;
  case 0x00455b40:
    // 00455b40  8bbb38020000           -mov edi, dword ptr [ebx + 0x238]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00455b46  3bb938020000           +cmp edi, dword ptr [ecx + 0x238]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455b4c  7e05                   -jle 0x455b53
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455b53;
    }
    // 00455b4e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455b53:
    // 00455b53  8bb338020000           -mov esi, dword ptr [ebx + 0x238]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00455b59  3bb138020000           +cmp esi, dword ptr [ecx + 0x238]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455b5f  7d05                   -jge 0x455b66
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455b66;
    }
    // 00455b61  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455b66:
    // 00455b66  8bbb38020000           -mov edi, dword ptr [ebx + 0x238]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00455b6c  3bb938020000           +cmp edi, dword ptr [ecx + 0x238]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455b72  7541                   -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
    // 00455b74  eb3d                   -jmp 0x455bb3
    goto L_0x00455bb3;
  case 0x00455b76:
    // 00455b76  d981b8020000           +fld dword ptr [ecx + 0x2b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(696) /* 0x2b8 */)));
    // 00455b7c  d89bb8020000           +fcomp dword ptr [ebx + 0x2b8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(696) /* 0x2b8 */)));
    cpu.fpu.pop();
    // 00455b82  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00455b84  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00455b85  7305                   -jae 0x455b8c
    if (!cpu.flags.cf)
    {
        goto L_0x00455b8c;
    }
    // 00455b87  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455b8c:
    // 00455b8c  d981b8020000           +fld dword ptr [ecx + 0x2b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(696) /* 0x2b8 */)));
    // 00455b92  d89bb8020000           +fcomp dword ptr [ebx + 0x2b8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(696) /* 0x2b8 */)));
    cpu.fpu.pop();
    // 00455b98  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00455b9a  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00455b9b  7605                   -jbe 0x455ba2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00455ba2;
    }
    // 00455b9d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455ba2:
    // 00455ba2  d981b8020000           +fld dword ptr [ecx + 0x2b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(696) /* 0x2b8 */)));
    // 00455ba8  d89bb8020000           +fcomp dword ptr [ebx + 0x2b8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(696) /* 0x2b8 */)));
    cpu.fpu.pop();
    // 00455bae  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00455bb0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00455bb1  7502                   -jne 0x455bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00455bb5;
    }
L_0x00455bb3:
    // 00455bb3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
  [[fallthrough]];
  case 0x00455bb5:
L_0x00455bb5:
    // 00455bb5  833d1c96550001         +cmp dword ptr [0x55961c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608988) /* 0x55961c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455bbc  7502                   -jne 0x455bc0
    if (!cpu.flags.zf)
    {
        goto L_0x00455bc0;
    }
    // 00455bbe  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00455bc0:
    // 00455bc0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00455bc2  7536                   -jne 0x455bfa
    if (!cpu.flags.zf)
    {
        goto L_0x00455bfa;
    }
    // 00455bc4  8bb338020000           -mov esi, dword ptr [ebx + 0x238]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00455bca  3bb138020000           +cmp esi, dword ptr [ecx + 0x238]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455bd0  7e05                   -jle 0x455bd7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455bd7;
    }
    // 00455bd2  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00455bd7:
    // 00455bd7  8bbb38020000           -mov edi, dword ptr [ebx + 0x238]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00455bdd  3bb938020000           +cmp edi, dword ptr [ecx + 0x238]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455be3  7d05                   -jge 0x455bea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455bea;
    }
    // 00455be5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00455bea:
    // 00455bea  8b8138020000           -mov eax, dword ptr [ecx + 0x238]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */);
    // 00455bf0  3b8338020000           +cmp eax, dword ptr [ebx + 0x238]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455bf6  7502                   -jne 0x455bfa
    if (!cpu.flags.zf)
    {
        goto L_0x00455bfa;
    }
    // 00455bf8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00455bfa:
    // 00455bfa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00455bfc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455bfd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455bfe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455bff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455c00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455c01  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_455c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455c10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455c11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455c12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455c13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455c14  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455c16  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00455c19  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00455c1b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00455c1d  eb05                   -jmp 0x455c24
    goto L_0x00455c24;
L_0x00455c1f:
    // 00455c1f  83f810                 +cmp eax, 0x10
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
    // 00455c22  7d36                   -jge 0x455c5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455c5a;
    }
L_0x00455c24:
    // 00455c24  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00455c26  8d3c00                 -lea edi, [eax + eax]
    cpu.edi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00455c29  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 00455c2c  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00455c2e  66c781d8955500ffff     -mov word ptr [ecx + 0x5595d8], 0xffff
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5608920) /* 0x5595d8 */) = 65535 /*0xffff*/;
    // 00455c37  69cec09a0000           -imul ecx, esi, 0x9ac0
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(39616 /*0x9ac0*/)));
    // 00455c3d  bfb0476600             -mov edi, 0x6647b0
    cpu.edi = 6703024 /*0x6647b0*/;
    // 00455c42  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00455c44  69c8ac090000           -imul ecx, eax, 0x9ac
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455c4a  01f9                   +add ecx, edi
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
    // 00455c4c  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 00455c53  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455c54  894c2fc0               -mov dword ptr [edi + ebp - 0x40], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.ecx;
    // 00455c58  ebc5                   -jmp 0x455c1f
    goto L_0x00455c1f;
L_0x00455c5a:
    // 00455c5a  b940584500             -mov ecx, 0x455840
    cpu.ecx = 4544576 /*0x455840*/;
    // 00455c5f  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00455c62  891518965500           -mov dword ptr [0x559618], edx
    app->getMemory<x86::reg32>(x86::reg32(5608984) /* 0x559618 */) = cpu.edx;
    // 00455c68  891d1c965500           -mov dword ptr [0x55961c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608988) /* 0x55961c */) = cpu.ebx;
    // 00455c6e  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00455c73  8b14b5307d6700         -mov edx, dword ptr [esi*4 + 0x677d30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.esi * 4);
    // 00455c7a  e879880900             -call 0x4ee4f8
    cpu.esp -= 4;
    sub_4ee4f8(app, cpu);
    if (cpu.terminate) return;
    // 00455c7f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00455c81:
    // 00455c81  3b14b5307d6700         +cmp edx, dword ptr [esi*4 + 0x677d30]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.esi * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455c88  7d38                   -jge 0x455cc2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455cc2;
    }
    // 00455c8a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00455c8c:
    // 00455c8c  3b04b5307d6700         +cmp eax, dword ptr [esi*4 + 0x677d30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.esi * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455c93  7d2a                   -jge 0x455cbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455cbf;
    }
    // 00455c95  69dec09a0000           -imul ebx, esi, 0x9ac0
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(39616 /*0x9ac0*/)));
    // 00455c9b  69c8ac090000           -imul ecx, eax, 0x9ac
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455ca1  81c3b0476600           -add ebx, 0x6647b0
    (cpu.ebx) += x86::reg32(x86::sreg32(6703024 /*0x6647b0*/));
    // 00455ca7  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00455ca9  3b4c95c0               +cmp ecx, dword ptr [ebp + edx*4 - 0x40]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */ + cpu.edx * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455cad  750d                   -jne 0x455cbc
    if (!cpu.flags.zf)
    {
        goto L_0x00455cbc;
    }
    // 00455caf  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00455cb1  c1e105                 +shl ecx, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00455cb4  66898451d8955500       -mov word ptr [ecx + edx*2 + 0x5595d8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5608920) /* 0x5595d8 */ + cpu.edx * 2) = cpu.ax;
L_0x00455cbc:
    // 00455cbc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455cbd  ebcd                   -jmp 0x455c8c
    goto L_0x00455c8c;
L_0x00455cbf:
    // 00455cbf  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00455cc0  ebbf                   -jmp 0x455c81
    goto L_0x00455c81;
L_0x00455cc2:
    // 00455cc2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455cc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455cc5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455cc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455cc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455cc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_455cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455cd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455cd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455cd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455cd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455cd5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00455cd8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00455cda  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00455cdd  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00455cdf  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 00455ce2  83fa10                 +cmp edx, 0x10
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
    // 00455ce5  0f8fd4000000           -jg 0x455dbf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00455dbf;
    }
    // 00455ceb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00455ced  7545                   -jne 0x455d34
    if (!cpu.flags.zf)
    {
        goto L_0x00455d34;
    }
    // 00455cef  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00455cf2  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455cf4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455cf6  6683b8d895550000       +cmp word ptr [eax + 0x5595d8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5608920) /* 0x5595d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00455cfe  0f8cbb000000           -jl 0x455dbf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00455dbf;
    }
    // 00455d04  8b80d6955500           -mov eax, dword ptr [eax + 0x5595d6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5608918) /* 0x5595d6 */);
    // 00455d0a  8b0cb5307d6700         -mov ecx, dword ptr [esi*4 + 0x677d30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.esi * 4);
    // 00455d11  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455d14  39c8                   +cmp eax, ecx
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
    // 00455d16  0f8fa3000000           -jg 0x455dbf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00455dbf;
    }
    // 00455d1c  69d0ac090000           -imul edx, eax, 0x9ac
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455d22  69c6c09a0000           -imul eax, esi, 0x9ac0
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(39616 /*0x9ac0*/)));
    // 00455d28  05b0476600             -add eax, 0x6647b0
    (cpu.eax) += x86::reg32(x86::sreg32(6703024 /*0x6647b0*/));
    // 00455d2d  01d0                   +add eax, edx
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
    // 00455d2f  e98d000000             -jmp 0x455dc1
    goto L_0x00455dc1;
L_0x00455d34:
    // 00455d34  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00455d36  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00455d38  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00455d3b  eb55                   -jmp 0x455d92
    goto L_0x00455d92;
L_0x00455d3d:
    // 00455d3d  69c0ac090000           -imul eax, eax, 0x9ac
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455d43  69d6c09a0000           -imul edx, esi, 0x9ac0
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(39616 /*0x9ac0*/)));
    // 00455d49  bbb0476600             -mov ebx, 0x6647b0
    cpu.ebx = 6703024 /*0x6647b0*/;
    // 00455d4e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455d50  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00455d53  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00455d55  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00455d57  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00455d5a  e851faffff             -call 0x4557b0
    cpu.esp -= 4;
    sub_4557b0(app, cpu);
    if (cpu.terminate) return;
    // 00455d5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455d61  7429                   -je 0x455d8c
    if (cpu.flags.zf)
    {
        goto L_0x00455d8c;
    }
    // 00455d63  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00455d66  3b45f8                 +cmp eax, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455d69  751b                   -jne 0x455d86
    if (!cpu.flags.zf)
    {
        goto L_0x00455d86;
    }
    // 00455d6b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00455d6e  8b80d6955500           -mov eax, dword ptr [eax + 0x5595d6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5608918) /* 0x5595d6 */);
    // 00455d74  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455d77  69c0ac090000           -imul eax, eax, 0x9ac
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(2476 /*0x9ac*/)));
    // 00455d7d  0345f0                 -add eax, dword ptr [ebp - 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 00455d80  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455d82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455d83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455d84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455d85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00455d86:
    // 00455d86  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00455d89  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
L_0x00455d8c:
    // 00455d8c  41                     -inc ecx
    (cpu.ecx)++;
    // 00455d8d  83f910                 +cmp ecx, 0x10
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
    // 00455d90  7d2d                   -jge 0x455dbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00455dbf;
    }
L_0x00455d92:
    // 00455d92  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00455d94  8d0409                 -lea eax, [ecx + ecx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 00455d97  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00455d9a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00455d9c  668b9ad8955500         -mov bx, word ptr [edx + 0x5595d8]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5608920) /* 0x5595d8 */);
    // 00455da3  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00455da6  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 00455da9  7ce1                   -jl 0x455d8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00455d8c;
    }
    // 00455dab  8b82d6955500           -mov eax, dword ptr [edx + 0x5595d6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5608918) /* 0x5595d6 */);
    // 00455db1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455db4  3b04b5307d6700         +cmp eax, dword ptr [esi*4 + 0x677d30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */ + cpu.esi * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455dbb  7e80                   -jle 0x455d3d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00455d3d;
    }
    // 00455dbd  ebcd                   -jmp 0x455d8c
    goto L_0x00455d8c;
L_0x00455dbf:
    // 00455dbf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00455dc1:
    // 00455dc1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455dc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455dc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455dc5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455dc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_455dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455dd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455dd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455dd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455dd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455dd5  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00455dd8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00455dda  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00455ddd  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00455de0  bfd8955500             -mov edi, 0x5595d8
    cpu.edi = 5608920 /*0x5595d8*/;
    // 00455de5  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00455de8  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00455ded  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00455def  8d55d8                 -lea edx, [ebp - 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00455df2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00455df4  e8f7460900             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00455df9  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00455dfc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00455dfe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00455e00  e80bfeffff             -call 0x455c10
    cpu.esp -= 4;
    sub_455c10(app, cpu);
    if (cpu.terminate) return;
    // 00455e05  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00455e08  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00455e0b  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00455e0e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00455e10  e8bbfeffff             -call 0x455cd0
    cpu.esp -= 4;
    sub_455cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455e15  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00455e1a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00455e1c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00455e1e  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00455e21  e8ca460900             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00455e26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00455e28  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00455e2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455e2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455e2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00455e2d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_455e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00455e30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455e31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455e32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00455e33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00455e34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00455e35  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00455e37  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00455e3a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00455e3c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00455e3e  ba1e000000             -mov edx, 0x1e
    cpu.edx = 30 /*0x1e*/;
    // 00455e43  e81848ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00455e48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00455e4a  0f84bb010000           -je 0x45600b
    if (cpu.flags.zf)
    {
        goto L_0x0045600b;
    }
    // 00455e50  bffd9d64ff             -mov edi, 0xff649dfd
    cpu.edi = 4284784125 /*0xff649dfd*/;
    // 00455e55  8a6104                 -mov ah, byte ptr [ecx + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00455e58  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00455e5a  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 00455e5d  7407                   -je 0x455e66
    if (cpu.flags.zf)
    {
        goto L_0x00455e66;
    }
    // 00455e5f  bf964a0000             -mov edi, 0x4a96
    cpu.edi = 19094 /*0x4a96*/;
    // 00455e64  eb1a                   -jmp 0x455e80
    goto L_0x00455e80;
L_0x00455e66:
    // 00455e66  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00455e68  7405                   -je 0x455e6f
    if (cpu.flags.zf)
    {
        goto L_0x00455e6f;
    }
    // 00455e6a  bf40e4ff00             -mov edi, 0xffe440
    cpu.edi = 16770112 /*0xffe440*/;
L_0x00455e6f:
    // 00455e6f  81ff40e4ff00           +cmp edi, 0xffe440
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16770112 /*0xffe440*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455e75  7509                   -jne 0x455e80
    if (!cpu.flags.zf)
    {
        goto L_0x00455e80;
    }
    // 00455e77  668b1d427d6700         -mov bx, word ptr [0x677d42]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(6782274) /* 0x677d42 */);
    // 00455e7e  eb07                   -jmp 0x455e87
    goto L_0x00455e87;
L_0x00455e80:
    // 00455e80  668b1d467d6700         -mov bx, word ptr [0x677d46]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(6782278) /* 0x677d46 */);
L_0x00455e87:
    // 00455e87  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00455e8a  66895df4               -mov word ptr [ebp - 0xc], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.bx;
    // 00455e8e  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00455e91  8d5df8                 -lea ebx, [ebp - 8]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00455e94  b9400000a0             -mov ecx, 0xa0000040
    cpu.ecx = 2684354624 /*0xa0000040*/;
    // 00455e99  e852080800             -call 0x4d66f0
    cpu.esp -= 4;
    sub_4d66f0(app, cpu);
    if (cpu.terminate) return;
    // 00455e9e  ba400000ff             -mov edx, 0xff000040
    cpu.edx = 4278190144 /*0xff000040*/;
    // 00455ea3  bb222222d0             -mov ebx, 0xd0222222
    cpu.ebx = 3491897890 /*0xd0222222*/;
    // 00455ea8  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00455eab  81ff40e4ff00           +cmp edi, 0xffe440
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16770112 /*0xffe440*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455eb1  7507                   -jne 0x455eba
    if (!cpu.flags.zf)
    {
        goto L_0x00455eba;
    }
    // 00455eb3  c745f040e4ffff         -mov dword ptr [ebp - 0x10], 0xffffe440
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 4294960192 /*0xffffe440*/;
L_0x00455eba:
    // 00455eba  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00455ec1  740f                   -je 0x455ed2
    if (cpu.flags.zf)
    {
        goto L_0x00455ed2;
    }
    // 00455ec3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00455ec8  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00455ecd  e82ebafdff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x00455ed2:
    // 00455ed2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455ed3  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00455ed6  8b5642                 -mov edx, dword ptr [esi + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(66) /* 0x42 */);
    // 00455ed9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00455eda  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455edd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455ee0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455ee1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455ee3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00455ee4  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00455ee7  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00455eea  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455eed  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00455ef0  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00455ef3  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00455ef6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455ef9  e862290800             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 00455efe  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00455f01  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00455f04  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00455f05  8b5642                 -mov edx, dword ptr [esi + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(66) /* 0x42 */);
    // 00455f08  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f0b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455f0e  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00455f11  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455f13  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00455f16  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00455f19  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00455f1c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00455f1f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455f22  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f25  e8062a0800             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
    // 00455f2a  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00455f31  740c                   -je 0x455f3f
    if (cpu.flags.zf)
    {
        goto L_0x00455f3f;
    }
    // 00455f33  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00455f38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00455f3a  e8c1b9fdff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x00455f3f:
    // 00455f3f  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00455f44  b90000803f             -mov ecx, 0x3f800000
    cpu.ecx = 1065353216 /*0x3f800000*/;
    // 00455f49  e8b2c1ffff             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00455f4e  8b5e3c                 -mov ebx, dword ptr [esi + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00455f51  890d50945500           -mov dword ptr [0x559450], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */) = cpu.ecx;
    // 00455f57  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00455f59  7448                   -je 0x455fa3
    if (cpu.flags.zf)
    {
        goto L_0x00455fa3;
    }
    // 00455f5b  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00455f5e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f62  8b4646                 -mov eax, dword ptr [esi + 0x46]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(70) /* 0x46 */);
    // 00455f65  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f68  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f69  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00455f6b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00455f6e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f6f  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00455f72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f73  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00455f76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f77  8b4642                 -mov eax, dword ptr [esi + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(66) /* 0x42 */);
    // 00455f7a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f7d  48                     -dec eax
    (cpu.eax)--;
    // 00455f7e  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00455f83  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f84  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00455f87  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00455f8a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455f8d  c1f910                 +sar ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00455f90  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00455f91  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00455f93  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00455f95  e836bdffff             -call 0x451cd0
    cpu.esp -= 4;
    sub_451cd0(app, cpu);
    if (cpu.terminate) return;
    // 00455f9a  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00455f9d  66894642               -mov word ptr [esi + 0x42], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 00455fa1  eb06                   -jmp 0x455fa9
    goto L_0x00455fa9;
L_0x00455fa3:
    // 00455fa3  66c746420100           -mov word ptr [esi + 0x42], 1
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(66) /* 0x42 */) = 1 /*0x1*/;
L_0x00455fa9:
    // 00455fa9  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00455fac  8b4642                 -mov eax, dword ptr [esi + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(66) /* 0x42 */);
    // 00455faf  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00455fb2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455fb5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455fb8  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00455fbb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00455fbd  81ff40e4ff00           +cmp edi, 0xffe440
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16770112 /*0xffe440*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00455fc3  7508                   -jne 0x455fcd
    if (!cpu.flags.zf)
    {
        goto L_0x00455fcd;
    }
    // 00455fc5  66a1447d6700           -mov ax, word ptr [0x677d44]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6782276) /* 0x677d44 */);
    // 00455fcb  eb06                   -jmp 0x455fd3
    goto L_0x00455fd3;
L_0x00455fcd:
    // 00455fcd  66a1407d6700           -mov ax, word ptr [0x677d40]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6782272) /* 0x677d40 */);
L_0x00455fd3:
    // 00455fd3  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00455fd4  e8b7190800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00455fd9  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00455fdc  8b5e44                 -mov ebx, dword ptr [esi + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00455fdf  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455fe2  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00455fe5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00455fe7  8b55f6                 -mov edx, dword ptr [ebp - 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00455fea  4b                     -dec ebx
    (cpu.ebx)--;
    // 00455feb  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455fee  8b4642                 -mov eax, dword ptr [esi + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(66) /* 0x42 */);
    // 00455ff1  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00455ff3  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00455ff6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00455ff9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00455ffc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00455ffe  8b45f2                 -mov eax, dword ptr [ebp - 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00456001  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456004  e887190800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00456009  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045600b:
    // 0045600b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045600d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045600e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045600f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456010  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456011  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456012  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_456020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456020  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456021  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456022  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456023  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456024  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456026  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00456029  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045602b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0045602d  ba1e000000             -mov edx, 0x1e
    cpu.edx = 30 /*0x1e*/;
    // 00456032  e82946ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00456037  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00456039  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045603b  0f84c4000000           -je 0x456105
    if (cpu.flags.zf)
    {
        goto L_0x00456105;
    }
    // 00456041  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456044  66a1427d6700           -mov ax, word ptr [0x677d42]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6782274) /* 0x677d42 */);
    // 0045604a  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0045604d  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0045604e  e89d060800             -call 0x4d66f0
    cpu.esp -= 4;
    sub_4d66f0(app, cpu);
    if (cpu.terminate) return;
    // 00456053  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00456057  668945e8               -mov word ptr [ebp - 0x18], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ax;
    // 0045605b  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0045605f  668b5144               -mov dx, word ptr [ecx + 0x44]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 00456063  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00456065  668945ea               -mov word ptr [ebp - 0x16], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = cpu.ax;
    // 00456069  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0045606c  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00456070  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456073  668945ee               -mov word ptr [ebp - 0x12], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-18) /* -0x12 */) = cpu.ax;
    // 00456077  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0045607b  668b5946               -mov bx, word ptr [ecx + 0x46]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(70) /* 0x46 */);
    // 0045607f  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456082  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00456084  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00456086  668945f0               -mov word ptr [ebp - 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ax;
    // 0045608a  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0045608e  668b5944               -mov bx, word ptr [ecx + 0x44]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 00456092  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00456094  668945f2               -mov word ptr [ebp - 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-14) /* -0xe */) = cpu.ax;
    // 00456098  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0045609b  668955f6               -mov word ptr [ebp - 0xa], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */) = cpu.dx;
    // 0045609f  668945f4               -mov word ptr [ebp - 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ax;
    // 004560a3  6683fe0d               +cmp si, 0xd
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004560a7  755a                   -jne 0x456103
    if (!cpu.flags.zf)
    {
        goto L_0x00456103;
    }
    // 004560a9  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004560ac  e83f610400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 004560b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004560b3  741b                   -je 0x4560d0
    if (cpu.flags.zf)
    {
        goto L_0x004560d0;
    }
    // 004560b5  668b714a               -mov si, word ptr [ecx + 0x4a]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */);
    // 004560b9  4e                     -dec esi
    (cpu.esi)--;
    // 004560ba  6689714a               -mov word ptr [ecx + 0x4a], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */) = cpu.si;
    // 004560be  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 004560c1  7d06                   -jge 0x4560c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004560c9;
    }
    // 004560c3  66c7414a0000           -mov word ptr [ecx + 0x4a], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */) = 0 /*0x0*/;
L_0x004560c9:
    // 004560c9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004560ce  eb35                   -jmp 0x456105
    goto L_0x00456105;
L_0x004560d0:
    // 004560d0  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004560d3  e818610400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 004560d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004560da  7427                   -je 0x456103
    if (cpu.flags.zf)
    {
        goto L_0x00456103;
    }
    // 004560dc  66ff414a               -inc word ptr [ecx + 0x4a]
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */))++;
    // 004560e0  8b5146                 -mov edx, dword ptr [ecx + 0x46]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(70) /* 0x46 */);
    // 004560e3  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004560e6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004560e9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004560ec  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004560ee  8b5148                 -mov edx, dword ptr [ecx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004560f1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004560f4  39c2                   +cmp edx, eax
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
    // 004560f6  7e04                   -jle 0x4560fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004560fc;
    }
    // 004560f8  66ff494a               +dec word ptr [ecx + 0x4a]
    {
        auto tmp = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */);
        cpu.flags.of = 1 & (tmp >> 15);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 15));
        cpu.set_szp(tmp);
    }
L_0x004560fc:
    // 004560fc  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00456101  eb02                   -jmp 0x456105
    goto L_0x00456105;
L_0x00456103:
    // 00456103  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00456105:
    // 00456105  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456107  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456108  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456109  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045610a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045610b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_456110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456112  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456113  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456114  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456116  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00456119  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045611b  ba1e000000             -mov edx, 0x1e
    cpu.edx = 30 /*0x1e*/;
    // 00456120  e83b45ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00456125  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456127  7439                   -je 0x456162
    if (cpu.flags.zf)
    {
        goto L_0x00456162;
    }
    // 00456129  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0045612d  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 00456131  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00456135  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 00456139  668b4146               -mov ax, word ptr [ecx + 0x46]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(70) /* 0x46 */);
    // 0045613d  66894120               -mov word ptr [ecx + 0x20], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 00456141  668b4144               -mov ax, word ptr [ecx + 0x44]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 00456145  8d5df8                 -lea ebx, [ebp - 8]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00456148  6689411e               -mov word ptr [ecx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.ax;
    // 0045614c  66a1427d6700           -mov ax, word ptr [0x677d42]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6782274) /* 0x677d42 */);
    // 00456152  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456155  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00456156  e895050800             -call 0x4d66f0
    cpu.esp -= 4;
    sub_4d66f0(app, cpu);
    if (cpu.terminate) return;
    // 0045615b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045615e  6601411e               -add word ptr [ecx + 0x1e], ax
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */)) += x86::reg16(x86::sreg16(cpu.ax));
L_0x00456162:
    // 00456162  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456164  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456165  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456166  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456167  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456168  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_456170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456170  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456171  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456172  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456174  ba1e000000             -mov edx, 0x1e
    cpu.edx = 30 /*0x1e*/;
    // 00456179  e8e244ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0045617e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456180  7440                   -je 0x4561c2
    if (cpu.flags.zf)
    {
        goto L_0x004561c2;
    }
    // 00456182  b818995300             -mov eax, 0x539918
    cpu.eax = 5478680 /*0x539918*/;
    // 00456187  e824fc0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045618c  66a3407d6700           -mov word ptr [0x677d40], ax
    app->getMemory<x86::reg16>(x86::reg32(6782272) /* 0x677d40 */) = cpu.ax;
    // 00456192  b820995300             -mov eax, 0x539920
    cpu.eax = 5478688 /*0x539920*/;
    // 00456197  e814fc0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045619c  66a3467d6700           -mov word ptr [0x677d46], ax
    app->getMemory<x86::reg16>(x86::reg32(6782278) /* 0x677d46 */) = cpu.ax;
    // 004561a2  b828995300             -mov eax, 0x539928
    cpu.eax = 5478696 /*0x539928*/;
    // 004561a7  e804fc0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 004561ac  66a3447d6700           -mov word ptr [0x677d44], ax
    app->getMemory<x86::reg16>(x86::reg32(6782276) /* 0x677d44 */) = cpu.ax;
    // 004561b2  b830995300             -mov eax, 0x539930
    cpu.eax = 5478704 /*0x539930*/;
    // 004561b7  e8f4fb0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 004561bc  66a3427d6700           -mov word ptr [0x677d42], ax
    app->getMemory<x86::reg16>(x86::reg32(6782274) /* 0x677d42 */) = cpu.ax;
L_0x004561c2:
    // 004561c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004561c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004561c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4561d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004561d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004561d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004561d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004561d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004561d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004561d7  ba1e000000             -mov edx, 0x1e
    cpu.edx = 30 /*0x1e*/;
    // 004561dc  e87f44ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004561e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004561e3  7415                   -je 0x4561fa
    if (cpu.flags.zf)
    {
        goto L_0x004561fa;
    }
    // 004561e5  6683794000             +cmp word ptr [ecx + 0x40], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004561ea  740e                   -je 0x4561fa
    if (cpu.flags.zf)
    {
        goto L_0x004561fa;
    }
    // 004561ec  8b413c                 -mov eax, dword ptr [ecx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 004561ef  e89cb60800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004561f4  66c741400000           -mov word ptr [ecx + 0x40], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x004561fa:
    // 004561fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004561fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004561fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004561fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_456200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456200  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456201  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456202  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456203  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456204  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456205  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456206  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456208  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0045620b  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00456211  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456214  7d0d                   -jge 0x456223
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00456223;
    }
    // 00456216  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045621d  7427                   -je 0x456246
    if (cpu.flags.zf)
    {
        goto L_0x00456246;
    }
    // 0045621f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00456221  7523                   -jne 0x456246
    if (!cpu.flags.zf)
    {
        goto L_0x00456246;
    }
L_0x00456223:
    // 00456223  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00456225  668915747d6700         -mov word ptr [0x677d74], dx
    app->getMemory<x86::reg16>(x86::reg32(6782324) /* 0x677d74 */) = cpu.dx;
    // 0045622c  668915727d6700         -mov word ptr [0x677d72], dx
    app->getMemory<x86::reg16>(x86::reg32(6782322) /* 0x677d72 */) = cpu.dx;
    // 00456233  668915707d6700         -mov word ptr [0x677d70], dx
    app->getMemory<x86::reg16>(x86::reg32(6782320) /* 0x677d70 */) = cpu.dx;
    // 0045623a  668915767d6700         -mov word ptr [0x677d76], dx
    app->getMemory<x86::reg16>(x86::reg32(6782326) /* 0x677d76 */) = cpu.dx;
    // 00456241  e9c9000000             -jmp 0x45630f
    goto L_0x0045630f;
L_0x00456246:
    // 00456246  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00456248:
    // 00456248  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0045624d  3b0c85f4975500         +cmp ecx, dword ptr [eax*4 + 0x5597f4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5609460) /* 0x5597f4 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456254  0f8db5000000           -jge 0x45630f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045630f;
    }
    // 0045625a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045625d  8bbc88d4965500         -mov edi, dword ptr [eax + ecx*4 + 0x5596d4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5609172) /* 0x5596d4 */ + cpu.ecx * 4);
    // 00456264  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456265  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00456268  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456269  8d55b0                 -lea edx, [ebp - 0x50]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045626c  e81f940800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00456271  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00456274  a1807d6700             -mov eax, dword ptr [0x677d80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782336) /* 0x677d80 */);
    // 00456279  8d3409                 -lea esi, [ecx + ecx]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 0045627c  e8ef8f0900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 00456281  8a15583a7a00           -mov dl, byte ptr [0x7a3a58]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */);
    // 00456287  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00456289  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0045628c  7407                   -je 0x456295
    if (cpu.flags.zf)
    {
        goto L_0x00456295;
    }
    // 0045628e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00456293  eb02                   -jmp 0x456297
    goto L_0x00456297;
L_0x00456295:
    // 00456295  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00456297:
    // 00456297  e8f4000800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 0045629c  668986707d6700         -mov word ptr [esi + 0x677d70], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6782320) /* 0x677d70 */) = cpu.ax;
    // 004562a3  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004562a6  c1e014                 -shl eax, 0x14
    cpu.eax <<= 20 /*0x14*/ % 32;
    // 004562a9  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 004562ac  6689044d507d6700       -mov word ptr [ecx*2 + 0x677d50], ax
    app->getMemory<x86::reg16>(x86::reg32(6782288) /* 0x677d50 */ + cpu.ecx * 2) = cpu.ax;
    // 004562b4  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004562b7  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004562ba  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 004562bd  6689044d587d6700       -mov word ptr [ecx*2 + 0x677d58], ax
    app->getMemory<x86::reg16>(x86::reg32(6782296) /* 0x677d58 */ + cpu.ecx * 2) = cpu.ax;
    // 004562c5  8b5302                 -mov edx, dword ptr [ebx + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004562c8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004562cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004562cd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004562d0  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004562d2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004562d4  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004562d7  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004562da  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004562dd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004562df  6689044d687d6700       -mov word ptr [ecx*2 + 0x677d68], ax
    app->getMemory<x86::reg16>(x86::reg32(6782312) /* 0x677d68 */ + cpu.ecx * 2) = cpu.ax;
    // 004562e7  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004562ea  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004562ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004562ef  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004562f2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004562f4  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004562f6  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004562f9  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004562fc  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004562ff  41                     -inc ecx
    (cpu.ecx)++;
    // 00456300  01d0                   +add eax, edx
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
    // 00456302  6689044d5e7d6700       -mov word ptr [ecx*2 + 0x677d5e], ax
    app->getMemory<x86::reg16>(x86::reg32(6782302) /* 0x677d5e */ + cpu.ecx * 2) = cpu.ax;
    // 0045630a  e939ffffff             -jmp 0x456248
    goto L_0x00456248;
L_0x0045630f:
    // 0045630f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456311  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456312  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456313  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456314  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456315  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456316  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456317  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_456320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456322  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456323  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456324  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456325  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456326  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456328  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0045632b  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0045632e  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00456333  a17c7d6700             -mov eax, dword ptr [0x677d7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */);
    // 00456338  39f8                   +cmp eax, edi
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
    // 0045633a  720c                   -jb 0x456348
    if (cpu.flags.cf)
    {
        goto L_0x00456348;
    }
    // 0045633c  7628                   -jbe 0x456366
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00456366;
    }
    // 0045633e  83f802                 +cmp eax, 2
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
    // 00456341  7462                   -je 0x4563a5
    if (cpu.flags.zf)
    {
        goto L_0x004563a5;
    }
    // 00456343  e999000000             -jmp 0x4563e1
    goto L_0x004563e1;
L_0x00456348:
    // 00456348  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045634a  0f8591000000           -jne 0x4563e1
    if (!cpu.flags.zf)
    {
        goto L_0x004563e1;
    }
    // 00456350  8b0d787d6700           -mov ecx, dword ptr [0x677d78]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */);
    // 00456356  01f9                   +add ecx, edi
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
    // 00456358  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0045635b  890d787d6700           -mov dword ptr [0x677d78], ecx
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.ecx;
    // 00456361  e97b000000             -jmp 0x4563e1
    goto L_0x004563e1;
L_0x00456366:
    // 00456366  8b1d787d6700           -mov ebx, dword ptr [0x677d78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */);
    // 0045636c  81fb00010000           +cmp ebx, 0x100
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456372  7d1b                   -jge 0x45638f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045638f;
    }
    // 00456374  8d730c                 -lea esi, [ebx + 0xc]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00456377  8935787d6700           -mov dword ptr [0x677d78], esi
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.esi;
    // 0045637d  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456383  7e0a                   -jle 0x45638f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045638f;
    }
    // 00456385  c705787d670000010000   -mov dword ptr [0x677d78], 0x100
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = 256 /*0x100*/;
L_0x0045638f:
    // 0045638f  db05787d6700           -fild dword ptr [0x677d78]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */))));
    // 00456395  d80d489a5300           -fmul dword ptr [0x539a48]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5478984) /* 0x539a48 */));
    // 0045639b  dc05509a5300           -fadd qword ptr [0x539a50]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5478992) /* 0x539a50 */));
    // 004563a1  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004563a3  eb39                   -jmp 0x4563de
    goto L_0x004563de;
L_0x004563a5:
    // 004563a5  8b15787d6700           -mov edx, dword ptr [0x677d78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */);
    // 004563ab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004563ad  7419                   -je 0x4563c8
    if (cpu.flags.zf)
    {
        goto L_0x004563c8;
    }
    // 004563af  8d4aec                 -lea ecx, [edx - 0x14]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-20) /* -0x14 */);
    // 004563b2  890d787d6700           -mov dword ptr [0x677d78], ecx
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.ecx;
    // 004563b8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004563ba  7e04                   -jle 0x4563c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004563c0;
    }
    // 004563bc  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004563be  eb08                   -jmp 0x4563c8
    goto L_0x004563c8;
L_0x004563c0:
    // 004563c0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004563c2  8935787d6700           -mov dword ptr [0x677d78], esi
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.esi;
L_0x004563c8:
    // 004563c8  db05787d6700           -fild dword ptr [0x677d78]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */))));
    // 004563ce  d80d489a5300           -fmul dword ptr [0x539a48]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5478984) /* 0x539a48 */));
    // 004563d4  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004563d6  dc05589a5300           -fadd qword ptr [0x539a58]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5479000) /* 0x539a58 */));
    // 004563dc  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004563de:
    // 004563de  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004563e1:
    // 004563e1  a118985500             -mov eax, dword ptr [0x559818]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 004563e6  66813c45667d67004001   +cmp word ptr [eax*2 + 0x677d66], 0x140
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6782310) /* 0x677d66 */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(320 /*0x140*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004563f0  7e12                   -jle 0x456404
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00456404;
    }
    // 004563f2  bafa000000             -mov edx, 0xfa
    cpu.edx = 250 /*0xfa*/;
    // 004563f7  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 004563fc  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004563ff  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00456402  eb10                   -jmp 0x456414
    goto L_0x00456414;
L_0x00456404:
    // 00456404  bbfa000000             -mov ebx, 0xfa
    cpu.ebx = 250 /*0xfa*/;
    // 00456409  b900020000             -mov ecx, 0x200
    cpu.ecx = 512 /*0x200*/;
    // 0045640e  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00456411  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
L_0x00456414:
    // 00456414  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00456416  e93c010000             -jmp 0x456557
    goto L_0x00456557;
L_0x0045641b:
    // 0045641b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045641d  7564                   -jne 0x456483
    if (!cpu.flags.zf)
    {
        goto L_0x00456483;
    }
    // 0045641f  833d787d67003c         +cmp dword ptr [0x677d78], 0x3c
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456426  750b                   -jne 0x456433
    if (!cpu.flags.zf)
    {
        goto L_0x00456433;
    }
    // 00456428  a3787d6700             -mov dword ptr [0x677d78], eax
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.eax;
    // 0045642d  40                     -inc eax
    (cpu.eax)++;
    // 0045642e  a37c7d6700             -mov dword ptr [0x677d7c], eax
    app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */) = cpu.eax;
L_0x00456433:
    // 00456433  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00456435  be0e000000             -mov esi, 0xe
    cpu.esi = 14 /*0xe*/;
    // 0045643a  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0045643d  eb44                   -jmp 0x456483
    goto L_0x00456483;
L_0x0045643f:
    // 0045643f  813d787d670000010000   +cmp dword ptr [0x677d78], 0x100
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456449  750e                   -jne 0x456459
    if (!cpu.flags.zf)
    {
        goto L_0x00456459;
    }
    // 0045644b  c745f80000803f         -mov dword ptr [ebp - 8], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1065353216 /*0x3f800000*/;
    // 00456452  be0e000000             -mov esi, 0xe
    cpu.esi = 14 /*0xe*/;
    // 00456457  eb10                   -jmp 0x456469
    goto L_0x00456469;
L_0x00456459:
    // 00456459  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0045645c  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0045645e  dc05609a5300           -fadd qword ptr [0x539a60]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5479008) /* 0x539a60 */));
    // 00456464  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00456466  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00456469:
    // 00456469  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045646d  7414                   -je 0x456483
    if (cpu.flags.zf)
    {
        goto L_0x00456483;
    }
    // 0045646f  ff057c7d6700           +inc dword ptr [0x677d7c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00456475  eb0c                   -jmp 0x456483
    goto L_0x00456483;
L_0x00456477:
    // 00456477  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0045647a  dc05689a5300           +fadd qword ptr [0x539a68]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5479016) /* 0x539a68 */));
    // 00456480  d95df8                 +fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00456483:
    // 00456483  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00456486  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00456488  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0045648a  dd5dd4                 +fstp qword ptr [ebp - 0x2c]
    app->getMemory<double>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0045648d  dc5dd4                 +fcomp qword ptr [ebp - 0x2c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    cpu.fpu.pop();
    // 00456490  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00456492  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00456493  0f87b8000000           -ja 0x456551
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00456551;
    }
    // 00456499  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 0045649b  dc5dd4                 +fcomp qword ptr [ebp - 0x2c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    cpu.fpu.pop();
    // 0045649e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004564a0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004564a1  0f82aa000000           -jb 0x456551
    if (cpu.flags.cf)
    {
        goto L_0x00456551;
    }
    // 004564a7  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004564aa  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004564ac  d80d709a5300           -fmul dword ptr [0x539a70]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5479024) /* 0x539a70 */));
    // 004564b2  a118985500             -mov eax, dword ptr [0x559818]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 004564b7  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004564b9  df0445667d6700         -fild word ptr [eax*2 + 0x677d66]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(6782310) /* 0x677d66 */ + cpu.eax * 2))));
    // 004564c0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004564c2  dc65d4                 -fsub qword ptr [ebp - 0x2c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-44) /* -0x2c */));
    // 004564c5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004564c7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004564c9  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004564cc  df04455e7d6700         -fild word ptr [eax*2 + 0x677d5e]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(6782302) /* 0x677d5e */ + cpu.eax * 2))));
    // 004564d3  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004564d5  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004564d8  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004564db  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004564de  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004564e0  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004564e3  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004564e5  d805749a5300           -fadd dword ptr [0x539a74]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5479028) /* 0x539a74 */));
    // 004564eb  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004564ee  decd                   -fmulp st(5)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004564f0  e861980800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004564f5  db5de4                 -fistp dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004564f8  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004564fa  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004564fc  e855980800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00456501  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00456503  e84e980800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00456508  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0045650a  db5df0                 -fistp dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0045650d  db5dec                 -fistp dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00456510  83fe0e                 +cmp esi, 0xe
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456513  7507                   -jne 0x45651c
    if (!cpu.flags.zf)
    {
        goto L_0x0045651c;
    }
    // 00456515  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0045651a  eb05                   -jmp 0x456521
    goto L_0x00456521;
L_0x0045651c:
    // 0045651c  b8ffffff40             -mov eax, 0x40ffffff
    cpu.eax = 1090519039 /*0x40ffffff*/;
L_0x00456521:
    // 00456521  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456522  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456523  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00456526  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456528  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045652b  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0045652d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045652f  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456532  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456535  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456538  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045653a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045653c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045653d  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456540  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00456542  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00456544  a18e7d6700             -mov eax, dword ptr [0x677d8e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782350) /* 0x677d8e */);
    // 00456549  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045654c  e82f260800             -call 0x4d8b80
    cpu.esp -= 4;
    sub_4d8b80(app, cpu);
    if (cpu.terminate) return;
L_0x00456551:
    // 00456551  46                     -inc esi
    (cpu.esi)++;
    // 00456552  83fe0f                 +cmp esi, 0xf
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
    // 00456555  7d22                   -jge 0x456579
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00456579;
    }
L_0x00456557:
    // 00456557  a17c7d6700             -mov eax, dword ptr [0x677d7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */);
    // 0045655c  83f801                 +cmp eax, 1
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
    // 0045655f  0f82b6feffff           -jb 0x45641b
    if (cpu.flags.cf)
    {
        goto L_0x0045641b;
    }
    // 00456565  0f86d4feffff           -jbe 0x45643f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045643f;
    }
    // 0045656b  83f802                 +cmp eax, 2
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
    // 0045656e  0f8403ffffff           -je 0x456477
    if (cpu.flags.zf)
    {
        goto L_0x00456477;
    }
    // 00456574  e90affffff             -jmp 0x456483
    goto L_0x00456483;
L_0x00456579:
    // 00456579  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045657b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045657d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045657e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045657f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456580  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456581  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456582  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456583  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_456590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456590  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456591  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456592  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456593  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456594  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456595  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456596  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456598  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0045659b  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004565a1  83fa04                 +cmp edx, 4
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
    // 004565a4  750c                   -jne 0x4565b2
    if (!cpu.flags.zf)
    {
        goto L_0x004565b2;
    }
    // 004565a6  bbae010000             -mov ebx, 0x1ae
    cpu.ebx = 430 /*0x1ae*/;
    // 004565ab  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
    // 004565b0  eb24                   -jmp 0x4565d6
    goto L_0x004565d6;
L_0x004565b2:
    // 004565b2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004565b4  740a                   -je 0x4565c0
    if (cpu.flags.zf)
    {
        goto L_0x004565c0;
    }
    // 004565b6  83fa07                 +cmp edx, 7
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
    // 004565b9  7405                   -je 0x4565c0
    if (cpu.flags.zf)
    {
        goto L_0x004565c0;
    }
    // 004565bb  83fa08                 +cmp edx, 8
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
    // 004565be  750c                   -jne 0x4565cc
    if (!cpu.flags.zf)
    {
        goto L_0x004565cc;
    }
L_0x004565c0:
    // 004565c0  bb9a010000             -mov ebx, 0x19a
    cpu.ebx = 410 /*0x19a*/;
    // 004565c5  bafa000000             -mov edx, 0xfa
    cpu.edx = 250 /*0xfa*/;
    // 004565ca  eb0a                   -jmp 0x4565d6
    goto L_0x004565d6;
L_0x004565cc:
    // 004565cc  bb86010000             -mov ebx, 0x186
    cpu.ebx = 390 /*0x186*/;
    // 004565d1  bad1010000             -mov edx, 0x1d1
    cpu.edx = 465 /*0x1d1*/;
L_0x004565d6:
    // 004565d6  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004565db  8b0d68bc6f00           -mov ecx, dword ptr [0x6fbc68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322728) /* 0x6fbc68 */);
    // 004565e1  83f903                 +cmp ecx, 3
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
    // 004565e4  7405                   -je 0x4565eb
    if (cpu.flags.zf)
    {
        goto L_0x004565eb;
    }
    // 004565e6  83f904                 +cmp ecx, 4
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
    // 004565e9  750e                   -jne 0x4565f9
    if (!cpu.flags.zf)
    {
        goto L_0x004565f9;
    }
L_0x004565eb:
    // 004565eb  8b348568965500         -mov esi, dword ptr [eax*4 + 0x559668]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5609064) /* 0x559668 */ + cpu.eax * 4);
    // 004565f2  b88a070000             -mov eax, 0x78a
    cpu.eax = 1930 /*0x78a*/;
    // 004565f7  eb0c                   -jmp 0x456605
    goto L_0x00456605;
L_0x004565f9:
    // 004565f9  8b348544965500         -mov esi, dword ptr [eax*4 + 0x559644]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5609028) /* 0x559644 */ + cpu.eax * 4);
    // 00456600  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
L_0x00456605:
    // 00456605  e846b20700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0045660a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045660b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0045660c  687c8d5300             -push 0x538d7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475708 /*0x538d7c*/;
    cpu.esp -= 4;
    // 00456611  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00456614  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456615  e876900800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045661a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045661d  68fd8c4800             -push 0x488cfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 4754685 /*0x488cfd*/;
    cpu.esp -= 4;
    // 00456622  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00456624  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00456629  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045662c  e85fbbffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00456631  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456633  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456634  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456635  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456636  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456637  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456638  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456639  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_45663a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0045663a  90                     -nop 
    ;
    // 0045663b  90                     -nop 
    ;
    // 0045663c  90                     -nop 
    ;
    // 0045663d  90                     -nop 
    ;
    // 0045663e  90                     -nop 
    ;
    // 0045663f  90                     -nop 
    ;
    // 00456640  90                     -nop 
    ;
    // 00456641  90                     -nop 
    ;
    // 00456642  90                     -nop 
    ;
    // 00456643  90                     -nop 
    ;
    // 00456644  90                     -nop 
    ;
    // 00456645  90                     -nop 
    ;
    // 00456646  90                     -nop 
    ;
    // 00456647  90                     -nop 
    ;
    // 00456648  90                     -nop 
    ;
    // 00456649  90                     -nop 
    ;
    // 0045664a  90                     -nop 
    ;
    // 0045664b  90                     -nop 
    ;
    // 0045664c  90                     -nop 
    ;
    // 0045664d  90                     -nop 
    ;
    // 0045664e  90                     -nop 
    ;
    // 0045664f  90                     -nop 
    ;
    // 00456650  90                     -nop 
    ;
    // 00456651  90                     -nop 
    ;
    // 00456652  90                     -nop 
    ;
    // 00456653  90                     -nop 
    ;
    // 00456654  90                     -nop 
    ;
    // 00456655  90                     -nop 
    ;
    // 00456656  90                     -nop 
    ;
    // 00456657  90                     -nop 
    ;
    // 00456658  90                     -nop 
    ;
    // 00456659  90                     -nop 
    ;
    // 0045665a  90                     -nop 
    ;
    // 0045665b  90                     -nop 
    ;
    // 0045665c  90                     -nop 
    ;
    // 0045665d  90                     -nop 
    ;
    // 0045665e  90                     -nop 
    ;
    // 0045665f  90                     -nop 
    ;
    // 00456660  90                     -nop 
    ;
    // 00456661  90                     -nop 
    ;
    // 00456662  90                     -nop 
    ;
    // 00456663  90                     -nop 
    ;
    // 00456664  90                     -nop 
    ;
    // 00456665  90                     -nop 
    ;
    // 00456666  90                     -nop 
    ;
    // 00456667  90                     -nop 
    ;
    // 00456668  90                     -nop 
    ;
    // 00456669  90                     -nop 
    ;
    // 0045666a  90                     -nop 
    ;
    // 0045666b  90                     -nop 
    ;
    // 0045666c  90                     -nop 
    ;
    // 0045666d  90                     -nop 
    ;
    // 0045666e  90                     -nop 
    ;
    // 0045666f  90                     -nop 
    ;
    // 00456670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456672  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456673  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456674  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456675  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456676  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456678  8b15609c5500           -mov edx, dword ptr [0x559c60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5610592) /* 0x559c60 */);
    // 0045667e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00456680  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00456682  7407                   -je 0x45668b
    if (cpu.flags.zf)
    {
        goto L_0x0045668b;
    }
    // 00456684  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00456686  e967010000             -jmp 0x4567f2
    goto L_0x004567f2;
L_0x0045668b:
    // 0045668b  8b0dacd46f00           -mov ecx, dword ptr [0x6fd4ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00456691  3b0d8c7d6700           +cmp ecx, dword ptr [0x677d8c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782348) /* 0x677d8c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456697  740c                   -je 0x4566a5
    if (cpu.flags.zf)
    {
        goto L_0x004566a5;
    }
    // 00456699  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0045669e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045669f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004566a5:
    // 004566a5  e8e6feffff             -call 0x456590
    cpu.esp -= 4;
    sub_456590(app, cpu);
    if (cpu.terminate) return;
    // 004566aa  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 004566af  8b1d24985500           -mov ebx, dword ptr [0x559824]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5609508) /* 0x559824 */);
    // 004566b5  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004566ba  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004566bc  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004566bf  8b1445ae965500         -mov edx, dword ptr [eax*2 + 0x5596ae]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609134) /* 0x5596ae */ + cpu.eax * 2);
    // 004566c6  891d24985500           -mov dword ptr [0x559824], ebx
    app->getMemory<x86::reg32>(x86::reg32(5609508) /* 0x559824 */) = cpu.ebx;
    // 004566cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004566cd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004566d0  8b1c45c0965500         -mov ebx, dword ptr [eax*2 + 0x5596c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5609152) /* 0x5596c0 */ + cpu.eax * 2);
    // 004566d7  a1907d6700             -mov eax, dword ptr [0x677d90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782352) /* 0x677d90 */);
    // 004566dc  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004566df  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004566e2  e849000800             -call 0x4d6730
    cpu.esp -= 4;
    sub_4d6730(app, cpu);
    if (cpu.terminate) return;
    // 004566e7  8b151c985500           -mov edx, dword ptr [0x55981c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609500) /* 0x55981c */);
    // 004566ed  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004566f0  b900020000             -mov ecx, 0x200
    cpu.ecx = 512 /*0x200*/;
    // 004566f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004566f7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004566fa  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004566fc  89151c985500           -mov dword ptr [0x55981c], edx
    app->getMemory<x86::reg32>(x86::reg32(5609500) /* 0x55981c */) = cpu.edx;
    // 00456702  81fa00010000           +cmp edx, 0x100
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
    // 00456708  7d04                   -jge 0x45670e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045670e;
    }
    // 0045670a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045670c  eb07                   -jmp 0x456715
    goto L_0x00456715;
L_0x0045670e:
    // 0045670e  b9ff010000             -mov ecx, 0x1ff
    cpu.ecx = 511 /*0x1ff*/;
    // 00456713  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00456715:
    // 00456715  e8c62e0700             -call 0x4c95e0
    cpu.esp -= 4;
    sub_4c95e0(app, cpu);
    if (cpu.terminate) return;
    // 0045671a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045671c  7467                   -je 0x456785
    if (cpu.flags.zf)
    {
        goto L_0x00456785;
    }
    // 0045671e  833d2098550000         +cmp dword ptr [0x559820], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5609504) /* 0x559820 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456725  745e                   -je 0x456785
    if (cpu.flags.zf)
    {
        goto L_0x00456785;
    }
    // 00456727  8b3d18985500           -mov edi, dword ptr [0x559818]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 0045672d  47                     -inc edi
    (cpu.edi)++;
    // 0045672e  893d18985500           -mov dword ptr [0x559818], edi
    app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */) = cpu.edi;
    // 00456734  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456737  7d16                   -jge 0x45674f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045674f;
    }
    // 00456739  a18e7d6700             -mov eax, dword ptr [0x677d8e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782350) /* 0x677d8e */);
    // 0045673e  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00456741  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456744  e8b7000000             -call 0x456800
    cpu.esp -= 4;
    sub_456800(app, cpu);
    if (cpu.terminate) return;
    // 00456749  66a3907d6700           -mov word ptr [0x677d90], ax
    app->getMemory<x86::reg16>(x86::reg32(6782352) /* 0x677d90 */) = cpu.ax;
L_0x0045674f:
    // 0045674f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00456751  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00456756  89157c7d6700           -mov dword ptr [0x677d7c], edx
    app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */) = cpu.edx;
    // 0045675c  8915787d6700           -mov dword ptr [0x677d78], edx
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.edx;
    // 00456762  8b3c85f4975500         -mov edi, dword ptr [eax*4 + 0x5597f4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5609460) /* 0x5597f4 */ + cpu.eax * 4);
    // 00456769  8b1518985500           -mov edx, dword ptr [0x559818]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 0045676f  39fa                   +cmp edx, edi
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
    // 00456771  7f12                   -jg 0x456785
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00456785;
    }
    // 00456773  8b1d4cbb6f00           -mov ebx, dword ptr [0x6fbb4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 00456779  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045677b  ba33000000             -mov edx, 0x33
    cpu.edx = 51 /*0x33*/;
    // 00456780  e86b2e0700             -call 0x4c95f0
    cpu.esp -= 4;
    sub_4c95f0(app, cpu);
    if (cpu.terminate) return;
L_0x00456785:
    // 00456785  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0045678a  8b1518985500           -mov edx, dword ptr [0x559818]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 00456790  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00456793  8b1c85f4975500         -mov ebx, dword ptr [eax*4 + 0x5597f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5609460) /* 0x5597f4 */ + cpu.eax * 4);
    // 0045679a  81c1ffffff00           -add ecx, 0xffffff
    (cpu.ecx) += x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 004567a0  39da                   +cmp edx, ebx
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
    // 004567a2  7f42                   -jg 0x4567e6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004567e6;
    }
    // 004567a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004567a6  7e3e                   -jle 0x4567e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004567e6;
    }
    // 004567a8  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004567ab  6683b86e7d670000       +cmp word ptr [eax + 0x677d6e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6782318) /* 0x677d6e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004567b3  7420                   -je 0x4567d5
    if (cpu.flags.zf)
    {
        goto L_0x004567d5;
    }
    // 004567b5  8b98547d6700           -mov ebx, dword ptr [eax + 0x677d54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6782292) /* 0x677d54 */);
    // 004567bb  8b904c7d6700           -mov edx, dword ptr [eax + 0x677d4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6782284) /* 0x677d4c */);
    // 004567c1  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004567c4  8b806c7d6700           -mov eax, dword ptr [eax + 0x677d6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6782316) /* 0x677d6c */);
    // 004567ca  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004567cd  c1f810                 +sar eax, 0x10
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
    // 004567d0  e88b090800             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
L_0x004567d5:
    // 004567d5  e8062e0700             -call 0x4c95e0
    cpu.esp -= 4;
    sub_4c95e0(app, cpu);
    if (cpu.terminate) return;
    // 004567da  e841fbffff             -call 0x456320
    cpu.esp -= 4;
    sub_456320(app, cpu);
    if (cpu.terminate) return;
    // 004567df  a320985500             -mov dword ptr [0x559820], eax
    app->getMemory<x86::reg32>(x86::reg32(5609504) /* 0x559820 */) = cpu.eax;
    // 004567e4  eb0a                   -jmp 0x4567f0
    goto L_0x004567f0;
L_0x004567e6:
    // 004567e6  c7052098550001000000   -mov dword ptr [0x559820], 1
    app->getMemory<x86::reg32>(x86::reg32(5609504) /* 0x559820 */) = 1 /*0x1*/;
L_0x004567f0:
    // 004567f0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004567f2:
    // 004567f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_456670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00456670;
    // 0045663a  90                     -nop 
    ;
    // 0045663b  90                     -nop 
    ;
    // 0045663c  90                     -nop 
    ;
    // 0045663d  90                     -nop 
    ;
    // 0045663e  90                     -nop 
    ;
    // 0045663f  90                     -nop 
    ;
    // 00456640  90                     -nop 
    ;
    // 00456641  90                     -nop 
    ;
    // 00456642  90                     -nop 
    ;
    // 00456643  90                     -nop 
    ;
    // 00456644  90                     -nop 
    ;
    // 00456645  90                     -nop 
    ;
    // 00456646  90                     -nop 
    ;
    // 00456647  90                     -nop 
    ;
    // 00456648  90                     -nop 
    ;
    // 00456649  90                     -nop 
    ;
    // 0045664a  90                     -nop 
    ;
    // 0045664b  90                     -nop 
    ;
    // 0045664c  90                     -nop 
    ;
    // 0045664d  90                     -nop 
    ;
    // 0045664e  90                     -nop 
    ;
    // 0045664f  90                     -nop 
    ;
    // 00456650  90                     -nop 
    ;
    // 00456651  90                     -nop 
    ;
    // 00456652  90                     -nop 
    ;
    // 00456653  90                     -nop 
    ;
    // 00456654  90                     -nop 
    ;
    // 00456655  90                     -nop 
    ;
    // 00456656  90                     -nop 
    ;
    // 00456657  90                     -nop 
    ;
    // 00456658  90                     -nop 
    ;
    // 00456659  90                     -nop 
    ;
    // 0045665a  90                     -nop 
    ;
    // 0045665b  90                     -nop 
    ;
    // 0045665c  90                     -nop 
    ;
    // 0045665d  90                     -nop 
    ;
    // 0045665e  90                     -nop 
    ;
    // 0045665f  90                     -nop 
    ;
    // 00456660  90                     -nop 
    ;
    // 00456661  90                     -nop 
    ;
    // 00456662  90                     -nop 
    ;
    // 00456663  90                     -nop 
    ;
    // 00456664  90                     -nop 
    ;
    // 00456665  90                     -nop 
    ;
    // 00456666  90                     -nop 
    ;
    // 00456667  90                     -nop 
    ;
    // 00456668  90                     -nop 
    ;
    // 00456669  90                     -nop 
    ;
    // 0045666a  90                     -nop 
    ;
    // 0045666b  90                     -nop 
    ;
    // 0045666c  90                     -nop 
    ;
    // 0045666d  90                     -nop 
    ;
    // 0045666e  90                     -nop 
    ;
    // 0045666f  90                     -nop 
    ;
L_entry_0x00456670:
    // 00456670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456672  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456673  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456674  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456675  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456676  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456678  8b15609c5500           -mov edx, dword ptr [0x559c60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5610592) /* 0x559c60 */);
    // 0045667e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00456680  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00456682  7407                   -je 0x45668b
    if (cpu.flags.zf)
    {
        goto L_0x0045668b;
    }
    // 00456684  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00456686  e967010000             -jmp 0x4567f2
    goto L_0x004567f2;
L_0x0045668b:
    // 0045668b  8b0dacd46f00           -mov ecx, dword ptr [0x6fd4ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00456691  3b0d8c7d6700           +cmp ecx, dword ptr [0x677d8c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782348) /* 0x677d8c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456697  740c                   -je 0x4566a5
    if (cpu.flags.zf)
    {
        goto L_0x004566a5;
    }
    // 00456699  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0045669e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045669f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004566a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004566a5:
    // 004566a5  e8e6feffff             -call 0x456590
    cpu.esp -= 4;
    sub_456590(app, cpu);
    if (cpu.terminate) return;
    // 004566aa  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 004566af  8b1d24985500           -mov ebx, dword ptr [0x559824]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5609508) /* 0x559824 */);
    // 004566b5  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004566ba  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004566bc  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004566bf  8b1445ae965500         -mov edx, dword ptr [eax*2 + 0x5596ae]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609134) /* 0x5596ae */ + cpu.eax * 2);
    // 004566c6  891d24985500           -mov dword ptr [0x559824], ebx
    app->getMemory<x86::reg32>(x86::reg32(5609508) /* 0x559824 */) = cpu.ebx;
    // 004566cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004566cd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004566d0  8b1c45c0965500         -mov ebx, dword ptr [eax*2 + 0x5596c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5609152) /* 0x5596c0 */ + cpu.eax * 2);
    // 004566d7  a1907d6700             -mov eax, dword ptr [0x677d90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782352) /* 0x677d90 */);
    // 004566dc  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004566df  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004566e2  e849000800             -call 0x4d6730
    cpu.esp -= 4;
    sub_4d6730(app, cpu);
    if (cpu.terminate) return;
    // 004566e7  8b151c985500           -mov edx, dword ptr [0x55981c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609500) /* 0x55981c */);
    // 004566ed  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004566f0  b900020000             -mov ecx, 0x200
    cpu.ecx = 512 /*0x200*/;
    // 004566f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004566f7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004566fa  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004566fc  89151c985500           -mov dword ptr [0x55981c], edx
    app->getMemory<x86::reg32>(x86::reg32(5609500) /* 0x55981c */) = cpu.edx;
    // 00456702  81fa00010000           +cmp edx, 0x100
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
    // 00456708  7d04                   -jge 0x45670e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045670e;
    }
    // 0045670a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045670c  eb07                   -jmp 0x456715
    goto L_0x00456715;
L_0x0045670e:
    // 0045670e  b9ff010000             -mov ecx, 0x1ff
    cpu.ecx = 511 /*0x1ff*/;
    // 00456713  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00456715:
    // 00456715  e8c62e0700             -call 0x4c95e0
    cpu.esp -= 4;
    sub_4c95e0(app, cpu);
    if (cpu.terminate) return;
    // 0045671a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045671c  7467                   -je 0x456785
    if (cpu.flags.zf)
    {
        goto L_0x00456785;
    }
    // 0045671e  833d2098550000         +cmp dword ptr [0x559820], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5609504) /* 0x559820 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456725  745e                   -je 0x456785
    if (cpu.flags.zf)
    {
        goto L_0x00456785;
    }
    // 00456727  8b3d18985500           -mov edi, dword ptr [0x559818]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 0045672d  47                     -inc edi
    (cpu.edi)++;
    // 0045672e  893d18985500           -mov dword ptr [0x559818], edi
    app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */) = cpu.edi;
    // 00456734  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456737  7d16                   -jge 0x45674f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045674f;
    }
    // 00456739  a18e7d6700             -mov eax, dword ptr [0x677d8e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782350) /* 0x677d8e */);
    // 0045673e  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00456741  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456744  e8b7000000             -call 0x456800
    cpu.esp -= 4;
    sub_456800(app, cpu);
    if (cpu.terminate) return;
    // 00456749  66a3907d6700           -mov word ptr [0x677d90], ax
    app->getMemory<x86::reg16>(x86::reg32(6782352) /* 0x677d90 */) = cpu.ax;
L_0x0045674f:
    // 0045674f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00456751  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00456756  89157c7d6700           -mov dword ptr [0x677d7c], edx
    app->getMemory<x86::reg32>(x86::reg32(6782332) /* 0x677d7c */) = cpu.edx;
    // 0045675c  8915787d6700           -mov dword ptr [0x677d78], edx
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.edx;
    // 00456762  8b3c85f4975500         -mov edi, dword ptr [eax*4 + 0x5597f4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5609460) /* 0x5597f4 */ + cpu.eax * 4);
    // 00456769  8b1518985500           -mov edx, dword ptr [0x559818]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 0045676f  39fa                   +cmp edx, edi
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
    // 00456771  7f12                   -jg 0x456785
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00456785;
    }
    // 00456773  8b1d4cbb6f00           -mov ebx, dword ptr [0x6fbb4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 00456779  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045677b  ba33000000             -mov edx, 0x33
    cpu.edx = 51 /*0x33*/;
    // 00456780  e86b2e0700             -call 0x4c95f0
    cpu.esp -= 4;
    sub_4c95f0(app, cpu);
    if (cpu.terminate) return;
L_0x00456785:
    // 00456785  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0045678a  8b1518985500           -mov edx, dword ptr [0x559818]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */);
    // 00456790  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00456793  8b1c85f4975500         -mov ebx, dword ptr [eax*4 + 0x5597f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5609460) /* 0x5597f4 */ + cpu.eax * 4);
    // 0045679a  81c1ffffff00           -add ecx, 0xffffff
    (cpu.ecx) += x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 004567a0  39da                   +cmp edx, ebx
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
    // 004567a2  7f42                   -jg 0x4567e6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004567e6;
    }
    // 004567a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004567a6  7e3e                   -jle 0x4567e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004567e6;
    }
    // 004567a8  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004567ab  6683b86e7d670000       +cmp word ptr [eax + 0x677d6e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6782318) /* 0x677d6e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004567b3  7420                   -je 0x4567d5
    if (cpu.flags.zf)
    {
        goto L_0x004567d5;
    }
    // 004567b5  8b98547d6700           -mov ebx, dword ptr [eax + 0x677d54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6782292) /* 0x677d54 */);
    // 004567bb  8b904c7d6700           -mov edx, dword ptr [eax + 0x677d4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6782284) /* 0x677d4c */);
    // 004567c1  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004567c4  8b806c7d6700           -mov eax, dword ptr [eax + 0x677d6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6782316) /* 0x677d6c */);
    // 004567ca  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004567cd  c1f810                 +sar eax, 0x10
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
    // 004567d0  e88b090800             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
L_0x004567d5:
    // 004567d5  e8062e0700             -call 0x4c95e0
    cpu.esp -= 4;
    sub_4c95e0(app, cpu);
    if (cpu.terminate) return;
    // 004567da  e841fbffff             -call 0x456320
    cpu.esp -= 4;
    sub_456320(app, cpu);
    if (cpu.terminate) return;
    // 004567df  a320985500             -mov dword ptr [0x559820], eax
    app->getMemory<x86::reg32>(x86::reg32(5609504) /* 0x559820 */) = cpu.eax;
    // 004567e4  eb0a                   -jmp 0x4567f0
    goto L_0x004567f0;
L_0x004567e6:
    // 004567e6  c7052098550001000000   -mov dword ptr [0x559820], 1
    app->getMemory<x86::reg32>(x86::reg32(5609504) /* 0x559820 */) = 1 /*0x1*/;
L_0x004567f0:
    // 004567f0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004567f2:
    // 004567f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004567f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_456800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456802  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456803  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456804  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456805  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456807  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00456809  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045680b  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00456810  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00456815  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00456817  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00456819  e872890900             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 0045681e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456820  e87b450900             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00456825  803d1050560008         +cmp byte ptr [0x565010], 8
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
    // 0045682c  7507                   -jne 0x456835
    if (!cpu.flags.zf)
    {
        goto L_0x00456835;
    }
    // 0045682e  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00456833  eb02                   -jmp 0x456837
    goto L_0x00456837;
L_0x00456835:
    // 00456835  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00456837:
    // 00456837  e874890900             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 0045683c  833d807d670000         +cmp dword ptr [0x677d80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6782336) /* 0x677d80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456843  741f                   -je 0x456864
    if (cpu.flags.zf)
    {
        goto L_0x00456864;
    }
    // 00456845  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0045684b  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0045684e  a1807d6700             -mov eax, dword ptr [0x677d80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782336) /* 0x677d80 */);
    // 00456853  8b94ba64975500         -mov edx, dword ptr [edx + edi*4 + 0x559764]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5609316) /* 0x559764 */ + cpu.edi * 4);
    // 0045685a  e881890900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 0045685f  e8aca10900             -call 0x4f0a10
    cpu.esp -= 4;
    sub_4f0a10(app, cpu);
    if (cpu.terminate) return;
L_0x00456864:
    // 00456864  e827450900             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00456869  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045686b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0045686e  e81dfb0700             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00456873  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456875  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00456877  e884960900             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 0045687c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045687e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045687f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456880  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456881  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456882  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456883  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_456890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456892  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456893  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456894  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456896  833d2898550000         +cmp dword ptr [0x559828], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5609512) /* 0x559828 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045689d  742a                   -je 0x4568c9
    if (cpu.flags.zf)
    {
        goto L_0x004568c9;
    }
    // 0045689f  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004568a5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004568a7  a14cbb6f00             -mov eax, dword ptr [0x6fbb4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004568ac  890d28985500           -mov dword ptr [0x559828], ecx
    app->getMemory<x86::reg32>(x86::reg32(5609512) /* 0x559828 */) = cpu.ecx;
    // 004568b2  e8292c0700             -call 0x4c94e0
    cpu.esp -= 4;
    sub_4c94e0(app, cpu);
    if (cpu.terminate) return;
    // 004568b7  ba33000000             -mov edx, 0x33
    cpu.edx = 51 /*0x33*/;
    // 004568bc  8b1d4cbb6f00           -mov ebx, dword ptr [0x6fbb4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004568c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004568c4  e8272d0700             -call 0x4c95f0
    cpu.esp -= 4;
    sub_4c95f0(app, cpu);
    if (cpu.terminate) return;
L_0x004568c9:
    // 004568c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004568cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004568cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004568cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004568ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004568cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4568d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004568d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004568d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004568d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004568d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004568d4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004568d6  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004568d9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004568db  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004568e0  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004568e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004568e7  891528985500           -mov dword ptr [0x559828], edx
    app->getMemory<x86::reg32>(x86::reg32(5609512) /* 0x559828 */) = cpu.edx;
    // 004568ed  a38c7d6700             -mov dword ptr [0x677d8c], eax
    app->getMemory<x86::reg32>(x86::reg32(6782348) /* 0x677d8c */) = cpu.eax;
    // 004568f2  891d18985500           -mov dword ptr [0x559818], ebx
    app->getMemory<x86::reg32>(x86::reg32(5609496) /* 0x559818 */) = cpu.ebx;
    // 004568f8  891d1c985500           -mov dword ptr [0x55981c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5609500) /* 0x55981c */) = cpu.ebx;
    // 004568fe  b8889a5300             -mov eax, 0x539a88
    cpu.eax = 5479048 /*0x539a88*/;
    // 00456903  891d787d6700           -mov dword ptr [0x677d78], ebx
    app->getMemory<x86::reg32>(x86::reg32(6782328) /* 0x677d78 */) = cpu.ebx;
    // 00456909  e8a2f40700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045690e  66a3927d6700           -mov word ptr [0x677d92], ax
    app->getMemory<x86::reg16>(x86::reg32(6782354) /* 0x677d92 */) = cpu.ax;
    // 00456914  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00456919  8b148520965500         -mov edx, dword ptr [eax*4 + 0x559620]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608992) /* 0x559620 */ + cpu.eax * 4);
    // 00456920  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456921  68b4317a00             -push 0x7a31b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008116 /*0x7a31b4*/;
    cpu.esp -= 4;
    // 00456926  68909a5300             -push 0x539a90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479056 /*0x539a90*/;
    cpu.esp -= 4;
    // 0045692b  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045692e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045692f  e85c8d0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00456934  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00456937  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045693a  ba9c9a5300             -mov edx, 0x539a9c
    cpu.edx = 5479068 /*0x539a9c*/;
    // 0045693f  e84c43ffff             -call 0x44ac90
    cpu.esp -= 4;
    sub_44ac90(app, cpu);
    if (cpu.terminate) return;
    // 00456944  a3807d6700             -mov dword ptr [0x677d80], eax
    app->getMemory<x86::reg32>(x86::reg32(6782336) /* 0x677d80 */) = cpu.eax;
    // 00456949  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045694b  e8f0c0feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00456950  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456952  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456954  741a                   -je 0x456970
    if (cpu.flags.zf)
    {
        goto L_0x00456970;
    }
    // 00456956  baa89a5300             -mov edx, 0x539aa8
    cpu.edx = 5479080 /*0x539aa8*/;
    // 0045695b  a1807d6700             -mov eax, dword ptr [0x677d80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6782336) /* 0x677d80 */);
    // 00456960  e87b880900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00456965  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00456967  e824fa0700             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 0045696c  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x00456970:
    // 00456970  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00456972  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456974  e887feffff             -call 0x456800
    cpu.esp -= 4;
    sub_456800(app, cpu);
    if (cpu.terminate) return;
    // 00456979  66a3907d6700           -mov word ptr [0x677d90], ax
    app->getMemory<x86::reg16>(x86::reg32(6782352) /* 0x677d90 */) = cpu.ax;
    // 0045697f  e87cf8ffff             -call 0x456200
    cpu.esp -= 4;
    sub_456200(app, cpu);
    if (cpu.terminate) return;
    // 00456984  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456986  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456988  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456989  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045698a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045698b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045698c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_456990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456990  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456991  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456993  e8f82b0700             -call 0x4c9590
    cpu.esp -= 4;
    sub_4c9590(app, cpu);
    if (cpu.terminate) return;
    // 00456998  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045699a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045699b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4569a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004569a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004569a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004569a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004569a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004569a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004569a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004569a7  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004569ad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004569af  b82b000000             -mov eax, 0x2b
    cpu.eax = 43 /*0x2b*/;
    // 004569b4  e897ae0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004569b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004569ba  68b09a5300             -push 0x539ab0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479088 /*0x539ab0*/;
    cpu.esp -= 4;
    // 004569bf  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004569c5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004569c6  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004569cb  e8c08c0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004569d0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004569d3  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004569d9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004569db  e840b6ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 004569e0  6689411e               -mov word ptr [ecx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.ax;
L_0x004569e4:
    // 004569e4  3b594c                 +cmp ebx, dword ptr [ecx + 0x4c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004569e7  7d29                   -jge 0x456a12
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00456a12;
    }
    // 004569e9  8b4154                 -mov eax, dword ptr [ecx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 004569ec  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004569ee  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004569f0  e8cb2dfeff             -call 0x4397c0
    cpu.esp -= 4;
    sub_4397c0(app, cpu);
    if (cpu.terminate) return;
    // 004569f5  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004569fa  e821b6ffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 004569ff  8b711c                 -mov esi, dword ptr [ecx + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00456a02  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00456a05  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456a07  39f0                   +cmp eax, esi
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
    // 00456a09  7e04                   -jle 0x456a0f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00456a0f;
    }
    // 00456a0b  6689411e               -mov word ptr [ecx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.ax;
L_0x00456a0f:
    // 00456a0f  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00456a10  ebd2                   -jmp 0x4569e4
    goto L_0x004569e4;
L_0x00456a12:
    // 00456a12  6683411e26             -add word ptr [ecx + 0x1e], 0x26
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */)) += x86::reg16(x86::sreg16(38 /*0x26*/));
    // 00456a17  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456a19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456a1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456a1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456a1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456a1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456a1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_456a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456a20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456a21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456a22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456a23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456a24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456a25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456a26  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456a28  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00456a2b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00456a2d  c645f8ff               -mov byte ptr [ebp - 8], 0xff
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 255 /*0xff*/;
    // 00456a31  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00456a33  0f84ff000000           -je 0x456b38
    if (cpu.flags.zf)
    {
        goto L_0x00456b38;
    }
    // 00456a39  66837e4000             +cmp word ptr [esi + 0x40], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00456a3e  745b                   -je 0x456a9b
    if (cpu.flags.zf)
    {
        goto L_0x00456a9b;
    }
    // 00456a40  a128d36f00             -mov eax, dword ptr [0x6fd328]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
    // 00456a45  e80630feff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00456a4a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00456a4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456a4e  0f8496000000           -je 0x456aea
    if (cpu.flags.zf)
    {
        goto L_0x00456aea;
    }
    // 00456a54  c7465428d36f00         -mov dword ptr [esi + 0x54], 0x6fd328
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = 7328552 /*0x6fd328*/;
    // 00456a5b  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456a5e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456a60  894660                 -mov dword ptr [esi + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00456a63  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456a66  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00456a6b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456a6d  e81e2dfeff             -call 0x439790
    cpu.esp -= 4;
    sub_439790(app, cpu);
    if (cpu.terminate) return;
    // 00456a72  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00456a75  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00456a78  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00456a7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456a7c  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456a7f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456a80  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456a83  8d4dec                 -lea ecx, [ebp - 0x14]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456a86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456a87  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456a8a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00456a8f  8b5644                 -mov edx, dword ptr [esi + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00456a92  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456a94  e8772dfeff             -call 0x439810
    cpu.esp -= 4;
    sub_439810(app, cpu);
    if (cpu.terminate) return;
    // 00456a99  eb4f                   -jmp 0x456aea
    goto L_0x00456aea;
L_0x00456a9b:
    // 00456a9b  a1bcd26f00             -mov eax, dword ptr [0x6fd2bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 00456aa0  e8ab2ffeff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00456aa5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00456aa7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456aa9  743f                   -je 0x456aea
    if (cpu.flags.zf)
    {
        goto L_0x00456aea;
    }
    // 00456aab  c74654bcd26f00         -mov dword ptr [esi + 0x54], 0x6fd2bc
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = 7328444 /*0x6fd2bc*/;
    // 00456ab2  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456ab5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456ab7  894660                 -mov dword ptr [esi + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00456aba  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456abd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00456abf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456ac1  e8ca2cfeff             -call 0x439790
    cpu.esp -= 4;
    sub_439790(app, cpu);
    if (cpu.terminate) return;
    // 00456ac6  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00456ac9  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00456acc  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00456acf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456ad0  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456ad3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456ad4  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456ad7  8d4dec                 -lea ecx, [ebp - 0x14]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456ada  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456adb  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456ade  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00456ae0  8b5644                 -mov edx, dword ptr [esi + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00456ae3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456ae5  e8262dfeff             -call 0x439810
    cpu.esp -= 4;
    sub_439810(app, cpu);
    if (cpu.terminate) return;
L_0x00456aea:
    // 00456aea  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00456aec  744a                   -je 0x456b38
    if (cpu.flags.zf)
    {
        goto L_0x00456b38;
    }
    // 00456aee  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456af1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456af3  e8682cfeff             -call 0x439760
    cpu.esp -= 4;
    sub_439760(app, cpu);
    if (cpu.terminate) return;
    // 00456af8  89464c                 -mov dword ptr [esi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00456afb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456afd  8a45f8                 -mov al, byte ptr [ebp - 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00456b00  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456b02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b04  8a45ec                 -mov al, byte ptr [ebp - 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456b07  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456b0d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456b12  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00456b15  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00456b18  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b1a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b1c  8a45fc                 -mov al, byte ptr [ebp - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456b1f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456b24  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00456b27  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b2b  8a45f0                 -mov al, byte ptr [ebp - 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456b2e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456b33  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b35  895650                 -mov dword ptr [esi + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.edx;
L_0x00456b38:
    // 00456b38  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456b3a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456b40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_456b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456b50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456b51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456b52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456b53  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456b55  81ec1c010000           -sub esp, 0x11c
    (cpu.esp) -= x86::reg32(x86::sreg32(284 /*0x11c*/));
    // 00456b5b  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00456b5e  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00456b61  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00456b63  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00456b65  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 00456b69  0f849c000000           -je 0x456c0b
    if (cpu.flags.zf)
    {
        goto L_0x00456c0b;
    }
    // 00456b6f  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00456b72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456b73  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456b76  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00456b79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456b7a  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00456b7d  8d4df4                 -lea ecx, [ebp - 0xc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00456b80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456b81  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00456b84  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456b87  8b5b3e                 -mov ebx, dword ptr [ebx + 0x3e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(62) /* 0x3e */);
    // 00456b8a  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00456b8d  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00456b90  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456b92  e8792cfeff             -call 0x439810
    cpu.esp -= 4;
    sub_439810(app, cpu);
    if (cpu.terminate) return;
    // 00456b97  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456b99  8a45f4                 -mov al, byte ptr [ebp - 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00456b9c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456b9e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456ba0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456ba6  8a45f8                 -mov al, byte ptr [ebp - 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00456ba9  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00456bac  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456bb1  81ca000000ff           -or edx, 0xff000000
    cpu.edx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00456bb7  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00456bba  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00456bbc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00456bbe  8a45fc                 -mov al, byte ptr [ebp - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00456bc1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00456bc6  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00456bc8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456bc9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00456bcb  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 00456bd0  40                     -inc eax
    (cpu.eax)++;
    // 00456bd1  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00456bd6  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00456bd9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00456bdb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456bdd  e82e1d0800             -call 0x4d8910
    cpu.esp -= 4;
    sub_4d8910(app, cpu);
    if (cpu.terminate) return;
    // 00456be2  837d1000               +cmp dword ptr [ebp + 0x10], 0
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
    // 00456be6  7407                   -je 0x456bef
    if (cpu.flags.zf)
    {
        goto L_0x00456bef;
    }
    // 00456be8  6840e4ffff             -push 0xffffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 4294960192 /*0xffffe440*/;
    cpu.esp -= 4;
    // 00456bed  eb05                   -jmp 0x456bf4
    goto L_0x00456bf4;
L_0x00456bef:
    // 00456bef  68b58a7bff             -push 0xff7b8ab5
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286286517 /*0xff7b8ab5*/;
    cpu.esp -= 4;
L_0x00456bf4:
    // 00456bf4  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 00456bf9  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00456bfe  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00456c01  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456c03  e8981e0800             -call 0x4d8aa0
    cpu.esp -= 4;
    sub_4d8aa0(app, cpu);
    if (cpu.terminate) return;
    // 00456c08  83c613                 -add esi, 0x13
    (cpu.esi) += x86::reg32(x86::sreg32(19 /*0x13*/));
L_0x00456c0b:
    // 00456c0b  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 00456c0f  740d                   -je 0x456c1e
    if (cpu.flags.zf)
    {
        goto L_0x00456c1e;
    }
    // 00456c11  837d1000               +cmp dword ptr [ebp + 0x10], 0
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
    // 00456c15  7517                   -jne 0x456c2e
    if (!cpu.flags.zf)
    {
        goto L_0x00456c2e;
    }
    // 00456c17  bafd9d64ff             -mov edx, 0xff649dfd
    cpu.edx = 4284784125 /*0xff649dfd*/;
    // 00456c1c  eb15                   -jmp 0x456c33
    goto L_0x00456c33;
L_0x00456c1e:
    // 00456c1e  e8cd31ffff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00456c23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456c25  7407                   -je 0x456c2e
    if (cpu.flags.zf)
    {
        goto L_0x00456c2e;
    }
    // 00456c27  ba964a0000             -mov edx, 0x4a96
    cpu.edx = 19094 /*0x4a96*/;
    // 00456c2c  eb05                   -jmp 0x456c33
    goto L_0x00456c33;
L_0x00456c2e:
    // 00456c2e  ba40e4ff00             -mov edx, 0xffe440
    cpu.edx = 16770112 /*0xffe440*/;
L_0x00456c33:
    // 00456c33  f6052feb550040         +test byte ptr [0x55eb2f], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630767) /* 0x55eb2f */) & 64 /*0x40*/));
    // 00456c3a  0f858a000000           -jne 0x456cca
    if (!cpu.flags.zf)
    {
        goto L_0x00456cca;
    }
    // 00456c40  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00456c43  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00456c46  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456c48  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00456c4b  e8302bfeff             -call 0x439780
    cpu.esp -= 4;
    sub_439780(app, cpu);
    if (cpu.terminate) return;
    // 00456c50  39c8                   +cmp eax, ecx
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
    // 00456c52  7556                   -jne 0x456caa
    if (!cpu.flags.zf)
    {
        goto L_0x00456caa;
    }
    // 00456c54  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00456c57  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00456c59  7433                   -je 0x456c8e
    if (cpu.flags.zf)
    {
        goto L_0x00456c8e;
    }
    // 00456c5b  b82b000000             -mov eax, 0x2b
    cpu.eax = 43 /*0x2b*/;
    // 00456c60  e8ebab0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00456c65  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456c66  68b09a5300             -push 0x539ab0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5479088 /*0x539ab0*/;
    cpu.esp -= 4;
    // 00456c6b  8d85e4feffff           -lea eax, [ebp - 0x11c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-284) /* -0x11c */);
    // 00456c71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456c72  e8198a0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00456c77  83c40c                 +add esp, 0xc
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
    // 00456c7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456c7b  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00456c80  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00456c82  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00456c84  8d85e4feffff           -lea eax, [ebp - 0x11c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-284) /* -0x11c */);
    // 00456c8a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00456c8c  eb15                   -jmp 0x456ca3
    goto L_0x00456ca3;
L_0x00456c8e:
    // 00456c8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456c8f  b82b000000             -mov eax, 0x2b
    cpu.eax = 43 /*0x2b*/;
    // 00456c94  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00456c99  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456c9a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00456c9c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00456c9e  e8adab0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
L_0x00456ca3:
    // 00456ca3  e8e8b4ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00456ca8  eb20                   -jmp 0x456cca
    goto L_0x00456cca;
L_0x00456caa:
    // 00456caa  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00456cad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456cae  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00456cb0  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00456cb3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00456cb5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00456cb7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456cb9  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00456cbe  e8fd2afeff             -call 0x4397c0
    cpu.esp -= 4;
    sub_4397c0(app, cpu);
    if (cpu.terminate) return;
    // 00456cc3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00456cc5  e8c6b4ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00456cca:
    // 00456cca  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456ccc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456ccd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456cce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456ccf  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_456ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456ce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456ce2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456ce3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456ce4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456ce5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456ce7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00456cea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456cec  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00456cee  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00456cf3  e86839ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00456cf8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456cfa  0f8490010000           -je 0x456e90
    if (cpu.flags.zf)
    {
        goto L_0x00456e90;
    }
    // 00456d00  8b5154                 -mov edx, dword ptr [ecx + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 00456d03  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00456d05  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00456d07  0f8481010000           -je 0x456e8e
    if (cpu.flags.zf)
    {
        goto L_0x00456e8e;
    }
    // 00456d0d  6683795800             +cmp word ptr [ecx + 0x58], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(88) /* 0x58 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00456d12  7406                   -je 0x456d1a
    if (cpu.flags.zf)
    {
        goto L_0x00456d1a;
    }
    // 00456d14  80490504               +or byte ptr [ecx + 5], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00456d18  eb04                   -jmp 0x456d1e
    goto L_0x00456d1e;
L_0x00456d1a:
    // 00456d1a  806105fb               -and byte ptr [ecx + 5], 0xfb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x00456d1e:
    // 00456d1e  8b5654                 -mov edx, dword ptr [esi + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00456d21  8b4660                 -mov eax, dword ptr [esi + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 00456d24  3b02                   +cmp eax, dword ptr [edx]
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
    // 00456d26  7407                   -je 0x456d2f
    if (cpu.flags.zf)
    {
        goto L_0x00456d2f;
    }
    // 00456d28  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456d2a  e8f1fcffff             -call 0x456a20
    cpu.esp -= 4;
    sub_456a20(app, cpu);
    if (cpu.terminate) return;
L_0x00456d2f:
    // 00456d2f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00456d31  0f842b010000           -je 0x456e62
    if (cpu.flags.zf)
    {
        goto L_0x00456e62;
    }
    // 00456d37  66837e5800             +cmp word ptr [esi + 0x58], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(88) /* 0x58 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00456d3c  0f8404010000           -je 0x456e46
    if (cpu.flags.zf)
    {
        goto L_0x00456e46;
    }
    // 00456d42  8d461a                 -lea eax, [esi + 0x1a]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00456d45  e8a6540400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 00456d4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456d4c  7421                   -je 0x456d6f
    if (cpu.flags.zf)
    {
        goto L_0x00456d6f;
    }
    // 00456d4e  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00456d51  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00456d56  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456d59  e862540400             -call 0x49c1c0
    cpu.esp -= 4;
    sub_49c1c0(app, cpu);
    if (cpu.terminate) return;
    // 00456d5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456d60  7c0d                   -jl 0x456d6f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00456d6f;
    }
    // 00456d62  3b464c                 +cmp eax, dword ptr [esi + 0x4c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456d65  7d08                   -jge 0x456d6f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00456d6f;
    }
    // 00456d67  3b4648                 +cmp eax, dword ptr [esi + 0x48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456d6a  7403                   -je 0x456d6f
    if (cpu.flags.zf)
    {
        goto L_0x00456d6f;
    }
    // 00456d6c  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
L_0x00456d6f:
    // 00456d6f  68222222d0             -push 0xd0222222
    app->getMemory<x86::reg32>(cpu.esp-4) = 3491897890 /*0xd0222222*/;
    cpu.esp -= 4;
    // 00456d74  8b4e1e                 -mov ecx, dword ptr [esi + 0x1e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(30) /* 0x1e */);
    // 00456d77  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00456d7a  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00456d7d  8b461a                 -mov eax, dword ptr [esi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00456d80  68222222d0             -push 0xd0222222
    app->getMemory<x86::reg32>(cpu.esp-4) = 3491897890 /*0xd0222222*/;
    cpu.esp -= 4;
    // 00456d85  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00456d88  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00456d8b  68400000a0             -push 0xa0000040
    app->getMemory<x86::reg32>(cpu.esp-4) = 2684354624 /*0xa0000040*/;
    cpu.esp -= 4;
    // 00456d90  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456d93  68400000a0             -push 0xa0000040
    app->getMemory<x86::reg32>(cpu.esp-4) = 2684354624 /*0xa0000040*/;
    cpu.esp -= 4;
    // 00456d98  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456d9b  e8201d0800             -call 0x4d8ac0
    cpu.esp -= 4;
    sub_4d8ac0(app, cpu);
    if (cpu.terminate) return;
    // 00456da0  668b461a               -mov ax, word ptr [esi + 0x1a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00456da4  0505000000             -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00456da9  668945f8               -mov word ptr [ebp - 8], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ax;
    // 00456dad  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00456db1  0505000000             -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00456db6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00456db8  668945fc               -mov word ptr [ebp - 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
L_0x00456dbc:
    // 00456dbc  3b7e4c                 +cmp edi, dword ptr [esi + 0x4c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00456dbf  7d35                   -jge 0x456df6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00456df6;
    }
    // 00456dc1  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00456dc4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00456dc6  39d7                   +cmp edi, edx
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
    // 00456dc8  7507                   -jne 0x456dd1
    if (!cpu.flags.zf)
    {
        goto L_0x00456dd1;
    }
    // 00456dca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00456dcf  eb02                   -jmp 0x456dd3
    goto L_0x00456dd3;
L_0x00456dd1:
    // 00456dd1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00456dd3:
    // 00456dd3  8b4df6                 -mov ecx, dword ptr [ebp - 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00456dd6  8b5dfa                 -mov ebx, dword ptr [ebp - 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00456dd9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00456dda  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00456ddc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00456ddf  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00456de2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456de4  e867fdffff             -call 0x456b50
    cpu.esp -= 4;
    sub_456b50(app, cpu);
    if (cpu.terminate) return;
    // 00456de9  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00456dec  83c110                 +add ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00456def  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00456df0  66894df8               -mov word ptr [ebp - 8], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.cx;
    // 00456df4  ebc6                   -jmp 0x456dbc
    goto L_0x00456dbc;
L_0x00456df6:
    // 00456df6  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00456dfa  668b5606               -mov dx, word ptr [esi + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00456dfe  0fbfc8                 -movsx ecx, ax
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00456e01  0fbffa                 -movsx edi, dx
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 00456e04  8d590d                 -lea ebx, [ecx + 0xd]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00456e07  8b465a                 -mov eax, dword ptr [esi + 0x5a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(90) /* 0x5a */);
    // 00456e0a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00456e0c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456e0f  e87c0b0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00456e14  8d570c                 -lea edx, [edi + 0xc]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00456e17  8b465c                 -mov eax, dword ptr [esi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 00456e1a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00456e1c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456e1f  e86c0b0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00456e24  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 00456e29  8d19                   -lea ebx, [ecx]
    cpu.ebx = x86::reg32(cpu.ecx);
    // 00456e2b  90                     -nop 
    ;
    // 00456e2c  8b561a                 -mov edx, dword ptr [esi + 0x1a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00456e2f  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00456e32  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00456e34  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456e37  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00456e3c  83c20f                 +add edx, 0xf
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00456e3f  e84cb3ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00456e44  eb1c                   -jmp 0x456e62
    goto L_0x00456e62;
L_0x00456e46:
    // 00456e46  668b5608               -mov dx, word ptr [esi + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00456e4a  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 00456e4d  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00456e51  8d5a0d                 -lea ebx, [edx + 0xd]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00456e54  0fbfd0                 -movsx edx, ax
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00456e57  8b465a                 -mov eax, dword ptr [esi + 0x5a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(90) /* 0x5a */);
    // 00456e5a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456e5d  e82e0b0800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00456e62:
    // 00456e62  66837e5800             +cmp word ptr [esi + 0x58], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(88) /* 0x58 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00456e67  7525                   -jne 0x456e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00456e8e;
    }
    // 00456e69  8b0d609c5500           -mov ecx, dword ptr [0x559c60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5610592) /* 0x559c60 */);
    // 00456e6f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00456e71  751b                   -jne 0x456e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00456e8e;
    }
    // 00456e73  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456e74  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00456e77  8b5644                 -mov edx, dword ptr [esi + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00456e7a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456e7b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00456e7e  8b4e06                 -mov ecx, dword ptr [esi + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00456e81  8d5819                 -lea ebx, [eax + 0x19]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(25) /* 0x19 */);
    // 00456e84  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00456e87  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456e89  e8c2fcffff             -call 0x456b50
    cpu.esp -= 4;
    sub_456b50(app, cpu);
    if (cpu.terminate) return;
L_0x00456e8e:
    // 00456e8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00456e90:
    // 00456e90  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00456e92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456e93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456e94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456e95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456e96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456e97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_456ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456ea0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456ea1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456ea2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456ea3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456ea5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456ea7  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00456eac  e8af37ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00456eb1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456eb3  7453                   -je 0x456f08
    if (cpu.flags.zf)
    {
        goto L_0x00456f08;
    }
    // 00456eb5  b8b89a5300             -mov eax, 0x539ab8
    cpu.eax = 5479096 /*0x539ab8*/;
    // 00456eba  66c741580000           -mov word ptr [ecx + 0x58], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
    // 00456ec0  e8ebee0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00456ec5  6689415c               -mov word ptr [ecx + 0x5c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.ax;
    // 00456ec9  b8c09a5300             -mov eax, 0x539ac0
    cpu.eax = 5479104 /*0x539ac0*/;
    // 00456ece  e8ddee0700             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00456ed3  c7414400000000         -mov dword ptr [ecx + 0x44], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 00456eda  c7414c00000000         -mov dword ptr [ecx + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 00456ee1  c7415400000000         -mov dword ptr [ecx + 0x54], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00456ee8  c7415000000000         -mov dword ptr [ecx + 0x50], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = 0 /*0x0*/;
    // 00456eef  6689415e               -mov word ptr [ecx + 0x5e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(94) /* 0x5e */) = cpu.ax;
    // 00456ef3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00456ef5  c7414800000000         -mov dword ptr [ecx + 0x48], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 00456efc  e81ffbffff             -call 0x456a20
    cpu.esp -= 4;
    sub_456a20(app, cpu);
    if (cpu.terminate) return;
    // 00456f01  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00456f03  e898faffff             -call 0x4569a0
    cpu.esp -= 4;
    sub_4569a0(app, cpu);
    if (cpu.terminate) return;
L_0x00456f08:
    // 00456f08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_456f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456f10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456f11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456f12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456f13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456f14  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456f16  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456f18  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00456f1b  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00456f1e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00456f21  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456f24  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00456f26  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00456f29  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00456f2c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456f2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00456f31  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00456f34  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00456f36  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00456f38  8b511a                 -mov edx, dword ptr [ecx + 0x1a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 00456f3b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456f3e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00456f40  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00456f42  e879500400             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
    // 00456f47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_456f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456f50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456f51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456f52  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456f54  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00456f57  66c740580100           -mov word ptr [eax + 0x58], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(88) /* 0x58 */) = 1 /*0x1*/;
    // 00456f5d  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00456f60  e87b020000             -call 0x4571e0
    cpu.esp -= 4;
    sub_4571e0(app, cpu);
    if (cpu.terminate) return;
    // 00456f65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_456f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456f70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456f71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456f72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456f74  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00456f77  66c740580000           -mov word ptr [eax + 0x58], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
    // 00456f7d  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00456f80  e85b020000             -call 0x4571e0
    cpu.esp -= 4;
    sub_4571e0(app, cpu);
    if (cpu.terminate) return;
    // 00456f85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00456f87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_456f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00456f90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00456f91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00456f92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00456f93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00456f94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00456f95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00456f96  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00456f98  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00456f9a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00456f9c  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00456f9f  8b4044                 -mov eax, dword ptr [eax + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00456fa2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00456fa4  39d0                   +cmp eax, edx
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
    // 00456fa6  7405                   -je 0x456fad
    if (cpu.flags.zf)
    {
        goto L_0x00456fad;
    }
    // 00456fa8  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00456fad:
    // 00456fad  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00456fb0  66c741580000           -mov word ptr [ecx + 0x58], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
    // 00456fb6  894144                 -mov dword ptr [ecx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00456fb9  8b5948                 -mov ebx, dword ptr [ecx + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00456fbc  8b513e                 -mov edx, dword ptr [ecx + 0x3e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 00456fbf  8b4154                 -mov eax, dword ptr [ecx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 00456fc2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00456fc5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00456fc7  e80428feff             -call 0x4397d0
    cpu.esp -= 4;
    sub_4397d0(app, cpu);
    if (cpu.terminate) return;
    // 00456fcc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00456fce  e80d020000             -call 0x4571e0
    cpu.esp -= 4;
    sub_4571e0(app, cpu);
    if (cpu.terminate) return;
    // 00456fd3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00456fd5  7444                   -je 0x45701b
    if (cpu.flags.zf)
    {
        goto L_0x0045701b;
    }
    // 00456fd7  6683794000             +cmp word ptr [ecx + 0x40], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00456fdc  751a                   -jne 0x456ff8
    if (!cpu.flags.zf)
    {
        goto L_0x00456ff8;
    }
    // 00456fde  bac89a5300             -mov edx, 0x539ac8
    cpu.edx = 5479112 /*0x539ac8*/;
    // 00456fe3  e8c83effff             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00456fe8  e853bafeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00456fed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00456fef  7407                   -je 0x456ff8
    if (cpu.flags.zf)
    {
        goto L_0x00456ff8;
    }
    // 00456ff1  c680b300000001         -mov byte ptr [eax + 0xb3], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(179) /* 0xb3 */) = 1 /*0x1*/;
L_0x00456ff8:
    // 00456ff8  668b5940               -mov bx, word ptr [ecx + 0x40]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 00456ffc  6683fb01               +cmp bx, 1
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457000  7519                   -jne 0x45701b
    if (!cpu.flags.zf)
    {
        goto L_0x0045701b;
    }
    // 00457002  badc9a5300             -mov edx, 0x539adc
    cpu.edx = 5479132 /*0x539adc*/;
    // 00457007  e8a43effff             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 0045700c  e82fbafeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00457011  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457013  7406                   -je 0x45701b
    if (cpu.flags.zf)
    {
        goto L_0x0045701b;
    }
    // 00457015  8898b3000000           -mov byte ptr [eax + 0xb3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(179) /* 0xb3 */) = cpu.bl;
L_0x0045701b:
    // 0045701b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045701c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045701d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045701e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045701f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457020  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457021  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_457030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457031  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00457032  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00457033  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457034  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457036  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00457038  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0045703d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045703f  e81c36ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00457044  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00457046  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457048  0f847e010000           -je 0x4571cc
    if (cpu.flags.zf)
    {
        goto L_0x004571cc;
    }
    // 0045704e  83795400               +cmp dword ptr [ecx + 0x54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00457052  7507                   -jne 0x45705b
    if (!cpu.flags.zf)
    {
        goto L_0x0045705b;
    }
    // 00457054  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00457056  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457057  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457058  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457059  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045705a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045705b:
    // 0045705b  6683795800             +cmp word ptr [ecx + 0x58], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(88) /* 0x58 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457060  7531                   -jne 0x457093
    if (!cpu.flags.zf)
    {
        goto L_0x00457093;
    }
    // 00457062  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457066  740b                   -je 0x457073
    if (cpu.flags.zf)
    {
        goto L_0x00457073;
    }
    // 00457068  6681fb004d             +cmp bx, 0x4d00
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045706d  0f8557010000           -jne 0x4571ca
    if (!cpu.flags.zf)
    {
        goto L_0x004571ca;
    }
L_0x00457073:
    // 00457073  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00457075  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0045707a  e8d1feffff             -call 0x456f50
    cpu.esp -= 4;
    sub_456f50(app, cpu);
    if (cpu.terminate) return;
    // 0045707f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00457084  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00457089  e84211fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0045708e  e937010000             -jmp 0x4571ca
    goto L_0x004571ca;
L_0x00457093:
    // 00457093  6681fb0048             +cmp bx, 0x4800
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18432 /*0x4800*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00457098  7221                   -jb 0x4570bb
    if (cpu.flags.cf)
    {
        goto L_0x004570bb;
    }
    // 0045709a  7640                   -jbe 0x4570dc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004570dc;
    }
    // 0045709c  6681fb004b             +cmp bx, 0x4b00
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004570a1  0f8223010000           -jb 0x4571ca
    if (cpu.flags.cf)
    {
        goto L_0x004571ca;
    }
    // 004570a7  0f86a5000000           -jbe 0x457152
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457152;
    }
    // 004570ad  6681fb0050             +cmp bx, 0x5000
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20480 /*0x5000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004570b2  7463                   -je 0x457117
    if (cpu.flags.zf)
    {
        goto L_0x00457117;
    }
    // 004570b4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004570b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004570bb:
    // 004570bb  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004570bf  0f8205010000           -jb 0x4571ca
    if (cpu.flags.cf)
    {
        goto L_0x004571ca;
    }
    // 004570c5  0f8687000000           -jbe 0x457152
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00457152;
    }
    // 004570cb  6683fb1b               +cmp bx, 0x1b
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004570cf  0f84da000000           -je 0x4571af
    if (cpu.flags.zf)
    {
        goto L_0x004571af;
    }
    // 004570d5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004570d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004570db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004570dc:
    // 004570dc  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004570df  48                     -dec eax
    (cpu.eax)--;
    // 004570e0  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004570e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004570e7  7d04                   -jge 0x4570ed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004570ed;
    }
    // 004570e9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004570eb  eb0a                   -jmp 0x4570f7
    goto L_0x004570f7;
L_0x004570ed:
    // 004570ed  8b514c                 -mov edx, dword ptr [ecx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 004570f0  4a                     -dec edx
    (cpu.edx)--;
    // 004570f1  39d0                   +cmp eax, edx
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
    // 004570f3  7e02                   -jle 0x4570f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004570f7;
    }
    // 004570f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004570f7:
    // 004570f7  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004570fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004570fc  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00457101  e80afeffff             -call 0x456f10
    cpu.esp -= 4;
    sub_456f10(app, cpu);
    if (cpu.terminate) return;
    // 00457106  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 0045710b  e8c010fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00457110  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00457112  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457113  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457114  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457115  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457116  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00457117:
    // 00457117  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0045711a  40                     -inc eax
    (cpu.eax)++;
    // 0045711b  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00457120  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00457122  7d04                   -jge 0x457128
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00457128;
    }
    // 00457124  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00457126  eb0a                   -jmp 0x457132
    goto L_0x00457132;
L_0x00457128:
    // 00457128  8b514c                 -mov edx, dword ptr [ecx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0045712b  4a                     -dec edx
    (cpu.edx)--;
    // 0045712c  39d0                   +cmp eax, edx
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
    // 0045712e  7e02                   -jle 0x457132
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00457132;
    }
    // 00457130  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00457132:
    // 00457132  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00457135  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00457137  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0045713c  e8cffdffff             -call 0x456f10
    cpu.esp -= 4;
    sub_456f10(app, cpu);
    if (cpu.terminate) return;
    // 00457141  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 00457146  e88510fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0045714b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045714d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045714e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045714f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457150  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457151  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00457152:
    // 00457152  8d461a                 -lea eax, [esi + 0x1a]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00457155  e896500400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 0045715a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045715c  7451                   -je 0x4571af
    if (cpu.flags.zf)
    {
        goto L_0x004571af;
    }
    // 0045715e  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00457163  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00457168  e86310fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0045716d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045716f  e81cfeffff             -call 0x456f90
    cpu.esp -= 4;
    sub_456f90(app, cpu);
    if (cpu.terminate) return;
    // 00457174  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00457177  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00457179  e80226feff             -call 0x439780
    cpu.esp -= 4;
    sub_439780(app, cpu);
    if (cpu.terminate) return;
    // 0045717e  8b4e48                 -mov ecx, dword ptr [esi + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00457181  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00457186  39c8                   +cmp eax, ecx
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
    // 00457188  7540                   -jne 0x4571ca
    if (!cpu.flags.zf)
    {
        goto L_0x004571ca;
    }
    // 0045718a  baf09a5300             -mov edx, 0x539af0
    cpu.edx = 5479152 /*0x539af0*/;
    // 0045718f  e81c3dffff             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00457194  e8a7b8feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00457199  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045719b  742d                   -je 0x4571ca
    if (cpu.flags.zf)
    {
        goto L_0x004571ca;
    }
    // 0045719d  8b563e                 -mov edx, dword ptr [esi + 0x3e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(62) /* 0x3e */);
    // 004571a0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004571a3  e8a86bfeff             -call 0x43dd50
    cpu.esp -= 4;
    sub_43dd50(app, cpu);
    if (cpu.terminate) return;
    // 004571a8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004571aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004571af:
    // 004571af  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 004571b4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004571b9  e81210fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 004571be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004571c0  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004571c5  e8a6fdffff             -call 0x456f70
    cpu.esp -= 4;
    sub_456f70(app, cpu);
    if (cpu.terminate) return;
L_0x004571ca:
    // 004571ca  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004571cc:
    // 004571cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004571d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4571e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004571e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004571e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004571e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004571e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004571e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004571e7  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004571ec  e86f34ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 004571f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004571f3  7455                   -je 0x45724a
    if (cpu.flags.zf)
    {
        goto L_0x0045724a;
    }
    // 004571f5  6683795800             +cmp word ptr [ecx + 0x58], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(88) /* 0x58 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004571fa  742f                   -je 0x45722b
    if (cpu.flags.zf)
    {
        goto L_0x0045722b;
    }
    // 004571fc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004571fe  e89df7ffff             -call 0x4569a0
    cpu.esp -= 4;
    sub_4569a0(app, cpu);
    if (cpu.terminate) return;
    // 00457203  668b414c               -mov ax, word ptr [ecx + 0x4c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 00457207  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0045720a  0508000000             -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045720f  66894120               -mov word ptr [ecx + 0x20], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 00457213  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00457217  051c000000             -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0045721c  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 00457220  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00457224  0511000000             +add eax, 0x11
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00457229  eb1b                   -jmp 0x457246
    goto L_0x00457246;
L_0x0045722b:
    // 0045722b  66c741201b00           -mov word ptr [ecx + 0x20], 0x1b
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 27 /*0x1b*/;
    // 00457231  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00457235  66c7411e1e00           -mov word ptr [ecx + 0x1e], 0x1e
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = 30 /*0x1e*/;
    // 0045723b  83e80a                 -sub eax, 0xa
    (cpu.eax) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0045723e  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 00457242  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x00457246:
    // 00457246  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
L_0x0045724a:
    // 0045724a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045724b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045724c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045724d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_457250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457250  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457251  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457253  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00457254  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_457260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00457260  696e7430008d80         -imul ebp, dword ptr [esi + 0x74], 0x808d0030
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */))) * x86::sreg64(x86::sreg32(2156724272 /*0x808d0030*/)));
    // 00457267  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457269  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045726b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0045726e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
    // 00457270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457272  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457273  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457274  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457276  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00457278  eb2b                   -jmp 0x4572a5
    goto L_0x004572a5;
L_0x0045727a:
    // 0045727a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x0045727c:
    // 0045727c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045727e  8b144582985500         -mov edx, dword ptr [eax*2 + 0x559882]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609602) /* 0x559882 */ + cpu.eax * 2);
    // 00457285  8b1de8e55500           -mov ebx, dword ptr [0x55e5e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0045728b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045728e  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457290  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00457292  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00457294  7f02                   -jg 0x457298
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00457298;
    }
    // 00457296  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00457298:
    // 00457298  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045729a  83f910                 +cmp ecx, 0x10
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
    // 0045729d  7c25                   -jl 0x4572c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004572c4;
    }
    // 0045729f  40                     -inc eax
    (cpu.eax)++;
    // 004572a0  83f808                 +cmp eax, 8
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
    // 004572a3  7d1a                   -jge 0x4572bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004572bf;
    }
L_0x004572a5:
    // 004572a5  8b144572985500         -mov edx, dword ptr [eax*2 + 0x559872]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609586) /* 0x559872 */ + cpu.eax * 2);
    // 004572ac  8b0de4e55500           -mov ecx, dword ptr [0x55e5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 004572b2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004572b5  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004572b7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004572b9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004572bb  7ebd                   -jle 0x45727a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045727a;
    }
    // 004572bd  ebbd                   -jmp 0x45727c
    goto L_0x0045727c;
L_0x004572bf:
    // 004572bf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004572c4:
    // 004572c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_457270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00457270;
    // 00457260  696e7430008d80         -imul ebp, dword ptr [esi + 0x74], 0x808d0030
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */))) * x86::sreg64(x86::sreg32(2156724272 /*0x808d0030*/)));
    // 00457267  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00457269  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0045726b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0045726e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
L_entry_0x00457270:
    // 00457270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00457271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00457272  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00457273  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00457274  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00457276  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00457278  eb2b                   -jmp 0x4572a5
    goto L_0x004572a5;
L_0x0045727a:
    // 0045727a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x0045727c:
    // 0045727c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0045727e  8b144582985500         -mov edx, dword ptr [eax*2 + 0x559882]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609602) /* 0x559882 */ + cpu.eax * 2);
    // 00457285  8b1de8e55500           -mov ebx, dword ptr [0x55e5e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0045728b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045728e  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00457290  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00457292  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00457294  7f02                   -jg 0x457298
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00457298;
    }
    // 00457296  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00457298:
    // 00457298  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045729a  83f910                 +cmp ecx, 0x10
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
    // 0045729d  7c25                   -jl 0x4572c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004572c4;
    }
    // 0045729f  40                     -inc eax
    (cpu.eax)++;
    // 004572a0  83f808                 +cmp eax, 8
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
    // 004572a3  7d1a                   -jge 0x4572bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004572bf;
    }
L_0x004572a5:
    // 004572a5  8b144572985500         -mov edx, dword ptr [eax*2 + 0x559872]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5609586) /* 0x559872 */ + cpu.eax * 2);
    // 004572ac  8b0de4e55500           -mov ecx, dword ptr [0x55e5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 004572b2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004572b5  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004572b7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004572b9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004572bb  7ebd                   -jle 0x45727a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045727a;
    }
    // 004572bd  ebbd                   -jmp 0x45727c
    goto L_0x0045727c;
L_0x004572bf:
    // 004572bf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004572c4:
    // 004572c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004572c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
