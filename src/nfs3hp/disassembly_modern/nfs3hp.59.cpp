#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip  */
void Application::sub_532cad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532cad  833d24d4560000         +cmp dword ptr [0x56d424], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690404) /* 0x56d424 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532cb4  751f                   -jne 0x532cd5
    if (!cpu.flags.zf)
    {
        goto L_0x00532cd5;
    }
    // 00532cb6  6824d45600             -push 0x56d424
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690404 /*0x56d424*/;
    cpu.esp -= 4;
    // 00532cbb  68f4c75600             -push 0x56c7f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687284 /*0x56c7f4*/;
    cpu.esp -= 4;
    // 00532cc0  e853c6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532cc5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532cc7  740c                   -je 0x532cd5
    if (cpu.flags.zf)
    {
        goto L_0x00532cd5;
    }
    // 00532cc9  c70524d45600ffffffff   -mov dword ptr [0x56d424], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690404) /* 0x56d424 */) = 4294967295 /*0xffffffff*/;
    // 00532cd3  eb20                   -jmp 0x532cf5
    goto L_0x00532cf5;
L_0x00532cd5:
    // 00532cd5  833d24d45600ff         +cmp dword ptr [0x56d424], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690404) /* 0x56d424 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532cdc  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532ce1  7412                   -je 0x532cf5
    if (cpu.flags.zf)
    {
        goto L_0x00532cf5;
    }
    // 00532ce3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ce7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ceb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532cef  ff1524d45600           -call dword ptr [0x56d424]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690404) /* 0x56d424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532cf5:
    // 00532cf5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532cf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532cf8  833d28d4560000         +cmp dword ptr [0x56d428], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690408) /* 0x56d428 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532cff  751f                   -jne 0x532d20
    if (!cpu.flags.zf)
    {
        goto L_0x00532d20;
    }
    // 00532d01  6828d45600             -push 0x56d428
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690408 /*0x56d428*/;
    cpu.esp -= 4;
    // 00532d06  6804c85600             -push 0x56c804
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687300 /*0x56c804*/;
    cpu.esp -= 4;
    // 00532d0b  e808c6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532d10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532d12  740c                   -je 0x532d20
    if (cpu.flags.zf)
    {
        goto L_0x00532d20;
    }
    // 00532d14  c70528d45600ffffffff   -mov dword ptr [0x56d428], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690408) /* 0x56d428 */) = 4294967295 /*0xffffffff*/;
    // 00532d1e  eb1c                   -jmp 0x532d3c
    goto L_0x00532d3c;
L_0x00532d20:
    // 00532d20  833d28d45600ff         +cmp dword ptr [0x56d428], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690408) /* 0x56d428 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532d27  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532d2c  740e                   -je 0x532d3c
    if (cpu.flags.zf)
    {
        goto L_0x00532d3c;
    }
    // 00532d2e  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532d32  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532d36  ff1528d45600           -call dword ptr [0x56d428]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690408) /* 0x56d428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532d3c:
    // 00532d3c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_532d3f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532d3f  833d2cd4560000         +cmp dword ptr [0x56d42c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690412) /* 0x56d42c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532d46  751f                   -jne 0x532d67
    if (!cpu.flags.zf)
    {
        goto L_0x00532d67;
    }
    // 00532d48  682cd45600             -push 0x56d42c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690412 /*0x56d42c*/;
    cpu.esp -= 4;
    // 00532d4d  6818c85600             -push 0x56c818
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687320 /*0x56c818*/;
    cpu.esp -= 4;
    // 00532d52  e8c1c5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532d57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532d59  740c                   -je 0x532d67
    if (cpu.flags.zf)
    {
        goto L_0x00532d67;
    }
    // 00532d5b  c7052cd45600ffffffff   -mov dword ptr [0x56d42c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690412) /* 0x56d42c */) = 4294967295 /*0xffffffff*/;
    // 00532d65  eb20                   -jmp 0x532d87
    goto L_0x00532d87;
L_0x00532d67:
    // 00532d67  833d2cd45600ff         +cmp dword ptr [0x56d42c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690412) /* 0x56d42c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532d6e  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532d73  7412                   -je 0x532d87
    if (cpu.flags.zf)
    {
        goto L_0x00532d87;
    }
    // 00532d75  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532d79  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532d7d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532d81  ff152cd45600           -call dword ptr [0x56d42c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690412) /* 0x56d42c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532d87:
    // 00532d87  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532d8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532d8a  833d30d4560000         +cmp dword ptr [0x56d430], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690416) /* 0x56d430 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532d91  751f                   -jne 0x532db2
    if (!cpu.flags.zf)
    {
        goto L_0x00532db2;
    }
    // 00532d93  6830d45600             -push 0x56d430
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690416 /*0x56d430*/;
    cpu.esp -= 4;
    // 00532d98  6828c85600             -push 0x56c828
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687336 /*0x56c828*/;
    cpu.esp -= 4;
    // 00532d9d  e876c5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532da2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532da4  740c                   -je 0x532db2
    if (cpu.flags.zf)
    {
        goto L_0x00532db2;
    }
    // 00532da6  c70530d45600ffffffff   -mov dword ptr [0x56d430], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690416) /* 0x56d430 */) = 4294967295 /*0xffffffff*/;
    // 00532db0  eb20                   -jmp 0x532dd2
    goto L_0x00532dd2;
L_0x00532db2:
    // 00532db2  833d30d45600ff         +cmp dword ptr [0x56d430], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690416) /* 0x56d430 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532db9  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532dbe  7412                   -je 0x532dd2
    if (cpu.flags.zf)
    {
        goto L_0x00532dd2;
    }
    // 00532dc0  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532dc4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532dc8  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532dcc  ff1530d45600           -call dword ptr [0x56d430]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690416) /* 0x56d430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532dd2:
    // 00532dd2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532dd5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532dd5  833d34d4560000         +cmp dword ptr [0x56d434], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690420) /* 0x56d434 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532ddc  751f                   -jne 0x532dfd
    if (!cpu.flags.zf)
    {
        goto L_0x00532dfd;
    }
    // 00532dde  6834d45600             -push 0x56d434
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690420 /*0x56d434*/;
    cpu.esp -= 4;
    // 00532de3  6838c85600             -push 0x56c838
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687352 /*0x56c838*/;
    cpu.esp -= 4;
    // 00532de8  e82bc5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532ded  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532def  740c                   -je 0x532dfd
    if (cpu.flags.zf)
    {
        goto L_0x00532dfd;
    }
    // 00532df1  c70534d45600ffffffff   -mov dword ptr [0x56d434], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690420) /* 0x56d434 */) = 4294967295 /*0xffffffff*/;
    // 00532dfb  eb20                   -jmp 0x532e1d
    goto L_0x00532e1d;
L_0x00532dfd:
    // 00532dfd  833d34d45600ff         +cmp dword ptr [0x56d434], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690420) /* 0x56d434 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532e04  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532e09  7412                   -je 0x532e1d
    if (cpu.flags.zf)
    {
        goto L_0x00532e1d;
    }
    // 00532e0b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e0f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e13  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e17  ff1534d45600           -call dword ptr [0x56d434]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690420) /* 0x56d434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532e1d:
    // 00532e1d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532e20  833d38d4560000         +cmp dword ptr [0x56d438], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690424) /* 0x56d438 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532e27  751f                   -jne 0x532e48
    if (!cpu.flags.zf)
    {
        goto L_0x00532e48;
    }
    // 00532e29  6838d45600             -push 0x56d438
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690424 /*0x56d438*/;
    cpu.esp -= 4;
    // 00532e2e  6848c85600             -push 0x56c848
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687368 /*0x56c848*/;
    cpu.esp -= 4;
    // 00532e33  e8e0c4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532e38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532e3a  740c                   -je 0x532e48
    if (cpu.flags.zf)
    {
        goto L_0x00532e48;
    }
    // 00532e3c  c70538d45600ffffffff   -mov dword ptr [0x56d438], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690424) /* 0x56d438 */) = 4294967295 /*0xffffffff*/;
    // 00532e46  eb20                   -jmp 0x532e68
    goto L_0x00532e68;
L_0x00532e48:
    // 00532e48  833d38d45600ff         +cmp dword ptr [0x56d438], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690424) /* 0x56d438 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532e4f  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532e54  7412                   -je 0x532e68
    if (cpu.flags.zf)
    {
        goto L_0x00532e68;
    }
    // 00532e56  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e5a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e5e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e62  ff1538d45600           -call dword ptr [0x56d438]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690424) /* 0x56d438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532e68:
    // 00532e68  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532e6b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532e6b  833d3cd4560000         +cmp dword ptr [0x56d43c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690428) /* 0x56d43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532e72  751f                   -jne 0x532e93
    if (!cpu.flags.zf)
    {
        goto L_0x00532e93;
    }
    // 00532e74  683cd45600             -push 0x56d43c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690428 /*0x56d43c*/;
    cpu.esp -= 4;
    // 00532e79  6854c85600             -push 0x56c854
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687380 /*0x56c854*/;
    cpu.esp -= 4;
    // 00532e7e  e895c4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532e83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532e85  740c                   -je 0x532e93
    if (cpu.flags.zf)
    {
        goto L_0x00532e93;
    }
    // 00532e87  c7053cd45600ffffffff   -mov dword ptr [0x56d43c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690428) /* 0x56d43c */) = 4294967295 /*0xffffffff*/;
    // 00532e91  eb20                   -jmp 0x532eb3
    goto L_0x00532eb3;
L_0x00532e93:
    // 00532e93  833d3cd45600ff         +cmp dword ptr [0x56d43c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690428) /* 0x56d43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532e9a  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532e9f  7412                   -je 0x532eb3
    if (cpu.flags.zf)
    {
        goto L_0x00532eb3;
    }
    // 00532ea1  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ea5  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ea9  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ead  ff153cd45600           -call dword ptr [0x56d43c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690428) /* 0x56d43c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532eb3:
    // 00532eb3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532eb6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532eb6  833d40d4560000         +cmp dword ptr [0x56d440], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690432) /* 0x56d440 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532ebd  751f                   -jne 0x532ede
    if (!cpu.flags.zf)
    {
        goto L_0x00532ede;
    }
    // 00532ebf  6840d45600             -push 0x56d440
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690432 /*0x56d440*/;
    cpu.esp -= 4;
    // 00532ec4  6860c85600             -push 0x56c860
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687392 /*0x56c860*/;
    cpu.esp -= 4;
    // 00532ec9  e84ac4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532ece  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532ed0  740c                   -je 0x532ede
    if (cpu.flags.zf)
    {
        goto L_0x00532ede;
    }
    // 00532ed2  c70540d45600ffffffff   -mov dword ptr [0x56d440], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690432) /* 0x56d440 */) = 4294967295 /*0xffffffff*/;
    // 00532edc  eb20                   -jmp 0x532efe
    goto L_0x00532efe;
L_0x00532ede:
    // 00532ede  833d40d45600ff         +cmp dword ptr [0x56d440], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690432) /* 0x56d440 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532ee5  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532eea  7412                   -je 0x532efe
    if (cpu.flags.zf)
    {
        goto L_0x00532efe;
    }
    // 00532eec  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ef0  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ef4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ef8  ff1540d45600           -call dword ptr [0x56d440]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690432) /* 0x56d440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532efe:
    // 00532efe  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532f01(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532f01  833d44d4560000         +cmp dword ptr [0x56d444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690436) /* 0x56d444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532f08  751f                   -jne 0x532f29
    if (!cpu.flags.zf)
    {
        goto L_0x00532f29;
    }
    // 00532f0a  6844d45600             -push 0x56d444
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690436 /*0x56d444*/;
    cpu.esp -= 4;
    // 00532f0f  686cc85600             -push 0x56c86c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687404 /*0x56c86c*/;
    cpu.esp -= 4;
    // 00532f14  e8ffc3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532f19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532f1b  740c                   -je 0x532f29
    if (cpu.flags.zf)
    {
        goto L_0x00532f29;
    }
    // 00532f1d  c70544d45600ffffffff   -mov dword ptr [0x56d444], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690436) /* 0x56d444 */) = 4294967295 /*0xffffffff*/;
    // 00532f27  eb20                   -jmp 0x532f49
    goto L_0x00532f49;
L_0x00532f29:
    // 00532f29  833d44d45600ff         +cmp dword ptr [0x56d444], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690436) /* 0x56d444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532f30  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532f35  7412                   -je 0x532f49
    if (cpu.flags.zf)
    {
        goto L_0x00532f49;
    }
    // 00532f37  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f3b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f3f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f43  ff1544d45600           -call dword ptr [0x56d444]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690436) /* 0x56d444 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532f49:
    // 00532f49  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532f4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532f4c  833d48d4560000         +cmp dword ptr [0x56d448], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690440) /* 0x56d448 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532f53  751f                   -jne 0x532f74
    if (!cpu.flags.zf)
    {
        goto L_0x00532f74;
    }
    // 00532f55  6848d45600             -push 0x56d448
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690440 /*0x56d448*/;
    cpu.esp -= 4;
    // 00532f5a  687cc85600             -push 0x56c87c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687420 /*0x56c87c*/;
    cpu.esp -= 4;
    // 00532f5f  e8b4c3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532f64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532f66  740c                   -je 0x532f74
    if (cpu.flags.zf)
    {
        goto L_0x00532f74;
    }
    // 00532f68  c70548d45600ffffffff   -mov dword ptr [0x56d448], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690440) /* 0x56d448 */) = 4294967295 /*0xffffffff*/;
    // 00532f72  eb20                   -jmp 0x532f94
    goto L_0x00532f94;
L_0x00532f74:
    // 00532f74  833d48d45600ff         +cmp dword ptr [0x56d448], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690440) /* 0x56d448 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532f7b  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532f80  7412                   -je 0x532f94
    if (cpu.flags.zf)
    {
        goto L_0x00532f94;
    }
    // 00532f82  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f86  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f8a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f8e  ff1548d45600           -call dword ptr [0x56d448]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690440) /* 0x56d448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532f94:
    // 00532f94  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532f97(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532f97  833d4cd4560000         +cmp dword ptr [0x56d44c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690444) /* 0x56d44c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532f9e  751f                   -jne 0x532fbf
    if (!cpu.flags.zf)
    {
        goto L_0x00532fbf;
    }
    // 00532fa0  684cd45600             -push 0x56d44c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690444 /*0x56d44c*/;
    cpu.esp -= 4;
    // 00532fa5  688cc85600             -push 0x56c88c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687436 /*0x56c88c*/;
    cpu.esp -= 4;
    // 00532faa  e869c3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532faf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532fb1  740c                   -je 0x532fbf
    if (cpu.flags.zf)
    {
        goto L_0x00532fbf;
    }
    // 00532fb3  c7054cd45600ffffffff   -mov dword ptr [0x56d44c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690444) /* 0x56d44c */) = 4294967295 /*0xffffffff*/;
    // 00532fbd  eb20                   -jmp 0x532fdf
    goto L_0x00532fdf;
L_0x00532fbf:
    // 00532fbf  833d4cd45600ff         +cmp dword ptr [0x56d44c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690444) /* 0x56d44c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532fc6  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532fcb  7412                   -je 0x532fdf
    if (cpu.flags.zf)
    {
        goto L_0x00532fdf;
    }
    // 00532fcd  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532fd1  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532fd5  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532fd9  ff154cd45600           -call dword ptr [0x56d44c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690444) /* 0x56d44c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532fdf:
    // 00532fdf  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532fe2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532fe2  833d50d4560000         +cmp dword ptr [0x56d450], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690448) /* 0x56d450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532fe9  751f                   -jne 0x53300a
    if (!cpu.flags.zf)
    {
        goto L_0x0053300a;
    }
    // 00532feb  6850d45600             -push 0x56d450
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690448 /*0x56d450*/;
    cpu.esp -= 4;
    // 00532ff0  689cc85600             -push 0x56c89c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687452 /*0x56c89c*/;
    cpu.esp -= 4;
    // 00532ff5  e81ec3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532ffa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532ffc  740c                   -je 0x53300a
    if (cpu.flags.zf)
    {
        goto L_0x0053300a;
    }
    // 00532ffe  c70550d45600ffffffff   -mov dword ptr [0x56d450], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690448) /* 0x56d450 */) = 4294967295 /*0xffffffff*/;
    // 00533008  eb1c                   -jmp 0x533026
    goto L_0x00533026;
L_0x0053300a:
    // 0053300a  833d50d45600ff         +cmp dword ptr [0x56d450], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690448) /* 0x56d450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533011  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533016  740e                   -je 0x533026
    if (cpu.flags.zf)
    {
        goto L_0x00533026;
    }
    // 00533018  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053301c  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533020  ff1550d45600           -call dword ptr [0x56d450]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690448) /* 0x56d450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533026:
    // 00533026  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_533029(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533029  833d54d4560000         +cmp dword ptr [0x56d454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690452) /* 0x56d454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533030  751f                   -jne 0x533051
    if (!cpu.flags.zf)
    {
        goto L_0x00533051;
    }
    // 00533032  6854d45600             -push 0x56d454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690452 /*0x56d454*/;
    cpu.esp -= 4;
    // 00533037  68acc85600             -push 0x56c8ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687468 /*0x56c8ac*/;
    cpu.esp -= 4;
    // 0053303c  e8d7c2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533041  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533043  740c                   -je 0x533051
    if (cpu.flags.zf)
    {
        goto L_0x00533051;
    }
    // 00533045  c70554d45600ffffffff   -mov dword ptr [0x56d454], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690452) /* 0x56d454 */) = 4294967295 /*0xffffffff*/;
    // 0053304f  eb1c                   -jmp 0x53306d
    goto L_0x0053306d;
L_0x00533051:
    // 00533051  833d54d45600ff         +cmp dword ptr [0x56d454], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690452) /* 0x56d454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533058  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053305d  740e                   -je 0x53306d
    if (cpu.flags.zf)
    {
        goto L_0x0053306d;
    }
    // 0053305f  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533063  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533067  ff1554d45600           -call dword ptr [0x56d454]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690452) /* 0x56d454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053306d:
    // 0053306d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_533070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533070  833d58d4560000         +cmp dword ptr [0x56d458], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690456) /* 0x56d458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533077  751f                   -jne 0x533098
    if (!cpu.flags.zf)
    {
        goto L_0x00533098;
    }
    // 00533079  6858d45600             -push 0x56d458
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690456 /*0x56d458*/;
    cpu.esp -= 4;
    // 0053307e  68bcc85600             -push 0x56c8bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687484 /*0x56c8bc*/;
    cpu.esp -= 4;
    // 00533083  e890c2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533088  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053308a  740c                   -je 0x533098
    if (cpu.flags.zf)
    {
        goto L_0x00533098;
    }
    // 0053308c  c70558d45600ffffffff   -mov dword ptr [0x56d458], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690456) /* 0x56d458 */) = 4294967295 /*0xffffffff*/;
    // 00533096  eb1c                   -jmp 0x5330b4
    goto L_0x005330b4;
L_0x00533098:
    // 00533098  833d58d45600ff         +cmp dword ptr [0x56d458], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690456) /* 0x56d458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053309f  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005330a4  740e                   -je 0x5330b4
    if (cpu.flags.zf)
    {
        goto L_0x005330b4;
    }
    // 005330a6  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005330aa  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005330ae  ff1558d45600           -call dword ptr [0x56d458]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690456) /* 0x56d458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005330b4:
    // 005330b4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5330b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005330b7  833d5cd4560000         +cmp dword ptr [0x56d45c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690460) /* 0x56d45c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005330be  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005330bf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005330c1  751f                   -jne 0x5330e2
    if (!cpu.flags.zf)
    {
        goto L_0x005330e2;
    }
    // 005330c3  685cd45600             -push 0x56d45c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690460 /*0x56d45c*/;
    cpu.esp -= 4;
    // 005330c8  68ccc85600             -push 0x56c8cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687500 /*0x56c8cc*/;
    cpu.esp -= 4;
    // 005330cd  e846c2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005330d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005330d4  740c                   -je 0x5330e2
    if (cpu.flags.zf)
    {
        goto L_0x005330e2;
    }
    // 005330d6  c7055cd45600ffffffff   -mov dword ptr [0x56d45c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690460) /* 0x56d45c */) = 4294967295 /*0xffffffff*/;
    // 005330e0  eb20                   -jmp 0x533102
    goto L_0x00533102;
L_0x005330e2:
    // 005330e2  833d5cd45600ff         +cmp dword ptr [0x56d45c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690460) /* 0x56d45c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005330e9  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005330ee  7412                   -je 0x533102
    if (cpu.flags.zf)
    {
        goto L_0x00533102;
    }
    // 005330f0  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005330f3  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005330f6  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005330f9  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005330fc  ff155cd45600           -call dword ptr [0x56d45c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690460) /* 0x56d45c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533102:
    // 00533102  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533103  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_533106(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533106  833d60d4560000         +cmp dword ptr [0x56d460], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690464) /* 0x56d460 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053310d  751f                   -jne 0x53312e
    if (!cpu.flags.zf)
    {
        goto L_0x0053312e;
    }
    // 0053310f  6860d45600             -push 0x56d460
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690464 /*0x56d460*/;
    cpu.esp -= 4;
    // 00533114  68e4c85600             -push 0x56c8e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687524 /*0x56c8e4*/;
    cpu.esp -= 4;
    // 00533119  e8fac1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053311e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533120  740c                   -je 0x53312e
    if (cpu.flags.zf)
    {
        goto L_0x0053312e;
    }
    // 00533122  c70560d45600ffffffff   -mov dword ptr [0x56d460], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690464) /* 0x56d460 */) = 4294967295 /*0xffffffff*/;
    // 0053312c  eb20                   -jmp 0x53314e
    goto L_0x0053314e;
L_0x0053312e:
    // 0053312e  833d60d45600ff         +cmp dword ptr [0x56d460], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690464) /* 0x56d460 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533135  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053313a  7412                   -je 0x53314e
    if (cpu.flags.zf)
    {
        goto L_0x0053314e;
    }
    // 0053313c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533140  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533144  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533148  ff1560d45600           -call dword ptr [0x56d460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690464) /* 0x56d460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053314e:
    // 0053314e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_533151(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533151  833d64d4560000         +cmp dword ptr [0x56d464], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690468) /* 0x56d464 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533158  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533159  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053315b  751f                   -jne 0x53317c
    if (!cpu.flags.zf)
    {
        goto L_0x0053317c;
    }
    // 0053315d  6864d45600             -push 0x56d464
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690468 /*0x56d464*/;
    cpu.esp -= 4;
    // 00533162  68f4c85600             -push 0x56c8f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687540 /*0x56c8f4*/;
    cpu.esp -= 4;
    // 00533167  e8acc1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053316c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053316e  740c                   -je 0x53317c
    if (cpu.flags.zf)
    {
        goto L_0x0053317c;
    }
    // 00533170  c70564d45600ffffffff   -mov dword ptr [0x56d464], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690468) /* 0x56d464 */) = 4294967295 /*0xffffffff*/;
    // 0053317a  eb23                   -jmp 0x53319f
    goto L_0x0053319f;
L_0x0053317c:
    // 0053317c  833d64d45600ff         +cmp dword ptr [0x56d464], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690468) /* 0x56d464 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533183  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533188  7415                   -je 0x53319f
    if (cpu.flags.zf)
    {
        goto L_0x0053319f;
    }
    // 0053318a  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053318d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533190  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533193  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533196  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533199  ff1564d45600           -call dword ptr [0x56d464]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690468) /* 0x56d464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053319f:
    // 0053319f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005331a0  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5331a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005331a3  833d68d4560000         +cmp dword ptr [0x56d468], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690472) /* 0x56d468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005331aa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005331ab  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005331ad  751f                   -jne 0x5331ce
    if (!cpu.flags.zf)
    {
        goto L_0x005331ce;
    }
    // 005331af  6868d45600             -push 0x56d468
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690472 /*0x56d468*/;
    cpu.esp -= 4;
    // 005331b4  6804c95600             -push 0x56c904
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687556 /*0x56c904*/;
    cpu.esp -= 4;
    // 005331b9  e85ac1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005331be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005331c0  740c                   -je 0x5331ce
    if (cpu.flags.zf)
    {
        goto L_0x005331ce;
    }
    // 005331c2  c70568d45600ffffffff   -mov dword ptr [0x56d468], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690472) /* 0x56d468 */) = 4294967295 /*0xffffffff*/;
    // 005331cc  eb29                   -jmp 0x5331f7
    goto L_0x005331f7;
L_0x005331ce:
    // 005331ce  833d68d45600ff         +cmp dword ptr [0x56d468], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690472) /* 0x56d468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005331d5  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005331da  741b                   -je 0x5331f7
    if (cpu.flags.zf)
    {
        goto L_0x005331f7;
    }
    // 005331dc  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005331df  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005331e2  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005331e5  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005331e8  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005331eb  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005331ee  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005331f1  ff1568d45600           -call dword ptr [0x56d468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690472) /* 0x56d468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005331f7:
    // 005331f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005331f8  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_5331fb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005331fb  833d6cd4560000         +cmp dword ptr [0x56d46c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690476) /* 0x56d46c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533202  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533203  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533205  751f                   -jne 0x533226
    if (!cpu.flags.zf)
    {
        goto L_0x00533226;
    }
    // 00533207  686cd45600             -push 0x56d46c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690476 /*0x56d46c*/;
    cpu.esp -= 4;
    // 0053320c  6818c95600             -push 0x56c918
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687576 /*0x56c918*/;
    cpu.esp -= 4;
    // 00533211  e802c1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533216  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533218  740c                   -je 0x533226
    if (cpu.flags.zf)
    {
        goto L_0x00533226;
    }
    // 0053321a  c7056cd45600ffffffff   -mov dword ptr [0x56d46c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690476) /* 0x56d46c */) = 4294967295 /*0xffffffff*/;
    // 00533224  eb29                   -jmp 0x53324f
    goto L_0x0053324f;
L_0x00533226:
    // 00533226  833d6cd45600ff         +cmp dword ptr [0x56d46c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690476) /* 0x56d46c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053322d  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533232  741b                   -je 0x53324f
    if (cpu.flags.zf)
    {
        goto L_0x0053324f;
    }
    // 00533234  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00533237  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053323a  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053323d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533240  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533243  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533246  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533249  ff156cd45600           -call dword ptr [0x56d46c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690476) /* 0x56d46c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053324f:
    // 0053324f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533250  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_533253(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533253  833d70d4560000         +cmp dword ptr [0x56d470], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690480) /* 0x56d470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053325a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053325b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053325d  751f                   -jne 0x53327e
    if (!cpu.flags.zf)
    {
        goto L_0x0053327e;
    }
    // 0053325f  6870d45600             -push 0x56d470
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690480 /*0x56d470*/;
    cpu.esp -= 4;
    // 00533264  682cc95600             -push 0x56c92c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687596 /*0x56c92c*/;
    cpu.esp -= 4;
    // 00533269  e8aac0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053326e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533270  740c                   -je 0x53327e
    if (cpu.flags.zf)
    {
        goto L_0x0053327e;
    }
    // 00533272  c70570d45600ffffffff   -mov dword ptr [0x56d470], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690480) /* 0x56d470 */) = 4294967295 /*0xffffffff*/;
    // 0053327c  eb26                   -jmp 0x5332a4
    goto L_0x005332a4;
L_0x0053327e:
    // 0053327e  833d70d45600ff         +cmp dword ptr [0x56d470], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690480) /* 0x56d470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533285  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053328a  7418                   -je 0x5332a4
    if (cpu.flags.zf)
    {
        goto L_0x005332a4;
    }
    // 0053328c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053328f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00533292  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533295  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533298  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053329b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053329e  ff1570d45600           -call dword ptr [0x56d470]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690480) /* 0x56d470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005332a4:
    // 005332a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005332a5  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_5332a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005332a8  833d74d4560000         +cmp dword ptr [0x56d474], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690484) /* 0x56d474 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005332af  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005332b0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005332b2  751f                   -jne 0x5332d3
    if (!cpu.flags.zf)
    {
        goto L_0x005332d3;
    }
    // 005332b4  6874d45600             -push 0x56d474
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690484 /*0x56d474*/;
    cpu.esp -= 4;
    // 005332b9  6848c95600             -push 0x56c948
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687624 /*0x56c948*/;
    cpu.esp -= 4;
    // 005332be  e855c0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005332c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005332c5  740c                   -je 0x5332d3
    if (cpu.flags.zf)
    {
        goto L_0x005332d3;
    }
    // 005332c7  c70574d45600ffffffff   -mov dword ptr [0x56d474], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690484) /* 0x56d474 */) = 4294967295 /*0xffffffff*/;
    // 005332d1  eb26                   -jmp 0x5332f9
    goto L_0x005332f9;
L_0x005332d3:
    // 005332d3  833d74d45600ff         +cmp dword ptr [0x56d474], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690484) /* 0x56d474 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005332da  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005332df  7418                   -je 0x5332f9
    if (cpu.flags.zf)
    {
        goto L_0x005332f9;
    }
    // 005332e1  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005332e4  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005332e7  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005332ea  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005332ed  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005332f0  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005332f3  ff1574d45600           -call dword ptr [0x56d474]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690484) /* 0x56d474 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005332f9:
    // 005332f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005332fa  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_5332fd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005332fd  833d78d4560000         +cmp dword ptr [0x56d478], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690488) /* 0x56d478 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533304  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533305  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533307  751f                   -jne 0x533328
    if (!cpu.flags.zf)
    {
        goto L_0x00533328;
    }
    // 00533309  6878d45600             -push 0x56d478
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690488 /*0x56d478*/;
    cpu.esp -= 4;
    // 0053330e  6864c95600             -push 0x56c964
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687652 /*0x56c964*/;
    cpu.esp -= 4;
    // 00533313  e800c0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533318  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053331a  740c                   -je 0x533328
    if (cpu.flags.zf)
    {
        goto L_0x00533328;
    }
    // 0053331c  c70578d45600ffffffff   -mov dword ptr [0x56d478], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690488) /* 0x56d478 */) = 4294967295 /*0xffffffff*/;
    // 00533326  eb29                   -jmp 0x533351
    goto L_0x00533351;
L_0x00533328:
    // 00533328  833d78d45600ff         +cmp dword ptr [0x56d478], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690488) /* 0x56d478 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053332f  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533334  741b                   -je 0x533351
    if (cpu.flags.zf)
    {
        goto L_0x00533351;
    }
    // 00533336  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00533339  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053333c  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053333f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533342  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533345  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533348  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053334b  ff1578d45600           -call dword ptr [0x56d478]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690488) /* 0x56d478 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533351:
    // 00533351  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533352  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_533355(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533355  833d7cd4560000         +cmp dword ptr [0x56d47c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690492) /* 0x56d47c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053335c  751f                   -jne 0x53337d
    if (!cpu.flags.zf)
    {
        goto L_0x0053337d;
    }
    // 0053335e  687cd45600             -push 0x56d47c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690492 /*0x56d47c*/;
    cpu.esp -= 4;
    // 00533363  6870c95600             -push 0x56c970
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687664 /*0x56c970*/;
    cpu.esp -= 4;
    // 00533368  e8abbfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053336d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053336f  740c                   -je 0x53337d
    if (cpu.flags.zf)
    {
        goto L_0x0053337d;
    }
    // 00533371  c7057cd45600ffffffff   -mov dword ptr [0x56d47c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690492) /* 0x56d47c */) = 4294967295 /*0xffffffff*/;
    // 0053337b  eb20                   -jmp 0x53339d
    goto L_0x0053339d;
L_0x0053337d:
    // 0053337d  833d7cd45600ff         +cmp dword ptr [0x56d47c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690492) /* 0x56d47c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533384  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533389  7412                   -je 0x53339d
    if (cpu.flags.zf)
    {
        goto L_0x0053339d;
    }
    // 0053338b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053338f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533393  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533397  ff157cd45600           -call dword ptr [0x56d47c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690492) /* 0x56d47c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053339d:
    // 0053339d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5333a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005333a0  833d80d4560000         +cmp dword ptr [0x56d480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690496) /* 0x56d480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005333a7  751f                   -jne 0x5333c8
    if (!cpu.flags.zf)
    {
        goto L_0x005333c8;
    }
    // 005333a9  6880d45600             -push 0x56d480
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690496 /*0x56d480*/;
    cpu.esp -= 4;
    // 005333ae  6884c95600             -push 0x56c984
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687684 /*0x56c984*/;
    cpu.esp -= 4;
    // 005333b3  e860bfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005333b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005333ba  740c                   -je 0x5333c8
    if (cpu.flags.zf)
    {
        goto L_0x005333c8;
    }
    // 005333bc  c70580d45600ffffffff   -mov dword ptr [0x56d480], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690496) /* 0x56d480 */) = 4294967295 /*0xffffffff*/;
    // 005333c6  eb20                   -jmp 0x5333e8
    goto L_0x005333e8;
L_0x005333c8:
    // 005333c8  833d80d45600ff         +cmp dword ptr [0x56d480], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690496) /* 0x56d480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005333cf  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005333d4  7412                   -je 0x5333e8
    if (cpu.flags.zf)
    {
        goto L_0x005333e8;
    }
    // 005333d6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005333da  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005333de  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005333e2  ff1580d45600           -call dword ptr [0x56d480]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690496) /* 0x56d480 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005333e8:
    // 005333e8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5333eb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005333eb  833d84d4560000         +cmp dword ptr [0x56d484], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690500) /* 0x56d484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005333f2  751f                   -jne 0x533413
    if (!cpu.flags.zf)
    {
        goto L_0x00533413;
    }
    // 005333f4  6884d45600             -push 0x56d484
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690500 /*0x56d484*/;
    cpu.esp -= 4;
    // 005333f9  6898c95600             -push 0x56c998
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687704 /*0x56c998*/;
    cpu.esp -= 4;
    // 005333fe  e815bfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533403  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533405  740c                   -je 0x533413
    if (cpu.flags.zf)
    {
        goto L_0x00533413;
    }
    // 00533407  c70584d45600ffffffff   -mov dword ptr [0x56d484], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690500) /* 0x56d484 */) = 4294967295 /*0xffffffff*/;
    // 00533411  eb20                   -jmp 0x533433
    goto L_0x00533433;
L_0x00533413:
    // 00533413  833d84d45600ff         +cmp dword ptr [0x56d484], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690500) /* 0x56d484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053341a  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053341f  7412                   -je 0x533433
    if (cpu.flags.zf)
    {
        goto L_0x00533433;
    }
    // 00533421  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533425  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533429  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053342d  ff1584d45600           -call dword ptr [0x56d484]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690500) /* 0x56d484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533433:
    // 00533433  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_533436(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533436  833d88d4560000         +cmp dword ptr [0x56d488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690504) /* 0x56d488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053343d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053343e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533440  751f                   -jne 0x533461
    if (!cpu.flags.zf)
    {
        goto L_0x00533461;
    }
    // 00533442  6888d45600             -push 0x56d488
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690504 /*0x56d488*/;
    cpu.esp -= 4;
    // 00533447  68acc95600             -push 0x56c9ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687724 /*0x56c9ac*/;
    cpu.esp -= 4;
    // 0053344c  e8c7beffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533451  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533453  740c                   -je 0x533461
    if (cpu.flags.zf)
    {
        goto L_0x00533461;
    }
    // 00533455  c70588d45600ffffffff   -mov dword ptr [0x56d488], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690504) /* 0x56d488 */) = 4294967295 /*0xffffffff*/;
    // 0053345f  eb20                   -jmp 0x533481
    goto L_0x00533481;
L_0x00533461:
    // 00533461  833d88d45600ff         +cmp dword ptr [0x56d488], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690504) /* 0x56d488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533468  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053346d  7412                   -je 0x533481
    if (cpu.flags.zf)
    {
        goto L_0x00533481;
    }
    // 0053346f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533472  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533475  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533478  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053347b  ff1588d45600           -call dword ptr [0x56d488]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690504) /* 0x56d488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533481:
    // 00533481  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533482  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_533485(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533485  833d8cd4560000         +cmp dword ptr [0x56d48c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690508) /* 0x56d48c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053348c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053348d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053348f  751f                   -jne 0x5334b0
    if (!cpu.flags.zf)
    {
        goto L_0x005334b0;
    }
    // 00533491  688cd45600             -push 0x56d48c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690508 /*0x56d48c*/;
    cpu.esp -= 4;
    // 00533496  68bcc95600             -push 0x56c9bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687740 /*0x56c9bc*/;
    cpu.esp -= 4;
    // 0053349b  e878beffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005334a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005334a2  740c                   -je 0x5334b0
    if (cpu.flags.zf)
    {
        goto L_0x005334b0;
    }
    // 005334a4  c7058cd45600ffffffff   -mov dword ptr [0x56d48c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690508) /* 0x56d48c */) = 4294967295 /*0xffffffff*/;
    // 005334ae  eb23                   -jmp 0x5334d3
    goto L_0x005334d3;
L_0x005334b0:
    // 005334b0  833d8cd45600ff         +cmp dword ptr [0x56d48c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690508) /* 0x56d48c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005334b7  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005334bc  7415                   -je 0x5334d3
    if (cpu.flags.zf)
    {
        goto L_0x005334d3;
    }
    // 005334be  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005334c1  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005334c4  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005334c7  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005334ca  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005334cd  ff158cd45600           -call dword ptr [0x56d48c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690508) /* 0x56d48c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005334d3:
    // 005334d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005334d4  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5334d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005334d7  833d90d4560000         +cmp dword ptr [0x56d490], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690512) /* 0x56d490 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005334de  751f                   -jne 0x5334ff
    if (!cpu.flags.zf)
    {
        goto L_0x005334ff;
    }
    // 005334e0  6890d45600             -push 0x56d490
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690512 /*0x56d490*/;
    cpu.esp -= 4;
    // 005334e5  68ccc95600             -push 0x56c9cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687756 /*0x56c9cc*/;
    cpu.esp -= 4;
    // 005334ea  e829beffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005334ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005334f1  740c                   -je 0x5334ff
    if (cpu.flags.zf)
    {
        goto L_0x005334ff;
    }
    // 005334f3  c70590d45600ffffffff   -mov dword ptr [0x56d490], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690512) /* 0x56d490 */) = 4294967295 /*0xffffffff*/;
    // 005334fd  eb20                   -jmp 0x53351f
    goto L_0x0053351f;
L_0x005334ff:
    // 005334ff  833d90d45600ff         +cmp dword ptr [0x56d490], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690512) /* 0x56d490 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533506  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053350b  7412                   -je 0x53351f
    if (cpu.flags.zf)
    {
        goto L_0x0053351f;
    }
    // 0053350d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533511  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533515  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533519  ff1590d45600           -call dword ptr [0x56d490]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690512) /* 0x56d490 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053351f:
    // 0053351f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_533522(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533522  833d94d4560000         +cmp dword ptr [0x56d494], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690516) /* 0x56d494 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533529  751f                   -jne 0x53354a
    if (!cpu.flags.zf)
    {
        goto L_0x0053354a;
    }
    // 0053352b  6894d45600             -push 0x56d494
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690516 /*0x56d494*/;
    cpu.esp -= 4;
    // 00533530  68dcc95600             -push 0x56c9dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687772 /*0x56c9dc*/;
    cpu.esp -= 4;
    // 00533535  e8debdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053353a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053353c  740c                   -je 0x53354a
    if (cpu.flags.zf)
    {
        goto L_0x0053354a;
    }
    // 0053353e  c70594d45600ffffffff   -mov dword ptr [0x56d494], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690516) /* 0x56d494 */) = 4294967295 /*0xffffffff*/;
    // 00533548  eb20                   -jmp 0x53356a
    goto L_0x0053356a;
L_0x0053354a:
    // 0053354a  833d94d45600ff         +cmp dword ptr [0x56d494], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690516) /* 0x56d494 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533551  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533556  7412                   -je 0x53356a
    if (cpu.flags.zf)
    {
        goto L_0x0053356a;
    }
    // 00533558  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053355c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533560  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533564  ff1594d45600           -call dword ptr [0x56d494]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690516) /* 0x56d494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053356a:
    // 0053356a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53356d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053356d  833d98d4560000         +cmp dword ptr [0x56d498], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690520) /* 0x56d498 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533574  751f                   -jne 0x533595
    if (!cpu.flags.zf)
    {
        goto L_0x00533595;
    }
    // 00533576  6898d45600             -push 0x56d498
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690520 /*0x56d498*/;
    cpu.esp -= 4;
    // 0053357b  68f0c95600             -push 0x56c9f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687792 /*0x56c9f0*/;
    cpu.esp -= 4;
    // 00533580  e893bdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533585  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533587  740c                   -je 0x533595
    if (cpu.flags.zf)
    {
        goto L_0x00533595;
    }
    // 00533589  c70598d45600ffffffff   -mov dword ptr [0x56d498], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690520) /* 0x56d498 */) = 4294967295 /*0xffffffff*/;
    // 00533593  eb20                   -jmp 0x5335b5
    goto L_0x005335b5;
L_0x00533595:
    // 00533595  833d98d45600ff         +cmp dword ptr [0x56d498], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690520) /* 0x56d498 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053359c  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005335a1  7412                   -je 0x5335b5
    if (cpu.flags.zf)
    {
        goto L_0x005335b5;
    }
    // 005335a3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335a7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335ab  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335af  ff1598d45600           -call dword ptr [0x56d498]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690520) /* 0x56d498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005335b5:
    // 005335b5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5335b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005335b8  833d9cd4560000         +cmp dword ptr [0x56d49c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690524) /* 0x56d49c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005335bf  751f                   -jne 0x5335e0
    if (!cpu.flags.zf)
    {
        goto L_0x005335e0;
    }
    // 005335c1  689cd45600             -push 0x56d49c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690524 /*0x56d49c*/;
    cpu.esp -= 4;
    // 005335c6  6800ca5600             -push 0x56ca00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687808 /*0x56ca00*/;
    cpu.esp -= 4;
    // 005335cb  e848bdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005335d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005335d2  740c                   -je 0x5335e0
    if (cpu.flags.zf)
    {
        goto L_0x005335e0;
    }
    // 005335d4  c7059cd45600ffffffff   -mov dword ptr [0x56d49c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690524) /* 0x56d49c */) = 4294967295 /*0xffffffff*/;
    // 005335de  eb20                   -jmp 0x533600
    goto L_0x00533600;
L_0x005335e0:
    // 005335e0  833d9cd45600ff         +cmp dword ptr [0x56d49c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690524) /* 0x56d49c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005335e7  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005335ec  7412                   -je 0x533600
    if (cpu.flags.zf)
    {
        goto L_0x00533600;
    }
    // 005335ee  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335f2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335f6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335fa  ff159cd45600           -call dword ptr [0x56d49c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690524) /* 0x56d49c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533600:
    // 00533600  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_533603(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533603  833da0d4560000         +cmp dword ptr [0x56d4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690528) /* 0x56d4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053360a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053360b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053360d  751f                   -jne 0x53362e
    if (!cpu.flags.zf)
    {
        goto L_0x0053362e;
    }
    // 0053360f  68a0d45600             -push 0x56d4a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690528 /*0x56d4a0*/;
    cpu.esp -= 4;
    // 00533614  6810ca5600             -push 0x56ca10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687824 /*0x56ca10*/;
    cpu.esp -= 4;
    // 00533619  e8fabcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053361e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533620  740c                   -je 0x53362e
    if (cpu.flags.zf)
    {
        goto L_0x0053362e;
    }
    // 00533622  c705a0d45600ffffffff   -mov dword ptr [0x56d4a0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690528) /* 0x56d4a0 */) = 4294967295 /*0xffffffff*/;
    // 0053362c  eb20                   -jmp 0x53364e
    goto L_0x0053364e;
L_0x0053362e:
    // 0053362e  833da0d45600ff         +cmp dword ptr [0x56d4a0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690528) /* 0x56d4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533635  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053363a  7412                   -je 0x53364e
    if (cpu.flags.zf)
    {
        goto L_0x0053364e;
    }
    // 0053363c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053363f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533642  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533645  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533648  ff15a0d45600           -call dword ptr [0x56d4a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690528) /* 0x56d4a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053364e:
    // 0053364e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053364f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_533652(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533652  833da4d4560000         +cmp dword ptr [0x56d4a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690532) /* 0x56d4a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533659  751f                   -jne 0x53367a
    if (!cpu.flags.zf)
    {
        goto L_0x0053367a;
    }
    // 0053365b  68a4d45600             -push 0x56d4a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690532 /*0x56d4a4*/;
    cpu.esp -= 4;
    // 00533660  6828ca5600             -push 0x56ca28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687848 /*0x56ca28*/;
    cpu.esp -= 4;
    // 00533665  e8aebcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053366a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053366c  740c                   -je 0x53367a
    if (cpu.flags.zf)
    {
        goto L_0x0053367a;
    }
    // 0053366e  c705a4d45600ffffffff   -mov dword ptr [0x56d4a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690532) /* 0x56d4a4 */) = 4294967295 /*0xffffffff*/;
    // 00533678  eb20                   -jmp 0x53369a
    goto L_0x0053369a;
L_0x0053367a:
    // 0053367a  833da4d45600ff         +cmp dword ptr [0x56d4a4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690532) /* 0x56d4a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533681  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533686  7412                   -je 0x53369a
    if (cpu.flags.zf)
    {
        goto L_0x0053369a;
    }
    // 00533688  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053368c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533690  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533694  ff15a4d45600           -call dword ptr [0x56d4a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690532) /* 0x56d4a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053369a:
    // 0053369a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53369d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053369d  833da8d4560000         +cmp dword ptr [0x56d4a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690536) /* 0x56d4a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005336a4  751f                   -jne 0x5336c5
    if (!cpu.flags.zf)
    {
        goto L_0x005336c5;
    }
    // 005336a6  68a8d45600             -push 0x56d4a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690536 /*0x56d4a8*/;
    cpu.esp -= 4;
    // 005336ab  6838ca5600             -push 0x56ca38
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687864 /*0x56ca38*/;
    cpu.esp -= 4;
    // 005336b0  e863bcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005336b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005336b7  740c                   -je 0x5336c5
    if (cpu.flags.zf)
    {
        goto L_0x005336c5;
    }
    // 005336b9  c705a8d45600ffffffff   -mov dword ptr [0x56d4a8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690536) /* 0x56d4a8 */) = 4294967295 /*0xffffffff*/;
    // 005336c3  eb18                   -jmp 0x5336dd
    goto L_0x005336dd;
L_0x005336c5:
    // 005336c5  833da8d45600ff         +cmp dword ptr [0x56d4a8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690536) /* 0x56d4a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005336cc  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005336d1  740a                   -je 0x5336dd
    if (cpu.flags.zf)
    {
        goto L_0x005336dd;
    }
    // 005336d3  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 005336d7  ff15a8d45600           -call dword ptr [0x56d4a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690536) /* 0x56d4a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005336dd:
    // 005336dd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_5336e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005336e0  833dacd4560000         +cmp dword ptr [0x56d4ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690540) /* 0x56d4ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005336e7  751f                   -jne 0x533708
    if (!cpu.flags.zf)
    {
        goto L_0x00533708;
    }
    // 005336e9  68acd45600             -push 0x56d4ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690540 /*0x56d4ac*/;
    cpu.esp -= 4;
    // 005336ee  6848ca5600             -push 0x56ca48
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687880 /*0x56ca48*/;
    cpu.esp -= 4;
    // 005336f3  e820bcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005336f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005336fa  740c                   -je 0x533708
    if (cpu.flags.zf)
    {
        goto L_0x00533708;
    }
    // 005336fc  c705acd45600ffffffff   -mov dword ptr [0x56d4ac], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690540) /* 0x56d4ac */) = 4294967295 /*0xffffffff*/;
    // 00533706  eb1c                   -jmp 0x533724
    goto L_0x00533724;
L_0x00533708:
    // 00533708  833dacd45600ff         +cmp dword ptr [0x56d4ac], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690540) /* 0x56d4ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053370f  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00533714  740e                   -je 0x533724
    if (cpu.flags.zf)
    {
        goto L_0x00533724;
    }
    // 00533716  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053371a  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053371e  ff15acd45600           -call dword ptr [0x56d4ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690540) /* 0x56d4ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533724:
    // 00533724  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_533727(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533727  833db0d4560000         +cmp dword ptr [0x56d4b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690544) /* 0x56d4b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053372e  751f                   -jne 0x53374f
    if (!cpu.flags.zf)
    {
        goto L_0x0053374f;
    }
    // 00533730  68b0d45600             -push 0x56d4b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690544 /*0x56d4b0*/;
    cpu.esp -= 4;
    // 00533735  685cca5600             -push 0x56ca5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687900 /*0x56ca5c*/;
    cpu.esp -= 4;
    // 0053373a  e8d9bbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053373f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533741  740c                   -je 0x53374f
    if (cpu.flags.zf)
    {
        goto L_0x0053374f;
    }
    // 00533743  c705b0d45600ffffffff   -mov dword ptr [0x56d4b0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690544) /* 0x56d4b0 */) = 4294967295 /*0xffffffff*/;
    // 0053374d  eb1c                   -jmp 0x53376b
    goto L_0x0053376b;
L_0x0053374f:
    // 0053374f  833db0d45600ff         +cmp dword ptr [0x56d4b0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690544) /* 0x56d4b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533756  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 0053375b  740e                   -je 0x53376b
    if (cpu.flags.zf)
    {
        goto L_0x0053376b;
    }
    // 0053375d  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533761  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533765  ff15b0d45600           -call dword ptr [0x56d4b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690544) /* 0x56d4b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053376b:
    // 0053376b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_53376e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053376e  833db4d4560000         +cmp dword ptr [0x56d4b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690548) /* 0x56d4b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533775  751f                   -jne 0x533796
    if (!cpu.flags.zf)
    {
        goto L_0x00533796;
    }
    // 00533777  68b4d45600             -push 0x56d4b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690548 /*0x56d4b4*/;
    cpu.esp -= 4;
    // 0053377c  6874ca5600             -push 0x56ca74
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687924 /*0x56ca74*/;
    cpu.esp -= 4;
    // 00533781  e892bbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533786  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533788  740c                   -je 0x533796
    if (cpu.flags.zf)
    {
        goto L_0x00533796;
    }
    // 0053378a  c705b4d45600ffffffff   -mov dword ptr [0x56d4b4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690548) /* 0x56d4b4 */) = 4294967295 /*0xffffffff*/;
    // 00533794  eb1c                   -jmp 0x5337b2
    goto L_0x005337b2;
L_0x00533796:
    // 00533796  833db4d45600ff         +cmp dword ptr [0x56d4b4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690548) /* 0x56d4b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053379d  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 005337a2  740e                   -je 0x5337b2
    if (cpu.flags.zf)
    {
        goto L_0x005337b2;
    }
    // 005337a4  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005337a8  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005337ac  ff15b4d45600           -call dword ptr [0x56d4b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690548) /* 0x56d4b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005337b2:
    // 005337b2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5337b5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005337b5  833db8d4560000         +cmp dword ptr [0x56d4b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690552) /* 0x56d4b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005337bc  751f                   -jne 0x5337dd
    if (!cpu.flags.zf)
    {
        goto L_0x005337dd;
    }
    // 005337be  68b8d45600             -push 0x56d4b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690552 /*0x56d4b8*/;
    cpu.esp -= 4;
    // 005337c3  688cca5600             -push 0x56ca8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687948 /*0x56ca8c*/;
    cpu.esp -= 4;
    // 005337c8  e84bbbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005337cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005337cf  740c                   -je 0x5337dd
    if (cpu.flags.zf)
    {
        goto L_0x005337dd;
    }
    // 005337d1  c705b8d45600ffffffff   -mov dword ptr [0x56d4b8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690552) /* 0x56d4b8 */) = 4294967295 /*0xffffffff*/;
    // 005337db  eb1c                   -jmp 0x5337f9
    goto L_0x005337f9;
L_0x005337dd:
    // 005337dd  833db8d45600ff         +cmp dword ptr [0x56d4b8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690552) /* 0x56d4b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005337e4  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 005337e9  740e                   -je 0x5337f9
    if (cpu.flags.zf)
    {
        goto L_0x005337f9;
    }
    // 005337eb  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005337ef  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005337f3  ff15b8d45600           -call dword ptr [0x56d4b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690552) /* 0x56d4b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005337f9:
    // 005337f9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5337fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005337fc  833dbcd4560000         +cmp dword ptr [0x56d4bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690556) /* 0x56d4bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533803  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533804  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533806  751f                   -jne 0x533827
    if (!cpu.flags.zf)
    {
        goto L_0x00533827;
    }
    // 00533808  68bcd45600             -push 0x56d4bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690556 /*0x56d4bc*/;
    cpu.esp -= 4;
    // 0053380d  689cca5600             -push 0x56ca9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687964 /*0x56ca9c*/;
    cpu.esp -= 4;
    // 00533812  e801bbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533817  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533819  740c                   -je 0x533827
    if (cpu.flags.zf)
    {
        goto L_0x00533827;
    }
    // 0053381b  c705bcd45600ffffffff   -mov dword ptr [0x56d4bc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690556) /* 0x56d4bc */) = 4294967295 /*0xffffffff*/;
    // 00533825  eb20                   -jmp 0x533847
    goto L_0x00533847;
L_0x00533827:
    // 00533827  833dbcd45600ff         +cmp dword ptr [0x56d4bc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690556) /* 0x56d4bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053382e  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00533833  7412                   -je 0x533847
    if (cpu.flags.zf)
    {
        goto L_0x00533847;
    }
    // 00533835  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533838  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053383b  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053383e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533841  ff15bcd45600           -call dword ptr [0x56d4bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690556) /* 0x56d4bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533847:
    // 00533847  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533848  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_53384b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053384b  833dc0d4560000         +cmp dword ptr [0x56d4c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690560) /* 0x56d4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533852  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533853  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533855  751f                   -jne 0x533876
    if (!cpu.flags.zf)
    {
        goto L_0x00533876;
    }
    // 00533857  68c0d45600             -push 0x56d4c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690560 /*0x56d4c0*/;
    cpu.esp -= 4;
    // 0053385c  68b0ca5600             -push 0x56cab0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5687984 /*0x56cab0*/;
    cpu.esp -= 4;
    // 00533861  e8b2baffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533866  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533868  740c                   -je 0x533876
    if (cpu.flags.zf)
    {
        goto L_0x00533876;
    }
    // 0053386a  c705c0d45600ffffffff   -mov dword ptr [0x56d4c0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690560) /* 0x56d4c0 */) = 4294967295 /*0xffffffff*/;
    // 00533874  eb20                   -jmp 0x533896
    goto L_0x00533896;
L_0x00533876:
    // 00533876  833dc0d45600ff         +cmp dword ptr [0x56d4c0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690560) /* 0x56d4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053387d  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00533882  7412                   -je 0x533896
    if (cpu.flags.zf)
    {
        goto L_0x00533896;
    }
    // 00533884  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533887  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053388a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053388d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533890  ff15c0d45600           -call dword ptr [0x56d4c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690560) /* 0x56d4c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533896:
    // 00533896  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533897  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_53389a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053389a  833dc4d4560000         +cmp dword ptr [0x56d4c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690564) /* 0x56d4c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005338a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005338a2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005338a4  751f                   -jne 0x5338c5
    if (!cpu.flags.zf)
    {
        goto L_0x005338c5;
    }
    // 005338a6  68c4d45600             -push 0x56d4c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690564 /*0x56d4c4*/;
    cpu.esp -= 4;
    // 005338ab  68c8ca5600             -push 0x56cac8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5688008 /*0x56cac8*/;
    cpu.esp -= 4;
    // 005338b0  e863baffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005338b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005338b7  740c                   -je 0x5338c5
    if (cpu.flags.zf)
    {
        goto L_0x005338c5;
    }
    // 005338b9  c705c4d45600ffffffff   -mov dword ptr [0x56d4c4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690564) /* 0x56d4c4 */) = 4294967295 /*0xffffffff*/;
    // 005338c3  eb20                   -jmp 0x5338e5
    goto L_0x005338e5;
L_0x005338c5:
    // 005338c5  833dc4d45600ff         +cmp dword ptr [0x56d4c4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690564) /* 0x56d4c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005338cc  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 005338d1  7412                   -je 0x5338e5
    if (cpu.flags.zf)
    {
        goto L_0x005338e5;
    }
    // 005338d3  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005338d6  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005338d9  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005338dc  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005338df  ff15c4d45600           -call dword ptr [0x56d4c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690564) /* 0x56d4c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005338e5:
    // 005338e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005338e6  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_5338e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005338e9  833dc8d4560000         +cmp dword ptr [0x56d4c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690568) /* 0x56d4c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005338f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005338f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005338f3  751f                   -jne 0x533914
    if (!cpu.flags.zf)
    {
        goto L_0x00533914;
    }
    // 005338f5  68c8d45600             -push 0x56d4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690568 /*0x56d4c8*/;
    cpu.esp -= 4;
    // 005338fa  68e0ca5600             -push 0x56cae0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5688032 /*0x56cae0*/;
    cpu.esp -= 4;
    // 005338ff  e814baffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533904  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533906  740c                   -je 0x533914
    if (cpu.flags.zf)
    {
        goto L_0x00533914;
    }
    // 00533908  c705c8d45600ffffffff   -mov dword ptr [0x56d4c8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690568) /* 0x56d4c8 */) = 4294967295 /*0xffffffff*/;
    // 00533912  eb32                   -jmp 0x533946
    goto L_0x00533946;
L_0x00533914:
    // 00533914  833dc8d45600ff         +cmp dword ptr [0x56d4c8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690568) /* 0x56d4c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053391b  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00533920  7424                   -je 0x533946
    if (cpu.flags.zf)
    {
        goto L_0x00533946;
    }
    // 00533922  ff752c                 -push dword ptr [ebp + 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    // 00533925  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 00533928  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 0053392b  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0053392e  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00533931  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00533934  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533937  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053393a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053393d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533940  ff15c8d45600           -call dword ptr [0x56d4c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690568) /* 0x56d4c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533946:
    // 00533946  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533947  c22800                 -ret 0x28
    cpu.esp += 4+40 /*0x28*/;
    return;
}

/* align: skip  */
void Application::sub_53394a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053394a  833dccd4560000         +cmp dword ptr [0x56d4cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690572) /* 0x56d4cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533951  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533952  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533954  751f                   -jne 0x533975
    if (!cpu.flags.zf)
    {
        goto L_0x00533975;
    }
    // 00533956  68ccd45600             -push 0x56d4cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690572 /*0x56d4cc*/;
    cpu.esp -= 4;
    // 0053395b  68f8ca5600             -push 0x56caf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5688056 /*0x56caf8*/;
    cpu.esp -= 4;
    // 00533960  e8b3b9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533965  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533967  740c                   -je 0x533975
    if (cpu.flags.zf)
    {
        goto L_0x00533975;
    }
    // 00533969  c705ccd45600ffffffff   -mov dword ptr [0x56d4cc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690572) /* 0x56d4cc */) = 4294967295 /*0xffffffff*/;
    // 00533973  eb32                   -jmp 0x5339a7
    goto L_0x005339a7;
L_0x00533975:
    // 00533975  833dccd45600ff         +cmp dword ptr [0x56d4cc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690572) /* 0x56d4cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053397c  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00533981  7424                   -je 0x5339a7
    if (cpu.flags.zf)
    {
        goto L_0x005339a7;
    }
    // 00533983  ff752c                 -push dword ptr [ebp + 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    // 00533986  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 00533989  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 0053398c  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0053398f  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00533992  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00533995  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533998  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053399b  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053399e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005339a1  ff15ccd45600           -call dword ptr [0x56d4cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690572) /* 0x56d4cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005339a7:
    // 005339a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005339a8  c22800                 -ret 0x28
    cpu.esp += 4+40 /*0x28*/;
    return;
}

/* align: skip  */
void Application::sub_5339ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005339ab  833dd0d4560000         +cmp dword ptr [0x56d4d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690576) /* 0x56d4d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005339b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005339b3  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005339b5  751f                   -jne 0x5339d6
    if (!cpu.flags.zf)
    {
        goto L_0x005339d6;
    }
    // 005339b7  68d0d45600             -push 0x56d4d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690576 /*0x56d4d0*/;
    cpu.esp -= 4;
    // 005339bc  6810cb5600             -push 0x56cb10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5688080 /*0x56cb10*/;
    cpu.esp -= 4;
    // 005339c1  e852b9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005339c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005339c8  740c                   -je 0x5339d6
    if (cpu.flags.zf)
    {
        goto L_0x005339d6;
    }
    // 005339ca  c705d0d45600ffffffff   -mov dword ptr [0x56d4d0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690576) /* 0x56d4d0 */) = 4294967295 /*0xffffffff*/;
    // 005339d4  eb32                   -jmp 0x533a08
    goto L_0x00533a08;
L_0x005339d6:
    // 005339d6  833dd0d45600ff         +cmp dword ptr [0x56d4d0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690576) /* 0x56d4d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005339dd  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 005339e2  7424                   -je 0x533a08
    if (cpu.flags.zf)
    {
        goto L_0x00533a08;
    }
    // 005339e4  ff752c                 -push dword ptr [ebp + 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    // 005339e7  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 005339ea  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 005339ed  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005339f0  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005339f3  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005339f6  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005339f9  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005339fc  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005339ff  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533a02  ff15d0d45600           -call dword ptr [0x56d4d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690576) /* 0x56d4d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533a08:
    // 00533a08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533a09  c22800                 -ret 0x28
    cpu.esp += 4+40 /*0x28*/;
    return;
}

/* align: skip  */
void Application::sub_533a0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a0c  ff2594455300           -jmp dword ptr [0x534594]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457300), cpu);
}

/* align: skip  */
void Application::sub_533a12(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a12  ff252c455300           -jmp dword ptr [0x53452c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457196), cpu);
}

/* align: skip  */
void Application::sub_533a18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a18  ff25d4445300           -jmp dword ptr [0x5344d4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457108), cpu);
}

/* align: skip  */
void Application::sub_533a1e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a1e  ff2500465300           -jmp dword ptr [0x534600]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457408), cpu);
}

/* align: skip  */
void Application::sub_533a24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a24  ff252c465300           -jmp dword ptr [0x53462c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457452), cpu);
}

/* align: skip  */
void Application::sub_533a2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a2a  ff2598455300           -jmp dword ptr [0x534598]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457304), cpu);
}

/* align: skip  */
void Application::sub_533a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a30  ff2548455300           -jmp dword ptr [0x534548]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457224), cpu);
}

/* align: skip  */
void Application::sub_533a36(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a36  ff2510465300           -jmp dword ptr [0x534610]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457424), cpu);
}

/* align: skip  */
void Application::sub_533a3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a3c  ff2518465300           -jmp dword ptr [0x534618]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457432), cpu);
}

/* align: skip  */
void Application::sub_533a42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a42  ff250c465300           -jmp dword ptr [0x53460c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457420), cpu);
}

/* align: skip  */
void Application::sub_533a48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a48  ff2514465300           -jmp dword ptr [0x534614]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457428), cpu);
}

/* align: skip  */
void Application::sub_533a4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a4e  ff255c455300           -jmp dword ptr [0x53455c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457244), cpu);
}

/* align: skip  */
void Application::sub_533a54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a54  ff25f8455300           -jmp dword ptr [0x5345f8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457400), cpu);
}

/* align: skip  */
void Application::sub_533a5a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a5a  ff2538465300           -jmp dword ptr [0x534638]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457464), cpu);
}

/* align: skip  */
void Application::sub_533a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a60  ff25c4455300           -jmp dword ptr [0x5345c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457348), cpu);
}

/* align: skip  */
void Application::sub_533a66(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a66  ff25f0445300           -jmp dword ptr [0x5344f0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457136), cpu);
}

/* align: skip  */
void Application::sub_533a6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a6c  ff25c8455300           -jmp dword ptr [0x5345c8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457352), cpu);
}

/* align: skip  */
void Application::sub_533a72(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a72  ff25e8445300           -jmp dword ptr [0x5344e8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457128), cpu);
}

/* align: skip  */
void Application::sub_533a78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a78  ff25bc445300           -jmp dword ptr [0x5344bc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457084), cpu);
}

/* align: skip  */
void Application::sub_533a7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a7e  ff25a8455300           -jmp dword ptr [0x5345a8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457320), cpu);
}

/* align: skip  */
void Application::sub_533a84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a84  ff2554455300           -jmp dword ptr [0x534554]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457236), cpu);
}

/* align: skip  */
void Application::sub_533a8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a8a  ff2548475300           -jmp dword ptr [0x534748]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457736), cpu);
}

/* align: skip  */
void Application::sub_533a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a90  ff256c455300           -jmp dword ptr [0x53456c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457260), cpu);
}

/* align: skip  */
void Application::sub_533a96(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a96  ff2538455300           -jmp dword ptr [0x534538]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457208), cpu);
}

/* align: skip  */
void Application::sub_533a9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a9c  ff2508455300           -jmp dword ptr [0x534508]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457160), cpu);
}

/* align: skip  */
void Application::sub_533aa2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533aa2  ff2534465300           -jmp dword ptr [0x534634]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457460), cpu);
}

/* align: skip  */
void Application::sub_533aa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533aa8  ff2560455300           -jmp dword ptr [0x534560]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457248), cpu);
}

/* align: skip  */
void Application::sub_533aae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533aae  ff25f8445300           -jmp dword ptr [0x5344f8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457144), cpu);
}

/* align: skip  */
void Application::sub_533ab4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ab4  ff25f4445300           -jmp dword ptr [0x5344f4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457140), cpu);
}

/* align: skip  */
void Application::sub_533aba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533aba  ff2574455300           -jmp dword ptr [0x534574]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457268), cpu);
}

/* align: skip  */
void Application::sub_533ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ac0  ff251c455300           -jmp dword ptr [0x53451c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457180), cpu);
}

/* align: skip  */
void Application::sub_533ac6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ac6  ff25ac475300           -jmp dword ptr [0x5347ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457836), cpu);
}

/* align: skip  */
void Application::sub_533acc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533acc  ff2544475300           -jmp dword ptr [0x534744]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457732), cpu);
}

/* align: skip  */
void Application::sub_533ad2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ad2  ff2570475300           -jmp dword ptr [0x534770]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457776), cpu);
}

/* align: skip  */
void Application::sub_533ad8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ad8  ff25ec445300           -jmp dword ptr [0x5344ec]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457132), cpu);
}

/* align: skip  */
void Application::sub_533ade(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ade  ff25b0475300           -jmp dword ptr [0x5347b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457840), cpu);
}

/* align: skip  */
void Application::sub_533ae4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ae4  ff2518455300           -jmp dword ptr [0x534518]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457176), cpu);
}

/* align: skip  */
void Application::sub_533aea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533aea  ff25a0445300           -jmp dword ptr [0x5344a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457056), cpu);
}

/* align: skip  */
void Application::sub_533af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533af0  ff25dc455300           -jmp dword ptr [0x5345dc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457372), cpu);
}

/* align: skip  */
void Application::sub_533af6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533af6  ff25d0455300           -jmp dword ptr [0x5345d0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457360), cpu);
}

/* align: skip  */
void Application::sub_533afc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533afc  ff25fc445300           -jmp dword ptr [0x5344fc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457148), cpu);
}

/* align: skip  */
void Application::sub_533b02(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b02  ff25ac455300           -jmp dword ptr [0x5345ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457324), cpu);
}

/* align: skip  */
void Application::sub_533b08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b08  ff25a0455300           -jmp dword ptr [0x5345a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457312), cpu);
}

/* align: skip  */
void Application::sub_533b0e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b0e  ff2520455300           -jmp dword ptr [0x534520]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457184), cpu);
}

/* align: skip  */
void Application::sub_533b14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b14  ff25b4455300           -jmp dword ptr [0x5345b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457332), cpu);
}

/* align: skip  */
void Application::sub_533b1a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b1a  ff2568445300           -jmp dword ptr [0x534468]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457000), cpu);
}

/* align: skip  */
void Application::sub_533b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b20  ff2598475300           -jmp dword ptr [0x534798]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457816), cpu);
}

/* align: skip  */
void Application::sub_533b26(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b26  ff25ac445300           -jmp dword ptr [0x5344ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457068), cpu);
}

/* align: skip  */
void Application::sub_533b2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b2c  ff2584455300           -jmp dword ptr [0x534584]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457284), cpu);
}

/* align: skip  */
void Application::sub_533b32(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b32  ff2590445300           -jmp dword ptr [0x534490]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457040), cpu);
}

/* align: skip  */
void Application::sub_533b38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b38  ff25d8455300           -jmp dword ptr [0x5345d8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457368), cpu);
}

/* align: skip  */
void Application::sub_533b3e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b3e  ff2520465300           -jmp dword ptr [0x534620]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457440), cpu);
}

/* align: skip  */
void Application::sub_533b44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b44  ff25f0455300           -jmp dword ptr [0x5345f0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457392), cpu);
}

/* align: skip  */
void Application::sub_533b4a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b4a  ff2540465300           -jmp dword ptr [0x534640]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457472), cpu);
}

/* align: skip  */
void Application::sub_533b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b50  ff25b0455300           -jmp dword ptr [0x5345b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457328), cpu);
}

/* align: skip  */
void Application::sub_533b56(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b56  ff2590455300           -jmp dword ptr [0x534590]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457296), cpu);
}

}
