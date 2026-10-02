#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip  */
void Application::sub_4f916c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f916c;
    // 004f916a  90                     -nop 
    ;
    // 004f916b  90                     -nop 
    ;
L_entry_0x004f916c:
    // 004f916c  e8edffffff             -call 0x4f915e
    cpu.esp -= 4;
    sub_4f915e(app, cpu);
    if (cpu.terminate) return;
    // 004f9171  83f8ff                 +cmp eax, -1
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
    // 004f9174  740b                   -je 0x4f9181
    if (cpu.flags.zf)
    {
        goto L_0x004f9181;
    }
    // 004f9176  a910000000             +test eax, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16 /*0x10*/));
    // 004f917b  7404                   -je 0x4f9181
    if (cpu.flags.zf)
    {
        goto L_0x004f9181;
    }
    // 004f917d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f917f  40                     -inc eax
    (cpu.eax)++;
    // 004f9180  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9181:
    // 004f9181  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9183  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9184(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9184  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004f9185  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f9187  81ec44020000           -sub esp, 0x244
    (cpu.esp) -= x86::reg32(x86::sreg32(580 /*0x244*/));
    // 004f918d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f918f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f9191  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f9193  e820020000             -call 0x4f93b8
    cpu.esp -= 4;
    sub_4f93b8(app, cpu);
    if (cpu.terminate) return;
    // 004f9198  66c7072a00             -mov word ptr [edi], 0x2a
    app->getMemory<x86::reg16>(cpu.edi) = 42 /*0x2a*/;
    // 004f919d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004f919f  8dbc2404010000         -lea edi, [esp + 0x104]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f91a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f91a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f91a8  ff15cc445300           -call dword ptr [0x5344cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457100) /* 0x5344cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f91ae  83f8ff                 +cmp eax, -1
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
    // 004f91b1  742e                   -je 0x4f91e1
    if (cpu.flags.zf)
    {
        goto L_0x004f91e1;
    }
    // 004f91b3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004f91b5:
    // 004f91b5  8d472c                 -lea eax, [edi + 0x2c]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(44) /* 0x2c */);
    // 004f91b8  6683382e               +cmp word ptr [eax], 0x2e
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(46 /*0x2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f91bc  740d                   -je 0x4f91cb
    if (cpu.flags.zf)
    {
        goto L_0x004f91cb;
    }
    // 004f91be  6681382e2e             +cmp word ptr [eax], 0x2e2e
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(11822 /*0x2e2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f91c3  7514                   -jne 0x4f91d9
    if (!cpu.flags.zf)
    {
        goto L_0x004f91d9;
    }
    // 004f91c5  80780200               +cmp byte ptr [eax + 2], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f91c9  750e                   -jne 0x4f91d9
    if (!cpu.flags.zf)
    {
        goto L_0x004f91d9;
    }
L_0x004f91cb:
    // 004f91cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f91cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f91cd  ff15d0445300           -call dword ptr [0x5344d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f91d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f91d5  75de                   -jne 0x4f91b5
    if (!cpu.flags.zf)
    {
        goto L_0x004f91b5;
    }
    // 004f91d7  eb01                   -jmp 0x4f91da
    goto L_0x004f91da;
L_0x004f91d9:
    // 004f91d9  43                     -inc ebx
    (cpu.ebx)++;
L_0x004f91da:
    // 004f91da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f91db  ff15c8445300           -call dword ptr [0x5344c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f91e1:
    // 004f91e1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f91e3  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004f91e7  61                     -popal 
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
    // 004f91e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f91ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f91ea  90                     -nop 
    ;
    // 004f91eb  90                     -nop 
    ;
    // 004f91ec  e86dffffff             -call 0x4f915e
    cpu.esp -= 4;
    sub_4f915e(app, cpu);
    if (cpu.terminate) return;
    // 004f91f1  83f8ff                 +cmp eax, -1
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
    // 004f91f4  740b                   -je 0x4f9201
    if (cpu.flags.zf)
    {
        goto L_0x004f9201;
    }
    // 004f91f6  a910000000             +test eax, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16 /*0x10*/));
    // 004f91fb  7504                   -jne 0x4f9201
    if (!cpu.flags.zf)
    {
        goto L_0x004f9201;
    }
    // 004f91fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f91ff  40                     -inc eax
    (cpu.eax)++;
    // 004f9200  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9201:
    // 004f9201  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9203  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f91ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f91ec;
    // 004f91ea  90                     -nop 
    ;
    // 004f91eb  90                     -nop 
    ;
L_entry_0x004f91ec:
    // 004f91ec  e86dffffff             -call 0x4f915e
    cpu.esp -= 4;
    sub_4f915e(app, cpu);
    if (cpu.terminate) return;
    // 004f91f1  83f8ff                 +cmp eax, -1
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
    // 004f91f4  740b                   -je 0x4f9201
    if (cpu.flags.zf)
    {
        goto L_0x004f9201;
    }
    // 004f91f6  a910000000             +test eax, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16 /*0x10*/));
    // 004f91fb  7504                   -jne 0x4f9201
    if (!cpu.flags.zf)
    {
        goto L_0x004f9201;
    }
    // 004f91fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f91ff  40                     -inc eax
    (cpu.eax)++;
    // 004f9200  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9201:
    // 004f9201  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9203  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9204(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9204  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9205  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9206  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9208  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9209  ff1590445300           -call dword ptr [0x534490]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457040) /* 0x534490 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f920f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9210  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9211  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9212(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9212  90                     -nop 
    ;
    // 004f9213  90                     -nop 
    ;
    // 004f9214  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9215  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9217  e850ffffff             -call 0x4f916c
    cpu.esp -= 4;
    sub_4f916c(app, cpu);
    if (cpu.terminate) return;
    // 004f921c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f921e  7507                   -jne 0x4f9227
    if (!cpu.flags.zf)
    {
        goto L_0x004f9227;
    }
    // 004f9220  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f9222  e8ddffffff             -call 0x4f9204
    cpu.esp -= 4;
    sub_4f9204(app, cpu);
    if (cpu.terminate) return;
L_0x004f9227:
    // 004f9227  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9228  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9214(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f9214;
    // 004f9212  90                     -nop 
    ;
    // 004f9213  90                     -nop 
    ;
L_entry_0x004f9214:
    // 004f9214  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9215  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9217  e850ffffff             -call 0x4f916c
    cpu.esp -= 4;
    sub_4f916c(app, cpu);
    if (cpu.terminate) return;
    // 004f921c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f921e  7507                   -jne 0x4f9227
    if (!cpu.flags.zf)
    {
        goto L_0x004f9227;
    }
    // 004f9220  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f9222  e8ddffffff             -call 0x4f9204
    cpu.esp -= 4;
    sub_4f9204(app, cpu);
    if (cpu.terminate) return;
L_0x004f9227:
    // 004f9227  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9228  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f922a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f922a  90                     -nop 
    ;
    // 004f922b  90                     -nop 
    ;
    // 004f922c  90                     -nop 
    ;
    // 004f922d  90                     -nop 
    ;
    // 004f922e  90                     -nop 
    ;
    // 004f922f  90                     -nop 
    ;
    // 004f9230  90                     -nop 
    ;
    // 004f9231  90                     -nop 
    ;
    // 004f9232  90                     -nop 
    ;
    // 004f9233  90                     -nop 
    ;
    // 004f9234  90                     -nop 
    ;
    // 004f9235  90                     -nop 
    ;
    // 004f9236  90                     -nop 
    ;
    // 004f9237  90                     -nop 
    ;
    // 004f9238  90                     -nop 
    ;
    // 004f9239  90                     -nop 
    ;
    // 004f923a  90                     -nop 
    ;
    // 004f923b  90                     -nop 
    ;
    // 004f923c  90                     -nop 
    ;
    // 004f923d  90                     -nop 
    ;
    // 004f923e  90                     -nop 
    ;
    // 004f923f  90                     -nop 
    ;
    // 004f9240  90                     -nop 
    ;
    // 004f9241  90                     -nop 
    ;
    // 004f9242  90                     -nop 
    ;
    // 004f9243  90                     -nop 
    ;
    // 004f9244  90                     -nop 
    ;
    // 004f9245  90                     -nop 
    ;
    // 004f9246  90                     -nop 
    ;
    // 004f9247  90                     -nop 
    ;
    // 004f9248  90                     -nop 
    ;
    // 004f9249  90                     -nop 
    ;
    // 004f924a  90                     -nop 
    ;
    // 004f924b  90                     -nop 
    ;
    // 004f924c  90                     -nop 
    ;
    // 004f924d  90                     -nop 
    ;
    // 004f924e  90                     -nop 
    ;
    // 004f924f  90                     -nop 
    ;
    // 004f9250  90                     -nop 
    ;
    // 004f9251  90                     -nop 
    ;
    // 004f9252  90                     -nop 
    ;
    // 004f9253  90                     -nop 
    ;
    // 004f9254  90                     -nop 
    ;
    // 004f9255  90                     -nop 
    ;
    // 004f9256  90                     -nop 
    ;
    // 004f9257  90                     -nop 
    ;
    // 004f9258  90                     -nop 
    ;
    // 004f9259  90                     -nop 
    ;
    // 004f925a  90                     -nop 
    ;
    // 004f925b  90                     -nop 
    ;
    // 004f925c  90                     -nop 
    ;
    // 004f925d  90                     -nop 
    ;
    // 004f925e  90                     -nop 
    ;
    // 004f925f  90                     -nop 
    ;
    // 004f9260  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9262  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f9270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9272  6860924f00             -push 0x4f9260
    app->getMemory<x86::reg32>(cpu.esp-4) = 5214816 /*0x4f9260*/;
    cpu.esp -= 4;
    // 004f9277  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9279  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f927b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f927d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f927f  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004f9281  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004f9283  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f9285  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9287  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004f9289  ba68045400             -mov edx, 0x540468
    cpu.edx = 5506152 /*0x540468*/;
    // 004f928e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9290  e89b7ffeff             -call 0x4e1230
    cpu.esp -= 4;
    sub_4e1230(app, cpu);
    if (cpu.terminate) return;
    // 004f9295  8b15c0f59e00           -mov edx, dword ptr [0x9ef5c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */);
    // 004f929b  8915c4f59e00           -mov dword ptr [0x9ef5c4], edx
    app->getMemory<x86::reg32>(x86::reg32(10417604) /* 0x9ef5c4 */) = cpu.edx;
    // 004f92a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f92b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f92b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f92b3  e848e6ffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f92b8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f92ba  a3fc445600             -mov dword ptr [0x5644fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */) = cpu.eax;
    // 004f92bf  e8acffffff             -call 0x4f9270
    cpu.esp -= 4;
    sub_4f9270(app, cpu);
    if (cpu.terminate) return;
    // 004f92c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f92d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f92d1  a160277a00             -mov eax, dword ptr [0x7a2760]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8005472) /* 0x7a2760 */);
    // 004f92d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f92d8  e8d3ffffff             -call 0x4f92b0
    cpu.esp -= 4;
    sub_4f92b0(app, cpu);
    if (cpu.terminate) return;
    // 004f92dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f92e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f92e1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f92e3  e8c8ffffff             -call 0x4f92b0
    cpu.esp -= 4;
    sub_4f92b0(app, cpu);
    if (cpu.terminate) return;
    // 004f92e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f92f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f92f1  8b15fc445600           -mov edx, dword ptr [0x5644fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */);
    // 004f92f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f92f9  7502                   -jne 0x4f92fd
    if (!cpu.flags.zf)
    {
        goto L_0x004f92fd;
    }
    // 004f92fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f92fd:
    // 004f92fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f92fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f9300  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f9302  e8e9e6ffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f9307  890dfc445600           -mov dword ptr [0x5644fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */) = cpu.ecx;
    // 004f930d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f930e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f930f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9310  a38c715600             -mov dword ptr [0x56718c], eax
    app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */) = cpu.eax;
    // 004f9315  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f9320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9320  833d9471560000         +cmp dword ptr [0x567194], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9327  7401                   -je 0x4f932a
    if (cpu.flags.zf)
    {
        goto L_0x004f932a;
    }
    // 004f9329  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f932a:
    // 004f932a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f932b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f932d  e89efc0100             -call 0x518fd0
    cpu.esp -= 4;
    sub_518fd0(app, cpu);
    if (cpu.terminate) return;
    // 004f9332  b864905600             -mov eax, 0x569064
    cpu.eax = 5673060 /*0x569064*/;
    // 004f9337  e8d40b0200             -call 0x519f10
    cpu.esp -= 4;
    sub_519f10(app, cpu);
    if (cpu.terminate) return;
    // 004f933c  a390715600             -mov dword ptr [0x567190], eax
    app->getMemory<x86::reg32>(x86::reg32(5665168) /* 0x567190 */) = cpu.eax;
    // 004f9341  b860934f00             -mov eax, 0x4f9360
    cpu.eax = 5215072 /*0x4f9360*/;
    // 004f9346  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f934b  e82897ffff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004f9350  890d94715600           -mov dword ptr [0x567194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */) = cpu.ecx;
    // 004f9356  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9357  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9360  833d9471560000         +cmp dword ptr [0x567194], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9367  7501                   -jne 0x4f936a
    if (!cpu.flags.zf)
    {
        goto L_0x004f936a;
    }
    // 004f9369  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f936a:
    // 004f936a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f936b  a190715600             -mov eax, dword ptr [0x567190]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665168) /* 0x567190 */);
    // 004f9370  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f9372  e8f90d0200             -call 0x51a170
    cpu.esp -= 4;
    sub_51a170(app, cpu);
    if (cpu.terminate) return;
    // 004f9377  890d90715600           -mov dword ptr [0x567190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665168) /* 0x567190 */) = cpu.ecx;
    // 004f937d  e8befd0100             -call 0x519140
    cpu.esp -= 4;
    sub_519140(app, cpu);
    if (cpu.terminate) return;
    // 004f9382  890d94715600           -mov dword ptr [0x567194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */) = cpu.ecx;
    // 004f9388  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9389  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f9390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9390  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9391  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004f9394  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f9397  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9398  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f939a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f939a  90                     -nop 
    ;
    // 004f939b  90                     -nop 
    ;
    // 004f939c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f939d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004f93a0  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004f93a3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f939c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f939c;
    // 004f939a  90                     -nop 
    ;
    // 004f939b  90                     -nop 
    ;
L_entry_0x004f939c:
    // 004f939c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f939d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004f93a0  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004f93a3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f93a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93a6  90                     -nop 
    ;
    // 004f93a7  90                     -nop 
    ;
    // 004f93a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f93a9  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004f93ae  e8394d0200             -call 0x51e0ec
    cpu.esp -= 4;
    sub_51e0ec(app, cpu);
    if (cpu.terminate) return;
    // 004f93b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f93a8;
    // 004f93a6  90                     -nop 
    ;
    // 004f93a7  90                     -nop 
    ;
L_entry_0x004f93a8:
    // 004f93a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f93a9  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004f93ae  e8394d0200             -call 0x51e0ec
    cpu.esp -= 4;
    sub_51e0ec(app, cpu);
    if (cpu.terminate) return;
    // 004f93b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f93b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93b6  90                     -nop 
    ;
    // 004f93b7  90                     -nop 
    ;
    // 004f93b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93bb:
    // 004f93bb  ac                     -lodsb al, byte ptr [esi]
    NFS2_ASSERT(false);
    // 004f93bc  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93bd  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93bf  75fa                   -jne 0x4f93bb
    if (!cpu.flags.zf)
    {
        goto L_0x004f93bb;
    }
    // 004f93c1  4e                     -dec esi
    (cpu.esi)--;
    // 004f93c2  4f                     -dec edi
    (cpu.edi)--;
    // 004f93c3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f93b8;
    // 004f93b6  90                     -nop 
    ;
    // 004f93b7  90                     -nop 
    ;
L_entry_0x004f93b8:
    // 004f93b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93bb:
    // 004f93bb  ac                     -lodsb al, byte ptr [esi]
    NFS2_ASSERT(false);
    // 004f93bc  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93bd  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93bf  75fa                   -jne 0x4f93bb
    if (!cpu.flags.zf)
    {
        goto L_0x004f93bb;
    }
    // 004f93c1  4e                     -dec esi
    (cpu.esi)--;
    // 004f93c2  4f                     -dec edi
    (cpu.edi)--;
    // 004f93c3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f93c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93c6  90                     -nop 
    ;
    // 004f93c7  90                     -nop 
    ;
    // 004f93c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93cb:
    // 004f93cb  ac                     -lodsb al, byte ptr [esi]
    NFS2_ASSERT(false);
    // 004f93cc  e80f77ffff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 004f93d1  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93d2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93d4  75f5                   -jne 0x4f93cb
    if (!cpu.flags.zf)
    {
        goto L_0x004f93cb;
    }
    // 004f93d6  4e                     -dec esi
    (cpu.esi)--;
    // 004f93d7  4f                     -dec edi
    (cpu.edi)--;
    // 004f93d8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f93c8;
    // 004f93c6  90                     -nop 
    ;
    // 004f93c7  90                     -nop 
    ;
L_entry_0x004f93c8:
    // 004f93c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93cb:
    // 004f93cb  ac                     -lodsb al, byte ptr [esi]
    NFS2_ASSERT(false);
    // 004f93cc  e80f77ffff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 004f93d1  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93d2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93d4  75f5                   -jne 0x4f93cb
    if (!cpu.flags.zf)
    {
        goto L_0x004f93cb;
    }
    // 004f93d6  4e                     -dec esi
    (cpu.esi)--;
    // 004f93d7  4f                     -dec edi
    (cpu.edi)--;
    // 004f93d8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93da  90                     -nop 
    ;
    // 004f93db  90                     -nop 
    ;
    // 004f93dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f93dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f93de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f93e0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f93e2  e8e1ffffff             -call 0x4f93c8
    cpu.esp -= 4;
    sub_4f93c8(app, cpu);
    if (cpu.terminate) return;
    // 004f93e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f93dc;
    // 004f93da  90                     -nop 
    ;
    // 004f93db  90                     -nop 
    ;
L_entry_0x004f93dc:
    // 004f93dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f93dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f93de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f93e0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f93e2  e8e1ffffff             -call 0x4f93c8
    cpu.esp -= 4;
    sub_4f93c8(app, cpu);
    if (cpu.terminate) return;
    // 004f93e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93ea  90                     -nop 
    ;
    // 004f93eb  90                     -nop 
    ;
    // 004f93ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93ef:
    // 004f93ef  e30b                   -jecxz 0x4f93fc
    if (cpu.ecx == 0)
    {
        goto L_0x004f93fc;
    }
    // 004f93f1  ac                     -lodsb al, byte ptr [esi]
    NFS2_ASSERT(false);
    // 004f93f2  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93f3  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93f5  7403                   -je 0x4f93fa
    if (cpu.flags.zf)
    {
        goto L_0x004f93fa;
    }
    // 004f93f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f93f8  ebf5                   -jmp 0x4f93ef
    goto L_0x004f93ef;
L_0x004f93fa:
    // 004f93fa  4e                     -dec esi
    (cpu.esi)--;
    // 004f93fb  4f                     -dec edi
    (cpu.edi)--;
L_0x004f93fc:
    // 004f93fc  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f93ec;
    // 004f93ea  90                     -nop 
    ;
    // 004f93eb  90                     -nop 
    ;
L_entry_0x004f93ec:
    // 004f93ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93ef:
    // 004f93ef  e30b                   -jecxz 0x4f93fc
    if (cpu.ecx == 0)
    {
        goto L_0x004f93fc;
    }
    // 004f93f1  ac                     -lodsb al, byte ptr [esi]
    NFS2_ASSERT(false);
    // 004f93f2  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93f3  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93f5  7403                   -je 0x4f93fa
    if (cpu.flags.zf)
    {
        goto L_0x004f93fa;
    }
    // 004f93f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f93f8  ebf5                   -jmp 0x4f93ef
    goto L_0x004f93ef;
L_0x004f93fa:
    // 004f93fa  4e                     -dec esi
    (cpu.esi)--;
    // 004f93fb  4f                     -dec edi
    (cpu.edi)--;
L_0x004f93fc:
    // 004f93fc  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93fe  90                     -nop 
    ;
    // 004f93ff  90                     -nop 
    ;
    // 004f9400  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9401  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f9403:
    // 004f9403  e310                   -jecxz 0x4f9415
    if (cpu.ecx == 0)
    {
        goto L_0x004f9415;
    }
    // 004f9405  ac                     -lodsb al, byte ptr [esi]
    NFS2_ASSERT(false);
    // 004f9406  e8d576ffff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 004f940b  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f940c  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f940e  7403                   -je 0x4f9413
    if (cpu.flags.zf)
    {
        goto L_0x004f9413;
    }
    // 004f9410  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f9411  ebf0                   -jmp 0x4f9403
    goto L_0x004f9403;
L_0x004f9413:
    // 004f9413  4e                     -dec esi
    (cpu.esi)--;
    // 004f9414  4f                     -dec edi
    (cpu.edi)--;
L_0x004f9415:
    // 004f9415  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9416  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f9400;
    // 004f93fe  90                     -nop 
    ;
    // 004f93ff  90                     -nop 
    ;
L_entry_0x004f9400:
    // 004f9400  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9401  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f9403:
    // 004f9403  e310                   -jecxz 0x4f9415
    if (cpu.ecx == 0)
    {
        goto L_0x004f9415;
    }
    // 004f9405  ac                     -lodsb al, byte ptr [esi]
    NFS2_ASSERT(false);
    // 004f9406  e8d576ffff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 004f940b  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f940c  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f940e  7403                   -je 0x4f9413
    if (cpu.flags.zf)
    {
        goto L_0x004f9413;
    }
    // 004f9410  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f9411  ebf0                   -jmp 0x4f9403
    goto L_0x004f9403;
L_0x004f9413:
    // 004f9413  4e                     -dec esi
    (cpu.esi)--;
    // 004f9414  4f                     -dec edi
    (cpu.edi)--;
L_0x004f9415:
    // 004f9415  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9416  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f9418(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9418  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9419  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f941a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f941b  e8e0ffffff             -call 0x4f9400
    cpu.esp -= 4;
    sub_4f9400(app, cpu);
    if (cpu.terminate) return;
    // 004f9420  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9421  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9422  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9423  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9424(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9424  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9425  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f9427:
    // 004f9427  e310                   -jecxz 0x4f9439
    if (cpu.ecx == 0)
    {
        goto L_0x004f9439;
    }
    // 004f9429  ac                     -lodsb al, byte ptr [esi]
    NFS2_ASSERT(false);
    // 004f942a  e8b159ffff             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 004f942f  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f9430  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f9432  7403                   -je 0x4f9437
    if (cpu.flags.zf)
    {
        goto L_0x004f9437;
    }
    // 004f9434  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f9435  ebf0                   -jmp 0x4f9427
    goto L_0x004f9427;
L_0x004f9437:
    // 004f9437  4e                     -dec esi
    (cpu.esi)--;
    // 004f9438  4f                     -dec edi
    (cpu.edi)--;
L_0x004f9439:
    // 004f9439  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f943a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f943c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f943c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f943d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f943e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f943f  e8e0ffffff             -call 0x4f9424
    cpu.esp -= 4;
    sub_4f9424(app, cpu);
    if (cpu.terminate) return;
    // 004f9444  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9445  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9446  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9447  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004f9448:
    // 004f9448  803f00                 +cmp byte ptr [edi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f944b  7403                   -je 0x4f9450
    if (cpu.flags.zf)
    {
        goto L_0x004f9450;
    }
    // 004f944d  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f944e  ebf8                   -jmp 0x4f9448
    goto L_0x004f9448;
L_0x004f9450:
    // 004f9450  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f9452(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9452  90                     -nop 
    ;
    // 004f9453  90                     -nop 
    ;
    // 004f9454  90                     -nop 
    ;
    // 004f9455  90                     -nop 
    ;
    // 004f9456  90                     -nop 
    ;
    // 004f9457  90                     -nop 
    ;
    // 004f9458  90                     -nop 
    ;
    // 004f9459  90                     -nop 
    ;
    // 004f945a  90                     -nop 
    ;
    // 004f945b  90                     -nop 
    ;
    // 004f945c  90                     -nop 
    ;
    // 004f945d  90                     -nop 
    ;
    // 004f945e  90                     -nop 
    ;
    // 004f945f  90                     -nop 
    ;
    // 004f9460  90                     -nop 
    ;
    // 004f9461  90                     -nop 
    ;
    // 004f9462  90                     -nop 
    ;
    // 004f9463  90                     -nop 
    ;
    // 004f9464  90                     -nop 
    ;
    // 004f9465  90                     -nop 
    ;
    // 004f9466  90                     -nop 
    ;
    // 004f9467  90                     -nop 
    ;
    // 004f9468  90                     -nop 
    ;
    // 004f9469  90                     -nop 
    ;
    // 004f946a  90                     -nop 
    ;
    // 004f946b  90                     -nop 
    ;
    // 004f946c  90                     -nop 
    ;
    // 004f946d  90                     -nop 
    ;
    // 004f946e  90                     -nop 
    ;
    // 004f946f  90                     -nop 
    ;
    // 004f9470  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9472  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f9478  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004f947e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004f9480  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f9482(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9482  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 004f9484  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004f9486  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 004f9488  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004f948a  dee1                   +fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004f948c  d9e4                   +ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 004f948e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004f9490  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f9491  750f                   -jne 0x4f94a2
    if (!cpu.flags.zf)
    {
        goto L_0x004f94a2;
    }
    // 004f9493  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004f9495  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004f9497  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f9498  7704                   -ja 0x4f949e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f949e;
    }
    // 004f949a  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004f949c  eb02                   -jmp 0x4f94a0
    goto L_0x004f94a0;
L_0x004f949e:
    // 004f949e  d9eb                   +fldpi 
    cpu.fpu.push(3.1415926535897932);
L_0x004f94a0:
    // 004f94a0  eb1a                   -jmp 0x4f94bc
    goto L_0x004f94bc;
L_0x004f94a2:
    // 004f94a2  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004f94a4  e8110d0200             -call 0x51a1ba
    cpu.esp -= 4;
    sub_51a1ba(app, cpu);
    if (cpu.terminate) return;
    // 004f94a9  3c00                   +cmp al, 0
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
    // 004f94ab  750f                   -jne 0x4f94bc
    if (!cpu.flags.zf)
    {
        goto L_0x004f94bc;
    }
    // 004f94ad  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004f94af  e82572feff             -call 0x4e06d9
    cpu.esp -= 4;
    sub_4e06d9(app, cpu);
    if (cpu.terminate) return;
    // 004f94b4  db2d9c715600           -fld xword ptr [0x56719c]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5665180) /* 0x56719c */)));
    // 004f94ba  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
L_0x004f94bc:
    // 004f94bc  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f94be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f94bf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f94bf  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004f94c3  e8baffffff             -call 0x4f9482
    cpu.esp -= 4;
    sub_4f9482(app, cpu);
    if (cpu.terminate) return;
    // 004f94c8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f9500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004f9500  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9501  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9503  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9506  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004f950a  8b5c2468               -mov ebx, dword ptr [esp + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004f950e  8b74246c               -mov esi, dword ptr [esp + 0x6c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004f9512  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004f9516  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004f9519  83fa0b                 +cmp edx, 0xb
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
    // 004f951c  0f8762020000           -ja 0x4f9784
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f9784;
    }
    // 004f9522  ff2495d0944f00         -jmp dword ptr [edx*4 + 0x4f94d0]
    cpu.ip = app->getMemory<x86::reg32>(5215440 + cpu.edx * 4); goto dynamic_jump;
  case 0x004f9529:
    // 004f9529  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f952a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f952b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f952c  b898d95400             -mov eax, 0x54d998
    cpu.eax = 5560728 /*0x54d998*/;
    // 004f9531  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9532  b8ac4d9f00             -mov eax, 0x9f4dac
    cpu.eax = 10440108 /*0x9f4dac*/;
    // 004f9537  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9538  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f953f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f9542  beac4d9f00             -mov esi, 0x9f4dac
    cpu.esi = 10440108 /*0x9f4dac*/;
    // 004f9547  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9548  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f954a  b854445600             -mov eax, 0x564454
    cpu.eax = 5653588 /*0x564454*/;
    // 004f954f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9550  8935b4ab5600           -mov dword ptr [0x56abb4], esi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.esi;
    // 004f9556  e8f57a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f955b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f955e:
    // 004f955e  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9561  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9562  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9563  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9564  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f9567:
    // 004f9567  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9568  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9569  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f956a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f956b  6834d95400             -push 0x54d934
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560628 /*0x54d934*/;
    cpu.esp -= 4;
    // 004f9570  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f9575  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f957c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f957f  bfac4d9f00             -mov edi, 0x9f4dac
    cpu.edi = 10440108 /*0x9f4dac*/;
    // 004f9584  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9585  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9587  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f958c  893db4ab5600           -mov dword ptr [0x56abb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edi;
    // 004f9592  e8b97a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9597  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f959a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f959e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f959f  8b2da04d9f00           -mov ebp, dword ptr [0x9f4da0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f95a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f95a6  e8a2750300             -call 0x530b4d
    cpu.esp -= 4;
    sub_530b4d(app, cpu);
    if (cpu.terminate) return;
    // 004f95ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95ac  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f95af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95b2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f95b5:
    // 004f95b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f95b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f95b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f95b8  6868d95400             -push 0x54d968
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560680 /*0x54d968*/;
    cpu.esp -= 4;
    // 004f95bd  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f95c2  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f95c9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f95cc  b9ac4d9f00             -mov ecx, 0x9f4dac
    cpu.ecx = 10440108 /*0x9f4dac*/;
    // 004f95d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f95d2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f95d4  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f95d9  890db4ab5600           -mov dword ptr [0x56abb4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.ecx;
    // 004f95df  e86c7a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f95e4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f95e7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f95e9  0f846fffffff           -je 0x4f955e
    if (cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f95ef  c7059c4d9f000f000000   -mov dword ptr [0x9f4d9c], 0xf
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 15 /*0xf*/;
    // 004f95f9  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f9603  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9606  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9607  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9608  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9609  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f960c:
    // 004f960c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f960d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f960e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f960f  68ccd95400             -push 0x54d9cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560780 /*0x54d9cc*/;
    cpu.esp -= 4;
    // 004f9614  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f9619  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9620  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f9623  b8ac4d9f00             -mov eax, 0x9f4dac
    cpu.eax = 10440108 /*0x9f4dac*/;
    // 004f9628  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9629  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f962b  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9630  a3b4ab5600             -mov dword ptr [0x56abb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.eax;
    // 004f9635  e8167a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f963a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f963d  83fb10                 +cmp ebx, 0x10
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9640  732d                   -jae 0x4f966f
    if (!cpu.flags.cf)
    {
        goto L_0x004f966f;
    }
    // 004f9642  83fb02                 +cmp ebx, 2
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
    // 004f9645  0f83a4000000           -jae 0x4f96ef
    if (!cpu.flags.cf)
    {
        goto L_0x004f96ef;
    }
    // 004f964b  83fb01                 +cmp ebx, 1
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
    // 004f964e  0f850affffff           -jne 0x4f955e
    if (!cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f9654  8b0da44d9f00           -mov ecx, dword ptr [0x9f4da4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004f965a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f965b  e809630300             -call 0x52f969
    cpu.esp -= 4;
    sub_52f969(app, cpu);
    if (cpu.terminate) return;
    // 004f9660  891d984d9f00           -mov dword ptr [0x9f4d98], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = cpu.ebx;
    // 004f9666  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f9669  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f966a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f966b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f966c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f966f:
    // 004f966f  0f86e9feffff           -jbe 0x4f955e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f9675  81fb80000000           +cmp ebx, 0x80
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f967b  7326                   -jae 0x4f96a3
    if (!cpu.flags.cf)
    {
        goto L_0x004f96a3;
    }
    // 004f967d  83fb40                 +cmp ebx, 0x40
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
    // 004f9680  0f85d8feffff           -jne 0x4f955e
    if (!cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
L_0x004f9686:
    // 004f9686  c7059c4d9f000c000000   -mov dword ptr [0x9f4d9c], 0xc
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 12 /*0xc*/;
    // 004f9690  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f969a  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f969d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f969e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f969f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96a0  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f96a3:
    // 004f96a3  0f86b5feffff           -jbe 0x4f955e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f96a9  81fb00010000           +cmp ebx, 0x100
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
    // 004f96af  0f82a9feffff           -jb 0x4f955e
    if (cpu.flags.cf)
    {
        goto L_0x004f955e;
    }
    // 004f96b5  765e                   -jbe 0x4f9715
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9715;
    }
    // 004f96b7  81fb00400000           +cmp ebx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f96bd  0f859bfeffff           -jne 0x4f955e
    if (!cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f96c3  83fe08                 +cmp esi, 8
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
    // 004f96c6  7370                   -jae 0x4f9738
    if (!cpu.flags.cf)
    {
        goto L_0x004f9738;
    }
    // 004f96c8  83fe01                 +cmp esi, 1
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
    // 004f96cb  7205                   -jb 0x4f96d2
    if (cpu.flags.cf)
    {
        goto L_0x004f96d2;
    }
    // 004f96cd  7603                   -jbe 0x4f96d2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f96d2;
    }
    // 004f96cf  83fe02                 -cmp esi, 2
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
L_0x004f96d2:
    // 004f96d2  c7059c4d9f000b000000   -mov dword ptr [0x9f4d9c], 0xb
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 11 /*0xb*/;
    // 004f96dc  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f96e6  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f96e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96ec  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f96ef:
    // 004f96ef  0f8769feffff           -ja 0x4f955e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f96f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f96f7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f96f9  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004f96fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f96fe  e8325e0300             -call 0x52f535
    cpu.esp -= 4;
    sub_52f535(app, cpu);
    if (cpu.terminate) return;
    // 004f9703  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004f9707  a3a44d9f00             -mov dword ptr [0x9f4da4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */) = cpu.eax;
    // 004f970c  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f970f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9710  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9711  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9712  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f9715:
    // 004f9715  be09000000             -mov esi, 9
    cpu.esi = 9 /*0x9*/;
    // 004f971a  e8d1090000             -call 0x4fa0f0
    cpu.esp -= 4;
    sub_4fa0f0(app, cpu);
    if (cpu.terminate) return;
    // 004f971f  89359c4d9f00           -mov dword ptr [0x9f4d9c], esi
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.esi;
    // 004f9725  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f972f  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f9732  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9733  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9734  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9735  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f9738:
    // 004f9738  762d                   -jbe 0x4f9767
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9767;
    }
    // 004f973a  83fe20                 +cmp esi, 0x20
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f973d  7293                   -jb 0x4f96d2
    if (cpu.flags.cf)
    {
        goto L_0x004f96d2;
    }
    // 004f973f  0f8641ffffff           -jbe 0x4f9686
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9686;
    }
    // 004f9745  83fe40                 +cmp esi, 0x40
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9748  7588                   -jne 0x4f96d2
    if (!cpu.flags.zf)
    {
        goto L_0x004f96d2;
    }
    // 004f974a  c7059c4d9f000d000000   -mov dword ptr [0x9f4d9c], 0xd
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 13 /*0xd*/;
    // 004f9754  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f975e  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9761  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9762  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9763  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9764  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f9767:
    // 004f9767  c7059c4d9f000e000000   -mov dword ptr [0x9f4d9c], 0xe
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 14 /*0xe*/;
    // 004f9771  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f977b  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f977e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f977f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9780  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9781  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f9784:
L_0x004f9784:
    // 004f9784  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9785  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9786  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9787  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9788  6800da5400             -push 0x54da00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560832 /*0x54da00*/;
    cpu.esp -= 4;
    // 004f978d  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f9792  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9799  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f979c  baac4d9f00             -mov edx, 0x9f4dac
    cpu.edx = 10440108 /*0x9f4dac*/;
    // 004f97a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f97a2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f97a4  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f97a9  8915b4ab5600           -mov dword ptr [0x56abb4], edx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edx;
    // 004f97af  e89c780000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f97b4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f97b7  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f97ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f97bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f97bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f97bd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4f97c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f97c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f97c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f97c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f97c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f97c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f97c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f97c6  b8e8030000             -mov eax, 0x3e8
    cpu.eax = 1000 /*0x3e8*/;
    // 004f97cb  e81061feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f97d0  8b15a44d9f00           -mov edx, dword ptr [0x9f4da4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004f97d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f97d8  0f85d5000000           -jne 0x4f98b3
    if (!cpu.flags.zf)
    {
        goto L_0x004f98b3;
    }
L_0x004f97de:
    // 004f97de  8b1da04d9f00           -mov ebx, dword ptr [0x9f4da0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f97e4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f97e6  7425                   -je 0x4f980d
    if (cpu.flags.zf)
    {
        goto L_0x004f980d;
    }
    // 004f97e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f97e9  e8735e0300             -call 0x52f661
    cpu.esp -= 4;
    sub_52f661(app, cpu);
    if (cpu.terminate) return;
    // 004f97ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f97f0  741b                   -je 0x4f980d
    if (cpu.flags.zf)
    {
        goto L_0x004f980d;
    }
    // 004f97f2  bf3cda5400             -mov edi, 0x54da3c
    cpu.edi = 5560892 /*0x54da3c*/;
    // 004f97f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f97f8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f97fa  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f97ff  893db4ab5600           -mov dword ptr [0x56abb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edi;
    // 004f9805  e846780000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f980a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f980d:
    // 004f980d  8b2d844d9f00           -mov ebp, dword ptr [0x9f4d84]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004f9813  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f9815  0f84a3000000           -je 0x4f98be
    if (cpu.flags.zf)
    {
        goto L_0x004f98be;
    }
    // 004f981b  8b5538                 -mov edx, dword ptr [ebp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */);
    // 004f981e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f9820  83faff                 +cmp edx, -1
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
    // 004f9823  0f8495000000           -je 0x4f98be
    if (cpu.flags.zf)
    {
        goto L_0x004f98be;
    }
    // 004f9829  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f982b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f982d  e8ce190200             -call 0x51b200
    cpu.esp -= 4;
    sub_51b200(app, cpu);
    if (cpu.terminate) return;
    // 004f9832  893d844d9f00           -mov dword ptr [0x9f4d84], edi
    app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */) = cpu.edi;
L_0x004f9838:
    // 004f9838  8b2d884d9f00           -mov ebp, dword ptr [0x9f4d88]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f983e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f9840  740e                   -je 0x4f9850
    if (cpu.flags.zf)
    {
        goto L_0x004f9850;
    }
    // 004f9842  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f9844  e84780feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9849  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f984b  a3884d9f00             -mov dword ptr [0x9f4d88], eax
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.eax;
L_0x004f9850:
    // 004f9850  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9857  7443                   -je 0x4f989c
    if (cpu.flags.zf)
    {
        goto L_0x004f989c;
    }
    // 004f9859  8b0d804d9f00           -mov ecx, dword ptr [0x9f4d80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f985f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9861  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f9863  7e25                   -jle 0x4f988a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f988a;
    }
    // 004f9865  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f9867:
    // 004f9867  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f986c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f986e  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9871  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f9873  7407                   -je 0x4f987c
    if (cpu.flags.zf)
    {
        goto L_0x004f987c;
    }
    // 004f9875  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f9877  e81480feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f987c:
    // 004f987c  8b1d804d9f00           -mov ebx, dword ptr [0x9f4d80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9882  42                     -inc edx
    (cpu.edx)++;
    // 004f9883  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f9886  39da                   +cmp edx, ebx
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
    // 004f9888  7cdd                   -jl 0x4f9867
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f9867;
    }
L_0x004f988a:
    // 004f988a  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f988f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f9891  e8fa7ffeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9896  8935944d9f00           -mov dword ptr [0x9f4d94], esi
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.esi;
L_0x004f989c:
    // 004f989c  8b2d744d9f00           -mov ebp, dword ptr [0x9f4d74]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f98a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f98a3  e82a8c0300             -call 0x5324d2
    cpu.esp -= 4;
    sub_5324d2(app, cpu);
    if (cpu.terminate) return;
    // 004f98a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f98aa  7550                   -jne 0x4f98fc
    if (!cpu.flags.zf)
    {
        goto L_0x004f98fc;
    }
    // 004f98ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f98b3:
    // 004f98b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f98b4  e8b0600300             -call 0x52f969
    cpu.esp -= 4;
    sub_52f969(app, cpu);
    if (cpu.terminate) return;
    // 004f98b9  e920ffffff             -jmp 0x4f97de
    goto L_0x004f97de;
L_0x004f98be:
    // 004f98be  8b0da84d9f00           -mov ecx, dword ptr [0x9f4da8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */);
    // 004f98c4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f98c6  0f846cffffff           -je 0x4f9838
    if (cpu.flags.zf)
    {
        goto L_0x004f9838;
    }
    // 004f98cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f98cd  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f98d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f98d6  0f855cffffff           -jne 0x4f9838
    if (!cpu.flags.zf)
    {
        goto L_0x004f9838;
    }
    // 004f98dc  be50da5400             -mov esi, 0x54da50
    cpu.esi = 5560912 /*0x54da50*/;
    // 004f98e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f98e2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f98e4  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f98e9  8935b4ab5600           -mov dword ptr [0x56abb4], esi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.esi;
    // 004f98ef  e85c770000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f98f4  83c40c                 +add esp, 0xc
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
    // 004f98f7  e93cffffff             -jmp 0x4f9838
    goto L_0x004f9838;
L_0x004f98fc:
    // 004f98fc  b870da5400             -mov eax, 0x54da70
    cpu.eax = 5560944 /*0x54da70*/;
    // 004f9901  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9902  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9904  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9909  a3b4ab5600             -mov dword ptr [0x56abb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.eax;
    // 004f990e  e83d770000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9913  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f9916  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9917  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9918  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9919  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f991a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f991b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f991c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f9920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9921  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9922  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9923  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9925  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9927  89159c4d9f00           -mov dword ptr [0x9f4d9c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.edx;
    // 004f992d  833da8715600ff         +cmp dword ptr [0x5671a8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9934  7463                   -je 0x4f9999
    if (cpu.flags.zf)
    {
        goto L_0x004f9999;
    }
    // 004f9936  6afa                   -push -6
    app->getMemory<x86::reg32>(cpu.esp-4) = -6 /*-0x6*/;
    cpu.esp -= 4;
    // 004f9938  e83321ffff             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 004f993d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f993e  2eff1558475300         -call dword ptr cs:[0x534758]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457752) /* 0x534758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9945  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f994a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f994c  e89f000000             -call 0x4f99f0
    cpu.esp -= 4;
    sub_4f99f0(app, cpu);
    if (cpu.terminate) return;
    // 004f9951  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9953  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9955  0f8579000000           -jne 0x4f99d4
    if (!cpu.flags.zf)
    {
        goto L_0x004f99d4;
    }
    // 004f995b  e8c0030000             -call 0x4f9d20
    cpu.esp -= 4;
    sub_4f9d20(app, cpu);
    if (cpu.terminate) return;
    // 004f9960  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9962  0f8477000000           -je 0x4f99df
    if (cpu.flags.zf)
    {
        goto L_0x004f99df;
    }
    // 004f9968  e883040000             -call 0x4f9df0
    cpu.esp -= 4;
    sub_4f9df0(app, cpu);
    if (cpu.terminate) return;
    // 004f996d  e84efeffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
    // 004f9972  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004f9977  e8645ffeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f997c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f997e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f9980  e86b000000             -call 0x4f99f0
    cpu.esp -= 4;
    sub_4f99f0(app, cpu);
    if (cpu.terminate) return;
    // 004f9985  83f80a                 +cmp eax, 0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9988  7455                   -je 0x4f99df
    if (cpu.flags.zf)
    {
        goto L_0x004f99df;
    }
    // 004f998a  e891030000             -call 0x4f9d20
    cpu.esp -= 4;
    sub_4f9d20(app, cpu);
    if (cpu.terminate) return;
    // 004f998f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9991  7451                   -je 0x4f99e4
    if (cpu.flags.zf)
    {
        goto L_0x004f99e4;
    }
    // 004f9993  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9995  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9996  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9997  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9998  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9999:
    // 004f9999  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f999a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f999b  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004f99a0  be98da5400             -mov esi, 0x54da98
    cpu.esi = 5560984 /*0x54da98*/;
    // 004f99a5  bf23010000             -mov edi, 0x123
    cpu.edi = 291 /*0x123*/;
    // 004f99aa  68a4da5400             -push 0x54daa4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560996 /*0x54daa4*/;
    cpu.esp -= 4;
    // 004f99af  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f99b5  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f99bb  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f99c1  e84a76f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f99c6  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004f99cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f99ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f99d4:
    // 004f99d4  e8e7fdffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
    // 004f99d9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f99db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f99df:
    // 004f99df  e8dcfdffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
L_0x004f99e4:
    // 004f99e4  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004f99e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f99f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f99f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f99f1  68904d9f00             -push 0x9f4d90
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440080 /*0x9f4d90*/;
    cpu.esp -= 4;
    // 004f99f6  89157c4d9f00           -mov dword ptr [0x9f4d7c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440060) /* 0x9f4d7c */) = cpu.edx;
    // 004f99fc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f99fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f99ff  6800954f00             -push 0x4f9500
    app->getMemory<x86::reg32>(cpu.esp-4) = 5215488 /*0x4f9500*/;
    cpu.esp -= 4;
    // 004f9a04  8915884d9f00           -mov dword ptr [0x9f4d88], edx
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.edx;
    // 004f9a0a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9a0b  8915a84d9f00           -mov dword ptr [0x9f4da8], edx
    app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */) = cpu.edx;
    // 004f9a11  8915a44d9f00           -mov dword ptr [0x9f4da4], edx
    app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */) = cpu.edx;
    // 004f9a17  68744d9f00             -push 0x9f4d74
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440052 /*0x9f4d74*/;
    cpu.esp -= 4;
    // 004f9a1c  8915a04d9f00           -mov dword ptr [0x9f4da0], edx
    app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */) = cpu.edx;
    // 004f9a22  8915944d9f00           -mov dword ptr [0x9f4d94], edx
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.edx;
    // 004f9a28  e891760300             -call 0x5310be
    cpu.esp -= 4;
    sub_5310be(app, cpu);
    if (cpu.terminate) return;
    // 004f9a2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9a2f  7510                   -jne 0x4f9a41
    if (!cpu.flags.zf)
    {
        goto L_0x004f9a41;
    }
    // 004f9a31  833d904d9f0000         +cmp dword ptr [0x9f4d90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9a38  7505                   -jne 0x4f9a3f
    if (!cpu.flags.zf)
    {
        goto L_0x004f9a3f;
    }
    // 004f9a3a  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
L_0x004f9a3f:
    // 004f9a3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9a41:
    // 004f9a41  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004f9a46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9a50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9a51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9a52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9a54  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9a5b  741d                   -je 0x4f9a7a
    if (cpu.flags.zf)
    {
        goto L_0x004f9a7a;
    }
L_0x004f9a5d:
    // 004f9a5d  3b15804d9f00           +cmp edx, dword ptr [0x9f4d80]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9a63  7d1c                   -jge 0x4f9a81
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f9a81;
    }
    // 004f9a65  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9a6a  8b04d0                 -mov eax, dword ptr [eax + edx*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 8);
    // 004f9a6d  a3a8715600             -mov dword ptr [0x5671a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */) = cpu.eax;
    // 004f9a72  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9a77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9a7a:
    // 004f9a7a  e841000000             -call 0x4f9ac0
    cpu.esp -= 4;
    sub_4f9ac0(app, cpu);
    if (cpu.terminate) return;
    // 004f9a7f  ebdc                   -jmp 0x4f9a5d
    goto L_0x004f9a5d;
L_0x004f9a81:
    // 004f9a81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9a82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9a83  be88da5400             -mov esi, 0x54da88
    cpu.esi = 5560968 /*0x54da88*/;
    // 004f9a88  bfecda5400             -mov edi, 0x54daec
    cpu.edi = 5561068 /*0x54daec*/;
    // 004f9a8d  bd76010000             -mov ebp, 0x176
    cpu.ebp = 374 /*0x176*/;
    // 004f9a92  68fcda5400             -push 0x54dafc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561084 /*0x54dafc*/;
    cpu.esp -= 4;
    // 004f9a97  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004f9a9d  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f9aa3  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f9aa9  e86275f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f9aae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f9ab1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9ab3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9ac0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9ac1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9ac2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9ac3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9ac4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9ac5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9ac8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9aca  6afa                   -push -6
    app->getMemory<x86::reg32>(cpu.esp-4) = -6 /*-0x6*/;
    cpu.esp -= 4;
    // 004f9acc  8915804d9f00           -mov dword ptr [0x9f4d80], edx
    app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */) = cpu.edx;
    // 004f9ad2  e8991fffff             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 004f9ad7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9ad8  2eff1558475300         -call dword ptr cs:[0x534758]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457752) /* 0x534758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9adf  68904d9f00             -push 0x9f4d90
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440080 /*0x9f4d90*/;
    cpu.esp -= 4;
    // 004f9ae4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9ae6  6800954f00             -push 0x4f9500
    app->getMemory<x86::reg32>(cpu.esp-4) = 5215488 /*0x4f9500*/;
    cpu.esp -= 4;
    // 004f9aeb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9aec  68744d9f00             -push 0x9f4d74
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440052 /*0x9f4d74*/;
    cpu.esp -= 4;
    // 004f9af1  e8c8750300             -call 0x5310be
    cpu.esp -= 4;
    sub_5310be(app, cpu);
    if (cpu.terminate) return;
    // 004f9af6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9af8  0f8529010000           -jne 0x4f9c27
    if (!cpu.flags.zf)
    {
        goto L_0x004f9c27;
    }
    // 004f9afe  833d904d9f0000         +cmp dword ptr [0x9f4d90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b05  0f8427010000           -je 0x4f9c32
    if (cpu.flags.zf)
    {
        goto L_0x004f9c32;
    }
    // 004f9b0b  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b12  7433                   -je 0x4f9b47
    if (cpu.flags.zf)
    {
        goto L_0x004f9b47;
    }
    // 004f9b14  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f9b16:
    // 004f9b16  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9b1b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004f9b1d  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9b20  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f9b22  7407                   -je 0x4f9b2b
    if (cpu.flags.zf)
    {
        goto L_0x004f9b2b;
    }
    // 004f9b24  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f9b26  e8657dfeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f9b2b:
    // 004f9b2b  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f9b2e  81fea0000000           +cmp esi, 0xa0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b34  75e0                   -jne 0x4f9b16
    if (!cpu.flags.zf)
    {
        goto L_0x004f9b16;
    }
    // 004f9b36  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9b3b  e8507dfeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9b40  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9b42  a3944d9f00             -mov dword ptr [0x9f4d94], eax
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.eax;
L_0x004f9b47:
    // 004f9b47  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9b48  ba88da5400             -mov edx, 0x54da88
    cpu.edx = 5560968 /*0x54da88*/;
    // 004f9b4d  b914db5400             -mov ecx, 0x54db14
    cpu.ecx = 5561108 /*0x54db14*/;
    // 004f9b52  bba9010000             -mov ebx, 0x1a9
    cpu.ebx = 425 /*0x1a9*/;
    // 004f9b57  b828db5400             -mov eax, 0x54db28
    cpu.eax = 5561128 /*0x54db28*/;
    // 004f9b5c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f9b5e  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f9b64  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f9b6a  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 004f9b6f  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9b75  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f9b7b  e8a07afeff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9b80  a3944d9f00             -mov dword ptr [0x9f4d94], eax
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.eax;
    // 004f9b85  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f9b87:
    // 004f9b87  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9b8c  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f9b8f  895406fc               -mov dword ptr [esi + eax - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.edx;
    // 004f9b93  895406f8               -mov dword ptr [esi + eax - 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.edx;
    // 004f9b97  81fea0000000           +cmp esi, 0xa0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b9d  75e8                   -jne 0x4f9b87
    if (!cpu.flags.zf)
    {
        goto L_0x004f9b87;
    }
    // 004f9b9f  8b3d904d9f00           -mov edi, dword ptr [0x9f4d90]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
    // 004f9ba5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f9ba7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f9ba9  7639                   -jbe 0x4f9be4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9be4;
    }
    // 004f9bab  bf14db5400             -mov edi, 0x54db14
    cpu.edi = 5561108 /*0x54db14*/;
L_0x004f9bb0:
    // 004f9bb0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9bb4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9bb5  688c4d9f00             -push 0x9f4d8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440076 /*0x9f4d8c*/;
    cpu.esp -= 4;
    // 004f9bba  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9bbf  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9bc4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9bc5  8b0d744d9f00           -mov ecx, dword ptr [0x9f4d74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9bcb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9bcc  e8be770300             -call 0x53138f
    cpu.esp -= 4;
    sub_53138f(app, cpu);
    if (cpu.terminate) return;
    // 004f9bd1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9bd3  0f8499000000           -je 0x4f9c72
    if (cpu.flags.zf)
    {
        goto L_0x004f9c72;
    }
L_0x004f9bd9:
    // 004f9bd9  8b2d904d9f00           -mov ebp, dword ptr [0x9f4d90]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
    // 004f9bdf  46                     -inc esi
    (cpu.esi)++;
    // 004f9be0  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9be2  72cc                   -jb 0x4f9bb0
    if (cpu.flags.cf)
    {
        goto L_0x004f9bb0;
    }
L_0x004f9be4:
    // 004f9be4  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004f9be9  e8f25cfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f9bee  a1744d9f00             -mov eax, dword ptr [0x9f4d74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9bf3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9bf4  e8d9880300             -call 0x5324d2
    cpu.esp -= 4;
    sub_5324d2(app, cpu);
    if (cpu.terminate) return;
    // 004f9bf9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9bfb  741b                   -je 0x4f9c18
    if (cpu.flags.zf)
    {
        goto L_0x004f9c18;
    }
    // 004f9bfd  ba70da5400             -mov edx, 0x54da70
    cpu.edx = 5560944 /*0x54da70*/;
    // 004f9c02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9c03  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9c05  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9c0a  8915b4ab5600           -mov dword ptr [0x56abb4], edx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edx;
    // 004f9c10  e83b740000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9c15  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f9c18:
    // 004f9c18  a1804d9f00             -mov eax, dword ptr [0x9f4d80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9c1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c1e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9c21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9c27:
    // 004f9c27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9c29  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9c2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9c32:
    // 004f9c32  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004f9c37  e8a45cfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f9c3c  8b35744d9f00           -mov esi, dword ptr [0x9f4d74]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9c42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9c43  e88a880300             -call 0x5324d2
    cpu.esp -= 4;
    sub_5324d2(app, cpu);
    if (cpu.terminate) return;
    // 004f9c48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9c4a  741b                   -je 0x4f9c67
    if (cpu.flags.zf)
    {
        goto L_0x004f9c67;
    }
    // 004f9c4c  bf70da5400             -mov edi, 0x54da70
    cpu.edi = 5560944 /*0x54da70*/;
    // 004f9c51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9c52  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9c54  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9c59  893db4ab5600           -mov dword ptr [0x56abb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edi;
    // 004f9c5f  e8ec730000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9c64  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f9c67:
    // 004f9c67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9c69  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9c6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9c72:
    // 004f9c72  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f9c74  e8b7020000             -call 0x4f9f30
    cpu.esp -= 4;
    sub_4f9f30(app, cpu);
    if (cpu.terminate) return;
    // 004f9c79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9c7b  0f8558ffffff           -jne 0x4f9bd9
    if (!cpu.flags.zf)
    {
        goto L_0x004f9bd9;
    }
    // 004f9c81  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9c86  f6403c10               +test byte ptr [eax + 0x3c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) & 16 /*0x10*/));
    // 004f9c8a  0f8449ffffff           -je 0x4f9bd9
    if (cpu.flags.zf)
    {
        goto L_0x004f9bd9;
    }
    // 004f9c90  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004f9c95  bdc1010000             -mov ebp, 0x1c1
    cpu.ebp = 449 /*0x1c1*/;
    // 004f9c9a  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f9ca0  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f9ca3  b834db5400             -mov eax, 0x54db34
    cpu.eax = 5561140 /*0x54db34*/;
    // 004f9ca8  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f9cae  42                     -inc edx
    (cpu.edx)++;
    // 004f9caf  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9cb5  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f9cbb  e86079feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9cc0  8b0d804d9f00           -mov ecx, dword ptr [0x9f4d80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9cc6  8b15944d9f00           -mov edx, dword ptr [0x9f4d94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9ccc  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004f9ccf  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f9cd1  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f9cd4  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9cd9  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004f9cdc  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f9cdf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f9ce1  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f9ce4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f9ce6  e84571feff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f9ceb  8b15804d9f00           -mov edx, dword ptr [0x9f4d80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9cf1  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9cf6  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004f9cf9  01d0                   +add eax, edx
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
    // 004f9cfb  8b15884d9f00           -mov edx, dword ptr [0x9f4d88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9d01  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9d04  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004f9d07  c6041100               -mov byte ptr [ecx + edx], 0
    app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1) = 0 /*0x0*/;
    // 004f9d0b  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004f9d0d  ff05804d9f00           +inc dword ptr [0x9f4d80]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f9d13  e9c1feffff             -jmp 0x4f9bd9
    goto L_0x004f9bd9;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9d21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9d22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9d23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9d24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9d25  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9d28  8b15a8715600           -mov edx, dword ptr [0x5671a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9d2e  83faff                 +cmp edx, -1
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
    // 004f9d31  750b                   -jne 0x4f9d3e
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d3e;
    }
L_0x004f9d33:
    // 004f9d33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9d35  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9d38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9d3e:
    // 004f9d3e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9d40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9d41  688c4d9f00             -push 0x9f4d8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440076 /*0x9f4d8c*/;
    cpu.esp -= 4;
    // 004f9d46  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9d4b  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9d50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9d51  8b1d744d9f00           -mov ebx, dword ptr [0x9f4d74]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9d57  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9d58  e832760300             -call 0x53138f
    cpu.esp -= 4;
    sub_53138f(app, cpu);
    if (cpu.terminate) return;
    // 004f9d5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9d5f  75d2                   -jne 0x4f9d33
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d33;
    }
    // 004f9d61  a1a8715600             -mov eax, dword ptr [0x5671a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9d66  e8c5010000             -call 0x4f9f30
    cpu.esp -= 4;
    sub_4f9f30(app, cpu);
    if (cpu.terminate) return;
    // 004f9d6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9d6d  75c4                   -jne 0x4f9d33
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d33;
    }
    // 004f9d6f  833d7c4d9f0000         +cmp dword ptr [0x9f4d7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440060) /* 0x9f4d7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9d76  746b                   -je 0x4f9de3
    if (cpu.flags.zf)
    {
        goto L_0x004f9de3;
    }
    // 004f9d78  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x004f9d7d:
    // 004f9d7d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9d7f  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004f9d81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9d82  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9d84  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9d86  8b3d8c4d9f00           -mov edi, dword ptr [0x9f4d8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440076) /* 0x9f4d8c */);
    // 004f9d8c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9d8d  68a04d9f00             -push 0x9f4da0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440096 /*0x9f4da0*/;
    cpu.esp -= 4;
    // 004f9d92  8b2da8715600           -mov ebp, dword ptr [0x5671a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9d98  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9d99  a1744d9f00             -mov eax, dword ptr [0x9f4d74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9d9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9d9f  e895760300             -call 0x531439
    cpu.esp -= 4;
    sub_531439(app, cpu);
    if (cpu.terminate) return;
    // 004f9da4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9da6  758b                   -jne 0x4f9d33
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d33;
    }
    // 004f9da8  833d784d9f0000         +cmp dword ptr [0x9f4d78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440056) /* 0x9f4d78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9daf  7424                   -je 0x4f9dd5
    if (cpu.flags.zf)
    {
        goto L_0x004f9dd5;
    }
    // 004f9db1  a1a04d9f00             -mov eax, dword ptr [0x9f4da0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f9db6  e8e5000000             -call 0x4f9ea0
    cpu.esp -= 4;
    sub_4f9ea0(app, cpu);
    if (cpu.terminate) return;
    // 004f9dbb  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9dc0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9dc2  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004f9dc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9dc9  8b1da04d9f00           -mov ebx, dword ptr [0x9f4da0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f9dcf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9dd0  e88d830300             -call 0x532162
    cpu.esp -= 4;
    sub_532162(app, cpu);
    if (cpu.terminate) return;
L_0x004f9dd5:
    // 004f9dd5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9dda  83c410                 +add esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f9ddd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9dde  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ddf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9de0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9de1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9de2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9de3:
    // 004f9de3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9de8  eb93                   -jmp 0x4f9d7d
    goto L_0x004f9d7d;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f9df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9df1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9df2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9df3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9df4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9df5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9df6  81ec401f0000           -sub esp, 0x1f40
    (cpu.esp) -= x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9dfc  bb401f0000             -mov ebx, 0x1f40
    cpu.ebx = 8000 /*0x1f40*/;
    // 004f9e01  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9e03  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9e05  e83668feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f9e0a  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004f9e0f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9e13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9e14  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9e16  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9e18  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9e1a  8b0da04d9f00           -mov ecx, dword ptr [0x9f4da0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f9e20  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 004f9e25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9e26  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004f9e2a  e81f6c0300             -call 0x530a4e
    cpu.esp -= 4;
    sub_530a4e(app, cpu);
    if (cpu.terminate) return;
    // 004f9e2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9e31  740f                   -je 0x4f9e42
    if (cpu.flags.zf)
    {
        goto L_0x004f9e42;
    }
L_0x004f9e33:
    // 004f9e33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9e35  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9e3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9e42:
    // 004f9e42  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f9e44  035c2414               -add ebx, dword ptr [esp + 0x14]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004f9e48  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 004f9e4d  68603d9f00             -push 0x9f3d60
    app->getMemory<x86::reg32>(cpu.esp-4) = 10435936 /*0x9f3d60*/;
    cpu.esp -= 4;
    // 004f9e52  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f9e54  bf2ef53ce7             -mov edi, 0xe73cf52e
    cpu.edi = 3879531822 /*0xe73cf52e*/;
    // 004f9e59  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9e5a  668915603d9f00         -mov word ptr [0x9f3d60], dx
    app->getMemory<x86::reg16>(x86::reg32(10435936) /* 0x9f3d60 */) = cpu.dx;
    // 004f9e61  893d943d9f00           -mov dword ptr [0x9f3d94], edi
    app->getMemory<x86::reg32>(x86::reg32(10435988) /* 0x9f3d94 */) = cpu.edi;
    // 004f9e67  2eff15ec445300         -call dword ptr cs:[0x5344ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457132) /* 0x5344ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9e6e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f9e70  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f9e72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9e73  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9e7a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f9e7c  74b5                   -je 0x4f9e33
    if (cpu.flags.zf)
    {
        goto L_0x004f9e33;
    }
    // 004f9e7e  b8603d9f00             -mov eax, 0x9f3d60
    cpu.eax = 10435936 /*0x9f3d60*/;
    // 004f9e83  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004f9e86  a3784d9f00             -mov dword ptr [0x9f4d78], eax
    app->getMemory<x86::reg32>(x86::reg32(10440056) /* 0x9f4d78 */) = cpu.eax;
    // 004f9e8b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9e90  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9e96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f9ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9ea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9ea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9ea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9ea3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9ea4  81ec401f0000           -sub esp, 0x1f40
    (cpu.esp) -= x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9eaa  bb401f0000             -mov ebx, 0x1f40
    cpu.ebx = 8000 /*0x1f40*/;
    // 004f9eaf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9eb1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9eb3  e88867feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f9eb8  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004f9ebd  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9ec1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9ec2  8b0da8715600           -mov ecx, dword ptr [0x5671a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9ec8  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 004f9ecd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9ece  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004f9ed2  e866690300             -call 0x53083d
    cpu.esp -= 4;
    sub_53083d(app, cpu);
    if (cpu.terminate) return;
    // 004f9ed7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9ed9  7509                   -jne 0x4f9ee4
    if (!cpu.flags.zf)
    {
        goto L_0x004f9ee4;
    }
    // 004f9edb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9edf  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004f9ee2  760d                   -jbe 0x4f9ef1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9ef1;
    }
L_0x004f9ee4:
    // 004f9ee4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9ee6  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9eec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9eed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9eee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9eef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ef0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9ef1:
    // 004f9ef1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9ef2  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9ef6  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004f9efa  8d503c                 -lea edx, [eax + 0x3c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004f9efd  806220f8               -and byte ptr [edx + 0x20], 0xf8
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(32) /* 0x20 */) &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004f9f01  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004f9f06  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f9f0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9f0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9f0c  8b2da8715600           -mov ebp, dword ptr [0x5671a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9f12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9f13  e819800300             -call 0x531f31
    cpu.esp -= 4;
    sub_531f31(app, cpu);
    if (cpu.terminate) return;
    // 004f9f18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9f1a  7405                   -je 0x4f9f21
    if (cpu.flags.zf)
    {
        goto L_0x004f9f21;
    }
    // 004f9f1c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f9f21:
    // 004f9f21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f22  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9f28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f9f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9f32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9f33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9f34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9f35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9f36  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f9f38  8b15884d9f00           -mov edx, dword ptr [0x9f4d88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9f3e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f9f40  0f85af000000           -jne 0x4f9ff5
    if (!cpu.flags.zf)
    {
        goto L_0x004f9ff5;
    }
L_0x004f9f46:
    // 004f9f46  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004f9f4b  bf50db5400             -mov edi, 0x54db50
    cpu.edi = 5561168 /*0x54db50*/;
    // 004f9f50  bd5a020000             -mov ebp, 0x25a
    cpu.ebp = 602 /*0x25a*/;
    // 004f9f55  baf0000000             -mov edx, 0xf0
    cpu.edx = 240 /*0xf0*/;
    // 004f9f5a  b860db5400             -mov eax, 0x54db60
    cpu.eax = 5561184 /*0x54db60*/;
    // 004f9f5f  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f9f65  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f9f6b  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f9f71  bf88da5400             -mov edi, 0x54da88
    cpu.edi = 5560968 /*0x54da88*/;
    // 004f9f76  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9f7c  bd50db5400             -mov ebp, 0x54db50
    cpu.ebp = 5561168 /*0x54db50*/;
    // 004f9f81  e89a76feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9f86  a3884d9f00             -mov dword ptr [0x9f4d88], eax
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.eax;
    // 004f9f8b  c700f0000000           -mov dword ptr [eax], 0xf0
    app->getMemory<x86::reg32>(cpu.eax) = 240 /*0xf0*/;
L_0x004f9f91:
    // 004f9f91  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9f96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9f97  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9f99  8b158c4d9f00           -mov edx, dword ptr [0x9f4d8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440076) /* 0x9f4d8c */);
    // 004f9f9f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9fa0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9fa1  8b0d744d9f00           -mov ecx, dword ptr [0x9f4d74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9fa7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9fa8  e89a670300             -call 0x530747
    cpu.esp -= 4;
    sub_530747(app, cpu);
    if (cpu.terminate) return;
    // 004f9fad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9faf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9fb1  7556                   -jne 0x4fa009
    if (!cpu.flags.zf)
    {
        goto L_0x004fa009;
    }
    // 004f9fb3  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9fb8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9fbb  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9fbd  765c                   -jbe 0x4fa01b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fa01b;
    }
    // 004f9fbf  e8cc78feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9fc4  b86f020000             -mov eax, 0x26f
    cpu.eax = 623 /*0x26f*/;
    // 004f9fc9  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9fcf  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004f9fd5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f9fd7  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f9fdc  b860db5400             -mov eax, 0x54db60
    cpu.eax = 5561184 /*0x54db60*/;
    // 004f9fe1  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004f9fe7  e83476feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9fec  a3884d9f00             -mov dword ptr [0x9f4d88], eax
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.eax;
    // 004f9ff1  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004f9ff3  eb9c                   -jmp 0x4f9f91
    goto L_0x004f9f91;
L_0x004f9ff5:
    // 004f9ff5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f9ff7  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004f9ff9  e89278feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9ffe  890d884d9f00           -mov dword ptr [0x9f4d88], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.ecx;
    // 004fa004  e93dffffff             -jmp 0x4f9f46
    goto L_0x004f9f46;
L_0x004fa009:
    // 004fa009  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004fa00e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fa010  e87b78feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa015  890d884d9f00           -mov dword ptr [0x9f4d88], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.ecx;
L_0x004fa01b:
    // 004fa01b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa01d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa01e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa01f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa020  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa021  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa022  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa023  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fa030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa033  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa034  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa035  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa036  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa038  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa03a  740b                   -je 0x4fa047
    if (cpu.flags.zf)
    {
        goto L_0x004fa047;
    }
    // 004fa03c  833da04d9f0000         +cmp dword ptr [0x9f4da0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa043  7509                   -jne 0x4fa04e
    if (!cpu.flags.zf)
    {
        goto L_0x004fa04e;
    }
    // 004fa045  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fa047:
    // 004fa047  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa048  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa049  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa04e:
    // 004fa04e  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004fa053  be70db5400             -mov esi, 0x54db70
    cpu.esi = 5561200 /*0x54db70*/;
    // 004fa058  bf87020000             -mov edi, 0x287
    cpu.edi = 647 /*0x287*/;
    // 004fa05d  ba70000000             -mov edx, 0x70
    cpu.edx = 112 /*0x70*/;
    // 004fa062  b880db5400             -mov eax, 0x54db80
    cpu.eax = 5561216 /*0x54db80*/;
    // 004fa067  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004fa06d  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004fa073  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fa079  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004fa07f  e89c75feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fa084  bb70000000             -mov ebx, 0x70
    cpu.ebx = 112 /*0x70*/;
    // 004fa089  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa08b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa08d  e8ae65feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004fa092  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa093  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa095  c70670000000           -mov dword ptr [esi], 0x70
    app->getMemory<x86::reg32>(cpu.esi) = 112 /*0x70*/;
    // 004fa09b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa09c  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004fa0a3  68a44d9f00             -push 0x9f4da4
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440100 /*0x9f4da4*/;
    cpu.esp -= 4;
    // 004fa0a8  8b2da04d9f00           -mov ebp, dword ptr [0x9f4da0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004fa0ae  c7461010000000         -mov dword ptr [esi + 0x10], 0x10
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 16 /*0x10*/;
    // 004fa0b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa0b6  c7462cb80b0000         -mov dword ptr [esi + 0x2c], 0xbb8
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 3000 /*0xbb8*/;
    // 004fa0bd  e8fe700300             -call 0x5311c0
    cpu.esp -= 4;
    sub_5311c0(app, cpu);
    if (cpu.terminate) return;
    // 004fa0c2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa0c4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa0c6  e8c577feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa0cb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fa0cd  7c0c                   -jl 0x4fa0db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa0db;
    }
    // 004fa0cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa0d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa0db:
    // 004fa0db  c7059c4d9f000f000000   -mov dword ptr [0x9f4d9c], 0xf
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 15 /*0xf*/;
    // 004fa0e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa0e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4fa0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa0f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa0f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa0f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa0f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa0f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa0f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa0f6  ba88da5400             -mov edx, 0x54da88
    cpu.edx = 5560968 /*0x54da88*/;
    // 004fa0fb  b994db5400             -mov ecx, 0x54db94
    cpu.ecx = 5561236 /*0x54db94*/;
    // 004fa100  bbaa020000             -mov ebx, 0x2aa
    cpu.ebx = 682 /*0x2aa*/;
    // 004fa105  b8a8db5400             -mov eax, 0x54dba8
    cpu.eax = 5561256 /*0x54dba8*/;
    // 004fa10a  bd88da5400             -mov ebp, 0x54da88
    cpu.ebp = 5560968 /*0x54da88*/;
    // 004fa10f  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004fa115  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004fa11b  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004fa120  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fa126  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004fa12c  e8ef74feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fa131  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa133  c70018000000           -mov dword ptr [eax], 0x18
    app->getMemory<x86::reg32>(cpu.eax) = 24 /*0x18*/;
L_0x004fa139:
    // 004fa139  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004fa13e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa13f  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004fa141  8b35a44d9f00           -mov esi, dword ptr [0x9f4da4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004fa147  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa148  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa14a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa14c  e8fd680300             -call 0x530a4e
    cpu.esp -= 4;
    sub_530a4e(app, cpu);
    if (cpu.terminate) return;
    // 004fa151  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa153  7541                   -jne 0x4fa196
    if (!cpu.flags.zf)
    {
        goto L_0x004fa196;
    }
    // 004fa155  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004fa158  3b3b                   +cmp edi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa15a  764d                   -jbe 0x4fa1a9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fa1a9;
    }
    // 004fa15c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa15e  babd020000             -mov edx, 0x2bd
    cpu.edx = 701 /*0x2bd*/;
    // 004fa163  e82877feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa168  b894db5400             -mov eax, 0x54db94
    cpu.eax = 5561236 /*0x54db94*/;
    // 004fa16d  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fa173  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004fa179  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004fa17e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa180  b8a8db5400             -mov eax, 0x54dba8
    cpu.eax = 5561256 /*0x54dba8*/;
    // 004fa185  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004fa18b  e89074feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fa190  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa192  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 004fa194  eba3                   -jmp 0x4fa139
    goto L_0x004fa139;
L_0x004fa196:
    // 004fa196  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa198  e8f376feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa19d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004fa1a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa1a9:
    // 004fa1a9  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004fa1ac  8b0403                 -mov eax, dword ptr [ebx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 004fa1af  a3a84d9f00             -mov dword ptr [0x9f4da8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */) = cpu.eax;
    // 004fa1b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa1b6  e8d576feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa1bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa1bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fa1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa1d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa1d1  8b15a44d9f00           -mov edx, dword ptr [0x9f4da4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004fa1d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fa1d9  7502                   -jne 0x4fa1dd
    if (!cpu.flags.zf)
    {
        goto L_0x004fa1dd;
    }
    // 004fa1db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa1dd:
    // 004fa1dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa1de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa1df  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa1e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa1e3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa1e4  bbb8db5400             -mov ebx, 0x54dbb8
    cpu.ebx = 5561272 /*0x54dbb8*/;
    // 004fa1e9  e840590300             -call 0x52fb2e
    cpu.esp -= 4;
    sub_52fb2e(app, cpu);
    if (cpu.terminate) return;
    // 004fa1ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa1ef  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004fa1f1  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004fa1f6  891db4ab5600           -mov dword ptr [0x56abb4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.ebx;
    // 004fa1fc  e84f6e0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004fa201  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fa204  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa205  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa206  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa207  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa210  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa211  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fa214  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa219  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004fa21c  e82ff8ffff             -call 0x4f9a50
    cpu.esp -= 4;
    sub_4f9a50(app, cpu);
    if (cpu.terminate) return;
    // 004fa221  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa223  0f84c4000000           -je 0x4fa2ed
    if (cpu.flags.zf)
    {
        goto L_0x004fa2ed;
    }
    // 004fa229  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa22e  83786800               +cmp dword ptr [eax + 0x68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa232  0f8583000000           -jne 0x4fa2bb
    if (!cpu.flags.zf)
    {
        goto L_0x004fa2bb;
    }
    // 004fa238  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fa23d:
    // 004fa23d  e8def6ffff             -call 0x4f9920
    cpu.esp -= 4;
    sub_4f9920(app, cpu);
    if (cpu.terminate) return;
    // 004fa242  a39c4d9f00             -mov dword ptr [0x9f4d9c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.eax;
    // 004fa247  833d9c4d9f0000         +cmp dword ptr [0x9f4d9c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa24e  0f858f000000           -jne 0x4fa2e3
    if (!cpu.flags.zf)
    {
        goto L_0x004fa2e3;
    }
    // 004fa254  c7059c4d9f0002000000   -mov dword ptr [0x9f4d9c], 2
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 2 /*0x2*/;
    // 004fa25e  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa263  8b6868                 -mov ebp, dword ptr [eax + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 004fa266  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004fa268  7558                   -jne 0x4fa2c2
    if (!cpu.flags.zf)
    {
        goto L_0x004fa2c2;
    }
L_0x004fa26a:
    // 004fa26a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fa26f:
    // 004fa26f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa271  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa272  8b15844d9f00           -mov edx, dword ptr [0x9f4d84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa278  894234                 -mov dword ptr [edx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004fa27b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa27d  a3984d9f00             -mov dword ptr [0x9f4d98], eax
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = cpu.eax;
    // 004fa282  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004fa284:
    // 004fa284  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa289  3b5834                 +cmp ebx, dword ptr [eax + 0x34]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa28c  744d                   -je 0x4fa2db
    if (cpu.flags.zf)
    {
        goto L_0x004fa2db;
    }
    // 004fa28e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa28f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa291  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004fa295  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fa296  2eff154c475300         -call dword ptr cs:[0x53474c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457740) /* 0x53474c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa29d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa29f  742e                   -je 0x4fa2cf
    if (cpu.flags.zf)
    {
        goto L_0x004fa2cf;
    }
    // 004fa2a1  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa2a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fa2a6  2eff15a4475300         -call dword ptr cs:[0x5347a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457828) /* 0x5347a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa2ad  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa2b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fa2b2  2eff152c475300         -call dword ptr cs:[0x53472c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457708) /* 0x53472c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa2b9  ebc9                   -jmp 0x4fa284
    goto L_0x004fa284;
L_0x004fa2bb:
    // 004fa2bb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fa2bd  e97bffffff             -jmp 0x4fa23d
    goto L_0x004fa23d;
L_0x004fa2c2:
    // 004fa2c2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa2c4  e867fdffff             -call 0x4fa030
    cpu.esp -= 4;
    sub_4fa030(app, cpu);
    if (cpu.terminate) return;
    // 004fa2c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa2cb  759d                   -jne 0x4fa26a
    if (!cpu.flags.zf)
    {
        goto L_0x004fa26a;
    }
    // 004fa2cd  eba0                   -jmp 0x4fa26f
    goto L_0x004fa26f;
L_0x004fa2cf:
    // 004fa2cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa2d4  e80756feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa2d9  eba9                   -jmp 0x4fa284
    goto L_0x004fa284;
L_0x004fa2db:
    // 004fa2db  e8f0feffff             -call 0x4fa1d0
    cpu.esp -= 4;
    sub_4fa1d0(app, cpu);
    if (cpu.terminate) return;
    // 004fa2e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa2e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa2e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004fa2e3:
    // 004fa2e3  e8d8f4ffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
    // 004fa2e8  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fa2eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa2ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa2ed:
    // 004fa2ed  c7059c4d9f0002000080   -mov dword ptr [0x9f4d9c], 0x80000002
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 2147483650 /*0x80000002*/;
    // 004fa2f7  a3844d9f00             -mov dword ptr [0x9f4d84], eax
    app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */) = cpu.eax;
    // 004fa2fc  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fa2ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa300  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4fa310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa312  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa313  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa314  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa315  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa317  a3844d9f00             -mov dword ptr [0x9f4d84], eax
    app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */) = cpu.eax;
    // 004fa31c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fa31e  8915ac715600           -mov dword ptr [0x5671ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5665196) /* 0x5671ac */) = cpu.edx;
    // 004fa324  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa326  89159c4d9f00           -mov dword ptr [0x9f4d9c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.edx;
    // 004fa32c  c74038ffffffff         -mov dword ptr [eax + 0x38], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 4294967295 /*0xffffffff*/;
    // 004fa333  68604d9f00             -push 0x9f4d60
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440032 /*0x9f4d60*/;
    cpu.esp -= 4;
    // 004fa338  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 004fa33b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004fa340  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004fa345  b810a24f00             -mov eax, 0x4fa210
    cpu.eax = 5218832 /*0x4fa210*/;
    // 004fa34a  890d984d9f00           -mov dword ptr [0x9f4d98], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = cpu.ecx;
    // 004fa350  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004fa355  e84654feff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004fa35a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa35c  0f84c7000000           -je 0x4fa429
    if (cpu.flags.zf)
    {
        goto L_0x004fa429;
    }
    // 004fa362  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
L_0x004fa367:
    // 004fa367  833d984d9f0000         +cmp dword ptr [0x9f4d98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa36e  7416                   -je 0x4fa386
    if (cpu.flags.zf)
    {
        goto L_0x004fa386;
    }
    // 004fa370  8b1dd8435600           -mov ebx, dword ptr [0x5643d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa376  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fa378  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa37a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa37d  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fa37f  e85c55feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa384  ebe1                   -jmp 0x4fa367
    goto L_0x004fa367;
L_0x004fa386:
    // 004fa386  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004fa38b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004fa38d:
    // 004fa38d  8b2d984d9f00           -mov ebp, dword ptr [0x9f4d98]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */);
    // 004fa393  39e9                   +cmp ecx, ebp
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
    // 004fa395  753e                   -jne 0x4fa3d5
    if (!cpu.flags.zf)
    {
        goto L_0x004fa3d5;
    }
    // 004fa397  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa399  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa39c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa39e  7535                   -jne 0x4fa3d5
    if (!cpu.flags.zf)
    {
        goto L_0x004fa3d5;
    }
    // 004fa3a0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa3a2  e88955feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004fa3a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa3a9  7421                   -je 0x4fa3cc
    if (cpu.flags.zf)
    {
        goto L_0x004fa3cc;
    }
    // 004fa3ab  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa3ad  e87ed2feff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004fa3b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa3b4  7c1f                   -jl 0x4fa3d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa3d5;
    }
L_0x004fa3b6:
    // 004fa3b6  8b2dd8435600           -mov ebp, dword ptr [0x5643d8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa3bc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fa3be  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa3c0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa3c3  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fa3c5  e81655feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa3ca  ebc1                   -jmp 0x4fa38d
    goto L_0x004fa38d;
L_0x004fa3cc:
    // 004fa3cc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa3ce  e80d55feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa3d3  ebe1                   -jmp 0x4fa3b6
    goto L_0x004fa3b6;
L_0x004fa3d5:
    // 004fa3d5  833d984d9f0000         +cmp dword ptr [0x9f4d98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa3dc  7540                   -jne 0x4fa41e
    if (!cpu.flags.zf)
    {
        goto L_0x004fa41e;
    }
L_0x004fa3de:
    // 004fa3de  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa3e0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa3e2  c7473400000000         -mov dword ptr [edi + 0x34], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa3e9  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004fa3ee  8b0d704d9f00           -mov ecx, dword ptr [0x9f4d70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440048) /* 0x9f4d70 */);
    // 004fa3f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa3f5  2eff1570475300         -call dword ptr cs:[0x534770]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457776) /* 0x534770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004fa3fc:
    // 004fa3fc  837f3400               +cmp dword ptr [edi + 0x34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa400  7413                   -je 0x4fa415
    if (cpu.flags.zf)
    {
        goto L_0x004fa415;
    }
    // 004fa402  833d9c4d9f0009         +cmp dword ptr [0x9f4d9c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa409  750a                   -jne 0x4fa415
    if (!cpu.flags.zf)
    {
        goto L_0x004fa415;
    }
    // 004fa40b  8b0da84d9f00           -mov ecx, dword ptr [0x9f4da8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */);
    // 004fa411  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fa413  7520                   -jne 0x4fa435
    if (!cpu.flags.zf)
    {
        goto L_0x004fa435;
    }
L_0x004fa415:
    // 004fa415  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa418  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa419  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa41e:
    // 004fa41e  833d9c4d9f0009         +cmp dword ptr [0x9f4d9c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa425  75b7                   -jne 0x4fa3de
    if (!cpu.flags.zf)
    {
        goto L_0x004fa3de;
    }
    // 004fa427  ebd3                   -jmp 0x4fa3fc
    goto L_0x004fa3fc;
L_0x004fa429:
    // 004fa429  c7059c4d9f0001000000   -mov dword ptr [0x9f4d9c], 1
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 1 /*0x1*/;
    // 004fa433  ebc7                   -jmp 0x4fa3fc
    goto L_0x004fa3fc;
L_0x004fa435:
    // 004fa435  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004fa43a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fa43c  e8af0e0200             -call 0x51b2f0
    cpu.esp -= 4;
    sub_51b2f0(app, cpu);
    if (cpu.terminate) return;
    // 004fa441  894738                 -mov dword ptr [edi + 0x38], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004fa444  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa447  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa448  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa449  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa44a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa44b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa44c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4fa450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa450  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa451  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa452  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa454  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa456  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004fa45b  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa462  8b15704d9f00           -mov edx, dword ptr [0x9f4d70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440048) /* 0x9f4d70 */);
    // 004fa468  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa469  2eff1570475300         -call dword ptr cs:[0x534770]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457776) /* 0x534770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa470  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa475  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa476  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa477  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa481  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa482  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa484  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa486  833d9c4d9f0009         +cmp dword ptr [0x9f4d9c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa48d  750f                   -jne 0x4fa49e
    if (!cpu.flags.zf)
    {
        goto L_0x004fa49e;
    }
    // 004fa48f  833dac71560000         +cmp dword ptr [0x5671ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665196) /* 0x5671ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa496  752a                   -jne 0x4fa4c2
    if (!cpu.flags.zf)
    {
        goto L_0x004fa4c2;
    }
L_0x004fa498:
    // 004fa498  8b4334                 -mov eax, dword ptr [ebx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 004fa49b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa49c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa49d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa49e:
    // 004fa49e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa49f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa4a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa4a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa4a4  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004fa4a9  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa4b0  8b3d704d9f00           -mov edi, dword ptr [0x9f4d70]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440048) /* 0x9f4d70 */);
    // 004fa4b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa4b7  2eff1570475300         -call dword ptr cs:[0x534770]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457776) /* 0x534770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa4be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4c0  ebd6                   -jmp 0x4fa498
    goto L_0x004fa498;
L_0x004fa4c2:
    // 004fa4c2  e829000000             -call 0x4fa4f0
    cpu.esp -= 4;
    sub_4fa4f0(app, cpu);
    if (cpu.terminate) return;
    // 004fa4c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa4c9  74cd                   -je 0x4fa498
    if (cpu.flags.zf)
    {
        goto L_0x004fa498;
    }
    // 004fa4cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa4cd  ff15ac715600           -call dword ptr [0x5671ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5665196) /* 0x5671ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa4d3  8b4334                 -mov eax, dword ptr [ebx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 004fa4d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fa4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa4e0  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa4e3  e918140200             -jmp 0x51b900
    return sub_51b900(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa4f0  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa4f3  e9a8130200             -jmp 0x51b8a0
    return sub_51b8a0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa501  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa503  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa505  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fa507  8b4938                 -mov ecx, dword ptr [ecx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004fa50a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa50c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa50e  e83d150200             -call 0x51ba50
    cpu.esp -= 4;
    sub_51ba50(app, cpu);
    if (cpu.terminate) return;
    // 004fa513  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa515  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa517  7c04                   -jl 0x4fa51d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa51d;
    }
    // 004fa519  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa51b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa51c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa51d:
    // 004fa51d  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004fa51f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa521  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa522  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fa530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa530  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa531  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa533  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa535  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fa537  8b4938                 -mov ecx, dword ptr [ecx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004fa53a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa53c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa53e  e8ed0f0200             -call 0x51b530
    cpu.esp -= 4;
    sub_51b530(app, cpu);
    if (cpu.terminate) return;
    // 004fa543  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa544  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fa550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa550  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa551  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa552  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa553  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa554  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa55a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa55c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fa55e  83fbff                 +cmp ebx, -1
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
    // 004fa561  0f857d000000           -jne 0x4fa5e4
    if (!cpu.flags.zf)
    {
        goto L_0x004fa5e4;
    }
    // 004fa567  bd10ac5600             -mov ebp, 0x56ac10
    cpu.ebp = 5680144 /*0x56ac10*/;
L_0x004fa56c:
    // 004fa56c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fa56e  7454                   -je 0x4fa5c4
    if (cpu.flags.zf)
    {
        goto L_0x004fa5c4;
    }
    // 004fa570  66837e2a00             +cmp word ptr [esi + 0x2a], 0
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
    // 004fa575  7513                   -jne 0x4fa58a
    if (!cpu.flags.zf)
    {
        goto L_0x004fa58a;
    }
    // 004fa577  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa579  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa57b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa57e  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004fa581  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa583  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004fa586  6689462a               -mov word ptr [esi + 0x2a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */) = cpu.ax;
L_0x004fa58a:
    // 004fa58a  66837e2c00             +cmp word ptr [esi + 0x2c], 0
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
    // 004fa58f  7513                   -jne 0x4fa5a4
    if (!cpu.flags.zf)
    {
        goto L_0x004fa5a4;
    }
    // 004fa591  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa593  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa595  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa598  c1e202                 +shl edx, 2
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
    // 004fa59b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa59d  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004fa5a0  6689462c               -mov word ptr [esi + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ax;
L_0x004fa5a4:
    // 004fa5a4  66837e2e00             +cmp word ptr [esi + 0x2e], 0
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
    // 004fa5a9  7513                   -jne 0x4fa5be
    if (!cpu.flags.zf)
    {
        goto L_0x004fa5be;
    }
    // 004fa5ab  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa5ad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa5af  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa5b2  c1e202                 +shl edx, 2
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
    // 004fa5b5  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa5b7  c1f802                 +sar eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004fa5ba  6689462e               -mov word ptr [esi + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */) = cpu.ax;
L_0x004fa5be:
    // 004fa5be  66c746280600           -mov word ptr [esi + 0x28], 6
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = 6 /*0x6*/;
L_0x004fa5c4:
    // 004fa5c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa5c5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fa5c7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa5c9  bbb0715600             -mov ebx, 0x5671b0
    cpu.ebx = 5665200 /*0x5671b0*/;
    // 004fa5ce  893dd8435600           -mov dword ptr [0x5643d8], edi
    app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */) = cpu.edi;
    // 004fa5d4  e857abffff             -call 0x4f5130
    cpu.esp -= 4;
    sub_4f5130(app, cpu);
    if (cpu.terminate) return;
    // 004fa5d9  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa5df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa5e4:
    // 004fa5e4  bd28ac5600             -mov ebp, 0x56ac28
    cpu.ebp = 5680168 /*0x56ac28*/;
    // 004fa5e9  eb81                   -jmp 0x4fa56c
    goto L_0x004fa56c;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4fa5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa5f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa5f1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa5f3  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa5fa  7417                   -je 0x4fa613
    if (cpu.flags.zf)
    {
        goto L_0x004fa613;
    }
L_0x004fa5fc:
    // 004fa5fc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fa5fe  7c1a                   -jl 0x4fa61a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa61a;
    }
    // 004fa600  3b15804d9f00           +cmp edx, dword ptr [0x9f4d80]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa606  7312                   -jae 0x4fa61a
    if (!cpu.flags.cf)
    {
        goto L_0x004fa61a;
    }
    // 004fa608  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004fa60d  8b44d004               -mov eax, dword ptr [eax + edx*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edx * 8);
    // 004fa611  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa612  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa613:
    // 004fa613  e8a8f4ffff             -call 0x4f9ac0
    cpu.esp -= 4;
    sub_4f9ac0(app, cpu);
    if (cpu.terminate) return;
    // 004fa618  ebe2                   -jmp 0x4fa5fc
    goto L_0x004fa5fc;
L_0x004fa61a:
    // 004fa61a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa61c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa61d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4fa620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa622  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa623  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa624  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa626  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fa628  8915ac4e9f00           -mov dword ptr [0x9f4eac], edx
    app->getMemory<x86::reg32>(x86::reg32(10440364) /* 0x9f4eac */) = cpu.edx;
    // 004fa62e  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa635  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa637  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa63a  891558445600           -mov dword ptr [0x564458], edx
    app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */) = cpu.edx;
    // 004fa640  e83b0e0200             -call 0x51b480
    cpu.esp -= 4;
    sub_51b480(app, cpu);
    if (cpu.terminate) return;
    // 004fa645  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa648  e8e3090200             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 004fa64d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa64f  7525                   -jne 0x4fa676
    if (!cpu.flags.zf)
    {
        goto L_0x004fa676;
    }
    // 004fa651  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa658  7c14                   -jl 0x4fa66e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa66e;
    }
    // 004fa65a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa65b  b8d8db5400             -mov eax, 0x54dbd8
    cpu.eax = 5561304 /*0x54dbd8*/;
    // 004fa660  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fa662  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004fa664  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fa666  8d5638                 -lea edx, [esi + 0x38]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa669  e8127b0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004fa66e:
    // 004fa66e  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa671  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa672  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa673  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa674  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa675  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa676:
    // 004fa676  8b5e4c                 -mov ebx, dword ptr [esi + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004fa679  8b4e48                 -mov ecx, dword ptr [esi + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004fa67c  8b5640                 -mov edx, dword ptr [esi + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 004fa67f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa680  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa683  8b5e44                 -mov ebx, dword ptr [esi + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004fa686  e885100200             -call 0x51b710
    cpu.esp -= 4;
    sub_51b710(app, cpu);
    if (cpu.terminate) return;
    // 004fa68b  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa68e  e82d0b0200             -call 0x51b1c0
    cpu.esp -= 4;
    sub_51b1c0(app, cpu);
    if (cpu.terminate) return;
    // 004fa693  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa696  e8450b0200             -call 0x51b1e0
    cpu.esp -= 4;
    sub_51b1e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa69b  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa69e  e88d020200             -call 0x51a930
    cpu.esp -= 4;
    sub_51a930(app, cpu);
    if (cpu.terminate) return;
    // 004fa6a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa6a5  750f                   -jne 0x4fa6b6
    if (!cpu.flags.zf)
    {
        goto L_0x004fa6b6;
    }
    // 004fa6a7  c7463401000000         -mov dword ptr [esi + 0x34], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = 1 /*0x1*/;
    // 004fa6ae  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa6b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa6b6:
    // 004fa6b6  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa6b9  e8420b0200             -call 0x51b200
    cpu.esp -= 4;
    sub_51b200(app, cpu);
    if (cpu.terminate) return;
    // 004fa6be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa6c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fa6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa6d0  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa6d7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa6dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4fa6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa6e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa6e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa6e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa6e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa6e5  8b1dac4e9f00           -mov ebx, dword ptr [0x9f4eac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440364) /* 0x9f4eac */);
    // 004fa6eb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa6ed  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fa6ef  7507                   -jne 0x4fa6f8
    if (!cpu.flags.zf)
    {
        goto L_0x004fa6f8;
    }
L_0x004fa6f1:
    // 004fa6f1  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 004fa6f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa6f8:
    // 004fa6f8  e823000000             -call 0x4fa720
    cpu.esp -= 4;
    sub_4fa720(app, cpu);
    if (cpu.terminate) return;
    // 004fa6fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa6ff  74f0                   -je 0x4fa6f1
    if (cpu.flags.zf)
    {
        goto L_0x004fa6f1;
    }
    // 004fa701  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa703  ff15ac4e9f00           -call dword ptr [0x9f4eac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10440364) /* 0x9f4eac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa709  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 004fa70c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa70d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa70e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa70f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fa710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa710  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa713  e9e8110200             -jmp 0x51b900
    return sub_51b900(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa720  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa723  e978110200             -jmp 0x51b8a0
    return sub_51b8a0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa731  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa733  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa735  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fa737  8b4938                 -mov ecx, dword ptr [ecx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004fa73a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa73c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa73e  e80d130200             -call 0x51ba50
    cpu.esp -= 4;
    sub_51ba50(app, cpu);
    if (cpu.terminate) return;
    // 004fa743  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa745  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa747  7c04                   -jl 0x4fa74d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa74d;
    }
    // 004fa749  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa74b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa74c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa74d:
    // 004fa74d  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004fa74f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa751  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa752  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fa760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa761  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa763  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa765  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fa767  8b4938                 -mov ecx, dword ptr [ecx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004fa76a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa76c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa76e  e8bd0d0200             -call 0x51b530
    cpu.esp -= 4;
    sub_51b530(app, cpu);
    if (cpu.terminate) return;
    // 004fa773  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa774  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fa780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa780  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa781  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa782  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa783  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa784  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fa787  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa78d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa78f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fa791  83fbff                 +cmp ebx, -1
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
    // 004fa794  0f8585000000           -jne 0x4fa81f
    if (!cpu.flags.zf)
    {
        goto L_0x004fa81f;
    }
    // 004fa79a  bd10ac5600             -mov ebp, 0x56ac10
    cpu.ebp = 5680144 /*0x56ac10*/;
L_0x004fa79f:
    // 004fa79f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fa7a1  7459                   -je 0x4fa7fc
    if (cpu.flags.zf)
    {
        goto L_0x004fa7fc;
    }
    // 004fa7a3  66837e2a00             +cmp word ptr [esi + 0x2a], 0
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
    // 004fa7a8  7513                   -jne 0x4fa7bd
    if (!cpu.flags.zf)
    {
        goto L_0x004fa7bd;
    }
    // 004fa7aa  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa7ac  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa7ae  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa7b1  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004fa7b4  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa7b6  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004fa7b9  6689462a               -mov word ptr [esi + 0x2a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */) = cpu.ax;
L_0x004fa7bd:
    // 004fa7bd  66837e2c00             +cmp word ptr [esi + 0x2c], 0
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
    // 004fa7c2  7515                   -jne 0x4fa7d9
    if (!cpu.flags.zf)
    {
        goto L_0x004fa7d9;
    }
    // 004fa7c4  c704240a000000         -mov dword ptr [esp], 0xa
    app->getMemory<x86::reg32>(cpu.esp) = 10 /*0xa*/;
    // 004fa7cb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa7cd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa7cf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa7d2  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fa7d5  6689462c               -mov word ptr [esi + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ax;
L_0x004fa7d9:
    // 004fa7d9  66837e2e00             +cmp word ptr [esi + 0x2e], 0
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
    // 004fa7de  7516                   -jne 0x4fa7f6
    if (!cpu.flags.zf)
    {
        goto L_0x004fa7f6;
    }
    // 004fa7e0  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004fa7e5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa7e7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004fa7ea  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa7ed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa7ef  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fa7f2  6689462e               -mov word ptr [esi + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */) = cpu.ax;
L_0x004fa7f6:
    // 004fa7f6  66c746280300           -mov word ptr [esi + 0x28], 3
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = 3 /*0x3*/;
L_0x004fa7fc:
    // 004fa7fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa7fd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fa7ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa801  bbd0715600             -mov ebx, 0x5671d0
    cpu.ebx = 5665232 /*0x5671d0*/;
    // 004fa806  893dd8435600           -mov dword ptr [0x5643d8], edi
    app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */) = cpu.edi;
    // 004fa80c  e81fa9ffff             -call 0x4f5130
    cpu.esp -= 4;
    sub_4f5130(app, cpu);
    if (cpu.terminate) return;
    // 004fa811  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa817  83c404                 +add esp, 4
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
    // 004fa81a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa81b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa81c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa81d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa81e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa81f:
    // 004fa81f  bd28ac5600             -mov ebp, 0x56ac28
    cpu.ebp = 5680168 /*0x56ac28*/;
    // 004fa824  e976ffffff             -jmp 0x4fa79f
    goto L_0x004fa79f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4fa830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa830  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa831  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa832  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa833  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fa836  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fa83a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004fa83d  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004fa841  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004fa846  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fa848  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004fa84a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004fa84e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa853  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004fa858  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004fa85a  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa85e  a3bc4e9f00             -mov dword ptr [0x9f4ebc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */) = cpu.eax;
    // 004fa863  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004fa865  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa869  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa86e  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fa870  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004fa872  a3c04e9f00             -mov dword ptr [0x9f4ec0], eax
    app->getMemory<x86::reg32>(x86::reg32(10440384) /* 0x9f4ec0 */) = cpu.eax;
    // 004fa877  a1bc4e9f00             -mov eax, dword ptr [0x9f4ebc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004fa87c  a3c84e9f00             -mov dword ptr [0x9f4ec8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */) = cpu.eax;
    // 004fa881  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004fa884  8b15bc4e9f00           -mov edx, dword ptr [0x9f4ebc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004fa88a  891db84e9f00           -mov dword ptr [0x9f4eb8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440376) /* 0x9f4eb8 */) = cpu.ebx;
    // 004fa890  a3cc4e9f00             -mov dword ptr [0x9f4ecc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */) = cpu.eax;
    // 004fa895  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fa899  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fa89d  e88e070000             -call 0x4fb030
    cpu.esp -= 4;
    sub_4fb030(app, cpu);
    if (cpu.terminate) return;
    // 004fa8a2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa8a4  8b1db84e9f00           -mov ebx, dword ptr [0x9f4eb8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440376) /* 0x9f4eb8 */);
    // 004fa8aa  8915b04e9f00           -mov dword ptr [0x9f4eb0], edx
    app->getMemory<x86::reg32>(x86::reg32(10440368) /* 0x9f4eb0 */) = cpu.edx;
    // 004fa8b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fa8b2  7e23                   -jle 0x4fa8d7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fa8d7;
    }
L_0x004fa8b4:
    // 004fa8b4  a1b04e9f00             -mov eax, dword ptr [0x9f4eb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440368) /* 0x9f4eb0 */);
    // 004fa8b9  80b8c450560000         +cmp byte ptr [eax + 0x5650c4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656772) /* 0x5650c4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fa8c0  7524                   -jne 0x4fa8e6
    if (!cpu.flags.zf)
    {
        goto L_0x004fa8e6;
    }
L_0x004fa8c2:
    // 004fa8c2  8b35b04e9f00           -mov esi, dword ptr [0x9f4eb0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440368) /* 0x9f4eb0 */);
    // 004fa8c8  46                     -inc esi
    (cpu.esi)++;
    // 004fa8c9  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fa8cd  8935b04e9f00           -mov dword ptr [0x9f4eb0], esi
    app->getMemory<x86::reg32>(x86::reg32(10440368) /* 0x9f4eb0 */) = cpu.esi;
    // 004fa8d3  39fe                   +cmp esi, edi
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
    // 004fa8d5  7cdd                   -jl 0x4fa8b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa8b4;
    }
L_0x004fa8d7:
    // 004fa8d7  891db84e9f00           -mov dword ptr [0x9f4eb8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440376) /* 0x9f4eb8 */) = cpu.ebx;
    // 004fa8dd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fa8e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa8e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa8e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa8e3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004fa8e6:
    // 004fa8e6  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004fa8e9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fa8ec  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa8ee  0fb67702               -movzx esi, byte ptr [edi + 2]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */));
    // 004fa8f2  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa8f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa8f8  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004fa8fa  0fb66f01               -movzx ebp, byte ptr [edi + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */));
    // 004fa8fe  a3f44e9f00             -mov dword ptr [0x9f4ef4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */) = cpu.eax;
    // 004fa903  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa905  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004fa907  0fb63f                 -movzx edi, byte ptr [edi]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 004fa90a  a3e44e9f00             -mov dword ptr [0x9f4ee4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440420) /* 0x9f4ee4 */) = cpu.eax;
    // 004fa90f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa911  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fa913  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004fa915  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa918  a3e84e9f00             -mov dword ptr [0x9f4ee8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */) = cpu.eax;
    // 004fa91d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa91f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa921  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004fa923  8b0df44e9f00           -mov ecx, dword ptr [0x9f4ef4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */);
    // 004fa929  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa92c  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004fa92f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004fa931  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa934  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa936  8b15e44e9f00           -mov edx, dword ptr [0x9f4ee4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440420) /* 0x9f4ee4 */);
    // 004fa93c  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa93f  890df84e9f00           -mov dword ptr [0x9f4ef8], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.ecx;
    // 004fa945  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004fa947  0fafeb                 -imul ebp, ebx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa94a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa94c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa94e  8b15e84e9f00           -mov edx, dword ptr [0x9f4ee8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */);
    // 004fa954  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa957  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fa959  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa95b  0faffb                 -imul edi, ebx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004fa95e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa960  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa962  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004fa965  8915f04e9f00           -mov dword ptr [0x9f4ef0], edx
    app->getMemory<x86::reg32>(x86::reg32(10440432) /* 0x9f4ef0 */) = cpu.edx;
    // 004fa96b  8b15f84e9f00           -mov edx, dword ptr [0x9f4ef8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */);
    // 004fa971  0fafd2                 -imul edx, edx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fa974  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa976  a1f04e9f00             -mov eax, dword ptr [0x9f4ef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440432) /* 0x9f4ef0 */);
    // 004fa97b  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004fa97e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa980  a1f44e9f00             -mov eax, dword ptr [0x9f4ef4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */);
    // 004fa985  8915f04e9f00           -mov dword ptr [0x9f4ef0], edx
    app->getMemory<x86::reg32>(x86::reg32(10440432) /* 0x9f4ef0 */) = cpu.edx;
    // 004fa98b  8b15c04e9f00           -mov edx, dword ptr [0x9f4ec0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440384) /* 0x9f4ec0 */);
    // 004fa991  40                     -inc eax
    (cpu.eax)++;
    // 004fa992  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fa995  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fa997  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa999  a3d04e9f00             -mov dword ptr [0x9f4ed0], eax
    app->getMemory<x86::reg32>(x86::reg32(10440400) /* 0x9f4ed0 */) = cpu.eax;
    // 004fa99e  a1e44e9f00             -mov eax, dword ptr [0x9f4ee4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440420) /* 0x9f4ee4 */);
    // 004fa9a3  40                     -inc eax
    (cpu.eax)++;
    // 004fa9a4  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fa9a7  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fa9a9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa9ab  a3d84e9f00             -mov dword ptr [0x9f4ed8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440408) /* 0x9f4ed8 */) = cpu.eax;
    // 004fa9b0  a1e84e9f00             -mov eax, dword ptr [0x9f4ee8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */);
    // 004fa9b5  40                     -inc eax
    (cpu.eax)++;
    // 004fa9b6  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fa9b9  8b35f44e9f00           -mov esi, dword ptr [0x9f4ef4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */);
    // 004fa9bf  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004fa9c1  0faf35cc4e9f00         -imul esi, dword ptr [0x9f4ecc]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */))));
    // 004fa9c8  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa9ca  a3d44e9f00             -mov dword ptr [0x9f4ed4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440404) /* 0x9f4ed4 */) = cpu.eax;
    // 004fa9cf  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fa9d3  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 004fa9da  8b15c84e9f00           -mov edx, dword ptr [0x9f4ec8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fa9e0  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fa9e2  a1e44e9f00             -mov eax, dword ptr [0x9f4ee4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440420) /* 0x9f4ee4 */);
    // 004fa9e7  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fa9ea  890d004f9f00           -mov dword ptr [0x9f4f00], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.ecx;
    // 004fa9f0  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004fa9f4  891db84e9f00           -mov dword ptr [0x9f4eb8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440376) /* 0x9f4eb8 */) = cpu.ebx;
    // 004fa9fa  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fa9fc  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 004faa03  8b15e84e9f00           -mov edx, dword ptr [0x9f4ee8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */);
    // 004faa09  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004faa0b  8b3de84e9f00           -mov edi, dword ptr [0x9f4ee8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */);
    // 004faa11  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004faa13  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004faa16  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004faa18  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004faa1a  8915b44e9f00           -mov dword ptr [0x9f4eb4], edx
    app->getMemory<x86::reg32>(x86::reg32(10440372) /* 0x9f4eb4 */) = cpu.edx;
    // 004faa20  892de04e9f00           -mov dword ptr [0x9f4ee0], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440416) /* 0x9f4ee0 */) = cpu.ebp;
    // 004faa26  e815000000             -call 0x4faa40
    cpu.esp -= 4;
    sub_4faa40(app, cpu);
    if (cpu.terminate) return;
    // 004faa2b  8b1db84e9f00           -mov ebx, dword ptr [0x9f4eb8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440376) /* 0x9f4eb8 */);
    // 004faa31  e98cfeffff             -jmp 0x4fa8c2
    goto L_0x004fa8c2;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4faa40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004faa40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004faa41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004faa42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004faa43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004faa44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004faa45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004faa46  a1f04e9f00             -mov eax, dword ptr [0x9f4ef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440432) /* 0x9f4ef0 */);
    // 004faa4b  8b1dc04e9f00           -mov ebx, dword ptr [0x9f4ec0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440384) /* 0x9f4ec0 */);
    // 004faa51  8b0df44e9f00           -mov ecx, dword ptr [0x9f4ef4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */);
    // 004faa57  8b35d04e9f00           -mov esi, dword ptr [0x9f4ed0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440400) /* 0x9f4ed0 */);
    // 004faa5d  8b3dbc4e9f00           -mov edi, dword ptr [0x9f4ebc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004faa63  a3f84e9f00             -mov dword ptr [0x9f4ef8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.eax;
    // 004faa68  a1e04e9f00             -mov eax, dword ptr [0x9f4ee0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440416) /* 0x9f4ee0 */);
    // 004faa6d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004faa6f  a3dc4e9f00             -mov dword ptr [0x9f4edc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.eax;
    // 004faa74  a1b44e9f00             -mov eax, dword ptr [0x9f4eb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440372) /* 0x9f4eb4 */);
    // 004faa79  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004faa7b  a3c44e9f00             -mov dword ptr [0x9f4ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.eax;
    // 004faa80  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004faa85  39f9                   +cmp ecx, edi
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
    // 004faa87  0f8cc0000000           -jl 0x4fab4d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fab4d;
    }
L_0x004faa8d:
    // 004faa8d  8b35d04e9f00           -mov esi, dword ptr [0x9f4ed0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440400) /* 0x9f4ed0 */);
    // 004faa93  a1f04e9f00             -mov eax, dword ptr [0x9f4ef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440432) /* 0x9f4ef0 */);
    // 004faa98  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004faa9a  8b3dcc4e9f00           -mov edi, dword ptr [0x9f4ecc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004faaa0  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004faaa2  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004faaa5  a3f84e9f00             -mov dword ptr [0x9f4ef8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.eax;
    // 004faaaa  a1e04e9f00             -mov eax, dword ptr [0x9f4ee0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440416) /* 0x9f4ee0 */);
    // 004faaaf  8b0df44e9f00           -mov ecx, dword ptr [0x9f4ef4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440436) /* 0x9f4ef4 */);
    // 004faab5  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004faab7  8b2dcc4e9f00           -mov ebp, dword ptr [0x9f4ecc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004faabd  a3dc4e9f00             -mov dword ptr [0x9f4edc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.eax;
    // 004faac2  a1b44e9f00             -mov eax, dword ptr [0x9f4eb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440372) /* 0x9f4eb4 */);
    // 004faac7  49                     -dec ecx
    (cpu.ecx)--;
    // 004faac8  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004faaca  8935044f9f00           -mov dword ptr [0x9f4f04], esi
    app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */) = cpu.esi;
    // 004faad0  a3c44e9f00             -mov dword ptr [0x9f4ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.eax;
    // 004faad5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004faada  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004faadc  7c60                   -jl 0x4fab3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fab3e;
    }
L_0x004faade:
    // 004faade  e8fd000000             -call 0x4fabe0
    cpu.esp -= 4;
    sub_4fabe0(app, cpu);
    if (cpu.terminate) return;
    // 004faae3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004faae5  0f84dd000000           -je 0x4fabc8
    if (cpu.flags.zf)
    {
        goto L_0x004fabc8;
    }
    // 004faaeb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004faaf0:
    // 004faaf0  a1cc4e9f00             -mov eax, dword ptr [0x9f4ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004faaf5  8b35dc4e9f00           -mov esi, dword ptr [0x9f4edc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */);
    // 004faafb  8b3dc44e9f00           -mov edi, dword ptr [0x9f4ec4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */);
    // 004fab01  8b2df84e9f00           -mov ebp, dword ptr [0x9f4ef8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */);
    // 004fab07  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fab0a  49                     -dec ecx
    (cpu.ecx)--;
    // 004fab0b  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fab0d  a1cc4e9f00             -mov eax, dword ptr [0x9f4ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004fab12  8935dc4e9f00           -mov dword ptr [0x9f4edc], esi
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.esi;
    // 004fab18  8b35044f9f00           -mov esi, dword ptr [0x9f4f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */);
    // 004fab1e  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fab20  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fab22  893dc44e9f00           -mov dword ptr [0x9f4ec4], edi
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.edi;
    // 004fab28  8935044f9f00           -mov dword ptr [0x9f4f04], esi
    app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */) = cpu.esi;
    // 004fab2e  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fab30  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fab32  892df84e9f00           -mov dword ptr [0x9f4ef8], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.ebp;
    // 004fab38  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004fab3a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fab3c  7da0                   -jge 0x4faade
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004faade;
    }
L_0x004fab3e:
    // 004fab3e  8b35044f9f00           -mov esi, dword ptr [0x9f4f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */);
    // 004fab44  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fab46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fab4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fab4d:
    // 004fab4d  8935044f9f00           -mov dword ptr [0x9f4f04], esi
    app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */) = cpu.esi;
L_0x004fab53:
    // 004fab53  e888000000             -call 0x4fabe0
    cpu.esp -= 4;
    sub_4fabe0(app, cpu);
    if (cpu.terminate) return;
    // 004fab58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fab5a  745c                   -je 0x4fabb8
    if (cpu.flags.zf)
    {
        goto L_0x004fabb8;
    }
    // 004fab5c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004fab61  8b35044f9f00           -mov esi, dword ptr [0x9f4f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */);
L_0x004fab67:
    // 004fab67  a1cc4e9f00             -mov eax, dword ptr [0x9f4ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004fab6c  8b2ddc4e9f00           -mov ebp, dword ptr [0x9f4edc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */);
    // 004fab72  8b3dc44e9f00           -mov edi, dword ptr [0x9f4ec4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */);
    // 004fab78  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fab7b  41                     -inc ecx
    (cpu.ecx)++;
    // 004fab7c  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fab7e  a1cc4e9f00             -mov eax, dword ptr [0x9f4ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440396) /* 0x9f4ecc */);
    // 004fab83  892ddc4e9f00           -mov dword ptr [0x9f4edc], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.ebp;
    // 004fab89  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fab8b  8b2df84e9f00           -mov ebp, dword ptr [0x9f4ef8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */);
    // 004fab91  893dc44e9f00           -mov dword ptr [0x9f4ec4], edi
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.edi;
    // 004fab97  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fab99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fab9b  8b3dbc4e9f00           -mov edi, dword ptr [0x9f4ebc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004faba1  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004faba3  892df84e9f00           -mov dword ptr [0x9f4ef8], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.ebp;
    // 004faba9  8935044f9f00           -mov dword ptr [0x9f4f04], esi
    app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */) = cpu.esi;
    // 004fabaf  39f9                   +cmp ecx, edi
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
    // 004fabb1  7ca0                   -jl 0x4fab53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fab53;
    }
    // 004fabb3  e9d5feffff             -jmp 0x4faa8d
    goto L_0x004faa8d;
L_0x004fabb8:
    // 004fabb8  8b35044f9f00           -mov esi, dword ptr [0x9f4f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440452) /* 0x9f4f04 */);
    // 004fabbe  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fabc0  0f85c7feffff           -jne 0x4faa8d
    if (!cpu.flags.zf)
    {
        goto L_0x004faa8d;
    }
    // 004fabc6  eb9f                   -jmp 0x4fab67
    goto L_0x004fab67;
L_0x004fabc8:
    // 004fabc8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fabca  0f856effffff           -jne 0x4fab3e
    if (!cpu.flags.zf)
    {
        goto L_0x004fab3e;
    }
    // 004fabd0  e91bffffff             -jmp 0x4faaf0
    goto L_0x004faaf0;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fabe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fabe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fabe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fabe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fabe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fabe4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fabe5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fabe6  8b35c04e9f00           -mov esi, dword ptr [0x9f4ec0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440384) /* 0x9f4ec0 */);
    // 004fabec  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fabee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fabf0  0f855d020000           -jne 0x4fae53
    if (!cpu.flags.zf)
    {
        goto L_0x004fae53;
    }
L_0x004fabf6:
    // 004fabf6  8b0d084f9f00           -mov ecx, dword ptr [0x9f4f08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */);
    // 004fabfc  a1f84e9f00             -mov eax, dword ptr [0x9f4ef8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */);
    // 004fac01  8b1d144f9f00           -mov ebx, dword ptr [0x9f4f14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440468) /* 0x9f4f14 */);
    // 004fac07  a3004f9f00             -mov dword ptr [0x9f4f00], eax
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.eax;
    // 004fac0c  a31c4f9f00             -mov dword ptr [0x9f4f1c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */) = cpu.eax;
    // 004fac11  a1dc4e9f00             -mov eax, dword ptr [0x9f4edc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */);
    // 004fac16  8b3d104f9f00           -mov edi, dword ptr [0x9f4f10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440464) /* 0x9f4f10 */);
    // 004fac1c  a3ec4e9f00             -mov dword ptr [0x9f4eec], eax
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.eax;
    // 004fac21  a3204f9f00             -mov dword ptr [0x9f4f20], eax
    app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */) = cpu.eax;
    // 004fac26  a1c44e9f00             -mov eax, dword ptr [0x9f4ec4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */);
    // 004fac2b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fac2d  a3fc4e9f00             -mov dword ptr [0x9f4efc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.eax;
    // 004fac32  a3244f9f00             -mov dword ptr [0x9f4f24], eax
    app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */) = cpu.eax;
    // 004fac37  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fac3c  39f9                   +cmp ecx, edi
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
    // 004fac3e  0f8fce000000           -jg 0x4fad12
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fad12;
    }
    // 004fac44  891d184f9f00           -mov dword ptr [0x9f4f18], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */) = cpu.ebx;
L_0x004fac4a:
    // 004fac4a  e851020000             -call 0x4faea0
    cpu.esp -= 4;
    sub_4faea0(app, cpu);
    if (cpu.terminate) return;
    // 004fac4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fac51  0f8428020000           -je 0x4fae7f
    if (cpu.flags.zf)
    {
        goto L_0x004fae7f;
    }
    // 004fac57  8b1d184f9f00           -mov ebx, dword ptr [0x9f4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */);
    // 004fac5d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fac5f  7537                   -jne 0x4fac98
    if (!cpu.flags.zf)
    {
        goto L_0x004fac98;
    }
    // 004fac61  3b0d084f9f00           +cmp ecx, dword ptr [0x9f4f08]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fac67  7e2a                   -jle 0x4fac93
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fac93;
    }
    // 004fac69  a1204f9f00             -mov eax, dword ptr [0x9f4f20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */);
    // 004fac6e  a3dc4e9f00             -mov dword ptr [0x9f4edc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.eax;
    // 004fac73  a1244f9f00             -mov eax, dword ptr [0x9f4f24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */);
    // 004fac78  891d144f9f00           -mov dword ptr [0x9f4f14], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440468) /* 0x9f4f14 */) = cpu.ebx;
    // 004fac7e  a3c44e9f00             -mov dword ptr [0x9f4ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.eax;
    // 004fac83  a11c4f9f00             -mov eax, dword ptr [0x9f4f1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */);
    // 004fac88  890d084f9f00           -mov dword ptr [0x9f4f08], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */) = cpu.ecx;
    // 004fac8e  a3f84e9f00             -mov dword ptr [0x9f4ef8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.eax;
L_0x004fac93:
    // 004fac93  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004fac98:
    // 004fac98  a1c84e9f00             -mov eax, dword ptr [0x9f4ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fac9d  8b2dec4e9f00           -mov ebp, dword ptr [0x9f4eec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */);
    // 004faca3  8b3d204f9f00           -mov edi, dword ptr [0x9f4f20]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */);
    // 004faca9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004facac  41                     -inc ecx
    (cpu.ecx)++;
    // 004facad  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004facaf  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004facb1  a1c84e9f00             -mov eax, dword ptr [0x9f4ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004facb6  892dec4e9f00           -mov dword ptr [0x9f4eec], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.ebp;
    // 004facbc  893d204f9f00           -mov dword ptr [0x9f4f20], edi
    app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */) = cpu.edi;
    // 004facc2  8b2dfc4e9f00           -mov ebp, dword ptr [0x9f4efc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */);
    // 004facc8  8b3d244f9f00           -mov edi, dword ptr [0x9f4f24]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */);
    // 004facce  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004facd0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004facd2  892dfc4e9f00           -mov dword ptr [0x9f4efc], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.ebp;
    // 004facd8  893d244f9f00           -mov dword ptr [0x9f4f24], edi
    app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */) = cpu.edi;
    // 004facde  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004face0  8b2d004f9f00           -mov ebp, dword ptr [0x9f4f00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */);
    // 004face6  8b3d1c4f9f00           -mov edi, dword ptr [0x9f4f1c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */);
    // 004facec  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004facee  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004facf0  892d004f9f00           -mov dword ptr [0x9f4f00], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.ebp;
    // 004facf6  893d1c4f9f00           -mov dword ptr [0x9f4f1c], edi
    app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */) = cpu.edi;
    // 004facfc  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004facfe  8b2d104f9f00           -mov ebp, dword ptr [0x9f4f10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440464) /* 0x9f4f10 */);
    // 004fad04  891d184f9f00           -mov dword ptr [0x9f4f18], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */) = cpu.ebx;
    // 004fad0a  39e9                   +cmp ecx, ebp
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
    // 004fad0c  0f8e38ffffff           -jle 0x4fac4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fac4a;
    }
L_0x004fad12:
    // 004fad12  8b1d144f9f00           -mov ebx, dword ptr [0x9f4f14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440468) /* 0x9f4f14 */);
    // 004fad18  a1f84e9f00             -mov eax, dword ptr [0x9f4ef8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */);
    // 004fad1d  8b3dc84e9f00           -mov edi, dword ptr [0x9f4ec8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fad23  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fad25  8b0d084f9f00           -mov ecx, dword ptr [0x9f4f08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */);
    // 004fad2b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fad2d  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004fad30  a3004f9f00             -mov dword ptr [0x9f4f00], eax
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.eax;
    // 004fad35  a31c4f9f00             -mov dword ptr [0x9f4f1c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */) = cpu.eax;
    // 004fad3a  a1dc4e9f00             -mov eax, dword ptr [0x9f4edc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */);
    // 004fad3f  8b2d0c4f9f00           -mov ebp, dword ptr [0x9f4f0c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440460) /* 0x9f4f0c */);
    // 004fad45  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004fad47  8b3dc84e9f00           -mov edi, dword ptr [0x9f4ec8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fad4d  a3ec4e9f00             -mov dword ptr [0x9f4eec], eax
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.eax;
    // 004fad52  a3204f9f00             -mov dword ptr [0x9f4f20], eax
    app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */) = cpu.eax;
    // 004fad57  a1c44e9f00             -mov eax, dword ptr [0x9f4ec4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */);
    // 004fad5c  49                     -dec ecx
    (cpu.ecx)--;
    // 004fad5d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004fad5f  891d184f9f00           -mov dword ptr [0x9f4f18], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */) = cpu.ebx;
    // 004fad65  a3fc4e9f00             -mov dword ptr [0x9f4efc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.eax;
    // 004fad6a  a3244f9f00             -mov dword ptr [0x9f4f24], eax
    app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */) = cpu.eax;
    // 004fad6f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fad74  39e9                   +cmp ecx, ebp
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
    // 004fad76  0f8cc8000000           -jl 0x4fae44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fae44;
    }
L_0x004fad7c:
    // 004fad7c  e81f010000             -call 0x4faea0
    cpu.esp -= 4;
    sub_4faea0(app, cpu);
    if (cpu.terminate) return;
    // 004fad81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fad83  0f8409010000           -je 0x4fae92
    if (cpu.flags.zf)
    {
        goto L_0x004fae92;
    }
    // 004fad89  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fad8b  7535                   -jne 0x4fadc2
    if (!cpu.flags.zf)
    {
        goto L_0x004fadc2;
    }
    // 004fad8d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004fad92  a1204f9f00             -mov eax, dword ptr [0x9f4f20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */);
    // 004fad97  8b1d184f9f00           -mov ebx, dword ptr [0x9f4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */);
    // 004fad9d  a3dc4e9f00             -mov dword ptr [0x9f4edc], eax
    app->getMemory<x86::reg32>(x86::reg32(10440412) /* 0x9f4edc */) = cpu.eax;
    // 004fada2  a1244f9f00             -mov eax, dword ptr [0x9f4f24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */);
    // 004fada7  890d084f9f00           -mov dword ptr [0x9f4f08], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */) = cpu.ecx;
    // 004fadad  a3c44e9f00             -mov dword ptr [0x9f4ec4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440388) /* 0x9f4ec4 */) = cpu.eax;
    // 004fadb2  a11c4f9f00             -mov eax, dword ptr [0x9f4f1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */);
    // 004fadb7  891d144f9f00           -mov dword ptr [0x9f4f14], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440468) /* 0x9f4f14 */) = cpu.ebx;
    // 004fadbd  a3f84e9f00             -mov dword ptr [0x9f4ef8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440440) /* 0x9f4ef8 */) = cpu.eax;
L_0x004fadc2:
    // 004fadc2  a1c84e9f00             -mov eax, dword ptr [0x9f4ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fadc7  8b1dec4e9f00           -mov ebx, dword ptr [0x9f4eec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */);
    // 004fadcd  8b3d204f9f00           -mov edi, dword ptr [0x9f4f20]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */);
    // 004fadd3  8b2dfc4e9f00           -mov ebp, dword ptr [0x9f4efc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */);
    // 004fadd9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004faddc  49                     -dec ecx
    (cpu.ecx)--;
    // 004faddd  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004faddf  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fade1  a1c84e9f00             -mov eax, dword ptr [0x9f4ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440392) /* 0x9f4ec8 */);
    // 004fade6  891dec4e9f00           -mov dword ptr [0x9f4eec], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.ebx;
    // 004fadec  893d204f9f00           -mov dword ptr [0x9f4f20], edi
    app->getMemory<x86::reg32>(x86::reg32(10440480) /* 0x9f4f20 */) = cpu.edi;
    // 004fadf2  8b1d244f9f00           -mov ebx, dword ptr [0x9f4f24]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */);
    // 004fadf8  8b3d004f9f00           -mov edi, dword ptr [0x9f4f00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */);
    // 004fadfe  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fae00  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fae02  891d244f9f00           -mov dword ptr [0x9f4f24], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440484) /* 0x9f4f24 */) = cpu.ebx;
    // 004fae08  8b1d184f9f00           -mov ebx, dword ptr [0x9f4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */);
    // 004fae0e  892dfc4e9f00           -mov dword ptr [0x9f4efc], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.ebp;
    // 004fae14  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fae16  8b2d1c4f9f00           -mov ebp, dword ptr [0x9f4f1c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */);
    // 004fae1c  891d184f9f00           -mov dword ptr [0x9f4f18], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */) = cpu.ebx;
    // 004fae22  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fae24  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fae26  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fae28  893d004f9f00           -mov dword ptr [0x9f4f00], edi
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.edi;
    // 004fae2e  892d1c4f9f00           -mov dword ptr [0x9f4f1c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440476) /* 0x9f4f1c */) = cpu.ebp;
    // 004fae34  8b3d0c4f9f00           -mov edi, dword ptr [0x9f4f0c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440460) /* 0x9f4f0c */);
    // 004fae3a  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fae3c  39f9                   +cmp ecx, edi
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
    // 004fae3e  0f8d38ffffff           -jge 0x4fad7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fad7c;
    }
L_0x004fae44:
    // 004fae44  8b1d184f9f00           -mov ebx, dword ptr [0x9f4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */);
    // 004fae4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fae4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae4f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae51  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fae52  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fae53:
    // 004fae53  a1e44e9f00             -mov eax, dword ptr [0x9f4ee4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440420) /* 0x9f4ee4 */);
    // 004fae58  a3084f9f00             -mov dword ptr [0x9f4f08], eax
    app->getMemory<x86::reg32>(x86::reg32(10440456) /* 0x9f4f08 */) = cpu.eax;
    // 004fae5d  a1bc4e9f00             -mov eax, dword ptr [0x9f4ebc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004fae62  48                     -dec eax
    (cpu.eax)--;
    // 004fae63  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004fae65  a3104f9f00             -mov dword ptr [0x9f4f10], eax
    app->getMemory<x86::reg32>(x86::reg32(10440464) /* 0x9f4f10 */) = cpu.eax;
    // 004fae6a  a1d84e9f00             -mov eax, dword ptr [0x9f4ed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440408) /* 0x9f4ed8 */);
    // 004fae6f  890d0c4f9f00           -mov dword ptr [0x9f4f0c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440460) /* 0x9f4f0c */) = cpu.ecx;
    // 004fae75  a3144f9f00             -mov dword ptr [0x9f4f14], eax
    app->getMemory<x86::reg32>(x86::reg32(10440468) /* 0x9f4f14 */) = cpu.eax;
    // 004fae7a  e977fdffff             -jmp 0x4fabf6
    goto L_0x004fabf6;
L_0x004fae7f:
    // 004fae7f  8b1d184f9f00           -mov ebx, dword ptr [0x9f4f18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440472) /* 0x9f4f18 */);
    // 004fae85  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fae87  0f8585feffff           -jne 0x4fad12
    if (!cpu.flags.zf)
    {
        goto L_0x004fad12;
    }
    // 004fae8d  e906feffff             -jmp 0x4fac98
    goto L_0x004fac98;
L_0x004fae92:
    // 004fae92  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fae94  75ae                   -jne 0x4fae44
    if (!cpu.flags.zf)
    {
        goto L_0x004fae44;
    }
    // 004fae96  e927ffffff             -jmp 0x4fadc2
    goto L_0x004fadc2;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4faea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004faea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004faea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004faea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004faea3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004faea4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004faea5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004faea6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004faea9  8b15b04e9f00           -mov edx, dword ptr [0x9f4eb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440368) /* 0x9f4eb0 */);
    // 004faeaf  8b2dc04e9f00           -mov ebp, dword ptr [0x9f4ec0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440384) /* 0x9f4ec0 */);
    // 004faeb5  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004faeb9  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004faebb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004faebd  0f8582000000           -jne 0x4faf45
    if (!cpu.flags.zf)
    {
        goto L_0x004faf45;
    }
L_0x004faec3:
    // 004faec3  8b0d284f9f00           -mov ecx, dword ptr [0x9f4f28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */);
    // 004faec9  8b15004f9f00           -mov edx, dword ptr [0x9f4f00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */);
    // 004faecf  8b35344f9f00           -mov esi, dword ptr [0x9f4f34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440500) /* 0x9f4f34 */);
    // 004faed5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004faed7  a1ec4e9f00             -mov eax, dword ptr [0x9f4eec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */);
    // 004faedc  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004faedf  8b1d304f9f00           -mov ebx, dword ptr [0x9f4f30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440496) /* 0x9f4f30 */);
    // 004faee5  8b3dfc4e9f00           -mov edi, dword ptr [0x9f4efc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */);
    // 004faeeb  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004faeef  39d9                   +cmp ecx, ebx
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
    // 004faef1  7f34                   -jg 0x4faf27
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004faf27;
    }
L_0x004faef3:
    // 004faef3  3b10                   +cmp edx, dword ptr [eax]
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
    // 004faef5  0f8376000000           -jae 0x4faf71
    if (!cpu.flags.cf)
    {
        goto L_0x004faf71;
    }
    // 004faefb  3b0d284f9f00           +cmp ecx, dword ptr [0x9f4f28]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004faf01  7e1d                   -jle 0x4faf20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004faf20;
    }
    // 004faf03  a3ec4e9f00             -mov dword ptr [0x9f4eec], eax
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.eax;
    // 004faf08  893dfc4e9f00           -mov dword ptr [0x9f4efc], edi
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.edi;
    // 004faf0e  8915004f9f00           -mov dword ptr [0x9f4f00], edx
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.edx;
    // 004faf14  8935344f9f00           -mov dword ptr [0x9f4f34], esi
    app->getMemory<x86::reg32>(x86::reg32(10440500) /* 0x9f4f34 */) = cpu.esi;
    // 004faf1a  890d284f9f00           -mov dword ptr [0x9f4f28], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */) = cpu.ecx;
L_0x004faf20:
    // 004faf20  c7042401000000         -mov dword ptr [esp], 1
    app->getMemory<x86::reg32>(cpu.esp) = 1 /*0x1*/;
L_0x004faf27:
    // 004faf27  3b4c240c               +cmp ecx, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004faf2b  7f5b                   -jg 0x4faf88
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004faf88;
    }
    // 004faf2d  3b10                   +cmp edx, dword ptr [eax]
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
    // 004faf2f  7357                   -jae 0x4faf88
    if (!cpu.flags.cf)
    {
        goto L_0x004faf88;
    }
    // 004faf31  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004faf35  41                     -inc ecx
    (cpu.ecx)++;
    // 004faf36  47                     -inc edi
    (cpu.edi)++;
    // 004faf37  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004faf39  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004faf3c  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004faf3e  885fff                 -mov byte ptr [edi - 1], bl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 004faf41  01ee                   +add esi, ebp
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004faf43  ebe2                   -jmp 0x4faf27
    goto L_0x004faf27;
L_0x004faf45:
    // 004faf45  a1e84e9f00             -mov eax, dword ptr [0x9f4ee8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440424) /* 0x9f4ee8 */);
    // 004faf4a  a3284f9f00             -mov dword ptr [0x9f4f28], eax
    app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */) = cpu.eax;
    // 004faf4f  a1bc4e9f00             -mov eax, dword ptr [0x9f4ebc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440380) /* 0x9f4ebc */);
    // 004faf54  48                     -dec eax
    (cpu.eax)--;
    // 004faf55  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004faf57  a3304f9f00             -mov dword ptr [0x9f4f30], eax
    app->getMemory<x86::reg32>(x86::reg32(10440496) /* 0x9f4f30 */) = cpu.eax;
    // 004faf5c  a1d44e9f00             -mov eax, dword ptr [0x9f4ed4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440404) /* 0x9f4ed4 */);
    // 004faf61  890d2c4f9f00           -mov dword ptr [0x9f4f2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440492) /* 0x9f4f2c */) = cpu.ecx;
    // 004faf67  a3344f9f00             -mov dword ptr [0x9f4f34], eax
    app->getMemory<x86::reg32>(x86::reg32(10440500) /* 0x9f4f34 */) = cpu.eax;
    // 004faf6c  e952ffffff             -jmp 0x4faec3
    goto L_0x004faec3;
L_0x004faf71:
    // 004faf71  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004faf75  41                     -inc ecx
    (cpu.ecx)++;
    // 004faf76  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004faf79  47                     -inc edi
    (cpu.edi)++;
    // 004faf7a  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004faf7c  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004faf7e  39d9                   +cmp ecx, ebx
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
    // 004faf80  0f8e6dffffff           -jle 0x4faef3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004faef3;
    }
    // 004faf86  eb9f                   -jmp 0x4faf27
    goto L_0x004faf27;
L_0x004faf88:
    // 004faf88  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004faf8b  a12c4f9f00             -mov eax, dword ptr [0x9f4f2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440492) /* 0x9f4f2c */);
    // 004faf90  8b35284f9f00           -mov esi, dword ptr [0x9f4f28]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */);
    // 004faf96  8b0d344f9f00           -mov ecx, dword ptr [0x9f4f34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440500) /* 0x9f4f34 */);
    // 004faf9c  8b15ec4e9f00           -mov edx, dword ptr [0x9f4eec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */);
    // 004fafa2  8b3dfc4e9f00           -mov edi, dword ptr [0x9f4efc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */);
    // 004fafa8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fafac  4e                     -dec esi
    (cpu.esi)--;
    // 004fafad  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fafb0  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fafb2  a1004f9f00             -mov eax, dword ptr [0x9f4f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */);
    // 004fafb7  4f                     -dec edi
    (cpu.edi)--;
    // 004fafb8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fafba  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fafbc  7506                   -jne 0x4fafc4
    if (!cpu.flags.zf)
    {
        goto L_0x004fafc4;
    }
L_0x004fafbe:
    // 004fafbe  3b742408               +cmp esi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fafc2  7d1e                   -jge 0x4fafe2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fafe2;
    }
L_0x004fafc4:
    // 004fafc4  3b742408               +cmp esi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fafc8  7c4e                   -jl 0x4fb018
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fb018;
    }
    // 004fafca  3b02                   +cmp eax, dword ptr [edx]
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
    // 004fafcc  734a                   -jae 0x4fb018
    if (!cpu.flags.cf)
    {
        goto L_0x004fb018;
    }
    // 004fafce  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fafd2  4e                     -dec esi
    (cpu.esi)--;
    // 004fafd3  4f                     -dec edi
    (cpu.edi)--;
    // 004fafd4  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fafd6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fafd8  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fafdb  29c8                   +sub eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004fafdd  885f01                 -mov byte ptr [edi + 1], bl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004fafe0  ebe2                   -jmp 0x4fafc4
    goto L_0x004fafc4;
L_0x004fafe2:
    // 004fafe2  3b02                   +cmp eax, dword ptr [edx]
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
    // 004fafe4  720b                   -jb 0x4faff1
    if (cpu.flags.cf)
    {
        goto L_0x004faff1;
    }
    // 004fafe6  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fafe9  4f                     -dec edi
    (cpu.edi)--;
    // 004fafea  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fafec  4e                     -dec esi
    (cpu.esi)--;
    // 004fafed  29c8                   +sub eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004fafef  ebcd                   -jmp 0x4fafbe
    goto L_0x004fafbe;
L_0x004faff1:
    // 004faff1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004faff6  8915ec4e9f00           -mov dword ptr [0x9f4eec], edx
    app->getMemory<x86::reg32>(x86::reg32(10440428) /* 0x9f4eec */) = cpu.edx;
    // 004faffc  893dfc4e9f00           -mov dword ptr [0x9f4efc], edi
    app->getMemory<x86::reg32>(x86::reg32(10440444) /* 0x9f4efc */) = cpu.edi;
    // 004fb002  a3004f9f00             -mov dword ptr [0x9f4f00], eax
    app->getMemory<x86::reg32>(x86::reg32(10440448) /* 0x9f4f00 */) = cpu.eax;
    // 004fb007  890d344f9f00           -mov dword ptr [0x9f4f34], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440500) /* 0x9f4f34 */) = cpu.ecx;
    // 004fb00d  8935284f9f00           -mov dword ptr [0x9f4f28], esi
    app->getMemory<x86::reg32>(x86::reg32(10440488) /* 0x9f4f28 */) = cpu.esi;
    // 004fb013  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004fb016  ebac                   -jmp 0x4fafc4
    goto L_0x004fafc4;
L_0x004fb018:
    // 004fb018  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004fb01b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fb01e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb01f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb020  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb021  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb022  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb023  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb024  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fb030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb031  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fb033  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fb035  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fb038  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fb03b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fb03d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb03f  7e0f                   -jle 0x4fb050
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb050;
    }
L_0x004fb041:
    // 004fb041  48                     -dec eax
    (cpu.eax)--;
    // 004fb042  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 004fb048  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb04b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb04d  7ff2                   -jg 0x4fb041
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fb041;
    }
    // 004fb04f  90                     -nop 
    ;
L_0x004fb050:
    // 004fb050  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb051  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4fb060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb060  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb061  8b15c0505600           -mov edx, dword ptr [0x5650c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */);
    // 004fb067  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fb069  7502                   -jne 0x4fb06d
    if (!cpu.flags.zf)
    {
        goto L_0x004fb06d;
    }
    // 004fb06b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb06c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb06d:
    // 004fb06d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb06e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fb070  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb072  e81968feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fb077  890dc0505600           -mov dword ptr [0x5650c0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */) = cpu.ecx;
    // 004fb07d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb07e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb07f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb082  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb083  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb084  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb085  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb086  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fb088  baecdb5400             -mov edx, 0x54dbec
    cpu.edx = 5561324 /*0x54dbec*/;
    // 004fb08d  b9fcdb5400             -mov ecx, 0x54dbfc
    cpu.ecx = 5561340 /*0x54dbfc*/;
    // 004fb092  bb73000000             -mov ebx, 0x73
    cpu.ebx = 115 /*0x73*/;
    // 004fb097  b80cdc5400             -mov eax, 0x54dc0c
    cpu.eax = 5561356 /*0x54dc0c*/;
    // 004fb09c  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004fb0a2  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004fb0a8  ba00800000             -mov edx, 0x8000
    cpu.edx = 32768 /*0x8000*/;
    // 004fb0ad  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fb0b3  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004fb0b9  e86265feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fb0be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fb0c0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fb0c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb0c4  7509                   -jne 0x4fb0cf
    if (!cpu.flags.zf)
    {
        goto L_0x004fb0cf;
    }
    // 004fb0c6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fb0c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb0ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb0cf:
    // 004fb0cf  beecdb5400             -mov esi, 0x54dbec
    cpu.esi = 5561324 /*0x54dbec*/;
    // 004fb0d4  b8fcdb5400             -mov eax, 0x54dbfc
    cpu.eax = 5561340 /*0x54dbfc*/;
    // 004fb0d9  ba77000000             -mov edx, 0x77
    cpu.edx = 119 /*0x77*/;
    // 004fb0de  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fb0e4  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004fb0e9  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004fb0ef  ba00000200             -mov edx, 0x20000
    cpu.edx = 131072 /*0x20000*/;
    // 004fb0f4  b818dc5400             -mov eax, 0x54dc18
    cpu.eax = 5561368 /*0x54dc18*/;
    // 004fb0f9  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004fb0ff  e81c65feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fb104  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb106  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb108  750b                   -jne 0x4fb115
    if (!cpu.flags.zf)
    {
        goto L_0x004fb115;
    }
    // 004fb10a  31cf                   -xor edi, ecx
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb10c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fb10e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb10f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb110  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb111  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb112  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb113  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb114  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb115:
    // 004fb115  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 004fb11a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb11b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb11d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fb11f  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004fb124  e807f7ffff             -call 0x4fa830
    cpu.esp -= 4;
    sub_4fa830(app, cpu);
    if (cpu.terminate) return;
    // 004fb129  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fb12b  e86067feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fb130  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fb132  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb133  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb134  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb135  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb136  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb137  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb138  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fb140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb141  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb142  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb148  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fb14a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fb14c  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004fb151  e80a2d0200             -call 0x51de60
    cpu.esp -= 4;
    sub_51de60(app, cpu);
    if (cpu.terminate) return;
    // 004fb156  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fb158  e823ffffff             -call 0x4fb080
    cpu.esp -= 4;
    sub_4fb080(app, cpu);
    if (cpu.terminate) return;
    // 004fb15d  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb163  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb164  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb165  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4fb170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb171  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb172  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb178  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fb17a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fb17c  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004fb181  e8da2d0200             -call 0x51df60
    cpu.esp -= 4;
    sub_51df60(app, cpu);
    if (cpu.terminate) return;
    // 004fb186  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fb188  e8f3feffff             -call 0x4fb080
    cpu.esp -= 4;
    sub_4fb080(app, cpu);
    if (cpu.terminate) return;
    // 004fb18d  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb193  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb194  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb195  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4fb1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb1a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb1a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb1a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb1a3  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb1a9  e8b2feffff             -call 0x4fb060
    cpu.esp -= 4;
    sub_4fb060(app, cpu);
    if (cpu.terminate) return;
    // 004fb1ae  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fb1b0  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004fb1b5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb1b7  e8548d0000             -call 0x503f10
    cpu.esp -= 4;
    sub_503f10(app, cpu);
    if (cpu.terminate) return;
    // 004fb1bc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fb1be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb1c0  e8bbfeffff             -call 0x4fb080
    cpu.esp -= 4;
    sub_4fb080(app, cpu);
    if (cpu.terminate) return;
    // 004fb1c5  a3c0505600             -mov dword ptr [0x5650c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */) = cpu.eax;
    // 004fb1ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb1cc  7405                   -je 0x4fb1d3
    if (cpu.flags.zf)
    {
        goto L_0x004fb1d3;
    }
    // 004fb1ce  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004fb1d3:
    // 004fb1d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fb1d5  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004fb1db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb1dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb1dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb1de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4fb1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb1e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb1e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb1e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb1e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb1e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb1e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fb1e7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fb1e9  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fb1f0  0f849c000000           -je 0x4fb292
    if (cpu.flags.zf)
    {
        goto L_0x004fb292;
    }
    // 004fb1f6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fb1f8  0f8c9b000000           -jl 0x4fb299
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fb299;
    }
    // 004fb1fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fb200:
    // 004fb200  e86b730000             -call 0x502570
    cpu.esp -= 4;
    sub_502570(app, cpu);
    if (cpu.terminate) return;
    // 004fb205  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb207  0f8596000000           -jne 0x4fb2a3
    if (!cpu.flags.zf)
    {
        goto L_0x004fb2a3;
    }
    // 004fb20d  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004fb214  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fb216  8b14853ca1a000         -mov edx, dword ptr [eax*4 + 0xa0a13c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10527036) /* 0xa0a13c */ + cpu.eax * 4);
    // 004fb21d  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fb21f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fb221  0f8c83000000           -jl 0x4fb2aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fb2aa;
    }
L_0x004fb227:
    // 004fb227  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb229  668b4206               -mov ax, word ptr [edx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004fb22d  39c1                   +cmp ecx, eax
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
    // 004fb22f  0f8da9000000           -jge 0x4fb2de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb2de;
    }
    // 004fb235  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004fb238  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fb23a  7437                   -je 0x4fb273
    if (cpu.flags.zf)
    {
        goto L_0x004fb273;
    }
    // 004fb23c  3c04                   +cmp al, 4
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fb23e  7433                   -je 0x4fb273
    if (cpu.flags.zf)
    {
        goto L_0x004fb273;
    }
    // 004fb240  c7059021550024dc5400   -mov dword ptr [0x552190], 0x54dc24
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5561380 /*0x54dc24*/;
    // 004fb24a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb24c  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004fb24f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb250  be34dc5400             -mov esi, 0x54dc34
    cpu.esi = 5561396 /*0x54dc34*/;
    // 004fb255  bf47000000             -mov edi, 0x47
    cpu.edi = 71 /*0x47*/;
    // 004fb25a  6878dc5400             -push 0x54dc78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561464 /*0x54dc78*/;
    cpu.esp -= 4;
    // 004fb25f  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004fb265  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004fb26b  e8a05df0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fb270  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004fb273:
    // 004fb273  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004fb27a  807a0404               +cmp byte ptr [edx + 4], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fb27e  7562                   -jne 0x4fb2e2
    if (!cpu.flags.zf)
    {
        goto L_0x004fb2e2;
    }
    // 004fb280  837c031400             +cmp dword ptr [ebx + eax + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */ + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb285  7457                   -je 0x4fb2de
    if (cpu.flags.zf)
    {
        goto L_0x004fb2de;
    }
    // 004fb287  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fb28c:
    // 004fb28c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb28d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb28e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb28f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb290  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb291  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb292:
    // 004fb292  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004fb297  ebf3                   -jmp 0x4fb28c
    goto L_0x004fb28c;
L_0x004fb299:
    // 004fb299  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fb29e  e95dffffff             -jmp 0x4fb200
    goto L_0x004fb200;
L_0x004fb2a3:
    // 004fb2a3  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004fb2a8  ebe2                   -jmp 0x4fb28c
    goto L_0x004fb28c;
L_0x004fb2aa:
    // 004fb2aa  be24dc5400             -mov esi, 0x54dc24
    cpu.esi = 5561380 /*0x54dc24*/;
    // 004fb2af  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb2b0  bf34dc5400             -mov edi, 0x54dc34
    cpu.edi = 5561396 /*0x54dc34*/;
    // 004fb2b5  bd3b000000             -mov ebp, 0x3b
    cpu.ebp = 59 /*0x3b*/;
    // 004fb2ba  6848dc5400             -push 0x54dc48
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561416 /*0x54dc48*/;
    cpu.esp -= 4;
    // 004fb2bf  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004fb2c5  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004fb2cb  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004fb2d1  e83a5df0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004fb2d6  83c408                 +add esp, 8
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
    // 004fb2d9  e949ffffff             -jmp 0x4fb227
    goto L_0x004fb227;
L_0x004fb2de:
    // 004fb2de  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fb2e0  ebaa                   -jmp 0x4fb28c
    goto L_0x004fb28c;
L_0x004fb2e2:
    // 004fb2e2  837c020c00             +cmp dword ptr [edx + eax + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb2e7  74f5                   -je 0x4fb2de
    if (cpu.flags.zf)
    {
        goto L_0x004fb2de;
    }
    // 004fb2e9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fb2ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb2ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb2f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb2f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb2f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb2f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4fb300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb300  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb301  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb302  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004fb303  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004fb305  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004fb307  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb308  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb30b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fb30d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004fb30f  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004fb313  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004fb316  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fb318  744c                   -je 0x4fb366
    if (cpu.flags.zf)
    {
        goto L_0x004fb366;
    }
    // 004fb31a  4b                     -dec ebx
    (cpu.ebx)--;
    // 004fb31b  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004fb31e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fb320  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004fb323  39f2                   +cmp edx, esi
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
    // 004fb325  732c                   -jae 0x4fb353
    if (!cpu.flags.cf)
    {
        goto L_0x004fb353;
    }
L_0x004fb327:
    // 004fb327  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fb329  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fb32b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb32d  f7f7                   -div edi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.edi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004fb32f  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004fb331  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004fb334  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004fb337  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fb339  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fb33b  ff1424                 -call dword ptr [esp]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb33e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb340  7504                   -jne 0x4fb346
    if (!cpu.flags.zf)
    {
        goto L_0x004fb346;
    }
    // 004fb342  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fb344  eb22                   -jmp 0x4fb368
    goto L_0x004fb368;
L_0x004fb346:
    // 004fb346  7d04                   -jge 0x4fb34c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb34c;
    }
    // 004fb348  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004fb34a  eb03                   -jmp 0x4fb34f
    goto L_0x004fb34f;
L_0x004fb34c:
    // 004fb34c  8d0c3b                 -lea ecx, [ebx + edi]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.edi * 1);
L_0x004fb34f:
    // 004fb34f  39f1                   +cmp ecx, esi
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
    // 004fb351  72d4                   -jb 0x4fb327
    if (cpu.flags.cf)
    {
        goto L_0x004fb327;
    }
L_0x004fb353:
    // 004fb353  39f1                   +cmp ecx, esi
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
    // 004fb355  750f                   -jne 0x4fb366
    if (!cpu.flags.zf)
    {
        goto L_0x004fb366;
    }
    // 004fb357  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fb359  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fb35b  ff1424                 -call dword ptr [esp]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb35e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb360  7504                   -jne 0x4fb366
    if (!cpu.flags.zf)
    {
        goto L_0x004fb366;
    }
    // 004fb362  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fb364  eb02                   -jmp 0x4fb368
    goto L_0x004fb368;
L_0x004fb366:
    // 004fb366  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fb368:
    // 004fb368  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fb36b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb36c  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fb36e  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fb370  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fb371  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb372  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb373  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4fb380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb380  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb385  a36c435600             -mov dword ptr [0x56436c], eax
    app->getMemory<x86::reg32>(x86::reg32(5653356) /* 0x56436c */) = cpu.eax;
    // 004fb38a  a1384f9f00             -mov eax, dword ptr [0x9f4f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb38f  a370435600             -mov dword ptr [0x564370], eax
    app->getMemory<x86::reg32>(x86::reg32(5653360) /* 0x564370 */) = cpu.eax;
    // 004fb394  a1544f9f00             -mov eax, dword ptr [0x9f4f54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb399  a374435600             -mov dword ptr [0x564374], eax
    app->getMemory<x86::reg32>(x86::reg32(5653364) /* 0x564374 */) = cpu.eax;
    // 004fb39e  a174435600             -mov eax, dword ptr [0x564374]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653364) /* 0x564374 */);
    // 004fb3a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fb3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb3b0  ff05484f9f00           -inc dword ptr [0x9f4f48]
    (app->getMemory<x86::reg32>(x86::reg32(10440520) /* 0x9f4f48 */))++;
    // 004fb3b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4fb3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb3c0  ff0d484f9f00           -dec dword ptr [0x9f4f48]
    (app->getMemory<x86::reg32>(x86::reg32(10440520) /* 0x9f4f48 */))--;
    // 004fb3c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4fb3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb3d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb3d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb3d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb3d3  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004fb3d8  bfc0b34f00             -mov edi, 0x4fb3c0
    cpu.edi = 5223360 /*0x4fb3c0*/;
    // 004fb3dd  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 004fb3e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fb3e4  a3444f9f00             -mov dword ptr [0x9f4f44], eax
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.eax;
    // 004fb3e9  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb3ef  8915484f9f00           -mov dword ptr [0x9f4f48], edx
    app->getMemory<x86::reg32>(x86::reg32(10440520) /* 0x9f4f48 */) = cpu.edx;
    // 004fb3f5  89154c4f9f00           -mov dword ptr [0x9f4f4c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.edx;
    // 004fb3fb  893568435600           -mov dword ptr [0x564368], esi
    app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */) = cpu.esi;
    // 004fb401  893d5c445600           -mov dword ptr [0x56445c], edi
    app->getMemory<x86::reg32>(x86::reg32(5653596) /* 0x56445c */) = cpu.edi;
    // 004fb407  893d60445600           -mov dword ptr [0x564460], edi
    app->getMemory<x86::reg32>(x86::reg32(5653600) /* 0x564460 */) = cpu.edi;
    // 004fb40d  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 004fb412  ba80b34f00             -mov edx, 0x4fb380
    cpu.edx = 5223296 /*0x4fb380*/;
    // 004fb417  a3404f9f00             -mov dword ptr [0x9f4f40], eax
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.eax;
    // 004fb41c  b8b0b34f00             -mov eax, 0x4fb3b0
    cpu.eax = 5223344 /*0x4fb3b0*/;
    // 004fb421  891568445600           -mov dword ptr [0x564468], edx
    app->getMemory<x86::reg32>(x86::reg32(5653608) /* 0x564468 */) = cpu.edx;
    // 004fb427  a364445600             -mov dword ptr [0x564464], eax
    app->getMemory<x86::reg32>(x86::reg32(5653604) /* 0x564464 */) = cpu.eax;
    // 004fb42c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fb42e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb42f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb430  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb431  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4fb440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
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
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
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
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb536(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb536;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
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
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
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
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
L_entry_0x004fb536:
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb527(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb527;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
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
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
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
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
L_entry_0x004fb527:
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb51b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb51b;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
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
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
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
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004fb51b:
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb50b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb50b;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
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
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
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
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
L_entry_0x004fb50b:
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb4ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb4ea;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
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
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
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
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
L_entry_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb4d0;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
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
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_entry_0x004fb4d0:
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
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
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb4c0;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
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
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
L_entry_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
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
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fb470;
    // 004fb440  a34c4f9f00             -mov dword ptr [0x9f4f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */) = cpu.eax;
    // 004fb445  8915504f9f00           -mov dword ptr [0x9f4f50], edx
    app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */) = cpu.edx;
    // 004fb44b  891d444f9f00           -mov dword ptr [0x9f4f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */) = cpu.ebx;
    // 004fb451  890d404f9f00           -mov dword ptr [0x9f4f40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */) = cpu.ecx;
    // 004fb457  8b1d544f9f00           -mov ebx, dword ptr [0x9f4f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb45d  8b15384f9f00           -mov edx, dword ptr [0x9f4f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb463  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb468  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fb46a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x004fb470:
    // 004fb470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb473  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb476  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fb478  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fb47a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fb47e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004fb481  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb488  0f84ca000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb48e  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb495  0f84bd000000           -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb49b  8b1d4c4f9f00           -mov ebx, dword ptr [0x9f4f4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4a1  39d8                   +cmp eax, ebx
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
    // 004fb4a3  7e02                   -jle 0x4fb4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4a7;
    }
    // 004fb4a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004fb4a7:
    // 004fb4a7  8b2d444f9f00           -mov ebp, dword ptr [0x9f4f44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb4ad  39eb                   +cmp ebx, ebp
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
    // 004fb4af  7d0f                   -jge 0x4fb4c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb4c0;
    }
    // 004fb4b1  a14c4f9f00             -mov eax, dword ptr [0x9f4f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb4b6  39c6                   +cmp esi, eax
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
    // 004fb4b8  0f8ee2010000           -jle 0x4fb6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a0(app, cpu);
    }
    // 004fb4be  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004fb4c0:
    // 004fb4c0  8b15504f9f00           -mov edx, dword ptr [0x9f4f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4c6  39d7                   +cmp edi, edx
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
    // 004fb4c8  0f8ed9010000           -jle 0x4fb6a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4fb6a7(app, cpu);
    }
    // 004fb4ce  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fb4d0  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb4d6  39cb                   +cmp ebx, ecx
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
    // 004fb4d8  0f8dd0010000           -jge 0x4fb6ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4fb6ae(app, cpu);
    }
    // 004fb4de  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb4e4  39df                   +cmp edi, ebx
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
    // 004fb4e6  7e02                   -jle 0x4fb4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb4ea;
    }
    // 004fb4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004fb4ea:
    // 004fb4ea  a190125600             -mov eax, dword ptr [0x561290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb4ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fb4f0  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb4f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb4fa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004fb4fe  a3544f9f00             -mov dword ptr [0x9f4f54], eax
    app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */) = cpu.eax;
    // 004fb503  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb505  0f84aa010000           -je 0x4fb6b5
    if (cpu.flags.zf)
    {
        return sub_4fb6b5(app, cpu);
    }
    // 004fb50b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb50f  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb514  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb516  e87513fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb51b  3b2d3c4f9f00           +cmp ebp, dword ptr [0x9f4f3c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb521  0f849b010000           -je 0x4fb6c2
    if (cpu.flags.zf)
    {
        return sub_4fb6c2(app, cpu);
    }
    // 004fb527  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fb52b  892d3c4f9f00           -mov dword ptr [0x9f4f3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.ebp;
    // 004fb531  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb536  8b1d90125600           -mov ebx, dword ptr [0x561290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004fb53c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb53d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fb541  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb547  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fb549  740d                   -je 0x4fb558
    if (cpu.flags.zf)
    {
        goto L_0x004fb558;
    }
    // 004fb54b  833d6c44560000         +cmp dword ptr [0x56446c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653612) /* 0x56446c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fb552  0f857f010000           -jne 0x4fb6d7
    if (!cpu.flags.zf)
    {
        return sub_4fb6d7(app, cpu);
    }
L_0x004fb558:
    // 004fb558  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fb55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb55e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4fb560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb560  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb562  7510                   -jne 0x4fb574
    if (!cpu.flags.zf)
    {
        goto L_0x004fb574;
    }
L_0x004fb564:
    // 004fb564  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fb566  7407                   -je 0x4fb56f
    if (cpu.flags.zf)
    {
        goto L_0x004fb56f;
    }
    // 004fb568  a13c4f9f00             -mov eax, dword ptr [0x9f4f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */);
    // 004fb56d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004fb56f:
    // 004fb56f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004fb571  750d                   -jne 0x4fb580
    if (!cpu.flags.zf)
    {
        goto L_0x004fb580;
    }
    // 004fb573  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb574:
    // 004fb574  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb575  8b0d544f9f00           -mov ecx, dword ptr [0x9f4f54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440532) /* 0x9f4f54 */);
    // 004fb57b  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004fb57d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb57e  ebe4                   -jmp 0x4fb564
    goto L_0x004fb564;
L_0x004fb580:
    // 004fb580  a1384f9f00             -mov eax, dword ptr [0x9f4f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */);
    // 004fb585  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004fb587  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fb590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb590  ff1568445600           -call dword ptr [0x564468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653608) /* 0x564468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb596  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4fb5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb5a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fb5a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fb5a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb5a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fb5a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fb5a5  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fb5a8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fb5aa  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004fb5ac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb5ae  e87d43feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004fb5b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb5b5  0f85a5000000           -jne 0x4fb660
    if (!cpu.flags.zf)
    {
        goto L_0x004fb660;
    }
    // 004fb5bb  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004fb5c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fb5c2  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004fb5c8:
    // 004fb5c8  8b0d4c4f9f00           -mov ecx, dword ptr [0x9f4f4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb5ce  39cb                   +cmp ebx, ecx
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
    // 004fb5d0  0f8e9b000000           -jle 0x4fb671
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb671;
    }
    // 004fb5d6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004fb5d8:
    // 004fb5d8  8b3d444f9f00           -mov edi, dword ptr [0x9f4f44]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440516) /* 0x9f4f44 */);
    // 004fb5de  39f8                   +cmp eax, edi
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
    // 004fb5e0  0f8d99000000           -jge 0x4fb67f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb67f;
    }
    // 004fb5e6  8b2d4c4f9f00           -mov ebp, dword ptr [0x9f4f4c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440524) /* 0x9f4f4c */);
    // 004fb5ec  39eb                   +cmp ebx, ebp
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
    // 004fb5ee  0f8e84000000           -jle 0x4fb678
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb678;
    }
    // 004fb5f4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x004fb5f6:
    // 004fb5f6  a1504f9f00             -mov eax, dword ptr [0x9f4f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb5fb  39c6                   +cmp esi, eax
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
    // 004fb5fd  7e02                   -jle 0x4fb601
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb601;
    }
    // 004fb5ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004fb601:
    // 004fb601  8b0d404f9f00           -mov ecx, dword ptr [0x9f4f40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440512) /* 0x9f4f40 */);
    // 004fb607  39c8                   +cmp eax, ecx
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
    // 004fb609  0f8d77000000           -jge 0x4fb686
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fb686;
    }
    // 004fb60f  8b1d504f9f00           -mov ebx, dword ptr [0x9f4f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440528) /* 0x9f4f50 */);
    // 004fb615  39de                   +cmp esi, ebx
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
    // 004fb617  7e02                   -jle 0x4fb61b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fb61b;
    }
    // 004fb619  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x004fb61b:
    // 004fb61b  89156c435600           -mov dword ptr [0x56436c], edx
    app->getMemory<x86::reg32>(x86::reg32(5653356) /* 0x56436c */) = cpu.edx;
    // 004fb621  a16c435600             -mov eax, dword ptr [0x56436c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653356) /* 0x56436c */);
    // 004fb626  a33c4f9f00             -mov dword ptr [0x9f4f3c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440508) /* 0x9f4f3c */) = cpu.eax;
    // 004fb62b  891d70435600           -mov dword ptr [0x564370], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653360) /* 0x564370 */) = cpu.ebx;
    // 004fb631  a170435600             -mov eax, dword ptr [0x564370]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653360) /* 0x564370 */);
    // 004fb636  a3384f9f00             -mov dword ptr [0x9f4f38], eax
    app->getMemory<x86::reg32>(x86::reg32(10440504) /* 0x9f4f38 */) = cpu.eax;
    // 004fb63b  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004fb640  e84b12fdff             -call 0x4cc890
    cpu.esp -= 4;
    sub_4cc890(app, cpu);
    if (cpu.terminate) return;
    // 004fb645  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fb647  e8e442feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004fb64c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fb64e  743a                   -je 0x4fb68a
    if (cpu.flags.zf)
    {
        goto L_0x004fb68a;
    }
    // 004fb650  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fb652  e8a990ffff             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
    // 004fb657  83c470                 +add esp, 0x70
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004fb65a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb65b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb65c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb65d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb65e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb65f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fb660:
    // 004fb660  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fb662  e86990ffff             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 004fb667  e824f7feff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 004fb66c  e957ffffff             -jmp 0x4fb5c8
    goto L_0x004fb5c8;
L_0x004fb671:
    // 004fb671  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fb673  e960ffffff             -jmp 0x4fb5d8
    goto L_0x004fb5d8;
L_0x004fb678:
    // 004fb678  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fb67a  e977ffffff             -jmp 0x4fb5f6
    goto L_0x004fb5f6;
L_0x004fb67f:
    // 004fb67f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fb681  e970ffffff             -jmp 0x4fb5f6
    goto L_0x004fb5f6;
L_0x004fb686:
    // 004fb686  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fb688  eb91                   -jmp 0x4fb61b
    goto L_0x004fb61b;
L_0x004fb68a:
    // 004fb68a  8b3580445600           -mov esi, dword ptr [0x564480]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004fb690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fb691  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fb697  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fb69a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb69b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb69c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb69d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb69e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fb69f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fb6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb6a0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fb6a2  e919feffff             -jmp 0x4fb4c0
    return sub_4fb4c0(app, cpu);
}

/* align: skip  */
void Application::sub_4fb6a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb6a7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fb6a9  e922feffff             -jmp 0x4fb4d0
    return sub_4fb4d0(app, cpu);
}

/* align: skip  */
void Application::sub_4fb6ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fb6ae  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fb6b0  e935feffff             -jmp 0x4fb4ea
    return sub_4fb4ea(app, cpu);
}

}
