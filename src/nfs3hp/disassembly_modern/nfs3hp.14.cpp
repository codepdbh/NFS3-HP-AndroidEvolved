#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip  */
void Application::sub_4493a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004493a3;
    // 00449366  90                     -nop 
    ;
    // 00449367  90                     -nop 
    ;
    // 00449368  90                     -nop 
    ;
    // 00449369  90                     -nop 
    ;
    // 0044936a  90                     -nop 
    ;
    // 0044936b  90                     -nop 
    ;
    // 0044936c  90                     -nop 
    ;
    // 0044936d  90                     -nop 
    ;
    // 0044936e  90                     -nop 
    ;
    // 0044936f  90                     -nop 
    ;
    // 00449370  90                     -nop 
    ;
    // 00449371  e8dafbffff             -call 0x448f50
    cpu.esp -= 4;
    sub_448f50(app, cpu);
    if (cpu.terminate) return;
    // 00449376  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044937b  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044937e  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00449381  eb10                   -jmp 0x449393
    goto L_0x00449393;
    // 00449383  e828feffff             -call 0x4491b0
    cpu.esp -= 4;
    sub_4491b0(app, cpu);
    if (cpu.terminate) return;
    // 00449388  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044938d  8d75e4                 -lea esi, [ebp - 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00449390  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00449393:
    // 00449393  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449394  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00449396  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00449399  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044939b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044939d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004493a0  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004493a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004493a3:
    // 004493a3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004493a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_449393(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00449393;
    // 00449366  90                     -nop 
    ;
    // 00449367  90                     -nop 
    ;
    // 00449368  90                     -nop 
    ;
    // 00449369  90                     -nop 
    ;
    // 0044936a  90                     -nop 
    ;
    // 0044936b  90                     -nop 
    ;
    // 0044936c  90                     -nop 
    ;
    // 0044936d  90                     -nop 
    ;
    // 0044936e  90                     -nop 
    ;
    // 0044936f  90                     -nop 
    ;
    // 00449370  90                     -nop 
    ;
    // 00449371  e8dafbffff             -call 0x448f50
    cpu.esp -= 4;
    sub_448f50(app, cpu);
    if (cpu.terminate) return;
    // 00449376  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044937b  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044937e  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00449381  eb10                   -jmp 0x449393
    goto L_0x00449393;
    // 00449383  e828feffff             -call 0x4491b0
    cpu.esp -= 4;
    sub_4491b0(app, cpu);
    if (cpu.terminate) return;
    // 00449388  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044938d  8d75e4                 -lea esi, [ebp - 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00449390  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00449393:
L_entry_0x00449393:
    // 00449393  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449394  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00449396  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00449399  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044939b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044939d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004493a0  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004493a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004493a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_449383(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00449383;
    // 00449366  90                     -nop 
    ;
    // 00449367  90                     -nop 
    ;
    // 00449368  90                     -nop 
    ;
    // 00449369  90                     -nop 
    ;
    // 0044936a  90                     -nop 
    ;
    // 0044936b  90                     -nop 
    ;
    // 0044936c  90                     -nop 
    ;
    // 0044936d  90                     -nop 
    ;
    // 0044936e  90                     -nop 
    ;
    // 0044936f  90                     -nop 
    ;
    // 00449370  90                     -nop 
    ;
    // 00449371  e8dafbffff             -call 0x448f50
    cpu.esp -= 4;
    sub_448f50(app, cpu);
    if (cpu.terminate) return;
    // 00449376  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044937b  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044937e  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00449381  eb10                   -jmp 0x449393
    goto L_0x00449393;
L_entry_0x00449383:
    // 00449383  e828feffff             -call 0x4491b0
    cpu.esp -= 4;
    sub_4491b0(app, cpu);
    if (cpu.terminate) return;
    // 00449388  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044938d  8d75e4                 -lea esi, [ebp - 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00449390  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00449393:
    // 00449393  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449394  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00449396  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00449399  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044939b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044939d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004493a0  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004493a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004493a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_449371(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00449371;
    // 00449366  90                     -nop 
    ;
    // 00449367  90                     -nop 
    ;
    // 00449368  90                     -nop 
    ;
    // 00449369  90                     -nop 
    ;
    // 0044936a  90                     -nop 
    ;
    // 0044936b  90                     -nop 
    ;
    // 0044936c  90                     -nop 
    ;
    // 0044936d  90                     -nop 
    ;
    // 0044936e  90                     -nop 
    ;
    // 0044936f  90                     -nop 
    ;
    // 00449370  90                     -nop 
    ;
L_entry_0x00449371:
    // 00449371  e8dafbffff             -call 0x448f50
    cpu.esp -= 4;
    sub_448f50(app, cpu);
    if (cpu.terminate) return;
    // 00449376  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044937b  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044937e  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00449381  eb10                   -jmp 0x449393
    goto L_0x00449393;
    // 00449383  e828feffff             -call 0x4491b0
    cpu.esp -= 4;
    sub_4491b0(app, cpu);
    if (cpu.terminate) return;
    // 00449388  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044938d  8d75e4                 -lea esi, [ebp - 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00449390  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00449393:
    // 00449393  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449394  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00449396  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00449399  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044939b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044939d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004493a0  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004493a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004493a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4493b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004493b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004493b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004493b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004493b3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004493b5  81ec14050000           -sub esp, 0x514
    (cpu.esp) -= x86::reg32(x86::sreg32(1300 /*0x514*/));
    // 004493bb  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004493be  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004493c1  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004493c4  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004493c7  b940010000             -mov ecx, 0x140
    cpu.ecx = 320 /*0x140*/;
    // 004493cc  8dbdecfaffff           -lea edi, [ebp - 0x514]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 004493d2  bef0894400             -mov esi, 0x4489f0
    cpu.esi = 4491760 /*0x4489f0*/;
    // 004493d7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004493d9  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
L_0x004493db:
    // 004493db  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004493de  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004493e1  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004493e4  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004493e7  ba01050000             -mov edx, 0x501
    cpu.edx = 1281 /*0x501*/;
    // 004493ec  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004493ef  8d85ecfaffff           -lea eax, [ebp - 0x514]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 004493f5  e876710a00             -call 0x4f0570
    cpu.esp -= 4;
    sub_4f0570(app, cpu);
    if (cpu.terminate) return;
    // 004493fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004493fc  0f84fc000000           -je 0x4494fe
    if (cpu.flags.zf)
    {
        goto L_0x004494fe;
    }
    // 00449402  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00449405  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00449407  42                     -inc edx
    (cpu.edx)++;
    // 00449408  8dbdecfaffff           -lea edi, [ebp - 0x514]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 0044940e  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00449410  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449412  49                     -dec ecx
    (cpu.ecx)--;
    // 00449413  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00449415  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00449417  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00449419  49                     -dec ecx
    (cpu.ecx)--;
    // 0044941a  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
L_0x0044941d:
    // 0044941d  83f8ff                 +cmp eax, -1
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
    // 00449420  7e1d                   -jle 0x44943f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044943f;
    }
    // 00449422  8a9428ecfaffff         -mov dl, byte ptr [eax + ebp - 0x514]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1);
    // 00449429  80fa0a                 +cmp dl, 0xa
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044942c  7405                   -je 0x449433
    if (cpu.flags.zf)
    {
        goto L_0x00449433;
    }
    // 0044942e  80fa0d                 +cmp dl, 0xd
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00449431  7509                   -jne 0x44943c
    if (!cpu.flags.zf)
    {
        goto L_0x0044943c;
    }
L_0x00449433:
    // 00449433  30db                   +xor bl, bl
    cpu.clear_co();
    cpu.set_szp((cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl))));
    // 00449435  889c28ecfaffff         -mov byte ptr [eax + ebp - 0x514], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1) = cpu.bl;
L_0x0044943c:
    // 0044943c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044943d  ebde                   -jmp 0x44941d
    goto L_0x0044941d;
L_0x0044943f:
    // 0044943f  8dbdecfaffff           -lea edi, [ebp - 0x514]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 00449445  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449447  49                     -dec ecx
    (cpu.ecx)--;
    // 00449448  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044944a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044944c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0044944e  49                     -dec ecx
    (cpu.ecx)--;
    // 0044944f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00449451  7502                   -jne 0x449455
    if (!cpu.flags.zf)
    {
        goto L_0x00449455;
    }
    // 00449453  eb86                   -jmp 0x4493db
    goto L_0x004493db;
L_0x00449455:
    // 00449455  80bdecfaffff3b         +cmp byte ptr [ebp - 0x514], 0x3b
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(59 /*0x3b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044945c  7505                   -jne 0x449463
    if (!cpu.flags.zf)
    {
        goto L_0x00449463;
    }
    // 0044945e  e978ffffff             -jmp 0x4493db
    goto L_0x004493db;
L_0x00449463:
    // 00449463  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00449465  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00449467:
    // 00449467  8a8c28ecfaffff         -mov cl, byte ptr [eax + ebp - 0x514]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1);
    // 0044946e  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00449470  7422                   -je 0x449494
    if (cpu.flags.zf)
    {
        goto L_0x00449494;
    }
    // 00449472  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00449475  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00449477  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00449479  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0044947b  40                     -inc eax
    (cpu.eax)++;
    // 0044947c  42                     -inc edx
    (cpu.edx)++;
    // 0044947d  8819                   -mov byte ptr [ecx], bl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bl;
    // 0044947f  80fb3d                 +cmp bl, 0x3d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00449482  7503                   -jne 0x449487
    if (!cpu.flags.zf)
    {
        goto L_0x00449487;
    }
    // 00449484  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00449485  eb0d                   -jmp 0x449494
    goto L_0x00449494;
L_0x00449487:
    // 00449487  80fb20                 +cmp bl, 0x20
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044948a  7405                   -je 0x449491
    if (cpu.flags.zf)
    {
        goto L_0x00449491;
    }
    // 0044948c  80fb09                 +cmp bl, 9
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044948f  75d6                   -jne 0x449467
    if (!cpu.flags.zf)
    {
        goto L_0x00449467;
    }
L_0x00449491:
    // 00449491  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00449492  ebd3                   -jmp 0x449467
    goto L_0x00449467;
L_0x00449494:
    // 00449494  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00449497  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449499  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 0044949c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044949e  7505                   -jne 0x4494a5
    if (!cpu.flags.zf)
    {
        goto L_0x004494a5;
    }
    // 004494a0  e936ffffff             -jmp 0x4493db
    goto L_0x004493db;
L_0x004494a5:
    // 004494a5  80bc28ecfaffff00       +cmp byte ptr [eax + ebp - 0x514], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004494ad  7510                   -jne 0x4494bf
    if (!cpu.flags.zf)
    {
        goto L_0x004494bf;
    }
    // 004494af  8079ff5d               +cmp byte ptr [ecx - 1], 0x5d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(93 /*0x5d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004494b3  740a                   -je 0x4494bf
    if (cpu.flags.zf)
    {
        goto L_0x004494bf;
    }
    // 004494b5  e8666c0a00             -call 0x4f0120
    cpu.esp -= 4;
    sub_4f0120(app, cpu);
    if (cpu.terminate) return;
    // 004494ba  e91cffffff             -jmp 0x4493db
    goto L_0x004493db;
L_0x004494bf:
    // 004494bf  8a9c28ecfaffff         -mov bl, byte ptr [eax + ebp - 0x514]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1);
    // 004494c6  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004494c8  7410                   -je 0x4494da
    if (cpu.flags.zf)
    {
        goto L_0x004494da;
    }
    // 004494ca  40                     -inc eax
    (cpu.eax)++;
    // 004494cb  88da                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 004494cd  80fb20                 +cmp bl, 0x20
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004494d0  74ed                   -je 0x4494bf
    if (cpu.flags.zf)
    {
        goto L_0x004494bf;
    }
    // 004494d2  80fb09                 +cmp bl, 9
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004494d5  7502                   -jne 0x4494d9
    if (!cpu.flags.zf)
    {
        goto L_0x004494d9;
    }
    // 004494d7  ebe6                   -jmp 0x4494bf
    goto L_0x004494bf;
L_0x004494d9:
    // 004494d9  48                     -dec eax
    (cpu.eax)--;
L_0x004494da:
    // 004494da  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004494dc:
    // 004494dc  8abc28ecfaffff         -mov bh, byte ptr [eax + ebp - 0x514]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1);
    // 004494e3  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004494e5  740d                   -je 0x4494f4
    if (cpu.flags.zf)
    {
        goto L_0x004494f4;
    }
    // 004494e7  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004494ea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004494ec  01f9                   +add ecx, edi
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
    // 004494ee  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004494ef  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004494f0  8839                   -mov byte ptr [ecx], bh
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bh;
    // 004494f2  ebe8                   -jmp 0x4494dc
    goto L_0x004494dc;
L_0x004494f4:
    // 004494f4  0355f8                 -add edx, dword ptr [ebp - 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004494f7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004494fc  883a                   -mov byte ptr [edx], bh
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bh;
L_0x004494fe:
    // 004494fe  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00449500  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449501  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449502  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449503  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_449510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00449511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449512  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449513  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449514  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449515  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449517  81ec0c060000           -sub esp, 0x60c
    (cpu.esp) -= x86::reg32(x86::sreg32(1548 /*0x60c*/));
    // 0044951d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044951f  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00449522  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00449524  7441                   -je 0x449567
    if (cpu.flags.zf)
    {
        goto L_0x00449567;
    }
    // 00449526  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0044952b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044952d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044952f  891dac0b6600           -mov dword ptr [0x660bac], ebx
    app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */) = cpu.ebx;
    // 00449535  890da80b6600           -mov dword ptr [0x660ba8], ecx
    app->getMemory<x86::reg32>(x86::reg32(6687656) /* 0x660ba8 */) = cpu.ecx;
    // 0044953b  890db00b6600           -mov dword ptr [0x660bb0], ecx
    app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */) = cpu.ecx;
    // 00449541  eb08                   -jmp 0x44954b
    goto L_0x0044954b;
L_0x00449543:
    // 00449543  81fad0070000           +cmp edx, 0x7d0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2000 /*0x7d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449549  7d50                   -jge 0x44959b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044959b;
    }
L_0x0044954b:
    // 0044954b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0044954d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449554  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449556  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449559  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044955b  31d1                   +xor ecx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044955d  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044955e  890c85e04e6000         -mov dword ptr [eax*4 + 0x604ee0], ecx
    app->getMemory<x86::reg32>(x86::reg32(6311648) /* 0x604ee0 */ + cpu.eax * 4) = cpu.ecx;
    // 00449565  ebdc                   -jmp 0x449543
    goto L_0x00449543;
L_0x00449567:
    // 00449567  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00449569:
    // 00449569  3b0db00b6600           +cmp ecx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044956f  7d1e                   -jge 0x44958f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044958f;
    }
    // 00449571  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 00449578  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044957a  8b1485e4406000         -mov edx, dword ptr [eax*4 + 0x6040e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6308068) /* 0x6040e4 */ + cpu.eax * 4);
    // 00449581  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00449583  e8884d0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00449588  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044958a  7403                   -je 0x44958f
    if (cpu.flags.zf)
    {
        goto L_0x0044958f;
    }
    // 0044958c  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044958d  ebda                   -jmp 0x449569
    goto L_0x00449569;
L_0x0044958f:
    // 0044958f  3b0db00b6600           +cmp ecx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449595  0f8ce9020000           -jl 0x449884
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00449884;
    }
L_0x0044959b:
    // 0044959b  8b15b00b6600           -mov edx, dword ptr [0x660bb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */);
    // 004495a1  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004495a8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004495aa  bb24000000             -mov ebx, 0x24
    cpu.ebx = 36 /*0x24*/;
    // 004495af  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004495b2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004495b4  05d0406000             -add eax, 0x6040d0
    (cpu.eax) += x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
    // 004495b9  e882700900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004495be  8b15b00b6600           -mov edx, dword ptr [0x660bb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */);
    // 004495c4  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004495cb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004495cd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004495d0  42                     -inc edx
    (cpu.edx)++;
    // 004495d1  89b0e4406000           -mov dword ptr [eax + 0x6040e4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6308068) /* 0x6040e4 */) = cpu.esi;
    // 004495d7  05d0406000             -add eax, 0x6040d0
    (cpu.eax) += x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
    // 004495dc  8915b00b6600           -mov dword ptr [0x660bb0], edx
    app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */) = cpu.edx;
    // 004495e2  e82995ffff             -call 0x442b10
    cpu.esp -= 4;
    sub_442b10(app, cpu);
    if (cpu.terminate) return;
    // 004495e7  a1b00b6600             -mov eax, dword ptr [0x660bb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */);
    // 004495ec  48                     -dec eax
    (cpu.eax)--;
    // 004495ed  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x004495f0:
    // 004495f0  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004495f3  3b05b00b6600           +cmp eax, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004495f9  0f8d62020000           -jge 0x449861
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00449861;
    }
    // 004495ff  be342d7a00             -mov esi, 0x7a2d34
    cpu.esi = 8006964 /*0x7a2d34*/;
    // 00449604  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00449607  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0044960d  8d1cd500000000         -lea ebx, [edx*8]
    cpu.ebx = x86::reg32(cpu.edx * 8);
    // 00449614  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00449615:
    // 00449615  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00449617  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00449619  3c00                   +cmp al, 0
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
    // 0044961b  7410                   -je 0x44962d
    if (cpu.flags.zf)
    {
        goto L_0x0044962d;
    }
    // 0044961d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00449620  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00449623  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00449626  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00449629  3c00                   +cmp al, 0
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
    // 0044962b  75e8                   -jne 0x449615
    if (!cpu.flags.zf)
    {
        goto L_0x00449615;
    }
L_0x0044962d:
    // 0044962d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044962e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449630  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00449636  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00449639  e862930000             -call 0x4529a0
    cpu.esp -= 4;
    sub_4529a0(app, cpu);
    if (cpu.terminate) return;
    // 0044963e  8b8be4406000           -mov ecx, dword ptr [ebx + 0x6040e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6308068) /* 0x6040e4 */);
    // 00449644  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449645  68948f5300             -push 0x538f94
    app->getMemory<x86::reg32>(cpu.esp-4) = 5476244 /*0x538f94*/;
    cpu.esp -= 4;
    // 0044964a  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00449650  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449652  49                     -dec ecx
    (cpu.ecx)--;
    // 00449653  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00449655  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00449657  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00449659  49                     -dec ecx
    (cpu.ecx)--;
    // 0044965a  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00449660  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00449662  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00449663  e828600900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00449668  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044966b  ba9c8f5300             -mov edx, 0x538f9c
    cpu.edx = 5476252 /*0x538f9c*/;
    // 00449670  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00449676  e86d490a00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0044967b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044967d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044967f  7509                   -jne 0x44968a
    if (!cpu.flags.zf)
    {
        goto L_0x0044968a;
    }
    // 00449681  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 00449685  e9cf010000             -jmp 0x449859
    goto L_0x00449859;
L_0x0044968a:
    // 0044968a  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00449690  a31c925500             -mov dword ptr [0x55921c], eax
    app->getMemory<x86::reg32>(x86::reg32(5607964) /* 0x55921c */) = cpu.eax;
    // 00449695  66a1ac0b6600           -mov ax, word ptr [0x660bac]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6687660) /* 0x660bac */);
    // 0044969b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0044969d  40                     -inc eax
    (cpu.eax)++;
    // 0044969e  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004496a1  668983e8406000         -mov word ptr [ebx + 0x6040e8], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6308072) /* 0x6040e8 */) = cpu.ax;
L_0x004496a8:
    // 004496a8  8d4df4                 -lea ecx, [ebp - 0xc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004496ab  8d9df4f9ffff           -lea ebx, [ebp - 0x60c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-1548) /* -0x60c */);
    // 004496b1  8d95f4fdffff           -lea edx, [ebp - 0x20c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-524) /* -0x20c */);
    // 004496b7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004496b9  e8f2fcffff             -call 0x4493b0
    cpu.esp -= 4;
    sub_4493b0(app, cpu);
    if (cpu.terminate) return;
    // 004496be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004496c0  0f8476010000           -je 0x44983c
    if (cpu.flags.zf)
    {
        goto L_0x0044983c;
    }
    // 004496c6  8d85f4fdffff           -lea eax, [ebp - 0x20c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-524) /* -0x20c */);
    // 004496cc  e80ffaffff             -call 0x4490e0
    cpu.esp -= 4;
    sub_4490e0(app, cpu);
    if (cpu.terminate) return;
    // 004496d1  83f8ff                 +cmp eax, -1
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
    // 004496d4  7422                   -je 0x4496f8
    if (cpu.flags.zf)
    {
        goto L_0x004496f8;
    }
    // 004496d6  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 004496dc  81fad0070000           +cmp edx, 0x7d0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2000 /*0x7d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004496e2  7dc4                   -jge 0x4496a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004496a8;
    }
    // 004496e4  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004496e7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004496e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004496eb  890dac0b6600           -mov dword ptr [0x660bac], ecx
    app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */) = cpu.ecx;
    // 004496f1  e86af9ffff             -call 0x449060
    cpu.esp -= 4;
    sub_449060(app, cpu);
    if (cpu.terminate) return;
    // 004496f6  ebb0                   -jmp 0x4496a8
    goto L_0x004496a8;
L_0x004496f8:
    // 004496f8  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 004496fe  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449705  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449707  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044970a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044970c  8b1485e04e6000         -mov edx, dword ptr [eax*4 + 0x604ee0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6311648) /* 0x604ee0 */ + cpu.eax * 4);
    // 00449713  8d85f4fdffff           -lea eax, [ebp - 0x20c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-524) /* -0x20c */);
    // 00449719  e8e2f7ffff             -call 0x448f00
    cpu.esp -= 4;
    sub_448f00(app, cpu);
    if (cpu.terminate) return;
    // 0044971e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00449720  83f8ff                 +cmp eax, -1
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
    // 00449723  7483                   -je 0x4496a8
    if (cpu.flags.zf)
    {
        goto L_0x004496a8;
    }
    // 00449725  8d9df4f9ffff           -lea ebx, [ebp - 0x60c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-1548) /* -0x60c */);
    // 0044972b  a1ac0b6600             -mov eax, dword ptr [0x660bac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 00449730  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00449732  e809fbffff             -call 0x449240
    cpu.esp -= 4;
    sub_449240(app, cpu);
    if (cpu.terminate) return;
    // 00449737  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00449739  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044973c  83b8107c550005         +cmp dword ptr [eax + 0x557c10], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5602320) /* 0x557c10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449743  0f855fffffff           -jne 0x4496a8
    if (!cpu.flags.zf)
    {
        goto L_0x004496a8;
    }
    // 00449749  baa08f5300             -mov edx, 0x538fa0
    cpu.edx = 5476256 /*0x538fa0*/;
    // 0044974e  8b80147c5500           -mov eax, dword ptr [eax + 0x557c14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5602324) /* 0x557c14 */);
    // 00449754  e8b74b0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00449759  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044975b  7405                   -je 0x449762
    if (cpu.flags.zf)
    {
        goto L_0x00449762;
    }
    // 0044975d  e946ffffff             -jmp 0x4496a8
    goto L_0x004496a8;
L_0x00449762:
    // 00449762  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 00449768  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044976f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449771  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449774  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449776  8b0485204f6000         -mov eax, dword ptr [eax*4 + 0x604f20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6311712) /* 0x604f20 */ + cpu.eax * 4);
    // 0044977d  803800                 +cmp byte ptr [eax], 0
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
    // 00449780  0f8422ffffff           -je 0x4496a8
    if (cpu.flags.zf)
    {
        goto L_0x004496a8;
    }
    // 00449786  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00449788:
    // 00449788  3b0db00b6600           +cmp ecx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044978e  7d39                   -jge 0x4497c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004497c9;
    }
    // 00449790  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 00449797  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00449799  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 0044979f  8b3c85e4406000         -mov edi, dword ptr [eax*4 + 0x6040e4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6308068) /* 0x6040e4 */ + cpu.eax * 4);
    // 004497a6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004497ad  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004497af  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004497b2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004497b4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004497b6  8b0485204f6000         -mov eax, dword ptr [eax*4 + 0x604f20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6311712) /* 0x604f20 */ + cpu.eax * 4);
    // 004497bd  e84e4b0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004497c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004497c4  7403                   -je 0x4497c9
    if (cpu.flags.zf)
    {
        goto L_0x004497c9;
    }
    // 004497c6  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004497c7  ebbf                   -jmp 0x449788
    goto L_0x00449788;
L_0x004497c9:
    // 004497c9  a1b00b6600             -mov eax, dword ptr [0x660bb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */);
    // 004497ce  39c1                   +cmp ecx, eax
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
    // 004497d0  0f85d2feffff           -jne 0x4496a8
    if (!cpu.flags.zf)
    {
        goto L_0x004496a8;
    }
    // 004497d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004497d8  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004497db  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004497dd  bb24000000             -mov ebx, 0x24
    cpu.ebx = 36 /*0x24*/;
    // 004497e2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004497e5  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004497e7  05d0406000             -add eax, 0x6040d0
    (cpu.eax) += x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
    // 004497ec  e84f6e0900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004497f1  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 004497f7  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 004497fe  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449800  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00449803  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449805  8b15b00b6600           -mov edx, dword ptr [0x660bb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */);
    // 0044980b  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00449812  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00449815  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449817  8b8b204f6000           -mov ecx, dword ptr [ebx + 0x604f20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6311712) /* 0x604f20 */);
    // 0044981d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449820  42                     -inc edx
    (cpu.edx)++;
    // 00449821  8988e4406000           -mov dword ptr [eax + 0x6040e4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6308068) /* 0x6040e4 */) = cpu.ecx;
    // 00449827  05d0406000             +add eax, 0x6040d0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044982c  8915b00b6600           -mov dword ptr [0x660bb0], edx
    app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */) = cpu.edx;
    // 00449832  e8d992ffff             -call 0x442b10
    cpu.esp -= 4;
    sub_442b10(app, cpu);
    if (cpu.terminate) return;
    // 00449837  e96cfeffff             -jmp 0x4496a8
    goto L_0x004496a8;
L_0x0044983c:
    // 0044983c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044983e  e8bd480a00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 00449843  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 00449849  42                     -inc edx
    (cpu.edx)++;
    // 0044984a  8915ac0b6600           -mov dword ptr [0x660bac], edx
    app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */) = cpu.edx;
    // 00449850  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00449852  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00449854  e807f8ffff             -call 0x449060
    cpu.esp -= 4;
    sub_449060(app, cpu);
    if (cpu.terminate) return;
L_0x00449859:
    // 00449859  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044985c  e98ffdffff             -jmp 0x4495f0
    goto L_0x004495f0;
L_0x00449861:
    // 00449861  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00449863:
    // 00449863  3b15b00b6600           +cmp edx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449869  7d19                   -jge 0x449884
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00449884;
    }
    // 0044986b  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00449872  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449874  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449877  05d0406000             +add eax, 0x6040d0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044987c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044987d  e80e010000             -call 0x449990
    cpu.esp -= 4;
    sub_449990(app, cpu);
    if (cpu.terminate) return;
    // 00449882  ebdf                   -jmp 0x449863
    goto L_0x00449863;
L_0x00449884:
    // 00449884  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00449889  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044988b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044988c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044988d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044988e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044988f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449890  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4498a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004498a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004498a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004498a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004498a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004498a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004498a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004498a7  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004498ad  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 004498b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004498b5  be848f5300             -mov esi, 0x538f84
    cpu.esi = 5476228 /*0x538f84*/;
    // 004498ba  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004498bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004498be:
    // 004498be  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004498c0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004498c2  3c00                   +cmp al, 0
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
    // 004498c4  7410                   -je 0x4498d6
    if (cpu.flags.zf)
    {
        goto L_0x004498d6;
    }
    // 004498c6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004498c9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004498cc  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004498cf  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004498d2  3c00                   +cmp al, 0
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
    // 004498d4  75e8                   -jne 0x4498be
    if (!cpu.flags.zf)
    {
        goto L_0x004498be;
    }
L_0x004498d6:
    // 004498d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004498d7  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004498da  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004498dc  e8bf900000             -call 0x4529a0
    cpu.esp -= 4;
    sub_4529a0(app, cpu);
    if (cpu.terminate) return;
    // 004498e1  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 004498e8  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004498ea  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004498ed  8b3485e4406000         -mov esi, dword ptr [eax*4 + 0x6040e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6308068) /* 0x6040e4 */ + cpu.eax * 4);
    // 004498f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004498f5  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004498f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004498f8  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004498fa  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004498fc  4f                     -dec edi
    (cpu.edi)--;
L_0x004498fd:
    // 004498fd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004498ff  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00449901  3c00                   +cmp al, 0
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
    // 00449903  7410                   -je 0x449915
    if (cpu.flags.zf)
    {
        goto L_0x00449915;
    }
    // 00449905  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00449908  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044990b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044990e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00449911  3c00                   +cmp al, 0
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
    // 00449913  75e8                   -jne 0x4498fd
    if (!cpu.flags.zf)
    {
        goto L_0x004498fd;
    }
L_0x00449915:
    // 00449915  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449916  beac8f5300             -mov esi, 0x538fac
    cpu.esi = 5476268 /*0x538fac*/;
    // 0044991b  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044991e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00449923  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449924  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00449926  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00449927  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00449929  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044992b  4f                     -dec edi
    (cpu.edi)--;
L_0x0044992c:
    // 0044992c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044992e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00449930  3c00                   +cmp al, 0
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
    // 00449932  7410                   -je 0x449944
    if (cpu.flags.zf)
    {
        goto L_0x00449944;
    }
    // 00449934  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00449937  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044993a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044993d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00449940  3c00                   +cmp al, 0
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
    // 00449942  75e8                   -jne 0x44992c
    if (!cpu.flags.zf)
    {
        goto L_0x0044992c;
    }
L_0x00449944:
    // 00449944  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449945  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00449948  e8a36c0a00             -call 0x4f05f0
    cpu.esp -= 4;
    sub_4f05f0(app, cpu);
    if (cpu.terminate) return;
    // 0044994d  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 00449953  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449954  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449955  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449956  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449957  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449958  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_449960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449960  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449961  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449962  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449964  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00449966:
    // 00449966  3b15b00b6600           +cmp edx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044996c  7d15                   -jge 0x449983
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00449983;
    }
    // 0044996e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00449970  e88b93ffff             -call 0x442d00
    cpu.esp -= 4;
    sub_442d00(app, cpu);
    if (cpu.terminate) return;
    // 00449975  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449977  7407                   -je 0x449980
    if (cpu.flags.zf)
    {
        goto L_0x00449980;
    }
    // 00449979  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044997b  e820ffffff             -call 0x4498a0
    cpu.esp -= 4;
    sub_4498a0(app, cpu);
    if (cpu.terminate) return;
L_0x00449980:
    // 00449980  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00449981  ebe3                   -jmp 0x449966
    goto L_0x00449966;
L_0x00449983:
    // 00449983  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449984  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449985  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_449990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449990  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449991  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449992  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449994  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00449996  6683782000             +cmp word ptr [eax + 0x20], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044999b  750d                   -jne 0x4499aa
    if (!cpu.flags.zf)
    {
        goto L_0x004499aa;
    }
    // 0044999d  833800                 +cmp dword ptr [eax], 0
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
    // 004499a0  7402                   -je 0x4499a4
    if (cpu.flags.zf)
    {
        goto L_0x004499a4;
    }
    // 004499a2  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004499a4:
    // 004499a4  66c742200100           -mov word ptr [edx + 0x20], 1
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x004499aa:
    // 004499aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4499b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004499b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004499b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004499b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004499b4  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
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
    // 004499bb  742b                   -je 0x4499e8
    if (cpu.flags.zf)
    {
        goto L_0x004499e8;
    }
    // 004499bd  833d08d56f0000         +cmp dword ptr [0x6fd508], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329032) /* 0x6fd508 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004499c4  7422                   -je 0x4499e8
    if (cpu.flags.zf)
    {
        goto L_0x004499e8;
    }
    // 004499c6  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004499cd  7519                   -jne 0x4499e8
    if (!cpu.flags.zf)
    {
        goto L_0x004499e8;
    }
    // 004499cf  bab48f5300             -mov edx, 0x538fb4
    cpu.edx = 5476276 /*0x538fb4*/;
    // 004499d4  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004499d7  e8e48fffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004499dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004499de  740d                   -je 0x4499ed
    if (cpu.flags.zf)
    {
        goto L_0x004499ed;
    }
    // 004499e0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004499e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004499e8:
    // 004499e8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004499ed:
    // 004499ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4499f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004499f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004499f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004499f2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004499f4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004499f6  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
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
    // 004499fd  0f8455000000           -je 0x449a58
    if (cpu.flags.zf)
    {
        goto L_0x00449a58;
    }
    // 00449a03  833d08d56f0000         +cmp dword ptr [0x6fd508], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329032) /* 0x6fd508 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449a0a  744c                   -je 0x449a58
    if (cpu.flags.zf)
    {
        goto L_0x00449a58;
    }
    // 00449a0c  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449a13  7543                   -jne 0x449a58
    if (!cpu.flags.zf)
    {
        goto L_0x00449a58;
    }
    // 00449a15  e8667cffff             -call 0x441680
    cpu.esp -= 4;
    sub_441680(app, cpu);
    if (cpu.terminate) return;
    // 00449a1a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449a1c  753a                   -jne 0x449a58
    if (!cpu.flags.zf)
    {
        goto L_0x00449a58;
    }
    // 00449a1e  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449a23  7438                   -je 0x449a5d
    if (cpu.flags.zf)
    {
        goto L_0x00449a5d;
    }
    // 00449a25  6683fa1b               +cmp dx, 0x1b
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449a29  7432                   -je 0x449a5d
    if (cpu.flags.zf)
    {
        goto L_0x00449a5d;
    }
    // 00449a2b  8b4116                 -mov eax, dword ptr [ecx + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 00449a2e  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00449a31  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00449a34  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449a37  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449a39  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449a40  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449a42  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449a45  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449a47  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449a4a  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 00449a4f  e85cffffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 00449a54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449a56  7405                   -je 0x449a5d
    if (cpu.flags.zf)
    {
        goto L_0x00449a5d;
    }
L_0x00449a58:
    // 00449a58  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00449a5d:
    // 00449a5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_449a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449a60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00449a61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449a62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449a63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449a64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449a66  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00449a6b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00449a70  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00449a75  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00449a77  890d44925500           -mov dword ptr [0x559244], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */) = cpu.ecx;
    // 00449a7d  891d4c925500           -mov dword ptr [0x55924c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.ebx;
    // 00449a83  a33c925500             -mov dword ptr [0x55923c], eax
    app->getMemory<x86::reg32>(x86::reg32(5607996) /* 0x55923c */) = cpu.eax;
    // 00449a88  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00449a8d  891538925500           -mov dword ptr [0x559238], edx
    app->getMemory<x86::reg32>(x86::reg32(5607992) /* 0x559238 */) = cpu.edx;
    // 00449a93  a340925500             -mov dword ptr [0x559240], eax
    app->getMemory<x86::reg32>(x86::reg32(5608000) /* 0x559240 */) = cpu.eax;
    // 00449a98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_449aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449aa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00449aa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449aa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449aa3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449aa4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449aa5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449aa6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449aa8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00449aab  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00449ab2  740c                   -je 0x449ac0
    if (cpu.flags.zf)
    {
        goto L_0x00449ac0;
    }
    // 00449ab4  c705509455000000803f   -mov dword ptr [0x559450], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */) = 1065353216 /*0x3f800000*/;
    // 00449abe  eb0a                   -jmp 0x449aca
    goto L_0x00449aca;
L_0x00449ac0:
    // 00449ac0  c705509455006666663f   -mov dword ptr [0x559450], 0x3f666666
    app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */) = 1063675494 /*0x3f666666*/;
L_0x00449aca:
    // 00449aca  e8e1130000             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00449acf  3b0548925500           +cmp eax, dword ptr [0x559248]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5608008) /* 0x559248 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449ad5  7509                   -jne 0x449ae0
    if (!cpu.flags.zf)
    {
        goto L_0x00449ae0;
    }
    // 00449ad7  e8d49dffff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 00449adc  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00449ade  743a                   -je 0x449b1a
    if (cpu.flags.zf)
    {
        goto L_0x00449b1a;
    }
L_0x00449ae0:
    // 00449ae0  c7053892550001000000   -mov dword ptr [0x559238], 1
    app->getMemory<x86::reg32>(x86::reg32(5607992) /* 0x559238 */) = 1 /*0x1*/;
    // 00449aea  e8c1130000             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00449aef  a348925500             -mov dword ptr [0x559248], eax
    app->getMemory<x86::reg32>(x86::reg32(5608008) /* 0x559248 */) = cpu.eax;
    // 00449af4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00449af6  a34c925500             -mov dword ptr [0x55924c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.eax;
    // 00449afb  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00449b00  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 00449b05  a33c925500             -mov dword ptr [0x55923c], eax
    app->getMemory<x86::reg32>(x86::reg32(5607996) /* 0x55923c */) = cpu.eax;
    // 00449b0a  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00449b0f  893d44925500           -mov dword ptr [0x559244], edi
    app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */) = cpu.edi;
    // 00449b15  a340925500             -mov dword ptr [0x559240], eax
    app->getMemory<x86::reg32>(x86::reg32(5608000) /* 0x559240 */) = cpu.eax;
L_0x00449b1a:
    // 00449b1a  e8d1020000             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00449b1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449b21  0f85ba020000           -jne 0x449de1
    if (!cpu.flags.zf)
    {
        goto L_0x00449de1;
    }
    // 00449b27  e814090000             -call 0x44a440
    cpu.esp -= 4;
    sub_44a440(app, cpu);
    if (cpu.terminate) return;
    // 00449b2c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00449b2e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00449b30  e87b9dffff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 00449b35  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00449b37  750f                   -jne 0x449b48
    if (!cpu.flags.zf)
    {
        goto L_0x00449b48;
    }
    // 00449b39  83faff                 +cmp edx, -1
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
    // 00449b3c  740a                   -je 0x449b48
    if (cpu.flags.zf)
    {
        goto L_0x00449b48;
    }
    // 00449b3e  8b1d44925500           -mov ebx, dword ptr [0x559244]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */);
    // 00449b44  39da                   +cmp edx, ebx
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
    // 00449b46  740c                   -je 0x449b54
    if (cpu.flags.zf)
    {
        goto L_0x00449b54;
    }
L_0x00449b48:
    // 00449b48  c70544925500ffffffff   -mov dword ptr [0x559244], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */) = 4294967295 /*0xffffffff*/;
    // 00449b52  eb09                   -jmp 0x449b5d
    goto L_0x00449b5d;
L_0x00449b54:
    // 00449b54  83fbff                 +cmp ebx, -1
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
    // 00449b57  0f8517010000           -jne 0x449c74
    if (!cpu.flags.zf)
    {
        goto L_0x00449c74;
    }
L_0x00449b5d:
    // 00449b5d  8b153c925500           -mov edx, dword ptr [0x55923c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607996) /* 0x55923c */);
    // 00449b63  3b15e4e55500           +cmp edx, dword ptr [0x55e5e4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449b69  750e                   -jne 0x449b79
    if (!cpu.flags.zf)
    {
        goto L_0x00449b79;
    }
    // 00449b6b  8b1d40925500           -mov ebx, dword ptr [0x559240]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5608000) /* 0x559240 */);
    // 00449b71  3b1de8e55500           +cmp ebx, dword ptr [0x55e5e8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449b77  742e                   -je 0x449ba7
    if (cpu.flags.zf)
    {
        goto L_0x00449ba7;
    }
L_0x00449b79:
    // 00449b79  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00449b7e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00449b80  a33c925500             -mov dword ptr [0x55923c], eax
    app->getMemory<x86::reg32>(x86::reg32(5607996) /* 0x55923c */) = cpu.eax;
    // 00449b85  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00449b8a  893538925500           -mov dword ptr [0x559238], esi
    app->getMemory<x86::reg32>(x86::reg32(5607992) /* 0x559238 */) = cpu.esi;
    // 00449b90  a340925500             -mov dword ptr [0x559240], eax
    app->getMemory<x86::reg32>(x86::reg32(5608000) /* 0x559240 */) = cpu.eax;
    // 00449b95  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00449b9a  83c064                 +add eax, 0x64
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00449b9d  a350296600             -mov dword ptr [0x662950], eax
    app->getMemory<x86::reg32>(x86::reg32(6695248) /* 0x662950 */) = cpu.eax;
    // 00449ba2  e9cd000000             -jmp 0x449c74
    goto L_0x00449c74;
L_0x00449ba7:
    // 00449ba7  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00449bac  3b0550296600           +cmp eax, dword ptr [0x662950]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6695248) /* 0x662950 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449bb2  0f8ebc000000           -jle 0x449c74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00449c74;
    }
    // 00449bb8  83f9ff                 +cmp ecx, -1
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
    // 00449bbb  0f84b3000000           -je 0x449c74
    if (cpu.flags.zf)
    {
        goto L_0x00449c74;
    }
    // 00449bc1  a138925500             -mov eax, dword ptr [0x559238]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607992) /* 0x559238 */);
    // 00449bc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449bc8  0f85a6000000           -jne 0x449c74
    if (!cpu.flags.zf)
    {
        goto L_0x00449c74;
    }
    // 00449bce  890d44925500           -mov dword ptr [0x559244], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */) = cpu.ecx;
    // 00449bd4  a364296600             -mov dword ptr [0x662964], eax
    app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */) = cpu.eax;
    // 00449bd9  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00449be0  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449be2  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449be5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449be7  bb7c010000             -mov ebx, 0x17c
    cpu.ebx = 380 /*0x17c*/;
    // 00449bec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00449bee  8b0485ec4e6000         -mov eax, dword ptr [eax*4 + 0x604eec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6311660) /* 0x604eec */ + cpu.eax * 4);
    // 00449bf5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449bf6  a34c925500             -mov dword ptr [0x55924c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.eax;
    // 00449bfb  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00449bfe  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00449c03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00449c04  8d4df8                 -lea ecx, [ebp - 8]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00449c07  a14c925500             -mov eax, dword ptr [0x55924c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
    // 00449c0c  e8df830000             -call 0x451ff0
    cpu.esp -= 4;
    sub_451ff0(app, cpu);
    if (cpu.terminate) return;
    // 00449c11  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00449c14  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00449c17  8b0de4e55500           -mov ecx, dword ptr [0x55e5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00449c1d  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00449c20  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00449c23  890d58296600           -mov dword ptr [0x662958], ecx
    app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */) = cpu.ecx;
    // 00449c29  891560296600           -mov dword ptr [0x662960], edx
    app->getMemory<x86::reg32>(x86::reg32(6695264) /* 0x662960 */) = cpu.edx;
    // 00449c2f  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449c31  a354296600             -mov dword ptr [0x662954], eax
    app->getMemory<x86::reg32>(x86::reg32(6695252) /* 0x662954 */) = cpu.eax;
    // 00449c36  81f976020000           +cmp ecx, 0x276
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(630 /*0x276*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449c3c  7e0d                   -jle 0x449c4b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00449c4b;
    }
    // 00449c3e  b976020000             -mov ecx, 0x276
    cpu.ecx = 630 /*0x276*/;
    // 00449c43  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449c45  890d58296600           -mov dword ptr [0x662958], ecx
    app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */) = cpu.ecx;
L_0x00449c4b:
    // 00449c4b  8b15e8e55500           -mov edx, dword ptr [0x55e5e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00449c51  83c214                 -add edx, 0x14
    (cpu.edx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00449c54  89155c296600           -mov dword ptr [0x66295c], edx
    app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */) = cpu.edx;
    // 00449c5a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449c5c  81facc010000           +cmp edx, 0x1cc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(460 /*0x1cc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449c62  7e10                   -jle 0x449c74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00449c74;
    }
    // 00449c64  8b15e8e55500           -mov edx, dword ptr [0x55e5e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00449c6a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00449c6c  8d42f8                 -lea eax, [edx - 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00449c6f  a35c296600             -mov dword ptr [0x66295c], eax
    app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */) = cpu.eax;
L_0x00449c74:
    // 00449c74  8b0d4c925500           -mov ecx, dword ptr [0x55924c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
    // 00449c7a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00449c7c  740d                   -je 0x449c8b
    if (cpu.flags.zf)
    {
        goto L_0x00449c8b;
    }
    // 00449c7e  803900                 +cmp byte ptr [ecx], 0
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
    // 00449c81  7508                   -jne 0x449c8b
    if (!cpu.flags.zf)
    {
        goto L_0x00449c8b;
    }
    // 00449c83  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00449c85  891d4c925500           -mov dword ptr [0x55924c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.ebx;
L_0x00449c8b:
    // 00449c8b  833d4c92550000         +cmp dword ptr [0x55924c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449c92  0f8466000000           -je 0x449cfe
    if (cpu.flags.zf)
    {
        goto L_0x00449cfe;
    }
    // 00449c98  833d44925500ff         +cmp dword ptr [0x559244], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449c9f  7530                   -jne 0x449cd1
    if (!cpu.flags.zf)
    {
        goto L_0x00449cd1;
    }
    // 00449ca1  a164296600             -mov eax, dword ptr [0x662964]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */);
    // 00449ca6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449ca8  7e0a                   -jle 0x449cb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00449cb4;
    }
    // 00449caa  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00449cac  891564296600           -mov dword ptr [0x662964], edx
    app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */) = cpu.edx;
    // 00449cb2  eb02                   -jmp 0x449cb6
    goto L_0x00449cb6;
L_0x00449cb4:
    // 00449cb4  7f08                   -jg 0x449cbe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00449cbe;
    }
L_0x00449cb6:
    // 00449cb6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00449cb8  891d4c925500           -mov dword ptr [0x55924c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.ebx;
L_0x00449cbe:
    // 00449cbe  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00449cc5  7437                   -je 0x449cfe
    if (cpu.flags.zf)
    {
        goto L_0x00449cfe;
    }
    // 00449cc7  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00449cc9  89354c925500           -mov dword ptr [0x55924c], esi
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.esi;
    // 00449ccf  eb2d                   -jmp 0x449cfe
    goto L_0x00449cfe;
L_0x00449cd1:
    // 00449cd1  8b3d64296600           -mov edi, dword ptr [0x662964]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */);
    // 00449cd7  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449cdd  7c02                   -jl 0x449ce1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00449ce1;
    }
    // 00449cdf  7e0a                   -jle 0x449ceb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00449ceb;
    }
L_0x00449ce1:
    // 00449ce1  c70564296600ff000000   -mov dword ptr [0x662964], 0xff
    app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */) = 255 /*0xff*/;
L_0x00449ceb:
    // 00449ceb  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00449cf2  740a                   -je 0x449cfe
    if (cpu.flags.zf)
    {
        goto L_0x00449cfe;
    }
    // 00449cf4  c70564296600ff000000   -mov dword ptr [0x662964], 0xff
    app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */) = 255 /*0xff*/;
L_0x00449cfe:
    // 00449cfe  833d4c92550000         +cmp dword ptr [0x55924c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449d05  0f84cc000000           -je 0x449dd7
    if (cpu.flags.zf)
    {
        goto L_0x00449dd7;
    }
    // 00449d0b  68ad6c4bff             -push 0xff4b6cad
    app->getMemory<x86::reg32>(cpu.esp-4) = 4283133101 /*0xff4b6cad*/;
    cpu.esp -= 4;
    // 00449d10  a164296600             -mov eax, dword ptr [0x662964]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */);
    // 00449d15  8b0d5c296600           -mov ecx, dword ptr [0x66295c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */);
    // 00449d1b  8b1554296600           -mov edx, dword ptr [0x662954]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6695252) /* 0x662954 */);
    // 00449d21  8b1d60296600           -mov ebx, dword ptr [0x662960]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6695264) /* 0x662960 */);
    // 00449d27  6a9c                   -push -0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = -100 /*-0x64*/;
    cpu.esp -= 4;
    // 00449d29  a3a43a5600             -mov dword ptr [0x563aa4], eax
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = cpu.eax;
    // 00449d2e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00449d30  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449d32  a158296600             -mov eax, dword ptr [0x662958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */);
    // 00449d37  8b155c296600           -mov edx, dword ptr [0x66295c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */);
    // 00449d3d  c1e718                 -shl edi, 0x18
    cpu.edi <<= 24 /*0x18*/ % 32;
    // 00449d40  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449d42  893da43a5600           -mov dword ptr [0x563aa4], edi
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = cpu.edi;
    // 00449d48  e803e80800             -call 0x4d8550
    cpu.esp -= 4;
    sub_4d8550(app, cpu);
    if (cpu.terminate) return;
    // 00449d4d  a164296600             -mov eax, dword ptr [0x662964]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */);
    // 00449d52  8b0d54296600           -mov ecx, dword ptr [0x662954]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6695252) /* 0x662954 */);
    // 00449d58  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00449d5b  8b1d60296600           -mov ebx, dword ptr [0x662960]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6695264) /* 0x662960 */);
    // 00449d61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00449d62  8b155c296600           -mov edx, dword ptr [0x66295c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */);
    // 00449d68  a158296600             -mov eax, dword ptr [0x662958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */);
    // 00449d6d  e8beeb0800             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
    // 00449d72  8b3534925500           -mov esi, dword ptr [0x559234]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00449d78  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00449d7a  7424                   -je 0x449da0
    if (cpu.flags.zf)
    {
        goto L_0x00449da0;
    }
    // 00449d7c  68fd8c4800             -push 0x488cfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 4754685 /*0x488cfd*/;
    cpu.esp -= 4;
    // 00449d81  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00449d86  8b1d5c296600           -mov ebx, dword ptr [0x66295c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */);
    // 00449d8c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00449d8e  8b1558296600           -mov edx, dword ptr [0x662958]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */);
    // 00449d94  a14c925500             -mov eax, dword ptr [0x55924c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
    // 00449d99  e8f2830000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00449d9e  eb2d                   -jmp 0x449dcd
    goto L_0x00449dcd;
L_0x00449da0:
    // 00449da0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449da1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449da2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449da3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449da4  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00449da9  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00449dae  687c010000             -push 0x17c
    app->getMemory<x86::reg32>(cpu.esp-4) = 380 /*0x17c*/;
    cpu.esp -= 4;
    // 00449db3  8b3d5c296600           -mov edi, dword ptr [0x66295c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */);
    // 00449db9  8b0d58296600           -mov ecx, dword ptr [0x662958]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */);
    // 00449dbf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449dc0  a14c925500             -mov eax, dword ptr [0x55924c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
    // 00449dc5  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00449dc8  e8f3810000             -call 0x451fc0
    cpu.esp -= 4;
    sub_451fc0(app, cpu);
    if (cpu.terminate) return;
L_0x00449dcd:
    // 00449dcd  c705a43a5600000000ff   -mov dword ptr [0x563aa4], 0xff000000
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = 4278190080 /*0xff000000*/;
L_0x00449dd7:
    // 00449dd7  c705509455000000803f   -mov dword ptr [0x559450], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */) = 1065353216 /*0x3f800000*/;
L_0x00449de1:
    // 00449de1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00449de3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_449df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449df0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449df1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449df2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449df4  e847060000             -call 0x44a440
    cpu.esp -= 4;
    sub_44a440(app, cpu);
    if (cpu.terminate) return;
    // 00449df9  83f8ff                 +cmp eax, -1
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
    // 00449dfc  743a                   -je 0x449e38
    if (cpu.flags.zf)
    {
        goto L_0x00449e38;
    }
    // 00449dfe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00449e00  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449e03  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449e05  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449e08  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449e0a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449e0d  f680e54e600004         +test byte ptr [eax + 0x604ee5], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6311653) /* 0x604ee5 */) & 4 /*0x4*/));
    // 00449e14  7422                   -je 0x449e38
    if (cpu.flags.zf)
    {
        goto L_0x00449e38;
    }
    // 00449e16  8b90e04e6000           -mov edx, dword ptr [eax + 0x604ee0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
    // 00449e1c  83fa11                 +cmp edx, 0x11
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449e1f  740f                   -je 0x449e30
    if (cpu.flags.zf)
    {
        goto L_0x00449e30;
    }
    // 00449e21  83fa1d                 +cmp edx, 0x1d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(29 /*0x1d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449e24  740a                   -je 0x449e30
    if (cpu.flags.zf)
    {
        goto L_0x00449e30;
    }
    // 00449e26  83fa12                 +cmp edx, 0x12
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
    // 00449e29  7405                   -je 0x449e30
    if (cpu.flags.zf)
    {
        goto L_0x00449e30;
    }
    // 00449e2b  83fa13                 +cmp edx, 0x13
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
    // 00449e2e  7508                   -jne 0x449e38
    if (!cpu.flags.zf)
    {
        goto L_0x00449e38;
    }
L_0x00449e30:
    // 00449e30  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00449e35  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00449e38:
    // 00449e38  e8739affff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 00449e3d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00449e3f  7408                   -je 0x449e49
    if (cpu.flags.zf)
    {
        goto L_0x00449e49;
    }
    // 00449e41  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00449e46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e47  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00449e49:
    // 00449e49  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00449e4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_449e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449e50  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449e51  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449e53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449e55  7c43                   -jl 0x449e9a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00449e9a;
    }
    // 00449e57  83f864                 +cmp eax, 0x64
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449e5a  743e                   -je 0x449e9a
    if (cpu.flags.zf)
    {
        goto L_0x00449e9a;
    }
    // 00449e5c  8b5216                 -mov edx, dword ptr [edx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(22) /* 0x16 */);
    // 00449e5f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449e62  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449e64  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449e6b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449e6d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449e70  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449e72  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449e75  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 00449e7a  8b5002                 -mov edx, dword ptr [eax + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00449e7d  e82efbffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 00449e82  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449e85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449e87  7503                   -jne 0x449e8c
    if (!cpu.flags.zf)
    {
        goto L_0x00449e8c;
    }
    // 00449e89  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00449e8c:
    // 00449e8c  66f7c20113             +test dx, 0x1301
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & 4865 /*0x1301*/));
    // 00449e91  7507                   -jne 0x449e9a
    if (!cpu.flags.zf)
    {
        goto L_0x00449e9a;
    }
    // 00449e93  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00449e98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00449e9a:
    // 00449e9a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00449e9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_449ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449ea0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449ea1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449ea2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449ea3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449ea5  6683781a64             +cmp word ptr [eax + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449eaa  7477                   -je 0x449f23
    if (cpu.flags.zf)
    {
        goto L_0x00449f23;
    }
    // 00449eac  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 00449eaf  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00449eb2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449eb5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00449eb8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449eba  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449ec1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449ec3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449ec6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449ec8  b9e04e6000             -mov ecx, 0x604ee0
    cpu.ecx = 6311648 /*0x604ee0*/;
    // 00449ecd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449ed0  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449ed2  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00449ed5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449ed8  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449edf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449ee1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00449ee3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00449ee6  c1e202                 +shl edx, 2
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
    // 00449ee9  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00449eeb  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00449eee  8b511a                 -mov edx, dword ptr [ecx + 0x1a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 00449ef1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449ef4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449ef6  8915e4e55500           -mov dword ptr [0x55e5e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.edx;
    // 00449efc  8b511e                 -mov edx, dword ptr [ecx + 0x1e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00449eff  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449f02  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00449f04  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00449f07  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449f09  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00449f0b  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00449f0e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449f11  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449f13  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00449f18  8915e8e55500           -mov dword ptr [0x55e5e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.edx;
    // 00449f1e  e89d200500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x00449f23:
    // 00449f23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449f24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449f25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449f26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_449f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00449f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449f32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449f33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449f34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449f35  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449f37  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00449f3a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00449f3c  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00449f3f  668b501a               -mov dx, word ptr [eax + 0x1a]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
    // 00449f43  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00449f46  6683fa64               +cmp dx, 0x64
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449f4a  7424                   -je 0x449f70
    if (cpu.flags.zf)
    {
        goto L_0x00449f70;
    }
    // 00449f4c  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 00449f4f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449f52  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00449f54  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449f5b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449f5d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449f60  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449f62  f60485e54e600004       +test byte ptr [eax*4 + 0x604ee5], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6311653) /* 0x604ee5 */ + cpu.eax * 4) & 4 /*0x4*/));
    // 00449f6a  0f853d010000           -jne 0x44a0ad
    if (!cpu.flags.zf)
    {
        goto L_0x0044a0ad;
    }
L_0x00449f70:
    // 00449f70  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449f75  7411                   -je 0x449f88
    if (cpu.flags.zf)
    {
        goto L_0x00449f88;
    }
    // 00449f77  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00449f7a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00449f7c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00449f7f  e8ccfeffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 00449f84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449f86  751e                   -jne 0x449fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00449fa6;
    }
L_0x00449f88:
    // 00449f88  8b411a                 -mov eax, dword ptr [ecx + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 00449f8b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00449f8d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00449f90  e8bbfeffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 00449f95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449f97  740d                   -je 0x449fa6
    if (cpu.flags.zf)
    {
        goto L_0x00449fa6;
    }
    // 00449f99  668b411c               -mov ax, word ptr [ecx + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00449f9d  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 00449fa1  e9d9000000             -jmp 0x44a07f
    goto L_0x0044a07f;
L_0x00449fa6:
    // 00449fa6  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449fab  7556                   -jne 0x44a003
    if (!cpu.flags.zf)
    {
        goto L_0x0044a003;
    }
    // 00449fad  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 00449fb0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
L_0x00449fb3:
    // 00449fb3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449fba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449fbc  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449fbf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449fc1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449fc4  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449fcb  0f84ae000000           -je 0x44a07f
    if (cpu.flags.zf)
    {
        goto L_0x0044a07f;
    }
    // 00449fd1  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 00449fd6  8b7002                 -mov esi, dword ptr [eax + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00449fd9  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00449fdc  e8cff9ffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 00449fe1  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00449fe4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449fe6  7504                   -jne 0x449fec
    if (!cpu.flags.zf)
    {
        goto L_0x00449fec;
    }
    // 00449fe8  804dfc01               -or byte ptr [ebp - 4], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00449fec:
    // 00449fec  66f745fc0113           +test word ptr [ebp - 4], 0x1301
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 4865 /*0x1301*/));
    // 00449ff2  750c                   -jne 0x44a000
    if (!cpu.flags.zf)
    {
        goto L_0x0044a000;
    }
    // 00449ff4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00449ff6  668b4118               -mov ax, word ptr [ecx + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00449ffa  29c6                   +sub esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00449ffc  6689711a               -mov word ptr [ecx + 0x1a], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.si;
L_0x0044a000:
    // 0044a000  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a001  ebb0                   -jmp 0x449fb3
    goto L_0x00449fb3;
L_0x0044a003:
    // 0044a003  668b511a               -mov dx, word ptr [ecx + 0x1a]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 0044a007  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0044a00a  7409                   -je 0x44a015
    if (cpu.flags.zf)
    {
        goto L_0x0044a015;
    }
    // 0044a00c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0044a00e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044a00f  6689711a               -mov word ptr [ecx + 0x1a], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.si;
    // 0044a013  eb2d                   -jmp 0x44a042
    goto L_0x0044a042;
L_0x0044a015:
    // 0044a015  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a018  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a01b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a01e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a021  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a023  42                     -inc edx
    (cpu.edx)++;
    // 0044a024  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a02b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a02d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a030  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a032  833c85e04e600000       +cmp dword ptr [eax*4 + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6311648) /* 0x604ee0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a03a  7406                   -je 0x44a042
    if (cpu.flags.zf)
    {
        goto L_0x0044a042;
    }
    // 0044a03c  66ff411a               +inc word ptr [ecx + 0x1a]
    {
        auto tmp = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        cpu.flags.of = ~(1 & (tmp >> 15));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 15);
        cpu.set_szp(tmp);
    }
    // 0044a040  ebd3                   -jmp 0x44a015
    goto L_0x0044a015;
L_0x0044a042:
    // 0044a042  8b4116                 -mov eax, dword ptr [ecx + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a045  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a048  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a04b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a04e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a050  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a057  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a059  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a05c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a05e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a061  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044a066  8b5002                 -mov edx, dword ptr [eax + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0044a069  e842f9ffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 0044a06e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a071  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a073  7503                   -jne 0x44a078
    if (!cpu.flags.zf)
    {
        goto L_0x0044a078;
    }
    // 0044a075  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044a078:
    // 0044a078  66f7c20113             +test dx, 0x1301
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & 4865 /*0x1301*/));
    // 0044a07d  7584                   -jne 0x44a003
    if (!cpu.flags.zf)
    {
        goto L_0x0044a003;
    }
L_0x0044a07f:
    // 0044a07f  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a082  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a085  39d8                   +cmp eax, ebx
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
    // 0044a087  740c                   -je 0x44a095
    if (cpu.flags.zf)
    {
        goto L_0x0044a095;
    }
    // 0044a089  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0044a08e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a090  e83be1fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a095:
    // 0044a095  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a097  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044a099  e8b2fdffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044a09e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a0a0  7404                   -je 0x44a0a6
    if (cpu.flags.zf)
    {
        goto L_0x0044a0a6;
    }
    // 0044a0a2  6689591c               -mov word ptr [ecx + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.bx;
L_0x0044a0a6:
    // 0044a0a6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a0a8  e8f3fdffff             -call 0x449ea0
    cpu.esp -= 4;
    sub_449ea0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a0ad:
    // 0044a0ad  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a0af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a0b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a0b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a0b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a0b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a0b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_44a0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a0c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a0c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a0c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a0c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044a0c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a0c5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a0c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044a0ca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044a0cc  6683781a64             +cmp word ptr [eax + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a0d1  742a                   -je 0x44a0fd
    if (cpu.flags.zf)
    {
        goto L_0x0044a0fd;
    }
    // 0044a0d3  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a0d6  8b4016                 -mov eax, dword ptr [eax + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044a0d9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a0dc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a0df  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a0e1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a0e8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a0ea  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a0ed  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a0ef  f60485e54e600004       +test byte ptr [eax*4 + 0x604ee5], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6311653) /* 0x604ee5 */ + cpu.eax * 4) & 4 /*0x4*/));
    // 0044a0f7  0f8536010000           -jne 0x44a233
    if (!cpu.flags.zf)
    {
        goto L_0x0044a233;
    }
L_0x0044a0fd:
    // 0044a0fd  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a100  668b711a               -mov si, word ptr [ecx + 0x1a]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 0044a104  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0044a107  6683fe64               +cmp si, 0x64
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a10b  740d                   -je 0x44a11a
    if (cpu.flags.zf)
    {
        goto L_0x0044a11a;
    }
    // 0044a10d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a10f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044a111  e83afdffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044a116  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a118  751e                   -jne 0x44a138
    if (!cpu.flags.zf)
    {
        goto L_0x0044a138;
    }
L_0x0044a11a:
    // 0044a11a  8b411a                 -mov eax, dword ptr [ecx + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 0044a11d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a11f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a122  e829fdffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044a127  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a129  740d                   -je 0x44a138
    if (cpu.flags.zf)
    {
        goto L_0x0044a138;
    }
    // 0044a12b  668b411c               -mov ax, word ptr [ecx + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0044a12f  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 0044a133  e9cd000000             -jmp 0x44a205
    goto L_0x0044a205;
L_0x0044a138:
    // 0044a138  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a13d  7559                   -jne 0x44a198
    if (!cpu.flags.zf)
    {
        goto L_0x0044a198;
    }
    // 0044a13f  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a142  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
L_0x0044a145:
    // 0044a145  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a14c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a14e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a151  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a153  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a156  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a15d  0f84a2000000           -je 0x44a205
    if (cpu.flags.zf)
    {
        goto L_0x0044a205;
    }
    // 0044a163  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044a168  8b7002                 -mov esi, dword ptr [eax + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0044a16b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0044a16e  e83df8ffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 0044a173  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0044a176  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a178  7504                   -jne 0x44a17e
    if (!cpu.flags.zf)
    {
        goto L_0x0044a17e;
    }
    // 0044a17a  804dfc01               -or byte ptr [ebp - 4], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044a17e:
    // 0044a17e  66f745fc0113           +test word ptr [ebp - 4], 0x1301
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 4865 /*0x1301*/));
    // 0044a184  750f                   -jne 0x44a195
    if (!cpu.flags.zf)
    {
        goto L_0x0044a195;
    }
    // 0044a186  668b4118               -mov ax, word ptr [ecx + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a18a  29c2                   +sub edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044a18c  6689511a               -mov word ptr [ecx + 0x1a], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.dx;
    // 0044a190  e970000000             -jmp 0x44a205
    goto L_0x0044a205;
L_0x0044a195:
    // 0044a195  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a196  ebad                   -jmp 0x44a145
    goto L_0x0044a145;
L_0x0044a198:
    // 0044a198  66ff411a               -inc word ptr [ecx + 0x1a]
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */))++;
    // 0044a19c  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a19f  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a1a2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a1a5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a1a8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a1aa  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a1b1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a1b3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a1b6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a1b8  833c85e04e600000       +cmp dword ptr [eax*4 + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6311648) /* 0x604ee0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a1c0  7506                   -jne 0x44a1c8
    if (!cpu.flags.zf)
    {
        goto L_0x0044a1c8;
    }
    // 0044a1c2  66c7411a0000           -mov word ptr [ecx + 0x1a], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = 0 /*0x0*/;
L_0x0044a1c8:
    // 0044a1c8  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a1cb  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a1ce  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a1d1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a1d4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a1d6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a1dd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a1df  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a1e2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a1e4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a1e7  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044a1ec  8b5002                 -mov edx, dword ptr [eax + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0044a1ef  e8bcf7ffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 0044a1f4  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a1f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a1f9  7503                   -jne 0x44a1fe
    if (!cpu.flags.zf)
    {
        goto L_0x0044a1fe;
    }
    // 0044a1fb  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044a1fe:
    // 0044a1fe  66f7c20113             +test dx, 0x1301
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & 4865 /*0x1301*/));
    // 0044a203  7593                   -jne 0x44a198
    if (!cpu.flags.zf)
    {
        goto L_0x0044a198;
    }
L_0x0044a205:
    // 0044a205  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a207  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044a209  e842fcffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044a20e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a210  7404                   -je 0x44a216
    if (cpu.flags.zf)
    {
        goto L_0x0044a216;
    }
    // 0044a212  6689591c               -mov word ptr [ecx + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.bx;
L_0x0044a216:
    // 0044a216  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a219  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a21c  39d8                   +cmp eax, ebx
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
    // 0044a21e  740c                   -je 0x44a22c
    if (cpu.flags.zf)
    {
        goto L_0x0044a22c;
    }
    // 0044a220  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0044a225  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a227  e8a4dffcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a22c:
    // 0044a22c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a22e  e86dfcffff             -call 0x449ea0
    cpu.esp -= 4;
    sub_449ea0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a233:
    // 0044a233  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a235  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a236  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a237  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a238  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a239  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a23a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44a240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a240  68bc8f5300             -push 0x538fbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5476284 /*0x538fbc*/;
    cpu.esp -= 4;
    // 0044a245  e802000000             -call 0x44a24c
    cpu.esp -= 4;
    sub_44a24c(app, cpu);
    if (cpu.terminate) return;
    // 0044a24a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_44a24c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a24c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a24d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a24e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044a24f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044a250  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a251  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a253  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044a256  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044a258  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0044a25a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a25c  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0044a25f  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0044a261  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a263  7453                   -je 0x44a2b8
    if (cpu.flags.zf)
    {
        goto L_0x0044a2b8;
    }
    // 0044a265  0fbf5818               -movsx ebx, word ptr [eax + 0x18]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(24) /* 0x18 */)));
L_0x0044a269:
    // 0044a269  69c3bc000000           -imul eax, ebx, 0xbc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(188 /*0xbc*/)));
    // 0044a26f  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a276  743d                   -je 0x44a2b5
    if (cpu.flags.zf)
    {
        goto L_0x0044a2b5;
    }
    // 0044a278  b9e04e6000             -mov ecx, 0x604ee0
    cpu.ecx = 6311648 /*0x604ee0*/;
    // 0044a27d  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a27f  833905                 +cmp dword ptr [ecx], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a282  752e                   -jne 0x44a2b2
    if (!cpu.flags.zf)
    {
        goto L_0x0044a2b2;
    }
    // 0044a284  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0044a287  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044a289  7427                   -je 0x44a2b2
    if (cpu.flags.zf)
    {
        goto L_0x0044a2b2;
    }
    // 0044a28b  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 0044a28f  7521                   -jne 0x44a2b2
    if (!cpu.flags.zf)
    {
        goto L_0x0044a2b2;
    }
    // 0044a291  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044a293  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0044a296  e82587ffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 0044a29b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a29d  7413                   -je 0x44a2b2
    if (cpu.flags.zf)
    {
        goto L_0x0044a2b2;
    }
    // 0044a29f  f6410401               +test byte ptr [ecx + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 0044a2a3  750d                   -jne 0x44a2b2
    if (!cpu.flags.zf)
    {
        goto L_0x0044a2b2;
    }
    // 0044a2a5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0044a2a7  0fbf4618               -movsx eax, word ptr [esi + 0x18]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 0044a2ab  29c2                   +sub edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044a2ad  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0044a2b0  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
L_0x0044a2b2:
    // 0044a2b2  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a2b3  ebb4                   -jmp 0x44a269
    goto L_0x0044a269;
L_0x0044a2b5:
    // 0044a2b5  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x0044a2b8:
    // 0044a2b8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a2ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a2bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a2bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a2bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a2be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a2bf  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_44a2c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a2c2  90                     -nop 
    ;
    // 0044a2c3  90                     -nop 
    ;
    // 0044a2c4  90                     -nop 
    ;
    // 0044a2c5  90                     -nop 
    ;
    // 0044a2c6  90                     -nop 
    ;
    // 0044a2c7  90                     -nop 
    ;
    // 0044a2c8  90                     -nop 
    ;
    // 0044a2c9  90                     -nop 
    ;
    // 0044a2ca  90                     -nop 
    ;
    // 0044a2cb  90                     -nop 
    ;
    // 0044a2cc  90                     -nop 
    ;
    // 0044a2cd  90                     -nop 
    ;
    // 0044a2ce  90                     -nop 
    ;
    // 0044a2cf  90                     -nop 
    ;
    // 0044a2d0  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0044a2d1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a2d3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044a2d6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044a2d8  0fbff2                 -movsx esi, dx
    cpu.esi = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0044a2db  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044a2dd  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0044a2e0  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
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
    // 0044a2e7  742c                   -je 0x44a315
    if (cpu.flags.zf)
    {
        goto L_0x0044a315;
    }
    // 0044a2e9  6683fe09               +cmp si, 9
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(9 /*0x9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a2ed  7426                   -je 0x44a315
    if (cpu.flags.zf)
    {
        goto L_0x0044a315;
    }
    // 0044a2ef  6683fe1b               +cmp si, 0x1b
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a2f3  7420                   -je 0x44a315
    if (cpu.flags.zf)
    {
        goto L_0x0044a315;
    }
    // 0044a2f5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044a2f7  e80474ffff             -call 0x441700
    cpu.esp -= 4;
    sub_441700(app, cpu);
    if (cpu.terminate) return;
    // 0044a2fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044a2fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a300  0f8522010000           -jne 0x44a428
    if (!cpu.flags.zf)
    {
        goto L_0x0044a428;
    }
    // 0044a306  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a308  e8e3f6ffff             -call 0x4499f0
    cpu.esp -= 4;
    sub_4499f0(app, cpu);
    if (cpu.terminate) return;
    // 0044a30d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a30f  0f8413010000           -je 0x44a428
    if (cpu.flags.zf)
    {
        goto L_0x0044a428;
    }
L_0x0044a315:
    // 0044a315  833d6829660000         +cmp dword ptr [0x662968], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a31c  7507                   -jne 0x44a325
    if (!cpu.flags.zf)
    {
        goto L_0x0044a325;
    }
    // 0044a31e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044a320  e8bb810000             -call 0x4524e0
    cpu.esp -= 4;
    sub_4524e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a325:
    // 0044a325  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a32a  750d                   -jne 0x44a339
    if (!cpu.flags.zf)
    {
        goto L_0x0044a339;
    }
    // 0044a32c  6683fe0d               +cmp si, 0xd
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
    // 0044a330  7530                   -jne 0x44a362
    if (!cpu.flags.zf)
    {
        goto L_0x0044a362;
    }
    // 0044a332  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044a334  e9f6000000             -jmp 0x44a42f
    goto L_0x0044a42f;
L_0x0044a339:
    // 0044a339  bfe04e6000             -mov edi, 0x604ee0
    cpu.edi = 6311648 /*0x604ee0*/;
    // 0044a33e  0fbf511a               -movsx edx, word ptr [ecx + 0x1a]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */)));
    // 0044a342  0fbf4118               -movsx eax, word ptr [ecx + 0x18]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 0044a346  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044a348  69c0bc000000           -imul eax, eax, 0xbc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(188 /*0xbc*/)));
    // 0044a34e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a350  837f3000               +cmp dword ptr [edi + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a354  740c                   -je 0x44a362
    if (cpu.flags.zf)
    {
        goto L_0x0044a362;
    }
    // 0044a356  0fbfde                 -movsx ebx, si
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0044a359  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a35b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044a35d  ff5730                 -call dword ptr [edi + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a360  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0044a362:
    // 0044a362  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044a364  0f85be000000           -jne 0x44a428
    if (!cpu.flags.zf)
    {
        goto L_0x0044a428;
    }
    // 0044a36a  66bf0100               -mov di, 1
    cpu.di = 1 /*0x1*/;
    // 0044a36e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a370  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044a373  6683fe09               +cmp si, 9
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(9 /*0x9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a377  7427                   -je 0x44a3a0
    if (cpu.flags.zf)
    {
        goto L_0x0044a3a0;
    }
    // 0044a379  6683fe1b               +cmp si, 0x1b
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a37d  742a                   -je 0x44a3a9
    if (cpu.flags.zf)
    {
        goto L_0x0044a3a9;
    }
    // 0044a37f  6681fe0048             +cmp si, 0x4800
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18432 /*0x4800*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a384  7435                   -je 0x44a3bb
    if (cpu.flags.zf)
    {
        goto L_0x0044a3bb;
    }
    // 0044a386  6681fe004b             +cmp si, 0x4b00
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a38b  743e                   -je 0x44a3cb
    if (cpu.flags.zf)
    {
        goto L_0x0044a3cb;
    }
    // 0044a38d  6681fe004d             +cmp si, 0x4d00
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a392  745e                   -je 0x44a3f2
    if (cpu.flags.zf)
    {
        goto L_0x0044a3f2;
    }
    // 0044a394  6681fe0050             +cmp si, 0x5000
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20480 /*0x5000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a399  7447                   -je 0x44a3e2
    if (cpu.flags.zf)
    {
        goto L_0x0044a3e2;
    }
    // 0044a39b  e988000000             -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a3a0:
    // 0044a3a0  e8277c0a00             -call 0x4f1fcc
    cpu.esp -= 4;
    sub_4f1fcc(app, cpu);
    if (cpu.terminate) return;
    // 0044a3a5  7532                   -jne 0x44a3d9
    if (!cpu.flags.zf)
    {
        goto L_0x0044a3d9;
    }
    // 0044a3a7  eb57                   -jmp 0x44a400
    goto L_0x0044a400;
L_0x0044a3a9:
    // 0044a3a9  66bf0300               -mov di, 3
    cpu.di = 3 /*0x3*/;
    // 0044a3ad  e88efeffff             -call 0x44a240
    cpu.esp -= 4;
    sub_44a240(app, cpu);
    if (cpu.terminate) return;
    // 0044a3b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3b4  7553                   -jne 0x44a409
    if (!cpu.flags.zf)
    {
        goto L_0x0044a409;
    }
    // 0044a3b6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044a3b8  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a3b9  eb65                   -jmp 0x44a420
    goto L_0x0044a420;
L_0x0044a3bb:
    // 0044a3bb  6828be5300             -push 0x53be28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5488168 /*0x53be28*/;
    cpu.esp -= 4;
    // 0044a3c0  e887feffff             -call 0x44a24c
    cpu.esp -= 4;
    sub_44a24c(app, cpu);
    if (cpu.terminate) return;
    // 0044a3c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3c7  7540                   -jne 0x44a409
    if (!cpu.flags.zf)
    {
        goto L_0x0044a409;
    }
    // 0044a3c9  eb0e                   -jmp 0x44a3d9
    goto L_0x0044a3d9;
L_0x0044a3cb:
    // 0044a3cb  6836be5300             -push 0x53be36
    app->getMemory<x86::reg32>(cpu.esp-4) = 5488182 /*0x53be36*/;
    cpu.esp -= 4;
    // 0044a3d0  e877feffff             -call 0x44a24c
    cpu.esp -= 4;
    sub_44a24c(app, cpu);
    if (cpu.terminate) return;
    // 0044a3d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3d7  7530                   -jne 0x44a409
    if (!cpu.flags.zf)
    {
        goto L_0x0044a409;
    }
L_0x0044a3d9:
    // 0044a3d9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a3db  e850fbffff             -call 0x449f30
    cpu.esp -= 4;
    sub_449f30(app, cpu);
    if (cpu.terminate) return;
    // 0044a3e0  eb46                   -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a3e2:
    // 0044a3e2  682ebe5300             -push 0x53be2e
    app->getMemory<x86::reg32>(cpu.esp-4) = 5488174 /*0x53be2e*/;
    cpu.esp -= 4;
    // 0044a3e7  e860feffff             -call 0x44a24c
    cpu.esp -= 4;
    sub_44a24c(app, cpu);
    if (cpu.terminate) return;
    // 0044a3ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3ee  7519                   -jne 0x44a409
    if (!cpu.flags.zf)
    {
        goto L_0x0044a409;
    }
    // 0044a3f0  eb0e                   -jmp 0x44a400
    goto L_0x0044a400;
L_0x0044a3f2:
    // 0044a3f2  683ebe5300             -push 0x53be3e
    app->getMemory<x86::reg32>(cpu.esp-4) = 5488190 /*0x53be3e*/;
    cpu.esp -= 4;
    // 0044a3f7  e850feffff             -call 0x44a24c
    cpu.esp -= 4;
    sub_44a24c(app, cpu);
    if (cpu.terminate) return;
    // 0044a3fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3fe  7509                   -jne 0x44a409
    if (!cpu.flags.zf)
    {
        goto L_0x0044a409;
    }
L_0x0044a400:
    // 0044a400  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a402  e8b9fcffff             -call 0x44a0c0
    cpu.esp -= 4;
    sub_44a0c0(app, cpu);
    if (cpu.terminate) return;
    // 0044a407  eb1f                   -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a409:
    // 0044a409  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044a40c  6689591a               -mov word ptr [ecx + 0x1a], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.bx;
    // 0044a410  6689591c               -mov word ptr [ecx + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.bx;
    // 0044a414  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 0044a419  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a41b  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a41e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0044a420:
    // 0044a420  0fb7c7                 -movzx eax, di
    cpu.eax = x86::reg32(cpu.di);
    // 0044a423  e8a8ddfcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a428:
    // 0044a428  83fb02                 +cmp ebx, 2
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
    // 0044a42b  7502                   -jne 0x44a42f
    if (!cpu.flags.zf)
    {
        goto L_0x0044a42f;
    }
    // 0044a42d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0044a42f:
    // 0044a42f  895d1c                 -mov dword ptr [ebp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0044a432  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a434  61                     -popal 
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
    // 0044a435  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_44a2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0044a2d0;
    // 0044a2c2  90                     -nop 
    ;
    // 0044a2c3  90                     -nop 
    ;
    // 0044a2c4  90                     -nop 
    ;
    // 0044a2c5  90                     -nop 
    ;
    // 0044a2c6  90                     -nop 
    ;
    // 0044a2c7  90                     -nop 
    ;
    // 0044a2c8  90                     -nop 
    ;
    // 0044a2c9  90                     -nop 
    ;
    // 0044a2ca  90                     -nop 
    ;
    // 0044a2cb  90                     -nop 
    ;
    // 0044a2cc  90                     -nop 
    ;
    // 0044a2cd  90                     -nop 
    ;
    // 0044a2ce  90                     -nop 
    ;
    // 0044a2cf  90                     -nop 
    ;
L_entry_0x0044a2d0:
    // 0044a2d0  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0044a2d1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a2d3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044a2d6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044a2d8  0fbff2                 -movsx esi, dx
    cpu.esi = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0044a2db  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044a2dd  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0044a2e0  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
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
    // 0044a2e7  742c                   -je 0x44a315
    if (cpu.flags.zf)
    {
        goto L_0x0044a315;
    }
    // 0044a2e9  6683fe09               +cmp si, 9
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(9 /*0x9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a2ed  7426                   -je 0x44a315
    if (cpu.flags.zf)
    {
        goto L_0x0044a315;
    }
    // 0044a2ef  6683fe1b               +cmp si, 0x1b
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a2f3  7420                   -je 0x44a315
    if (cpu.flags.zf)
    {
        goto L_0x0044a315;
    }
    // 0044a2f5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044a2f7  e80474ffff             -call 0x441700
    cpu.esp -= 4;
    sub_441700(app, cpu);
    if (cpu.terminate) return;
    // 0044a2fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044a2fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a300  0f8522010000           -jne 0x44a428
    if (!cpu.flags.zf)
    {
        goto L_0x0044a428;
    }
    // 0044a306  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a308  e8e3f6ffff             -call 0x4499f0
    cpu.esp -= 4;
    sub_4499f0(app, cpu);
    if (cpu.terminate) return;
    // 0044a30d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a30f  0f8413010000           -je 0x44a428
    if (cpu.flags.zf)
    {
        goto L_0x0044a428;
    }
L_0x0044a315:
    // 0044a315  833d6829660000         +cmp dword ptr [0x662968], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a31c  7507                   -jne 0x44a325
    if (!cpu.flags.zf)
    {
        goto L_0x0044a325;
    }
    // 0044a31e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044a320  e8bb810000             -call 0x4524e0
    cpu.esp -= 4;
    sub_4524e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a325:
    // 0044a325  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a32a  750d                   -jne 0x44a339
    if (!cpu.flags.zf)
    {
        goto L_0x0044a339;
    }
    // 0044a32c  6683fe0d               +cmp si, 0xd
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
    // 0044a330  7530                   -jne 0x44a362
    if (!cpu.flags.zf)
    {
        goto L_0x0044a362;
    }
    // 0044a332  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044a334  e9f6000000             -jmp 0x44a42f
    goto L_0x0044a42f;
L_0x0044a339:
    // 0044a339  bfe04e6000             -mov edi, 0x604ee0
    cpu.edi = 6311648 /*0x604ee0*/;
    // 0044a33e  0fbf511a               -movsx edx, word ptr [ecx + 0x1a]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */)));
    // 0044a342  0fbf4118               -movsx eax, word ptr [ecx + 0x18]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 0044a346  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044a348  69c0bc000000           -imul eax, eax, 0xbc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(188 /*0xbc*/)));
    // 0044a34e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a350  837f3000               +cmp dword ptr [edi + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a354  740c                   -je 0x44a362
    if (cpu.flags.zf)
    {
        goto L_0x0044a362;
    }
    // 0044a356  0fbfde                 -movsx ebx, si
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0044a359  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a35b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044a35d  ff5730                 -call dword ptr [edi + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a360  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0044a362:
    // 0044a362  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044a364  0f85be000000           -jne 0x44a428
    if (!cpu.flags.zf)
    {
        goto L_0x0044a428;
    }
    // 0044a36a  66bf0100               -mov di, 1
    cpu.di = 1 /*0x1*/;
    // 0044a36e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a370  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044a373  6683fe09               +cmp si, 9
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(9 /*0x9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a377  7427                   -je 0x44a3a0
    if (cpu.flags.zf)
    {
        goto L_0x0044a3a0;
    }
    // 0044a379  6683fe1b               +cmp si, 0x1b
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a37d  742a                   -je 0x44a3a9
    if (cpu.flags.zf)
    {
        goto L_0x0044a3a9;
    }
    // 0044a37f  6681fe0048             +cmp si, 0x4800
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18432 /*0x4800*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a384  7435                   -je 0x44a3bb
    if (cpu.flags.zf)
    {
        goto L_0x0044a3bb;
    }
    // 0044a386  6681fe004b             +cmp si, 0x4b00
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a38b  743e                   -je 0x44a3cb
    if (cpu.flags.zf)
    {
        goto L_0x0044a3cb;
    }
    // 0044a38d  6681fe004d             +cmp si, 0x4d00
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a392  745e                   -je 0x44a3f2
    if (cpu.flags.zf)
    {
        goto L_0x0044a3f2;
    }
    // 0044a394  6681fe0050             +cmp si, 0x5000
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20480 /*0x5000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a399  7447                   -je 0x44a3e2
    if (cpu.flags.zf)
    {
        goto L_0x0044a3e2;
    }
    // 0044a39b  e988000000             -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a3a0:
    // 0044a3a0  e8277c0a00             -call 0x4f1fcc
    cpu.esp -= 4;
    sub_4f1fcc(app, cpu);
    if (cpu.terminate) return;
    // 0044a3a5  7532                   -jne 0x44a3d9
    if (!cpu.flags.zf)
    {
        goto L_0x0044a3d9;
    }
    // 0044a3a7  eb57                   -jmp 0x44a400
    goto L_0x0044a400;
L_0x0044a3a9:
    // 0044a3a9  66bf0300               -mov di, 3
    cpu.di = 3 /*0x3*/;
    // 0044a3ad  e88efeffff             -call 0x44a240
    cpu.esp -= 4;
    sub_44a240(app, cpu);
    if (cpu.terminate) return;
    // 0044a3b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3b4  7553                   -jne 0x44a409
    if (!cpu.flags.zf)
    {
        goto L_0x0044a409;
    }
    // 0044a3b6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044a3b8  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a3b9  eb65                   -jmp 0x44a420
    goto L_0x0044a420;
L_0x0044a3bb:
    // 0044a3bb  6828be5300             -push 0x53be28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5488168 /*0x53be28*/;
    cpu.esp -= 4;
    // 0044a3c0  e887feffff             -call 0x44a24c
    cpu.esp -= 4;
    sub_44a24c(app, cpu);
    if (cpu.terminate) return;
    // 0044a3c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3c7  7540                   -jne 0x44a409
    if (!cpu.flags.zf)
    {
        goto L_0x0044a409;
    }
    // 0044a3c9  eb0e                   -jmp 0x44a3d9
    goto L_0x0044a3d9;
L_0x0044a3cb:
    // 0044a3cb  6836be5300             -push 0x53be36
    app->getMemory<x86::reg32>(cpu.esp-4) = 5488182 /*0x53be36*/;
    cpu.esp -= 4;
    // 0044a3d0  e877feffff             -call 0x44a24c
    cpu.esp -= 4;
    sub_44a24c(app, cpu);
    if (cpu.terminate) return;
    // 0044a3d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3d7  7530                   -jne 0x44a409
    if (!cpu.flags.zf)
    {
        goto L_0x0044a409;
    }
L_0x0044a3d9:
    // 0044a3d9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a3db  e850fbffff             -call 0x449f30
    cpu.esp -= 4;
    sub_449f30(app, cpu);
    if (cpu.terminate) return;
    // 0044a3e0  eb46                   -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a3e2:
    // 0044a3e2  682ebe5300             -push 0x53be2e
    app->getMemory<x86::reg32>(cpu.esp-4) = 5488174 /*0x53be2e*/;
    cpu.esp -= 4;
    // 0044a3e7  e860feffff             -call 0x44a24c
    cpu.esp -= 4;
    sub_44a24c(app, cpu);
    if (cpu.terminate) return;
    // 0044a3ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3ee  7519                   -jne 0x44a409
    if (!cpu.flags.zf)
    {
        goto L_0x0044a409;
    }
    // 0044a3f0  eb0e                   -jmp 0x44a400
    goto L_0x0044a400;
L_0x0044a3f2:
    // 0044a3f2  683ebe5300             -push 0x53be3e
    app->getMemory<x86::reg32>(cpu.esp-4) = 5488190 /*0x53be3e*/;
    cpu.esp -= 4;
    // 0044a3f7  e850feffff             -call 0x44a24c
    cpu.esp -= 4;
    sub_44a24c(app, cpu);
    if (cpu.terminate) return;
    // 0044a3fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3fe  7509                   -jne 0x44a409
    if (!cpu.flags.zf)
    {
        goto L_0x0044a409;
    }
L_0x0044a400:
    // 0044a400  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a402  e8b9fcffff             -call 0x44a0c0
    cpu.esp -= 4;
    sub_44a0c0(app, cpu);
    if (cpu.terminate) return;
    // 0044a407  eb1f                   -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a409:
    // 0044a409  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044a40c  6689591a               -mov word ptr [ecx + 0x1a], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.bx;
    // 0044a410  6689591c               -mov word ptr [ecx + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.bx;
    // 0044a414  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 0044a419  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a41b  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a41e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0044a420:
    // 0044a420  0fb7c7                 -movzx eax, di
    cpu.eax = x86::reg32(cpu.di);
    // 0044a423  e8a8ddfcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a428:
    // 0044a428  83fb02                 +cmp ebx, 2
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
    // 0044a42b  7502                   -jne 0x44a42f
    if (!cpu.flags.zf)
    {
        goto L_0x0044a42f;
    }
    // 0044a42d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0044a42f:
    // 0044a42f  895d1c                 -mov dword ptr [ebp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0044a432  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a434  61                     -popal 
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
    // 0044a435  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_44a436(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a436  90                     -nop 
    ;
    // 0044a437  90                     -nop 
    ;
    // 0044a438  90                     -nop 
    ;
    // 0044a439  90                     -nop 
    ;
    // 0044a43a  90                     -nop 
    ;
    // 0044a43b  90                     -nop 
    ;
    // 0044a43c  90                     -nop 
    ;
    // 0044a43d  90                     -nop 
    ;
    // 0044a43e  90                     -nop 
    ;
    // 0044a43f  90                     -nop 
    ;
    // 0044a440  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a441  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a442  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a444  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a449  6683781a64             +cmp word ptr [eax + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a44e  7508                   -jne 0x44a458
    if (!cpu.flags.zf)
    {
        goto L_0x0044a458;
    }
    // 0044a450  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0044a455  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a456  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a457  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044a458:
    // 0044a458  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044a45b  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044a45e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a461  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a464  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044a466  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a467  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a468  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_44a440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0044a440;
    // 0044a436  90                     -nop 
    ;
    // 0044a437  90                     -nop 
    ;
    // 0044a438  90                     -nop 
    ;
    // 0044a439  90                     -nop 
    ;
    // 0044a43a  90                     -nop 
    ;
    // 0044a43b  90                     -nop 
    ;
    // 0044a43c  90                     -nop 
    ;
    // 0044a43d  90                     -nop 
    ;
    // 0044a43e  90                     -nop 
    ;
    // 0044a43f  90                     -nop 
    ;
L_entry_0x0044a440:
    // 0044a440  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a441  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a442  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a444  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a449  6683781a64             +cmp word ptr [eax + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a44e  7508                   -jne 0x44a458
    if (!cpu.flags.zf)
    {
        goto L_0x0044a458;
    }
    // 0044a450  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0044a455  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a456  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a457  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044a458:
    // 0044a458  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044a45b  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044a45e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a461  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a464  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044a466  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a467  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a468  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44a470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a472  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a473  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a474  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a476  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044a478  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a47d  8b4816                 -mov ecx, dword ptr [eax + 0x16]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044a480  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
L_0x0044a483:
    // 0044a483  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044a48a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044a48c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a48f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044a491  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a494  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a49b  7447                   -je 0x44a4e4
    if (cpu.flags.zf)
    {
        goto L_0x0044a4e4;
    }
    // 0044a49d  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044a4a2  39d8                   +cmp eax, ebx
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
    // 0044a4a4  753b                   -jne 0x44a4e1
    if (!cpu.flags.zf)
    {
        goto L_0x0044a4e1;
    }
    // 0044a4a6  8b1530925500           -mov edx, dword ptr [0x559230]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a4ac  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0044a4af  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a4b2  e899f9ffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044a4b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a4b9  740d                   -je 0x44a4c8
    if (cpu.flags.zf)
    {
        goto L_0x0044a4c8;
    }
    // 0044a4bb  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a4c0  668b501a               -mov dx, word ptr [eax + 0x1a]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
    // 0044a4c4  6689501c               -mov word ptr [eax + 0x1c], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.dx;
L_0x0044a4c8:
    // 0044a4c8  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a4cd  668b5018               -mov dx, word ptr [eax + 0x18]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044a4d1  29d1                   +sub ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044a4d3  6689481a               -mov word ptr [eax + 0x1a], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */) = cpu.cx;
    // 0044a4d7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044a4dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044a4e1:
    // 0044a4e1  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a4e2  eb9f                   -jmp 0x44a483
    goto L_0x0044a483;
L_0x0044a4e4:
    // 0044a4e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a4e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44a4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a4f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a4f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a4f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a4f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044a4f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044a4f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a4f6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a4f8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044a4fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044a4fd  668b5818               -mov bx, word ptr [eax + 0x18]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044a501  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044a503  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0044a505:
    // 0044a505  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044a508  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0044a50b  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044a50e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a511  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a513  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a516  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a518  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a51b  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a522  7412                   -je 0x44a536
    if (cpu.flags.zf)
    {
        goto L_0x0044a536;
    }
    // 0044a524  8b80e84e6000           -mov eax, dword ptr [eax + 0x604ee8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311656) /* 0x604ee8 */);
    // 0044a52a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a52d  39c8                   +cmp eax, ecx
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
    // 0044a52f  7e02                   -jle 0x44a533
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044a533;
    }
    // 0044a531  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0044a533:
    // 0044a533  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a534  ebcf                   -jmp 0x44a505
    goto L_0x0044a505;
L_0x0044a536:
    // 0044a536  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044a538  0f8cfc000000           -jl 0x44a63a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044a63a;
    }
    // 0044a53e  83f904                 +cmp ecx, 4
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
    // 0044a541  7f14                   -jg 0x44a557
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0044a557;
    }
    // 0044a543  b800ff7f3f             -mov eax, 0x3f7fff00
    cpu.eax = 1065352960 /*0x3f7fff00*/;
    // 0044a548  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044a54a  a3ac3a5600             -mov dword ptr [0x563aac], eax
    app->getMemory<x86::reg32>(x86::reg32(5651116) /* 0x563aac */) = cpu.eax;
    // 0044a54f  891da83a5600           -mov dword ptr [0x563aa8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651112) /* 0x563aa8 */) = cpu.ebx;
    // 0044a555  eb16                   -jmp 0x44a56d
    goto L_0x0044a56d;
L_0x0044a557:
    // 0044a557  bb80008037             -mov ebx, 0x37800080
    cpu.ebx = 931135616 /*0x37800080*/;
    // 0044a55c  ba00ff7f3f             -mov edx, 0x3f7fff00
    cpu.edx = 1065352960 /*0x3f7fff00*/;
    // 0044a561  891dac3a5600           -mov dword ptr [0x563aac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651116) /* 0x563aac */) = cpu.ebx;
    // 0044a567  8915a83a5600           -mov dword ptr [0x563aa8], edx
    app->getMemory<x86::reg32>(x86::reg32(5651112) /* 0x563aa8 */) = cpu.edx;
L_0x0044a56d:
    // 0044a56d  668b4618               -mov ax, word ptr [esi + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0044a571  668945fc               -mov word ptr [ebp - 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
L_0x0044a575:
    // 0044a575  8b55fa                 -mov edx, dword ptr [ebp - 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0044a578  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a57b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a582  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a584  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a587  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a589  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a58c  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a593  7456                   -je 0x44a5eb
    if (cpu.flags.zf)
    {
        goto L_0x0044a5eb;
    }
    // 0044a595  bbe04e6000             -mov ebx, 0x604ee0
    cpu.ebx = 6311648 /*0x604ee0*/;
    // 0044a59a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a59c  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0044a59f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a5a2  39c1                   +cmp ecx, eax
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
    // 0044a5a4  753f                   -jne 0x44a5e5
    if (!cpu.flags.zf)
    {
        goto L_0x0044a5e5;
    }
    // 0044a5a6  668b461a               -mov ax, word ptr [esi + 0x1a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 0044a5aa  6683f864               +cmp ax, 0x64
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a5ae  7412                   -je 0x44a5c2
    if (cpu.flags.zf)
    {
        goto L_0x0044a5c2;
    }
    // 0044a5b0  66034618               -add ax, word ptr [esi + 0x18]
    (cpu.ax) += x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 0044a5b4  0fbfc0                 -movsx eax, ax
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0044a5b7  39c2                   +cmp edx, eax
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
    // 0044a5b9  7507                   -jne 0x44a5c2
    if (!cpu.flags.zf)
    {
        goto L_0x0044a5c2;
    }
    // 0044a5bb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044a5c0  eb09                   -jmp 0x44a5cb
    goto L_0x0044a5cb;
L_0x0044a5c2:
    // 0044a5c2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044a5c4  eb05                   -jmp 0x44a5cb
    goto L_0x0044a5cb;
    // 0044a5c6  90                     -nop 
    ;
    // 0044a5c7  90                     -nop 
    ;
    // 0044a5c8  90                     -nop 
    ;
    // 0044a5c9  90                     -nop 
    ;
    // 0044a5ca  90                     -nop 
    ;
L_0x0044a5cb:
    // 0044a5cb  837b2c00               +cmp dword ptr [ebx + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a5cf  7414                   -je 0x44a5e5
    if (cpu.flags.zf)
    {
        goto L_0x0044a5e5;
    }
    // 0044a5d1  f6430510               +test byte ptr [ebx + 5], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) & 16 /*0x10*/));
    // 0044a5d5  750e                   -jne 0x44a5e5
    if (!cpu.flags.zf)
    {
        goto L_0x0044a5e5;
    }
    // 0044a5d7  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0044a5d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044a5da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044a5dc  ff532c                 -call dword ptr [ebx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a5df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a5e1  7402                   -je 0x44a5e5
    if (cpu.flags.zf)
    {
        goto L_0x0044a5e5;
    }
    // 0044a5e3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0044a5e5:
    // 0044a5e5  66ff45fc               +inc word ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 15));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 15);
        cpu.set_szp(tmp);
    }
    // 0044a5e9  eb8a                   -jmp 0x44a575
    goto L_0x0044a575;
L_0x0044a5eb:
    // 0044a5eb  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a5f2  7416                   -je 0x44a60a
    if (cpu.flags.zf)
    {
        goto L_0x0044a60a;
    }
    // 0044a5f4  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
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
    // 0044a5fb  7437                   -je 0x44a634
    if (cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a5fd  e83e6affff             -call 0x441040
    cpu.esp -= 4;
    sub_441040(app, cpu);
    if (cpu.terminate) return;
    // 0044a602  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a604  742e                   -je 0x44a634
    if (cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a606  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044a608  eb2a                   -jmp 0x44a634
    goto L_0x0044a634;
L_0x0044a60a:
    // 0044a60a  83f908                 +cmp ecx, 8
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
    // 0044a60d  7525                   -jne 0x44a634
    if (!cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a60f  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
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
    // 0044a616  741c                   -je 0x44a634
    if (cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a618  bac48f5300             -mov edx, 0x538fc4
    cpu.edx = 5476292 /*0x538fc4*/;
    // 0044a61d  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0044a620  e8eb3c0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044a625  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a627  740b                   -je 0x44a634
    if (cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a629  e8126affff             -call 0x441040
    cpu.esp -= 4;
    sub_441040(app, cpu);
    if (cpu.terminate) return;
    // 0044a62e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a630  7402                   -je 0x44a634
    if (cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a632  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0044a634:
    // 0044a634  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044a635  e9fcfeffff             -jmp 0x44a536
    goto L_0x0044a536;
L_0x0044a63a:
    // 0044a63a  bb80008037             -mov ebx, 0x37800080
    cpu.ebx = 931135616 /*0x37800080*/;
    // 0044a63f  b900ff7f3f             -mov ecx, 0x3f7fff00
    cpu.ecx = 1065352960 /*0x3f7fff00*/;
    // 0044a644  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044a646  891dac3a5600           -mov dword ptr [0x563aac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651116) /* 0x563aac */) = cpu.ebx;
    // 0044a64c  890da83a5600           -mov dword ptr [0x563aa8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5651112) /* 0x563aa8 */) = cpu.ecx;
    // 0044a652  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a654  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a655  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a656  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a657  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a658  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a659  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a65a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44a660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a660  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a661  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a663  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a66a  740a                   -je 0x44a676
    if (cpu.flags.zf)
    {
        goto L_0x0044a676;
    }
    // 0044a66c  f6400508               +test byte ptr [eax + 5], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) & 8 /*0x8*/));
    // 0044a670  7504                   -jne 0x44a676
    if (!cpu.flags.zf)
    {
        goto L_0x0044a676;
    }
    // 0044a672  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a674  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a675  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044a676:
    // 0044a676  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044a67b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a67c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_44a680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a680  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a681  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a683  c6055092550001         -mov byte ptr [0x559250], 1
    app->getMemory<x86::reg8>(x86::reg32(5608016) /* 0x559250 */) = 1 /*0x1*/;
    // 0044a68a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a68b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_44a690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a690  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a691  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a693  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0044a695  882550925500           -mov byte ptr [0x559250], ah
    app->getMemory<x86::reg8>(x86::reg32(5608016) /* 0x559250 */) = cpu.ah;
    // 0044a69b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a69c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_44a6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a6a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a6a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a6a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a6a5  a050925500             -mov al, byte ptr [0x559250]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5608016) /* 0x559250 */);
    // 0044a6aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a6ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_44a6b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a6b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a6b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a6b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a6b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044a6b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044a6b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a6b6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a6b8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0044a6bb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044a6bd  8b15d0565500           -mov edx, dword ptr [0x5556d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */);
    // 0044a6c3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044a6c5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044a6c7  0f8585010000           -jne 0x44a852
    if (!cpu.flags.zf)
    {
        goto L_0x0044a852;
    }
    // 0044a6cd  e8de91ffff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 0044a6d2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0044a6d4  7536                   -jne 0x44a70c
    if (!cpu.flags.zf)
    {
        goto L_0x0044a70c;
    }
    // 0044a6d6  803d5092550000         +cmp byte ptr [0x559250], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5608016) /* 0x559250 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044a6dd  752d                   -jne 0x44a70c
    if (!cpu.flags.zf)
    {
        goto L_0x0044a70c;
    }
    // 0044a6df  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a6e4  7431                   -je 0x44a717
    if (cpu.flags.zf)
    {
        goto L_0x0044a717;
    }
    // 0044a6e6  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a6e9  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a6ec  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a6ef  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a6f2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a6f4  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a6fb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a6fd  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a700  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a702  f60485e54e600004       +test byte ptr [eax*4 + 0x604ee5], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6311653) /* 0x604ee5 */ + cpu.eax * 4) & 4 /*0x4*/));
    // 0044a70a  740b                   -je 0x44a717
    if (cpu.flags.zf)
    {
        goto L_0x0044a717;
    }
L_0x0044a70c:
    // 0044a70c  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a70f  c1f810                 +sar eax, 0x10
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
    // 0044a712  e940010000             -jmp 0x44a857
    goto L_0x0044a857;
L_0x0044a717:
    // 0044a717  81fe0f270000           +cmp esi, 0x270f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9999 /*0x270f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a71d  0f8d2f010000           -jge 0x44a852
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044a852;
    }
    // 0044a723  bf0f270000             -mov edi, 0x270f
    cpu.edi = 9999 /*0x270f*/;
    // 0044a728  668b5918               -mov bx, word ptr [ecx + 0x18]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(24) /* 0x18 */);
L_0x0044a72c:
    // 0044a72c  0fbfd3                 -movsx edx, bx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044a72f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a736  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a738  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a73b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a73d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a740  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a747  0f84fe000000           -je 0x44a84b
    if (cpu.flags.zf)
    {
        goto L_0x0044a84b;
    }
    // 0044a74d  bae04e6000             -mov edx, 0x604ee0
    cpu.edx = 6311648 /*0x604ee0*/;
    // 0044a752  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a754  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0044a757  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a75a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0044a75d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044a75f  e84cf2ffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 0044a764  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a766  7504                   -jne 0x44a76c
    if (!cpu.flags.zf)
    {
        goto L_0x0044a76c;
    }
    // 0044a768  804dfc01               -or byte ptr [ebp - 4], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044a76c:
    // 0044a76c  66f745fc0111           +test word ptr [ebp - 4], 0x1101
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 4353 /*0x1101*/));
    // 0044a772  0f85cd000000           -jne 0x44a845
    if (!cpu.flags.zf)
    {
        goto L_0x0044a845;
    }
    // 0044a778  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0044a77b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a77e  39f0                   +cmp eax, esi
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
    // 0044a780  0f85b5000000           -jne 0x44a83b
    if (!cpu.flags.zf)
    {
        goto L_0x0044a83b;
    }
    // 0044a786  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0044a789  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a78c  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0044a78f  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0044a794  3b45f8                 +cmp eax, dword ptr [ebp - 8]
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
    // 0044a797  0f8ea8000000           -jle 0x44a845
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044a845;
    }
    // 0044a79d  8b421e                 -mov eax, dword ptr [edx + 0x1e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 0044a7a0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a7a3  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0044a7a6  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044a7a9  0345f0                 -add eax, dword ptr [ebp - 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 0044a7ac  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0044a7af  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0044a7b4  3b45f0                 +cmp eax, dword ptr [ebp - 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a7b7  0f8d88000000           -jge 0x44a845
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044a845;
    }
    // 0044a7bd  8b421a                 -mov eax, dword ptr [edx + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(26) /* 0x1a */);
    // 0044a7c0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a7c3  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0044a7c6  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 0044a7cb  3b45f4                 +cmp eax, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a7ce  0f8e71000000           -jle 0x44a845
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044a845;
    }
    // 0044a7d4  8b521c                 -mov edx, dword ptr [edx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0044a7d7  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044a7da  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a7dd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a7df  3b15e4e55500           +cmp edx, dword ptr [0x55e5e4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a7e5  7e5e                   -jle 0x44a845
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044a845;
    }
    // 0044a7e7  0fbff3                 -movsx esi, bx
    cpu.esi = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044a7ea  8b4116                 -mov eax, dword ptr [ecx + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a7ed  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0044a7ef  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a7f2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a7f4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044a7f6  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a7f9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a7fc  39c2                   +cmp edx, eax
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
    // 0044a7fe  7408                   -je 0x44a808
    if (cpu.flags.zf)
    {
        goto L_0x0044a808;
    }
    // 0044a800  66f745fc0110           +test word ptr [ebp - 4], 0x1001
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 4097 /*0x1001*/));
    // 0044a806  7414                   -je 0x44a81c
    if (cpu.flags.zf)
    {
        goto L_0x0044a81c;
    }
L_0x0044a808:
    // 0044a808  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a80b  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044a80e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a811  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a813  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a815  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a816  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a817  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a818  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a819  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a81a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a81b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044a81c:
    // 0044a81c  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0044a821  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a823  e8a8d9fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0044a828  8b4116                 -mov eax, dword ptr [ecx + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a82b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a82e  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a830  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044a832  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a834  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a835  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a836  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a837  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a838  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a839  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a83a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044a83b:
    // 0044a83b  39f8                   +cmp eax, edi
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
    // 0044a83d  7d06                   -jge 0x44a845
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044a845;
    }
    // 0044a83f  39f0                   +cmp eax, esi
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
    // 0044a841  7e02                   -jle 0x44a845
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044a845;
    }
    // 0044a843  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0044a845:
    // 0044a845  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a846  e9e1feffff             -jmp 0x44a72c
    goto L_0x0044a72c;
L_0x0044a84b:
    // 0044a84b  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0044a84d  e9c5feffff             -jmp 0x44a717
    goto L_0x0044a717;
L_0x0044a852:
    // 0044a852  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0044a857:
    // 0044a857  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a859  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a85a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a85b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a85c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a85d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a85e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a85f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_44a860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a861  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a862  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a863  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a865  668b5818               -mov bx, word ptr [eax + 0x18]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(24) /* 0x18 */);
L_0x0044a869:
    // 0044a869  0fbfd3                 -movsx edx, bx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044a86c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a873  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a875  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a878  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a87a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a87d  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a884  7417                   -je 0x44a89d
    if (cpu.flags.zf)
    {
        goto L_0x0044a89d;
    }
    // 0044a886  bae04e6000             -mov edx, 0x604ee0
    cpu.edx = 6311648 /*0x604ee0*/;
    // 0044a88b  01c2                   +add edx, eax
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
    // 0044a88d  740b                   -je 0x44a89a
    if (cpu.flags.zf)
    {
        goto L_0x0044a89a;
    }
    // 0044a88f  837a3400               +cmp dword ptr [edx + 0x34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a893  7405                   -je 0x44a89a
    if (cpu.flags.zf)
    {
        goto L_0x0044a89a;
    }
    // 0044a895  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044a897  ff5234                 -call dword ptr [edx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0044a89a:
    // 0044a89a  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a89b  ebcc                   -jmp 0x44a869
    goto L_0x0044a869;
L_0x0044a89d:
    // 0044a89d  e8eefdffff             -call 0x44a690
    cpu.esp -= 4;
    sub_44a690(app, cpu);
    if (cpu.terminate) return;
    // 0044a8a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a8a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a8a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a8a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_44a8b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a8b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a8b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a8b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a8b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a8b4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a8b6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044a8b8  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044a8bb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044a8bd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
L_0x0044a8c0:
    // 0044a8c0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a8c7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a8c9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a8cc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a8ce  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a8d1  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a8d8  7427                   -je 0x44a901
    if (cpu.flags.zf)
    {
        goto L_0x0044a901;
    }
    // 0044a8da  83b8184f600000         +cmp dword ptr [eax + 0x604f18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311704) /* 0x604f18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a8e1  741b                   -je 0x44a8fe
    if (cpu.flags.zf)
    {
        goto L_0x0044a8fe;
    }
    // 0044a8e3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044a8e5  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044a8ea  ff93184f6000           -call dword ptr [ebx + 0x604f18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6311704) /* 0x604f18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a8f0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044a8f2  83f804                 +cmp eax, 4
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
    // 0044a8f5  7457                   -je 0x44a94e
    if (cpu.flags.zf)
    {
        goto L_0x0044a94e;
    }
    // 0044a8f7  83f803                 +cmp eax, 3
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
    // 0044a8fa  7452                   -je 0x44a94e
    if (cpu.flags.zf)
    {
        goto L_0x0044a94e;
    }
    // 0044a8fc  31c3                   +xor ebx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.eax))));
L_0x0044a8fe:
    // 0044a8fe  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a8ff  ebbf                   -jmp 0x44a8c0
    goto L_0x0044a8c0;
L_0x0044a901:
    // 0044a901  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a906  7434                   -je 0x44a93c
    if (cpu.flags.zf)
    {
        goto L_0x0044a93c;
    }
    // 0044a908  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a90b  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a90e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a911  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a914  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a916  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a91d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a91f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a922  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a924  bae04e6000             -mov edx, 0x604ee0
    cpu.edx = 6311648 /*0x604ee0*/;
    // 0044a929  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a92c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a92e  8b4238                 -mov eax, dword ptr [edx + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 0044a931  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a933  7407                   -je 0x44a93c
    if (cpu.flags.zf)
    {
        goto L_0x0044a93c;
    }
    // 0044a935  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044a937  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a93a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0044a93c:
    // 0044a93c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a93e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a940  e8abf0ffff             -call 0x4499f0
    cpu.esp -= 4;
    sub_4499f0(app, cpu);
    if (cpu.terminate) return;
    // 0044a945  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a947  7505                   -jne 0x44a94e
    if (!cpu.flags.zf)
    {
        goto L_0x0044a94e;
    }
    // 0044a949  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
L_0x0044a94e:
    // 0044a94e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044a950  e88b170500             -call 0x49c0e0
    cpu.esp -= 4;
    sub_49c0e0(app, cpu);
    if (cpu.terminate) return;
    // 0044a955  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a956  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a957  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a958  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a959  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_44a960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a961  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a962  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a963  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a965  668b5818               -mov bx, word ptr [eax + 0x18]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(24) /* 0x18 */);
L_0x0044a969:
    // 0044a969  0fbfd3                 -movsx edx, bx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044a96c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a973  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a975  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a978  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a97a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a97d  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a984  7443                   -je 0x44a9c9
    if (cpu.flags.zf)
    {
        goto L_0x0044a9c9;
    }
    // 0044a986  bae04e6000             -mov edx, 0x604ee0
    cpu.edx = 6311648 /*0x604ee0*/;
    // 0044a98b  01c2                   +add edx, eax
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
    // 0044a98d  7437                   -je 0x44a9c6
    if (cpu.flags.zf)
    {
        goto L_0x0044a9c6;
    }
    // 0044a98f  837a2400               +cmp dword ptr [edx + 0x24], 0
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
    // 0044a993  7431                   -je 0x44a9c6
    if (cpu.flags.zf)
    {
        goto L_0x0044a9c6;
    }
    // 0044a995  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044a997  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a99a  66837a1400             +cmp word ptr [edx + 0x14], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(20) /* 0x14 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a99f  740f                   -je 0x44a9b0
    if (cpu.flags.zf)
    {
        goto L_0x0044a9b0;
    }
    // 0044a9a1  833d6829660000         +cmp dword ptr [0x662968], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a9a8  7506                   -jne 0x44a9b0
    if (!cpu.flags.zf)
    {
        goto L_0x0044a9b0;
    }
    // 0044a9aa  66814a040110           -or word ptr [edx + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x0044a9b0:
    // 0044a9b0  66837a1600             +cmp word ptr [edx + 0x16], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(22) /* 0x16 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a9b5  740f                   -je 0x44a9c6
    if (cpu.flags.zf)
    {
        goto L_0x0044a9c6;
    }
    // 0044a9b7  833d6829660000         +cmp dword ptr [0x662968], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a9be  7406                   -je 0x44a9c6
    if (cpu.flags.zf)
    {
        goto L_0x0044a9c6;
    }
    // 0044a9c0  66814a040110           +or word ptr [edx + 4], 0x1001
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/))));
L_0x0044a9c6:
    // 0044a9c6  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a9c7  eba0                   -jmp 0x44a969
    goto L_0x0044a969;
L_0x0044a9c9:
    // 0044a9c9  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
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
    // 0044a9d0  7405                   -je 0x44a9d7
    if (cpu.flags.zf)
    {
        goto L_0x0044a9d7;
    }
    // 0044a9d2  e8995fffff             -call 0x440970
    cpu.esp -= 4;
    sub_440970(app, cpu);
    if (cpu.terminate) return;
L_0x0044a9d7:
    // 0044a9d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a9d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a9d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a9da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44a9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a9e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a9e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a9e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a9e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a9e5  668b5818               -mov bx, word ptr [eax + 0x18]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(24) /* 0x18 */);
L_0x0044a9e9:
    // 0044a9e9  0fbfd3                 -movsx edx, bx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044a9ec  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a9f3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a9f5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a9f8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a9fa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a9fd  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044aa04  7417                   -je 0x44aa1d
    if (cpu.flags.zf)
    {
        goto L_0x0044aa1d;
    }
    // 0044aa06  bae04e6000             -mov edx, 0x604ee0
    cpu.edx = 6311648 /*0x604ee0*/;
    // 0044aa0b  01c2                   +add edx, eax
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
    // 0044aa0d  740b                   -je 0x44aa1a
    if (cpu.flags.zf)
    {
        goto L_0x0044aa1a;
    }
    // 0044aa0f  837a2800               +cmp dword ptr [edx + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044aa13  7405                   -je 0x44aa1a
    if (cpu.flags.zf)
    {
        goto L_0x0044aa1a;
    }
    // 0044aa15  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044aa17  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0044aa1a:
    // 0044aa1a  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044aa1b  ebcc                   -jmp 0x44a9e9
    goto L_0x0044a9e9;
L_0x0044aa1d:
    // 0044aa1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aa1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aa1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aa20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_44aa30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044aa30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044aa31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044aa32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044aa33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044aa34  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044aa36  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044aa38  8a25583a7a00           -mov ah, byte ptr [0x7a3a58]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */);
    // 0044aa3e  bb19000000             -mov ebx, 0x19
    cpu.ebx = 25 /*0x19*/;
    // 0044aa43  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 0044aa46  7405                   -je 0x44aa4d
    if (cpu.flags.zf)
    {
        goto L_0x0044aa4d;
    }
    // 0044aa48  bb32000000             -mov ebx, 0x32
    cpu.ebx = 50 /*0x32*/;
L_0x0044aa4d:
    // 0044aa4d  83790c00               +cmp dword ptr [ecx + 0xc], 0
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
    // 0044aa51  7405                   -je 0x44aa58
    if (cpu.flags.zf)
    {
        goto L_0x0044aa58;
    }
    // 0044aa53  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044aa55  ff510c                 -call dword ptr [ecx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0044aa58:
    // 0044aa58  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044aa5f  7404                   -je 0x44aa65
    if (cpu.flags.zf)
    {
        goto L_0x0044aa65;
    }
    // 0044aa61  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044aa63  eb5a                   -jmp 0x44aabf
    goto L_0x0044aabf;
L_0x0044aa65:
    // 0044aa65  83fa09                 +cmp edx, 9
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
    // 0044aa68  744b                   -je 0x44aab5
    if (cpu.flags.zf)
    {
        goto L_0x0044aab5;
    }
    // 0044aa6a  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0044aa6f  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0044aa74  e857d7fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0044aa79  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 0044aa80  752b                   -jne 0x44aaad
    if (!cpu.flags.zf)
    {
        goto L_0x0044aaad;
    }
    // 0044aa82  891d609c5500           -mov dword ptr [0x559c60], ebx
    app->getMemory<x86::reg32>(x86::reg32(5610592) /* 0x559c60 */) = cpu.ebx;
L_0x0044aa88:
    // 0044aa88  813d609c5500f4010000   +cmp dword ptr [0x559c60], 0x1f4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5610592) /* 0x559c60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044aa92  7d19                   -jge 0x44aaad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044aaad;
    }
    // 0044aa94  e887e60800             -call 0x4d9120
    cpu.esp -= 4;
    sub_4d9120(app, cpu);
    if (cpu.terminate) return;
    // 0044aa99  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044aa9b  e850faffff             -call 0x44a4f0
    cpu.esp -= 4;
    sub_44a4f0(app, cpu);
    if (cpu.terminate) return;
    // 0044aaa0  e89be60800             -call 0x4d9140
    cpu.esp -= 4;
    sub_4d9140(app, cpu);
    if (cpu.terminate) return;
    // 0044aaa5  011d609c5500           +add dword ptr [0x559c60], ebx
    {
        auto tmp1 = app->getMemory<x86::reg32>(x86::reg32(5610592) /* 0x559c60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044aaab  ebdb                   -jmp 0x44aa88
    goto L_0x0044aa88;
L_0x0044aaad:
    // 0044aaad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044aaaf  891d609c5500           -mov dword ptr [0x559c60], ebx
    app->getMemory<x86::reg32>(x86::reg32(5610592) /* 0x559c60 */) = cpu.ebx;
L_0x0044aab5:
    // 0044aab5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044aab7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044aab9  8935689c5500           -mov dword ptr [0x559c68], esi
    app->getMemory<x86::reg32>(x86::reg32(5610600) /* 0x559c68 */) = cpu.esi;
L_0x0044aabf:
    // 0044aabf  e81cffffff             -call 0x44a9e0
    cpu.esp -= 4;
    sub_44a9e0(app, cpu);
    if (cpu.terminate) return;
    // 0044aac4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aac5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aac6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aac7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aac8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44aad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044aad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044aad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044aad2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044aad3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044aad4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044aad5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044aad7  8b4816                 -mov ecx, dword ptr [eax + 0x16]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044aada  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
L_0x0044aadd:
    // 0044aadd  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044aae4  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044aae6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044aae9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044aaeb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044aaee  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044aaf5  743f                   -je 0x44ab36
    if (cpu.flags.zf)
    {
        goto L_0x0044ab36;
    }
    // 0044aaf7  bbe04e6000             -mov ebx, 0x604ee0
    cpu.ebx = 6311648 /*0x604ee0*/;
    // 0044aafc  01c3                   +add ebx, eax
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
    // 0044aafe  7433                   -je 0x44ab33
    if (cpu.flags.zf)
    {
        goto L_0x0044ab33;
    }
    // 0044ab00  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044ab02:
    // 0044ab02  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044ab09  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044ab0b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044ab0e  8bb0847a5500           -mov esi, dword ptr [eax + 0x557a84]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5601924) /* 0x557a84 */);
    // 0044ab14  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044ab16  741b                   -je 0x44ab33
    if (cpu.flags.zf)
    {
        goto L_0x0044ab33;
    }
    // 0044ab18  3b33                   +cmp esi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044ab1a  7514                   -jne 0x44ab30
    if (!cpu.flags.zf)
    {
        goto L_0x0044ab30;
    }
    // 0044ab1c  8b908c7a5500           -mov edx, dword ptr [eax + 0x557a8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5601932) /* 0x557a8c */);
    // 0044ab22  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044ab24  740d                   -je 0x44ab33
    if (cpu.flags.zf)
    {
        goto L_0x0044ab33;
    }
    // 0044ab26  668b4204               -mov ax, word ptr [edx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0044ab2a  66894304               -mov word ptr [ebx + 4], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0044ab2e  eb03                   -jmp 0x44ab33
    goto L_0x0044ab33;
L_0x0044ab30:
    // 0044ab30  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044ab31  ebcf                   -jmp 0x44ab02
    goto L_0x0044ab02;
L_0x0044ab33:
    // 0044ab33  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044ab34  eba7                   -jmp 0x44aadd
    goto L_0x0044aadd;
L_0x0044ab36:
    // 0044ab36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ab37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ab38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ab39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ab3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ab3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_44ab40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044ab40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044ab41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044ab42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044ab43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044ab44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044ab45  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044ab47  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0044ab4d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044ab4f  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 0044ab55  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044ab57  0f85d5000000           -jne 0x44ac32
    if (!cpu.flags.zf)
    {
        goto L_0x0044ac32;
    }
    // 0044ab5d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044ab5f  e87c150500             -call 0x49c0e0
    cpu.esp -= 4;
    sub_49c0e0(app, cpu);
    if (cpu.terminate) return;
    // 0044ab64  b8c88f5300             -mov eax, 0x538fc8
    cpu.eax = 5476296 /*0x538fc8*/;
    // 0044ab69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ab6b  0f84c1000000           -je 0x44ac32
    if (cpu.flags.zf)
    {
        goto L_0x0044ac32;
    }
    // 0044ab71  e80a040900             -call 0x4daf80
    cpu.esp -= 4;
    sub_4daf80(app, cpu);
    if (cpu.terminate) return;
    // 0044ab76  e8c5150500             -call 0x49c140
    cpu.esp -= 4;
    sub_49c140(app, cpu);
    if (cpu.terminate) return;
    // 0044ab7b  833d2892550000         +cmp dword ptr [0x559228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044ab82  7562                   -jne 0x44abe6
    if (!cpu.flags.zf)
    {
        goto L_0x0044abe6;
    }
    // 0044ab84  68c88f5300             -push 0x538fc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5476296 /*0x538fc8*/;
    cpu.esp -= 4;
    // 0044ab89  68b42d7a00             -push 0x7a2db4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007092 /*0x7a2db4*/;
    cpu.esp -= 4;
    // 0044ab8e  68d08f5300             -push 0x538fd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5476304 /*0x538fd0*/;
    cpu.esp -= 4;
    // 0044ab93  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044ab99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044ab9a  e8f14a0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0044ab9f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0044aba2  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044aba8  e843ab0400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 0044abad  a328925500             -mov dword ptr [0x559228], eax
    app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */) = cpu.eax;
    // 0044abb2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044abb4  7530                   -jne 0x44abe6
    if (!cpu.flags.zf)
    {
        goto L_0x0044abe6;
    }
    // 0044abb6  68c88f5300             -push 0x538fc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5476296 /*0x538fc8*/;
    cpu.esp -= 4;
    // 0044abbb  68b42d7a00             -push 0x7a2db4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007092 /*0x7a2db4*/;
    cpu.esp -= 4;
    // 0044abc0  68dc8f5300             -push 0x538fdc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5476316 /*0x538fdc*/;
    cpu.esp -= 4;
    // 0044abc5  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044abcb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044abcc  e8bf4a0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0044abd1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0044abd4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044abd6  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044abdc  e80fab0400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 0044abe1  a328925500             -mov dword ptr [0x559228], eax
    app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */) = cpu.eax;
L_0x0044abe6:
    // 0044abe6  e8f5b1ffff             -call 0x445de0
    cpu.esp -= 4;
    sub_445de0(app, cpu);
    if (cpu.terminate) return;
    // 0044abeb  e870b10100             -call 0x465d60
    cpu.esp -= 4;
    sub_465d60(app, cpu);
    if (cpu.terminate) return;
    // 0044abf0  bae88f5300             -mov edx, 0x538fe8
    cpu.edx = 5476328 /*0x538fe8*/;
    // 0044abf5  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0044abf8  e813370a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044abfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044abff  7422                   -je 0x44ac23
    if (cpu.flags.zf)
    {
        goto L_0x0044ac23;
    }
    // 0044ac01  baf48f5300             -mov edx, 0x538ff4
    cpu.edx = 5476340 /*0x538ff4*/;
    // 0044ac06  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0044ac09  e802370a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044ac0e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ac10  7411                   -je 0x44ac23
    if (cpu.flags.zf)
    {
        goto L_0x0044ac23;
    }
    // 0044ac12  bafc8f5300             -mov edx, 0x538ffc
    cpu.edx = 5476348 /*0x538ffc*/;
    // 0044ac17  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0044ac1a  e8f1360a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044ac1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ac21  750a                   -jne 0x44ac2d
    if (!cpu.flags.zf)
    {
        goto L_0x0044ac2d;
    }
L_0x0044ac23:
    // 0044ac23  a128925500             -mov eax, dword ptr [0x559228]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */);
    // 0044ac28  e853b10100             -call 0x465d80
    cpu.esp -= 4;
    sub_465d80(app, cpu);
    if (cpu.terminate) return;
L_0x0044ac2d:
    // 0044ac2d  e86e9f0500             -call 0x4a4ba0
    cpu.esp -= 4;
    sub_4a4ba0(app, cpu);
    if (cpu.terminate) return;
L_0x0044ac32:
    // 0044ac32  66c7411a6400           -mov word ptr [ecx + 0x1a], 0x64
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = 100 /*0x64*/;
    // 0044ac38  668b411a               -mov ax, word ptr [ecx + 0x1a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 0044ac3c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044ac3e  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 0044ac42  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044ac44  89352c925500           -mov dword ptr [0x55922c], esi
    app->getMemory<x86::reg32>(x86::reg32(5607980) /* 0x55922c */) = cpu.esi;
    // 0044ac4a  e881feffff             -call 0x44aad0
    cpu.esp -= 4;
    sub_44aad0(app, cpu);
    if (cpu.terminate) return;
    // 0044ac4f  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0044ac52  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044ac54  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044ac56  7407                   -je 0x44ac5f
    if (cpu.flags.zf)
    {
        goto L_0x0044ac5f;
    }
    // 0044ac58  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044ac5a  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044ac5d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0044ac5f:
    // 0044ac5f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044ac61  e8fafcffff             -call 0x44a960
    cpu.esp -= 4;
    sub_44a960(app, cpu);
    if (cpu.terminate) return;
    // 0044ac66  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044ac68  e8f3fbffff             -call 0x44a860
    cpu.esp -= 4;
    sub_44a860(app, cpu);
    if (cpu.terminate) return;
    // 0044ac6d  e8de590a00             -call 0x4f0650
    cpu.esp -= 4;
    sub_4f0650(app, cpu);
    if (cpu.terminate) return;
    // 0044ac72  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044ac74  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044ac76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ac77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ac78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ac79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ac7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ac7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_44ac90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0044ac90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044ac91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044ac92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044ac93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044ac94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044ac95  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044ac97  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044ac99  ba04905300             -mov edx, 0x539004
    cpu.edx = 5476356 /*0x539004*/;
    // 0044ac9e  e87d5b0900             -call 0x4e0820
    cpu.esp -= 4;
    sub_4e0820(app, cpu);
    if (cpu.terminate) return;
    // 0044aca3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044aca5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044aca7  7450                   -je 0x44acf9
    if (cpu.flags.zf)
    {
        goto L_0x0044acf9;
    }
    // 0044aca9  8b154cbb6f00           -mov edx, dword ptr [0x6fbb4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 0044acaf  4a                     -dec edx
    (cpu.edx)--;
    // 0044acb0  83fa04                 +cmp edx, 4
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
    // 0044acb3  7744                   -ja 0x44acf9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0044acf9;
    }
    // 0044acb5  ff24957cac4400         -jmp dword ptr [edx*4 + 0x44ac7c]
    cpu.ip = app->getMemory<x86::reg32>(4500604 + cpu.edx * 4); goto dynamic_jump;
  case 0x0044acbc:
    // 0044acbc  be0c905300             -mov esi, 0x53900c
    cpu.esi = 5476364 /*0x53900c*/;
    // 0044acc1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044acc3  eb1a                   -jmp 0x44acdf
    goto L_0x0044acdf;
  case 0x0044acc5:
    // 0044acc5  be18905300             -mov esi, 0x539018
    cpu.esi = 5476376 /*0x539018*/;
    // 0044acca  eb13                   -jmp 0x44acdf
    goto L_0x0044acdf;
  case 0x0044accc:
    // 0044accc  be24905300             -mov esi, 0x539024
    cpu.esi = 5476388 /*0x539024*/;
    // 0044acd1  eb0c                   -jmp 0x44acdf
    goto L_0x0044acdf;
  case 0x0044acd3:
    // 0044acd3  be30905300             -mov esi, 0x539030
    cpu.esi = 5476400 /*0x539030*/;
    // 0044acd8  eb05                   -jmp 0x44acdf
    goto L_0x0044acdf;
  case 0x0044acda:
    // 0044acda  be3c905300             -mov esi, 0x53903c
    cpu.esi = 5476412 /*0x53903c*/;
L_0x0044acdf:
    // 0044acdf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044ace0:
    // 0044ace0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044ace2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044ace4  3c00                   +cmp al, 0
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
    // 0044ace6  7410                   -je 0x44acf8
    if (cpu.flags.zf)
    {
        goto L_0x0044acf8;
    }
    // 0044ace8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044aceb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044acee  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044acf1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044acf4  3c00                   +cmp al, 0
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
    // 0044acf6  75e8                   -jne 0x44ace0
    if (!cpu.flags.zf)
    {
        goto L_0x0044ace0;
    }
L_0x0044acf8:
    // 0044acf8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0044acf9:
    // 0044acf9  833d2c92550000         +cmp dword ptr [0x55922c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607980) /* 0x55922c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044ad00  741a                   -je 0x44ad1c
    if (cpu.flags.zf)
    {
        goto L_0x0044ad1c;
    }
    // 0044ad02  ba50286600             -mov edx, 0x662850
    cpu.edx = 6694992 /*0x662850*/;
    // 0044ad07  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044ad09  e802360a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044ad0e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ad10  743c                   -je 0x44ad4e
    if (cpu.flags.zf)
    {
        goto L_0x0044ad4e;
    }
    // 0044ad12  a12c925500             -mov eax, dword ptr [0x55922c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607980) /* 0x55922c */);
    // 0044ad17  e8746b0900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0044ad1c:
    // 0044ad1c  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0044ad21  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044ad23  bf50286600             -mov edi, 0x662850
    cpu.edi = 6694992 /*0x662850*/;
    // 0044ad28  e8c3a90400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 0044ad2d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0044ad2f  a32c925500             -mov dword ptr [0x55922c], eax
    app->getMemory<x86::reg32>(x86::reg32(5607980) /* 0x55922c */) = cpu.eax;
    // 0044ad34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044ad35:
    // 0044ad35  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044ad37  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044ad39  3c00                   +cmp al, 0
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
    // 0044ad3b  7410                   -je 0x44ad4d
    if (cpu.flags.zf)
    {
        goto L_0x0044ad4d;
    }
    // 0044ad3d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044ad40  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044ad43  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044ad46  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044ad49  3c00                   +cmp al, 0
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
    // 0044ad4b  75e8                   -jne 0x44ad35
    if (!cpu.flags.zf)
    {
        goto L_0x0044ad35;
    }
L_0x0044ad4d:
    // 0044ad4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0044ad4e:
    // 0044ad4e  a12c925500             -mov eax, dword ptr [0x55922c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607980) /* 0x55922c */);
    // 0044ad53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ad54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ad55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ad56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ad57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ad58  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44ad60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044ad60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044ad61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044ad62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044ad63  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044ad65  8b1500286600           -mov edx, dword ptr [0x662800]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6694912) /* 0x662800 */);
    // 0044ad6b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044ad6d  7436                   -je 0x44ada5
    if (cpu.flags.zf)
    {
        goto L_0x0044ada5;
    }
    // 0044ad6f  8b5216                 -mov edx, dword ptr [edx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(22) /* 0x16 */);
    // 0044ad72  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
L_0x0044ad75:
    // 0044ad75  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044ad7c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044ad7e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044ad81  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044ad83  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044ad86  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044ad8d  7416                   -je 0x44ada5
    if (cpu.flags.zf)
    {
        goto L_0x0044ada5;
    }
    // 0044ad8f  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044ad94  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0044ad96  83fb02                 +cmp ebx, 2
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
    // 0044ad99  7507                   -jne 0x44ada2
    if (!cpu.flags.zf)
    {
        goto L_0x0044ada2;
    }
    // 0044ad9b  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 0044ad9e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ad9f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ada0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ada1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044ada2:
    // 0044ada2  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044ada3  ebd0                   -jmp 0x44ad75
    goto L_0x0044ad75;
L_0x0044ada5:
    // 0044ada5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044ada7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ada8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ada9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044adaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44adb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044adb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044adb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044adb2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044adb3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044adb5  833d0028660000         +cmp dword ptr [0x662800], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6694912) /* 0x662800 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044adbc  743b                   -je 0x44adf9
    if (cpu.flags.zf)
    {
        goto L_0x0044adf9;
    }
    // 0044adbe  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044adc3  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044adc6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
L_0x0044adc9:
    // 0044adc9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044add0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044add2  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044add5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044add7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044adda  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044ade1  7416                   -je 0x44adf9
    if (cpu.flags.zf)
    {
        goto L_0x0044adf9;
    }
    // 0044ade3  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044ade8  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0044adea  83fb02                 +cmp ebx, 2
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
    // 0044aded  7507                   -jne 0x44adf6
    if (!cpu.flags.zf)
    {
        goto L_0x0044adf6;
    }
    // 0044adef  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 0044adf2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044adf3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044adf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044adf5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044adf6:
    // 0044adf6  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044adf7  ebd0                   -jmp 0x44adc9
    goto L_0x0044adc9;
L_0x0044adf9:
    // 0044adf9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044adfb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044adfc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044adfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044adfe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_44ae00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044ae00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044ae01  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044ae02  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044ae04  8b1530925500           -mov edx, dword ptr [0x559230]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044ae0a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044ae0c  7406                   -je 0x44ae14
    if (cpu.flags.zf)
    {
        goto L_0x0044ae14;
    }
    // 0044ae0e  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0044ae11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ae12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ae13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044ae14:
    // 0044ae14  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044ae16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ae17  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ae18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44ae20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044ae20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044ae21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044ae22  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044ae24  8b1530925500           -mov edx, dword ptr [0x559230]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044ae2a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044ae2c  7505                   -jne 0x44ae33
    if (!cpu.flags.zf)
    {
        goto L_0x0044ae33;
    }
    // 0044ae2e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044ae30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ae31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ae32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044ae33:
    // 0044ae33  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044ae35  8b5216                 -mov edx, dword ptr [edx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(22) /* 0x16 */);
    // 0044ae38  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044ae3b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044ae3e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044ae41  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044ae43  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044ae4a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044ae4c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044ae4f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044ae51  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044ae54  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044ae59  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0044ae5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ae5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ae5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_44ae60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044ae60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044ae61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044ae62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044ae63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044ae64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044ae65  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044ae67  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044ae69  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0044ae6b:
    // 0044ae6b  3b0db00b6600           +cmp ecx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044ae71  7d29                   -jge 0x44ae9c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044ae9c;
    }
    // 0044ae73  8d34cd00000000         -lea esi, [ecx*8]
    cpu.esi = x86::reg32(cpu.ecx * 8);
    // 0044ae7a  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044ae7c  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0044ae7f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044ae81  8b96e4406000           -mov edx, dword ptr [esi + 0x6040e4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6308068) /* 0x6040e4 */);
    // 0044ae87  e884340a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044ae8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ae8e  7509                   -jne 0x44ae99
    if (!cpu.flags.zf)
    {
        goto L_0x0044ae99;
    }
    // 0044ae90  b8d0406000             -mov eax, 0x6040d0
    cpu.eax = 6308048 /*0x6040d0*/;
    // 0044ae95  01f0                   +add eax, esi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044ae97  eb05                   -jmp 0x44ae9e
    goto L_0x0044ae9e;
L_0x0044ae99:
    // 0044ae99  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044ae9a  ebcf                   -jmp 0x44ae6b
    goto L_0x0044ae6b;
L_0x0044ae9c:
    // 0044ae9c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044ae9e:
    // 0044ae9e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ae9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aea0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aea1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aea2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aea3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_44aeb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044aeb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044aeb1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044aeb3  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044aeb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aeb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_44aec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044aec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044aec1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044aec2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044aec3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044aec5  8b0d00286600           -mov ecx, dword ptr [0x662800]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6694912) /* 0x662800 */);
    // 0044aecb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044aecd  40                     -inc eax
    (cpu.eax)++;
    // 0044aece  8b1c8500286600         -mov ebx, dword ptr [eax*4 + 0x662800]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6694912) /* 0x662800 */ + cpu.eax * 4);
    // 0044aed5  891c85fc276600         -mov dword ptr [eax*4 + 0x6627fc], ebx
    app->getMemory<x86::reg32>(x86::reg32(6694908) /* 0x6627fc */ + cpu.eax * 4) = cpu.ebx;
L_0x0044aedc:
    // 0044aedc  83f813                 +cmp eax, 0x13
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
    // 0044aedf  7d11                   -jge 0x44aef2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044aef2;
    }
    // 0044aee1  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044aee2  8b1c8500286600         -mov ebx, dword ptr [eax*4 + 0x662800]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6694912) /* 0x662800 */ + cpu.eax * 4);
    // 0044aee9  891c85fc276600         -mov dword ptr [eax*4 + 0x6627fc], ebx
    app->getMemory<x86::reg32>(x86::reg32(6694908) /* 0x6627fc */ + cpu.eax * 4) = cpu.ebx;
    // 0044aef0  ebea                   -jmp 0x44aedc
    goto L_0x0044aedc;
L_0x0044aef2:
    // 0044aef2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044aef4  7505                   -jne 0x44aefb
    if (!cpu.flags.zf)
    {
        goto L_0x0044aefb;
    }
    // 0044aef6  b9d0406000             -mov ecx, 0x6040d0
    cpu.ecx = 6308048 /*0x6040d0*/;
L_0x0044aefb:
    // 0044aefb  890d30925500           -mov dword ptr [0x559230], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */) = cpu.ecx;
    // 0044af01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044af02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044af03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044af04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_44af10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044af10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044af11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044af12  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044af14  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 0044af19  48                     -dec eax
    (cpu.eax)--;
    // 0044af1a  8b0c8504286600         -mov ecx, dword ptr [eax*4 + 0x662804]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6694916) /* 0x662804 */ + cpu.eax * 4);
    // 0044af21  890c8508286600         -mov dword ptr [eax*4 + 0x662808], ecx
    app->getMemory<x86::reg32>(x86::reg32(6694920) /* 0x662808 */ + cpu.eax * 4) = cpu.ecx;
L_0x0044af28:
    // 0044af28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044af2a  7c11                   -jl 0x44af3d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044af3d;
    }
    // 0044af2c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044af2d  8b0c8504286600         -mov ecx, dword ptr [eax*4 + 0x662804]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6694916) /* 0x662804 */ + cpu.eax * 4);
    // 0044af34  890c8508286600         -mov dword ptr [eax*4 + 0x662808], ecx
    app->getMemory<x86::reg32>(x86::reg32(6694920) /* 0x662808 */ + cpu.eax * 4) = cpu.ecx;
    // 0044af3b  ebeb                   -jmp 0x44af28
    goto L_0x0044af28;
L_0x0044af3d:
    // 0044af3d  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044af42  a300286600             -mov dword ptr [0x662800], eax
    app->getMemory<x86::reg32>(x86::reg32(6694912) /* 0x662800 */) = cpu.eax;
    // 0044af47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044af48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044af49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_44af50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044af50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044af51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044af52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044af53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044af54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044af55  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044af57  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044af59  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044af5b:
    // 0044af5b  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 0044af62  8d0419                 -lea eax, [ecx + ebx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebx * 1);
    // 0044af65  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0044af67  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044af69  7414                   -je 0x44af7f
    if (cpu.flags.zf)
    {
        goto L_0x0044af7f;
    }
    // 0044af6b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044af6d  e8eefeffff             -call 0x44ae60
    cpu.esp -= 4;
    sub_44ae60(app, cpu);
    if (cpu.terminate) return;
    // 0044af72  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044af74  7406                   -je 0x44af7c
    if (cpu.flags.zf)
    {
        goto L_0x0044af7c;
    }
    // 0044af76  898300286600           -mov dword ptr [ebx + 0x662800], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6694912) /* 0x662800 */) = cpu.eax;
L_0x0044af7c:
    // 0044af7c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044af7d  ebdc                   -jmp 0x44af5b
    goto L_0x0044af5b;
L_0x0044af7f:
    // 0044af7f  e83cffffff             -call 0x44aec0
    cpu.esp -= 4;
    sub_44aec0(app, cpu);
    if (cpu.terminate) return;
    // 0044af84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044af85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044af86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044af87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044af88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044af89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_44af90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044af90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044af91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044af92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044af93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044af94  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044af96  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0044af99  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044af9b  83f801                 +cmp eax, 1
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
    // 0044af9e  0f8572000000           -jne 0x44b016
    if (!cpu.flags.zf)
    {
        goto L_0x0044b016;
    }
    // 0044afa4  e81797ffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0044afa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044afab  7409                   -je 0x44afb6
    if (cpu.flags.zf)
    {
        goto L_0x0044afb6;
    }
    // 0044afad  833d5846660000         +cmp dword ptr [0x664658], 0
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
    // 0044afb4  7549                   -jne 0x44afff
    if (!cpu.flags.zf)
    {
        goto L_0x0044afff;
    }
L_0x0044afb6:
    // 0044afb6  e8559cffff             -call 0x444c10
    cpu.esp -= 4;
    sub_444c10(app, cpu);
    if (cpu.terminate) return;
    // 0044afbb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044afbd  e82e720200             -call 0x4721f0
    cpu.esp -= 4;
    sub_4721f0(app, cpu);
    if (cpu.terminate) return;
    // 0044afc2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044afc4  7407                   -je 0x44afcd
    if (cpu.flags.zf)
    {
        goto L_0x0044afcd;
    }
    // 0044afc6  bffcd26f00             -mov edi, 0x6fd2fc
    cpu.edi = 7328508 /*0x6fd2fc*/;
    // 0044afcb  eb11                   -jmp 0x44afde
    goto L_0x0044afde;
L_0x0044afcd:
    // 0044afcd  b8fa000000             -mov eax, 0xfa
    cpu.eax = 250 /*0xfa*/;
    // 0044afd2  bffcd26f00             -mov edi, 0x6fd2fc
    cpu.edi = 7328508 /*0x6fd2fc*/;
    // 0044afd7  e874680800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044afdc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0044afde:
    // 0044afde  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044afdf:
    // 0044afdf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044afe1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044afe3  3c00                   +cmp al, 0
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
    // 0044afe5  7410                   -je 0x44aff7
    if (cpu.flags.zf)
    {
        goto L_0x0044aff7;
    }
    // 0044afe7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044afea  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044afed  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044aff0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044aff3  3c00                   +cmp al, 0
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
    // 0044aff5  75e8                   -jne 0x44afdf
    if (!cpu.flags.zf)
    {
        goto L_0x0044afdf;
    }
L_0x0044aff7:
    // 0044aff7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044aff8  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
    // 0044affd  eb12                   -jmp 0x44b011
    goto L_0x0044b011;
L_0x0044afff:
    // 0044afff  83f801                 +cmp eax, 1
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
    // 0044b002  7527                   -jne 0x44b02b
    if (!cpu.flags.zf)
    {
        goto L_0x0044b02b;
    }
    // 0044b004  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 0044b006  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0044b00b  8825fcd26f00           -mov byte ptr [0x6fd2fc], ah
    app->getMemory<x86::reg8>(x86::reg32(7328508) /* 0x6fd2fc */) = cpu.ah;
L_0x0044b011:
    // 0044b011  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0044b014  eb15                   -jmp 0x44b02b
    goto L_0x0044b02b;
L_0x0044b016:
    // 0044b016  83f803                 +cmp eax, 3
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
    // 0044b019  7510                   -jne 0x44b02b
    if (!cpu.flags.zf)
    {
        goto L_0x0044b02b;
    }
    // 0044b01b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0044b01d  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0044b022  881dfcd26f00           -mov byte ptr [0x6fd2fc], bl
    app->getMemory<x86::reg8>(x86::reg32(7328508) /* 0x6fd2fc */) = cpu.bl;
    // 0044b028  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0044b02b:
    // 0044b02b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044b02d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b02e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b02f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b030  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b031  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_44b040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044b040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044b041  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044b042  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044b043  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044b044  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044b046  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0044b049  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044b04b  83f801                 +cmp eax, 1
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
    // 0044b04e  0f8572000000           -jne 0x44b0c6
    if (!cpu.flags.zf)
    {
        goto L_0x0044b0c6;
    }
    // 0044b054  e86796ffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0044b059  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044b05b  7409                   -je 0x44b066
    if (cpu.flags.zf)
    {
        goto L_0x0044b066;
    }
    // 0044b05d  833d5846660000         +cmp dword ptr [0x664658], 0
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
    // 0044b064  7549                   -jne 0x44b0af
    if (!cpu.flags.zf)
    {
        goto L_0x0044b0af;
    }
L_0x0044b066:
    // 0044b066  e8a59bffff             -call 0x444c10
    cpu.esp -= 4;
    sub_444c10(app, cpu);
    if (cpu.terminate) return;
    // 0044b06b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044b06d  e87e710200             -call 0x4721f0
    cpu.esp -= 4;
    sub_4721f0(app, cpu);
    if (cpu.terminate) return;
    // 0044b072  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044b074  7407                   -je 0x44b07d
    if (cpu.flags.zf)
    {
        goto L_0x0044b07d;
    }
    // 0044b076  bf68d36f00             -mov edi, 0x6fd368
    cpu.edi = 7328616 /*0x6fd368*/;
    // 0044b07b  eb11                   -jmp 0x44b08e
    goto L_0x0044b08e;
L_0x0044b07d:
    // 0044b07d  b8fb000000             -mov eax, 0xfb
    cpu.eax = 251 /*0xfb*/;
    // 0044b082  bf68d36f00             -mov edi, 0x6fd368
    cpu.edi = 7328616 /*0x6fd368*/;
    // 0044b087  e8c4670800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b08c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0044b08e:
    // 0044b08e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044b08f:
    // 0044b08f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044b091  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044b093  3c00                   +cmp al, 0
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
    // 0044b095  7410                   -je 0x44b0a7
    if (cpu.flags.zf)
    {
        goto L_0x0044b0a7;
    }
    // 0044b097  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044b09a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044b09d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044b0a0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044b0a3  3c00                   +cmp al, 0
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
    // 0044b0a5  75e8                   -jne 0x44b08f
    if (!cpu.flags.zf)
    {
        goto L_0x0044b08f;
    }
L_0x0044b0a7:
    // 0044b0a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b0a8  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
    // 0044b0ad  eb12                   -jmp 0x44b0c1
    goto L_0x0044b0c1;
L_0x0044b0af:
    // 0044b0af  83f801                 +cmp eax, 1
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
    // 0044b0b2  7527                   -jne 0x44b0db
    if (!cpu.flags.zf)
    {
        goto L_0x0044b0db;
    }
    // 0044b0b4  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 0044b0b6  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0044b0bb  882568d36f00           -mov byte ptr [0x6fd368], ah
    app->getMemory<x86::reg8>(x86::reg32(7328616) /* 0x6fd368 */) = cpu.ah;
L_0x0044b0c1:
    // 0044b0c1  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0044b0c4  eb15                   -jmp 0x44b0db
    goto L_0x0044b0db;
L_0x0044b0c6:
    // 0044b0c6  83f803                 +cmp eax, 3
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
    // 0044b0c9  7510                   -jne 0x44b0db
    if (!cpu.flags.zf)
    {
        goto L_0x0044b0db;
    }
    // 0044b0cb  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0044b0cd  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0044b0d2  881d68d36f00           -mov byte ptr [0x6fd368], bl
    app->getMemory<x86::reg8>(x86::reg32(7328616) /* 0x6fd368 */) = cpu.bl;
    // 0044b0d8  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0044b0db:
    // 0044b0db  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044b0dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b0de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b0df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b0e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b0e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_44b0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044b0f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044b0f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044b0f2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044b0f4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044b0f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044b0f8  83f901                 +cmp ecx, 1
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
    // 0044b0fb  0f8260000000           -jb 0x44b161
    if (cpu.flags.cf)
    {
        goto L_0x0044b161;
    }
    // 0044b101  7608                   -jbe 0x44b10b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044b10b;
    }
    // 0044b103  83f903                 +cmp ecx, 3
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
    // 0044b106  744d                   -je 0x44b155
    if (cpu.flags.zf)
    {
        goto L_0x0044b155;
    }
    // 0044b108  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b109  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b10a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044b10b:
    // 0044b10b  e8b095ffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0044b110  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044b112  7516                   -jne 0x44b12a
    if (!cpu.flags.zf)
    {
        goto L_0x0044b12a;
    }
    // 0044b114  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044b116  7403                   -je 0x44b11b
    if (cpu.flags.zf)
    {
        goto L_0x0044b11b;
    }
    // 0044b118  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0044b11b:
    // 0044b11b  c6055192550001         -mov byte ptr [0x559251], 1
    app->getMemory<x86::reg8>(x86::reg32(5608017) /* 0x559251 */) = 1 /*0x1*/;
    // 0044b122  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0044b127  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b128  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b129  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044b12a:
    // 0044b12a  83f801                 +cmp eax, 1
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
    // 0044b12d  7517                   -jne 0x44b146
    if (!cpu.flags.zf)
    {
        goto L_0x0044b146;
    }
    // 0044b12f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044b131  7403                   -je 0x44b136
    if (cpu.flags.zf)
    {
        goto L_0x0044b136;
    }
    // 0044b133  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0044b136:
    // 0044b136  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0044b138  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044b13d  881551925500           -mov byte ptr [0x559251], dl
    app->getMemory<x86::reg8>(x86::reg32(5608017) /* 0x559251 */) = cpu.dl;
    // 0044b143  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b144  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b145  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044b146:
    // 0044b146  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044b148  7403                   -je 0x44b14d
    if (cpu.flags.zf)
    {
        goto L_0x0044b14d;
    }
    // 0044b14a  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x0044b14d:
    // 0044b14d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044b152  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b153  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b154  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044b155:
    // 0044b155  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044b157  7403                   -je 0x44b15c
    if (cpu.flags.zf)
    {
        goto L_0x0044b15c;
    }
    // 0044b159  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0044b15c:
    // 0044b15c  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0044b161:
    // 0044b161  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b162  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b163  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_44b170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044b170  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044b171  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044b173  e8a8df0800             -call 0x4d9120
    cpu.esp -= 4;
    sub_4d9120(app, cpu);
    if (cpu.terminate) return;
    // 0044b178  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b17d  e86ef3ffff             -call 0x44a4f0
    cpu.esp -= 4;
    sub_44a4f0(app, cpu);
    if (cpu.terminate) return;
    // 0044b182  e82987ffff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 0044b187  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0044b189  7405                   -je 0x44b190
    if (cpu.flags.zf)
    {
        goto L_0x0044b190;
    }
    // 0044b18b  e8c0adffff             -call 0x445f50
    cpu.esp -= 4;
    sub_445f50(app, cpu);
    if (cpu.terminate) return;
L_0x0044b190:
    // 0044b190  e8abdf0800             -call 0x4d9140
    cpu.esp -= 4;
    sub_4d9140(app, cpu);
    if (cpu.terminate) return;
    // 0044b195  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b196  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_44b1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044b1a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044b1a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044b1a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044b1a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044b1a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044b1a6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044b1a8  833d4494550000         +cmp dword ptr [0x559444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608516) /* 0x559444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b1af  7507                   -jne 0x44b1b8
    if (!cpu.flags.zf)
    {
        goto L_0x0044b1b8;
    }
    // 0044b1b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044b1b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b1b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b1b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b1b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b1b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044b1b8:
    // 0044b1b8  c7020d000000           -mov dword ptr [edx], 0xd
    app->getMemory<x86::reg32>(cpu.edx) = 13 /*0xd*/;
L_0x0044b1be:
    // 0044b1be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044b1c0  e84b550a00             -call 0x4f0710
    cpu.esp -= 4;
    sub_4f0710(app, cpu);
    if (cpu.terminate) return;
    // 0044b1c5  e896e60700             -call 0x4c9860
    cpu.esp -= 4;
    sub_4c9860(app, cpu);
    if (cpu.terminate) return;
    // 0044b1ca  8b3544945500           -mov esi, dword ptr [0x559444]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5608516) /* 0x559444 */);
    // 0044b1d0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044b1d2  75ea                   -jne 0x44b1be
    if (!cpu.flags.zf)
    {
        goto L_0x0044b1be;
    }
    // 0044b1d4  ff1518f99e00           -call dword ptr [0x9ef918]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418456) /* 0x9ef918 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044b1da  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044b1df  8935c0fe5500           -mov dword ptr [0x55fec0], esi
    app->getMemory<x86::reg32>(x86::reg32(5635776) /* 0x55fec0 */) = cpu.esi;
    // 0044b1e5  e8c63c0700             -call 0x4beeb0
    cpu.esp -= 4;
    sub_4beeb0(app, cpu);
    if (cpu.terminate) return;
    // 0044b1ea  837b0c00               +cmp dword ptr [ebx + 0xc], 0
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
    // 0044b1ee  7405                   -je 0x44b1f5
    if (cpu.flags.zf)
    {
        goto L_0x0044b1f5;
    }
    // 0044b1f0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044b1f2  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0044b1f5:
    // 0044b1f5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044b1f7  e8e4f7ffff             -call 0x44a9e0
    cpu.esp -= 4;
    sub_44a9e0(app, cpu);
    if (cpu.terminate) return;
    // 0044b1fc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044b201  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b202  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b203  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b204  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b205  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_44b230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0044b230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044b231  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044b232  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044b233  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044b234  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044b235  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044b237  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0044b23a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044b23c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0044b23e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044b243  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044b245  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0044b248  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 0044b24b  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0044b24e  ba48905300             -mov edx, 0x539048
    cpu.edx = 5476424 /*0x539048*/;
    // 0044b253  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0044b256  e8b5300a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044b25b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044b25d  750c                   -jne 0x44b26b
    if (!cpu.flags.zf)
    {
        goto L_0x0044b26b;
    }
    // 0044b25f  c7056829660001000000   -mov dword ptr [0x662968], 1
    app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */) = 1 /*0x1*/;
    // 0044b269  eb06                   -jmp 0x44b271
    goto L_0x0044b271;
L_0x0044b26b:
    // 0044b26b  891d68296600           -mov dword ptr [0x662968], ebx
    app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */) = cpu.ebx;
L_0x0044b271:
    // 0044b271  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0044b273  a14cbb6f00             -mov eax, dword ptr [0x6fbb4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 0044b278  893d34925500           -mov dword ptr [0x559234], edi
    app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */) = cpu.edi;
    // 0044b27e  893d10eb5500           -mov dword ptr [0x55eb10], edi
    app->getMemory<x86::reg32>(x86::reg32(5630736) /* 0x55eb10 */) = cpu.edi;
    // 0044b284  893d28925500           -mov dword ptr [0x559228], edi
    app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */) = cpu.edi;
    // 0044b28a  e8c1640800             -call 0x4d1750
    cpu.esp -= 4;
    sub_4d1750(app, cpu);
    if (cpu.terminate) return;
    // 0044b28f  e88c680000             -call 0x451b20
    cpu.esp -= 4;
    sub_451b20(app, cpu);
    if (cpu.terminate) return;
    // 0044b294  8b1d68296600           -mov ebx, dword ptr [0x662968]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
    // 0044b29a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044b29c  7412                   -je 0x44b2b0
    if (cpu.flags.zf)
    {
        goto L_0x0044b2b0;
    }
    // 0044b29e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0044b2a3  8b15e8bb6f00           -mov edx, dword ptr [0x6fbbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */);
    // 0044b2a9  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0044b2ae  eb0b                   -jmp 0x44b2bb
    goto L_0x0044b2bb;
L_0x0044b2b0:
    // 0044b2b0  b816000000             -mov eax, 0x16
    cpu.eax = 22 /*0x16*/;
    // 0044b2b5  8b15e8bb6f00           -mov edx, dword ptr [0x6fbbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */);
L_0x0044b2bb:
    // 0044b2bb  e83052fcff             -call 0x4104f0
    cpu.esp -= 4;
    sub_4104f0(app, cpu);
    if (cpu.terminate) return;
    // 0044b2c0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044b2c5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044b2c7  bf05000000             -mov edi, 5
    cpu.edi = 5 /*0x5*/;
    // 0044b2cc  e83fe2ffff             -call 0x449510
    cpu.esp -= 4;
    sub_449510(app, cpu);
    if (cpu.terminate) return;
    // 0044b2d1  893d6c296600           -mov dword ptr [0x66296c], edi
    app->getMemory<x86::reg32>(x86::reg32(6695276) /* 0x66296c */) = cpu.edi;
    // 0044b2d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044b2d9  40                     -inc eax
    (cpu.eax)++;
    // 0044b2da  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044b2dc  891485fc276600         -mov dword ptr [eax*4 + 0x6627fc], edx
    app->getMemory<x86::reg32>(x86::reg32(6694908) /* 0x6627fc */ + cpu.eax * 4) = cpu.edx;
L_0x0044b2e3:
    // 0044b2e3  83f814                 +cmp eax, 0x14
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
    // 0044b2e6  7d0c                   -jge 0x44b2f4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044b2f4;
    }
    // 0044b2e8  40                     -inc eax
    (cpu.eax)++;
    // 0044b2e9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044b2eb  891485fc276600         -mov dword ptr [eax*4 + 0x6627fc], edx
    app->getMemory<x86::reg32>(x86::reg32(6694908) /* 0x6627fc */ + cpu.eax * 4) = cpu.edx;
    // 0044b2f2  ebef                   -jmp 0x44b2e3
    goto L_0x0044b2e3;
L_0x0044b2f4:
    // 0044b2f4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044b2f6  7409                   -je 0x44b301
    if (cpu.flags.zf)
    {
        goto L_0x0044b301;
    }
    // 0044b2f8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044b2fa  e851fcffff             -call 0x44af50
    cpu.esp -= 4;
    sub_44af50(app, cpu);
    if (cpu.terminate) return;
    // 0044b2ff  eb0a                   -jmp 0x44b30b
    goto L_0x0044b30b;
L_0x0044b301:
    // 0044b301  c70530925500d0406000   -mov dword ptr [0x559230], 0x6040d0
    app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */) = 6308048 /*0x6040d0*/;
L_0x0044b30b:
    // 0044b30b  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044b30e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044b310  0f84f5050000           -je 0x44b90b
    if (cpu.flags.zf)
    {
        goto L_0x0044b90b;
    }
    // 0044b316  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b31b  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044b31e  e81df8ffff             -call 0x44ab40
    cpu.esp -= 4;
    sub_44ab40(app, cpu);
    if (cpu.terminate) return;
    // 0044b323  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0044b326  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044b328  740f                   -je 0x44b339
    if (cpu.flags.zf)
    {
        goto L_0x0044b339;
    }
    // 0044b32a  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b32f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0044b331  e88aedffff             -call 0x44a0c0
    cpu.esp -= 4;
    sub_44a0c0(app, cpu);
    if (cpu.terminate) return;
    // 0044b336  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
L_0x0044b339:
    // 0044b339  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b33d  7407                   -je 0x44b346
    if (cpu.flags.zf)
    {
        goto L_0x0044b346;
    }
    // 0044b33f  c745f003000000         -mov dword ptr [ebp - 0x10], 3
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 3 /*0x3*/;
L_0x0044b346:
    // 0044b346  e8d168feff             -call 0x431c1c
    cpu.esp -= 4;
    sub_431c1c(app, cpu);
    if (cpu.terminate) return;
    // 0044b34b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0044b350  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0044b355  890d30768b00           -mov dword ptr [0x8b7630], ecx
    app->getMemory<x86::reg32>(x86::reg32(9139760) /* 0x8b7630 */) = cpu.ecx;
    // 0044b35b  e870cefcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x0044b360:
    // 0044b360  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b364  0f8519030000           -jne 0x44b683
    if (!cpu.flags.zf)
    {
        goto L_0x0044b683;
    }
    // 0044b36a  e8f1e40700             -call 0x4c9860
    cpu.esp -= 4;
    sub_4c9860(app, cpu);
    if (cpu.terminate) return;
    // 0044b36f  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b374  83781000               +cmp dword ptr [eax + 0x10], 0
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
    // 0044b378  7408                   -je 0x44b382
    if (cpu.flags.zf)
    {
        goto L_0x0044b382;
    }
    // 0044b37a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044b37c  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044b37f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
L_0x0044b382:
    // 0044b382  e8d90a0000             -call 0x44be60
    cpu.esp -= 4;
    sub_44be60(app, cpu);
    if (cpu.terminate) return;
    // 0044b387  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b38b  754c                   -jne 0x44b3d9
    if (!cpu.flags.zf)
    {
        goto L_0x0044b3d9;
    }
    // 0044b38d  e88edd0800             -call 0x4d9120
    cpu.esp -= 4;
    sub_4d9120(app, cpu);
    if (cpu.terminate) return;
    // 0044b392  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b397  e854f1ffff             -call 0x44a4f0
    cpu.esp -= 4;
    sub_44a4f0(app, cpu);
    if (cpu.terminate) return;
    // 0044b39c  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0044b39f  e80c85ffff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 0044b3a4  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0044b3a6  7408                   -je 0x44b3b0
    if (cpu.flags.zf)
    {
        goto L_0x0044b3b0;
    }
    // 0044b3a8  e8a3abffff             -call 0x445f50
    cpu.esp -= 4;
    sub_445f50(app, cpu);
    if (cpu.terminate) return;
    // 0044b3ad  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
L_0x0044b3b0:
    // 0044b3b0  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b3b5  e8f6f4ffff             -call 0x44a8b0
    cpu.esp -= 4;
    sub_44a8b0(app, cpu);
    if (cpu.terminate) return;
    // 0044b3ba  e8d1f70800             -call 0x4dab90
    cpu.esp -= 4;
    sub_4dab90(app, cpu);
    if (cpu.terminate) return;
    // 0044b3bf  8a252eeb5500           -mov ah, byte ptr [0x55eb2e]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */);
    // 0044b3c5  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 0044b3c8  750a                   -jne 0x44b3d4
    if (!cpu.flags.zf)
    {
        goto L_0x0044b3d4;
    }
    // 0044b3ca  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 0044b3cd  7505                   -jne 0x44b3d4
    if (!cpu.flags.zf)
    {
        goto L_0x0044b3d4;
    }
    // 0044b3cf  e8cce6ffff             -call 0x449aa0
    cpu.esp -= 4;
    sub_449aa0(app, cpu);
    if (cpu.terminate) return;
L_0x0044b3d4:
    // 0044b3d4  e867dd0800             -call 0x4d9140
    cpu.esp -= 4;
    sub_4d9140(app, cpu);
    if (cpu.terminate) return;
L_0x0044b3d9:
    // 0044b3d9  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b3dd  0f85b9000000           -jne 0x44b49c
    if (!cpu.flags.zf)
    {
        goto L_0x0044b49c;
    }
    // 0044b3e3  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044b3eb  7509                   -jne 0x44b3f6
    if (!cpu.flags.zf)
    {
        goto L_0x0044b3f6;
    }
    // 0044b3ed  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
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
    // 0044b3f4  7508                   -jne 0x44b3fe
    if (!cpu.flags.zf)
    {
        goto L_0x0044b3fe;
    }
L_0x0044b3f6:
    // 0044b3f6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044b3f8  890dd0565500           -mov dword ptr [0x5556d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592784) /* 0x5556d0 */) = cpu.ecx;
L_0x0044b3fe:
    // 0044b3fe  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b403  e8a8f2ffff             -call 0x44a6b0
    cpu.esp -= 4;
    sub_44a6b0(app, cpu);
    if (cpu.terminate) return;
    // 0044b408  8b1530925500           -mov edx, dword ptr [0x559230]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b40e  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0044b411  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0044b414  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044b416  39c1                   +cmp ecx, eax
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
    // 0044b418  741d                   -je 0x44b437
    if (cpu.flags.zf)
    {
        goto L_0x0044b437;
    }
    // 0044b41a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044b41c  e82feaffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044b421  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044b423  7412                   -je 0x44b437
    if (cpu.flags.zf)
    {
        goto L_0x0044b437;
    }
    // 0044b425  e836530100             -call 0x460760
    cpu.esp -= 4;
    sub_460760(app, cpu);
    if (cpu.terminate) return;
    // 0044b42a  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b42f  668b501a               -mov dx, word ptr [eax + 0x1a]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
    // 0044b433  6689501c               -mov word ptr [eax + 0x1c], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.dx;
L_0x0044b437:
    // 0044b437  83fbff                 +cmp ebx, -1
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
    // 0044b43a  750d                   -jne 0x44b449
    if (!cpu.flags.zf)
    {
        goto L_0x0044b449;
    }
    // 0044b43c  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b441  66c7401a6400           -mov word ptr [eax + 0x1a], 0x64
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */) = 100 /*0x64*/;
    // 0044b447  eb09                   -jmp 0x44b452
    goto L_0x0044b452;
L_0x0044b449:
    // 0044b449  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b44e  6689581a               -mov word ptr [eax + 0x1a], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */) = cpu.bx;
L_0x0044b452:
    // 0044b452  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044b457  e804650000             -call 0x451960
    cpu.esp -= 4;
    sub_451960(app, cpu);
    if (cpu.terminate) return;
    // 0044b45c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044b45e  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0044b461  7439                   -je 0x44b49c
    if (cpu.flags.zf)
    {
        goto L_0x0044b49c;
    }
    // 0044b463  e84884ffff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 0044b468  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0044b46a  740a                   -je 0x44b476
    if (cpu.flags.zf)
    {
        goto L_0x0044b476;
    }
    // 0044b46c  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0044b46f  e8eca9ffff             -call 0x445e60
    cpu.esp -= 4;
    sub_445e60(app, cpu);
    if (cpu.terminate) return;
    // 0044b474  eb0d                   -jmp 0x44b483
    goto L_0x0044b483;
L_0x0044b476:
    // 0044b476  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b47b  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0044b47e  e84deeffff             -call 0x44a2d0
    cpu.esp -= 4;
    sub_44a2d0(app, cpu);
    if (cpu.terminate) return;
L_0x0044b483:
    // 0044b483  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0044b486  8d55f0                 -lea edx, [ebp - 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b489  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b48e  e80dfdffff             -call 0x44b1a0
    cpu.esp -= 4;
    sub_44b1a0(app, cpu);
    if (cpu.terminate) return;
    // 0044b493  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044b495  7405                   -je 0x44b49c
    if (cpu.flags.zf)
    {
        goto L_0x0044b49c;
    }
    // 0044b497  e9c4feffff             -jmp 0x44b360
    goto L_0x0044b360;
L_0x0044b49c:
    // 0044b49c  837df00a               +cmp dword ptr [ebp - 0x10], 0xa
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b4a0  7569                   -jne 0x44b50b
    if (!cpu.flags.zf)
    {
        goto L_0x0044b50b;
    }
    // 0044b4a2  803d5192550000         +cmp byte ptr [0x559251], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5608017) /* 0x559251 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044b4a9  7560                   -jne 0x44b50b
    if (!cpu.flags.zf)
    {
        goto L_0x0044b50b;
    }
    // 0044b4ab  8b3594e85500           -mov esi, dword ptr [0x55e894]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5630100) /* 0x55e894 */);
    // 0044b4b1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044b4b3  7556                   -jne 0x44b50b
    if (!cpu.flags.zf)
    {
        goto L_0x0044b50b;
    }
    // 0044b4b5  b8f4000000             -mov eax, 0xf4
    cpu.eax = 244 /*0xf4*/;
    // 0044b4ba  e891630800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b4bf  a370296600             -mov dword ptr [0x662970], eax
    app->getMemory<x86::reg32>(x86::reg32(6695280) /* 0x662970 */) = cpu.eax;
    // 0044b4c4  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 0044b4c9  e882630800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b4ce  a37c296600             -mov dword ptr [0x66297c], eax
    app->getMemory<x86::reg32>(x86::reg32(6695292) /* 0x66297c */) = cpu.eax;
    // 0044b4d3  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 0044b4d8  e873630800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b4dd  68f0b04400             -push 0x44b0f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4501744 /*0x44b0f0*/;
    cpu.esp -= 4;
    // 0044b4e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044b4e3  b97c296600             -mov ecx, 0x66297c
    cpu.ecx = 6695292 /*0x66297c*/;
    // 0044b4e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044b4e9  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0044b4ee  ba70296600             -mov edx, 0x662970
    cpu.edx = 6695280 /*0x662970*/;
    // 0044b4f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044b4f4  a380296600             -mov dword ptr [0x662980], eax
    app->getMemory<x86::reg32>(x86::reg32(6695296) /* 0x662980 */) = cpu.eax;
    // 0044b4f9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044b4fe  e8cd91ffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0044b503  8975f0                 -mov dword ptr [ebp - 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.esi;
    // 0044b506  e955feffff             -jmp 0x44b360
    goto L_0x0044b360;
L_0x0044b50b:
    // 0044b50b  837df005               +cmp dword ptr [ebp - 0x10], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b50f  0f8549010000           -jne 0x44b65e
    if (!cpu.flags.zf)
    {
        goto L_0x0044b65e;
    }
    // 0044b515  803dfcd26f0000         +cmp byte ptr [0x6fd2fc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(7328508) /* 0x6fd2fc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044b51c  0f8593000000           -jne 0x44b5b5
    if (!cpu.flags.zf)
    {
        goto L_0x0044b5b5;
    }
    // 0044b522  b8c9000000             -mov eax, 0xc9
    cpu.eax = 201 /*0xc9*/;
    // 0044b527  e824630800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b52c  a370296600             -mov dword ptr [0x662970], eax
    app->getMemory<x86::reg32>(x86::reg32(6695280) /* 0x662970 */) = cpu.eax;
    // 0044b531  b8f8000000             -mov eax, 0xf8
    cpu.eax = 248 /*0xf8*/;
    // 0044b536  e815630800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b53b  a374296600             -mov dword ptr [0x662974], eax
    app->getMemory<x86::reg32>(x86::reg32(6695284) /* 0x662974 */) = cpu.eax;
    // 0044b540  b8f9000000             -mov eax, 0xf9
    cpu.eax = 249 /*0xf9*/;
    // 0044b545  e806630800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b54a  a37c296600             -mov dword ptr [0x66297c], eax
    app->getMemory<x86::reg32>(x86::reg32(6695292) /* 0x66297c */) = cpu.eax;
    // 0044b54f  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0044b554  e8f7620800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b559  a380296600             -mov dword ptr [0x662980], eax
    app->getMemory<x86::reg32>(x86::reg32(6695296) /* 0x662980 */) = cpu.eax;
    // 0044b55e  b8fa000000             -mov eax, 0xfa
    cpu.eax = 250 /*0xfa*/;
    // 0044b563  bffcd26f00             -mov edi, 0x6fd2fc
    cpu.edi = 7328508 /*0x6fd2fc*/;
    // 0044b568  e8e3620800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b56d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044b56f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044b570:
    // 0044b570  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044b572  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044b574  3c00                   +cmp al, 0
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
    // 0044b576  7410                   -je 0x44b588
    if (cpu.flags.zf)
    {
        goto L_0x0044b588;
    }
    // 0044b578  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044b57b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044b57e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044b581  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044b584  3c00                   +cmp al, 0
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
    // 0044b586  75e8                   -jne 0x44b570
    if (!cpu.flags.zf)
    {
        goto L_0x0044b570;
    }
L_0x0044b588:
    // 0044b588  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b589  6890af4400             -push 0x44af90
    app->getMemory<x86::reg32>(cpu.esp-4) = 4501392 /*0x44af90*/;
    cpu.esp -= 4;
    // 0044b58e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0044b590  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0044b592  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044b593  b97c296600             -mov ecx, 0x66297c
    cpu.ecx = 6695292 /*0x66297c*/;
    // 0044b598  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0044b59d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044b59f  ba70296600             -mov edx, 0x662970
    cpu.edx = 6695280 /*0x662970*/;
    // 0044b5a4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044b5a6  e87596ffff             -call 0x444c20
    cpu.esp -= 4;
    sub_444c20(app, cpu);
    if (cpu.terminate) return;
    // 0044b5ab  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044b5ad  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0044b5b0  e9a9000000             -jmp 0x44b65e
    goto L_0x0044b65e;
L_0x0044b5b5:
    // 0044b5b5  8b0db0d36f00           -mov ecx, dword ptr [0x6fd3b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0044b5bb  83f901                 +cmp ecx, 1
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
    // 0044b5be  0f859a000000           -jne 0x44b65e
    if (!cpu.flags.zf)
    {
        goto L_0x0044b65e;
    }
    // 0044b5c4  803d68d36f0000         +cmp byte ptr [0x6fd368], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(7328616) /* 0x6fd368 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044b5cb  0f858d000000           -jne 0x44b65e
    if (!cpu.flags.zf)
    {
        goto L_0x0044b65e;
    }
    // 0044b5d1  b8ca000000             -mov eax, 0xca
    cpu.eax = 202 /*0xca*/;
    // 0044b5d6  e875620800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b5db  a370296600             -mov dword ptr [0x662970], eax
    app->getMemory<x86::reg32>(x86::reg32(6695280) /* 0x662970 */) = cpu.eax;
    // 0044b5e0  b8f8000000             -mov eax, 0xf8
    cpu.eax = 248 /*0xf8*/;
    // 0044b5e5  e866620800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b5ea  a374296600             -mov dword ptr [0x662974], eax
    app->getMemory<x86::reg32>(x86::reg32(6695284) /* 0x662974 */) = cpu.eax;
    // 0044b5ef  b8f9000000             -mov eax, 0xf9
    cpu.eax = 249 /*0xf9*/;
    // 0044b5f4  e857620800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b5f9  a37c296600             -mov dword ptr [0x66297c], eax
    app->getMemory<x86::reg32>(x86::reg32(6695292) /* 0x66297c */) = cpu.eax;
    // 0044b5fe  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0044b603  e848620800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b608  a380296600             -mov dword ptr [0x662980], eax
    app->getMemory<x86::reg32>(x86::reg32(6695296) /* 0x662980 */) = cpu.eax;
    // 0044b60d  b8fb000000             -mov eax, 0xfb
    cpu.eax = 251 /*0xfb*/;
    // 0044b612  bf68d36f00             -mov edi, 0x6fd368
    cpu.edi = 7328616 /*0x6fd368*/;
    // 0044b617  e834620800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044b61c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044b61e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044b61f:
    // 0044b61f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044b621  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044b623  3c00                   +cmp al, 0
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
    // 0044b625  7410                   -je 0x44b637
    if (cpu.flags.zf)
    {
        goto L_0x0044b637;
    }
    // 0044b627  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044b62a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044b62d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044b630  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044b633  3c00                   +cmp al, 0
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
    // 0044b635  75e8                   -jne 0x44b61f
    if (!cpu.flags.zf)
    {
        goto L_0x0044b61f;
    }
L_0x0044b637:
    // 0044b637  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b638  6840b04400             -push 0x44b040
    app->getMemory<x86::reg32>(cpu.esp-4) = 4501568 /*0x44b040*/;
    cpu.esp -= 4;
    // 0044b63d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044b63e  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0044b640  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044b641  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0044b646  ba70296600             -mov edx, 0x662970
    cpu.edx = 6695280 /*0x662970*/;
    // 0044b64b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044b64d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044b64f  b97c296600             -mov ecx, 0x66297c
    cpu.ecx = 6695292 /*0x66297c*/;
    // 0044b654  e8c795ffff             -call 0x444c20
    cpu.esp -= 4;
    sub_444c20(app, cpu);
    if (cpu.terminate) return;
    // 0044b659  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044b65b  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
L_0x0044b65e:
    // 0044b65e  837df004               +cmp dword ptr [ebp - 0x10], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b662  0f85f8fcffff           -jne 0x44b360
    if (!cpu.flags.zf)
    {
        goto L_0x0044b360;
    }
    // 0044b668  813d30925500d0406000   +cmp dword ptr [0x559230], 0x6040d0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b672  7405                   -je 0x44b679
    if (cpu.flags.zf)
    {
        goto L_0x0044b679;
    }
    // 0044b674  e9e7fcffff             -jmp 0x44b360
    goto L_0x0044b360;
L_0x0044b679:
    // 0044b679  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044b67b  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0044b67e  e9ddfcffff             -jmp 0x44b360
    goto L_0x0044b360;
L_0x0044b683:
    // 0044b683  8b152c925500           -mov edx, dword ptr [0x55922c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607980) /* 0x55922c */);
    // 0044b689  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044b68b  740f                   -je 0x44b69c
    if (cpu.flags.zf)
    {
        goto L_0x0044b69c;
    }
    // 0044b68d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044b68f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044b691  e8fa610900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0044b696  890d2c925500           -mov dword ptr [0x55922c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607980) /* 0x55922c */) = cpu.ecx;
L_0x0044b69c:
    // 0044b69c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044b69e  8b35e0227a00           -mov esi, dword ptr [0x7a22e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
    // 0044b6a4  891d30768b00           -mov dword ptr [0x8b7630], ebx
    app->getMemory<x86::reg32>(x86::reg32(9139760) /* 0x8b7630 */) = cpu.ebx;
    // 0044b6aa  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044b6ac  7405                   -je 0x44b6b3
    if (cpu.flags.zf)
    {
        goto L_0x0044b6b3;
    }
    // 0044b6ae  e86d56ffff             -call 0x440d20
    cpu.esp -= 4;
    sub_440d20(app, cpu);
    if (cpu.terminate) return;
L_0x0044b6b3:
    // 0044b6b3  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b6b6  a36c296600             -mov dword ptr [0x66296c], eax
    app->getMemory<x86::reg32>(x86::reg32(6695276) /* 0x66296c */) = cpu.eax;
    // 0044b6bb  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b6c0  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0044b6c3  e8087e0000             -call 0x4534d0
    cpu.esp -= 4;
    sub_4534d0(app, cpu);
    if (cpu.terminate) return;
    // 0044b6c8  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b6cb  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044b6ce  83f807                 +cmp eax, 7
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
    // 0044b6d1  0f871f000000           -ja 0x44b6f6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0044b6f6;
    }
    // 0044b6d7  ff248508b24400         -jmp dword ptr [eax*4 + 0x44b208]
    cpu.ip = app->getMemory<x86::reg32>(4502024 + cpu.eax * 4); goto dynamic_jump;
  case 0x0044b6de:
    // 0044b6de  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b6e1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0044b6e3  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b6e8  893d10eb5500           -mov dword ptr [0x55eb10], edi
    app->getMemory<x86::reg32>(x86::reg32(5630736) /* 0x55eb10 */) = cpu.edi;
    // 0044b6ee  e83df3ffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
    // 0044b6f3  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
  [[fallthrough]];
  case 0x0044b6f6:
L_0x0044b6f6:
    // 0044b6f6  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b6f9  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b6fc  7409                   -je 0x44b707
    if (cpu.flags.zf)
    {
        goto L_0x0044b707;
    }
    // 0044b6fe  83fb01                 +cmp ebx, 1
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
    // 0044b701  0f8504fcffff           -jne 0x44b30b
    if (!cpu.flags.zf)
    {
        goto L_0x0044b30b;
    }
L_0x0044b707:
    // 0044b707  8b3d30925500           -mov edi, dword ptr [0x559230]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b70d  81ffd0406000           +cmp edi, 0x6040d0
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b713  0f85de010000           -jne 0x44b8f7
    if (!cpu.flags.zf)
    {
        goto L_0x0044b8f7;
    }
    // 0044b719  ba0b000000             -mov edx, 0xb
    cpu.edx = 11 /*0xb*/;
    // 0044b71e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044b720  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0044b723  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0044b726  e9e0fbffff             -jmp 0x44b30b
    goto L_0x0044b30b;
  case 0x0044b72b:
    // 0044b72b  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b730  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044b732  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0044b734  891510eb5500           -mov dword ptr [0x55eb10], edx
    app->getMemory<x86::reg32>(x86::reg32(5630736) /* 0x55eb10 */) = cpu.edx;
    // 0044b73a  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b73d  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0044b740  e8ebf2ffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
    // 0044b745  ebaf                   -jmp 0x44b6f6
    goto L_0x0044b6f6;
  case 0x0044b747:
    // 0044b747  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0044b74c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0044b751  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0044b756  e875cafcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0044b75b  e8c0d90800             -call 0x4d9120
    cpu.esp -= 4;
    sub_4d9120(app, cpu);
    if (cpu.terminate) return;
    // 0044b760  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b765  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0044b767  e884edffff             -call 0x44a4f0
    cpu.esp -= 4;
    sub_44a4f0(app, cpu);
    if (cpu.terminate) return;
    // 0044b76c  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0044b76f  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0044b774  891d30768b00           -mov dword ptr [0x8b7630], ebx
    app->getMemory<x86::reg32>(x86::reg32(9139760) /* 0x8b7630 */) = cpu.ebx;
    // 0044b77a  e861090500             -call 0x49c0e0
    cpu.esp -= 4;
    sub_49c0e0(app, cpu);
    if (cpu.terminate) return;
    // 0044b77f  e80cf40800             -call 0x4dab90
    cpu.esp -= 4;
    sub_4dab90(app, cpu);
    if (cpu.terminate) return;
    // 0044b784  e8b7d90800             -call 0x4d9140
    cpu.esp -= 4;
    sub_4d9140(app, cpu);
    if (cpu.terminate) return;
    // 0044b789  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b78c  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b791  893530768b00           -mov dword ptr [0x8b7630], esi
    app->getMemory<x86::reg32>(x86::reg32(9139760) /* 0x8b7630 */) = cpu.esi;
    // 0044b797  893510eb5500           -mov dword ptr [0x55eb10], esi
    app->getMemory<x86::reg32>(x86::reg32(5630736) /* 0x55eb10 */) = cpu.esi;
    // 0044b79d  e88ef2ffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
    // 0044b7a2  e94fffffff             -jmp 0x44b6f6
    goto L_0x0044b6f6;
  case 0x0044b7a7:
    // 0044b7a7  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b7aa  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b7af  e87cf2ffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
    // 0044b7b4  8b1524925500           -mov edx, dword ptr [0x559224]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607972) /* 0x559224 */);
    // 0044b7ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044b7bc  7422                   -je 0x44b7e0
    if (cpu.flags.zf)
    {
        goto L_0x0044b7e0;
    }
    // 0044b7be  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044b7c0  e89bf6ffff             -call 0x44ae60
    cpu.esp -= 4;
    sub_44ae60(app, cpu);
    if (cpu.terminate) return;
    // 0044b7c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044b7c7  7417                   -je 0x44b7e0
    if (cpu.flags.zf)
    {
        goto L_0x0044b7e0;
    }
    // 0044b7c9  a124925500             -mov eax, dword ptr [0x559224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607972) /* 0x559224 */);
    // 0044b7ce  e88df6ffff             -call 0x44ae60
    cpu.esp -= 4;
    sub_44ae60(app, cpu);
    if (cpu.terminate) return;
    // 0044b7d3  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0044b7d5  a330925500             -mov dword ptr [0x559230], eax
    app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */) = cpu.eax;
    // 0044b7da  890d24925500           -mov dword ptr [0x559224], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607972) /* 0x559224 */) = cpu.ecx;
L_0x0044b7e0:
    // 0044b7e0  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0044b7e7  e90affffff             -jmp 0x44b6f6
    goto L_0x0044b6f6;
  case 0x0044b7ec:
    // 0044b7ec  8b3530925500           -mov esi, dword ptr [0x559230]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b7f2  8b5616                 -mov edx, dword ptr [esi + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 0044b7f5  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0044b7f8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044b7fb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044b7fe  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044b800  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044b807  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044b809  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044b80c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044b80e  bbe04e6000             -mov ebx, 0x604ee0
    cpu.ebx = 6311648 /*0x604ee0*/;
    // 0044b813  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044b816  8d55f4                 -lea edx, [ebp - 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044b819  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044b81b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044b81d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044b81f  e81ceaffff             -call 0x44a240
    cpu.esp -= 4;
    sub_44a240(app, cpu);
    if (cpu.terminate) return;
    // 0044b824  39c3                   +cmp ebx, eax
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
    // 0044b826  750c                   -jne 0x44b834
    if (!cpu.flags.zf)
    {
        goto L_0x0044b834;
    }
    // 0044b828  c745f003000000         -mov dword ptr [ebp - 0x10], 3
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 3 /*0x3*/;
    // 0044b82f  e9d3feffff             -jmp 0x44b707
    goto L_0x0044b707;
L_0x0044b834:
    // 0044b834  833b05                 +cmp dword ptr [ebx], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b837  7503                   -jne 0x44b83c
    if (!cpu.flags.zf)
    {
        goto L_0x0044b83c;
    }
    // 0044b839  8b4b40                 -mov ecx, dword ptr [ebx + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */);
L_0x0044b83c:
    // 0044b83c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044b83e  0f847c000000           -je 0x44b8c0
    if (cpu.flags.zf)
    {
        goto L_0x0044b8c0;
    }
    // 0044b844  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044b846  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x0044b849:
    // 0044b849  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044b84c  3b05b00b6600           +cmp eax, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b852  7d1e                   -jge 0x44b872
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044b872;
    }
    // 0044b854  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044b856  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0044b859  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044b85b  8b1485e4406000         -mov edx, dword ptr [eax*4 + 0x6040e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6308068) /* 0x6040e4 */ + cpu.eax * 4);
    // 0044b862  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044b864  e8a72a0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044b869  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044b86b  7405                   -je 0x44b872
    if (cpu.flags.zf)
    {
        goto L_0x0044b872;
    }
    // 0044b86d  ff45f4                 +inc dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044b870  ebd7                   -jmp 0x44b849
    goto L_0x0044b849;
L_0x0044b872:
    // 0044b872  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044b875  3b05b00b6600           +cmp eax, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b87b  7d30                   -jge 0x44b8ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044b8ad;
    }
    // 0044b87d  e88ef6ffff             -call 0x44af10
    cpu.esp -= 4;
    sub_44af10(app, cpu);
    if (cpu.terminate) return;
    // 0044b882  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b885  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b88a  e8a1f1ffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
    // 0044b88f  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044b892  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0044b899  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044b89b  bad0406000             -mov edx, 0x6040d0
    cpu.edx = 6308048 /*0x6040d0*/;
    // 0044b8a0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044b8a3  01c2                   +add edx, eax
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
    // 0044b8a5  891530925500           -mov dword ptr [0x559230], edx
    app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */) = cpu.edx;
    // 0044b8ab  eb1a                   -jmp 0x44b8c7
    goto L_0x0044b8c7;
L_0x0044b8ad:
    // 0044b8ad  c745f003000000         -mov dword ptr [ebp - 0x10], 3
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 3 /*0x3*/;
    // 0044b8b4  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0044b8bb  e936feffff             -jmp 0x44b6f6
    goto L_0x0044b6f6;
L_0x0044b8c0:
    // 0044b8c0  c745f003000000         -mov dword ptr [ebp - 0x10], 3
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 3 /*0x3*/;
L_0x0044b8c7:
    // 0044b8c7  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0044b8ce  e923feffff             -jmp 0x44b6f6
    goto L_0x0044b6f6;
  case 0x0044b8d3:
    // 0044b8d3  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b8d6  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044b8db  e850f1ffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
L_0x0044b8e0:
    // 0044b8e0  813d30925500d0406000   +cmp dword ptr [0x559230], 0x6040d0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b8ea  0f8406feffff           -je 0x44b6f6
    if (cpu.flags.zf)
    {
        goto L_0x0044b6f6;
    }
    // 0044b8f0  e8cbf5ffff             -call 0x44aec0
    cpu.esp -= 4;
    sub_44aec0(app, cpu);
    if (cpu.terminate) return;
    // 0044b8f5  ebe9                   -jmp 0x44b8e0
    goto L_0x0044b8e0;
L_0x0044b8f7:
    // 0044b8f7  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b8fa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044b8fc  e82ff1ffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
    // 0044b901  e8baf5ffff             -call 0x44aec0
    cpu.esp -= 4;
    sub_44aec0(app, cpu);
    if (cpu.terminate) return;
    // 0044b906  e900faffff             -jmp 0x44b30b
    goto L_0x0044b30b;
L_0x0044b90b:
    // 0044b90b  e850e0ffff             -call 0x449960
    cpu.esp -= 4;
    sub_449960(app, cpu);
    if (cpu.terminate) return;
    // 0044b910  8b0d28925500           -mov ecx, dword ptr [0x559228]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */);
    // 0044b916  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044b918  740d                   -je 0x44b927
    if (cpu.flags.zf)
    {
        goto L_0x0044b927;
    }
    // 0044b91a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044b91c  e86f5f0900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0044b921  891d28925500           -mov dword ptr [0x559228], ebx
    app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */) = cpu.ebx;
L_0x0044b927:
    // 0044b927  e8e4670000             -call 0x452110
    cpu.esp -= 4;
    sub_452110(app, cpu);
    if (cpu.terminate) return;
    // 0044b92c  e8dfa5ffff             -call 0x445f10
    cpu.esp -= 4;
    sub_445f10(app, cpu);
    if (cpu.terminate) return;
    // 0044b931  e89a50fcff             -call 0x4109d0
    cpu.esp -= 4;
    sub_4109d0(app, cpu);
    if (cpu.terminate) return;
    // 0044b936  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044b939  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044b93b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b93c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b93d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b93e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b93f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044b940  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_44b950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044b950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044b951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044b952  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044b953  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044b954  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044b955  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044b956  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044b958  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044b95d  a14cbb6f00             -mov eax, dword ptr [0x6fbb4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 0044b962  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044b964  891534925500           -mov dword ptr [0x559234], edx
    app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */) = cpu.edx;
    // 0044b96a  890d54925500           -mov dword ptr [0x559254], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608020) /* 0x559254 */) = cpu.ecx;
    // 0044b970  890d28925500           -mov dword ptr [0x559228], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */) = cpu.ecx;
    // 0044b976  e8d55d0800             -call 0x4d1750
    cpu.esp -= 4;
    sub_4d1750(app, cpu);
    if (cpu.terminate) return;
    // 0044b97b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044b97d  40                     -inc eax
    (cpu.eax)++;
    // 0044b97e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044b980  893485fc276600         -mov dword ptr [eax*4 + 0x6627fc], esi
    app->getMemory<x86::reg32>(x86::reg32(6694908) /* 0x6627fc */ + cpu.eax * 4) = cpu.esi;
L_0x0044b987:
    // 0044b987  83f814                 +cmp eax, 0x14
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
    // 0044b98a  7d0c                   -jge 0x44b998
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044b998;
    }
    // 0044b98c  40                     -inc eax
    (cpu.eax)++;
    // 0044b98d  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0044b98f  893485fc276600         -mov dword ptr [eax*4 + 0x6627fc], esi
    app->getMemory<x86::reg32>(x86::reg32(6694908) /* 0x6627fc */ + cpu.eax * 4) = cpu.esi;
    // 0044b996  ebef                   -jmp 0x44b987
    goto L_0x0044b987;
L_0x0044b998:
    // 0044b998  bf05000000             -mov edi, 5
    cpu.edi = 5 /*0x5*/;
    // 0044b99d  8a252eeb5500           -mov ah, byte ptr [0x55eb2e]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */);
    // 0044b9a3  893d6c296600           -mov dword ptr [0x66296c], edi
    app->getMemory<x86::reg32>(x86::reg32(6695276) /* 0x66296c */) = cpu.edi;
    // 0044b9a9  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 0044b9ac  743a                   -je 0x44b9e8
    if (cpu.flags.zf)
    {
        goto L_0x0044b9e8;
    }
    // 0044b9ae  a1c8fa5e00             -mov eax, dword ptr [0x5efac8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224584) /* 0x5efac8 */);
    // 0044b9b3  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 0044b9ba  7409                   -je 0x44b9c5
    if (cpu.flags.zf)
    {
        goto L_0x0044b9c5;
    }
    // 0044b9bc  83b8c402000003         +cmp dword ptr [eax + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b9c3  7417                   -je 0x44b9dc
    if (cpu.flags.zf)
    {
        goto L_0x0044b9dc;
    }
L_0x0044b9c5:
    // 0044b9c5  a1c8fa5e00             -mov eax, dword ptr [0x5efac8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224584) /* 0x5efac8 */);
    // 0044b9ca  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 0044b9d1  7415                   -je 0x44b9e8
    if (cpu.flags.zf)
    {
        goto L_0x0044b9e8;
    }
    // 0044b9d3  83b8c402000004         +cmp dword ptr [eax + 0x2c4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044b9da  750c                   -jne 0x44b9e8
    if (!cpu.flags.zf)
    {
        goto L_0x0044b9e8;
    }
L_0x0044b9dc:
    // 0044b9dc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044b9e1  b854905300             -mov eax, 0x539054
    cpu.eax = 5476436 /*0x539054*/;
    // 0044b9e6  eb1f                   -jmp 0x44ba07
    goto L_0x0044ba07;
L_0x0044b9e8:
    // 0044b9e8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044b9ed  b85c905300             -mov eax, 0x53905c
    cpu.eax = 5476444 /*0x53905c*/;
    // 0044b9f2  e819dbffff             -call 0x449510
    cpu.esp -= 4;
    sub_449510(app, cpu);
    if (cpu.terminate) return;
    // 0044b9f7  f6052eeb550020         +test byte ptr [0x55eb2e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */) & 32 /*0x20*/));
    // 0044b9fe  740c                   -je 0x44ba0c
    if (cpu.flags.zf)
    {
        goto L_0x0044ba0c;
    }
    // 0044ba00  b864905300             -mov eax, 0x539064
    cpu.eax = 5476452 /*0x539064*/;
    // 0044ba05  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044ba07:
    // 0044ba07  e804dbffff             -call 0x449510
    cpu.esp -= 4;
    sub_449510(app, cpu);
    if (cpu.terminate) return;
L_0x0044ba0c:
    // 0044ba0c  bbd0406000             -mov ebx, 0x6040d0
    cpu.ebx = 6308048 /*0x6040d0*/;
    // 0044ba11  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0044ba16  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044ba18  891d30925500           -mov dword ptr [0x559230], ebx
    app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */) = cpu.ebx;
    // 0044ba1e  e81df1ffff             -call 0x44ab40
    cpu.esp -= 4;
    sub_44ab40(app, cpu);
    if (cpu.terminate) return;
    // 0044ba23  893530768b00           -mov dword ptr [0x8b7630], esi
    app->getMemory<x86::reg32>(x86::reg32(9139760) /* 0x8b7630 */) = cpu.esi;
    // 0044ba29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_44ba30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044ba30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044ba31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044ba32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044ba33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044ba34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044ba35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044ba36  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044ba38  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044ba3d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044ba3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044ba41  890d54925500           -mov dword ptr [0x559254], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608020) /* 0x559254 */) = cpu.ecx;
    // 0044ba47  891534925500           -mov dword ptr [0x559234], edx
    app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */) = cpu.edx;
    // 0044ba4d  40                     -inc eax
    (cpu.eax)++;
    // 0044ba4e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044ba50  891c85fc276600         -mov dword ptr [eax*4 + 0x6627fc], ebx
    app->getMemory<x86::reg32>(x86::reg32(6694908) /* 0x6627fc */ + cpu.eax * 4) = cpu.ebx;
L_0x0044ba57:
    // 0044ba57  83f814                 +cmp eax, 0x14
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
    // 0044ba5a  7d0c                   -jge 0x44ba68
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044ba68;
    }
    // 0044ba5c  40                     -inc eax
    (cpu.eax)++;
    // 0044ba5d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044ba5f  891c85fc276600         -mov dword ptr [eax*4 + 0x6627fc], ebx
    app->getMemory<x86::reg32>(x86::reg32(6694908) /* 0x6627fc */ + cpu.eax * 4) = cpu.ebx;
    // 0044ba66  ebef                   -jmp 0x44ba57
    goto L_0x0044ba57;
L_0x0044ba68:
    // 0044ba68  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
    // 0044ba6d  bfd0406000             -mov edi, 0x6040d0
    cpu.edi = 6308048 /*0x6040d0*/;
    // 0044ba72  89356c296600           -mov dword ptr [0x66296c], esi
    app->getMemory<x86::reg32>(x86::reg32(6695276) /* 0x66296c */) = cpu.esi;
    // 0044ba78  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044ba7a  893d30925500           -mov dword ptr [0x559230], edi
    app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */) = cpu.edi;
    // 0044ba80  e8bbf0ffff             -call 0x44ab40
    cpu.esp -= 4;
    sub_44ab40(app, cpu);
    if (cpu.terminate) return;
    // 0044ba85  c70530768b0001000000   -mov dword ptr [0x8b7630], 1
    app->getMemory<x86::reg32>(x86::reg32(9139760) /* 0x8b7630 */) = 1 /*0x1*/;
    // 0044ba8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba92  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba94  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ba95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_44bac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0044bac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044bac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044bac2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044bac3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044bac4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044bac5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044bac6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044bac8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044bacb  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0044bad0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044bad2  8b3554925500           -mov esi, dword ptr [0x559254]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5608020) /* 0x559254 */);
    // 0044bad8  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0044badb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044badd  740f                   -je 0x44baee
    if (cpu.flags.zf)
    {
        goto L_0x0044baee;
    }
    // 0044badf  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0044bae1  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0044bae3  893d54925500           -mov dword ptr [0x559254], edi
    app->getMemory<x86::reg32>(x86::reg32(5608020) /* 0x559254 */) = cpu.edi;
    // 0044bae9  e982000000             -jmp 0x44bb70
    goto L_0x0044bb70;
L_0x0044baee:
    // 0044baee  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044baf3  e8b8ebffff             -call 0x44a6b0
    cpu.esp -= 4;
    sub_44a6b0(app, cpu);
    if (cpu.terminate) return;
    // 0044baf8  8b1530925500           -mov edx, dword ptr [0x559230]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bafe  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0044bb01  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044bb03  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0044bb06  39c6                   +cmp esi, eax
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
    // 0044bb08  7418                   -je 0x44bb22
    if (cpu.flags.zf)
    {
        goto L_0x0044bb22;
    }
    // 0044bb0a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044bb0c  e83fe3ffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044bb11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044bb13  740d                   -je 0x44bb22
    if (cpu.flags.zf)
    {
        goto L_0x0044bb22;
    }
    // 0044bb15  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bb1a  668b501a               -mov dx, word ptr [eax + 0x1a]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
    // 0044bb1e  6689501c               -mov word ptr [eax + 0x1c], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.dx;
L_0x0044bb22:
    // 0044bb22  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bb25  750d                   -jne 0x44bb34
    if (!cpu.flags.zf)
    {
        goto L_0x0044bb34;
    }
    // 0044bb27  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bb2c  66c7401a6400           -mov word ptr [eax + 0x1a], 0x64
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */) = 100 /*0x64*/;
    // 0044bb32  eb09                   -jmp 0x44bb3d
    goto L_0x0044bb3d;
L_0x0044bb34:
    // 0044bb34  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bb39  6689781a               -mov word ptr [eax + 0x1a], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */) = cpu.di;
L_0x0044bb3d:
    // 0044bb3d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044bb42  e8195e0000             -call 0x451960
    cpu.esp -= 4;
    sub_451960(app, cpu);
    if (cpu.terminate) return;
    // 0044bb47  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044bb49  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0044bb4c  7422                   -je 0x44bb70
    if (cpu.flags.zf)
    {
        goto L_0x0044bb70;
    }
    // 0044bb4e  e85d7dffff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 0044bb53  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0044bb55  740a                   -je 0x44bb61
    if (cpu.flags.zf)
    {
        goto L_0x0044bb61;
    }
    // 0044bb57  0fbfc6                 -movsx eax, si
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0044bb5a  e801a3ffff             -call 0x445e60
    cpu.esp -= 4;
    sub_445e60(app, cpu);
    if (cpu.terminate) return;
    // 0044bb5f  eb0d                   -jmp 0x44bb6e
    goto L_0x0044bb6e;
L_0x0044bb61:
    // 0044bb61  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bb66  0fbfd6                 -movsx edx, si
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0044bb69  e862e7ffff             -call 0x44a2d0
    cpu.esp -= 4;
    sub_44a2d0(app, cpu);
    if (cpu.terminate) return;
L_0x0044bb6e:
    // 0044bb6e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0044bb70:
    // 0044bb70  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044bb72  0f845e010000           -je 0x44bcd6
    if (cpu.flags.zf)
    {
        goto L_0x0044bcd6;
    }
    // 0044bb78  890d6c296600           -mov dword ptr [0x66296c], ecx
    app->getMemory<x86::reg32>(x86::reg32(6695276) /* 0x66296c */) = cpu.ecx;
    // 0044bb7e  8d41fb                 -lea eax, [ecx - 5]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-5) /* -0x5 */);
    // 0044bb81  83f807                 +cmp eax, 7
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
    // 0044bb84  0f8718010000           -ja 0x44bca2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0044bca2;
    }
    // 0044bb8a  ff248598ba4400         -jmp dword ptr [eax*4 + 0x44ba98]
    cpu.ip = app->getMemory<x86::reg32>(4504216 + cpu.eax * 4); goto dynamic_jump;
  case 0x0044bb91:
    // 0044bb91  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bb96  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044bb98  e893eeffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
    // 0044bb9d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044bb9f  e9fe000000             -jmp 0x44bca2
    goto L_0x0044bca2;
  case 0x0044bba4:
    // 0044bba4  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bba9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044bbab  e880eeffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
    // 0044bbb0  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bbb5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0044bbba  e881efffff             -call 0x44ab40
    cpu.esp -= 4;
    sub_44ab40(app, cpu);
    if (cpu.terminate) return;
    // 0044bbbf  e9de000000             -jmp 0x44bca2
    goto L_0x0044bca2;
  case 0x0044bbc4:
    // 0044bbc4  8b3d30925500           -mov edi, dword ptr [0x559230]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bbca  8b4716                 -mov eax, dword ptr [edi + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 0044bbcd  8b5718                 -mov edx, dword ptr [edi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0044bbd0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044bbd3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044bbd6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044bbd8  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0044bbdb  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044bbde  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044bbe1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044bbe3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044bbe6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044bbe8  bae04e6000             -mov edx, 0x604ee0
    cpu.edx = 6311648 /*0x604ee0*/;
    // 0044bbed  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044bbf0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044bbf2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044bbf4  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0044bbf7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044bbf9  8d55f4                 -lea edx, [ebp - 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044bbfc  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044bbff  e83ce6ffff             -call 0x44a240
    cpu.esp -= 4;
    sub_44a240(app, cpu);
    if (cpu.terminate) return;
    // 0044bc04  39f8                   +cmp eax, edi
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
    // 0044bc06  750a                   -jne 0x44bc12
    if (!cpu.flags.zf)
    {
        goto L_0x0044bc12;
    }
    // 0044bc08  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0044bc0d  e99a000000             -jmp 0x44bcac
    goto L_0x0044bcac;
L_0x0044bc12:
    // 0044bc12  833f05                 +cmp dword ptr [edi], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bc15  7503                   -jne 0x44bc1a
    if (!cpu.flags.zf)
    {
        goto L_0x0044bc1a;
    }
    // 0044bc17  8b7740                 -mov esi, dword ptr [edi + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(64) /* 0x40 */);
L_0x0044bc1a:
    // 0044bc1a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044bc1c  0f8476000000           -je 0x44bc98
    if (cpu.flags.zf)
    {
        goto L_0x0044bc98;
    }
    // 0044bc22  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044bc24  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x0044bc27:
    // 0044bc27  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044bc2a  3b05b00b6600           +cmp eax, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bc30  7d1e                   -jge 0x44bc50
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044bc50;
    }
    // 0044bc32  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044bc34  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0044bc37  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044bc39  8b1485e4406000         -mov edx, dword ptr [eax*4 + 0x6040e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6308068) /* 0x6040e4 */ + cpu.eax * 4);
    // 0044bc40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044bc42  e8c9260a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044bc47  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044bc49  7405                   -je 0x44bc50
    if (cpu.flags.zf)
    {
        goto L_0x0044bc50;
    }
    // 0044bc4b  ff45f4                 +inc dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044bc4e  ebd7                   -jmp 0x44bc27
    goto L_0x0044bc27;
L_0x0044bc50:
    // 0044bc50  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044bc53  3b05b00b6600           +cmp eax, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bc59  7d36                   -jge 0x44bc91
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044bc91;
    }
    // 0044bc5b  e8b0f2ffff             -call 0x44af10
    cpu.esp -= 4;
    sub_44af10(app, cpu);
    if (cpu.terminate) return;
    // 0044bc60  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bc65  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044bc67  e8c4edffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
    // 0044bc6c  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044bc6f  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0044bc76  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044bc78  bad0406000             -mov edx, 0x6040d0
    cpu.edx = 6308048 /*0x6040d0*/;
    // 0044bc7d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044bc80  01c2                   +add edx, eax
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
    // 0044bc82  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044bc84  891530925500           -mov dword ptr [0x559230], edx
    app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */) = cpu.edx;
    // 0044bc8a  e8b1eeffff             -call 0x44ab40
    cpu.esp -= 4;
    sub_44ab40(app, cpu);
    if (cpu.terminate) return;
    // 0044bc8f  eb0c                   -jmp 0x44bc9d
    goto L_0x0044bc9d;
L_0x0044bc91:
    // 0044bc91  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0044bc96  eb05                   -jmp 0x44bc9d
    goto L_0x0044bc9d;
L_0x0044bc98:
    // 0044bc98  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
L_0x0044bc9d:
    // 0044bc9d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
  [[fallthrough]];
  case 0x0044bca2:
L_0x0044bca2:
    // 0044bca2  83f903                 +cmp ecx, 3
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
    // 0044bca5  7405                   -je 0x44bcac
    if (cpu.flags.zf)
    {
        goto L_0x0044bcac;
    }
    // 0044bca7  83f901                 +cmp ecx, 1
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
    // 0044bcaa  752a                   -jne 0x44bcd6
    if (!cpu.flags.zf)
    {
        goto L_0x0044bcd6;
    }
L_0x0044bcac:
    // 0044bcac  8b3530925500           -mov esi, dword ptr [0x559230]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bcb2  81fed0406000           +cmp esi, 0x6040d0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bcb8  7504                   -jne 0x44bcbe
    if (!cpu.flags.zf)
    {
        goto L_0x0044bcbe;
    }
    // 0044bcba  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044bcbc  eb18                   -jmp 0x44bcd6
    goto L_0x0044bcd6;
L_0x0044bcbe:
    // 0044bcbe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044bcc0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044bcc2  e869edffff             -call 0x44aa30
    cpu.esp -= 4;
    sub_44aa30(app, cpu);
    if (cpu.terminate) return;
    // 0044bcc7  e8f4f1ffff             -call 0x44aec0
    cpu.esp -= 4;
    sub_44aec0(app, cpu);
    if (cpu.terminate) return;
    // 0044bccc  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bcd1  e86aeeffff             -call 0x44ab40
    cpu.esp -= 4;
    sub_44ab40(app, cpu);
    if (cpu.terminate) return;
L_0x0044bcd6:
    // 0044bcd6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044bcd8  741c                   -je 0x44bcf6
    if (cpu.flags.zf)
    {
        goto L_0x0044bcf6;
    }
    // 0044bcda  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bcdf  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0044bce2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044bce4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044bce6  0f84d1000000           -je 0x44bdbd
    if (cpu.flags.zf)
    {
        goto L_0x0044bdbd;
    }
    // 0044bcec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044bcee  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044bcf1  e9c7000000             -jmp 0x44bdbd
    goto L_0x0044bdbd;
L_0x0044bcf6:
    // 0044bcf6  83f90b                 +cmp ecx, 0xb
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bcf9  7209                   -jb 0x44bd04
    if (cpu.flags.cf)
    {
        goto L_0x0044bd04;
    }
    // 0044bcfb  761e                   -jbe 0x44bd1b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044bd1b;
    }
    // 0044bcfd  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bd00  7409                   -je 0x44bd0b
    if (cpu.flags.zf)
    {
        goto L_0x0044bd0b;
    }
    // 0044bd02  eb37                   -jmp 0x44bd3b
    goto L_0x0044bd3b;
L_0x0044bd04:
    // 0044bd04  83f90a                 +cmp ecx, 0xa
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bd07  7422                   -je 0x44bd2b
    if (cpu.flags.zf)
    {
        goto L_0x0044bd2b;
    }
    // 0044bd09  eb30                   -jmp 0x44bd3b
    goto L_0x0044bd3b;
L_0x0044bd0b:
    // 0044bd0b  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0044bd10  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044bd12  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044bd14  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd15  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd17  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd1a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044bd1b:
    // 0044bd1b  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044bd20  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044bd22  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044bd24  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd25  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd26  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044bd2b:
    // 0044bd2b  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0044bd30  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044bd32  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044bd34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd37  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044bd3b:
    // 0044bd3b  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bd40  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044bd43  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044bd46  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044bd49  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044bd4c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044bd4e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044bd55  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044bd57  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044bd5a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044bd5c  b9e04e6000             -mov ecx, 0x604ee0
    cpu.ecx = 6311648 /*0x604ee0*/;
    // 0044bd61  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044bd64  01c1                   +add ecx, eax
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
    // 0044bd66  7453                   -je 0x44bdbb
    if (cpu.flags.zf)
    {
        goto L_0x0044bdbb;
    }
    // 0044bd68  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0044bd6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044bd6d  744c                   -je 0x44bdbb
    if (cpu.flags.zf)
    {
        goto L_0x0044bdbb;
    }
    // 0044bd6f  ba68905300             -mov edx, 0x539068
    cpu.edx = 5476456 /*0x539068*/;
    // 0044bd74  e8476cffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 0044bd79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044bd7b  7410                   -je 0x44bd8d
    if (cpu.flags.zf)
    {
        goto L_0x0044bd8d;
    }
    // 0044bd7d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0044bd82  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044bd84  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044bd86  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd89  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd8b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bd8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044bd8d:
    // 0044bd8d  ba78905300             -mov edx, 0x539078
    cpu.edx = 5476472 /*0x539078*/;
    // 0044bd92  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0044bd95  e8266cffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 0044bd9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044bd9c  7410                   -je 0x44bdae
    if (cpu.flags.zf)
    {
        goto L_0x0044bdae;
    }
    // 0044bd9e  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0044bda3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044bda5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044bda7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bda8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bda9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdaa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044bdae:
    // 0044bdae  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044bdb0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044bdb2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044bdb4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdb7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044bdbb:
    // 0044bdbb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0044bdbd:
    // 0044bdbd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044bdbf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044bdc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdc4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044bdc7  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_44bdd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044bdd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044bdd1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044bdd2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044bdd4  833d6492550000         +cmp dword ptr [0x559264], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608036) /* 0x559264 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bddb  7505                   -jne 0x44bde2
    if (!cpu.flags.zf)
    {
        goto L_0x0044bde2;
    }
    // 0044bddd  e8feb70500             -call 0x4a75e0
    cpu.esp -= 4;
    sub_4a75e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044bde2:
    // 0044bde2  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044bde7  e804e7ffff             -call 0x44a4f0
    cpu.esp -= 4;
    sub_44a4f0(app, cpu);
    if (cpu.terminate) return;
    // 0044bdec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044bdee  e8bd7affff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 0044bdf3  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0044bdf5  7407                   -je 0x44bdfe
    if (cpu.flags.zf)
    {
        goto L_0x0044bdfe;
    }
    // 0044bdf7  e854a1ffff             -call 0x445f50
    cpu.esp -= 4;
    sub_445f50(app, cpu);
    if (cpu.terminate) return;
    // 0044bdfc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0044bdfe:
    // 0044bdfe  e83d550800             -call 0x4d1340
    cpu.esp -= 4;
    sub_4d1340(app, cpu);
    if (cpu.terminate) return;
    // 0044be03  e8588dfeff             -call 0x434b60
    cpu.esp -= 4;
    sub_434b60(app, cpu);
    if (cpu.terminate) return;
    // 0044be08  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044be0d  e89eeaffff             -call 0x44a8b0
    cpu.esp -= 4;
    sub_44a8b0(app, cpu);
    if (cpu.terminate) return;
    // 0044be12  891554925500           -mov dword ptr [0x559254], edx
    app->getMemory<x86::reg32>(x86::reg32(5608020) /* 0x559254 */) = cpu.edx;
    // 0044be18  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044be1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044be1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044be1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
/* data blob: 9090909090909090909090909090909090909090a4bf4400a8bf4400a8bf4400a8bf44006ec044007ac0440086c0440095c044008d80000000008d9200000000 */
void Application::sub_44be60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0044be60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044be61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044be62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044be63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044be64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044be65  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044be67  833d6829660000         +cmp dword ptr [0x662968], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044be6e  0f8554040000           -jne 0x44c2c8
    if (!cpu.flags.zf)
    {
        goto L_0x0044c2c8;
    }
    // 0044be74  833d58925500ff         +cmp dword ptr [0x559258], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608024) /* 0x559258 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044be7b  7514                   -jne 0x44be91
    if (!cpu.flags.zf)
    {
        goto L_0x0044be91;
    }
    // 0044be7d  a1d0d46f00             -mov eax, dword ptr [0x6fd4d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328976) /* 0x6fd4d0 */);
    // 0044be82  a358925500             -mov dword ptr [0x559258], eax
    app->getMemory<x86::reg32>(x86::reg32(5608024) /* 0x559258 */) = cpu.eax;
    // 0044be87  a1d4d46f00             -mov eax, dword ptr [0x6fd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 0044be8c  a35c925500             -mov dword ptr [0x55925c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608028) /* 0x55925c */) = cpu.eax;
L_0x0044be91:
    // 0044be91  833d60925500ff         +cmp dword ptr [0x559260], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608032) /* 0x559260 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044be98  750a                   -jne 0x44bea4
    if (!cpu.flags.zf)
    {
        goto L_0x0044bea4;
    }
    // 0044be9a  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044be9f  a360925500             -mov dword ptr [0x559260], eax
    app->getMemory<x86::reg32>(x86::reg32(5608032) /* 0x559260 */) = cpu.eax;
L_0x0044bea4:
    // 0044bea4  8b3d00bc6f00           -mov edi, dword ptr [0x6fbc00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7322624) /* 0x6fbc00 */);
    // 0044beaa  eb15                   -jmp 0x44bec1
    goto L_0x0044bec1;
    // 0044beac  90                     -nop 
    ;
    // 0044bead  90                     -nop 
    ;
    // 0044beae  90                     -nop 
    ;
    // 0044beaf  90                     -nop 
    ;
    // 0044beb0  90                     -nop 
    ;
    // 0044beb1  90                     -nop 
    ;
    // 0044beb2  90                     -nop 
    ;
    // 0044beb3  90                     -nop 
    ;
    // 0044beb4  90                     -nop 
    ;
    // 0044beb5  90                     -nop 
    ;
    // 0044beb6  90                     -nop 
    ;
    // 0044beb7  90                     -nop 
    ;
    // 0044beb8  90                     -nop 
    ;
    // 0044beb9  90                     -nop 
    ;
    // 0044beba  90                     -nop 
    ;
    // 0044bebb  90                     -nop 
    ;
    // 0044bebc  90                     -nop 
    ;
    // 0044bebd  90                     -nop 
    ;
    // 0044bebe  90                     -nop 
    ;
    // 0044bebf  90                     -nop 
    ;
    // 0044bec0  90                     -nop 
    ;
L_0x0044bec1:
    // 0044bec1  83ff01                 +cmp edi, 1
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
    // 0044bec4  7509                   -jne 0x44becf
    if (!cpu.flags.zf)
    {
        goto L_0x0044becf;
    }
    // 0044bec6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044bec8  a32c295500             -mov dword ptr [0x55292c], eax
    app->getMemory<x86::reg32>(x86::reg32(5581100) /* 0x55292c */) = cpu.eax;
    // 0044becd  eb0e                   -jmp 0x44bedd
    goto L_0x0044bedd;
L_0x0044becf:
    // 0044becf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044bed1  750a                   -jne 0x44bedd
    if (!cpu.flags.zf)
    {
        goto L_0x0044bedd;
    }
    // 0044bed3  c7052c29550001000000   -mov dword ptr [0x55292c], 1
    app->getMemory<x86::reg32>(x86::reg32(5581100) /* 0x55292c */) = 1 /*0x1*/;
L_0x0044bedd:
    // 0044bedd  833db8d36f0003         +cmp dword ptr [0x6fd3b8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bee4  750a                   -jne 0x44bef0
    if (!cpu.flags.zf)
    {
        goto L_0x0044bef0;
    }
    // 0044bee6  c705d0d46f0002000000   -mov dword ptr [0x6fd4d0], 2
    app->getMemory<x86::reg32>(x86::reg32(7328976) /* 0x6fd4d0 */) = 2 /*0x2*/;
L_0x0044bef0:
    // 0044bef0  8b3d58925500           -mov edi, dword ptr [0x559258]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5608024) /* 0x559258 */);
    // 0044bef6  a1d0d46f00             -mov eax, dword ptr [0x6fd4d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328976) /* 0x6fd4d0 */);
    // 0044befb  39f8                   +cmp eax, edi
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
    // 0044befd  0f8481000000           -je 0x44bf84
    if (cpu.flags.zf)
    {
        goto L_0x0044bf84;
    }
    // 0044bf03  a358925500             -mov dword ptr [0x559258], eax
    app->getMemory<x86::reg32>(x86::reg32(5608024) /* 0x559258 */) = cpu.eax;
    // 0044bf08  83f801                 +cmp eax, 1
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
    // 0044bf0b  720c                   -jb 0x44bf19
    if (cpu.flags.cf)
    {
        goto L_0x0044bf19;
    }
    // 0044bf0d  7632                   -jbe 0x44bf41
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044bf41;
    }
    // 0044bf0f  83f802                 +cmp eax, 2
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
    // 0044bf12  7450                   -je 0x44bf64
    if (cpu.flags.zf)
    {
        goto L_0x0044bf64;
    }
    // 0044bf14  e9c5000000             -jmp 0x44bfde
    goto L_0x0044bfde;
L_0x0044bf19:
    // 0044bf19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044bf1b  0f85bd000000           -jne 0x44bfde
    if (!cpu.flags.zf)
    {
        goto L_0x0044bfde;
    }
    // 0044bf21  833dd4d46f0000         +cmp dword ptr [0x6fd4d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bf28  0f84b0000000           -je 0x44bfde
    if (cpu.flags.zf)
    {
        goto L_0x0044bfde;
    }
    // 0044bf2e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044bf30  89155c925500           -mov dword ptr [0x55925c], edx
    app->getMemory<x86::reg32>(x86::reg32(5608028) /* 0x55925c */) = cpu.edx;
    // 0044bf36  8915d4d46f00           -mov dword ptr [0x6fd4d4], edx
    app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */) = cpu.edx;
    // 0044bf3c  e99d000000             -jmp 0x44bfde
    goto L_0x0044bfde;
L_0x0044bf41:
    // 0044bf41  833dd4d46f0000         +cmp dword ptr [0x6fd4d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bf48  0f8590000000           -jne 0x44bfde
    if (!cpu.flags.zf)
    {
        goto L_0x0044bfde;
    }
    // 0044bf4e  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 0044bf53  89355c925500           -mov dword ptr [0x55925c], esi
    app->getMemory<x86::reg32>(x86::reg32(5608028) /* 0x55925c */) = cpu.esi;
    // 0044bf59  8935d4d46f00           -mov dword ptr [0x6fd4d4], esi
    app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */) = cpu.esi;
    // 0044bf5f  e97a000000             -jmp 0x44bfde
    goto L_0x0044bfde;
L_0x0044bf64:
    // 0044bf64  833dd4d46f0000         +cmp dword ptr [0x6fd4d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bf6b  0f856d000000           -jne 0x44bfde
    if (!cpu.flags.zf)
    {
        goto L_0x0044bfde;
    }
    // 0044bf71  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044bf76  89155c925500           -mov dword ptr [0x55925c], edx
    app->getMemory<x86::reg32>(x86::reg32(5608028) /* 0x55925c */) = cpu.edx;
    // 0044bf7c  8915d4d46f00           -mov dword ptr [0x6fd4d4], edx
    app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */) = cpu.edx;
    // 0044bf82  eb5a                   -jmp 0x44bfde
    goto L_0x0044bfde;
L_0x0044bf84:
    // 0044bf84  8b1d5c925500           -mov ebx, dword ptr [0x55925c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5608028) /* 0x55925c */);
    // 0044bf8a  a1d4d46f00             -mov eax, dword ptr [0x6fd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 0044bf8f  39d8                   +cmp eax, ebx
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
    // 0044bf91  744b                   -je 0x44bfde
    if (cpu.flags.zf)
    {
        goto L_0x0044bfde;
    }
    // 0044bf93  a35c925500             -mov dword ptr [0x55925c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608028) /* 0x55925c */) = cpu.eax;
    // 0044bf98  83f803                 +cmp eax, 3
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
    // 0044bf9b  7727                   -ja 0x44bfc4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0044bfc4;
    }
    // 0044bf9d  ff248534be4400         -jmp dword ptr [eax*4 + 0x44be34]
    cpu.ip = app->getMemory<x86::reg32>(4505140 + cpu.eax * 4); goto dynamic_jump;
  case 0x0044bfa4:
    // 0044bfa4  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0044bfa6  eb2a                   -jmp 0x44bfd2
    goto L_0x0044bfd2;
  case 0x0044bfa8:
    // 0044bfa8  833dd0d46f0000         +cmp dword ptr [0x6fd4d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328976) /* 0x6fd4d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bfaf  752d                   -jne 0x44bfde
    if (!cpu.flags.zf)
    {
        goto L_0x0044bfde;
    }
    // 0044bfb1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0044bfb6  891558925500           -mov dword ptr [0x559258], edx
    app->getMemory<x86::reg32>(x86::reg32(5608024) /* 0x559258 */) = cpu.edx;
    // 0044bfbc  8915d0d46f00           -mov dword ptr [0x6fd4d0], edx
    app->getMemory<x86::reg32>(x86::reg32(7328976) /* 0x6fd4d0 */) = cpu.edx;
    // 0044bfc2  eb1a                   -jmp 0x44bfde
    goto L_0x0044bfde;
L_0x0044bfc4:
    // 0044bfc4  833dd0d46f0000         +cmp dword ptr [0x6fd4d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328976) /* 0x6fd4d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044bfcb  7511                   -jne 0x44bfde
    if (!cpu.flags.zf)
    {
        goto L_0x0044bfde;
    }
    // 0044bfcd  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x0044bfd2:
    // 0044bfd2  893558925500           -mov dword ptr [0x559258], esi
    app->getMemory<x86::reg32>(x86::reg32(5608024) /* 0x559258 */) = cpu.esi;
    // 0044bfd8  8935d0d46f00           -mov dword ptr [0x6fd4d0], esi
    app->getMemory<x86::reg32>(x86::reg32(7328976) /* 0x6fd4d0 */) = cpu.esi;
L_0x0044bfde:
    // 0044bfde  8b1560925500           -mov edx, dword ptr [0x559260]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608032) /* 0x559260 */);
    // 0044bfe4  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044bfe9  39d0                   +cmp eax, edx
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
    // 0044bfeb  7405                   -je 0x44bff2
    if (cpu.flags.zf)
    {
        goto L_0x0044bff2;
    }
    // 0044bfed  a360925500             -mov dword ptr [0x559260], eax
    app->getMemory<x86::reg32>(x86::reg32(5608032) /* 0x559260 */) = cpu.eax;
L_0x0044bff2:
    // 0044bff2  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0044bff7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044bff9  e8e2e6feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
    // 0044bffe  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c003  b804400000             -mov eax, 0x4004
    cpu.eax = 16388 /*0x4004*/;
    // 0044c008  e8d3e6feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
    // 0044c00d  833db0d36f0002         +cmp dword ptr [0x6fd3b0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044c014  0f8c7b000000           -jl 0x44c095
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044c095;
    }
    // 0044c01a  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044c020  83fb01                 +cmp ebx, 1
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
    // 0044c023  7405                   -je 0x44c02a
    if (cpu.flags.zf)
    {
        goto L_0x0044c02a;
    }
    // 0044c025  83fb02                 +cmp ebx, 2
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
    // 0044c028  751b                   -jne 0x44c045
    if (!cpu.flags.zf)
    {
        goto L_0x0044c045;
    }
L_0x0044c02a:
    // 0044c02a  833d04d56f0003         +cmp dword ptr [0x6fd504], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329028) /* 0x6fd504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044c031  7507                   -jne 0x44c03a
    if (!cpu.flags.zf)
    {
        goto L_0x0044c03a;
    }
    // 0044c033  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044c035  a304d56f00             -mov dword ptr [0x6fd504], eax
    app->getMemory<x86::reg32>(x86::reg32(7329028) /* 0x6fd504 */) = cpu.eax;
L_0x0044c03a:
    // 0044c03a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044c03c  6689159c635500         -mov word ptr [0x55639c], dx
    app->getMemory<x86::reg16>(x86::reg32(5596060) /* 0x55639c */) = cpu.dx;
    // 0044c043  eb09                   -jmp 0x44c04e
    goto L_0x0044c04e;
L_0x0044c045:
    // 0044c045  66c7059c6355000100     -mov word ptr [0x55639c], 1
    app->getMemory<x86::reg16>(x86::reg32(5596060) /* 0x55639c */) = 1 /*0x1*/;
L_0x0044c04e:
    // 0044c04e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c053  b804000400             -mov eax, 0x40004
    cpu.eax = 262148 /*0x40004*/;
    // 0044c058  e883e6feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
    // 0044c05d  a104d56f00             -mov eax, dword ptr [0x6fd504]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7329028) /* 0x6fd504 */);
    // 0044c062  83f803                 +cmp eax, 3
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
    // 0044c065  772e                   -ja 0x44c095
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0044c095;
    }
    // 0044c067  ff248544be4400         -jmp dword ptr [eax*4 + 0x44be44]
    cpu.ip = app->getMemory<x86::reg32>(4505156 + cpu.eax * 4); goto dynamic_jump;
  case 0x0044c06e:
    // 0044c06e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c073  b86c060000             -mov eax, 0x66c
    cpu.eax = 1644 /*0x66c*/;
    // 0044c078  eb16                   -jmp 0x44c090
    goto L_0x0044c090;
  case 0x0044c07a:
    // 0044c07a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c07f  b85c050000             -mov eax, 0x55c
    cpu.eax = 1372 /*0x55c*/;
    // 0044c084  eb0a                   -jmp 0x44c090
    goto L_0x0044c090;
  case 0x0044c086:
    // 0044c086  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c08b  b83c030000             -mov eax, 0x33c
    cpu.eax = 828 /*0x33c*/;
L_0x0044c090:
    // 0044c090  e84be6feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x0044c095:
L_0x0044c095:
    // 0044c095  8b15b8d36f00           -mov edx, dword ptr [0x6fd3b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044c09b  83fa01                 +cmp edx, 1
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
    // 0044c09e  7405                   -je 0x44c0a5
    if (cpu.flags.zf)
    {
        goto L_0x0044c0a5;
    }
    // 0044c0a0  83fa02                 +cmp edx, 2
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
    // 0044c0a3  7552                   -jne 0x44c0f7
    if (!cpu.flags.zf)
    {
        goto L_0x0044c0f7;
    }
L_0x0044c0a5:
    // 0044c0a5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0044c0aa  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0044c0af  b884080000             -mov eax, 0x884
    cpu.eax = 2180 /*0x884*/;
    // 0044c0b4  891de8d46f00           -mov dword ptr [0x6fd4e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(7329000) /* 0x6fd4e8 */) = cpu.ebx;
    // 0044c0ba  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0044c0bc  8935d0d46f00           -mov dword ptr [0x6fd4d0], esi
    app->getMemory<x86::reg32>(x86::reg32(7328976) /* 0x6fd4d0 */) = cpu.esi;
    // 0044c0c2  e819e6feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
    // 0044c0c7  a1d4d46f00             -mov eax, dword ptr [0x6fd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 0044c0cc  39f0                   +cmp eax, esi
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
    // 0044c0ce  7209                   -jb 0x44c0d9
    if (cpu.flags.cf)
    {
        goto L_0x0044c0d9;
    }
    // 0044c0d0  7612                   -jbe 0x44c0e4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044c0e4;
    }
    // 0044c0d2  83f803                 +cmp eax, 3
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
    // 0044c0d5  7414                   -je 0x44c0eb
    if (cpu.flags.zf)
    {
        goto L_0x0044c0eb;
    }
    // 0044c0d7  eb1e                   -jmp 0x44c0f7
    goto L_0x0044c0f7;
L_0x0044c0d9:
    // 0044c0d9  39d8                   +cmp eax, ebx
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
    // 0044c0db  751a                   -jne 0x44c0f7
    if (!cpu.flags.zf)
    {
        goto L_0x0044c0f7;
    }
    // 0044c0dd  b868000000             -mov eax, 0x68
    cpu.eax = 104 /*0x68*/;
    // 0044c0e2  eb0c                   -jmp 0x44c0f0
    goto L_0x0044c0f0;
L_0x0044c0e4:
    // 0044c0e4  b858000000             -mov eax, 0x58
    cpu.eax = 88 /*0x58*/;
    // 0044c0e9  eb05                   -jmp 0x44c0f0
    goto L_0x0044c0f0;
L_0x0044c0eb:
    // 0044c0eb  b838000000             -mov eax, 0x38
    cpu.eax = 56 /*0x38*/;
L_0x0044c0f0:
    // 0044c0f0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0044c0f2  e8e9e5feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044c0f7:
    // 0044c0f7  833db8d36f0003         +cmp dword ptr [0x6fd3b8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044c0fe  740f                   -je 0x44c10f
    if (cpu.flags.zf)
    {
        goto L_0x0044c10f;
    }
    // 0044c100  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c105  b808400000             -mov eax, 0x4008
    cpu.eax = 16392 /*0x4008*/;
    // 0044c10a  e990000000             -jmp 0x44c19f
    goto L_0x0044c19f;
L_0x0044c10f:
    // 0044c10f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c114  b808200000             -mov eax, 0x2008
    cpu.eax = 8200 /*0x2008*/;
    // 0044c119  e8c2e5feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
    // 0044c11e  a1b0d36f00             -mov eax, dword ptr [0x6fd3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0044c123  83f802                 +cmp eax, 2
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
    // 0044c126  7c2f                   -jl 0x44c157
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044c157;
    }
    // 0044c128  a174227a00             -mov eax, dword ptr [0x7a2274]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8004212) /* 0x7a2274 */);
    // 0044c12d  8b15d0e55500           -mov edx, dword ptr [0x55e5d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629392) /* 0x55e5d0 */);
    // 0044c133  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044c136  39d0                   +cmp eax, edx
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
    // 0044c138  750c                   -jne 0x44c146
    if (!cpu.flags.zf)
    {
        goto L_0x0044c146;
    }
    // 0044c13a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c13f  b884200000             -mov eax, 0x2084
    cpu.eax = 8324 /*0x2084*/;
    // 0044c144  eb0a                   -jmp 0x44c150
    goto L_0x0044c150;
L_0x0044c146:
    // 0044c146  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c14b  b8040f0000             -mov eax, 0xf04
    cpu.eax = 3844 /*0xf04*/;
L_0x0044c150:
    // 0044c150  e88be5feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
    // 0044c155  eb4d                   -jmp 0x44c1a4
    goto L_0x0044c1a4;
L_0x0044c157:
    // 0044c157  83f801                 +cmp eax, 1
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
    // 0044c15a  7539                   -jne 0x44c195
    if (!cpu.flags.zf)
    {
        goto L_0x0044c195;
    }
    // 0044c15c  a1bcd26f00             -mov eax, dword ptr [0x6fd2bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 0044c161  e84ad5feff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0044c166  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c168  741a                   -je 0x44c184
    if (cpu.flags.zf)
    {
        goto L_0x0044c184;
    }
    // 0044c16a  a128d36f00             -mov eax, dword ptr [0x6fd328]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
    // 0044c16f  e83cd5feff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0044c174  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c176  740c                   -je 0x44c184
    if (cpu.flags.zf)
    {
        goto L_0x0044c184;
    }
    // 0044c178  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c17d  b884200000             -mov eax, 0x2084
    cpu.eax = 8324 /*0x2084*/;
    // 0044c182  eb0a                   -jmp 0x44c18e
    goto L_0x0044c18e;
L_0x0044c184:
    // 0044c184  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c189  b8040f0000             -mov eax, 0xf04
    cpu.eax = 3844 /*0xf04*/;
L_0x0044c18e:
    // 0044c18e  e84de5feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
    // 0044c193  eb0f                   -jmp 0x44c1a4
    goto L_0x0044c1a4;
L_0x0044c195:
    // 0044c195  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c19a  b884200000             -mov eax, 0x2084
    cpu.eax = 8324 /*0x2084*/;
L_0x0044c19f:
    // 0044c19f  e83ce5feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044c1a4:
    // 0044c1a4  ba84905300             -mov edx, 0x539084
    cpu.edx = 5476484 /*0x539084*/;
    // 0044c1a9  e852ecffff             -call 0x44ae00
    cpu.esp -= 4;
    sub_44ae00(app, cpu);
    if (cpu.terminate) return;
    // 0044c1ae  e85d210a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044c1b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c1b5  7413                   -je 0x44c1ca
    if (cpu.flags.zf)
    {
        goto L_0x0044c1ca;
    }
    // 0044c1b7  ba90905300             -mov edx, 0x539090
    cpu.edx = 5476496 /*0x539090*/;
    // 0044c1bc  e83fecffff             -call 0x44ae00
    cpu.esp -= 4;
    sub_44ae00(app, cpu);
    if (cpu.terminate) return;
    // 0044c1c1  e84a210a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044c1c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c1c8  751e                   -jne 0x44c1e8
    if (!cpu.flags.zf)
    {
        goto L_0x0044c1e8;
    }
L_0x0044c1ca:
    // 0044c1ca  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c1cf  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0044c1d4  e807e5feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
    // 0044c1d9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c1de  b808000800             -mov eax, 0x80008
    cpu.eax = 524296 /*0x80008*/;
    // 0044c1e3  e8f8e4feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044c1e8:
    // 0044c1e8  ba9c905300             -mov edx, 0x53909c
    cpu.edx = 5476508 /*0x53909c*/;
    // 0044c1ed  e80eecffff             -call 0x44ae00
    cpu.esp -= 4;
    sub_44ae00(app, cpu);
    if (cpu.terminate) return;
    // 0044c1f2  e819210a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044c1f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c1f9  751e                   -jne 0x44c219
    if (!cpu.flags.zf)
    {
        goto L_0x0044c219;
    }
    // 0044c1fb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c200  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0044c205  e8d6e4feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
    // 0044c20a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c20f  b808002800             -mov eax, 0x280008
    cpu.eax = 2621448 /*0x280008*/;
    // 0044c214  e8c7e4feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044c219:
    // 0044c219  baa4905300             -mov edx, 0x5390a4
    cpu.edx = 5476516 /*0x5390a4*/;
    // 0044c21e  e8ddebffff             -call 0x44ae00
    cpu.esp -= 4;
    sub_44ae00(app, cpu);
    if (cpu.terminate) return;
    // 0044c223  e8e8200a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044c228  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c22a  750f                   -jne 0x44c23b
    if (!cpu.flags.zf)
    {
        goto L_0x0044c23b;
    }
    // 0044c22c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c231  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0044c236  e8a5e4feff             -call 0x43a6e0
    cpu.esp -= 4;
    sub_43a6e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044c23b:
    // 0044c23b  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044c240  83f801                 +cmp eax, 1
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
    // 0044c243  7248                   -jb 0x44c28d
    if (cpu.flags.cf)
    {
        goto L_0x0044c28d;
    }
    // 0044c245  7607                   -jbe 0x44c24e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044c24e;
    }
    // 0044c247  83f802                 +cmp eax, 2
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
    // 0044c24a  742e                   -je 0x44c27a
    if (cpu.flags.zf)
    {
        goto L_0x0044c27a;
    }
    // 0044c24c  eb3f                   -jmp 0x44c28d
    goto L_0x0044c28d;
L_0x0044c24e:
    // 0044c24e  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044c255  7e07                   -jle 0x44c25e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044c25e;
    }
    // 0044c257  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044c25c  eb05                   -jmp 0x44c263
    goto L_0x0044c263;
L_0x0044c25e:
    // 0044c25e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x0044c263:
    // 0044c263  e8f82e0800             -call 0x4cf160
    cpu.esp -= 4;
    sub_4cf160(app, cpu);
    if (cpu.terminate) return;
    // 0044c268  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0044c269  a3b0d46f00             -mov dword ptr [0x6fd4b0], eax
    app->getMemory<x86::reg32>(x86::reg32(7328944) /* 0x6fd4b0 */) = cpu.eax;
    // 0044c26e  a104d05500             -mov eax, dword ptr [0x55d004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5623812) /* 0x55d004 */);
    // 0044c273  a3acd46f00             -mov dword ptr [0x6fd4ac], eax
    app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */) = cpu.eax;
    // 0044c278  eb13                   -jmp 0x44c28d
    goto L_0x0044c28d;
L_0x0044c27a:
    // 0044c27a  e8e12e0800             -call 0x4cf160
    cpu.esp -= 4;
    sub_4cf160(app, cpu);
    if (cpu.terminate) return;
    // 0044c27f  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0044c280  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044c282  a3b0d46f00             -mov dword ptr [0x6fd4b0], eax
    app->getMemory<x86::reg32>(x86::reg32(7328944) /* 0x6fd4b0 */) = cpu.eax;
    // 0044c287  8935acd46f00           -mov dword ptr [0x6fd4ac], esi
    app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */) = cpu.esi;
L_0x0044c28d:
    // 0044c28d  a1aed46f00             -mov eax, dword ptr [0x6fd4ae]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328942) /* 0x6fd4ae */);
    // 0044c292  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044c295  e8f62e0800             -call 0x4cf190
    cpu.esp -= 4;
    sub_4cf190(app, cpu);
    if (cpu.terminate) return;
    // 0044c29a  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0044c29b  a3b4d46f00             -mov dword ptr [0x6fd4b4], eax
    app->getMemory<x86::reg32>(x86::reg32(7328948) /* 0x6fd4b4 */) = cpu.eax;
    // 0044c2a0  a1d0d46f00             -mov eax, dword ptr [0x6fd4d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328976) /* 0x6fd4d0 */);
    // 0044c2a5  a358925500             -mov dword ptr [0x559258], eax
    app->getMemory<x86::reg32>(x86::reg32(5608024) /* 0x559258 */) = cpu.eax;
    // 0044c2aa  a1d4d46f00             -mov eax, dword ptr [0x6fd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 0044c2af  8b3dacd26f00           -mov edi, dword ptr [0x6fd2ac]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328428) /* 0x6fd2ac */);
    // 0044c2b5  a35c925500             -mov dword ptr [0x55925c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608028) /* 0x55925c */) = cpu.eax;
    // 0044c2ba  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044c2bc  740a                   -je 0x44c2c8
    if (cpu.flags.zf)
    {
        goto L_0x0044c2c8;
    }
    // 0044c2be  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0044c2c3  e89868ffff             -call 0x442b60
    cpu.esp -= 4;
    sub_442b60(app, cpu);
    if (cpu.terminate) return;
L_0x0044c2c8:
    // 0044c2c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c2c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c2ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c2cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c2cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c2cd  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_44c2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044c2d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044c2d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044c2d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044c2d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044c2d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044c2d7  baac905300             -mov edx, 0x5390ac
    cpu.edx = 5476524 /*0x5390ac*/;
    // 0044c2dc  e85f67ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c2e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c2e3  0f8468000000           -je 0x44c351
    if (cpu.flags.zf)
    {
        goto L_0x0044c351;
    }
    // 0044c2e9  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0044c2ed  bab4905300             -mov edx, 0x5390b4
    cpu.edx = 5476532 /*0x5390b4*/;
    // 0044c2f2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c2f4  e84767ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c2f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c2fb  7454                   -je 0x44c351
    if (cpu.flags.zf)
    {
        goto L_0x0044c351;
    }
    // 0044c2fd  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0044c301  bac0905300             -mov edx, 0x5390c0
    cpu.edx = 5476544 /*0x5390c0*/;
    // 0044c306  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c308  e83367ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c30d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c30f  7440                   -je 0x44c351
    if (cpu.flags.zf)
    {
        goto L_0x0044c351;
    }
    // 0044c311  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0044c315  bac8905300             -mov edx, 0x5390c8
    cpu.edx = 5476552 /*0x5390c8*/;
    // 0044c31a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c31c  e81f67ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c321  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c323  742c                   -je 0x44c351
    if (cpu.flags.zf)
    {
        goto L_0x0044c351;
    }
    // 0044c325  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0044c329  bad0905300             -mov edx, 0x5390d0
    cpu.edx = 5476560 /*0x5390d0*/;
    // 0044c32e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c330  e80b67ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c335  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c337  7418                   -je 0x44c351
    if (cpu.flags.zf)
    {
        goto L_0x0044c351;
    }
    // 0044c339  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0044c33d  bad8905300             -mov edx, 0x5390d8
    cpu.edx = 5476568 /*0x5390d8*/;
    // 0044c342  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c344  e8f766ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c349  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c34b  7404                   -je 0x44c351
    if (cpu.flags.zf)
    {
        goto L_0x0044c351;
    }
    // 0044c34d  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c351:
    // 0044c351  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c352  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c353  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c354  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_44c360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044c360  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044c361  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044c362  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044c363  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044c365  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044c367  bae0905300             -mov edx, 0x5390e0
    cpu.edx = 5476576 /*0x5390e0*/;
    // 0044c36c  e8cf66ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c371  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c373  7404                   -je 0x44c379
    if (cpu.flags.zf)
    {
        goto L_0x0044c379;
    }
    // 0044c375  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c379:
    // 0044c379  baf0905300             -mov edx, 0x5390f0
    cpu.edx = 5476592 /*0x5390f0*/;
    // 0044c37e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c380  e8bb66ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c385  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c387  7404                   -je 0x44c38d
    if (cpu.flags.zf)
    {
        goto L_0x0044c38d;
    }
    // 0044c389  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c38d:
    // 0044c38d  bafc905300             -mov edx, 0x5390fc
    cpu.edx = 5476604 /*0x5390fc*/;
    // 0044c392  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c394  e8a766ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c399  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c39b  7404                   -je 0x44c3a1
    if (cpu.flags.zf)
    {
        goto L_0x0044c3a1;
    }
    // 0044c39d  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c3a1:
    // 0044c3a1  ba0c915300             -mov edx, 0x53910c
    cpu.edx = 5476620 /*0x53910c*/;
    // 0044c3a6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c3a8  e89366ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c3ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c3af  7404                   -je 0x44c3b5
    if (cpu.flags.zf)
    {
        goto L_0x0044c3b5;
    }
    // 0044c3b1  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c3b5:
    // 0044c3b5  ba18915300             -mov edx, 0x539118
    cpu.edx = 5476632 /*0x539118*/;
    // 0044c3ba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c3bc  e87f66ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c3c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c3c3  7404                   -je 0x44c3c9
    if (cpu.flags.zf)
    {
        goto L_0x0044c3c9;
    }
    // 0044c3c5  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c3c9:
    // 0044c3c9  ba24915300             -mov edx, 0x539124
    cpu.edx = 5476644 /*0x539124*/;
    // 0044c3ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c3d0  e86b66ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c3d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c3d7  7404                   -je 0x44c3dd
    if (cpu.flags.zf)
    {
        goto L_0x0044c3dd;
    }
    // 0044c3d9  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c3dd:
    // 0044c3dd  ba2c915300             -mov edx, 0x53912c
    cpu.edx = 5476652 /*0x53912c*/;
    // 0044c3e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c3e4  e85766ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c3e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c3eb  7404                   -je 0x44c3f1
    if (cpu.flags.zf)
    {
        goto L_0x0044c3f1;
    }
    // 0044c3ed  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c3f1:
    // 0044c3f1  ba3c915300             -mov edx, 0x53913c
    cpu.edx = 5476668 /*0x53913c*/;
    // 0044c3f6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c3f8  e84366ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c3fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c3ff  7404                   -je 0x44c405
    if (cpu.flags.zf)
    {
        goto L_0x0044c405;
    }
    // 0044c401  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c405:
    // 0044c405  ba4c915300             -mov edx, 0x53914c
    cpu.edx = 5476684 /*0x53914c*/;
    // 0044c40a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c40c  e82f66ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c411  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c413  7404                   -je 0x44c419
    if (cpu.flags.zf)
    {
        goto L_0x0044c419;
    }
    // 0044c415  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c419:
    // 0044c419  ba60915300             -mov edx, 0x539160
    cpu.edx = 5476704 /*0x539160*/;
    // 0044c41e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c420  e81b66ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c425  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c427  7404                   -je 0x44c42d
    if (cpu.flags.zf)
    {
        goto L_0x0044c42d;
    }
    // 0044c429  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c42d:
    // 0044c42d  ba74915300             -mov edx, 0x539174
    cpu.edx = 5476724 /*0x539174*/;
    // 0044c432  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c434  e80766ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c439  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c43b  7404                   -je 0x44c441
    if (cpu.flags.zf)
    {
        goto L_0x0044c441;
    }
    // 0044c43d  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c441:
    // 0044c441  ba88915300             -mov edx, 0x539188
    cpu.edx = 5476744 /*0x539188*/;
    // 0044c446  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c448  e8f365ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c44d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c44f  7404                   -je 0x44c455
    if (cpu.flags.zf)
    {
        goto L_0x0044c455;
    }
    // 0044c451  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c455:
    // 0044c455  ba9c915300             -mov edx, 0x53919c
    cpu.edx = 5476764 /*0x53919c*/;
    // 0044c45a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c45c  e8df65ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c461  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c463  7404                   -je 0x44c469
    if (cpu.flags.zf)
    {
        goto L_0x0044c469;
    }
    // 0044c465  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c469:
    // 0044c469  baac915300             -mov edx, 0x5391ac
    cpu.edx = 5476780 /*0x5391ac*/;
    // 0044c46e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c470  e8cb65ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c475  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c477  7404                   -je 0x44c47d
    if (cpu.flags.zf)
    {
        goto L_0x0044c47d;
    }
    // 0044c479  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c47d:
    // 0044c47d  bab8915300             -mov edx, 0x5391b8
    cpu.edx = 5476792 /*0x5391b8*/;
    // 0044c482  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c484  e8b765ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c489  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c48b  7404                   -je 0x44c491
    if (cpu.flags.zf)
    {
        goto L_0x0044c491;
    }
    // 0044c48d  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044c491:
    // 0044c491  bacc915300             -mov edx, 0x5391cc
    cpu.edx = 5476812 /*0x5391cc*/;
    // 0044c496  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c498  e8a365ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c49d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c49f  7404                   -je 0x44c4a5
    if (cpu.flags.zf)
    {
        goto L_0x0044c4a5;
    }
    // 0044c4a1  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044c4a5:
    // 0044c4a5  bae0915300             -mov edx, 0x5391e0
    cpu.edx = 5476832 /*0x5391e0*/;
    // 0044c4aa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c4ac  e88f65ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c4b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c4b3  7404                   -je 0x44c4b9
    if (cpu.flags.zf)
    {
        goto L_0x0044c4b9;
    }
    // 0044c4b5  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044c4b9:
    // 0044c4b9  baf8915300             -mov edx, 0x5391f8
    cpu.edx = 5476856 /*0x5391f8*/;
    // 0044c4be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c4c0  e87b65ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c4c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c4c7  7404                   -je 0x44c4cd
    if (cpu.flags.zf)
    {
        goto L_0x0044c4cd;
    }
    // 0044c4c9  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044c4cd:
    // 0044c4cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c4ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c4cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c4d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_44c4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044c4e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044c4e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044c4e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044c4e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044c4e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044c4e7  ba0c925300             -mov edx, 0x53920c
    cpu.edx = 5476876 /*0x53920c*/;
    // 0044c4ec  e84f65ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c4f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c4f3  7404                   -je 0x44c4f9
    if (cpu.flags.zf)
    {
        goto L_0x0044c4f9;
    }
    // 0044c4f5  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c4f9:
    // 0044c4f9  ba1c925300             -mov edx, 0x53921c
    cpu.edx = 5476892 /*0x53921c*/;
    // 0044c4fe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c500  e83b65ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c505  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c507  7404                   -je 0x44c50d
    if (cpu.flags.zf)
    {
        goto L_0x0044c50d;
    }
    // 0044c509  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c50d:
    // 0044c50d  ba2c925300             -mov edx, 0x53922c
    cpu.edx = 5476908 /*0x53922c*/;
    // 0044c512  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c514  e82765ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c519  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c51b  7404                   -je 0x44c521
    if (cpu.flags.zf)
    {
        goto L_0x0044c521;
    }
    // 0044c51d  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c521:
    // 0044c521  ba3c925300             -mov edx, 0x53923c
    cpu.edx = 5476924 /*0x53923c*/;
    // 0044c526  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c528  e81365ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c52d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c52f  7404                   -je 0x44c535
    if (cpu.flags.zf)
    {
        goto L_0x0044c535;
    }
    // 0044c531  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c535:
    // 0044c535  ba4c925300             -mov edx, 0x53924c
    cpu.edx = 5476940 /*0x53924c*/;
    // 0044c53a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c53c  e8ff64ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c541  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c543  7404                   -je 0x44c549
    if (cpu.flags.zf)
    {
        goto L_0x0044c549;
    }
    // 0044c545  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c549:
    // 0044c549  ba5c925300             -mov edx, 0x53925c
    cpu.edx = 5476956 /*0x53925c*/;
    // 0044c54e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c550  e8eb64ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c555  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c557  7404                   -je 0x44c55d
    if (cpu.flags.zf)
    {
        goto L_0x0044c55d;
    }
    // 0044c559  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c55d:
    // 0044c55d  bab8915300             -mov edx, 0x5391b8
    cpu.edx = 5476792 /*0x5391b8*/;
    // 0044c562  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c564  e8d764ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c569  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c56b  7404                   -je 0x44c571
    if (cpu.flags.zf)
    {
        goto L_0x0044c571;
    }
    // 0044c56d  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c571:
    // 0044c571  bacc915300             -mov edx, 0x5391cc
    cpu.edx = 5476812 /*0x5391cc*/;
    // 0044c576  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c578  e8c364ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c57d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c57f  7404                   -je 0x44c585
    if (cpu.flags.zf)
    {
        goto L_0x0044c585;
    }
    // 0044c581  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c585:
    // 0044c585  bae0915300             -mov edx, 0x5391e0
    cpu.edx = 5476832 /*0x5391e0*/;
    // 0044c58a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c58c  e8af64ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c591  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c593  7404                   -je 0x44c599
    if (cpu.flags.zf)
    {
        goto L_0x0044c599;
    }
    // 0044c595  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c599:
    // 0044c599  baf8915300             -mov edx, 0x5391f8
    cpu.edx = 5476856 /*0x5391f8*/;
    // 0044c59e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c5a0  e89b64ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c5a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c5a7  7404                   -je 0x44c5ad
    if (cpu.flags.zf)
    {
        goto L_0x0044c5ad;
    }
    // 0044c5a9  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c5ad:
    // 0044c5ad  ba68925300             -mov edx, 0x539268
    cpu.edx = 5476968 /*0x539268*/;
    // 0044c5b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c5b4  e88764ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c5b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c5bb  7404                   -je 0x44c5c1
    if (cpu.flags.zf)
    {
        goto L_0x0044c5c1;
    }
    // 0044c5bd  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c5c1:
    // 0044c5c1  ba80925300             -mov edx, 0x539280
    cpu.edx = 5476992 /*0x539280*/;
    // 0044c5c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c5c8  e87364ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c5cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c5cf  7404                   -je 0x44c5d5
    if (cpu.flags.zf)
    {
        goto L_0x0044c5d5;
    }
    // 0044c5d1  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c5d5:
    // 0044c5d5  ba94925300             -mov edx, 0x539294
    cpu.edx = 5477012 /*0x539294*/;
    // 0044c5da  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c5dc  e85f64ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c5e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c5e3  7404                   -je 0x44c5e9
    if (cpu.flags.zf)
    {
        goto L_0x0044c5e9;
    }
    // 0044c5e5  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c5e9:
    // 0044c5e9  baa4925300             -mov edx, 0x5392a4
    cpu.edx = 5477028 /*0x5392a4*/;
    // 0044c5ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044c5f0  e84b64ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044c5f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c5f7  7404                   -je 0x44c5fd
    if (cpu.flags.zf)
    {
        goto L_0x0044c5fd;
    }
    // 0044c5f9  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044c5fd:
    // 0044c5fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c5fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c5ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c600  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_44c610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044c610  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044c611  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044c612  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044c614  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044c616  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044c618  83f901                 +cmp ecx, 1
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
    // 0044c61b  724b                   -jb 0x44c668
    if (cpu.flags.cf)
    {
        goto L_0x0044c668;
    }
    // 0044c61d  7608                   -jbe 0x44c627
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044c627;
    }
    // 0044c61f  83f903                 +cmp ecx, 3
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
    // 0044c622  7438                   -je 0x44c65c
    if (cpu.flags.zf)
    {
        goto L_0x0044c65c;
    }
    // 0044c624  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c625  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c626  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044c627:
    // 0044c627  e89480ffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0044c62c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c62e  750f                   -jne 0x44c63f
    if (!cpu.flags.zf)
    {
        goto L_0x0044c63f;
    }
    // 0044c630  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044c632  7403                   -je 0x44c637
    if (cpu.flags.zf)
    {
        goto L_0x0044c637;
    }
    // 0044c634  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0044c637:
    // 0044c637  a168925500             -mov eax, dword ptr [0x559268]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608040) /* 0x559268 */);
    // 0044c63c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c63d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c63e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044c63f:
    // 0044c63f  83f801                 +cmp eax, 1
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
    // 0044c642  7509                   -jne 0x44c64d
    if (!cpu.flags.zf)
    {
        goto L_0x0044c64d;
    }
    // 0044c644  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044c646  740c                   -je 0x44c654
    if (cpu.flags.zf)
    {
        goto L_0x0044c654;
    }
    // 0044c648  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0044c64b  eb07                   -jmp 0x44c654
    goto L_0x0044c654;
L_0x0044c64d:
    // 0044c64d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044c64f  7403                   -je 0x44c654
    if (cpu.flags.zf)
    {
        goto L_0x0044c654;
    }
    // 0044c651  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x0044c654:
    // 0044c654  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044c659  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c65a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c65b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044c65c:
    // 0044c65c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044c65e  7403                   -je 0x44c663
    if (cpu.flags.zf)
    {
        goto L_0x0044c663;
    }
    // 0044c660  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0044c663:
    // 0044c663  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0044c668:
    // 0044c668  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c669  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c66a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44c670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044c670  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044c671  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044c672  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044c674  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044c676  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044c678  83f901                 +cmp ecx, 1
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
    // 0044c67b  724b                   -jb 0x44c6c8
    if (cpu.flags.cf)
    {
        goto L_0x0044c6c8;
    }
    // 0044c67d  7608                   -jbe 0x44c687
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044c687;
    }
    // 0044c67f  83f903                 +cmp ecx, 3
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
    // 0044c682  7438                   -je 0x44c6bc
    if (cpu.flags.zf)
    {
        goto L_0x0044c6bc;
    }
    // 0044c684  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c685  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c686  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044c687:
    // 0044c687  e83480ffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0044c68c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c68e  750f                   -jne 0x44c69f
    if (!cpu.flags.zf)
    {
        goto L_0x0044c69f;
    }
    // 0044c690  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044c692  7403                   -je 0x44c697
    if (cpu.flags.zf)
    {
        goto L_0x0044c697;
    }
    // 0044c694  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0044c697:
    // 0044c697  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0044c69c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c69d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c69e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044c69f:
    // 0044c69f  83f801                 +cmp eax, 1
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
    // 0044c6a2  7509                   -jne 0x44c6ad
    if (!cpu.flags.zf)
    {
        goto L_0x0044c6ad;
    }
    // 0044c6a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044c6a6  740c                   -je 0x44c6b4
    if (cpu.flags.zf)
    {
        goto L_0x0044c6b4;
    }
    // 0044c6a8  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0044c6ab  eb07                   -jmp 0x44c6b4
    goto L_0x0044c6b4;
L_0x0044c6ad:
    // 0044c6ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044c6af  7403                   -je 0x44c6b4
    if (cpu.flags.zf)
    {
        goto L_0x0044c6b4;
    }
    // 0044c6b1  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x0044c6b4:
    // 0044c6b4  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044c6b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c6ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c6bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044c6bc:
    // 0044c6bc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044c6be  7403                   -je 0x44c6c3
    if (cpu.flags.zf)
    {
        goto L_0x0044c6c3;
    }
    // 0044c6c0  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0044c6c3:
    // 0044c6c3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0044c6c8:
    // 0044c6c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c6c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c6ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44c6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044c6d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044c6d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044c6d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044c6d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044c6d5  891568925500           -mov dword ptr [0x559268], edx
    app->getMemory<x86::reg32>(x86::reg32(5608040) /* 0x559268 */) = cpu.edx;
    // 0044c6db  e870510800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c6e0  a310446600             -mov dword ptr [0x664410], eax
    app->getMemory<x86::reg32>(x86::reg32(6702096) /* 0x664410 */) = cpu.eax;
    // 0044c6e5  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 0044c6ea  e861510800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c6ef  a314446600             -mov dword ptr [0x664414], eax
    app->getMemory<x86::reg32>(x86::reg32(6702100) /* 0x664414 */) = cpu.eax;
    // 0044c6f4  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 0044c6f9  e852510800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c6fe  6810c64400             -push 0x44c610
    app->getMemory<x86::reg32>(cpu.esp-4) = 4507152 /*0x44c610*/;
    cpu.esp -= 4;
    // 0044c703  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044c705  b914446600             -mov ecx, 0x664414
    cpu.ecx = 6702100 /*0x664414*/;
    // 0044c70a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0044c70c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0044c711  ba10446600             -mov edx, 0x664410
    cpu.edx = 6702096 /*0x664410*/;
    // 0044c716  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044c718  a318446600             -mov dword ptr [0x664418], eax
    app->getMemory<x86::reg32>(x86::reg32(6702104) /* 0x664418 */) = cpu.eax;
    // 0044c71d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044c722  e8a97fffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0044c727  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c728  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c729  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c72a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44c730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044c730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044c731  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044c732  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044c734  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0044c736  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044c738  83f801                 +cmp eax, 1
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
    // 0044c73b  0f825d000000           -jb 0x44c79e
    if (cpu.flags.cf)
    {
        goto L_0x0044c79e;
    }
    // 0044c741  760a                   -jbe 0x44c74d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044c74d;
    }
    // 0044c743  83f803                 +cmp eax, 3
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
    // 0044c746  744a                   -je 0x44c792
    if (cpu.flags.zf)
    {
        goto L_0x0044c792;
    }
    // 0044c748  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044c74a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c74b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c74c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044c74d:
    // 0044c74d  e86e7fffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0044c752  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c754  7c2b                   -jl 0x44c781
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044c781;
    }
    // 0044c756  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044c759  8b90882c6600           -mov edx, dword ptr [eax + 0x662c88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6696072) /* 0x662c88 */);
    // 0044c75f  83fa02                 +cmp edx, 2
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
    // 0044c762  7509                   -jne 0x44c76d
    if (!cpu.flags.zf)
    {
        goto L_0x0044c76d;
    }
    // 0044c764  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044c766  7431                   -je 0x44c799
    if (cpu.flags.zf)
    {
        goto L_0x0044c799;
    }
    // 0044c768  c60101                 -mov byte ptr [ecx], 1
    app->getMemory<x86::reg8>(cpu.ecx) = 1 /*0x1*/;
    // 0044c76b  eb2c                   -jmp 0x44c799
    goto L_0x0044c799;
L_0x0044c76d:
    // 0044c76d  8b80702c6600           -mov eax, dword ptr [eax + 0x662c70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6696048) /* 0x662c70 */);
    // 0044c773  e858ffffff             -call 0x44c6d0
    cpu.esp -= 4;
    sub_44c6d0(app, cpu);
    if (cpu.terminate) return;
    // 0044c778  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044c77a  740c                   -je 0x44c788
    if (cpu.flags.zf)
    {
        goto L_0x0044c788;
    }
    // 0044c77c  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 0044c77f  eb07                   -jmp 0x44c788
    goto L_0x0044c788;
L_0x0044c781:
    // 0044c781  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044c783  7403                   -je 0x44c788
    if (cpu.flags.zf)
    {
        goto L_0x0044c788;
    }
    // 0044c785  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x0044c788:
    // 0044c788  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0044c78d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044c78f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c790  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c791  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044c792:
    // 0044c792  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044c794  7403                   -je 0x44c799
    if (cpu.flags.zf)
    {
        goto L_0x0044c799;
    }
    // 0044c796  c60101                 -mov byte ptr [ecx], 1
    app->getMemory<x86::reg8>(cpu.ecx) = 1 /*0x1*/;
L_0x0044c799:
    // 0044c799  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x0044c79e:
    // 0044c79e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044c7a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c7a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c7a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44c7b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044c7b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044c7b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044c7b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044c7b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044c7b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044c7b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044c7b6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044c7b8  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044c7bf  7e11                   -jle 0x44c7d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044c7d2;
    }
    // 0044c7c1  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044c7c9  7507                   -jne 0x44c7d2
    if (!cpu.flags.zf)
    {
        goto L_0x0044c7d2;
    }
    // 0044c7cb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c7d0  eb02                   -jmp 0x44c7d4
    goto L_0x0044c7d4;
L_0x0044c7d2:
    // 0044c7d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044c7d4:
    // 0044c7d4  8b1da0d36f00           -mov ebx, dword ptr [0x6fd3a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328672) /* 0x6fd3a0 */);
    // 0044c7da  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0044c7dc  83fb02                 +cmp ebx, 2
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
    // 0044c7df  7c07                   -jl 0x44c7e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044c7e8;
    }
    // 0044c7e1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044c7e6  eb02                   -jmp 0x44c7ea
    goto L_0x0044c7ea;
L_0x0044c7e8:
    // 0044c7e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044c7ea:
    // 0044c7ea  b8db010000             -mov eax, 0x1db
    cpu.eax = 475 /*0x1db*/;
    // 0044c7ef  e85c500800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c7f4  a31c446600             -mov dword ptr [0x66441c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702108) /* 0x66441c */) = cpu.eax;
    // 0044c7f9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044c7fb  0f84a2000000           -je 0x44c8a3
    if (cpu.flags.zf)
    {
        goto L_0x0044c8a3;
    }
    // 0044c801  a1b4367d00             -mov eax, dword ptr [0x7d36b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8206004) /* 0x7d36b4 */);
    // 0044c806  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044c808  7507                   -jne 0x44c811
    if (!cpu.flags.zf)
    {
        goto L_0x0044c811;
    }
    // 0044c80a  b8dc010000             -mov eax, 0x1dc
    cpu.eax = 476 /*0x1dc*/;
    // 0044c80f  eb05                   -jmp 0x44c816
    goto L_0x0044c816;
L_0x0044c811:
    // 0044c811  b8dd010000             -mov eax, 0x1dd
    cpu.eax = 477 /*0x1dd*/;
L_0x0044c816:
    // 0044c816  e835500800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c81b  a320446600             -mov dword ptr [0x664420], eax
    app->getMemory<x86::reg32>(x86::reg32(6702112) /* 0x664420 */) = cpu.eax;
    // 0044c820  b8ef010000             -mov eax, 0x1ef
    cpu.eax = 495 /*0x1ef*/;
    // 0044c825  be0c000000             -mov esi, 0xc
    cpu.esi = 12 /*0xc*/;
    // 0044c82a  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 0044c82f  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0044c834  b9fc000000             -mov ecx, 0xfc
    cpu.ecx = 252 /*0xfc*/;
    // 0044c839  e812500800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c83e  a324446600             -mov dword ptr [0x664424], eax
    app->getMemory<x86::reg32>(x86::reg32(6702116) /* 0x664424 */) = cpu.eax;
    // 0044c843  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0044c848  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0044c84d  e8fe4f0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c852  6830c74400             -push 0x44c730
    app->getMemory<x86::reg32>(cpu.esp-4) = 4507440 /*0x44c730*/;
    cpu.esp -= 4;
    // 0044c857  a328446600             -mov dword ptr [0x664428], eax
    app->getMemory<x86::reg32>(x86::reg32(6702120) /* 0x664428 */) = cpu.eax;
    // 0044c85c  8935882c6600           -mov dword ptr [0x662c88], esi
    app->getMemory<x86::reg32>(x86::reg32(6696072) /* 0x662c88 */) = cpu.esi;
    // 0044c862  8915702c6600           -mov dword ptr [0x662c70], edx
    app->getMemory<x86::reg32>(x86::reg32(6696048) /* 0x662c70 */) = cpu.edx;
    // 0044c868  890d742c6600           -mov dword ptr [0x662c74], ecx
    app->getMemory<x86::reg32>(x86::reg32(6696052) /* 0x662c74 */) = cpu.ecx;
    // 0044c86e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0044c870  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044c875  b920446600             -mov ecx, 0x664420
    cpu.ecx = 6702112 /*0x664420*/;
    // 0044c87a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044c87b  ba1c446600             -mov edx, 0x66441c
    cpu.edx = 6702108 /*0x66441c*/;
    // 0044c880  a3902c6600             -mov dword ptr [0x662c90], eax
    app->getMemory<x86::reg32>(x86::reg32(6696080) /* 0x662c90 */) = cpu.eax;
    // 0044c885  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044c887  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044c88c  893d8c2c6600           -mov dword ptr [0x662c8c], edi
    app->getMemory<x86::reg32>(x86::reg32(6696076) /* 0x662c8c */) = cpu.edi;
    // 0044c892  e8397effff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0044c897  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044c89c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c89d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c89e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c89f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c8a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c8a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c8a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044c8a3:
    // 0044c8a3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044c8a5  0f8492000000           -je 0x44c93d
    if (cpu.flags.zf)
    {
        goto L_0x0044c93d;
    }
    // 0044c8ab  b8df010000             -mov eax, 0x1df
    cpu.eax = 479 /*0x1df*/;
    // 0044c8b0  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 0044c8b5  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 0044c8ba  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 0044c8bf  e88c4f0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c8c4  a320446600             -mov dword ptr [0x664420], eax
    app->getMemory<x86::reg32>(x86::reg32(6702112) /* 0x664420 */) = cpu.eax;
    // 0044c8c9  b8ef010000             -mov eax, 0x1ef
    cpu.eax = 495 /*0x1ef*/;
    // 0044c8ce  bafc000000             -mov edx, 0xfc
    cpu.edx = 252 /*0xfc*/;
    // 0044c8d3  e8784f0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c8d8  a324446600             -mov dword ptr [0x664424], eax
    app->getMemory<x86::reg32>(x86::reg32(6702116) /* 0x664424 */) = cpu.eax;
    // 0044c8dd  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0044c8e2  b920446600             -mov ecx, 0x664420
    cpu.ecx = 6702112 /*0x664420*/;
    // 0044c8e7  e8644f0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c8ec  6830c74400             -push 0x44c730
    app->getMemory<x86::reg32>(cpu.esp-4) = 4507440 /*0x44c730*/;
    cpu.esp -= 4;
    // 0044c8f1  a328446600             -mov dword ptr [0x664428], eax
    app->getMemory<x86::reg32>(x86::reg32(6702120) /* 0x664428 */) = cpu.eax;
    // 0044c8f6  891d882c6600           -mov dword ptr [0x662c88], ebx
    app->getMemory<x86::reg32>(x86::reg32(6696072) /* 0x662c88 */) = cpu.ebx;
    // 0044c8fc  89358c2c6600           -mov dword ptr [0x662c8c], esi
    app->getMemory<x86::reg32>(x86::reg32(6696076) /* 0x662c8c */) = cpu.esi;
    // 0044c902  8915742c6600           -mov dword ptr [0x662c74], edx
    app->getMemory<x86::reg32>(x86::reg32(6696052) /* 0x662c74 */) = cpu.edx;
    // 0044c908  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0044c90a  b801010000             -mov eax, 0x101
    cpu.eax = 257 /*0x101*/;
    // 0044c90f  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0044c914  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044c915  ba1c446600             -mov edx, 0x66441c
    cpu.edx = 6702108 /*0x66441c*/;
    // 0044c91a  a3702c6600             -mov dword ptr [0x662c70], eax
    app->getMemory<x86::reg32>(x86::reg32(6696048) /* 0x662c70 */) = cpu.eax;
    // 0044c91f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044c921  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044c926  893d902c6600           -mov dword ptr [0x662c90], edi
    app->getMemory<x86::reg32>(x86::reg32(6696080) /* 0x662c90 */) = cpu.edi;
    // 0044c92c  e89f7dffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0044c931  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044c936  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c937  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c938  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c939  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c93a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c93b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044c93c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044c93d:
    // 0044c93d  bafd000000             -mov edx, 0xfd
    cpu.edx = 253 /*0xfd*/;
    // 0044c942  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044c947  83f801                 +cmp eax, 1
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
    // 0044c94a  7213                   -jb 0x44c95f
    if (cpu.flags.cf)
    {
        goto L_0x0044c95f;
    }
    // 0044c94c  760c                   -jbe 0x44c95a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044c95a;
    }
    // 0044c94e  83f802                 +cmp eax, 2
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
    // 0044c951  750c                   -jne 0x44c95f
    if (!cpu.flags.zf)
    {
        goto L_0x0044c95f;
    }
    // 0044c953  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0044c958  eb05                   -jmp 0x44c95f
    goto L_0x0044c95f;
L_0x0044c95a:
    // 0044c95a  bafe000000             -mov edx, 0xfe
    cpu.edx = 254 /*0xfe*/;
L_0x0044c95f:
    // 0044c95f  b8dd010000             -mov eax, 0x1dd
    cpu.eax = 477 /*0x1dd*/;
    // 0044c964  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 0044c969  e8e24e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c96e  a320446600             -mov dword ptr [0x664420], eax
    app->getMemory<x86::reg32>(x86::reg32(6702112) /* 0x664420 */) = cpu.eax;
    // 0044c973  b8dc010000             -mov eax, 0x1dc
    cpu.eax = 476 /*0x1dc*/;
    // 0044c978  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 0044c97d  e8ce4e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c982  a324446600             -mov dword ptr [0x664424], eax
    app->getMemory<x86::reg32>(x86::reg32(6702116) /* 0x664424 */) = cpu.eax;
    // 0044c987  b8ef010000             -mov eax, 0x1ef
    cpu.eax = 495 /*0x1ef*/;
    // 0044c98c  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 0044c991  e8ba4e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c996  a328446600             -mov dword ptr [0x664428], eax
    app->getMemory<x86::reg32>(x86::reg32(6702120) /* 0x664428 */) = cpu.eax;
    // 0044c99b  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0044c9a0  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 0044c9a5  e8a64e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044c9aa  6830c74400             -push 0x44c730
    app->getMemory<x86::reg32>(cpu.esp-4) = 4507440 /*0x44c730*/;
    cpu.esp -= 4;
    // 0044c9af  a32c446600             -mov dword ptr [0x66442c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702124) /* 0x66442c */) = cpu.eax;
    // 0044c9b4  890d882c6600           -mov dword ptr [0x662c88], ecx
    app->getMemory<x86::reg32>(x86::reg32(6696072) /* 0x662c88 */) = cpu.ecx;
    // 0044c9ba  891d8c2c6600           -mov dword ptr [0x662c8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(6696076) /* 0x662c8c */) = cpu.ebx;
    // 0044c9c0  8935902c6600           -mov dword ptr [0x662c90], esi
    app->getMemory<x86::reg32>(x86::reg32(6696080) /* 0x662c90 */) = cpu.esi;
    // 0044c9c6  8915702c6600           -mov dword ptr [0x662c70], edx
    app->getMemory<x86::reg32>(x86::reg32(6696048) /* 0x662c70 */) = cpu.edx;
    // 0044c9cc  8915742c6600           -mov dword ptr [0x662c74], edx
    app->getMemory<x86::reg32>(x86::reg32(6696052) /* 0x662c74 */) = cpu.edx;
    // 0044c9d2  b8fc000000             -mov eax, 0xfc
    cpu.eax = 252 /*0xfc*/;
    // 0044c9d7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0044c9d9  b920446600             -mov ecx, 0x664420
    cpu.ecx = 6702112 /*0x664420*/;
    // 0044c9de  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0044c9e3  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0044c9e5  ba1c446600             -mov edx, 0x66441c
    cpu.edx = 6702108 /*0x66441c*/;
    // 0044c9ea  a3782c6600             -mov dword ptr [0x662c78], eax
    app->getMemory<x86::reg32>(x86::reg32(6696056) /* 0x662c78 */) = cpu.eax;
    // 0044c9ef  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044c9f1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044c9f6  893d942c6600           -mov dword ptr [0x662c94], edi
    app->getMemory<x86::reg32>(x86::reg32(6696084) /* 0x662c94 */) = cpu.edi;
    // 0044c9fc  e8cf7cffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0044ca01  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044ca06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ca07  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ca08  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ca09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ca0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ca0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ca0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_44ca10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044ca10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044ca11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044ca12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044ca13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044ca14  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044ca16  b8ea010000             -mov eax, 0x1ea
    cpu.eax = 490 /*0x1ea*/;
    // 0044ca1b  e8304e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044ca20  a334446600             -mov dword ptr [0x664434], eax
    app->getMemory<x86::reg32>(x86::reg32(6702132) /* 0x664434 */) = cpu.eax;
    // 0044ca25  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 0044ca2a  e8214e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044ca2f  a338446600             -mov dword ptr [0x664438], eax
    app->getMemory<x86::reg32>(x86::reg32(6702136) /* 0x664438 */) = cpu.eax;
    // 0044ca34  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 0044ca39  e8124e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044ca3e  6870c64400             -push 0x44c670
    app->getMemory<x86::reg32>(cpu.esp-4) = 4507248 /*0x44c670*/;
    cpu.esp -= 4;
    // 0044ca43  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044ca45  b938446600             -mov ecx, 0x664438
    cpu.ecx = 6702136 /*0x664438*/;
    // 0044ca4a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044ca4c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0044ca51  ba34446600             -mov edx, 0x664434
    cpu.edx = 6702132 /*0x664434*/;
    // 0044ca56  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044ca58  a33c446600             -mov dword ptr [0x66443c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702140) /* 0x66443c */) = cpu.eax;
    // 0044ca5d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044ca62  e8697cffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0044ca67  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044ca6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ca6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ca6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ca6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ca70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_44ca80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044ca80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044ca81  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044ca83  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044ca88  83f801                 +cmp eax, 1
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
    // 0044ca8b  7217                   -jb 0x44caa4
    if (cpu.flags.cf)
    {
        goto L_0x0044caa4;
    }
    // 0044ca8d  7607                   -jbe 0x44ca96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044ca96;
    }
    // 0044ca8f  83f802                 +cmp eax, 2
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
    // 0044ca92  7409                   -je 0x44ca9d
    if (cpu.flags.zf)
    {
        goto L_0x0044ca9d;
    }
    // 0044ca94  eb0e                   -jmp 0x44caa4
    goto L_0x0044caa4;
L_0x0044ca96:
    // 0044ca96  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044ca9b  eb02                   -jmp 0x44ca9f
    goto L_0x0044ca9f;
L_0x0044ca9d:
    // 0044ca9d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044ca9f:
    // 0044ca9f  e88cafffff             -call 0x447a30
    cpu.esp -= 4;
    sub_447a30(app, cpu);
    if (cpu.terminate) return;
L_0x0044caa4:
    // 0044caa4  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044caa9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044caaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44cab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044cab0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044cab1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044cab2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044cab3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044cab4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044cab5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044cab6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044cab8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044cabb  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0044cabe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044cac0  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0044cac5  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0044cac8  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0044cacb  e8604a0000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
    // 0044cad0  bab4925300             -mov edx, 0x5392b4
    cpu.edx = 5477044 /*0x5392b4*/;
    // 0044cad5  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044cad8  e8635fffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044cadd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044cadf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044cae1  7462                   -je 0x44cb45
    if (cpu.flags.zf)
    {
        goto L_0x0044cb45;
    }
    // 0044cae3  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044caea  7406                   -je 0x44caf2
    if (cpu.flags.zf)
    {
        goto L_0x0044caf2;
    }
    // 0044caec  66c740080401           -mov word ptr [eax + 8], 0x104
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 260 /*0x104*/;
L_0x0044caf2:
    // 0044caf2  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044caf9  7f44                   -jg 0x44cb3f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0044cb3f;
    }
    // 0044cafb  833da0d36f0000         +cmp dword ptr [0x6fd3a0], 0
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
    // 0044cb02  753b                   -jne 0x44cb3f
    if (!cpu.flags.zf)
    {
        goto L_0x0044cb3f;
    }
    // 0044cb04  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044cb09  83f801                 +cmp eax, 1
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
    // 0044cb0c  7516                   -jne 0x44cb24
    if (!cpu.flags.zf)
    {
        goto L_0x0044cb24;
    }
    // 0044cb0e  b890040000             -mov eax, 0x490
    cpu.eax = 1168 /*0x490*/;
    // 0044cb13  e8384d0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cb18  c7426480ca4400         -mov dword ptr [edx + 0x64], 0x44ca80
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */) = 4508288 /*0x44ca80*/;
    // 0044cb1f  89423c                 -mov dword ptr [edx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0044cb22  eb21                   -jmp 0x44cb45
    goto L_0x0044cb45;
L_0x0044cb24:
    // 0044cb24  83f802                 +cmp eax, 2
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
    // 0044cb27  7516                   -jne 0x44cb3f
    if (!cpu.flags.zf)
    {
        goto L_0x0044cb3f;
    }
    // 0044cb29  b891040000             -mov eax, 0x491
    cpu.eax = 1169 /*0x491*/;
    // 0044cb2e  e81d4d0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cb33  c7426480ca4400         -mov dword ptr [edx + 0x64], 0x44ca80
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */) = 4508288 /*0x44ca80*/;
    // 0044cb3a  89423c                 -mov dword ptr [edx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0044cb3d  eb06                   -jmp 0x44cb45
    goto L_0x0044cb45;
L_0x0044cb3f:
    // 0044cb3f  66814a040110           -or word ptr [edx + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x0044cb45:
    // 0044cb45  bac0925300             -mov edx, 0x5392c0
    cpu.edx = 5477056 /*0x5392c0*/;
    // 0044cb4a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044cb4d  e8ee5effff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044cb52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044cb54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044cb56  0f846c020000           -je 0x44cdc8
    if (cpu.flags.zf)
    {
        goto L_0x0044cdc8;
    }
    // 0044cb5c  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044cb62  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044cb64  0f8585000000           -jne 0x44cbef
    if (!cpu.flags.zf)
    {
        goto L_0x0044cbef;
    }
    // 0044cb6a  b8d5000000             -mov eax, 0xd5
    cpu.eax = 213 /*0xd5*/;
    // 0044cb6f  bf6c925500             -mov edi, 0x55926c
    cpu.edi = 5608044 /*0x55926c*/;
    // 0044cb74  e8d74c0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cb79  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044cb7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044cb7c:
    // 0044cb7c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cb7e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cb80  3c00                   +cmp al, 0
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
    // 0044cb82  7410                   -je 0x44cb94
    if (cpu.flags.zf)
    {
        goto L_0x0044cb94;
    }
    // 0044cb84  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cb87  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cb8a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cb8d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cb90  3c00                   +cmp al, 0
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
    // 0044cb92  75e8                   -jne 0x44cb7c
    if (!cpu.flags.zf)
    {
        goto L_0x0044cb7c;
    }
L_0x0044cb94:
    // 0044cb94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cb95  bec8925300             -mov esi, 0x5392c8
    cpu.esi = 5477064 /*0x5392c8*/;
    // 0044cb9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044cb9b  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044cb9d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044cb9e  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0044cba0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044cba2  4f                     -dec edi
    (cpu.edi)--;
L_0x0044cba3:
    // 0044cba3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cba5  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cba7  3c00                   +cmp al, 0
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
    // 0044cba9  7410                   -je 0x44cbbb
    if (cpu.flags.zf)
    {
        goto L_0x0044cbbb;
    }
    // 0044cbab  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cbae  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cbb1  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cbb4  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cbb7  3c00                   +cmp al, 0
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
    // 0044cbb9  75e8                   -jne 0x44cba3
    if (!cpu.flags.zf)
    {
        goto L_0x0044cba3;
    }
L_0x0044cbbb:
    // 0044cbbb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cbbc  b8ba010000             -mov eax, 0x1ba
    cpu.eax = 442 /*0x1ba*/;
    // 0044cbc1  e88a4c0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cbc6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044cbc8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044cbc9  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044cbcb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044cbcc  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0044cbce  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044cbd0  4f                     -dec edi
    (cpu.edi)--;
L_0x0044cbd1:
    // 0044cbd1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cbd3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cbd5  3c00                   +cmp al, 0
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
    // 0044cbd7  7410                   -je 0x44cbe9
    if (cpu.flags.zf)
    {
        goto L_0x0044cbe9;
    }
    // 0044cbd9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cbdc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cbdf  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cbe2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cbe5  3c00                   +cmp al, 0
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
    // 0044cbe7  75e8                   -jne 0x44cbd1
    if (!cpu.flags.zf)
    {
        goto L_0x0044cbd1;
    }
L_0x0044cbe9:
    // 0044cbe9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cbea  e9d2010000             -jmp 0x44cdc1
    goto L_0x0044cdc1;
L_0x0044cbef:
    // 0044cbef  83fb01                 +cmp ebx, 1
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
    // 0044cbf2  0f8585000000           -jne 0x44cc7d
    if (!cpu.flags.zf)
    {
        goto L_0x0044cc7d;
    }
    // 0044cbf8  b8d6000000             -mov eax, 0xd6
    cpu.eax = 214 /*0xd6*/;
    // 0044cbfd  bf6c925500             -mov edi, 0x55926c
    cpu.edi = 5608044 /*0x55926c*/;
    // 0044cc02  e8494c0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cc07  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044cc09  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044cc0a:
    // 0044cc0a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cc0c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cc0e  3c00                   +cmp al, 0
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
    // 0044cc10  7410                   -je 0x44cc22
    if (cpu.flags.zf)
    {
        goto L_0x0044cc22;
    }
    // 0044cc12  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cc15  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cc18  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cc1b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cc1e  3c00                   +cmp al, 0
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
    // 0044cc20  75e8                   -jne 0x44cc0a
    if (!cpu.flags.zf)
    {
        goto L_0x0044cc0a;
    }
L_0x0044cc22:
    // 0044cc22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cc23  bec8925300             -mov esi, 0x5392c8
    cpu.esi = 5477064 /*0x5392c8*/;
    // 0044cc28  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044cc29  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044cc2b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044cc2c  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0044cc2e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044cc30  4f                     -dec edi
    (cpu.edi)--;
L_0x0044cc31:
    // 0044cc31  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cc33  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cc35  3c00                   +cmp al, 0
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
    // 0044cc37  7410                   -je 0x44cc49
    if (cpu.flags.zf)
    {
        goto L_0x0044cc49;
    }
    // 0044cc39  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cc3c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cc3f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cc42  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cc45  3c00                   +cmp al, 0
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
    // 0044cc47  75e8                   -jne 0x44cc31
    if (!cpu.flags.zf)
    {
        goto L_0x0044cc31;
    }
L_0x0044cc49:
    // 0044cc49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cc4a  b8ba010000             -mov eax, 0x1ba
    cpu.eax = 442 /*0x1ba*/;
    // 0044cc4f  e8fc4b0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cc54  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044cc56  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044cc57  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044cc59  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044cc5a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0044cc5c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044cc5e  4f                     -dec edi
    (cpu.edi)--;
L_0x0044cc5f:
    // 0044cc5f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cc61  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cc63  3c00                   +cmp al, 0
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
    // 0044cc65  7410                   -je 0x44cc77
    if (cpu.flags.zf)
    {
        goto L_0x0044cc77;
    }
    // 0044cc67  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cc6a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cc6d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cc70  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cc73  3c00                   +cmp al, 0
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
    // 0044cc75  75e8                   -jne 0x44cc5f
    if (!cpu.flags.zf)
    {
        goto L_0x0044cc5f;
    }
L_0x0044cc77:
    // 0044cc77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cc78  e944010000             -jmp 0x44cdc1
    goto L_0x0044cdc1;
L_0x0044cc7d:
    // 0044cc7d  83fb02                 +cmp ebx, 2
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
    // 0044cc80  0f8585000000           -jne 0x44cd0b
    if (!cpu.flags.zf)
    {
        goto L_0x0044cd0b;
    }
    // 0044cc86  b8d7000000             -mov eax, 0xd7
    cpu.eax = 215 /*0xd7*/;
    // 0044cc8b  bf6c925500             -mov edi, 0x55926c
    cpu.edi = 5608044 /*0x55926c*/;
    // 0044cc90  e8bb4b0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cc95  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044cc97  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044cc98:
    // 0044cc98  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cc9a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cc9c  3c00                   +cmp al, 0
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
    // 0044cc9e  7410                   -je 0x44ccb0
    if (cpu.flags.zf)
    {
        goto L_0x0044ccb0;
    }
    // 0044cca0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cca3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cca6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cca9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044ccac  3c00                   +cmp al, 0
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
    // 0044ccae  75e8                   -jne 0x44cc98
    if (!cpu.flags.zf)
    {
        goto L_0x0044cc98;
    }
L_0x0044ccb0:
    // 0044ccb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ccb1  bec8925300             -mov esi, 0x5392c8
    cpu.esi = 5477064 /*0x5392c8*/;
    // 0044ccb6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044ccb7  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044ccb9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044ccba  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0044ccbc  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044ccbe  4f                     -dec edi
    (cpu.edi)--;
L_0x0044ccbf:
    // 0044ccbf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044ccc1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044ccc3  3c00                   +cmp al, 0
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
    // 0044ccc5  7410                   -je 0x44ccd7
    if (cpu.flags.zf)
    {
        goto L_0x0044ccd7;
    }
    // 0044ccc7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044ccca  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cccd  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044ccd0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044ccd3  3c00                   +cmp al, 0
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
    // 0044ccd5  75e8                   -jne 0x44ccbf
    if (!cpu.flags.zf)
    {
        goto L_0x0044ccbf;
    }
L_0x0044ccd7:
    // 0044ccd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ccd8  b8ba010000             -mov eax, 0x1ba
    cpu.eax = 442 /*0x1ba*/;
    // 0044ccdd  e86e4b0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cce2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044cce4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044cce5  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044cce7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044cce8  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0044ccea  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044ccec  4f                     -dec edi
    (cpu.edi)--;
L_0x0044cced:
    // 0044cced  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044ccef  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044ccf1  3c00                   +cmp al, 0
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
    // 0044ccf3  7410                   -je 0x44cd05
    if (cpu.flags.zf)
    {
        goto L_0x0044cd05;
    }
    // 0044ccf5  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044ccf8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044ccfb  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044ccfe  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cd01  3c00                   +cmp al, 0
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
    // 0044cd03  75e8                   -jne 0x44cced
    if (!cpu.flags.zf)
    {
        goto L_0x0044cced;
    }
L_0x0044cd05:
    // 0044cd05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cd06  e9b6000000             -jmp 0x44cdc1
    goto L_0x0044cdc1;
L_0x0044cd0b:
    // 0044cd0b  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044cd0e  0f8582000000           -jne 0x44cd96
    if (!cpu.flags.zf)
    {
        goto L_0x0044cd96;
    }
    // 0044cd14  b8dc000000             -mov eax, 0xdc
    cpu.eax = 220 /*0xdc*/;
    // 0044cd19  bf6c925500             -mov edi, 0x55926c
    cpu.edi = 5608044 /*0x55926c*/;
    // 0044cd1e  e82d4b0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cd23  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044cd25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044cd26:
    // 0044cd26  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cd28  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cd2a  3c00                   +cmp al, 0
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
    // 0044cd2c  7410                   -je 0x44cd3e
    if (cpu.flags.zf)
    {
        goto L_0x0044cd3e;
    }
    // 0044cd2e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cd31  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cd34  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cd37  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cd3a  3c00                   +cmp al, 0
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
    // 0044cd3c  75e8                   -jne 0x44cd26
    if (!cpu.flags.zf)
    {
        goto L_0x0044cd26;
    }
L_0x0044cd3e:
    // 0044cd3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cd3f  bec8925300             -mov esi, 0x5392c8
    cpu.esi = 5477064 /*0x5392c8*/;
    // 0044cd44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044cd45  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044cd47  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044cd48  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0044cd4a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044cd4c  4f                     -dec edi
    (cpu.edi)--;
L_0x0044cd4d:
    // 0044cd4d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cd4f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cd51  3c00                   +cmp al, 0
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
    // 0044cd53  7410                   -je 0x44cd65
    if (cpu.flags.zf)
    {
        goto L_0x0044cd65;
    }
    // 0044cd55  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cd58  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cd5b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cd5e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cd61  3c00                   +cmp al, 0
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
    // 0044cd63  75e8                   -jne 0x44cd4d
    if (!cpu.flags.zf)
    {
        goto L_0x0044cd4d;
    }
L_0x0044cd65:
    // 0044cd65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cd66  b8ba010000             -mov eax, 0x1ba
    cpu.eax = 442 /*0x1ba*/;
    // 0044cd6b  e8e04a0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cd70  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044cd72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044cd73  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044cd75  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044cd76  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0044cd78  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044cd7a  4f                     -dec edi
    (cpu.edi)--;
L_0x0044cd7b:
    // 0044cd7b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cd7d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cd7f  3c00                   +cmp al, 0
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
    // 0044cd81  7410                   -je 0x44cd93
    if (cpu.flags.zf)
    {
        goto L_0x0044cd93;
    }
    // 0044cd83  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cd86  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cd89  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cd8c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cd8f  3c00                   +cmp al, 0
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
    // 0044cd91  75e8                   -jne 0x44cd7b
    if (!cpu.flags.zf)
    {
        goto L_0x0044cd7b;
    }
L_0x0044cd93:
    // 0044cd93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cd94  eb2b                   -jmp 0x44cdc1
    goto L_0x0044cdc1;
L_0x0044cd96:
    // 0044cd96  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 0044cd9b  bf6c925500             -mov edi, 0x55926c
    cpu.edi = 5608044 /*0x55926c*/;
    // 0044cda0  e8ab4a0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044cda5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044cda7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044cda8:
    // 0044cda8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044cdaa  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044cdac  3c00                   +cmp al, 0
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
    // 0044cdae  7410                   -je 0x44cdc0
    if (cpu.flags.zf)
    {
        goto L_0x0044cdc0;
    }
    // 0044cdb0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044cdb3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cdb6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044cdb9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044cdbc  3c00                   +cmp al, 0
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
    // 0044cdbe  75e8                   -jne 0x44cda8
    if (!cpu.flags.zf)
    {
        goto L_0x0044cda8;
    }
L_0x0044cdc0:
    // 0044cdc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0044cdc1:
    // 0044cdc1  c7423c6c925500         -mov dword ptr [edx + 0x3c], 0x55926c
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */) = 5608044 /*0x55926c*/;
L_0x0044cdc8:
    // 0044cdc8  f6052eeb550020         +test byte ptr [0x55eb2e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */) & 32 /*0x20*/));
    // 0044cdcf  7416                   -je 0x44cde7
    if (cpu.flags.zf)
    {
        goto L_0x0044cde7;
    }
    // 0044cdd1  bacc925300             -mov edx, 0x5392cc
    cpu.edx = 5477068 /*0x5392cc*/;
    // 0044cdd6  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044cdd9  e8625cffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044cdde  c74040dc925300         -mov dword ptr [eax + 0x40], 0x5392dc
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477084 /*0x5392dc*/;
    // 0044cde5  eb18                   -jmp 0x44cdff
    goto L_0x0044cdff;
L_0x0044cde7:
    // 0044cde7  bacc925300             -mov edx, 0x5392cc
    cpu.edx = 5477068 /*0x5392cc*/;
    // 0044cdec  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044cdef  e84c5cffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044cdf4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044cdf6  7407                   -je 0x44cdff
    if (cpu.flags.zf)
    {
        goto L_0x0044cdff;
    }
    // 0044cdf8  c74064b0c74400         -mov dword ptr [eax + 0x64], 0x44c7b0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4507568 /*0x44c7b0*/;
L_0x0044cdff:
    // 0044cdff  bae0925300             -mov edx, 0x5392e0
    cpu.edx = 5477088 /*0x5392e0*/;
    // 0044ce04  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044ce07  e8345cffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044ce0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ce0e  7404                   -je 0x44ce14
    if (cpu.flags.zf)
    {
        goto L_0x0044ce14;
    }
    // 0044ce10  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044ce14:
    // 0044ce14  baf4925300             -mov edx, 0x5392f4
    cpu.edx = 5477108 /*0x5392f4*/;
    // 0044ce19  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044ce1c  e81f5cffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044ce21  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ce23  7404                   -je 0x44ce29
    if (cpu.flags.zf)
    {
        goto L_0x0044ce29;
    }
    // 0044ce25  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044ce29:
    // 0044ce29  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044ce30  7541                   -jne 0x44ce73
    if (!cpu.flags.zf)
    {
        goto L_0x0044ce73;
    }
    // 0044ce32  ba00935300             -mov edx, 0x539300
    cpu.edx = 5477120 /*0x539300*/;
    // 0044ce37  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044ce3a  e8015cffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044ce3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ce41  7404                   -je 0x44ce47
    if (cpu.flags.zf)
    {
        goto L_0x0044ce47;
    }
    // 0044ce43  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044ce47:
    // 0044ce47  ba04935300             -mov edx, 0x539304
    cpu.edx = 5477124 /*0x539304*/;
    // 0044ce4c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044ce4f  e8ec5bffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044ce54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ce56  7404                   -je 0x44ce5c
    if (cpu.flags.zf)
    {
        goto L_0x0044ce5c;
    }
    // 0044ce58  806005ef               -and byte ptr [eax + 5], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x0044ce5c:
    // 0044ce5c  ba0c935300             -mov edx, 0x53930c
    cpu.edx = 5477132 /*0x53930c*/;
    // 0044ce61  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044ce64  e8d75bffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044ce69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ce6b  7445                   -je 0x44ceb2
    if (cpu.flags.zf)
    {
        goto L_0x0044ceb2;
    }
    // 0044ce6d  806005ef               +and byte ptr [eax + 5], 0xef
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 0044ce71  eb3f                   -jmp 0x44ceb2
    goto L_0x0044ceb2;
L_0x0044ce73:
    // 0044ce73  ba00935300             -mov edx, 0x539300
    cpu.edx = 5477120 /*0x539300*/;
    // 0044ce78  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044ce7b  e8c05bffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044ce80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ce82  7404                   -je 0x44ce88
    if (cpu.flags.zf)
    {
        goto L_0x0044ce88;
    }
    // 0044ce84  806005ef               -and byte ptr [eax + 5], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x0044ce88:
    // 0044ce88  ba04935300             -mov edx, 0x539304
    cpu.edx = 5477124 /*0x539304*/;
    // 0044ce8d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044ce90  e8ab5bffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044ce95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ce97  7404                   -je 0x44ce9d
    if (cpu.flags.zf)
    {
        goto L_0x0044ce9d;
    }
    // 0044ce99  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044ce9d:
    // 0044ce9d  ba0c935300             -mov edx, 0x53930c
    cpu.edx = 5477132 /*0x53930c*/;
    // 0044cea2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044cea5  e8965bffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044ceaa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ceac  7404                   -je 0x44ceb2
    if (cpu.flags.zf)
    {
        goto L_0x0044ceb2;
    }
    // 0044ceae  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044ceb2:
    // 0044ceb2  ba14935300             -mov edx, 0x539314
    cpu.edx = 5477140 /*0x539314*/;
    // 0044ceb7  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044ceba  e8815bffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044cebf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044cec1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044cec3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044cec5  7433                   -je 0x44cefa
    if (cpu.flags.zf)
    {
        goto L_0x0044cefa;
    }
    // 0044cec7  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044ceca  8d4df8                 -lea ecx, [ebp - 8]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044cecd  8d5df4                 -lea ebx, [ebp - 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044ced0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044ced1  8d55f4                 -lea edx, [ebp - 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044ced4  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
    // 0044ced9  e8421c0700             -call 0x4beb20
    cpu.esp -= 4;
    sub_4beb20(app, cpu);
    if (cpu.terminate) return;
    // 0044cede  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044cee5  750f                   -jne 0x44cef6
    if (!cpu.flags.zf)
    {
        goto L_0x0044cef6;
    }
    // 0044cee7  817df880020000         +cmp dword ptr [ebp - 8], 0x280
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(640 /*0x280*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044ceee  7d06                   -jge 0x44cef6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044cef6;
    }
    // 0044cef0  804e0401               +or byte ptr [esi + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044cef4  eb04                   -jmp 0x44cefa
    goto L_0x0044cefa;
L_0x0044cef6:
    // 0044cef6  806704fe               -and byte ptr [edi + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x0044cefa:
    // 0044cefa  ba20935300             -mov edx, 0x539320
    cpu.edx = 5477152 /*0x539320*/;
    // 0044ceff  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044cf02  e8395bffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044cf07  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044cf09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044cf0b  743a                   -je 0x44cf47
    if (cpu.flags.zf)
    {
        goto L_0x0044cf47;
    }
    // 0044cf0d  8b35b0d36f00           -mov esi, dword ptr [0x6fd3b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0044cf13  c7406410ca4400         -mov dword ptr [eax + 0x64], 0x44ca10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4508176 /*0x44ca10*/;
    // 0044cf1a  83fe01                 +cmp esi, 1
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
    // 0044cf1d  7c19                   -jl 0x44cf38
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044cf38;
    }
    // 0044cf1f  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044cf27  7409                   -je 0x44cf32
    if (cpu.flags.zf)
    {
        goto L_0x0044cf32;
    }
    // 0044cf29  833de4227a0002         +cmp dword ptr [0x7a22e4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044cf30  7506                   -jne 0x44cf38
    if (!cpu.flags.zf)
    {
        goto L_0x0044cf38;
    }
L_0x0044cf32:
    // 0044cf32  668148040110           -or word ptr [eax + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x0044cf38:
    // 0044cf38  833da0d36f0002         +cmp dword ptr [0x6fd3a0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328672) /* 0x6fd3a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044cf3f  7c06                   -jl 0x44cf47
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044cf47;
    }
    // 0044cf41  66816004feef           -and word ptr [eax + 4], 0xeffe
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg16(x86::sreg16(61438 /*0xeffe*/));
L_0x0044cf47:
    // 0044cf47  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044cf4a  e881f3ffff             -call 0x44c2d0
    cpu.esp -= 4;
    sub_44c2d0(app, cpu);
    if (cpu.terminate) return;
    // 0044cf4f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044cf51  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044cf53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cf54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cf55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cf56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cf57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cf58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cf59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_44cf60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044cf60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044cf61  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044cf63  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044cf65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cf66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_44cf70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044cf70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044cf71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044cf72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044cf73  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044cf75  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044cf77  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0044cf7c  e8dfd6ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0044cf81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044cf83  740f                   -je 0x44cf94
    if (cpu.flags.zf)
    {
        goto L_0x0044cf94;
    }
    // 0044cf85  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044cf87  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044cf89  e822fa0100             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 0044cf8e  d91d38bc6f00           -fstp dword ptr [0x6fbc38]
    app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0044cf94:
    // 0044cf94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cf95  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cf96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cf97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_44cfa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044cfa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044cfa1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044cfa2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044cfa3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044cfa5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044cfa7  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0044cfac  e8afd6ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0044cfb1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044cfb3  7419                   -je 0x44cfce
    if (cpu.flags.zf)
    {
        goto L_0x0044cfce;
    }
    // 0044cfb5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044cfb7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044cfb9  e8f2f90100             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 0044cfbe  d80d2c935300           -fmul dword ptr [0x53932c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477164) /* 0x53932c */));
    // 0044cfc4  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0044cfc6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0044cfc8  d91d04be6f00           -fstp dword ptr [0x6fbe04]
    app->getMemory<float>(x86::reg32(7323140) /* 0x6fbe04 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0044cfce:
    // 0044cfce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cfcf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cfd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044cfd1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_44cfe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044cfe0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044cfe1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044cfe2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044cfe3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044cfe5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044cfe7  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0044cfec  e86fd6ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0044cff1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044cff3  7419                   -je 0x44d00e
    if (cpu.flags.zf)
    {
        goto L_0x0044d00e;
    }
    // 0044cff5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044cff7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044cff9  e8b2f90100             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 0044cffe  d80d30935300           -fmul dword ptr [0x539330]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477168) /* 0x539330 */));
    // 0044d004  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0044d006  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0044d008  d91d60bc6f00           -fstp dword ptr [0x6fbc60]
    app->getMemory<float>(x86::reg32(7322720) /* 0x6fbc60 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0044d00e:
    // 0044d00e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d00f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d010  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d011  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_44d020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d020  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d021  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d022  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d023  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d025  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044d027  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0044d02c  e82fd6ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0044d031  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d033  7419                   -je 0x44d04e
    if (cpu.flags.zf)
    {
        goto L_0x0044d04e;
    }
    // 0044d035  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d037  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044d039  e872f90100             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 0044d03e  d80d34935300           -fmul dword ptr [0x539334]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477172) /* 0x539334 */));
    // 0044d044  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0044d046  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0044d048  d91d4cc16f00           -fstp dword ptr [0x6fc14c]
    app->getMemory<float>(x86::reg32(7323980) /* 0x6fc14c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0044d04e:
    // 0044d04e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d04f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d050  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d051  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_44d060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d060  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d061  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d062  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d063  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d065  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044d067  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0044d06c  e8efd5ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0044d071  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d073  7419                   -je 0x44d08e
    if (cpu.flags.zf)
    {
        goto L_0x0044d08e;
    }
    // 0044d075  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d077  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044d079  e832f90100             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 0044d07e  d80d38935300           -fmul dword ptr [0x539338]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477176) /* 0x539338 */));
    // 0044d084  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0044d086  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0044d088  d91da8bf6f00           -fstp dword ptr [0x6fbfa8]
    app->getMemory<float>(x86::reg32(7323560) /* 0x6fbfa8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0044d08e:
    // 0044d08e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d08f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d090  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d091  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_44d0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d0a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d0a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d0a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d0a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d0a5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044d0a7  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0044d0ac  e8afd5ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0044d0b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d0b3  7419                   -je 0x44d0ce
    if (cpu.flags.zf)
    {
        goto L_0x0044d0ce;
    }
    // 0044d0b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d0b7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044d0b9  e8f2f80100             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 0044d0be  d80d3c935300           -fmul dword ptr [0x53933c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477180) /* 0x53933c */));
    // 0044d0c4  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0044d0c6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0044d0c8  d91d94c46f00           -fstp dword ptr [0x6fc494]
    app->getMemory<float>(x86::reg32(7324820) /* 0x6fc494 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0044d0ce:
    // 0044d0ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d0cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d0d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d0d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_44d0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d0e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d0e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d0e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d0e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d0e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044d0e7  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0044d0ec  e86fd5ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0044d0f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d0f3  7419                   -je 0x44d10e
    if (cpu.flags.zf)
    {
        goto L_0x0044d10e;
    }
    // 0044d0f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d0f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044d0f9  e8b2f80100             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 0044d0fe  d80d40935300           -fmul dword ptr [0x539340]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477184) /* 0x539340 */));
    // 0044d104  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0044d106  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0044d108  d91df0c26f00           -fstp dword ptr [0x6fc2f0]
    app->getMemory<float>(x86::reg32(7324400) /* 0x6fc2f0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0044d10e:
    // 0044d10e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d10f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d110  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d111  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_44d120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d120  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d121  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d122  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d123  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d125  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044d127  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0044d12c  e8ff430000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
    // 0044d131  ba44935300             -mov edx, 0x539344
    cpu.edx = 5477188 /*0x539344*/;
    // 0044d136  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d138  e80359ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d13d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d13f  740d                   -je 0x44d14e
    if (cpu.flags.zf)
    {
        goto L_0x0044d14e;
    }
    // 0044d141  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
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
    // 0044d148  7404                   -je 0x44d14e
    if (cpu.flags.zf)
    {
        goto L_0x0044d14e;
    }
    // 0044d14a  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d14e:
    // 0044d14e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d150  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d151  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d152  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d153  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_44d160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d160  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d161  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d163  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d165  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d166  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_44d170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d170  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d171  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d172  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d174  6683fb0d               +cmp bx, 0xd
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
    // 0044d178  7508                   -jne 0x44d182
    if (!cpu.flags.zf)
    {
        goto L_0x0044d182;
    }
    // 0044d17a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044d17c  890d0c446600           -mov dword ptr [0x66440c], ecx
    app->getMemory<x86::reg32>(x86::reg32(6702092) /* 0x66440c */) = cpu.ecx;
L_0x0044d182:
    // 0044d182  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044d185  e8e6400100             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 0044d18a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d18b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d18c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_44d190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d190  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044d191  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d192  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d193  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d194  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d196  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044d198  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0044d19d  e88e430000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
    // 0044d1a2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044d1a7  bb68000000             -mov ebx, 0x68
    cpu.ebx = 104 /*0x68*/;
    // 0044d1ac  a1b0d36f00             -mov eax, dword ptr [0x6fd3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0044d1b1  89150c446600           -mov dword ptr [0x66440c], edx
    app->getMemory<x86::reg32>(x86::reg32(6702092) /* 0x66440c */) = cpu.edx;
    // 0044d1b7  bad03c5f00             -mov edx, 0x5f3cd0
    cpu.edx = 6241488 /*0x5f3cd0*/;
    // 0044d1bc  e80f330400             -call 0x4904d0
    cpu.esp -= 4;
    sub_4904d0(app, cpu);
    if (cpu.terminate) return;
    // 0044d1c1  e82ad30900             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0044d1c6  ba4c935300             -mov edx, 0x53934c
    cpu.edx = 5477196 /*0x53934c*/;
    // 0044d1cb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d1cd  e86e58ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d1d2  f60570c96f0008         +test byte ptr [0x6fc970], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7326064) /* 0x6fc970 */) & 8 /*0x8*/));
    // 0044d1d9  7508                   -jne 0x44d1e3
    if (!cpu.flags.zf)
    {
        goto L_0x0044d1e3;
    }
    // 0044d1db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d1dd  7404                   -je 0x44d1e3
    if (cpu.flags.zf)
    {
        goto L_0x0044d1e3;
    }
    // 0044d1df  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d1e3:
    // 0044d1e3  ba5c935300             -mov edx, 0x53935c
    cpu.edx = 5477212 /*0x53935c*/;
    // 0044d1e8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d1ea  e85158ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d1ef  833d70c96f0000         +cmp dword ptr [0x6fc970], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7326064) /* 0x6fc970 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d1f6  7508                   -jne 0x44d200
    if (!cpu.flags.zf)
    {
        goto L_0x0044d200;
    }
    // 0044d1f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d1fa  7404                   -je 0x44d200
    if (cpu.flags.zf)
    {
        goto L_0x0044d200;
    }
    // 0044d1fc  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d200:
    // 0044d200  ba6c935300             -mov edx, 0x53936c
    cpu.edx = 5477228 /*0x53936c*/;
    // 0044d205  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d207  e83458ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d20c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d20e  7407                   -je 0x44d217
    if (cpu.flags.zf)
    {
        goto L_0x0044d217;
    }
    // 0044d210  c7403070d14400         -mov dword ptr [eax + 0x30], 0x44d170
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4510064 /*0x44d170*/;
L_0x0044d217:
    // 0044d217  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d219  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d21a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d21b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d21c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d21d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_44d220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044d221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d222  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d223  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d224  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d226  a1b0d36f00             -mov eax, dword ptr [0x6fd3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0044d22b  e8a0320400             -call 0x4904d0
    cpu.esp -= 4;
    sub_4904d0(app, cpu);
    if (cpu.terminate) return;
    // 0044d230  833d0c44660000         +cmp dword ptr [0x66440c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702092) /* 0x66440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d237  7523                   -jne 0x44d25c
    if (!cpu.flags.zf)
    {
        goto L_0x0044d25c;
    }
    // 0044d239  bb68000000             -mov ebx, 0x68
    cpu.ebx = 104 /*0x68*/;
    // 0044d23e  8b0db0d36f00           -mov ecx, dword ptr [0x6fd3b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0044d244  83f901                 +cmp ecx, 1
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
    // 0044d247  7405                   -je 0x44d24e
    if (cpu.flags.zf)
    {
        goto L_0x0044d24e;
    }
    // 0044d249  bb34000000             -mov ebx, 0x34
    cpu.ebx = 52 /*0x34*/;
L_0x0044d24e:
    // 0044d24e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044d250  b8d03c5f00             -mov eax, 0x5f3cd0
    cpu.eax = 6241488 /*0x5f3cd0*/;
    // 0044d255  e896d20900             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0044d25a  eb05                   -jmp 0x44d261
    goto L_0x0044d261;
L_0x0044d25c:
    // 0044d25c  e88f3e0200             -call 0x4710f0
    cpu.esp -= 4;
    sub_4710f0(app, cpu);
    if (cpu.terminate) return;
L_0x0044d261:
    // 0044d261  e88a1f0400             -call 0x48f1f0
    cpu.esp -= 4;
    sub_48f1f0(app, cpu);
    if (cpu.terminate) return;
    // 0044d266  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d268  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d269  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d26a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d26b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d26c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_44d270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d270  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d271  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d273  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d275  e85659fdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044d27a  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044d281  7407                   -je 0x44d28a
    if (cpu.flags.zf)
    {
        goto L_0x0044d28a;
    }
    // 0044d283  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044d288  eb02                   -jmp 0x44d28c
    goto L_0x0044d28c;
L_0x0044d28a:
    // 0044d28a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044d28c:
    // 0044d28c  e84f130700             -call 0x4be5e0
    cpu.esp -= 4;
    sub_4be5e0(app, cpu);
    if (cpu.terminate) return;
    // 0044d291  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044d296  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d297  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_44d2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d2a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044d2a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d2a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d2a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044d2a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044d2a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d2a6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d2a8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044d2aa  b96c170000             -mov ecx, 0x176c
    cpu.ecx = 5996 /*0x176c*/;
    // 0044d2af  be4cbb6f00             -mov esi, 0x6fbb4c
    cpu.esi = 7322444 /*0x6fbb4c*/;
    // 0044d2b4  bfa02c6600             -mov edi, 0x662ca0
    cpu.edi = 6696096 /*0x662ca0*/;
    // 0044d2b9  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0044d2bc  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044d2be  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d2c0  e8ffa4feff             -call 0x4377c4
    cpu.esp -= 4;
    sub_4377c4(app, cpu);
    if (cpu.terminate) return;
    // 0044d2c5  eb02                   -jmp 0x44d2c9
    return sub_44d2c9(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_44d2c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d2c8  90                     -nop 
    ;
    // 0044d2c9  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0044d2ce  e85d420000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
    // 0044d2d3  f605583a7a0006         +test byte ptr [0x7a3a58], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 6 /*0x6*/));
    // 0044d2da  753e                   -jne 0x44d31a
    if (!cpu.flags.zf)
    {
        goto L_0x0044d31a;
    }
    // 0044d2dc  ba74935300             -mov edx, 0x539374
    cpu.edx = 5477236 /*0x539374*/;
    // 0044d2e1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d2e3  e85857ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d2e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d2ea  7404                   -je 0x44d2f0
    if (cpu.flags.zf)
    {
        goto L_0x0044d2f0;
    }
    // 0044d2ec  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d2f0:
    // 0044d2f0  ba80935300             -mov edx, 0x539380
    cpu.edx = 5477248 /*0x539380*/;
    // 0044d2f5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d2f7  e84457ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d2fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d2fe  7406                   -je 0x44d306
    if (cpu.flags.zf)
    {
        goto L_0x0044d306;
    }
    // 0044d300  668148040110           -or word ptr [eax + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x0044d306:
    // 0044d306  ba9c935300             -mov edx, 0x53939c
    cpu.edx = 5477276 /*0x53939c*/;
    // 0044d30b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d30d  e82e57ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d312  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d314  7404                   -je 0x44d31a
    if (cpu.flags.zf)
    {
        goto L_0x0044d31a;
    }
    // 0044d316  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d31a:
    // 0044d31a  bab0935300             -mov edx, 0x5393b0
    cpu.edx = 5477296 /*0x5393b0*/;
    // 0044d31f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d321  e81a57ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d326  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d328  7416                   -je 0x44d340
    if (cpu.flags.zf)
    {
        goto L_0x0044d340;
    }
    // 0044d32a  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044d331  7506                   -jne 0x44d339
    if (!cpu.flags.zf)
    {
        goto L_0x0044d339;
    }
    // 0044d333  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044d337  eb07                   -jmp 0x44d340
    goto L_0x0044d340;
L_0x0044d339:
    // 0044d339  c7406470d24400         -mov dword ptr [eax + 0x64], 0x44d270
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4510320 /*0x44d270*/;
L_0x0044d340:
    // 0044d340  bac4935300             -mov edx, 0x5393c4
    cpu.edx = 5477316 /*0x5393c4*/;
    // 0044d345  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d347  e8f456ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d34c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d34e  740d                   -je 0x44d35d
    if (cpu.flags.zf)
    {
        goto L_0x0044d35d;
    }
    // 0044d350  f605583a7a0006         +test byte ptr [0x7a3a58], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 6 /*0x6*/));
    // 0044d357  7404                   -je 0x44d35d
    if (cpu.flags.zf)
    {
        goto L_0x0044d35d;
    }
    // 0044d359  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d35d:
    // 0044d35d  bad0935300             -mov edx, 0x5393d0
    cpu.edx = 5477328 /*0x5393d0*/;
    // 0044d362  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d364  e8d756ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d369  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d36b  7422                   -je 0x44d38f
    if (cpu.flags.zf)
    {
        goto L_0x0044d38f;
    }
    // 0044d36d  f605583a7a0050         +test byte ptr [0x7a3a58], 0x50
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 80 /*0x50*/));
    // 0044d374  7506                   -jne 0x44d37c
    if (!cpu.flags.zf)
    {
        goto L_0x0044d37c;
    }
    // 0044d376  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044d37a  eb13                   -jmp 0x44d38f
    goto L_0x0044d38f;
L_0x0044d37c:
    // 0044d37c  d90538bc6f00           -fld dword ptr [0x6fbc38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */)));
    // 0044d382  ba70cf4400             -mov edx, 0x44cf70
    cpu.edx = 4509552 /*0x44cf70*/;
    // 0044d387  d95854                 -fstp dword ptr [eax + 0x54]
    app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044d38a  e831f70100             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x0044d38f:
    // 0044d38f  bae0935300             -mov edx, 0x5393e0
    cpu.edx = 5477344 /*0x5393e0*/;
    // 0044d394  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d396  e8a556ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d39b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d39d  7413                   -je 0x44d3b2
    if (cpu.flags.zf)
    {
        goto L_0x0044d3b2;
    }
    // 0044d39f  833d683a7a0000         +cmp dword ptr [0x7a3a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010344) /* 0x7a3a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d3a6  7406                   -je 0x44d3ae
    if (cpu.flags.zf)
    {
        goto L_0x0044d3ae;
    }
    // 0044d3a8  806004fe               +and byte ptr [eax + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 0044d3ac  eb04                   -jmp 0x44d3b2
    goto L_0x0044d3b2;
L_0x0044d3ae:
    // 0044d3ae  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d3b2:
    // 0044d3b2  baec935300             -mov edx, 0x5393ec
    cpu.edx = 5477356 /*0x5393ec*/;
    // 0044d3b7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d3b9  e88256ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d3be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d3c0  7413                   -je 0x44d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0044d3d5;
    }
    // 0044d3c2  833d683a7a0000         +cmp dword ptr [0x7a3a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010344) /* 0x7a3a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d3c9  7406                   -je 0x44d3d1
    if (cpu.flags.zf)
    {
        goto L_0x0044d3d1;
    }
    // 0044d3cb  806004fe               +and byte ptr [eax + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 0044d3cf  eb04                   -jmp 0x44d3d5
    goto L_0x0044d3d5;
L_0x0044d3d1:
    // 0044d3d1  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d3d5:
    // 0044d3d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d3d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_44d2c9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0044d2c9;
    // 0044d2c8  90                     -nop 
    ;
L_entry_0x0044d2c9:
    // 0044d2c9  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0044d2ce  e85d420000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
    // 0044d2d3  f605583a7a0006         +test byte ptr [0x7a3a58], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 6 /*0x6*/));
    // 0044d2da  753e                   -jne 0x44d31a
    if (!cpu.flags.zf)
    {
        goto L_0x0044d31a;
    }
    // 0044d2dc  ba74935300             -mov edx, 0x539374
    cpu.edx = 5477236 /*0x539374*/;
    // 0044d2e1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d2e3  e85857ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d2e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d2ea  7404                   -je 0x44d2f0
    if (cpu.flags.zf)
    {
        goto L_0x0044d2f0;
    }
    // 0044d2ec  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d2f0:
    // 0044d2f0  ba80935300             -mov edx, 0x539380
    cpu.edx = 5477248 /*0x539380*/;
    // 0044d2f5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d2f7  e84457ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d2fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d2fe  7406                   -je 0x44d306
    if (cpu.flags.zf)
    {
        goto L_0x0044d306;
    }
    // 0044d300  668148040110           -or word ptr [eax + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x0044d306:
    // 0044d306  ba9c935300             -mov edx, 0x53939c
    cpu.edx = 5477276 /*0x53939c*/;
    // 0044d30b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d30d  e82e57ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d312  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d314  7404                   -je 0x44d31a
    if (cpu.flags.zf)
    {
        goto L_0x0044d31a;
    }
    // 0044d316  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d31a:
    // 0044d31a  bab0935300             -mov edx, 0x5393b0
    cpu.edx = 5477296 /*0x5393b0*/;
    // 0044d31f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d321  e81a57ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d326  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d328  7416                   -je 0x44d340
    if (cpu.flags.zf)
    {
        goto L_0x0044d340;
    }
    // 0044d32a  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044d331  7506                   -jne 0x44d339
    if (!cpu.flags.zf)
    {
        goto L_0x0044d339;
    }
    // 0044d333  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044d337  eb07                   -jmp 0x44d340
    goto L_0x0044d340;
L_0x0044d339:
    // 0044d339  c7406470d24400         -mov dword ptr [eax + 0x64], 0x44d270
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4510320 /*0x44d270*/;
L_0x0044d340:
    // 0044d340  bac4935300             -mov edx, 0x5393c4
    cpu.edx = 5477316 /*0x5393c4*/;
    // 0044d345  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d347  e8f456ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d34c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d34e  740d                   -je 0x44d35d
    if (cpu.flags.zf)
    {
        goto L_0x0044d35d;
    }
    // 0044d350  f605583a7a0006         +test byte ptr [0x7a3a58], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 6 /*0x6*/));
    // 0044d357  7404                   -je 0x44d35d
    if (cpu.flags.zf)
    {
        goto L_0x0044d35d;
    }
    // 0044d359  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d35d:
    // 0044d35d  bad0935300             -mov edx, 0x5393d0
    cpu.edx = 5477328 /*0x5393d0*/;
    // 0044d362  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d364  e8d756ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d369  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d36b  7422                   -je 0x44d38f
    if (cpu.flags.zf)
    {
        goto L_0x0044d38f;
    }
    // 0044d36d  f605583a7a0050         +test byte ptr [0x7a3a58], 0x50
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 80 /*0x50*/));
    // 0044d374  7506                   -jne 0x44d37c
    if (!cpu.flags.zf)
    {
        goto L_0x0044d37c;
    }
    // 0044d376  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044d37a  eb13                   -jmp 0x44d38f
    goto L_0x0044d38f;
L_0x0044d37c:
    // 0044d37c  d90538bc6f00           -fld dword ptr [0x6fbc38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */)));
    // 0044d382  ba70cf4400             -mov edx, 0x44cf70
    cpu.edx = 4509552 /*0x44cf70*/;
    // 0044d387  d95854                 -fstp dword ptr [eax + 0x54]
    app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044d38a  e831f70100             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x0044d38f:
    // 0044d38f  bae0935300             -mov edx, 0x5393e0
    cpu.edx = 5477344 /*0x5393e0*/;
    // 0044d394  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d396  e8a556ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d39b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d39d  7413                   -je 0x44d3b2
    if (cpu.flags.zf)
    {
        goto L_0x0044d3b2;
    }
    // 0044d39f  833d683a7a0000         +cmp dword ptr [0x7a3a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010344) /* 0x7a3a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d3a6  7406                   -je 0x44d3ae
    if (cpu.flags.zf)
    {
        goto L_0x0044d3ae;
    }
    // 0044d3a8  806004fe               +and byte ptr [eax + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 0044d3ac  eb04                   -jmp 0x44d3b2
    goto L_0x0044d3b2;
L_0x0044d3ae:
    // 0044d3ae  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d3b2:
    // 0044d3b2  baec935300             -mov edx, 0x5393ec
    cpu.edx = 5477356 /*0x5393ec*/;
    // 0044d3b7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d3b9  e88256ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d3be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d3c0  7413                   -je 0x44d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0044d3d5;
    }
    // 0044d3c2  833d683a7a0000         +cmp dword ptr [0x7a3a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010344) /* 0x7a3a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d3c9  7406                   -je 0x44d3d1
    if (cpu.flags.zf)
    {
        goto L_0x0044d3d1;
    }
    // 0044d3cb  806004fe               +and byte ptr [eax + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 0044d3cf  eb04                   -jmp 0x44d3d5
    goto L_0x0044d3d5;
L_0x0044d3d1:
    // 0044d3d1  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d3d5:
    // 0044d3d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d3d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d3dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_44d3e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d3e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d3e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d3e2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d3e4  baec935300             -mov edx, 0x5393ec
    cpu.edx = 5477356 /*0x5393ec*/;
    // 0044d3e9  e85256ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d3ee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044d3f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d3f2  741f                   -je 0x44d413
    if (cpu.flags.zf)
    {
        goto L_0x0044d413;
    }
    // 0044d3f4  833d683a7a0000         +cmp dword ptr [0x7a3a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010344) /* 0x7a3a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d3fb  7412                   -je 0x44d40f
    if (cpu.flags.zf)
    {
        goto L_0x0044d40f;
    }
    // 0044d3fd  833d34bc6f0000         +cmp dword ptr [0x6fbc34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322676) /* 0x6fbc34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d404  7409                   -je 0x44d40f
    if (cpu.flags.zf)
    {
        goto L_0x0044d40f;
    }
    // 0044d406  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0044d40a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d40c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d40d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d40e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044d40f:
    // 0044d40f  804a0401               -or byte ptr [edx + 4], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044d413:
    // 0044d413  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d415  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d416  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d417  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_44d420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d420  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044d421  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d422  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d423  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044d424  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044d425  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d426  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d428  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044d42b  8b4016                 -mov eax, dword ptr [eax + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044d42e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044d431  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044d434  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044d436  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044d43d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044d43f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044d442  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044d444  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044d447  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044d44c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0044d44e  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0044d450  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d453  7562                   -jne 0x44d4b7
    if (!cpu.flags.zf)
    {
        goto L_0x0044d4b7;
    }
    // 0044d455  baf8935300             -mov edx, 0x5393f8
    cpu.edx = 5477368 /*0x5393f8*/;
    // 0044d45a  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0044d45d  e82aa3feff             -call 0x43778c
    cpu.esp -= 4;
    sub_43778c(app, cpu);
    if (cpu.terminate) return;
    // 0044d462  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d464  7451                   -je 0x44d4b7
    if (cpu.flags.zf)
    {
        goto L_0x0044d4b7;
    }
    // 0044d466  8b0da02d6600           -mov ecx, dword ptr [0x662da0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6696352) /* 0x662da0 */);
    // 0044d46c  3b0d4cbc6f00           +cmp ecx, dword ptr [0x6fbc4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322700) /* 0x6fbc4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d472  7402                   -je 0x44d476
    if (cpu.flags.zf)
    {
        goto L_0x0044d476;
    }
    // 0044d474  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
L_0x0044d476:
    // 0044d476  b96c170000             -mov ecx, 0x176c
    cpu.ecx = 5996 /*0x176c*/;
    // 0044d47b  bea02c6600             -mov esi, 0x662ca0
    cpu.esi = 6696096 /*0x662ca0*/;
    // 0044d480  bf4cbb6f00             -mov edi, 0x6fbb4c
    cpu.edi = 7322444 /*0x6fbb4c*/;
    // 0044d485  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044d486  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d488  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044d48b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044d48d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044d48f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044d492  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044d494  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d495  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0044d497  741e                   -je 0x44d4b7
    if (cpu.flags.zf)
    {
        goto L_0x0044d4b7;
    }
    // 0044d499  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d49b  e83057fdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044d4a0  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044d4a7  7407                   -je 0x44d4b0
    if (cpu.flags.zf)
    {
        goto L_0x0044d4b0;
    }
    // 0044d4a9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044d4ae  eb02                   -jmp 0x44d4b2
    goto L_0x0044d4b2;
L_0x0044d4b0:
    // 0044d4b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044d4b2:
    // 0044d4b2  e829110700             -call 0x4be5e0
    cpu.esp -= 4;
    sub_4be5e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044d4b7:
    // 0044d4b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d4b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d4ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d4bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d4bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d4bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d4be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d4bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_44d4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d4c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044d4c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d4c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d4c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044d4c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044d4c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d4c6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d4c8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044d4ca  b96c170000             -mov ecx, 0x176c
    cpu.ecx = 5996 /*0x176c*/;
    // 0044d4cf  be4cbb6f00             -mov esi, 0x6fbb4c
    cpu.esi = 7322444 /*0x6fbb4c*/;
    // 0044d4d4  bfa02c6600             -mov edi, 0x662ca0
    cpu.edi = 6696096 /*0x662ca0*/;
    // 0044d4d9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044d4de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044d4df  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d4e1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044d4e4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044d4e6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044d4e8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044d4eb  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044d4ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d4ee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d4f0  89151c1b7900           -mov dword ptr [0x791b1c], edx
    app->getMemory<x86::reg32>(x86::reg32(7936796) /* 0x791b1c */) = cpu.edx;
    // 0044d4f6  e8d556fdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044d4fb  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044d502  7407                   -je 0x44d50b
    if (cpu.flags.zf)
    {
        goto L_0x0044d50b;
    }
    // 0044d504  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044d509  eb02                   -jmp 0x44d50d
    goto L_0x0044d50d;
L_0x0044d50b:
    // 0044d50b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044d50d:
    // 0044d50d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044d50f  69f0a4010000           -imul esi, eax, 0x1a4
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d515  8bb670bc6f00           -mov esi, dword ptr [esi + 0x6fbc70]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(7322736) /* 0x6fbc70 */);
    // 0044d51b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d51d  7507                   -jne 0x44d526
    if (!cpu.flags.zf)
    {
        goto L_0x0044d526;
    }
    // 0044d51f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044d524  eb02                   -jmp 0x44d528
    goto L_0x0044d528;
L_0x0044d526:
    // 0044d526  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044d528:
    // 0044d528  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0044d52d  ba08945300             -mov edx, 0x539408
    cpu.edx = 5477384 /*0x539408*/;
    // 0044d532  a3f07d6700             -mov dword ptr [0x677df0], eax
    app->getMemory<x86::reg32>(x86::reg32(6782448) /* 0x677df0 */) = cpu.eax;
    // 0044d537  e8f43f0000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
    // 0044d53c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d53e  e8fd54ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d543  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d545  743c                   -je 0x44d583
    if (cpu.flags.zf)
    {
        goto L_0x0044d583;
    }
    // 0044d547  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044d549  7419                   -je 0x44d564
    if (cpu.flags.zf)
    {
        goto L_0x0044d564;
    }
    // 0044d54b  d90504be6f00           +fld dword ptr [0x6fbe04]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7323140) /* 0x6fbe04 */)));
    // 0044d551  d80534945300           +fadd dword ptr [0x539434]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5477428) /* 0x539434 */));
    // 0044d557  d80d38945300           +fmul dword ptr [0x539438]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477432) /* 0x539438 */));
    // 0044d55d  baa0cf4400             -mov edx, 0x44cfa0
    cpu.edx = 4509600 /*0x44cfa0*/;
    // 0044d562  eb17                   -jmp 0x44d57b
    goto L_0x0044d57b;
L_0x0044d564:
    // 0044d564  d90560bc6f00           -fld dword ptr [0x6fbc60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7322720) /* 0x6fbc60 */)));
    // 0044d56a  d80534945300           -fadd dword ptr [0x539434]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5477428) /* 0x539434 */));
    // 0044d570  d80d38945300           -fmul dword ptr [0x539438]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477432) /* 0x539438 */));
    // 0044d576  bae0cf4400             -mov edx, 0x44cfe0
    cpu.edx = 4509664 /*0x44cfe0*/;
L_0x0044d57b:
    // 0044d57b  d95854                 -fstp dword ptr [eax + 0x54]
    app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044d57e  e83df50100             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x0044d583:
    // 0044d583  ba14945300             -mov edx, 0x539414
    cpu.edx = 5477396 /*0x539414*/;
    // 0044d588  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d58a  e8b154ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d58f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d591  7414                   -je 0x44d5a7
    if (cpu.flags.zf)
    {
        goto L_0x0044d5a7;
    }
    // 0044d593  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044d595  7409                   -je 0x44d5a0
    if (cpu.flags.zf)
    {
        goto L_0x0044d5a0;
    }
    // 0044d597  c7404020945300         -mov dword ptr [eax + 0x40], 0x539420
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477408 /*0x539420*/;
    // 0044d59e  eb07                   -jmp 0x44d5a7
    goto L_0x0044d5a7;
L_0x0044d5a0:
    // 0044d5a0  c7404028945300         -mov dword ptr [eax + 0x40], 0x539428
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477416 /*0x539428*/;
L_0x0044d5a7:
    // 0044d5a7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d5a9  e822edffff             -call 0x44c2d0
    cpu.esp -= 4;
    sub_44c2d0(app, cpu);
    if (cpu.terminate) return;
    // 0044d5ae  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044d5b0  7409                   -je 0x44d5bb
    if (cpu.flags.zf)
    {
        goto L_0x0044d5bb;
    }
    // 0044d5b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d5b4  e8a7edffff             -call 0x44c360
    cpu.esp -= 4;
    sub_44c360(app, cpu);
    if (cpu.terminate) return;
    // 0044d5b9  eb07                   -jmp 0x44d5c2
    goto L_0x0044d5c2;
L_0x0044d5bb:
    // 0044d5bb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d5bd  e81eefffff             -call 0x44c4e0
    cpu.esp -= 4;
    sub_44c4e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044d5c2:
    // 0044d5c2  69d9a4010000           -imul ebx, ecx, 0x1a4
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d5c8  8bbb68bc6f00           -mov edi, dword ptr [ebx + 0x6fbc68]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7322728) /* 0x6fbc68 */);
    // 0044d5ce  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044d5d5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044d5d7  740b                   -je 0x44d5e4
    if (cpu.flags.zf)
    {
        goto L_0x0044d5e4;
    }
    // 0044d5d9  8d5fff                 -lea ebx, [edi - 1]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 0044d5dc  899840886700           -mov dword ptr [eax + 0x678840], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785088) /* 0x678840 */) = cpu.ebx;
    // 0044d5e2  eb0a                   -jmp 0x44d5ee
    goto L_0x0044d5ee;
L_0x0044d5e4:
    // 0044d5e4  c7804088670004000000   -mov dword ptr [eax + 0x678840], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785088) /* 0x678840 */) = 4 /*0x4*/;
L_0x0044d5ee:
    // 0044d5ee  69c1a4010000           -imul eax, ecx, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d5f4  8bb86cbc6f00           -mov edi, dword ptr [eax + 0x6fbc6c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7322732) /* 0x6fbc6c */);
    // 0044d5fa  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0044d601  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044d603  740b                   -je 0x44d610
    if (cpu.flags.zf)
    {
        goto L_0x0044d610;
    }
    // 0044d605  8d47ff                 -lea eax, [edi - 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 0044d608  898310886700           -mov dword ptr [ebx + 0x678810], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6785040) /* 0x678810 */) = cpu.eax;
    // 0044d60e  eb0a                   -jmp 0x44d61a
    goto L_0x0044d61a;
L_0x0044d610:
    // 0044d610  c7831088670003000000   -mov dword ptr [ebx + 0x678810], 3
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6785040) /* 0x678810 */) = 3 /*0x3*/;
L_0x0044d61a:
    // 0044d61a  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044d621  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044d623  7409                   -je 0x44d62e
    if (cpu.flags.zf)
    {
        goto L_0x0044d62e;
    }
    // 0044d625  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044d626  89b0f8876700           -mov dword ptr [eax + 0x6787f8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785016) /* 0x6787f8 */) = cpu.esi;
    // 0044d62c  eb0a                   -jmp 0x44d638
    goto L_0x0044d638;
L_0x0044d62e:
    // 0044d62e  c780f887670002000000   -mov dword ptr [eax + 0x6787f8], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785016) /* 0x6787f8 */) = 2 /*0x2*/;
L_0x0044d638:
    // 0044d638  69c1a4010000           -imul eax, ecx, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d63e  8b9864bc6f00           -mov ebx, dword ptr [eax + 0x6fbc64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7322724) /* 0x6fbc64 */);
    // 0044d644  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0044d647  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044d649  740b                   -je 0x44d656
    if (cpu.flags.zf)
    {
        goto L_0x0044d656;
    }
    // 0044d64b  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0044d64e  898128886700           -mov dword ptr [ecx + 0x678828], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6785064) /* 0x678828 */) = cpu.eax;
    // 0044d654  eb0a                   -jmp 0x44d660
    goto L_0x0044d660;
L_0x0044d656:
    // 0044d656  c7812888670005000000   -mov dword ptr [ecx + 0x678828], 5
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6785064) /* 0x678828 */) = 5 /*0x5*/;
L_0x0044d660:
    // 0044d660  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d662  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d663  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d664  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d665  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d666  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d667  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d668  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44d670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044d671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d672  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d673  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044d674  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044d675  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d676  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d678  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044d67a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d67c  e84f55fdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044d681  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044d688  7407                   -je 0x44d691
    if (cpu.flags.zf)
    {
        goto L_0x0044d691;
    }
    // 0044d68a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044d68f  eb02                   -jmp 0x44d693
    goto L_0x0044d693;
L_0x0044d691:
    // 0044d691  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044d693:
    // 0044d693  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044d695  69caa4010000           -imul ecx, edx, 0x1a4
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d69b  be50bc6f00             -mov esi, 0x6fbc50
    cpu.esi = 7322704 /*0x6fbc50*/;
    // 0044d6a0  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0044d6a3  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044d6a5  8bba40886700           -mov edi, dword ptr [edx + 0x678840]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785088) /* 0x678840 */);
    // 0044d6ab  83c620                 -add esi, 0x20
    (cpu.esi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0044d6ae  83ff04                 +cmp edi, 4
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
    // 0044d6b1  7405                   -je 0x44d6b8
    if (cpu.flags.zf)
    {
        goto L_0x0044d6b8;
    }
    // 0044d6b3  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0044d6b6  eb02                   -jmp 0x44d6ba
    goto L_0x0044d6ba;
L_0x0044d6b8:
    // 0044d6b8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044d6ba:
    // 0044d6ba  899168bc6f00           -mov dword ptr [ecx + 0x6fbc68], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(7322728) /* 0x6fbc68 */) = cpu.edx;
    // 0044d6c0  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0044d6c7  69c8a4010000           -imul ecx, eax, 0x1a4
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d6cd  8bba10886700           -mov edi, dword ptr [edx + 0x678810]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785040) /* 0x678810 */);
    // 0044d6d3  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d6d6  7405                   -je 0x44d6dd
    if (cpu.flags.zf)
    {
        goto L_0x0044d6dd;
    }
    // 0044d6d8  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0044d6db  eb02                   -jmp 0x44d6df
    goto L_0x0044d6df;
L_0x0044d6dd:
    // 0044d6dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044d6df:
    // 0044d6df  89916cbc6f00           -mov dword ptr [ecx + 0x6fbc6c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(7322732) /* 0x6fbc6c */) = cpu.edx;
    // 0044d6e5  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0044d6ec  8b8af8876700           -mov ecx, dword ptr [edx + 0x6787f8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785016) /* 0x6787f8 */);
    // 0044d6f2  83f902                 +cmp ecx, 2
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
    // 0044d6f5  7407                   -je 0x44d6fe
    if (cpu.flags.zf)
    {
        goto L_0x0044d6fe;
    }
    // 0044d6f7  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0044d6fa  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0044d6fc  eb06                   -jmp 0x44d704
    goto L_0x0044d704;
L_0x0044d6fe:
    // 0044d6fe  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0044d704:
    // 0044d704  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0044d70b  69c0a4010000           -imul eax, eax, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d711  8bb228886700           -mov esi, dword ptr [edx + 0x678828]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785064) /* 0x678828 */);
    // 0044d717  83fe05                 +cmp esi, 5
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
    // 0044d71a  740b                   -je 0x44d727
    if (cpu.flags.zf)
    {
        goto L_0x0044d727;
    }
    // 0044d71c  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044d71f  899064bc6f00           -mov dword ptr [eax + 0x6fbc64], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7322724) /* 0x6fbc64 */) = cpu.edx;
    // 0044d725  eb08                   -jmp 0x44d72f
    goto L_0x0044d72f;
L_0x0044d727:
    // 0044d727  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0044d729  89b864bc6f00           -mov dword ptr [eax + 0x6fbc64], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7322724) /* 0x6fbc64 */) = cpu.edi;
L_0x0044d72f:
    // 0044d72f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d731  e88a6d0300             -call 0x4844c0
    cpu.esp -= 4;
    sub_4844c0(app, cpu);
    if (cpu.terminate) return;
    // 0044d736  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0044d739  8b4316                 -mov eax, dword ptr [ebx + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(22) /* 0x16 */);
    // 0044d73c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044d73f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044d742  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044d744  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044d74b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044d74d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044d750  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044d752  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044d755  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044d75a  833805                 +cmp dword ptr [eax], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044d75d  7530                   -jne 0x44d78f
    if (!cpu.flags.zf)
    {
        goto L_0x0044d78f;
    }
    // 0044d75f  ba3c945300             -mov edx, 0x53943c
    cpu.edx = 5477436 /*0x53943c*/;
    // 0044d764  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0044d767  e85452ffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 0044d76c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d76e  741f                   -je 0x44d78f
    if (cpu.flags.zf)
    {
        goto L_0x0044d78f;
    }
    // 0044d770  b96c170000             -mov ecx, 0x176c
    cpu.ecx = 5996 /*0x176c*/;
    // 0044d775  bea02c6600             -mov esi, 0x662ca0
    cpu.esi = 6696096 /*0x662ca0*/;
    // 0044d77a  bf4cbb6f00             -mov edi, 0x6fbb4c
    cpu.edi = 7322444 /*0x6fbb4c*/;
    // 0044d77f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044d780  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d782  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044d785  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044d787  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044d789  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044d78c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044d78e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0044d78f:
    // 0044d78f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d791  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d792  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d793  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d794  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d795  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d796  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d797  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_44d7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d7a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044d7a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d7a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d7a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044d7a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044d7a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d7a6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d7a8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044d7aa  b96c170000             -mov ecx, 0x176c
    cpu.ecx = 5996 /*0x176c*/;
    // 0044d7af  be4cbb6f00             -mov esi, 0x6fbb4c
    cpu.esi = 7322444 /*0x6fbb4c*/;
    // 0044d7b4  bfa02c6600             -mov edi, 0x662ca0
    cpu.edi = 6696096 /*0x662ca0*/;
    // 0044d7b9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044d7be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044d7bf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044d7c1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044d7c4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044d7c6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044d7c8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044d7cb  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044d7cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d7ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d7d0  89151c1b7900           -mov dword ptr [0x791b1c], edx
    app->getMemory<x86::reg32>(x86::reg32(7936796) /* 0x791b1c */) = cpu.edx;
    // 0044d7d6  e8f553fdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044d7db  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044d7e2  7407                   -je 0x44d7eb
    if (cpu.flags.zf)
    {
        goto L_0x0044d7eb;
    }
    // 0044d7e4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0044d7e9  eb02                   -jmp 0x44d7ed
    goto L_0x0044d7ed;
L_0x0044d7eb:
    // 0044d7eb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0044d7ed:
    // 0044d7ed  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044d7f2  e8d953fdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044d7f7  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044d7fe  7407                   -je 0x44d807
    if (cpu.flags.zf)
    {
        goto L_0x0044d807;
    }
    // 0044d800  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0044d805  eb02                   -jmp 0x44d809
    goto L_0x0044d809;
L_0x0044d807:
    // 0044d807  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0044d809:
    // 0044d809  69c1a4010000           -imul eax, ecx, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d80f  8bb8b8bf6f00           -mov edi, dword ptr [eax + 0x6fbfb8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7323576) /* 0x6fbfb8 */);
    // 0044d815  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044d817  7507                   -jne 0x44d820
    if (!cpu.flags.zf)
    {
        goto L_0x0044d820;
    }
    // 0044d819  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044d81e  eb02                   -jmp 0x44d822
    goto L_0x0044d822;
L_0x0044d820:
    // 0044d820  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044d822:
    // 0044d822  a3f07d6700             -mov dword ptr [0x677df0], eax
    app->getMemory<x86::reg32>(x86::reg32(6782448) /* 0x677df0 */) = cpu.eax;
    // 0044d827  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044d829  7507                   -jne 0x44d832
    if (!cpu.flags.zf)
    {
        goto L_0x0044d832;
    }
    // 0044d82b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044d830  eb02                   -jmp 0x44d834
    goto L_0x0044d834;
L_0x0044d832:
    // 0044d832  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044d834:
    // 0044d834  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0044d839  ba08945300             -mov edx, 0x539408
    cpu.edx = 5477384 /*0x539408*/;
    // 0044d83e  a3f47d6700             -mov dword ptr [0x677df4], eax
    app->getMemory<x86::reg32>(x86::reg32(6782452) /* 0x677df4 */) = cpu.eax;
    // 0044d843  e8e83c0000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
    // 0044d848  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d84a  e8f151ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d84f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d851  743c                   -je 0x44d88f
    if (cpu.flags.zf)
    {
        goto L_0x0044d88f;
    }
    // 0044d853  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044d855  7419                   -je 0x44d870
    if (cpu.flags.zf)
    {
        goto L_0x0044d870;
    }
    // 0044d857  d9054cc16f00           +fld dword ptr [0x6fc14c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7323980) /* 0x6fc14c */)));
    // 0044d85d  d80574945300           +fadd dword ptr [0x539474]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5477492) /* 0x539474 */));
    // 0044d863  d80d78945300           +fmul dword ptr [0x539478]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477496) /* 0x539478 */));
    // 0044d869  ba20d04400             -mov edx, 0x44d020
    cpu.edx = 4509728 /*0x44d020*/;
    // 0044d86e  eb17                   -jmp 0x44d887
    goto L_0x0044d887;
L_0x0044d870:
    // 0044d870  d905a8bf6f00           -fld dword ptr [0x6fbfa8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7323560) /* 0x6fbfa8 */)));
    // 0044d876  d80574945300           -fadd dword ptr [0x539474]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5477492) /* 0x539474 */));
    // 0044d87c  d80d78945300           -fmul dword ptr [0x539478]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477496) /* 0x539478 */));
    // 0044d882  ba60d04400             -mov edx, 0x44d060
    cpu.edx = 4509792 /*0x44d060*/;
L_0x0044d887:
    // 0044d887  d95854                 -fstp dword ptr [eax + 0x54]
    app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044d88a  e831f20100             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x0044d88f:
    // 0044d88f  ba14945300             -mov edx, 0x539414
    cpu.edx = 5477396 /*0x539414*/;
    // 0044d894  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d896  e8a551ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044d89b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044d89d  742e                   -je 0x44d8cd
    if (cpu.flags.zf)
    {
        goto L_0x0044d8cd;
    }
    // 0044d89f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044d8a1  7416                   -je 0x44d8b9
    if (cpu.flags.zf)
    {
        goto L_0x0044d8b9;
    }
    // 0044d8a3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044d8a5  7409                   -je 0x44d8b0
    if (cpu.flags.zf)
    {
        goto L_0x0044d8b0;
    }
    // 0044d8a7  c740404c945300         -mov dword ptr [eax + 0x40], 0x53944c
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477452 /*0x53944c*/;
    // 0044d8ae  eb1d                   -jmp 0x44d8cd
    goto L_0x0044d8cd;
L_0x0044d8b0:
    // 0044d8b0  c7404054945300         -mov dword ptr [eax + 0x40], 0x539454
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477460 /*0x539454*/;
    // 0044d8b7  eb14                   -jmp 0x44d8cd
    goto L_0x0044d8cd;
L_0x0044d8b9:
    // 0044d8b9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044d8bb  7409                   -je 0x44d8c6
    if (cpu.flags.zf)
    {
        goto L_0x0044d8c6;
    }
    // 0044d8bd  c7404060945300         -mov dword ptr [eax + 0x40], 0x539460
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477472 /*0x539460*/;
    // 0044d8c4  eb07                   -jmp 0x44d8cd
    goto L_0x0044d8cd;
L_0x0044d8c6:
    // 0044d8c6  c740406c945300         -mov dword ptr [eax + 0x40], 0x53946c
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477484 /*0x53946c*/;
L_0x0044d8cd:
    // 0044d8cd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d8cf  e8fce9ffff             -call 0x44c2d0
    cpu.esp -= 4;
    sub_44c2d0(app, cpu);
    if (cpu.terminate) return;
    // 0044d8d4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044d8d6  7409                   -je 0x44d8e1
    if (cpu.flags.zf)
    {
        goto L_0x0044d8e1;
    }
    // 0044d8d8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d8da  e881eaffff             -call 0x44c360
    cpu.esp -= 4;
    sub_44c360(app, cpu);
    if (cpu.terminate) return;
    // 0044d8df  eb07                   -jmp 0x44d8e8
    goto L_0x0044d8e8;
L_0x0044d8e1:
    // 0044d8e1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044d8e3  e8f8ebffff             -call 0x44c4e0
    cpu.esp -= 4;
    sub_44c4e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044d8e8:
    // 0044d8e8  69d9a4010000           -imul ebx, ecx, 0x1a4
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d8ee  8bb3b0bf6f00           -mov esi, dword ptr [ebx + 0x6fbfb0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7323568) /* 0x6fbfb0 */);
    // 0044d8f4  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044d8fb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044d8fd  740b                   -je 0x44d90a
    if (cpu.flags.zf)
    {
        goto L_0x0044d90a;
    }
    // 0044d8ff  8d5eff                 -lea ebx, [esi - 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0044d902  899848886700           -mov dword ptr [eax + 0x678848], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785096) /* 0x678848 */) = cpu.ebx;
    // 0044d908  eb0a                   -jmp 0x44d914
    goto L_0x0044d914;
L_0x0044d90a:
    // 0044d90a  c7804888670004000000   -mov dword ptr [eax + 0x678848], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785096) /* 0x678848 */) = 4 /*0x4*/;
L_0x0044d914:
    // 0044d914  69d9a4010000           -imul ebx, ecx, 0x1a4
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d91a  8bb3b4bf6f00           -mov esi, dword ptr [ebx + 0x6fbfb4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7323572) /* 0x6fbfb4 */);
    // 0044d920  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044d927  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044d929  740b                   -je 0x44d936
    if (cpu.flags.zf)
    {
        goto L_0x0044d936;
    }
    // 0044d92b  8d5eff                 -lea ebx, [esi - 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0044d92e  899818886700           -mov dword ptr [eax + 0x678818], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785048) /* 0x678818 */) = cpu.ebx;
    // 0044d934  eb0a                   -jmp 0x44d940
    goto L_0x0044d940;
L_0x0044d936:
    // 0044d936  c7801888670003000000   -mov dword ptr [eax + 0x678818], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785048) /* 0x678818 */) = 3 /*0x3*/;
L_0x0044d940:
    // 0044d940  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044d947  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044d949  7409                   -je 0x44d954
    if (cpu.flags.zf)
    {
        goto L_0x0044d954;
    }
    // 0044d94b  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044d94c  89b800886700           -mov dword ptr [eax + 0x678800], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785024) /* 0x678800 */) = cpu.edi;
    // 0044d952  eb0a                   -jmp 0x44d95e
    goto L_0x0044d95e;
L_0x0044d954:
    // 0044d954  c7800088670002000000   -mov dword ptr [eax + 0x678800], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785024) /* 0x678800 */) = 2 /*0x2*/;
L_0x0044d95e:
    // 0044d95e  69d9a4010000           -imul ebx, ecx, 0x1a4
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d964  8bb3acbf6f00           -mov esi, dword ptr [ebx + 0x6fbfac]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7323564) /* 0x6fbfac */);
    // 0044d96a  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044d971  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044d973  740b                   -je 0x44d980
    if (cpu.flags.zf)
    {
        goto L_0x0044d980;
    }
    // 0044d975  8d4eff                 -lea ecx, [esi - 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0044d978  898830886700           -mov dword ptr [eax + 0x678830], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785072) /* 0x678830 */) = cpu.ecx;
    // 0044d97e  eb0a                   -jmp 0x44d98a
    goto L_0x0044d98a;
L_0x0044d980:
    // 0044d980  c7803088670005000000   -mov dword ptr [eax + 0x678830], 5
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785072) /* 0x678830 */) = 5 /*0x5*/;
L_0x0044d98a:
    // 0044d98a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d98c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d98d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d98e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d98f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d990  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d991  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044d992  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44d9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044d9a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044d9a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044d9a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044d9a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044d9a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044d9a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044d9a6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044d9a8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044d9aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044d9ac  e81f52fdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044d9b1  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044d9b8  7407                   -je 0x44d9c1
    if (cpu.flags.zf)
    {
        goto L_0x0044d9c1;
    }
    // 0044d9ba  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044d9bf  eb02                   -jmp 0x44d9c3
    goto L_0x0044d9c3;
L_0x0044d9c1:
    // 0044d9c1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044d9c3:
    // 0044d9c3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044d9c5  69caa4010000           -imul ecx, edx, 0x1a4
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d9cb  be98bf6f00             -mov esi, 0x6fbf98
    cpu.esi = 7323544 /*0x6fbf98*/;
    // 0044d9d0  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0044d9d3  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044d9d5  8bba48886700           -mov edi, dword ptr [edx + 0x678848]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785096) /* 0x678848 */);
    // 0044d9db  83c620                 -add esi, 0x20
    (cpu.esi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0044d9de  83ff04                 +cmp edi, 4
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
    // 0044d9e1  7405                   -je 0x44d9e8
    if (cpu.flags.zf)
    {
        goto L_0x0044d9e8;
    }
    // 0044d9e3  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0044d9e6  eb02                   -jmp 0x44d9ea
    goto L_0x0044d9ea;
L_0x0044d9e8:
    // 0044d9e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044d9ea:
    // 0044d9ea  8991b0bf6f00           -mov dword ptr [ecx + 0x6fbfb0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(7323568) /* 0x6fbfb0 */) = cpu.edx;
    // 0044d9f0  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0044d9f7  69c8a4010000           -imul ecx, eax, 0x1a4
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044d9fd  8bba18886700           -mov edi, dword ptr [edx + 0x678818]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785048) /* 0x678818 */);
    // 0044da03  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044da06  7405                   -je 0x44da0d
    if (cpu.flags.zf)
    {
        goto L_0x0044da0d;
    }
    // 0044da08  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0044da0b  eb02                   -jmp 0x44da0f
    goto L_0x0044da0f;
L_0x0044da0d:
    // 0044da0d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044da0f:
    // 0044da0f  8991b4bf6f00           -mov dword ptr [ecx + 0x6fbfb4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(7323572) /* 0x6fbfb4 */) = cpu.edx;
    // 0044da15  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0044da1c  8b8a00886700           -mov ecx, dword ptr [edx + 0x678800]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785024) /* 0x678800 */);
    // 0044da22  83f902                 +cmp ecx, 2
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
    // 0044da25  7407                   -je 0x44da2e
    if (cpu.flags.zf)
    {
        goto L_0x0044da2e;
    }
    // 0044da27  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0044da2a  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0044da2c  eb06                   -jmp 0x44da34
    goto L_0x0044da34;
L_0x0044da2e:
    // 0044da2e  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0044da34:
    // 0044da34  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0044da3b  69c0a4010000           -imul eax, eax, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044da41  8bb230886700           -mov esi, dword ptr [edx + 0x678830]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785072) /* 0x678830 */);
    // 0044da47  83fe05                 +cmp esi, 5
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
    // 0044da4a  740b                   -je 0x44da57
    if (cpu.flags.zf)
    {
        goto L_0x0044da57;
    }
    // 0044da4c  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044da4f  8990acbf6f00           -mov dword ptr [eax + 0x6fbfac], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7323564) /* 0x6fbfac */) = cpu.edx;
    // 0044da55  eb08                   -jmp 0x44da5f
    goto L_0x0044da5f;
L_0x0044da57:
    // 0044da57  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0044da59  89b8acbf6f00           -mov dword ptr [eax + 0x6fbfac], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7323564) /* 0x6fbfac */) = cpu.edi;
L_0x0044da5f:
    // 0044da5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044da61  e85a6a0300             -call 0x4844c0
    cpu.esp -= 4;
    sub_4844c0(app, cpu);
    if (cpu.terminate) return;
    // 0044da66  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0044da69  8b4316                 -mov eax, dword ptr [ebx + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(22) /* 0x16 */);
    // 0044da6c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044da6f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044da72  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044da74  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044da7b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044da7d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044da80  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044da82  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044da85  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044da8a  833805                 +cmp dword ptr [eax], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044da8d  7530                   -jne 0x44dabf
    if (!cpu.flags.zf)
    {
        goto L_0x0044dabf;
    }
    // 0044da8f  ba3c945300             -mov edx, 0x53943c
    cpu.edx = 5477436 /*0x53943c*/;
    // 0044da94  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0044da97  e8244fffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 0044da9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044da9e  741f                   -je 0x44dabf
    if (cpu.flags.zf)
    {
        goto L_0x0044dabf;
    }
    // 0044daa0  b96c170000             -mov ecx, 0x176c
    cpu.ecx = 5996 /*0x176c*/;
    // 0044daa5  bea02c6600             -mov esi, 0x662ca0
    cpu.esi = 6696096 /*0x662ca0*/;
    // 0044daaa  bf4cbb6f00             -mov edi, 0x6fbb4c
    cpu.edi = 7322444 /*0x6fbb4c*/;
    // 0044daaf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044dab0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044dab2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044dab5  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044dab7  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044dab9  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044dabc  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044dabe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0044dabf:
    // 0044dabf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044dac1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dac2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dac3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dac4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dac5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dac6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dac7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_44dad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044dad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044dad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044dad2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044dad3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044dad4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044dad5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044dad6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044dad8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044dada  b96c170000             -mov ecx, 0x176c
    cpu.ecx = 5996 /*0x176c*/;
    // 0044dadf  be4cbb6f00             -mov esi, 0x6fbb4c
    cpu.esi = 7322444 /*0x6fbb4c*/;
    // 0044dae4  bfa02c6600             -mov edi, 0x662ca0
    cpu.edi = 6696096 /*0x662ca0*/;
    // 0044dae9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044daee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044daef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044daf1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044daf4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044daf6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044daf8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044dafb  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044dafd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dafe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044db00  89151c1b7900           -mov dword ptr [0x791b1c], edx
    app->getMemory<x86::reg32>(x86::reg32(7936796) /* 0x791b1c */) = cpu.edx;
    // 0044db06  e8c550fdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044db0b  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044db12  7407                   -je 0x44db1b
    if (cpu.flags.zf)
    {
        goto L_0x0044db1b;
    }
    // 0044db14  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044db19  eb02                   -jmp 0x44db1d
    goto L_0x0044db1d;
L_0x0044db1b:
    // 0044db1b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044db1d:
    // 0044db1d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044db22  e8a950fdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044db27  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0044db29  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044db30  7407                   -je 0x44db39
    if (cpu.flags.zf)
    {
        goto L_0x0044db39;
    }
    // 0044db32  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044db37  eb02                   -jmp 0x44db3b
    goto L_0x0044db3b;
L_0x0044db39:
    // 0044db39  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044db3b:
    // 0044db3b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044db3d  69c0a4010000           -imul eax, eax, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044db43  8bb000c36f00           -mov esi, dword ptr [eax + 0x6fc300]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7324416) /* 0x6fc300 */);
    // 0044db49  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044db4b  7507                   -jne 0x44db54
    if (!cpu.flags.zf)
    {
        goto L_0x0044db54;
    }
    // 0044db4d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044db52  eb02                   -jmp 0x44db56
    goto L_0x0044db56;
L_0x0044db54:
    // 0044db54  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044db56:
    // 0044db56  a3f07d6700             -mov dword ptr [0x677df0], eax
    app->getMemory<x86::reg32>(x86::reg32(6782448) /* 0x677df0 */) = cpu.eax;
    // 0044db5b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044db5d  7507                   -jne 0x44db66
    if (!cpu.flags.zf)
    {
        goto L_0x0044db66;
    }
    // 0044db5f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044db64  eb02                   -jmp 0x44db68
    goto L_0x0044db68;
L_0x0044db66:
    // 0044db66  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044db68:
    // 0044db68  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0044db6d  ba08945300             -mov edx, 0x539408
    cpu.edx = 5477384 /*0x539408*/;
    // 0044db72  a3f47d6700             -mov dword ptr [0x677df4], eax
    app->getMemory<x86::reg32>(x86::reg32(6782452) /* 0x677df4 */) = cpu.eax;
    // 0044db77  e8b4390000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
    // 0044db7c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044db7e  e8bd4effff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044db83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044db85  743c                   -je 0x44dbc3
    if (cpu.flags.zf)
    {
        goto L_0x0044dbc3;
    }
    // 0044db87  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044db89  7419                   -je 0x44dba4
    if (cpu.flags.zf)
    {
        goto L_0x0044dba4;
    }
    // 0044db8b  d90594c46f00           +fld dword ptr [0x6fc494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7324820) /* 0x6fc494 */)));
    // 0044db91  d8057c945300           +fadd dword ptr [0x53947c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5477500) /* 0x53947c */));
    // 0044db97  d80d80945300           +fmul dword ptr [0x539480]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477504) /* 0x539480 */));
    // 0044db9d  baa0d04400             -mov edx, 0x44d0a0
    cpu.edx = 4509856 /*0x44d0a0*/;
    // 0044dba2  eb17                   -jmp 0x44dbbb
    goto L_0x0044dbbb;
L_0x0044dba4:
    // 0044dba4  d905f0c26f00           -fld dword ptr [0x6fc2f0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7324400) /* 0x6fc2f0 */)));
    // 0044dbaa  d8057c945300           -fadd dword ptr [0x53947c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5477500) /* 0x53947c */));
    // 0044dbb0  d80d80945300           -fmul dword ptr [0x539480]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477504) /* 0x539480 */));
    // 0044dbb6  bae0d04400             -mov edx, 0x44d0e0
    cpu.edx = 4509920 /*0x44d0e0*/;
L_0x0044dbbb:
    // 0044dbbb  d95854                 -fstp dword ptr [eax + 0x54]
    app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044dbbe  e8fdee0100             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x0044dbc3:
    // 0044dbc3  ba14945300             -mov edx, 0x539414
    cpu.edx = 5477396 /*0x539414*/;
    // 0044dbc8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044dbca  e8714effff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044dbcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044dbd1  742e                   -je 0x44dc01
    if (cpu.flags.zf)
    {
        goto L_0x0044dc01;
    }
    // 0044dbd3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044dbd5  7416                   -je 0x44dbed
    if (cpu.flags.zf)
    {
        goto L_0x0044dbed;
    }
    // 0044dbd7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044dbd9  7409                   -je 0x44dbe4
    if (cpu.flags.zf)
    {
        goto L_0x0044dbe4;
    }
    // 0044dbdb  c740404c945300         -mov dword ptr [eax + 0x40], 0x53944c
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477452 /*0x53944c*/;
    // 0044dbe2  eb1d                   -jmp 0x44dc01
    goto L_0x0044dc01;
L_0x0044dbe4:
    // 0044dbe4  c7404054945300         -mov dword ptr [eax + 0x40], 0x539454
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477460 /*0x539454*/;
    // 0044dbeb  eb14                   -jmp 0x44dc01
    goto L_0x0044dc01;
L_0x0044dbed:
    // 0044dbed  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044dbef  7409                   -je 0x44dbfa
    if (cpu.flags.zf)
    {
        goto L_0x0044dbfa;
    }
    // 0044dbf1  c7404060945300         -mov dword ptr [eax + 0x40], 0x539460
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477472 /*0x539460*/;
    // 0044dbf8  eb07                   -jmp 0x44dc01
    goto L_0x0044dc01;
L_0x0044dbfa:
    // 0044dbfa  c740406c945300         -mov dword ptr [eax + 0x40], 0x53946c
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 5477484 /*0x53946c*/;
L_0x0044dc01:
    // 0044dc01  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044dc03  e8c8e6ffff             -call 0x44c2d0
    cpu.esp -= 4;
    sub_44c2d0(app, cpu);
    if (cpu.terminate) return;
    // 0044dc08  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044dc0a  7409                   -je 0x44dc15
    if (cpu.flags.zf)
    {
        goto L_0x0044dc15;
    }
    // 0044dc0c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044dc0e  e84de7ffff             -call 0x44c360
    cpu.esp -= 4;
    sub_44c360(app, cpu);
    if (cpu.terminate) return;
    // 0044dc13  eb07                   -jmp 0x44dc1c
    goto L_0x0044dc1c;
L_0x0044dc15:
    // 0044dc15  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044dc17  e8c4e8ffff             -call 0x44c4e0
    cpu.esp -= 4;
    sub_44c4e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044dc1c:
    // 0044dc1c  69c1a4010000           -imul eax, ecx, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044dc22  8b98f8c26f00           -mov ebx, dword ptr [eax + 0x6fc2f8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7324408) /* 0x6fc2f8 */);
    // 0044dc28  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0044dc2f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044dc31  740b                   -je 0x44dc3e
    if (cpu.flags.zf)
    {
        goto L_0x0044dc3e;
    }
    // 0044dc33  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0044dc36  898250886700           -mov dword ptr [edx + 0x678850], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785104) /* 0x678850 */) = cpu.eax;
    // 0044dc3c  eb0a                   -jmp 0x44dc48
    goto L_0x0044dc48;
L_0x0044dc3e:
    // 0044dc3e  c7825088670004000000   -mov dword ptr [edx + 0x678850], 4
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785104) /* 0x678850 */) = 4 /*0x4*/;
L_0x0044dc48:
    // 0044dc48  69c1a4010000           -imul eax, ecx, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044dc4e  8b98fcc26f00           -mov ebx, dword ptr [eax + 0x6fc2fc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7324412) /* 0x6fc2fc */);
    // 0044dc54  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0044dc5b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044dc5d  740b                   -je 0x44dc6a
    if (cpu.flags.zf)
    {
        goto L_0x0044dc6a;
    }
    // 0044dc5f  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0044dc62  898220886700           -mov dword ptr [edx + 0x678820], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785056) /* 0x678820 */) = cpu.eax;
    // 0044dc68  eb0a                   -jmp 0x44dc74
    goto L_0x0044dc74;
L_0x0044dc6a:
    // 0044dc6a  c7822088670003000000   -mov dword ptr [edx + 0x678820], 3
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785056) /* 0x678820 */) = 3 /*0x3*/;
L_0x0044dc74:
    // 0044dc74  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044dc7b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044dc7d  7409                   -je 0x44dc88
    if (cpu.flags.zf)
    {
        goto L_0x0044dc88;
    }
    // 0044dc7f  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044dc80  89b008886700           -mov dword ptr [eax + 0x678808], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785032) /* 0x678808 */) = cpu.esi;
    // 0044dc86  eb0a                   -jmp 0x44dc92
    goto L_0x0044dc92;
L_0x0044dc88:
    // 0044dc88  c7800888670002000000   -mov dword ptr [eax + 0x678808], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785032) /* 0x678808 */) = 2 /*0x2*/;
L_0x0044dc92:
    // 0044dc92  69d1a4010000           -imul edx, ecx, 0x1a4
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044dc98  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044dc9f  83baf4c26f0000         +cmp dword ptr [edx + 0x6fc2f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7324404) /* 0x6fc2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044dca6  740f                   -je 0x44dcb7
    if (cpu.flags.zf)
    {
        goto L_0x0044dcb7;
    }
    // 0044dca8  8b92acbf6f00           -mov edx, dword ptr [edx + 0x6fbfac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7323564) /* 0x6fbfac */);
    // 0044dcae  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044dcaf  899038886700           -mov dword ptr [eax + 0x678838], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785080) /* 0x678838 */) = cpu.edx;
    // 0044dcb5  eb0a                   -jmp 0x44dcc1
    goto L_0x0044dcc1;
L_0x0044dcb7:
    // 0044dcb7  c7803888670005000000   -mov dword ptr [eax + 0x678838], 5
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6785080) /* 0x678838 */) = 5 /*0x5*/;
L_0x0044dcc1:
    // 0044dcc1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044dcc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dcc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dcc5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dcc6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dcc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dcc8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dcc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_44dcd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044dcd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044dcd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044dcd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044dcd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044dcd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044dcd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044dcd6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044dcd8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044dcda  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044dcdf  e8ec4efdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044dce4  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044dceb  7407                   -je 0x44dcf4
    if (cpu.flags.zf)
    {
        goto L_0x0044dcf4;
    }
    // 0044dced  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044dcf2  eb02                   -jmp 0x44dcf6
    goto L_0x0044dcf6;
L_0x0044dcf4:
    // 0044dcf4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044dcf6:
    // 0044dcf6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044dcf8  69caa4010000           -imul ecx, edx, 0x1a4
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044dcfe  bee0c26f00             -mov esi, 0x6fc2e0
    cpu.esi = 7324384 /*0x6fc2e0*/;
    // 0044dd03  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0044dd06  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044dd08  8bba50886700           -mov edi, dword ptr [edx + 0x678850]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785104) /* 0x678850 */);
    // 0044dd0e  83c620                 -add esi, 0x20
    (cpu.esi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0044dd11  83ff04                 +cmp edi, 4
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
    // 0044dd14  7405                   -je 0x44dd1b
    if (cpu.flags.zf)
    {
        goto L_0x0044dd1b;
    }
    // 0044dd16  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0044dd19  eb02                   -jmp 0x44dd1d
    goto L_0x0044dd1d;
L_0x0044dd1b:
    // 0044dd1b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044dd1d:
    // 0044dd1d  8991f8c26f00           -mov dword ptr [ecx + 0x6fc2f8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(7324408) /* 0x6fc2f8 */) = cpu.edx;
    // 0044dd23  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0044dd2a  69c8a4010000           -imul ecx, eax, 0x1a4
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044dd30  8bba20886700           -mov edi, dword ptr [edx + 0x678820]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785056) /* 0x678820 */);
    // 0044dd36  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044dd39  7405                   -je 0x44dd40
    if (cpu.flags.zf)
    {
        goto L_0x0044dd40;
    }
    // 0044dd3b  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0044dd3e  eb02                   -jmp 0x44dd42
    goto L_0x0044dd42;
L_0x0044dd40:
    // 0044dd40  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044dd42:
    // 0044dd42  8991fcc26f00           -mov dword ptr [ecx + 0x6fc2fc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(7324412) /* 0x6fc2fc */) = cpu.edx;
    // 0044dd48  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0044dd4f  8b8a08886700           -mov ecx, dword ptr [edx + 0x678808]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785032) /* 0x678808 */);
    // 0044dd55  83f902                 +cmp ecx, 2
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
    // 0044dd58  7407                   -je 0x44dd61
    if (cpu.flags.zf)
    {
        goto L_0x0044dd61;
    }
    // 0044dd5a  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0044dd5d  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0044dd5f  eb06                   -jmp 0x44dd67
    goto L_0x0044dd67;
L_0x0044dd61:
    // 0044dd61  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0044dd67:
    // 0044dd67  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0044dd6e  69c0a4010000           -imul eax, eax, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044dd74  8bb238886700           -mov esi, dword ptr [edx + 0x678838]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6785080) /* 0x678838 */);
    // 0044dd7a  83fe05                 +cmp esi, 5
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
    // 0044dd7d  740b                   -je 0x44dd8a
    if (cpu.flags.zf)
    {
        goto L_0x0044dd8a;
    }
    // 0044dd7f  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044dd82  8990f4c26f00           -mov dword ptr [eax + 0x6fc2f4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7324404) /* 0x6fc2f4 */) = cpu.edx;
    // 0044dd88  eb08                   -jmp 0x44dd92
    goto L_0x0044dd92;
L_0x0044dd8a:
    // 0044dd8a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0044dd8c  89b8f4c26f00           -mov dword ptr [eax + 0x6fc2f4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7324404) /* 0x6fc2f4 */) = cpu.edi;
L_0x0044dd92:
    // 0044dd92  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044dd97  e824670300             -call 0x4844c0
    cpu.esp -= 4;
    sub_4844c0(app, cpu);
    if (cpu.terminate) return;
    // 0044dd9c  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0044dd9f  8b4316                 -mov eax, dword ptr [ebx + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(22) /* 0x16 */);
    // 0044dda2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044dda5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044dda8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044ddaa  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044ddb1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044ddb3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044ddb6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044ddb8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044ddbb  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044ddc0  833805                 +cmp dword ptr [eax], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044ddc3  7530                   -jne 0x44ddf5
    if (!cpu.flags.zf)
    {
        goto L_0x0044ddf5;
    }
    // 0044ddc5  ba3c945300             -mov edx, 0x53943c
    cpu.edx = 5477436 /*0x53943c*/;
    // 0044ddca  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0044ddcd  e8ee4bffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 0044ddd2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044ddd4  741f                   -je 0x44ddf5
    if (cpu.flags.zf)
    {
        goto L_0x0044ddf5;
    }
    // 0044ddd6  b96c170000             -mov ecx, 0x176c
    cpu.ecx = 5996 /*0x176c*/;
    // 0044dddb  bea02c6600             -mov esi, 0x662ca0
    cpu.esi = 6696096 /*0x662ca0*/;
    // 0044dde0  bf4cbb6f00             -mov edi, 0x6fbb4c
    cpu.edi = 7322444 /*0x6fbb4c*/;
    // 0044dde5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044dde6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044dde8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044ddeb  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044dded  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044ddef  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044ddf2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044ddf4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0044ddf5:
    // 0044ddf5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044ddf7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ddf8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ddf9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ddfa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ddfb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ddfc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044ddfd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_44de00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044de00  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044de01  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044de03  6683fb0d               +cmp bx, 0xd
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
    // 0044de07  750a                   -jne 0x44de13
    if (!cpu.flags.zf)
    {
        goto L_0x0044de13;
    }
    // 0044de09  c7050c44660001000000   -mov dword ptr [0x66440c], 1
    app->getMemory<x86::reg32>(x86::reg32(6702092) /* 0x66440c */) = 1 /*0x1*/;
L_0x0044de13:
    // 0044de13  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044de16  e855340100             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 0044de1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044de1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_44de20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044de20  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044de21  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044de23  6683fb0d               +cmp bx, 0xd
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
    // 0044de27  754c                   -jne 0x44de75
    if (!cpu.flags.zf)
    {
        goto L_0x0044de75;
    }
    // 0044de29  e852780300             -call 0x485680
    cpu.esp -= 4;
    sub_485680(app, cpu);
    if (cpu.terminate) return;
    // 0044de2e  668b5a18               -mov bx, word ptr [edx + 0x18]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(24) /* 0x18 */);
L_0x0044de32:
    // 0044de32  0fbfd3                 -movsx edx, bx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044de35  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044de3c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044de3e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044de41  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044de43  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044de46  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044de4d  741f                   -je 0x44de6e
    if (cpu.flags.zf)
    {
        goto L_0x0044de6e;
    }
    // 0044de4f  bae04e6000             -mov edx, 0x604ee0
    cpu.edx = 6311648 /*0x604ee0*/;
    // 0044de54  01c2                   +add edx, eax
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
    // 0044de56  7413                   -je 0x44de6b
    if (cpu.flags.zf)
    {
        goto L_0x0044de6b;
    }
    // 0044de58  833a1f                 +cmp dword ptr [edx], 0x1f
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044de5b  750e                   -jne 0x44de6b
    if (!cpu.flags.zf)
    {
        goto L_0x0044de6b;
    }
    // 0044de5d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044de5f  e82cec0000             -call 0x45ca90
    cpu.esp -= 4;
    sub_45ca90(app, cpu);
    if (cpu.terminate) return;
    // 0044de64  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044de66  e865eb0000             -call 0x45c9d0
    cpu.esp -= 4;
    sub_45c9d0(app, cpu);
    if (cpu.terminate) return;
L_0x0044de6b:
    // 0044de6b  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044de6c  ebc4                   -jmp 0x44de32
    goto L_0x0044de32;
L_0x0044de6e:
    // 0044de6e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044de73  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044de74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044de75:
    // 0044de75  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044de78  e8f3330100             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 0044de7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044de7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_44de80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044de80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044de81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044de82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044de83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044de84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044de85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044de86  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044de88  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044de8b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044de8d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044de8f  e83c4dfdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044de94  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044de9b  7407                   -je 0x44dea4
    if (cpu.flags.zf)
    {
        goto L_0x0044dea4;
    }
    // 0044de9d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044dea2  eb02                   -jmp 0x44dea6
    goto L_0x0044dea6;
L_0x0044dea4:
    // 0044dea4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044dea6:
    // 0044dea6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044dea8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044dead  e81e4dfdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044deb2  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044deb9  7407                   -je 0x44dec2
    if (cpu.flags.zf)
    {
        goto L_0x0044dec2;
    }
    // 0044debb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044dec0  eb02                   -jmp 0x44dec4
    goto L_0x0044dec4;
L_0x0044dec2:
    // 0044dec2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044dec4:
    // 0044dec4  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 0044dec9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044dece  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0044ded1  e85a360000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
    // 0044ded6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044ded8  891564925500           -mov dword ptr [0x559264], edx
    app->getMemory<x86::reg32>(x86::reg32(5608036) /* 0x559264 */) = cpu.edx;
    // 0044dede  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044dee0  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0044dee5  890d0c446600           -mov dword ptr [0x66440c], ecx
    app->getMemory<x86::reg32>(x86::reg32(6702092) /* 0x66440c */) = cpu.ecx;
    // 0044deeb  e8705afdff             -call 0x423960
    cpu.esp -= 4;
    sub_423960(app, cpu);
    if (cpu.terminate) return;
    // 0044def0  8b3db0d36f00           -mov edi, dword ptr [0x6fd3b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0044def6  83ff01                 +cmp edi, 1
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
    // 0044def9  750c                   -jne 0x44df07
    if (!cpu.flags.zf)
    {
        goto L_0x0044df07;
    }
    // 0044defb  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0044df00  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044df02  e8595afdff             -call 0x423960
    cpu.esp -= 4;
    sub_423960(app, cpu);
    if (cpu.terminate) return;
L_0x0044df07:
    // 0044df07  69f6a4010000           -imul esi, esi, 0x1a4
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044df0d  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044df14  7540                   -jne 0x44df56
    if (!cpu.flags.zf)
    {
        goto L_0x0044df56;
    }
    // 0044df16  b970010000             -mov ecx, 0x170
    cpu.ecx = 368 /*0x170*/;
    // 0044df1b  81c698bf6f00           -add esi, 0x6fbf98
    (cpu.esi) += x86::reg32(x86::sreg32(7323544 /*0x6fbf98*/));
    // 0044df21  bf90296600             -mov edi, 0x662990
    cpu.edi = 6695312 /*0x662990*/;
    // 0044df26  83c624                 -add esi, 0x24
    (cpu.esi) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0044df29  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044df2c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044df2d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044df2f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044df32  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044df34  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044df36  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044df39  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044df3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044df3c  69c2a4010000           -imul eax, edx, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044df42  b970010000             -mov ecx, 0x170
    cpu.ecx = 368 /*0x170*/;
    // 0044df47  05e0c26f00             +add eax, 0x6fc2e0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7324384 /*0x6fc2e0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044df4c  bf002b6600             -mov edi, 0x662b00
    cpu.edi = 6695680 /*0x662b00*/;
    // 0044df51  8d7024                 -lea esi, [eax + 0x24]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0044df54  eb13                   -jmp 0x44df69
    goto L_0x0044df69;
L_0x0044df56:
    // 0044df56  b970010000             -mov ecx, 0x170
    cpu.ecx = 368 /*0x170*/;
    // 0044df5b  81c650bc6f00           -add esi, 0x6fbc50
    (cpu.esi) += x86::reg32(x86::sreg32(7322704 /*0x6fbc50*/));
    // 0044df61  bf90296600             -mov edi, 0x662990
    cpu.edi = 6695312 /*0x662990*/;
    // 0044df66  83c624                 -add esi, 0x24
    (cpu.esi) += x86::reg32(x86::sreg32(36 /*0x24*/));
L_0x0044df69:
    // 0044df69  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044df6a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044df6c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044df6f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044df71  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044df73  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044df76  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044df78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044df79  ba84945300             -mov edx, 0x539484
    cpu.edx = 5477508 /*0x539484*/;
    // 0044df7e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044df80  e8bb4affff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044df85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044df87  7407                   -je 0x44df90
    if (cpu.flags.zf)
    {
        goto L_0x0044df90;
    }
    // 0044df89  c7403000de4400         -mov dword ptr [eax + 0x30], 0x44de00
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4513280 /*0x44de00*/;
L_0x0044df90:
    // 0044df90  ba8c945300             -mov edx, 0x53948c
    cpu.edx = 5477516 /*0x53948c*/;
    // 0044df95  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044df97  e8a44affff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044df9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044df9e  7407                   -je 0x44dfa7
    if (cpu.flags.zf)
    {
        goto L_0x0044dfa7;
    }
    // 0044dfa0  c7403020de4400         -mov dword ptr [eax + 0x30], 0x44de20
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4513312 /*0x44de20*/;
L_0x0044dfa7:
    // 0044dfa7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044dfa9  e8f2200300             -call 0x4800a0
    cpu.esp -= 4;
    sub_4800a0(app, cpu);
    if (cpu.terminate) return;
    // 0044dfae  8b0db0d36f00           -mov ecx, dword ptr [0x6fd3b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0044dfb4  83f901                 +cmp ecx, 1
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
    // 0044dfb7  7507                   -jne 0x44dfc0
    if (!cpu.flags.zf)
    {
        goto L_0x0044dfc0;
    }
    // 0044dfb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044dfbb  e8e0200300             -call 0x4800a0
    cpu.esp -= 4;
    sub_4800a0(app, cpu);
    if (cpu.terminate) return;
L_0x0044dfc0:
    // 0044dfc0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044dfc2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044dfc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dfc5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dfc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dfc7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dfc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dfc9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044dfca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44dfd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044dfd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044dfd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044dfd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044dfd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044dfd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044dfd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044dfd6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044dfd8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044dfda  e8f14bfdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044dfdf  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044dfe6  7407                   -je 0x44dfef
    if (cpu.flags.zf)
    {
        goto L_0x0044dfef;
    }
    // 0044dfe8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044dfed  eb02                   -jmp 0x44dff1
    goto L_0x0044dff1;
L_0x0044dfef:
    // 0044dfef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044dff1:
    // 0044dff1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044dff3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044dff8  e8d34bfdff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0044dffd  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0044e004  7407                   -je 0x44e00d
    if (cpu.flags.zf)
    {
        goto L_0x0044e00d;
    }
    // 0044e006  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0044e00b  eb02                   -jmp 0x44e00f
    goto L_0x0044e00f;
L_0x0044e00d:
    // 0044e00d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0044e00f:
    // 0044e00f  833d0c44660000         +cmp dword ptr [0x66440c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702092) /* 0x66440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044e016  0f85a8000000           -jne 0x44e0c4
    if (!cpu.flags.zf)
    {
        goto L_0x0044e0c4;
    }
    // 0044e01c  69c9a4010000           -imul ecx, ecx, 0x1a4
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044e022  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044e029  753b                   -jne 0x44e066
    if (!cpu.flags.zf)
    {
        goto L_0x0044e066;
    }
    // 0044e02b  b898bf6f00             -mov eax, 0x6fbf98
    cpu.eax = 7323544 /*0x6fbf98*/;
    // 0044e030  be90296600             -mov esi, 0x662990
    cpu.esi = 6695312 /*0x662990*/;
    // 0044e035  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044e037  b970010000             -mov ecx, 0x170
    cpu.ecx = 368 /*0x170*/;
    // 0044e03c  8d7824                 -lea edi, [eax + 0x24]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0044e03f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044e040  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044e042  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044e045  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044e047  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044e049  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044e04c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044e04e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044e04f  69c3a4010000           -imul eax, ebx, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 0044e055  b970010000             -mov ecx, 0x170
    cpu.ecx = 368 /*0x170*/;
    // 0044e05a  05e0c26f00             +add eax, 0x6fc2e0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7324384 /*0x6fc2e0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044e05f  be002b6600             -mov esi, 0x662b00
    cpu.esi = 6695680 /*0x662b00*/;
    // 0044e064  eb11                   -jmp 0x44e077
    goto L_0x0044e077;
L_0x0044e066:
    // 0044e066  b850bc6f00             -mov eax, 0x6fbc50
    cpu.eax = 7322704 /*0x6fbc50*/;
    // 0044e06b  be90296600             -mov esi, 0x662990
    cpu.esi = 6695312 /*0x662990*/;
    // 0044e070  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044e072  b970010000             -mov ecx, 0x170
    cpu.ecx = 368 /*0x170*/;
L_0x0044e077:
    // 0044e077  8d7824                 -lea edi, [eax + 0x24]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0044e07a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044e07b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044e07d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0044e080  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044e082  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044e084  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0044e087  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0044e089  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044e08a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0044e08c:
    // 0044e08c  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044e093  7507                   -jne 0x44e09c
    if (!cpu.flags.zf)
    {
        goto L_0x0044e09c;
    }
    // 0044e095  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044e09a  eb05                   -jmp 0x44e0a1
    goto L_0x0044e0a1;
L_0x0044e09c:
    // 0044e09c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0044e0a1:
    // 0044e0a1  39c1                   +cmp ecx, eax
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
    // 0044e0a3  7d1f                   -jge 0x44e0c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044e0c4;
    }
    // 0044e0a5  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044e0a7  eb05                   -jmp 0x44e0ae
    goto L_0x0044e0ae;
L_0x0044e0a9:
    // 0044e0a9  83fb17                 +cmp ebx, 0x17
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(23 /*0x17*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044e0ac  7d0c                   -jge 0x44e0ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044e0ba;
    }
L_0x0044e0ae:
    // 0044e0ae  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0044e0b0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044e0b2  e809730300             -call 0x4853c0
    cpu.esp -= 4;
    sub_4853c0(app, cpu);
    if (cpu.terminate) return;
    // 0044e0b7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044e0b8  ebef                   -jmp 0x44e0a9
    goto L_0x0044e0a9;
L_0x0044e0ba:
    // 0044e0ba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044e0bc  e8df1f0300             -call 0x4800a0
    cpu.esp -= 4;
    sub_4800a0(app, cpu);
    if (cpu.terminate) return;
    // 0044e0c1  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044e0c2  ebc8                   -jmp 0x44e08c
    goto L_0x0044e08c;
L_0x0044e0c4:
    // 0044e0c4  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0044e0c9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044e0cb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044e0cd  e85e3f0300             -call 0x482030
    cpu.esp -= 4;
    sub_482030(app, cpu);
    if (cpu.terminate) return;
    // 0044e0d2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044e0d7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0044e0dc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044e0de  e84d3f0300             -call 0x482030
    cpu.esp -= 4;
    sub_482030(app, cpu);
    if (cpu.terminate) return;
    // 0044e0e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044e0e5  ba17000000             -mov edx, 0x17
    cpu.edx = 23 /*0x17*/;
    // 0044e0ea  a364925500             -mov dword ptr [0x559264], eax
    app->getMemory<x86::reg32>(x86::reg32(5608036) /* 0x559264 */) = cpu.eax;
    // 0044e0ef  e86c58fdff             -call 0x423960
    cpu.esp -= 4;
    sub_423960(app, cpu);
    if (cpu.terminate) return;
    // 0044e0f4  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 0044e0fb  750f                   -jne 0x44e10c
    if (!cpu.flags.zf)
    {
        goto L_0x0044e10c;
    }
    // 0044e0fd  ba17000000             -mov edx, 0x17
    cpu.edx = 23 /*0x17*/;
    // 0044e102  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044e107  e85458fdff             -call 0x423960
    cpu.esp -= 4;
    sub_423960(app, cpu);
    if (cpu.terminate) return;
L_0x0044e10c:
    // 0044e10c  8b0db0d36f00           -mov ecx, dword ptr [0x6fd3b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0044e112  83f901                 +cmp ecx, 1
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
    // 0044e115  750e                   -jne 0x44e125
    if (!cpu.flags.zf)
    {
        goto L_0x0044e125;
    }
    // 0044e117  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044e119  e8a2630300             -call 0x4844c0
    cpu.esp -= 4;
    sub_4844c0(app, cpu);
    if (cpu.terminate) return;
    // 0044e11e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044e120  e89b630300             -call 0x4844c0
    cpu.esp -= 4;
    sub_4844c0(app, cpu);
    if (cpu.terminate) return;
L_0x0044e125:
    // 0044e125  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044e127  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044e128  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044e129  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044e12a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044e12b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044e12c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044e12d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_44e130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044e130  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044e131  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044e133  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044e135  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044e136  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
