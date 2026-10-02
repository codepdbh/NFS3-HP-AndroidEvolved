#include "eacsnd.h"
#include <lib/thread.h>

namespace eacsnd
{

/* align: skip  */
void sub_a590b3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a590b3;
    // 00a59093  83fb01                 +cmp ebx, 1
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
    // 00a59096  7411                   -je 0xa590a9
    if (cpu.flags.zf)
    {
        goto L_0x00a590a9;
    }
    // 00a59098  e92affffff             -jmp 0xa58fc7
    return sub_a58fc7(app, cpu);
    // 00a5909d  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 00a590a2  e829ffffff             -call 0xa58fd0
    cpu.esp -= 4;
    sub_a58fd0(app, cpu);
    if (cpu.terminate) return;
    // 00a590a7  eb37                   -jmp 0xa590e0
    goto L_0x00a590e0;
L_0x00a590a9:
    // 00a590a9  83f802                 +cmp eax, 2
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
    // 00a590ac  7505                   -jne 0xa590b3
    if (!cpu.flags.zf)
    {
        goto L_0x00a590b3;
    }
    // 00a590ae  e88e050000             -call 0xa59641
    cpu.esp -= 4;
    sub_a59641(app, cpu);
    if (cpu.terminate) return;
L_0x00a590b3:
L_entry_0x00a590b3:
    // 00a590b3  83f901                 +cmp ecx, 1
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
    // 00a590b6  741a                   -je 0xa590d2
    if (cpu.flags.zf)
    {
        goto L_0x00a590d2;
    }
    // 00a590b8  83f902                 +cmp ecx, 2
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
    // 00a590bb  7415                   -je 0xa590d2
    if (cpu.flags.zf)
    {
        goto L_0x00a590d2;
    }
    // 00a590bd  83f903                 +cmp ecx, 3
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
    // 00a590c0  7410                   -je 0xa590d2
    if (cpu.flags.zf)
    {
        goto L_0x00a590d2;
    }
    // 00a590c2  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a590c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a590c9  e838fdffff             -call 0xa58e06
    cpu.esp -= 4;
    sub_a58e06(app, cpu);
    if (cpu.terminate) return;
    // 00a590ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a590d0  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a590d2:
    // 00a590d2  e82afeffff             -call 0xa58f01
    cpu.esp -= 4;
    sub_a58f01(app, cpu);
    if (cpu.terminate) return;
    // 00a590d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a590d9  7505                   -jne 0xa590e0
    if (!cpu.flags.zf)
    {
        goto L_0x00a590e0;
    }
    // 00a590db  e885feffff             -call 0xa58f65
    cpu.esp -= 4;
    sub_a58f65(app, cpu);
    if (cpu.terminate) return;
L_0x00a590e0:
    // 00a590e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a590e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a590e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a590e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a590e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5909d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a5909d;
    // 00a59093  83fb01                 +cmp ebx, 1
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
    // 00a59096  7411                   -je 0xa590a9
    if (cpu.flags.zf)
    {
        goto L_0x00a590a9;
    }
    // 00a59098  e92affffff             -jmp 0xa58fc7
    return sub_a58fc7(app, cpu);
L_entry_0x00a5909d:
    // 00a5909d  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 00a590a2  e829ffffff             -call 0xa58fd0
    cpu.esp -= 4;
    sub_a58fd0(app, cpu);
    if (cpu.terminate) return;
    // 00a590a7  eb37                   -jmp 0xa590e0
    goto L_0x00a590e0;
L_0x00a590a9:
    // 00a590a9  83f802                 +cmp eax, 2
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
    // 00a590ac  7505                   -jne 0xa590b3
    if (!cpu.flags.zf)
    {
        goto L_0x00a590b3;
    }
    // 00a590ae  e88e050000             -call 0xa59641
    cpu.esp -= 4;
    sub_a59641(app, cpu);
    if (cpu.terminate) return;
L_0x00a590b3:
    // 00a590b3  83f901                 +cmp ecx, 1
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
    // 00a590b6  741a                   -je 0xa590d2
    if (cpu.flags.zf)
    {
        goto L_0x00a590d2;
    }
    // 00a590b8  83f902                 +cmp ecx, 2
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
    // 00a590bb  7415                   -je 0xa590d2
    if (cpu.flags.zf)
    {
        goto L_0x00a590d2;
    }
    // 00a590bd  83f903                 +cmp ecx, 3
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
    // 00a590c0  7410                   -je 0xa590d2
    if (cpu.flags.zf)
    {
        goto L_0x00a590d2;
    }
    // 00a590c2  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a590c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a590c9  e838fdffff             -call 0xa58e06
    cpu.esp -= 4;
    sub_a58e06(app, cpu);
    if (cpu.terminate) return;
    // 00a590ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a590d0  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a590d2:
    // 00a590d2  e82afeffff             -call 0xa58f01
    cpu.esp -= 4;
    sub_a58f01(app, cpu);
    if (cpu.terminate) return;
    // 00a590d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a590d9  7505                   -jne 0xa590e0
    if (!cpu.flags.zf)
    {
        goto L_0x00a590e0;
    }
    // 00a590db  e885feffff             -call 0xa58f65
    cpu.esp -= 4;
    sub_a58f65(app, cpu);
    if (cpu.terminate) return;
L_0x00a590e0:
    // 00a590e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a590e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a590e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a590e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a590e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a590e6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a590e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a590e7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a590e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a590e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a590ea  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a590eb  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
L_0x00a590f0:
    // 00a590f0  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a590f6  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00a590f9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a590fb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a590fd  8d7e58                 -lea edi, [esi + 0x58]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00a59100  8db250dea500           -lea esi, [edx + 0xa5de50]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(10870352) /* 0xa5de50 */);
    // 00a59106  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a59109  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a5910a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a5910b  83fa68                 +cmp edx, 0x68
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
    // 00a5910e  75e0                   -jne 0xa590f0
    if (!cpu.flags.zf)
    {
        goto L_0x00a590f0;
    }
    // 00a59110  ba868ea500             -mov edx, 0xa58e86
    cpu.edx = 10849926 /*0xa58e86*/;
    // 00a59115  bba38fa500             -mov ebx, 0xa58fa3
    cpu.ebx = 10850211 /*0xa58fa3*/;
    // 00a5911a  89151cdea500           -mov dword ptr [0xa5de1c], edx
    app->getMemory<x86::reg32>(x86::reg32(10870300) /* 0xa5de1c */) = cpu.edx;
    // 00a59120  891d20dea500           -mov dword ptr [0xa5de20], ebx
    app->getMemory<x86::reg32>(x86::reg32(10870304) /* 0xa5de20 */) = cpu.ebx;
    // 00a59126  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a59127  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59128  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59129  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5912a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5912b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5912c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5912c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5912d  e8cffdffff             -call 0xa58f01
    cpu.esp -= 4;
    sub_a58f01(app, cpu);
    if (cpu.terminate) return;
    // 00a59132  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59134  7423                   -je 0xa59159
    if (cpu.flags.zf)
    {
        goto L_0x00a59159;
    }
    // 00a59136  e82afeffff             -call 0xa58f65
    cpu.esp -= 4;
    sub_a58f65(app, cpu);
    if (cpu.terminate) return;
    // 00a5913b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a59140  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a59145  e8bcfcffff             -call 0xa58e06
    cpu.esp -= 4;
    sub_a58e06(app, cpu);
    if (cpu.terminate) return;
    // 00a5914a  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a5914f  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a59154  e8adfcffff             -call 0xa58e06
    cpu.esp -= 4;
    sub_a58e06(app, cpu);
    if (cpu.terminate) return;
L_0x00a59159:
    // 00a59159  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5915a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5915b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5915b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5915c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5915d  bae690a500             -mov edx, 0xa590e6
    cpu.edx = 10850534 /*0xa590e6*/;
    // 00a59162  bb2c91a500             -mov ebx, 0xa5912c
    cpu.ebx = 10850604 /*0xa5912c*/;
    // 00a59167  8915a4dca500           -mov dword ptr [0xa5dca4], edx
    app->getMemory<x86::reg32>(x86::reg32(10869924) /* 0xa5dca4 */) = cpu.edx;
    // 00a5916d  891da8dca500           -mov dword ptr [0xa5dca8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10869928) /* 0xa5dca8 */) = cpu.ebx;
    // 00a59173  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59174  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59175  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a59180(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59180  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59181  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59182  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59183  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a59184  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a59186  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59188  0f849a000000           -je 0xa59228
    if (cpu.flags.zf)
    {
        goto L_0x00a59228;
    }
    // 00a5918e  8d480b                 -lea ecx, [eax + 0xb]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00a59191  39c1                   +cmp ecx, eax
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
    // 00a59193  0f828f000000           -jb 0xa59228
    if (cpu.flags.cf)
    {
        goto L_0x00a59228;
    }
    // 00a59199  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a5919b  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a5919e  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00a591a1  83f910                 +cmp ecx, 0x10
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
    // 00a591a4  7305                   -jae 0xa591ab
    if (!cpu.flags.cf)
    {
        goto L_0x00a591ab;
    }
    // 00a591a6  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x00a591ab:
    // 00a591ab  39c1                   +cmp ecx, eax
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
    // 00a591ad  0f8775000000           -ja 0xa59228
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a59228;
    }
    // 00a591b3  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00a591b6  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00a591b9  39d9                   +cmp ecx, ebx
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
    // 00a591bb  7705                   -ja 0xa591c2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a591c2;
    }
    // 00a591bd  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00a591c0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a591c2:
    // 00a591c2  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00a591c5:
    // 00a591c5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a591c7  39d1                   +cmp ecx, edx
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
    // 00a591c9  7612                   -jbe 0xa591dd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a591dd;
    }
    // 00a591cb  39da                   +cmp edx, ebx
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
    // 00a591cd  7602                   -jbe 0xa591d1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a591d1;
    }
    // 00a591cf  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00a591d1:
    // 00a591d1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a591d4  39f0                   +cmp eax, esi
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
    // 00a591d6  75ed                   -jne 0xa591c5
    if (!cpu.flags.zf)
    {
        goto L_0x00a591c5;
    }
    // 00a591d8  895f14                 -mov dword ptr [edi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00a591db  eb4b                   -jmp 0xa59228
    goto L_0x00a59228;
L_0x00a591dd:
    // 00a591dd  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a591e0  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00a591e3  43                     -inc ebx
    (cpu.ebx)++;
    // 00a591e4  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a591e6  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a591e9  83fa10                 +cmp edx, 0x10
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
    // 00a591ec  721e                   -jb 0xa5920c
    if (cpu.flags.cf)
    {
        goto L_0x00a5920c;
    }
    // 00a591ee  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00a591f1  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a591f4  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a591f6  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00a591f8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a591fb  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a591fe  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a59201  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a59204  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a59207  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a5920a  eb12                   -jmp 0xa5921e
    goto L_0x00a5921e;
L_0x00a5920c:
    // 00a5920c  ff4f1c                 -dec dword ptr [edi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))--;
    // 00a5920f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a59212  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a59215  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a59218  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a5921b  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00a5921e:
    // 00a5921e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a59220  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a59223  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a59226  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a59228:
    // 00a59228  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a5922a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5922b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5922c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5922d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5922e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a59230(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59230  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59231  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59232  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59233  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a59234  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a59236  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59238  0f841d010000           -je 0xa5935b
    if (cpu.flags.zf)
    {
        goto L_0x00a5935b;
    }
    // 00a5923e  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a59241  f60301                 +test byte ptr [ebx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx) & 1 /*0x1*/));
    // 00a59244  0f8411010000           -je 0xa5935b
    if (cpu.flags.zf)
    {
        goto L_0x00a5935b;
    }
    // 00a5924a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a5924c  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a5924f  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00a59252  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a59254  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00a59257  7522                   -jne 0xa5927b
    if (!cpu.flags.zf)
    {
        goto L_0x00a5927b;
    }
    // 00a59259  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a5925b  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a5925d  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a5925f  3b410c                 +cmp eax, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59262  7503                   -jne 0xa59267
    if (!cpu.flags.zf)
    {
        goto L_0x00a59267;
    }
    // 00a59264  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x00a59267:
    // 00a59267  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a5926a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a5926d  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a59270  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a59273  ff4e1c                 +dec dword ptr [esi + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a59276  e994000000             -jmp 0xa5930f
    goto L_0x00a5930f;
L_0x00a5927b:
    // 00a5927b  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a5927d  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a59280  39c3                   +cmp ebx, eax
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
    // 00a59282  7316                   -jae 0xa5929a
    if (!cpu.flags.cf)
    {
        goto L_0x00a5929a;
    }
    // 00a59284  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 00a59287  0f8782000000           -ja 0xa5930f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a5930f;
    }
    // 00a5928d  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00a59290  39c3                   +cmp ebx, eax
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
    // 00a59292  0f8277000000           -jb 0xa5930f
    if (cpu.flags.cf)
    {
        goto L_0x00a5930f;
    }
    // 00a59298  eb19                   -jmp 0xa592b3
    goto L_0x00a592b3;
L_0x00a5929a:
    // 00a5929a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a5929d  39c3                   +cmp ebx, eax
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
    // 00a5929f  0f826a000000           -jb 0xa5930f
    if (cpu.flags.cf)
    {
        goto L_0x00a5930f;
    }
    // 00a592a5  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a592a8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a592ab  39d3                   +cmp ebx, edx
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
    // 00a592ad  0f875c000000           -ja 0xa5930f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a5930f;
    }
L_0x00a592b3:
    // 00a592b3  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00a592b6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a592b9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a592bb  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a592be  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a592c0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a592c2  39f8                   +cmp eax, edi
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
    // 00a592c4  7328                   -jae 0xa592ee
    if (!cpu.flags.cf)
    {
        goto L_0x00a592ee;
    }
    // 00a592c6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a592c9  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a592cb  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a592cd  39f8                   +cmp eax, edi
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
    // 00a592cf  7705                   -ja 0xa592d6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a592d6;
    }
    // 00a592d1  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x00a592d6:
    // 00a592d6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a592d8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a592da:
    // 00a592da  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a592dc  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00a592df  742e                   -je 0xa5930f
    if (cpu.flags.zf)
    {
        goto L_0x00a5930f;
    }
    // 00a592e1  83faff                 +cmp edx, -1
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
    // 00a592e4  7408                   -je 0xa592ee
    if (cpu.flags.zf)
    {
        goto L_0x00a592ee;
    }
    // 00a592e6  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a592e9  01d0                   +add eax, edx
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
    // 00a592eb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a592ec  75ec                   -jne 0xa592da
    if (!cpu.flags.zf)
    {
        goto L_0x00a592da;
    }
L_0x00a592ee:
    // 00a592ee  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a592f1  39c3                   +cmp ebx, eax
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
    // 00a592f3  7303                   -jae 0xa592f8
    if (!cpu.flags.cf)
    {
        goto L_0x00a592f8;
    }
    // 00a592f5  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x00a592f8:
    // 00a592f8  39c3                   +cmp ebx, eax
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
    // 00a592fa  7213                   -jb 0xa5930f
    if (cpu.flags.cf)
    {
        goto L_0x00a5930f;
    }
    // 00a592fc  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a592ff  39c3                   +cmp ebx, eax
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
    // 00a59301  720c                   -jb 0xa5930f
    if (cpu.flags.cf)
    {
        goto L_0x00a5930f;
    }
    // 00a59303  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a59306  39c3                   +cmp ebx, eax
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
    // 00a59308  7205                   -jb 0xa5930f
    if (cpu.flags.cf)
    {
        goto L_0x00a5930f;
    }
    // 00a5930a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a5930d  ebe9                   -jmp 0xa592f8
    goto L_0x00a592f8;
L_0x00a5930f:
    // 00a5930f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a59312  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a59314  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a59316  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a59318  39df                   +cmp edi, ebx
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
    // 00a5931a  7512                   -jne 0xa5932e
    if (!cpu.flags.zf)
    {
        goto L_0x00a5932e;
    }
    // 00a5931c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a5931e  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a59320  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a59322  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59325  7503                   -jne 0xa5932a
    if (!cpu.flags.zf)
    {
        goto L_0x00a5932a;
    }
    // 00a59327  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00a5932a:
    // 00a5932a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a5932c  eb0f                   -jmp 0xa5933d
    goto L_0x00a5933d;
L_0x00a5932e:
    // 00a5932e  ff461c                 -inc dword ptr [esi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))++;
    // 00a59331  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a59334  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a59337  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a5933a  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00a5933d:
    // 00a5933d  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a59340  4a                     -dec edx
    (cpu.edx)--;
    // 00a59341  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a59344  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a59347  39fb                   +cmp ebx, edi
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
    // 00a59349  7308                   -jae 0xa59353
    if (!cpu.flags.cf)
    {
        goto L_0x00a59353;
    }
    // 00a5934b  3b4e10                 +cmp ecx, dword ptr [esi + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5934e  7603                   -jbe 0xa59353
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a59353;
    }
    // 00a59350  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x00a59353:
    // 00a59353  3b4e14                 +cmp ecx, dword ptr [esi + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59356  7603                   -jbe 0xa5935b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a5935b;
    }
    // 00a59358  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a5935b:
    // 00a5935b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5935c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5935d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5935e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5935f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59360(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59361  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59362  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59364  a138dea500             -mov eax, dword ptr [0xa5de38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870328) /* 0xa5de38 */);
    // 00a59369  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a5936b  eb09                   -jmp 0xa59376
    goto L_0x00a59376;
L_0x00a5936d:
    // 00a5936d  39c2                   +cmp edx, eax
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
    // 00a5936f  7209                   -jb 0xa5937a
    if (cpu.flags.cf)
    {
        goto L_0x00a5937a;
    }
    // 00a59371  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a59373  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x00a59376:
    // 00a59376  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59378  75f3                   -jne 0xa5936d
    if (!cpu.flags.zf)
    {
        goto L_0x00a5936d;
    }
L_0x00a5937a:
    // 00a5937a  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a5937d  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a59380  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a59382  7405                   -je 0xa59389
    if (cpu.flags.zf)
    {
        goto L_0x00a59389;
    }
    // 00a59384  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a59387  eb06                   -jmp 0xa5938f
    goto L_0x00a5938f;
L_0x00a59389:
    // 00a59389  891538dea500           -mov dword ptr [0xa5de38], edx
    app->getMemory<x86::reg32>(x86::reg32(10870328) /* 0xa5de38 */) = cpu.edx;
L_0x00a5938f:
    // 00a5938f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59391  7403                   -je 0xa59396
    if (cpu.flags.zf)
    {
        goto L_0x00a59396;
    }
    // 00a59393  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00a59396:
    // 00a59396  8d5a20                 -lea ebx, [edx + 0x20]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00a59399  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a5939b  83c22c                 -add edx, 0x2c
    (cpu.edx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a5939e  c742f400000000         -mov dword ptr [edx - 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = 0 /*0x0*/;
    // 00a593a5  c742e400000000         -mov dword ptr [edx - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 00a593ac  c742ec00000000         -mov dword ptr [edx - 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 00a593b3  c742f000000000         -mov dword ptr [edx - 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = 0 /*0x0*/;
    // 00a593ba  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00a593bd  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00a593c0  83e82c                 -sub eax, 0x2c
    (cpu.eax) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a593c3  895ae0                 -mov dword ptr [edx - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a593c6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a593c8  c70402ffffffff         -mov dword ptr [edx + eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 4294967295 /*0xffffffff*/;
    // 00a593cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a593d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a593d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a593d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a593d4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a593d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a593d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a593d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a593d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a593d8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a593d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a593da  833d10dfa50000         +cmp dword ptr [0xa5df10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10870544) /* 0xa5df10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a593e1  7507                   -jne 0xa593ea
    if (!cpu.flags.zf)
    {
        goto L_0x00a593ea;
    }
L_0x00a593e3:
    // 00a593e3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a593e5  e973000000             -jmp 0xa5945d
    goto L_0x00a5945d;
L_0x00a593ea:
    // 00a593ea  833dd8daa500fe         +cmp dword ptr [0xa5dad8], -2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10869464) /* 0xa5dad8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a593f1  74f0                   -je 0xa593e3
    if (cpu.flags.zf)
    {
        goto L_0x00a593e3;
    }
    // 00a593f3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a593f5  e87d000000             -call 0xa59477
    cpu.esp -= 4;
    sub_a59477(app, cpu);
    if (cpu.terminate) return;
    // 00a593fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a593fc  745f                   -je 0xa5945d
    if (cpu.flags.zf)
    {
        goto L_0x00a5945d;
    }
    // 00a593fe  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00a59400  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00a59405  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a59409  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5940a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a5940c  2eff15c4b9a500         -call dword ptr cs:[0xa5b9c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860996) /* 0xa5b9c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59413  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59415  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59417  7444                   -je 0xa5945d
    if (cpu.flags.zf)
    {
        goto L_0x00a5945d;
    }
    // 00a59419  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a5941c  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a5941f  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a59422  39f0                   +cmp eax, esi
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
    // 00a59424  77bd                   -ja 0xa593e3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a593e3;
    }
    // 00a59426  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a59429  83f838                 +cmp eax, 0x38
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5942c  72b5                   -jb 0xa593e3
    if (cpu.flags.cf)
    {
        goto L_0x00a593e3;
    }
    // 00a5942e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a59430  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a59432  e829ffffff             -call 0xa59360
    cpu.esp -= 4;
    sub_a59360(app, cpu);
    if (cpu.terminate) return;
    // 00a59437  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a59439  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a5943b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a5943e  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a59440  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a59442  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00a59445  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a5944c  47                     -inc edi
    (cpu.edi)++;
    // 00a5944d  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a59450  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00a59453  e8a5f2ffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a59458  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a5945d:
    // 00a5945d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a59460  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59461  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59462  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59463  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59464  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59465  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59466(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59466  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59467  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59469  e853020000             -call 0xa596c1
    cpu.esp -= 4;
    sub_a596c1(app, cpu);
    if (cpu.terminate) return;
    // 00a5946e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a59470  e85fffffff             -call 0xa593d4
    cpu.esp -= 4;
    sub_a593d4(app, cpu);
    if (cpu.terminate) return;
    // 00a59475  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59476  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59477(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59477  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59478  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59479  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5947b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a5947d  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a59480  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a59482  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59484  7438                   -je 0xa594be
    if (cpu.flags.zf)
    {
        goto L_0x00a594be;
    }
    // 00a59486  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a59488  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a5948b  3b02                   +cmp eax, dword ptr [edx]
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
    // 00a5948d  7305                   -jae 0xa59494
    if (!cpu.flags.cf)
    {
        goto L_0x00a59494;
    }
L_0x00a5948f:
    // 00a5948f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59491  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59492  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59493  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a59494:
    // 00a59494  8b0d14dfa500           -mov ecx, dword ptr [0xa5df14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10870548) /* 0xa5df14 */);
    // 00a5949a  39c8                   +cmp eax, ecx
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
    // 00a5949c  7304                   -jae 0xa594a2
    if (!cpu.flags.cf)
    {
        goto L_0x00a594a2;
    }
    // 00a5949e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a594a0  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00a594a2:
    // 00a594a2  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a594a4  05ff0f0000             -add eax, 0xfff
    (cpu.eax) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00a594a9  3b02                   +cmp eax, dword ptr [edx]
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
    // 00a594ab  72e2                   -jb 0xa5948f
    if (cpu.flags.cf)
    {
        goto L_0x00a5948f;
    }
    // 00a594ad  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00a594af  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00a594b2  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a594b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a594b6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a594b9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00a594be:
    // 00a594be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a594bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a594c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a594c1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a594c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a594c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a594c4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a594c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a594c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a594c7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a594c7  ff1500dfa500           -call dword ptr [0xa5df00]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870528) /* 0xa5df00 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a594cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a594ce(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a594ce  ff1504dfa500           -call dword ptr [0xa5df04]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870532) /* 0xa5df04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a594d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a594d5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a594d5  ff1508dfa500           -call dword ptr [0xa5df08]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870536) /* 0xa5df08 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a594db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a594dc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a594dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a594dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a594de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a594e0  7410                   -je 0xa594f2
    if (cpu.flags.zf)
    {
        goto L_0x00a594f2;
    }
    // 00a594e2  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a594e4  8b3500dfa500           -mov esi, dword ptr [0xa5df00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10870528) /* 0xa5df00 */);
    // 00a594ea  890d00dfa500           -mov dword ptr [0xa5df00], ecx
    app->getMemory<x86::reg32>(x86::reg32(10870528) /* 0xa5df00 */) = cpu.ecx;
    // 00a594f0  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x00a594f2:
    // 00a594f2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a594f4  740f                   -je 0xa59505
    if (cpu.flags.zf)
    {
        goto L_0x00a59505;
    }
    // 00a594f6  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a594f8  8b0d04dfa500           -mov ecx, dword ptr [0xa5df04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10870532) /* 0xa5df04 */);
    // 00a594fe  a304dfa500             -mov dword ptr [0xa5df04], eax
    app->getMemory<x86::reg32>(x86::reg32(10870532) /* 0xa5df04 */) = cpu.eax;
    // 00a59503  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x00a59505:
    // 00a59505  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a59507  740f                   -je 0xa59518
    if (cpu.flags.zf)
    {
        goto L_0x00a59518;
    }
    // 00a59509  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a5950b  8b1508dfa500           -mov edx, dword ptr [0xa5df08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10870536) /* 0xa5df08 */);
    // 00a59511  a308dfa500             -mov dword ptr [0xa5df08], eax
    app->getMemory<x86::reg32>(x86::reg32(10870536) /* 0xa5df08 */) = cpu.eax;
    // 00a59516  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x00a59518:
    // 00a59518  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59519  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5951a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5951b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5951b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5951c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5951d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5951e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5951f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59520  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a59521  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a59524  b854d0a500             -mov eax, 0xa5d054
    cpu.eax = 10866772 /*0xa5d054*/;
    // 00a59529  e806040000             -call 0xa59934
    cpu.esp -= 4;
    sub_a59934(app, cpu);
    if (cpu.terminate) return;
    // 00a5952e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a59530  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59532  0f84f9000000           -je 0xa59631
    if (cpu.flags.zf)
    {
        goto L_0x00a59631;
    }
L_0x00a59538:
    // 00a59538  803900                 +cmp byte ptr [ecx], 0
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
    // 00a5953b  0f84e6000000           -je 0xa59627
    if (cpu.flags.zf)
    {
        goto L_0x00a59627;
    }
    // 00a59541  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00a59543  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00a59545:
    // 00a59545  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a59547  3ac2                   +cmp al, dl
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
    // 00a59549  7412                   -je 0xa5955d
    if (cpu.flags.zf)
    {
        goto L_0x00a5955d;
    }
    // 00a5954b  3c00                   +cmp al, 0
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
    // 00a5954d  740c                   -je 0xa5955b
    if (cpu.flags.zf)
    {
        goto L_0x00a5955b;
    }
    // 00a5954f  46                     -inc esi
    (cpu.esi)++;
    // 00a59550  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a59552  3ac2                   +cmp al, dl
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
    // 00a59554  7407                   -je 0xa5955d
    if (cpu.flags.zf)
    {
        goto L_0x00a5955d;
    }
    // 00a59556  46                     -inc esi
    (cpu.esi)++;
    // 00a59557  3c00                   +cmp al, 0
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
    // 00a59559  75ea                   -jne 0xa59545
    if (!cpu.flags.zf)
    {
        goto L_0x00a59545;
    }
L_0x00a5955b:
    // 00a5955b  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a5955d:
    // 00a5955d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a5955f  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a59561  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a59563  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a59565  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a59567  e822040000             -call 0xa5998e
    cpu.esp -= 4;
    sub_a5998e(app, cpu);
    if (cpu.terminate) return;
    // 00a5956c  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a59571  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a59573  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a59575  881434                 -mov byte ptr [esp + esi], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 00a59578  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5957a  e87d050000             -call 0xa59afc
    cpu.esp -= 4;
    sub_a59afc(app, cpu);
    if (cpu.terminate) return;
    // 00a5957f  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a59582  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00a59584  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a59586  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a59588:
    // 00a59588  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a5958a  3ac2                   +cmp al, dl
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
    // 00a5958c  7412                   -je 0xa595a0
    if (cpu.flags.zf)
    {
        goto L_0x00a595a0;
    }
    // 00a5958e  3c00                   +cmp al, 0
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
    // 00a59590  740c                   -je 0xa5959e
    if (cpu.flags.zf)
    {
        goto L_0x00a5959e;
    }
    // 00a59592  46                     -inc esi
    (cpu.esi)++;
    // 00a59593  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a59595  3ac2                   +cmp al, dl
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
    // 00a59597  7407                   -je 0xa595a0
    if (cpu.flags.zf)
    {
        goto L_0x00a595a0;
    }
    // 00a59599  46                     -inc esi
    (cpu.esi)++;
    // 00a5959a  3c00                   +cmp al, 0
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
    // 00a5959c  75ea                   -jne 0xa59588
    if (!cpu.flags.zf)
    {
        goto L_0x00a59588;
    }
L_0x00a5959e:
    // 00a5959e  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a595a0:
    // 00a595a0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a595a2  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a595a4  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a595a6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a595a8  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a595aa  e8df030000             -call 0xa5998e
    cpu.esp -= 4;
    sub_a5998e(app, cpu);
    if (cpu.terminate) return;
    // 00a595af  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a595b4  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a595b6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a595b8  883434                 -mov byte ptr [esp + esi], dh
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 00a595bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a595bd  e83a050000             -call 0xa59afc
    cpu.esp -= 4;
    sub_a59afc(app, cpu);
    if (cpu.terminate) return;
    // 00a595c2  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a595c5  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 00a595c7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a595cb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a595cd:
    // 00a595cd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a595cf  3ac2                   +cmp al, dl
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
    // 00a595d1  7412                   -je 0xa595e5
    if (cpu.flags.zf)
    {
        goto L_0x00a595e5;
    }
    // 00a595d3  3c00                   +cmp al, 0
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
    // 00a595d5  740c                   -je 0xa595e3
    if (cpu.flags.zf)
    {
        goto L_0x00a595e3;
    }
    // 00a595d7  46                     -inc esi
    (cpu.esi)++;
    // 00a595d8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a595da  3ac2                   +cmp al, dl
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
    // 00a595dc  7407                   -je 0xa595e5
    if (cpu.flags.zf)
    {
        goto L_0x00a595e5;
    }
    // 00a595de  46                     -inc esi
    (cpu.esi)++;
    // 00a595df  3c00                   +cmp al, 0
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
    // 00a595e1  75ea                   -jne 0xa595cd
    if (!cpu.flags.zf)
    {
        goto L_0x00a595cd;
    }
L_0x00a595e3:
    // 00a595e3  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a595e5:
    // 00a595e5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a595e7  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a595e9  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a595eb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a595ed  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a595ef  e89a030000             -call 0xa5998e
    cpu.esp -= 4;
    sub_a5998e(app, cpu);
    if (cpu.terminate) return;
    // 00a595f4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a595f6  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a595f8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a595fa  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 00a595fd  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a59602  e8f5040000             -call 0xa59afc
    cpu.esp -= 4;
    sub_a59afc(app, cpu);
    if (cpu.terminate) return;
    // 00a59607  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a59609  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a5960b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a5960f  e8d2ddffff             -call 0xa573e6
    cpu.esp -= 4;
    sub_a573e6(app, cpu);
    if (cpu.terminate) return;
    // 00a59614  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a59616  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a59618  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a5961b  e8a2e3ffff             -call 0xa579c2
    cpu.esp -= 4;
    sub_a579c2(app, cpu);
    if (cpu.terminate) return;
    // 00a59620  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a59622  e911ffffff             -jmp 0xa59538
    goto L_0x00a59538;
L_0x00a59627:
    // 00a59627  b860d0a500             -mov eax, 0xa5d060
    cpu.eax = 10866784 /*0xa5d060*/;
    // 00a5962c  e824050000             -call 0xa59b55
    cpu.esp -= 4;
    sub_a59b55(app, cpu);
    if (cpu.terminate) return;
L_0x00a59631:
    // 00a59631  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a59634  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59635  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59636  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59637  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59638  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59639  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5963a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5963b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5963b  ff150cdfa500           -call dword ptr [0xa5df0c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870540) /* 0xa5df0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59641  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59642  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a59647  b870d0a500             -mov eax, 0xa5d070
    cpu.eax = 10866800 /*0xa5d070*/;
    // 00a5964c  e8d5ceffff             -call 0xa56526
    cpu.esp -= 4;
    sub_a56526(app, cpu);
    if (cpu.terminate) return;
    // 00a59651  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59652  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59641(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a59641;
    // 00a5963b  ff150cdfa500           -call dword ptr [0xa5df0c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870540) /* 0xa5df0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x00a59641:
    // 00a59641  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59642  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a59647  b870d0a500             -mov eax, 0xa5d070
    cpu.eax = 10866800 /*0xa5d070*/;
    // 00a5964c  e8d5ceffff             -call 0xa56526
    cpu.esp -= 4;
    sub_a56526(app, cpu);
    if (cpu.terminate) return;
    // 00a59651  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59652  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59653(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59653  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59654  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59655  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59656  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59657  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5965a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a5965c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a5965e  8a25d0daa500           -mov ah, byte ptr [0xa5dad0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(10869456) /* 0xa5dad0 */);
    // 00a59664  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00a59667  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a59669  7426                   -je 0xa59691
    if (cpu.flags.zf)
    {
        goto L_0x00a59691;
    }
    // 00a5966b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a5966d  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 00a59670  9b                     -wait 
    /*nothing*/;
    // 00a59671  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a59673  741c                   -je 0xa59691
    if (cpu.flags.zf)
    {
        goto L_0x00a59691;
    }
    // 00a59675  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a59677  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a5967a  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00a5967c  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a5967e  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 00a59680  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a59682  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a59684  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a59687  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 00a5968a  9b                     -wait 
    /*nothing*/;
    // 00a5968b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a5968d  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 00a59690  9b                     -wait 
    /*nothing*/;
L_0x00a59691:
    // 00a59691  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59693  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 00a59697  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5969a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5969b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5969c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5969d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5969e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a596a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a596a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a596a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a596a2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a596a4  ff1580dca500           -call dword ptr [0xa5dc80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869888) /* 0xa5dc80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a596aa  8b1510dfa500           -mov edx, dword ptr [0xa5df10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10870544) /* 0xa5df10 */);
    // 00a596b0  891d10dfa500           -mov dword ptr [0xa5df10], ebx
    app->getMemory<x86::reg32>(x86::reg32(10870544) /* 0xa5df10 */) = cpu.ebx;
    // 00a596b6  ff1588dca500           -call dword ptr [0xa5dc88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869896) /* 0xa5dc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a596bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a596be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a596bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a596c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a596c1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a596c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a596c2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a596c3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a596c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a596c5  ff1580dca500           -call dword ptr [0xa5dc80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869888) /* 0xa5dc80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a596cb  a138dea500             -mov eax, dword ptr [0xa5de38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870328) /* 0xa5de38 */);
    // 00a596d0  e9a2000000             -jmp 0xa59777
    return sub_a59777(app, cpu);
}

/* align: skip  */
void sub_a596d5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a596d5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a596d6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a596d7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a596d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a596d9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a596da  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a596dc  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00a596e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a596e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a596e4  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a596e7  2eff15c8b9a500         -call dword ptr cs:[0xa5b9c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10861000) /* 0xa5b9c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a596ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a596f0  7507                   -jne 0xa596f9
    if (!cpu.flags.zf)
    {
        goto L_0x00a596f9;
    }
    // 00a596f2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a596f7  eb36                   -jmp 0xa5972f
    goto L_0x00a5972f;
L_0x00a596f9:
    // 00a596f9  3b1d3cdea500           +cmp ebx, dword ptr [0xa5de3c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10870332) /* 0xa5de3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a596ff  751c                   -jne 0xa5971d
    if (!cpu.flags.zf)
    {
        goto L_0x00a5971d;
    }
    // 00a59701  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a59703  7408                   -je 0xa5970d
    if (cpu.flags.zf)
    {
        goto L_0x00a5970d;
    }
    // 00a59705  89353cdea500           -mov dword ptr [0xa5de3c], esi
    app->getMemory<x86::reg32>(x86::reg32(10870332) /* 0xa5de3c */) = cpu.esi;
    // 00a5970b  eb10                   -jmp 0xa5971d
    goto L_0x00a5971d;
L_0x00a5970d:
    // 00a5970d  a138dea500             -mov eax, dword ptr [0xa5de38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870328) /* 0xa5de38 */);
    // 00a59712  893540dea500           -mov dword ptr [0xa5de40], esi
    app->getMemory<x86::reg32>(x86::reg32(10870336) /* 0xa5de40 */) = cpu.esi;
    // 00a59718  a33cdea500             -mov dword ptr [0xa5de3c], eax
    app->getMemory<x86::reg32>(x86::reg32(10870332) /* 0xa5de3c */) = cpu.eax;
L_0x00a5971d:
    // 00a5971d  3b1d98f0a500           +cmp ebx, dword ptr [0xa5f098]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10875032) /* 0xa5f098 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59723  7508                   -jne 0xa5972d
    if (!cpu.flags.zf)
    {
        goto L_0x00a5972d;
    }
    // 00a59725  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a59727  893d98f0a500           -mov dword ptr [0xa5f098], edi
    app->getMemory<x86::reg32>(x86::reg32(10875032) /* 0xa5f098 */) = cpu.edi;
L_0x00a5972d:
    // 00a5972d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a5972f:
    // 00a5972f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59730  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59731  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59732  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59733  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59734  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59735(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59735  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59736  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59737  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a5973a  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a5973d  e893ffffff             -call 0xa596d5
    cpu.esp -= 4;
    sub_a596d5(app, cpu);
    if (cpu.terminate) return;
    // 00a59742  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59744  7516                   -jne 0xa5975c
    if (!cpu.flags.zf)
    {
        goto L_0x00a5975c;
    }
    // 00a59746  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a59748  7508                   -jne 0xa59752
    if (!cpu.flags.zf)
    {
        goto L_0x00a59752;
    }
    // 00a5974a  891538dea500           -mov dword ptr [0xa5de38], edx
    app->getMemory<x86::reg32>(x86::reg32(10870328) /* 0xa5de38 */) = cpu.edx;
    // 00a59750  eb03                   -jmp 0xa59755
    goto L_0x00a59755;
L_0x00a59752:
    // 00a59752  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00a59755:
    // 00a59755  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a59757  7403                   -je 0xa5975c
    if (cpu.flags.zf)
    {
        goto L_0x00a5975c;
    }
    // 00a59759  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00a5975c:
    // 00a5975c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5975d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5975e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5975f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00a5975f:
    // 00a5975f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a59761  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a59764  83e92c                 -sub ecx, 0x2c
    (cpu.ecx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a59767  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a59769  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a5976c  39f1                   +cmp ecx, esi
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
    // 00a5976e  7505                   -jne 0xa59775
    if (!cpu.flags.zf)
    {
        goto L_0x00a59775;
    }
    // 00a59770  e8c0ffffff             -call 0xa59735
    cpu.esp -= 4;
    sub_a59735(app, cpu);
    if (cpu.terminate) return;
L_0x00a59775:
    // 00a59775  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a59777  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59779  75e4                   -jne 0xa5975f
    if (!cpu.flags.zf)
    {
        goto L_0x00a5975f;
    }
    // 00a5977b  ff1588dca500           -call dword ptr [0xa5dc88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869896) /* 0xa5dc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59781  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59783  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59784  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59785  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59786  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59787  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59777(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a59777;
L_0x00a5975f:
    // 00a5975f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a59761  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a59764  83e92c                 -sub ecx, 0x2c
    (cpu.ecx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a59767  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a59769  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a5976c  39f1                   +cmp ecx, esi
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
    // 00a5976e  7505                   -jne 0xa59775
    if (!cpu.flags.zf)
    {
        goto L_0x00a59775;
    }
    // 00a59770  e8c0ffffff             -call 0xa59735
    cpu.esp -= 4;
    sub_a59735(app, cpu);
    if (cpu.terminate) return;
L_0x00a59775:
    // 00a59775  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_entry_0x00a59777:
    // 00a59777  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59779  75e4                   -jne 0xa5975f
    if (!cpu.flags.zf)
    {
        goto L_0x00a5975f;
    }
    // 00a5977b  ff1588dca500           -call dword ptr [0xa5dc88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869896) /* 0xa5dc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59781  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59783  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59784  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59785  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59786  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59787  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59788(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59788  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59789  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5978a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5978b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a5978c  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a5978e  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a59790  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a59791  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a59793  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a59796  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00a59799  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a5979b  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00a5979e  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00a597a1  8b1518e9a500           -mov edx, dword ptr [0xa5e918]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10873112) /* 0xa5e918 */);
    // 00a597a7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a597a9  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a597ac  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00a597af  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a597b1  753e                   -jne 0xa597f1
    if (!cpu.flags.zf)
    {
        goto L_0x00a597f1;
    }
    // 00a597b3  a144dea500             -mov eax, dword ptr [0xa5de44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870340) /* 0xa5de44 */);
    // 00a597b8  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a597bb  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a597bd  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a597bf  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a597c1  8b1d44dea500           -mov ebx, dword ptr [0xa5de44]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10870340) /* 0xa5de44 */);
    // 00a597c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a597c9  e87bbaffff             -call 0xa55249
    cpu.esp -= 4;
    sub_a55249(app, cpu);
    if (cpu.terminate) return;
    // 00a597ce  a144dea500             -mov eax, dword ptr [0xa5de44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870340) /* 0xa5de44 */);
    // 00a597d3  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00a597d9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a597db  e8e7e4ffff             -call 0xa57cc7
    cpu.esp -= 4;
    sub_a57cc7(app, cpu);
    if (cpu.terminate) return;
    // 00a597e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a597e2  750d                   -jne 0xa597f1
    if (!cpu.flags.zf)
    {
        goto L_0x00a597f1;
    }
    // 00a597e4  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a597e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a597e8  2eff1524b9a500         -call dword ptr cs:[0xa5b924]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860836) /* 0xa5b924 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a597ef  eb32                   -jmp 0xa59823
    goto L_0x00a59823;
L_0x00a597f1:
    // 00a597f1  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a597f4  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a597fa  8998de000000           -mov dword ptr [eax + 0xde], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */) = cpu.ebx;
    // 00a59800  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a59803  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59804  2eff15a0b9a500         -call dword ptr cs:[0xa5b9a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860960) /* 0xa5b9a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5980b  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a5980e  e88eecffff             -call 0xa584a1
    cpu.esp -= 4;
    sub_a584a1(app, cpu);
    if (cpu.terminate) return;
    // 00a59813  ff15a4dca500           -call dword ptr [0xa5dca4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869924) /* 0xa5dca4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59819  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a5981b  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5981e  e8abfcffff             -call 0xa594ce
    cpu.esp -= 4;
    sub_a594ce(app, cpu);
    if (cpu.terminate) return;
L_0x00a59823:
    // 00a59823  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a59825  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59826  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a59828  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a5982a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a5982b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5982c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5982d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5982e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5982f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5982f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59830  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59831  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59832  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a59833  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a59834  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a59837  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a59839  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a5983b  833d60dca500ff         +cmp dword ptr [0xa5dc60], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59842  7512                   -jne 0xa59856
    if (!cpu.flags.zf)
    {
        goto L_0x00a59856;
    }
    // 00a59844  e829e4ffff             -call 0xa57c72
    cpu.esp -= 4;
    sub_a57c72(app, cpu);
    if (cpu.terminate) return;
    // 00a59849  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5984b  0f84ae000000           -je 0xa598ff
    if (cpu.flags.zf)
    {
        goto L_0x00a598ff;
    }
    // 00a59851  e841e5ffff             -call 0xa57d97
    cpu.esp -= 4;
    sub_a57d97(app, cpu);
    if (cpu.terminate) return;
L_0x00a59856:
    // 00a59856  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a5985a  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a5985e  2eff1558b9a500         -call dword ptr cs:[0xa5b958]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860888) /* 0xa5b958 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59865  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a59869  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a5986b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a5986d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a5986f  be88d0a500             -mov esi, 0xa5d088
    cpu.esi = 10866824 /*0xa5d088*/;
    // 00a59874  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a59879  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a5987a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a5987b  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a5987c  2eff1554b9a500         -call dword ptr cs:[0xa5b954]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860884) /* 0xa5b954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59883  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a59887  e829c8ffff             -call 0xa560b5
    cpu.esp -= 4;
    sub_a560b5(app, cpu);
    if (cpu.terminate) return;
    // 00a5988c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a5988e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5988f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a59891  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a59893  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a59895  2eff1528b9a500         -call dword ptr cs:[0xa5b928]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860840) /* 0xa5b928 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5989c  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a598a0  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a598a4  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00a598a8  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a598ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a598ad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a598af  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a598b3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a598b4  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00a598ba  688897a500             -push 0xa59788
    app->getMemory<x86::reg32>(cpu.esp-4) = 10852232 /*0xa59788*/;
    cpu.esp -= 4;
    // 00a598bf  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 00a598c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a598c6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a598c8  2eff1530b9a500         -call dword ptr cs:[0xa5b930]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860848) /* 0xa5b930 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a598cf  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00a598d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a598d5  750a                   -jne 0xa598e1
    if (!cpu.flags.zf)
    {
        goto L_0x00a598e1;
    }
    // 00a598d7  c7442438ffffffff       -mov dword ptr [esp + 0x38], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 4294967295 /*0xffffffff*/;
    // 00a598df  eb0e                   -jmp 0xa598ef
    goto L_0x00a598ef;
L_0x00a598e1:
    // 00a598e1  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a598e3  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a598e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a598e8  2eff15d0b9a500         -call dword ptr cs:[0xa5b9d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10861008) /* 0xa5b9d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a598ef:
    // 00a598ef  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a598f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a598f4  2eff1524b9a500         -call dword ptr cs:[0xa5b924]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860836) /* 0xa5b924 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a598fb  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
L_0x00a598ff:
    // 00a598ff  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a59902  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59903  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a59904  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59905  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59906  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59907  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59908(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59908  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59909  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5990a  ff15a8dca500           -call dword ptr [0xa5dca8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869928) /* 0xa5dca8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59910  e8d8ebffff             -call 0xa584ed
    cpu.esp -= 4;
    sub_a584ed(app, cpu);
    if (cpu.terminate) return;
    // 00a59915  833d18e9a50000         +cmp dword ptr [0xa5e918], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10873112) /* 0xa5e918 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5991c  750a                   -jne 0xa59928
    if (!cpu.flags.zf)
    {
        goto L_0x00a59928;
    }
    // 00a5991e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a59923  e8eee3ffff             -call 0xa57d16
    cpu.esp -= 4;
    sub_a57d16(app, cpu);
    if (cpu.terminate) return;
L_0x00a59928:
    // 00a59928  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a5992a  2eff1540b9a500         -call dword ptr cs:[0xa5b940]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860864) /* 0xa5b940 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59931  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59932  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59933  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59934(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59934  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59935  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59936  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59937  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59938  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59939  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5993a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a5993c  8b3588f0a500           -mov esi, dword ptr [0xa5f088]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
    // 00a59942  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a59944  743f                   -je 0xa59985
    if (cpu.flags.zf)
    {
        goto L_0x00a59985;
    }
    // 00a59946  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59948  743b                   -je 0xa59985
    if (cpu.flags.zf)
    {
        goto L_0x00a59985;
    }
    // 00a5994a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a5994c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a5994d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a5994f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a59951  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a59953  49                     -dec ecx
    (cpu.ecx)--;
    // 00a59954  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a59956  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 00a59958  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a5995a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a5995b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a5995c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00a5995e  eb1f                   -jmp 0xa5997f
    goto L_0x00a5997f;
L_0x00a59960:
    // 00a59960  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a59962  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a59964  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59966  e88d050000             -call 0xa59ef8
    cpu.esp -= 4;
    sub_a59ef8(app, cpu);
    if (cpu.terminate) return;
    // 00a5996b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5996d  750d                   -jne 0xa5997c
    if (!cpu.flags.zf)
    {
        goto L_0x00a5997c;
    }
    // 00a5996f  803c393d               +cmp byte ptr [ecx + edi], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a59973  7507                   -jne 0xa5997c
    if (!cpu.flags.zf)
    {
        goto L_0x00a5997c;
    }
    // 00a59975  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a59978  01c8                   +add eax, ecx
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
    // 00a5997a  eb0b                   -jmp 0xa59987
    goto L_0x00a59987;
L_0x00a5997c:
    // 00a5997c  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a5997f:
    // 00a5997f  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a59981  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a59983  75db                   -jne 0xa59960
    if (!cpu.flags.zf)
    {
        goto L_0x00a59960;
    }
L_0x00a59985:
    // 00a59985  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a59987:
    // 00a59987  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59988  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59989  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5998a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5998b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5998c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5998d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5998e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5998e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5998f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59990  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a59992  eb0b                   -jmp 0xa5999f
    goto L_0x00a5999f;
L_0x00a59994:
    // 00a59994  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a59996  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a59998  7409                   -je 0xa599a3
    if (cpu.flags.zf)
    {
        goto L_0x00a599a3;
    }
    // 00a5999a  42                     -inc edx
    (cpu.edx)++;
    // 00a5999b  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a5999c  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00a5999e  40                     -inc eax
    (cpu.eax)++;
L_0x00a5999f:
    // 00a5999f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a599a1  75f1                   -jne 0xa59994
    if (!cpu.flags.zf)
    {
        goto L_0x00a59994;
    }
L_0x00a599a3:
    // 00a599a3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a599a5  7407                   -je 0xa599ae
    if (cpu.flags.zf)
    {
        goto L_0x00a599ae;
    }
    // 00a599a7  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a599a8  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a599ab  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a599ac  ebf5                   -jmp 0xa599a3
    goto L_0x00a599a3;
L_0x00a599ae:
    // 00a599ae  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a599b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a599b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a599b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a599b3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a599b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a599b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a599b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a599b6  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a599b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a599ba  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a599bc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a599be  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a599c2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a599c4  7402                   -je 0xa599c8
    if (cpu.flags.zf)
    {
        goto L_0x00a599c8;
    }
    // 00a599c6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00a599c8:
    // 00a599c8  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
L_0x00a599cb:
    // 00a599cb  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a599cd  fec0                   -inc al
    (cpu.al)++;
    // 00a599cf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a599d4  f68018dda50002         +test byte ptr [eax + 0xa5dd18], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10870040) /* 0xa5dd18 */) & 2 /*0x2*/));
    // 00a599db  7403                   -je 0xa599e0
    if (cpu.flags.zf)
    {
        goto L_0x00a599e0;
    }
    // 00a599dd  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a599de  ebeb                   -jmp 0xa599cb
    goto L_0x00a599cb;
L_0x00a599e0:
    // 00a599e0  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 00a599e2  80fd2b                 +cmp ch, 0x2b
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
    // 00a599e5  7405                   -je 0xa599ec
    if (cpu.flags.zf)
    {
        goto L_0x00a599ec;
    }
    // 00a599e7  80fd2d                 +cmp ch, 0x2d
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
    // 00a599ea  7501                   -jne 0xa599ed
    if (!cpu.flags.zf)
    {
        goto L_0x00a599ed;
    }
L_0x00a599ec:
    // 00a599ec  42                     -inc edx
    (cpu.edx)++;
L_0x00a599ed:
    // 00a599ed  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a599ef  752c                   -jne 0xa59a1d
    if (!cpu.flags.zf)
    {
        goto L_0x00a59a1d;
    }
    // 00a599f1  803a30                 +cmp byte ptr [edx], 0x30
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
    // 00a599f4  7514                   -jne 0xa59a0a
    if (!cpu.flags.zf)
    {
        goto L_0x00a59a0a;
    }
    // 00a599f6  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a599f9  80f978                 +cmp cl, 0x78
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
    // 00a599fc  7405                   -je 0xa59a03
    if (cpu.flags.zf)
    {
        goto L_0x00a59a03;
    }
    // 00a599fe  80f958                 +cmp cl, 0x58
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
    // 00a59a01  7507                   -jne 0xa59a0a
    if (!cpu.flags.zf)
    {
        goto L_0x00a59a0a;
    }
L_0x00a59a03:
    // 00a59a03  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00a59a08  eb33                   -jmp 0xa59a3d
    goto L_0x00a59a3d;
L_0x00a59a0a:
    // 00a59a0a  803a30                 +cmp byte ptr [edx], 0x30
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
    // 00a59a0d  7507                   -jne 0xa59a16
    if (!cpu.flags.zf)
    {
        goto L_0x00a59a16;
    }
    // 00a59a0f  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 00a59a14  eb3c                   -jmp 0xa59a52
    goto L_0x00a59a52;
L_0x00a59a16:
    // 00a59a16  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 00a59a1b  eb35                   -jmp 0xa59a52
    goto L_0x00a59a52;
L_0x00a59a1d:
    // 00a59a1d  83fe02                 +cmp esi, 2
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
    // 00a59a20  7c05                   -jl 0xa59a27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a59a27;
    }
    // 00a59a22  83fe24                 +cmp esi, 0x24
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
    // 00a59a25  7e11                   -jle 0xa59a38
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a59a38;
    }
L_0x00a59a27:
    // 00a59a27  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00a59a2c  e802dfffff             -call 0xa57933
    cpu.esp -= 4;
    sub_a57933(app, cpu);
    if (cpu.terminate) return;
    // 00a59a31  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a59a33  e9b3000000             -jmp 0xa59aeb
    goto L_0x00a59aeb;
L_0x00a59a38:
    // 00a59a38  83fe10                 +cmp esi, 0x10
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
    // 00a59a3b  7515                   -jne 0xa59a52
    if (!cpu.flags.zf)
    {
        goto L_0x00a59a52;
    }
L_0x00a59a3d:
    // 00a59a3d  803a30                 +cmp byte ptr [edx], 0x30
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
    // 00a59a40  7510                   -jne 0xa59a52
    if (!cpu.flags.zf)
    {
        goto L_0x00a59a52;
    }
    // 00a59a42  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a59a45  80ff78                 +cmp bh, 0x78
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
    // 00a59a48  7405                   -je 0xa59a4f
    if (cpu.flags.zf)
    {
        goto L_0x00a59a4f;
    }
    // 00a59a4a  80ff58                 +cmp bh, 0x58
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
    // 00a59a4d  7503                   -jne 0xa59a52
    if (!cpu.flags.zf)
    {
        goto L_0x00a59a52;
    }
L_0x00a59a4f:
    // 00a59a4f  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a59a52:
    // 00a59a52  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a59a56  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a59a58  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00a59a5a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a59a5c  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
L_0x00a59a5f:
    // 00a59a5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59a61  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a59a63  e89c000000             -call 0xa59b04
    cpu.esp -= 4;
    sub_a59b04(app, cpu);
    if (cpu.terminate) return;
    // 00a59a68  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a59a6c  39f0                   +cmp eax, esi
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
    // 00a59a6e  7d1c                   -jge 0xa59a8c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a59a8c;
    }
    // 00a59a70  3b9f10dfa500           +cmp ebx, dword ptr [edi + 0xa5df10]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10870544) /* 0xa5df10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59a76  7602                   -jbe 0xa59a7a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a59a7a;
    }
    // 00a59a78  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a59a7a:
    // 00a59a7a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a59a7c  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00a59a7f  035c2408               -add ebx, dword ptr [esp + 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00a59a83  39c3                   +cmp ebx, eax
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
    // 00a59a85  7302                   -jae 0xa59a89
    if (!cpu.flags.cf)
    {
        goto L_0x00a59a89;
    }
    // 00a59a87  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a59a89:
    // 00a59a89  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a59a8a  ebd3                   -jmp 0xa59a5f
    goto L_0x00a59a5f;
L_0x00a59a8c:
    // 00a59a8c  3b542404               +cmp edx, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59a90  7503                   -jne 0xa59a95
    if (!cpu.flags.zf)
    {
        goto L_0x00a59a95;
    }
    // 00a59a92  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
L_0x00a59a95:
    // 00a59a95  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a59a97  7403                   -je 0xa59a9c
    if (cpu.flags.zf)
    {
        goto L_0x00a59a9c;
    }
    // 00a59a99  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
L_0x00a59a9c:
    // 00a59a9c  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59aa1  750f                   -jne 0xa59ab2
    if (!cpu.flags.zf)
    {
        goto L_0x00a59ab2;
    }
    // 00a59aa3  81fb00000080           +cmp ebx, 0x80000000
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
    // 00a59aa9  7207                   -jb 0xa59ab2
    if (cpu.flags.cf)
    {
        goto L_0x00a59ab2;
    }
    // 00a59aab  7509                   -jne 0xa59ab6
    if (!cpu.flags.zf)
    {
        goto L_0x00a59ab6;
    }
    // 00a59aad  80fd2d                 +cmp ch, 0x2d
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
    // 00a59ab0  7504                   -jne 0xa59ab6
    if (!cpu.flags.zf)
    {
        goto L_0x00a59ab6;
    }
L_0x00a59ab2:
    // 00a59ab2  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a59ab4  742c                   -je 0xa59ae2
    if (cpu.flags.zf)
    {
        goto L_0x00a59ae2;
    }
L_0x00a59ab6:
    // 00a59ab6  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a59abb  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a59abf  e86fdeffff             -call 0xa57933
    cpu.esp -= 4;
    sub_a57933(app, cpu);
    if (cpu.terminate) return;
    // 00a59ac4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a59ac6  7507                   -jne 0xa59acf
    if (!cpu.flags.zf)
    {
        goto L_0x00a59acf;
    }
    // 00a59ac8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a59acd  eb1c                   -jmp 0xa59aeb
    goto L_0x00a59aeb;
L_0x00a59acf:
    // 00a59acf  80fd2d                 +cmp ch, 0x2d
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
    // 00a59ad2  7507                   -jne 0xa59adb
    if (!cpu.flags.zf)
    {
        goto L_0x00a59adb;
    }
    // 00a59ad4  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 00a59ad9  eb10                   -jmp 0xa59aeb
    goto L_0x00a59aeb;
L_0x00a59adb:
    // 00a59adb  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 00a59ae0  eb09                   -jmp 0xa59aeb
    goto L_0x00a59aeb;
L_0x00a59ae2:
    // 00a59ae2  80fd2d                 +cmp ch, 0x2d
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
    // 00a59ae5  7502                   -jne 0xa59ae9
    if (!cpu.flags.zf)
    {
        goto L_0x00a59ae9;
    }
    // 00a59ae7  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x00a59ae9:
    // 00a59ae9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a59aeb:
    // 00a59aeb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a59aee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59aef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59af0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59af1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59af2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59af2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59af3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a59af5  e8b9feffff             -call 0xa599b3
    cpu.esp -= 4;
    sub_a599b3(app, cpu);
    if (cpu.terminate) return;
    // 00a59afa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59afb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59af5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a59af5;
    // 00a59af2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59af3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x00a59af5:
    // 00a59af5  e8b9feffff             -call 0xa599b3
    cpu.esp -= 4;
    sub_a599b3(app, cpu);
    if (cpu.terminate) return;
    // 00a59afa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59afb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59afc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59afc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59afd  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a59b02  ebf1                   -jmp 0xa59af5
    return sub_a59af5(app, cpu);
}

/* align: skip  */
void sub_a59b04(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59b04  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59b05  3c30                   +cmp al, 0x30
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
    // 00a59b07  720e                   -jb 0xa59b17
    if (cpu.flags.cf)
    {
        goto L_0x00a59b17;
    }
    // 00a59b09  3c39                   +cmp al, 0x39
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
    // 00a59b0b  770a                   -ja 0xa59b17
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a59b17;
    }
    // 00a59b0d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a59b12  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a59b15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59b16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a59b17:
    // 00a59b17  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a59b1c  e849040000             -call 0xa59f6a
    cpu.esp -= 4;
    sub_a59f6a(app, cpu);
    if (cpu.terminate) return;
    // 00a59b21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59b23  3c61                   +cmp al, 0x61
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
    // 00a59b25  720d                   -jb 0xa59b34
    if (cpu.flags.cf)
    {
        goto L_0x00a59b34;
    }
    // 00a59b27  3c69                   +cmp al, 0x69
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
    // 00a59b29  7709                   -ja 0xa59b34
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a59b34;
    }
    // 00a59b2b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59b2d  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a59b2f  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a59b32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59b33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a59b34:
    // 00a59b34  3c6a                   +cmp al, 0x6a
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
    // 00a59b36  720e                   -jb 0xa59b46
    if (cpu.flags.cf)
    {
        goto L_0x00a59b46;
    }
    // 00a59b38  3c72                   +cmp al, 0x72
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
    // 00a59b3a  770a                   -ja 0xa59b46
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a59b46;
    }
L_0x00a59b3c:
    // 00a59b3c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a59b41  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a59b44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59b45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a59b46:
    // 00a59b46  3c73                   +cmp al, 0x73
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
    // 00a59b48  7204                   -jb 0xa59b4e
    if (cpu.flags.cf)
    {
        goto L_0x00a59b4e;
    }
    // 00a59b4a  3c7a                   +cmp al, 0x7a
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
    // 00a59b4c  76ee                   -jbe 0xa59b3c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a59b3c;
    }
L_0x00a59b4e:
    // 00a59b4e  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 00a59b53  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59b54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59b55(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59b55  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59b56  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59b57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59b58  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59b59  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59b5a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a59b5b  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a59b5e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a59b60  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a59b65  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a59b6a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a59b6d  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a59b72  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a59b76  e8fd030000             -call 0xa59f78
    cpu.esp -= 4;
    sub_a59f78(app, cpu);
    if (cpu.terminate) return;
    // 00a59b7b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a59b7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59b7f  7469                   -je 0xa59bea
    if (cpu.flags.zf)
    {
        goto L_0x00a59bea;
    }
    // 00a59b81  39e8                   +cmp eax, ebp
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
    // 00a59b83  7465                   -je 0xa59bea
    if (cpu.flags.zf)
    {
        goto L_0x00a59bea;
    }
    // 00a59b85  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a59b87  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a59b8b  40                     -inc eax
    (cpu.eax)++;
    // 00a59b8c  e87feaffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a59b91  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59b93  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a59b97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59b99  744f                   -je 0xa59bea
    if (cpu.flags.zf)
    {
        goto L_0x00a59bea;
    }
    // 00a59b9b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a59b9f  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a59ba1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a59ba3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a59ba4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a59ba6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a59ba8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59ba9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59bab  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a59bae  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a59bb0  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a59bb2  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a59bb5  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a59bb7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59bb8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a59bb9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a59bbd  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a59bc0  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a59bc4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a59bc6  e809040000             -call 0xa59fd4
    cpu.esp -= 4;
    sub_a59fd4(app, cpu);
    if (cpu.terminate) return;
    // 00a59bcb  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a59bcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59bd1  7446                   -je 0xa59c19
    if (cpu.flags.zf)
    {
        goto L_0x00a59c19;
    }
    // 00a59bd3  40                     -inc eax
    (cpu.eax)++;
    // 00a59bd4  e837eaffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a59bd9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a59bdb  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a59bdf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59be1  7511                   -jne 0xa59bf4
    if (!cpu.flags.zf)
    {
        goto L_0x00a59bf4;
    }
    // 00a59be3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a59be5:
    // 00a59be5  e813ebffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a59bea:
    // 00a59bea  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a59bef  e9af000000             -jmp 0xa59ca3
    goto L_0x00a59ca3;
L_0x00a59bf4:
    // 00a59bf4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a59bf8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a59bfa  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a59bfb  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a59bfd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a59bff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59c00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59c02  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a59c05  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a59c07  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a59c09  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a59c0c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a59c0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59c0f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a59c10  035c2414               +add ebx, dword ptr [esp + 0x14]
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
    // 00a59c14  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 00a59c17  eb04                   -jmp 0xa59c1d
    goto L_0x00a59c1d;
L_0x00a59c19:
    // 00a59c19  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a59c1d:
    // 00a59c1d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a59c21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a59c22  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a59c26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59c27  2eff1598b9a500         -call dword ptr cs:[0xa5b998]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860952) /* 0xa5b998 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59c2e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59c30  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a59c34  e8c4eaffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a59c39  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a59c3d  e8bbeaffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a59c42  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a59c44  74a4                   -je 0xa59bea
    if (cpu.flags.zf)
    {
        goto L_0x00a59bea;
    }
    // 00a59c46  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a59c48  e860000000             -call 0xa59cad
    cpu.esp -= 4;
    sub_a59cad(app, cpu);
    if (cpu.terminate) return;
    // 00a59c4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59c4f  7599                   -jne 0xa59bea
    if (!cpu.flags.zf)
    {
        goto L_0x00a59bea;
    }
    // 00a59c51  833d8cf0a50000         +cmp dword ptr [0xa5f08c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59c58  7449                   -je 0xa59ca3
    if (cpu.flags.zf)
    {
        goto L_0x00a59ca3;
    }
    // 00a59c5a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a59c5c  e873030000             -call 0xa59fd4
    cpu.esp -= 4;
    sub_a59fd4(app, cpu);
    if (cpu.terminate) return;
    // 00a59c61  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a59c64  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a59c67  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a59c6a  e8a1e9ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a59c6f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a59c71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59c73  750f                   -jne 0xa59c84
    if (!cpu.flags.zf)
    {
        goto L_0x00a59c84;
    }
    // 00a59c75  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a59c7a  e882030000             -call 0xa5a001
    cpu.esp -= 4;
    sub_a5a001(app, cpu);
    if (cpu.terminate) return;
    // 00a59c7f  e966ffffff             -jmp 0xa59bea
    goto L_0x00a59bea;
L_0x00a59c84:
    // 00a59c84  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00a59c89  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a59c8b  e8d3030000             -call 0xa5a063
    cpu.esp -= 4;
    sub_a5a063(app, cpu);
    if (cpu.terminate) return;
    // 00a59c90  83f8ff                 +cmp eax, -1
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
    // 00a59c93  7507                   -jne 0xa59c9c
    if (!cpu.flags.zf)
    {
        goto L_0x00a59c9c;
    }
    // 00a59c95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59c97  e949ffffff             -jmp 0xa59be5
    goto L_0x00a59be5;
L_0x00a59c9c:
    // 00a59c9c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59c9e  e85e050000             -call 0xa5a201
    cpu.esp -= 4;
    sub_a5a201(app, cpu);
    if (cpu.terminate) return;
L_0x00a59ca3:
    // 00a59ca3  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a59ca6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ca7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ca8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ca9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59caa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59cab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59cac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59ca6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a59ca6;
    // 00a59b55  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59b56  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59b57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59b58  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59b59  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59b5a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a59b5b  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a59b5e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a59b60  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a59b65  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a59b6a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a59b6d  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a59b72  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a59b76  e8fd030000             -call 0xa59f78
    cpu.esp -= 4;
    sub_a59f78(app, cpu);
    if (cpu.terminate) return;
    // 00a59b7b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a59b7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59b7f  7469                   -je 0xa59bea
    if (cpu.flags.zf)
    {
        goto L_0x00a59bea;
    }
    // 00a59b81  39e8                   +cmp eax, ebp
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
    // 00a59b83  7465                   -je 0xa59bea
    if (cpu.flags.zf)
    {
        goto L_0x00a59bea;
    }
    // 00a59b85  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a59b87  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a59b8b  40                     -inc eax
    (cpu.eax)++;
    // 00a59b8c  e87feaffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a59b91  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59b93  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a59b97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59b99  744f                   -je 0xa59bea
    if (cpu.flags.zf)
    {
        goto L_0x00a59bea;
    }
    // 00a59b9b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a59b9f  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a59ba1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a59ba3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a59ba4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a59ba6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a59ba8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59ba9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59bab  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a59bae  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a59bb0  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a59bb2  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a59bb5  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a59bb7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59bb8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a59bb9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a59bbd  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a59bc0  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a59bc4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a59bc6  e809040000             -call 0xa59fd4
    cpu.esp -= 4;
    sub_a59fd4(app, cpu);
    if (cpu.terminate) return;
    // 00a59bcb  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a59bcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59bd1  7446                   -je 0xa59c19
    if (cpu.flags.zf)
    {
        goto L_0x00a59c19;
    }
    // 00a59bd3  40                     -inc eax
    (cpu.eax)++;
    // 00a59bd4  e837eaffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a59bd9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a59bdb  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a59bdf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59be1  7511                   -jne 0xa59bf4
    if (!cpu.flags.zf)
    {
        goto L_0x00a59bf4;
    }
    // 00a59be3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a59be5:
    // 00a59be5  e813ebffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a59bea:
    // 00a59bea  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a59bef  e9af000000             -jmp 0xa59ca3
    goto L_0x00a59ca3;
L_0x00a59bf4:
    // 00a59bf4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a59bf8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a59bfa  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a59bfb  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a59bfd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a59bff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59c00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59c02  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a59c05  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a59c07  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a59c09  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a59c0c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a59c0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59c0f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a59c10  035c2414               +add ebx, dword ptr [esp + 0x14]
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
    // 00a59c14  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 00a59c17  eb04                   -jmp 0xa59c1d
    goto L_0x00a59c1d;
L_0x00a59c19:
    // 00a59c19  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a59c1d:
    // 00a59c1d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a59c21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a59c22  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a59c26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59c27  2eff1598b9a500         -call dword ptr cs:[0xa5b998]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860952) /* 0xa5b998 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59c2e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59c30  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a59c34  e8c4eaffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a59c39  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a59c3d  e8bbeaffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a59c42  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a59c44  74a4                   -je 0xa59bea
    if (cpu.flags.zf)
    {
        goto L_0x00a59bea;
    }
    // 00a59c46  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a59c48  e860000000             -call 0xa59cad
    cpu.esp -= 4;
    sub_a59cad(app, cpu);
    if (cpu.terminate) return;
    // 00a59c4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59c4f  7599                   -jne 0xa59bea
    if (!cpu.flags.zf)
    {
        goto L_0x00a59bea;
    }
    // 00a59c51  833d8cf0a50000         +cmp dword ptr [0xa5f08c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59c58  7449                   -je 0xa59ca3
    if (cpu.flags.zf)
    {
        goto L_0x00a59ca3;
    }
    // 00a59c5a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a59c5c  e873030000             -call 0xa59fd4
    cpu.esp -= 4;
    sub_a59fd4(app, cpu);
    if (cpu.terminate) return;
    // 00a59c61  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a59c64  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a59c67  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a59c6a  e8a1e9ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a59c6f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a59c71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59c73  750f                   -jne 0xa59c84
    if (!cpu.flags.zf)
    {
        goto L_0x00a59c84;
    }
    // 00a59c75  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a59c7a  e882030000             -call 0xa5a001
    cpu.esp -= 4;
    sub_a5a001(app, cpu);
    if (cpu.terminate) return;
    // 00a59c7f  e966ffffff             -jmp 0xa59bea
    goto L_0x00a59bea;
L_0x00a59c84:
    // 00a59c84  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00a59c89  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a59c8b  e8d3030000             -call 0xa5a063
    cpu.esp -= 4;
    sub_a5a063(app, cpu);
    if (cpu.terminate) return;
    // 00a59c90  83f8ff                 +cmp eax, -1
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
    // 00a59c93  7507                   -jne 0xa59c9c
    if (!cpu.flags.zf)
    {
        goto L_0x00a59c9c;
    }
    // 00a59c95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59c97  e949ffffff             -jmp 0xa59be5
    goto L_0x00a59be5;
L_0x00a59c9c:
    // 00a59c9c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59c9e  e85e050000             -call 0xa5a201
    cpu.esp -= 4;
    sub_a5a201(app, cpu);
    if (cpu.terminate) return;
L_0x00a59ca3:
    // 00a59ca3  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_entry_0x00a59ca6:
    // 00a59ca6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ca7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ca8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ca9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59caa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59cab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59cac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59cad(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59cad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59cae  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59caf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59cb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59cb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59cb2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a59cb3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a59cb6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a59cb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59cb9  750a                   -jne 0xa59cc5
    if (!cpu.flags.zf)
    {
        goto L_0x00a59cc5;
    }
L_0x00a59cbb:
    // 00a59cbb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a59cc0  e94b010000             -jmp 0xa59e10
    goto L_0x00a59e10;
L_0x00a59cc5:
    // 00a59cc5  803800                 +cmp byte ptr [eax], 0
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
    // 00a59cc8  7411                   -je 0xa59cdb
    if (cpu.flags.zf)
    {
        goto L_0x00a59cdb;
    }
    // 00a59cca  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a59ccd  eb06                   -jmp 0xa59cd5
    goto L_0x00a59cd5;
L_0x00a59ccf:
    // 00a59ccf  80ff3d                 +cmp bh, 0x3d
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a59cd2  7407                   -je 0xa59cdb
    if (cpu.flags.zf)
    {
        goto L_0x00a59cdb;
    }
    // 00a59cd4  42                     -inc edx
    (cpu.edx)++;
L_0x00a59cd5:
    // 00a59cd5  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 00a59cd7  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00a59cd9  75f4                   -jne 0xa59ccf
    if (!cpu.flags.zf)
    {
        goto L_0x00a59ccf;
    }
L_0x00a59cdb:
    // 00a59cdb  803a00                 +cmp byte ptr [edx], 0
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
    // 00a59cde  74db                   -je 0xa59cbb
    if (cpu.flags.zf)
    {
        goto L_0x00a59cbb;
    }
    // 00a59ce0  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 00a59ce4  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a59ce7  0fb6e8                 -movzx ebp, al
    cpu.ebp = x86::reg32(cpu.al);
    // 00a59cea  a188f0a500             -mov eax, dword ptr [0xa5f088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
    // 00a59cef  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a59cf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59cf5  7531                   -jne 0xa59d28
    if (!cpu.flags.zf)
    {
        goto L_0x00a59d28;
    }
    // 00a59cf7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a59cf9  0f8511010000           -jne 0xa59e10
    if (!cpu.flags.zf)
    {
        goto L_0x00a59e10;
    }
    // 00a59cff  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a59d04  e807e9ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a59d09  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a59d0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59d0f  74aa                   -je 0xa59cbb
    if (cpu.flags.zf)
    {
        goto L_0x00a59cbb;
    }
    // 00a59d11  a388f0a500             -mov dword ptr [0xa5f088], eax
    app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */) = cpu.eax;
    // 00a59d16  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 00a59d18  83c008                 +add eax, 8
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
    // 00a59d1b  8968fc                 -mov dword ptr [eax - 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00a59d1e  a384f0a500             -mov dword ptr [0xa5f084], eax
    app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */) = cpu.eax;
    // 00a59d23  e9cd000000             -jmp 0xa59df5
    goto L_0x00a59df5;
L_0x00a59d28:
    // 00a59d28  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a59d2b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a59d2d  e8e6000000             -call 0xa59e18
    cpu.esp -= 4;
    sub_a59e18(app, cpu);
    if (cpu.terminate) return;
    // 00a59d32  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a59d34  0f85d4000000           -jne 0xa59e0e
    if (!cpu.flags.zf)
    {
        goto L_0x00a59e0e;
    }
    // 00a59d3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59d3c  0f8fb0000000           -jg 0xa59df2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a59df2;
    }
    // 00a59d42  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a59d44  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 00a59d46  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a59d49  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00a59d4b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00a59d4e  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a59d51  8b3584f0a500           -mov esi, dword ptr [0xa5f084]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */);
    // 00a59d57  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a59d5b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a59d5d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a59d5f  7545                   -jne 0xa59da6
    if (!cpu.flags.zf)
    {
        goto L_0x00a59da6;
    }
    // 00a59d61  e8aae8ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a59d66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59d68  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a59d6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59d6e  0f8447ffffff           -je 0xa59cbb
    if (cpu.flags.zf)
    {
        goto L_0x00a59cbb;
    }
    // 00a59d74  8b3588f0a500           -mov esi, dword ptr [0xa5f088]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
    // 00a59d7a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a59d7c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a59d7d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a59d7f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a59d81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59d82  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59d84  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a59d87  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a59d89  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a59d8b  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a59d8e  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a59d90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59d91  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a59d92  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a59d96  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a59d98  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a59d9a  a384f0a500             -mov dword ptr [0xa5f084], eax
    app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */) = cpu.eax;
    // 00a59d9f  e8a5b4ffff             -call 0xa55249
    cpu.esp -= 4;
    sub_a55249(app, cpu);
    if (cpu.terminate) return;
    // 00a59da4  eb32                   -jmp 0xa59dd8
    goto L_0x00a59dd8;
L_0x00a59da6:
    // 00a59da6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59da8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a59dac  e832dcffff             -call 0xa579e3
    cpu.esp -= 4;
    sub_a579e3(app, cpu);
    if (cpu.terminate) return;
    // 00a59db1  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a59db5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59db7  0f84fefeffff           -je 0xa59cbb
    if (cpu.flags.zf)
    {
        goto L_0x00a59cbb;
    }
    // 00a59dbd  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a59dc1  8b1584f0a500           -mov edx, dword ptr [0xa5f084]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */);
    // 00a59dc7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a59dc9  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a59dcb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59dcd  e864060000             -call 0xa5a436
    cpu.esp -= 4;
    sub_a5a436(app, cpu);
    if (cpu.terminate) return;
    // 00a59dd2  890d84f0a500           -mov dword ptr [0xa5f084], ecx
    app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */) = cpu.ecx;
L_0x00a59dd8:
    // 00a59dd8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a59dda  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a59dde  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a59de1  01f8                   +add eax, edi
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
    // 00a59de3  893d88f0a500           -mov dword ptr [0xa5f088], edi
    app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */) = cpu.edi;
    // 00a59de9  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a59df0  eb03                   -jmp 0xa59df5
    goto L_0x00a59df5;
L_0x00a59df2:
    // 00a59df2  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00a59df5:
    // 00a59df5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a59df7  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a59dfb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a59dfe  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a59e00  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a59e03  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a59e05  a184f0a500             -mov eax, dword ptr [0xa5f084]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */);
    // 00a59e0a  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
L_0x00a59e0e:
    // 00a59e0e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a59e10:
    // 00a59e10  83c40c                 +add esp, 0xc
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
    // 00a59e13  e98efeffff             -jmp 0xa59ca6
    return sub_a59ca6(app, cpu);
}

/* align: skip  */
void sub_a59e18(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59e18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59e19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59e1a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59e1b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a59e1c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a59e1d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a59e1f  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a59e21  8b3588f0a500           -mov esi, dword ptr [0xa5f088]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
    // 00a59e27  e9b2000000             -jmp 0xa59ede
    goto L_0x00a59ede;
L_0x00a59e2c:
    // 00a59e2c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a59e2e  e99f000000             -jmp 0xa59ed2
    goto L_0x00a59ed2;
L_0x00a59e33:
    // 00a59e33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59e35  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a59e37  e80cc4ffff             -call 0xa56248
    cpu.esp -= 4;
    sub_a56248(app, cpu);
    if (cpu.terminate) return;
    // 00a59e3c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a59e3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59e40  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a59e42  e801c4ffff             -call 0xa56248
    cpu.esp -= 4;
    sub_a56248(app, cpu);
    if (cpu.terminate) return;
    // 00a59e47  39c1                   +cmp ecx, eax
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
    // 00a59e49  0f858c000000           -jne 0xa59edb
    if (!cpu.flags.zf)
    {
        goto L_0x00a59edb;
    }
    // 00a59e4f  803a3d                 +cmp byte ptr [edx], 0x3d
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
    // 00a59e52  0f8578000000           -jne 0xa59ed0
    if (!cpu.flags.zf)
    {
        goto L_0x00a59ed0;
    }
    // 00a59e58  8b1588f0a500           -mov edx, dword ptr [0xa5f088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
    // 00a59e5e  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a59e60  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a59e62  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00a59e65  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a59e67  7462                   -je 0xa59ecb
    if (cpu.flags.zf)
    {
        goto L_0x00a59ecb;
    }
    // 00a59e69  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a59e6b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a59e6d  eb08                   -jmp 0xa59e77
    goto L_0x00a59e77;
L_0x00a59e6f:
    // 00a59e6f  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a59e72  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a59e74  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a59e77:
    // 00a59e77  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a59e7a  75f3                   -jne 0xa59e6f
    if (!cpu.flags.zf)
    {
        goto L_0x00a59e6f;
    }
    // 00a59e7c  8b3584f0a500           -mov esi, dword ptr [0xa5f084]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */);
    // 00a59e82  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a59e84  7441                   -je 0xa59ec7
    if (cpu.flags.zf)
    {
        goto L_0x00a59ec7;
    }
    // 00a59e86  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a59e88  803c0700               +cmp byte ptr [edi + eax], 0
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
    // 00a59e8c  7407                   -je 0xa59e95
    if (cpu.flags.zf)
    {
        goto L_0x00a59e95;
    }
    // 00a59e8e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a59e90  e868e8ffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a59e95:
    // 00a59e95  8b2d88f0a500           -mov ebp, dword ptr [0xa5f088]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
    // 00a59e9b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a59e9d  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a59e9f  8b1584f0a500           -mov edx, dword ptr [0xa5f084]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */);
    // 00a59ea5  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00a59ea8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59eaa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a59eac  e885050000             -call 0xa5a436
    cpu.esp -= 4;
    sub_a5a436(app, cpu);
    if (cpu.terminate) return;
    // 00a59eb1  890d84f0a500           -mov dword ptr [0xa5f084], ecx
    app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */) = cpu.ecx;
    // 00a59eb7  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00a59eba  eb07                   -jmp 0xa59ec3
    goto L_0x00a59ec3;
L_0x00a59ebc:
    // 00a59ebc  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a59ebf  47                     -inc edi
    (cpu.edi)++;
    // 00a59ec0  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a59ec2  40                     -inc eax
    (cpu.eax)++;
L_0x00a59ec3:
    // 00a59ec3  39f7                   +cmp edi, esi
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
    // 00a59ec5  7cf5                   -jl 0xa59ebc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a59ebc;
    }
L_0x00a59ec7:
    // 00a59ec7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a59ec9  eb27                   -jmp 0xa59ef2
    goto L_0x00a59ef2;
L_0x00a59ecb:
    // 00a59ecb  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a59ece  eb22                   -jmp 0xa59ef2
    goto L_0x00a59ef2;
L_0x00a59ed0:
    // 00a59ed0  42                     -inc edx
    (cpu.edx)++;
    // 00a59ed1  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a59ed2:
    // 00a59ed2  803b00                 +cmp byte ptr [ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a59ed5  0f8558ffffff           -jne 0xa59e33
    if (!cpu.flags.zf)
    {
        goto L_0x00a59e33;
    }
L_0x00a59edb:
    // 00a59edb  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a59ede:
    // 00a59ede  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a59ee0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a59ee2  0f8544ffffff           -jne 0xa59e2c
    if (!cpu.flags.zf)
    {
        goto L_0x00a59e2c;
    }
    // 00a59ee8  a188f0a500             -mov eax, dword ptr [0xa5f088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
    // 00a59eed  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a59eef  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x00a59ef2:
    // 00a59ef2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ef3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ef4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ef5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ef6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ef7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59ef8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59ef8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59ef9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59efa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a59efc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a59efe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a59f00:
    // 00a59f00  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a59f02  763a                   -jbe 0xa59f3e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a59f3e;
    }
    // 00a59f04  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59f06  e878050000             -call 0xa5a483
    cpu.esp -= 4;
    sub_a5a483(app, cpu);
    if (cpu.terminate) return;
    // 00a59f0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59f0d  752f                   -jne 0xa59f3e
    if (!cpu.flags.zf)
    {
        goto L_0x00a59f3e;
    }
    // 00a59f0f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a59f11  e86d050000             -call 0xa5a483
    cpu.esp -= 4;
    sub_a5a483(app, cpu);
    if (cpu.terminate) return;
    // 00a59f16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59f18  7524                   -jne 0xa59f3e
    if (!cpu.flags.zf)
    {
        goto L_0x00a59f3e;
    }
    // 00a59f1a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a59f1c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59f1e  e89c050000             -call 0xa5a4bf
    cpu.esp -= 4;
    sub_a5a4bf(app, cpu);
    if (cpu.terminate) return;
    // 00a59f23  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59f25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59f27  753e                   -jne 0xa59f67
    if (!cpu.flags.zf)
    {
        goto L_0x00a59f67;
    }
    // 00a59f29  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59f2b  e8e6050000             -call 0xa5a516
    cpu.esp -= 4;
    sub_a5a516(app, cpu);
    if (cpu.terminate) return;
    // 00a59f30  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a59f32  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a59f34  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a59f35  e8dc050000             -call 0xa5a516
    cpu.esp -= 4;
    sub_a5a516(app, cpu);
    if (cpu.terminate) return;
    // 00a59f3a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a59f3c  ebc2                   -jmp 0xa59f00
    goto L_0x00a59f00;
L_0x00a59f3e:
    // 00a59f3e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a59f40  7623                   -jbe 0xa59f65
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a59f65;
    }
    // 00a59f42  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59f44  e83a050000             -call 0xa5a483
    cpu.esp -= 4;
    sub_a5a483(app, cpu);
    if (cpu.terminate) return;
    // 00a59f49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59f4b  750b                   -jne 0xa59f58
    if (!cpu.flags.zf)
    {
        goto L_0x00a59f58;
    }
    // 00a59f4d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a59f4f  e82f050000             -call 0xa5a483
    cpu.esp -= 4;
    sub_a5a483(app, cpu);
    if (cpu.terminate) return;
    // 00a59f54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59f56  740d                   -je 0xa59f65
    if (cpu.flags.zf)
    {
        goto L_0x00a59f65;
    }
L_0x00a59f58:
    // 00a59f58  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59f5a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a59f5c  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a59f5e  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 00a59f60  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a59f62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59f63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59f64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a59f65:
    // 00a59f65  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a59f67:
    // 00a59f67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59f68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59f69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59f6a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59f6a  83f841                 +cmp eax, 0x41
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
    // 00a59f6d  7c08                   -jl 0xa59f77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a59f77;
    }
    // 00a59f6f  83f85a                 +cmp eax, 0x5a
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
    // 00a59f72  7f03                   -jg 0xa59f77
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a59f77;
    }
    // 00a59f74  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a59f77:
    // 00a59f77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59f78(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59f78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59f79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59f7a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a59f7d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a59f7f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a59f81  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a59f83  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a59f85  e8b9050000             -call 0xa5a543
    cpu.esp -= 4;
    sub_a5a543(app, cpu);
    if (cpu.terminate) return;
    // 00a59f8a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a59f8c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a59f8e  e8ca050000             -call 0xa5a55d
    cpu.esp -= 4;
    sub_a5a55d(app, cpu);
    if (cpu.terminate) return;
    // 00a59f93  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x00a59f96:
    // 00a59f96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a59f98  e8e6040000             -call 0xa5a483
    cpu.esp -= 4;
    sub_a5a483(app, cpu);
    if (cpu.terminate) return;
    // 00a59f9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59f9f  7518                   -jne 0xa59fb9
    if (!cpu.flags.zf)
    {
        goto L_0x00a59fb9;
    }
    // 00a59fa1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a59fa3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a59fa5  e8de050000             -call 0xa5a588
    cpu.esp -= 4;
    sub_a5a588(app, cpu);
    if (cpu.terminate) return;
    // 00a59faa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59fac  740b                   -je 0xa59fb9
    if (cpu.flags.zf)
    {
        goto L_0x00a59fb9;
    }
    // 00a59fae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a59fb0  e861050000             -call 0xa5a516
    cpu.esp -= 4;
    sub_a5a516(app, cpu);
    if (cpu.terminate) return;
    // 00a59fb5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a59fb7  ebdd                   -jmp 0xa59f96
    goto L_0x00a59f96;
L_0x00a59fb9:
    // 00a59fb9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a59fbb  e8c3040000             -call 0xa5a483
    cpu.esp -= 4;
    sub_a5a483(app, cpu);
    if (cpu.terminate) return;
    // 00a59fc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59fc2  7404                   -je 0xa59fc8
    if (cpu.flags.zf)
    {
        goto L_0x00a59fc8;
    }
    // 00a59fc4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a59fc6  7504                   -jne 0xa59fcc
    if (!cpu.flags.zf)
    {
        goto L_0x00a59fcc;
    }
L_0x00a59fc8:
    // 00a59fc8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a59fca  eb02                   -jmp 0xa59fce
    goto L_0x00a59fce;
L_0x00a59fcc:
    // 00a59fcc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a59fce:
    // 00a59fce  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a59fd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59fd2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59fd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59fd4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59fd4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59fd5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a59fd6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59fd8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a59fda:
    // 00a59fda  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a59fdc  e8a2040000             -call 0xa5a483
    cpu.esp -= 4;
    sub_a5a483(app, cpu);
    if (cpu.terminate) return;
    // 00a59fe1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59fe3  750c                   -jne 0xa59ff1
    if (!cpu.flags.zf)
    {
        goto L_0x00a59ff1;
    }
    // 00a59fe5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a59fe7  e82a050000             -call 0xa5a516
    cpu.esp -= 4;
    sub_a5a516(app, cpu);
    if (cpu.terminate) return;
    // 00a59fec  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a59fed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a59fef  ebe9                   -jmp 0xa59fda
    goto L_0x00a59fda;
L_0x00a59ff1:
    // 00a59ff1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a59ff3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ff4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59ff5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59ff6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59ff6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a59ff8  7503                   -jne 0xa59ffd
    if (!cpu.flags.zf)
    {
        goto L_0x00a59ffd;
    }
    // 00a59ffa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a59ffc:
    // 00a59ffc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a59ffd:
    // 00a59ffd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a59fff  74fb                   -je 0xa59ffc
    if (cpu.flags.zf)
    {
        goto L_0x00a59ffc;
    }
    // 00a5a001  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a002  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a004  e856d9ffff             -call 0xa5795f
    cpu.esp -= 4;
    sub_a5795f(app, cpu);
    if (cpu.terminate) return;
    // 00a5a009  83fa7b                 +cmp edx, 0x7b
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
    // 00a5a00c  7507                   -jne 0xa5a015
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a015;
    }
    // 00a5a00e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a5a013  eb31                   -jmp 0xa5a046
    goto L_0x00a5a046;
L_0x00a5a015:
    // 00a5a015  81face000000           +cmp edx, 0xce
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
    // 00a5a01b  7507                   -jne 0xa5a024
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a024;
    }
    // 00a5a01d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a5a022  eb22                   -jmp 0xa5a046
    goto L_0x00a5a046;
L_0x00a5a024:
    // 00a5a024  81fab7000000           +cmp edx, 0xb7
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
    // 00a5a02a  7507                   -jne 0xa5a033
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a033;
    }
    // 00a5a02c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a5a031  eb13                   -jmp 0xa5a046
    goto L_0x00a5a046;
L_0x00a5a033:
    // 00a5a033  83fa13                 +cmp edx, 0x13
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
    // 00a5a036  7605                   -jbe 0xa5a03d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a5a03d;
    }
    // 00a5a038  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00a5a03d:
    // 00a5a03d  8b82a1dfa500           -mov eax, dword ptr [edx + 0xa5dfa1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10870689) /* 0xa5dfa1 */);
    // 00a5a043  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00a5a046:
    // 00a5a046  e8e8d8ffff             -call 0xa57933
    cpu.esp -= 4;
    sub_a57933(app, cpu);
    if (cpu.terminate) return;
    // 00a5a04b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a5a050  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a051  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a001(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a5a001;
    // 00a59ff6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a59ff8  7503                   -jne 0xa59ffd
    if (!cpu.flags.zf)
    {
        goto L_0x00a59ffd;
    }
    // 00a59ffa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a59ffc:
    // 00a59ffc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a59ffd:
    // 00a59ffd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a59fff  74fb                   -je 0xa59ffc
    if (cpu.flags.zf)
    {
        goto L_0x00a59ffc;
    }
L_entry_0x00a5a001:
    // 00a5a001  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a002  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a004  e856d9ffff             -call 0xa5795f
    cpu.esp -= 4;
    sub_a5795f(app, cpu);
    if (cpu.terminate) return;
    // 00a5a009  83fa7b                 +cmp edx, 0x7b
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
    // 00a5a00c  7507                   -jne 0xa5a015
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a015;
    }
    // 00a5a00e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a5a013  eb31                   -jmp 0xa5a046
    goto L_0x00a5a046;
L_0x00a5a015:
    // 00a5a015  81face000000           +cmp edx, 0xce
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
    // 00a5a01b  7507                   -jne 0xa5a024
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a024;
    }
    // 00a5a01d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a5a022  eb22                   -jmp 0xa5a046
    goto L_0x00a5a046;
L_0x00a5a024:
    // 00a5a024  81fab7000000           +cmp edx, 0xb7
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
    // 00a5a02a  7507                   -jne 0xa5a033
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a033;
    }
    // 00a5a02c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a5a031  eb13                   -jmp 0xa5a046
    goto L_0x00a5a046;
L_0x00a5a033:
    // 00a5a033  83fa13                 +cmp edx, 0x13
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
    // 00a5a036  7605                   -jbe 0xa5a03d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a5a03d;
    }
    // 00a5a038  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00a5a03d:
    // 00a5a03d  8b82a1dfa500           -mov eax, dword ptr [edx + 0xa5dfa1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10870689) /* 0xa5dfa1 */);
    // 00a5a043  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00a5a046:
    // 00a5a046  e8e8d8ffff             -call 0xa57933
    cpu.esp -= 4;
    sub_a57933(app, cpu);
    if (cpu.terminate) return;
    // 00a5a04b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a5a050  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a051  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a052(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a052  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a053  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a054  2eff1564b9a500         -call dword ptr cs:[0xa5b964]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860900) /* 0xa5b964 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5a05b  e8a1ffffff             -call 0xa5a001
    cpu.esp -= 4;
    sub_a5a001(app, cpu);
    if (cpu.terminate) return;
    // 00a5a060  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a061  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a062  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a063(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a063  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a064  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a065  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a066  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5a067  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a5a069  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a5a06b  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00a5a06d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a5a06f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a071  7438                   -je 0xa5a0ab
    if (cpu.flags.zf)
    {
        goto L_0x00a5a0ab;
    }
L_0x00a5a073:
    // 00a5a073  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a5a075  7658                   -jbe 0xa5a0cf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a5a0cf;
    }
    // 00a5a077  803900                 +cmp byte ptr [ecx], 0
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
    // 00a5a07a  7418                   -je 0xa5a094
    if (cpu.flags.zf)
    {
        goto L_0x00a5a094;
    }
    // 00a5a07c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a5a081  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a5a083  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5a085  e856050000             -call 0xa5a5e0
    cpu.esp -= 4;
    sub_a5a5e0(app, cpu);
    if (cpu.terminate) return;
    // 00a5a08a  83f8ff                 +cmp eax, -1
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
    // 00a5a08d  750c                   -jne 0xa5a09b
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a09b;
    }
    // 00a5a08f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a090  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a091  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a092  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a093  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a094:
    // 00a5a094  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 00a5a099  eb34                   -jmp 0xa5a0cf
    goto L_0x00a5a0cf;
L_0x00a5a09b:
    // 00a5a09b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a09d  4d                     -dec ebp
    (cpu.ebp)--;
    // 00a5a09e  e873040000             -call 0xa5a516
    cpu.esp -= 4;
    sub_a5a516(app, cpu);
    if (cpu.terminate) return;
    // 00a5a0a3  83c602                 +add esi, 2
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
    // 00a5a0a6  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a5a0a7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5a0a9  ebc8                   -jmp 0xa5a073
    goto L_0x00a5a073;
L_0x00a5a0ab:
    // 00a5a0ab  803900                 +cmp byte ptr [ecx], 0
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
    // 00a5a0ae  741f                   -je 0xa5a0cf
    if (cpu.flags.zf)
    {
        goto L_0x00a5a0cf;
    }
    // 00a5a0b0  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a5a0b5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a5a0b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a0b9  e822050000             -call 0xa5a5e0
    cpu.esp -= 4;
    sub_a5a5e0(app, cpu);
    if (cpu.terminate) return;
    // 00a5a0be  83f8ff                 +cmp eax, -1
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
    // 00a5a0c1  740e                   -je 0xa5a0d1
    if (cpu.flags.zf)
    {
        goto L_0x00a5a0d1;
    }
    // 00a5a0c3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a0c5  e84c040000             -call 0xa5a516
    cpu.esp -= 4;
    sub_a5a516(app, cpu);
    if (cpu.terminate) return;
    // 00a5a0ca  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a5a0cb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5a0cd  ebdc                   -jmp 0xa5a0ab
    goto L_0x00a5a0ab;
L_0x00a5a0cf:
    // 00a5a0cf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a5a0d1:
    // 00a5a0d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a0d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a0d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a0d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a0d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a0d6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a0d6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a0d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a0d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a0d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a0da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a0db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5a0dc  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a5a0df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5a0e1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a5a0e6  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a5a0ea  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a5a0ed  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a5a0f2  e87d050000             -call 0xa5a674
    cpu.esp -= 4;
    sub_a5a674(app, cpu);
    if (cpu.terminate) return;
    // 00a5a0f7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a5a0f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a0fb  7458                   -je 0xa5a155
    if (cpu.flags.zf)
    {
        goto L_0x00a5a155;
    }
    // 00a5a0fd  39c8                   +cmp eax, ecx
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
    // 00a5a0ff  7454                   -je 0xa5a155
    if (cpu.flags.zf)
    {
        goto L_0x00a5a155;
    }
    // 00a5a101  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a5a103  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a5a105  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 00a5a107  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a5a109  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 00a5a10c  e8ffe4ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a111  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a5a113  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a5a117  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a119  743a                   -je 0xa5a155
    if (cpu.flags.zf)
    {
        goto L_0x00a5a155;
    }
    // 00a5a11b  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a5a11d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a5a11f  e812ecffff             -call 0xa58d36
    cpu.esp -= 4;
    sub_a58d36(app, cpu);
    if (cpu.terminate) return;
    // 00a5a124  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00a5a127  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a129  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 00a5a12f  e8efebffff             -call 0xa58d23
    cpu.esp -= 4;
    sub_a58d23(app, cpu);
    if (cpu.terminate) return;
    // 00a5a134  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a136  743d                   -je 0xa5a175
    if (cpu.flags.zf)
    {
        goto L_0x00a5a175;
    }
    // 00a5a138  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a13a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a5a13e  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a5a141  e8cae4ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a146  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a5a148  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a5a14a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a14c  7511                   -jne 0xa5a15f
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a15f;
    }
L_0x00a5a14e:
    // 00a5a14e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5a150  e8a8e5ffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a5a155:
    // 00a5a155  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a5a15a  e998000000             -jmp 0xa5a1f7
    goto L_0x00a5a1f7;
L_0x00a5a15f:
    // 00a5a15f  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a5a163  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a5a167  01f7                   +add edi, esi
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
    // 00a5a169  e8c8ebffff             -call 0xa58d36
    cpu.esp -= 4;
    sub_a58d36(app, cpu);
    if (cpu.terminate) return;
    // 00a5a16e  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 00a5a173  eb02                   -jmp 0xa5a177
    goto L_0x00a5a177;
L_0x00a5a175:
    // 00a5a175  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a5a177:
    // 00a5a177  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a5a17b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a5a17d  e808050000             -call 0xa5a68a
    cpu.esp -= 4;
    sub_a5a68a(app, cpu);
    if (cpu.terminate) return;
    // 00a5a182  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a184  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a5a188  e870e5ffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a5a18d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a5a18f  e869e5ffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a5a194  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a5a196  74bd                   -je 0xa5a155
    if (cpu.flags.zf)
    {
        goto L_0x00a5a155;
    }
    // 00a5a198  833d8cf0a50000         +cmp dword ptr [0xa5f08c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a19f  7505                   -jne 0xa5a1a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a1a6;
    }
    // 00a5a1a1  e8aa050000             -call 0xa5a750
    cpu.esp -= 4;
    sub_a5a750(app, cpu);
    if (cpu.terminate) return;
L_0x00a5a1a6:
    // 00a5a1a6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a1a8  e854000000             -call 0xa5a201
    cpu.esp -= 4;
    sub_a5a201(app, cpu);
    if (cpu.terminate) return;
    // 00a5a1ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a1af  75a4                   -jne 0xa5a155
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a155;
    }
    // 00a5a1b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a1b3  e86bebffff             -call 0xa58d23
    cpu.esp -= 4;
    sub_a58d23(app, cpu);
    if (cpu.terminate) return;
    // 00a5a1b8  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a5a1bb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a5a1bf  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a5a1c2  e849e4ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a1c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a5a1c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a1cb  750f                   -jne 0xa5a1dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a1dc;
    }
    // 00a5a1cd  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a5a1d2  e82afeffff             -call 0xa5a001
    cpu.esp -= 4;
    sub_a5a001(app, cpu);
    if (cpu.terminate) return;
    // 00a5a1d7  e979ffffff             -jmp 0xa5a155
    goto L_0x00a5a155;
L_0x00a5a1dc:
    // 00a5a1dc  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a5a1e0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a5a1e2  e8b9050000             -call 0xa5a7a0
    cpu.esp -= 4;
    sub_a5a7a0(app, cpu);
    if (cpu.terminate) return;
    // 00a5a1e7  83f8ff                 +cmp eax, -1
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
    // 00a5a1ea  0f845effffff           -je 0xa5a14e
    if (cpu.flags.zf)
    {
        goto L_0x00a5a14e;
    }
    // 00a5a1f0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5a1f2  e8b6faffff             -call 0xa59cad
    cpu.esp -= 4;
    sub_a59cad(app, cpu);
    if (cpu.terminate) return;
L_0x00a5a1f7:
    // 00a5a1f7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a5a1fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a1fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a1fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a1fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a1fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a1ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a1fa(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a5a1fa;
    // 00a5a0d6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a0d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a0d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a0d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a0da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a0db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5a0dc  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a5a0df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5a0e1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a5a0e6  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a5a0ea  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a5a0ed  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a5a0f2  e87d050000             -call 0xa5a674
    cpu.esp -= 4;
    sub_a5a674(app, cpu);
    if (cpu.terminate) return;
    // 00a5a0f7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a5a0f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a0fb  7458                   -je 0xa5a155
    if (cpu.flags.zf)
    {
        goto L_0x00a5a155;
    }
    // 00a5a0fd  39c8                   +cmp eax, ecx
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
    // 00a5a0ff  7454                   -je 0xa5a155
    if (cpu.flags.zf)
    {
        goto L_0x00a5a155;
    }
    // 00a5a101  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a5a103  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a5a105  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 00a5a107  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a5a109  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 00a5a10c  e8ffe4ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a111  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a5a113  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a5a117  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a119  743a                   -je 0xa5a155
    if (cpu.flags.zf)
    {
        goto L_0x00a5a155;
    }
    // 00a5a11b  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a5a11d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a5a11f  e812ecffff             -call 0xa58d36
    cpu.esp -= 4;
    sub_a58d36(app, cpu);
    if (cpu.terminate) return;
    // 00a5a124  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00a5a127  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a129  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 00a5a12f  e8efebffff             -call 0xa58d23
    cpu.esp -= 4;
    sub_a58d23(app, cpu);
    if (cpu.terminate) return;
    // 00a5a134  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a136  743d                   -je 0xa5a175
    if (cpu.flags.zf)
    {
        goto L_0x00a5a175;
    }
    // 00a5a138  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a13a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a5a13e  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a5a141  e8cae4ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a146  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a5a148  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a5a14a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a14c  7511                   -jne 0xa5a15f
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a15f;
    }
L_0x00a5a14e:
    // 00a5a14e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5a150  e8a8e5ffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a5a155:
    // 00a5a155  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a5a15a  e998000000             -jmp 0xa5a1f7
    goto L_0x00a5a1f7;
L_0x00a5a15f:
    // 00a5a15f  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a5a163  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a5a167  01f7                   +add edi, esi
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
    // 00a5a169  e8c8ebffff             -call 0xa58d36
    cpu.esp -= 4;
    sub_a58d36(app, cpu);
    if (cpu.terminate) return;
    // 00a5a16e  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 00a5a173  eb02                   -jmp 0xa5a177
    goto L_0x00a5a177;
L_0x00a5a175:
    // 00a5a175  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a5a177:
    // 00a5a177  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a5a17b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a5a17d  e808050000             -call 0xa5a68a
    cpu.esp -= 4;
    sub_a5a68a(app, cpu);
    if (cpu.terminate) return;
    // 00a5a182  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a184  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a5a188  e870e5ffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a5a18d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a5a18f  e869e5ffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a5a194  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a5a196  74bd                   -je 0xa5a155
    if (cpu.flags.zf)
    {
        goto L_0x00a5a155;
    }
    // 00a5a198  833d8cf0a50000         +cmp dword ptr [0xa5f08c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a19f  7505                   -jne 0xa5a1a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a1a6;
    }
    // 00a5a1a1  e8aa050000             -call 0xa5a750
    cpu.esp -= 4;
    sub_a5a750(app, cpu);
    if (cpu.terminate) return;
L_0x00a5a1a6:
    // 00a5a1a6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a1a8  e854000000             -call 0xa5a201
    cpu.esp -= 4;
    sub_a5a201(app, cpu);
    if (cpu.terminate) return;
    // 00a5a1ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a1af  75a4                   -jne 0xa5a155
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a155;
    }
    // 00a5a1b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a1b3  e86bebffff             -call 0xa58d23
    cpu.esp -= 4;
    sub_a58d23(app, cpu);
    if (cpu.terminate) return;
    // 00a5a1b8  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a5a1bb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a5a1bf  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a5a1c2  e849e4ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a1c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a5a1c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a1cb  750f                   -jne 0xa5a1dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a1dc;
    }
    // 00a5a1cd  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a5a1d2  e82afeffff             -call 0xa5a001
    cpu.esp -= 4;
    sub_a5a001(app, cpu);
    if (cpu.terminate) return;
    // 00a5a1d7  e979ffffff             -jmp 0xa5a155
    goto L_0x00a5a155;
L_0x00a5a1dc:
    // 00a5a1dc  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a5a1e0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a5a1e2  e8b9050000             -call 0xa5a7a0
    cpu.esp -= 4;
    sub_a5a7a0(app, cpu);
    if (cpu.terminate) return;
    // 00a5a1e7  83f8ff                 +cmp eax, -1
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
    // 00a5a1ea  0f845effffff           -je 0xa5a14e
    if (cpu.flags.zf)
    {
        goto L_0x00a5a14e;
    }
    // 00a5a1f0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5a1f2  e8b6faffff             -call 0xa59cad
    cpu.esp -= 4;
    sub_a59cad(app, cpu);
    if (cpu.terminate) return;
L_0x00a5a1f7:
    // 00a5a1f7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_entry_0x00a5a1fa:
    // 00a5a1fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a1fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a1fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a1fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a1fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a1ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a201(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a201  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a202  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a203  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a204  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a205  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a206  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5a207  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a5a20a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a5a20c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a20e  750a                   -jne 0xa5a21a
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a21a;
    }
L_0x00a5a210:
    // 00a5a210  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a5a215  e92b010000             -jmp 0xa5a345
    goto L_0x00a5a345;
L_0x00a5a21a:
    // 00a5a21a  66833800               +cmp word ptr [eax], 0
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
    // 00a5a21e  7416                   -je 0xa5a236
    if (cpu.flags.zf)
    {
        goto L_0x00a5a236;
    }
    // 00a5a220  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a5a223  eb09                   -jmp 0xa5a22e
    goto L_0x00a5a22e;
L_0x00a5a225:
    // 00a5a225  6683f93d               +cmp cx, 0x3d
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a5a229  740b                   -je 0xa5a236
    if (cpu.flags.zf)
    {
        goto L_0x00a5a236;
    }
    // 00a5a22b  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a5a22e:
    // 00a5a22e  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 00a5a231  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a5a234  75ef                   -jne 0xa5a225
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a225;
    }
L_0x00a5a236:
    // 00a5a236  66833a00               +cmp word ptr [edx], 0
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
    // 00a5a23a  74d4                   -je 0xa5a210
    if (cpu.flags.zf)
    {
        goto L_0x00a5a210;
    }
    // 00a5a23c  66837a0200             +cmp word ptr [edx + 2], 0
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
    // 00a5a241  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a5a244  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a5a246  8b0d8cf0a500           -mov ecx, dword ptr [0xa5f08c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */);
    // 00a5a24c  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00a5a24e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a5a250  7531                   -jne 0xa5a283
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a283;
    }
    // 00a5a252  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a5a254  0f85e9000000           -jne 0xa5a343
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a343;
    }
    // 00a5a25a  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a5a25f  e8ace3ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a264  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5a266  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a268  74a6                   -je 0xa5a210
    if (cpu.flags.zf)
    {
        goto L_0x00a5a210;
    }
    // 00a5a26a  a38cf0a500             -mov dword ptr [0xa5f08c], eax
    app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */) = cpu.eax;
    // 00a5a26f  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00a5a271  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a5a274  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a5a276  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00a5a279  a384f0a500             -mov dword ptr [0xa5f084], eax
    app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */) = cpu.eax;
    // 00a5a27e  e9b2000000             -jmp 0xa5a335
    goto L_0x00a5a335;
L_0x00a5a283:
    // 00a5a283  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a5a285  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a5a287  e8c1000000             -call 0xa5a34d
    cpu.esp -= 4;
    sub_a5a34d(app, cpu);
    if (cpu.terminate) return;
    // 00a5a28c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a5a28e  0f85af000000           -jne 0xa5a343
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a343;
    }
    // 00a5a294  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a296  0f8f96000000           -jg 0xa5a332
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a5a332;
    }
    // 00a5a29c  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a5a29e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a5a2a0  8b2d84f0a500           -mov ebp, dword ptr [0xa5f084]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */);
    // 00a5a2a6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a5a2a8  40                     -inc eax
    (cpu.eax)++;
    // 00a5a2a9  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00a5a2ac  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a5a2b0  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a5a2b3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a5a2b7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a5a2ba  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a2bc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a5a2be  7533                   -jne 0xa5a2f3
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a2f3;
    }
    // 00a5a2c0  e84be3ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a2c5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a5a2c7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5a2c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a2cb  0f843fffffff           -je 0xa5a210
    if (cpu.flags.zf)
    {
        goto L_0x00a5a210;
    }
    // 00a5a2d1  8b158cf0a500           -mov edx, dword ptr [0xa5f08c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */);
    // 00a5a2d7  e85aeaffff             -call 0xa58d36
    cpu.esp -= 4;
    sub_a58d36(app, cpu);
    if (cpu.terminate) return;
    // 00a5a2dc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a5a2df  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a5a2e3  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a5a2e5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a5a2e7  a384f0a500             -mov dword ptr [0xa5f084], eax
    app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */) = cpu.eax;
    // 00a5a2ec  e858afffff             -call 0xa55249
    cpu.esp -= 4;
    sub_a55249(app, cpu);
    if (cpu.terminate) return;
    // 00a5a2f1  eb2d                   -jmp 0xa5a320
    goto L_0x00a5a320;
L_0x00a5a2f3:
    // 00a5a2f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a2f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a2f7  e8e7d6ffff             -call 0xa579e3
    cpu.esp -= 4;
    sub_a579e3(app, cpu);
    if (cpu.terminate) return;
    // 00a5a2fc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5a2fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a300  0f840affffff           -je 0xa5a210
    if (cpu.flags.zf)
    {
        goto L_0x00a5a210;
    }
    // 00a5a306  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00a5a309  8b1584f0a500           -mov edx, dword ptr [0xa5f084]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */);
    // 00a5a30f  01c5                   +add ebp, eax
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
    // 00a5a311  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a5a313  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a5a315  e81c010000             -call 0xa5a436
    cpu.esp -= 4;
    sub_a5a436(app, cpu);
    if (cpu.terminate) return;
    // 00a5a31a  892d84f0a500           -mov dword ptr [0xa5f084], ebp
    app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */) = cpu.ebp;
L_0x00a5a320:
    // 00a5a320  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5a322  890d8cf0a500           -mov dword ptr [0xa5f08c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */) = cpu.ecx;
    // 00a5a328  c744810400000000       -mov dword ptr [ecx + eax*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 00a5a330  eb03                   -jmp 0xa5a335
    goto L_0x00a5a335;
L_0x00a5a332:
    // 00a5a332  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00a5a335:
    // 00a5a335  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5a337  893c81                 -mov dword ptr [ecx + eax*4], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = cpu.edi;
    // 00a5a33a  a184f0a500             -mov eax, dword ptr [0xa5f084]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */);
    // 00a5a33f  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
L_0x00a5a343:
    // 00a5a343  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a5a345:
    // 00a5a345  83c408                 +add esp, 8
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
    // 00a5a348  e9adfeffff             -jmp 0xa5a1fa
    return sub_a5a1fa(app, cpu);
}

/* align: skip  */
void sub_a5a34d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a34d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a34e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a34f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a350  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a351  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5a352  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a5a354  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a5a356  8b358cf0a500           -mov esi, dword ptr [0xa5f08c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */);
    // 00a5a35c  e9bb000000             -jmp 0xa5a41c
    goto L_0x00a5a41c;
L_0x00a5a361:
    // 00a5a361  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a5a363  e9a7000000             -jmp 0xa5a40f
    goto L_0x00a5a40f;
L_0x00a5a368:
    // 00a5a368  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a36a  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 00a5a36d  e8e4040000             -call 0xa5a856
    cpu.esp -= 4;
    sub_a5a856(app, cpu);
    if (cpu.terminate) return;
    // 00a5a372  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5a374  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a376  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 00a5a379  e8d8040000             -call 0xa5a856
    cpu.esp -= 4;
    sub_a5a856(app, cpu);
    if (cpu.terminate) return;
    // 00a5a37e  6639c1                 +cmp cx, ax
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
    // 00a5a381  0f8592000000           -jne 0xa5a419
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a419;
    }
    // 00a5a387  66833a3d               +cmp word ptr [edx], 0x3d
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
    // 00a5a38b  0f8578000000           -jne 0xa5a409
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a409;
    }
    // 00a5a391  8b158cf0a500           -mov edx, dword ptr [0xa5f08c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */);
    // 00a5a397  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a5a399  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a39b  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00a5a39e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a5a3a0  7462                   -je 0xa5a404
    if (cpu.flags.zf)
    {
        goto L_0x00a5a404;
    }
    // 00a5a3a2  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a5a3a4  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a5a3a6  eb08                   -jmp 0xa5a3b0
    goto L_0x00a5a3b0;
L_0x00a5a3a8:
    // 00a5a3a8  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a5a3ab  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a5a3ad  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a5a3b0:
    // 00a5a3b0  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a3b3  75f3                   -jne 0xa5a3a8
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a3a8;
    }
    // 00a5a3b5  8b3584f0a500           -mov esi, dword ptr [0xa5f084]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */);
    // 00a5a3bb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a5a3bd  7441                   -je 0xa5a400
    if (cpu.flags.zf)
    {
        goto L_0x00a5a400;
    }
    // 00a5a3bf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5a3c1  803c0700               +cmp byte ptr [edi + eax], 0
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
    // 00a5a3c5  7407                   -je 0xa5a3ce
    if (cpu.flags.zf)
    {
        goto L_0x00a5a3ce;
    }
    // 00a5a3c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a3c9  e82fe3ffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a5a3ce:
    // 00a5a3ce  8b2d8cf0a500           -mov ebp, dword ptr [0xa5f08c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */);
    // 00a5a3d4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a5a3d6  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a5a3d8  8b1584f0a500           -mov edx, dword ptr [0xa5f084]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */);
    // 00a5a3de  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00a5a3e1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a3e3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a5a3e5  e84c000000             -call 0xa5a436
    cpu.esp -= 4;
    sub_a5a436(app, cpu);
    if (cpu.terminate) return;
    // 00a5a3ea  890d84f0a500           -mov dword ptr [0xa5f084], ecx
    app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */) = cpu.ecx;
    // 00a5a3f0  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00a5a3f3  eb07                   -jmp 0xa5a3fc
    goto L_0x00a5a3fc;
L_0x00a5a3f5:
    // 00a5a3f5  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a5a3f8  47                     -inc edi
    (cpu.edi)++;
    // 00a5a3f9  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a5a3fb  40                     -inc eax
    (cpu.eax)++;
L_0x00a5a3fc:
    // 00a5a3fc  39f7                   +cmp edi, esi
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
    // 00a5a3fe  7cf5                   -jl 0xa5a3f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a5a3f5;
    }
L_0x00a5a400:
    // 00a5a400  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a5a402  eb2c                   -jmp 0xa5a430
    goto L_0x00a5a430;
L_0x00a5a404:
    // 00a5a404  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a5a407  eb27                   -jmp 0xa5a430
    goto L_0x00a5a430;
L_0x00a5a409:
    // 00a5a409  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a5a40c  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a5a40f:
    // 00a5a40f  66833b00               +cmp word ptr [ebx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a5a413  0f854fffffff           -jne 0xa5a368
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a368;
    }
L_0x00a5a419:
    // 00a5a419  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a5a41c:
    // 00a5a41c  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a5a41e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a5a420  0f853bffffff           -jne 0xa5a361
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a361;
    }
    // 00a5a426  a18cf0a500             -mov eax, dword ptr [0xa5f08c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10875020) /* 0xa5f08c */);
    // 00a5a42b  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a5a42d  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x00a5a430:
    // 00a5a430  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a431  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a432  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a433  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a434  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a435  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a436(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a436  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a437  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a438  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a439  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a5a43b  39c2                   +cmp edx, eax
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
    // 00a5a43d  7440                   -je 0xa5a47f
    if (cpu.flags.zf)
    {
        goto L_0x00a5a47f;
    }
    // 00a5a43f  7328                   -jae 0xa5a469
    if (!cpu.flags.cf)
    {
        goto L_0x00a5a469;
    }
    // 00a5a441  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00a5a444  39c7                   +cmp edi, eax
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
    // 00a5a446  7621                   -jbe 0xa5a469
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a5a469;
    }
    // 00a5a448  8d77ff                 -lea esi, [edi - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00a5a44b  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00a5a44e  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a5a450  4f                     -dec edi
    (cpu.edi)--;
    // 00a5a451  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a5a452  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a5a454  fd                     -std 
    cpu.flags.df = 1;
    // 00a5a455  4e                     -dec esi
    (cpu.esi)--;
    // 00a5a456  4f                     -dec edi
    (cpu.edi)--;
    // 00a5a457  d1e9                   +shr ecx, 1
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
    // 00a5a459  66f3a5                 -rep movsw word ptr es:[edi], word ptr [esi]
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
    // 00a5a45c  11c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00a5a45e  46                     -inc esi
    (cpu.esi)++;
    // 00a5a45f  47                     -inc edi
    (cpu.edi)++;
    // 00a5a460  66f3a4                 -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a5a463  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a5a464  fc                     -cld 
    cpu.flags.df = 0;
    // 00a5a465  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a466  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a467  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a468  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a469:
    // 00a5a469  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a5a46b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a5a46d  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a5a46f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a5a470  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a5a472  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a473  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a5a476  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a5a478  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a479  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a5a47c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a5a47e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00a5a47f:
    // 00a5a47f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a480  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a481  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a482  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a483(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a483  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a484  803800                 +cmp byte ptr [eax], 0
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
    // 00a5a487  7507                   -jne 0xa5a490
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a490;
    }
    // 00a5a489  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a5a48e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a48f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a490:
    // 00a5a490  833d10e8a50000         +cmp dword ptr [0xa5e810], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10872848) /* 0xa5e810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a497  7422                   -je 0xa5a4bb
    if (cpu.flags.zf)
    {
        goto L_0x00a5a4bb;
    }
    // 00a5a499  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a49b  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5a49d  8a9215e8a500           -mov dl, byte ptr [edx + 0xa5e815]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10872853) /* 0xa5e815 */);
    // 00a5a4a3  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a5a4a6  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a5a4ac  740d                   -je 0xa5a4bb
    if (cpu.flags.zf)
    {
        goto L_0x00a5a4bb;
    }
    // 00a5a4ae  80780100               +cmp byte ptr [eax + 1], 0
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
    // 00a5a4b2  7507                   -jne 0xa5a4bb
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a4bb;
    }
    // 00a5a4b4  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a5a4b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a4ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a4bb:
    // 00a5a4bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a4bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a4be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a4bf(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a4bf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a4c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a4c1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a5a4c4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a5a4c6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a5a4c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a4ca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a5a4cc  e895030000             -call 0xa5a866
    cpu.esp -= 4;
    sub_a5a866(app, cpu);
    if (cpu.terminate) return;
    // 00a5a4d1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a5a4d3  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a5a4d5  e883000000             -call 0xa5a55d
    cpu.esp -= 4;
    sub_a5a55d(app, cpu);
    if (cpu.terminate) return;
    // 00a5a4da  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a5a4dd  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a5a4e1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a5a4e3  e87e030000             -call 0xa5a866
    cpu.esp -= 4;
    sub_a5a866(app, cpu);
    if (cpu.terminate) return;
    // 00a5a4e8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a4ea  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a5a4ec  e86c000000             -call 0xa5a55d
    cpu.esp -= 4;
    sub_a5a55d(app, cpu);
    if (cpu.terminate) return;
    // 00a5a4f1  88740404               -mov byte ptr [esp + eax + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 00a5a4f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a5a4f7  e89b030000             -call 0xa5a897
    cpu.esp -= 4;
    sub_a5a897(app, cpu);
    if (cpu.terminate) return;
    // 00a5a4fc  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a5a500  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a5a504  e88e030000             -call 0xa5a897
    cpu.esp -= 4;
    sub_a5a897(app, cpu);
    if (cpu.terminate) return;
    // 00a5a509  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a5a50b  e878000000             -call 0xa5a588
    cpu.esp -= 4;
    sub_a5a588(app, cpu);
    if (cpu.terminate) return;
    // 00a5a510  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a5a513  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a514  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a515  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a516(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a516  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a517  833d10e8a50000         +cmp dword ptr [0xa5e810], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10872848) /* 0xa5e810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a51e  7420                   -je 0xa5a540
    if (cpu.flags.zf)
    {
        goto L_0x00a5a540;
    }
    // 00a5a520  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a522  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5a524  8a9215e8a500           -mov dl, byte ptr [edx + 0xa5e815]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10872853) /* 0xa5e815 */);
    // 00a5a52a  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a5a52d  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a5a533  740b                   -je 0xa5a540
    if (cpu.flags.zf)
    {
        goto L_0x00a5a540;
    }
    // 00a5a535  80780100               +cmp byte ptr [eax + 1], 0
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
    // 00a5a539  7405                   -je 0xa5a540
    if (cpu.flags.zf)
    {
        goto L_0x00a5a540;
    }
    // 00a5a53b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a5a53e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a53f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a540:
    // 00a5a540  40                     -inc eax
    (cpu.eax)++;
    // 00a5a541  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a542  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a543(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a543  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a544  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a5a546  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a548  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 00a5a54b  740c                   -je 0xa5a559
    if (cpu.flags.zf)
    {
        goto L_0x00a5a559;
    }
    // 00a5a54d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a5a54f  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00a5a552  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a5a555  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a5a557  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a559:
    // 00a5a559  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00a5a55b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a55c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a55d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a55d  833d10e8a50000         +cmp dword ptr [0xa5e810], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10872848) /* 0xa5e810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a564  741c                   -je 0xa5a582
    if (cpu.flags.zf)
    {
        goto L_0x00a5a582;
    }
    // 00a5a566  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5a568  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5a56d  8a8015e8a500           -mov al, byte ptr [eax + 0xa5e815]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10872853) /* 0xa5e815 */);
    // 00a5a573  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a5a575  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a5a57a  7406                   -je 0xa5a582
    if (cpu.flags.zf)
    {
        goto L_0x00a5a582;
    }
    // 00a5a57c  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a5a581  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a582:
    // 00a5a582  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a5a587  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a588(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a588  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a589  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a58a  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5a58c  3a1a                   +cmp bl, byte ptr [edx]
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
    // 00a5a58e  7541                   -jne 0xa5a5d1
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a5d1;
    }
    // 00a5a590  833d10e8a50000         +cmp dword ptr [0xa5e810], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10872848) /* 0xa5e810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a597  741f                   -je 0xa5a5b8
    if (cpu.flags.zf)
    {
        goto L_0x00a5a5b8;
    }
    // 00a5a599  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a5a59b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5a59d  8a9b15e8a500           -mov bl, byte ptr [ebx + 0xa5e815]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10872853) /* 0xa5e815 */);
    // 00a5a5a3  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a5a5a6  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a5a5ac  740a                   -je 0xa5a5b8
    if (cpu.flags.zf)
    {
        goto L_0x00a5a5b8;
    }
    // 00a5a5ae  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a5a5b1  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a5a5b4  38cb                   +cmp bl, cl
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
    // 00a5a5b6  7505                   -jne 0xa5a5bd
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a5bd;
    }
L_0x00a5a5b8:
    // 00a5a5b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a5ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a5bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a5bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a5bd:
    // 00a5a5bd  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00a5a5bf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5a5c4  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00a5a5c6  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5a5cc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a5ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a5cf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a5d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a5d1:
    // 00a5a5d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a5a5d3  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5a5d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a5d7  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a5a5d9  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a5db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a5a5dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a5de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a5df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a5e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a5e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a5e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a5e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a5e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5a5e4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a5a5e6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5a5e9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a5a5eb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a5a5ed  7507                   -jne 0xa5a5f6
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a5f6;
    }
L_0x00a5a5ef:
    // 00a5a5ef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a5a5f1  e977000000             -jmp 0xa5a66d
    goto L_0x00a5a66d;
L_0x00a5a5f6:
    // 00a5a5f6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a5a5f8  0f866a000000           -jbe 0xa5a668
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a5a668;
    }
    // 00a5a5fe  803a00                 +cmp byte ptr [edx], 0
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
    // 00a5a601  750b                   -jne 0xa5a60e
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a60e;
    }
    // 00a5a603  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a5a605  74e8                   -je 0xa5a5ef
    if (cpu.flags.zf)
    {
        goto L_0x00a5a5ef;
    }
    // 00a5a607  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 00a5a60c  ebe1                   -jmp 0xa5a5ef
    goto L_0x00a5a5ef;
L_0x00a5a60e:
    // 00a5a60e  833d10e8a50000         +cmp dword ptr [0xa5e810], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10872848) /* 0xa5e810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a615  7419                   -je 0xa5a630
    if (cpu.flags.zf)
    {
        goto L_0x00a5a630;
    }
    // 00a5a617  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a619  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a5a61b  8a8015e8a500           -mov al, byte ptr [eax + 0xa5e815]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10872853) /* 0xa5e815 */);
    // 00a5a621  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a5a623  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a5a628  7406                   -je 0xa5a630
    if (cpu.flags.zf)
    {
        goto L_0x00a5a630;
    }
    // 00a5a62a  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 00a5a62e  7438                   -je 0xa5a668
    if (cpu.flags.zf)
    {
        goto L_0x00a5a668;
    }
L_0x00a5a630:
    // 00a5a630  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a632  e826ffffff             -call 0xa5a55d
    cpu.esp -= 4;
    sub_a5a55d(app, cpu);
    if (cpu.terminate) return;
    // 00a5a637  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a5a639  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a5a63c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a5a63e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a63f  39c3                   +cmp ebx, eax
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
    // 00a5a641  7302                   -jae 0xa5a645
    if (!cpu.flags.cf)
    {
        goto L_0x00a5a645;
    }
    // 00a5a643  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a5a645:
    // 00a5a645  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5a646  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a647  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00a5a649  a1c4dba500             -mov eax, dword ptr [0xa5dbc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10869700) /* 0xa5dbc4 */);
    // 00a5a64e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5a64f  2eff1590b9a500         -call dword ptr cs:[0xa5b990]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860944) /* 0xa5b990 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5a656  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a658  740e                   -je 0xa5a668
    if (cpu.flags.zf)
    {
        goto L_0x00a5a668;
    }
    // 00a5a65a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a5a65c  7406                   -je 0xa5a664
    if (cpu.flags.zf)
    {
        goto L_0x00a5a664;
    }
    // 00a5a65e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a5a661  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x00a5a664:
    // 00a5a664  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a5a666  eb05                   -jmp 0xa5a66d
    goto L_0x00a5a66d;
L_0x00a5a668:
    // 00a5a668  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00a5a66d:
    // 00a5a66d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a5a66f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a670  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a671  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a672  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a673  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a674(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a674  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a675  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00a5a677:
    // 00a5a677  663b18                 +cmp bx, word ptr [eax]
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
    // 00a5a67a  740c                   -je 0xa5a688
    if (cpu.flags.zf)
    {
        goto L_0x00a5a688;
    }
    // 00a5a67c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a67e  40                     -inc eax
    (cpu.eax)++;
    // 00a5a67f  40                     -inc eax
    (cpu.eax)++;
    // 00a5a680  66833a00               +cmp word ptr [edx], 0
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
    // 00a5a684  75f1                   -jne 0xa5a677
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a677;
    }
    // 00a5a686  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a5a688:
    // 00a5a688  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a689  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a68a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a68a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a68b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a68c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a68d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a68e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5a68f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5a690  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a5a692  66813d21dba5000080     +cmp word ptr [0xa5db21], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(10869537) /* 0xa5db21 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a5a69b  730e                   -jae 0xa5a6ab
    if (!cpu.flags.cf)
    {
        goto L_0x00a5a6ab;
    }
    // 00a5a69d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a69e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5a69f  2eff159cb9a500         -call dword ptr cs:[0xa5b99c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860956) /* 0xa5b99c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5a6a6  e99c000000             -jmp 0xa5a747
    goto L_0x00a5a747;
L_0x00a5a6ab:
    // 00a5a6ab  e873e6ffff             -call 0xa58d23
    cpu.esp -= 4;
    sub_a58d23(app, cpu);
    if (cpu.terminate) return;
    // 00a5a6b0  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a6b2  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a5a6b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a6b7  e854dfffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a6bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a6be  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a5a6c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a6c2  0f847f000000           -je 0xa5a747
    if (cpu.flags.zf)
    {
        goto L_0x00a5a747;
    }
    // 00a5a6c8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a5a6ca  7504                   -jne 0xa5a6d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a6d0;
    }
    // 00a5a6cc  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a5a6ce  eb1d                   -jmp 0xa5a6ed
    goto L_0x00a5a6ed;
L_0x00a5a6d0:
    // 00a5a6d0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a5a6d2  e84ce6ffff             -call 0xa58d23
    cpu.esp -= 4;
    sub_a58d23(app, cpu);
    if (cpu.terminate) return;
    // 00a5a6d7  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a6d9  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a5a6dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a6de  e82ddfffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a6e3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a5a6e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a6e7  7504                   -jne 0xa5a6ed
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a6ed;
    }
    // 00a5a6e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a6eb  eb1e                   -jmp 0xa5a70b
    goto L_0x00a5a70b;
L_0x00a5a6ed:
    // 00a5a6ed  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a5a6f0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a5a6f2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a5a6f4  e8a7000000             -call 0xa5a7a0
    cpu.esp -= 4;
    sub_a5a7a0(app, cpu);
    if (cpu.terminate) return;
    // 00a5a6f9  83f8ff                 +cmp eax, -1
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
    // 00a5a6fc  7516                   -jne 0xa5a714
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a714;
    }
    // 00a5a6fe  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a5a700  e8f8dfffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a5a705  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a5a707  7407                   -je 0xa5a710
    if (cpu.flags.zf)
    {
        goto L_0x00a5a710;
    }
L_0x00a5a709:
    // 00a5a709  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a5a70b:
    // 00a5a70b  e8eddfffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a5a710:
    // 00a5a710  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a5a712  eb33                   -jmp 0xa5a747
    goto L_0x00a5a747;
L_0x00a5a714:
    // 00a5a714  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a5a716  7410                   -je 0xa5a728
    if (cpu.flags.zf)
    {
        goto L_0x00a5a728;
    }
    // 00a5a718  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a5a71a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a5a71c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5a71e  e87d000000             -call 0xa5a7a0
    cpu.esp -= 4;
    sub_a5a7a0(app, cpu);
    if (cpu.terminate) return;
    // 00a5a723  83f8ff                 +cmp eax, -1
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
    // 00a5a726  74e1                   -je 0xa5a709
    if (cpu.flags.zf)
    {
        goto L_0x00a5a709;
    }
L_0x00a5a728:
    // 00a5a728  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a729  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5a72a  2eff1598b9a500         -call dword ptr cs:[0xa5b998]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860952) /* 0xa5b998 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5a731  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a733  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a5a735  e8c3dfffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a5a73a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a5a73c  7407                   -je 0xa5a745
    if (cpu.flags.zf)
    {
        goto L_0x00a5a745;
    }
    // 00a5a73e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5a740  e8b8dfffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a5a745:
    // 00a5a745  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a5a747:
    // 00a5a747  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5a74a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a74b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a74c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a74d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a74e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a74f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a750(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a753  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a754  8b3588f0a500           -mov esi, dword ptr [0xa5f088]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
    // 00a5a75a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a5a75c  743d                   -je 0xa5a79b
    if (cpu.flags.zf)
    {
        goto L_0x00a5a79b;
    }
L_0x00a5a75e:
    // 00a5a75e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a5a760  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5a763  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a5a765  7434                   -je 0xa5a79b
    if (cpu.flags.zf)
    {
        goto L_0x00a5a79b;
    }
    // 00a5a767  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a769  e866f8ffff             -call 0xa59fd4
    cpu.esp -= 4;
    sub_a59fd4(app, cpu);
    if (cpu.terminate) return;
    // 00a5a76e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a5a771  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 00a5a774  e897deffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a5a779  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5a77b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a77d  74df                   -je 0xa5a75e
    if (cpu.flags.zf)
    {
        goto L_0x00a5a75e;
    }
    // 00a5a77f  e8dff8ffff             -call 0xa5a063
    cpu.esp -= 4;
    sub_a5a063(app, cpu);
    if (cpu.terminate) return;
    // 00a5a784  83f8ff                 +cmp eax, -1
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
    // 00a5a787  7409                   -je 0xa5a792
    if (cpu.flags.zf)
    {
        goto L_0x00a5a792;
    }
    // 00a5a789  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a78b  e871faffff             -call 0xa5a201
    cpu.esp -= 4;
    sub_a5a201(app, cpu);
    if (cpu.terminate) return;
    // 00a5a790  ebcc                   -jmp 0xa5a75e
    goto L_0x00a5a75e;
L_0x00a5a792:
    // 00a5a792  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a794  e864dfffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a5a799  ebc3                   -jmp 0xa5a75e
    goto L_0x00a5a75e;
L_0x00a5a79b:
    // 00a5a79b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a79c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a79d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a79e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a79f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a7a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a7a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a7a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5a7a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a7a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5a7a4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a5a7a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5a7a8  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a5a7aa  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a5a7ae  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a5a7b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a7b2  0f8472000000           -je 0xa5a82a
    if (cpu.flags.zf)
    {
        goto L_0x00a5a82a;
    }
L_0x00a5a7b8:
    // 00a5a7b8  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a5a7bd  0f8689000000           -jbe 0xa5a84c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a5a84c;
    }
    // 00a5a7c3  668b4d00               -mov cx, word ptr [ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp);
    // 00a5a7c7  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a5a7ca  7421                   -je 0xa5a7ed
    if (cpu.flags.zf)
    {
        goto L_0x00a5a7ed;
    }
    // 00a5a7cc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a7ce  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a5a7d2  6689ca                 -mov dx, cx
    cpu.dx = cpu.cx;
    // 00a5a7d5  e85db8ffff             -call 0xa56037
    cpu.esp -= 4;
    sub_a56037(app, cpu);
    if (cpu.terminate) return;
    // 00a5a7da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a7dc  83f8ff                 +cmp eax, -1
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
    // 00a5a7df  0f8469000000           -je 0xa5a84e
    if (cpu.flags.zf)
    {
        goto L_0x00a5a84e;
    }
    // 00a5a7e5  3b442404               +cmp eax, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a7e9  7761                   -ja 0xa5a84c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a5a84c;
    }
    // 00a5a7eb  eb08                   -jmp 0xa5a7f5
    goto L_0x00a5a7f5;
L_0x00a5a7ed:
    // 00a5a7ed  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a5a7f0  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a5a7f3  eb57                   -jmp 0xa5a84c
    goto L_0x00a5a84c;
L_0x00a5a7f5:
    // 00a5a7f5  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a5a7f9  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a5a7fc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5a7fe  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a5a7ff  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a5a801  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a5a803  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5a804  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a806  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a5a809  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a5a80b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a5a80d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a5a810  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a5a812  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a813  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a5a814  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a5a817  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a819  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a5a81d  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a81f  29d0                   +sub eax, edx
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
    // 00a5a821  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00a5a824  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a5a828  eb8e                   -jmp 0xa5a7b8
    goto L_0x00a5a7b8;
L_0x00a5a82a:
    // 00a5a82a  66837d0000             +cmp word ptr [ebp], 0
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
    // 00a5a82f  741b                   -je 0xa5a84c
    if (cpu.flags.zf)
    {
        goto L_0x00a5a84c;
    }
    // 00a5a831  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a833  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a5a837  668b5500               -mov dx, word ptr [ebp]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp);
    // 00a5a83b  e8f7b7ffff             -call 0xa56037
    cpu.esp -= 4;
    sub_a56037(app, cpu);
    if (cpu.terminate) return;
    // 00a5a840  83f8ff                 +cmp eax, -1
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
    // 00a5a843  7409                   -je 0xa5a84e
    if (cpu.flags.zf)
    {
        goto L_0x00a5a84e;
    }
    // 00a5a845  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a5a848  01c3                   +add ebx, eax
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
    // 00a5a84a  ebde                   -jmp 0xa5a82a
    goto L_0x00a5a82a;
L_0x00a5a84c:
    // 00a5a84c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a5a84e:
    // 00a5a84e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a5a851  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a852  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a853  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a854  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a855  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a856(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a856  663d6100               +cmp ax, 0x61
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
    // 00a5a85a  7209                   -jb 0xa5a865
    if (cpu.flags.cf)
    {
        goto L_0x00a5a865;
    }
    // 00a5a85c  663d7a00               +cmp ax, 0x7a
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
    // 00a5a860  7703                   -ja 0xa5a865
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a5a865;
    }
    // 00a5a862  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a5a865:
    // 00a5a865  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a866(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a866  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a867  833d10e8a50000         +cmp dword ptr [0xa5e810], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10872848) /* 0xa5e810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a86e  7421                   -je 0xa5a891
    if (cpu.flags.zf)
    {
        goto L_0x00a5a891;
    }
    // 00a5a870  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a5a872  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a5a874  8a9b15e8a500           -mov bl, byte ptr [ebx + 0xa5e815]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10872853) /* 0xa5e815 */);
    // 00a5a87a  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a5a87d  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a5a883  740c                   -je 0xa5a891
    if (cpu.flags.zf)
    {
        goto L_0x00a5a891;
    }
    // 00a5a885  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a5a887  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00a5a889  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a5a88c  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 00a5a88f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a890  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a891:
    // 00a5a891  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a5a893  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a5a895  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a896  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a897(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a897  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a898  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a899  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a89a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5a89d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00a5a89f:
    // 00a5a89f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a5a8a1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a5a8a3  e8dbfbffff             -call 0xa5a483
    cpu.esp -= 4;
    sub_a5a483(app, cpu);
    if (cpu.terminate) return;
    // 00a5a8a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a8aa  7531                   -jne 0xa5a8dd
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a8dd;
    }
    // 00a5a8ac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a5a8ae  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a5a8b0  e831000000             -call 0xa5a8e6
    cpu.esp -= 4;
    sub_a5a8e6(app, cpu);
    if (cpu.terminate) return;
    // 00a5a8b5  e867000000             -call 0xa5a921
    cpu.esp -= 4;
    sub_a5a921(app, cpu);
    if (cpu.terminate) return;
    // 00a5a8ba  e884fcffff             -call 0xa5a543
    cpu.esp -= 4;
    sub_a5a543(app, cpu);
    if (cpu.terminate) return;
    // 00a5a8bf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a5a8c1  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 00a5a8c3  e895fcffff             -call 0xa5a55d
    cpu.esp -= 4;
    sub_a5a55d(app, cpu);
    if (cpu.terminate) return;
    // 00a5a8c8  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a5a8cb  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a5a8cd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a5a8cf  e892ffffff             -call 0xa5a866
    cpu.esp -= 4;
    sub_a5a866(app, cpu);
    if (cpu.terminate) return;
    // 00a5a8d4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a5a8d6  e83bfcffff             -call 0xa5a516
    cpu.esp -= 4;
    sub_a5a516(app, cpu);
    if (cpu.terminate) return;
    // 00a5a8db  ebc2                   -jmp 0xa5a89f
    goto L_0x00a5a89f;
L_0x00a5a8dd:
    // 00a5a8dd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5a8df  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5a8e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a8e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a8e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a8e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a8e6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a8e6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a8e7  833d10e8a50000         +cmp dword ptr [0xa5e810], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10872848) /* 0xa5e810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a8ee  7428                   -je 0xa5a918
    if (cpu.flags.zf)
    {
        goto L_0x00a5a918;
    }
    // 00a5a8f0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a8f2  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5a8f4  8a9215e8a500           -mov dl, byte ptr [edx + 0xa5e815]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10872853) /* 0xa5e815 */);
    // 00a5a8fa  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a5a8fd  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a5a903  7413                   -je 0xa5a918
    if (cpu.flags.zf)
    {
        goto L_0x00a5a918;
    }
    // 00a5a905  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a907  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5a909  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a5a90c  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a5a90f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5a914  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a916  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a917  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a918:
    // 00a5a918  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5a91a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5a91f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a920  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a921(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a921  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5a922  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5a923  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a924  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5a927  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a5a929  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a5a92b  e813fcffff             -call 0xa5a543
    cpu.esp -= 4;
    sub_a5a543(app, cpu);
    if (cpu.terminate) return;
    // 00a5a930  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a5a932  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a5a934  e824fcffff             -call 0xa5a55d
    cpu.esp -= 4;
    sub_a5a55d(app, cpu);
    if (cpu.terminate) return;
    // 00a5a939  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a5a93c  813dc4dba500a4030000   +cmp dword ptr [0xa5dbc4], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10869700) /* 0xa5dbc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a946  7526                   -jne 0xa5a96e
    if (!cpu.flags.zf)
    {
        goto L_0x00a5a96e;
    }
    // 00a5a948  833d10e8a50000         +cmp dword ptr [0xa5e810], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10872848) /* 0xa5e810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a94f  741d                   -je 0xa5a96e
    if (cpu.flags.zf)
    {
        goto L_0x00a5a96e;
    }
    // 00a5a951  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5a953  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00a5a956  8a8015e8a500           -mov al, byte ptr [eax + 0xa5e815]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10872853) /* 0xa5e815 */);
    // 00a5a95c  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a5a95e  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a5a963  7409                   -je 0xa5a96e
    if (cpu.flags.zf)
    {
        goto L_0x00a5a96e;
    }
    // 00a5a965  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a5a967  e81e000000             -call 0xa5a98a
    cpu.esp -= 4;
    sub_a5a98a(app, cpu);
    if (cpu.terminate) return;
    // 00a5a96c  eb15                   -jmp 0xa5a983
    goto L_0x00a5a983;
L_0x00a5a96e:
    // 00a5a96e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a5a970  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a5a974  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5a975  2eff151cb9a500         -call dword ptr cs:[0xa5b91c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860828) /* 0xa5b91c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5a97c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a5a97e  e863ffffff             -call 0xa5a8e6
    cpu.esp -= 4;
    sub_a5a8e6(app, cpu);
    if (cpu.terminate) return;
L_0x00a5a983:
    // 00a5a983  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5a986  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a987  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a988  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a989  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a98a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a98a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a98b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a98d  e80b000000             -call 0xa5a99d
    cpu.esp -= 4;
    sub_a5a99d(app, cpu);
    if (cpu.terminate) return;
    // 00a5a992  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a994  7403                   -je 0xa5a999
    if (cpu.flags.zf)
    {
        goto L_0x00a5a999;
    }
    // 00a5a996  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x00a5a999:
    // 00a5a999  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a99b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a99c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a99d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a99d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a99e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a9a0  e83b000000             -call 0xa5a9e0
    cpu.esp -= 4;
    sub_a5a9e0(app, cpu);
    if (cpu.terminate) return;
    // 00a5a9a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5a9a7  741f                   -je 0xa5a9c8
    if (cpu.flags.zf)
    {
        goto L_0x00a5a9c8;
    }
    // 00a5a9a9  81fa81820000           +cmp edx, 0x8281
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
    // 00a5a9af  7211                   -jb 0xa5a9c2
    if (cpu.flags.cf)
    {
        goto L_0x00a5a9c2;
    }
    // 00a5a9b1  81fa9a820000           +cmp edx, 0x829a
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
    // 00a5a9b7  7709                   -ja 0xa5a9c2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a5a9c2;
    }
    // 00a5a9b9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a5a9be  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a9c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a9c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a9c2:
    // 00a5a9c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a9c4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a9c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a9c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5a9c8:
    // 00a5a9c8  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a5a9ca  fec0                   -inc al
    (cpu.al)++;
    // 00a5a9cc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a9ce  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00a5a9d0  8a8218dda500           -mov al, byte ptr [edx + 0xa5dd18]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10870040) /* 0xa5dd18 */);
    // 00a5a9d6  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a5a9d8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5a9da  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00a5a9dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5a9de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5a9df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5a9e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5a9e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5a9e1  833d10e8a50000         +cmp dword ptr [0xa5e810], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10872848) /* 0xa5e810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5a9e8  7431                   -je 0xa5aa1b
    if (cpu.flags.zf)
    {
        goto L_0x00a5aa1b;
    }
    // 00a5a9ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5a9ec  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a5a9ef  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5a9f5  8a9215e8a500           -mov dl, byte ptr [edx + 0xa5e815]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10872853) /* 0xa5e815 */);
    // 00a5a9fb  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a5a9fe  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a5aa04  7415                   -je 0xa5aa1b
    if (cpu.flags.zf)
    {
        goto L_0x00a5aa1b;
    }
    // 00a5aa06  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5aa0b  e80f000000             -call 0xa5aa1f
    cpu.esp -= 4;
    sub_a5aa1f(app, cpu);
    if (cpu.terminate) return;
    // 00a5aa10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5aa12  7407                   -je 0xa5aa1b
    if (cpu.flags.zf)
    {
        goto L_0x00a5aa1b;
    }
    // 00a5aa14  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a5aa19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5aa1a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5aa1b:
    // 00a5aa1b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5aa1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5aa1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5aa1f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa1f  833d10e8a50000         +cmp dword ptr [0xa5e810], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10872848) /* 0xa5e810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5aa26  7429                   -je 0xa5aa51
    if (cpu.flags.zf)
    {
        goto L_0x00a5aa51;
    }
    // 00a5aa28  813dc4dba500a4030000   +cmp dword ptr [0xa5dbc4], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10869700) /* 0xa5dbc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5aa32  740a                   -je 0xa5aa3e
    if (cpu.flags.zf)
    {
        goto L_0x00a5aa3e;
    }
    // 00a5aa34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5aa36  741b                   -je 0xa5aa53
    if (cpu.flags.zf)
    {
        goto L_0x00a5aa53;
    }
    // 00a5aa38  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a5aa3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5aa3e:
    // 00a5aa3e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5aa43  8a80b9dfa500           -mov al, byte ptr [eax + 0xa5dfb9]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10870713) /* 0xa5dfb9 */);
    // 00a5aa49  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00a5aa4b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5aa50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5aa51:
    // 00a5aa51  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a5aa53:
    // 00a5aa53  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5aa54(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa54  ff251cb9a500           -jmp dword ptr [0xa5b91c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860828), cpu);
}

/* align: skip  */
void sub_a5aa5a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa5a  ff259cb9a500           -jmp dword ptr [0xa5b99c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860956), cpu);
}

/* align: skip  */
void sub_a5aa60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa60  ff2598b9a500           -jmp dword ptr [0xa5b998]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860952), cpu);
}

/* align: skip  */
void sub_a5aa66(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa66  ff2540b9a500           -jmp dword ptr [0xa5b940]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860864), cpu);
}

/* align: skip  */
void sub_a5aa6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa6c  ff25d0b9a500           -jmp dword ptr [0xa5b9d0]
    return app->dynamic_call(app->getMemory<x86::reg32>(10861008), cpu);
}

/* align: skip  */
void sub_a5aa72(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa72  ff2530b9a500           -jmp dword ptr [0xa5b930]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860848), cpu);
}

/* align: skip  */
void sub_a5aa78(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa78  ff2558b9a500           -jmp dword ptr [0xa5b958]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860888), cpu);
}

/* align: skip  */
void sub_a5aa7e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa7e  ff25a0b9a500           -jmp dword ptr [0xa5b9a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860960), cpu);
}

/* align: skip  */
void sub_a5aa84(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa84  ff25c8b9a500           -jmp dword ptr [0xa5b9c8]
    return app->dynamic_call(app->getMemory<x86::reg32>(10861000), cpu);
}

/* align: skip  */
void sub_a5aa8a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa8a  ff25c4b9a500           -jmp dword ptr [0xa5b9c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860996), cpu);
}

/* align: skip  */
void sub_a5aa90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa90  ff2594b9a500           -jmp dword ptr [0xa5b994]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860948), cpu);
}

/* align: skip  */
void sub_a5aa96(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa96  ff252cb9a500           -jmp dword ptr [0xa5b92c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860844), cpu);
}

/* align: skip  */
void sub_a5aa9c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aa9c  ff2560b9a500           -jmp dword ptr [0xa5b960]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860896), cpu);
}

/* align: skip  */
void sub_a5aaa2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aaa2  ff25acb9a500           -jmp dword ptr [0xa5b9ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860972), cpu);
}

/* align: skip  */
void sub_a5aaa8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aaa8  ff25c0b9a500           -jmp dword ptr [0xa5b9c0]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860992), cpu);
}

/* align: skip  */
void sub_a5aaae(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aaae  ff2578b9a500           -jmp dword ptr [0xa5b978]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860920), cpu);
}

/* align: skip  */
void sub_a5aab4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aab4  ff258cb9a500           -jmp dword ptr [0xa5b98c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860940), cpu);
}

/* align: skip  */
void sub_a5aaba(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aaba  ff25ccb9a500           -jmp dword ptr [0xa5b9cc]
    return app->dynamic_call(app->getMemory<x86::reg32>(10861004), cpu);
}

/* align: skip  */
void sub_a5aac0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aac0  ff2590b9a500           -jmp dword ptr [0xa5b990]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860944), cpu);
}

/* align: skip  */
void sub_a5aac6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aac6  ff256cb9a500           -jmp dword ptr [0xa5b96c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860908), cpu);
}

/* align: skip  */
void sub_a5aacc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aacc  ff25b4b9a500           -jmp dword ptr [0xa5b9b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860980), cpu);
}

/* align: skip  */
void sub_a5aad2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aad2  ff2524b9a500           -jmp dword ptr [0xa5b924]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860836), cpu);
}

/* align: skip  */
void sub_a5aad8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aad8  ff25bcb9a500           -jmp dword ptr [0xa5b9bc]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860988), cpu);
}

/* align: skip  */
void sub_a5aade(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aade  ff25b0b9a500           -jmp dword ptr [0xa5b9b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860976), cpu);
}

/* align: skip  */
void sub_a5aae4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aae4  ff25a4b9a500           -jmp dword ptr [0xa5b9a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860964), cpu);
}

/* align: skip  */
void sub_a5aaea(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5aaea  ff25b8b9a500           -jmp dword ptr [0xa5b9b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(10860984), cpu);
}

}
