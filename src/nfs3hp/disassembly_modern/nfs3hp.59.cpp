#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

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

/* align: skip  */
void Application::sub_533b5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b5c  ff259c445300           -jmp dword ptr [0x53449c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457052), cpu);
}

/* align: skip  */
void Application::sub_533b62(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b62  ff2524455300           -jmp dword ptr [0x534524]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457188), cpu);
}

/* align: skip  */
void Application::sub_533b68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b68  ff2598445300           -jmp dword ptr [0x534498]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457048), cpu);
}

/* align: skip  */
void Application::sub_533b6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b6e  ff2500455300           -jmp dword ptr [0x534500]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457152), cpu);
}

/* align: skip  */
void Application::sub_533b74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b74  ff25d4455300           -jmp dword ptr [0x5345d4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457364), cpu);
}

/* align: skip  */
void Application::sub_533b7a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b7a  ff2514455300           -jmp dword ptr [0x534514]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457172), cpu);
}

/* align: skip  */
void Application::sub_533b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b80  ff253c455300           -jmp dword ptr [0x53453c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457212), cpu);
}

/* align: skip  */
void Application::sub_533b86(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b86  ff2540455300           -jmp dword ptr [0x534540]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457216), cpu);
}

/* align: skip  */
void Application::sub_533b8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b8c  ff25f8465300           -jmp dword ptr [0x5346f8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457656), cpu);
}

/* align: skip  */
void Application::sub_533b92(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b92  ff2578455300           -jmp dword ptr [0x534578]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457272), cpu);
}

/* align: skip  */
void Application::sub_533b98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b98  ff2530455300           -jmp dword ptr [0x534530]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457200), cpu);
}

/* align: skip  */
void Application::sub_533b9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533b9e  ff25b0445300           -jmp dword ptr [0x5344b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457072), cpu);
}

/* align: skip  */
void Application::sub_533ba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ba4  ff2528465300           -jmp dword ptr [0x534628]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457448), cpu);
}

/* align: skip  */
void Application::sub_533baa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533baa  ff2524465300           -jmp dword ptr [0x534624]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457444), cpu);
}

/* align: skip  */
void Application::sub_533bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bb0  ff25f4455300           -jmp dword ptr [0x5345f4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457396), cpu);
}

/* align: skip  */
void Application::sub_533bb6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bb6  ff25a4455300           -jmp dword ptr [0x5345a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457316), cpu);
}

/* align: skip  */
void Application::sub_533bbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bbc  ff25b8455300           -jmp dword ptr [0x5345b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457336), cpu);
}

/* align: skip  */
void Application::sub_533bc2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bc2  ff25e8455300           -jmp dword ptr [0x5345e8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457384), cpu);
}

/* align: skip  */
void Application::sub_533bc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bc8  ff25c4445300           -jmp dword ptr [0x5344c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457092), cpu);
}

/* align: skip  */
void Application::sub_533bce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bce  ff25fc455300           -jmp dword ptr [0x5345fc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457404), cpu);
}

/* align: skip  */
void Application::sub_533bd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bd4  ff2564455300           -jmp dword ptr [0x534564]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457252), cpu);
}

/* align: skip  */
void Application::sub_533bda(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bda  ff2508465300           -jmp dword ptr [0x534608]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457416), cpu);
}

/* align: skip  */
void Application::sub_533be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533be0  ff2504465300           -jmp dword ptr [0x534604]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457412), cpu);
}

/* align: skip  */
void Application::sub_533be6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533be6  ff25bc455300           -jmp dword ptr [0x5345bc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457340), cpu);
}

/* align: skip  */
void Application::sub_533bec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bec  ff25a4445300           -jmp dword ptr [0x5344a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457060), cpu);
}

/* align: skip  */
void Application::sub_533bf2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bf2  ff25b4445300           -jmp dword ptr [0x5344b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457076), cpu);
}

/* align: skip  */
void Application::sub_533bf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bf8  ff2510455300           -jmp dword ptr [0x534510]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457168), cpu);
}

/* align: skip  */
void Application::sub_533bfe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533bfe  ff2504455300           -jmp dword ptr [0x534504]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457156), cpu);
}

/* align: skip  */
void Application::sub_533c04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533c04  ff250c455300           -jmp dword ptr [0x53450c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457164), cpu);
}

/* align: skip  */
void Application::sub_533c0a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533c0a  ff2530465300           -jmp dword ptr [0x534630]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457456), cpu);
}

/* align: skip  */
void Application::sub_533c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533c10  ff258c475300           -jmp dword ptr [0x53478c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457804), cpu);
}

/* align: skip  */
void Application::sub_533c16(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533c16  ff2558475300           -jmp dword ptr [0x534758]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457752), cpu);
}

/* align: skip  */
void Application::sub_533c1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533c1c  ff2574475300           -jmp dword ptr [0x534774]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457780), cpu);
}

/* align: skip  */
void Application::sub_533c22(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533c22  ff255c445300           -jmp dword ptr [0x53445c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5456988), cpu);
}

/* align: skip  */
void Application::sub_533c28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533c28  ff2560475300           -jmp dword ptr [0x534760]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457760), cpu);
}

/* align: skip  */
void Application::sub_533c2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533c2e  ff255c475300           -jmp dword ptr [0x53475c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457756), cpu);
}

}
