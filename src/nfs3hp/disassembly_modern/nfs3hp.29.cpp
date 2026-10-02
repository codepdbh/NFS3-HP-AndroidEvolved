#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x90 */
void Application::sub_4bbd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbd80  b800008000             -mov eax, 0x800000
    cpu.eax = 8388608 /*0x800000*/;
    // 004bbd85  e872610300             -call 0x4f1efc
    cpu.esp -= 4;
    sub_4f1efc(app, cpu);
    if (cpu.terminate) return;
    // 004bbd8a  a334fe5500             -mov dword ptr [0x55fe34], eax
    app->getMemory<x86::reg32>(x86::reg32(5635636) /* 0x55fe34 */) = cpu.eax;
    // 004bbd8f  83c01f                 -add eax, 0x1f
    (cpu.eax) += x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004bbd92  24e0                   -and al, 0xe0
    cpu.al &= x86::reg8(x86::sreg8(224 /*0xe0*/));
    // 004bbd94  a338fe5500             -mov dword ptr [0x55fe38], eax
    app->getMemory<x86::reg32>(x86::reg32(5635640) /* 0x55fe38 */) = cpu.eax;
    // 004bbd99  c705043d7a009cff7f00   -mov dword ptr [0x7a3d04], 0x7fff9c
    app->getMemory<x86::reg32>(x86::reg32(8011012) /* 0x7a3d04 */) = 8388508 /*0x7fff9c*/;
    // 004bbda3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbda4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbda4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbda6  870534fe5500           -xchg dword ptr [0x55fe34], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(x86::reg32(5635636) /* 0x55fe34 */);
        app->getMemory<x86::reg32>(x86::reg32(5635636) /* 0x55fe34 */) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004bbdac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbdae  7405                   -je 0x4bbdb5
    if (cpu.flags.zf)
    {
        goto L_0x004bbdb5;
    }
    // 004bbdb0  e87b610300             -call 0x4f1f30
    cpu.esp -= 4;
    sub_4f1f30(app, cpu);
    if (cpu.terminate) return;
L_0x004bbdb5:
    // 004bbdb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbdb6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbdb6  90                     -nop 
    ;
    // 004bbdb7  90                     -nop 
    ;
    // 004bbdb8  90                     -nop 
    ;
    // 004bbdb9  90                     -nop 
    ;
    // 004bbdba  90                     -nop 
    ;
    // 004bbdbb  90                     -nop 
    ;
    // 004bbdbc  90                     -nop 
    ;
    // 004bbdbd  90                     -nop 
    ;
    // 004bbdbe  90                     -nop 
    ;
    // 004bbdbf  90                     -nop 
    ;
    // 004bbdc0  90                     -nop 
    ;
    // 004bbdc1  90                     -nop 
    ;
    // 004bbdc2  90                     -nop 
    ;
    // 004bbdc3  90                     -nop 
    ;
    // 004bbdc4  90                     -nop 
    ;
    // 004bbdc5  90                     -nop 
    ;
    // 004bbdc6  90                     -nop 
    ;
    // 004bbdc7  90                     -nop 
    ;
    // 004bbdc8  90                     -nop 
    ;
    // 004bbdc9  90                     -nop 
    ;
    // 004bbdca  90                     -nop 
    ;
    // 004bbdcb  90                     -nop 
    ;
    // 004bbdcc  90                     -nop 
    ;
    // 004bbdcd  90                     -nop 
    ;
    // 004bbdce  90                     -nop 
    ;
    // 004bbdcf  90                     -nop 
    ;
    // 004bbdd0  90                     -nop 
    ;
    // 004bbdd1  90                     -nop 
    ;
    // 004bbdd2  90                     -nop 
    ;
    // 004bbdd3  90                     -nop 
    ;
    // 004bbdd4  90                     -nop 
    ;
    // 004bbdd5  90                     -nop 
    ;
    // 004bbdd6  90                     -nop 
    ;
    // 004bbdd7  90                     -nop 
    ;
    // 004bbdd8  90                     -nop 
    ;
    // 004bbdd9  90                     -nop 
    ;
    // 004bbdda  90                     -nop 
    ;
    // 004bbddb  90                     -nop 
    ;
    // 004bbddc  90                     -nop 
    ;
    // 004bbddd  90                     -nop 
    ;
    // 004bbdde  90                     -nop 
    ;
    // 004bbddf  90                     -nop 
    ;
    // 004bbde0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bbde1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbde2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbde3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbde4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbde5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbde7  8b0d38fe5500           -mov ecx, dword ptr [0x55fe38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5635640) /* 0x55fe38 */);
    // 004bbded  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004bbdef  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bbdf1  890d38fe5500           -mov dword ptr [0x55fe38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5635640) /* 0x55fe38 */) = cpu.ecx;
    // 004bbdf7  8d591f                 -lea ebx, [ecx + 0x1f]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 004bbdfa  891d38fe5500           -mov dword ptr [0x55fe38], ebx
    app->getMemory<x86::reg32>(x86::reg32(5635640) /* 0x55fe38 */) = cpu.ebx;
    // 004bbe00  802538fe5500e0         -and byte ptr [0x55fe38], 0xe0
    app->getMemory<x86::reg8>(x86::reg32(5635640) /* 0x55fe38 */) &= x86::reg8(x86::sreg8(224 /*0xe0*/));
    // 004bbe07  8b3534fe5500           -mov esi, dword ptr [0x55fe34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5635636) /* 0x55fe34 */);
    // 004bbe0d  a138fe5500             -mov eax, dword ptr [0x55fe38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635640) /* 0x55fe38 */);
    // 004bbe12  8b3d043d7a00           -mov edi, dword ptr [0x7a3d04]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8011012) /* 0x7a3d04 */);
    // 004bbe18  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bbe1a  39f8                   +cmp eax, edi
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
    // 004bbe1c  7e11                   -jle 0x4bbe2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbe2f;
    }
    // 004bbe1e  6848015400             -push 0x540148
    app->getMemory<x86::reg32>(cpu.esp-4) = 5505352 /*0x540148*/;
    cpu.esp -= 4;
    // 004bbe23  e8e851f4ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004bbe28  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbe2b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bbe2d  eb05                   -jmp 0x4bbe34
    goto L_0x004bbe34;
L_0x004bbe2f:
    // 004bbe2f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004bbe34:
    // 004bbe34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe38  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bbde0;
    // 004bbdb6  90                     -nop 
    ;
    // 004bbdb7  90                     -nop 
    ;
    // 004bbdb8  90                     -nop 
    ;
    // 004bbdb9  90                     -nop 
    ;
    // 004bbdba  90                     -nop 
    ;
    // 004bbdbb  90                     -nop 
    ;
    // 004bbdbc  90                     -nop 
    ;
    // 004bbdbd  90                     -nop 
    ;
    // 004bbdbe  90                     -nop 
    ;
    // 004bbdbf  90                     -nop 
    ;
    // 004bbdc0  90                     -nop 
    ;
    // 004bbdc1  90                     -nop 
    ;
    // 004bbdc2  90                     -nop 
    ;
    // 004bbdc3  90                     -nop 
    ;
    // 004bbdc4  90                     -nop 
    ;
    // 004bbdc5  90                     -nop 
    ;
    // 004bbdc6  90                     -nop 
    ;
    // 004bbdc7  90                     -nop 
    ;
    // 004bbdc8  90                     -nop 
    ;
    // 004bbdc9  90                     -nop 
    ;
    // 004bbdca  90                     -nop 
    ;
    // 004bbdcb  90                     -nop 
    ;
    // 004bbdcc  90                     -nop 
    ;
    // 004bbdcd  90                     -nop 
    ;
    // 004bbdce  90                     -nop 
    ;
    // 004bbdcf  90                     -nop 
    ;
    // 004bbdd0  90                     -nop 
    ;
    // 004bbdd1  90                     -nop 
    ;
    // 004bbdd2  90                     -nop 
    ;
    // 004bbdd3  90                     -nop 
    ;
    // 004bbdd4  90                     -nop 
    ;
    // 004bbdd5  90                     -nop 
    ;
    // 004bbdd6  90                     -nop 
    ;
    // 004bbdd7  90                     -nop 
    ;
    // 004bbdd8  90                     -nop 
    ;
    // 004bbdd9  90                     -nop 
    ;
    // 004bbdda  90                     -nop 
    ;
    // 004bbddb  90                     -nop 
    ;
    // 004bbddc  90                     -nop 
    ;
    // 004bbddd  90                     -nop 
    ;
    // 004bbdde  90                     -nop 
    ;
    // 004bbddf  90                     -nop 
    ;
L_entry_0x004bbde0:
    // 004bbde0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bbde1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbde2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbde3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbde4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbde5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbde7  8b0d38fe5500           -mov ecx, dword ptr [0x55fe38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5635640) /* 0x55fe38 */);
    // 004bbded  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004bbdef  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bbdf1  890d38fe5500           -mov dword ptr [0x55fe38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5635640) /* 0x55fe38 */) = cpu.ecx;
    // 004bbdf7  8d591f                 -lea ebx, [ecx + 0x1f]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 004bbdfa  891d38fe5500           -mov dword ptr [0x55fe38], ebx
    app->getMemory<x86::reg32>(x86::reg32(5635640) /* 0x55fe38 */) = cpu.ebx;
    // 004bbe00  802538fe5500e0         -and byte ptr [0x55fe38], 0xe0
    app->getMemory<x86::reg8>(x86::reg32(5635640) /* 0x55fe38 */) &= x86::reg8(x86::sreg8(224 /*0xe0*/));
    // 004bbe07  8b3534fe5500           -mov esi, dword ptr [0x55fe34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5635636) /* 0x55fe34 */);
    // 004bbe0d  a138fe5500             -mov eax, dword ptr [0x55fe38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635640) /* 0x55fe38 */);
    // 004bbe12  8b3d043d7a00           -mov edi, dword ptr [0x7a3d04]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8011012) /* 0x7a3d04 */);
    // 004bbe18  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bbe1a  39f8                   +cmp eax, edi
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
    // 004bbe1c  7e11                   -jle 0x4bbe2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbe2f;
    }
    // 004bbe1e  6848015400             -push 0x540148
    app->getMemory<x86::reg32>(cpu.esp-4) = 5505352 /*0x540148*/;
    cpu.esp -= 4;
    // 004bbe23  e8e851f4ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004bbe28  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbe2b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bbe2d  eb05                   -jmp 0x4bbe34
    goto L_0x004bbe34;
L_0x004bbe2f:
    // 004bbe2f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004bbe34:
    // 004bbe34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe38  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4bbe40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbe40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbe41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbe42  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbe44  8b1538fe5500           -mov edx, dword ptr [0x55fe38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5635640) /* 0x55fe38 */);
    // 004bbe4a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004bbe4c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bbe4e  8b1534fe5500           -mov edx, dword ptr [0x55fe34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5635636) /* 0x55fe34 */);
    // 004bbe54  8b0d043d7a00           -mov ecx, dword ptr [0x7a3d04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8011012) /* 0x7a3d04 */);
    // 004bbe5a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbe5c  39c8                   +cmp eax, ecx
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
    // 004bbe5e  7e05                   -jle 0x4bbe65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbe65;
    }
    // 004bbe60  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbe62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bbe65:
    // 004bbe65  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bbe6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bbe70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbe70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bbe71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbe72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbe73  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbe75  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bbe78  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bbe7a  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004bbe7c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbe7e  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bbe81  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004bbe84  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004bbe87  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbe88  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbe89  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bbe8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe8d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bbe90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbe90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bbe91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbe92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbe93  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbe95  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bbe98  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004bbe9a  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004bbe9d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004bbea0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbea2  7406                   -je 0x4bbeaa
    if (cpu.flags.zf)
    {
        goto L_0x004bbeaa;
    }
    // 004bbea4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
L_0x004bbeaa:
    // 004bbeaa  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bbead  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bbeaf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbeb0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbeb1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bbeb3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bbeb5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbeb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbeb7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbeb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4bbec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bbec1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bbec2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbec3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbec4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbec6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bbec9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004bbecb  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 004bbecf  7508                   -jne 0x4bbed9
    if (!cpu.flags.zf)
    {
        goto L_0x004bbed9;
    }
    // 004bbed1  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bbed4  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004bbed7  eb32                   -jmp 0x4bbf0b
    goto L_0x004bbf0b;
L_0x004bbed9:
    // 004bbed9  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004bbedc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bbede  751a                   -jne 0x4bbefa
    if (!cpu.flags.zf)
    {
        goto L_0x004bbefa;
    }
    // 004bbee0  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bbee3  8d7514                 -lea esi, [ebp + 0x14]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bbee6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbee7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbee8  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bbeeb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bbeed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbeee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbeef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bbef1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bbef3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbef4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbef5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbef6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbef7  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004bbefa:
    // 004bbefa  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bbefd  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004bbf00  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bbf03  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004bbf05  8d7514                 -lea esi, [ebp + 0x14]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bbf08  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004bbf0b:
    // 004bbf0b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbf0c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbf0d  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bbf10  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bbf12  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbf13  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbf14  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bbf16  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bbf18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf1c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bbf20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbf20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bbf21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbf22  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbf24  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbf26  8915083d7a00           -mov dword ptr [0x7a3d08], edx
    app->getMemory<x86::reg32>(x86::reg32(8011016) /* 0x7a3d08 */) = cpu.edx;
    // 004bbf2c  89150c3d7a00           -mov dword ptr [0x7a3d0c], edx
    app->getMemory<x86::reg32>(x86::reg32(8011020) /* 0x7a3d0c */) = cpu.edx;
    // 004bbf32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf33  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4bbf40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbf40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bbf41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbf42  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbf44  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004bbf47  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bbf49  742a                   -je 0x4bbf75
    if (cpu.flags.zf)
    {
        goto L_0x004bbf75;
    }
    // 004bbf4b  837d1000               +cmp dword ptr [ebp + 0x10], 0
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
    // 004bbf4f  7424                   -je 0x4bbf75
    if (cpu.flags.zf)
    {
        goto L_0x004bbf75;
    }
    // 004bbf51  833d0c3d7a0000         +cmp dword ptr [0x7a3d0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011020) /* 0x7a3d0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbf58  7508                   -jne 0x4bbf62
    if (!cpu.flags.zf)
    {
        goto L_0x004bbf62;
    }
    // 004bbf5a  89150c3d7a00           -mov dword ptr [0x7a3d0c], edx
    app->getMemory<x86::reg32>(x86::reg32(8011020) /* 0x7a3d0c */) = cpu.edx;
    // 004bbf60  eb0b                   -jmp 0x4bbf6d
    goto L_0x004bbf6d;
L_0x004bbf62:
    // 004bbf62  8b15083d7a00           -mov edx, dword ptr [0x7a3d08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8011016) /* 0x7a3d08 */);
    // 004bbf68  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004bbf6b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004bbf6d:
    // 004bbf6d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004bbf70  a3083d7a00             -mov dword ptr [0x7a3d08], eax
    app->getMemory<x86::reg32>(x86::reg32(8011016) /* 0x7a3d08 */) = cpu.eax;
L_0x004bbf75:
    // 004bbf75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf76  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf77  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4bbf80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbf80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbf81  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbf82  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbf84  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bbf86  e855feffff             -call 0x4bbde0
    cpu.esp -= 4;
    sub_4bbde0(app, cpu);
    if (cpu.terminate) return;
    // 004bbf8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbf8d  7428                   -je 0x4bbfb7
    if (cpu.flags.zf)
    {
        goto L_0x004bbfb7;
    }
    // 004bbf8f  833d0c3d7a0000         +cmp dword ptr [0x7a3d0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011020) /* 0x7a3d0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbf96  7509                   -jne 0x4bbfa1
    if (!cpu.flags.zf)
    {
        goto L_0x004bbfa1;
    }
    // 004bbf98  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bbf9a  a30c3d7a00             -mov dword ptr [0x7a3d0c], eax
    app->getMemory<x86::reg32>(x86::reg32(8011020) /* 0x7a3d0c */) = cpu.eax;
    // 004bbf9f  eb0a                   -jmp 0x4bbfab
    goto L_0x004bbfab;
L_0x004bbfa1:
    // 004bbfa1  8b15083d7a00           -mov edx, dword ptr [0x7a3d08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8011016) /* 0x7a3d08 */);
    // 004bbfa7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bbfa9  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004bbfab:
    // 004bbfab  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bbfad  a3083d7a00             -mov dword ptr [0x7a3d08], eax
    app->getMemory<x86::reg32>(x86::reg32(8011016) /* 0x7a3d08 */) = cpu.eax;
    // 004bbfb2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004bbfb7:
    // 004bbfb7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4bbfc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bbfc0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbfc1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbfc2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbfc4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bbfc7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bbfc9  8b350c3d7a00           -mov esi, dword ptr [0x7a3d0c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8011020) /* 0x7a3d0c */);
    // 004bbfcf  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 004bbfd2  8b35083d7a00           -mov esi, dword ptr [0x7a3d08]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8011016) /* 0x7a3d08 */);
    // 004bbfd8  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004bbfdb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bbfdd  7406                   -je 0x4bbfe5
    if (cpu.flags.zf)
    {
        goto L_0x004bbfe5;
    }
    // 004bbfdf  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x004bbfe5:
    // 004bbfe5  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bbfe8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bbfea  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbfeb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bbfec  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bbfee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbff0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4bc000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc000  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc001  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc002  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc003  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc004  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc006  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc009  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004bc00b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc00d  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc010  e88bb90000             -call 0x4c79a0
    cpu.esp -= 4;
    sub_4c79a0(app, cpu);
    if (cpu.terminate) return;
    // 004bc015  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004bc017  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc019  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc01c  e82fb70000             -call 0x4c7750
    cpu.esp -= 4;
    sub_4c7750(app, cpu);
    if (cpu.terminate) return;
    // 004bc021  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc022  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc023  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bc025  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bc027  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc028  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc029  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc02a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc02b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4bc030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc032  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc033  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc034  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc035  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc037  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc03a  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004bc03d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc03e  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bc040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc041  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc044  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bc046  e88589f7ff             -call 0x4349d0
    cpu.esp -= 4;
    sub_4349d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc04b  e820feffff             -call 0x4bbe70
    cpu.esp -= 4;
    sub_4bbe70(app, cpu);
    if (cpu.terminate) return;
    // 004bc050  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc053  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc054  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc055  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bc057  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc058  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc059  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc05a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc05b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc05c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bc060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc061  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc062  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc063  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc064  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc066  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc069  833d603a7a0000         +cmp dword ptr [0x7a3a60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010336) /* 0x7a3a60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc070  750c                   -jne 0x4bc07e
    if (!cpu.flags.zf)
    {
        goto L_0x004bc07e;
    }
    // 004bc072  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004bc074  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004bc077  e814b70000             -call 0x4c7790
    cpu.esp -= 4;
    sub_4c7790(app, cpu);
    if (cpu.terminate) return;
    // 004bc07c  eb0c                   -jmp 0x4bc08a
    goto L_0x004bc08a;
L_0x004bc07e:
    // 004bc07e  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004bc081  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc082  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004bc084  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc085  e84689f7ff             -call 0x4349d0
    cpu.esp -= 4;
    sub_4349d0(app, cpu);
    if (cpu.terminate) return;
L_0x004bc08a:
    // 004bc08a  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc08d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bc08f  e8dcfdffff             -call 0x4bbe70
    cpu.esp -= 4;
    sub_4bbe70(app, cpu);
    if (cpu.terminate) return;
    // 004bc094  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc097  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc098  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc099  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bc09b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc09c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc09d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc09e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc09f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4bc0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc0b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc0b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc0b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc0b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc0b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc0b5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc0b7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc0ba  833d603a7a0000         +cmp dword ptr [0x7a3a60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010336) /* 0x7a3a60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc0c1  7511                   -jne 0x4bc0d4
    if (!cpu.flags.zf)
    {
        goto L_0x004bc0d4;
    }
    // 004bc0c3  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004bc0c6  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004bc0c9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc0ca  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004bc0cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc0cd  e82eb30000             -call 0x4c7400
    cpu.esp -= 4;
    sub_4c7400(app, cpu);
    if (cpu.terminate) return;
    // 004bc0d2  eb0c                   -jmp 0x4bc0e0
    goto L_0x004bc0e0;
L_0x004bc0d4:
    // 004bc0d4  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004bc0d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc0d8  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bc0da  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc0db  e8f088f7ff             -call 0x4349d0
    cpu.esp -= 4;
    sub_4349d0(app, cpu);
    if (cpu.terminate) return;
L_0x004bc0e0:
    // 004bc0e0  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc0e3  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bc0e5  e886fdffff             -call 0x4bbe70
    cpu.esp -= 4;
    sub_4bbe70(app, cpu);
    if (cpu.terminate) return;
    // 004bc0ea  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc0ed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc0ee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc0ef  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bc0f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0f6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4bc100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc100  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc101  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc103  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004bc10a  750d                   -jne 0x4bc119
    if (!cpu.flags.zf)
    {
        goto L_0x004bc119;
    }
    // 004bc10c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004bc10f  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004bc112  0508db7c00             +add eax, 0x7cdb08
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8182536 /*0x7cdb08*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc117  eb05                   -jmp 0x4bc11e
    goto L_0x004bc11e;
L_0x004bc119:
    // 004bc119  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
L_0x004bc11e:
    // 004bc11e  e84d2c0000             -call 0x4bed70
    cpu.esp -= 4;
    sub_4bed70(app, cpu);
    if (cpu.terminate) return;
    // 004bc123  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc124  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4bc130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc130  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc131  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc133  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004bc13a  750d                   -jne 0x4bc149
    if (!cpu.flags.zf)
    {
        goto L_0x004bc149;
    }
    // 004bc13c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004bc13f  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004bc142  0580da7c00             +add eax, 0x7cda80
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8182400 /*0x7cda80*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc147  eb05                   -jmp 0x4bc14e
    goto L_0x004bc14e;
L_0x004bc149:
    // 004bc149  b888db7c00             -mov eax, 0x7cdb88
    cpu.eax = 8182664 /*0x7cdb88*/;
L_0x004bc14e:
    // 004bc14e  e81d2c0000             -call 0x4bed70
    cpu.esp -= 4;
    sub_4bed70(app, cpu);
    if (cpu.terminate) return;
    // 004bc153  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc154  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4bc160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc162  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc163  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc164  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc165  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc166  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc168  83ec50                 +sub esp, 0x50
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc16b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bc16d  e8aa5af7ff             -call 0x431c1c
    cpu.esp -= 4;
    sub_431c1c(app, cpu);
    if (cpu.terminate) return;
    // 004bc172  eb02                   -jmp 0x4bc176
    goto L_0x004bc176;
    // 004bc174  90                     -nop 
    ;
    // 004bc175  90                     -nop 
    ;
L_0x004bc176:
    // 004bc176  e84557f7ff             -call 0x4318c0
    cpu.esp -= 4;
    sub_4318c0(app, cpu);
    if (cpu.terminate) return;
    // 004bc17b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc180  e8cbb50000             -call 0x4c7750
    cpu.esp -= 4;
    sub_4c7750(app, cpu);
    if (cpu.terminate) return;
    // 004bc185  e866b40000             -call 0x4c75f0
    cpu.esp -= 4;
    sub_4c75f0(app, cpu);
    if (cpu.terminate) return;
    // 004bc18a  e851b20000             -call 0x4c73e0
    cpu.esp -= 4;
    sub_4c73e0(app, cpu);
    if (cpu.terminate) return;
    // 004bc18f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bc191  750f                   -jne 0x4bc1a2
    if (!cpu.flags.zf)
    {
        goto L_0x004bc1a2;
    }
    // 004bc193  f605583a7a0006         +test byte ptr [0x7a3a58], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 6 /*0x6*/));
    // 004bc19a  7406                   -je 0x4bc1a2
    if (cpu.flags.zf)
    {
        goto L_0x004bc1a2;
    }
    // 004bc19c  ff1570f99e00           -call dword ptr [0x9ef970]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418544) /* 0x9ef970 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004bc1a2:
    // 004bc1a2  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 004bc1a9  7426                   -je 0x4bc1d1
    if (cpu.flags.zf)
    {
        goto L_0x004bc1d1;
    }
    // 004bc1ab  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bc1b0  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004bc1b5  8d75b0                 -lea esi, [ebp - 0x50]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004bc1b8  e84357f7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
    // 004bc1bd  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc1c2  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc1c7  e814c1fbff             -call 0x4782e0
    cpu.esp -= 4;
    sub_4782e0(app, cpu);
    if (cpu.terminate) return;
    // 004bc1cc  8d75b0                 -lea esi, [ebp - 0x50]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004bc1cf  eb15                   -jmp 0x4bc1e6
    goto L_0x004bc1e6;
L_0x004bc1d1:
    // 004bc1d1  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc1d6  8d75b8                 -lea esi, [ebp - 0x48]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 004bc1d9  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc1de  e8fdc0fbff             -call 0x4782e0
    cpu.esp -= 4;
    sub_4782e0(app, cpu);
    if (cpu.terminate) return;
    // 004bc1e3  8d75b8                 -lea esi, [ebp - 0x48]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
L_0x004bc1e6:
    // 004bc1e6  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc1eb  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc1f0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc1f1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc1f2  e839feffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc1f7  eb13                   -jmp 0x4bc20c
    return sub_4bc20c(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4bc1fa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc1fa  90                     -nop 
    ;
    // 004bc1fb  90                     -nop 
    ;
    // 004bc1fc  90                     -nop 
    ;
    // 004bc1fd  90                     -nop 
    ;
    // 004bc1fe  90                     -nop 
    ;
    // 004bc1ff  90                     -nop 
    ;
    // 004bc200  90                     -nop 
    ;
    // 004bc201  90                     -nop 
    ;
    // 004bc202  90                     -nop 
    ;
    // 004bc203  90                     -nop 
    ;
    // 004bc204  90                     -nop 
    ;
    // 004bc205  90                     -nop 
    ;
    // 004bc206  90                     -nop 
    ;
    // 004bc207  90                     -nop 
    ;
    // 004bc208  90                     -nop 
    ;
    // 004bc209  90                     -nop 
    ;
    // 004bc20a  90                     -nop 
    ;
    // 004bc20b  90                     -nop 
    ;
    // 004bc20c  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 004bc213  7422                   -je 0x4bc237
    if (cpu.flags.zf)
    {
        goto L_0x004bc237;
    }
    // 004bc215  8b1544bc6f00           -mov edx, dword ptr [0x6fbc44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322692) /* 0x6fbc44 */);
    // 004bc21b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bc21d  7509                   -jne 0x4bc228
    if (!cpu.flags.zf)
    {
        goto L_0x004bc228;
    }
    // 004bc21f  833dc8d46f0001         +cmp dword ptr [0x6fd4c8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328968) /* 0x6fd4c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc226  7505                   -jne 0x4bc22d
    if (!cpu.flags.zf)
    {
        goto L_0x004bc22d;
    }
L_0x004bc228:
    // 004bc228  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004bc22d:
    // 004bc22d  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004bc232  e8c956f7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x004bc237:
    // 004bc237  833d603a7a0000         +cmp dword ptr [0x7a3a60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010336) /* 0x7a3a60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc23e  7555                   -jne 0x4bc295
    if (!cpu.flags.zf)
    {
        goto L_0x004bc295;
    }
    // 004bc240  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc245  e866f7f5ff             -call 0x41b9b0
    cpu.esp -= 4;
    sub_41b9b0(app, cpu);
    if (cpu.terminate) return;
    // 004bc24a  eb16                   -jmp 0x4bc262
    goto L_0x004bc262;
    // 004bc24c  90                     -nop 
    ;
    // 004bc24d  90                     -nop 
    ;
    // 004bc24e  90                     -nop 
    ;
    // 004bc24f  90                     -nop 
    ;
    // 004bc250  90                     -nop 
    ;
    // 004bc251  90                     -nop 
    ;
    // 004bc252  90                     -nop 
    ;
    // 004bc253  90                     -nop 
    ;
    // 004bc254  90                     -nop 
    ;
    // 004bc255  90                     -nop 
    ;
    // 004bc256  90                     -nop 
    ;
    // 004bc257  90                     -nop 
    ;
    // 004bc258  90                     -nop 
    ;
    // 004bc259  90                     -nop 
    ;
    // 004bc25a  90                     -nop 
    ;
    // 004bc25b  90                     -nop 
    ;
    // 004bc25c  90                     -nop 
    ;
    // 004bc25d  90                     -nop 
    ;
    // 004bc25e  90                     -nop 
    ;
    // 004bc25f  90                     -nop 
    ;
    // 004bc260  90                     -nop 
    ;
    // 004bc261  90                     -nop 
    ;
L_0x004bc262:
    // 004bc262  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc267  e894ac0000             -call 0x4c6f00
    cpu.esp -= 4;
    sub_4c6f00(app, cpu);
    if (cpu.terminate) return;
    // 004bc26c  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc271  8d75c0                 -lea esi, [ebp - 0x40]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004bc274  e827f9ffff             -call 0x4bbba0
    cpu.esp -= 4;
    sub_4bbba0(app, cpu);
    if (cpu.terminate) return;
    // 004bc279  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc27e  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc283  e838030100             -call 0x4cc5c0
    cpu.esp -= 4;
    sub_4cc5c0(app, cpu);
    if (cpu.terminate) return;
    // 004bc288  e8f3b20000             -call 0x4c7580
    cpu.esp -= 4;
    sub_4c7580(app, cpu);
    if (cpu.terminate) return;
    // 004bc28d  8d75c0                 -lea esi, [ebp - 0x40]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004bc290  e9c2000000             -jmp 0x4bc357
    return sub_4bc357(app, cpu);
L_0x004bc295:
    // 004bc295  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc29a  8d75c8                 -lea esi, [ebp - 0x38]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004bc29d  e80ef7f5ff             -call 0x41b9b0
    cpu.esp -= 4;
    sub_41b9b0(app, cpu);
    if (cpu.terminate) return;
    // 004bc2a2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc2a7  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc2ac  e84ffdffff             -call 0x4bc000
    cpu.esp -= 4;
    sub_4bc000(app, cpu);
    if (cpu.terminate) return;
    // 004bc2b1  8d75c8                 -lea esi, [ebp - 0x38]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004bc2b4  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc2b9  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc2be  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc2bf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc2c0  e86bfdffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc2c5  eb16                   -jmp 0x4bc2dd
    return sub_4bc2dd(app, cpu);
}

/* align: skip  */
void Application::sub_4bc20c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bc20c;
    // 004bc1fa  90                     -nop 
    ;
    // 004bc1fb  90                     -nop 
    ;
    // 004bc1fc  90                     -nop 
    ;
    // 004bc1fd  90                     -nop 
    ;
    // 004bc1fe  90                     -nop 
    ;
    // 004bc1ff  90                     -nop 
    ;
    // 004bc200  90                     -nop 
    ;
    // 004bc201  90                     -nop 
    ;
    // 004bc202  90                     -nop 
    ;
    // 004bc203  90                     -nop 
    ;
    // 004bc204  90                     -nop 
    ;
    // 004bc205  90                     -nop 
    ;
    // 004bc206  90                     -nop 
    ;
    // 004bc207  90                     -nop 
    ;
    // 004bc208  90                     -nop 
    ;
    // 004bc209  90                     -nop 
    ;
    // 004bc20a  90                     -nop 
    ;
    // 004bc20b  90                     -nop 
    ;
L_entry_0x004bc20c:
    // 004bc20c  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 004bc213  7422                   -je 0x4bc237
    if (cpu.flags.zf)
    {
        goto L_0x004bc237;
    }
    // 004bc215  8b1544bc6f00           -mov edx, dword ptr [0x6fbc44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322692) /* 0x6fbc44 */);
    // 004bc21b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bc21d  7509                   -jne 0x4bc228
    if (!cpu.flags.zf)
    {
        goto L_0x004bc228;
    }
    // 004bc21f  833dc8d46f0001         +cmp dword ptr [0x6fd4c8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328968) /* 0x6fd4c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc226  7505                   -jne 0x4bc22d
    if (!cpu.flags.zf)
    {
        goto L_0x004bc22d;
    }
L_0x004bc228:
    // 004bc228  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004bc22d:
    // 004bc22d  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004bc232  e8c956f7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x004bc237:
    // 004bc237  833d603a7a0000         +cmp dword ptr [0x7a3a60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010336) /* 0x7a3a60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc23e  7555                   -jne 0x4bc295
    if (!cpu.flags.zf)
    {
        goto L_0x004bc295;
    }
    // 004bc240  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc245  e866f7f5ff             -call 0x41b9b0
    cpu.esp -= 4;
    sub_41b9b0(app, cpu);
    if (cpu.terminate) return;
    // 004bc24a  eb16                   -jmp 0x4bc262
    goto L_0x004bc262;
    // 004bc24c  90                     -nop 
    ;
    // 004bc24d  90                     -nop 
    ;
    // 004bc24e  90                     -nop 
    ;
    // 004bc24f  90                     -nop 
    ;
    // 004bc250  90                     -nop 
    ;
    // 004bc251  90                     -nop 
    ;
    // 004bc252  90                     -nop 
    ;
    // 004bc253  90                     -nop 
    ;
    // 004bc254  90                     -nop 
    ;
    // 004bc255  90                     -nop 
    ;
    // 004bc256  90                     -nop 
    ;
    // 004bc257  90                     -nop 
    ;
    // 004bc258  90                     -nop 
    ;
    // 004bc259  90                     -nop 
    ;
    // 004bc25a  90                     -nop 
    ;
    // 004bc25b  90                     -nop 
    ;
    // 004bc25c  90                     -nop 
    ;
    // 004bc25d  90                     -nop 
    ;
    // 004bc25e  90                     -nop 
    ;
    // 004bc25f  90                     -nop 
    ;
    // 004bc260  90                     -nop 
    ;
    // 004bc261  90                     -nop 
    ;
L_0x004bc262:
    // 004bc262  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc267  e894ac0000             -call 0x4c6f00
    cpu.esp -= 4;
    sub_4c6f00(app, cpu);
    if (cpu.terminate) return;
    // 004bc26c  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc271  8d75c0                 -lea esi, [ebp - 0x40]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004bc274  e827f9ffff             -call 0x4bbba0
    cpu.esp -= 4;
    sub_4bbba0(app, cpu);
    if (cpu.terminate) return;
    // 004bc279  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc27e  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc283  e838030100             -call 0x4cc5c0
    cpu.esp -= 4;
    sub_4cc5c0(app, cpu);
    if (cpu.terminate) return;
    // 004bc288  e8f3b20000             -call 0x4c7580
    cpu.esp -= 4;
    sub_4c7580(app, cpu);
    if (cpu.terminate) return;
    // 004bc28d  8d75c0                 -lea esi, [ebp - 0x40]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004bc290  e9c2000000             -jmp 0x4bc357
    return sub_4bc357(app, cpu);
L_0x004bc295:
    // 004bc295  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc29a  8d75c8                 -lea esi, [ebp - 0x38]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004bc29d  e80ef7f5ff             -call 0x41b9b0
    cpu.esp -= 4;
    sub_41b9b0(app, cpu);
    if (cpu.terminate) return;
    // 004bc2a2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc2a7  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc2ac  e84ffdffff             -call 0x4bc000
    cpu.esp -= 4;
    sub_4bc000(app, cpu);
    if (cpu.terminate) return;
    // 004bc2b1  8d75c8                 -lea esi, [ebp - 0x38]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004bc2b4  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc2b9  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc2be  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc2bf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc2c0  e86bfdffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc2c5  eb16                   -jmp 0x4bc2dd
    return sub_4bc2dd(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4bc2c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc2c8  90                     -nop 
    ;
    // 004bc2c9  90                     -nop 
    ;
    // 004bc2ca  90                     -nop 
    ;
    // 004bc2cb  90                     -nop 
    ;
    // 004bc2cc  90                     -nop 
    ;
    // 004bc2cd  90                     -nop 
    ;
    // 004bc2ce  90                     -nop 
    ;
    // 004bc2cf  90                     -nop 
    ;
    // 004bc2d0  90                     -nop 
    ;
    // 004bc2d1  90                     -nop 
    ;
    // 004bc2d2  90                     -nop 
    ;
    // 004bc2d3  90                     -nop 
    ;
    // 004bc2d4  90                     -nop 
    ;
    // 004bc2d5  90                     -nop 
    ;
    // 004bc2d6  90                     -nop 
    ;
    // 004bc2d7  90                     -nop 
    ;
    // 004bc2d8  90                     -nop 
    ;
    // 004bc2d9  90                     -nop 
    ;
    // 004bc2da  90                     -nop 
    ;
    // 004bc2db  90                     -nop 
    ;
    // 004bc2dc  90                     -nop 
    ;
    // 004bc2dd  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc2e2  8d75d0                 -lea esi, [ebp - 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004bc2e5  e816ac0000             -call 0x4c6f00
    cpu.esp -= 4;
    sub_4c6f00(app, cpu);
    if (cpu.terminate) return;
    // 004bc2ea  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc2ef  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc2f4  e807fdffff             -call 0x4bc000
    cpu.esp -= 4;
    sub_4bc000(app, cpu);
    if (cpu.terminate) return;
    // 004bc2f9  8d75d0                 -lea esi, [ebp - 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004bc2fc  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc301  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc306  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc307  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc308  e823fdffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc30d  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc312  8d75d8                 -lea esi, [ebp - 0x28]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004bc315  e886f8ffff             -call 0x4bbba0
    cpu.esp -= 4;
    sub_4bbba0(app, cpu);
    if (cpu.terminate) return;
    // 004bc31a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc31f  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc324  e8d7fcffff             -call 0x4bc000
    cpu.esp -= 4;
    sub_4bc000(app, cpu);
    if (cpu.terminate) return;
    // 004bc329  8d75d8                 -lea esi, [ebp - 0x28]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004bc32c  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc331  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc336  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc337  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc338  e8f3fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc33d  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc342  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bc345  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc34a  e871020100             -call 0x4cc5c0
    cpu.esp -= 4;
    sub_4cc5c0(app, cpu);
    if (cpu.terminate) return;
    // 004bc34f  e88cb30000             -call 0x4c76e0
    cpu.esp -= 4;
    sub_4c76e0(app, cpu);
    if (cpu.terminate) return;
    // 004bc354  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bc357  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc35c  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc361  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc362  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc363  e8c8fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc368  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc36d  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bc370  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc375  e866290200             -call 0x4dece0
    cpu.esp -= 4;
    sub_4dece0(app, cpu);
    if (cpu.terminate) return;
    // 004bc37a  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bc37d  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc382  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc387  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc388  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc389  e8a2fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc38e  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc393  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bc396  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc39b  e8502a0200             -call 0x4dedf0
    cpu.esp -= 4;
    sub_4dedf0(app, cpu);
    if (cpu.terminate) return;
    // 004bc3a0  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bc3a3  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc3a8  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3ad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3ae  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3af  e87cfcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc3b4  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3b9  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc3bc  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc3c1  e83a020100             -call 0x4cc600
    cpu.esp -= 4;
    sub_4cc600(app, cpu);
    if (cpu.terminate) return;
    // 004bc3c6  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc3c9  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc3ce  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3d3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3d4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3d5  e856fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc3da  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bc3dc  751b                   -jne 0x4bc3f9
    if (!cpu.flags.zf)
    {
        goto L_0x004bc3f9;
    }
    // 004bc3de  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
    // 004bc3e3  e888290000             -call 0x4bed70
    cpu.esp -= 4;
    sub_4bed70(app, cpu);
    if (cpu.terminate) return;
    // 004bc3e8  e8b356f7ff             -call 0x431aa0
    cpu.esp -= 4;
    sub_431aa0(app, cpu);
    if (cpu.terminate) return;
    // 004bc3ed  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3f2  e80967fcff             -call 0x482b00
    cpu.esp -= 4;
    sub_482b00(app, cpu);
    if (cpu.terminate) return;
    // 004bc3f7  eb19                   -jmp 0x4bc412
    goto L_0x004bc412;
L_0x004bc3f9:
    // 004bc3f9  83fb01                 +cmp ebx, 1
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
    // 004bc3fc  7523                   -jne 0x4bc421
    if (!cpu.flags.zf)
    {
        goto L_0x004bc421;
    }
    // 004bc3fe  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc403  e8f8fcffff             -call 0x4bc100
    cpu.esp -= 4;
    sub_4bc100(app, cpu);
    if (cpu.terminate) return;
    // 004bc408  e89356f7ff             -call 0x431aa0
    cpu.esp -= 4;
    sub_431aa0(app, cpu);
    if (cpu.terminate) return;
    // 004bc40d  e81e7cfcff             -call 0x484030
    cpu.esp -= 4;
    sub_484030(app, cpu);
    if (cpu.terminate) return;
L_0x004bc412:
    // 004bc412  e82957f7ff             -call 0x431b40
    cpu.esp -= 4;
    sub_431b40(app, cpu);
    if (cpu.terminate) return;
    // 004bc417  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc41c  e80ffdffff             -call 0x4bc130
    cpu.esp -= 4;
    sub_4bc130(app, cpu);
    if (cpu.terminate) return;
L_0x004bc421:
    // 004bc421  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bc423  7526                   -jne 0x4bc44b
    if (!cpu.flags.zf)
    {
        return sub_4bc44b(app, cpu);
    }
    // 004bc425  833da0367d0000         +cmp dword ptr [0x7d36a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8205984) /* 0x7d36a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc42c  7513                   -jne 0x4bc441
    if (!cpu.flags.zf)
    {
        goto L_0x004bc441;
    }
    // 004bc42e  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc435  750a                   -jne 0x4bc441
    if (!cpu.flags.zf)
    {
        goto L_0x004bc441;
    }
    // 004bc437  a1183d7a00             -mov eax, dword ptr [0x7a3d18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8011032) /* 0x7a3d18 */);
    // 004bc43c  e8df61fcff             -call 0x482620
    cpu.esp -= 4;
    sub_482620(app, cpu);
    if (cpu.terminate) return;
L_0x004bc441:
    // 004bc441  eb08                   -jmp 0x4bc44b
    return sub_4bc44b(app, cpu);
}

/* align: skip  */
void Application::sub_4bc357(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bc357;
    // 004bc2c8  90                     -nop 
    ;
    // 004bc2c9  90                     -nop 
    ;
    // 004bc2ca  90                     -nop 
    ;
    // 004bc2cb  90                     -nop 
    ;
    // 004bc2cc  90                     -nop 
    ;
    // 004bc2cd  90                     -nop 
    ;
    // 004bc2ce  90                     -nop 
    ;
    // 004bc2cf  90                     -nop 
    ;
    // 004bc2d0  90                     -nop 
    ;
    // 004bc2d1  90                     -nop 
    ;
    // 004bc2d2  90                     -nop 
    ;
    // 004bc2d3  90                     -nop 
    ;
    // 004bc2d4  90                     -nop 
    ;
    // 004bc2d5  90                     -nop 
    ;
    // 004bc2d6  90                     -nop 
    ;
    // 004bc2d7  90                     -nop 
    ;
    // 004bc2d8  90                     -nop 
    ;
    // 004bc2d9  90                     -nop 
    ;
    // 004bc2da  90                     -nop 
    ;
    // 004bc2db  90                     -nop 
    ;
    // 004bc2dc  90                     -nop 
    ;
    // 004bc2dd  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc2e2  8d75d0                 -lea esi, [ebp - 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004bc2e5  e816ac0000             -call 0x4c6f00
    cpu.esp -= 4;
    sub_4c6f00(app, cpu);
    if (cpu.terminate) return;
    // 004bc2ea  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc2ef  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc2f4  e807fdffff             -call 0x4bc000
    cpu.esp -= 4;
    sub_4bc000(app, cpu);
    if (cpu.terminate) return;
    // 004bc2f9  8d75d0                 -lea esi, [ebp - 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004bc2fc  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc301  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc306  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc307  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc308  e823fdffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc30d  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc312  8d75d8                 -lea esi, [ebp - 0x28]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004bc315  e886f8ffff             -call 0x4bbba0
    cpu.esp -= 4;
    sub_4bbba0(app, cpu);
    if (cpu.terminate) return;
    // 004bc31a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc31f  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc324  e8d7fcffff             -call 0x4bc000
    cpu.esp -= 4;
    sub_4bc000(app, cpu);
    if (cpu.terminate) return;
    // 004bc329  8d75d8                 -lea esi, [ebp - 0x28]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004bc32c  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc331  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc336  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc337  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc338  e8f3fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc33d  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc342  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bc345  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc34a  e871020100             -call 0x4cc5c0
    cpu.esp -= 4;
    sub_4cc5c0(app, cpu);
    if (cpu.terminate) return;
    // 004bc34f  e88cb30000             -call 0x4c76e0
    cpu.esp -= 4;
    sub_4c76e0(app, cpu);
    if (cpu.terminate) return;
    // 004bc354  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
L_entry_0x004bc357:
    // 004bc357  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc35c  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc361  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc362  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc363  e8c8fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc368  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc36d  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bc370  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc375  e866290200             -call 0x4dece0
    cpu.esp -= 4;
    sub_4dece0(app, cpu);
    if (cpu.terminate) return;
    // 004bc37a  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bc37d  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc382  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc387  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc388  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc389  e8a2fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc38e  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc393  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bc396  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc39b  e8502a0200             -call 0x4dedf0
    cpu.esp -= 4;
    sub_4dedf0(app, cpu);
    if (cpu.terminate) return;
    // 004bc3a0  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bc3a3  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc3a8  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3ad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3ae  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3af  e87cfcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc3b4  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3b9  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc3bc  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc3c1  e83a020100             -call 0x4cc600
    cpu.esp -= 4;
    sub_4cc600(app, cpu);
    if (cpu.terminate) return;
    // 004bc3c6  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc3c9  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc3ce  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3d3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3d4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3d5  e856fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc3da  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bc3dc  751b                   -jne 0x4bc3f9
    if (!cpu.flags.zf)
    {
        goto L_0x004bc3f9;
    }
    // 004bc3de  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
    // 004bc3e3  e888290000             -call 0x4bed70
    cpu.esp -= 4;
    sub_4bed70(app, cpu);
    if (cpu.terminate) return;
    // 004bc3e8  e8b356f7ff             -call 0x431aa0
    cpu.esp -= 4;
    sub_431aa0(app, cpu);
    if (cpu.terminate) return;
    // 004bc3ed  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3f2  e80967fcff             -call 0x482b00
    cpu.esp -= 4;
    sub_482b00(app, cpu);
    if (cpu.terminate) return;
    // 004bc3f7  eb19                   -jmp 0x4bc412
    goto L_0x004bc412;
L_0x004bc3f9:
    // 004bc3f9  83fb01                 +cmp ebx, 1
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
    // 004bc3fc  7523                   -jne 0x4bc421
    if (!cpu.flags.zf)
    {
        goto L_0x004bc421;
    }
    // 004bc3fe  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc403  e8f8fcffff             -call 0x4bc100
    cpu.esp -= 4;
    sub_4bc100(app, cpu);
    if (cpu.terminate) return;
    // 004bc408  e89356f7ff             -call 0x431aa0
    cpu.esp -= 4;
    sub_431aa0(app, cpu);
    if (cpu.terminate) return;
    // 004bc40d  e81e7cfcff             -call 0x484030
    cpu.esp -= 4;
    sub_484030(app, cpu);
    if (cpu.terminate) return;
L_0x004bc412:
    // 004bc412  e82957f7ff             -call 0x431b40
    cpu.esp -= 4;
    sub_431b40(app, cpu);
    if (cpu.terminate) return;
    // 004bc417  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc41c  e80ffdffff             -call 0x4bc130
    cpu.esp -= 4;
    sub_4bc130(app, cpu);
    if (cpu.terminate) return;
L_0x004bc421:
    // 004bc421  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bc423  7526                   -jne 0x4bc44b
    if (!cpu.flags.zf)
    {
        return sub_4bc44b(app, cpu);
    }
    // 004bc425  833da0367d0000         +cmp dword ptr [0x7d36a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8205984) /* 0x7d36a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc42c  7513                   -jne 0x4bc441
    if (!cpu.flags.zf)
    {
        goto L_0x004bc441;
    }
    // 004bc42e  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc435  750a                   -jne 0x4bc441
    if (!cpu.flags.zf)
    {
        goto L_0x004bc441;
    }
    // 004bc437  a1183d7a00             -mov eax, dword ptr [0x7a3d18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8011032) /* 0x7a3d18 */);
    // 004bc43c  e8df61fcff             -call 0x482620
    cpu.esp -= 4;
    sub_482620(app, cpu);
    if (cpu.terminate) return;
L_0x004bc441:
    // 004bc441  eb08                   -jmp 0x4bc44b
    return sub_4bc44b(app, cpu);
}

/* align: skip  */
void Application::sub_4bc2dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bc2dd;
    // 004bc2c8  90                     -nop 
    ;
    // 004bc2c9  90                     -nop 
    ;
    // 004bc2ca  90                     -nop 
    ;
    // 004bc2cb  90                     -nop 
    ;
    // 004bc2cc  90                     -nop 
    ;
    // 004bc2cd  90                     -nop 
    ;
    // 004bc2ce  90                     -nop 
    ;
    // 004bc2cf  90                     -nop 
    ;
    // 004bc2d0  90                     -nop 
    ;
    // 004bc2d1  90                     -nop 
    ;
    // 004bc2d2  90                     -nop 
    ;
    // 004bc2d3  90                     -nop 
    ;
    // 004bc2d4  90                     -nop 
    ;
    // 004bc2d5  90                     -nop 
    ;
    // 004bc2d6  90                     -nop 
    ;
    // 004bc2d7  90                     -nop 
    ;
    // 004bc2d8  90                     -nop 
    ;
    // 004bc2d9  90                     -nop 
    ;
    // 004bc2da  90                     -nop 
    ;
    // 004bc2db  90                     -nop 
    ;
    // 004bc2dc  90                     -nop 
    ;
L_entry_0x004bc2dd:
    // 004bc2dd  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc2e2  8d75d0                 -lea esi, [ebp - 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004bc2e5  e816ac0000             -call 0x4c6f00
    cpu.esp -= 4;
    sub_4c6f00(app, cpu);
    if (cpu.terminate) return;
    // 004bc2ea  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc2ef  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc2f4  e807fdffff             -call 0x4bc000
    cpu.esp -= 4;
    sub_4bc000(app, cpu);
    if (cpu.terminate) return;
    // 004bc2f9  8d75d0                 -lea esi, [ebp - 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004bc2fc  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc301  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc306  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc307  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc308  e823fdffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc30d  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc312  8d75d8                 -lea esi, [ebp - 0x28]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004bc315  e886f8ffff             -call 0x4bbba0
    cpu.esp -= 4;
    sub_4bbba0(app, cpu);
    if (cpu.terminate) return;
    // 004bc31a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc31f  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc324  e8d7fcffff             -call 0x4bc000
    cpu.esp -= 4;
    sub_4bc000(app, cpu);
    if (cpu.terminate) return;
    // 004bc329  8d75d8                 -lea esi, [ebp - 0x28]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004bc32c  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc331  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc336  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc337  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc338  e8f3fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc33d  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc342  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bc345  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc34a  e871020100             -call 0x4cc5c0
    cpu.esp -= 4;
    sub_4cc5c0(app, cpu);
    if (cpu.terminate) return;
    // 004bc34f  e88cb30000             -call 0x4c76e0
    cpu.esp -= 4;
    sub_4c76e0(app, cpu);
    if (cpu.terminate) return;
    // 004bc354  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004bc357  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc35c  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc361  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc362  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc363  e8c8fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc368  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc36d  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bc370  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc375  e866290200             -call 0x4dece0
    cpu.esp -= 4;
    sub_4dece0(app, cpu);
    if (cpu.terminate) return;
    // 004bc37a  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004bc37d  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc382  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc387  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc388  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc389  e8a2fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc38e  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc393  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bc396  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc39b  e8502a0200             -call 0x4dedf0
    cpu.esp -= 4;
    sub_4dedf0(app, cpu);
    if (cpu.terminate) return;
    // 004bc3a0  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004bc3a3  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc3a8  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3ad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3ae  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3af  e87cfcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc3b4  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3b9  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc3bc  bff03c7a00             -mov edi, 0x7a3cf0
    cpu.edi = 8010992 /*0x7a3cf0*/;
    // 004bc3c1  e83a020100             -call 0x4cc600
    cpu.esp -= 4;
    sub_4cc600(app, cpu);
    if (cpu.terminate) return;
    // 004bc3c6  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc3c9  baf03c7a00             -mov edx, 0x7a3cf0
    cpu.edx = 8010992 /*0x7a3cf0*/;
    // 004bc3ce  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3d3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3d4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bc3d5  e856fcffff             -call 0x4bc030
    cpu.esp -= 4;
    sub_4bc030(app, cpu);
    if (cpu.terminate) return;
    // 004bc3da  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bc3dc  751b                   -jne 0x4bc3f9
    if (!cpu.flags.zf)
    {
        goto L_0x004bc3f9;
    }
    // 004bc3de  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
    // 004bc3e3  e888290000             -call 0x4bed70
    cpu.esp -= 4;
    sub_4bed70(app, cpu);
    if (cpu.terminate) return;
    // 004bc3e8  e8b356f7ff             -call 0x431aa0
    cpu.esp -= 4;
    sub_431aa0(app, cpu);
    if (cpu.terminate) return;
    // 004bc3ed  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc3f2  e80967fcff             -call 0x482b00
    cpu.esp -= 4;
    sub_482b00(app, cpu);
    if (cpu.terminate) return;
    // 004bc3f7  eb19                   -jmp 0x4bc412
    goto L_0x004bc412;
L_0x004bc3f9:
    // 004bc3f9  83fb01                 +cmp ebx, 1
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
    // 004bc3fc  7523                   -jne 0x4bc421
    if (!cpu.flags.zf)
    {
        goto L_0x004bc421;
    }
    // 004bc3fe  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc403  e8f8fcffff             -call 0x4bc100
    cpu.esp -= 4;
    sub_4bc100(app, cpu);
    if (cpu.terminate) return;
    // 004bc408  e89356f7ff             -call 0x431aa0
    cpu.esp -= 4;
    sub_431aa0(app, cpu);
    if (cpu.terminate) return;
    // 004bc40d  e81e7cfcff             -call 0x484030
    cpu.esp -= 4;
    sub_484030(app, cpu);
    if (cpu.terminate) return;
L_0x004bc412:
    // 004bc412  e82957f7ff             -call 0x431b40
    cpu.esp -= 4;
    sub_431b40(app, cpu);
    if (cpu.terminate) return;
    // 004bc417  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc41c  e80ffdffff             -call 0x4bc130
    cpu.esp -= 4;
    sub_4bc130(app, cpu);
    if (cpu.terminate) return;
L_0x004bc421:
    // 004bc421  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bc423  7526                   -jne 0x4bc44b
    if (!cpu.flags.zf)
    {
        return sub_4bc44b(app, cpu);
    }
    // 004bc425  833da0367d0000         +cmp dword ptr [0x7d36a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8205984) /* 0x7d36a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc42c  7513                   -jne 0x4bc441
    if (!cpu.flags.zf)
    {
        goto L_0x004bc441;
    }
    // 004bc42e  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc435  750a                   -jne 0x4bc441
    if (!cpu.flags.zf)
    {
        goto L_0x004bc441;
    }
    // 004bc437  a1183d7a00             -mov eax, dword ptr [0x7a3d18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8011032) /* 0x7a3d18 */);
    // 004bc43c  e8df61fcff             -call 0x482620
    cpu.esp -= 4;
    sub_482620(app, cpu);
    if (cpu.terminate) return;
L_0x004bc441:
    // 004bc441  eb08                   -jmp 0x4bc44b
    return sub_4bc44b(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4bc444(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc444  90                     -nop 
    ;
    // 004bc445  90                     -nop 
    ;
    // 004bc446  90                     -nop 
    ;
    // 004bc447  90                     -nop 
    ;
    // 004bc448  90                     -nop 
    ;
    // 004bc449  90                     -nop 
    ;
    // 004bc44a  90                     -nop 
    ;
    // 004bc44b  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 004bc452  740c                   -je 0x4bc460
    if (cpu.flags.zf)
    {
        goto L_0x004bc460;
    }
    // 004bc454  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004bc459  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc45b  e8a054f7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x004bc460:
    // 004bc460  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bc462  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc463  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc464  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc465  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc466  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc467  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc468  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc44b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bc44b;
    // 004bc444  90                     -nop 
    ;
    // 004bc445  90                     -nop 
    ;
    // 004bc446  90                     -nop 
    ;
    // 004bc447  90                     -nop 
    ;
    // 004bc448  90                     -nop 
    ;
    // 004bc449  90                     -nop 
    ;
    // 004bc44a  90                     -nop 
    ;
L_entry_0x004bc44b:
    // 004bc44b  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 004bc452  740c                   -je 0x4bc460
    if (cpu.flags.zf)
    {
        goto L_0x004bc460;
    }
    // 004bc454  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004bc459  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc45b  e8a054f7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x004bc460:
    // 004bc460  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bc462  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc463  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc464  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc465  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc466  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc467  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc468  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4bc470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc473  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc475  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bc477  e8f4f8ffff             -call 0x4bbd70
    cpu.esp -= 4;
    sub_4bbd70(app, cpu);
    if (cpu.terminate) return;
    // 004bc47c  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc481  8935143d7a00           -mov dword ptr [0x7a3d14], esi
    app->getMemory<x86::reg32>(x86::reg32(8011028) /* 0x7a3d14 */) = cpu.esi;
    // 004bc487  8915183d7a00           -mov dword ptr [0x7a3d18], edx
    app->getMemory<x86::reg32>(x86::reg32(8011032) /* 0x7a3d18 */) = cpu.edx;
    // 004bc48d  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004bc490  891d7c3d7a00           -mov dword ptr [0x7a3d7c], ebx
    app->getMemory<x86::reg32>(x86::reg32(8011132) /* 0x7a3d7c */) = cpu.ebx;
    // 004bc496  8915843d7a00           -mov dword ptr [0x7a3d84], edx
    app->getMemory<x86::reg32>(x86::reg32(8011140) /* 0x7a3d84 */) = cpu.edx;
    // 004bc49c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc49e  890d803d7a00           -mov dword ptr [0x7a3d80], ecx
    app->getMemory<x86::reg32>(x86::reg32(8011136) /* 0x7a3d80 */) = cpu.ecx;
    // 004bc4a4  e8a74ff6ff             -call 0x421450
    cpu.esp -= 4;
    sub_421450(app, cpu);
    if (cpu.terminate) return;
    // 004bc4a9  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc4ae  e8ed84f7ff             -call 0x4349a0
    cpu.esp -= 4;
    sub_4349a0(app, cpu);
    if (cpu.terminate) return;
    // 004bc4b3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc4b5  7607                   -jbe 0x4bc4be
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bc4be;
    }
    // 004bc4b7  83fe01                 +cmp esi, 1
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
    // 004bc4ba  741f                   -je 0x4bc4db
    if (cpu.flags.zf)
    {
        goto L_0x004bc4db;
    }
    // 004bc4bc  eb67                   -jmp 0x4bc525
    goto L_0x004bc525;
L_0x004bc4be:
    // 004bc4be  bacdcc4c3f             -mov edx, 0x3f4ccccd
    cpu.edx = 1061997773 /*0x3f4ccccd*/;
    // 004bc4c3  b9cdcc4c3e             -mov ecx, 0x3e4ccccd
    cpu.ecx = 1045220557 /*0x3e4ccccd*/;
    // 004bc4c8  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc4cd  891594005600           -mov dword ptr [0x560094], edx
    app->getMemory<x86::reg32>(x86::reg32(5636244) /* 0x560094 */) = cpu.edx;
    // 004bc4d3  890d98005600           -mov dword ptr [0x560098], ecx
    app->getMemory<x86::reg32>(x86::reg32(5636248) /* 0x560098 */) = cpu.ecx;
    // 004bc4d9  eb18                   -jmp 0x4bc4f3
    goto L_0x004bc4f3;
L_0x004bc4db:
    // 004bc4db  bbcdcc4c3e             -mov ebx, 0x3e4ccccd
    cpu.ebx = 1045220557 /*0x3e4ccccd*/;
    // 004bc4e0  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc4e5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bc4e7  891d94005600           -mov dword ptr [0x560094], ebx
    app->getMemory<x86::reg32>(x86::reg32(5636244) /* 0x560094 */) = cpu.ebx;
    // 004bc4ed  893d98005600           -mov dword ptr [0x560098], edi
    app->getMemory<x86::reg32>(x86::reg32(5636248) /* 0x560098 */) = cpu.edi;
L_0x004bc4f3:
    // 004bc4f3  e858f6f5ff             -call 0x41bb50
    cpu.esp -= 4;
    sub_41bb50(app, cpu);
    if (cpu.terminate) return;
    // 004bc4f8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bc4fa  e861fcffff             -call 0x4bc160
    cpu.esp -= 4;
    sub_4bc160(app, cpu);
    if (cpu.terminate) return;
    // 004bc4ff  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004bc504  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc509  e8424ff6ff             -call 0x421450
    cpu.esp -= 4;
    sub_421450(app, cpu);
    if (cpu.terminate) return;
    // 004bc50e  a1f43c7a00             -mov eax, dword ptr [0x7a3cf4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8010996) /* 0x7a3cf4 */);
    // 004bc513  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bc514  8b15f03c7a00           -mov edx, dword ptr [0x7a3cf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8010992) /* 0x7a3cf0 */);
    // 004bc51a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc51b  b8143d7a00             -mov eax, 0x7a3d14
    cpu.eax = 8011028 /*0x7a3d14*/;
    // 004bc520  e8ab84f7ff             -call 0x4349d0
    cpu.esp -= 4;
    sub_4349d0(app, cpu);
    if (cpu.terminate) return;
L_0x004bc525:
    // 004bc525  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc526  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc527  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc528  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4bc530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc530  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc531  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc532  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc533  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc534  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc536  bbfc3c7a00             -mov ebx, 0x7a3cfc
    cpu.ebx = 8011004 /*0x7a3cfc*/;
    // 004bc53b  b8003d7a00             -mov eax, 0x7a3d00
    cpu.eax = 8011008 /*0x7a3d00*/;
    // 004bc540  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc542  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc544  89153cfe5500           -mov dword ptr [0x55fe3c], edx
    app->getMemory<x86::reg32>(x86::reg32(5635644) /* 0x55fe3c */) = cpu.edx;
    // 004bc54a  baf83c7a00             -mov edx, 0x7a3cf8
    cpu.edx = 8011000 /*0x7a3cf8*/;
    // 004bc54f  e8bc8df7ff             -call 0x435310
    cpu.esp -= 4;
    sub_435310(app, cpu);
    if (cpu.terminate) return;
    // 004bc554  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc555  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc556  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc557  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc558  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4bc560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc562  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc563  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc564  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc566  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc569  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
    // 004bc56e  8d5df8                 -lea ebx, [ebp - 8]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc571  8d55f4                 -lea edx, [ebp - 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bc574  e8f7270000             -call 0x4bed70
    cpu.esp -= 4;
    sub_4bed70(app, cpu);
    if (cpu.terminate) return;
    // 004bc579  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc57b  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bc57e  e88d8df7ff             -call 0x435310
    cpu.esp -= 4;
    sub_435310(app, cpu);
    if (cpu.terminate) return;
    // 004bc583  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bc586  2b05f83c7a00           -sub eax, dword ptr [0x7a3cf8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(8011000) /* 0x7a3cf8 */)));
    // 004bc58c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bc58e  7f02                   -jg 0x4bc592
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc592;
    }
    // 004bc590  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004bc592:
    // 004bc592  8b0dfc3c7a00           -mov ecx, dword ptr [0x7a3cfc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8011004) /* 0x7a3cfc */);
    // 004bc598  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc59a  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc59d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc59f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bc5a1  7f02                   -jg 0x4bc5a5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc5a5;
    }
    // 004bc5a3  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004bc5a5:
    // 004bc5a5  83fa01                 +cmp edx, 1
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
    // 004bc5a8  7f10                   -jg 0x4bc5ba
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc5ba;
    }
    // 004bc5aa  83f801                 +cmp eax, 1
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
    // 004bc5ad  7f0b                   -jg 0x4bc5ba
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc5ba;
    }
    // 004bc5af  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bc5b2  3b1d003d7a00           +cmp ebx, dword ptr [0x7a3d00]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(8011008) /* 0x7a3d00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc5b8  7429                   -je 0x4bc5e3
    if (cpu.flags.zf)
    {
        goto L_0x004bc5e3;
    }
L_0x004bc5ba:
    // 004bc5ba  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004bc5bf  0580020000             +add eax, 0x280
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(640 /*0x280*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc5c4  a33cfe5500             -mov dword ptr [0x55fe3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5635644) /* 0x55fe3c */) = cpu.eax;
    // 004bc5c9  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bc5cc  a3f83c7a00             -mov dword ptr [0x7a3cf8], eax
    app->getMemory<x86::reg32>(x86::reg32(8011000) /* 0x7a3cf8 */) = cpu.eax;
    // 004bc5d1  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bc5d4  a3fc3c7a00             -mov dword ptr [0x7a3cfc], eax
    app->getMemory<x86::reg32>(x86::reg32(8011004) /* 0x7a3cfc */) = cpu.eax;
    // 004bc5d9  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bc5dc  a3003d7a00             -mov dword ptr [0x7a3d00], eax
    app->getMemory<x86::reg32>(x86::reg32(8011008) /* 0x7a3d00 */) = cpu.eax;
    // 004bc5e1  eb1d                   -jmp 0x4bc600
    goto L_0x004bc600;
L_0x004bc5e3:
    // 004bc5e3  833d3cfe550000         +cmp dword ptr [0x55fe3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5635644) /* 0x55fe3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc5ea  7414                   -je 0x4bc600
    if (cpu.flags.zf)
    {
        goto L_0x004bc600;
    }
    // 004bc5ec  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004bc5f1  3b053cfe5500           +cmp eax, dword ptr [0x55fe3c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5635644) /* 0x55fe3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc5f7  7c07                   -jl 0x4bc600
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc600;
    }
    // 004bc5f9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc5fb  a33cfe5500             -mov dword ptr [0x55fe3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5635644) /* 0x55fe3c */) = cpu.eax;
L_0x004bc600:
    // 004bc600  833d3cfe550000         +cmp dword ptr [0x55fe3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5635644) /* 0x55fe3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc607  740d                   -je 0x4bc616
    if (cpu.flags.zf)
    {
        goto L_0x004bc616;
    }
    // 004bc609  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc60b  890d3c3d5600           -mov dword ptr [0x563d3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5651772) /* 0x563d3c */) = cpu.ecx;
    // 004bc611  e84a85f7ff             -call 0x434b60
    cpu.esp -= 4;
    sub_434b60(app, cpu);
    if (cpu.terminate) return;
L_0x004bc616:
    // 004bc616  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bc618  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc619  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc61a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc61b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc61c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bc620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc620  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc621  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc622  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc624  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bc626  7507                   -jne 0x4bc62f
    if (!cpu.flags.zf)
    {
        goto L_0x004bc62f;
    }
    // 004bc628  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bc62d  eb02                   -jmp 0x4bc631
    goto L_0x004bc631;
L_0x004bc62f:
    // 004bc62f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bc631:
    // 004bc631  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bc633  7507                   -jne 0x4bc63c
    if (!cpu.flags.zf)
    {
        goto L_0x004bc63c;
    }
    // 004bc635  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc63a  eb02                   -jmp 0x4bc63e
    goto L_0x004bc63e;
L_0x004bc63c:
    // 004bc63c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bc63e:
    // 004bc63e  e8bd83f7ff             -call 0x434a00
    cpu.esp -= 4;
    sub_434a00(app, cpu);
    if (cpu.terminate) return;
    // 004bc643  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc644  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc645  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4bc650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc650  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc651  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc653  e83883f7ff             -call 0x434990
    cpu.esp -= 4;
    sub_434990(app, cpu);
    if (cpu.terminate) return;
    // 004bc658  e81384f7ff             -call 0x434a70
    cpu.esp -= 4;
    sub_434a70(app, cpu);
    if (cpu.terminate) return;
    // 004bc65d  e8beb5ffff             -call 0x4b7c20
    cpu.esp -= 4;
    sub_4b7c20(app, cpu);
    if (cpu.terminate) return;
    // 004bc662  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc663  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc664(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc664  90                     -nop 
    ;
    // 004bc665  90                     -nop 
    ;
    // 004bc666  90                     -nop 
    ;
    // 004bc667  90                     -nop 
    ;
    // 004bc668  90                     -nop 
    ;
    // 004bc669  90                     -nop 
    ;
    // 004bc66a  90                     -nop 
    ;
    // 004bc66b  90                     -nop 
    ;
    // 004bc66c  90                     -nop 
    ;
    // 004bc66d  90                     -nop 
    ;
    // 004bc66e  90                     -nop 
    ;
    // 004bc66f  90                     -nop 
    ;
    // 004bc670  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc671  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc673  e89898f8ff             -call 0x445f10
    cpu.esp -= 4;
    sub_445f10(app, cpu);
    if (cpu.terminate) return;
    // 004bc678  e8b3feffff             -call 0x4bc530
    cpu.esp -= 4;
    sub_4bc530(app, cpu);
    if (cpu.terminate) return;
    // 004bc67d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc67e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bc670;
    // 004bc664  90                     -nop 
    ;
    // 004bc665  90                     -nop 
    ;
    // 004bc666  90                     -nop 
    ;
    // 004bc667  90                     -nop 
    ;
    // 004bc668  90                     -nop 
    ;
    // 004bc669  90                     -nop 
    ;
    // 004bc66a  90                     -nop 
    ;
    // 004bc66b  90                     -nop 
    ;
    // 004bc66c  90                     -nop 
    ;
    // 004bc66d  90                     -nop 
    ;
    // 004bc66e  90                     -nop 
    ;
    // 004bc66f  90                     -nop 
    ;
L_entry_0x004bc670:
    // 004bc670  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc671  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc673  e89898f8ff             -call 0x445f10
    cpu.esp -= 4;
    sub_445f10(app, cpu);
    if (cpu.terminate) return;
    // 004bc678  e8b3feffff             -call 0x4bc530
    cpu.esp -= 4;
    sub_4bc530(app, cpu);
    if (cpu.terminate) return;
    // 004bc67d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc67e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bc680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc681  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc682  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc683  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc684  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc685  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc687  9b                     -wait 
    /*nothing*/;
    // 004bc688  dbe3                   +fninit 
    cpu.fpu.init();
    // 004bc68a  9b                     -wait 
    /*nothing*/;
    // 004bc68b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bc68d  eb18                   -jmp 0x4bc6a7
    return sub_4bc6a7(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4bc690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc690  90                     -nop 
    ;
    // 004bc691  90                     -nop 
    ;
    // 004bc692  90                     -nop 
    ;
    // 004bc693  90                     -nop 
    ;
    // 004bc694  90                     -nop 
    ;
    // 004bc695  90                     -nop 
    ;
    // 004bc696  90                     -nop 
    ;
    // 004bc697  90                     -nop 
    ;
    // 004bc698  90                     -nop 
    ;
    // 004bc699  90                     -nop 
    ;
    // 004bc69a  90                     -nop 
    ;
    // 004bc69b  90                     -nop 
    ;
    // 004bc69c  90                     -nop 
    ;
    // 004bc69d  90                     -nop 
    ;
    // 004bc69e  90                     -nop 
    ;
    // 004bc69f  90                     -nop 
    ;
    // 004bc6a0  90                     -nop 
    ;
    // 004bc6a1  90                     -nop 
    ;
    // 004bc6a2  90                     -nop 
    ;
    // 004bc6a3  90                     -nop 
    ;
    // 004bc6a4  90                     -nop 
    ;
    // 004bc6a5  90                     -nop 
    ;
    // 004bc6a6  90                     -nop 
    ;
    // 004bc6a7  e89454f7ff             -call 0x431b40
    cpu.esp -= 4;
    sub_431b40(app, cpu);
    if (cpu.terminate) return;
    // 004bc6ac  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004bc6b3  753a                   -jne 0x4bc6ef
    if (!cpu.flags.zf)
    {
        goto L_0x004bc6ef;
    }
    // 004bc6b5  a1103d7a00             -mov eax, dword ptr [0x7a3d10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
    // 004bc6ba  e861ffffff             -call 0x4bc620
    cpu.esp -= 4;
    sub_4bc620(app, cpu);
    if (cpu.terminate) return;
    // 004bc6bf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc6c1  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
    // 004bc6c6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc6c8  e8a3260000             -call 0x4bed70
    cpu.esp -= 4;
    sub_4bed70(app, cpu);
    if (cpu.terminate) return;
    // 004bc6cd  e80e220000             -call 0x4be8e0
    cpu.esp -= 4;
    sub_4be8e0(app, cpu);
    if (cpu.terminate) return;
    // 004bc6d2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc6d4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc6d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc6d8  e893fdffff             -call 0x4bc470
    cpu.esp -= 4;
    sub_4bc470(app, cpu);
    if (cpu.terminate) return;
    // 004bc6dd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc6df  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bc6e4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc6e6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc6e8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bc6ea  e983000000             -jmp 0x4bc772
    goto L_0x004bc772;
L_0x004bc6ef:
    // 004bc6ef  a1103d7a00             -mov eax, dword ptr [0x7a3d10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
    // 004bc6f4  e827ffffff             -call 0x4bc620
    cpu.esp -= 4;
    sub_4bc620(app, cpu);
    if (cpu.terminate) return;
    // 004bc6f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc6fb  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
    // 004bc700  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc702  e869260000             -call 0x4bed70
    cpu.esp -= 4;
    sub_4bed70(app, cpu);
    if (cpu.terminate) return;
    // 004bc707  e8d4210000             -call 0x4be8e0
    cpu.esp -= 4;
    sub_4be8e0(app, cpu);
    if (cpu.terminate) return;
    // 004bc70c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc70e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc710  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc712  e859fdffff             -call 0x4bc470
    cpu.esp -= 4;
    sub_4bc470(app, cpu);
    if (cpu.terminate) return;
    // 004bc717  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc71e  7409                   -je 0x4bc729
    if (cpu.flags.zf)
    {
        goto L_0x004bc729;
    }
    // 004bc720  833d6492550000         +cmp dword ptr [0x559264], 0
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
    // 004bc727  744e                   -je 0x4bc777
    if (cpu.flags.zf)
    {
        goto L_0x004bc777;
    }
L_0x004bc729:
    // 004bc729  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc72b  e8a064f6ff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 004bc730  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 004bc737  7407                   -je 0x4bc740
    if (cpu.flags.zf)
    {
        goto L_0x004bc740;
    }
    // 004bc739  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc73e  eb02                   -jmp 0x4bc742
    goto L_0x004bc742;
L_0x004bc740:
    // 004bc740  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bc742:
    // 004bc742  69c0a4010000           -imul eax, eax, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 004bc748  83b85cbc6f0000         +cmp dword ptr [eax + 0x6fbc5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7322716) /* 0x6fbc5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc74f  740b                   -je 0x4bc75c
    if (cpu.flags.zf)
    {
        goto L_0x004bc75c;
    }
    // 004bc751  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc753  e84863f6ff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 004bc758  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bc75a  7509                   -jne 0x4bc765
    if (!cpu.flags.zf)
    {
        goto L_0x004bc765;
    }
L_0x004bc75c:
    // 004bc75c  833d6492550000         +cmp dword ptr [0x559264], 0
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
    // 004bc763  7412                   -je 0x4bc777
    if (cpu.flags.zf)
    {
        goto L_0x004bc777;
    }
L_0x004bc765:
    // 004bc765  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc767  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc76c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc76e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc770  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bc772:
    // 004bc772  e8f9fcffff             -call 0x4bc470
    cpu.esp -= 4;
    sub_4bc470(app, cpu);
    if (cpu.terminate) return;
L_0x004bc777:
    // 004bc777  e8d4feffff             -call 0x4bc650
    cpu.esp -= 4;
    sub_4bc650(app, cpu);
    if (cpu.terminate) return;
    // 004bc77c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc77e  743c                   -je 0x4bc7bc
    if (cpu.flags.zf)
    {
        goto L_0x004bc7bc;
    }
    // 004bc780  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc787  750f                   -jne 0x4bc798
    if (!cpu.flags.zf)
    {
        goto L_0x004bc798;
    }
    // 004bc789  c705103d7a0001000000   -mov dword ptr [0x7a3d10], 1
    app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */) = 1 /*0x1*/;
    // 004bc793  e898f2f8ff             -call 0x44ba30
    cpu.esp -= 4;
    sub_44ba30(app, cpu);
    if (cpu.terminate) return;
L_0x004bc798:
    // 004bc798  e88383f7ff             -call 0x434b20
    cpu.esp -= 4;
    sub_434b20(app, cpu);
    if (cpu.terminate) return;
    // 004bc79d  e84e53f7ff             -call 0x431af0
    cpu.esp -= 4;
    sub_431af0(app, cpu);
    if (cpu.terminate) return;
    // 004bc7a2  833dfc00560000         +cmp dword ptr [0x5600fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5636348) /* 0x5600fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc7a9  7505                   -jne 0x4bc7b0
    if (!cpu.flags.zf)
    {
        goto L_0x004bc7b0;
    }
    // 004bc7ab  e820f6f8ff             -call 0x44bdd0
    cpu.esp -= 4;
    sub_44bdd0(app, cpu);
    if (cpu.terminate) return;
L_0x004bc7b0:
    // 004bc7b0  e88b83f7ff             -call 0x434b40
    cpu.esp -= 4;
    sub_434b40(app, cpu);
    if (cpu.terminate) return;
    // 004bc7b5  e88653f7ff             -call 0x431b40
    cpu.esp -= 4;
    sub_431b40(app, cpu);
    if (cpu.terminate) return;
    // 004bc7ba  eb14                   -jmp 0x4bc7d0
    goto L_0x004bc7d0;
L_0x004bc7bc:
    // 004bc7bc  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc7c3  740b                   -je 0x4bc7d0
    if (cpu.flags.zf)
    {
        goto L_0x004bc7d0;
    }
    // 004bc7c5  8935103d7a00           -mov dword ptr [0x7a3d10], esi
    app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */) = cpu.esi;
    // 004bc7cb  e8a0feffff             -call 0x4bc670
    cpu.esp -= 4;
    sub_4bc670(app, cpu);
    if (cpu.terminate) return;
L_0x004bc7d0:
    // 004bc7d0  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc7d7  7505                   -jne 0x4bc7de
    if (!cpu.flags.zf)
    {
        goto L_0x004bc7de;
    }
    // 004bc7d9  e882fdffff             -call 0x4bc560
    cpu.esp -= 4;
    sub_4bc560(app, cpu);
    if (cpu.terminate) return;
L_0x004bc7de:
    // 004bc7de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc6a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bc6a7;
    // 004bc690  90                     -nop 
    ;
    // 004bc691  90                     -nop 
    ;
    // 004bc692  90                     -nop 
    ;
    // 004bc693  90                     -nop 
    ;
    // 004bc694  90                     -nop 
    ;
    // 004bc695  90                     -nop 
    ;
    // 004bc696  90                     -nop 
    ;
    // 004bc697  90                     -nop 
    ;
    // 004bc698  90                     -nop 
    ;
    // 004bc699  90                     -nop 
    ;
    // 004bc69a  90                     -nop 
    ;
    // 004bc69b  90                     -nop 
    ;
    // 004bc69c  90                     -nop 
    ;
    // 004bc69d  90                     -nop 
    ;
    // 004bc69e  90                     -nop 
    ;
    // 004bc69f  90                     -nop 
    ;
    // 004bc6a0  90                     -nop 
    ;
    // 004bc6a1  90                     -nop 
    ;
    // 004bc6a2  90                     -nop 
    ;
    // 004bc6a3  90                     -nop 
    ;
    // 004bc6a4  90                     -nop 
    ;
    // 004bc6a5  90                     -nop 
    ;
    // 004bc6a6  90                     -nop 
    ;
L_entry_0x004bc6a7:
    // 004bc6a7  e89454f7ff             -call 0x431b40
    cpu.esp -= 4;
    sub_431b40(app, cpu);
    if (cpu.terminate) return;
    // 004bc6ac  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004bc6b3  753a                   -jne 0x4bc6ef
    if (!cpu.flags.zf)
    {
        goto L_0x004bc6ef;
    }
    // 004bc6b5  a1103d7a00             -mov eax, dword ptr [0x7a3d10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
    // 004bc6ba  e861ffffff             -call 0x4bc620
    cpu.esp -= 4;
    sub_4bc620(app, cpu);
    if (cpu.terminate) return;
    // 004bc6bf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc6c1  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
    // 004bc6c6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc6c8  e8a3260000             -call 0x4bed70
    cpu.esp -= 4;
    sub_4bed70(app, cpu);
    if (cpu.terminate) return;
    // 004bc6cd  e80e220000             -call 0x4be8e0
    cpu.esp -= 4;
    sub_4be8e0(app, cpu);
    if (cpu.terminate) return;
    // 004bc6d2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc6d4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc6d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc6d8  e893fdffff             -call 0x4bc470
    cpu.esp -= 4;
    sub_4bc470(app, cpu);
    if (cpu.terminate) return;
    // 004bc6dd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc6df  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bc6e4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc6e6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc6e8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bc6ea  e983000000             -jmp 0x4bc772
    goto L_0x004bc772;
L_0x004bc6ef:
    // 004bc6ef  a1103d7a00             -mov eax, dword ptr [0x7a3d10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
    // 004bc6f4  e827ffffff             -call 0x4bc620
    cpu.esp -= 4;
    sub_4bc620(app, cpu);
    if (cpu.terminate) return;
    // 004bc6f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc6fb  b8c0da7c00             -mov eax, 0x7cdac0
    cpu.eax = 8182464 /*0x7cdac0*/;
    // 004bc700  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc702  e869260000             -call 0x4bed70
    cpu.esp -= 4;
    sub_4bed70(app, cpu);
    if (cpu.terminate) return;
    // 004bc707  e8d4210000             -call 0x4be8e0
    cpu.esp -= 4;
    sub_4be8e0(app, cpu);
    if (cpu.terminate) return;
    // 004bc70c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc70e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc710  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc712  e859fdffff             -call 0x4bc470
    cpu.esp -= 4;
    sub_4bc470(app, cpu);
    if (cpu.terminate) return;
    // 004bc717  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc71e  7409                   -je 0x4bc729
    if (cpu.flags.zf)
    {
        goto L_0x004bc729;
    }
    // 004bc720  833d6492550000         +cmp dword ptr [0x559264], 0
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
    // 004bc727  744e                   -je 0x4bc777
    if (cpu.flags.zf)
    {
        goto L_0x004bc777;
    }
L_0x004bc729:
    // 004bc729  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc72b  e8a064f6ff             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 004bc730  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 004bc737  7407                   -je 0x4bc740
    if (cpu.flags.zf)
    {
        goto L_0x004bc740;
    }
    // 004bc739  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc73e  eb02                   -jmp 0x4bc742
    goto L_0x004bc742;
L_0x004bc740:
    // 004bc740  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bc742:
    // 004bc742  69c0a4010000           -imul eax, eax, 0x1a4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 004bc748  83b85cbc6f0000         +cmp dword ptr [eax + 0x6fbc5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7322716) /* 0x6fbc5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc74f  740b                   -je 0x4bc75c
    if (cpu.flags.zf)
    {
        goto L_0x004bc75c;
    }
    // 004bc751  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc753  e84863f6ff             -call 0x422aa0
    cpu.esp -= 4;
    sub_422aa0(app, cpu);
    if (cpu.terminate) return;
    // 004bc758  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bc75a  7509                   -jne 0x4bc765
    if (!cpu.flags.zf)
    {
        goto L_0x004bc765;
    }
L_0x004bc75c:
    // 004bc75c  833d6492550000         +cmp dword ptr [0x559264], 0
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
    // 004bc763  7412                   -je 0x4bc777
    if (cpu.flags.zf)
    {
        goto L_0x004bc777;
    }
L_0x004bc765:
    // 004bc765  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc767  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bc76c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc76e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc770  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bc772:
    // 004bc772  e8f9fcffff             -call 0x4bc470
    cpu.esp -= 4;
    sub_4bc470(app, cpu);
    if (cpu.terminate) return;
L_0x004bc777:
    // 004bc777  e8d4feffff             -call 0x4bc650
    cpu.esp -= 4;
    sub_4bc650(app, cpu);
    if (cpu.terminate) return;
    // 004bc77c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc77e  743c                   -je 0x4bc7bc
    if (cpu.flags.zf)
    {
        goto L_0x004bc7bc;
    }
    // 004bc780  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc787  750f                   -jne 0x4bc798
    if (!cpu.flags.zf)
    {
        goto L_0x004bc798;
    }
    // 004bc789  c705103d7a0001000000   -mov dword ptr [0x7a3d10], 1
    app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */) = 1 /*0x1*/;
    // 004bc793  e898f2f8ff             -call 0x44ba30
    cpu.esp -= 4;
    sub_44ba30(app, cpu);
    if (cpu.terminate) return;
L_0x004bc798:
    // 004bc798  e88383f7ff             -call 0x434b20
    cpu.esp -= 4;
    sub_434b20(app, cpu);
    if (cpu.terminate) return;
    // 004bc79d  e84e53f7ff             -call 0x431af0
    cpu.esp -= 4;
    sub_431af0(app, cpu);
    if (cpu.terminate) return;
    // 004bc7a2  833dfc00560000         +cmp dword ptr [0x5600fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5636348) /* 0x5600fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc7a9  7505                   -jne 0x4bc7b0
    if (!cpu.flags.zf)
    {
        goto L_0x004bc7b0;
    }
    // 004bc7ab  e820f6f8ff             -call 0x44bdd0
    cpu.esp -= 4;
    sub_44bdd0(app, cpu);
    if (cpu.terminate) return;
L_0x004bc7b0:
    // 004bc7b0  e88b83f7ff             -call 0x434b40
    cpu.esp -= 4;
    sub_434b40(app, cpu);
    if (cpu.terminate) return;
    // 004bc7b5  e88653f7ff             -call 0x431b40
    cpu.esp -= 4;
    sub_431b40(app, cpu);
    if (cpu.terminate) return;
    // 004bc7ba  eb14                   -jmp 0x4bc7d0
    goto L_0x004bc7d0;
L_0x004bc7bc:
    // 004bc7bc  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc7c3  740b                   -je 0x4bc7d0
    if (cpu.flags.zf)
    {
        goto L_0x004bc7d0;
    }
    // 004bc7c5  8935103d7a00           -mov dword ptr [0x7a3d10], esi
    app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */) = cpu.esi;
    // 004bc7cb  e8a0feffff             -call 0x4bc670
    cpu.esp -= 4;
    sub_4bc670(app, cpu);
    if (cpu.terminate) return;
L_0x004bc7d0:
    // 004bc7d0  833d103d7a0000         +cmp dword ptr [0x7a3d10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc7d7  7505                   -jne 0x4bc7de
    if (!cpu.flags.zf)
    {
        goto L_0x004bc7de;
    }
    // 004bc7d9  e882fdffff             -call 0x4bc560
    cpu.esp -= 4;
    sub_4bc560(app, cpu);
    if (cpu.terminate) return;
L_0x004bc7de:
    // 004bc7de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc7e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc7e4  90                     -nop 
    ;
    // 004bc7e5  90                     -nop 
    ;
    // 004bc7e6  90                     -nop 
    ;
    // 004bc7e7  90                     -nop 
    ;
    // 004bc7e8  90                     -nop 
    ;
    // 004bc7e9  90                     -nop 
    ;
    // 004bc7ea  90                     -nop 
    ;
    // 004bc7eb  90                     -nop 
    ;
    // 004bc7ec  90                     -nop 
    ;
    // 004bc7ed  90                     -nop 
    ;
    // 004bc7ee  90                     -nop 
    ;
    // 004bc7ef  90                     -nop 
    ;
    // 004bc7f0  90                     -nop 
    ;
    // 004bc7f1  90                     -nop 
    ;
    // 004bc7f2  90                     -nop 
    ;
    // 004bc7f3  90                     -nop 
    ;
    // 004bc7f4  90                     -nop 
    ;
    // 004bc7f5  90                     -nop 
    ;
    // 004bc7f6  90                     -nop 
    ;
    // 004bc7f7  90                     -nop 
    ;
    // 004bc7f8  90                     -nop 
    ;
    // 004bc7f9  90                     -nop 
    ;
    // 004bc7fa  90                     -nop 
    ;
    // 004bc7fb  90                     -nop 
    ;
    // 004bc7fc  90                     -nop 
    ;
    // 004bc7fd  90                     -nop 
    ;
    // 004bc7fe  90                     -nop 
    ;
    // 004bc7ff  90                     -nop 
    ;
    // 004bc800  90                     -nop 
    ;
    // 004bc801  90                     -nop 
    ;
    // 004bc802  90                     -nop 
    ;
    // 004bc803  90                     -nop 
    ;
    // 004bc804  90                     -nop 
    ;
    // 004bc805  90                     -nop 
    ;
    // 004bc806  90                     -nop 
    ;
    // 004bc807  90                     -nop 
    ;
    // 004bc808  90                     -nop 
    ;
    // 004bc809  90                     -nop 
    ;
    // 004bc80a  90                     -nop 
    ;
    // 004bc80b  90                     -nop 
    ;
    // 004bc80c  90                     -nop 
    ;
    // 004bc80d  90                     -nop 
    ;
    // 004bc80e  90                     -nop 
    ;
    // 004bc80f  90                     -nop 
    ;
    // 004bc810  90                     -nop 
    ;
    // 004bc811  90                     -nop 
    ;
    // 004bc812  90                     -nop 
    ;
    // 004bc813  90                     -nop 
    ;
    // 004bc814  90                     -nop 
    ;
    // 004bc815  90                     -nop 
    ;
    // 004bc816  90                     -nop 
    ;
    // 004bc817  90                     -nop 
    ;
    // 004bc818  90                     -nop 
    ;
    // 004bc819  90                     -nop 
    ;
    // 004bc81a  90                     -nop 
    ;
    // 004bc81b  90                     -nop 
    ;
    // 004bc81c  90                     -nop 
    ;
    // 004bc81d  90                     -nop 
    ;
    // 004bc81e  90                     -nop 
    ;
    // 004bc81f  90                     -nop 
    ;
    // 004bc820  90                     -nop 
    ;
    // 004bc821  90                     -nop 
    ;
    // 004bc822  90                     -nop 
    ;
    // 004bc823  90                     -nop 
    ;
    // 004bc824  90                     -nop 
    ;
    // 004bc825  90                     -nop 
    ;
    // 004bc826  90                     -nop 
    ;
    // 004bc827  90                     -nop 
    ;
    // 004bc828  90                     -nop 
    ;
    // 004bc829  90                     -nop 
    ;
    // 004bc82a  90                     -nop 
    ;
    // 004bc82b  90                     -nop 
    ;
    // 004bc82c  90                     -nop 
    ;
    // 004bc82d  90                     -nop 
    ;
    // 004bc82e  90                     -nop 
    ;
    // 004bc82f  90                     -nop 
    ;
    // 004bc830  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc831  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc833  e8284bf6ff             -call 0x421360
    cpu.esp -= 4;
    sub_421360(app, cpu);
    if (cpu.terminate) return;
    // 004bc838  e8936bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc83d  e8aea80000             -call 0x4c70f0
    cpu.esp -= 4;
    sub_4c70f0(app, cpu);
    if (cpu.terminate) return;
    // 004bc842  e8896bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc847  e854f30100             -call 0x4dbba0
    cpu.esp -= 4;
    sub_4dbba0(app, cpu);
    if (cpu.terminate) return;
    // 004bc84c  e87f6bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc851  e81a78fcff             -call 0x484070
    cpu.esp -= 4;
    sub_484070(app, cpu);
    if (cpu.terminate) return;
    // 004bc856  e8756bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc85b  e810ee0000             -call 0x4cb670
    cpu.esp -= 4;
    sub_4cb670(app, cpu);
    if (cpu.terminate) return;
    // 004bc860  e86b6bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc865  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc866  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bc830;
    // 004bc7e4  90                     -nop 
    ;
    // 004bc7e5  90                     -nop 
    ;
    // 004bc7e6  90                     -nop 
    ;
    // 004bc7e7  90                     -nop 
    ;
    // 004bc7e8  90                     -nop 
    ;
    // 004bc7e9  90                     -nop 
    ;
    // 004bc7ea  90                     -nop 
    ;
    // 004bc7eb  90                     -nop 
    ;
    // 004bc7ec  90                     -nop 
    ;
    // 004bc7ed  90                     -nop 
    ;
    // 004bc7ee  90                     -nop 
    ;
    // 004bc7ef  90                     -nop 
    ;
    // 004bc7f0  90                     -nop 
    ;
    // 004bc7f1  90                     -nop 
    ;
    // 004bc7f2  90                     -nop 
    ;
    // 004bc7f3  90                     -nop 
    ;
    // 004bc7f4  90                     -nop 
    ;
    // 004bc7f5  90                     -nop 
    ;
    // 004bc7f6  90                     -nop 
    ;
    // 004bc7f7  90                     -nop 
    ;
    // 004bc7f8  90                     -nop 
    ;
    // 004bc7f9  90                     -nop 
    ;
    // 004bc7fa  90                     -nop 
    ;
    // 004bc7fb  90                     -nop 
    ;
    // 004bc7fc  90                     -nop 
    ;
    // 004bc7fd  90                     -nop 
    ;
    // 004bc7fe  90                     -nop 
    ;
    // 004bc7ff  90                     -nop 
    ;
    // 004bc800  90                     -nop 
    ;
    // 004bc801  90                     -nop 
    ;
    // 004bc802  90                     -nop 
    ;
    // 004bc803  90                     -nop 
    ;
    // 004bc804  90                     -nop 
    ;
    // 004bc805  90                     -nop 
    ;
    // 004bc806  90                     -nop 
    ;
    // 004bc807  90                     -nop 
    ;
    // 004bc808  90                     -nop 
    ;
    // 004bc809  90                     -nop 
    ;
    // 004bc80a  90                     -nop 
    ;
    // 004bc80b  90                     -nop 
    ;
    // 004bc80c  90                     -nop 
    ;
    // 004bc80d  90                     -nop 
    ;
    // 004bc80e  90                     -nop 
    ;
    // 004bc80f  90                     -nop 
    ;
    // 004bc810  90                     -nop 
    ;
    // 004bc811  90                     -nop 
    ;
    // 004bc812  90                     -nop 
    ;
    // 004bc813  90                     -nop 
    ;
    // 004bc814  90                     -nop 
    ;
    // 004bc815  90                     -nop 
    ;
    // 004bc816  90                     -nop 
    ;
    // 004bc817  90                     -nop 
    ;
    // 004bc818  90                     -nop 
    ;
    // 004bc819  90                     -nop 
    ;
    // 004bc81a  90                     -nop 
    ;
    // 004bc81b  90                     -nop 
    ;
    // 004bc81c  90                     -nop 
    ;
    // 004bc81d  90                     -nop 
    ;
    // 004bc81e  90                     -nop 
    ;
    // 004bc81f  90                     -nop 
    ;
    // 004bc820  90                     -nop 
    ;
    // 004bc821  90                     -nop 
    ;
    // 004bc822  90                     -nop 
    ;
    // 004bc823  90                     -nop 
    ;
    // 004bc824  90                     -nop 
    ;
    // 004bc825  90                     -nop 
    ;
    // 004bc826  90                     -nop 
    ;
    // 004bc827  90                     -nop 
    ;
    // 004bc828  90                     -nop 
    ;
    // 004bc829  90                     -nop 
    ;
    // 004bc82a  90                     -nop 
    ;
    // 004bc82b  90                     -nop 
    ;
    // 004bc82c  90                     -nop 
    ;
    // 004bc82d  90                     -nop 
    ;
    // 004bc82e  90                     -nop 
    ;
    // 004bc82f  90                     -nop 
    ;
L_entry_0x004bc830:
    // 004bc830  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc831  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc833  e8284bf6ff             -call 0x421360
    cpu.esp -= 4;
    sub_421360(app, cpu);
    if (cpu.terminate) return;
    // 004bc838  e8936bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc83d  e8aea80000             -call 0x4c70f0
    cpu.esp -= 4;
    sub_4c70f0(app, cpu);
    if (cpu.terminate) return;
    // 004bc842  e8896bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc847  e854f30100             -call 0x4dbba0
    cpu.esp -= 4;
    sub_4dbba0(app, cpu);
    if (cpu.terminate) return;
    // 004bc84c  e87f6bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc851  e81a78fcff             -call 0x484070
    cpu.esp -= 4;
    sub_484070(app, cpu);
    if (cpu.terminate) return;
    // 004bc856  e8756bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc85b  e810ee0000             -call 0x4cb670
    cpu.esp -= 4;
    sub_4cb670(app, cpu);
    if (cpu.terminate) return;
    // 004bc860  e86b6bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc865  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc866  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4bc870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc870  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc871  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc873  e80882f7ff             -call 0x434a80
    cpu.esp -= 4;
    sub_434a80(app, cpu);
    if (cpu.terminate) return;
    // 004bc878  e8536bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc87d  e8ceeafbff             -call 0x47b350
    cpu.esp -= 4;
    sub_47b350(app, cpu);
    if (cpu.terminate) return;
    // 004bc882  e8496bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc887  e864050200             -call 0x4dcdf0
    cpu.esp -= 4;
    sub_4dcdf0(app, cpu);
    if (cpu.terminate) return;
    // 004bc88c  e83f6bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc891  e87ab20000             -call 0x4c7b10
    cpu.esp -= 4;
    sub_4c7b10(app, cpu);
    if (cpu.terminate) return;
    // 004bc896  e8356bfeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc89b  e890fcffff             -call 0x4bc530
    cpu.esp -= 4;
    sub_4bc530(app, cpu);
    if (cpu.terminate) return;
    // 004bc8a0  e8cbf4ffff             -call 0x4bbd70
    cpu.esp -= 4;
    sub_4bbd70(app, cpu);
    if (cpu.terminate) return;
    // 004bc8a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc8a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4bc8b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc8b0  90                     -nop 
    ;
    // 004bc8b1  90                     -nop 
    ;
    // 004bc8b2  90                     -nop 
    ;
    // 004bc8b3  90                     -nop 
    ;
    // 004bc8b4  90                     -nop 
    ;
    // 004bc8b5  90                     -nop 
    ;
    // 004bc8b6  90                     -nop 
    ;
    // 004bc8b7  90                     -nop 
    ;
    // 004bc8b8  90                     -nop 
    ;
    // 004bc8b9  90                     -nop 
    ;
    // 004bc8ba  90                     -nop 
    ;
    // 004bc8bb  90                     -nop 
    ;
    // 004bc8bc  90                     -nop 
    ;
    // 004bc8bd  90                     -nop 
    ;
    // 004bc8be  90                     -nop 
    ;
    // 004bc8bf  90                     -nop 
    ;
    // 004bc8c0  90                     -nop 
    ;
    // 004bc8c1  90                     -nop 
    ;
    // 004bc8c2  90                     -nop 
    ;
    // 004bc8c3  90                     -nop 
    ;
    // 004bc8c4  90                     -nop 
    ;
    // 004bc8c5  90                     -nop 
    ;
    // 004bc8c6  90                     -nop 
    ;
    // 004bc8c7  90                     -nop 
    ;
    // 004bc8c8  90                     -nop 
    ;
    // 004bc8c9  90                     -nop 
    ;
    // 004bc8ca  90                     -nop 
    ;
    // 004bc8cb  90                     -nop 
    ;
    // 004bc8cc  90                     -nop 
    ;
    // 004bc8cd  90                     -nop 
    ;
    // 004bc8ce  90                     -nop 
    ;
    // 004bc8cf  90                     -nop 
    ;
    // 004bc8d0  90                     -nop 
    ;
    // 004bc8d1  90                     -nop 
    ;
    // 004bc8d2  90                     -nop 
    ;
    // 004bc8d3  90                     -nop 
    ;
    // 004bc8d4  90                     -nop 
    ;
    // 004bc8d5  90                     -nop 
    ;
    // 004bc8d6  90                     -nop 
    ;
    // 004bc8d7  90                     -nop 
    ;
    // 004bc8d8  90                     -nop 
    ;
    // 004bc8d9  90                     -nop 
    ;
    // 004bc8da  90                     -nop 
    ;
    // 004bc8db  90                     -nop 
    ;
    // 004bc8dc  90                     -nop 
    ;
    // 004bc8dd  90                     -nop 
    ;
    // 004bc8de  90                     -nop 
    ;
    // 004bc8df  90                     -nop 
    ;
    // 004bc8e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc8e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc8e2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc8e4  e8378e0100             -call 0x4d5720
    cpu.esp -= 4;
    sub_4d5720(app, cpu);
    if (cpu.terminate) return;
    // 004bc8e9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc8eb  e8e06afeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc8f0  8915103d7a00           -mov dword ptr [0x7a3d10], edx
    app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */) = cpu.edx;
    // 004bc8f6  e8d56afeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc8fb  e870f4ffff             -call 0x4bbd70
    cpu.esp -= 4;
    sub_4bbd70(app, cpu);
    if (cpu.terminate) return;
    // 004bc900  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc901  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc902  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bc8e0;
    // 004bc8b0  90                     -nop 
    ;
    // 004bc8b1  90                     -nop 
    ;
    // 004bc8b2  90                     -nop 
    ;
    // 004bc8b3  90                     -nop 
    ;
    // 004bc8b4  90                     -nop 
    ;
    // 004bc8b5  90                     -nop 
    ;
    // 004bc8b6  90                     -nop 
    ;
    // 004bc8b7  90                     -nop 
    ;
    // 004bc8b8  90                     -nop 
    ;
    // 004bc8b9  90                     -nop 
    ;
    // 004bc8ba  90                     -nop 
    ;
    // 004bc8bb  90                     -nop 
    ;
    // 004bc8bc  90                     -nop 
    ;
    // 004bc8bd  90                     -nop 
    ;
    // 004bc8be  90                     -nop 
    ;
    // 004bc8bf  90                     -nop 
    ;
    // 004bc8c0  90                     -nop 
    ;
    // 004bc8c1  90                     -nop 
    ;
    // 004bc8c2  90                     -nop 
    ;
    // 004bc8c3  90                     -nop 
    ;
    // 004bc8c4  90                     -nop 
    ;
    // 004bc8c5  90                     -nop 
    ;
    // 004bc8c6  90                     -nop 
    ;
    // 004bc8c7  90                     -nop 
    ;
    // 004bc8c8  90                     -nop 
    ;
    // 004bc8c9  90                     -nop 
    ;
    // 004bc8ca  90                     -nop 
    ;
    // 004bc8cb  90                     -nop 
    ;
    // 004bc8cc  90                     -nop 
    ;
    // 004bc8cd  90                     -nop 
    ;
    // 004bc8ce  90                     -nop 
    ;
    // 004bc8cf  90                     -nop 
    ;
    // 004bc8d0  90                     -nop 
    ;
    // 004bc8d1  90                     -nop 
    ;
    // 004bc8d2  90                     -nop 
    ;
    // 004bc8d3  90                     -nop 
    ;
    // 004bc8d4  90                     -nop 
    ;
    // 004bc8d5  90                     -nop 
    ;
    // 004bc8d6  90                     -nop 
    ;
    // 004bc8d7  90                     -nop 
    ;
    // 004bc8d8  90                     -nop 
    ;
    // 004bc8d9  90                     -nop 
    ;
    // 004bc8da  90                     -nop 
    ;
    // 004bc8db  90                     -nop 
    ;
    // 004bc8dc  90                     -nop 
    ;
    // 004bc8dd  90                     -nop 
    ;
    // 004bc8de  90                     -nop 
    ;
    // 004bc8df  90                     -nop 
    ;
L_entry_0x004bc8e0:
    // 004bc8e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc8e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc8e2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc8e4  e8378e0100             -call 0x4d5720
    cpu.esp -= 4;
    sub_4d5720(app, cpu);
    if (cpu.terminate) return;
    // 004bc8e9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc8eb  e8e06afeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc8f0  8915103d7a00           -mov dword ptr [0x7a3d10], edx
    app->getMemory<x86::reg32>(x86::reg32(8011024) /* 0x7a3d10 */) = cpu.edx;
    // 004bc8f6  e8d56afeff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004bc8fb  e870f4ffff             -call 0x4bbd70
    cpu.esp -= 4;
    sub_4bbd70(app, cpu);
    if (cpu.terminate) return;
    // 004bc900  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc901  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc902  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4bc910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc910  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc911  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc912  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc913  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc914  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc916  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004bc91b  ba80664200             -mov edx, 0x426680
    cpu.edx = 4351616 /*0x426680*/;
    // 004bc920  a18c367d00             -mov eax, dword ptr [0x7d368c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205964) /* 0x7d368c */);
    // 004bc925  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc927  e824190000             -call 0x4be250
    cpu.esp -= 4;
    sub_4be250(app, cpu);
    if (cpu.terminate) return;
    // 004bc92c  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004bc931  bac0b24c00             -mov edx, 0x4cb2c0
    cpu.edx = 5026496 /*0x4cb2c0*/;
    // 004bc936  a18c367d00             -mov eax, dword ptr [0x7d368c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205964) /* 0x7d368c */);
    // 004bc93b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc93d  e80e190000             -call 0x4be250
    cpu.esp -= 4;
    sub_4be250(app, cpu);
    if (cpu.terminate) return;
    // 004bc942  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc943  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc944  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc945  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc946  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4bc950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc950  90                     -nop 
    ;
    // 004bc951  90                     -nop 
    ;
    // 004bc952  90                     -nop 
    ;
    // 004bc953  90                     -nop 
    ;
    // 004bc954  90                     -nop 
    ;
    // 004bc955  90                     -nop 
    ;
    // 004bc956  90                     -nop 
    ;
    // 004bc957  90                     -nop 
    ;
    // 004bc958  90                     -nop 
    ;
    // 004bc959  90                     -nop 
    ;
    // 004bc95a  90                     -nop 
    ;
    // 004bc95b  90                     -nop 
    ;
    // 004bc95c  90                     -nop 
    ;
    // 004bc95d  90                     -nop 
    ;
    // 004bc95e  90                     -nop 
    ;
    // 004bc95f  90                     -nop 
    ;
    // 004bc960  90                     -nop 
    ;
    // 004bc961  90                     -nop 
    ;
    // 004bc962  90                     -nop 
    ;
    // 004bc963  90                     -nop 
    ;
    // 004bc964  90                     -nop 
    ;
    // 004bc965  90                     -nop 
    ;
    // 004bc966  90                     -nop 
    ;
    // 004bc967  90                     -nop 
    ;
    // 004bc968  90                     -nop 
    ;
    // 004bc969  90                     -nop 
    ;
    // 004bc96a  90                     -nop 
    ;
    // 004bc96b  90                     -nop 
    ;
    // 004bc96c  90                     -nop 
    ;
    // 004bc96d  90                     -nop 
    ;
    // 004bc96e  90                     -nop 
    ;
    // 004bc96f  90                     -nop 
    ;
    // 004bc970  90                     -nop 
    ;
    // 004bc971  90                     -nop 
    ;
    // 004bc972  90                     -nop 
    ;
    // 004bc973  90                     -nop 
    ;
    // 004bc974  90                     -nop 
    ;
    // 004bc975  90                     -nop 
    ;
    // 004bc976  90                     -nop 
    ;
    // 004bc977  90                     -nop 
    ;
    // 004bc978  90                     -nop 
    ;
    // 004bc979  90                     -nop 
    ;
    // 004bc97a  90                     -nop 
    ;
    // 004bc97b  90                     -nop 
    ;
    // 004bc97c  90                     -nop 
    ;
    // 004bc97d  90                     -nop 
    ;
    // 004bc97e  90                     -nop 
    ;
    // 004bc97f  90                     -nop 
    ;
    // 004bc980  90                     -nop 
    ;
    // 004bc981  90                     -nop 
    ;
    // 004bc982  90                     -nop 
    ;
    // 004bc983  90                     -nop 
    ;
    // 004bc984  90                     -nop 
    ;
    // 004bc985  90                     -nop 
    ;
    // 004bc986  90                     -nop 
    ;
    // 004bc987  90                     -nop 
    ;
    // 004bc988  90                     -nop 
    ;
    // 004bc989  90                     -nop 
    ;
    // 004bc98a  90                     -nop 
    ;
    // 004bc98b  90                     -nop 
    ;
    // 004bc98c  90                     -nop 
    ;
    // 004bc98d  90                     -nop 
    ;
    // 004bc98e  90                     -nop 
    ;
    // 004bc98f  90                     -nop 
    ;
    // 004bc990  90                     -nop 
    ;
    // 004bc991  90                     -nop 
    ;
    // 004bc992  90                     -nop 
    ;
    // 004bc993  90                     -nop 
    ;
    // 004bc994  90                     -nop 
    ;
    // 004bc995  90                     -nop 
    ;
    // 004bc996  90                     -nop 
    ;
    // 004bc997  90                     -nop 
    ;
    // 004bc998  90                     -nop 
    ;
    // 004bc999  90                     -nop 
    ;
    // 004bc99a  90                     -nop 
    ;
    // 004bc99b  90                     -nop 
    ;
    // 004bc99c  90                     -nop 
    ;
    // 004bc99d  90                     -nop 
    ;
    // 004bc99e  90                     -nop 
    ;
    // 004bc99f  90                     -nop 
    ;
    // 004bc9a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc9a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc9a2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc9a4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc9a6  891558da7c00           -mov dword ptr [0x7cda58], edx
    app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */) = cpu.edx;
    // 004bc9ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc9ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc9ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bc9a0;
    // 004bc950  90                     -nop 
    ;
    // 004bc951  90                     -nop 
    ;
    // 004bc952  90                     -nop 
    ;
    // 004bc953  90                     -nop 
    ;
    // 004bc954  90                     -nop 
    ;
    // 004bc955  90                     -nop 
    ;
    // 004bc956  90                     -nop 
    ;
    // 004bc957  90                     -nop 
    ;
    // 004bc958  90                     -nop 
    ;
    // 004bc959  90                     -nop 
    ;
    // 004bc95a  90                     -nop 
    ;
    // 004bc95b  90                     -nop 
    ;
    // 004bc95c  90                     -nop 
    ;
    // 004bc95d  90                     -nop 
    ;
    // 004bc95e  90                     -nop 
    ;
    // 004bc95f  90                     -nop 
    ;
    // 004bc960  90                     -nop 
    ;
    // 004bc961  90                     -nop 
    ;
    // 004bc962  90                     -nop 
    ;
    // 004bc963  90                     -nop 
    ;
    // 004bc964  90                     -nop 
    ;
    // 004bc965  90                     -nop 
    ;
    // 004bc966  90                     -nop 
    ;
    // 004bc967  90                     -nop 
    ;
    // 004bc968  90                     -nop 
    ;
    // 004bc969  90                     -nop 
    ;
    // 004bc96a  90                     -nop 
    ;
    // 004bc96b  90                     -nop 
    ;
    // 004bc96c  90                     -nop 
    ;
    // 004bc96d  90                     -nop 
    ;
    // 004bc96e  90                     -nop 
    ;
    // 004bc96f  90                     -nop 
    ;
    // 004bc970  90                     -nop 
    ;
    // 004bc971  90                     -nop 
    ;
    // 004bc972  90                     -nop 
    ;
    // 004bc973  90                     -nop 
    ;
    // 004bc974  90                     -nop 
    ;
    // 004bc975  90                     -nop 
    ;
    // 004bc976  90                     -nop 
    ;
    // 004bc977  90                     -nop 
    ;
    // 004bc978  90                     -nop 
    ;
    // 004bc979  90                     -nop 
    ;
    // 004bc97a  90                     -nop 
    ;
    // 004bc97b  90                     -nop 
    ;
    // 004bc97c  90                     -nop 
    ;
    // 004bc97d  90                     -nop 
    ;
    // 004bc97e  90                     -nop 
    ;
    // 004bc97f  90                     -nop 
    ;
    // 004bc980  90                     -nop 
    ;
    // 004bc981  90                     -nop 
    ;
    // 004bc982  90                     -nop 
    ;
    // 004bc983  90                     -nop 
    ;
    // 004bc984  90                     -nop 
    ;
    // 004bc985  90                     -nop 
    ;
    // 004bc986  90                     -nop 
    ;
    // 004bc987  90                     -nop 
    ;
    // 004bc988  90                     -nop 
    ;
    // 004bc989  90                     -nop 
    ;
    // 004bc98a  90                     -nop 
    ;
    // 004bc98b  90                     -nop 
    ;
    // 004bc98c  90                     -nop 
    ;
    // 004bc98d  90                     -nop 
    ;
    // 004bc98e  90                     -nop 
    ;
    // 004bc98f  90                     -nop 
    ;
    // 004bc990  90                     -nop 
    ;
    // 004bc991  90                     -nop 
    ;
    // 004bc992  90                     -nop 
    ;
    // 004bc993  90                     -nop 
    ;
    // 004bc994  90                     -nop 
    ;
    // 004bc995  90                     -nop 
    ;
    // 004bc996  90                     -nop 
    ;
    // 004bc997  90                     -nop 
    ;
    // 004bc998  90                     -nop 
    ;
    // 004bc999  90                     -nop 
    ;
    // 004bc99a  90                     -nop 
    ;
    // 004bc99b  90                     -nop 
    ;
    // 004bc99c  90                     -nop 
    ;
    // 004bc99d  90                     -nop 
    ;
    // 004bc99e  90                     -nop 
    ;
    // 004bc99f  90                     -nop 
    ;
L_entry_0x004bc9a0:
    // 004bc9a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bc9a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc9a2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc9a4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc9a6  891558da7c00           -mov dword ptr [0x7cda58], edx
    app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */) = cpu.edx;
    // 004bc9ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc9ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc9ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bc9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bc9b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc9b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc9b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc9b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc9b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc9b5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc9b7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc9ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bc9bc  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004bc9bf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bc9c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc9c6  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004bc9c8  eb49                   -jmp 0x4bca13
    goto L_0x004bca13;
L_0x004bc9ca:
    // 004bc9ca  42                     -inc edx
    (cpu.edx)++;
    // 004bc9cb  83fa20                 +cmp edx, 0x20
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
    // 004bc9ce  7d0a                   -jge 0x4bc9da
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc9da;
    }
    // 004bc9d0  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004bc9d3  8a5fff                 -mov bl, byte ptr [edi - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004bc9d6  3a1f                   +cmp bl, byte ptr [edi]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edi)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bc9d8  75f0                   -jne 0x4bc9ca
    if (!cpu.flags.zf)
    {
        goto L_0x004bc9ca;
    }
L_0x004bc9da:
    // 004bc9da  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc9dc  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004bc9df  83fa01                 +cmp edx, 1
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
    // 004bc9e2  7e27                   -jle 0x4bca0b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bca0b;
    }
    // 004bc9e4  4a                     -dec edx
    (cpu.edx)--;
    // 004bc9e5  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004bc9e8  8a55fc                 -mov dl, byte ptr [ebp - 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bc9eb  40                     -inc eax
    (cpu.eax)++;
    // 004bc9ec  f6da                   -neg dl
    cpu.dl = ~cpu.dl + 1;
    // 004bc9ee  88908f3d7a00           -mov byte ptr [eax + 0x7a3d8f], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8011151) /* 0x7a3d8f */) = cpu.dl;
    // 004bc9f4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bc9f6:
    // 004bc9f6  3b55fc                 +cmp edx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc9f9  7d10                   -jge 0x4bca0b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bca0b;
    }
    // 004bc9fb  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bc9fd  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bc9fe  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bc9ff  8a1c1e                 -mov bl, byte ptr [esi + ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004bca02  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bca03  88988f3d7a00           -mov byte ptr [eax + 0x7a3d8f], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8011151) /* 0x7a3d8f */) = cpu.bl;
    // 004bca09  ebeb                   -jmp 0x4bc9f6
    goto L_0x004bc9f6;
L_0x004bca0b:
    // 004bca0b  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004bca0e  83fa20                 +cmp edx, 0x20
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
    // 004bca11  7d44                   -jge 0x4bca57
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bca57;
    }
L_0x004bca13:
    // 004bca13  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004bca16  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004bca19  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004bca1b  8a3f                   -mov bh, byte ptr [edi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi);
    // 004bca1d  38fb                   +cmp bl, bh
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
    // 004bca1f  75a9                   -jne 0x4bc9ca
    if (!cpu.flags.zf)
    {
        goto L_0x004bc9ca;
    }
L_0x004bca21:
    // 004bca21  42                     -inc edx
    (cpu.edx)++;
    // 004bca22  83fa20                 +cmp edx, 0x20
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
    // 004bca25  7d0c                   -jge 0x4bca33
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bca33;
    }
    // 004bca27  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004bca2a  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004bca2d  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004bca2f  3a1f                   +cmp bl, byte ptr [edi]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edi)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bca31  74ee                   -je 0x4bca21
    if (cpu.flags.zf)
    {
        goto L_0x004bca21;
    }
L_0x004bca33:
    // 004bca33  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bca35  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bca37  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004bca3a  83fb01                 +cmp ebx, 1
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
    // 004bca3d  7ecc                   -jle 0x4bca0b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bca0b;
    }
    // 004bca3f  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bca40  8a5dfc                 -mov bl, byte ptr [ebp - 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bca43  88988f3d7a00           -mov byte ptr [eax + 0x7a3d8f], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8011151) /* 0x7a3d8f */) = cpu.bl;
    // 004bca49  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bca4a  8a1c31                 -mov bl, byte ptr [ecx + esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1);
    // 004bca4d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bca4f  88988f3d7a00           -mov byte ptr [eax + 0x7a3d8f], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8011151) /* 0x7a3d8f */) = cpu.bl;
    // 004bca55  ebb4                   -jmp 0x4bca0b
    goto L_0x004bca0b;
L_0x004bca57:
    // 004bca57  7514                   -jne 0x4bca6d
    if (!cpu.flags.zf)
    {
        goto L_0x004bca6d;
    }
    // 004bca59  40                     -inc eax
    (cpu.eax)++;
    // 004bca5a  c6808f3d7a00ff         -mov byte ptr [eax + 0x7a3d8f], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8011151) /* 0x7a3d8f */) = 255 /*0xff*/;
    // 004bca61  8d140e                 -lea edx, [esi + ecx]
    cpu.edx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004bca64  40                     -inc eax
    (cpu.eax)++;
    // 004bca65  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 004bca67  88908f3d7a00           -mov byte ptr [eax + 0x7a3d8f], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8011151) /* 0x7a3d8f */) = cpu.dl;
L_0x004bca6d:
    // 004bca6d  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bca70  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004bca72  b8903d7a00             -mov eax, 0x7a3d90
    cpu.eax = 8011152 /*0x7a3d90*/;
    // 004bca77  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bca79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bca7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bca7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bca7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bca7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bca7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bca80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bca80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bca81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bca82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bca83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bca84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bca85  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bca87  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bca8a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bca8c  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004bca8f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bca91  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bca93  eb06                   -jmp 0x4bca9b
    goto L_0x004bca9b;
L_0x004bca95:
    // 004bca95  40                     -inc eax
    (cpu.eax)++;
L_0x004bca96:
    // 004bca96  83fa20                 +cmp edx, 0x20
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
    // 004bca99  7d44                   -jge 0x4bcadf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcadf;
    }
L_0x004bca9b:
    // 004bca9b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bca9d  8a1c19                 -mov bl, byte ptr [ecx + ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1);
    // 004bcaa0  40                     -inc eax
    (cpu.eax)++;
    // 004bcaa1  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004bcaa3  7e18                   -jle 0x4bcabd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcabd;
    }
    // 004bcaa5  0fbefb                 -movsx edi, bl
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 004bcaa8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004bcaaa:
    // 004bcaaa  39fe                   +cmp esi, edi
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
    // 004bcaac  7de7                   -jge 0x4bca95
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bca95;
    }
    // 004bcaae  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004bcab1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bcab2  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004bcab4  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bcab5  889a0f3e7a00           -mov byte ptr [edx + 0x7a3e0f], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8011279) /* 0x7a3e0f */) = cpu.bl;
    // 004bcabb  ebed                   -jmp 0x4bcaaa
    goto L_0x004bcaaa;
L_0x004bcabd:
    // 004bcabd  0fbedb                 -movsx ebx, bl
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 004bcac0  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004bcac3  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 004bcac5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004bcac7  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
L_0x004bcaca:
    // 004bcaca  3b75fc                 +cmp esi, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcacd  7dc7                   -jge 0x4bca96
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bca96;
    }
    // 004bcacf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bcad1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bcad2  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bcad3  8a1c19                 -mov bl, byte ptr [ecx + ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1);
    // 004bcad6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bcad7  889a0f3e7a00           -mov byte ptr [edx + 0x7a3e0f], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8011279) /* 0x7a3e0f */) = cpu.bl;
    // 004bcadd  ebeb                   -jmp 0x4bcaca
    goto L_0x004bcaca;
L_0x004bcadf:
    // 004bcadf  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bcae2  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004bcae4  b8103e7a00             -mov eax, 0x7a3e10
    cpu.eax = 8011280 /*0x7a3e10*/;
    // 004bcae9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bcaeb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcaec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcaed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcaee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcaef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcaf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4bcb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bcb00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcb01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bcb02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcb03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcb04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcb05  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bcb07  81ec6c170000           -sub esp, 0x176c
    (cpu.esp) -= x86::reg32(x86::sreg32(5996 /*0x176c*/));
    // 004bcb0d  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004bcb12  8dbd94e8ffff           -lea edi, [ebp - 0x176c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-5996) /* -0x176c */);
    // 004bcb18  be4cbb6f00             -mov esi, 0x6fbb4c
    cpu.esi = 7322444 /*0x6fbb4c*/;
    // 004bcb1d  890da0d36f00           -mov dword ptr [0x6fd3a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(7328672) /* 0x6fd3a0 */) = cpu.ecx;
    // 004bcb23  890d58da7c00           -mov dword ptr [0x7cda58], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */) = cpu.ecx;
    // 004bcb29  b9db050000             -mov ecx, 0x5db
    cpu.ecx = 1499 /*0x5db*/;
    // 004bcb2e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bcb33  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bcb35  e8a6070000             -call 0x4bd2e0
    cpu.esp -= 4;
    sub_4bd2e0(app, cpu);
    if (cpu.terminate) return;
    // 004bcb3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bcb3c  7502                   -jne 0x4bcb40
    if (!cpu.flags.zf)
    {
        goto L_0x004bcb40;
    }
    // 004bcb3e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bcb40:
    // 004bcb40  b93c080000             -mov ecx, 0x83c
    cpu.ecx = 2108 /*0x83c*/;
    // 004bcb45  bf40bb6f00             -mov edi, 0x6fbb40
    cpu.edi = 7322432 /*0x6fbb40*/;
    // 004bcb4a  be503e7a00             -mov esi, 0x7a3e50
    cpu.esi = 8011344 /*0x7a3e50*/;
    // 004bcb4f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bcb51  b9db050000             -mov ecx, 0x5db
    cpu.ecx = 1499 /*0x5db*/;
    // 004bcb56  8db594e8ffff           -lea esi, [ebp - 0x176c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-5996) /* -0x176c */);
    // 004bcb5c  bf4cbb6f00             -mov edi, 0x6fbb4c
    cpu.edi = 7322444 /*0x6fbb4c*/;
    // 004bcb61  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bcb63  a1445f7a00             -mov eax, dword ptr [0x7a5f44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8019780) /* 0x7a5f44 */);
    // 004bcb68  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004bcb6a  a340fe5500             -mov dword ptr [0x55fe40], eax
    app->getMemory<x86::reg32>(x86::reg32(5635648) /* 0x55fe40 */) = cpu.eax;
    // 004bcb6f  893554da7c00           -mov dword ptr [0x7cda54], esi
    app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */) = cpu.esi;
    // 004bcb75  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bcb77  750c                   -jne 0x4bcb85
    if (!cpu.flags.zf)
    {
        goto L_0x004bcb85;
    }
    // 004bcb79  893558da7c00           -mov dword ptr [0x7cda58], esi
    app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */) = cpu.esi;
    // 004bcb7f  8935a0d36f00           -mov dword ptr [0x6fd3a0], esi
    app->getMemory<x86::reg32>(x86::reg32(7328672) /* 0x6fd3a0 */) = cpu.esi;
L_0x004bcb85:
    // 004bcb85  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bcb87  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bcb89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcb8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcb8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcb8c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcb8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcb8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bcb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bcb90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bcb91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcb92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bcb93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcb94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcb95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcb96  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bcb98  8b3558da7c00           -mov esi, dword ptr [0x7cda58]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */);
    // 004bcb9e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bcba0  7409                   -je 0x4bcbab
    if (cpu.flags.zf)
    {
        goto L_0x004bcbab;
    }
    // 004bcba2  83fe01                 +cmp esi, 1
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
    // 004bcba5  0f85b5000000           -jne 0x4bcc60
    if (!cpu.flags.zf)
    {
        goto L_0x004bcc60;
    }
L_0x004bcbab:
    // 004bcbab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcbad  40                     -inc eax
    (cpu.eax)++;
    // 004bcbae  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004bcbb0  8890475f7a00           -mov byte ptr [eax + 0x7a5f47], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8019783) /* 0x7a5f47 */) = cpu.dl;
L_0x004bcbb6:
    // 004bcbb6  3d00e00100             +cmp eax, 0x1e000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122880 /*0x1e000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcbbb  7d0b                   -jge 0x4bcbc8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcbc8;
    }
    // 004bcbbd  40                     -inc eax
    (cpu.eax)++;
    // 004bcbbe  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 004bcbc0  8890475f7a00           -mov byte ptr [eax + 0x7a5f47], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8019783) /* 0x7a5f47 */) = cpu.dl;
    // 004bcbc6  ebee                   -jmp 0x4bcbb6
    goto L_0x004bcbb6;
L_0x004bcbc8:
    // 004bcbc8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcbca  40                     -inc eax
    (cpu.eax)++;
    // 004bcbcb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcbcd  891485cc3d7a00         -mov dword ptr [eax*4 + 0x7a3dcc], edx
    app->getMemory<x86::reg32>(x86::reg32(8011212) /* 0x7a3dcc */ + cpu.eax * 4) = cpu.edx;
L_0x004bcbd4:
    // 004bcbd4  83f810                 +cmp eax, 0x10
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
    // 004bcbd7  7d0c                   -jge 0x4bcbe5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcbe5;
    }
    // 004bcbd9  40                     -inc eax
    (cpu.eax)++;
    // 004bcbda  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bcbdc  891485cc3d7a00         -mov dword ptr [eax*4 + 0x7a3dcc], edx
    app->getMemory<x86::reg32>(x86::reg32(8011212) /* 0x7a3dcc */ + cpu.eax * 4) = cpu.edx;
    // 004bcbe3  ebef                   -jmp 0x4bcbd4
    goto L_0x004bcbd4;
L_0x004bcbe5:
    // 004bcbe5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bcbe7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcbe9  890d54da7c00           -mov dword ptr [0x7cda54], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */) = cpu.ecx;
    // 004bcbef  890d50da7c00           -mov dword ptr [0x7cda50], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */) = cpu.ecx;
    // 004bcbf5  40                     -inc eax
    (cpu.eax)++;
    // 004bcbf6  c70485443f7c000b000000 -mov dword ptr [eax*4 + 0x7c3f44], 0xb
    app->getMemory<x86::reg32>(x86::reg32(8142660) /* 0x7c3f44 */ + cpu.eax * 4) = 11 /*0xb*/;
L_0x004bcc01:
    // 004bcc01  83f810                 +cmp eax, 0x10
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
    // 004bcc04  7d0e                   -jge 0x4bcc14
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcc14;
    }
    // 004bcc06  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bcc07  c70485443f7c000b000000 -mov dword ptr [eax*4 + 0x7c3f44], 0xb
    app->getMemory<x86::reg32>(x86::reg32(8142660) /* 0x7c3f44 */ + cpu.eax * 4) = 11 /*0xb*/;
    // 004bcc12  ebed                   -jmp 0x4bcc01
    goto L_0x004bcc01;
L_0x004bcc14:
    // 004bcc14  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bcc19  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcc1b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bcc1d  40                     -inc eax
    (cpu.eax)++;
    // 004bcc1e  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
    // 004bcc21  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bcc23  898c83443f7c00         -mov dword ptr [ebx + eax*4 + 0x7c3f44], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8142660) /* 0x7c3f44 */ + cpu.eax * 4) = cpu.ecx;
L_0x004bcc2a:
    // 004bcc2a  83f810                 +cmp eax, 0x10
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
    // 004bcc2d  7d11                   -jge 0x4bcc40
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcc40;
    }
    // 004bcc2f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bcc31  40                     -inc eax
    (cpu.eax)++;
    // 004bcc32  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
    // 004bcc35  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004bcc37  898c83443f7c00         -mov dword ptr [ebx + eax*4 + 0x7c3f44], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8142660) /* 0x7c3f44 */ + cpu.eax * 4) = cpu.ecx;
    // 004bcc3e  ebea                   -jmp 0x4bcc2a
    goto L_0x004bcc2a;
L_0x004bcc40:
    // 004bcc40  42                     -inc edx
    (cpu.edx)++;
    // 004bcc41  81fa58020000           +cmp edx, 0x258
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(600 /*0x258*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcc47  0f8d73000000           -jge 0x4bccc0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bccc0;
    }
    // 004bcc4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcc4f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bcc51  40                     -inc eax
    (cpu.eax)++;
    // 004bcc52  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
    // 004bcc55  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004bcc57  898c83443f7c00         -mov dword ptr [ebx + eax*4 + 0x7c3f44], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8142660) /* 0x7c3f44 */ + cpu.eax * 4) = cpu.ecx;
    // 004bcc5e  ebca                   -jmp 0x4bcc2a
    goto L_0x004bcc2a;
L_0x004bcc60:
    // 004bcc60  83fe02                 +cmp esi, 2
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
    // 004bcc63  7c5b                   -jl 0x4bccc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bccc0;
    }
    // 004bcc65  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bcc67  891d48d97c00           -mov dword ptr [0x7cd948], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182088) /* 0x7cd948 */) = cpu.ebx;
    // 004bcc6d  891d50d97c00           -mov dword ptr [0x7cd950], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182096) /* 0x7cd950 */) = cpu.ebx;
    // 004bcc73  891d58d97c00           -mov dword ptr [0x7cd958], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */) = cpu.ebx;
    // 004bcc79  891d5cd97c00           -mov dword ptr [0x7cd95c], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182108) /* 0x7cd95c */) = cpu.ebx;
    // 004bcc7f  891d60d97c00           -mov dword ptr [0x7cd960], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182112) /* 0x7cd960 */) = cpu.ebx;
    // 004bcc85  891d54da7c00           -mov dword ptr [0x7cda54], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */) = cpu.ebx;
    // 004bcc8b  83fe04                 +cmp esi, 4
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
    // 004bcc8e  7519                   -jne 0x4bcca9
    if (!cpu.flags.zf)
    {
        goto L_0x004bcca9;
    }
    // 004bcc90  833d54d97c0000         +cmp dword ptr [0x7cd954], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcc97  7407                   -je 0x4bcca0
    if (cpu.flags.zf)
    {
        goto L_0x004bcca0;
    }
    // 004bcc99  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bcc9e  eb02                   -jmp 0x4bcca2
    goto L_0x004bcca2;
L_0x004bcca0:
    // 004bcca0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
L_0x004bcca2:
    // 004bcca2  a360d97c00             -mov dword ptr [0x7cd960], eax
    app->getMemory<x86::reg32>(x86::reg32(8182112) /* 0x7cd960 */) = cpu.eax;
    // 004bcca7  eb17                   -jmp 0x4bccc0
    goto L_0x004bccc0;
L_0x004bcca9:
    // 004bcca9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004bccae  891d64d97c00           -mov dword ptr [0x7cd964], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182116) /* 0x7cd964 */) = cpu.ebx;
    // 004bccb4  891d54d97c00           -mov dword ptr [0x7cd954], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */) = cpu.ebx;
    // 004bccba  89154cd97c00           -mov dword ptr [0x7cd94c], edx
    app->getMemory<x86::reg32>(x86::reg32(8182092) /* 0x7cd94c */) = cpu.edx;
L_0x004bccc0:
    // 004bccc0  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bccc2  eb2d                   -jmp 0x4bccf1
    goto L_0x004bccf1;
L_0x004bccc4:
    // 004bccc4  83f919                 +cmp ecx, 0x19
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bccc7  7d22                   -jge 0x4bcceb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcceb;
    }
L_0x004bccc9:
    // 004bccc9  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004bccd0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bccd2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bccd5  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004bccd8  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004bccdb  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004bcce0  89bc8b78d97c00         -mov dword ptr [ebx + ecx*4 + 0x7cd978], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8182136) /* 0x7cd978 */ + cpu.ecx * 4) = cpu.edi;
    // 004bcce7  01f9                   +add ecx, edi
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
    // 004bcce9  ebd9                   -jmp 0x4bccc4
    goto L_0x004bccc4;
L_0x004bcceb:
    // 004bcceb  42                     -inc edx
    (cpu.edx)++;
    // 004bccec  83fa02                 +cmp edx, 2
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
    // 004bccef  7d39                   -jge 0x4bcd2a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcd2a;
    }
L_0x004bccf1:
    // 004bccf1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bccf3  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004bccfa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bccfc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bccff  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bcd01  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004bcd06  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bcd08  891c8568d97c00         -mov dword ptr [eax*4 + 0x7cd968], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182120) /* 0x7cd968 */ + cpu.eax * 4) = cpu.ebx;
    // 004bcd0f  31d1                   -xor ecx, edx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcd11  893c856cd97c00         -mov dword ptr [eax*4 + 0x7cd96c], edi
    app->getMemory<x86::reg32>(x86::reg32(8182124) /* 0x7cd96c */ + cpu.eax * 4) = cpu.edi;
    // 004bcd18  890c8570d97c00         -mov dword ptr [eax*4 + 0x7cd970], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182128) /* 0x7cd970 */ + cpu.eax * 4) = cpu.ecx;
    // 004bcd1f  893c8574d97c00         -mov dword ptr [eax*4 + 0x7cd974], edi
    app->getMemory<x86::reg32>(x86::reg32(8182132) /* 0x7cd974 */ + cpu.eax * 4) = cpu.edi;
    // 004bcd26  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004bcd28  eb9f                   -jmp 0x4bccc9
    goto L_0x004bccc9;
L_0x004bcd2a:
    // 004bcd2a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcd2c  40                     -inc eax
    (cpu.eax)++;
    // 004bcd2d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcd2f  8914852c3e7a00         -mov dword ptr [eax*4 + 0x7a3e2c], edx
    app->getMemory<x86::reg32>(x86::reg32(8011308) /* 0x7a3e2c */ + cpu.eax * 4) = cpu.edx;
L_0x004bcd36:
    // 004bcd36  83f808                 +cmp eax, 8
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
    // 004bcd39  7d0c                   -jge 0x4bcd47
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcd47;
    }
    // 004bcd3b  40                     -inc eax
    (cpu.eax)++;
    // 004bcd3c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bcd3e  8914852c3e7a00         -mov dword ptr [eax*4 + 0x7a3e2c], edx
    app->getMemory<x86::reg32>(x86::reg32(8011308) /* 0x7a3e2c */ + cpu.eax * 4) = cpu.edx;
    // 004bcd45  ebef                   -jmp 0x4bcd36
    goto L_0x004bcd36;
L_0x004bcd47:
    // 004bcd47  893558da7c00           -mov dword ptr [0x7cda58], esi
    app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */) = cpu.esi;
    // 004bcd4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd4e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd4f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd50  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd53  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4bcd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bcd60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcd61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcd62  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bcd64  833d8ce8550000         +cmp dword ptr [0x55e88c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5630092) /* 0x55e88c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcd6b  7528                   -jne 0x4bcd95
    if (!cpu.flags.zf)
    {
        goto L_0x004bcd95;
    }
    // 004bcd6d  833d58da7c0001         +cmp dword ptr [0x7cda58], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcd74  7f05                   -jg 0x4bcd7b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bcd7b;
    }
    // 004bcd76  e865040000             -call 0x4bd1e0
    cpu.esp -= 4;
    sub_4bd1e0(app, cpu);
    if (cpu.terminate) return;
L_0x004bcd7b:
    // 004bcd7b  833d58da7c0001         +cmp dword ptr [0x7cda58], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcd82  7e11                   -jle 0x4bcd95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcd95;
    }
    // 004bcd84  833db0d36f0002         +cmp dword ptr [0x6fd3b0], 2
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
    // 004bcd8b  7c08                   -jl 0x4bcd95
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcd95;
    }
    // 004bcd8d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bcd8f  893db0d36f00           -mov dword ptr [0x6fd3b0], edi
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.edi;
L_0x004bcd95:
    // 004bcd95  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4bcda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bcda0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bcda1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcda2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bcda3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcda4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcda5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcda6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bcda8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcdab  a150da7c00             -mov eax, dword ptr [0x7cda50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */);
    // 004bcdb0  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004bcdb5  3d00e00100             +cmp eax, 0x1e000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122880 /*0x1e000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcdba  7c1a                   -jl 0x4bcdd6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcdd6;
    }
    // 004bcdbc  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004bcdc1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bcdc6  a340fe5500             -mov dword ptr [0x55fe40], eax
    app->getMemory<x86::reg32>(x86::reg32(5635648) /* 0x55fe40 */) = cpu.eax;
    // 004bcdcb  891558da7c00           -mov dword ptr [0x7cda58], edx
    app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */) = cpu.edx;
    // 004bcdd1  e9f0000000             -jmp 0x4bcec6
    goto L_0x004bcec6;
L_0x004bcdd6:
    // 004bcdd6  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bcdd9  8d451c                 -lea eax, [ebp + 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004bcddc  bf485f7a00             -mov edi, 0x7a5f48
    cpu.edi = 8019784 /*0x7a5f48*/;
    // 004bcde1  e8cafbffff             -call 0x4bc9b0
    cpu.esp -= 4;
    sub_4bc9b0(app, cpu);
    if (cpu.terminate) return;
    // 004bcde6  8b0d50da7c00           -mov ecx, dword ptr [0x7cda50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */);
    // 004bcdec  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bcdee  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bcdf0  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bcdf3  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bcdf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcdf7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bcdf9  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bcdfc  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bcdfe  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bce00  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bce03  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bce05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce06  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bce09  8b1d50da7c00           -mov ebx, dword ptr [0x7cda50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */);
    // 004bce0f  bf485f7a00             -mov edi, 0x7a5f48
    cpu.edi = 8019784 /*0x7a5f48*/;
    // 004bce14  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bce16  8d453c                 -lea eax, [ebp + 0x3c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(60) /* 0x3c */);
    // 004bce19  891d50da7c00           -mov dword ptr [0x7cda50], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */) = cpu.ebx;
    // 004bce1f  e88cfbffff             -call 0x4bc9b0
    cpu.esp -= 4;
    sub_4bc9b0(app, cpu);
    if (cpu.terminate) return;
    // 004bce24  8b3550da7c00           -mov esi, dword ptr [0x7cda50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */);
    // 004bce2a  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bce2d  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bce2f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bce31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bce32  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bce34  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bce37  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bce39  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bce3b  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bce3e  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bce40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce41  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bce44  8b3d50da7c00           -mov edi, dword ptr [0x7cda50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */);
    // 004bce4a  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bce4d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bce4f  8d455c                 -lea eax, [ebp + 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(92) /* 0x5c */);
    // 004bce52  893d50da7c00           -mov dword ptr [0x7cda50], edi
    app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */) = cpu.edi;
    // 004bce58  e853fbffff             -call 0x4bc9b0
    cpu.esp -= 4;
    sub_4bc9b0(app, cpu);
    if (cpu.terminate) return;
    // 004bce5d  bf485f7a00             -mov edi, 0x7a5f48
    cpu.edi = 8019784 /*0x7a5f48*/;
    // 004bce62  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bce65  8b1550da7c00           -mov edx, dword ptr [0x7cda50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */);
    // 004bce6b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bce6d  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bce6f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bce70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bce72  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bce75  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bce77  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bce79  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bce7c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bce7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce7f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bce82  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bce85  8b0d50da7c00           -mov ecx, dword ptr [0x7cda50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */);
    // 004bce8b  bf485f7a00             -mov edi, 0x7a5f48
    cpu.edi = 8019784 /*0x7a5f48*/;
    // 004bce90  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bce92  8d457c                 -lea eax, [ebp + 0x7c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(124) /* 0x7c */);
    // 004bce95  890d50da7c00           -mov dword ptr [0x7cda50], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */) = cpu.ecx;
    // 004bce9b  e810fbffff             -call 0x4bc9b0
    cpu.esp -= 4;
    sub_4bc9b0(app, cpu);
    if (cpu.terminate) return;
    // 004bcea0  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bcea3  8b1d50da7c00           -mov ebx, dword ptr [0x7cda50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */);
    // 004bcea9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bceab  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bcead  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bceae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bceb0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bceb3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bceb5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bceb7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bceba  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bcebc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcebd  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bcec0  010550da7c00           -add dword ptr [0x7cda50], eax
    (app->getMemory<x86::reg32>(x86::reg32(8182352) /* 0x7cda50 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004bcec6:
    // 004bcec6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bcec8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcec9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bceca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcecb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcecc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcecd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcece  c28000                 -ret 0x80
    cpu.esp += 4+128 /*0x80*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4bcee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bcee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bcee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bcee3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcee4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcee5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bcee7  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 004bceed  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 004bcef3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004bcef5  b8485f7a00             -mov eax, 0x7a5f48
    cpu.eax = 8019784 /*0x7a5f48*/;
    // 004bcefa  8b1554da7c00           -mov edx, dword ptr [0x7cda54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */);
    // 004bcf00  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004bcf05  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bcf07  8d557e                 -lea edx, [ebp + 0x7e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004bcf0a  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 004bcf0d  e86efbffff             -call 0x4bca80
    cpu.esp -= 4;
    sub_4bca80(app, cpu);
    if (cpu.terminate) return;
    // 004bcf12  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bcf14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcf15  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bcf17  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bcf1a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bcf1c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bcf1e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bcf21  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bcf23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf24  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004bcf27  8b0d54da7c00           -mov ecx, dword ptr [0x7cda54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */);
    // 004bcf2d  8d557e                 -lea edx, [ebp + 0x7e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004bcf30  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bcf32  b8485f7a00             -mov eax, 0x7a5f48
    cpu.eax = 8019784 /*0x7a5f48*/;
    // 004bcf37  8d7d1e                 -lea edi, [ebp + 0x1e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(30) /* 0x1e */);
    // 004bcf3a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bcf3c  890d54da7c00           -mov dword ptr [0x7cda54], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */) = cpu.ecx;
    // 004bcf42  e839fbffff             -call 0x4bca80
    cpu.esp -= 4;
    sub_4bca80(app, cpu);
    if (cpu.terminate) return;
    // 004bcf47  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004bcf4c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bcf4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcf4f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bcf51  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bcf54  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bcf56  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bcf58  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bcf5b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bcf5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf5e  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004bcf61  8b3d54da7c00           -mov edi, dword ptr [0x7cda54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */);
    // 004bcf67  8d557e                 -lea edx, [ebp + 0x7e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004bcf6a  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bcf6c  b8485f7a00             -mov eax, 0x7a5f48
    cpu.eax = 8019784 /*0x7a5f48*/;
    // 004bcf71  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004bcf76  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bcf78  893d54da7c00           -mov dword ptr [0x7cda54], edi
    app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */) = cpu.edi;
    // 004bcf7e  e8fdfaffff             -call 0x4bca80
    cpu.esp -= 4;
    sub_4bca80(app, cpu);
    if (cpu.terminate) return;
    // 004bcf83  8d7d3e                 -lea edi, [ebp + 0x3e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(62) /* 0x3e */);
    // 004bcf86  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bcf88  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcf89  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bcf8b  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bcf8e  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bcf90  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bcf92  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bcf95  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bcf97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf98  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004bcf9b  8b0d54da7c00           -mov ecx, dword ptr [0x7cda54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */);
    // 004bcfa1  8d557e                 -lea edx, [ebp + 0x7e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004bcfa4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bcfa6  b8485f7a00             -mov eax, 0x7a5f48
    cpu.eax = 8019784 /*0x7a5f48*/;
    // 004bcfab  8d7d5e                 -lea edi, [ebp + 0x5e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(94) /* 0x5e */);
    // 004bcfae  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bcfb0  890d54da7c00           -mov dword ptr [0x7cda54], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */) = cpu.ecx;
    // 004bcfb6  e8c5faffff             -call 0x4bca80
    cpu.esp -= 4;
    sub_4bca80(app, cpu);
    if (cpu.terminate) return;
    // 004bcfbb  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004bcfc0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bcfc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcfc3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bcfc5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bcfc8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bcfca  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bcfcc  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bcfcf  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bcfd1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcfd2  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004bcfd5  8b3d54da7c00           -mov edi, dword ptr [0x7cda54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */);
    // 004bcfdb  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004bcfe0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bcfe2  8d75fe                 -lea esi, [ebp - 2]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 004bcfe5  893d54da7c00           -mov dword ptr [0x7cda54], edi
    app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */) = cpu.edi;
    // 004bcfeb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004bcfed  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bcfef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bcff1  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 004bcff7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcff8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcff9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcffa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcffb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcffc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bd000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd002  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd003  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd004  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bd005  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd006  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bd008  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd00a  e89126fdff             -call 0x48f6a0
    cpu.esp -= 4;
    sub_48f6a0(app, cpu);
    if (cpu.terminate) return;
    // 004bd00f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004bd016  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bd018  8b90303e7a00           -mov edx, dword ptr [eax + 0x7a3e30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8011312) /* 0x7a3e30 */);
    // 004bd01e  42                     -inc edx
    (cpu.edx)++;
    // 004bd01f  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 004bd022  8a1da8c47900           -mov bl, byte ptr [0x79c4a8]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(7980200) /* 0x79c4a8 */);
    // 004bd028  889c3247d57c00         -mov byte ptr [edx + esi + 0x7cd547], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8181063) /* 0x7cd547 */ + cpu.esi * 1) = cpu.bl;
    // 004bd02f  8a1da9c47900           -mov bl, byte ptr [0x79c4a9]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(7980201) /* 0x79c4a9 */);
    // 004bd035  889c3267d57c00         -mov byte ptr [edx + esi + 0x7cd567], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8181095) /* 0x7cd567 */ + cpu.esi * 1) = cpu.bl;
    // 004bd03c  8a1daac47900           -mov bl, byte ptr [0x79c4aa]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(7980202) /* 0x79c4aa */);
    // 004bd042  889c3287d57c00         -mov byte ptr [edx + esi + 0x7cd587], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8181127) /* 0x7cd587 */ + cpu.esi * 1) = cpu.bl;
    // 004bd049  8a1dabc47900           -mov bl, byte ptr [0x79c4ab]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(7980203) /* 0x79c4ab */);
    // 004bd04f  8990303e7a00           -mov dword ptr [eax + 0x7a3e30], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8011312) /* 0x7a3e30 */) = cpu.edx;
    // 004bd055  889c32a7d57c00         -mov byte ptr [edx + esi + 0x7cd5a7], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8181159) /* 0x7cd5a7 */ + cpu.esi * 1) = cpu.bl;
    // 004bd05c  83fa20                 +cmp edx, 0x20
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
    // 004bd05f  751f                   -jne 0x4bd080
    if (!cpu.flags.zf)
    {
        goto L_0x004bd080;
    }
    // 004bd061  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bd063  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004bd069  8db648d57c00           -lea esi, [esi + 0x7cd548]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(8181064) /* 0x7cd548 */);
    // 004bd06f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bd071  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004bd073  8998303e7a00           -mov dword ptr [eax + 0x7a3e30], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8011312) /* 0x7a3e30 */) = cpu.ebx;
    // 004bd079  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bd07b  e820fdffff             -call 0x4bcda0
    cpu.esp -= 4;
    sub_4bcda0(app, cpu);
    if (cpu.terminate) return;
L_0x004bd080:
    // 004bd080  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd081  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd082  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd083  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd084  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd085  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd086  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4bd090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd090  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd091  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd092  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd093  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd094  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bd095  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd096  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bd098  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004bd09e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd0a0  833c85303e7a0000       +cmp dword ptr [eax*4 + 0x7a3e30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011312) /* 0x7a3e30 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd0a8  7537                   -jne 0x4bd0e1
    if (!cpu.flags.zf)
    {
        goto L_0x004bd0e1;
    }
    // 004bd0aa  a154da7c00             -mov eax, dword ptr [0x7cda54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182356) /* 0x7cda54 */);
    // 004bd0af  80b8485f7a0000         +cmp byte ptr [eax + 0x7a5f48], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8019784) /* 0x7a5f48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bd0b6  750c                   -jne 0x4bd0c4
    if (!cpu.flags.zf)
    {
        goto L_0x004bd0c4;
    }
    // 004bd0b8  c70558da7c0004000000   -mov dword ptr [0x7cda58], 4
    app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */) = 4 /*0x4*/;
    // 004bd0c2  eb1d                   -jmp 0x4bd0e1
    goto L_0x004bd0e1;
L_0x004bd0c4:
    // 004bd0c4  8d7580                 -lea esi, [ebp - 0x80]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-128) /* -0x80 */);
    // 004bd0c7  e814feffff             -call 0x4bcee0
    cpu.esp -= 4;
    sub_4bcee0(app, cpu);
    if (cpu.terminate) return;
    // 004bd0cc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd0ce  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004bd0d3  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004bd0d6  8d7580                 -lea esi, [ebp - 0x80]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-128) /* -0x80 */);
    // 004bd0d9  8db848d57c00           -lea edi, [eax + 0x7cd548]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(8181064) /* 0x7cd548 */);
    // 004bd0df  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004bd0e1:
    // 004bd0e1  8b3558da7c00           -mov esi, dword ptr [0x7cda58]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */);
    // 004bd0e7  83fe02                 +cmp esi, 2
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
    // 004bd0ea  753f                   -jne 0x4bd12b
    if (!cpu.flags.zf)
    {
        goto L_0x004bd12b;
    }
    // 004bd0ec  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bd0ee  8b0495303e7a00         -mov eax, dword ptr [edx*4 + 0x7a3e30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8011312) /* 0x7a3e30 */ + cpu.edx * 4);
    // 004bd0f5  c1e107                 -shl ecx, 7
    cpu.ecx <<= 7 /*0x7*/ % 32;
    // 004bd0f8  01c8                   +add eax, ecx
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
    // 004bd0fa  8a8848d57c00           -mov cl, byte ptr [eax + 0x7cd548]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8181064) /* 0x7cd548 */);
    // 004bd100  880da8c47900           -mov byte ptr [0x79c4a8], cl
    app->getMemory<x86::reg8>(x86::reg32(7980200) /* 0x79c4a8 */) = cpu.cl;
    // 004bd106  8a8868d57c00           -mov cl, byte ptr [eax + 0x7cd568]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8181096) /* 0x7cd568 */);
    // 004bd10c  880da9c47900           -mov byte ptr [0x79c4a9], cl
    app->getMemory<x86::reg8>(x86::reg32(7980201) /* 0x79c4a9 */) = cpu.cl;
    // 004bd112  8a8888d57c00           -mov cl, byte ptr [eax + 0x7cd588]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8181128) /* 0x7cd588 */);
    // 004bd118  8a80a8d57c00           -mov al, byte ptr [eax + 0x7cd5a8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8181160) /* 0x7cd5a8 */);
    // 004bd11e  880daac47900           -mov byte ptr [0x79c4aa], cl
    app->getMemory<x86::reg8>(x86::reg32(7980202) /* 0x79c4aa */) = cpu.cl;
    // 004bd124  a2abc47900             -mov byte ptr [0x79c4ab], al
    app->getMemory<x86::reg8>(x86::reg32(7980203) /* 0x79c4ab */) = cpu.al;
    // 004bd129  eb1f                   -jmp 0x4bd14a
    goto L_0x004bd14a;
L_0x004bd12b:
    // 004bd12b  83fe03                 +cmp esi, 3
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
    // 004bd12e  751a                   -jne 0x4bd14a
    if (!cpu.flags.zf)
    {
        goto L_0x004bd14a;
    }
    // 004bd130  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004bd132  883da9c47900           -mov byte ptr [0x79c4a9], bh
    app->getMemory<x86::reg8>(x86::reg32(7980201) /* 0x79c4a9 */) = cpu.bh;
    // 004bd138  883daac47900           -mov byte ptr [0x79c4aa], bh
    app->getMemory<x86::reg8>(x86::reg32(7980202) /* 0x79c4aa */) = cpu.bh;
    // 004bd13e  883dabc47900           -mov byte ptr [0x79c4ab], bh
    app->getMemory<x86::reg8>(x86::reg32(7980203) /* 0x79c4ab */) = cpu.bh;
    // 004bd144  883da8c47900           -mov byte ptr [0x79c4a8], bh
    app->getMemory<x86::reg8>(x86::reg32(7980200) /* 0x79c4a8 */) = cpu.bh;
L_0x004bd14a:
    // 004bd14a  8b0495303e7a00         -mov eax, dword ptr [edx*4 + 0x7a3e30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8011312) /* 0x7a3e30 */ + cpu.edx * 4);
    // 004bd151  40                     -inc eax
    (cpu.eax)++;
    // 004bd152  8b0db0d36f00           -mov ecx, dword ptr [0x6fd3b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 004bd158  890495303e7a00         -mov dword ptr [edx*4 + 0x7a3e30], eax
    app->getMemory<x86::reg32>(x86::reg32(8011312) /* 0x7a3e30 */ + cpu.edx * 4) = cpu.eax;
    // 004bd15f  83f902                 +cmp ecx, 2
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
    // 004bd162  7c08                   -jl 0x4bd16c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd16c;
    }
    // 004bd164  3b15f4d46f00           +cmp edx, dword ptr [0x6fd4f4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd16a  740a                   -je 0x4bd176
    if (cpu.flags.zf)
    {
        goto L_0x004bd176;
    }
L_0x004bd16c:
    // 004bd16c  8b35b0d36f00           -mov esi, dword ptr [0x6fd3b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 004bd172  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bd174  751b                   -jne 0x4bd191
    if (!cpu.flags.zf)
    {
        goto L_0x004bd191;
    }
L_0x004bd176:
    // 004bd176  833d68d97c0000         +cmp dword ptr [0x7cd968], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8182120) /* 0x7cd968 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd17d  743f                   -je 0x4bd1be
    if (cpu.flags.zf)
    {
        goto L_0x004bd1be;
    }
    // 004bd17f  833d80367d0000         +cmp dword ptr [0x7d3680], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8205952) /* 0x7d3680 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd186  7436                   -je 0x4bd1be
    if (cpu.flags.zf)
    {
        goto L_0x004bd1be;
    }
    // 004bd188  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bd18a  e8e10b0000             -call 0x4bdd70
    cpu.esp -= 4;
    sub_4bdd70(app, cpu);
    if (cpu.terminate) return;
    // 004bd18f  eb2d                   -jmp 0x4bd1be
    goto L_0x004bd1be;
L_0x004bd191:
    // 004bd191  83fe01                 +cmp esi, 1
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
    // 004bd194  7528                   -jne 0x4bd1be
    if (!cpu.flags.zf)
    {
        goto L_0x004bd1be;
    }
    // 004bd196  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004bd19d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bd19f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd1a2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bd1a4  833c8568d97c0000       +cmp dword ptr [eax*4 + 0x7cd968], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8182120) /* 0x7cd968 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd1ac  7410                   -je 0x4bd1be
    if (cpu.flags.zf)
    {
        goto L_0x004bd1be;
    }
    // 004bd1ae  833d80367d0000         +cmp dword ptr [0x7d3680], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8205952) /* 0x7d3680 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd1b5  7407                   -je 0x4bd1be
    if (cpu.flags.zf)
    {
        goto L_0x004bd1be;
    }
    // 004bd1b7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd1b9  e8b20b0000             -call 0x4bdd70
    cpu.esp -= 4;
    sub_4bdd70(app, cpu);
    if (cpu.terminate) return;
L_0x004bd1be:
    // 004bd1be  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004bd1c5  83b8303e7a0020         +cmp dword ptr [eax + 0x7a3e30], 0x20
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8011312) /* 0x7a3e30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd1cc  7508                   -jne 0x4bd1d6
    if (!cpu.flags.zf)
    {
        goto L_0x004bd1d6;
    }
    // 004bd1ce  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bd1d0  8990303e7a00           -mov dword ptr [eax + 0x7a3e30], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8011312) /* 0x7a3e30 */) = cpu.edx;
L_0x004bd1d6:
    // 004bd1d6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bd1d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd1d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd1da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd1db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd1dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd1dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd1de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bd1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd1e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd1e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd1e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd1e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd1e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bd1e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd1e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bd1e8  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004bd1eb  833dacd36f0000         +cmp dword ptr [0x6fd3ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328684) /* 0x6fd3ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd1f2  0f84d2000000           -je 0x4bd2ca
    if (cpu.flags.zf)
    {
        goto L_0x004bd2ca;
    }
    // 004bd1f8  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004bd1ff  7e0d                   -jle 0x4bd20e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd20e;
    }
    // 004bd201  833d0cd56f0000         +cmp dword ptr [0x6fd50c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd208  0f85bc000000           -jne 0x4bd2ca
    if (!cpu.flags.zf)
    {
        goto L_0x004bd2ca;
    }
L_0x004bd20e:
    // 004bd20e  e82d1e0100             -call 0x4cf040
    cpu.esp -= 4;
    sub_4cf040(app, cpu);
    if (cpu.terminate) return;
    // 004bd213  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd215  0f85af000000           -jne 0x4bd2ca
    if (!cpu.flags.zf)
    {
        goto L_0x004bd2ca;
    }
    // 004bd21b  6868015400             -push 0x540168
    app->getMemory<x86::reg32>(cpu.esp-4) = 5505384 /*0x540168*/;
    cpu.esp -= 4;
    // 004bd220  8d45c4                 -lea eax, [ebp - 0x3c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004bd223  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bd224  e867240200             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004bd229  8b3558da7c00           -mov esi, dword ptr [0x7cda58]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */);
    // 004bd22f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bd232  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bd234  750a                   -jne 0x4bd240
    if (!cpu.flags.zf)
    {
        goto L_0x004bd240;
    }
    // 004bd236  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004bd23b  a340fe5500             -mov dword ptr [0x55fe40], eax
    app->getMemory<x86::reg32>(x86::reg32(5635648) /* 0x55fe40 */) = cpu.eax;
L_0x004bd240:
    // 004bd240  b93c080000             -mov ecx, 0x83c
    cpu.ecx = 2108 /*0x83c*/;
    // 004bd245  bf503e7a00             -mov edi, 0x7a3e50
    cpu.edi = 8011344 /*0x7a3e50*/;
    // 004bd24a  be40bb6f00             -mov esi, 0x6fbb40
    cpu.esi = 7322432 /*0x6fbb40*/;
    // 004bd24f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bd251  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004bd256  a100d05500             -mov eax, dword ptr [0x55d000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5623808) /* 0x55d000 */);
    // 004bd25b  893db0567a00           -mov dword ptr [0x7a56b0], edi
    app->getMemory<x86::reg32>(x86::reg32(8017584) /* 0x7a56b0 */) = cpu.edi;
    // 004bd261  83f801                 +cmp eax, 1
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
    // 004bd264  7402                   -je 0x4bd268
    if (cpu.flags.zf)
    {
        goto L_0x004bd268;
    }
    // 004bd266  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bd268:
    // 004bd268  a3405f7a00             -mov dword ptr [0x7a5f40], eax
    app->getMemory<x86::reg32>(x86::reg32(8019776) /* 0x7a5f40 */) = cpu.eax;
    // 004bd26d  a140fe5500             -mov eax, dword ptr [0x55fe40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635648) /* 0x55fe40 */);
    // 004bd272  a3445f7a00             -mov dword ptr [0x7a5f44], eax
    app->getMemory<x86::reg32>(x86::reg32(8019780) /* 0x7a5f44 */) = cpu.eax;
    // 004bd277  b8503e7a00             -mov eax, 0x7a3e50
    cpu.eax = 8011344 /*0x7a3e50*/;
    // 004bd27c  bbf8960200             -mov ebx, 0x296f8
    cpu.ebx = 169720 /*0x296f8*/;
    // 004bd281  e88aadfbff             -call 0x478010
    cpu.esp -= 4;
    sub_478010(app, cpu);
    if (cpu.terminate) return;
    // 004bd286  b8503e7a00             -mov eax, 0x7a3e50
    cpu.eax = 8011344 /*0x7a3e50*/;
    // 004bd28b  ba503e7a00             -mov edx, 0x7a3e50
    cpu.edx = 8011344 /*0x7a3e50*/;
    // 004bd290  e81baffbff             -call 0x4781b0
    cpu.esp -= 4;
    sub_4781b0(app, cpu);
    if (cpu.terminate) return;
    // 004bd295  8d45c4                 -lea eax, [ebp - 0x3c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004bd298  e843180300             -call 0x4eeae0
    cpu.esp -= 4;
    sub_4eeae0(app, cpu);
    if (cpu.terminate) return;
    // 004bd29d  833d00d0550001         +cmp dword ptr [0x55d000], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5623808) /* 0x55d000 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd2a4  7524                   -jne 0x4bd2ca
    if (!cpu.flags.zf)
    {
        goto L_0x004bd2ca;
    }
    // 004bd2a6  ba74015400             -mov edx, 0x540174
    cpu.edx = 5505396 /*0x540174*/;
    // 004bd2ab  8d45c4                 -lea eax, [ebp - 0x3c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004bd2ae  e8350d0300             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 004bd2b3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bd2b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd2b7  7411                   -je 0x4bd2ca
    if (cpu.flags.zf)
    {
        goto L_0x004bd2ca;
    }
    // 004bd2b9  baf8960200             -mov edx, 0x296f8
    cpu.edx = 169720 /*0x296f8*/;
    // 004bd2be  e8fda7fbff             -call 0x477ac0
    cpu.esp -= 4;
    sub_477ac0(app, cpu);
    if (cpu.terminate) return;
    // 004bd2c3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bd2c5  e8360e0300             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x004bd2ca:
    // 004bd2ca  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bd2cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd2cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd2ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd2cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd2d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd2d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd2d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4bd2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd2e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd2e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd2e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd2e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd2e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd2e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bd2e7  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 004bd2ea  6868015400             -push 0x540168
    app->getMemory<x86::reg32>(cpu.esp-4) = 5505384 /*0x540168*/;
    cpu.esp -= 4;
    // 004bd2ef  8d45a4                 -lea eax, [ebp - 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 004bd2f2  8d4df8                 -lea ecx, [ebp - 8]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bd2f5  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bd2f8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bd2fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bd2fb  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004bd2fe  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004bd301  e88a230200             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004bd306  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bd309  8d55f4                 -lea edx, [ebp - 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bd30c  8d45a4                 -lea eax, [ebp - 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 004bd30f  e8bc550200             -call 0x4e28d0
    cpu.esp -= 4;
    sub_4e28d0(app, cpu);
    if (cpu.terminate) return;
    // 004bd314  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bd317  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004bd31c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bd31e  7508                   -jne 0x4bd328
    if (!cpu.flags.zf)
    {
        goto L_0x004bd328;
    }
    // 004bd320  891d58da7c00           -mov dword ptr [0x7cda58], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */) = cpu.ebx;
    // 004bd326  eb49                   -jmp 0x4bd371
    goto L_0x004bd371;
L_0x004bd328:
    // 004bd328  bbf8960200             -mov ebx, 0x296f8
    cpu.ebx = 169720 /*0x296f8*/;
    // 004bd32d  ba503e7a00             -mov edx, 0x7a3e50
    cpu.edx = 8011344 /*0x7a3e50*/;
    // 004bd332  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bd335  e8a65a0200             -call 0x4e2de0
    cpu.esp -= 4;
    sub_4e2de0(app, cpu);
    if (cpu.terminate) return;
    // 004bd33a  833d405f7a0000         +cmp dword ptr [0x7a5f40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8019776) /* 0x7a5f40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd341  7408                   -je 0x4bd34b
    if (cpu.flags.zf)
    {
        goto L_0x004bd34b;
    }
    // 004bd343  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bd346  e8b5a7fbff             -call 0x477b00
    cpu.esp -= 4;
    sub_477b00(app, cpu);
    if (cpu.terminate) return;
L_0x004bd34b:
    // 004bd34b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004bd34e  e84d5a0200             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004bd353  b8503e7a00             -mov eax, 0x7a3e50
    cpu.eax = 8011344 /*0x7a3e50*/;
    // 004bd358  e833adfbff             -call 0x478090
    cpu.esp -= 4;
    sub_478090(app, cpu);
    if (cpu.terminate) return;
    // 004bd35d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd35f  7502                   -jne 0x4bd363
    if (!cpu.flags.zf)
    {
        goto L_0x004bd363;
    }
    // 004bd361  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004bd363:
    // 004bd363  b8503e7a00             -mov eax, 0x7a3e50
    cpu.eax = 8011344 /*0x7a3e50*/;
    // 004bd368  e893adfbff             -call 0x478100
    cpu.esp -= 4;
    sub_478100(app, cpu);
    if (cpu.terminate) return;
    // 004bd36d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd36f  7502                   -jne 0x4bd373
    if (!cpu.flags.zf)
    {
        goto L_0x004bd373;
    }
L_0x004bd371:
    // 004bd371  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004bd373:
    // 004bd373  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bd375  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bd377  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd378  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd379  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd37a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd37b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd37c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bd380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd380  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd381  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd382  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd383  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd384  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bd386  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd388  a1f4d46f00             -mov eax, dword ptr [0x6fd4f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 004bd38d  8b0c8548fa5e00         -mov ecx, dword ptr [eax*4 + 0x5efa48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.eax * 4);
    // 004bd394  39ca                   +cmp edx, ecx
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
    // 004bd396  7510                   -jne 0x4bd3a8
    if (!cpu.flags.zf)
    {
        goto L_0x004bd3a8;
    }
    // 004bd398  833da0d36f0000         +cmp dword ptr [0x6fd3a0], 0
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
    // 004bd39f  7507                   -jne 0x4bd3a8
    if (!cpu.flags.zf)
    {
        goto L_0x004bd3a8;
    }
    // 004bd3a1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bd3a3  e878a8fbff             -call 0x477c20
    cpu.esp -= 4;
    sub_477c20(app, cpu);
    if (cpu.terminate) return;
L_0x004bd3a8:
    // 004bd3a8  8b3558da7c00           -mov esi, dword ptr [0x7cda58]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */);
    // 004bd3ae  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bd3b0  7405                   -je 0x4bd3b7
    if (cpu.flags.zf)
    {
        goto L_0x004bd3b7;
    }
    // 004bd3b2  83fe01                 +cmp esi, 1
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
    // 004bd3b5  7515                   -jne 0x4bd3cc
    if (!cpu.flags.zf)
    {
        goto L_0x004bd3cc;
    }
L_0x004bd3b7:
    // 004bd3b7  8b82f4010000           -mov eax, dword ptr [edx + 0x1f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(500) /* 0x1f4 */);
    // 004bd3bd  e83efcffff             -call 0x4bd000
    cpu.esp -= 4;
    sub_4bd000(app, cpu);
    if (cpu.terminate) return;
    // 004bd3c2  e839060000             -call 0x4bda00
    cpu.esp -= 4;
    sub_4bda00(app, cpu);
    if (cpu.terminate) return;
    // 004bd3c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd3c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd3c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd3ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd3cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bd3cc:
    // 004bd3cc  8b82f4010000           -mov eax, dword ptr [edx + 0x1f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(500) /* 0x1f4 */);
    // 004bd3d2  e8b9fcffff             -call 0x4bd090
    cpu.esp -= 4;
    sub_4bd090(app, cpu);
    if (cpu.terminate) return;
    // 004bd3d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd3d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd3d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd3da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd3db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4bd3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004bd3f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd3f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd3f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd3f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bd3f5  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004bd3f8  8b15dc977400           -mov edx, dword ptr [0x7497dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7641052) /* 0x7497dc */);
    // 004bd3fe  8b0de4977400           -mov ecx, dword ptr [0x7497e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7641060) /* 0x7497e4 */);
    // 004bd404  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd406  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004bd409  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004bd40c  d80d78015400           -fmul dword ptr [0x540178]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5505400) /* 0x540178 */));
    // 004bd412  db05e0977400           -fild dword ptr [0x7497e0]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7641056) /* 0x7497e0 */))));
    // 004bd418  db05d8977400           -fild dword ptr [0x7497d8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7641048) /* 0x7497d8 */))));
    // 004bd41e  d95df4                 -fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd421  d955ec                 -fst dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    // 004bd424  d865f4                 -fsub dword ptr [ebp - 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */));
    // 004bd427  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004bd429  dc0d80015400           -fmul qword ptr [0x540180]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5505408) /* 0x540180 */));
    // 004bd42f  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004bd431  dc0d88015400           -fmul qword ptr [0x540188]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5505416) /* 0x540188 */));
    // 004bd437  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bd439  dc0d90015400           -fmul qword ptr [0x540190]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5505424) /* 0x540190 */));
    // 004bd43f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004bd441  d95de0                 -fstp dword ptr [ebp - 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd444  db05d8977400           -fild dword ptr [0x7497d8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7641048) /* 0x7497d8 */))));
    // 004bd44a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bd44c  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004bd44e  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bd450  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004bd452  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004bd454  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bd456  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bd458  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd45b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bd45d  d95de8                 -fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd460  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd463  83f803                 +cmp eax, 3
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
    // 004bd466  772e                   -ja 0x4bd496
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bd496;
    }
    // 004bd468  ff2485dcd34b00         -jmp dword ptr [eax*4 + 0x4bd3dc]
    cpu.ip = app->getMemory<x86::reg32>(4969436 + cpu.eax * 4); goto dynamic_jump;
  case 0x004bd46f:
    // 004bd46f  d945f0                 +fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 004bd472  d845f4                 +fadd dword ptr [ebp - 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */));
    // 004bd475  eb16                   -jmp 0x4bd48d
    goto L_0x004bd48d;
  case 0x004bd477:
    // 004bd477  d945e8                 +fld dword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 004bd47a  d845f0                 +fadd dword ptr [ebp - 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 004bd47d  eb0e                   -jmp 0x4bd48d
    goto L_0x004bd48d;
  case 0x004bd47f:
    // 004bd47f  d945e4                 +fld dword ptr [ebp - 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 004bd482  d845e8                 +fadd dword ptr [ebp - 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */));
    // 004bd485  eb06                   -jmp 0x4bd48d
    goto L_0x004bd48d;
  case 0x004bd487:
    // 004bd487  d945ec                 -fld dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004bd48a  d845e4                 -fadd dword ptr [ebp - 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
L_0x004bd48d:
    // 004bd48d  d80d78015400           -fmul dword ptr [0x540178]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5505400) /* 0x540178 */));
    // 004bd493  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004bd496:
    // 004bd496  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004bd499  d945e0                 -fld dword ptr [ebp - 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 004bd49c  e8b5280200             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004bd4a1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bd4a3  e8ae280200             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004bd4a8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bd4aa  db5ddc                 -fistp dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004bd4ad  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004bd4b0  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004bd4b3  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bd4b6  e805ebfdff             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
    // 004bd4bb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bd4bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd4be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd4bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd4c0  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4bd4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd4d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd4d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd4d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd4d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd4d4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bd4d6  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004bd4d9  db05d8977400           -fild dword ptr [0x7497d8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7641048) /* 0x7497d8 */))));
    // 004bd4df  db05e0977400           -fild dword ptr [0x7497e0]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7641056) /* 0x7497e0 */))));
    // 004bd4e5  db05dc977400           -fild dword ptr [0x7497dc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7641052) /* 0x7497dc */))));
    // 004bd4eb  db05e4977400           -fild dword ptr [0x7497e4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7641060) /* 0x7497e4 */))));
    // 004bd4f1  8d5dd0                 -lea ebx, [ebp - 0x30]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004bd4f4  8d55cc                 -lea edx, [ebp - 0x34]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bd4f7  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004bd4fa  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004bd4fc  d95df4                 -fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd4ff  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bd501  d95dec                 -fstp dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd504  d95de0                 -fstp dword ptr [ebp - 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd507  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd509  d95de8                 -fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd50c  e8ff7df7ff             -call 0x435310
    cpu.esp -= 4;
    sub_435310(app, cpu);
    if (cpu.terminate) return;
    // 004bd511  8d55d8                 -lea edx, [ebp - 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004bd514  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004bd517  e8f4d50100             -call 0x4dab10
    cpu.esp -= 4;
    sub_4dab10(app, cpu);
    if (cpu.terminate) return;
    // 004bd51c  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004bd51f  2b45d4                 -sub eax, dword ptr [ebp - 0x2c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    // 004bd522  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004bd525  8b4dd8                 -mov ecx, dword ptr [ebp - 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004bd528  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004bd52b  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004bd52e  29c8                   +sub eax, ecx
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
    // 004bd530  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004bd533  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bd534  d95df8                 +fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd537  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004bd53a  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004bd53d  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004bd540  d95df0                 +fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd543  d85df4                 +fcomp dword ptr [ebp - 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    cpu.fpu.pop();
    // 004bd546  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004bd548  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004bd549  7228                   -jb 0x4bd573
    if (cpu.flags.cf)
    {
        goto L_0x004bd573;
    }
    // 004bd54b  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004bd54e  d85dec                 +fcomp dword ptr [ebp - 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    cpu.fpu.pop();
    // 004bd551  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004bd553  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004bd554  771d                   -ja 0x4bd573
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bd573;
    }
    // 004bd556  d945f0                 +fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 004bd559  d85de0                 +fcomp dword ptr [ebp - 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    cpu.fpu.pop();
    // 004bd55c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004bd55e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004bd55f  7212                   -jb 0x4bd573
    if (cpu.flags.cf)
    {
        goto L_0x004bd573;
    }
    // 004bd561  d945f0                 +fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 004bd564  d85de8                 +fcomp dword ptr [ebp - 0x18]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    cpu.fpu.pop();
    // 004bd567  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004bd569  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004bd56a  7707                   -ja 0x4bd573
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bd573;
    }
    // 004bd56c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bd571  eb02                   -jmp 0x4bd575
    goto L_0x004bd575;
L_0x004bd573:
    // 004bd573  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bd575:
    // 004bd575  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd577  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd579  0f8482000000           -je 0x4bd601
    if (cpu.flags.zf)
    {
        goto L_0x004bd601;
    }
    // 004bd57f  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 004bd582  d945ec                 +fld dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004bd585  d8e1                   +fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 004bd587  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004bd589  dc0d98015400           +fmul qword ptr [0x540198]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5505432) /* 0x540198 */));
    // 004bd58f  d9c1                   +fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004bd591  dc0da0015400           +fmul qword ptr [0x5401a0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5505440) /* 0x5401a0 */));
    // 004bd597  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bd599  dc0da8015400           +fmul qword ptr [0x5401a8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5505448) /* 0x5401a8 */));
    // 004bd59f  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004bd5a2  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bd5a4  d8c4                   +fadd st(4)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(4));
    // 004bd5a6  d9cb                   +fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004bd5a8  d8c4                   +fadd st(4)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(4));
    // 004bd5aa  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bd5ac  dec4                   +faddp st(4)
    cpu.fpu.st(4) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bd5ae  d95de4                 +fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd5b1  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bd5b3  d95ddc                 +fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bd5b6  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bd5b8  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004bd5ba  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004bd5bc  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004bd5bd  730a                   -jae 0x4bd5c9
    if (!cpu.flags.cf)
    {
        goto L_0x004bd5c9;
    }
    // 004bd5bf  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004bd5c1  891d58d97c00           -mov dword ptr [0x7cd958], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */) = cpu.ebx;
    // 004bd5c7  eb38                   -jmp 0x4bd601
    goto L_0x004bd601;
L_0x004bd5c9:
    // 004bd5c9  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004bd5cc  d85de4                 +fcomp dword ptr [ebp - 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    cpu.fpu.pop();
    // 004bd5cf  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004bd5d1  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004bd5d2  730c                   -jae 0x4bd5e0
    if (!cpu.flags.cf)
    {
        goto L_0x004bd5e0;
    }
    // 004bd5d4  c70558d97c0001000000   -mov dword ptr [0x7cd958], 1
    app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */) = 1 /*0x1*/;
    // 004bd5de  eb21                   -jmp 0x4bd601
    goto L_0x004bd601;
L_0x004bd5e0:
    // 004bd5e0  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004bd5e3  d85ddc                 +fcomp dword ptr [ebp - 0x24]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    cpu.fpu.pop();
    // 004bd5e6  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004bd5e8  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004bd5e9  730c                   -jae 0x4bd5f7
    if (!cpu.flags.cf)
    {
        goto L_0x004bd5f7;
    }
    // 004bd5eb  c70558d97c0002000000   -mov dword ptr [0x7cd958], 2
    app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */) = 2 /*0x2*/;
    // 004bd5f5  eb0a                   -jmp 0x4bd601
    goto L_0x004bd601;
L_0x004bd5f7:
    // 004bd5f7  c70558d97c0003000000   -mov dword ptr [0x7cd958], 3
    app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */) = 3 /*0x3*/;
L_0x004bd601:
    // 004bd601  8b4dc8                 -mov ecx, dword ptr [ebp - 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004bd604  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bd606  741e                   -je 0x4bd626
    if (cpu.flags.zf)
    {
        goto L_0x004bd626;
    }
    // 004bd608  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bd60a  741a                   -je 0x4bd626
    if (cpu.flags.zf)
    {
        goto L_0x004bd626;
    }
    // 004bd60c  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004bd611  3b05bcfe5500           +cmp eax, dword ptr [0x55febc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5635772) /* 0x55febc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd617  7e0d                   -jle 0x4bd626
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd626;
    }
    // 004bd619  83c020                 +add eax, 0x20
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bd61c  a3bcfe5500             -mov dword ptr [0x55febc], eax
    app->getMemory<x86::reg32>(x86::reg32(5635772) /* 0x55febc */) = cpu.eax;
    // 004bd621  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004bd624  eb02                   -jmp 0x4bd628
    goto L_0x004bd628;
L_0x004bd626:
    // 004bd626  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bd628:
    // 004bd628  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bd62a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd62b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd62c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd62d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd62e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bd640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004bd640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd641  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd642  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd643  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd644  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bd645  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd646  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bd648  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004bd64d  3b1db0d36f00           +cmp ebx, dword ptr [0x6fd3b0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd653  7505                   -jne 0x4bd65a
    if (!cpu.flags.zf)
    {
        goto L_0x004bd65a;
    }
    // 004bd655  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x004bd65a:
    // 004bd65a  8b0d64d97c00           -mov ecx, dword ptr [0x7cd964]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182116) /* 0x7cd964 */);
    // 004bd660  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bd662  7e58                   -jle 0x4bd6bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd6bc;
    }
    // 004bd664  833d60d97c0000         +cmp dword ptr [0x7cd960], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8182112) /* 0x7cd960 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd66b  744f                   -je 0x4bd6bc
    if (cpu.flags.zf)
    {
        goto L_0x004bd6bc;
    }
    // 004bd66d  890d54d97c00           -mov dword ptr [0x7cd954], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */) = cpu.ecx;
    // 004bd673  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004bd675:
    // 004bd675  39d9                   +cmp ecx, ebx
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
    // 004bd677  7d43                   -jge 0x4bd6bc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd6bc;
    }
    // 004bd679  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bd67b  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 004bd682  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd684  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd687  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd689  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bd68b  893c8568d97c00         -mov dword ptr [eax*4 + 0x7cd968], edi
    app->getMemory<x86::reg32>(x86::reg32(8182120) /* 0x7cd968 */ + cpu.eax * 4) = cpu.edi;
    // 004bd692  a154d97c00             -mov eax, dword ptr [0x7cd954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */);
    // 004bd697  8b048544fe5500         -mov eax, dword ptr [eax*4 + 0x55fe44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635652) /* 0x55fe44 */ + cpu.eax * 4);
    // 004bd69e  e86d4ff6ff             -call 0x422610
    cpu.esp -= 4;
    sub_422610(app, cpu);
    if (cpu.terminate) return;
    // 004bd6a3  a154d97c00             -mov eax, dword ptr [0x7cd954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */);
    // 004bd6a8  833c8544fe550009       +cmp dword ptr [eax*4 + 0x55fe44], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5635652) /* 0x55fe44 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd6b0  7507                   -jne 0x4bd6b9
    if (!cpu.flags.zf)
    {
        goto L_0x004bd6b9;
    }
    // 004bd6b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bd6b4  e8d73df6ff             -call 0x421490
    cpu.esp -= 4;
    sub_421490(app, cpu);
    if (cpu.terminate) return;
L_0x004bd6b9:
    // 004bd6b9  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bd6ba  ebb9                   -jmp 0x4bd675
    goto L_0x004bd675;
L_0x004bd6bc:
    // 004bd6bc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd6be  8b355cd97c00           -mov esi, dword ptr [0x7cd95c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182108) /* 0x7cd95c */);
    // 004bd6c4  890d60d97c00           -mov dword ptr [0x7cd960], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182112) /* 0x7cd960 */) = cpu.ecx;
    // 004bd6ca  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bd6cc  7e0e                   -jle 0x4bd6dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd6dc;
    }
    // 004bd6ce  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 004bd6d1  893d5cd97c00           -mov dword ptr [0x7cd95c], edi
    app->getMemory<x86::reg32>(x86::reg32(8182108) /* 0x7cd95c */) = cpu.edi;
    // 004bd6d7  e9d9020000             -jmp 0x4bd9b5
    goto L_0x004bd9b5;
L_0x004bd6dc:
    // 004bd6dc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bd6e1  b84b000000             -mov eax, 0x4b
    cpu.eax = 75 /*0x4b*/;
    // 004bd6e6  e8e521fdff             -call 0x48f8d0
    cpu.esp -= 4;
    sub_48f8d0(app, cpu);
    if (cpu.terminate) return;
    // 004bd6eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd6ed  7421                   -je 0x4bd710
    if (cpu.flags.zf)
    {
        goto L_0x004bd710;
    }
    // 004bd6ef  a158d97c00             -mov eax, dword ptr [0x7cd958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */);
    // 004bd6f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd6f6  7e09                   -jle 0x4bd701
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd701;
    }
    // 004bd6f8  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004bd6fb  891558d97c00           -mov dword ptr [0x7cd958], edx
    app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */) = cpu.edx;
L_0x004bd701:
    // 004bd701  a158d97c00             -mov eax, dword ptr [0x7cd958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */);
    // 004bd706  e8e5fcffff             -call 0x4bd3f0
    cpu.esp -= 4;
    sub_4bd3f0(app, cpu);
    if (cpu.terminate) return;
    // 004bd70b  e9a5020000             -jmp 0x4bd9b5
    goto L_0x004bd9b5;
L_0x004bd710:
    // 004bd710  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bd715  b84d000000             -mov eax, 0x4d
    cpu.eax = 77 /*0x4d*/;
    // 004bd71a  e8b121fdff             -call 0x48f8d0
    cpu.esp -= 4;
    sub_48f8d0(app, cpu);
    if (cpu.terminate) return;
    // 004bd71f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd721  7423                   -je 0x4bd746
    if (cpu.flags.zf)
    {
        goto L_0x004bd746;
    }
    // 004bd723  8b0d58d97c00           -mov ecx, dword ptr [0x7cd958]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */);
    // 004bd729  83f903                 +cmp ecx, 3
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
    // 004bd72c  7d09                   -jge 0x4bd737
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd737;
    }
    // 004bd72e  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004bd731  891d58d97c00           -mov dword ptr [0x7cd958], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */) = cpu.ebx;
L_0x004bd737:
    // 004bd737  a158d97c00             -mov eax, dword ptr [0x7cd958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */);
    // 004bd73c  e8affcffff             -call 0x4bd3f0
    cpu.esp -= 4;
    sub_4bd3f0(app, cpu);
    if (cpu.terminate) return;
    // 004bd741  e96f020000             -jmp 0x4bd9b5
    goto L_0x004bd9b5;
L_0x004bd746:
    // 004bd746  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bd74b  b850000000             -mov eax, 0x50
    cpu.eax = 80 /*0x50*/;
    // 004bd750  e87b21fdff             -call 0x48f8d0
    cpu.esp -= 4;
    sub_48f8d0(app, cpu);
    if (cpu.terminate) return;
    // 004bd755  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd757  0f841a010000           -je 0x4bd877
    if (cpu.flags.zf)
    {
        goto L_0x004bd877;
    }
    // 004bd75d  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 004bd762  a158d97c00             -mov eax, dword ptr [0x7cd958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */);
    // 004bd767  89355cd97c00           -mov dword ptr [0x7cd95c], esi
    app->getMemory<x86::reg32>(x86::reg32(8182108) /* 0x7cd95c */) = cpu.esi;
    // 004bd76d  83f801                 +cmp eax, 1
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
    // 004bd770  7214                   -jb 0x4bd786
    if (cpu.flags.cf)
    {
        goto L_0x004bd786;
    }
    // 004bd772  0f86db000000           -jbe 0x4bd853
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bd853;
    }
    // 004bd778  83f802                 +cmp eax, 2
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
    // 004bd77b  0f84c6000000           -je 0x4bd847
    if (cpu.flags.zf)
    {
        goto L_0x004bd847;
    }
    // 004bd781  e92f020000             -jmp 0x4bd9b5
    goto L_0x004bd9b5;
L_0x004bd786:
    // 004bd786  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd788  0f8527020000           -jne 0x4bd9b5
    if (!cpu.flags.zf)
    {
        goto L_0x004bd9b5;
    }
    // 004bd78e  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004bd793  a154d97c00             -mov eax, dword ptr [0x7cd954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */);
    // 004bd798  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bd79a  893d60d97c00           -mov dword ptr [0x7cd960], edi
    app->getMemory<x86::reg32>(x86::reg32(8182112) /* 0x7cd960 */) = cpu.edi;
    // 004bd7a0  a354d97c00             -mov dword ptr [0x7cd954], eax
    app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */) = cpu.eax;
    // 004bd7a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd7a7  7d06                   -jge 0x4bd7af
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd7af;
    }
    // 004bd7a9  893554d97c00           -mov dword ptr [0x7cd954], esi
    app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */) = cpu.esi;
L_0x004bd7af:
    // 004bd7af  a154d97c00             -mov eax, dword ptr [0x7cd954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */);
    // 004bd7b4  8b348544fe5500         -mov esi, dword ptr [eax*4 + 0x55fe44]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5635652) /* 0x55fe44 */ + cpu.eax * 4);
    // 004bd7bb  a364d97c00             -mov dword ptr [0x7cd964], eax
    app->getMemory<x86::reg32>(x86::reg32(8182116) /* 0x7cd964 */) = cpu.eax;
    // 004bd7c0  83fe0f                 +cmp esi, 0xf
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
    // 004bd7c3  0f85ec010000           -jne 0x4bd9b5
    if (!cpu.flags.zf)
    {
        goto L_0x004bd9b5;
    }
    // 004bd7c9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004bd7cb:
    // 004bd7cb  39d9                   +cmp ecx, ebx
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
    // 004bd7cd  0f8de2010000           -jge 0x4bd9b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd9b5;
    }
    // 004bd7d3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bd7d5  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 004bd7dc  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd7de  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd7e1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd7e3  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004bd7e8  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd7ea  893c8568d97c00         -mov dword ptr [eax*4 + 0x7cd968], edi
    app->getMemory<x86::reg32>(x86::reg32(8182120) /* 0x7cd968 */ + cpu.eax * 4) = cpu.edi;
    // 004bd7f1  89148570d97c00         -mov dword ptr [eax*4 + 0x7cd970], edx
    app->getMemory<x86::reg32>(x86::reg32(8182128) /* 0x7cd970 */ + cpu.eax * 4) = cpu.edx;
    // 004bd7f8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bd7fa  8b149568fe5500         -mov edx, dword ptr [edx*4 + 0x55fe68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5635688) /* 0x55fe68 */ + cpu.edx * 4);
    // 004bd801  e8ba040000             -call 0x4bdcc0
    cpu.esp -= 4;
    sub_4bdcc0(app, cpu);
    if (cpu.terminate) return;
    // 004bd806  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bd808  eb05                   -jmp 0x4bd80f
    goto L_0x004bd80f;
L_0x004bd80a:
    // 004bd80a  83fa19                 +cmp edx, 0x19
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd80d  7d21                   -jge 0x4bd830
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd830;
    }
L_0x004bd80f:
    // 004bd80f  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 004bd816  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd818  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd81b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd81d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd820  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004bd825  89b49078d97c00         -mov dword ptr [eax + edx*4 + 0x7cd978], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8182136) /* 0x7cd978 */ + cpu.edx * 4) = cpu.esi;
    // 004bd82c  01f2                   +add edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bd82e  ebda                   -jmp 0x4bd80a
    goto L_0x004bd80a;
L_0x004bd830:
    // 004bd830  8b8070d97c00           -mov eax, dword ptr [eax + 0x7cd970]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8182128) /* 0x7cd970 */);
    // 004bd836  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bd838  8b048568fe5500         -mov eax, dword ptr [eax*4 + 0x55fe68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635688) /* 0x55fe68 */ + cpu.eax * 4);
    // 004bd83f  e8cc4df6ff             -call 0x422610
    cpu.esp -= 4;
    sub_422610(app, cpu);
    if (cpu.terminate) return;
    // 004bd844  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bd845  eb84                   -jmp 0x4bd7cb
    goto L_0x004bd7cb;
  case 0x004bd847:
L_0x004bd847:
    // 004bd847  803548d97c0001         +xor byte ptr [0x7cd948], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(8182088) /* 0x7cd948 */) ^= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004bd84e  e962010000             -jmp 0x4bd9b5
    goto L_0x004bd9b5;
L_0x004bd853:
    // 004bd853  8b3d4cd97c00           -mov edi, dword ptr [0x7cd94c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8182092) /* 0x7cd94c */);
    // 004bd859  4f                     -dec edi
    (cpu.edi)--;
    // 004bd85a  893d4cd97c00           -mov dword ptr [0x7cd94c], edi
    app->getMemory<x86::reg32>(x86::reg32(8182092) /* 0x7cd94c */) = cpu.edi;
    // 004bd860  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd862  0f8d4d010000           -jge 0x4bd9b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd9b5;
    }
    // 004bd868  c7054cd97c0003000000   -mov dword ptr [0x7cd94c], 3
    app->getMemory<x86::reg32>(x86::reg32(8182092) /* 0x7cd94c */) = 3 /*0x3*/;
    // 004bd872  e93e010000             -jmp 0x4bd9b5
    goto L_0x004bd9b5;
L_0x004bd877:
    // 004bd877  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bd87c  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004bd881  e84a20fdff             -call 0x48f8d0
    cpu.esp -= 4;
    sub_48f8d0(app, cpu);
    if (cpu.terminate) return;
    // 004bd886  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd888  7520                   -jne 0x4bd8aa
    if (!cpu.flags.zf)
    {
        goto L_0x004bd8aa;
    }
    // 004bd88a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bd88f  b848000000             -mov eax, 0x48
    cpu.eax = 72 /*0x48*/;
    // 004bd894  e83720fdff             -call 0x48f8d0
    cpu.esp -= 4;
    sub_48f8d0(app, cpu);
    if (cpu.terminate) return;
    // 004bd899  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd89b  750d                   -jne 0x4bd8aa
    if (!cpu.flags.zf)
    {
        goto L_0x004bd8aa;
    }
    // 004bd89d  e82efcffff             -call 0x4bd4d0
    cpu.esp -= 4;
    sub_4bd4d0(app, cpu);
    if (cpu.terminate) return;
    // 004bd8a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd8a4  0f840b010000           -je 0x4bd9b5
    if (cpu.flags.zf)
    {
        goto L_0x004bd9b5;
    }
L_0x004bd8aa:
    // 004bd8aa  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004bd8af  a158d97c00             -mov eax, dword ptr [0x7cd958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182104) /* 0x7cd958 */);
    // 004bd8b4  890d5cd97c00           -mov dword ptr [0x7cd95c], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182108) /* 0x7cd95c */) = cpu.ecx;
    // 004bd8ba  83f803                 +cmp eax, 3
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
    // 004bd8bd  0f87f2000000           -ja 0x4bd9b5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bd9b5;
    }
    // 004bd8c3  ff248530d64b00         -jmp dword ptr [eax*4 + 0x4bd630]
    cpu.ip = app->getMemory<x86::reg32>(4970032 + cpu.eax * 4); goto dynamic_jump;
  case 0x004bd8ca:
    // 004bd8ca  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004bd8cf  8b1554d97c00           -mov edx, dword ptr [0x7cd954]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */);
    // 004bd8d5  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bd8d7  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004bd8dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd8de  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd8e1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd8e3  893560d97c00           -mov dword ptr [0x7cd960], esi
    app->getMemory<x86::reg32>(x86::reg32(8182112) /* 0x7cd960 */) = cpu.esi;
    // 004bd8e9  891554d97c00           -mov dword ptr [0x7cd954], edx
    app->getMemory<x86::reg32>(x86::reg32(8182100) /* 0x7cd954 */) = cpu.edx;
    // 004bd8ef  8b3c9544fe5500         -mov edi, dword ptr [edx*4 + 0x55fe44]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5635652) /* 0x55fe44 */ + cpu.edx * 4);
    // 004bd8f6  891564d97c00           -mov dword ptr [0x7cd964], edx
    app->getMemory<x86::reg32>(x86::reg32(8182116) /* 0x7cd964 */) = cpu.edx;
    // 004bd8fc  83ff0f                 +cmp edi, 0xf
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
    // 004bd8ff  0f85b0000000           -jne 0x4bd9b5
    if (!cpu.flags.zf)
    {
        goto L_0x004bd9b5;
    }
    // 004bd905  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004bd907:
    // 004bd907  39d9                   +cmp ecx, ebx
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
    // 004bd909  0f8da6000000           -jge 0x4bd9b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd9b5;
    }
    // 004bd90f  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 004bd916  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd918  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd91b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd91d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bd922  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004bd924  89148568d97c00         -mov dword ptr [eax*4 + 0x7cd968], edx
    app->getMemory<x86::reg32>(x86::reg32(8182120) /* 0x7cd968 */ + cpu.eax * 4) = cpu.edx;
    // 004bd92b  89348570d97c00         -mov dword ptr [eax*4 + 0x7cd970], esi
    app->getMemory<x86::reg32>(x86::reg32(8182128) /* 0x7cd970 */ + cpu.eax * 4) = cpu.esi;
    // 004bd932  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bd934  8b14b568fe5500         -mov edx, dword ptr [esi*4 + 0x55fe68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5635688) /* 0x55fe68 */ + cpu.esi * 4);
    // 004bd93b  e880030000             -call 0x4bdcc0
    cpu.esp -= 4;
    sub_4bdcc0(app, cpu);
    if (cpu.terminate) return;
    // 004bd940  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bd942  eb05                   -jmp 0x4bd949
    goto L_0x004bd949;
L_0x004bd944:
    // 004bd944  83fa19                 +cmp edx, 0x19
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd947  7d21                   -jge 0x4bd96a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd96a;
    }
L_0x004bd949:
    // 004bd949  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 004bd950  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd952  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd955  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bd957  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd95a  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004bd95f  89bc9078d97c00         -mov dword ptr [eax + edx*4 + 0x7cd978], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8182136) /* 0x7cd978 */ + cpu.edx * 4) = cpu.edi;
    // 004bd966  01fa                   +add edx, edi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bd968  ebda                   -jmp 0x4bd944
    goto L_0x004bd944;
L_0x004bd96a:
    // 004bd96a  8b8070d97c00           -mov eax, dword ptr [eax + 0x7cd970]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8182128) /* 0x7cd970 */);
    // 004bd970  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bd972  8b048568fe5500         -mov eax, dword ptr [eax*4 + 0x55fe68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635688) /* 0x55fe68 */ + cpu.eax * 4);
    // 004bd979  e8924cf6ff             -call 0x422610
    cpu.esp -= 4;
    sub_422610(app, cpu);
    if (cpu.terminate) return;
    // 004bd97e  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bd97f  eb86                   -jmp 0x4bd907
    goto L_0x004bd907;
  case 0x004bd981:
    // 004bd981  8b154cd97c00           -mov edx, dword ptr [0x7cd94c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182092) /* 0x7cd94c */);
    // 004bd987  42                     -inc edx
    (cpu.edx)++;
    // 004bd988  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004bd98d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd98f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd992  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd994  89154cd97c00           -mov dword ptr [0x7cd94c], edx
    app->getMemory<x86::reg32>(x86::reg32(8182092) /* 0x7cd94c */) = cpu.edx;
    // 004bd99a  eb19                   -jmp 0x4bd9b5
    goto L_0x004bd9b5;
  case 0x004bd99c:
    // 004bd99c  c7055cd97c0018000000   -mov dword ptr [0x7cd95c], 0x18
    app->getMemory<x86::reg32>(x86::reg32(8182108) /* 0x7cd95c */) = 24 /*0x18*/;
    // 004bd9a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bd9ab  e8b03ff9ff             -call 0x451960
    cpu.esp -= 4;
    sub_451960(app, cpu);
    if (cpu.terminate) return;
    // 004bd9b0  e8cb730000             -call 0x4c4d80
    cpu.esp -= 4;
    sub_4c4d80(app, cpu);
    if (cpu.terminate) return;
L_0x004bd9b5:
    // 004bd9b5  833da8367d0000         +cmp dword ptr [0x7d36a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8205992) /* 0x7d36a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd9bc  7407                   -je 0x4bd9c5
    if (cpu.flags.zf)
    {
        goto L_0x004bd9c5;
    }
    // 004bd9be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd9c0  e8bb8cf6ff             -call 0x426680
    cpu.esp -= 4;
    sub_426680(app, cpu);
    if (cpu.terminate) return;
L_0x004bd9c5:
    // 004bd9c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd9c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd9c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd9c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd9c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd9ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd9cb  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4bd9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bd9d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd9d1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bd9d3  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004bd9d9  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004bd9dc  3b82d03d7a00           +cmp eax, dword ptr [edx + 0x7a3dd0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8011216) /* 0x7a3dd0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd9e2  7e06                   -jle 0x4bd9ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd9ea;
    }
    // 004bd9e4  8982d03d7a00           -mov dword ptr [edx + 0x7a3dd0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8011216) /* 0x7a3dd0 */) = cpu.eax;
L_0x004bd9ea:
    // 004bd9ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd9eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bda00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004bda00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bda01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bda02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bda03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bda04  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bda05  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bda06  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bda08  8b1558da7c00           -mov edx, dword ptr [0x7cda58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182360) /* 0x7cda58 */);
    // 004bda0e  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004bda13  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bda15  0f8539010000           -jne 0x4bdb54
    if (!cpu.flags.zf)
    {
        goto L_0x004bdb54;
    }
    // 004bda1b  8d9000feffff           -lea edx, [eax - 0x200]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-512) /* -0x200 */);
    // 004bda21  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bda23  7d02                   -jge 0x4bda27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bda27;
    }
    // 004bda25  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bda27:
    // 004bda27  b978000000             -mov ecx, 0x78
    cpu.ecx = 120 /*0x78*/;
    // 004bda2c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bda2e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bda31  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bda33  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bda35  3d2b010000             +cmp eax, 0x12b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(299 /*0x12b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bda3a  0f8d14010000           -jge 0x4bdb54
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdb54;
    }
    // 004bda40  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bda42:
    // 004bda42  3b1d9cfd5e00           +cmp ebx, dword ptr [0x5efd9c]
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
    // 004bda48  0f8d06010000           -jge 0x4bdb54
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdb54;
    }
    // 004bda4e  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 004bda53  8b349dc8fa5e00         -mov esi, dword ptr [ebx*4 + 0x5efac8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6224584) /* 0x5efac8 */ + cpu.ebx * 4);
    // 004bda5a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
L_0x004bda5c:
    // 004bda5c  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bda5d  0f84cf000000           -je 0x4bdb32
    if (cpu.flags.zf)
    {
        goto L_0x004bdb32;
    }
    // 004bda63  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bda65  0f85c7000000           -jne 0x4bdb32
    if (!cpu.flags.zf)
    {
        goto L_0x004bdb32;
    }
L_0x004bda6b:
    // 004bda6b  8d42fa                 -lea eax, [edx - 6]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-6) /* -0x6 */);
    // 004bda6e  83f804                 +cmp eax, 4
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
    // 004bda71  77e9                   -ja 0x4bda5c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bda5c;
    }
    // 004bda73  c1e002                 +shl eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004bda76  ffa0ecd94b00           -jmp dword ptr [eax + 0x4bd9ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + 4970988); goto dynamic_jump;
  case 0x004bda7c:
    // 004bda7c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004bda83  83b8d03d7a0000         +cmp dword ptr [eax + 0x7a3dd0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8011216) /* 0x7a3dd0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bda8a  74d0                   -je 0x4bda5c
    if (cpu.flags.zf)
    {
        goto L_0x004bda5c;
    }
    // 004bda8c  8b88d03d7a00           -mov ecx, dword ptr [eax + 0x7a3dd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8011216) /* 0x7a3dd0 */);
    // 004bda92  c780d03d7a0000000000   -mov dword ptr [eax + 0x7a3dd0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8011216) /* 0x7a3dd0 */) = 0 /*0x0*/;
    // 004bda9c  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bda9d  0f848f000000           -je 0x4bdb32
    if (cpu.flags.zf)
    {
        goto L_0x004bdb32;
    }
    // 004bdaa3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bdaa5  74c4                   -je 0x4bda6b
    if (cpu.flags.zf)
    {
        goto L_0x004bda6b;
    }
    // 004bdaa7  e986000000             -jmp 0x4bdb32
    goto L_0x004bdb32;
  case 0x004bdaac:
    // 004bdaac  6683be6401000020       +cmp word ptr [esi + 0x164], 0x20
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(356) /* 0x164 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32 /*0x20*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bdab4  76a6                   -jbe 0x4bda5c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bda5c;
    }
    // 004bdab6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bdab8  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bdab9  0f8473000000           -je 0x4bdb32
    if (cpu.flags.zf)
    {
        goto L_0x004bdb32;
    }
    // 004bdabf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bdac1  74a8                   -je 0x4bda6b
    if (cpu.flags.zf)
    {
        goto L_0x004bda6b;
    }
    // 004bdac3  e96a000000             -jmp 0x4bdb32
    goto L_0x004bdb32;
  case 0x004bdac8:
    // 004bdac8  8b86f4010000           -mov eax, dword ptr [esi + 0x1f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */);
    // 004bdace  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004bdad1  e8ba62f6ff             -call 0x423d90
    cpu.esp -= 4;
    sub_423d90(app, cpu);
    if (cpu.terminate) return;
    // 004bdad6  83f8ff                 +cmp eax, -1
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
    // 004bdad9  7481                   -je 0x4bda5c
    if (cpu.flags.zf)
    {
        goto L_0x004bda5c;
    }
    // 004bdadb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bdadd  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bdade  7452                   -je 0x4bdb32
    if (cpu.flags.zf)
    {
        goto L_0x004bdb32;
    }
    // 004bdae0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bdae2  7487                   -je 0x4bda6b
    if (cpu.flags.zf)
    {
        goto L_0x004bda6b;
    }
    // 004bdae4  eb4c                   -jmp 0x4bdb32
    goto L_0x004bdb32;
  case 0x004bdae6:
    // 004bdae6  f6860002000001         +test byte ptr [esi + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004bdaed  0f8469ffffff           -je 0x4bda5c
    if (cpu.flags.zf)
    {
        goto L_0x004bda5c;
    }
    // 004bdaf3  83bec402000003         +cmp dword ptr [esi + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdafa  740d                   -je 0x4bdb09
    if (cpu.flags.zf)
    {
        goto L_0x004bdb09;
    }
    // 004bdafc  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bdafd  7433                   -je 0x4bdb32
    if (cpu.flags.zf)
    {
        goto L_0x004bdb32;
    }
    // 004bdaff  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bdb01  0f8464ffffff           -je 0x4bda6b
    if (cpu.flags.zf)
    {
        goto L_0x004bda6b;
    }
    // 004bdb07  eb29                   -jmp 0x4bdb32
    goto L_0x004bdb32;
L_0x004bdb09:
    // 004bdb09  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bdb0b  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bdb0c  7424                   -je 0x4bdb32
    if (cpu.flags.zf)
    {
        goto L_0x004bdb32;
    }
    // 004bdb0e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bdb10  0f8455ffffff           -je 0x4bda6b
    if (cpu.flags.zf)
    {
        goto L_0x004bda6b;
    }
    // 004bdb16  eb1a                   -jmp 0x4bdb32
    goto L_0x004bdb32;
  case 0x004bdb18:
    // 004bdb18  83bed408000000         +cmp dword ptr [esi + 0x8d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2260) /* 0x8d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdb1f  0f8437ffffff           -je 0x4bda5c
    if (cpu.flags.zf)
    {
        goto L_0x004bda5c;
    }
    // 004bdb25  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bdb27  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bdb28  7408                   -je 0x4bdb32
    if (cpu.flags.zf)
    {
        goto L_0x004bdb32;
    }
    // 004bdb2a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bdb2c  0f8439ffffff           -je 0x4bda6b
    if (cpu.flags.zf)
    {
        goto L_0x004bda6b;
    }
L_0x004bdb32:
    // 004bdb32  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004bdb34  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004bdb3b  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 004bdb3e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bdb40  3b88483f7c00           +cmp ecx, dword ptr [eax + 0x7c3f48]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8142664) /* 0x7c3f48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdb46  7e06                   -jle 0x4bdb4e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdb4e;
    }
    // 004bdb48  8988483f7c00           -mov dword ptr [eax + 0x7c3f48], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8142664) /* 0x7c3f48 */) = cpu.ecx;
L_0x004bdb4e:
    // 004bdb4e  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bdb4f  e9eefeffff             -jmp 0x4bda42
    goto L_0x004bda42;
L_0x004bdb54:
    // 004bdb54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb5a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4bdb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bdb60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bdb61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bdb62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bdb63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bdb64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bdb66  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bdb68  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bdb6a  e851010000             -call 0x4bdcc0
    cpu.esp -= 4;
    sub_4bdcc0(app, cpu);
    if (cpu.terminate) return;
    // 004bdb6f  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004bdb76  8b90b8105e00           -mov edx, dword ptr [eax + 0x5e10b8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6164664) /* 0x5e10b8 */);
    // 004bdb7c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bdb7e  740a                   -je 0x4bdb8a
    if (cpu.flags.zf)
    {
        goto L_0x004bdb8a;
    }
    // 004bdb80  7404                   -je 0x4bdb86
    if (cpu.flags.zf)
    {
        goto L_0x004bdb86;
    }
    // 004bdb82  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004bdb84  eb1b                   -jmp 0x4bdba1
    goto L_0x004bdba1;
L_0x004bdb86:
    // 004bdb86  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bdb88  eb17                   -jmp 0x4bdba1
    goto L_0x004bdba1;
L_0x004bdb8a:
    // 004bdb8a  8bb8b0105e00           -mov edi, dword ptr [eax + 0x5e10b0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6164656) /* 0x5e10b0 */);
    // 004bdb90  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdb92  740b                   -je 0x4bdb9f
    if (cpu.flags.zf)
    {
        goto L_0x004bdb9f;
    }
    // 004bdb94  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004bdb96  39d8                   +cmp eax, ebx
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
    // 004bdb98  7510                   -jne 0x4bdbaa
    if (!cpu.flags.zf)
    {
        goto L_0x004bdbaa;
    }
    // 004bdb9a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb9b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdb9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bdb9f:
    // 004bdb9f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bdba1:
    // 004bdba1  39d8                   +cmp eax, ebx
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
    // 004bdba3  7505                   -jne 0x4bdbaa
    if (!cpu.flags.zf)
    {
        goto L_0x004bdbaa;
    }
    // 004bdba5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdba6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdba7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdba8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdba9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bdbaa:
    // 004bdbaa  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bdbac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bdbae  e85d4af6ff             -call 0x422610
    cpu.esp -= 4;
    sub_422610(app, cpu);
    if (cpu.terminate) return;
    // 004bdbb3  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdbb6  7507                   -jne 0x4bdbbf
    if (!cpu.flags.zf)
    {
        goto L_0x004bdbbf;
    }
    // 004bdbb8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bdbba  e8d138f6ff             -call 0x421490
    cpu.esp -= 4;
    sub_421490(app, cpu);
    if (cpu.terminate) return;
L_0x004bdbbf:
    // 004bdbbf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdbc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdbc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdbc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdbc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4bdbd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bdbd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bdbd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bdbd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bdbd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bdbd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bdbd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bdbd6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bdbd8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bdbda  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004bdbdd  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bdbdf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bdbe2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bdbe4  8b148568d97c00         -mov edx, dword ptr [eax*4 + 0x7cd968]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182120) /* 0x7cd968 */ + cpu.eax * 4);
    // 004bdbeb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bdbed  752c                   -jne 0x4bdc1b
    if (!cpu.flags.zf)
    {
        goto L_0x004bdc1b;
    }
    // 004bdbef  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004bdbf6  8b98b8105e00           -mov ebx, dword ptr [eax + 0x5e10b8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6164664) /* 0x5e10b8 */);
    // 004bdbfc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bdbfe  7406                   -je 0x4bdc06
    if (cpu.flags.zf)
    {
        goto L_0x004bdc06;
    }
    // 004bdc00  7410                   -je 0x4bdc12
    if (cpu.flags.zf)
    {
        goto L_0x004bdc12;
    }
    // 004bdc02  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bdc04  eb0c                   -jmp 0x4bdc12
    goto L_0x004bdc12;
L_0x004bdc06:
    // 004bdc06  8bb8b0105e00           -mov edi, dword ptr [eax + 0x5e10b0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6164656) /* 0x5e10b0 */);
    // 004bdc0c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdc0e  7402                   -je 0x4bdc12
    if (cpu.flags.zf)
    {
        goto L_0x004bdc12;
    }
    // 004bdc10  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
L_0x004bdc12:
    // 004bdc12  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bdc14  e8a7000000             -call 0x4bdcc0
    cpu.esp -= 4;
    sub_4bdcc0(app, cpu);
    if (cpu.terminate) return;
    // 004bdc19  eb42                   -jmp 0x4bdc5d
    goto L_0x004bdc5d;
L_0x004bdc1b:
    // 004bdc1b  8d1ccd00000000         -lea ebx, [ecx*8]
    cpu.ebx = x86::reg32(cpu.ecx * 8);
    // 004bdc22  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bdc24  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004bdc27  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bdc29  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004bdc2c  8b9370d97c00           -mov edx, dword ptr [ebx + 0x7cd970]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8182128) /* 0x7cd970 */);
    // 004bdc32  42                     -inc edx
    (cpu.edx)++;
    // 004bdc33  be15000000             -mov esi, 0x15
    cpu.esi = 21 /*0x15*/;
    // 004bdc38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bdc3a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bdc3d  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bdc3f  899370d97c00           -mov dword ptr [ebx + 0x7cd970], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8182128) /* 0x7cd970 */) = cpu.edx;
    // 004bdc45  8b149568fe5500         -mov edx, dword ptr [edx*4 + 0x55fe68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5635688) /* 0x55fe68 */ + cpu.edx * 4);
    // 004bdc4c  83bc9378d97c0000       +cmp dword ptr [ebx + edx*4 + 0x7cd978], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8182136) /* 0x7cd978 */ + cpu.edx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdc54  74c5                   -je 0x4bdc1b
    if (cpu.flags.zf)
    {
        goto L_0x004bdc1b;
    }
    // 004bdc56  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bdc58  e803ffffff             -call 0x4bdb60
    cpu.esp -= 4;
    sub_4bdb60(app, cpu);
    if (cpu.terminate) return;
L_0x004bdc5d:
    // 004bdc5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdc5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdc5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdc60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdc61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdc62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdc63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4bdc70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bdc70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bdc71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bdc72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bdc73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bdc74  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bdc76  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bdc78  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004bdc7b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bdc7d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bdc80  8b0d84367d00           -mov ecx, dword ptr [0x7d3684]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004bdc86  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bdc88  81e900020000           -sub ecx, 0x200
    (cpu.ecx) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004bdc8e  8b14856cd97c00         -mov edx, dword ptr [eax*4 + 0x7cd96c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182124) /* 0x7cd96c */ + cpu.eax * 4);
    // 004bdc95  8b1c8574d97c00         -mov ebx, dword ptr [eax*4 + 0x7cd974]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8182132) /* 0x7cd974 */ + cpu.eax * 4);
    // 004bdc9c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bdc9e  39d9                   +cmp ecx, ebx
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
    // 004bdca0  7e0a                   -jle 0x4bdcac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdcac;
    }
    // 004bdca2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bdca7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdca8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdca9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdcaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdcab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bdcac:
    // 004bdcac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bdcae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdcaf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdcb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdcb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdcb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4bdcc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bdcc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bdcc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bdcc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bdcc3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bdcc5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bdcc7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bdcc9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004bdccc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bdcce  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bdcd1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bdcd3  8b1d84367d00           -mov ebx, dword ptr [0x7d3684]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004bdcd9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bdcdc  81eb00020000           -sub ebx, 0x200
    (cpu.ebx) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004bdce2  89986cd97c00           -mov dword ptr [eax + 0x7cd96c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8182124) /* 0x7cd96c */) = cpu.ebx;
    // 004bdce8  83f912                 +cmp ecx, 0x12
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdceb  750e                   -jne 0x4bdcfb
    if (!cpu.flags.zf)
    {
        goto L_0x004bdcfb;
    }
    // 004bdced  c78074d97c00a0000000   -mov dword ptr [eax + 0x7cd974], 0xa0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8182132) /* 0x7cd974 */) = 160 /*0xa0*/;
    // 004bdcf7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdcf8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdcf9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdcfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bdcfb:
    // 004bdcfb  c78074d97c0040010000   -mov dword ptr [eax + 0x7cd974], 0x140
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8182132) /* 0x7cd974 */) = 320 /*0x140*/;
    // 004bdd05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4bdd10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bdd10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bdd11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bdd12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bdd13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bdd14  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bdd16  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bdd18  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bdd1a:
    // 004bdd1a  81fa58020000           +cmp edx, 0x258
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(600 /*0x258*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdd20  7d22                   -jge 0x4bdd44
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdd44;
    }
    // 004bdd22  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bdd24  7e1e                   -jle 0x4bdd44
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdd44;
    }
    // 004bdd26  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bdd28  8d3cb500000000         -lea edi, [esi*4]
    cpu.edi = x86::reg32(cpu.esi * 4);
    // 004bdd2f  c1e106                 -shl ecx, 6
    cpu.ecx <<= 6 /*0x6*/ % 32;
    // 004bdd32  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bdd34  8b89483f7c00           -mov ecx, dword ptr [ecx + 0x7c3f48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8142664) /* 0x7c3f48 */);
    // 004bdd3a  39c1                   +cmp ecx, eax
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
    // 004bdd3c  7e02                   -jle 0x4bdd40
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bdd40;
    }
    // 004bdd3e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004bdd40:
    // 004bdd40  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bdd41  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bdd42  ebd6                   -jmp 0x4bdd1a
    goto L_0x004bdd1a;
L_0x004bdd44:
    // 004bdd44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdd48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4bdd70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004bdd70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bdd71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bdd72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bdd73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bdd74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bdd75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bdd76  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bdd78  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bdd7b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bdd7d  8b1584367d00           -mov edx, dword ptr [0x7d3684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004bdd83  81ea00020000           -sub edx, 0x200
    (cpu.edx) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004bdd89  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bdd8b  7d02                   -jge 0x4bdd8f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdd8f;
    }
    // 004bdd8d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bdd8f:
    // 004bdd8f  b978000000             -mov ecx, 0x78
    cpu.ecx = 120 /*0x78*/;
    // 004bdd94  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bdd96  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bdd99  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bdd9b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004bdd9e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bdda0  e8cbfeffff             -call 0x4bdc70
    cpu.esp -= 4;
    sub_4bdc70(app, cpu);
    if (cpu.terminate) return;
    // 004bdda5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bdda7  a1f8d46f00             -mov eax, dword ptr [0x6fd4f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7329016) /* 0x6fd4f8 */);
    // 004bddac  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bddaf  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004bddb2  81fa58020000           +cmp edx, 0x258
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(600 /*0x258*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bddb8  0f8d31020000           -jge 0x4bdfef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdfef;
    }
    // 004bddbe  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bddc0  eb05                   -jmp 0x4bddc7
    goto L_0x004bddc7;
L_0x004bddc2:
    // 004bddc2  83f819                 +cmp eax, 0x19
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bddc5  7d21                   -jge 0x4bdde8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bdde8;
    }
L_0x004bddc7:
    // 004bddc7  8d0cf500000000         -lea ecx, [esi*8]
    cpu.ecx = x86::reg32(cpu.esi * 8);
    // 004bddce  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bddd0  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004bddd3  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bddd5  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004bddd8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004bdddd  899c8178d97c00         -mov dword ptr [ecx + eax*4 + 0x7cd978], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182136) /* 0x7cd978 */ + cpu.eax * 4) = cpu.ebx;
    // 004bdde4  01d8                   +add eax, ebx
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
    // 004bdde6  ebda                   -jmp 0x4bddc2
    goto L_0x004bddc2;
L_0x004bdde8:
    // 004bdde8  8b8174d97c00           -mov eax, dword ptr [ecx + 0x7cd974]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182132) /* 0x7cd974 */);
    // 004bddee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bddf0  bb78000000             -mov ebx, 0x78
    cpu.ebx = 120 /*0x78*/;
    // 004bddf5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bddf8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bddfa  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004bddfd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bddff  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bde02  e809ffffff             -call 0x4bdd10
    cpu.esp -= 4;
    sub_4bdd10(app, cpu);
    if (cpu.terminate) return;
    // 004bde07  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004bde0a  83f806                 +cmp eax, 6
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
    // 004bde0d  0f8793010000           -ja 0x4bdfa6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bdfa6;
    }
    // 004bde13  ff24854cdd4b00         -jmp dword ptr [eax*4 + 0x4bdd4c]
    cpu.ip = app->getMemory<x86::reg32>(4971852 + cpu.eax * 4); goto dynamic_jump;
  case 0x004bde1a:
    // 004bde1a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bde1c  e86f5ff6ff             -call 0x423d90
    cpu.esp -= 4;
    sub_423d90(app, cpu);
    if (cpu.terminate) return;
    // 004bde21  83f8ff                 +cmp eax, -1
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
    // 004bde24  7508                   -jne 0x4bde2e
    if (!cpu.flags.zf)
    {
        goto L_0x004bde2e;
    }
    // 004bde26  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bde28  0f84c1010000           -je 0x4bdfef
    if (cpu.flags.zf)
    {
        goto L_0x004bdfef;
    }
L_0x004bde2e:
    // 004bde2e  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004bde33  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bde35  e826fdffff             -call 0x4bdb60
    cpu.esp -= 4;
    sub_4bdb60(app, cpu);
    if (cpu.terminate) return;
    // 004bde3a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bde3c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde3d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde42  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bde43:
    // 004bde43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bde45  89817cd97c00           -mov dword ptr [ecx + 0x7cd97c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182140) /* 0x7cd97c */) = cpu.eax;
    // 004bde4b  8b8170d97c00           -mov eax, dword ptr [ecx + 0x7cd970]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182128) /* 0x7cd970 */);
    // 004bde51  8b048568fe5500         -mov eax, dword ptr [eax*4 + 0x55fe68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635688) /* 0x55fe68 */ + cpu.eax * 4);
    // 004bde58  83bc8178d97c0000       +cmp dword ptr [ecx + eax*4 + 0x7cd978], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182136) /* 0x7cd978 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bde60  7408                   -je 0x4bde6a
    if (cpu.flags.zf)
    {
        goto L_0x004bde6a;
    }
    // 004bde62  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bde64  0f8485010000           -je 0x4bdfef
    if (cpu.flags.zf)
    {
        goto L_0x004bdfef;
    }
L_0x004bde6a:
    // 004bde6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bde6c  e85ffdffff             -call 0x4bdbd0
    cpu.esp -= 4;
    sub_4bdbd0(app, cpu);
    if (cpu.terminate) return;
    // 004bde71  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bde73  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde74  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde75  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde76  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bde79  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bde7a:
    // 004bde7a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bde7c  8999a0d97c00           -mov dword ptr [ecx + 0x7cd9a0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182176) /* 0x7cd9a0 */) = cpu.ebx;
    // 004bde82  8999a8d97c00           -mov dword ptr [ecx + 0x7cd9a8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182184) /* 0x7cd9a8 */) = cpu.ebx;
    // 004bde88  8b8170d97c00           -mov eax, dword ptr [ecx + 0x7cd970]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182128) /* 0x7cd970 */);
    // 004bde8e  8999acd97c00           -mov dword ptr [ecx + 0x7cd9ac], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182188) /* 0x7cd9ac */) = cpu.ebx;
    // 004bde94  8b048568fe5500         -mov eax, dword ptr [eax*4 + 0x55fe68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635688) /* 0x55fe68 */ + cpu.eax * 4);
    // 004bde9b  899994d97c00           -mov dword ptr [ecx + 0x7cd994], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182164) /* 0x7cd994 */) = cpu.ebx;
    // 004bdea1  83bc8178d97c0000       +cmp dword ptr [ecx + eax*4 + 0x7cd978], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182136) /* 0x7cd978 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdea9  7408                   -je 0x4bdeb3
    if (cpu.flags.zf)
    {
        goto L_0x004bdeb3;
    }
    // 004bdeab  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdead  0f843c010000           -je 0x4bdfef
    if (cpu.flags.zf)
    {
        goto L_0x004bdfef;
    }
L_0x004bdeb3:
    // 004bdeb3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bdeb5  e816fdffff             -call 0x4bdbd0
    cpu.esp -= 4;
    sub_4bdbd0(app, cpu);
    if (cpu.terminate) return;
    // 004bdeba  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bdebc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdebd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdebe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdebf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdec0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdec1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdec2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bdec3:
    // 004bdec3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bdec5  8999a0d97c00           -mov dword ptr [ecx + 0x7cd9a0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182176) /* 0x7cd9a0 */) = cpu.ebx;
    // 004bdecb  8999a8d97c00           -mov dword ptr [ecx + 0x7cd9a8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182184) /* 0x7cd9a8 */) = cpu.ebx;
    // 004bded1  8b8170d97c00           -mov eax, dword ptr [ecx + 0x7cd970]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182128) /* 0x7cd970 */);
    // 004bded7  8999acd97c00           -mov dword ptr [ecx + 0x7cd9ac], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182188) /* 0x7cd9ac */) = cpu.ebx;
    // 004bdedd  8b048568fe5500         -mov eax, dword ptr [eax*4 + 0x55fe68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635688) /* 0x55fe68 */ + cpu.eax * 4);
    // 004bdee4  8999a4d97c00           -mov dword ptr [ecx + 0x7cd9a4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182180) /* 0x7cd9a4 */) = cpu.ebx;
    // 004bdeea  83bc8178d97c0000       +cmp dword ptr [ecx + eax*4 + 0x7cd978], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182136) /* 0x7cd978 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdef2  7408                   -je 0x4bdefc
    if (cpu.flags.zf)
    {
        goto L_0x004bdefc;
    }
    // 004bdef4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdef6  0f84f3000000           -je 0x4bdfef
    if (cpu.flags.zf)
    {
        goto L_0x004bdfef;
    }
L_0x004bdefc:
    // 004bdefc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bdefe  e8cdfcffff             -call 0x4bdbd0
    cpu.esp -= 4;
    sub_4bdbd0(app, cpu);
    if (cpu.terminate) return;
    // 004bdf03  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bdf05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf0b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bdf0c:
    // 004bdf0c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bdf0e  899998d97c00           -mov dword ptr [ecx + 0x7cd998], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182168) /* 0x7cd998 */) = cpu.ebx;
    // 004bdf14  8999c0d97c00           -mov dword ptr [ecx + 0x7cd9c0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182208) /* 0x7cd9c0 */) = cpu.ebx;
    // 004bdf1a  8999a4d97c00           -mov dword ptr [ecx + 0x7cd9a4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182180) /* 0x7cd9a4 */) = cpu.ebx;
    // 004bdf20  8b8170d97c00           -mov eax, dword ptr [ecx + 0x7cd970]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182128) /* 0x7cd970 */);
    // 004bdf26  899994d97c00           -mov dword ptr [ecx + 0x7cd994], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182164) /* 0x7cd994 */) = cpu.ebx;
    // 004bdf2c  8b048568fe5500         -mov eax, dword ptr [eax*4 + 0x55fe68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635688) /* 0x55fe68 */ + cpu.eax * 4);
    // 004bdf33  8999a0d97c00           -mov dword ptr [ecx + 0x7cd9a0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182176) /* 0x7cd9a0 */) = cpu.ebx;
    // 004bdf39  83bc8178d97c0000       +cmp dword ptr [ecx + eax*4 + 0x7cd978], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182136) /* 0x7cd978 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdf41  7408                   -je 0x4bdf4b
    if (cpu.flags.zf)
    {
        goto L_0x004bdf4b;
    }
    // 004bdf43  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdf45  0f84a4000000           -je 0x4bdfef
    if (cpu.flags.zf)
    {
        goto L_0x004bdfef;
    }
L_0x004bdf4b:
    // 004bdf4b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bdf4d  e87efcffff             -call 0x4bdbd0
    cpu.esp -= 4;
    sub_4bdbd0(app, cpu);
    if (cpu.terminate) return;
    // 004bdf52  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bdf54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdf5a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bdf5b:
    // 004bdf5b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bdf5d  8999a4d97c00           -mov dword ptr [ecx + 0x7cd9a4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182180) /* 0x7cd9a4 */) = cpu.ebx;
    // 004bdf63  8999a0d97c00           -mov dword ptr [ecx + 0x7cd9a0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182176) /* 0x7cd9a0 */) = cpu.ebx;
    // 004bdf69  8999a8d97c00           -mov dword ptr [ecx + 0x7cd9a8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182184) /* 0x7cd9a8 */) = cpu.ebx;
    // 004bdf6f  8b8170d97c00           -mov eax, dword ptr [ecx + 0x7cd970]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182128) /* 0x7cd970 */);
    // 004bdf75  8999acd97c00           -mov dword ptr [ecx + 0x7cd9ac], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182188) /* 0x7cd9ac */) = cpu.ebx;
    // 004bdf7b  8b048568fe5500         -mov eax, dword ptr [eax*4 + 0x55fe68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635688) /* 0x55fe68 */ + cpu.eax * 4);
    // 004bdf82  89999cd97c00           -mov dword ptr [ecx + 0x7cd99c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182172) /* 0x7cd99c */) = cpu.ebx;
    // 004bdf88  83bc8178d97c0000       +cmp dword ptr [ecx + eax*4 + 0x7cd978], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8182136) /* 0x7cd978 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdf90  7404                   -je 0x4bdf96
    if (cpu.flags.zf)
    {
        goto L_0x004bdf96;
    }
    // 004bdf92  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdf94  7459                   -je 0x4bdfef
    if (cpu.flags.zf)
    {
        goto L_0x004bdfef;
    }
L_0x004bdf96:
    // 004bdf96  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bdf98  e833fcffff             -call 0x4bdbd0
    cpu.esp -= 4;
    sub_4bdbd0(app, cpu);
    if (cpu.terminate) return;
    // 004bdf9d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bdf9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdfa0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdfa1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdfa2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdfa3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdfa4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdfa5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bdfa6:
L_0x004bdfa6:
    // 004bdfa6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bdfa8  7445                   -je 0x4bdfef
    if (cpu.flags.zf)
    {
        goto L_0x004bdfef;
    }
    // 004bdfaa  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004bdfb1  8b88b8105e00           -mov ecx, dword ptr [eax + 0x5e10b8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6164664) /* 0x5e10b8 */);
    // 004bdfb7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bdfb9  7404                   -je 0x4bdfbf
    if (cpu.flags.zf)
    {
        goto L_0x004bdfbf;
    }
    // 004bdfbb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bdfbd  eb06                   -jmp 0x4bdfc5
    goto L_0x004bdfc5;
L_0x004bdfbf:
    // 004bdfbf  8b80b0105e00           -mov eax, dword ptr [eax + 0x5e10b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6164656) /* 0x5e10b0 */);
L_0x004bdfc5:
    // 004bdfc5  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004bdfc8  83b89809000000         +cmp dword ptr [eax + 0x998], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2456) /* 0x998 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bdfcf  7417                   -je 0x4bdfe8
    if (cpu.flags.zf)
    {
        goto L_0x004bdfe8;
    }
    // 004bdfd1  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 004bdfd8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bdfda  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bdfdd  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bdfdf  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bdfe1  893c859cd97c00         -mov dword ptr [eax*4 + 0x7cd99c], edi
    app->getMemory<x86::reg32>(x86::reg32(8182172) /* 0x7cd99c */ + cpu.eax * 4) = cpu.edi;
L_0x004bdfe8:
    // 004bdfe8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bdfea  e8e1fbffff             -call 0x4bdbd0
    cpu.esp -= 4;
    sub_4bdbd0(app, cpu);
    if (cpu.terminate) return;
L_0x004bdfef:
    // 004bdfef  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bdff1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdff2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdff3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdff4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdff5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdff6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bdff7  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4be000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be000  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be001  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be003  3c30                   +cmp al, 0x30
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
    // 004be005  7204                   -jb 0x4be00b
    if (cpu.flags.cf)
    {
        goto L_0x004be00b;
    }
    // 004be007  3c39                   +cmp al, 0x39
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
    // 004be009  760c                   -jbe 0x4be017
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004be017;
    }
L_0x004be00b:
    // 004be00b  3c2d                   +cmp al, 0x2d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004be00d  7504                   -jne 0x4be013
    if (!cpu.flags.zf)
    {
        goto L_0x004be013;
    }
    // 004be00f  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004be011  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be012  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be013:
    // 004be013  3c2b                   +cmp al, 0x2b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004be015  7504                   -jne 0x4be01b
    if (!cpu.flags.zf)
    {
        goto L_0x004be01b;
    }
L_0x004be017:
    // 004be017  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004be019  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be01a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be01b:
    // 004be01b  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004be01d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be01e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4be020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004be021  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be022  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004be023  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be024  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be026  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004be02c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004be02e  e89d53feff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004be033  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004be035  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004be037:
    // 004be037  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be039  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004be03b  e8c0ffffff             -call 0x4be000
    cpu.esp -= 4;
    sub_4be000(app, cpu);
    if (cpu.terminate) return;
    // 004be040  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004be042  7512                   -jne 0x4be056
    if (!cpu.flags.zf)
    {
        goto L_0x004be056;
    }
    // 004be044  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be046  42                     -inc edx
    (cpu.edx)++;
    // 004be047  80382f                 +cmp byte ptr [eax], 0x2f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004be04a  75eb                   -jne 0x4be037
    if (!cpu.flags.zf)
    {
        goto L_0x004be037;
    }
L_0x004be04c:
    // 004be04c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be04e  42                     -inc edx
    (cpu.edx)++;
    // 004be04f  80382f                 +cmp byte ptr [eax], 0x2f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004be052  75f8                   -jne 0x4be04c
    if (!cpu.flags.zf)
    {
        goto L_0x004be04c;
    }
    // 004be054  ebe1                   -jmp 0x4be037
    goto L_0x004be037;
L_0x004be056:
    // 004be056  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be058  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004be05a  e8a1ffffff             -call 0x4be000
    cpu.esp -= 4;
    sub_4be000(app, cpu);
    if (cpu.terminate) return;
    // 004be05f  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004be061  740d                   -je 0x4be070
    if (cpu.flags.zf)
    {
        goto L_0x004be070;
    }
    // 004be063  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be064  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004be066  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be067  888429fffeffff         -mov byte ptr [ecx + ebp - 0x101], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-257) /* -0x101 */ + cpu.ebp * 1) = cpu.al;
    // 004be06e  ebe6                   -jmp 0x4be056
    goto L_0x004be056;
L_0x004be070:
    // 004be070  88842900ffffff         -mov byte ptr [ecx + ebp - 0x100], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-256) /* -0x100 */ + cpu.ebp * 1) = cpu.al;
    // 004be077  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004be07d  e8ae230300             -call 0x4f0430
    cpu.esp -= 4;
    sub_4f0430(app, cpu);
    if (cpu.terminate) return;
    // 004be082  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004be084  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be086  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be087  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be088  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be089  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be08a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4be090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be090  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be091  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be092  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be093  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be095  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be098  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004be09a  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004be09d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004be09f  8d0c10                 -lea ecx, [eax + edx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004be0a2  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004be0a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004be0a7  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004be0aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004be0ac  0f84db000000           -je 0x4be18d
    if (cpu.flags.zf)
    {
        goto L_0x004be18d;
    }
    // 004be0b2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004be0b4:
    // 004be0b4  3b55fc                 +cmp edx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be0b7  7d1b                   -jge 0x4be0d4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be0d4;
    }
L_0x004be0b9:
    // 004be0b9  39c8                   +cmp eax, ecx
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
    // 004be0bb  7507                   -jne 0x4be0c4
    if (!cpu.flags.zf)
    {
        goto L_0x004be0c4;
    }
    // 004be0bd  31c8                   +xor eax, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004be0bf  e9c9000000             -jmp 0x4be18d
    goto L_0x004be18d;
L_0x004be0c4:
    // 004be0c4  80380a                 +cmp byte ptr [eax], 0xa
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004be0c7  7505                   -jne 0x4be0ce
    if (!cpu.flags.zf)
    {
        goto L_0x004be0ce;
    }
    // 004be0c9  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be0ca  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004be0cc  eb03                   -jmp 0x4be0d1
    goto L_0x004be0d1;
L_0x004be0ce:
    // 004be0ce  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be0cf  ebe8                   -jmp 0x4be0b9
    goto L_0x004be0b9;
L_0x004be0d1:
    // 004be0d1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be0d2  ebe0                   -jmp 0x4be0b4
    goto L_0x004be0b4;
L_0x004be0d4:
    // 004be0d4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004be0d6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004be0d8  39cb                   +cmp ebx, ecx
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
    // 004be0da  750a                   -jne 0x4be0e6
    if (!cpu.flags.zf)
    {
        goto L_0x004be0e6;
    }
    // 004be0dc  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004be0de  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be0e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be0e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be0e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be0e3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004be0e6:
    // 004be0e6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004be0e8:
    // 004be0e8  39fb                   +cmp ebx, edi
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
    // 004be0ea  7d2a                   -jge 0x4be116
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be116;
    }
L_0x004be0ec:
    // 004be0ec  39c8                   +cmp eax, ecx
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
    // 004be0ee  740c                   -je 0x4be0fc
    if (cpu.flags.zf)
    {
        goto L_0x004be0fc;
    }
    // 004be0f0  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004be0f2  80fa0a                 +cmp dl, 0xa
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
    // 004be0f5  7405                   -je 0x4be0fc
    if (cpu.flags.zf)
    {
        goto L_0x004be0fc;
    }
    // 004be0f7  80fa0d                 +cmp dl, 0xd
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
    // 004be0fa  750a                   -jne 0x4be106
    if (!cpu.flags.zf)
    {
        goto L_0x004be106;
    }
L_0x004be0fc:
    // 004be0fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be0fe  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be100  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be101  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be102  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be103  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004be106:
    // 004be106  80fa2c                 +cmp dl, 0x2c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004be109  7505                   -jne 0x4be110
    if (!cpu.flags.zf)
    {
        goto L_0x004be110;
    }
    // 004be10b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be10c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004be10e  eb03                   -jmp 0x4be113
    goto L_0x004be113;
L_0x004be110:
    // 004be110  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be111  ebd9                   -jmp 0x4be0ec
    goto L_0x004be0ec;
L_0x004be113:
    // 004be113  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be114  ebd2                   -jmp 0x4be0e8
    goto L_0x004be0e8;
L_0x004be116:
    // 004be116  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be118  39ca                   +cmp edx, ecx
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
    // 004be11a  750a                   -jne 0x4be126
    if (!cpu.flags.zf)
    {
        goto L_0x004be126;
    }
    // 004be11c  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004be11e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be120  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be121  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be122  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be123  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004be126:
    // 004be126  39c8                   +cmp eax, ecx
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
    // 004be128  7505                   -jne 0x4be12f
    if (!cpu.flags.zf)
    {
        goto L_0x004be12f;
    }
    // 004be12a  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004be12d  eb19                   -jmp 0x4be148
    goto L_0x004be148;
L_0x004be12f:
    // 004be12f  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004be131  80fb2c                 +cmp bl, 0x2c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004be134  7412                   -je 0x4be148
    if (cpu.flags.zf)
    {
        goto L_0x004be148;
    }
    // 004be136  80fb0d                 +cmp bl, 0xd
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004be139  740d                   -je 0x4be148
    if (cpu.flags.zf)
    {
        goto L_0x004be148;
    }
    // 004be13b  80fb0a                 +cmp bl, 0xa
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004be13e  7408                   -je 0x4be148
    if (cpu.flags.zf)
    {
        goto L_0x004be148;
    }
    // 004be140  40                     -inc eax
    (cpu.eax)++;
    // 004be141  39c8                   +cmp eax, ecx
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
    // 004be143  75ea                   -jne 0x4be12f
    if (!cpu.flags.zf)
    {
        goto L_0x004be12f;
    }
    // 004be145  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
L_0x004be148:
    // 004be148  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004be14a  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be14c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004be14e  7f0a                   -jg 0x4be15a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004be15a;
    }
    // 004be150  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be152  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be154  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be155  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be156  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be157  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004be15a:
    // 004be15a  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004be15c  fec0                   -inc al
    (cpu.al)++;
    // 004be15e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004be163  f680f04e5600e0         +test byte ptr [eax + 0x564ef0], 0xe0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 224 /*0xe0*/));
    // 004be16a  750a                   -jne 0x4be176
    if (!cpu.flags.zf)
    {
        goto L_0x004be176;
    }
    // 004be16c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be16e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be170  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be171  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be172  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be173  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004be176:
    // 004be176  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004be179  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004be17c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004be17e  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004be180  e8ab2c0200             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004be185  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004be18a  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x004be18d:
    // 004be18d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be18f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be190  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be191  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be192  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4be1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be1a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004be1a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be1a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be1a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be1a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be1a6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004be1a8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004be1aa  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004be1af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004be1b1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be1b4  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be1b6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004be1b8  8d0c30                 -lea ecx, [eax + esi]
    cpu.ecx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004be1bb  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 004be1c0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004be1c2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be1c5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be1c7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004be1c9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004be1cb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004be1cd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be1d0  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be1d2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004be1d4  7507                   -jne 0x4be1dd
    if (!cpu.flags.zf)
    {
        goto L_0x004be1dd;
    }
    // 004be1d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be1d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1db  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004be1dd:
    // 004be1dd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004be1e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be1e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4be1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be1f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004be1f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be1f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be1f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be1f5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004be1f7  b8b0015400             -mov eax, 0x5401b0
    cpu.eax = 5505456 /*0x5401b0*/;
    // 004be1fc  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004be1ff  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004be201  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004be204  e817340200             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004be209  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004be210  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004be212  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004be214  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004be216:
    // 004be216  3b02                   +cmp eax, dword ptr [edx]
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
    // 004be218  7d18                   -jge 0x4be232
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be232;
    }
    // 004be21a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004be21c  c1e104                 +shl ecx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004be21f  c7441108fe7f0000       -mov dword ptr [ecx + edx + 8], 0x7ffe
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.edx * 1) = 32766 /*0x7ffe*/;
    // 004be227  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be228  c744110c00000000       -mov dword ptr [ecx + edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.edx * 1) = 0 /*0x0*/;
    // 004be230  ebe4                   -jmp 0x4be216
    goto L_0x004be216;
L_0x004be232:
    // 004be232  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be234  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be235  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be236  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be237  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4be240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be240  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be241  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be243  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004be245  7405                   -je 0x4be24c
    if (cpu.flags.zf)
    {
        goto L_0x004be24c;
    }
    // 004be247  e844360200             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004be24c:
    // 004be24c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be24d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4be250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be250  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be251  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be252  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be253  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be255  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004be258  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004be25b  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 004be25e  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004be261  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 004be264  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004be267  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004be269  41                     -inc ecx
    (cpu.ecx)++;
    // 004be26a  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004be26d  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
L_0x004be270:
    // 004be270  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be273  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be276  7d4d                   -jge 0x4be2c5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be2c5;
    }
    // 004be278  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be27a  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be27d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004be280  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004be282  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004be285  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004be288  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004be28b  39f9                   +cmp ecx, edi
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
    // 004be28d  7d33                   -jge 0x4be2c2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be2c2;
    }
    // 004be28f  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004be292  4b                     -dec ebx
    (cpu.ebx)--;
L_0x004be293:
    // 004be293  39d3                   +cmp ebx, edx
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
    // 004be295  7e2e                   -jle 0x4be2c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be2c5;
    }
    // 004be297  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004be299  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be29c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004be29f  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be2a2  8d70f0                 -lea esi, [eax - 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 004be2a5  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004be2a7  8d3c08                 -lea edi, [eax + ecx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004be2aa  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004be2af  4b                     -dec ebx
    (cpu.ebx)--;
    // 004be2b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be2b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004be2b3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004be2b6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004be2b8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004be2ba  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004be2bd  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004be2bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be2c0  ebd1                   -jmp 0x4be293
    goto L_0x004be293;
L_0x004be2c2:
    // 004be2c2  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be2c3  ebab                   -jmp 0x4be270
    goto L_0x004be270;
L_0x004be2c5:
    // 004be2c5  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004be2c8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be2cb  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004be2ce  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be2d0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004be2d3  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004be2d6  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004be2d9  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004be2dc  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004be2df  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004be2e2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be2e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be2e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be2e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be2e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4be2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be2f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be2f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be2f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be2f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be2f4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be2f6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be2f9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004be2fc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004be2fe  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004be300  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004be302  0f8489000000           -je 0x4be391
    if (cpu.flags.zf)
    {
        goto L_0x004be391;
    }
    // 004be308  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004be30c  0f847f000000           -je 0x4be391
    if (cpu.flags.zf)
    {
        goto L_0x004be391;
    }
    // 004be312  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004be314:
    // 004be314  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be317  3b4304                 +cmp eax, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be31a  7d5d                   -jge 0x4be379
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be379;
    }
    // 004be31c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004be31e  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be321  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004be324  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004be326  3b7b0c                 +cmp edi, dword ptr [ebx + 0xc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be329  753d                   -jne 0x4be368
    if (!cpu.flags.zf)
    {
        goto L_0x004be368;
    }
    // 004be32b  3b5310                 +cmp edx, dword ptr [ebx + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be32e  7538                   -jne 0x4be368
    if (!cpu.flags.zf)
    {
        goto L_0x004be368;
    }
    // 004be330  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004be332:
    // 004be332  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be335  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004be338  48                     -dec eax
    (cpu.eax)--;
    // 004be339  39c2                   +cmp edx, eax
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
    // 004be33b  7d3c                   -jge 0x4be379
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be379;
    }
    // 004be33d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be33f  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be342  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004be345  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004be348  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004be34b  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004be350  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004be352  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004be355  42                     -inc edx
    (cpu.edx)++;
    // 004be356  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be357  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004be359  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004be35c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004be35e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004be360  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004be363  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004be365  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be366  ebca                   -jmp 0x4be332
    goto L_0x004be332;
L_0x004be368:
    // 004be368  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004be36a  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be36d  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004be370  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004be372  837b0c00               +cmp dword ptr [ebx + 0xc], 0
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
    // 004be376  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be377  eb9b                   -jmp 0x4be314
    goto L_0x004be314;
L_0x004be379:
    // 004be379  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be37c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004be37f  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be382  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004be385  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004be387  c74008fe7f0000         -mov dword ptr [eax + 8], 0x7ffe
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 32766 /*0x7ffe*/;
    // 004be38e  ff4b04                 -dec dword ptr [ebx + 4]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))--;
L_0x004be391:
    // 004be391  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be393  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be394  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be395  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be396  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be397  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4be3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be3a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004be3a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be3a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004be3a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be3a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be3a6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004be3a8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004be3aa:
    // 004be3aa  3b5104                 +cmp edx, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be3ad  7d18                   -jge 0x4be3c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be3c7;
    }
    // 004be3af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be3b1  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004be3b4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004be3b6  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 004be3ba  7408                   -je 0x4be3c4
    if (cpu.flags.zf)
    {
        goto L_0x004be3c4;
    }
    // 004be3bc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004be3be  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004be3c1  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004be3c4:
    // 004be3c4  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be3c5  ebe3                   -jmp 0x4be3aa
    goto L_0x004be3aa;
L_0x004be3c7:
    // 004be3c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be3c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be3c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be3ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be3cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4be3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be3d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004be3d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be3d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004be3d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be3d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be3d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be3d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be3d8  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004be3db  a164da7c00             -mov eax, dword ptr [0x7cda64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182372) /* 0x7cda64 */);
    // 004be3e0  8b356cda7c00           -mov esi, dword ptr [0x7cda6c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182380) /* 0x7cda6c */);
    // 004be3e6  8b15b0d36f00           -mov edx, dword ptr [0x6fd3b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 004be3ec  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004be3ef  a168da7c00             -mov eax, dword ptr [0x7cda68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */);
    // 004be3f4  8b3d60da7c00           -mov edi, dword ptr [0x7cda60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8182368) /* 0x7cda60 */);
    // 004be3fa  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004be3fd  83fa01                 +cmp edx, 1
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
    // 004be400  7514                   -jne 0x4be416
    if (!cpu.flags.zf)
    {
        goto L_0x004be416;
    }
    // 004be402  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004be405  8b0d98da7c00           -mov ecx, dword ptr [0x7cda98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182424) /* 0x7cda98 */);
    // 004be40b  a190da7c00             -mov eax, dword ptr [0x7cda90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182416) /* 0x7cda90 */);
    // 004be410  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004be412  01c1                   +add ecx, eax
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
    // 004be414  eb1b                   -jmp 0x4be431
    goto L_0x004be431;
L_0x004be416:
    // 004be416  8b0da0db7c00           -mov ecx, dword ptr [0x7cdba0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182688) /* 0x7cdba0 */);
    // 004be41c  a198db7c00             -mov eax, dword ptr [0x7cdb98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182680) /* 0x7cdb98 */);
    // 004be421  8b159cdb7c00           -mov edx, dword ptr [0x7cdb9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182684) /* 0x7cdb9c */);
    // 004be427  8b1da4db7c00           -mov ebx, dword ptr [0x7cdba4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8182692) /* 0x7cdba4 */);
    // 004be42d  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be42f  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004be431:
    // 004be431  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 004be434  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004be437  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 004be43a  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004be43d  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004be440  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004be443  db45e8                 -fild dword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */))));
    // 004be446  db45ec                 -fild dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */))));
    // 004be449  db45f0                 -fild dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))));
    // 004be44c  db45f4                 -fild dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))));
    // 004be44f  db45f8                 -fild dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 004be452  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004be455  8b7de4                 -mov edi, dword ptr [ebp - 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004be458  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004be45b  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004be45d  d91dd4fe5500           -fstp dword ptr [0x55fed4]
    app->getMemory<float>(x86::reg32(5635796) /* 0x55fed4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be463  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004be465  d91df4fe5500           -fstp dword ptr [0x55fef4]
    app->getMemory<float>(x86::reg32(5635828) /* 0x55fef4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be46b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004be46d  d91d14ff5500           -fstp dword ptr [0x55ff14]
    app->getMemory<float>(x86::reg32(5635860) /* 0x55ff14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be473  d91d58ff5500           -fstp dword ptr [0x55ff58]
    app->getMemory<float>(x86::reg32(5635928) /* 0x55ff58 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be479  d91d98ff5500           -fstp dword ptr [0x55ff98]
    app->getMemory<float>(x86::reg32(5635992) /* 0x55ff98 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be47f  d91dd8ff5500           -fstp dword ptr [0x55ffd8]
    app->getMemory<float>(x86::reg32(5636056) /* 0x55ffd8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be485  d905f4fe5500           -fld dword ptr [0x55fef4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5635828) /* 0x55fef4 */)));
    // 004be48b  d90514ff5500           -fld dword ptr [0x55ff14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5635860) /* 0x55ff14 */)));
    // 004be491  d90558ff5500           -fld dword ptr [0x55ff58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5635928) /* 0x55ff58 */)));
    // 004be497  d90598ff5500           -fld dword ptr [0x55ff98]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5635992) /* 0x55ff98 */)));
    // 004be49d  d905d4fe5500           -fld dword ptr [0x55fed4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5635796) /* 0x55fed4 */)));
    // 004be4a3  d905d8ff5500           -fld dword ptr [0x55ffd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5636056) /* 0x55ffd8 */)));
    // 004be4a9  897dec                 -mov dword ptr [ebp - 0x14], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edi;
    // 004be4ac  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004be4af  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004be4b1  d91d54ff5500           -fstp dword ptr [0x55ff54]
    app->getMemory<float>(x86::reg32(5635924) /* 0x55ff54 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be4b7  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004be4b9  d91d74ff5500           -fstp dword ptr [0x55ff74]
    app->getMemory<float>(x86::reg32(5635956) /* 0x55ff74 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be4bf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004be4c1  d91d78ff5500           -fstp dword ptr [0x55ff78]
    app->getMemory<float>(x86::reg32(5635960) /* 0x55ff78 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be4c7  d91db8ff5500           -fstp dword ptr [0x55ffb8]
    app->getMemory<float>(x86::reg32(5636024) /* 0x55ffb8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be4cd  d91dd4ff5500           -fstp dword ptr [0x55ffd4]
    app->getMemory<float>(x86::reg32(5636052) /* 0x55ffd4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be4d3  d91df8ff5500           -fstp dword ptr [0x55fff8]
    app->getMemory<float>(x86::reg32(5636088) /* 0x55fff8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be4d9  db45ec                 -fild dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */))));
    // 004be4dc  db45f4                 -fild dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))));
    // 004be4df  d90554ff5500           -fld dword ptr [0x55ff54]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5635924) /* 0x55ff54 */)));
    // 004be4e5  d90574ff5500           -fld dword ptr [0x55ff74]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5635956) /* 0x55ff74 */)));
    // 004be4eb  d905f8ff5500           -fld dword ptr [0x55fff8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5636088) /* 0x55fff8 */)));
    // 004be4f1  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004be4f3  d91dd8fe5500           -fstp dword ptr [0x55fed8]
    app->getMemory<float>(x86::reg32(5635800) /* 0x55fed8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be4f9  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004be4fb  d91d34ff5500           -fstp dword ptr [0x55ff34]
    app->getMemory<float>(x86::reg32(5635892) /* 0x55ff34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be501  d91d94ff5500           -fstp dword ptr [0x55ff94]
    app->getMemory<float>(x86::reg32(5635988) /* 0x55ff94 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be507  d91db4ff5500           -fstp dword ptr [0x55ffb4]
    app->getMemory<float>(x86::reg32(5636020) /* 0x55ffb4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be50d  d91d18005600           -fstp dword ptr [0x560018]
    app->getMemory<float>(x86::reg32(5636120) /* 0x560018 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be513  d905d8fe5500           -fld dword ptr [0x55fed8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5635800) /* 0x55fed8 */)));
    // 004be519  d90594ff5500           -fld dword ptr [0x55ff94]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5635988) /* 0x55ff94 */)));
    // 004be51f  d905b4ff5500           -fld dword ptr [0x55ffb4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5636020) /* 0x55ffb4 */)));
    // 004be525  d90534ff5500           -fld dword ptr [0x55ff34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5635892) /* 0x55ff34 */)));
    // 004be52b  d90518005600           -fld dword ptr [0x560018]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5636120) /* 0x560018 */)));
    // 004be531  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004be533  d91df8fe5500           -fstp dword ptr [0x55fef8]
    app->getMemory<float>(x86::reg32(5635832) /* 0x55fef8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be539  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004be53b  d91df4ff5500           -fstp dword ptr [0x55fff4]
    app->getMemory<float>(x86::reg32(5636084) /* 0x55fff4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be541  d91d14005600           -fstp dword ptr [0x560014]
    app->getMemory<float>(x86::reg32(5636116) /* 0x560014 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be547  d91d34005600           -fstp dword ptr [0x560034]
    app->getMemory<float>(x86::reg32(5636148) /* 0x560034 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be54d  d91d38005600           -fstp dword ptr [0x560038]
    app->getMemory<float>(x86::reg32(5636152) /* 0x560038 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be553  a1f8fe5500             -mov eax, dword ptr [0x55fef8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635832) /* 0x55fef8 */);
    // 004be558  a318ff5500             -mov dword ptr [0x55ff18], eax
    app->getMemory<x86::reg32>(x86::reg32(5635864) /* 0x55ff18 */) = cpu.eax;
    // 004be55d  a118ff5500             -mov eax, dword ptr [0x55ff18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635864) /* 0x55ff18 */);
    // 004be562  a338ff5500             -mov dword ptr [0x55ff38], eax
    app->getMemory<x86::reg32>(x86::reg32(5635896) /* 0x55ff38 */) = cpu.eax;
    // 004be567  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be569  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be56a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be56b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be56c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be56d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be56e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be56f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4be570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be570  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be571  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be572  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be573  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be575  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be578  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004be57a  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004be57d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004be57f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004be581  90                     -nop 
    ;
    // 004be582  a15c3a7a00             -mov eax, dword ptr [0x7a3a5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8010332) /* 0x7a3a5c */);
    // 004be587  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004be589  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004be58c  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004be592  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004be598  3b723c                 +cmp esi, dword ptr [edx + 0x3c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be59b  7f1d                   -jg 0x4be5ba
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004be5ba;
    }
    // 004be59d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004be59f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004be5a2  8b4a40                 -mov ecx, dword ptr [edx + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004be5a5  01f0                   +add eax, esi
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
    // 004be5a7  8b0cc1                 -mov ecx, dword ptr [ecx + eax*8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 004be5aa  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 004be5ac  8b5240                 -mov edx, dword ptr [edx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004be5af  8b44c204               -mov eax, dword ptr [edx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004be5b3  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004be5b6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004be5b8  eb0f                   -jmp 0x4be5c9
    goto L_0x004be5c9;
L_0x004be5ba:
    // 004be5ba  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004be5bd  c70380020000           -mov dword ptr [ebx], 0x280
    app->getMemory<x86::reg32>(cpu.ebx) = 640 /*0x280*/;
    // 004be5c3  c700e0010000           -mov dword ptr [eax], 0x1e0
    app->getMemory<x86::reg32>(cpu.eax) = 480 /*0x1e0*/;
L_0x004be5c9:
    // 004be5c9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be5cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be5cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be5cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be5ce  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4be5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be5e0  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004be5e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be5e3  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004be5e6  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004be5e9  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004be5ec  8d4de0                 -lea ecx, [ebp - 0x20]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004be5ef  8d5ddc                 -lea ebx, [ebp - 0x24]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004be5f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004be5f3  8d55d8                 -lea edx, [ebp - 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004be5f6  a1c4fe5500             -mov eax, dword ptr [0x55fec4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5635780) /* 0x55fec4 */);
    // 004be5fb  e870ffffff             -call 0x4be570
    cpu.esp -= 4;
    sub_4be570(app, cpu);
    if (cpu.terminate) return;
    // 004be600  c705a8db7c0002000000   -mov dword ptr [0x7cdba8], 2
    app->getMemory<x86::reg32>(x86::reg32(8182696) /* 0x7cdba8 */) = 2 /*0x2*/;
    // 004be60a  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004be60d  6bc003                 -imul eax, eax, 3
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(3 /*0x3*/)));
    // 004be610  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004be613  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004be616  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004be619  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be61b  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 004be61d  895dd8                 -mov dword ptr [ebp - 0x28], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ebx;
    // 004be620  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004be622  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004be629  7406                   -je 0x4be631
    if (cpu.flags.zf)
    {
        goto L_0x004be631;
    }
    // 004be62b  8b354cbc6f00           -mov esi, dword ptr [0x6fbc4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322700) /* 0x6fbc4c */);
L_0x004be631:
    // 004be631  bf88db7c00             -mov edi, 0x7cdb88
    cpu.edi = 8182664 /*0x7cdb88*/;
    // 004be636  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be638  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004be63a  8b4de0                 -mov ecx, dword ptr [ebp - 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004be63d  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004be640  f7c602000000           +test esi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 2 /*0x2*/));
    // 004be646  740a                   -je 0x4be652
    if (cpu.flags.zf)
    {
        goto L_0x004be652;
    }
    // 004be648  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004be64a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004be64c  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004be64e  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be650  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
L_0x004be652:
    // 004be652  e851020000             -call 0x4be8a8
    cpu.esp -= 4;
    sub_4be8a8(app, cpu);
    if (cpu.terminate) return;
    // 004be657  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004be65a  f7c601000000           +test esi, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 1 /*0x1*/));
    // 004be660  741c                   -je 0x4be67e
    if (cpu.flags.zf)
    {
        goto L_0x004be67e;
    }
    // 004be662  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 004be664  035dd8                 -add ebx, dword ptr [ebp - 0x28]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 004be667  f7c602000000           +test esi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 2 /*0x2*/));
    // 004be66d  740f                   -je 0x4be67e
    if (cpu.flags.zf)
    {
        goto L_0x004be67e;
    }
    // 004be66f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004be671  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004be673  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004be675  0345e4                 -add eax, dword ptr [ebp - 0x1c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 004be678  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004be67a  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004be67c  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004be67e:
    // 004be67e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be680  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004be683  e814020000             -call 0x4be89c
    cpu.esp -= 4;
    sub_4be89c(app, cpu);
    if (cpu.terminate) return;
    // 004be688  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be68a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004be68c  8b4de0                 -mov ecx, dword ptr [ebp - 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004be68f  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004be692  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004be694  bf80da7c00             -mov edi, 0x7cda80
    cpu.edi = 8182400 /*0x7cda80*/;
    // 004be699  e80a020000             -call 0x4be8a8
    cpu.esp -= 4;
    sub_4be8a8(app, cpu);
    if (cpu.terminate) return;
    // 004be69e  bf08db7c00             -mov edi, 0x7cdb08
    cpu.edi = 8182536 /*0x7cdb08*/;
    // 004be6a3  e800020000             -call 0x4be8a8
    cpu.esp -= 4;
    sub_4be8a8(app, cpu);
    if (cpu.terminate) return;
    // 004be6a8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004be6aa  bfa0da7c00             -mov edi, 0x7cdaa0
    cpu.edi = 8182432 /*0x7cdaa0*/;
    // 004be6af  e8f4010000             -call 0x4be8a8
    cpu.esp -= 4;
    sub_4be8a8(app, cpu);
    if (cpu.terminate) return;
    // 004be6b4  bf28db7c00             -mov edi, 0x7cdb28
    cpu.edi = 8182568 /*0x7cdb28*/;
    // 004be6b9  e8ea010000             -call 0x4be8a8
    cpu.esp -= 4;
    sub_4be8a8(app, cpu);
    if (cpu.terminate) return;
    // 004be6be  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004be6c1  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004be6c4  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 004be6c6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004be6c8  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004be6cb  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be6cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be6cf  bf80da7c00             -mov edi, 0x7cda80
    cpu.edi = 8182400 /*0x7cda80*/;
    // 004be6d4  e8c3010000             -call 0x4be89c
    cpu.esp -= 4;
    sub_4be89c(app, cpu);
    if (cpu.terminate) return;
    // 004be6d9  bf08db7c00             -mov edi, 0x7cdb08
    cpu.edi = 8182536 /*0x7cdb08*/;
    // 004be6de  e8b9010000             -call 0x4be89c
    cpu.esp -= 4;
    sub_4be89c(app, cpu);
    if (cpu.terminate) return;
    // 004be6e3  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004be6e6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004be6e8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004be6ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be6ec  bfa0da7c00             -mov edi, 0x7cdaa0
    cpu.edi = 8182432 /*0x7cdaa0*/;
    // 004be6f1  e8a6010000             -call 0x4be89c
    cpu.esp -= 4;
    sub_4be89c(app, cpu);
    if (cpu.terminate) return;
    // 004be6f6  bf28db7c00             -mov edi, 0x7cdb28
    cpu.edi = 8182568 /*0x7cdb28*/;
    // 004be6fb  e89c010000             -call 0x4be89c
    cpu.esp -= 4;
    sub_4be89c(app, cpu);
    if (cpu.terminate) return;
    // 004be700  837dd800               +cmp dword ptr [ebp - 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004be704  742e                   -je 0x4be734
    if (cpu.flags.zf)
    {
        goto L_0x004be734;
    }
    // 004be706  7c0d                   -jl 0x4be715
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be715;
    }
    // 004be708  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004be70a  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004be70d  8b4de0                 -mov ecx, dword ptr [ebp - 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004be710  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004be713  eb29                   -jmp 0x4be73e
    goto L_0x004be73e;
L_0x004be715:
    // 004be715  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004be718  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004be71b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004be71d  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004be722  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be724  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004be726  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004be729  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004be72c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004be72e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004be730  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004be732  eb0a                   -jmp 0x4be73e
    goto L_0x004be73e;
L_0x004be734:
    // 004be734  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be736  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004be738  8b4de0                 -mov ecx, dword ptr [ebp - 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004be73b  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
L_0x004be73e:
    // 004be73e  bf40277a00             -mov edi, 0x7a2740
    cpu.edi = 8005440 /*0x7a2740*/;
    // 004be743  e854010000             -call 0x4be89c
    cpu.esp -= 4;
    sub_4be89c(app, cpu);
    if (cpu.terminate) return;
    // 004be748  e8fbd40100             -call 0x4dbc48
    cpu.esp -= 4;
    sub_4dbc48(app, cpu);
    if (cpu.terminate) return;
    // 004be74d  e85212fcff             -call 0x47f9a4
    cpu.esp -= 4;
    sub_47f9a4(app, cpu);
    if (cpu.terminate) return;
    // 004be752  6955fca4010000         -imul edx, dword ptr [ebp - 4], 0x1a4
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))) * x86::sreg64(x86::sreg32(420 /*0x1a4*/)));
    // 004be759  8b0dd0fe5500           -mov ecx, dword ptr [0x55fed0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5635792) /* 0x55fed0 */);
    // 004be75f  db45e0                 -fild dword ptr [ebp - 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */))));
    // 004be762  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004be764  d88a08bd6f00           -fmul dword ptr [edx + 0x6fbd08]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(7322888) /* 0x6fbd08 */));
    // 004be76a  db5de8                 -fistp dword ptr [ebp - 0x18]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004be76d  014de8                 -add dword ptr [ebp - 0x18], ecx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004be770  d88a10bd6f00           -fmul dword ptr [edx + 0x6fbd10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(7322896) /* 0x6fbd10 */));
    // 004be776  db5df0                 -fistp dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004be779  294df0                 -sub dword ptr [ebp - 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004be77c  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004be77f  2945f0                 -sub dword ptr [ebp - 0x10], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be782  db45e4                 -fild dword ptr [ebp - 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))));
    // 004be785  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004be787  d88a04bd6f00           -fmul dword ptr [edx + 0x6fbd04]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(7322884) /* 0x6fbd04 */));
    // 004be78d  db5dec                 -fistp dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004be790  014dec                 -add dword ptr [ebp - 0x14], ecx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004be793  d88a0cbd6f00           -fmul dword ptr [edx + 0x6fbd0c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(7322892) /* 0x6fbd0c */));
    // 004be799  db5df4                 -fistp dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004be79c  294df4                 -sub dword ptr [ebp - 0xc], ecx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004be79f  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004be7a2  2945f4                 -sub dword ptr [ebp - 0xc], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be7a5  bf48db7c00             -mov edi, 0x7cdb48
    cpu.edi = 8182600 /*0x7cdb48*/;
    // 004be7aa  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004be7ad  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004be7b0  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004be7b3  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004be7b6  e8ed000000             -call 0x4be8a8
    cpu.esp -= 4;
    sub_4be8a8(app, cpu);
    if (cpu.terminate) return;
    // 004be7bb  6945f4e8030000         -imul eax, dword ptr [ebp - 0xc], 0x3e8
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))) * x86::sreg64(x86::sreg32(1000 /*0x3e8*/)));
    // 004be7c2  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004be7c3  b915020000             -mov ecx, 0x215
    cpu.ecx = 533 /*0x215*/;
    // 004be7c8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be7ca  6b55f00a               -imul edx, dword ptr [ebp - 0x10], 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004be7ce  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 004be7d1  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004be7d4  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004be7d6  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 004be7d8  035dec                 -add ebx, dword ptr [ebp - 0x14]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004be7db  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004be7de  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004be7e1  e8b6000000             -call 0x4be89c
    cpu.esp -= 4;
    sub_4be89c(app, cpu);
    if (cpu.terminate) return;
    // 004be7e6  bf68db7c00             -mov edi, 0x7cdb68
    cpu.edi = 8182632 /*0x7cdb68*/;
    // 004be7eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004be7ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004be7ef  b980020000             -mov ecx, 0x280
    cpu.ecx = 640 /*0x280*/;
    // 004be7f4  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 004be7f9  e89e000000             -call 0x4be89c
    cpu.esp -= 4;
    sub_4be89c(app, cpu);
    if (cpu.terminate) return;
    // 004be7fe  e8a5000000             -call 0x4be8a8
    cpu.esp -= 4;
    sub_4be8a8(app, cpu);
    if (cpu.terminate) return;
    // 004be803  db45e0                 -fild dword ptr [ebp - 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */))));
    // 004be806  da75e4                 -fidiv dword ptr [ebp - 0x1c]
    cpu.fpu.st(0) /= x86::Float(double(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))));
    // 004be809  68abaaaa3f             -push 0x3faaaaab
    app->getMemory<x86::reg32>(cpu.esp-4) = 1068149419 /*0x3faaaaab*/;
    cpu.esp -= 4;
    // 004be80e  d83c24                 -fdivr dword ptr [esp]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esp)) / cpu.fpu.st(0);
    // 004be811  c704240000fe42         -mov dword ptr [esp], 0x42fe0000
    app->getMemory<x86::reg32>(cpu.esp) = 1123942400 /*0x42fe0000*/;
    // 004be818  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004be81b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004be81d  d91dd88a5300           -fstp dword ptr [0x538ad8]
    app->getMemory<float>(x86::reg32(5475032) /* 0x538ad8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be823  c70424000020c1         -mov dword ptr [esp], 0xc1200000
    app->getMemory<x86::reg32>(cpu.esp) = 3240099840 /*0xc1200000*/;
    // 004be82a  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004be82d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004be82f  d91dd4a95300           -fstp dword ptr [0x53a9d4]
    app->getMemory<float>(x86::reg32(5482964) /* 0x53a9d4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be835  c7042400002041         -mov dword ptr [esp], 0x41200000
    app->getMemory<x86::reg32>(cpu.esp) = 1092616192 /*0x41200000*/;
    // 004be83c  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004be83f  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004be841  d91de0a95300           -fstp dword ptr [0x53a9e0]
    app->getMemory<float>(x86::reg32(5482976) /* 0x53a9e0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be847  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004be849  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004be84c  e87ffbffff             -call 0x4be3d0
    cpu.esp -= 4;
    sub_4be3d0(app, cpu);
    if (cpu.terminate) return;
    // 004be851  e806000000             -call 0x4be85c
    cpu.esp -= 4;
    sub_4be85c(app, cpu);
    if (cpu.terminate) return;
    // 004be856  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004be858  61                     -popal 
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
    // 004be859  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4be85a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be85a  90                     -nop 
    ;
    // 004be85b  90                     -nop 
    ;
    // 004be85c  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004be85d  a188db7c00             -mov eax, dword ptr [0x7cdb88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182664) /* 0x7cdb88 */);
    // 004be862  8b1d8cdb7c00           -mov ebx, dword ptr [0x7cdb8c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8182668) /* 0x7cdb8c */);
    // 004be868  8b0d90db7c00           -mov ecx, dword ptr [0x7cdb90]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182672) /* 0x7cdb90 */);
    // 004be86e  8b1594db7c00           -mov edx, dword ptr [0x7cdb94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182676) /* 0x7cdb94 */);
    // 004be874  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004be876  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be878  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004be87a:
    // 004be87a  81ee80020000           +sub esi, 0x280
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(640 /*0x280*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004be880  7e03                   -jle 0x4be885
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be885;
    }
    // 004be882  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be883  ebf5                   -jmp 0x4be87a
    goto L_0x004be87a;
L_0x004be885:
    // 004be885  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004be887  6bff03                 -imul edi, edi, 3
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(3 /*0x3*/)));
    // 004be88a  c1ef02                 -shr edi, 2
    cpu.edi >>= 2 /*0x2*/ % 32;
    // 004be88d  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004be88f  bf50277a00             -mov edi, 0x7a2750
    cpu.edi = 8005456 /*0x7a2750*/;
    // 004be894  e803000000             -call 0x4be89c
    cpu.esp -= 4;
    sub_4be89c(app, cpu);
    if (cpu.terminate) return;
    // 004be899  61                     -popal 
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
    // 004be89a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4be85c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004be85c;
    // 004be85a  90                     -nop 
    ;
    // 004be85b  90                     -nop 
    ;
L_entry_0x004be85c:
    // 004be85c  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004be85d  a188db7c00             -mov eax, dword ptr [0x7cdb88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182664) /* 0x7cdb88 */);
    // 004be862  8b1d8cdb7c00           -mov ebx, dword ptr [0x7cdb8c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8182668) /* 0x7cdb8c */);
    // 004be868  8b0d90db7c00           -mov ecx, dword ptr [0x7cdb90]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182672) /* 0x7cdb90 */);
    // 004be86e  8b1594db7c00           -mov edx, dword ptr [0x7cdb94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182676) /* 0x7cdb94 */);
    // 004be874  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004be876  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004be878  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004be87a:
    // 004be87a  81ee80020000           +sub esi, 0x280
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(640 /*0x280*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004be880  7e03                   -jle 0x4be885
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004be885;
    }
    // 004be882  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004be883  ebf5                   -jmp 0x4be87a
    goto L_0x004be87a;
L_0x004be885:
    // 004be885  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004be887  6bff03                 -imul edi, edi, 3
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(3 /*0x3*/)));
    // 004be88a  c1ef02                 -shr edi, 2
    cpu.edi >>= 2 /*0x2*/ % 32;
    // 004be88d  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004be88f  bf50277a00             -mov edi, 0x7a2750
    cpu.edi = 8005456 /*0x7a2750*/;
    // 004be894  e803000000             -call 0x4be89c
    cpu.esp -= 4;
    sub_4be89c(app, cpu);
    if (cpu.terminate) return;
    // 004be899  61                     -popal 
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
    // 004be89a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4be89c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be89c  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004be89e  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004be8a1  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004be8a4  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004be8a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4be8a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be8a8  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004be8ab  895f14                 -mov dword ptr [edi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004be8ae  894f18                 -mov dword ptr [edi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004be8b1  89571c                 -mov dword ptr [edi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004be8b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4be8b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be8b6  90                     -nop 
    ;
    // 004be8b7  90                     -nop 
    ;
    // 004be8b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004be8b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be8ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004be8bb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004be8bd  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004be8c0  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004be8c3  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004be8c6  e815030000             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 004be8cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be8cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be8cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be8ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4be8b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004be8b8;
    // 004be8b6  90                     -nop 
    ;
    // 004be8b7  90                     -nop 
    ;
L_entry_0x004be8b8:
    // 004be8b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004be8b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be8ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004be8bb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004be8bd  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004be8c0  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004be8c3  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004be8c6  e815030000             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 004be8cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be8cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be8cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be8ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4be8d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be8d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be8d1  be60da7c00             -mov esi, 0x7cda60
    cpu.esi = 8182368 /*0x7cda60*/;
    // 004be8d6  e8ddffffff             -call 0x4be8b8
    cpu.esp -= 4;
    sub_4be8b8(app, cpu);
    if (cpu.terminate) return;
    // 004be8db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be8dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4be8de(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be8de  90                     -nop 
    ;
    // 004be8df  90                     -nop 
    ;
    // 004be8e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be8e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004be8e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be8e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be8e5  8b15a8db7c00           -mov edx, dword ptr [0x7cdba8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182696) /* 0x7cdba8 */);
    // 004be8eb  a1a0db7c00             -mov eax, dword ptr [0x7cdba0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182688) /* 0x7cdba0 */);
    // 004be8f0  4a                     -dec edx
    (cpu.edx)--;
    // 004be8f1  8b0d68da7c00           -mov ecx, dword ptr [0x7cda68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */);
    // 004be8f7  8915a8db7c00           -mov dword ptr [0x7cdba8], edx
    app->getMemory<x86::reg32>(x86::reg32(8182696) /* 0x7cdba8 */) = cpu.edx;
    // 004be8fd  39c8                   +cmp eax, ecx
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
    // 004be8ff  7c12                   -jl 0x4be913
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be913;
    }
    // 004be901  f6054cbc6f0002         +test byte ptr [0x6fbc4c], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7322700) /* 0x6fbc4c */) & 2 /*0x2*/));
    // 004be908  745a                   -je 0x4be964
    if (cpu.flags.zf)
    {
        goto L_0x004be964;
    }
    // 004be90a  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004be911  7451                   -je 0x4be964
    if (cpu.flags.zf)
    {
        goto L_0x004be964;
    }
L_0x004be913:
    // 004be913  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004be918  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004be91a  e8e12ff7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
    // 004be91f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004be924  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004be926  e8d52ff7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
    // 004be92b  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004be932  750e                   -jne 0x4be942
    if (!cpu.flags.zf)
    {
        goto L_0x004be942;
    }
    // 004be934  6854005600             -push 0x560054
    app->getMemory<x86::reg32>(cpu.esp-4) = 5636180 /*0x560054*/;
    cpu.esp -= 4;
    // 004be939  68d4fe5500             -push 0x55fed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5635796 /*0x55fed4*/;
    cpu.esp -= 4;
    // 004be93e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004be940  eb0c                   -jmp 0x4be94e
    goto L_0x004be94e;
L_0x004be942:
    // 004be942  6854005600             -push 0x560054
    app->getMemory<x86::reg32>(cpu.esp-4) = 5636180 /*0x560054*/;
    cpu.esp -= 4;
    // 004be947  68d4fe5500             -push 0x55fed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5635796 /*0x55fed4*/;
    cpu.esp -= 4;
    // 004be94c  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
L_0x004be94e:
    // 004be94e  ff1530f99e00           -call dword ptr [0x9ef930]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418480) /* 0x9ef930 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004be954  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004be959  8b15603a7a00           -mov edx, dword ptr [0x7a3a60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8010336) /* 0x7a3a60 */);
    // 004be95f  e89c2ff7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x004be964:
    // 004be964  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be965  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be966  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be967  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4be8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004be8e0;
    // 004be8de  90                     -nop 
    ;
    // 004be8df  90                     -nop 
    ;
L_entry_0x004be8e0:
    // 004be8e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be8e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004be8e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be8e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be8e5  8b15a8db7c00           -mov edx, dword ptr [0x7cdba8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182696) /* 0x7cdba8 */);
    // 004be8eb  a1a0db7c00             -mov eax, dword ptr [0x7cdba0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182688) /* 0x7cdba0 */);
    // 004be8f0  4a                     -dec edx
    (cpu.edx)--;
    // 004be8f1  8b0d68da7c00           -mov ecx, dword ptr [0x7cda68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */);
    // 004be8f7  8915a8db7c00           -mov dword ptr [0x7cdba8], edx
    app->getMemory<x86::reg32>(x86::reg32(8182696) /* 0x7cdba8 */) = cpu.edx;
    // 004be8fd  39c8                   +cmp eax, ecx
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
    // 004be8ff  7c12                   -jl 0x4be913
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004be913;
    }
    // 004be901  f6054cbc6f0002         +test byte ptr [0x6fbc4c], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7322700) /* 0x6fbc4c */) & 2 /*0x2*/));
    // 004be908  745a                   -je 0x4be964
    if (cpu.flags.zf)
    {
        goto L_0x004be964;
    }
    // 004be90a  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004be911  7451                   -je 0x4be964
    if (cpu.flags.zf)
    {
        goto L_0x004be964;
    }
L_0x004be913:
    // 004be913  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004be918  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004be91a  e8e12ff7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
    // 004be91f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004be924  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004be926  e8d52ff7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
    // 004be92b  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004be932  750e                   -jne 0x4be942
    if (!cpu.flags.zf)
    {
        goto L_0x004be942;
    }
    // 004be934  6854005600             -push 0x560054
    app->getMemory<x86::reg32>(cpu.esp-4) = 5636180 /*0x560054*/;
    cpu.esp -= 4;
    // 004be939  68d4fe5500             -push 0x55fed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5635796 /*0x55fed4*/;
    cpu.esp -= 4;
    // 004be93e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004be940  eb0c                   -jmp 0x4be94e
    goto L_0x004be94e;
L_0x004be942:
    // 004be942  6854005600             -push 0x560054
    app->getMemory<x86::reg32>(cpu.esp-4) = 5636180 /*0x560054*/;
    cpu.esp -= 4;
    // 004be947  68d4fe5500             -push 0x55fed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5635796 /*0x55fed4*/;
    cpu.esp -= 4;
    // 004be94c  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
L_0x004be94e:
    // 004be94e  ff1530f99e00           -call dword ptr [0x9ef930]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418480) /* 0x9ef930 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004be954  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004be959  8b15603a7a00           -mov edx, dword ptr [0x7a3a60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8010336) /* 0x7a3a60 */);
    // 004be95f  e89c2ff7ff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x004be964:
    // 004be964  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be965  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be966  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004be967  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4be970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004be970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004be971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004be972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004be973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004be974  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004be975  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004be976  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004be978  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004be97a  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 004be981  7407                   -je 0x4be98a
    if (cpu.flags.zf)
    {
        goto L_0x004be98a;
    }
    // 004be983  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004be988  eb13                   -jmp 0x4be99d
    goto L_0x004be99d;
L_0x004be98a:
    // 004be98a  a168da7c00             -mov eax, dword ptr [0x7cda68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */);
    // 004be98f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004be991  b928000000             -mov ecx, 0x28
    cpu.ecx = 40 /*0x28*/;
    // 004be996  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004be999  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004be99b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004be99d:
    // 004be99d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004be99f  7d02                   -jge 0x4be9a3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004be9a3;
    }
    // 004be9a1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x004be9a3:
    // 004be9a3  f6054cbc6f0002         +test byte ptr [0x6fbc4c], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7322700) /* 0x6fbc4c */) & 2 /*0x2*/));
    // 004be9aa  740d                   -je 0x4be9b9
    if (cpu.flags.zf)
    {
        goto L_0x004be9b9;
    }
    // 004be9ac  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 004be9b3  0f8571000000           -jne 0x4bea2a
    if (!cpu.flags.zf)
    {
        goto L_0x004bea2a;
    }
L_0x004be9b9:
    // 004be9b9  b888db7c00             -mov eax, 0x7cdb88
    cpu.eax = 8182664 /*0x7cdb88*/;
    // 004be9be  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004be9c0  8b3da0db7c00           -mov edi, dword ptr [0x7cdba0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8182688) /* 0x7cdba0 */);
    // 004be9c6  e875000000             -call 0x4bea40
    cpu.esp -= 4;
    sub_4bea40(app, cpu);
    if (cpu.terminate) return;
    // 004be9cb  b880da7c00             -mov eax, 0x7cda80
    cpu.eax = 8182400 /*0x7cda80*/;
    // 004be9d0  8b1d94da7c00           -mov ebx, dword ptr [0x7cda94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8182420) /* 0x7cda94 */);
    // 004be9d6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004be9d8  8b359cda7c00           -mov esi, dword ptr [0x7cda9c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182428) /* 0x7cda9c */);
    // 004be9de  e85d000000             -call 0x4bea40
    cpu.esp -= 4;
    sub_4bea40(app, cpu);
    if (cpu.terminate) return;
    // 004be9e3  b8a0da7c00             -mov eax, 0x7cdaa0
    cpu.eax = 8182432 /*0x7cdaa0*/;
    // 004be9e8  891d94da7c00           -mov dword ptr [0x7cda94], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182420) /* 0x7cda94 */) = cpu.ebx;
    // 004be9ee  89359cda7c00           -mov dword ptr [0x7cda9c], esi
    app->getMemory<x86::reg32>(x86::reg32(8182428) /* 0x7cda9c */) = cpu.esi;
    // 004be9f4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004be9f6  8b1db4da7c00           -mov ebx, dword ptr [0x7cdab4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8182452) /* 0x7cdab4 */);
    // 004be9fc  8b35bcda7c00           -mov esi, dword ptr [0x7cdabc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182460) /* 0x7cdabc */);
    // 004bea02  e839000000             -call 0x4bea40
    cpu.esp -= 4;
    sub_4bea40(app, cpu);
    if (cpu.terminate) return;
    // 004bea07  891db4da7c00           -mov dword ptr [0x7cdab4], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182452) /* 0x7cdab4 */) = cpu.ebx;
    // 004bea0d  8935bcda7c00           -mov dword ptr [0x7cdabc], esi
    app->getMemory<x86::reg32>(x86::reg32(8182460) /* 0x7cdabc */) = cpu.esi;
    // 004bea13  e8b8f9ffff             -call 0x4be3d0
    cpu.esp -= 4;
    sub_4be3d0(app, cpu);
    if (cpu.terminate) return;
    // 004bea18  3b3da0db7c00           +cmp edi, dword ptr [0x7cdba0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(8182688) /* 0x7cdba0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bea1e  7e0a                   -jle 0x4bea2a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bea2a;
    }
    // 004bea20  c705a8db7c0002000000   -mov dword ptr [0x7cdba8], 2
    app->getMemory<x86::reg32>(x86::reg32(8182696) /* 0x7cdba8 */) = 2 /*0x2*/;
L_0x004bea2a:
    // 004bea2a  e82dfeffff             -call 0x4be85c
    cpu.esp -= 4;
    sub_4be85c(app, cpu);
    if (cpu.terminate) return;
    // 004bea2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bea35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bea36(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bea36  90                     -nop 
    ;
    // 004bea37  90                     -nop 
    ;
    // 004bea38  90                     -nop 
    ;
    // 004bea39  90                     -nop 
    ;
    // 004bea3a  90                     -nop 
    ;
    // 004bea3b  90                     -nop 
    ;
    // 004bea3c  90                     -nop 
    ;
    // 004bea3d  90                     -nop 
    ;
    // 004bea3e  90                     -nop 
    ;
    // 004bea3f  90                     -nop 
    ;
    // 004bea40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bea41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bea42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bea43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bea44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bea45  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bea47  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bea4a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bea4c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bea4e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004bea55  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bea57  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bea59  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bea5c  c1e202                 +shl edx, 2
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
    // 004bea5f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004bea61  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004bea64  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bea66  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bea68  0f8481000000           -je 0x4beaef
    if (cpu.flags.zf)
    {
        goto L_0x004beaef;
    }
    // 004bea6e  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004bea71  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bea73  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004bea76  a168da7c00             -mov eax, dword ptr [0x7cda68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */);
    // 004bea7b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bea7d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bea80  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bea82  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bea84  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004bea87  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bea89  39c7                   +cmp edi, eax
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
    // 004bea8b  7c62                   -jl 0x4beaef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004beaef;
    }
    // 004bea8d  3b3d68da7c00           +cmp edi, dword ptr [0x7cda68]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bea93  7f5a                   -jg 0x4beaef
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004beaef;
    }
    // 004bea95  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 004bea99  7c54                   -jl 0x4beaef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004beaef;
    }
    // 004bea9b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bea9d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bea9f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004beaa2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004beaa4  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004beaa6  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004beaa8  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004beaab  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004beaad  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004beaaf  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004beab1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004beab3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004beab5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004beab8  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004beaba  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004beabc  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004beabf  8b7914                 -mov edi, dword ptr [ecx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004beac2  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004beac4  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004beac7  897914                 -mov dword ptr [ecx + 0x14], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 004beaca  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004beacc  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004beacf  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bead2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bead4  8b791c                 -mov edi, dword ptr [ecx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004bead7  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004beada  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004beadc  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004beadf  89791c                 -mov dword ptr [ecx + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 004beae2  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004beae4  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004beae7  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004beaea  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004beaec  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004beaef:
    // 004beaef  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004beaf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beaf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beaf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beaf4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beaf5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beaf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bea40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004bea40;
    // 004bea36  90                     -nop 
    ;
    // 004bea37  90                     -nop 
    ;
    // 004bea38  90                     -nop 
    ;
    // 004bea39  90                     -nop 
    ;
    // 004bea3a  90                     -nop 
    ;
    // 004bea3b  90                     -nop 
    ;
    // 004bea3c  90                     -nop 
    ;
    // 004bea3d  90                     -nop 
    ;
    // 004bea3e  90                     -nop 
    ;
    // 004bea3f  90                     -nop 
    ;
L_entry_0x004bea40:
    // 004bea40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bea41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bea42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bea43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bea44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bea45  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bea47  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bea4a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bea4c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bea4e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004bea55  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bea57  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bea59  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bea5c  c1e202                 +shl edx, 2
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
    // 004bea5f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004bea61  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004bea64  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bea66  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bea68  0f8481000000           -je 0x4beaef
    if (cpu.flags.zf)
    {
        goto L_0x004beaef;
    }
    // 004bea6e  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004bea71  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bea73  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004bea76  a168da7c00             -mov eax, dword ptr [0x7cda68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */);
    // 004bea7b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bea7d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bea80  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bea82  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bea84  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004bea87  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bea89  39c7                   +cmp edi, eax
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
    // 004bea8b  7c62                   -jl 0x4beaef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004beaef;
    }
    // 004bea8d  3b3d68da7c00           +cmp edi, dword ptr [0x7cda68]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bea93  7f5a                   -jg 0x4beaef
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004beaef;
    }
    // 004bea95  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 004bea99  7c54                   -jl 0x4beaef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004beaef;
    }
    // 004bea9b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bea9d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bea9f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004beaa2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004beaa4  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004beaa6  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004beaa8  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004beaab  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004beaad  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004beaaf  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004beab1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004beab3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004beab5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004beab8  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004beaba  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004beabc  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004beabf  8b7914                 -mov edi, dword ptr [ecx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004beac2  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004beac4  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004beac7  897914                 -mov dword ptr [ecx + 0x14], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 004beaca  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004beacc  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004beacf  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bead2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bead4  8b791c                 -mov edi, dword ptr [ecx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004bead7  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004beada  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004beadc  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004beadf  89791c                 -mov dword ptr [ecx + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 004beae2  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004beae4  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004beae7  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004beaea  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004beaec  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004beaef:
    // 004beaef  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004beaf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beaf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beaf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beaf4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beaf5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beaf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4beb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004beb00  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004beb01  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004beb03  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004beb05  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004beb08  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004beb0b  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004beb0e  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004beb11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beb12  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4beb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004beb20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004beb21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004beb22  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004beb24  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004beb26  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004beb28  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004beb2b  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004beb2d  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004beb30  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004beb32  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004beb35  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004beb38  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004beb3a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beb3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beb3c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4beb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004beb40  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004beb41  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004beb43  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004beb46  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004beb49  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004beb4c  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004beb4f  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004beb52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beb53  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4beb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004beb60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004beb61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004beb62  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004beb64  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004beb67  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004beb69  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004beb6c  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004beb6e  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004beb71  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004beb73  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004beb76  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004beb79  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004beb7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beb7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beb7d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4beb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004beb80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004beb81  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004beb82  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004beb84  8b3570da7c00           -mov esi, dword ptr [0x7cda70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182384) /* 0x7cda70 */);
    // 004beb8a  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004beb8c  a174da7c00             -mov eax, dword ptr [0x7cda74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182388) /* 0x7cda74 */);
    // 004beb91  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004beb93  a178da7c00             -mov eax, dword ptr [0x7cda78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182392) /* 0x7cda78 */);
    // 004beb98  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004beb9a  a17cda7c00             -mov eax, dword ptr [0x7cda7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182396) /* 0x7cda7c */);
    // 004beb9f  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004beba1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beba2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004beba3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4bebb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bebb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bebb1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bebb3  a360da7c00             -mov dword ptr [0x7cda60], eax
    app->getMemory<x86::reg32>(x86::reg32(8182368) /* 0x7cda60 */) = cpu.eax;
    // 004bebb8  891564da7c00           -mov dword ptr [0x7cda64], edx
    app->getMemory<x86::reg32>(x86::reg32(8182372) /* 0x7cda64 */) = cpu.edx;
    // 004bebbe  891d68da7c00           -mov dword ptr [0x7cda68], ebx
    app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */) = cpu.ebx;
    // 004bebc4  890d6cda7c00           -mov dword ptr [0x7cda6c], ecx
    app->getMemory<x86::reg32>(x86::reg32(8182380) /* 0x7cda6c */) = cpu.ecx;
    // 004bebca  e811000000             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 004bebcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bebd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4bebe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bebe0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bebe1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bebe2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bebe3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bebe5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bebe8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bebea  7d02                   -jge 0x4bebee
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bebee;
    }
    // 004bebec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bebee:
    // 004bebee  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bebf0  7d02                   -jge 0x4bebf4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bebf4;
    }
    // 004bebf2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bebf4:
    // 004bebf4  8b3568da7c00           -mov esi, dword ptr [0x7cda68]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */);
    // 004bebfa  4e                     -dec esi
    (cpu.esi)--;
    // 004bebfb  39f0                   +cmp eax, esi
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
    // 004bebfd  7c02                   -jl 0x4bec01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bec01;
    }
    // 004bebff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004bec01:
    // 004bec01  a370da7c00             -mov dword ptr [0x7cda70], eax
    app->getMemory<x86::reg32>(x86::reg32(8182384) /* 0x7cda70 */) = cpu.eax;
    // 004bec06  a16cda7c00             -mov eax, dword ptr [0x7cda6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182380) /* 0x7cda6c */);
    // 004bec0b  48                     -dec eax
    (cpu.eax)--;
    // 004bec0c  39c2                   +cmp edx, eax
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
    // 004bec0e  7c02                   -jl 0x4bec12
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bec12;
    }
    // 004bec10  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004bec12:
    // 004bec12  a168da7c00             -mov eax, dword ptr [0x7cda68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182376) /* 0x7cda68 */);
    // 004bec17  891574da7c00           -mov dword ptr [0x7cda74], edx
    app->getMemory<x86::reg32>(x86::reg32(8182388) /* 0x7cda74 */) = cpu.edx;
    // 004bec1d  2b0570da7c00           -sub eax, dword ptr [0x7cda70]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(8182384) /* 0x7cda70 */)));
    // 004bec23  39c3                   +cmp ebx, eax
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
    // 004bec25  7d02                   -jge 0x4bec29
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bec29;
    }
    // 004bec27  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004bec29:
    // 004bec29  8b1d74da7c00           -mov ebx, dword ptr [0x7cda74]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8182388) /* 0x7cda74 */);
    // 004bec2f  a378da7c00             -mov dword ptr [0x7cda78], eax
    app->getMemory<x86::reg32>(x86::reg32(8182392) /* 0x7cda78 */) = cpu.eax;
    // 004bec34  a16cda7c00             -mov eax, dword ptr [0x7cda6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182380) /* 0x7cda6c */);
    // 004bec39  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bec3b  39c1                   +cmp ecx, eax
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
    // 004bec3d  7d02                   -jge 0x4bec41
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bec41;
    }
    // 004bec3f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004bec41:
    // 004bec41  8b3574da7c00           -mov esi, dword ptr [0x7cda74]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8182388) /* 0x7cda74 */);
    // 004bec47  a37cda7c00             -mov dword ptr [0x7cda7c], eax
    app->getMemory<x86::reg32>(x86::reg32(8182396) /* 0x7cda7c */) = cpu.eax;
    // 004bec4c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bec4e  8b3d78da7c00           -mov edi, dword ptr [0x7cda78]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8182392) /* 0x7cda78 */);
    // 004bec54  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bec55  a170da7c00             -mov eax, dword ptr [0x7cda70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182384) /* 0x7cda70 */);
    // 004bec5a  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bec5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bec5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bec5e  8b1570da7c00           -mov edx, dword ptr [0x7cda70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8182384) /* 0x7cda70 */);
    // 004bec64  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bec65  ff152cf99e00           -call dword ptr [0x9ef92c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418476) /* 0x9ef92c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bec6b  68ad55033b             -push 0x3b0355ad
    app->getMemory<x86::reg32>(cpu.esp-4) = 990074285 /*0x3b0355ad*/;
    cpu.esp -= 4;
    // 004bec70  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 004bec75  a174da7c00             -mov eax, dword ptr [0x7cda74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182388) /* 0x7cda74 */);
    // 004bec7a  8b0d7cda7c00           -mov ecx, dword ptr [0x7cda7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8182396) /* 0x7cda7c */);
    // 004bec80  8b1d78da7c00           -mov ebx, dword ptr [0x7cda78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8182392) /* 0x7cda78 */);
    // 004bec86  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bec88  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bec8b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004bec8e  a170da7c00             -mov eax, dword ptr [0x7cda70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8182384) /* 0x7cda70 */);
    // 004bec93  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004bec96  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bec98  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bec9b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004bec9e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004beca1  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004beca4  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004beca7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004becaa  db0574da7c00           -fild dword ptr [0x7cda74]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(8182388) /* 0x7cda74 */))));
    // 004becb0  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004becb3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004becb6  db0570da7c00           -fild dword ptr [0x7cda70]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(8182384) /* 0x7cda70 */))));
    // 004becbc  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004becbf  e8ec040000             -call 0x4bf1b0
    cpu.esp -= 4;
    sub_4bf1b0(app, cpu);
    if (cpu.terminate) return;
    // 004becc4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004becc6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004becc7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004becc8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004becc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4becd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004becd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004becd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004becd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004becd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004becd5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004becd7  8b7a1c                 -mov edi, dword ptr [edx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004becda  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004becdd  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bece0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bece2  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bece4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bece6  7d02                   -jge 0x4becea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004becea;
    }
    // 004bece8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004becea:
    // 004becea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004beceb  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004becee  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004becf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004becf1  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004becf4  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004becf7  e8c4cf0100             -call 0x4dbcc0
    cpu.esp -= 4;
    sub_4dbcc0(app, cpu);
    if (cpu.terminate) return;
    // 004becfc  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004becff  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bed02  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bed05  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bed08  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bed0a  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bed0c  e8cffeffff             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 004bed11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bed12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bed13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bed14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4bed20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004bed20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bed21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bed22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bed23  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bed25  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bed27  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bed28  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004bed2b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bed2c  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bed2f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004bed32  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bed34  e887cf0100             -call 0x4dbcc0
    cpu.esp -= 4;
    sub_4dbcc0(app, cpu);
    if (cpu.terminate) return;
    // 004bed39  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bed3c  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bed3f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bed42  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bed45  e896feffff             -call 0x4bebe0
    cpu.esp -= 4;
    sub_4bebe0(app, cpu);
    if (cpu.terminate) return;
    // 004bed4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bed4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bed4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bed4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
