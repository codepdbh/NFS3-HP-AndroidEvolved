#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

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

/* align: skip  */
void Application::sub_530d46(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530d46  833d88d2560000         +cmp dword ptr [0x56d288], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689992) /* 0x56d288 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530d4d  751f                   -jne 0x530d6e
    if (!cpu.flags.zf)
    {
        goto L_0x00530d6e;
    }
    // 00530d4f  6888d25600             -push 0x56d288
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689992 /*0x56d288*/;
    cpu.esp -= 4;
    // 00530d54  6834c05600             -push 0x56c034
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685300 /*0x56c034*/;
    cpu.esp -= 4;
    // 00530d59  e8bae5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530d5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530d60  740c                   -je 0x530d6e
    if (cpu.flags.zf)
    {
        goto L_0x00530d6e;
    }
    // 00530d62  c70588d25600ffffffff   -mov dword ptr [0x56d288], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689992) /* 0x56d288 */) = 4294967295 /*0xffffffff*/;
    // 00530d6c  eb1c                   -jmp 0x530d8a
    goto L_0x00530d8a;
L_0x00530d6e:
    // 00530d6e  833d88d25600ff         +cmp dword ptr [0x56d288], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689992) /* 0x56d288 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530d75  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530d7a  740e                   -je 0x530d8a
    if (cpu.flags.zf)
    {
        goto L_0x00530d8a;
    }
    // 00530d7c  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530d80  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530d84  ff1588d25600           -call dword ptr [0x56d288]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689992) /* 0x56d288 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530d8a:
    // 00530d8a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530d8d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530d8d  833d8cd2560000         +cmp dword ptr [0x56d28c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689996) /* 0x56d28c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530d94  751f                   -jne 0x530db5
    if (!cpu.flags.zf)
    {
        goto L_0x00530db5;
    }
    // 00530d96  688cd25600             -push 0x56d28c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689996 /*0x56d28c*/;
    cpu.esp -= 4;
    // 00530d9b  684cc05600             -push 0x56c04c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685324 /*0x56c04c*/;
    cpu.esp -= 4;
    // 00530da0  e873e5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530da5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530da7  740c                   -je 0x530db5
    if (cpu.flags.zf)
    {
        goto L_0x00530db5;
    }
    // 00530da9  c7058cd25600ffffffff   -mov dword ptr [0x56d28c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689996) /* 0x56d28c */) = 4294967295 /*0xffffffff*/;
    // 00530db3  eb20                   -jmp 0x530dd5
    goto L_0x00530dd5;
L_0x00530db5:
    // 00530db5  833d8cd25600ff         +cmp dword ptr [0x56d28c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689996) /* 0x56d28c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530dbc  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530dc1  7412                   -je 0x530dd5
    if (cpu.flags.zf)
    {
        goto L_0x00530dd5;
    }
    // 00530dc3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530dc7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530dcb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530dcf  ff158cd25600           -call dword ptr [0x56d28c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689996) /* 0x56d28c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530dd5:
    // 00530dd5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530dd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530dd8  833d90d2560000         +cmp dword ptr [0x56d290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690000) /* 0x56d290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530ddf  751f                   -jne 0x530e00
    if (!cpu.flags.zf)
    {
        goto L_0x00530e00;
    }
    // 00530de1  6890d25600             -push 0x56d290
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690000 /*0x56d290*/;
    cpu.esp -= 4;
    // 00530de6  685cc05600             -push 0x56c05c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685340 /*0x56c05c*/;
    cpu.esp -= 4;
    // 00530deb  e828e5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530df0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530df2  740c                   -je 0x530e00
    if (cpu.flags.zf)
    {
        goto L_0x00530e00;
    }
    // 00530df4  c70590d25600ffffffff   -mov dword ptr [0x56d290], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690000) /* 0x56d290 */) = 4294967295 /*0xffffffff*/;
    // 00530dfe  eb20                   -jmp 0x530e20
    goto L_0x00530e20;
L_0x00530e00:
    // 00530e00  833d90d25600ff         +cmp dword ptr [0x56d290], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690000) /* 0x56d290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530e07  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530e0c  7412                   -je 0x530e20
    if (cpu.flags.zf)
    {
        goto L_0x00530e20;
    }
    // 00530e0e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e12  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e16  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e1a  ff1590d25600           -call dword ptr [0x56d290]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690000) /* 0x56d290 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530e20:
    // 00530e20  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530e23(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530e23  833d94d2560000         +cmp dword ptr [0x56d294], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690004) /* 0x56d294 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530e2a  751f                   -jne 0x530e4b
    if (!cpu.flags.zf)
    {
        goto L_0x00530e4b;
    }
    // 00530e2c  6894d25600             -push 0x56d294
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690004 /*0x56d294*/;
    cpu.esp -= 4;
    // 00530e31  686cc05600             -push 0x56c06c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685356 /*0x56c06c*/;
    cpu.esp -= 4;
    // 00530e36  e8dde4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530e3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530e3d  740c                   -je 0x530e4b
    if (cpu.flags.zf)
    {
        goto L_0x00530e4b;
    }
    // 00530e3f  c70594d25600ffffffff   -mov dword ptr [0x56d294], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690004) /* 0x56d294 */) = 4294967295 /*0xffffffff*/;
    // 00530e49  eb20                   -jmp 0x530e6b
    goto L_0x00530e6b;
L_0x00530e4b:
    // 00530e4b  833d94d25600ff         +cmp dword ptr [0x56d294], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690004) /* 0x56d294 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530e52  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530e57  7412                   -je 0x530e6b
    if (cpu.flags.zf)
    {
        goto L_0x00530e6b;
    }
    // 00530e59  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e5d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e61  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e65  ff1594d25600           -call dword ptr [0x56d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690004) /* 0x56d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530e6b:
    // 00530e6b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530e6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530e6e  833d98d2560000         +cmp dword ptr [0x56d298], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690008) /* 0x56d298 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530e75  751f                   -jne 0x530e96
    if (!cpu.flags.zf)
    {
        goto L_0x00530e96;
    }
    // 00530e77  6898d25600             -push 0x56d298
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690008 /*0x56d298*/;
    cpu.esp -= 4;
    // 00530e7c  687cc05600             -push 0x56c07c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685372 /*0x56c07c*/;
    cpu.esp -= 4;
    // 00530e81  e892e4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530e86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530e88  740c                   -je 0x530e96
    if (cpu.flags.zf)
    {
        goto L_0x00530e96;
    }
    // 00530e8a  c70598d25600ffffffff   -mov dword ptr [0x56d298], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690008) /* 0x56d298 */) = 4294967295 /*0xffffffff*/;
    // 00530e94  eb20                   -jmp 0x530eb6
    goto L_0x00530eb6;
L_0x00530e96:
    // 00530e96  833d98d25600ff         +cmp dword ptr [0x56d298], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690008) /* 0x56d298 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530e9d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530ea2  7412                   -je 0x530eb6
    if (cpu.flags.zf)
    {
        goto L_0x00530eb6;
    }
    // 00530ea4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530ea8  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530eac  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530eb0  ff1598d25600           -call dword ptr [0x56d298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690008) /* 0x56d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530eb6:
    // 00530eb6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530eb9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530eb9  833d9cd2560000         +cmp dword ptr [0x56d29c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690012) /* 0x56d29c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530ec0  751f                   -jne 0x530ee1
    if (!cpu.flags.zf)
    {
        goto L_0x00530ee1;
    }
    // 00530ec2  689cd25600             -push 0x56d29c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690012 /*0x56d29c*/;
    cpu.esp -= 4;
    // 00530ec7  6894c05600             -push 0x56c094
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685396 /*0x56c094*/;
    cpu.esp -= 4;
    // 00530ecc  e847e4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530ed1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530ed3  740c                   -je 0x530ee1
    if (cpu.flags.zf)
    {
        goto L_0x00530ee1;
    }
    // 00530ed5  c7059cd25600ffffffff   -mov dword ptr [0x56d29c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690012) /* 0x56d29c */) = 4294967295 /*0xffffffff*/;
    // 00530edf  eb20                   -jmp 0x530f01
    goto L_0x00530f01;
L_0x00530ee1:
    // 00530ee1  833d9cd25600ff         +cmp dword ptr [0x56d29c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690012) /* 0x56d29c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530ee8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530eed  7412                   -je 0x530f01
    if (cpu.flags.zf)
    {
        goto L_0x00530f01;
    }
    // 00530eef  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530ef3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530ef7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530efb  ff159cd25600           -call dword ptr [0x56d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690012) /* 0x56d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530f01:
    // 00530f01  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530f04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530f04  833da0d2560000         +cmp dword ptr [0x56d2a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690016) /* 0x56d2a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530f0b  751f                   -jne 0x530f2c
    if (!cpu.flags.zf)
    {
        goto L_0x00530f2c;
    }
    // 00530f0d  68a0d25600             -push 0x56d2a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690016 /*0x56d2a0*/;
    cpu.esp -= 4;
    // 00530f12  68acc05600             -push 0x56c0ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685420 /*0x56c0ac*/;
    cpu.esp -= 4;
    // 00530f17  e8fce3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530f1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530f1e  740c                   -je 0x530f2c
    if (cpu.flags.zf)
    {
        goto L_0x00530f2c;
    }
    // 00530f20  c705a0d25600ffffffff   -mov dword ptr [0x56d2a0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690016) /* 0x56d2a0 */) = 4294967295 /*0xffffffff*/;
    // 00530f2a  eb20                   -jmp 0x530f4c
    goto L_0x00530f4c;
L_0x00530f2c:
    // 00530f2c  833da0d25600ff         +cmp dword ptr [0x56d2a0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690016) /* 0x56d2a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530f33  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530f38  7412                   -je 0x530f4c
    if (cpu.flags.zf)
    {
        goto L_0x00530f4c;
    }
    // 00530f3a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f3e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f42  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f46  ff15a0d25600           -call dword ptr [0x56d2a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690016) /* 0x56d2a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530f4c:
    // 00530f4c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530f4f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530f4f  833da4d2560000         +cmp dword ptr [0x56d2a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690020) /* 0x56d2a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530f56  751f                   -jne 0x530f77
    if (!cpu.flags.zf)
    {
        goto L_0x00530f77;
    }
    // 00530f58  68a4d25600             -push 0x56d2a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690020 /*0x56d2a4*/;
    cpu.esp -= 4;
    // 00530f5d  68c4c05600             -push 0x56c0c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685444 /*0x56c0c4*/;
    cpu.esp -= 4;
    // 00530f62  e8b1e3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530f67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530f69  740c                   -je 0x530f77
    if (cpu.flags.zf)
    {
        goto L_0x00530f77;
    }
    // 00530f6b  c705a4d25600ffffffff   -mov dword ptr [0x56d2a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690020) /* 0x56d2a4 */) = 4294967295 /*0xffffffff*/;
    // 00530f75  eb20                   -jmp 0x530f97
    goto L_0x00530f97;
L_0x00530f77:
    // 00530f77  833da4d25600ff         +cmp dword ptr [0x56d2a4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690020) /* 0x56d2a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530f7e  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530f83  7412                   -je 0x530f97
    if (cpu.flags.zf)
    {
        goto L_0x00530f97;
    }
    // 00530f85  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f89  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f8d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f91  ff15a4d25600           -call dword ptr [0x56d2a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690020) /* 0x56d2a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530f97:
    // 00530f97  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530f9a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530f9a  833da8d2560000         +cmp dword ptr [0x56d2a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690024) /* 0x56d2a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530fa1  751f                   -jne 0x530fc2
    if (!cpu.flags.zf)
    {
        goto L_0x00530fc2;
    }
    // 00530fa3  68a8d25600             -push 0x56d2a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690024 /*0x56d2a8*/;
    cpu.esp -= 4;
    // 00530fa8  68dcc05600             -push 0x56c0dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685468 /*0x56c0dc*/;
    cpu.esp -= 4;
    // 00530fad  e866e3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530fb2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530fb4  740c                   -je 0x530fc2
    if (cpu.flags.zf)
    {
        goto L_0x00530fc2;
    }
    // 00530fb6  c705a8d25600ffffffff   -mov dword ptr [0x56d2a8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690024) /* 0x56d2a8 */) = 4294967295 /*0xffffffff*/;
    // 00530fc0  eb20                   -jmp 0x530fe2
    goto L_0x00530fe2;
L_0x00530fc2:
    // 00530fc2  833da8d25600ff         +cmp dword ptr [0x56d2a8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690024) /* 0x56d2a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530fc9  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530fce  7412                   -je 0x530fe2
    if (cpu.flags.zf)
    {
        goto L_0x00530fe2;
    }
    // 00530fd0  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530fd4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530fd8  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530fdc  ff15a8d25600           -call dword ptr [0x56d2a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690024) /* 0x56d2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530fe2:
    // 00530fe2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530fe5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530fe5  833dacd2560000         +cmp dword ptr [0x56d2ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690028) /* 0x56d2ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530fec  751f                   -jne 0x53100d
    if (!cpu.flags.zf)
    {
        goto L_0x0053100d;
    }
    // 00530fee  68acd25600             -push 0x56d2ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690028 /*0x56d2ac*/;
    cpu.esp -= 4;
    // 00530ff3  68e8c05600             -push 0x56c0e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685480 /*0x56c0e8*/;
    cpu.esp -= 4;
    // 00530ff8  e81be3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530ffd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530fff  740c                   -je 0x53100d
    if (cpu.flags.zf)
    {
        goto L_0x0053100d;
    }
    // 00531001  c705acd25600ffffffff   -mov dword ptr [0x56d2ac], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690028) /* 0x56d2ac */) = 4294967295 /*0xffffffff*/;
    // 0053100b  eb20                   -jmp 0x53102d
    goto L_0x0053102d;
L_0x0053100d:
    // 0053100d  833dacd25600ff         +cmp dword ptr [0x56d2ac], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690028) /* 0x56d2ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531014  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531019  7412                   -je 0x53102d
    if (cpu.flags.zf)
    {
        goto L_0x0053102d;
    }
    // 0053101b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053101f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531023  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531027  ff15acd25600           -call dword ptr [0x56d2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690028) /* 0x56d2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053102d:
    // 0053102d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531030  833db0d2560000         +cmp dword ptr [0x56d2b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690032) /* 0x56d2b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531037  751f                   -jne 0x531058
    if (!cpu.flags.zf)
    {
        goto L_0x00531058;
    }
    // 00531039  68b0d25600             -push 0x56d2b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690032 /*0x56d2b0*/;
    cpu.esp -= 4;
    // 0053103e  68f8c05600             -push 0x56c0f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685496 /*0x56c0f8*/;
    cpu.esp -= 4;
    // 00531043  e8d0e2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531048  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053104a  740c                   -je 0x531058
    if (cpu.flags.zf)
    {
        goto L_0x00531058;
    }
    // 0053104c  c705b0d25600ffffffff   -mov dword ptr [0x56d2b0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690032) /* 0x56d2b0 */) = 4294967295 /*0xffffffff*/;
    // 00531056  eb20                   -jmp 0x531078
    goto L_0x00531078;
L_0x00531058:
    // 00531058  833db0d25600ff         +cmp dword ptr [0x56d2b0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690032) /* 0x56d2b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053105f  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531064  7412                   -je 0x531078
    if (cpu.flags.zf)
    {
        goto L_0x00531078;
    }
    // 00531066  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053106a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053106e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531072  ff15b0d25600           -call dword ptr [0x56d2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690032) /* 0x56d2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531078:
    // 00531078  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53107b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053107b  833db4d2560000         +cmp dword ptr [0x56d2b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690036) /* 0x56d2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531082  751f                   -jne 0x5310a3
    if (!cpu.flags.zf)
    {
        goto L_0x005310a3;
    }
    // 00531084  68b4d25600             -push 0x56d2b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690036 /*0x56d2b4*/;
    cpu.esp -= 4;
    // 00531089  6808c15600             -push 0x56c108
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685512 /*0x56c108*/;
    cpu.esp -= 4;
    // 0053108e  e885e2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531093  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531095  740c                   -je 0x5310a3
    if (cpu.flags.zf)
    {
        goto L_0x005310a3;
    }
    // 00531097  c705b4d25600ffffffff   -mov dword ptr [0x56d2b4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690036) /* 0x56d2b4 */) = 4294967295 /*0xffffffff*/;
    // 005310a1  eb18                   -jmp 0x5310bb
    goto L_0x005310bb;
L_0x005310a3:
    // 005310a3  833db4d25600ff         +cmp dword ptr [0x56d2b4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690036) /* 0x56d2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005310aa  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005310af  740a                   -je 0x5310bb
    if (cpu.flags.zf)
    {
        goto L_0x005310bb;
    }
    // 005310b1  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 005310b5  ff15b4d25600           -call dword ptr [0x56d2b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690036) /* 0x56d2b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005310bb:
    // 005310bb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_5310be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005310be  833db8d2560000         +cmp dword ptr [0x56d2b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690040) /* 0x56d2b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005310c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005310c6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005310c8  751f                   -jne 0x5310e9
    if (!cpu.flags.zf)
    {
        goto L_0x005310e9;
    }
    // 005310ca  68b8d25600             -push 0x56d2b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690040 /*0x56d2b8*/;
    cpu.esp -= 4;
    // 005310cf  6814c15600             -push 0x56c114
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685524 /*0x56c114*/;
    cpu.esp -= 4;
    // 005310d4  e83fe2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005310d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005310db  740c                   -je 0x5310e9
    if (cpu.flags.zf)
    {
        goto L_0x005310e9;
    }
    // 005310dd  c705b8d25600ffffffff   -mov dword ptr [0x56d2b8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690040) /* 0x56d2b8 */) = 4294967295 /*0xffffffff*/;
    // 005310e7  eb23                   -jmp 0x53110c
    goto L_0x0053110c;
L_0x005310e9:
    // 005310e9  833db8d25600ff         +cmp dword ptr [0x56d2b8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690040) /* 0x56d2b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005310f0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005310f5  7415                   -je 0x53110c
    if (cpu.flags.zf)
    {
        goto L_0x0053110c;
    }
    // 005310f7  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005310fa  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005310fd  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531100  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531103  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531106  ff15b8d25600           -call dword ptr [0x56d2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690040) /* 0x56d2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053110c:
    // 0053110c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053110d  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531110  833dbcd2560000         +cmp dword ptr [0x56d2bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690044) /* 0x56d2bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531117  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531118  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053111a  751f                   -jne 0x53113b
    if (!cpu.flags.zf)
    {
        goto L_0x0053113b;
    }
    // 0053111c  68bcd25600             -push 0x56d2bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690044 /*0x56d2bc*/;
    cpu.esp -= 4;
    // 00531121  6824c15600             -push 0x56c124
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685540 /*0x56c124*/;
    cpu.esp -= 4;
    // 00531126  e8ede1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053112b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053112d  740c                   -je 0x53113b
    if (cpu.flags.zf)
    {
        goto L_0x0053113b;
    }
    // 0053112f  c705bcd25600ffffffff   -mov dword ptr [0x56d2bc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690044) /* 0x56d2bc */) = 4294967295 /*0xffffffff*/;
    // 00531139  eb29                   -jmp 0x531164
    goto L_0x00531164;
L_0x0053113b:
    // 0053113b  833dbcd25600ff         +cmp dword ptr [0x56d2bc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690044) /* 0x56d2bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531142  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531147  741b                   -je 0x531164
    if (cpu.flags.zf)
    {
        goto L_0x00531164;
    }
    // 00531149  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0053114c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053114f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531152  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531155  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531158  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053115b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053115e  ff15bcd25600           -call dword ptr [0x56d2bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690044) /* 0x56d2bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531164:
    // 00531164  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531165  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_531168(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531168  833dc0d2560000         +cmp dword ptr [0x56d2c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690048) /* 0x56d2c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053116f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531170  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531172  751f                   -jne 0x531193
    if (!cpu.flags.zf)
    {
        goto L_0x00531193;
    }
    // 00531174  68c0d25600             -push 0x56d2c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690048 /*0x56d2c0*/;
    cpu.esp -= 4;
    // 00531179  6838c15600             -push 0x56c138
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685560 /*0x56c138*/;
    cpu.esp -= 4;
    // 0053117e  e895e1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531183  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531185  740c                   -je 0x531193
    if (cpu.flags.zf)
    {
        goto L_0x00531193;
    }
    // 00531187  c705c0d25600ffffffff   -mov dword ptr [0x56d2c0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690048) /* 0x56d2c0 */) = 4294967295 /*0xffffffff*/;
    // 00531191  eb29                   -jmp 0x5311bc
    goto L_0x005311bc;
L_0x00531193:
    // 00531193  833dc0d25600ff         +cmp dword ptr [0x56d2c0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690048) /* 0x56d2c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053119a  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053119f  741b                   -je 0x5311bc
    if (cpu.flags.zf)
    {
        goto L_0x005311bc;
    }
    // 005311a1  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005311a4  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005311a7  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005311aa  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005311ad  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005311b0  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005311b3  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005311b6  ff15c0d25600           -call dword ptr [0x56d2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690048) /* 0x56d2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005311bc:
    // 005311bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005311bd  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_5311c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005311c0  833dc4d2560000         +cmp dword ptr [0x56d2c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690052) /* 0x56d2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005311c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005311c8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005311ca  751f                   -jne 0x5311eb
    if (!cpu.flags.zf)
    {
        goto L_0x005311eb;
    }
    // 005311cc  68c4d25600             -push 0x56d2c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690052 /*0x56d2c4*/;
    cpu.esp -= 4;
    // 005311d1  684cc15600             -push 0x56c14c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685580 /*0x56c14c*/;
    cpu.esp -= 4;
    // 005311d6  e83de1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005311db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005311dd  740c                   -je 0x5311eb
    if (cpu.flags.zf)
    {
        goto L_0x005311eb;
    }
    // 005311df  c705c4d25600ffffffff   -mov dword ptr [0x56d2c4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690052) /* 0x56d2c4 */) = 4294967295 /*0xffffffff*/;
    // 005311e9  eb23                   -jmp 0x53120e
    goto L_0x0053120e;
L_0x005311eb:
    // 005311eb  833dc4d25600ff         +cmp dword ptr [0x56d2c4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690052) /* 0x56d2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005311f2  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005311f7  7415                   -je 0x53120e
    if (cpu.flags.zf)
    {
        goto L_0x0053120e;
    }
    // 005311f9  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005311fc  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005311ff  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531202  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531205  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531208  ff15c4d25600           -call dword ptr [0x56d2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690052) /* 0x56d2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053120e:
    // 0053120e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053120f  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531212(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531212  833dc8d2560000         +cmp dword ptr [0x56d2c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690056) /* 0x56d2c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531219  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053121a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053121c  751f                   -jne 0x53123d
    if (!cpu.flags.zf)
    {
        goto L_0x0053123d;
    }
    // 0053121e  68c8d25600             -push 0x56d2c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690056 /*0x56d2c8*/;
    cpu.esp -= 4;
    // 00531223  685cc15600             -push 0x56c15c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685596 /*0x56c15c*/;
    cpu.esp -= 4;
    // 00531228  e8ebe0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053122d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053122f  740c                   -je 0x53123d
    if (cpu.flags.zf)
    {
        goto L_0x0053123d;
    }
    // 00531231  c705c8d25600ffffffff   -mov dword ptr [0x56d2c8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690056) /* 0x56d2c8 */) = 4294967295 /*0xffffffff*/;
    // 0053123b  eb23                   -jmp 0x531260
    goto L_0x00531260;
L_0x0053123d:
    // 0053123d  833dc8d25600ff         +cmp dword ptr [0x56d2c8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690056) /* 0x56d2c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531244  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531249  7415                   -je 0x531260
    if (cpu.flags.zf)
    {
        goto L_0x00531260;
    }
    // 0053124b  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053124e  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531251  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531254  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531257  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053125a  ff15c8d25600           -call dword ptr [0x56d2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690056) /* 0x56d2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531260:
    // 00531260  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531261  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531264(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531264  833dccd2560000         +cmp dword ptr [0x56d2cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690060) /* 0x56d2cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053126b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053126c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053126e  751f                   -jne 0x53128f
    if (!cpu.flags.zf)
    {
        goto L_0x0053128f;
    }
    // 00531270  68ccd25600             -push 0x56d2cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690060 /*0x56d2cc*/;
    cpu.esp -= 4;
    // 00531275  686cc15600             -push 0x56c16c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685612 /*0x56c16c*/;
    cpu.esp -= 4;
    // 0053127a  e899e0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053127f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531281  740c                   -je 0x53128f
    if (cpu.flags.zf)
    {
        goto L_0x0053128f;
    }
    // 00531283  c705ccd25600ffffffff   -mov dword ptr [0x56d2cc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690060) /* 0x56d2cc */) = 4294967295 /*0xffffffff*/;
    // 0053128d  eb23                   -jmp 0x5312b2
    goto L_0x005312b2;
L_0x0053128f:
    // 0053128f  833dccd25600ff         +cmp dword ptr [0x56d2cc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690060) /* 0x56d2cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531296  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053129b  7415                   -je 0x5312b2
    if (cpu.flags.zf)
    {
        goto L_0x005312b2;
    }
    // 0053129d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005312a0  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005312a3  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005312a6  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005312a9  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005312ac  ff15ccd25600           -call dword ptr [0x56d2cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690060) /* 0x56d2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005312b2:
    // 005312b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005312b3  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5312b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005312b6  833dd0d2560000         +cmp dword ptr [0x56d2d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690064) /* 0x56d2d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005312bd  751f                   -jne 0x5312de
    if (!cpu.flags.zf)
    {
        goto L_0x005312de;
    }
    // 005312bf  68d0d25600             -push 0x56d2d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690064 /*0x56d2d0*/;
    cpu.esp -= 4;
    // 005312c4  687cc15600             -push 0x56c17c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685628 /*0x56c17c*/;
    cpu.esp -= 4;
    // 005312c9  e84ae0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005312ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005312d0  740c                   -je 0x5312de
    if (cpu.flags.zf)
    {
        goto L_0x005312de;
    }
    // 005312d2  c705d0d25600ffffffff   -mov dword ptr [0x56d2d0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690064) /* 0x56d2d0 */) = 4294967295 /*0xffffffff*/;
    // 005312dc  eb1c                   -jmp 0x5312fa
    goto L_0x005312fa;
L_0x005312de:
    // 005312de  833dd0d25600ff         +cmp dword ptr [0x56d2d0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690064) /* 0x56d2d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005312e5  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005312ea  740e                   -je 0x5312fa
    if (cpu.flags.zf)
    {
        goto L_0x005312fa;
    }
    // 005312ec  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005312f0  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005312f4  ff15d0d25600           -call dword ptr [0x56d2d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690064) /* 0x56d2d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005312fa:
    // 005312fa  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5312fd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005312fd  833dd4d2560000         +cmp dword ptr [0x56d2d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690068) /* 0x56d2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531304  751f                   -jne 0x531325
    if (!cpu.flags.zf)
    {
        goto L_0x00531325;
    }
    // 00531306  68d4d25600             -push 0x56d2d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690068 /*0x56d2d4*/;
    cpu.esp -= 4;
    // 0053130b  6890c15600             -push 0x56c190
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685648 /*0x56c190*/;
    cpu.esp -= 4;
    // 00531310  e803e0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531315  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531317  740c                   -je 0x531325
    if (cpu.flags.zf)
    {
        goto L_0x00531325;
    }
    // 00531319  c705d4d25600ffffffff   -mov dword ptr [0x56d2d4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690068) /* 0x56d2d4 */) = 4294967295 /*0xffffffff*/;
    // 00531323  eb1c                   -jmp 0x531341
    goto L_0x00531341;
L_0x00531325:
    // 00531325  833dd4d25600ff         +cmp dword ptr [0x56d2d4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690068) /* 0x56d2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053132c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531331  740e                   -je 0x531341
    if (cpu.flags.zf)
    {
        goto L_0x00531341;
    }
    // 00531333  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531337  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053133b  ff15d4d25600           -call dword ptr [0x56d2d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690068) /* 0x56d2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531341:
    // 00531341  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_531344(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531344  833dd8d2560000         +cmp dword ptr [0x56d2d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690072) /* 0x56d2d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053134b  751f                   -jne 0x53136c
    if (!cpu.flags.zf)
    {
        goto L_0x0053136c;
    }
    // 0053134d  68d8d25600             -push 0x56d2d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690072 /*0x56d2d8*/;
    cpu.esp -= 4;
    // 00531352  68a4c15600             -push 0x56c1a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685668 /*0x56c1a4*/;
    cpu.esp -= 4;
    // 00531357  e8bcdfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053135c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053135e  740c                   -je 0x53136c
    if (cpu.flags.zf)
    {
        goto L_0x0053136c;
    }
    // 00531360  c705d8d25600ffffffff   -mov dword ptr [0x56d2d8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690072) /* 0x56d2d8 */) = 4294967295 /*0xffffffff*/;
    // 0053136a  eb20                   -jmp 0x53138c
    goto L_0x0053138c;
L_0x0053136c:
    // 0053136c  833dd8d25600ff         +cmp dword ptr [0x56d2d8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690072) /* 0x56d2d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531373  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531378  7412                   -je 0x53138c
    if (cpu.flags.zf)
    {
        goto L_0x0053138c;
    }
    // 0053137a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053137e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531382  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531386  ff15d8d25600           -call dword ptr [0x56d2d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690072) /* 0x56d2d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053138c:
    // 0053138c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53138f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053138f  833ddcd2560000         +cmp dword ptr [0x56d2dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690076) /* 0x56d2dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531396  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531397  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531399  751f                   -jne 0x5313ba
    if (!cpu.flags.zf)
    {
        goto L_0x005313ba;
    }
    // 0053139b  68dcd25600             -push 0x56d2dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690076 /*0x56d2dc*/;
    cpu.esp -= 4;
    // 005313a0  68b8c15600             -push 0x56c1b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685688 /*0x56c1b8*/;
    cpu.esp -= 4;
    // 005313a5  e86edfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005313aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005313ac  740c                   -je 0x5313ba
    if (cpu.flags.zf)
    {
        goto L_0x005313ba;
    }
    // 005313ae  c705dcd25600ffffffff   -mov dword ptr [0x56d2dc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690076) /* 0x56d2dc */) = 4294967295 /*0xffffffff*/;
    // 005313b8  eb26                   -jmp 0x5313e0
    goto L_0x005313e0;
L_0x005313ba:
    // 005313ba  833ddcd25600ff         +cmp dword ptr [0x56d2dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690076) /* 0x56d2dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005313c1  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005313c6  7418                   -je 0x5313e0
    if (cpu.flags.zf)
    {
        goto L_0x005313e0;
    }
    // 005313c8  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005313cb  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005313ce  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005313d1  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005313d4  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005313d7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005313da  ff15dcd25600           -call dword ptr [0x56d2dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690076) /* 0x56d2dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005313e0:
    // 005313e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005313e1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_5313e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005313e4  833de0d2560000         +cmp dword ptr [0x56d2e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690080) /* 0x56d2e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005313eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005313ec  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005313ee  751f                   -jne 0x53140f
    if (!cpu.flags.zf)
    {
        goto L_0x0053140f;
    }
    // 005313f0  68e0d25600             -push 0x56d2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690080 /*0x56d2e0*/;
    cpu.esp -= 4;
    // 005313f5  68d0c15600             -push 0x56c1d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685712 /*0x56c1d0*/;
    cpu.esp -= 4;
    // 005313fa  e819dfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005313ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531401  740c                   -je 0x53140f
    if (cpu.flags.zf)
    {
        goto L_0x0053140f;
    }
    // 00531403  c705e0d25600ffffffff   -mov dword ptr [0x56d2e0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690080) /* 0x56d2e0 */) = 4294967295 /*0xffffffff*/;
    // 0053140d  eb26                   -jmp 0x531435
    goto L_0x00531435;
L_0x0053140f:
    // 0053140f  833de0d25600ff         +cmp dword ptr [0x56d2e0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690080) /* 0x56d2e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531416  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053141b  7418                   -je 0x531435
    if (cpu.flags.zf)
    {
        goto L_0x00531435;
    }
    // 0053141d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00531420  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531423  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531426  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531429  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053142c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053142f  ff15e0d25600           -call dword ptr [0x56d2e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690080) /* 0x56d2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531435:
    // 00531435  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531436  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_531439(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531439  833de4d2560000         +cmp dword ptr [0x56d2e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690084) /* 0x56d2e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531440  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531441  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531443  751f                   -jne 0x531464
    if (!cpu.flags.zf)
    {
        goto L_0x00531464;
    }
    // 00531445  68e4d25600             -push 0x56d2e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690084 /*0x56d2e4*/;
    cpu.esp -= 4;
    // 0053144a  68e8c15600             -push 0x56c1e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685736 /*0x56c1e8*/;
    cpu.esp -= 4;
    // 0053144f  e8c4deffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531454  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531456  740c                   -je 0x531464
    if (cpu.flags.zf)
    {
        goto L_0x00531464;
    }
    // 00531458  c705e4d25600ffffffff   -mov dword ptr [0x56d2e4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690084) /* 0x56d2e4 */) = 4294967295 /*0xffffffff*/;
    // 00531462  eb2f                   -jmp 0x531493
    goto L_0x00531493;
L_0x00531464:
    // 00531464  833de4d25600ff         +cmp dword ptr [0x56d2e4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690084) /* 0x56d2e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053146b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531470  7421                   -je 0x531493
    if (cpu.flags.zf)
    {
        goto L_0x00531493;
    }
    // 00531472  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 00531475  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00531478  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0053147b  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053147e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531481  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531484  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531487  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053148a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053148d  ff15e4d25600           -call dword ptr [0x56d2e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690084) /* 0x56d2e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531493:
    // 00531493  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531494  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::sub_531497(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531497  833de8d2560000         +cmp dword ptr [0x56d2e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690088) /* 0x56d2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053149e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053149f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005314a1  751f                   -jne 0x5314c2
    if (!cpu.flags.zf)
    {
        goto L_0x005314c2;
    }
    // 005314a3  68e8d25600             -push 0x56d2e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690088 /*0x56d2e8*/;
    cpu.esp -= 4;
    // 005314a8  68f4c15600             -push 0x56c1f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685748 /*0x56c1f4*/;
    cpu.esp -= 4;
    // 005314ad  e866deffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005314b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005314b4  740c                   -je 0x5314c2
    if (cpu.flags.zf)
    {
        goto L_0x005314c2;
    }
    // 005314b6  c705e8d25600ffffffff   -mov dword ptr [0x56d2e8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690088) /* 0x56d2e8 */) = 4294967295 /*0xffffffff*/;
    // 005314c0  eb2f                   -jmp 0x5314f1
    goto L_0x005314f1;
L_0x005314c2:
    // 005314c2  833de8d25600ff         +cmp dword ptr [0x56d2e8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690088) /* 0x56d2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005314c9  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005314ce  7421                   -je 0x5314f1
    if (cpu.flags.zf)
    {
        goto L_0x005314f1;
    }
    // 005314d0  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 005314d3  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 005314d6  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005314d9  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005314dc  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005314df  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005314e2  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005314e5  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005314e8  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005314eb  ff15e8d25600           -call dword ptr [0x56d2e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690088) /* 0x56d2e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005314f1:
    // 005314f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005314f2  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::sub_5314f5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005314f5  833decd2560000         +cmp dword ptr [0x56d2ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690092) /* 0x56d2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005314fc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005314fd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005314ff  751f                   -jne 0x531520
    if (!cpu.flags.zf)
    {
        goto L_0x00531520;
    }
    // 00531501  68ecd25600             -push 0x56d2ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690092 /*0x56d2ec*/;
    cpu.esp -= 4;
    // 00531506  6800c25600             -push 0x56c200
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685760 /*0x56c200*/;
    cpu.esp -= 4;
    // 0053150b  e808deffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531510  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531512  740c                   -je 0x531520
    if (cpu.flags.zf)
    {
        goto L_0x00531520;
    }
    // 00531514  c705ecd25600ffffffff   -mov dword ptr [0x56d2ec], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690092) /* 0x56d2ec */) = 4294967295 /*0xffffffff*/;
    // 0053151e  eb2f                   -jmp 0x53154f
    goto L_0x0053154f;
L_0x00531520:
    // 00531520  833decd25600ff         +cmp dword ptr [0x56d2ec], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690092) /* 0x56d2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531527  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053152c  7421                   -je 0x53154f
    if (cpu.flags.zf)
    {
        goto L_0x0053154f;
    }
    // 0053152e  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 00531531  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00531534  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00531537  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053153a  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053153d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531540  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531543  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531546  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531549  ff15ecd25600           -call dword ptr [0x56d2ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690092) /* 0x56d2ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053154f:
    // 0053154f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531550  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::sub_531553(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531553  833df0d2560000         +cmp dword ptr [0x56d2f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690096) /* 0x56d2f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053155a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053155b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053155d  751f                   -jne 0x53157e
    if (!cpu.flags.zf)
    {
        goto L_0x0053157e;
    }
    // 0053155f  68f0d25600             -push 0x56d2f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690096 /*0x56d2f0*/;
    cpu.esp -= 4;
    // 00531564  680cc25600             -push 0x56c20c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685772 /*0x56c20c*/;
    cpu.esp -= 4;
    // 00531569  e8aaddffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053156e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531570  740c                   -je 0x53157e
    if (cpu.flags.zf)
    {
        goto L_0x0053157e;
    }
    // 00531572  c705f0d25600ffffffff   -mov dword ptr [0x56d2f0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690096) /* 0x56d2f0 */) = 4294967295 /*0xffffffff*/;
    // 0053157c  eb20                   -jmp 0x53159e
    goto L_0x0053159e;
L_0x0053157e:
    // 0053157e  833df0d25600ff         +cmp dword ptr [0x56d2f0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690096) /* 0x56d2f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531585  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053158a  7412                   -je 0x53159e
    if (cpu.flags.zf)
    {
        goto L_0x0053159e;
    }
    // 0053158c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053158f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531592  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531595  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531598  ff15f0d25600           -call dword ptr [0x56d2f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690096) /* 0x56d2f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053159e:
    // 0053159e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053159f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_5315a2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005315a2  833df4d2560000         +cmp dword ptr [0x56d2f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690100) /* 0x56d2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005315a9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005315aa  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005315ac  751f                   -jne 0x5315cd
    if (!cpu.flags.zf)
    {
        goto L_0x005315cd;
    }
    // 005315ae  68f4d25600             -push 0x56d2f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690100 /*0x56d2f4*/;
    cpu.esp -= 4;
    // 005315b3  6818c25600             -push 0x56c218
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685784 /*0x56c218*/;
    cpu.esp -= 4;
    // 005315b8  e85bddffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005315bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005315bf  740c                   -je 0x5315cd
    if (cpu.flags.zf)
    {
        goto L_0x005315cd;
    }
    // 005315c1  c705f4d25600ffffffff   -mov dword ptr [0x56d2f4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690100) /* 0x56d2f4 */) = 4294967295 /*0xffffffff*/;
    // 005315cb  eb20                   -jmp 0x5315ed
    goto L_0x005315ed;
L_0x005315cd:
    // 005315cd  833df4d25600ff         +cmp dword ptr [0x56d2f4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690100) /* 0x56d2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005315d4  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005315d9  7412                   -je 0x5315ed
    if (cpu.flags.zf)
    {
        goto L_0x005315ed;
    }
    // 005315db  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005315de  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005315e1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005315e4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005315e7  ff15f4d25600           -call dword ptr [0x56d2f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690100) /* 0x56d2f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005315ed:
    // 005315ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005315ee  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_5315f1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005315f1  833df8d2560000         +cmp dword ptr [0x56d2f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690104) /* 0x56d2f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005315f8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005315f9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005315fb  751f                   -jne 0x53161c
    if (!cpu.flags.zf)
    {
        goto L_0x0053161c;
    }
    // 005315fd  68f8d25600             -push 0x56d2f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690104 /*0x56d2f8*/;
    cpu.esp -= 4;
    // 00531602  6824c25600             -push 0x56c224
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685796 /*0x56c224*/;
    cpu.esp -= 4;
    // 00531607  e80cddffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053160c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053160e  740c                   -je 0x53161c
    if (cpu.flags.zf)
    {
        goto L_0x0053161c;
    }
    // 00531610  c705f8d25600ffffffff   -mov dword ptr [0x56d2f8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690104) /* 0x56d2f8 */) = 4294967295 /*0xffffffff*/;
    // 0053161a  eb20                   -jmp 0x53163c
    goto L_0x0053163c;
L_0x0053161c:
    // 0053161c  833df8d25600ff         +cmp dword ptr [0x56d2f8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690104) /* 0x56d2f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531623  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531628  7412                   -je 0x53163c
    if (cpu.flags.zf)
    {
        goto L_0x0053163c;
    }
    // 0053162a  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053162d  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531630  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531633  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531636  ff15f8d25600           -call dword ptr [0x56d2f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690104) /* 0x56d2f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053163c:
    // 0053163c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053163d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_531640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531640  833dfcd2560000         +cmp dword ptr [0x56d2fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690108) /* 0x56d2fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531647  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531648  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053164a  751f                   -jne 0x53166b
    if (!cpu.flags.zf)
    {
        goto L_0x0053166b;
    }
    // 0053164c  68fcd25600             -push 0x56d2fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690108 /*0x56d2fc*/;
    cpu.esp -= 4;
    // 00531651  6830c25600             -push 0x56c230
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685808 /*0x56c230*/;
    cpu.esp -= 4;
    // 00531656  e8bddcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053165b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053165d  740c                   -je 0x53166b
    if (cpu.flags.zf)
    {
        goto L_0x0053166b;
    }
    // 0053165f  c705fcd25600ffffffff   -mov dword ptr [0x56d2fc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690108) /* 0x56d2fc */) = 4294967295 /*0xffffffff*/;
    // 00531669  eb23                   -jmp 0x53168e
    goto L_0x0053168e;
L_0x0053166b:
    // 0053166b  833dfcd25600ff         +cmp dword ptr [0x56d2fc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690108) /* 0x56d2fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531672  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531677  7415                   -je 0x53168e
    if (cpu.flags.zf)
    {
        goto L_0x0053168e;
    }
    // 00531679  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053167c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053167f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531682  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531685  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531688  ff15fcd25600           -call dword ptr [0x56d2fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690108) /* 0x56d2fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053168e:
    // 0053168e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053168f  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531692(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531692  833d00d3560000         +cmp dword ptr [0x56d300], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690112) /* 0x56d300 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531699  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053169a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053169c  751f                   -jne 0x5316bd
    if (!cpu.flags.zf)
    {
        goto L_0x005316bd;
    }
    // 0053169e  6800d35600             -push 0x56d300
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690112 /*0x56d300*/;
    cpu.esp -= 4;
    // 005316a3  683cc25600             -push 0x56c23c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685820 /*0x56c23c*/;
    cpu.esp -= 4;
    // 005316a8  e86bdcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005316ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005316af  740c                   -je 0x5316bd
    if (cpu.flags.zf)
    {
        goto L_0x005316bd;
    }
    // 005316b1  c70500d35600ffffffff   -mov dword ptr [0x56d300], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690112) /* 0x56d300 */) = 4294967295 /*0xffffffff*/;
    // 005316bb  eb23                   -jmp 0x5316e0
    goto L_0x005316e0;
L_0x005316bd:
    // 005316bd  833d00d35600ff         +cmp dword ptr [0x56d300], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690112) /* 0x56d300 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005316c4  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005316c9  7415                   -je 0x5316e0
    if (cpu.flags.zf)
    {
        goto L_0x005316e0;
    }
    // 005316cb  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005316ce  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005316d1  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005316d4  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005316d7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005316da  ff1500d35600           -call dword ptr [0x56d300]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690112) /* 0x56d300 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005316e0:
    // 005316e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005316e1  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5316e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005316e4  833d04d3560000         +cmp dword ptr [0x56d304], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690116) /* 0x56d304 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005316eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005316ec  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005316ee  751f                   -jne 0x53170f
    if (!cpu.flags.zf)
    {
        goto L_0x0053170f;
    }
    // 005316f0  6804d35600             -push 0x56d304
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690116 /*0x56d304*/;
    cpu.esp -= 4;
    // 005316f5  6848c25600             -push 0x56c248
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685832 /*0x56c248*/;
    cpu.esp -= 4;
    // 005316fa  e819dcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005316ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531701  740c                   -je 0x53170f
    if (cpu.flags.zf)
    {
        goto L_0x0053170f;
    }
    // 00531703  c70504d35600ffffffff   -mov dword ptr [0x56d304], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690116) /* 0x56d304 */) = 4294967295 /*0xffffffff*/;
    // 0053170d  eb23                   -jmp 0x531732
    goto L_0x00531732;
L_0x0053170f:
    // 0053170f  833d04d35600ff         +cmp dword ptr [0x56d304], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690116) /* 0x56d304 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531716  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053171b  7415                   -je 0x531732
    if (cpu.flags.zf)
    {
        goto L_0x00531732;
    }
    // 0053171d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531720  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531723  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531726  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531729  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053172c  ff1504d35600           -call dword ptr [0x56d304]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690116) /* 0x56d304 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531732:
    // 00531732  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531733  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531736(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531736  833d08d3560000         +cmp dword ptr [0x56d308], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690120) /* 0x56d308 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053173d  751f                   -jne 0x53175e
    if (!cpu.flags.zf)
    {
        goto L_0x0053175e;
    }
    // 0053173f  6808d35600             -push 0x56d308
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690120 /*0x56d308*/;
    cpu.esp -= 4;
    // 00531744  6854c25600             -push 0x56c254
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685844 /*0x56c254*/;
    cpu.esp -= 4;
    // 00531749  e8cadbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053174e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531750  740c                   -je 0x53175e
    if (cpu.flags.zf)
    {
        goto L_0x0053175e;
    }
    // 00531752  c70508d35600ffffffff   -mov dword ptr [0x56d308], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690120) /* 0x56d308 */) = 4294967295 /*0xffffffff*/;
    // 0053175c  eb20                   -jmp 0x53177e
    goto L_0x0053177e;
L_0x0053175e:
    // 0053175e  833d08d35600ff         +cmp dword ptr [0x56d308], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690120) /* 0x56d308 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531765  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053176a  7412                   -je 0x53177e
    if (cpu.flags.zf)
    {
        goto L_0x0053177e;
    }
    // 0053176c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531770  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531774  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531778  ff1508d35600           -call dword ptr [0x56d308]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690120) /* 0x56d308 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053177e:
    // 0053177e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531781(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531781  833d0cd3560000         +cmp dword ptr [0x56d30c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690124) /* 0x56d30c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531788  751f                   -jne 0x5317a9
    if (!cpu.flags.zf)
    {
        goto L_0x005317a9;
    }
    // 0053178a  680cd35600             -push 0x56d30c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690124 /*0x56d30c*/;
    cpu.esp -= 4;
    // 0053178f  6870c25600             -push 0x56c270
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685872 /*0x56c270*/;
    cpu.esp -= 4;
    // 00531794  e87fdbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531799  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053179b  740c                   -je 0x5317a9
    if (cpu.flags.zf)
    {
        goto L_0x005317a9;
    }
    // 0053179d  c7050cd35600ffffffff   -mov dword ptr [0x56d30c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690124) /* 0x56d30c */) = 4294967295 /*0xffffffff*/;
    // 005317a7  eb20                   -jmp 0x5317c9
    goto L_0x005317c9;
L_0x005317a9:
    // 005317a9  833d0cd35600ff         +cmp dword ptr [0x56d30c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690124) /* 0x56d30c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005317b0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005317b5  7412                   -je 0x5317c9
    if (cpu.flags.zf)
    {
        goto L_0x005317c9;
    }
    // 005317b7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005317bb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005317bf  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005317c3  ff150cd35600           -call dword ptr [0x56d30c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690124) /* 0x56d30c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005317c9:
    // 005317c9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5317cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005317cc  833d10d3560000         +cmp dword ptr [0x56d310], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690128) /* 0x56d310 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005317d3  751f                   -jne 0x5317f4
    if (!cpu.flags.zf)
    {
        goto L_0x005317f4;
    }
    // 005317d5  6810d35600             -push 0x56d310
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690128 /*0x56d310*/;
    cpu.esp -= 4;
    // 005317da  688cc25600             -push 0x56c28c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685900 /*0x56c28c*/;
    cpu.esp -= 4;
    // 005317df  e834dbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005317e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005317e6  740c                   -je 0x5317f4
    if (cpu.flags.zf)
    {
        goto L_0x005317f4;
    }
    // 005317e8  c70510d35600ffffffff   -mov dword ptr [0x56d310], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690128) /* 0x56d310 */) = 4294967295 /*0xffffffff*/;
    // 005317f2  eb20                   -jmp 0x531814
    goto L_0x00531814;
L_0x005317f4:
    // 005317f4  833d10d35600ff         +cmp dword ptr [0x56d310], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690128) /* 0x56d310 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005317fb  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531800  7412                   -je 0x531814
    if (cpu.flags.zf)
    {
        goto L_0x00531814;
    }
    // 00531802  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531806  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053180a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053180e  ff1510d35600           -call dword ptr [0x56d310]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690128) /* 0x56d310 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531814:
    // 00531814  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531817(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531817  833d14d3560000         +cmp dword ptr [0x56d314], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690132) /* 0x56d314 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053181e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053181f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531821  751f                   -jne 0x531842
    if (!cpu.flags.zf)
    {
        goto L_0x00531842;
    }
    // 00531823  6814d35600             -push 0x56d314
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690132 /*0x56d314*/;
    cpu.esp -= 4;
    // 00531828  68a8c25600             -push 0x56c2a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685928 /*0x56c2a8*/;
    cpu.esp -= 4;
    // 0053182d  e8e6daffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531832  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531834  740c                   -je 0x531842
    if (cpu.flags.zf)
    {
        goto L_0x00531842;
    }
    // 00531836  c70514d35600ffffffff   -mov dword ptr [0x56d314], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690132) /* 0x56d314 */) = 4294967295 /*0xffffffff*/;
    // 00531840  eb26                   -jmp 0x531868
    goto L_0x00531868;
L_0x00531842:
    // 00531842  833d14d35600ff         +cmp dword ptr [0x56d314], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690132) /* 0x56d314 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531849  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053184e  7418                   -je 0x531868
    if (cpu.flags.zf)
    {
        goto L_0x00531868;
    }
    // 00531850  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00531853  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531856  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531859  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053185c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053185f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531862  ff1514d35600           -call dword ptr [0x56d314]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690132) /* 0x56d314 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531868:
    // 00531868  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531869  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_53186c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053186c  833d18d3560000         +cmp dword ptr [0x56d318], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690136) /* 0x56d318 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531873  751f                   -jne 0x531894
    if (!cpu.flags.zf)
    {
        goto L_0x00531894;
    }
    // 00531875  6818d35600             -push 0x56d318
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690136 /*0x56d318*/;
    cpu.esp -= 4;
    // 0053187a  68bcc25600             -push 0x56c2bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685948 /*0x56c2bc*/;
    cpu.esp -= 4;
    // 0053187f  e894daffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531884  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531886  740c                   -je 0x531894
    if (cpu.flags.zf)
    {
        goto L_0x00531894;
    }
    // 00531888  c70518d35600ffffffff   -mov dword ptr [0x56d318], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690136) /* 0x56d318 */) = 4294967295 /*0xffffffff*/;
    // 00531892  eb20                   -jmp 0x5318b4
    goto L_0x005318b4;
L_0x00531894:
    // 00531894  833d18d35600ff         +cmp dword ptr [0x56d318], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690136) /* 0x56d318 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053189b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005318a0  7412                   -je 0x5318b4
    if (cpu.flags.zf)
    {
        goto L_0x005318b4;
    }
    // 005318a2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318a6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318aa  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318ae  ff1518d35600           -call dword ptr [0x56d318]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690136) /* 0x56d318 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005318b4:
    // 005318b4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5318b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005318b7  833d1cd3560000         +cmp dword ptr [0x56d31c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690140) /* 0x56d31c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005318be  751f                   -jne 0x5318df
    if (!cpu.flags.zf)
    {
        goto L_0x005318df;
    }
    // 005318c0  681cd35600             -push 0x56d31c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690140 /*0x56d31c*/;
    cpu.esp -= 4;
    // 005318c5  68d0c25600             -push 0x56c2d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685968 /*0x56c2d0*/;
    cpu.esp -= 4;
    // 005318ca  e849daffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005318cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005318d1  740c                   -je 0x5318df
    if (cpu.flags.zf)
    {
        goto L_0x005318df;
    }
    // 005318d3  c7051cd35600ffffffff   -mov dword ptr [0x56d31c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690140) /* 0x56d31c */) = 4294967295 /*0xffffffff*/;
    // 005318dd  eb20                   -jmp 0x5318ff
    goto L_0x005318ff;
L_0x005318df:
    // 005318df  833d1cd35600ff         +cmp dword ptr [0x56d31c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690140) /* 0x56d31c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005318e6  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005318eb  7412                   -je 0x5318ff
    if (cpu.flags.zf)
    {
        goto L_0x005318ff;
    }
    // 005318ed  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318f1  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318f5  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318f9  ff151cd35600           -call dword ptr [0x56d31c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690140) /* 0x56d31c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005318ff:
    // 005318ff  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531902(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531902  833d20d3560000         +cmp dword ptr [0x56d320], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690144) /* 0x56d320 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531909  751f                   -jne 0x53192a
    if (!cpu.flags.zf)
    {
        goto L_0x0053192a;
    }
    // 0053190b  6820d35600             -push 0x56d320
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690144 /*0x56d320*/;
    cpu.esp -= 4;
    // 00531910  68e0c25600             -push 0x56c2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685984 /*0x56c2e0*/;
    cpu.esp -= 4;
    // 00531915  e8fed9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053191a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053191c  740c                   -je 0x53192a
    if (cpu.flags.zf)
    {
        goto L_0x0053192a;
    }
    // 0053191e  c70520d35600ffffffff   -mov dword ptr [0x56d320], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690144) /* 0x56d320 */) = 4294967295 /*0xffffffff*/;
    // 00531928  eb20                   -jmp 0x53194a
    goto L_0x0053194a;
L_0x0053192a:
    // 0053192a  833d20d35600ff         +cmp dword ptr [0x56d320], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690144) /* 0x56d320 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531931  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531936  7412                   -je 0x53194a
    if (cpu.flags.zf)
    {
        goto L_0x0053194a;
    }
    // 00531938  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053193c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531940  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531944  ff1520d35600           -call dword ptr [0x56d320]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690144) /* 0x56d320 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053194a:
    // 0053194a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

}
