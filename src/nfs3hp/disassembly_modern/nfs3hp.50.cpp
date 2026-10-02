#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip  */
void Application::sub_5177ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x005177ac;
    // 005177aa  90                     -nop 
    ;
    // 005177ab  90                     -nop 
    ;
L_entry_0x005177ac:
    // 005177ac  e8dbffffff             -call 0x51778c
    cpu.esp -= 4;
    sub_51778c(app, cpu);
    if (cpu.terminate) return;
    // 005177b1  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 005177b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5177b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005177b6  90                     -nop 
    ;
    // 005177b7  90                     -nop 
    ;
    // 005177b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005177b9  e8eeffffff             -call 0x5177ac
    cpu.esp -= 4;
    sub_5177ac(app, cpu);
    if (cpu.terminate) return;
    // 005177be  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 005177c1  e8c6ffffff             -call 0x51778c
    cpu.esp -= 4;
    sub_51778c(app, cpu);
    if (cpu.terminate) return;
    // 005177c6  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 005177c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005177ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5177cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005177cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005177cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005177ce  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005177d0  e8d7ffffff             -call 0x5177ac
    cpu.esp -= 4;
    sub_5177ac(app, cpu);
    if (cpu.terminate) return;
    // 005177d5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005177d7  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005177d9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005177db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005177dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005177dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5177de(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005177de  90                     -nop 
    ;
    // 005177df  90                     -nop 
    ;
    // 005177e0  90                     -nop 
    ;
    // 005177e1  90                     -nop 
    ;
    // 005177e2  90                     -nop 
    ;
    // 005177e3  90                     -nop 
    ;
    // 005177e4  90                     -nop 
    ;
    // 005177e5  90                     -nop 
    ;
    // 005177e6  90                     -nop 
    ;
    // 005177e7  90                     -nop 
    ;
    // 005177e8  90                     -nop 
    ;
    // 005177e9  90                     -nop 
    ;
    // 005177ea  90                     -nop 
    ;
    // 005177eb  90                     -nop 
    ;
    // 005177ec  90                     -nop 
    ;
    // 005177ed  90                     -nop 
    ;
    // 005177ee  90                     -nop 
    ;
    // 005177ef  90                     -nop 
    ;
    // 005177f0  90                     -nop 
    ;
    // 005177f1  90                     -nop 
    ;
    // 005177f2  90                     -nop 
    ;
    // 005177f3  90                     -nop 
    ;
    // 005177f4  90                     -nop 
    ;
    // 005177f5  90                     -nop 
    ;
    // 005177f6  90                     -nop 
    ;
    // 005177f7  90                     -nop 
    ;
    // 005177f8  90                     -nop 
    ;
    // 005177f9  90                     -nop 
    ;
    // 005177fa  90                     -nop 
    ;
    // 005177fb  90                     -nop 
    ;
    // 005177fc  90                     -nop 
    ;
    // 005177fd  90                     -nop 
    ;
    // 005177fe  90                     -nop 
    ;
    // 005177ff  90                     -nop 
    ;
    // 00517800  90                     -nop 
    ;
    // 00517801  90                     -nop 
    ;
    // 00517802  90                     -nop 
    ;
    // 00517803  90                     -nop 
    ;
    // 00517804  90                     -nop 
    ;
    // 00517805  90                     -nop 
    ;
    // 00517806  90                     -nop 
    ;
    // 00517807  90                     -nop 
    ;
    // 00517808  90                     -nop 
    ;
    // 00517809  90                     -nop 
    ;
    // 0051780a  90                     -nop 
    ;
    // 0051780b  90                     -nop 
    ;
    // 0051780c  90                     -nop 
    ;
    // 0051780d  90                     -nop 
    ;
    // 0051780e  90                     -nop 
    ;
    // 0051780f  90                     -nop 
    ;
    // 00517810  90                     -nop 
    ;
    // 00517811  90                     -nop 
    ;
    // 00517812  90                     -nop 
    ;
    // 00517813  90                     -nop 
    ;
    // 00517814  90                     -nop 
    ;
    // 00517815  90                     -nop 
    ;
    // 00517816  90                     -nop 
    ;
    // 00517817  90                     -nop 
    ;
    // 00517818  90                     -nop 
    ;
    // 00517819  90                     -nop 
    ;
    // 0051781a  90                     -nop 
    ;
    // 0051781b  90                     -nop 
    ;
    // 0051781c  90                     -nop 
    ;
    // 0051781d  90                     -nop 
    ;
    // 0051781e  90                     -nop 
    ;
    // 0051781f  90                     -nop 
    ;
    // 00517820  90                     -nop 
    ;
    // 00517821  90                     -nop 
    ;
    // 00517822  90                     -nop 
    ;
    // 00517823  90                     -nop 
    ;
    // 00517824  90                     -nop 
    ;
    // 00517825  90                     -nop 
    ;
    // 00517826  90                     -nop 
    ;
    // 00517827  90                     -nop 
    ;
    // 00517828  90                     -nop 
    ;
    // 00517829  90                     -nop 
    ;
    // 0051782a  90                     -nop 
    ;
    // 0051782b  90                     -nop 
    ;
    // 0051782c  90                     -nop 
    ;
    // 0051782d  90                     -nop 
    ;
    // 0051782e  90                     -nop 
    ;
    // 0051782f  90                     -nop 
    ;
    // 00517830  90                     -nop 
    ;
    // 00517831  90                     -nop 
    ;
    // 00517832  90                     -nop 
    ;
    // 00517833  90                     -nop 
    ;
    // 00517834  90                     -nop 
    ;
    // 00517835  90                     -nop 
    ;
    // 00517836  90                     -nop 
    ;
    // 00517837  90                     -nop 
    ;
    // 00517838  90                     -nop 
    ;
    // 00517839  90                     -nop 
    ;
    // 0051783a  90                     -nop 
    ;
    // 0051783b  90                     -nop 
    ;
    // 0051783c  90                     -nop 
    ;
    // 0051783d  90                     -nop 
    ;
    // 0051783e  90                     -nop 
    ;
    // 0051783f  90                     -nop 
    ;
    // 00517840  90                     -nop 
    ;
    // 00517841  90                     -nop 
    ;
    // 00517842  90                     -nop 
    ;
    // 00517843  90                     -nop 
    ;
    // 00517844  90                     -nop 
    ;
    // 00517845  90                     -nop 
    ;
    // 00517846  90                     -nop 
    ;
    // 00517847  90                     -nop 
    ;
    // 00517848  90                     -nop 
    ;
    // 00517849  90                     -nop 
    ;
    // 0051784a  90                     -nop 
    ;
    // 0051784b  90                     -nop 
    ;
    // 0051784c  90                     -nop 
    ;
    // 0051784d  90                     -nop 
    ;
    // 0051784e  90                     -nop 
    ;
    // 0051784f  90                     -nop 
    ;
    // 00517850  90                     -nop 
    ;
    // 00517851  90                     -nop 
    ;
    // 00517852  90                     -nop 
    ;
    // 00517853  90                     -nop 
    ;
    // 00517854  90                     -nop 
    ;
    // 00517855  90                     -nop 
    ;
    // 00517856  90                     -nop 
    ;
    // 00517857  90                     -nop 
    ;
    // 00517858  90                     -nop 
    ;
    // 00517859  90                     -nop 
    ;
    // 0051785a  90                     -nop 
    ;
    // 0051785b  90                     -nop 
    ;
    // 0051785c  90                     -nop 
    ;
    // 0051785d  90                     -nop 
    ;
    // 0051785e  90                     -nop 
    ;
    // 0051785f  90                     -nop 
    ;
    // 00517860  90                     -nop 
    ;
    // 00517861  90                     -nop 
    ;
    // 00517862  90                     -nop 
    ;
    // 00517863  90                     -nop 
    ;
    // 00517864  90                     -nop 
    ;
    // 00517865  90                     -nop 
    ;
    // 00517866  90                     -nop 
    ;
    // 00517867  90                     -nop 
    ;
    // 00517868  90                     -nop 
    ;
    // 00517869  90                     -nop 
    ;
    // 0051786a  90                     -nop 
    ;
    // 0051786b  90                     -nop 
    ;
    // 0051786c  90                     -nop 
    ;
    // 0051786d  90                     -nop 
    ;
    // 0051786e  90                     -nop 
    ;
    // 0051786f  90                     -nop 
    ;
    // 00517870  90                     -nop 
    ;
    // 00517871  90                     -nop 
    ;
    // 00517872  90                     -nop 
    ;
    // 00517873  90                     -nop 
    ;
    // 00517874  90                     -nop 
    ;
    // 00517875  90                     -nop 
    ;
    // 00517876  90                     -nop 
    ;
    // 00517877  90                     -nop 
    ;
    // 00517878  90                     -nop 
    ;
    // 00517879  90                     -nop 
    ;
    // 0051787a  90                     -nop 
    ;
    // 0051787b  90                     -nop 
    ;
    // 0051787c  90                     -nop 
    ;
    // 0051787d  90                     -nop 
    ;
    // 0051787e  90                     -nop 
    ;
    // 0051787f  90                     -nop 
    ;
    // 00517880  90                     -nop 
    ;
    // 00517881  90                     -nop 
    ;
    // 00517882  90                     -nop 
    ;
    // 00517883  90                     -nop 
    ;
    // 00517884  90                     -nop 
    ;
    // 00517885  90                     -nop 
    ;
    // 00517886  90                     -nop 
    ;
    // 00517887  90                     -nop 
    ;
    // 00517888  90                     -nop 
    ;
    // 00517889  90                     -nop 
    ;
    // 0051788a  90                     -nop 
    ;
    // 0051788b  90                     -nop 
    ;
    // 0051788c  90                     -nop 
    ;
    // 0051788d  90                     -nop 
    ;
    // 0051788e  90                     -nop 
    ;
    // 0051788f  90                     -nop 
    ;
    // 00517890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00517891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517892  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00517894  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517895  ff1538f99e00           -call dword ptr [0x9ef938]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418488) /* 0x9ef938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051789b  ff1554f99e00           -call dword ptr [0x9ef954]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418516) /* 0x9ef954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005178a1  a32082a100             -mov dword ptr [0xa18220], eax
    app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */) = cpu.eax;
    // 005178a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005178a8  7503                   -jne 0x5178ad
    if (!cpu.flags.zf)
    {
        goto L_0x005178ad;
    }
    // 005178aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005178ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005178ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005178ad:
    // 005178ad  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005178af  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 005178b2  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005178b5  891df4af5600           -mov dword ptr [0x56aff4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5681140) /* 0x56aff4 */) = cpu.ebx;
    // 005178bb  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 005178be  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005178c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005178c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005178c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_517890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00517890;
    // 005177de  90                     -nop 
    ;
    // 005177df  90                     -nop 
    ;
    // 005177e0  90                     -nop 
    ;
    // 005177e1  90                     -nop 
    ;
    // 005177e2  90                     -nop 
    ;
    // 005177e3  90                     -nop 
    ;
    // 005177e4  90                     -nop 
    ;
    // 005177e5  90                     -nop 
    ;
    // 005177e6  90                     -nop 
    ;
    // 005177e7  90                     -nop 
    ;
    // 005177e8  90                     -nop 
    ;
    // 005177e9  90                     -nop 
    ;
    // 005177ea  90                     -nop 
    ;
    // 005177eb  90                     -nop 
    ;
    // 005177ec  90                     -nop 
    ;
    // 005177ed  90                     -nop 
    ;
    // 005177ee  90                     -nop 
    ;
    // 005177ef  90                     -nop 
    ;
    // 005177f0  90                     -nop 
    ;
    // 005177f1  90                     -nop 
    ;
    // 005177f2  90                     -nop 
    ;
    // 005177f3  90                     -nop 
    ;
    // 005177f4  90                     -nop 
    ;
    // 005177f5  90                     -nop 
    ;
    // 005177f6  90                     -nop 
    ;
    // 005177f7  90                     -nop 
    ;
    // 005177f8  90                     -nop 
    ;
    // 005177f9  90                     -nop 
    ;
    // 005177fa  90                     -nop 
    ;
    // 005177fb  90                     -nop 
    ;
    // 005177fc  90                     -nop 
    ;
    // 005177fd  90                     -nop 
    ;
    // 005177fe  90                     -nop 
    ;
    // 005177ff  90                     -nop 
    ;
    // 00517800  90                     -nop 
    ;
    // 00517801  90                     -nop 
    ;
    // 00517802  90                     -nop 
    ;
    // 00517803  90                     -nop 
    ;
    // 00517804  90                     -nop 
    ;
    // 00517805  90                     -nop 
    ;
    // 00517806  90                     -nop 
    ;
    // 00517807  90                     -nop 
    ;
    // 00517808  90                     -nop 
    ;
    // 00517809  90                     -nop 
    ;
    // 0051780a  90                     -nop 
    ;
    // 0051780b  90                     -nop 
    ;
    // 0051780c  90                     -nop 
    ;
    // 0051780d  90                     -nop 
    ;
    // 0051780e  90                     -nop 
    ;
    // 0051780f  90                     -nop 
    ;
    // 00517810  90                     -nop 
    ;
    // 00517811  90                     -nop 
    ;
    // 00517812  90                     -nop 
    ;
    // 00517813  90                     -nop 
    ;
    // 00517814  90                     -nop 
    ;
    // 00517815  90                     -nop 
    ;
    // 00517816  90                     -nop 
    ;
    // 00517817  90                     -nop 
    ;
    // 00517818  90                     -nop 
    ;
    // 00517819  90                     -nop 
    ;
    // 0051781a  90                     -nop 
    ;
    // 0051781b  90                     -nop 
    ;
    // 0051781c  90                     -nop 
    ;
    // 0051781d  90                     -nop 
    ;
    // 0051781e  90                     -nop 
    ;
    // 0051781f  90                     -nop 
    ;
    // 00517820  90                     -nop 
    ;
    // 00517821  90                     -nop 
    ;
    // 00517822  90                     -nop 
    ;
    // 00517823  90                     -nop 
    ;
    // 00517824  90                     -nop 
    ;
    // 00517825  90                     -nop 
    ;
    // 00517826  90                     -nop 
    ;
    // 00517827  90                     -nop 
    ;
    // 00517828  90                     -nop 
    ;
    // 00517829  90                     -nop 
    ;
    // 0051782a  90                     -nop 
    ;
    // 0051782b  90                     -nop 
    ;
    // 0051782c  90                     -nop 
    ;
    // 0051782d  90                     -nop 
    ;
    // 0051782e  90                     -nop 
    ;
    // 0051782f  90                     -nop 
    ;
    // 00517830  90                     -nop 
    ;
    // 00517831  90                     -nop 
    ;
    // 00517832  90                     -nop 
    ;
    // 00517833  90                     -nop 
    ;
    // 00517834  90                     -nop 
    ;
    // 00517835  90                     -nop 
    ;
    // 00517836  90                     -nop 
    ;
    // 00517837  90                     -nop 
    ;
    // 00517838  90                     -nop 
    ;
    // 00517839  90                     -nop 
    ;
    // 0051783a  90                     -nop 
    ;
    // 0051783b  90                     -nop 
    ;
    // 0051783c  90                     -nop 
    ;
    // 0051783d  90                     -nop 
    ;
    // 0051783e  90                     -nop 
    ;
    // 0051783f  90                     -nop 
    ;
    // 00517840  90                     -nop 
    ;
    // 00517841  90                     -nop 
    ;
    // 00517842  90                     -nop 
    ;
    // 00517843  90                     -nop 
    ;
    // 00517844  90                     -nop 
    ;
    // 00517845  90                     -nop 
    ;
    // 00517846  90                     -nop 
    ;
    // 00517847  90                     -nop 
    ;
    // 00517848  90                     -nop 
    ;
    // 00517849  90                     -nop 
    ;
    // 0051784a  90                     -nop 
    ;
    // 0051784b  90                     -nop 
    ;
    // 0051784c  90                     -nop 
    ;
    // 0051784d  90                     -nop 
    ;
    // 0051784e  90                     -nop 
    ;
    // 0051784f  90                     -nop 
    ;
    // 00517850  90                     -nop 
    ;
    // 00517851  90                     -nop 
    ;
    // 00517852  90                     -nop 
    ;
    // 00517853  90                     -nop 
    ;
    // 00517854  90                     -nop 
    ;
    // 00517855  90                     -nop 
    ;
    // 00517856  90                     -nop 
    ;
    // 00517857  90                     -nop 
    ;
    // 00517858  90                     -nop 
    ;
    // 00517859  90                     -nop 
    ;
    // 0051785a  90                     -nop 
    ;
    // 0051785b  90                     -nop 
    ;
    // 0051785c  90                     -nop 
    ;
    // 0051785d  90                     -nop 
    ;
    // 0051785e  90                     -nop 
    ;
    // 0051785f  90                     -nop 
    ;
    // 00517860  90                     -nop 
    ;
    // 00517861  90                     -nop 
    ;
    // 00517862  90                     -nop 
    ;
    // 00517863  90                     -nop 
    ;
    // 00517864  90                     -nop 
    ;
    // 00517865  90                     -nop 
    ;
    // 00517866  90                     -nop 
    ;
    // 00517867  90                     -nop 
    ;
    // 00517868  90                     -nop 
    ;
    // 00517869  90                     -nop 
    ;
    // 0051786a  90                     -nop 
    ;
    // 0051786b  90                     -nop 
    ;
    // 0051786c  90                     -nop 
    ;
    // 0051786d  90                     -nop 
    ;
    // 0051786e  90                     -nop 
    ;
    // 0051786f  90                     -nop 
    ;
    // 00517870  90                     -nop 
    ;
    // 00517871  90                     -nop 
    ;
    // 00517872  90                     -nop 
    ;
    // 00517873  90                     -nop 
    ;
    // 00517874  90                     -nop 
    ;
    // 00517875  90                     -nop 
    ;
    // 00517876  90                     -nop 
    ;
    // 00517877  90                     -nop 
    ;
    // 00517878  90                     -nop 
    ;
    // 00517879  90                     -nop 
    ;
    // 0051787a  90                     -nop 
    ;
    // 0051787b  90                     -nop 
    ;
    // 0051787c  90                     -nop 
    ;
    // 0051787d  90                     -nop 
    ;
    // 0051787e  90                     -nop 
    ;
    // 0051787f  90                     -nop 
    ;
    // 00517880  90                     -nop 
    ;
    // 00517881  90                     -nop 
    ;
    // 00517882  90                     -nop 
    ;
    // 00517883  90                     -nop 
    ;
    // 00517884  90                     -nop 
    ;
    // 00517885  90                     -nop 
    ;
    // 00517886  90                     -nop 
    ;
    // 00517887  90                     -nop 
    ;
    // 00517888  90                     -nop 
    ;
    // 00517889  90                     -nop 
    ;
    // 0051788a  90                     -nop 
    ;
    // 0051788b  90                     -nop 
    ;
    // 0051788c  90                     -nop 
    ;
    // 0051788d  90                     -nop 
    ;
    // 0051788e  90                     -nop 
    ;
    // 0051788f  90                     -nop 
    ;
L_entry_0x00517890:
    // 00517890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00517891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517892  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00517894  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517895  ff1538f99e00           -call dword ptr [0x9ef938]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418488) /* 0x9ef938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051789b  ff1554f99e00           -call dword ptr [0x9ef954]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418516) /* 0x9ef954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005178a1  a32082a100             -mov dword ptr [0xa18220], eax
    app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */) = cpu.eax;
    // 005178a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005178a8  7503                   -jne 0x5178ad
    if (!cpu.flags.zf)
    {
        goto L_0x005178ad;
    }
    // 005178aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005178ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005178ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005178ad:
    // 005178ad  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005178af  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 005178b2  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005178b5  891df4af5600           -mov dword ptr [0x56aff4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5681140) /* 0x56aff4 */) = cpu.ebx;
    // 005178bb  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 005178be  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005178c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005178c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005178c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_5178d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005178d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005178d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005178d2  833df4af560000         +cmp dword ptr [0x56aff4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5681140) /* 0x56aff4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005178d9  7514                   -jne 0x5178ef
    if (!cpu.flags.zf)
    {
        goto L_0x005178ef;
    }
    // 005178db  833d2082a10000         +cmp dword ptr [0xa18220], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005178e2  752c                   -jne 0x517910
    if (!cpu.flags.zf)
    {
        goto L_0x00517910;
    }
L_0x005178e4:
    // 005178e4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005178e6  ff1538f99e00           -call dword ptr [0x9ef938]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418488) /* 0x9ef938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005178ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005178ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005178ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005178ef:
    // 005178ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005178f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005178f1  8b1d2082a100           -mov ebx, dword ptr [0xa18220]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */);
    // 005178f7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005178f8  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 005178fa  ff155cf99e00           -call dword ptr [0x9ef95c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418524) /* 0x9ef95c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00517900  89352082a100           -mov dword ptr [0xa18220], esi
    app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */) = cpu.esi;
    // 00517906  8935f4af5600           -mov dword ptr [0x56aff4], esi
    app->getMemory<x86::reg32>(x86::reg32(5681140) /* 0x56aff4 */) = cpu.esi;
    // 0051790c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051790d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051790e  ebd4                   -jmp 0x5178e4
    goto L_0x005178e4;
L_0x00517910:
    // 00517910  e8dbcf0000             -call 0x5248f0
    cpu.esp -= 4;
    sub_5248f0(app, cpu);
    if (cpu.terminate) return;
    // 00517915  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00517917  ff1538f99e00           -call dword ptr [0x9ef938]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418488) /* 0x9ef938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051791d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051791e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051791f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_517920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00517921  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517922  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00517923  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00517925  833d2082a10000         +cmp dword ptr [0xa18220], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051792c  7533                   -jne 0x517961
    if (!cpu.flags.zf)
    {
        goto L_0x00517961;
    }
L_0x0051792e:
    // 0051792e  833d0c3d9f0000         +cmp dword ptr [0x9f3d0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435852) /* 0x9f3d0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517935  740a                   -je 0x517941
    if (cpu.flags.zf)
    {
        goto L_0x00517941;
    }
    // 00517937  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 0051793c  e85f59fdff             -call 0x4ed2a0
    cpu.esp -= 4;
    sub_4ed2a0(app, cpu);
    if (cpu.terminate) return;
L_0x00517941:
    // 00517941  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00517943  7413                   -je 0x517958
    if (cpu.flags.zf)
    {
        goto L_0x00517958;
    }
    // 00517945  8a631e                 -mov ah, byte ptr [ebx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00517948  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0051794a  7405                   -je 0x517951
    if (cpu.flags.zf)
    {
        goto L_0x00517951;
    }
    // 0051794c  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051794f  7517                   -jne 0x517968
    if (!cpu.flags.zf)
    {
        goto L_0x00517968;
    }
L_0x00517951:
    // 00517951  8b7334                 -mov esi, dword ptr [ebx + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 00517954  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00517956  751f                   -jne 0x517977
    if (!cpu.flags.zf)
    {
        goto L_0x00517977;
    }
L_0x00517958:
    // 00517958  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051795d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051795e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051795f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517960  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00517961:
    // 00517961  e86affffff             -call 0x5178d0
    cpu.esp -= 4;
    sub_5178d0(app, cpu);
    if (cpu.terminate) return;
    // 00517966  ebc6                   -jmp 0x51792e
    goto L_0x0051792e;
L_0x00517968:
    // 00517968  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051796a  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0051796c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051796e  e81dffffff             -call 0x517890
    cpu.esp -= 4;
    sub_517890(app, cpu);
    if (cpu.terminate) return;
    // 00517973  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517974  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517975  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517976  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00517977:
    // 00517977  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 0051797c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051797e  e86d57fdff             -call 0x4ed0f0
    cpu.esp -= 4;
    sub_4ed0f0(app, cpu);
    if (cpu.terminate) return;
    // 00517983  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517984  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517985  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517986  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_517990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517990  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517991  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517992  e839ffffff             -call 0x5178d0
    cpu.esp -= 4;
    sub_5178d0(app, cpu);
    if (cpu.terminate) return;
    // 00517997  ff1540f99e00           -call dword ptr [0x9ef940]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418496) /* 0x9ef940 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051799d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051799e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051799f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_5179d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 005179d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005179d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005179d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005179d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005179d4  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 005179d7  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 005179db  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005179dd  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 005179df  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005179e4  740c                   -je 0x5179f2
    if (cpu.flags.zf)
    {
        goto L_0x005179f2;
    }
    // 005179e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005179e8  7545                   -jne 0x517a2f
    if (!cpu.flags.zf)
    {
        goto L_0x00517a2f;
    }
L_0x005179ea:
    // 005179ea  83c418                 +add esp, 0x18
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
    // 005179ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005179ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005179ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005179f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005179f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005179f2:
    // 005179f2  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005179f6  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005179fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005179fb  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005179ff  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00517a03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00517a04  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00517a08  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00517a0a  e8115efdff             -call 0x4ed820
    cpu.esp -= 4;
    sub_4ed820(app, cpu);
    if (cpu.terminate) return;
    // 00517a0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00517a10  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00517a14  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00517a18  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00517a19  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00517a1d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00517a21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00517a22  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00517a26  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517a28  e85311ffff             -call 0x508b80
    cpu.esp -= 4;
    sub_508b80(app, cpu);
    if (cpu.terminate) return;
    // 00517a2d  ebbb                   -jmp 0x5179ea
    goto L_0x005179ea;
L_0x00517a2f:
    // 00517a2f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00517a30  ff1538f99e00           -call dword ptr [0x9ef938]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418488) /* 0x9ef938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00517a36  ff1554f99e00           -call dword ptr [0x9ef954]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418516) /* 0x9ef954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00517a3c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00517a3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00517a40  7438                   -je 0x517a7a
    if (cpu.flags.zf)
    {
        goto L_0x00517a7a;
    }
    // 00517a42  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00517a44  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00517a47  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00517a4a  895328                 -mov dword ptr [ebx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00517a4d  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00517a50  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00517a53  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00517a56  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00517a59  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00517a5c  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00517a5f  83f809                 +cmp eax, 9
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
    // 00517a62  0f87b1000000           -ja 0x517b19
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00517b19;
    }
    // 00517a68  ff2485a0795100         -jmp dword ptr [eax*4 + 0x5179a0]
    cpu.ip = app->getMemory<x86::reg32>(5339552 + cpu.eax * 4); goto dynamic_jump;
  case 0x00517a6f:
    // 00517a6f  c6431c08               -mov byte ptr [ebx + 0x1c], 8
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
L_0x00517a73:
    // 00517a73  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517a74  ff155cf99e00           -call dword ptr [0x9ef95c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418524) /* 0x9ef95c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00517a7a:
    // 00517a7a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00517a7c  ff1538f99e00           -call dword ptr [0x9ef938]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418488) /* 0x9ef938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00517a82  0fb66e1c               -movzx ebp, byte ptr [esi + 0x1c]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */));
    // 00517a86  83fd0f                 +cmp ebp, 0xf
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517a89  7505                   -jne 0x517a90
    if (!cpu.flags.zf)
    {
        goto L_0x00517a90;
    }
    // 00517a8b  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x00517a90:
    // 00517a90  c706444e4957           -mov dword ptr [esi], 0x57494e44
    app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 00517a96  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00517a9d  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00517aa4  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00517aa7  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00517aaa  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00517aad  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00517ab0  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00517ab4  88461e                 -mov byte ptr [esi + 0x1e], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */) = cpu.al;
    // 00517ab7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00517ab9  8a461c                 -mov al, byte ptr [esi + 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00517abc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00517abe  e80d1effff             -call 0x5098d0
    cpu.esp -= 4;
    sub_5098d0(app, cpu);
    if (cpu.terminate) return;
    // 00517ac3  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00517ac6  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00517ac9  88461d                 -mov byte ptr [esi + 0x1d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 00517acc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00517ace  897e34                 -mov dword ptr [esi + 0x34], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.edi;
    // 00517ad1  e85a1fffff             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 00517ad6  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00517adb  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00517add  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00517ae0  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00517ae3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00517ae5  e8461fffff             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 00517aea  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00517aed  83c418                 +add esp, 0x18
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
    // 00517af0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517af1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517af2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517af3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517af4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00517af5:
    // 00517af5  c6461c0f               -mov byte ptr [esi + 0x1c], 0xf
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = 15 /*0xf*/;
    // 00517af9  e975ffffff             -jmp 0x517a73
    goto L_0x00517a73;
  case 0x00517afe:
    // 00517afe  c6431c10               -mov byte ptr [ebx + 0x1c], 0x10
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 16 /*0x10*/;
    // 00517b02  e96cffffff             -jmp 0x517a73
    goto L_0x00517a73;
  case 0x00517b07:
    // 00517b07  c6431c18               -mov byte ptr [ebx + 0x1c], 0x18
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 24 /*0x18*/;
    // 00517b0b  e963ffffff             -jmp 0x517a73
    goto L_0x00517a73;
  case 0x00517b10:
    // 00517b10  c6431c20               -mov byte ptr [ebx + 0x1c], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 32 /*0x20*/;
    // 00517b14  e95affffff             -jmp 0x517a73
    goto L_0x00517a73;
  case 0x00517b19:
L_0x00517b19:
    // 00517b19  c6461c10               -mov byte ptr [esi + 0x1c], 0x10
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = 16 /*0x10*/;
    // 00517b1d  e951ffffff             -jmp 0x517a73
    goto L_0x00517a73;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_517b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517b30  833d308f560000         +cmp dword ptr [0x568f30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5672752) /* 0x568f30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517b37  7401                   -je 0x517b3a
    if (cpu.flags.zf)
    {
        goto L_0x00517b3a;
    }
    // 00517b39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00517b3a:
    // 00517b3a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517b3b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517b3c  bab8000000             -mov edx, 0xb8
    cpu.edx = 184 /*0xb8*/;
    // 00517b41  b8f4715600             -mov eax, 0x5671f4
    cpu.eax = 5665268 /*0x5671f4*/;
    // 00517b46  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00517b4b  e8bc8bfcff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 00517b50  b8707b5100             -mov eax, 0x517b70
    cpu.eax = 5340016 /*0x517b70*/;
    // 00517b55  890d308f5600           -mov dword ptr [0x568f30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5672752) /* 0x568f30 */) = cpu.ecx;
    // 00517b5b  e818affdff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 00517b60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517b61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517b62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_517b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517b70  833d308f560000         +cmp dword ptr [0x568f30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5672752) /* 0x568f30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517b77  7501                   -jne 0x517b7a
    if (!cpu.flags.zf)
    {
        goto L_0x00517b7a;
    }
    // 00517b79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00517b7a:
    // 00517b7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517b7b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517b7c  e85f46ffff             -call 0x50c1e0
    cpu.esp -= 4;
    sub_50c1e0(app, cpu);
    if (cpu.terminate) return;
    // 00517b81  bab8000000             -mov edx, 0xb8
    cpu.edx = 184 /*0xb8*/;
    // 00517b86  b8f4715600             -mov eax, 0x5671f4
    cpu.eax = 5665268 /*0x5671f4*/;
    // 00517b8b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00517b8d  e87a8bfcff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 00517b92  890d308f5600           -mov dword ptr [0x568f30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5672752) /* 0x568f30 */) = cpu.ecx;
    // 00517b98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517b99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517b9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_517ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517ba0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00517ba1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517ba2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517ba3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00517ba5  2eff1548475300         -call dword ptr cs:[0x534748]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457736) /* 0x534748 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00517bac  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00517bae  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00517bb0  2eff1548475300         -call dword ptr cs:[0x534748]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457736) /* 0x534748 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00517bb7  83fb07                 +cmp ebx, 7
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517bba  750e                   -jne 0x517bca
    if (!cpu.flags.zf)
    {
        goto L_0x00517bca;
    }
    // 00517bbc  3d010d0000             +cmp eax, 0xd01
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3329 /*0xd01*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517bc1  7c07                   -jl 0x517bca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00517bca;
    }
    // 00517bc3  3d040d0000             +cmp eax, 0xd04
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3332 /*0xd04*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517bc8  7e06                   -jle 0x517bd0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00517bd0;
    }
L_0x00517bca:
    // 00517bca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00517bcc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517bcd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517bce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517bcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00517bd0:
    // 00517bd0  ba348f5600             -mov edx, 0x568f34
    cpu.edx = 5672756 /*0x568f34*/;
    // 00517bd5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00517bda  891598125600           -mov dword ptr [0x561298], edx
    app->getMemory<x86::reg32>(x86::reg32(5640856) /* 0x561298 */) = cpu.edx;
    // 00517be0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517be1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517be2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517be3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_517bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517bf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00517bf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517bf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517bf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00517bf4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00517bf5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00517bf6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00517bf8  68b48f5600             -push 0x568fb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5672884 /*0x568fb4*/;
    cpu.esp -= 4;
    // 00517bfd  e8be7afcff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 00517c02  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00517c05  68b48f5600             -push 0x568fb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5672884 /*0x568fb4*/;
    cpu.esp -= 4;
    // 00517c0a  e8b17afcff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 00517c0f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00517c12  6814065500             -push 0x550614
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572116 /*0x550614*/;
    cpu.esp -= 4;
    // 00517c17  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00517c1a  e8a17afcff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 00517c1f  8b1c95c0f59e00         -mov ebx, dword ptr [edx*4 + 0x9ef5c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.edx * 4);
    // 00517c26  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00517c28  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00517c2b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00517c2e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00517c30  0f84b9000000           -je 0x517cef
    if (cpu.flags.zf)
    {
        goto L_0x00517cef;
    }
L_0x00517c36:
    // 00517c36  8d7310                 -lea esi, [ebx + 0x10]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00517c39  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517c3b  e8a099fcff             -call 0x4e15e0
    cpu.esp -= 4;
    sub_4e15e0(app, cpu);
    if (cpu.terminate) return;
    // 00517c40  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00517c42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00517c44  7505                   -jne 0x517c4b
    if (!cpu.flags.zf)
    {
        goto L_0x00517c4b;
    }
    // 00517c46  b958065500             -mov ecx, 0x550658
    cpu.ecx = 5572184 /*0x550658*/;
L_0x00517c4b:
    // 00517c4b  8a6303                 -mov ah, byte ptr [ebx + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00517c4e  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 00517c51  0f84bb000000           -je 0x517d12
    if (cpu.flags.zf)
    {
        goto L_0x00517d12;
    }
    // 00517c57  6810065500             -push 0x550610
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572112 /*0x550610*/;
    cpu.esp -= 4;
    // 00517c5c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00517c5e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00517c60  668b5302               -mov dx, word ptr [ebx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00517c64  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517c65  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00517c68  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00517c6a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517c6b  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00517c6e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00517c6f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00517c70  685c065500             -push 0x55065c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572188 /*0x55065c*/;
    cpu.esp -= 4;
    // 00517c75  68f78f5600             -push 0x568ff7
    app->getMemory<x86::reg32>(cpu.esp-4) = 5672951 /*0x568ff7*/;
    cpu.esp -= 4;
    // 00517c7a  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00517c7c:
    // 00517c7c  e83f7afcff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 00517c81  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00517c84  8a6303                 -mov ah, byte ptr [ebx + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00517c87  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00517c8a  744b                   -je 0x517cd7
    if (cpu.flags.zf)
    {
        goto L_0x00517cd7;
    }
    // 00517c8c  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 00517c8f  7546                   -jne 0x517cd7
    if (!cpu.flags.zf)
    {
        goto L_0x00517cd7;
    }
    // 00517c91  037304                 -add esi, dword ptr [ebx + 4]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 00517c94  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00517c99  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00517c9c  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00517ca0  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00517ca2  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00517ca9  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00517cab  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00517cb0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00517cb2  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00517cb5  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00517cb9  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00517cbb  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00517cc2  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00517cc4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00517cc6  740f                   -je 0x517cd7
    if (cpu.flags.zf)
    {
        goto L_0x00517cd7;
    }
    // 00517cc8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00517cc9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517cca  6868065500             -push 0x550668
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572200 /*0x550668*/;
    cpu.esp -= 4;
    // 00517ccf  e8ec79fcff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 00517cd4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00517cd7:
    // 00517cd7  6870065500             -push 0x550670
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572208 /*0x550670*/;
    cpu.esp -= 4;
    // 00517cdc  e8df79fcff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 00517ce1  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00517ce4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00517ce7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00517ce9  0f8547ffffff           -jne 0x517c36
    if (!cpu.flags.zf)
    {
        goto L_0x00517c36;
    }
L_0x00517cef:
    // 00517cef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00517cf0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00517cf1  6874065500             -push 0x550674
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572212 /*0x550674*/;
    cpu.esp -= 4;
    // 00517cf6  e8c579fcff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 00517cfb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00517cfe  68b48f5600             -push 0x568fb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5672884 /*0x568fb4*/;
    cpu.esp -= 4;
    // 00517d03  e8b879fcff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 00517d08  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00517d0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517d0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517d0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517d0e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517d0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517d10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517d11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00517d12:
    // 00517d12  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00517d15  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00517d17  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00517d19  7410                   -je 0x517d2b
    if (cpu.flags.zf)
    {
        goto L_0x00517d2b;
    }
    // 00517d1b  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 00517d1e  750b                   -jne 0x517d2b
    if (!cpu.flags.zf)
    {
        goto L_0x00517d2b;
    }
    // 00517d20  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00517d22  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517d24  e857cafdff             -call 0x4f4780
    cpu.esp -= 4;
    sub_4f4780(app, cpu);
    if (cpu.terminate) return;
    // 00517d29  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00517d2b:
    // 00517d2b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00517d2d  e88ecafdff             -call 0x4f47c0
    cpu.esp -= 4;
    sub_4f47c0(app, cpu);
    if (cpu.terminate) return;
    // 00517d32  8b2c8520905600         -mov ebp, dword ptr [eax*4 + 0x569020]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5672992) /* 0x569020 */ + cpu.eax * 4);
    // 00517d39  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00517d3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00517d3c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517d3d  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00517d41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00517d42  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00517d45  29d8                   +sub eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00517d47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00517d48  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00517d4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00517d4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00517d4d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517d4e  68f78f5600             -push 0x568ff7
    app->getMemory<x86::reg32>(cpu.esp-4) = 5672951 /*0x568ff7*/;
    cpu.esp -= 4;
    // 00517d53  e924ffffff             -jmp 0x517c7c
    goto L_0x00517c7c;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_517d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517d60  a1f4435600             -mov eax, dword ptr [0x5643f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 00517d65  e986feffff             -jmp 0x517bf0
    return sub_517bf0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_517d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517d70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00517d71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517d72  8a2590435600           -mov ah, byte ptr [0x564390]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */);
    // 00517d78  8b1d8c435600           -mov ebx, dword ptr [0x56438c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 00517d7e  80f401                 -xor ah, 1
    cpu.ah ^= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00517d81  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00517d87  882590435600           -mov byte ptr [0x564390], ah
    app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */) = cpu.ah;
    // 00517d8d  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00517d92  e8390cffff             -call 0x5089d0
    cpu.esp -= 4;
    sub_5089d0(app, cpu);
    if (cpu.terminate) return;
    // 00517d97  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517d98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517d99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_517da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517da0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517da1  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00517da4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00517da6  e825c9fdff             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 00517dab  e8702ffdff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00517db0  b898065500             -mov eax, 0x550698
    cpu.eax = 5572248 /*0x550698*/;
    // 00517db5  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00517dba  e8a133fdff             -call 0x4eb160
    cpu.esp -= 4;
    sub_4eb160(app, cpu);
    if (cpu.terminate) return;
    // 00517dbf  b8a4065500             -mov eax, 0x5506a4
    cpu.eax = 5572260 /*0x5506a4*/;
    // 00517dc4  e867ce0000             -call 0x524c30
    cpu.esp -= 4;
    sub_524c30(app, cpu);
    if (cpu.terminate) return;
    // 00517dc9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00517dcb  e830c9fdff             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
    // 00517dd0  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00517dd3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517dd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_517de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517de0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517de1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00517de6  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00517deb  891510485600           -mov dword ptr [0x564810], edx
    app->getMemory<x86::reg32>(x86::reg32(5654544) /* 0x564810 */) = cpu.edx;
    // 00517df1  bad04d5200             -mov edx, 0x524dd0
    cpu.edx = 5393872 /*0x524dd0*/;
    // 00517df6  e8d947ffff             -call 0x50c5d4
    cpu.esp -= 4;
    sub_50c5d4(app, cpu);
    if (cpu.terminate) return;
    // 00517dfb  bae04d5200             -mov edx, 0x524de0
    cpu.edx = 5393888 /*0x524de0*/;
    // 00517e00  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00517e05  e8ca47ffff             -call 0x50c5d4
    cpu.esp -= 4;
    sub_50c5d4(app, cpu);
    if (cpu.terminate) return;
    // 00517e0a  ba904d5200             -mov edx, 0x524d90
    cpu.edx = 5393808 /*0x524d90*/;
    // 00517e0f  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00517e14  e8bb47ffff             -call 0x50c5d4
    cpu.esp -= 4;
    sub_50c5d4(app, cpu);
    if (cpu.terminate) return;
    // 00517e19  bab04b5200             -mov edx, 0x524bb0
    cpu.edx = 5393328 /*0x524bb0*/;
    // 00517e1e  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 00517e23  e8ac47ffff             -call 0x50c5d4
    cpu.esp -= 4;
    sub_50c5d4(app, cpu);
    if (cpu.terminate) return;
    // 00517e28  baa07d5100             -mov edx, 0x517da0
    cpu.edx = 5340576 /*0x517da0*/;
    // 00517e2d  b816000000             -mov eax, 0x16
    cpu.eax = 22 /*0x16*/;
    // 00517e32  e89d47ffff             -call 0x50c5d4
    cpu.esp -= 4;
    sub_50c5d4(app, cpu);
    if (cpu.terminate) return;
    // 00517e37  ba707d5100             -mov edx, 0x517d70
    cpu.edx = 5340528 /*0x517d70*/;
    // 00517e3c  b817000000             -mov eax, 0x17
    cpu.eax = 23 /*0x17*/;
    // 00517e41  e88e47ffff             -call 0x50c5d4
    cpu.esp -= 4;
    sub_50c5d4(app, cpu);
    if (cpu.terminate) return;
    // 00517e46  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517e47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_517e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517e50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00517e51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517e52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517e53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00517e55  e87697fcff             -call 0x4e15d0
    cpu.esp -= 4;
    sub_4e15d0(app, cpu);
    if (cpu.terminate) return;
    // 00517e5a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00517e5c  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517e5f  7d06                   -jge 0x517e67
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00517e67;
    }
L_0x00517e61:
    // 00517e61  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00517e63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517e64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517e65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517e66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00517e67:
    // 00517e67  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00517e69  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00517e6e  83e80c                 -sub eax, 0xc
    (cpu.eax) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00517e71  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00517e73  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00517e75  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00517e77  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00517e7e  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00517e80  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00517e85  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00517e87  b8b4065500             -mov eax, 0x5506b4
    cpu.eax = 5572276 /*0x5506b4*/;
    // 00517e8c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00517e8e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00517e90  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00517e92  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00517e99  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00517e9b  39c2                   +cmp edx, eax
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
    // 00517e9d  75c2                   -jne 0x517e61
    if (!cpu.flags.zf)
    {
        goto L_0x00517e61;
    }
    // 00517e9f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00517ea4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00517ea6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517ea7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517ea8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517ea9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_517eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517eb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00517eb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517eb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00517eb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00517eb4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00517eb6  e81597fcff             -call 0x4e15d0
    cpu.esp -= 4;
    sub_4e15d0(app, cpu);
    if (cpu.terminate) return;
    // 00517ebb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00517ebd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00517ebf  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00517ec4  e887ffffff             -call 0x517e50
    cpu.esp -= 4;
    sub_517e50(app, cpu);
    if (cpu.terminate) return;
    // 00517ec9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00517ecb  7507                   -jne 0x517ed4
    if (!cpu.flags.zf)
    {
        goto L_0x00517ed4;
    }
L_0x00517ecd:
    // 00517ecd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517ecf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517ed0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517ed1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517ed2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517ed3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00517ed4:
    // 00517ed4  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00517ed7  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00517edc  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00517edf  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00517ee3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00517ee5  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00517eec  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00517eee  83ea0c                 -sub edx, 0xc
    (cpu.edx) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00517ef1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00517ef3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00517ef5  e886c8fdff             -call 0x4f4780
    cpu.esp -= 4;
    sub_4f4780(app, cpu);
    if (cpu.terminate) return;
    // 00517efa  39c1                   +cmp ecx, eax
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
    // 00517efc  74cf                   -je 0x517ecd
    if (cpu.flags.zf)
    {
        goto L_0x00517ecd;
    }
    // 00517efe  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00517f00  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517f02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_517f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00517f10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517f11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00517f12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00517f13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00517f14  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00517f16  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00517f18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00517f1a  7507                   -jne 0x517f23
    if (!cpu.flags.zf)
    {
        goto L_0x00517f23;
    }
L_0x00517f1c:
    // 00517f1c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517f1e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00517f23:
    // 00517f23  e828ffffff             -call 0x517e50
    cpu.esp -= 4;
    sub_517e50(app, cpu);
    if (cpu.terminate) return;
    // 00517f28  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00517f2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00517f2c  7556                   -jne 0x517f84
    if (!cpu.flags.zf)
    {
        goto L_0x00517f84;
    }
    // 00517f2e  833d3090560000         +cmp dword ptr [0x569030], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5673008) /* 0x569030 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517f35  74e5                   -je 0x517f1c
    if (cpu.flags.zf)
    {
        goto L_0x00517f1c;
    }
    // 00517f37  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517f39  e89296fcff             -call 0x4e15d0
    cpu.esp -= 4;
    sub_4e15d0(app, cpu);
    if (cpu.terminate) return;
    // 00517f3e  833d0c44560000         +cmp dword ptr [0x56440c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517f45  7430                   -je 0x517f77
    if (cpu.flags.zf)
    {
        goto L_0x00517f77;
    }
    // 00517f47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00517f48  babc065500             -mov edx, 0x5506bc
    cpu.edx = 5572284 /*0x5506bc*/;
    // 00517f4d  b9cc065500             -mov ecx, 0x5506cc
    cpu.ecx = 5572300 /*0x5506cc*/;
    // 00517f52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00517f53  bb57000000             -mov ebx, 0x57
    cpu.ebx = 87 /*0x57*/;
    // 00517f58  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00517f5e  68e0065500             -push 0x5506e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572320 /*0x5506e0*/;
    cpu.esp -= 4;
    // 00517f63  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00517f69  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00517f6f  e89c90eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00517f74  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00517f77:
    // 00517f77  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00517f79  75a1                   -jne 0x517f1c
    if (!cpu.flags.zf)
    {
        goto L_0x00517f1c;
    }
    // 00517f7b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00517f7d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517f7f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00517f83  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00517f84:
    // 00517f84  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517f86  e825ffffff             -call 0x517eb0
    cpu.esp -= 4;
    sub_517eb0(app, cpu);
    if (cpu.terminate) return;
    // 00517f8b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00517f8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00517f8f  0f857a000000           -jne 0x51800f
    if (!cpu.flags.zf)
    {
        goto L_0x0051800f;
    }
    // 00517f95  833d0c44560000         +cmp dword ptr [0x56440c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00517f9c  74d9                   -je 0x517f77
    if (cpu.flags.zf)
    {
        goto L_0x00517f77;
    }
    // 00517f9e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517fa0  e82b96fcff             -call 0x4e15d0
    cpu.esp -= 4;
    sub_4e15d0(app, cpu);
    if (cpu.terminate) return;
    // 00517fa5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00517fa7  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00517fa9  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00517fae  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00517fb1  8d53f4                 -lea edx, [ebx - 0xc]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-12) /* -0xc */);
    // 00517fb4  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00517fb8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00517fba  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00517fc1  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00517fc3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00517fc5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00517fc7  e8b4c7fdff             -call 0x4f4780
    cpu.esp -= 4;
    sub_4f4780(app, cpu);
    if (cpu.terminate) return;
    // 00517fcc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00517fcd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00517fce  babc065500             -mov edx, 0x5506bc
    cpu.edx = 5572284 /*0x5506bc*/;
    // 00517fd3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00517fd4  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00517fda  bacc065500             -mov edx, 0x5506cc
    cpu.edx = 5572300 /*0x5506cc*/;
    // 00517fdf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00517fe0  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 00517fe6  ba68000000             -mov edx, 0x68
    cpu.edx = 104 /*0x68*/;
    // 00517feb  6820075500             -push 0x550720
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572384 /*0x550720*/;
    cpu.esp -= 4;
    // 00517ff0  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 00517ff6  e81590eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00517ffb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00517ffe  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00518000  0f8516ffffff           -jne 0x517f1c
    if (!cpu.flags.zf)
    {
        goto L_0x00517f1c;
    }
    // 00518006  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00518008  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051800a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051800b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051800c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051800d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051800e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051800f:
    // 0051800f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00518011  e8ba95fcff             -call 0x4e15d0
    cpu.esp -= 4;
    sub_4e15d0(app, cpu);
    if (cpu.terminate) return;
    // 00518016  8b152c905600           -mov edx, dword ptr [0x56902c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5673004) /* 0x56902c */);
    // 0051801c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051801e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518020  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00518022  e8c9cd0000             -call 0x524df0
    cpu.esp -= 4;
    sub_524df0(app, cpu);
    if (cpu.terminate) return;
    // 00518027  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00518029  0f85edfeffff           -jne 0x517f1c
    if (!cpu.flags.zf)
    {
        goto L_0x00517f1c;
    }
    // 0051802f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00518031  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00518033  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518034  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518035  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518036  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518037  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_518040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518040  c70568785600107f5100   -mov dword ptr [0x567868], 0x517f10
    app->getMemory<x86::reg32>(x86::reg32(5666920) /* 0x567868 */) = 5340944 /*0x517f10*/;
    // 0051804a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_518050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518050  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00518051  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00518052  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518054  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00518056:
    // 00518056  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00518058  e863d00000             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 0051805d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051805f  750c                   -jne 0x51806d
    if (!cpu.flags.zf)
    {
        goto L_0x0051806d;
    }
    // 00518061  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00518063  e898d00000             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 00518068  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00518069  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051806b  ebe9                   -jmp 0x518056
    goto L_0x00518056;
L_0x0051806d:
    // 0051806d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051806f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518070  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518071  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_518080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00518081  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518082  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518083  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00518084  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00518086  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00518088  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0051808a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0051808c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051808e  7438                   -je 0x5180c8
    if (cpu.flags.zf)
    {
        goto L_0x005180c8;
    }
L_0x00518090:
    // 00518090  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00518092  765a                   -jbe 0x5180ee
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005180ee;
    }
    // 00518094  803900                 +cmp byte ptr [ecx], 0
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
    // 00518097  7418                   -je 0x5180b1
    if (cpu.flags.zf)
    {
        goto L_0x005180b1;
    }
    // 00518099  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0051809e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005180a0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005180a2  e859bb0000             -call 0x523c00
    cpu.esp -= 4;
    sub_523c00(app, cpu);
    if (cpu.terminate) return;
    // 005180a7  83f8ff                 +cmp eax, -1
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
    // 005180aa  750c                   -jne 0x5180b8
    if (!cpu.flags.zf)
    {
        goto L_0x005180b8;
    }
    // 005180ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005180ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005180ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005180af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005180b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005180b1:
    // 005180b1  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 005180b6  eb36                   -jmp 0x5180ee
    goto L_0x005180ee;
L_0x005180b8:
    // 005180b8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005180ba  4d                     -dec ebp
    (cpu.ebp)--;
    // 005180bb  e840d00000             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 005180c0  83c602                 +add esi, 2
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
    // 005180c3  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005180c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005180c6  ebc8                   -jmp 0x518090
    goto L_0x00518090;
L_0x005180c8:
    // 005180c8  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x005180cd:
    // 005180cd  803900                 +cmp byte ptr [ecx], 0
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
    // 005180d0  741c                   -je 0x5180ee
    if (cpu.flags.zf)
    {
        goto L_0x005180ee;
    }
    // 005180d2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005180d4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005180d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005180d8  e823bb0000             -call 0x523c00
    cpu.esp -= 4;
    sub_523c00(app, cpu);
    if (cpu.terminate) return;
    // 005180dd  83f8ff                 +cmp eax, -1
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
    // 005180e0  740e                   -je 0x5180f0
    if (cpu.flags.zf)
    {
        goto L_0x005180f0;
    }
    // 005180e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005180e4  e817d00000             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 005180e9  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005180ea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005180ec  ebdf                   -jmp 0x5180cd
    goto L_0x005180cd;
L_0x005180ee:
    // 005180ee  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x005180f0:
    // 005180f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005180f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005180f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005180f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005180f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_518100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518100  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00518101  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518102  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518103  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00518104  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00518107  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00518109  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051810b  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0051810f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00518114  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00518118  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0051811b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051811d  7415                   -je 0x518134
    if (cpu.flags.zf)
    {
        goto L_0x00518134;
    }
    // 0051811f  66833f00               +cmp word ptr [edi], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00518123  750f                   -jne 0x518134
    if (!cpu.flags.zf)
    {
        goto L_0x00518134;
    }
    // 00518125  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00518127  7509                   -jne 0x518132
    if (!cpu.flags.zf)
    {
        goto L_0x00518132;
    }
    // 00518129  e802d00000             -call 0x525130
    cpu.esp -= 4;
    sub_525130(app, cpu);
    if (cpu.terminate) return;
    // 0051812e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00518130  7502                   -jne 0x518134
    if (!cpu.flags.zf)
    {
        goto L_0x00518134;
    }
L_0x00518132:
    // 00518132  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00518134:
    // 00518134  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518139  750b                   -jne 0x518146
    if (!cpu.flags.zf)
    {
        goto L_0x00518146;
    }
    // 0051813b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051813d  e8eecf0000             -call 0x525130
    cpu.esp -= 4;
    sub_525130(app, cpu);
    if (cpu.terminate) return;
    // 00518142  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00518144  7517                   -jne 0x51815d
    if (!cpu.flags.zf)
    {
        goto L_0x0051815d;
    }
L_0x00518146:
    // 00518146  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00518148  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051814a  e851d00000             -call 0x5251a0
    cpu.esp -= 4;
    sub_5251a0(app, cpu);
    if (cpu.terminate) return;
    // 0051814f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00518151  750a                   -jne 0x51815d
    if (!cpu.flags.zf)
    {
        goto L_0x0051815d;
    }
    // 00518153  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00518158  e928010000             -jmp 0x518285
    goto L_0x00518285;
L_0x0051815d:
    // 0051815d  833d58b1a00000         +cmp dword ptr [0xa0b158], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518164  7505                   -jne 0x51816b
    if (!cpu.flags.zf)
    {
        goto L_0x0051816b;
    }
    // 00518166  e835d10000             -call 0x5252a0
    cpu.esp -= 4;
    sub_5252a0(app, cpu);
    if (cpu.terminate) return;
L_0x0051816b:
    // 0051816b  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051816f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00518171  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00518173  e818010000             -call 0x518290
    cpu.esp -= 4;
    sub_518290(app, cpu);
    if (cpu.terminate) return;
    // 00518178  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051817a  740d                   -je 0x518189
    if (cpu.flags.zf)
    {
        goto L_0x00518189;
    }
    // 0051817c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00518181  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00518184  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518185  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518186  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518187  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518188  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00518189:
    // 00518189  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051818b  e870d10000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 00518190  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00518193  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00518197  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0051819a  e861f7fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0051819f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005181a1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005181a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005181a5  7517                   -jne 0x5181be
    if (!cpu.flags.zf)
    {
        goto L_0x005181be;
    }
    // 005181a7  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 005181ac  e8db8dfeff             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 005181b1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005181b6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005181b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005181ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005181bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005181bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005181bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005181be:
    // 005181be  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005181c0  743c                   -je 0x5181fe
    if (cpu.flags.zf)
    {
        goto L_0x005181fe;
    }
    // 005181c2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005181c4  e837d10000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 005181c9  40                     -inc eax
    (cpu.eax)++;
    // 005181ca  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005181ce  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005181d2  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 005181d5  e826f7fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005181da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005181dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005181de  7520                   -jne 0x518200
    if (!cpu.flags.zf)
    {
        goto L_0x00518200;
    }
    // 005181e0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005181e2  e809f8fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 005181e7  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 005181ec  e89b8dfeff             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 005181f1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005181f6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005181f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005181fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005181fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005181fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005181fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005181fe:
    // 005181fe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00518200:
    // 00518200  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00518204  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00518206  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00518208  e8e3c00000             -call 0x5242f0
    cpu.esp -= 4;
    sub_5242f0(app, cpu);
    if (cpu.terminate) return;
    // 0051820d  83f8ff                 +cmp eax, -1
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
    // 00518210  751b                   -jne 0x51822d
    if (!cpu.flags.zf)
    {
        goto L_0x0051822d;
    }
    // 00518212  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00518214  e8d7f7fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00518219  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051821b  e8d0f7fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00518220  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00518225  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00518228  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518229  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051822a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051822b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051822c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051822d:
    // 0051822d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051822f  7431                   -je 0x518262
    if (cpu.flags.zf)
    {
        goto L_0x00518262;
    }
    // 00518231  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00518235  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00518239  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051823b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051823d  e8aec00000             -call 0x5242f0
    cpu.esp -= 4;
    sub_5242f0(app, cpu);
    if (cpu.terminate) return;
    // 00518242  83f8ff                 +cmp eax, -1
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
    // 00518245  751b                   -jne 0x518262
    if (!cpu.flags.zf)
    {
        goto L_0x00518262;
    }
    // 00518247  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00518249  e8a2f7fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0051824e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00518250  e89bf7fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00518255  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0051825a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051825d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051825e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051825f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518260  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518261  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00518262:
    // 00518262  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00518266  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00518268  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051826a  e8790afeff             -call 0x4f8ce8
    cpu.esp -= 4;
    sub_4f8ce8(app, cpu);
    if (cpu.terminate) return;
    // 0051826f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518271  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00518273  e878f7fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00518278  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051827a  7407                   -je 0x518283
    if (cpu.flags.zf)
    {
        goto L_0x00518283;
    }
    // 0051827c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051827e  e86df7fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x00518283:
    // 00518283  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00518285:
    // 00518285  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00518288  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518289  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051828a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051828b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051828c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_518290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518290  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00518291  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518292  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518293  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00518294  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00518297  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00518299  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051829b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051829d  750a                   -jne 0x5182a9
    if (!cpu.flags.zf)
    {
        goto L_0x005182a9;
    }
    // 0051829f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005182a4  e9e4010000             -jmp 0x51848d
    goto L_0x0051848d;
L_0x005182a9:
    // 005182a9  66833800               +cmp word ptr [eax], 0
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
    // 005182ad  750d                   -jne 0x5182bc
    if (!cpu.flags.zf)
    {
        goto L_0x005182bc;
    }
    // 005182af  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005182b4  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 005182b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005182b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005182b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005182ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005182bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005182bc:
    // 005182bc  833d58b1a00000         +cmp dword ptr [0xa0b158], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005182c3  7505                   -jne 0x5182ca
    if (!cpu.flags.zf)
    {
        goto L_0x005182ca;
    }
    // 005182c5  e8d6cf0000             -call 0x5252a0
    cpu.esp -= 4;
    sub_5252a0(app, cpu);
    if (cpu.terminate) return;
L_0x005182ca:
    // 005182ca  8b3558b1a000           -mov esi, dword ptr [0xa0b158]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 005182d0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005182d2  7546                   -jne 0x51831a
    if (!cpu.flags.zf)
    {
        goto L_0x0051831a;
    }
    // 005182d4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005182d6  0f84af010000           -je 0x51848b
    if (cpu.flags.zf)
    {
        goto L_0x0051848b;
    }
    // 005182dc  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 005182e1  e81af6fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005182e6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005182e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005182ea  750d                   -jne 0x5182f9
    if (!cpu.flags.zf)
    {
        goto L_0x005182f9;
    }
    // 005182ec  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005182f1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 005182f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005182f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005182f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005182f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005182f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005182f9:
    // 005182f9  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 005182ff  a358b1a000             -mov dword ptr [0xa0b158], eax
    app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */) = cpu.eax;
    // 00518304  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0051830b  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051830e  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00518310  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 00518315  e9dd000000             -jmp 0x5183f7
    goto L_0x005183f7;
L_0x0051831a:
    // 0051831a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051831c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051831e  e875010000             -call 0x518498
    cpu.esp -= 4;
    sub_518498(app, cpu);
    if (cpu.terminate) return;
    // 00518323  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00518325  0f8460010000           -je 0x51848b
    if (cpu.flags.zf)
    {
        goto L_0x0051848b;
    }
    // 0051832b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051832d  0f8fb9000000           -jg 0x5183ec
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005183ec;
    }
    // 00518333  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00518335  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00518337  40                     -inc eax
    (cpu.eax)++;
    // 00518338  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0051833f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00518343  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00518346  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051834a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0051834e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518350  833d50b1a00000         +cmp dword ptr [0xa0b150], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518357  753d                   -jne 0x518396
    if (!cpu.flags.zf)
    {
        goto L_0x00518396;
    }
    // 00518359  e8a2f5fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0051835e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00518360  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00518362  750d                   -jne 0x518371
    if (!cpu.flags.zf)
    {
        goto L_0x00518371;
    }
    // 00518364  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00518369  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0051836c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051836d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051836e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051836f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518370  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00518371:
    // 00518371  8b1558b1a000           -mov edx, dword ptr [0xa0b158]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 00518377  e8a4cf0000             -call 0x525320
    cpu.esp -= 4;
    sub_525320(app, cpu);
    if (cpu.terminate) return;
    // 0051837c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00518380  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00518382  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00518386  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518388  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051838a  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0051838f  e8ac82fcff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00518394  eb3d                   -jmp 0x5183d3
    goto L_0x005183d3;
L_0x00518396:
    // 00518396  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518398  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051839a  e821020000             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 0051839f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005183a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005183a3  750d                   -jne 0x5183b2
    if (!cpu.flags.zf)
    {
        goto L_0x005183b2;
    }
    // 005183a5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005183aa  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 005183ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005183ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005183af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005183b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005183b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005183b2:
    // 005183b2  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005183b6  01c3                   +add ebx, eax
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
    // 005183b8  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 005183bb  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 005183c1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005183c4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005183c6  e875020000             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 005183cb  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005183ce  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
L_0x005183d3:
    // 005183d3  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 005183d8  c7448e0400000000       -mov dword ptr [esi + ecx*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = 0 /*0x0*/;
    // 005183e0  893558b1a000           -mov dword ptr [0xa0b158], esi
    app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */) = cpu.esi;
    // 005183e6  c6040100               -mov byte ptr [ecx + eax], 0
    app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1) = 0 /*0x0*/;
    // 005183ea  eb0b                   -jmp 0x5183f7
    goto L_0x005183f7;
L_0x005183ec:
    // 005183ec  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005183ee  0f8497000000           -je 0x51848b
    if (cpu.flags.zf)
    {
        goto L_0x0051848b;
    }
    // 005183f4  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x005183f7:
    // 005183f7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005183f9  e802cf0000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 005183fe  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00518402  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 00518407  803c0100               +cmp byte ptr [ecx + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051840b  7405                   -je 0x518412
    if (cpu.flags.zf)
    {
        goto L_0x00518412;
    }
    // 0051840d  8b1c8e                 -mov ebx, dword ptr [esi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 4);
    // 00518410  eb02                   -jmp 0x518414
    goto L_0x00518414;
L_0x00518412:
    // 00518412  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00518414:
    // 00518414  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00518416  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051841a  e8e1ce0000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 0051841f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518421  8d144500000000         -lea edx, [eax*2]
    cpu.edx = x86::reg32(cpu.eax * 2);
    // 00518428  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051842b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051842d  e88e010000             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 00518432  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00518436  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00518438  750d                   -jne 0x518447
    if (!cpu.flags.zf)
    {
        goto L_0x00518447;
    }
    // 0051843a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0051843f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00518442  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518443  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518444  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518445  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518446  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00518447:
    // 00518447  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051844b  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051844d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0051844f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00518452  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00518454  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00518458  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0051845b  e8c0ce0000             -call 0x525320
    cpu.esp -= 4;
    sub_525320(app, cpu);
    if (cpu.terminate) return;
    // 00518460  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00518464  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00518466  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051846a  66c7003d00             -mov word ptr [eax], 0x3d
    app->getMemory<x86::reg16>(cpu.eax) = 61 /*0x3d*/;
    // 0051846f  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 00518472  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518474  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00518476  e8d5ce0000             -call 0x525350
    cpu.esp -= 4;
    sub_525350(app, cpu);
    if (cpu.terminate) return;
    // 0051847b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051847f  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 00518484  89148e                 -mov dword ptr [esi + ecx*4], edx
    app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 4) = cpu.edx;
    // 00518487  c6040101               -mov byte ptr [ecx + eax], 1
    app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1) = 1 /*0x1*/;
L_0x0051848b:
    // 0051848b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0051848d:
    // 0051848d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00518490  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518491  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518492  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518493  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518494  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_518498(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518498  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00518499  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051849a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051849b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051849c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051849d  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005184a0  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005184a4  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005184a8  a158b1a000             -mov eax, dword ptr [0xa0b158]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 005184ad  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005184b0  e9e1000000             -jmp 0x518596
    goto L_0x00518596;
L_0x005184b5:
    // 005184b5  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x005184b9:
    // 005184b9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005184bd  6683383d               +cmp word ptr [eax], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005184c1  0f8591000000           -jne 0x518558
    if (!cpu.flags.zf)
    {
        goto L_0x00518558;
    }
    // 005184c7  66837d0000             +cmp word ptr [ebp], 0
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
    // 005184cc  0f8586000000           -jne 0x518558
    if (!cpu.flags.zf)
    {
        goto L_0x00518558;
    }
    // 005184d2  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 005184d5  2b3558b1a000           -sub esi, dword ptr [0xa0b158]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */)));
    // 005184db  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005184df  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 005184e2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005184e4  0f8569000000           -jne 0x518553
    if (!cpu.flags.zf)
    {
        goto L_0x00518553;
    }
    // 005184ea  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 005184ed  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 005184ef  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 005184f2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005184f4  740f                   -je 0x518505
    if (cpu.flags.zf)
    {
        goto L_0x00518505;
    }
L_0x005184f6:
    // 005184f6  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 005184f9  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 005184fb  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 005184fe  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00518501  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00518503  75f1                   -jne 0x5184f6
    if (!cpu.flags.zf)
    {
        goto L_0x005184f6;
    }
L_0x00518505:
    // 00518505  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0051850b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051850d  7449                   -je 0x518558
    if (cpu.flags.zf)
    {
        goto L_0x00518558;
    }
    // 0051850f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00518511  803c0600               +cmp byte ptr [esi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00518515  7407                   -je 0x51851e
    if (cpu.flags.zf)
    {
        goto L_0x0051851e;
    }
    // 00518517  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00518519  e8d2f4fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x0051851e:
    // 0051851e  8b1d58b1a000           -mov ebx, dword ptr [0xa0b158]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 00518524  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00518526  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00518528  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0051852e  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00518531  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00518533  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00518535  e806010000             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 0051853a  890d50b1a000           -mov dword ptr [0xa0b150], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ecx;
    // 00518540  39fe                   +cmp esi, edi
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
    // 00518542  7d14                   -jge 0x518558
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00518558;
    }
    // 00518544  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00518546:
    // 00518546  41                     -inc ecx
    (cpu.ecx)++;
    // 00518547  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00518549  46                     -inc esi
    (cpu.esi)++;
    // 0051854a  8841ff                 -mov byte ptr [ecx - 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0051854d  39fe                   +cmp esi, edi
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
    // 0051854f  7d07                   -jge 0x518558
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00518558;
    }
    // 00518551  ebf3                   -jmp 0x518546
    goto L_0x00518546;
L_0x00518553:
    // 00518553  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00518556  eb5c                   -jmp 0x5185b4
    goto L_0x005185b4;
L_0x00518558:
    // 00518558  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051855c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051855e  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 00518561  e80ace0000             -call 0x525370
    cpu.esp -= 4;
    sub_525370(app, cpu);
    if (cpu.terminate) return;
    // 00518566  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518568  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051856a  668b4500               -mov ax, word ptr [ebp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp);
    // 0051856e  e8fdcd0000             -call 0x525370
    cpu.esp -= 4;
    sub_525370(app, cpu);
    if (cpu.terminate) return;
    // 00518573  6639c2                 +cmp dx, ax
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00518576  751a                   -jne 0x518592
    if (!cpu.flags.zf)
    {
        goto L_0x00518592;
    }
    // 00518578  66837d0000             +cmp word ptr [ebp], 0
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
    // 0051857d  7413                   -je 0x518592
    if (cpu.flags.zf)
    {
        goto L_0x00518592;
    }
    // 0051857f  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00518583  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00518586  83c502                 +add ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00518589  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0051858d  e927ffffff             -jmp 0x5184b9
    goto L_0x005184b9;
L_0x00518592:
    // 00518592  83042404               -add dword ptr [esp], 4
    (app->getMemory<x86::reg32>(cpu.esp)) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00518596:
    // 00518596  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00518599  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051859b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0051859f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005185a1  0f850effffff           -jne 0x5184b5
    if (!cpu.flags.zf)
    {
        goto L_0x005184b5;
    }
    // 005185a7  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 005185aa  a158b1a000             -mov eax, dword ptr [0xa0b158]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 005185af  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 005185b1  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x005185b4:
    // 005185b4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005185b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005185b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005185b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005185ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005185bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005185bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_5185c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005185c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005185c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005185c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005185c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005185c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005185c5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005185c7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005185c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005185cb  7509                   -jne 0x5185d6
    if (!cpu.flags.zf)
    {
        goto L_0x005185d6;
    }
    // 005185cd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005185cf  e82cf3fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005185d4  eb62                   -jmp 0x518638
    goto L_0x00518638;
L_0x005185d6:
    // 005185d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005185d8  750d                   -jne 0x5185e7
    if (!cpu.flags.zf)
    {
        goto L_0x005185e7;
    }
    // 005185da  e811f4fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 005185df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005185e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005185e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005185e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005185e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005185e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005185e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005185e7:
    // 005185e7  e894cd0000             -call 0x525380
    cpu.esp -= 4;
    sub_525380(app, cpu);
    if (cpu.terminate) return;
    // 005185ec  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005185ee  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005185f0  e89bcd0000             -call 0x525390
    cpu.esp -= 4;
    sub_525390(app, cpu);
    if (cpu.terminate) return;
    // 005185f5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005185f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005185f9  753b                   -jne 0x518636
    if (!cpu.flags.zf)
    {
        goto L_0x00518636;
    }
    // 005185fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005185fd  e8fef2fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 00518602  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00518604  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00518606  7425                   -je 0x51862d
    if (cpu.flags.zf)
    {
        goto L_0x0051862d;
    }
    // 00518608  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0051860a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051860c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0051860e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0051860f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00518611  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00518613  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518614  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00518616  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00518619  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051861b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0051861d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00518620  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00518622  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518623  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00518624  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00518626  e8c5f3fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0051862b  eb09                   -jmp 0x518636
    goto L_0x00518636;
L_0x0051862d:
    // 0051862d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051862f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00518631  e85acd0000             -call 0x525390
    cpu.esp -= 4;
    sub_525390(app, cpu);
    if (cpu.terminate) return;
L_0x00518636:
    // 00518636  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00518638:
    // 00518638  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518639  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051863a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051863b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051863c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051863d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_518640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518640  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00518641  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518642  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518643  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00518645  39c2                   +cmp edx, eax
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
    // 00518647  7440                   -je 0x518689
    if (cpu.flags.zf)
    {
        goto L_0x00518689;
    }
    // 00518649  7328                   -jae 0x518673
    if (!cpu.flags.cf)
    {
        goto L_0x00518673;
    }
    // 0051864b  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0051864e  39c7                   +cmp edi, eax
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
    // 00518650  7621                   -jbe 0x518673
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00518673;
    }
    // 00518652  8d77ff                 -lea esi, [edi - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00518655  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00518658  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0051865a  4f                     -dec edi
    (cpu.edi)--;
    // 0051865b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0051865c  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 0051865e  fd                     -std 
    cpu.flags.df = 1;
    // 0051865f  4e                     -dec esi
    (cpu.esi)--;
    // 00518660  4f                     -dec edi
    (cpu.edi)--;
    // 00518661  d1e9                   +shr ecx, 1
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
    // 00518663  66f3a5                 -rep movsw word ptr es:[edi], word ptr [esi]
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
    // 00518666  11c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00518668  46                     -inc esi
    (cpu.esi)++;
    // 00518669  47                     -inc edi
    (cpu.edi)++;
    // 0051866a  66f3a4                 -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0051866d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0051866e  fc                     -cld 
    cpu.flags.df = 0;
    // 0051866f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518670  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518671  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518672  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00518673:
    // 00518673  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00518675  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00518677  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00518679  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0051867a  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 0051867c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051867d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00518680  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00518682  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518683  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00518686  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00518688  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00518689:
    // 00518689  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051868a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051868b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051868c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_518690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00518691  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00518692  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518693  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518694  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00518695  81ec30030000           -sub esp, 0x330
    (cpu.esp) -= x86::reg32(x86::sreg32(816 /*0x330*/));
    // 0051869b  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 005186a2  8994240c030000         -mov dword ptr [esp + 0x30c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */) = cpu.edx;
    // 005186a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005186ab  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x005186ad:
    // 005186ad  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005186b0  8b8814a8a000           -mov ecx, dword ptr [eax + 0xa0a814]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10528788) /* 0xa0a814 */);
    // 005186b6  8b9814a8a000           -mov ebx, dword ptr [eax + 0xa0a814]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10528788) /* 0xa0a814 */);
    // 005186bc  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 005186bf  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 005186c2  884c14fd               -mov byte ptr [esp + edx - 3], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-3) /* -0x3 */ + cpu.edx * 1) = cpu.cl;
    // 005186c6  885c14fe               -mov byte ptr [esp + edx - 2], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.edx * 1) = cpu.bl;
    // 005186ca  8a9814a8a000           -mov bl, byte ptr [eax + 0xa0a814]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10528788) /* 0xa0a814 */);
    // 005186d0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005186d3  885c14ff               -mov byte ptr [esp + edx - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.edx * 1) = cpu.bl;
    // 005186d7  3d00040000             +cmp eax, 0x400
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
    // 005186dc  75cf                   -jne 0x5186ad
    if (!cpu.flags.zf)
    {
        goto L_0x005186ad;
    }
    // 005186de  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 005186e5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 005186e7  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 005186ea  89bc2404030000         -mov dword ptr [esp + 0x304], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.edi;
    // 005186f1  89842408030000         -mov dword ptr [esp + 0x308], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */) = cpu.eax;
L_0x005186f8:
    // 005186f8  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 005186ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00518701  8a0414                 -mov al, byte ptr [esp + edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1);
    // 00518704  89842418030000         -mov dword ptr [esp + 0x318], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */) = cpu.eax;
    // 0051870b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051870d  8a441401               -mov al, byte ptr [esp + edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.edx * 1);
    // 00518711  89842410030000         -mov dword ptr [esp + 0x310], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */) = cpu.eax;
    // 00518718  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051871a  8b8c2400030000         -mov ecx, dword ptr [esp + 0x300]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 00518721  8a441402               -mov al, byte ptr [esp + edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.edx * 1);
    // 00518725  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00518727  89842414030000         -mov dword ptr [esp + 0x314], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */) = cpu.eax;
L_0x0051872e:
    // 0051872e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00518730  8a5103                 -mov dl, byte ptr [ecx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 00518733  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00518735  754b                   -jne 0x518782
    if (!cpu.flags.zf)
    {
        goto L_0x00518782;
    }
    // 00518737  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00518739:
    // 00518739  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051873b  8b9c240c030000         -mov ebx, dword ptr [esp + 0x30c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 00518742  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00518744  8bac2408030000         -mov ebp, dword ptr [esp + 0x308]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 0051874b  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0051874d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00518750  81c600010000           -add esi, 0x100
    (cpu.esi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00518756  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00518758  39e9                   +cmp ecx, ebp
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
    // 0051875a  75d2                   -jne 0x51872e
    if (!cpu.flags.zf)
    {
        goto L_0x0051872e;
    }
    // 0051875c  8b842404030000         -mov eax, dword ptr [esp + 0x304]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 00518763  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00518766  47                     -inc edi
    (cpu.edi)++;
    // 00518767  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 0051876e  81ff00010000           +cmp edi, 0x100
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518774  7c82                   -jl 0x5186f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005186f8;
    }
    // 00518776  81c430030000           -add esp, 0x330
    (cpu.esp) += x86::reg32(x86::sreg32(816 /*0x330*/));
    // 0051877c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051877d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051877e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051877f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518780  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518781  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00518782:
    // 00518782  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 00518787  89942424030000         -mov dword ptr [esp + 0x324], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */) = cpu.edx;
    // 0051878e  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00518790  8b942418030000         -mov edx, dword ptr [esp + 0x318]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */);
    // 00518797  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0051879a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051879c  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0051879f  8984241c030000         -mov dword ptr [esp + 0x31c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */) = cpu.eax;
    // 005187a6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005187a8  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 005187aa  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 005187b5  89842420030000         -mov dword ptr [esp + 0x320], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */) = cpu.eax;
    // 005187bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005187be  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005187c1  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005187c8  0384241c030000         -add eax, dword ptr [esp + 0x31c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */)));
    // 005187cf  0fb66901               -movzx ebp, byte ptr [ecx + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */));
    // 005187d3  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005187d8  7e05                   -jle 0x5187df
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005187df;
    }
    // 005187da  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x005187df:
    // 005187df  8b942410030000         -mov edx, dword ptr [esp + 0x310]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 005187e6  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 005187e9  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 005187f4  89842428030000         -mov dword ptr [esp + 0x328], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */) = cpu.eax;
    // 005187fb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005187fd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00518800  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00518807  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00518809  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051880e  7e05                   -jle 0x518815
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00518815;
    }
    // 00518810  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x00518815:
    // 00518815  8b942414030000         -mov edx, dword ptr [esp + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 0051881c  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0051881f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00518821  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 00518826  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00518828  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051882b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051882d  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 00518834  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00518836  39da                   +cmp edx, ebx
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
    // 00518838  7e02                   -jle 0x51883c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051883c;
    }
    // 0051883a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0051883c:
    // 0051883c  8b842424030000         -mov eax, dword ptr [esp + 0x324]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 00518843  8b9c2428030000         -mov ebx, dword ptr [esp + 0x328]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */);
    // 0051884a  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0051884d  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00518850  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 00518853  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00518855  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00518857  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00518859  e8026ffdff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0051885e  e9d6feffff             -jmp 0x518739
    goto L_0x00518739;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_518870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518870  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518871  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518872  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00518873  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00518876  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0051887a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0051887e  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00518880  8b0d34905600           -mov ecx, dword ptr [0x569034]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5673012) /* 0x569034 */);
    // 00518886  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00518888  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051888a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051888d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051888f  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00518891  0faff8                 -imul edi, eax
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00518894  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00518896  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00518898  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0051889b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051889e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 005188a0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005188a2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005188a4  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 005188a6  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 005188a8  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 005188ac  40                     -inc eax
    (cpu.eax)++;
    // 005188ad  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 005188af  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005188b3  8a2512505600           -mov ah, byte ptr [0x565012]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5656594) /* 0x565012 */);
    // 005188b9  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 005188bc  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 005188be  0f858b030000           -jne 0x518c4f
    if (!cpu.flags.zf)
    {
        goto L_0x00518c4f;
    }
    // 005188c4  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 005188c8  3b0500505600           +cmp eax, dword ptr [0x565000]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005188ce  0f8c7b030000           -jl 0x518c4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00518c4f;
    }
    // 005188d4  3b0508505600           +cmp eax, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005188da  0f8d6f030000           -jge 0x518c4f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00518c4f;
    }
    // 005188e0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005188e4  3b0504505600           +cmp eax, dword ptr [0x565004]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005188ea  0f8c5f030000           -jl 0x518c4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00518c4f;
    }
    // 005188f0  3b050c505600           +cmp eax, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005188f6  0f8d53030000           -jge 0x518c4f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00518c4f;
    }
    // 005188fc  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00518900  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00518904  8b1d00505600           -mov ebx, dword ptr [0x565000]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 0051890a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051890c  39d8                   +cmp eax, ebx
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
    // 0051890e  0f8c3b030000           -jl 0x518c4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00518c4f;
    }
    // 00518914  3b0508505600           +cmp eax, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051891a  0f8d2f030000           -jge 0x518c4f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00518c4f;
    }
    // 00518920  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00518924  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00518928  8b1d04505600           -mov ebx, dword ptr [0x565004]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 0051892e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00518930  39d8                   +cmp eax, ebx
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
    // 00518932  0f8c17030000           -jl 0x518c4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00518c4f;
    }
    // 00518938  3b050c505600           +cmp eax, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051893e  0f8d0b030000           -jge 0x518c4f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00518c4f;
    }
    // 00518944  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00518948  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051894a  8a1510505600           -mov dl, byte ptr [0x565010]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 00518950  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00518952  80fa10                 +cmp dl, 0x10
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00518955  0f8567010000           -jne 0x518ac2
    if (!cpu.flags.zf)
    {
        goto L_0x00518ac2;
    }
    // 0051895b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0051895f:
    // 0051895f  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00518963  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00518967  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0051896d  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00518970  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 00518976  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 00518979  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 0051897f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00518981  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00518985  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x00518989:
    // 00518989  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051898b  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0051898d  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00518990  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 00518994  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051899a  726b                   -jb 0x518a07
    if (cpu.flags.cf)
    {
        goto L_0x00518a07;
    }
    // 0051899c  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005189a2  7340                   -jae 0x5189e4
    if (!cpu.flags.cf)
    {
        goto L_0x005189e4;
    }
    // 005189a4  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 005189a7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005189a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005189ab  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 005189ae  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 005189b1  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 005189b3  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 005189b9  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 005189bc  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 005189c1  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 005189c4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005189c6  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 005189c8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 005189cb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005189cd  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 005189d0  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 005189d2  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 005189d5  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005189db  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 005189e0  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 005189e2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x005189e4:
    // 005189e4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005189e6  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 005189ec  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 005189ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005189f1  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 005189f4  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 005189fa  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 005189fd  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00518a00  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00518a02  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518a04  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00518a07:
    // 00518a07  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00518a0a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00518a0c  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00518a0e  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00518a11  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 00518a15  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518a1b  726b                   -jb 0x518a88
    if (cpu.flags.cf)
    {
        goto L_0x00518a88;
    }
    // 00518a1d  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518a23  7340                   -jae 0x518a65
    if (!cpu.flags.cf)
    {
        goto L_0x00518a65;
    }
    // 00518a25  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00518a28  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00518a2a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518a2c  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00518a2f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00518a32  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00518a34  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00518a3a  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00518a3d  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00518a42  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00518a45  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518a47  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00518a49  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00518a4c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00518a4e  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00518a51  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518a53  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00518a56  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00518a5c  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00518a61  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00518a63  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00518a65:
    // 00518a65  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00518a67  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00518a6d  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00518a70  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518a72  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00518a75  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00518a7b  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00518a7e  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00518a81  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00518a83  01d3                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00518a85  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00518a88:
    // 00518a88  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00518a8b  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00518a8f  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00518a90  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00518a91  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 00518a95  0f85eefeffff           -jne 0x518989
    if (!cpu.flags.zf)
    {
        goto L_0x00518989;
    }
    // 00518a9b  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00518a9f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00518aa3  8b5c2448               -mov ebx, dword ptr [esp + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00518aa7  41                     -inc ecx
    (cpu.ecx)++;
    // 00518aa8  01d7                   +add edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00518aaa  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00518aae  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00518aaf  895c2448               -mov dword ptr [esp + 0x48], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ebx;
    // 00518ab3  0f85a6feffff           -jne 0x51895f
    if (!cpu.flags.zf)
    {
        goto L_0x0051895f;
    }
L_0x00518ab9:
    // 00518ab9  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00518abc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518abd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518abe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518abf  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00518ac2:
    // 00518ac2  80fa0f                 +cmp dl, 0xf
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00518ac5  0f857b010000           -jne 0x518c46
    if (!cpu.flags.zf)
    {
        goto L_0x00518c46;
    }
    // 00518acb  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00518acf:
    // 00518acf  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00518ad3  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00518ad7  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 00518add  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00518ae0  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 00518ae6  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 00518ae9  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 00518aef  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00518af1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00518af5  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x00518af9:
    // 00518af9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00518afb  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00518afd  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00518b00  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00518b03  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00518b06  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00518b08  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518b0e  7273                   -jb 0x518b83
    if (cpu.flags.cf)
    {
        goto L_0x00518b83;
    }
    // 00518b10  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518b16  7348                   -jae 0x518b60
    if (!cpu.flags.cf)
    {
        goto L_0x00518b60;
    }
    // 00518b18  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00518b1b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00518b1d  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 00518b22  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 00518b25  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00518b27  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00518b2d  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00518b30  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518b32  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00518b35  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00518b37  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00518b39  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00518b3c  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00518b42  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00518b44  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00518b47  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518b49  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518b4b  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00518b4e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00518b54  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518b56  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00518b59  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00518b5e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00518b60:
    // 00518b60  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00518b62  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00518b68  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00518b6b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518b6d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00518b70  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00518b76  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00518b79  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00518b7c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00518b7e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518b80  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00518b83:
    // 00518b83  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00518b86  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00518b88  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00518b8a  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00518b8d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00518b90  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00518b93  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00518b95  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518b9b  7273                   -jb 0x518c10
    if (cpu.flags.cf)
    {
        goto L_0x00518c10;
    }
    // 00518b9d  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518ba3  7348                   -jae 0x518bed
    if (!cpu.flags.cf)
    {
        goto L_0x00518bed;
    }
    // 00518ba5  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00518ba8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00518baa  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 00518baf  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 00518bb2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00518bb4  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00518bba  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00518bbd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518bbf  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00518bc2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00518bc4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00518bc6  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00518bc9  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00518bcf  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00518bd1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00518bd4  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518bd6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518bd8  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00518bdb  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00518be1  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518be3  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00518be6  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00518beb  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00518bed:
    // 00518bed  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00518bef  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00518bf5  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00518bf8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518bfa  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00518bfd  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00518c03  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00518c06  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00518c09  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00518c0b  01d3                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00518c0d  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00518c10:
    // 00518c10  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00518c13  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00518c17  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00518c18  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00518c19  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 00518c1d  0f85d6feffff           -jne 0x518af9
    if (!cpu.flags.zf)
    {
        goto L_0x00518af9;
    }
    // 00518c23  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00518c27  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00518c2b  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00518c2f  40                     -inc eax
    (cpu.eax)++;
    // 00518c30  01f7                   +add edi, esi
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
    // 00518c32  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00518c36  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00518c37  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00518c3b  0f8478feffff           -je 0x518ab9
    if (cpu.flags.zf)
    {
        goto L_0x00518ab9;
    }
    // 00518c41  e989feffff             -jmp 0x518acf
    goto L_0x00518acf;
L_0x00518c46:
    // 00518c46  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00518c49  0f849a000000           -je 0x518ce9
    if (cpu.flags.zf)
    {
        goto L_0x00518ce9;
    }
L_0x00518c4f:
    // 00518c4f  8b5c2448               -mov ebx, dword ptr [esp + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00518c53  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00518c55  0f8e5efeffff           -jle 0x518ab9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00518ab9;
    }
    // 00518c5b  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00518c5f  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00518c63  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00518c67  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00518c69  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00518c6b  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00518c6e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00518c72:
    // 00518c72  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00518c76  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00518c78  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00518c7a  7e51                   -jle 0x518ccd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00518ccd;
    }
    // 00518c7c  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00518c80  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00518c84  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00518c88  46                     -inc esi
    (cpu.esi)++;
    // 00518c89  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00518c8d:
    // 00518c8d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00518c8f  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00518c91  47                     -inc edi
    (cpu.edi)++;
    // 00518c92  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00518c94  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00518c97  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00518c9a  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00518c9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00518ca0  0f858d000000           -jne 0x518d33
    if (!cpu.flags.zf)
    {
        goto L_0x00518d33;
    }
L_0x00518ca6:
    // 00518ca6  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00518caa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00518cac  7411                   -je 0x518cbf
    if (cpu.flags.zf)
    {
        goto L_0x00518cbf;
    }
    // 00518cae  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00518cb0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00518cb2  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00518cb6  8b5c9d00               -mov ebx, dword ptr [ebp + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.ebx * 4);
    // 00518cba  e8a1aa0000             -call 0x523760
    cpu.esp -= 4;
    sub_523760(app, cpu);
    if (cpu.terminate) return;
L_0x00518cbf:
    // 00518cbf  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00518cc3  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00518cc6  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00518cc9  39c1                   +cmp ecx, eax
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
    // 00518ccb  7cc0                   -jl 0x518c8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00518c8d;
    }
L_0x00518ccd:
    // 00518ccd  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00518cd0  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00518cd4  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00518cd8  46                     -inc esi
    (cpu.esi)++;
    // 00518cd9  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00518cdb  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00518cdf  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518ce1  0f8dd2fdffff           -jge 0x518ab9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00518ab9;
    }
    // 00518ce7  eb89                   -jmp 0x518c72
    goto L_0x00518c72;
L_0x00518ce9:
    // 00518ce9  8b1d1c505600           -mov ebx, dword ptr [0x56501c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */);
    // 00518cef  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00518cf1  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00518cf3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00518cf4  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00518cf8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00518cf9  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00518cfd  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00518d01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518d02  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00518d05  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00518d06  a120505600             -mov eax, dword ptr [0x565020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 00518d0b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00518d0d  a114505600             -mov eax, dword ptr [0x565014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */);
    // 00518d12  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00518d14  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00518d18  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00518d1a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00518d1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00518d1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518d1e  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00518d21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00518d22  e8c5ac0000             -call 0x5239ec
    cpu.esp -= 4;
    sub_5239ec(app, cpu);
    if (cpu.terminate) return;
    // 00518d27  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00518d2a  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00518d2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518d2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518d2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518d30  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00518d33:
    // 00518d33  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 00518d37  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00518d3b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00518d3f  01c8                   +add eax, ecx
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
    // 00518d41  e81aaa0000             -call 0x523760
    cpu.esp -= 4;
    sub_523760(app, cpu);
    if (cpu.terminate) return;
    // 00518d46  e95bffffff             -jmp 0x518ca6
    goto L_0x00518ca6;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_518d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518d50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00518d51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518d52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518d53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00518d54  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00518d57  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00518d5b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00518d5d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00518d5f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00518d61  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00518d63  0f8e77000000           -jle 0x518de0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00518de0;
    }
L_0x00518d69:
    // 00518d69  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00518d6b  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00518d6d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00518d70  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 00518d73  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00518d78  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00518d7b  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 00518d80  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00518d82  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00518d87  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00518d89  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00518d8b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00518d8e  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00518d91  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00518d93  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00518d95  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00518d98  21e8                   -and eax, ebp
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ebp));
    // 00518d9a  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00518d9d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00518da0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00518da2  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00518da7  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00518da9  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00518dac  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00518daf  09c5                   -or ebp, eax
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.eax));
    // 00518db1  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00518db3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00518db8  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00518dbb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00518dbd  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 00518dc2  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00518dc7  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00518dc9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00518dcc  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00518dcf  47                     -inc edi
    (cpu.edi)++;
    // 00518dd0  09c5                   -or ebp, eax
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.eax));
    // 00518dd2  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00518dd6  896efc                 -mov dword ptr [esi - 4], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00518dd9  39df                   +cmp edi, ebx
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
    // 00518ddb  7c8c                   -jl 0x518d69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00518d69;
    }
    // 00518ddd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00518de0:
    // 00518de0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00518de3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518de4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518de5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518de6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518de7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_518df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00518df1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00518df2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00518df4  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00518df9  e882010000             -call 0x518f80
    cpu.esp -= 4;
    sub_518f80(app, cpu);
    if (cpu.terminate) return;
    // 00518dfe  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00518e01  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00518e04  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00518e06  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00518e08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00518e0a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00518e0d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00518e0f  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00518e11  e86a010000             -call 0x518f80
    cpu.esp -= 4;
    sub_518f80(app, cpu);
    if (cpu.terminate) return;
    // 00518e16  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00518e19  b840000000             -mov eax, 0x40
    cpu.eax = 64 /*0x40*/;
    // 00518e1e  e85d010000             -call 0x518f80
    cpu.esp -= 4;
    sub_518f80(app, cpu);
    if (cpu.terminate) return;
    // 00518e23  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00518e26  b840100000             -mov eax, 0x1040
    cpu.eax = 4160 /*0x1040*/;
    // 00518e2b  e850010000             -call 0x518f80
    cpu.esp -= 4;
    sub_518f80(app, cpu);
    if (cpu.terminate) return;
    // 00518e30  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00518e33  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00518e35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518e36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518e37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_518e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518e40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00518e41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518e42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518e43  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00518e45  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00518e47  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00518e49  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00518e4b  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00518e4e  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00518e51  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00518e53  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00518e56  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00518e58  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00518e5a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00518e5c  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00518e5f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00518e61  e88a16fdff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00518e66  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00518e6b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00518e6d  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00518e70  e8dbfeffff             -call 0x518d50
    cpu.esp -= 4;
    sub_518d50(app, cpu);
    if (cpu.terminate) return;
    // 00518e75  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00518e7a  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00518e7d  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00518e80  e86b16fdff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00518e85  803d1050560008         +cmp byte ptr [0x565010], 8
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
    // 00518e8c  7609                   -jbe 0x518e97
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00518e97;
    }
    // 00518e8e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00518e93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518e94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518e95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518e96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00518e97:
    // 00518e97  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00518e9a  8d5040                 -lea edx, [eax + 0x40]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00518e9d  e8eef7ffff             -call 0x518690
    cpu.esp -= 4;
    sub_518690(app, cpu);
    if (cpu.terminate) return;
    // 00518ea2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00518ea7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518ea8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518ea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518eaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_518eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518eb0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00518eb1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518eb3  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00518eb6  e8d589fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00518ebb  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00518ebe  e8cd89fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00518ec3  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00518ec6  e8c589fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00518ecb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00518ecd  e8be89fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00518ed2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518ed3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_518ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518ee0  a334905600             -mov dword ptr [0x569034], eax
    app->getMemory<x86::reg32>(x86::reg32(5673012) /* 0x569034 */) = cpu.eax;
    // 00518ee5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00518eea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_518ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518ef0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518ef1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00518ef2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00518ef3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00518ef6  8d2c8500000000         -lea ebp, [eax*4]
    cpu.ebp = x86::reg32(cpu.eax * 4);
    // 00518efd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00518eff  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00518f01  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00518f03  7e68                   -jle 0x518f6d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00518f6d;
    }
    // 00518f05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x00518f06:
    // 00518f06  81c680000000           -add esi, 0x80
    (cpu.esi) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00518f0c  d946a0                 -fld dword ptr [esi - 0x60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(-96) /* -0x60 */)));
    // 00518f0f  d946c4                 -fld dword ptr [esi - 0x3c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(-60) /* -0x3c */)));
    // 00518f12  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00518f15  8b4680                 -mov eax, dword ptr [esi - 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-128) /* -0x80 */);
    // 00518f18  8b5e98                 -mov ebx, dword ptr [esi - 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-104) /* -0x68 */);
    // 00518f1b  8b4e9c                 -mov ecx, dword ptr [esi - 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-100) /* -0x64 */);
    // 00518f1e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00518f22  8b4684                 -mov eax, dword ptr [esi - 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-124) /* -0x7c */);
    // 00518f25  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00518f27  d8642404               -fsub dword ptr [esp + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 00518f2b  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00518f2f  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00518f33  d8642408               -fsub dword ptr [esp + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00518f37  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00518f3a  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00518f3d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518f3e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00518f3f  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00518f43  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00518f46  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00518f49  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518f4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00518f4b  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00518f4f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00518f52  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00518f55  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518f56  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00518f5a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518f5c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00518f5f  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00518f62  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518f63  e808f9ffff             -call 0x518870
    cpu.esp -= 4;
    sub_518870(app, cpu);
    if (cpu.terminate) return;
    // 00518f68  39ef                   +cmp edi, ebp
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
    // 00518f6a  7c9a                   -jl 0x518f06
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00518f06;
    }
    // 00518f6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00518f6d:
    // 00518f6d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00518f72  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00518f75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518f76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518f77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518f78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_518f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518f80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00518f81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00518f82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00518f83  ba80075500             -mov edx, 0x550780
    cpu.edx = 5572480 /*0x550780*/;
    // 00518f88  b990075500             -mov ecx, 0x550790
    cpu.ecx = 5572496 /*0x550790*/;
    // 00518f8d  bb27010000             -mov ebx, 0x127
    cpu.ebx = 295 /*0x127*/;
    // 00518f92  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00518f98  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00518f9e  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 00518fa4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00518fa6  b8a0075500             -mov eax, 0x5507a0
    cpu.eax = 5572512 /*0x5507a0*/;
    // 00518fab  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00518fb1  e86a86fcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00518fb6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518fb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518fb8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00518fb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_518fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518fc0  e9cb88fcff             -jmp 0x4e1890
    return sub_4e1890(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_518fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00518fd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00518fd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00518fd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00518fd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00518fd4  8b1d54905600           -mov ebx, dword ptr [0x569054]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */);
    // 00518fda  8b355c905600           -mov esi, dword ptr [0x56905c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5673052) /* 0x56905c */);
    // 00518fe0  833d5890560000         +cmp dword ptr [0x569058], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5673048) /* 0x569058 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00518fe7  0f8573000000           -jne 0x519060
    if (!cpu.flags.zf)
    {
        goto L_0x00519060;
    }
    // 00518fed  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00518fef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00518ff1  7505                   -jne 0x518ff8
    if (!cpu.flags.zf)
    {
        goto L_0x00518ff8;
    }
    // 00518ff3  bb90010000             -mov ebx, 0x190
    cpu.ebx = 400 /*0x190*/;
L_0x00518ff8:
    // 00518ff8  8b158c715600           -mov edx, dword ptr [0x56718c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 00518ffe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00519000  891d54905600           -mov dword ptr [0x569054], ebx
    app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */) = cpu.ebx;
    // 00519006  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00519009  89355c905600           -mov dword ptr [0x56905c], esi
    app->getMemory<x86::reg32>(x86::reg32(5673052) /* 0x56905c */) = cpu.esi;
    // 0051900f  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00519012  8b1d54905600           -mov ebx, dword ptr [0x569054]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */);
    // 00519018  8b158c715600           -mov edx, dword ptr [0x56718c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 0051901e  a358905600             -mov dword ptr [0x569058], eax
    app->getMemory<x86::reg32>(x86::reg32(5673048) /* 0x569058 */) = cpu.eax;
    // 00519023  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0051902a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051902c  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051902f  8b1d54905600           -mov ebx, dword ptr [0x569054]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */);
    // 00519035  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00519037  890d60905600           -mov dword ptr [0x569060], ecx
    app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */) = cpu.ecx;
    // 0051903d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051903f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00519041  7e1d                   -jle 0x519060
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00519060;
    }
    // 00519043  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00519045  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00519047:
    // 00519047  890411                 -mov dword ptr [ecx + edx], eax
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.eax;
    // 0051904a  40                     -inc eax
    (cpu.eax)++;
    // 0051904b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051904e  39d8                   +cmp eax, ebx
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
    // 00519050  7cf5                   -jl 0x519047
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00519047;
    }
    // 00519052  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00519058  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0051905e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00519060:
    // 00519060  89355c905600           -mov dword ptr [0x56905c], esi
    app->getMemory<x86::reg32>(x86::reg32(5673052) /* 0x56905c */) = cpu.esi;
    // 00519066  891d54905600           -mov dword ptr [0x569054], ebx
    app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */) = cpu.ebx;
    // 0051906c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051906d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051906e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051906f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519070  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_519080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00519080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00519081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00519082  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00519083  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00519084  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00519085  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00519086  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00519089  8b1d54905600           -mov ebx, dword ptr [0x569054]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */);
    // 0051908f  8b2d5c905600           -mov ebp, dword ptr [0x56905c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5673052) /* 0x56905c */);
    // 00519095  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00519097  a158905600             -mov eax, dword ptr [0x569058]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5673048) /* 0x569058 */);
    // 0051909c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051909f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005190a1  8b0d8c715600           -mov ecx, dword ptr [0x56718c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 005190a7  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 005190aa  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 005190ad  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005190b0  8b0d54905600           -mov ecx, dword ptr [0x569054]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */);
    // 005190b6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005190b8  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 005190bb  a358905600             -mov dword ptr [0x569058], eax
    app->getMemory<x86::reg32>(x86::reg32(5673048) /* 0x569058 */) = cpu.eax;
    // 005190c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005190c1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005190c3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 005190c6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005190c8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 005190ca  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 005190cd  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005190cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005190d0  8b0d8c715600           -mov ecx, dword ptr [0x56718c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 005190d6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005190d9  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005190dc  8b0d8c715600           -mov ecx, dword ptr [0x56718c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 005190e2  a15c905600             -mov eax, dword ptr [0x56905c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5673052) /* 0x56905c */);
    // 005190e7  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005190ea  8b0d8c715600           -mov ecx, dword ptr [0x56718c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 005190f0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005190f7  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005190fa  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005190fc  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 005190fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00519100  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00519102  7e1c                   -jle 0x519120
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00519120;
    }
    // 00519104  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00519106  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00519108:
    // 00519108  890411                 -mov dword ptr [ecx + edx], eax
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.eax;
    // 0051910b  40                     -inc eax
    (cpu.eax)++;
    // 0051910c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051910f  39d8                   +cmp eax, ebx
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
    // 00519111  7cf5                   -jl 0x519108
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00519108;
    }
    // 00519113  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00519119  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0051911f  90                     -nop 
    ;
L_0x00519120:
    // 00519120  892d5c905600           -mov dword ptr [0x56905c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5673052) /* 0x56905c */) = cpu.ebp;
    // 00519126  891d54905600           -mov dword ptr [0x569054], ebx
    app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */) = cpu.ebx;
    // 0051912c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051912f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519130  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519131  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519132  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519133  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519134  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519135  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_519140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00519140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00519141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00519142  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00519143  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00519144  833d5890560000         +cmp dword ptr [0x569058], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5673048) /* 0x569058 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051914b  751d                   -jne 0x51916a
    if (!cpu.flags.zf)
    {
        goto L_0x0051916a;
    }
L_0x0051914d:
    // 0051914d  8b1d5c905600           -mov ebx, dword ptr [0x56905c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5673052) /* 0x56905c */);
    // 00519153  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00519155  752b                   -jne 0x519182
    if (!cpu.flags.zf)
    {
        goto L_0x00519182;
    }
    // 00519157  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00519159  893d54905600           -mov dword ptr [0x569054], edi
    app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */) = cpu.edi;
    // 0051915f  893d60905600           -mov dword ptr [0x569060], edi
    app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */) = cpu.edi;
    // 00519165  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519166  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519167  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519168  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519169  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051916a:
    // 0051916a  8b158c715600           -mov edx, dword ptr [0x56718c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 00519170  a158905600             -mov eax, dword ptr [0x569058]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5673048) /* 0x569058 */);
    // 00519175  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00519177  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051917a  890d58905600           -mov dword ptr [0x569058], ecx
    app->getMemory<x86::reg32>(x86::reg32(5673048) /* 0x569058 */) = cpu.ecx;
    // 00519180  ebcb                   -jmp 0x51914d
    goto L_0x0051914d;
L_0x00519182:
    // 00519182  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00519183  8b158c715600           -mov edx, dword ptr [0x56718c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 00519189  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051918b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051918d  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00519190  89355c905600           -mov dword ptr [0x56905c], esi
    app->getMemory<x86::reg32>(x86::reg32(5673052) /* 0x56905c */) = cpu.esi;
    // 00519196  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519197  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00519199  893d54905600           -mov dword ptr [0x569054], edi
    app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */) = cpu.edi;
    // 0051919f  893d60905600           -mov dword ptr [0x569060], edi
    app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */) = cpu.edi;
    // 005191a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005191a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005191a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005191a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005191a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_5191b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005191b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005191b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005191b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005191b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005191b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005191b5  83ec08                 +sub esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005191b8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005191ba  d902                   +fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005191bc  d898d0000000           +fcomp dword ptr [eax + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 005191c2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005191c4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005191c5  0f8225030000           -jb 0x5194f0
    if (cpu.flags.cf)
    {
        goto L_0x005194f0;
    }
L_0x005191cb:
    // 005191cb  d94204                 +fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005191ce  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 005191d4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005191d6  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005191d7  734d                   -jae 0x519226
    if (!cpu.flags.cf)
    {
        goto L_0x00519226;
    }
    // 005191d9  d94264                 -fld dword ptr [edx + 0x64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */)));
    // 005191dc  d8a1d8000000           -fsub dword ptr [ecx + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */));
    // 005191e2  d94264                 -fld dword ptr [edx + 0x64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */)));
    // 005191e5  d86204                 -fsub dword ptr [edx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 005191e8  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005191ea  8b427c                 -mov eax, dword ptr [edx + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */);
    // 005191ed  8b6a1c                 -mov ebp, dword ptr [edx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 005191f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005191f2  29e8                   +sub eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005191f4  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 005191f8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005191fb  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 005191fe  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519200  8b427c                 -mov eax, dword ptr [edx + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */);
    // 00519203  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00519207  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051920a  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 0051920d  dee1                   +fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0051920f  e8426bfcff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00519214  df3c24                 +fistp qword ptr [esp]
    app->getMemory<x86::reg64>(cpu.esp) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00519217  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051921a  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0051921d  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00519223  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00519226:
    // 00519226  d902                   +fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00519228  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 0051922e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519230  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519231  7608                   -jbe 0x51923b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051923b;
    }
    // 00519233  8b81d4000000           -mov eax, dword ptr [ecx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00519239  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0051923b:
    // 0051923b  d94204                 +fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0051923e  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 00519244  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519246  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519247  7609                   -jbe 0x519252
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00519252;
    }
    // 00519249  8b81dc000000           -mov eax, dword ptr [ecx + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0051924f  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00519252:
    // 00519252  d94220                 +fld dword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 00519255  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 0051925b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051925d  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051925e  7648                   -jbe 0x5192a8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005192a8;
    }
    // 00519260  d981d4000000           -fld dword ptr [ecx + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    // 00519266  d822                   -fsub dword ptr [edx]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx));
    // 00519268  d94220                 -fld dword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 0051926b  d822                   -fsub dword ptr [edx]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx));
    // 0051926d  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051926f  8b4238                 -mov eax, dword ptr [edx + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 00519272  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00519275  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00519277  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00519279  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0051927d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00519280  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00519283  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519285  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00519289  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0051928c  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 0051928f  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519291  e8c06afcff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00519296  df3c24                 +fistp qword ptr [esp]
    app->getMemory<x86::reg64>(cpu.esp) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00519299  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051929c  894238                 -mov dword ptr [edx + 0x38], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0051929f  8b81d4000000           -mov eax, dword ptr [ecx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 005192a5  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x005192a8:
    // 005192a8  d94224                 +fld dword ptr [edx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */)));
    // 005192ab  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 005192b1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005192b3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005192b4  734d                   -jae 0x519303
    if (!cpu.flags.cf)
    {
        goto L_0x00519303;
    }
    // 005192b6  d94244                 -fld dword ptr [edx + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(68) /* 0x44 */)));
    // 005192b9  d8a1d8000000           -fsub dword ptr [ecx + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */));
    // 005192bf  d94244                 -fld dword ptr [edx + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(68) /* 0x44 */)));
    // 005192c2  d86224                 -fsub dword ptr [edx + 0x24]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */));
    // 005192c5  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005192c7  8b425c                 -mov eax, dword ptr [edx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */);
    // 005192ca  8b5a3c                 -mov ebx, dword ptr [edx + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 005192cd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 005192cf  29d8                   +sub eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005192d1  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 005192d5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005192d8  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 005192db  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005192dd  8b425c                 -mov eax, dword ptr [edx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */);
    // 005192e0  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 005192e4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005192e7  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 005192ea  dee1                   +fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 005192ec  e8656afcff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 005192f1  df3c24                 +fistp qword ptr [esp]
    app->getMemory<x86::reg64>(cpu.esp) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005192f4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005192f7  89423c                 -mov dword ptr [edx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 005192fa  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00519300  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00519303:
    // 00519303  d94220                 +fld dword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 00519306  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 0051930c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051930e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051930f  7309                   -jae 0x51931a
    if (!cpu.flags.cf)
    {
        goto L_0x0051931a;
    }
    // 00519311  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 00519317  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0051931a:
    // 0051931a  d94224                 +fld dword ptr [edx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */)));
    // 0051931d  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 00519323  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519325  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519326  7609                   -jbe 0x519331
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00519331;
    }
    // 00519328  8b81dc000000           -mov eax, dword ptr [ecx + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0051932e  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00519331:
    // 00519331  d94240                 +fld dword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 00519334  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 0051933a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051933c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051933d  764a                   -jbe 0x519389
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00519389;
    }
    // 0051933f  d981d4000000           -fld dword ptr [ecx + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    // 00519345  d86260                 -fsub dword ptr [edx + 0x60]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */));
    // 00519348  d94240                 -fld dword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 0051934b  d86260                 -fsub dword ptr [edx + 0x60]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */));
    // 0051934e  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519350  8b4258                 -mov eax, dword ptr [edx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    // 00519353  8b6a78                 -mov ebp, dword ptr [edx + 0x78]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 00519356  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00519358  29e8                   +sub eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051935a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0051935e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00519361  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00519364  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519366  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0051936a  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0051936d  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00519370  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519372  e8df69fcff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00519377  df3c24                 +fistp qword ptr [esp]
    app->getMemory<x86::reg64>(cpu.esp) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0051937a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051937d  894258                 -mov dword ptr [edx + 0x58], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 00519380  8b81d4000000           -mov eax, dword ptr [ecx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00519386  894240                 -mov dword ptr [edx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */) = cpu.eax;
L_0x00519389:
    // 00519389  d94244                 +fld dword ptr [edx + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(68) /* 0x44 */)));
    // 0051938c  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 00519392  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519394  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519395  764a                   -jbe 0x5193e1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005193e1;
    }
    // 00519397  d981dc000000           -fld dword ptr [ecx + 0xdc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    // 0051939d  d86224                 -fsub dword ptr [edx + 0x24]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */));
    // 005193a0  d94244                 -fld dword ptr [edx + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(68) /* 0x44 */)));
    // 005193a3  d86224                 -fsub dword ptr [edx + 0x24]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */));
    // 005193a6  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005193a8  8b425c                 -mov eax, dword ptr [edx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */);
    // 005193ab  8b7a3c                 -mov edi, dword ptr [edx + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 005193ae  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 005193b0  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005193b2  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 005193b6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005193b9  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 005193bc  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005193be  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 005193c2  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 005193c5  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 005193c8  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005193ca  e88769fcff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 005193cf  df3c24                 +fistp qword ptr [esp]
    app->getMemory<x86::reg64>(cpu.esp) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005193d2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005193d5  89425c                 -mov dword ptr [edx + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 005193d8  8b81dc000000           -mov eax, dword ptr [ecx + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 005193de  894244                 -mov dword ptr [edx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */) = cpu.eax;
L_0x005193e1:
    // 005193e1  d94240                 +fld dword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 005193e4  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 005193ea  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005193ec  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005193ed  7309                   -jae 0x5193f8
    if (!cpu.flags.cf)
    {
        goto L_0x005193f8;
    }
    // 005193ef  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 005193f5  894240                 -mov dword ptr [edx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */) = cpu.eax;
L_0x005193f8:
    // 005193f8  d94244                 +fld dword ptr [edx + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(68) /* 0x44 */)));
    // 005193fb  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 00519401  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519403  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519404  7309                   -jae 0x51940f
    if (!cpu.flags.cf)
    {
        goto L_0x0051940f;
    }
    // 00519406  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0051940c  894244                 -mov dword ptr [edx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */) = cpu.eax;
L_0x0051940f:
    // 0051940f  d94260                 +fld dword ptr [edx + 0x60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */)));
    // 00519412  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 00519418  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051941a  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051941b  734d                   -jae 0x51946a
    if (!cpu.flags.cf)
    {
        goto L_0x0051946a;
    }
    // 0051941d  d94240                 -fld dword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 00519420  d8a1d0000000           -fsub dword ptr [ecx + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */));
    // 00519426  d94240                 -fld dword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 00519429  d86260                 -fsub dword ptr [edx + 0x60]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */));
    // 0051942c  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051942e  8b4258                 -mov eax, dword ptr [edx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    // 00519431  8b5a78                 -mov ebx, dword ptr [edx + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 00519434  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00519436  29d8                   +sub eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00519438  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0051943c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051943f  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00519442  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519444  8b4258                 -mov eax, dword ptr [edx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    // 00519447  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0051944b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051944e  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00519451  dee1                   +fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00519453  e8fe68fcff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00519458  df3c24                 +fistp qword ptr [esp]
    app->getMemory<x86::reg64>(cpu.esp) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0051945b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051945e  894278                 -mov dword ptr [edx + 0x78], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00519461  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 00519467  894260                 -mov dword ptr [edx + 0x60], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x0051946a:
    // 0051946a  d94264                 +fld dword ptr [edx + 0x64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */)));
    // 0051946d  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 00519473  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519475  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519476  764a                   -jbe 0x5194c2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005194c2;
    }
    // 00519478  d981dc000000           -fld dword ptr [ecx + 0xdc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    // 0051947e  d86204                 -fsub dword ptr [edx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 00519481  d94264                 -fld dword ptr [edx + 0x64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */)));
    // 00519484  d86204                 -fsub dword ptr [edx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 00519487  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519489  8b427c                 -mov eax, dword ptr [edx + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */);
    // 0051948c  8b6a1c                 -mov ebp, dword ptr [edx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0051948f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00519491  29e8                   +sub eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00519493  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00519497  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051949a  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 0051949d  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051949f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 005194a3  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 005194a6  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 005194a9  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005194ab  e8a668fcff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 005194b0  df3c24                 +fistp qword ptr [esp]
    app->getMemory<x86::reg64>(cpu.esp) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005194b3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005194b6  89427c                 -mov dword ptr [edx + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 005194b9  8b81dc000000           -mov eax, dword ptr [ecx + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 005194bf  894264                 -mov dword ptr [edx + 0x64], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */) = cpu.eax;
L_0x005194c2:
    // 005194c2  d94260                 +fld dword ptr [edx + 0x60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */)));
    // 005194c5  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 005194cb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005194cd  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005194ce  7609                   -jbe 0x5194d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005194d9;
    }
    // 005194d0  8b81d4000000           -mov eax, dword ptr [ecx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 005194d6  894260                 -mov dword ptr [edx + 0x60], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x005194d9:
    // 005194d9  d94264                 +fld dword ptr [edx + 0x64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */)));
    // 005194dc  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 005194e2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005194e4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005194e5  7259                   -jb 0x519540
    if (cpu.flags.cf)
    {
        goto L_0x00519540;
    }
    // 005194e7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005194ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005194eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005194ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005194ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005194ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005194ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005194f0:
    // 005194f0  d94220                 -fld dword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 005194f3  d8a1d0000000           -fsub dword ptr [ecx + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */));
    // 005194f9  d94220                 -fld dword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 005194fc  d822                   -fsub dword ptr [edx]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx));
    // 005194fe  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519500  8b4238                 -mov eax, dword ptr [edx + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 00519503  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00519506  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00519508  29d8                   +sub eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051950a  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0051950e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00519511  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00519514  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519516  8b4238                 -mov eax, dword ptr [edx + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 00519519  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0051951d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00519520  df2c24                 +fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00519523  dee1                   +fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00519525  e82c68fcff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0051952a  df3c24                 +fistp qword ptr [esp]
    app->getMemory<x86::reg64>(cpu.esp) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0051952d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00519530  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00519533  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 00519539  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0051953b  e98bfcffff             -jmp 0x5191cb
    goto L_0x005191cb;
L_0x00519540:
    // 00519540  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00519546  894264                 -mov dword ptr [edx + 0x64], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00519549  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051954c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051954d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051954e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051954f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519550  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519551  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_519560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00519560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00519561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00519562  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00519563  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00519565  80b8bc00000000         +cmp byte ptr [eax + 0xbc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(188) /* 0xbc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051956c  7533                   -jne 0x5195a1
    if (!cpu.flags.zf)
    {
        goto L_0x005195a1;
    }
    // 0051956e  837a5400               +cmp dword ptr [edx + 0x54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00519572  742d                   -je 0x5195a1
    if (cpu.flags.zf)
    {
        goto L_0x005195a1;
    }
L_0x00519574:
    // 00519574  8b1d8c715600           -mov ebx, dword ptr [0x56718c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 0051957a  8b4254                 -mov eax, dword ptr [edx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 0051957d  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00519580  8b0d8c715600           -mov ecx, dword ptr [0x56718c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 00519586  8b1d5c905600           -mov ebx, dword ptr [0x56905c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5673052) /* 0x56905c */);
    // 0051958c  a160905600             -mov eax, dword ptr [0x569060]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */);
    // 00519591  8b1558905600           -mov edx, dword ptr [0x569058]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5673048) /* 0x569058 */);
    // 00519597  c1f802                 +sar eax, 2
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
    // 0051959a  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051959d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051959e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051959f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005195a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005195a1:
    // 005195a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005195a3  e8e8bf0000             -call 0x525590
    cpu.esp -= 4;
    sub_525590(app, cpu);
    if (cpu.terminate) return;
    // 005195a8  ebca                   -jmp 0x519574
    goto L_0x00519574;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_5195b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005195b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005195b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005195b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005195b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005195b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005195b5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 005195b8  8b1d60905600           -mov ebx, dword ptr [0x569060]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */);
    // 005195be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005195c0  db4010                 -fild dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))));
    // 005195c3  d888c8000000           -fmul dword ptr [eax + 0xc8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(200) /* 0xc8 */));
    // 005195c9  8b1554905600           -mov edx, dword ptr [0x569054]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5673044) /* 0x569054 */);
    // 005195cf  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005195d2  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005195d6  39d0                   +cmp eax, edx
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
    // 005195d8  0f8fc6010000           -jg 0x5197a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005197a4;
    }
L_0x005195de:
    // 005195de  8b1d60905600           -mov ebx, dword ptr [0x569060]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */);
    // 005195e4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005195e6  a158905600             -mov eax, dword ptr [0x569058]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5673048) /* 0x569058 */);
    // 005195eb  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 005195ee  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005195f0  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 005195f4  c7426c58ff7f3f         -mov dword ptr [edx + 0x6c], 0x3f7fff58
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */) = 1065353048 /*0x3f7fff58*/;
    // 005195fb  894268                 -mov dword ptr [edx + 0x68], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 005195fe  8b426c                 -mov eax, dword ptr [edx + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 00519601  89424c                 -mov dword ptr [edx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00519604  d9424c                 -fld dword ptr [edx + 0x4c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(76) /* 0x4c */)));
    // 00519607  8b4268                 -mov eax, dword ptr [edx + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(104) /* 0x68 */);
    // 0051960a  894248                 -mov dword ptr [edx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0051960d  d9522c                 -fst dword ptr [edx + 0x2c]
    app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    // 00519610  8b4248                 -mov eax, dword ptr [edx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00519613  894228                 -mov dword ptr [edx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00519616  d95a0c                 -fstp dword ptr [edx + 0xc]
    app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519619  8b4228                 -mov eax, dword ptr [edx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 0051961c  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051961f  8b415c                 -mov eax, dword ptr [ecx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */);
    // 00519622  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00519625  8b4160                 -mov eax, dword ptr [ecx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */);
    // 00519628  894230                 -mov dword ptr [edx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0051962b  8b4164                 -mov eax, dword ptr [ecx + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    // 0051962e  894250                 -mov dword ptr [edx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00519631  8b4168                 -mov eax, dword ptr [ecx + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */);
    // 00519634  c7427400000000         -mov dword ptr [edx + 0x74], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 0051963b  894270                 -mov dword ptr [edx + 0x70], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 0051963e  8b4274                 -mov eax, dword ptr [edx + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 00519641  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00519645  894254                 -mov dword ptr [edx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 00519648  d9442438               -fld dword ptr [esp + 0x38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */)));
    // 0051964c  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0051964e  894234                 -mov dword ptr [edx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00519651  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00519653  d9442440               -fld dword ptr [esp + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 00519657  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00519659  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 0051965b  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0051965e  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00519660  d8e3                   -fsub st(3)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(3));
    // 00519662  d981c0000000           -fld dword ptr [ecx + 0xc0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(192) /* 0xc0 */)));
    // 00519668  decc                   -fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051966a  d981c0000000           -fld dword ptr [ecx + 0xc0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(192) /* 0xc0 */)));
    // 00519670  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00519672  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00519674  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 00519678  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0051967c  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051967e  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00519682  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00519684  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519688  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051968c  8b7c2454               -mov edi, dword ptr [esp + 0x54]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00519690  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00519693  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00519697  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00519699  d844243c               -fadd dword ptr [esp + 0x3c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */));
    // 0051969d  894278                 -mov dword ptr [edx + 0x78], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 005196a0  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 005196a2  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 005196a5  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 005196a9  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 005196ab  89423c                 -mov dword ptr [edx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 005196ae  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 005196b2  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 005196b5  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 005196b9  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005196bb  d8442434               -fadd dword ptr [esp + 0x34]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */));
    // 005196bf  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 005196c1  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005196c3  dec5                   -faddp st(5)
    cpu.fpu.st(5) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005196c5  894258                 -mov dword ptr [edx + 0x58], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 005196c8  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 005196ca  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 005196cc  d95264                 -fst dword ptr [edx + 0x64]
    app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */) = float(cpu.fpu.st(0));
    // 005196cf  d95a44                 -fstp dword ptr [edx + 0x44]
    app->getMemory<float>(cpu.edx + x86::reg32(68) /* 0x44 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005196d2  8b7224                 -mov esi, dword ptr [edx + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 005196d5  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 005196d8  894238                 -mov dword ptr [edx + 0x38], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 005196db  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 005196df  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005196e1  d8c5                   -fadd st(5)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(5));
    // 005196e3  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 005196e5  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 005196e7  dec5                   -faddp st(5)
    cpu.fpu.st(5) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005196e9  89427c                 -mov dword ptr [edx + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 005196ec  d8c2                   -fadd st(2)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(2));
    // 005196ee  89425c                 -mov dword ptr [edx + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 005196f1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005196f3  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005196f5  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 005196f7  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005196f9  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 005196fb  d95a20                 -fstp dword ptr [edx + 0x20]
    app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005196fe  d95a60                 -fstp dword ptr [edx + 0x60]
    app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519701  d95a40                 -fstp dword ptr [edx + 0x40]
    app->getMemory<float>(cpu.edx + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519704  f681cc00000002         +test byte ptr [ecx + 0xcc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(204) /* 0xcc */) & 2 /*0x2*/));
    // 0051970b  0f8409020000           -je 0x51991a
    if (cpu.flags.zf)
    {
        goto L_0x0051991a;
    }
    // 00519711  d902                   +fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00519713  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 00519719  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051971b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051971c  0f868f000000           -jbe 0x5197b1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005197b1;
    }
L_0x00519722:
    // 00519722  d902                   +fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00519724  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 0051972a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051972c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051972d  0f869f010000           -jbe 0x5198d2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005198d2;
    }
L_0x00519733:
    // 00519733  d94220                 +fld dword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 00519736  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 0051973c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051973e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051973f  0f86e9010000           -jbe 0x51992e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051992e;
    }
L_0x00519745:
    // 00519745  d94240                 +fld dword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 00519748  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 0051974e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519750  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519751  0f860f020000           -jbe 0x519966
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00519966;
    }
L_0x00519757:
    // 00519757  d94260                 +fld dword ptr [edx + 0x60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */)));
    // 0051975a  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 00519760  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519762  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519763  772e                   -ja 0x519793
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519793;
    }
    // 00519765  d94260                 +fld dword ptr [edx + 0x60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */)));
    // 00519768  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 0051976e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519770  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519771  7220                   -jb 0x519793
    if (cpu.flags.cf)
    {
        goto L_0x00519793;
    }
    // 00519773  d94264                 +fld dword ptr [edx + 0x64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */)));
    // 00519776  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 0051977c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051977e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051977f  7712                   -ja 0x519793
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519793;
    }
    // 00519781  d94264                 +fld dword ptr [edx + 0x64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */)));
    // 00519784  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 0051978a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051978c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051978d  0f8374010000           -jae 0x519907
    if (!cpu.flags.cf)
    {
        goto L_0x00519907;
    }
L_0x00519793:
    // 00519793  891d60905600           -mov dword ptr [0x569060], ebx
    app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */) = cpu.ebx;
    // 00519799  83c414                 +add esp, 0x14
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
    // 0051979c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051979d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051979e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051979f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005197a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005197a1  c22c00                 -ret 0x2c
    cpu.esp += 4+44 /*0x2c*/;
    return;
L_0x005197a4:
    // 005197a4  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 005197a7  e8d4f8ffff             -call 0x519080
    cpu.esp -= 4;
    sub_519080(app, cpu);
    if (cpu.terminate) return;
    // 005197ac  e92dfeffff             -jmp 0x5195de
    goto L_0x005195de;
L_0x005197b1:
    // 005197b1  d902                   +fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005197b3  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 005197b9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005197bb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005197bc  0f8260ffffff           -jb 0x519722
    if (cpu.flags.cf)
    {
        goto L_0x00519722;
    }
    // 005197c2  d94204                 +fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005197c5  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 005197cb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005197cd  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005197ce  0f874effffff           -ja 0x519722
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519722;
    }
    // 005197d4  d94204                 +fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005197d7  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 005197dd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005197df  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005197e0  0f823cffffff           -jb 0x519722
    if (cpu.flags.cf)
    {
        goto L_0x00519722;
    }
    // 005197e6  d94220                 +fld dword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 005197e9  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 005197ef  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005197f1  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005197f2  0f872affffff           -ja 0x519722
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519722;
    }
    // 005197f8  d94220                 +fld dword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 005197fb  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 00519801  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519803  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519804  0f8218ffffff           -jb 0x519722
    if (cpu.flags.cf)
    {
        goto L_0x00519722;
    }
    // 0051980a  d94224                 +fld dword ptr [edx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */)));
    // 0051980d  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 00519813  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519815  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519816  0f8706ffffff           -ja 0x519722
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519722;
    }
    // 0051981c  d94224                 +fld dword ptr [edx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */)));
    // 0051981f  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 00519825  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519827  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519828  0f82f4feffff           -jb 0x519722
    if (cpu.flags.cf)
    {
        goto L_0x00519722;
    }
    // 0051982e  d94240                 +fld dword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 00519831  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 00519837  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519839  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051983a  0f87e2feffff           -ja 0x519722
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519722;
    }
    // 00519840  d94240                 +fld dword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 00519843  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 00519849  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051984b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051984c  0f82d0feffff           -jb 0x519722
    if (cpu.flags.cf)
    {
        goto L_0x00519722;
    }
    // 00519852  d94244                 +fld dword ptr [edx + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(68) /* 0x44 */)));
    // 00519855  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 0051985b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051985d  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051985e  0f87befeffff           -ja 0x519722
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519722;
    }
    // 00519864  d94244                 +fld dword ptr [edx + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(68) /* 0x44 */)));
    // 00519867  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 0051986d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051986f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519870  0f82acfeffff           -jb 0x519722
    if (cpu.flags.cf)
    {
        goto L_0x00519722;
    }
    // 00519876  d94260                 +fld dword ptr [edx + 0x60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */)));
    // 00519879  d899d4000000           +fcomp dword ptr [ecx + 0xd4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(212) /* 0xd4 */)));
    cpu.fpu.pop();
    // 0051987f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519881  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519882  0f879afeffff           -ja 0x519722
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519722;
    }
    // 00519888  d94260                 +fld dword ptr [edx + 0x60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */)));
    // 0051988b  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 00519891  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519893  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519894  0f8288feffff           -jb 0x519722
    if (cpu.flags.cf)
    {
        goto L_0x00519722;
    }
    // 0051989a  d94264                 +fld dword ptr [edx + 0x64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */)));
    // 0051989d  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 005198a3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005198a5  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005198a6  0f8776feffff           -ja 0x519722
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519722;
    }
    // 005198ac  d94264                 +fld dword ptr [edx + 0x64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */)));
    // 005198af  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 005198b5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005198b7  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005198b8  0f8264feffff           -jb 0x519722
    if (cpu.flags.cf)
    {
        goto L_0x00519722;
    }
    // 005198be  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005198c1  891d60905600           -mov dword ptr [0x569060], ebx
    app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */) = cpu.ebx;
    // 005198c7  83c414                 +add esp, 0x14
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
    // 005198ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005198cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005198cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005198cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005198ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005198cf  c22c00                 -ret 0x2c
    cpu.esp += 4+44 /*0x2c*/;
    return;
L_0x005198d2:
    // 005198d2  d902                   +fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005198d4  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 005198da  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005198dc  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005198dd  0f8250feffff           -jb 0x519733
    if (cpu.flags.cf)
    {
        goto L_0x00519733;
    }
    // 005198e3  d94204                 +fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005198e6  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 005198ec  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005198ee  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005198ef  0f873efeffff           -ja 0x519733
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519733;
    }
    // 005198f5  d94204                 +fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005198f8  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 005198fe  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519900  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519901  0f822cfeffff           -jb 0x519733
    if (cpu.flags.cf)
    {
        goto L_0x00519733;
    }
L_0x00519907:
    // 00519907  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00519909  891d60905600           -mov dword ptr [0x569060], ebx
    app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */) = cpu.ebx;
    // 0051990f  e89cf8ffff             -call 0x5191b0
    cpu.esp -= 4;
    sub_5191b0(app, cpu);
    if (cpu.terminate) return;
    // 00519914  8b1d60905600           -mov ebx, dword ptr [0x569060]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */);
L_0x0051991a:
    // 0051991a  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051991d  891d60905600           -mov dword ptr [0x569060], ebx
    app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */) = cpu.ebx;
    // 00519923  83c414                 +add esp, 0x14
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
    // 00519926  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519927  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519928  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519929  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051992a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051992b  c22c00                 -ret 0x2c
    cpu.esp += 4+44 /*0x2c*/;
    return;
L_0x0051992e:
    // 0051992e  d94220                 +fld dword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 00519931  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 00519937  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519939  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051993a  0f8205feffff           -jb 0x519745
    if (cpu.flags.cf)
    {
        goto L_0x00519745;
    }
    // 00519940  d94224                 +fld dword ptr [edx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */)));
    // 00519943  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 00519949  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051994b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051994c  0f87f3fdffff           -ja 0x519745
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519745;
    }
    // 00519952  d94224                 +fld dword ptr [edx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */)));
    // 00519955  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 0051995b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051995d  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051995e  0f82e1fdffff           -jb 0x519745
    if (cpu.flags.cf)
    {
        goto L_0x00519745;
    }
    // 00519964  eba1                   -jmp 0x519907
    goto L_0x00519907;
L_0x00519966:
    // 00519966  d94240                 +fld dword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 00519969  d899d0000000           +fcomp dword ptr [ecx + 0xd0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(208) /* 0xd0 */)));
    cpu.fpu.pop();
    // 0051996f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519971  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519972  0f82dffdffff           -jb 0x519757
    if (cpu.flags.cf)
    {
        goto L_0x00519757;
    }
    // 00519978  d94244                 +fld dword ptr [edx + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(68) /* 0x44 */)));
    // 0051997b  d899dc000000           +fcomp dword ptr [ecx + 0xdc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(220) /* 0xdc */)));
    cpu.fpu.pop();
    // 00519981  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519983  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519984  0f87cdfdffff           -ja 0x519757
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00519757;
    }
    // 0051998a  d94244                 +fld dword ptr [edx + 0x44]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(68) /* 0x44 */)));
    // 0051998d  d899d8000000           +fcomp dword ptr [ecx + 0xd8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(216) /* 0xd8 */)));
    cpu.fpu.pop();
    // 00519993  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519995  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519996  0f82bbfdffff           -jb 0x519757
    if (cpu.flags.cf)
    {
        goto L_0x00519757;
    }
    // 0051999c  e966ffffff             -jmp 0x519907
    goto L_0x00519907;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_5199b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005199b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005199b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005199b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005199b3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005199b5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005199b7  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 005199b9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005199bb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005199bd  7436                   -je 0x5199f5
    if (cpu.flags.zf)
    {
        goto L_0x005199f5;
    }
L_0x005199bf:
    // 005199bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005199c1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 005199c3  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 005199c6  8d1c07                 -lea ebx, [edi + eax]
    cpu.ebx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 005199c9  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 005199ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005199d0  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 005199d4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 005199d6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 005199dd  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 005199df  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 005199e1  29c1                   +sub ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005199e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005199e5  7414                   -je 0x5199fb
    if (cpu.flags.zf)
    {
        goto L_0x005199fb;
    }
    // 005199e7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005199e9  7e04                   -jle 0x5199ef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005199ef;
    }
    // 005199eb  4a                     -dec edx
    (cpu.edx)--;
    // 005199ec  8d3c33                 -lea edi, [ebx + esi]
    cpu.edi = x86::reg32(cpu.ebx + cpu.esi * 1);
L_0x005199ef:
    // 005199ef  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 005199f1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005199f3  75ca                   -jne 0x5199bf
    if (!cpu.flags.zf)
    {
        goto L_0x005199bf;
    }
L_0x005199f5:
    // 005199f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005199f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005199f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005199f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005199fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005199fb:
    // 005199fb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005199fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005199fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005199ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519a00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_519a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00519a10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00519a11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00519a12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00519a13  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00519a15  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00519a17  8b7848                 -mov edi, dword ptr [eax + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00519a1a  8b4844                 -mov ecx, dword ptr [eax + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00519a1d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00519a1f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00519a21  7e15                   -jle 0x519a38
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00519a38;
    }
    // 00519a23  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00519a25:
    // 00519a25  663b5802               +cmp bx, word ptr [eax + 2]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00519a29  7505                   -jne 0x519a30
    if (!cpu.flags.zf)
    {
        goto L_0x00519a30;
    }
    // 00519a2b  663b30                 +cmp si, word ptr [eax]
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00519a2e  740e                   -je 0x519a3e
    if (cpu.flags.zf)
    {
        goto L_0x00519a3e;
    }
L_0x00519a30:
    // 00519a30  42                     -inc edx
    (cpu.edx)++;
    // 00519a31  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00519a34  39ca                   +cmp edx, ecx
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
    // 00519a36  7ced                   -jl 0x519a25
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00519a25;
    }
L_0x00519a38:
    // 00519a38  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00519a3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519a3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519a3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519a3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00519a3e:
    // 00519a3e  8b4001                 -mov eax, dword ptr [eax + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00519a41  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00519a44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519a45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519a46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519a47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_519a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00519a50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00519a51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00519a52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00519a53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00519a54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00519a55  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00519a57  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00519a59  8b5028                 -mov edx, dword ptr [eax + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00519a5c  8b7830                 -mov edi, dword ptr [eax + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00519a5f  83fa64                 +cmp edx, 0x64
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00519a62  7d2d                   -jge 0x519a91
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00519a91;
    }
    // 00519a64  b9ac075500             -mov ecx, 0x5507ac
    cpu.ecx = 5572524 /*0x5507ac*/;
    // 00519a69  bdbc075500             -mov ebp, 0x5507bc
    cpu.ebp = 5572540 /*0x5507bc*/;
    // 00519a6e  b860010000             -mov eax, 0x160
    cpu.eax = 352 /*0x160*/;
    // 00519a73  68d0075500             -push 0x5507d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572560 /*0x5507d0*/;
    cpu.esp -= 4;
    // 00519a78  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00519a7e  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 00519a84  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00519a89  e88275eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00519a8e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00519a91:
    // 00519a91  8d56e0                 -lea edx, [esi - 0x20]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 00519a94  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00519a9b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00519a9d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00519aa0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00519aa2  8d1407                 -lea edx, [edi + eax]
    cpu.edx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 00519aa5  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00519aaa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00519aac  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00519ab0  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00519ab2  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00519ab9  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00519abb  39f0                   +cmp eax, esi
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
    // 00519abd  7508                   -jne 0x519ac7
    if (!cpu.flags.zf)
    {
        goto L_0x00519ac7;
    }
    // 00519abf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00519ac1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519ac2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519ac3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519ac4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519ac5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519ac6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00519ac7:
    // 00519ac7  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 00519acc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00519ace  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00519ad0  8b5b20                 -mov ebx, dword ptr [ebx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 00519ad3  e8d8feffff             -call 0x5199b0
    cpu.esp -= 4;
    sub_5199b0(app, cpu);
    if (cpu.terminate) return;
    // 00519ad8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519ad9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519ada  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519adb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519adc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519add  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_519ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00519ae0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00519ae1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00519ae2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00519ae3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00519ae4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00519ae5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00519ae6  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00519ae9  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00519aed  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00519aef  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00519af2  8b4040                 -mov eax, dword ptr [eax + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00519af5  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00519af9  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00519afc  d9442448               -fld dword ptr [esp + 0x48]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */)));
    // 00519b00  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00519b04  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00519b07  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00519b0a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519b0b  db4604                 -fild dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */))));
    // 00519b0e  d88ec4000000           -fmul dword ptr [esi + 0xc4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(196) /* 0xc4 */));
    // 00519b14  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00519b16  db4608                 -fild dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */))));
    // 00519b19  d88ec4000000           -fmul dword ptr [esi + 0xc4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(196) /* 0xc4 */));
    // 00519b1f  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00519b23  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00519b27  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00519b2b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00519b2d  d8442448               -fadd dword ptr [esp + 0x48]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */));
    // 00519b31  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00519b33  d844244c               -fadd dword ptr [esp + 0x4c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(76) /* 0x4c */));
    // 00519b37  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00519b39  d95c2448               -fstp dword ptr [esp + 0x48]
    app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519b3d  d95c244c               -fstp dword ptr [esp + 0x4c]
    app->getMemory<float>(cpu.esp + x86::reg32(76) /* 0x4c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519b41  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00519b43  0f8432010000           -je 0x519c7b
    if (cpu.flags.zf)
    {
        goto L_0x00519c7b;
    }
L_0x00519b49:
    // 00519b49  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00519b4b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00519b4d  891560905600           -mov dword ptr [0x569060], edx
    app->getMemory<x86::reg32>(x86::reg32(5673056) /* 0x569060 */) = cpu.edx;
    // 00519b53  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00519b58  e8f3feffff             -call 0x519a50
    cpu.esp -= 4;
    sub_519a50(app, cpu);
    if (cpu.terminate) return;
    // 00519b5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00519b5f  0f8548010000           -jne 0x519cad
    if (!cpu.flags.zf)
    {
        goto L_0x00519cad;
    }
L_0x00519b65:
    // 00519b65  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00519b67  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00519b6b  ff542408               -call dword ptr [esp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00519b6f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00519b71  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00519b75  83f820                 +cmp eax, 0x20
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
    // 00519b78  0f8ee7010000           -jle 0x519d65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00519d65;
    }
    // 00519b7e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00519b80  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00519b82  e8c9feffff             -call 0x519a50
    cpu.esp -= 4;
    sub_519a50(app, cpu);
    if (cpu.terminate) return;
    // 00519b87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00519b89  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00519b8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00519b8d  0f844d010000           -je 0x519ce0
    if (cpu.flags.zf)
    {
        goto L_0x00519ce0;
    }
    // 00519b93  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00519b98  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00519b9b  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00519b9f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00519ba1  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00519ba8  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00519baa  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00519baf  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00519bb3  8d4206                 -lea eax, [edx + 6]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 00519bb6  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00519bba  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00519bbc  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00519bc3  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00519bc5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00519bc7  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00519bcc  0f85ea000000           -jne 0x519cbc
    if (!cpu.flags.zf)
    {
        goto L_0x00519cbc;
    }
L_0x00519bd2:
    // 00519bd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00519bd4  8a4503                 -mov al, byte ptr [ebp + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 00519bd7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00519bd8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00519bda  8a4502                 -mov al, byte ptr [ebp + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 00519bdd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00519bde  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00519bdf  660fbe450a             -movsx ax, byte ptr [ebp + 0xa]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(10) /* 0xa */)));
    // 00519be4  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00519be8  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00519bec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00519bed  df442438               -fild word ptr [esp + 0x38]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */))));
    // 00519bf1  d88ec8000000           -fmul dword ptr [esi + 0xc8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 00519bf7  ff742460               -push dword ptr [esp + 0x60]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    // 00519bfb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00519bfe  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519c01  660fbe4509             -movsx ax, byte ptr [ebp + 9]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(9) /* 0x9 */)));
    // 00519c06  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00519c0a  df442440               -fild word ptr [esp + 0x40]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(64) /* 0x40 */))));
    // 00519c0e  d88ec4000000           -fmul dword ptr [esi + 0xc4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(196) /* 0xc4 */));
    // 00519c14  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00519c17  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00519c19  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519c1c  8a4503                 -mov al, byte ptr [ebp + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 00519c1f  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00519c23  df442444               -fild word ptr [esp + 0x44]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(68) /* 0x44 */))));
    // 00519c27  d88ec8000000           -fmul dword ptr [esi + 0xc8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 00519c2d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00519c30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00519c32  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519c35  8a4502                 -mov al, byte ptr [ebp + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 00519c38  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00519c3c  df442448               -fild word ptr [esp + 0x48]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(72) /* 0x48 */))));
    // 00519c40  d88ec4000000           -fmul dword ptr [esi + 0xc4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(196) /* 0xc4 */));
    // 00519c46  83ec04                 +sub esp, 4
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
    // 00519c49  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519c4c  ff742470               -push dword ptr [esp + 0x70]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    cpu.esp -= 4;
    // 00519c50  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00519c52  ff742470               -push dword ptr [esp + 0x70]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    cpu.esp -= 4;
    // 00519c56  e855f9ffff             -call 0x5195b0
    cpu.esp -= 4;
    sub_5195b0(app, cpu);
    if (cpu.terminate) return;
    // 00519c5b  660fbe4508             -movsx ax, byte ptr [ebp + 8]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00519c60  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00519c64  df442428               +fild word ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 00519c68  d88ec4000000           +fmul dword ptr [esi + 0xc4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(196) /* 0xc4 */));
    // 00519c6e  d8442448               +fadd dword ptr [esp + 0x48]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */));
    // 00519c72  d95c2448               +fstp dword ptr [esp + 0x48]
    app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519c76  e9eafeffff             -jmp 0x519b65
    goto L_0x00519b65;
L_0x00519c7b:
    // 00519c7b  bfac075500             -mov edi, 0x5507ac
    cpu.edi = 5572524 /*0x5507ac*/;
    // 00519c80  bd04085500             -mov ebp, 0x550804
    cpu.ebp = 5572612 /*0x550804*/;
    // 00519c85  b885010000             -mov eax, 0x185
    cpu.eax = 389 /*0x185*/;
    // 00519c8a  6820085500             -push 0x550820
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572640 /*0x550820*/;
    cpu.esp -= 4;
    // 00519c8f  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 00519c95  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 00519c9b  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00519ca0  e86b73eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00519ca5  83c404                 +add esp, 4
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
    // 00519ca8  e99cfeffff             -jmp 0x519b49
    goto L_0x00519b49;
L_0x00519cad:
    // 00519cad  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00519cb0  c1f818                 +sar eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00519cb3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00519cb7  e9a9feffff             -jmp 0x519b65
    goto L_0x00519b65;
L_0x00519cbc:
    // 00519cbc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00519cbe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00519cc0  e84bfdffff             -call 0x519a10
    cpu.esp -= 4;
    sub_519a10(app, cpu);
    if (cpu.terminate) return;
    // 00519cc5  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00519cc9  db442424               +fild dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 00519ccd  d88ec4000000           +fmul dword ptr [esi + 0xc4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(196) /* 0xc4 */));
    // 00519cd3  d8442448               +fadd dword ptr [esp + 0x48]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */));
    // 00519cd7  d95c2448               +fstp dword ptr [esp + 0x48]
    app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519cdb  e9f2feffff             -jmp 0x519bd2
    goto L_0x00519bd2;
L_0x00519ce0:
    // 00519ce0  f686cc00000001         +test byte ptr [esi + 0xcc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(204) /* 0xcc */) & 1 /*0x1*/));
    // 00519ce7  0f8478feffff           -je 0x519b65
    if (cpu.flags.zf)
    {
        goto L_0x00519b65;
    }
    // 00519ced  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00519cf0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00519cf2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00519cf5  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00519cf7  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00519cf9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00519cfb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00519cfe  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00519d00  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00519d02  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00519d04  8b5634                 -mov edx, dword ptr [esi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 00519d07  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00519d0a  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00519d0d  8b5202                 -mov edx, dword ptr [edx + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00519d10  4b                     -dec ebx
    (cpu.ebx)--;
    // 00519d11  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00519d14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00519d15  4a                     -dec edx
    (cpu.edx)--;
    // 00519d16  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00519d17  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00519d18  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00519d19  ff742460               -push dword ptr [esp + 0x60]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    // 00519d1d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00519d1f  897c243c               -mov dword ptr [esp + 0x3c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edi;
    // 00519d23  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00519d25  db442440               -fild dword ptr [esp + 0x40]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */))));
    // 00519d29  83ec04                 +sub esp, 4
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
    // 00519d2c  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00519d30  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519d33  db442444               +fild dword ptr [esp + 0x44]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */))));
    // 00519d37  d95c2440               +fstp dword ptr [esp + 0x40]
    app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519d3b  ff742440               -push dword ptr [esp + 0x40]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    // 00519d3f  ff742470               -push dword ptr [esp + 0x70]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    cpu.esp -= 4;
    // 00519d43  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00519d45  ff742470               -push dword ptr [esp + 0x70]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    cpu.esp -= 4;
    // 00519d49  e862f8ffff             -call 0x5195b0
    cpu.esp -= 4;
    sub_5195b0(app, cpu);
    if (cpu.terminate) return;
    // 00519d4e  d986c4000000           +fld dword ptr [esi + 0xc4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(196) /* 0xc4 */)));
    // 00519d54  d84c2420               +fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00519d58  d8442448               +fadd dword ptr [esp + 0x48]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */));
    // 00519d5c  d95c2448               +fstp dword ptr [esp + 0x48]
    app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519d60  e900feffff             -jmp 0x519b65
    goto L_0x00519b65;
L_0x00519d65:
    // 00519d65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00519d67  0f84a4000000           -je 0x519e11
    if (cpu.flags.zf)
    {
        goto L_0x00519e11;
    }
    // 00519d6d  83f80a                 +cmp eax, 0xa
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
    // 00519d70  7535                   -jne 0x519da7
    if (!cpu.flags.zf)
    {
        goto L_0x00519da7;
    }
    // 00519d72  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00519d75  035614                 +add edx, dword ptr [esi + 0x14]
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00519d78  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00519d7c  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00519d80  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00519d84  db442424               +fild dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 00519d88  d88ec8000000           +fmul dword ptr [esi + 0xc8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 00519d8e  db442420               +fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 00519d92  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00519d94  d844244c               +fadd dword ptr [esp + 0x4c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(76) /* 0x4c */));
    // 00519d98  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00519d9a  d95c2448               +fstp dword ptr [esp + 0x48]
    app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519d9e  d95c244c               +fstp dword ptr [esp + 0x4c]
    app->getMemory<float>(cpu.esp + x86::reg32(76) /* 0x4c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519da2  e9befdffff             -jmp 0x519b65
    goto L_0x00519b65;
L_0x00519da7:
    // 00519da7  8b4e50                 -mov ecx, dword ptr [esi + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 00519daa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00519dac  751f                   -jne 0x519dcd
    if (!cpu.flags.zf)
    {
        goto L_0x00519dcd;
    }
L_0x00519dae:
    // 00519dae  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00519db2  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00519db6  db442420               +fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 00519dba  d88ec4000000           +fmul dword ptr [esi + 0xc4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(196) /* 0xc4 */));
    // 00519dc0  d8442448               +fadd dword ptr [esp + 0x48]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */));
    // 00519dc4  d95c2448               +fstp dword ptr [esp + 0x48]
    app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519dc8  e998fdffff             -jmp 0x519b65
    goto L_0x00519b65;
L_0x00519dcd:
    // 00519dcd  83f809                 +cmp eax, 9
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
    // 00519dd0  75dc                   -jne 0x519dae
    if (!cpu.flags.zf)
    {
        goto L_0x00519dae;
    }
    // 00519dd2  8b5e4c                 -mov ebx, dword ptr [esi + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 00519dd5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00519dd7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00519dd9  0f8e86fdffff           -jle 0x519b65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00519b65;
    }
    // 00519ddf  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x00519de1:
    // 00519de1  d9442448               +fld dword ptr [esp + 0x48]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(72) /* 0x48 */)));
    // 00519de5  db07                   +fild dword ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi))));
    // 00519de7  d95c241c               +fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00519deb  d85c241c               +fcomp dword ptr [esp + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 00519def  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00519df1  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00519df2  730d                   -jae 0x519e01
    if (!cpu.flags.cf)
    {
        goto L_0x00519e01;
    }
    // 00519df4  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00519df8  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00519dfc  e964fdffff             -jmp 0x519b65
    goto L_0x00519b65;
L_0x00519e01:
    // 00519e01  42                     -inc edx
    (cpu.edx)++;
    // 00519e02  8b4e4c                 -mov ecx, dword ptr [esi + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 00519e05  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00519e08  39ca                   +cmp edx, ecx
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
    // 00519e0a  7cd5                   -jl 0x519de1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00519de1;
    }
    // 00519e0c  e954fdffff             -jmp 0x519b65
    goto L_0x00519b65;
L_0x00519e11:
    // 00519e11  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00519e13  e848f7ffff             -call 0x519560
    cpu.esp -= 4;
    sub_519560(app, cpu);
    if (cpu.terminate) return;
    // 00519e18  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00519e1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519e1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519e1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519e1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519e1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519e20  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519e21  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_519e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00519e30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00519e31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00519e32  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00519e38  8d842424020000         -lea eax, [esp + 0x224]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(548) /* 0x224 */);
    // 00519e3f  8d9c2400020000         -lea ebx, [esp + 0x200]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00519e46  8b942420020000         -mov edx, dword ptr [esp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00519e4d  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 00519e54  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00519e56  e81958fcff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 00519e5b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00519e5d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00519e5e  ffb42420020000         -push dword ptr [esp + 0x220]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    cpu.esp -= 4;
    // 00519e65  ffb42420020000         -push dword ptr [esp + 0x220]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    cpu.esp -= 4;
    // 00519e6c  8b84241c020000         -mov eax, dword ptr [esp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */);
    // 00519e73  ffb42420020000         -push dword ptr [esp + 0x220]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    cpu.esp -= 4;
    // 00519e7a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00519e7c  e85ffcffff             -call 0x519ae0
    cpu.esp -= 4;
    sub_519ae0(app, cpu);
    if (cpu.terminate) return;
    // 00519e81  89942400020000         -mov dword ptr [esp + 0x200], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.edx;
    // 00519e88  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00519e8e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519e8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519e90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_519ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00519ea0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00519ea1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00519ea3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00519ea8  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00519ead  83f850                 +cmp eax, 0x50
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00519eb0  7313                   -jae 0x519ec5
    if (!cpu.flags.cf)
    {
        goto L_0x00519ec5;
    }
    // 00519eb2  83f803                 +cmp eax, 3
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
    // 00519eb5  733c                   -jae 0x519ef3
    if (!cpu.flags.cf)
    {
        goto L_0x00519ef3;
    }
    // 00519eb7  83f801                 +cmp eax, 1
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
    // 00519eba  7505                   -jne 0x519ec1
    if (!cpu.flags.zf)
    {
        goto L_0x00519ec1;
    }
L_0x00519ebc:
    // 00519ebc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00519ec1:
    // 00519ec1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00519ec3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519ec4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00519ec5:
    // 00519ec5  7623                   -jbe 0x519eea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00519eea;
    }
    // 00519ec7  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00519eca  7310                   -jae 0x519edc
    if (!cpu.flags.cf)
    {
        goto L_0x00519edc;
    }
    // 00519ecc  83f856                 +cmp eax, 0x56
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86 /*0x56*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00519ecf  72f0                   -jb 0x519ec1
    if (cpu.flags.cf)
    {
        goto L_0x00519ec1;
    }
    // 00519ed1  76e9                   -jbe 0x519ebc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00519ebc;
    }
    // 00519ed3  83f860                 +cmp eax, 0x60
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00519ed6  74e4                   -je 0x519ebc
    if (cpu.flags.zf)
    {
        goto L_0x00519ebc;
    }
    // 00519ed8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00519eda  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519edb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00519edc:
    // 00519edc  760c                   -jbe 0x519eea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00519eea;
    }
    // 00519ede  83f879                 +cmp eax, 0x79
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(121 /*0x79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00519ee1  72de                   -jb 0x519ec1
    if (cpu.flags.cf)
    {
        goto L_0x00519ec1;
    }
    // 00519ee3  76d7                   -jbe 0x519ebc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00519ebc;
    }
    // 00519ee5  83f87a                 +cmp eax, 0x7a
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
    // 00519ee8  75d7                   -jne 0x519ec1
    if (!cpu.flags.zf)
    {
        goto L_0x00519ec1;
    }
L_0x00519eea:
    // 00519eea  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00519eef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00519ef1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519ef2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00519ef3:
    // 00519ef3  76f5                   -jbe 0x519eea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00519eea;
    }
    // 00519ef5  83f840                 +cmp eax, 0x40
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
    // 00519ef8  72c7                   -jb 0x519ec1
    if (cpu.flags.cf)
    {
        goto L_0x00519ec1;
    }
    // 00519efa  76ee                   -jbe 0x519eea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00519eea;
    }
    // 00519efc  83f844                 +cmp eax, 0x44
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00519eff  74bb                   -je 0x519ebc
    if (cpu.flags.zf)
    {
        goto L_0x00519ebc;
    }
    // 00519f01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00519f03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519f04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_519f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00519f10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00519f11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00519f12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00519f13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00519f14  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00519f17  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00519f19  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00519f1b  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00519f1e  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00519f20  8b158c715600           -mov edx, dword ptr [0x56718c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 00519f26  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00519f29  b8e0000000             -mov eax, 0xe0
    cpu.eax = 224 /*0xe0*/;
    // 00519f2e  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00519f31  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00519f33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00519f35  750a                   -jne 0x519f41
    if (!cpu.flags.zf)
    {
        goto L_0x00519f41;
    }
    // 00519f37  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00519f39  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00519f3c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519f3d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519f3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519f3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00519f40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00519f41:
    // 00519f41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00519f42  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00519f43  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00519f48  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00519f4a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00519f4c  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00519f4e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00519f50  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00519f57  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00519f59  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00519f5b  3d00544e46             +cmp eax, 0x464e5400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1179538432 /*0x464e5400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00519f60  742f                   -je 0x519f91
    if (cpu.flags.zf)
    {
        goto L_0x00519f91;
    }
    // 00519f62  ba40085500             -mov edx, 0x550840
    cpu.edx = 5572672 /*0x550840*/;
    // 00519f67  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00519f68  b950085500             -mov ecx, 0x550850
    cpu.ecx = 5572688 /*0x550850*/;
    // 00519f6d  bb6d000000             -mov ebx, 0x6d
    cpu.ebx = 109 /*0x6d*/;
    // 00519f72  685c085500             -push 0x55085c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5572700 /*0x55085c*/;
    cpu.esp -= 4;
    // 00519f77  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00519f7d  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00519f83  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00519f89  e88270eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00519f8e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00519f91:
    // 00519f91  bbe0000000             -mov ebx, 0xe0
    cpu.ebx = 224 /*0xe0*/;
    // 00519f96  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00519f98  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00519f9a  e8a166fcff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00519f9f  c7462864000000         -mov dword ptr [esi + 0x28], 0x64
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 100 /*0x64*/;
    // 00519fa6  8b470d                 -mov eax, dword ptr [edi + 0xd]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 00519fa9  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00519fac  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00519faf  8b470e                 -mov eax, dword ptr [edi + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 00519fb2  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00519fb5  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00519fb8  8b470f                 -mov eax, dword ptr [edi + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(15) /* 0xf */);
    // 00519fbb  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00519fbe  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00519fc1  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00519fc4  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00519fc7  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00519fca  8b5710                 -mov edx, dword ptr [edi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00519fcd  8b470f                 -mov eax, dword ptr [edi + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(15) /* 0xf */);
    // 00519fd0  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00519fd3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00519fd6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00519fd8  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00519fdb  8b5710                 -mov edx, dword ptr [edi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00519fde  8b470f                 -mov eax, dword ptr [edi + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(15) /* 0xf */);
    // 00519fe1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00519fe4  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00519fe7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00519fe9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00519feb  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00519fee  668b470a               -mov ax, word ptr [edi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 00519ff2  c7464800000000         -mov dword ptr [esi + 0x48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 00519ff9  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00519ffc  896e2c                 -mov dword ptr [esi + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 00519fff  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051a003  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0051a006  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0051a009  8d1407                 -lea edx, [edi + eax]
    cpu.edx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0051a00c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051a010  895630                 -mov dword ptr [esi + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0051a013  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051a017  e884feffff             -call 0x519ea0
    cpu.esp -= 4;
    sub_519ea0(app, cpu);
    if (cpu.terminate) return;
    // 0051a01c  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0051a01f  8b5202                 -mov edx, dword ptr [edx + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0051a022  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051a026  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0051a029  e872feffff             -call 0x519ea0
    cpu.esp -= 4;
    sub_519ea0(app, cpu);
    if (cpu.terminate) return;
    // 0051a02e  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0051a031  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0051a034  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0051a036  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0051a039  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0051a03c  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0051a03f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0051a042  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051a045  83f802                 +cmp eax, 2
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
    // 0051a048  0f85de000000           -jne 0x51a12c
    if (!cpu.flags.zf)
    {
        goto L_0x0051a12c;
    }
L_0x0051a04e:
    // 0051a04e  c7464070565200         -mov dword ptr [esi + 0x40], 0x525670
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = 5396080 /*0x525670*/;
L_0x0051a055:
    // 0051a055  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a057  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051a059  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051a05b  e820bb0000             -call 0x525b80
    cpu.esp -= 4;
    sub_525b80(app, cpu);
    if (cpu.terminate) return;
    // 0051a060  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a062  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051a064  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051a066  e855b70000             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 0051a06b  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0051a070  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a072  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051a074  e847b70000             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 0051a079  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0051a07e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a080  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051a082  e839b70000             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 0051a087  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 0051a08c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a08e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051a090  e82bb70000             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 0051a095  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0051a09a  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0051a09f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a0a1  e81ab70000             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 0051a0a6  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0051a0ab  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0051a0b0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a0b2  e809b70000             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 0051a0b7  bbffffff00             -mov ebx, 0xffffff
    cpu.ebx = 16777215 /*0xffffff*/;
    // 0051a0bc  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 0051a0c1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a0c3  e8f8b60000             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 0051a0c8  bb000000ff             -mov ebx, 0xff000000
    cpu.ebx = 4278190080 /*0xff000000*/;
    // 0051a0cd  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 0051a0d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a0d4  e8e7b60000             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 0051a0d9  bb000000ff             -mov ebx, 0xff000000
    cpu.ebx = 4278190080 /*0xff000000*/;
    // 0051a0de  ba0b000000             -mov edx, 0xb
    cpu.edx = 11 /*0xb*/;
    // 0051a0e3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a0e5  e8d6b60000             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 0051a0ea  ba41000000             -mov edx, 0x41
    cpu.edx = 65 /*0x41*/;
    // 0051a0ef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a0f1  c686bc00000001         -mov byte ptr [esi + 0xbc], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(188) /* 0xbc */) = 1 /*0x1*/;
    // 0051a0f8  e853f9ffff             -call 0x519a50
    cpu.esp -= 4;
    sub_519a50(app, cpu);
    if (cpu.terminate) return;
    // 0051a0fd  8b7807                 -mov edi, dword ptr [eax + 7]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0051a100  0fb66803               -movzx ebp, byte ptr [eax + 3]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 0051a104  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 0051a107  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0051a109  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0051a10c  29ef                   -sub edi, ebp
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0051a10e  897e14                 -mov dword ptr [esi + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0051a111  0fb67803               -movzx edi, byte ptr [eax + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 0051a115  8b4007                 -mov eax, dword ptr [eax + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0051a118  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0051a11b  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051a11d  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0051a120  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a121  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a122  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a124  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051a127  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a128  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a129  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a12a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a12b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a12c:
    // 0051a12c  817e20ff000000         +cmp dword ptr [esi + 0x20], 0xff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a133  0f8f15ffffff           -jg 0x51a04e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051a04e;
    }
    // 0051a139  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0051a13e  8d4520                 -lea eax, [ebp + 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0051a141  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0051a145  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051a147  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0051a14e  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0051a150  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a155  0f87f3feffff           -ja 0x51a04e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051a04e;
    }
    // 0051a15b  c7464030565200         -mov dword ptr [esi + 0x40], 0x525630
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = 5396016 /*0x525630*/;
    // 0051a162  e9eefeffff             -jmp 0x51a055
    goto L_0x0051a055;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_51a170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a170  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051a171  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051a172  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051a174  e887b40000             -call 0x525600
    cpu.esp -= 4;
    sub_525600(app, cpu);
    if (cpu.terminate) return;
    // 0051a179  8b0d8c715600           -mov ecx, dword ptr [0x56718c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 0051a17f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051a181  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051a184  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a185  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a186  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_51a188(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a188  f644240b80             +test byte ptr [esp + 0xb], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 128 /*0x80*/));
    // 0051a18d  7420                   -je 0x51a1af
    if (cpu.flags.zf)
    {
        goto L_0x0051a1af;
    }
    // 0051a18f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051a193  25ffffff7f             -and eax, 0x7fffffff
    cpu.eax &= x86::reg32(x86::sreg32(2147483647 /*0x7fffffff*/));
    // 0051a198  0b442404               +or eax, dword ptr [esp + 4]
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)))));
    // 0051a19c  7411                   -je 0x51a1af
    if (cpu.flags.zf)
    {
        goto L_0x0051a1af;
    }
    // 0051a19e  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0051a1a0  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0051a1a4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0051a1a8  e8afc3ffff             -call 0x51655c
    cpu.esp -= 4;
    sub_51655c(app, cpu);
    if (cpu.terminate) return;
    // 0051a1ad  eb06                   -jmp 0x51a1b5
    goto L_0x0051a1b5;
L_0x0051a1af:
    // 0051a1af  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0051a1b3  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
L_0x0051a1b5:
    // 0051a1b5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_51a1b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a1b8  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
    // 0051a1ba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051a1bb  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051a1bd  d9e4                   -ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 0051a1bf  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051a1c2  9b                     -wait 
    /*nothing*/;
    // 0051a1c3  dd7df8                 -fnstsw word ptr [ebp - 8]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.fpu.status.word;
    // 0051a1c6  9b                     -wait 
    /*nothing*/;
    // 0051a1c7  668745f8               -xchg word ptr [ebp - 8], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ax;
        cpu.ax = tmp;
    }
    // 0051a1cb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051a1cc  7319                   -jae 0x51a1e7
    if (!cpu.flags.cf)
    {
        goto L_0x0051a1e7;
    }
    // 0051a1ce  dd5df0                 -fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0051a1d1  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0051a1d4  3c03                   +cmp al, 3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051a1d6  7403                   -je 0x51a1db
    if (cpu.flags.zf)
    {
        goto L_0x0051a1db;
    }
    // 0051a1d8  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0051a1db:
    // 0051a1db  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0051a1de  e879c3ffff             -call 0x51655c
    cpu.esp -= 4;
    sub_51655c(app, cpu);
    if (cpu.terminate) return;
    // 0051a1e3  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0051a1e5  eb04                   -jmp 0x51a1eb
    goto L_0x0051a1eb;
L_0x0051a1e7:
    // 0051a1e7  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 0051a1e9  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
L_0x0051a1eb:
    // 0051a1eb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0051a1ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a1ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51a1ba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0051a1ba;
    // 0051a1b8  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_entry_0x0051a1ba:
    // 0051a1ba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051a1bb  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051a1bd  d9e4                   -ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 0051a1bf  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051a1c2  9b                     -wait 
    /*nothing*/;
    // 0051a1c3  dd7df8                 -fnstsw word ptr [ebp - 8]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.fpu.status.word;
    // 0051a1c6  9b                     -wait 
    /*nothing*/;
    // 0051a1c7  668745f8               -xchg word ptr [ebp - 8], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ax;
        cpu.ax = tmp;
    }
    // 0051a1cb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051a1cc  7319                   -jae 0x51a1e7
    if (!cpu.flags.cf)
    {
        goto L_0x0051a1e7;
    }
    // 0051a1ce  dd5df0                 -fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0051a1d1  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0051a1d4  3c03                   +cmp al, 3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051a1d6  7403                   -je 0x51a1db
    if (cpu.flags.zf)
    {
        goto L_0x0051a1db;
    }
    // 0051a1d8  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0051a1db:
    // 0051a1db  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0051a1de  e879c3ffff             -call 0x51655c
    cpu.esp -= 4;
    sub_51655c(app, cpu);
    if (cpu.terminate) return;
    // 0051a1e3  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0051a1e5  eb04                   -jmp 0x51a1eb
    goto L_0x0051a1eb;
L_0x0051a1e7:
    // 0051a1e7  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 0051a1e9  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
L_0x0051a1eb:
    // 0051a1eb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0051a1ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a1ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_51a1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a1f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051a1f1  ba9c0a5500             -mov edx, 0x550a9c
    cpu.edx = 5573276 /*0x550a9c*/;
    // 0051a1f6  e805000000             -call 0x51a200
    cpu.esp -= 4;
    sub_51a200(app, cpu);
    if (cpu.terminate) return;
    // 0051a1fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a1fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51a200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a200  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051a201  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051a202  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051a204  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051a206  e8a5050000             -call 0x51a7b0
    cpu.esp -= 4;
    sub_51a7b0(app, cpu);
    if (cpu.terminate) return;
    // 0051a20b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a20d  7508                   -jne 0x51a217
    if (!cpu.flags.zf)
    {
        goto L_0x0051a217;
    }
L_0x0051a20f:
    // 0051a20f  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0051a214  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a215  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a216  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a217:
    // 0051a217  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051a21d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051a21f  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051a221  e84a020000             -call 0x51a470
    cpu.esp -= 4;
    sub_51a470(app, cpu);
    if (cpu.terminate) return;
    // 0051a226  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051a228  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a22a  7405                   -je 0x51a231
    if (cpu.flags.zf)
    {
        goto L_0x0051a231;
    }
    // 0051a22c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051a22e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a22f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a230  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a231:
    // 0051a231  baac0a5500             -mov edx, 0x550aac
    cpu.edx = 5573292 /*0x550aac*/;
    // 0051a236  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051a238  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051a23a  e871050000             -call 0x51a7b0
    cpu.esp -= 4;
    sub_51a7b0(app, cpu);
    if (cpu.terminate) return;
    // 0051a23f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a241  74cc                   -je 0x51a20f
    if (cpu.flags.zf)
    {
        goto L_0x0051a20f;
    }
    // 0051a243  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051a249  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051a24b  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051a24d  e81e020000             -call 0x51a470
    cpu.esp -= 4;
    sub_51a470(app, cpu);
    if (cpu.terminate) return;
    // 0051a252  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051a254  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051a256  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a257  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a258  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51a260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a260  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051a261  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051a262  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051a263  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051a265  bab80a5500             -mov edx, 0x550ab8
    cpu.edx = 5573304 /*0x550ab8*/;
    // 0051a26a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051a26c  e83f050000             -call 0x51a7b0
    cpu.esp -= 4;
    sub_51a7b0(app, cpu);
    if (cpu.terminate) return;
    // 0051a271  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a273  7509                   -jne 0x51a27e
    if (!cpu.flags.zf)
    {
        goto L_0x0051a27e;
    }
    // 0051a275  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0051a27a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a27b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a27c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a27d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a27e:
    // 0051a27e  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051a284  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051a286  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051a288  e8e3010000             -call 0x51a470
    cpu.esp -= 4;
    sub_51a470(app, cpu);
    if (cpu.terminate) return;
    // 0051a28d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a28e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a28f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a290  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_51a2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a2a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051a2a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051a2a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051a2a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051a2a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051a2a5  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0051a2a8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051a2aa  bec00a5500             -mov esi, 0x550ac0
    cpu.esi = 5573312 /*0x550ac0*/;
    // 0051a2af  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0051a2b1  e8aaffffff             -call 0x51a260
    cpu.esp -= 4;
    sub_51a260(app, cpu);
    if (cpu.terminate) return;
    // 0051a2b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0051a2b7:
    // 0051a2b7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051a2b9  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051a2bb  3c00                   +cmp al, 0
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
    // 0051a2bd  7410                   -je 0x51a2cf
    if (cpu.flags.zf)
    {
        goto L_0x0051a2cf;
    }
    // 0051a2bf  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051a2c2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051a2c5  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051a2c8  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051a2cb  3c00                   +cmp al, 0
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
    // 0051a2cd  75e8                   -jne 0x51a2b7
    if (!cpu.flags.zf)
    {
        goto L_0x0051a2b7;
    }
L_0x0051a2cf:
    // 0051a2cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a2d0  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0051a2d2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051a2d4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0051a2d9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051a2da  2bc9                   +sub ecx, ecx
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
    // 0051a2dc  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051a2dd  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051a2df  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051a2e1  4f                     -dec edi
    (cpu.edi)--;
L_0x0051a2e2:
    // 0051a2e2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051a2e4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051a2e6  3c00                   +cmp al, 0
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
    // 0051a2e8  7410                   -je 0x51a2fa
    if (cpu.flags.zf)
    {
        goto L_0x0051a2fa;
    }
    // 0051a2ea  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051a2ed  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051a2f0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051a2f3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051a2f6  3c00                   +cmp al, 0
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
    // 0051a2f8  75e8                   -jne 0x51a2e2
    if (!cpu.flags.zf)
    {
        goto L_0x0051a2e2;
    }
L_0x0051a2fa:
    // 0051a2fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a2fb  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0051a2fd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051a2ff  e8ac040000             -call 0x51a7b0
    cpu.esp -= 4;
    sub_51a7b0(app, cpu);
    if (cpu.terminate) return;
    // 0051a304  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0051a307  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a308  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a309  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a30a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a30b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a30c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51a310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a310  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051a311  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051a312  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051a313  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0051a316  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051a318  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0051a31a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0051a31c  e83fffffff             -call 0x51a260
    cpu.esp -= 4;
    sub_51a260(app, cpu);
    if (cpu.terminate) return;
    // 0051a321  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0051a322:
    // 0051a322  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051a324  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051a326  3c00                   +cmp al, 0
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
    // 0051a328  7410                   -je 0x51a33a
    if (cpu.flags.zf)
    {
        goto L_0x0051a33a;
    }
    // 0051a32a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051a32d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051a330  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051a333  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051a336  3c00                   +cmp al, 0
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
    // 0051a338  75e8                   -jne 0x51a322
    if (!cpu.flags.zf)
    {
        goto L_0x0051a322;
    }
L_0x0051a33a:
    // 0051a33a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a33b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051a33d  7464                   -je 0x51a3a3
    if (cpu.flags.zf)
    {
        goto L_0x0051a3a3;
    }
    // 0051a33f  bec40a5500             -mov esi, 0x550ac4
    cpu.esi = 5573316 /*0x550ac4*/;
L_0x0051a344:
    // 0051a344  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0051a346  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051a347  2bc9                   +sub ecx, ecx
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
    // 0051a349  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051a34a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051a34c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051a34e  4f                     -dec edi
    (cpu.edi)--;
L_0x0051a34f:
    // 0051a34f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051a351  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051a353  3c00                   +cmp al, 0
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
    // 0051a355  7410                   -je 0x51a367
    if (cpu.flags.zf)
    {
        goto L_0x0051a367;
    }
    // 0051a357  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051a35a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051a35d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051a360  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051a363  3c00                   +cmp al, 0
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
    // 0051a365  75e8                   -jne 0x51a34f
    if (!cpu.flags.zf)
    {
        goto L_0x0051a34f;
    }
L_0x0051a367:
    // 0051a367  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a368  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0051a36a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051a36c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0051a371  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051a372  2bc9                   +sub ecx, ecx
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
    // 0051a374  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051a375  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051a377  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051a379  4f                     -dec edi
    (cpu.edi)--;
L_0x0051a37a:
    // 0051a37a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051a37c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051a37e  3c00                   +cmp al, 0
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
    // 0051a380  7410                   -je 0x51a392
    if (cpu.flags.zf)
    {
        goto L_0x0051a392;
    }
    // 0051a382  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051a385  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051a388  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051a38b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051a38e  3c00                   +cmp al, 0
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
    // 0051a390  75e8                   -jne 0x51a37a
    if (!cpu.flags.zf)
    {
        goto L_0x0051a37a;
    }
L_0x0051a392:
    // 0051a392  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a393  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0051a395  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051a397  e814040000             -call 0x51a7b0
    cpu.esp -= 4;
    sub_51a7b0(app, cpu);
    if (cpu.terminate) return;
    // 0051a39c  83c450                 +add esp, 0x50
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051a39f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a3a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a3a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a3a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a3a3:
    // 0051a3a3  bec80a5500             -mov esi, 0x550ac8
    cpu.esi = 5573320 /*0x550ac8*/;
    // 0051a3a8  eb9a                   -jmp 0x51a344
    goto L_0x0051a344;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_51a3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a3b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051a3b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051a3b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051a3b3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051a3b5  e8a6feffff             -call 0x51a260
    cpu.esp -= 4;
    sub_51a260(app, cpu);
    if (cpu.terminate) return;
    // 0051a3ba  bac00a5500             -mov edx, 0x550ac0
    cpu.edx = 5573312 /*0x550ac0*/;
    // 0051a3bf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051a3c1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051a3c3  e8e8030000             -call 0x51a7b0
    cpu.esp -= 4;
    sub_51a7b0(app, cpu);
    if (cpu.terminate) return;
    // 0051a3c8  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051a3ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051a3d0  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051a3d2  e899000000             -call 0x51a470
    cpu.esp -= 4;
    sub_51a470(app, cpu);
    if (cpu.terminate) return;
    // 0051a3d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a3d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a3d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a3da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_51a3e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a3e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051a3e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051a3e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051a3e3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051a3e5  e876feffff             -call 0x51a260
    cpu.esp -= 4;
    sub_51a260(app, cpu);
    if (cpu.terminate) return;
    // 0051a3ea  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0051a3ef  bacc0a5500             -mov edx, 0x550acc
    cpu.edx = 5573324 /*0x550acc*/;
    // 0051a3f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051a3f6  e8b5030000             -call 0x51a7b0
    cpu.esp -= 4;
    sub_51a7b0(app, cpu);
    if (cpu.terminate) return;
    // 0051a3fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a3fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a3fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a3fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51a400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a400  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051a401  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051a402  bbd40a5500             -mov ebx, 0x550ad4
    cpu.ebx = 5573332 /*0x550ad4*/;
    // 0051a407  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0051a40c  e8df110000             -call 0x51b5f0
    cpu.esp -= 4;
    sub_51b5f0(app, cpu);
    if (cpu.terminate) return;
    // 0051a411  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a412  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a413  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_51a420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051a421  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051a422  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051a424  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051a429  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051a42b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051a42e  c1e202                 +shl edx, 2
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
    // 0051a431  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0051a433  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0051a436  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051a438  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051a43a  e831000000             -call 0x51a470
    cpu.esp -= 4;
    sub_51a470(app, cpu);
    if (cpu.terminate) return;
    // 0051a43f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051a441  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a443  741e                   -je 0x51a463
    if (cpu.flags.zf)
    {
        goto L_0x0051a463;
    }
    // 0051a445  83f802                 +cmp eax, 2
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
    // 0051a448  7419                   -je 0x51a463
    if (cpu.flags.zf)
    {
        goto L_0x0051a463;
    }
    // 0051a44a  83f8ff                 +cmp eax, -1
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
    // 0051a44d  7414                   -je 0x51a463
    if (cpu.flags.zf)
    {
        goto L_0x0051a463;
    }
    // 0051a44f  83f801                 +cmp eax, 1
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
    // 0051a452  740a                   -je 0x51a45e
    if (cpu.flags.zf)
    {
        goto L_0x0051a45e;
    }
    // 0051a454  83f805                 +cmp eax, 5
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
    // 0051a457  7405                   -je 0x51a45e
    if (cpu.flags.zf)
    {
        goto L_0x0051a45e;
    }
    // 0051a459  83f80a                 +cmp eax, 0xa
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
    // 0051a45c  7c0a                   -jl 0x51a468
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a468;
    }
L_0x0051a45e:
    // 0051a45e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051a460  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a461  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a462  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a463:
    // 0051a463  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a465  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a466  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a467  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a468:
    // 0051a468  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0051a46d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a46e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a46f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51a470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051a471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051a472  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051a473  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051a474  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051a475  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0051a478  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0051a47c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051a47e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051a480  8b1db8aa5600           -mov ebx, dword ptr [0x56aab8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5679800) /* 0x56aab8 */);
    // 0051a486  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0051a48a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051a48c  7518                   -jne 0x51a4a6
    if (!cpu.flags.zf)
    {
        goto L_0x0051a4a6;
    }
    // 0051a48e  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051a494  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051a496  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051a499  c1e202                 +shl edx, 2
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
    // 0051a49c  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0051a49e  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0051a4a1  a3b8aa5600             -mov dword ptr [0x56aab8], eax
    app->getMemory<x86::reg32>(x86::reg32(5679800) /* 0x56aab8 */) = cpu.eax;
L_0x0051a4a6:
    // 0051a4a6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051a4a8  8935b4ab5600           -mov dword ptr [0x56abb4], esi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.esi;
    // 0051a4ae  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0051a4b3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051a4b5  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0051a4b9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051a4bb  48                     -dec eax
    (cpu.eax)--;
    // 0051a4bc  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0051a4be  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
L_0x0051a4c2:
    // 0051a4c2  8b7c2438               -mov edi, dword ptr [esp + 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0051a4c6  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0051a4cb  39f8                   +cmp eax, edi
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
    // 0051a4cd  0f8daa020000           -jge 0x51a77d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051a77d;
    }
    // 0051a4d3  833d5844560000         +cmp dword ptr [0x564458], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a4da  0f859d020000           -jne 0x51a77d
    if (!cpu.flags.zf)
    {
        goto L_0x0051a77d;
    }
    // 0051a4e0  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0051a4e2  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0051a4e7  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0051a4eb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051a4ed  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0051a4ef  e8dc160000             -call 0x51bbd0
    cpu.esp -= 4;
    sub_51bbd0(app, cpu);
    if (cpu.terminate) return;
    // 0051a4f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a4f6  0f844c020000           -je 0x51a748
    if (cpu.flags.zf)
    {
        goto L_0x0051a748;
    }
    // 0051a4fc  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0051a500  8a242c                 -mov ah, byte ptr [esp + ebp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + cpu.ebp * 1);
    // 0051a503  42                     -inc edx
    (cpu.edx)++;
    // 0051a504  45                     -inc ebp
    (cpu.ebp)++;
    // 0051a505  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0051a509  80fc20                 +cmp ah, 0x20
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
    // 0051a50c  0f83d1000000           -jae 0x51a5e3
    if (!cpu.flags.cf)
    {
        goto L_0x0051a5e3;
    }
    // 0051a512  c6442cff5f             -mov byte ptr [esp + ebp - 1], 0x5f
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.ebp * 1) = 95 /*0x5f*/;
L_0x0051a517:
    // 0051a517  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0051a519:
    // 0051a519  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0051a51d  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0051a521  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051a523  0f84d6000000           -je 0x51a5ff
    if (cpu.flags.zf)
    {
        goto L_0x0051a5ff;
    }
L_0x0051a529:
    // 0051a529  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0051a52b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0051a52d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051a52f  883c2c                 -mov byte ptr [esp + ebp], bh
    app->getMemory<x86::reg8>(cpu.esp + cpu.ebp * 1) = cpu.bh;
L_0x0051a532:
    // 0051a532  8b0db8ab5600           -mov ecx, dword ptr [0x56abb8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5680056) /* 0x56abb8 */);
    // 0051a538  49                     -dec ecx
    (cpu.ecx)--;
    // 0051a539  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051a53b  0f8c1b010000           -jl 0x51a65c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a65c;
    }
    // 0051a541  6bd90c                 -imul ebx, ecx, 0xc
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 0051a544  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0051a546:
    // 0051a546  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051a548  8b93c0aa5600           -mov edx, dword ptr [ebx + 0x56aac0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5679808) /* 0x56aac0 */);
    // 0051a54e  e8cd62fcff             -call 0x4e0820
    cpu.esp -= 4;
    sub_4e0820(app, cpu);
    if (cpu.terminate) return;
    // 0051a553  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a555  0f84f5000000           -je 0x51a650
    if (cpu.flags.zf)
    {
        goto L_0x0051a650;
    }
    // 0051a55b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051a55d  0f8eb1000000           -jle 0x51a614
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051a614;
    }
    // 0051a563  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051a568:
    // 0051a568  8b2dbcab5600           -mov ebp, dword ptr [0x56abbc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5680060) /* 0x56abbc */);
    // 0051a56e  09c5                   -or ebp, eax
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a570  a154445600             -mov eax, dword ptr [0x564454]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653588) /* 0x564454 */);
    // 0051a575  892dbcab5600           -mov dword ptr [0x56abbc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5680060) /* 0x56abbc */) = cpu.ebp;
    // 0051a57b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a57d  742a                   -je 0x51a5a9
    if (cpu.flags.zf)
    {
        goto L_0x0051a5a9;
    }
    // 0051a57f  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0051a586  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051a588  8b1485c0aa5600         -mov edx, dword ptr [eax*4 + 0x56aac0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5679808) /* 0x56aac0 */ + cpu.eax * 4);
    // 0051a58f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051a590  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051a594  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051a595  68dc0a5500             -push 0x550adc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573340 /*0x550adc*/;
    cpu.esp -= 4;
    // 0051a59a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051a59c  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 0051a5a1  e8aa6afeff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0051a5a6  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0051a5a9:
    // 0051a5a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a5ab  e88053fcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 0051a5b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a5b2  0f8463000000           -je 0x51a61b
    if (cpu.flags.zf)
    {
        goto L_0x0051a61b;
    }
    // 0051a5b8  a1b8aa5600             -mov eax, dword ptr [0x56aab8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5679800) /* 0x56aab8 */);
    // 0051a5bd  e85ed1fcff             -call 0x4e7720
    cpu.esp -= 4;
    sub_4e7720(app, cpu);
    if (cpu.terminate) return;
    // 0051a5c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a5c4  0f8d5b000000           -jge 0x51a625
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051a625;
    }
    // 0051a5ca  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0051a5cf  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 0051a5d4  890d58445600           -mov dword ptr [0x564458], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */) = cpu.ecx;
    // 0051a5da  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0051a5dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a5de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a5df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a5e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a5e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a5e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a5e3:
    // 0051a5e3  80fc30                 +cmp ah, 0x30
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051a5e6  0f822bffffff           -jb 0x51a517
    if (cpu.flags.cf)
    {
        goto L_0x0051a517;
    }
    // 0051a5ec  80fc39                 +cmp ah, 0x39
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051a5ef  0f8722ffffff           -ja 0x51a517
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051a517;
    }
    // 0051a5f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051a5fa  e91affffff             -jmp 0x51a519
    goto L_0x0051a519;
L_0x0051a5ff:
    // 0051a5ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a601  0f8422ffffff           -je 0x51a529
    if (cpu.flags.zf)
    {
        goto L_0x0051a529;
    }
    // 0051a607  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0051a60b  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0051a60f  e915ffffff             -jmp 0x51a529
    goto L_0x0051a529;
L_0x0051a614:
    // 0051a614  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051a616  e94dffffff             -jmp 0x51a568
    goto L_0x0051a568;
L_0x0051a61b:
    // 0051a61b  a1b8aa5600             -mov eax, dword ptr [0x56aab8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5679800) /* 0x56aab8 */);
    // 0051a620  e8bb52fcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x0051a625:
    // 0051a625  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0051a62c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051a62e  8b1485c0aa5600         -mov edx, dword ptr [eax*4 + 0x56aac0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5679808) /* 0x56aac0 */ + cpu.eax * 4);
    // 0051a635  8b0485c8aa5600         -mov eax, dword ptr [eax*4 + 0x56aac8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5679816) /* 0x56aac8 */ + cpu.eax * 4);
    // 0051a63c  8915b4ab5600           -mov dword ptr [0x56abb4], edx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edx;
    // 0051a642  e8e95dfdff             -call 0x4f0430
    cpu.esp -= 4;
    sub_4f0430(app, cpu);
    if (cpu.terminate) return;
    // 0051a647  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0051a64a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a64b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a64c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a64d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a64e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a64f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a650:
    // 0051a650  49                     -dec ecx
    (cpu.ecx)--;
    // 0051a651  83eb0c                 -sub ebx, 0xc
    (cpu.ebx) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051a654  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051a656  0f8deafeffff           -jge 0x51a546
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051a546;
    }
L_0x0051a65c:
    // 0051a65c  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051a65f  47                     -inc edi
    (cpu.edi)++;
    // 0051a660  83fe08                 +cmp esi, 8
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
    // 0051a663  0f8cc9feffff           -jl 0x51a532
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a532;
    }
    // 0051a669  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0051a66d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051a66f  0f84d3000000           -je 0x51a748
    if (cpu.flags.zf)
    {
        goto L_0x0051a748;
    }
    // 0051a675  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a67a  0f85c8000000           -jne 0x51a748
    if (!cpu.flags.zf)
    {
        goto L_0x0051a748;
    }
    // 0051a680  833dbcab560000         +cmp dword ptr [0x56abbc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680060) /* 0x56abbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a687  0f84bb000000           -je 0x51a748
    if (cpu.flags.zf)
    {
        goto L_0x0051a748;
    }
    // 0051a68d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051a68f  e89c5dfdff             -call 0x4f0430
    cpu.esp -= 4;
    sub_4f0430(app, cpu);
    if (cpu.terminate) return;
    // 0051a694  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051a696  83f80a                 +cmp eax, 0xa
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
    // 0051a699  0f8c79000000           -jl 0x51a718
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a718;
    }
    // 0051a69f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0051a6a4:
    // 0051a6a4  833d5444560000         +cmp dword ptr [0x564454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653588) /* 0x564454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a6ab  742e                   -je 0x51a6db
    if (cpu.flags.zf)
    {
        goto L_0x0051a6db;
    }
    // 0051a6ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051a6af  7c2a                   -jl 0x51a6db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a6db;
    }
    // 0051a6b1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0051a6b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051a6ba  8b1c85c0aa5600         -mov ebx, dword ptr [eax*4 + 0x56aac0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5679808) /* 0x56aac0 */ + cpu.eax * 4);
    // 0051a6c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051a6c2  8b742438               -mov esi, dword ptr [esp + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0051a6c6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051a6c7  68dc0a5500             -push 0x550adc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573340 /*0x550adc*/;
    cpu.esp -= 4;
    // 0051a6cc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051a6ce  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 0051a6d3  e87869feff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0051a6d8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0051a6db:
    // 0051a6db  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051a6dd  7c15                   -jl 0x51a6f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a6f4;
    }
    // 0051a6df  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0051a6e6  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051a6e8  8b0485c0aa5600         -mov eax, dword ptr [eax*4 + 0x56aac0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5679808) /* 0x56aac0 */ + cpu.eax * 4);
    // 0051a6ef  a3b4ab5600             -mov dword ptr [0x56abb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.eax;
L_0x0051a6f4:
    // 0051a6f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a6f6  e83552fcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 0051a6fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a6fd  7424                   -je 0x51a723
    if (cpu.flags.zf)
    {
        goto L_0x0051a723;
    }
    // 0051a6ff  a1b8aa5600             -mov eax, dword ptr [0x56aab8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5679800) /* 0x56aab8 */);
    // 0051a704  e817d0fcff             -call 0x4e7720
    cpu.esp -= 4;
    sub_4e7720(app, cpu);
    if (cpu.terminate) return;
    // 0051a709  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a70b  7c22                   -jl 0x51a72f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a72f;
    }
L_0x0051a70d:
    // 0051a70d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051a70f  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0051a712  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a713  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a714  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a715  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a716  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a717  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a718:
    // 0051a718  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a71a  7d88                   -jge 0x51a6a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051a6a4;
    }
    // 0051a71c  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0051a721  eb81                   -jmp 0x51a6a4
    goto L_0x0051a6a4;
L_0x0051a723:
    // 0051a723  a1b8aa5600             -mov eax, dword ptr [0x56aab8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5679800) /* 0x56aab8 */);
    // 0051a728  e8b351fcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 0051a72d  ebde                   -jmp 0x51a70d
    goto L_0x0051a70d;
L_0x0051a72f:
    // 0051a72f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0051a734  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 0051a739  893d58445600           -mov dword ptr [0x564458], edi
    app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */) = cpu.edi;
    // 0051a73f  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0051a742  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a743  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a744  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a745  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a746  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a747  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a748:
    // 0051a748  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a74a  e8e151fcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 0051a74f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a751  740f                   -je 0x51a762
    if (cpu.flags.zf)
    {
        goto L_0x0051a762;
    }
    // 0051a753  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a755  e8d6cefcff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 0051a75a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a75c  7c0b                   -jl 0x51a769
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a769;
    }
L_0x0051a75e:
    // 0051a75e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051a760  eb0c                   -jmp 0x51a76e
    goto L_0x0051a76e;
L_0x0051a762:
    // 0051a762  e87951fcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 0051a767  ebf5                   -jmp 0x51a75e
    goto L_0x0051a75e;
L_0x0051a769:
    // 0051a769  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051a76e:
    // 0051a76e  090558445600           -or dword ptr [0x564458], eax
    app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */) |= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a774  83fd29                 +cmp ebp, 0x29
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a777  0f8c45fdffff           -jl 0x51a4c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a4c2;
    }
L_0x0051a77d:
    // 0051a77d  833d5844560000         +cmp dword ptr [0x564458], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a784  740e                   -je 0x51a794
    if (cpu.flags.zf)
    {
        goto L_0x0051a794;
    }
    // 0051a786  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 0051a78b  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0051a78e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a78f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a790  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a791  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a792  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a793  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a794:
    // 0051a794  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0051a799  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0051a79c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a79d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a79e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a79f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a7a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a7a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_51a7b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a7b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051a7b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051a7b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051a7b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051a7b4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051a7b7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051a7b9  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0051a7bc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051a7be  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051a7c0  49                     -dec ecx
    (cpu.ecx)--;
    // 0051a7c1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051a7c3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051a7c5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0051a7c7  49                     -dec ecx
    (cpu.ecx)--;
    // 0051a7c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051a7ca  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0051a7cc  8915b0ab5600           -mov dword ptr [0x56abb0], edx
    app->getMemory<x86::reg32>(x86::reg32(5680048) /* 0x56abb0 */) = cpu.edx;
    // 0051a7d2  83f931                 +cmp ecx, 0x31
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49 /*0x31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a7d5  7f22                   -jg 0x51a7f9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051a7f9;
    }
    // 0051a7d7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051a7d9  7522                   -jne 0x51a7fd
    if (!cpu.flags.zf)
    {
        goto L_0x0051a7fd;
    }
L_0x0051a7db:
    // 0051a7db  833d5844560000         +cmp dword ptr [0x564458], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a7e2  7422                   -je 0x51a806
    if (cpu.flags.zf)
    {
        goto L_0x0051a806;
    }
L_0x0051a7e4:
    // 0051a7e4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0051a7e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a7eb  891d58445600           -mov dword ptr [0x564458], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */) = cpu.ebx;
L_0x0051a7f1:
    // 0051a7f1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051a7f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a7f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a7f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a7f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a7f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a7f9:
    // 0051a7f9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051a7fb  ebf4                   -jmp 0x51a7f1
    goto L_0x0051a7f1;
L_0x0051a7fd:
    // 0051a7fd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051a7ff  e8dc090000             -call 0x51b1e0
    cpu.esp -= 4;
    sub_51b1e0(app, cpu);
    if (cpu.terminate) return;
    // 0051a804  ebd5                   -jmp 0x51a7db
    goto L_0x0051a7db;
L_0x0051a806:
    // 0051a806  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a808  e82351fcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 0051a80d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051a80f  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051a814  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051a816  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 0051a81b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051a81e  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051a820  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051a822  0f8593000000           -jne 0x51a8bb
    if (!cpu.flags.zf)
    {
        goto L_0x0051a8bb;
    }
    // 0051a828  e8b350fcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x0051a82d:
    // 0051a82d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051a82f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051a832  e889090000             -call 0x51b1c0
    cpu.esp -= 4;
    sub_51b1c0(app, cpu);
    if (cpu.terminate) return;
    // 0051a837  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051a839  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051a83b  e8b00d0000             -call 0x51b5f0
    cpu.esp -= 4;
    sub_51b5f0(app, cpu);
    if (cpu.terminate) return;
    // 0051a840  bb040b5500             -mov ebx, 0x550b04
    cpu.ebx = 5573380 /*0x550b04*/;
    // 0051a845  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051a84a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051a84c  e89f0d0000             -call 0x51b5f0
    cpu.esp -= 4;
    sub_51b5f0(app, cpu);
    if (cpu.terminate) return;
    // 0051a851  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0051a856  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051a858  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051a85d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051a85f  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0051a864  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051a867  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051a869  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051a86b  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0051a86d:
    // 0051a86d  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0051a872  39f8                   +cmp eax, edi
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
    // 0051a874  7d57                   -jge 0x51a8cd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051a8cd;
    }
    // 0051a876  833db0ab560000         +cmp dword ptr [0x56abb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680048) /* 0x56abb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a87d  754e                   -jne 0x51a8cd
    if (!cpu.flags.zf)
    {
        goto L_0x0051a8cd;
    }
    // 0051a87f  833d5844560000         +cmp dword ptr [0x564458], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a886  7545                   -jne 0x51a8cd
    if (!cpu.flags.zf)
    {
        goto L_0x0051a8cd;
    }
    // 0051a888  bb60b1a000             -mov ebx, 0xa0b160
    cpu.ebx = 10531168 /*0xa0b160*/;
    // 0051a88d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0051a892  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051a894  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051a896  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0051a898  e833130000             -call 0x51bbd0
    cpu.esp -= 4;
    sub_51bbd0(app, cpu);
    if (cpu.terminate) return;
    // 0051a89d  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051a89f  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 0051a8a1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051a8a4  88a660b1a000           -mov byte ptr [esi + 0xa0b160], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10531168) /* 0xa0b160 */) = cpu.ah;
    // 0051a8aa  b860b1a000             -mov eax, 0xa0b160
    cpu.eax = 10531168 /*0xa0b160*/;
    // 0051a8af  e86c5ffcff             -call 0x4e0820
    cpu.esp -= 4;
    sub_4e0820(app, cpu);
    if (cpu.terminate) return;
    // 0051a8b4  a3b0ab5600             -mov dword ptr [0x56abb0], eax
    app->getMemory<x86::reg32>(x86::reg32(5680048) /* 0x56abb0 */) = cpu.eax;
    // 0051a8b9  ebb2                   -jmp 0x51a86d
    goto L_0x0051a86d;
L_0x0051a8bb:
    // 0051a8bb  e860cefcff             -call 0x4e7720
    cpu.esp -= 4;
    sub_4e7720(app, cpu);
    if (cpu.terminate) return;
    // 0051a8c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a8c2  0f8c1cffffff           -jl 0x51a7e4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a7e4;
    }
    // 0051a8c8  e960ffffff             -jmp 0x51a82d
    goto L_0x0051a82d;
L_0x0051a8cd:
    // 0051a8cd  833d5444560000         +cmp dword ptr [0x564454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653588) /* 0x564454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a8d4  741f                   -je 0x51a8f5
    if (cpu.flags.zf)
    {
        goto L_0x0051a8f5;
    }
    // 0051a8d6  8b1db0ab5600           -mov ebx, dword ptr [0x56abb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5680048) /* 0x56abb0 */);
    // 0051a8dc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051a8de  742f                   -je 0x51a90f
    if (cpu.flags.zf)
    {
        goto L_0x0051a90f;
    }
    // 0051a8e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051a8e1  68080b5500             -push 0x550b08
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573384 /*0x550b08*/;
    cpu.esp -= 4;
    // 0051a8e6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051a8e8  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 0051a8ed  e85e67feff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0051a8f2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0051a8f5:
    // 0051a8f5  833db0ab560000         +cmp dword ptr [0x56abb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680048) /* 0x56abb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a8fc  0f84f7feffff           -je 0x51a7f9
    if (cpu.flags.zf)
    {
        goto L_0x0051a7f9;
    }
    // 0051a902  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051a907  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051a90a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a90b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a90c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a90d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a90e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a90f:
    // 0051a90f  681c0b5500             -push 0x550b1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573404 /*0x550b1c*/;
    cpu.esp -= 4;
    // 0051a914  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051a916  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 0051a91b  e83067feff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0051a920  83c40c                 +add esp, 0xc
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
    // 0051a923  ebd0                   -jmp 0x51a8f5
    goto L_0x0051a8f5;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_51a930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051a930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051a931  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051a932  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051a933  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051a934  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051a935  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051a937  833d5444560000         +cmp dword ptr [0x564454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653588) /* 0x564454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a93e  753d                   -jne 0x51a97d
    if (!cpu.flags.zf)
    {
        goto L_0x0051a97d;
    }
L_0x0051a940:
    // 0051a940  833db8aa560000         +cmp dword ptr [0x56aab8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5679800) /* 0x56aab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a947  7518                   -jne 0x51a961
    if (!cpu.flags.zf)
    {
        goto L_0x0051a961;
    }
    // 0051a949  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051a94f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051a951  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051a954  c1e202                 +shl edx, 2
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
    // 0051a957  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0051a959  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0051a95c  a3b8aa5600             -mov dword ptr [0x56aab8], eax
    app->getMemory<x86::reg32>(x86::reg32(5679800) /* 0x56aab8 */) = cpu.eax;
L_0x0051a961:
    // 0051a961  833d5844560000         +cmp dword ptr [0x564458], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a968  7429                   -je 0x51a993
    if (cpu.flags.zf)
    {
        goto L_0x0051a993;
    }
L_0x0051a96a:
    // 0051a96a  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0051a96f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a971  893558445600           -mov dword ptr [0x564458], esi
    app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */) = cpu.esi;
    // 0051a977  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a978  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a979  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a97a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a97b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a97c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a97d:
    // 0051a97d  683c0b5500             -push 0x550b3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573436 /*0x550b3c*/;
    cpu.esp -= 4;
    // 0051a982  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051a984  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 0051a989  e8c266feff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0051a98e  83c40c                 +add esp, 0xc
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
    // 0051a991  ebad                   -jmp 0x51a940
    goto L_0x0051a940;
L_0x0051a993:
    // 0051a993  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a995  e8964ffcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 0051a99a  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051a9a0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051a9a2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0051a9a9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051a9ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051a9ad  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051a9b0  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051a9b2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0051a9b4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051a9b6  7532                   -jne 0x51a9ea
    if (!cpu.flags.zf)
    {
        goto L_0x0051a9ea;
    }
    // 0051a9b8  e8234ffcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x0051a9bd:
    // 0051a9bd  bb580b5500             -mov ebx, 0x550b58
    cpu.ebx = 5573464 /*0x550b58*/;
    // 0051a9c2  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0051a9c7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051a9c9  e8220c0000             -call 0x51b5f0
    cpu.esp -= 4;
    sub_51b5f0(app, cpu);
    if (cpu.terminate) return;
    // 0051a9ce  833d5844560000         +cmp dword ptr [0x564458], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051a9d5  7422                   -je 0x51a9f9
    if (cpu.flags.zf)
    {
        goto L_0x0051a9f9;
    }
L_0x0051a9d7:
    // 0051a9d7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0051a9dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a9de  891d58445600           -mov dword ptr [0x564458], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */) = cpu.ebx;
    // 0051a9e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a9e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a9e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a9e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a9e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051a9e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051a9ea:
    // 0051a9ea  e831cdfcff             -call 0x4e7720
    cpu.esp -= 4;
    sub_4e7720(app, cpu);
    if (cpu.terminate) return;
    // 0051a9ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051a9f1  0f8c73ffffff           -jl 0x51a96a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a96a;
    }
    // 0051a9f7  ebc4                   -jmp 0x51a9bd
    goto L_0x0051a9bd;
L_0x0051a9f9:
    // 0051a9f9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051a9fb  e8304ffcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 0051aa00  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051aa06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051aa08  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0051aa0f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051aa11  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051aa13  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051aa16  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051aa18  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0051aa1a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051aa1c  753c                   -jne 0x51aa5a
    if (!cpu.flags.zf)
    {
        goto L_0x0051aa5a;
    }
    // 0051aa1e  e8bd4efcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x0051aa23:
    // 0051aa23  8b1dbcaa5600           -mov ebx, dword ptr [0x56aabc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5679804) /* 0x56aabc */);
    // 0051aa29  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0051aa2b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051aa2d  49                     -dec ecx
    (cpu.ecx)--;
    // 0051aa2e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051aa30  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051aa32  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0051aa34  49                     -dec ecx
    (cpu.ecx)--;
    // 0051aa35  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051aa37  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051aa39  e8b20b0000             -call 0x51b5f0
    cpu.esp -= 4;
    sub_51b5f0(app, cpu);
    if (cpu.terminate) return;
    // 0051aa3e  833d5844560000         +cmp dword ptr [0x564458], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051aa45  7422                   -je 0x51aa69
    if (cpu.flags.zf)
    {
        goto L_0x0051aa69;
    }
L_0x0051aa47:
    // 0051aa47  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0051aa4c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051aa4e  890d58445600           -mov dword ptr [0x564458], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */) = cpu.ecx;
    // 0051aa54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aa55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aa56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aa57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aa58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aa59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051aa5a:
    // 0051aa5a  e8c1ccfcff             -call 0x4e7720
    cpu.esp -= 4;
    sub_4e7720(app, cpu);
    if (cpu.terminate) return;
    // 0051aa5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051aa61  0f8c70ffffff           -jl 0x51a9d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051a9d7;
    }
    // 0051aa67  ebba                   -jmp 0x51aa23
    goto L_0x0051aa23;
L_0x0051aa69:
    // 0051aa69  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051aa6b  e8c04efcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 0051aa70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051aa72  7548                   -jne 0x51aabc
    if (!cpu.flags.zf)
    {
        goto L_0x0051aabc;
    }
    // 0051aa74  a1b8aa5600             -mov eax, dword ptr [0x56aab8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5679800) /* 0x56aab8 */);
    // 0051aa79  e8624efcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x0051aa7e:
    // 0051aa7e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051aa80  ba5c0b5500             -mov edx, 0x550b5c
    cpu.edx = 5573468 /*0x550b5c*/;
    // 0051aa85  e836070000             -call 0x51b1c0
    cpu.esp -= 4;
    sub_51b1c0(app, cpu);
    if (cpu.terminate) return;
    // 0051aa8a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051aa8c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051aa8e  e81dfdffff             -call 0x51a7b0
    cpu.esp -= 4;
    sub_51a7b0(app, cpu);
    if (cpu.terminate) return;
    // 0051aa93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051aa95  7539                   -jne 0x51aad0
    if (!cpu.flags.zf)
    {
        goto L_0x0051aad0;
    }
L_0x0051aa97:
    // 0051aa97  833d5444560000         +cmp dword ptr [0x564454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653588) /* 0x564454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051aa9e  7414                   -je 0x51aab4
    if (cpu.flags.zf)
    {
        goto L_0x0051aab4;
    }
    // 0051aaa0  68740b5500             -push 0x550b74
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573492 /*0x550b74*/;
    cpu.esp -= 4;
    // 0051aaa5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051aaa7  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 0051aaac  e89f65feff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0051aab1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0051aab4:
    // 0051aab4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051aab6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aab7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aab8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aab9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aaba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aabb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051aabc:
    // 0051aabc  a1b8aa5600             -mov eax, dword ptr [0x56aab8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5679800) /* 0x56aab8 */);
    // 0051aac1  e85accfcff             -call 0x4e7720
    cpu.esp -= 4;
    sub_4e7720(app, cpu);
    if (cpu.terminate) return;
    // 0051aac6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051aac8  0f8c79ffffff           -jl 0x51aa47
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051aa47;
    }
    // 0051aace  ebae                   -jmp 0x51aa7e
    goto L_0x0051aa7e;
L_0x0051aad0:
    // 0051aad0  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051aad6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051aad8  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051aada  e891f9ffff             -call 0x51a470
    cpu.esp -= 4;
    sub_51a470(app, cpu);
    if (cpu.terminate) return;
    // 0051aadf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051aae1  75b4                   -jne 0x51aa97
    if (!cpu.flags.zf)
    {
        goto L_0x0051aa97;
    }
    // 0051aae3  833d5444560000         +cmp dword ptr [0x564454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653588) /* 0x564454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051aaea  7414                   -je 0x51ab00
    if (cpu.flags.zf)
    {
        goto L_0x0051ab00;
    }
    // 0051aaec  68600b5500             -push 0x550b60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573472 /*0x550b60*/;
    cpu.esp -= 4;
    // 0051aaf1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051aaf3  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 0051aaf8  e85365feff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0051aafd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0051ab00:
    // 0051ab00  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051ab05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ab06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ab07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ab08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ab09  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ab0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_51ab10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ab10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051ab11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051ab12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051ab13  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051ab15  ba940b5500             -mov edx, 0x550b94
    cpu.edx = 5573524 /*0x550b94*/;
    // 0051ab1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051ab1c  e88ffcffff             -call 0x51a7b0
    cpu.esp -= 4;
    sub_51a7b0(app, cpu);
    if (cpu.terminate) return;
    // 0051ab21  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0051ab27  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051ab29  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051ab2b  e840f9ffff             -call 0x51a470
    cpu.esp -= 4;
    sub_51a470(app, cpu);
    if (cpu.terminate) return;
    // 0051ab30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ab31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ab32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ab33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51ab40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ab40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051ab41  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051ab43  833dc0ab560000         +cmp dword ptr [0x56abc0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ab4a  7416                   -je 0x51ab62
    if (cpu.flags.zf)
    {
        goto L_0x0051ab62;
    }
L_0x0051ab4c:
    // 0051ab4c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051ab4e  42                     -inc edx
    (cpu.edx)++;
    // 0051ab4f  e8ac060000             -call 0x51b200
    cpu.esp -= 4;
    sub_51b200(app, cpu);
    if (cpu.terminate) return;
    // 0051ab54  83fa10                 +cmp edx, 0x10
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
    // 0051ab57  7d09                   -jge 0x51ab62
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051ab62;
    }
    // 0051ab59  833dc0ab560000         +cmp dword ptr [0x56abc0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ab60  75ea                   -jne 0x51ab4c
    if (!cpu.flags.zf)
    {
        goto L_0x0051ab4c;
    }
L_0x0051ab62:
    // 0051ab62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ab63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_51ab70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ab70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051ab71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051ab72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051ab73  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051ab75  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0051ab77  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051ab7c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ab7d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ab83  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0051ab8a  8b90a0b1a000           -mov edx, dword ptr [eax + 0xa0b1a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10531232) /* 0xa0b1a0 */);
    // 0051ab90  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051ab92  7510                   -jne 0x51aba4
    if (!cpu.flags.zf)
    {
        goto L_0x0051aba4;
    }
    // 0051ab94  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051ab99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ab9a  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051aba0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aba1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aba2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051aba3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051aba4:
    // 0051aba4  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0051aba6  a1c4ab5600             -mov eax, dword ptr [0x56abc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680068) /* 0x56abc4 */);
    // 0051abab  e8804ffcff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 0051abb0  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051abb5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051abb6  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051abbc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051abbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051abbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051abbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51abc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051abc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051abc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051abc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051abc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051abc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051abc5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051abc6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051abc8  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051abcd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051abce  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051abd4  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051abd8  7518                   -jne 0x51abf2
    if (!cpu.flags.zf)
    {
        goto L_0x0051abf2;
    }
    // 0051abda  8d7318                 -lea esi, [ebx + 0x18]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0051abdd  8d6b14                 -lea ebp, [ebx + 0x14]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0051abe0  8d7b2c                 -lea edi, [ebx + 0x2c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(44) /* 0x2c */);
L_0x0051abe3:
    // 0051abe3  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0051abe6  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051abec  0f8cbb000000           -jl 0x51acad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051acad;
    }
L_0x0051abf2:
    // 0051abf2  8dbb3c020000           -lea edi, [ebx + 0x23c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(572) /* 0x23c */);
    // 0051abf8  8dab38020000           -lea ebp, [ebx + 0x238]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0051abfe  8db350020000           -lea esi, [ebx + 0x250]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(592) /* 0x250 */);
L_0x0051ac04:
    // 0051ac04  83bb2c02000000         +cmp dword ptr [ebx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ac0b  0f854c010000           -jne 0x51ad5d
    if (!cpu.flags.zf)
    {
        goto L_0x0051ad5d;
    }
    // 0051ac11  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0051ac17  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051ac19  0f8e3e010000           -jle 0x51ad5d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051ad5d;
    }
    // 0051ac1f  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0051ac25  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051ac27  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ac2d  0f8e03010000           -jle 0x51ad36
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051ad36;
    }
    // 0051ac33  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 0051ac38  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0051ac3a:
    // 0051ac3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051ac3b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051ac3c  c7833c02000000000000   -mov dword ptr [ebx + 0x23c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(572) /* 0x23c */) = 0 /*0x0*/;
    // 0051ac46  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051ac47  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0051ac49  c7834002000000000000   -mov dword ptr [ebx + 0x240], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(576) /* 0x240 */) = 0 /*0x0*/;
    // 0051ac53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ac54  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051ac57  c7834402000000000000   -mov dword ptr [ebx + 0x244], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(580) /* 0x244 */) = 0 /*0x0*/;
    // 0051ac61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051ac62  c7834802000000000000   -mov dword ptr [ebx + 0x248], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(584) /* 0x248 */) = 0 /*0x0*/;
    // 0051ac6c  2eff1540465300         -call dword ptr cs:[0x534640]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457472) /* 0x534640 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ac73  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ac75  0f84c6000000           -je 0x51ad41
    if (cpu.flags.zf)
    {
        goto L_0x0051ad41;
    }
    // 0051ac7b  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0051ac81  8b8338020000           -mov eax, dword ptr [ebx + 0x238]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0051ac87  8b8b38020000           -mov ecx, dword ptr [ebx + 0x238]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0051ac8d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0051ac8f  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0051ac95  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051ac97  899334020000           -mov dword ptr [ebx + 0x234], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = cpu.edx;
    // 0051ac9d  25ff010000             +and eax, 0x1ff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/))));
    // 0051aca2  898330020000           -mov dword ptr [ebx + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.eax;
    // 0051aca8  e957ffffff             -jmp 0x51ac04
    goto L_0x0051ac04;
L_0x0051acad:
    // 0051acad  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0051acb0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051acb2  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0051acb7  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0051acba  39d0                   +cmp eax, edx
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
    // 0051acbc  7d4e                   -jge 0x51ad0c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051ad0c;
    }
L_0x0051acbe:
    // 0051acbe  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0051acc0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051acc1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051acc2  c7431800000000         -mov dword ptr [ebx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0051acc9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051acca  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0051accc  c7431c00000000         -mov dword ptr [ebx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0051acd3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051acd4  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051acd7  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0051acde  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051acdf  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0051ace6  2eff15b0455300         -call dword ptr cs:[0x5345b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457328) /* 0x5345b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051aced  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051acef  7422                   -je 0x51ad13
    if (cpu.flags.zf)
    {
        goto L_0x0051ad13;
    }
    // 0051acf1  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0051acf4  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0051acf7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051acf9  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051acfc  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0051acff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ad01  0f84dcfeffff           -je 0x51abe3
    if (cpu.flags.zf)
    {
        goto L_0x0051abe3;
    }
    // 0051ad07  e9e6feffff             -jmp 0x51abf2
    goto L_0x0051abf2;
L_0x0051ad0c:
    // 0051ad0c  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 0051ad11  ebab                   -jmp 0x51acbe
    goto L_0x0051acbe;
L_0x0051ad13:
    // 0051ad13  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ad1a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ad1c  750c                   -jne 0x51ad2a
    if (!cpu.flags.zf)
    {
        goto L_0x0051ad2a;
    }
L_0x0051ad1e:
    // 0051ad1e  c7430801000000         -mov dword ptr [ebx + 8], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0051ad25  e9c8feffff             -jmp 0x51abf2
    goto L_0x0051abf2;
L_0x0051ad2a:
    // 0051ad2a  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ad2f  74ed                   -je 0x51ad1e
    if (cpu.flags.zf)
    {
        goto L_0x0051ad1e;
    }
    // 0051ad31  e9bcfeffff             -jmp 0x51abf2
    goto L_0x0051abf2;
L_0x0051ad36:
    // 0051ad36  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0051ad3c  e9f9feffff             -jmp 0x51ac3a
    goto L_0x0051ac3a;
L_0x0051ad41:
    // 0051ad41  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ad48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ad4a  7407                   -je 0x51ad53
    if (cpu.flags.zf)
    {
        goto L_0x0051ad53;
    }
    // 0051ad4c  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ad51  750a                   -jne 0x51ad5d
    if (!cpu.flags.zf)
    {
        goto L_0x0051ad5d;
    }
L_0x0051ad53:
    // 0051ad53  c7832c02000001000000   -mov dword ptr [ebx + 0x22c], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 1 /*0x1*/;
L_0x0051ad5d:
    // 0051ad5d  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051ad62  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ad63  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ad69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ad6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ad6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ad6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ad6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ad6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ad6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51ad70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ad70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051ad71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051ad72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051ad73  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051ad76  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051ad78  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051ad7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ad7e  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ad84  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ad88  7520                   -jne 0x51adaa
    if (!cpu.flags.zf)
    {
        goto L_0x0051adaa;
    }
L_0x0051ad8a:
    // 0051ad8a  83bb2c02000000         +cmp dword ptr [ebx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ad91  0f8570000000           -jne 0x51ae07
    if (!cpu.flags.zf)
    {
        goto L_0x0051ae07;
    }
L_0x0051ad97:
    // 0051ad97  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051ad9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ad9d  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ada3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051ada6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ada7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ada8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ada9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051adaa:
    // 0051adaa  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0051adad  e88e4dfcff             -call 0x4dfb40
    cpu.esp -= 4;
    sub_4dfb40(app, cpu);
    if (cpu.terminate) return;
    // 0051adb2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051adb4  74d4                   -je 0x51ad8a
    if (cpu.flags.zf)
    {
        goto L_0x0051ad8a;
    }
    // 0051adb6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051adb8  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051adbc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051adbd  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0051adc0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051adc1  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051adc4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051adc5  2eff1554455300         -call dword ptr cs:[0x534554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457236) /* 0x534554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051adcc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051adce  7418                   -je 0x51ade8
    if (cpu.flags.zf)
    {
        goto L_0x0051ade8;
    }
    // 0051add0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051add1  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051add5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051add7  750a                   -jne 0x51ade3
    if (!cpu.flags.zf)
    {
        goto L_0x0051ade3;
    }
L_0x0051add9:
    // 0051add9  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0051ade0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ade1  eba7                   -jmp 0x51ad8a
    goto L_0x0051ad8a;
L_0x0051ade3:
    // 0051ade3  017310                 +add dword ptr [ebx + 0x10], esi
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051ade6  ebf1                   -jmp 0x51add9
    goto L_0x0051add9;
L_0x0051ade8:
    // 0051ade8  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051adef  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051adf4  750a                   -jne 0x51ae00
    if (!cpu.flags.zf)
    {
        goto L_0x0051ae00;
    }
    // 0051adf6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051adfb  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051adfe  eb8a                   -jmp 0x51ad8a
    goto L_0x0051ad8a;
L_0x0051ae00:
    // 0051ae00  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051ae02  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051ae05  eb83                   -jmp 0x51ad8a
    goto L_0x0051ad8a;
L_0x0051ae07:
    // 0051ae07  8b834c020000           -mov eax, dword ptr [ebx + 0x24c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */);
    // 0051ae0d  e82e4dfcff             -call 0x4dfb40
    cpu.esp -= 4;
    sub_4dfb40(app, cpu);
    if (cpu.terminate) return;
    // 0051ae12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ae14  7481                   -je 0x51ad97
    if (cpu.flags.zf)
    {
        goto L_0x0051ad97;
    }
    // 0051ae16  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051ae18  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051ae1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ae1d  8d833c020000           -lea eax, [ebx + 0x23c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(572) /* 0x23c */);
    // 0051ae23  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ae24  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051ae27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ae28  2eff1554455300         -call dword ptr cs:[0x534554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457236) /* 0x534554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ae2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ae31  743e                   -je 0x51ae71
    if (cpu.flags.zf)
    {
        goto L_0x0051ae71;
    }
    // 0051ae33  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051ae36  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051ae38  741a                   -je 0x51ae54
    if (cpu.flags.zf)
    {
        goto L_0x0051ae54;
    }
    // 0051ae3a  299334020000           -sub dword ptr [ebx + 0x234], edx
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051ae40  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0051ae46  030424                 -add eax, dword ptr [esp]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0051ae49  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0051ae4e  898330020000           -mov dword ptr [ebx + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.eax;
L_0x0051ae54:
    // 0051ae54  c7832c02000000000000   -mov dword ptr [ebx + 0x22c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 0 /*0x0*/;
    // 0051ae5e  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051ae63  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ae64  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ae6a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051ae6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ae6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ae6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ae70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051ae71:
    // 0051ae71  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ae78  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ae7d  751e                   -jne 0x51ae9d
    if (!cpu.flags.zf)
    {
        goto L_0x0051ae9d;
    }
    // 0051ae7f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051ae84:
    // 0051ae84  89832c020000           -mov dword ptr [ebx + 0x22c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = cpu.eax;
    // 0051ae8a  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051ae8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ae90  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ae96  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051ae99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ae9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ae9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ae9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051ae9d:
    // 0051ae9d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051ae9f  ebe3                   -jmp 0x51ae84
    goto L_0x0051ae84;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_51aeb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051aeb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051aeb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051aeb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051aeb3  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0051aeb9  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0051aebe  a1c4ab5600             -mov eax, dword ptr [0x56abc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680068) /* 0x56abc4 */);
    // 0051aec3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051aec6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0051aec8:
    // 0051aec8  8b90a0b1a000           -mov edx, dword ptr [eax + 0xa0b1a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10531232) /* 0xa0b1a0 */);
    // 0051aece  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051aed0  7422                   -je 0x51aef4
    if (cpu.flags.zf)
    {
        goto L_0x0051aef4;
    }
    // 0051aed2  837a0800               +cmp dword ptr [edx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051aed6  7408                   -je 0x51aee0
    if (cpu.flags.zf)
    {
        goto L_0x0051aee0;
    }
    // 0051aed8  41                     -inc ecx
    (cpu.ecx)++;
    // 0051aed9  8b5a28                 -mov ebx, dword ptr [edx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 0051aedc  895c8cfc               -mov dword ptr [esp + ecx*4 - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.ebx;
L_0x0051aee0:
    // 0051aee0  83ba2c02000000         +cmp dword ptr [edx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051aee7  740b                   -je 0x51aef4
    if (cpu.flags.zf)
    {
        goto L_0x0051aef4;
    }
    // 0051aee9  41                     -inc ecx
    (cpu.ecx)++;
    // 0051aeea  8b924c020000           -mov edx, dword ptr [edx + 0x24c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(588) /* 0x24c */);
    // 0051aef0  89548cfc               -mov dword ptr [esp + ecx*4 - 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.edx;
L_0x0051aef4:
    // 0051aef4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051aef7  83f840                 +cmp eax, 0x40
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
    // 0051aefa  75cc                   -jne 0x51aec8
    if (!cpu.flags.zf)
    {
        goto L_0x0051aec8;
    }
    // 0051aefc  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0051aefe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051af00  e8eb4cfcff             -call 0x4dfbf0
    cpu.esp -= 4;
    sub_4dfbf0(app, cpu);
    if (cpu.terminate) return;
    // 0051af05  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0051af0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051af0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051af0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051af0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51af10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051af10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051af11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051af12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051af13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051af14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051af15  e8e64bfcff             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 0051af1a  a3c4ab5600             -mov dword ptr [0x56abc4], eax
    app->getMemory<x86::reg32>(x86::reg32(5680068) /* 0x56abc4 */) = cpu.eax;
    // 0051af1f  833dc0ab560000         +cmp dword ptr [0x56abc0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051af26  0f847d000000           -je 0x51afa9
    if (cpu.flags.zf)
    {
        goto L_0x0051afa9;
    }
    // 0051af2c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0051af2e:
    // 0051af2e  e87dffffff             -call 0x51aeb0
    cpu.esp -= 4;
    sub_51aeb0(app, cpu);
    if (cpu.terminate) return;
    // 0051af33  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0051af35:
    // 0051af35  8b9ea0b1a000           -mov ebx, dword ptr [esi + 0xa0b1a0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10531232) /* 0xa0b1a0 */);
    // 0051af3b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051af3d  745a                   -je 0x51af99
    if (cpu.flags.zf)
    {
        goto L_0x0051af99;
    }
    // 0051af3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051af41  e82afeffff             -call 0x51ad70
    cpu.esp -= 4;
    sub_51ad70(app, cpu);
    if (cpu.terminate) return;
    // 0051af46  3b3b                   +cmp edi, dword ptr [ebx]
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
    // 0051af48  7440                   -je 0x51af8a
    if (cpu.flags.zf)
    {
        goto L_0x0051af8a;
    }
    // 0051af4a  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051af4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051af50  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051af56  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051af58  83f803                 +cmp eax, 3
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
    // 0051af5b  7364                   -jae 0x51afc1
    if (!cpu.flags.cf)
    {
        goto L_0x0051afc1;
    }
    // 0051af5d  83f802                 +cmp eax, 2
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
    // 0051af60  751a                   -jne 0x51af7c
    if (!cpu.flags.zf)
    {
        goto L_0x0051af7c;
    }
    // 0051af62  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0051af64  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051af67  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051af68  2eff15a8455300         -call dword ptr cs:[0x5345a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457320) /* 0x5345a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051af6f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051af71  e8fafdffff             -call 0x51ad70
    cpu.esp -= 4;
    sub_51ad70(app, cpu);
    if (cpu.terminate) return;
    // 0051af76  897b0c                 -mov dword ptr [ebx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0051af79  897b10                 -mov dword ptr [ebx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0051af7c:
    // 0051af7c  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 0051af7e  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051af83  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051af84  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051af8a:
    // 0051af8a  3bbea0b1a000           +cmp edi, dword ptr [esi + 0xa0b1a0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10531232) /* 0xa0b1a0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051af90  7407                   -je 0x51af99
    if (cpu.flags.zf)
    {
        goto L_0x0051af99;
    }
    // 0051af92  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051af94  e827fcffff             -call 0x51abc0
    cpu.esp -= 4;
    sub_51abc0(app, cpu);
    if (cpu.terminate) return;
L_0x0051af99:
    // 0051af99  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051af9c  83fe40                 +cmp esi, 0x40
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
    // 0051af9f  7594                   -jne 0x51af35
    if (!cpu.flags.zf)
    {
        goto L_0x0051af35;
    }
    // 0051afa1  3b3dc0ab5600           +cmp edi, dword ptr [0x56abc0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051afa7  7585                   -jne 0x51af2e
    if (!cpu.flags.zf)
    {
        goto L_0x0051af2e;
    }
L_0x0051afa9:
    // 0051afa9  a1c4ab5600             -mov eax, dword ptr [0x56abc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680068) /* 0x56abc4 */);
    // 0051afae  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0051afb0  e84b4cfcff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 0051afb5  891dc4ab5600           -mov dword ptr [0x56abc4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5680068) /* 0x56abc4 */) = cpu.ebx;
    // 0051afbb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051afbc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051afbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051afbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051afbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051afc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051afc1:
    // 0051afc1  7642                   -jbe 0x51b005
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051b005;
    }
    // 0051afc3  83f804                 +cmp eax, 4
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
    // 0051afc6  75b4                   -jne 0x51af7c
    if (!cpu.flags.zf)
    {
        goto L_0x0051af7c;
    }
    // 0051afc8  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0051afca  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051afcd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051afce  2eff15a8455300         -call dword ptr cs:[0x5345a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457320) /* 0x5345a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051afd5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051afd7  e894fdffff             -call 0x51ad70
    cpu.esp -= 4;
    sub_51ad70(app, cpu);
    if (cpu.terminate) return;
    // 0051afdc  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051afdf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051afe0  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051afe7  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0051afea  e8114cfcff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 0051afef  8b834c020000           -mov eax, dword ptr [ebx + 0x24c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */);
    // 0051aff5  e8064cfcff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 0051affa  89bea0b1a000           -mov dword ptr [esi + 0xa0b1a0], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10531232) /* 0xa0b1a0 */) = cpu.edi;
    // 0051b000  e977ffffff             -jmp 0x51af7c
    goto L_0x0051af7c;
L_0x0051b005:
    // 0051b005  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0051b007  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051b00a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b00b  2eff15a8455300         -call dword ptr cs:[0x5345a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457320) /* 0x5345a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b012  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b014  e857fdffff             -call 0x51ad70
    cpu.esp -= 4;
    sub_51ad70(app, cpu);
    if (cpu.terminate) return;
    // 0051b019  89bb30020000           -mov dword ptr [ebx + 0x230], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.edi;
    // 0051b01f  89bb34020000           -mov dword ptr [ebx + 0x234], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = cpu.edi;
    // 0051b025  e952ffffff             -jmp 0x51af7c
    goto L_0x0051af7c;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_51b030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b030  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b032  7c1c                   -jl 0x51b050
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051b050;
    }
    // 0051b034  83f810                 +cmp eax, 0x10
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
    // 0051b037  7d17                   -jge 0x51b050
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051b050;
    }
    // 0051b039  833c85a0b1a00000       +cmp dword ptr [eax*4 + 0xa0b1a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b041  7510                   -jne 0x51b053
    if (!cpu.flags.zf)
    {
        goto L_0x0051b053;
    }
    // 0051b043  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0051b049  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0051b04f  90                     -nop 
    ;
L_0x0051b050:
    // 0051b050  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051b052  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b053:
    // 0051b053  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051b058  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51b060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b062  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b063  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b065  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b067  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b06e  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b075  750a                   -jne 0x51b081
    if (!cpu.flags.zf)
    {
        goto L_0x0051b081;
    }
    // 0051b077  e86402fdff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b07c  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b081:
    // 0051b081  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b086  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b087  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b08d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b08f  e89cffffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b094  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b096  7510                   -jne 0x51b0a8
    if (!cpu.flags.zf)
    {
        goto L_0x0051b0a8;
    }
    // 0051b098  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b09d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b09e  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b0a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b0a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b0a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b0a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b0a8:
    // 0051b0a8  8b049da0b1a000         -mov eax, dword ptr [ebx*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.ebx * 4);
    // 0051b0af  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0051b0b1  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051b0b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b0b5  2eff15bc445300         -call dword ptr cs:[0x5344bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457084) /* 0x5344bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b0bc  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b0c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b0c2  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b0c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b0c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b0ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b0cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_51b0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b0d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b0d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b0d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b0d3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b0d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b0d7  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b0de  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b0e5  750a                   -jne 0x51b0f1
    if (!cpu.flags.zf)
    {
        goto L_0x0051b0f1;
    }
    // 0051b0e7  e8f401fdff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b0ec  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b0f1:
    // 0051b0f1  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b0f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b0f7  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b0fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b0ff  e82cffffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b104  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b106  7510                   -jne 0x51b118
    if (!cpu.flags.zf)
    {
        goto L_0x0051b118;
    }
    // 0051b108  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b10d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b10e  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b114  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b115  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b116  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b117  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b118:
    // 0051b118  8b049da0b1a000         -mov eax, dword ptr [ebx*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.ebx * 4);
    // 0051b11f  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0051b121  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051b124  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b125  2eff15bc445300         -call dword ptr cs:[0x5344bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457084) /* 0x5344bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b12c  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b131  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b132  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b138  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b139  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b13a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b13b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_51b140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b142  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b143  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051b144  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051b147  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b149  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051b14b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051b14c  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b153  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b15a  750a                   -jne 0x51b166
    if (!cpu.flags.zf)
    {
        goto L_0x0051b166;
    }
    // 0051b15c  e87f01fdff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b161  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b166:
    // 0051b166  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b16b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b16c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b172  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b174  e8b7feffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b179  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b17b  7516                   -jne 0x51b193
    if (!cpu.flags.zf)
    {
        goto L_0x0051b193;
    }
L_0x0051b17d:
    // 0051b17d  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b182  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b183  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b189  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b18b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051b18e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b18f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b190  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b191  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b192  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b193:
    // 0051b193  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051b195  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051b197  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b198  8b049da0b1a000         -mov eax, dword ptr [ebx*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.ebx * 4);
    // 0051b19f  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0051b1a3  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051b1a6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b1a7  2eff15e8445300         -call dword ptr cs:[0x5344e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457128) /* 0x5344e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b1ae  f6042480               +test byte ptr [esp], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 128 /*0x80*/));
    // 0051b1b2  7407                   -je 0x51b1bb
    if (cpu.flags.zf)
    {
        goto L_0x0051b1bb;
    }
    // 0051b1b4  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0051b1b9  ebc2                   -jmp 0x51b17d
    goto L_0x0051b17d;
L_0x0051b1bb:
    // 0051b1bb  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0051b1bd  ebbe                   -jmp 0x51b17d
    goto L_0x0051b17d;
}

/* align: skip 0x90 */
void Application::sub_51b1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b1c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b1c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051b1c3  e868feffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b1c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b1ca  7502                   -jne 0x51b1ce
    if (!cpu.flags.zf)
    {
        goto L_0x0051b1ce;
    }
    // 0051b1cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b1cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b1ce:
    // 0051b1ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b1cf  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0051b1d4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051b1d6  e895f9ffff             -call 0x51ab70
    cpu.esp -= 4;
    sub_51ab70(app, cpu);
    if (cpu.terminate) return;
    // 0051b1db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b1dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b1dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51b1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b1e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b1e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051b1e3  e848feffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b1e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b1ea  7502                   -jne 0x51b1ee
    if (!cpu.flags.zf)
    {
        goto L_0x0051b1ee;
    }
    // 0051b1ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b1ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b1ee:
    // 0051b1ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b1ef  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0051b1f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051b1f6  e875f9ffff             -call 0x51ab70
    cpu.esp -= 4;
    sub_51ab70(app, cpu);
    if (cpu.terminate) return;
    // 0051b1fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b1fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b1fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51b200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b200  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b201  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b202  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b203  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b205  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b20c  0f848b000000           -je 0x51b29d
    if (cpu.flags.zf)
    {
        goto L_0x0051b29d;
    }
L_0x0051b212:
    // 0051b212  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b217  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b218  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b21e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b220  e80bfeffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b225  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b227  0f847f000000           -je 0x51b2ac
    if (cpu.flags.zf)
    {
        goto L_0x0051b2ac;
    }
    // 0051b22d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b22e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051b22f  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 0051b236  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0051b23b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b23d  8bbea0b1a000           -mov edi, dword ptr [esi + 0xa0b1a0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10531232) /* 0xa0b1a0 */);
    // 0051b243  e828f9ffff             -call 0x51ab70
    cpu.esp -= 4;
    sub_51ab70(app, cpu);
    if (cpu.terminate) return;
    // 0051b248  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b24d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b24e  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b254  8b8ea0b1a000           -mov ecx, dword ptr [esi + 0xa0b1a0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10531232) /* 0xa0b1a0 */);
    // 0051b25a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051b25c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051b25e  7420                   -je 0x51b280
    if (cpu.flags.zf)
    {
        goto L_0x0051b280;
    }
    // 0051b260  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x0051b265:
    // 0051b265  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b267  e87446fcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b26c  83baa0b1a00000         +cmp dword ptr [edx + 0xa0b1a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10531232) /* 0xa0b1a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b273  75f0                   -jne 0x51b265
    if (!cpu.flags.zf)
    {
        goto L_0x0051b265;
    }
    // 0051b275  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0051b27b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0051b27e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
L_0x0051b280:
    // 0051b280  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051b282  e80966fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0051b287  ff0dc0ab5600           -dec dword ptr [0x56abc0]
    (app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */))--;
    // 0051b28d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b28e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b28f  8b15c0ab5600           -mov edx, dword ptr [0x56abc0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */);
    // 0051b295  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051b297  742d                   -je 0x51b2c6
    if (cpu.flags.zf)
    {
        goto L_0x0051b2c6;
    }
    // 0051b299  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b29a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b29b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b29c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b29d:
    // 0051b29d  e83e00fdff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b2a2  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
    // 0051b2a7  e966ffffff             -jmp 0x51b212
    goto L_0x0051b212;
L_0x0051b2ac:
    // 0051b2ac  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b2b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b2b2  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b2b8  8b15c0ab5600           -mov edx, dword ptr [0x56abc0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */);
    // 0051b2be  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051b2c0  7404                   -je 0x51b2c6
    if (cpu.flags.zf)
    {
        goto L_0x0051b2c6;
    }
    // 0051b2c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b2c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b2c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b2c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b2c6:
    // 0051b2c6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b2c8  e8a3f8ffff             -call 0x51ab70
    cpu.esp -= 4;
    sub_51ab70(app, cpu);
    if (cpu.terminate) return;
    // 0051b2cd  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b2d2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051b2d4  e88700fdff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 0051b2d9  890dc8ab5600           -mov dword ptr [0x56abc8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.ecx;
    // 0051b2df  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b2e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b2e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b2e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51b2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b2f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b2f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b2f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051b2f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b2f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051b2f5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0051b2f8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051b2fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b2fc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051b2fe  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b305  83feff                 +cmp esi, -1
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
    // 0051b308  752a                   -jne 0x51b334
    if (!cpu.flags.zf)
    {
        goto L_0x0051b334;
    }
    // 0051b30a  b83c000000             -mov eax, 0x3c
    cpu.eax = 60 /*0x3c*/;
    // 0051b30f  8b15dcb1a000           -mov edx, dword ptr [0xa0b1dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531292) /* 0xa0b1dc */);
    // 0051b315  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
    // 0051b31a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051b31c  7412                   -je 0x51b330
    if (cpu.flags.zf)
    {
        goto L_0x0051b330;
    }
L_0x0051b31e:
    // 0051b31e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b320  7c0e                   -jl 0x51b330
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051b330;
    }
    // 0051b322  8b889cb1a000           -mov ecx, dword ptr [eax + 0xa0b19c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10531228) /* 0xa0b19c */);
    // 0051b328  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051b32b  4e                     -dec esi
    (cpu.esi)--;
    // 0051b32c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051b32e  75ee                   -jne 0x51b31e
    if (!cpu.flags.zf)
    {
        goto L_0x0051b31e;
    }
L_0x0051b330:
    // 0051b330  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051b332  7c67                   -jl 0x51b39b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051b39b;
    }
L_0x0051b334:
    // 0051b334  ff05c0ab5600           -inc dword ptr [0x56abc0]
    (app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */))++;
    // 0051b33a  833dc0ab560001         +cmp dword ptr [0x56abc0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b341  7566                   -jne 0x51b3a9
    if (!cpu.flags.zf)
    {
        goto L_0x0051b3a9;
    }
    // 0051b343  b840ab5100             -mov eax, 0x51ab40
    cpu.eax = 5352256 /*0x51ab40*/;
    // 0051b348  e82b77fdff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 0051b34d  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b354  750a                   -jne 0x51b360
    if (!cpu.flags.zf)
    {
        goto L_0x0051b360;
    }
    // 0051b356  e885fffcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b35b  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b360:
    // 0051b360  68e0b1a000             -push 0xa0b1e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10531296 /*0xa0b1e0*/;
    cpu.esp -= 4;
    // 0051b365  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0051b36a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0051b36f  b810af5100             -mov eax, 0x51af10
    cpu.eax = 5353232 /*0x51af10*/;
    // 0051b374  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051b376  e82544fcff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 0051b37b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b37d  752a                   -jne 0x51b3a9
    if (!cpu.flags.zf)
    {
        goto L_0x0051b3a9;
    }
    // 0051b37f  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b384  e8d7fffcff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 0051b389  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051b38b  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
    // 0051b390  a1c0ab5600             -mov eax, dword ptr [0x56abc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */);
    // 0051b395  ff0dc0ab5600           -dec dword ptr [0x56abc0]
    (app->getMemory<x86::reg32>(x86::reg32(5680064) /* 0x56abc0 */))--;
L_0x0051b39b:
    // 0051b39b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0051b3a0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0051b3a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b3a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b3a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b3a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b3a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b3a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b3a9:
    // 0051b3a9  ba9c0b5500             -mov edx, 0x550b9c
    cpu.edx = 5573532 /*0x550b9c*/;
    // 0051b3ae  b9a80b5500             -mov ecx, 0x550ba8
    cpu.ecx = 5573544 /*0x550ba8*/;
    // 0051b3b3  bb48020000             -mov ebx, 0x248
    cpu.ebx = 584 /*0x248*/;
    // 0051b3b8  b8bc0b5500             -mov eax, 0x550bbc
    cpu.eax = 5573564 /*0x550bbc*/;
    // 0051b3bd  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0051b3c3  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 0051b3c9  ba50040000             -mov edx, 0x450
    cpu.edx = 1104 /*0x450*/;
    // 0051b3ce  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 0051b3d4  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 0051b3da  e84162fcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0051b3df  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b3e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b3e3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051b3e5  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0051b3ec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b3ee  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b3f0  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0051b3f3  2eff1594445300         -call dword ptr cs:[0x534494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457044) /* 0x534494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b3fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b3fc  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0051b403  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b405  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0051b40c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051b40e  c7832c02000000000000   -mov dword ptr [ebx + 0x22c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 0 /*0x0*/;
    // 0051b418  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b41a  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0051b41d  2eff1594445300         -call dword ptr cs:[0x534494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457044) /* 0x534494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b424  c7833002000000000000   -mov dword ptr [ebx + 0x230], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = 0 /*0x0*/;
    // 0051b42e  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0051b433  89834c020000           -mov dword ptr [ebx + 0x24c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */) = cpu.eax;
    // 0051b439  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051b43b  c7833402000000000000   -mov dword ptr [ebx + 0x234], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = 0 /*0x0*/;
    // 0051b445  e8c252fcff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 0051b44a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051b44c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b44d  bd19000000             -mov ebp, 0x19
    cpu.ebp = 25 /*0x19*/;
    // 0051b452  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b453  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0051b457  2eff15c8455300         -call dword ptr cs:[0x5345c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457352) /* 0x5345c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b45e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051b463  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b465  891cb5a0b1a000         -mov dword ptr [esi*4 + 0xa0b1a0], ebx
    app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4) = cpu.ebx;
    // 0051b46c  e8fff6ffff             -call 0x51ab70
    cpu.esp -= 4;
    sub_51ab70(app, cpu);
    if (cpu.terminate) return;
    // 0051b471  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b473  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0051b476  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b477  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b478  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b479  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b47a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b47b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_51b480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b482  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b483  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b484  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051b487  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b489  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b48b  7c05                   -jl 0x51b492
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051b492;
    }
    // 0051b48d  83f810                 +cmp eax, 0x10
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
    // 0051b490  7c31                   -jl 0x51b4c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051b4c3;
    }
L_0x0051b492:
    // 0051b492  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051b493  ba9c0b5500             -mov edx, 0x550b9c
    cpu.edx = 5573532 /*0x550b9c*/;
    // 0051b498  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b499  b9c80b5500             -mov ecx, 0x550bc8
    cpu.ecx = 5573576 /*0x550bc8*/;
    // 0051b49e  be69020000             -mov esi, 0x269
    cpu.esi = 617 /*0x269*/;
    // 0051b4a3  68d40b5500             -push 0x550bd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573588 /*0x550bd4*/;
    cpu.esp -= 4;
    // 0051b4a8  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0051b4ae  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 0051b4b4  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0051b4ba  e8515beeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051b4bf  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051b4c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0051b4c3:
    // 0051b4c3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b4c5  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b4cc  8b3c9da0b1a000         -mov edi, dword ptr [ebx*4 + 0xa0b1a0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.ebx * 4);
    // 0051b4d3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051b4d5  7408                   -je 0x51b4df
    if (cpu.flags.zf)
    {
        goto L_0x0051b4df;
    }
L_0x0051b4d7:
    // 0051b4d7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051b4da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b4db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b4dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b4dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b4de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b4df:
    // 0051b4df  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0051b4e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b4e3  68f40b5500             -push 0x550bf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573620 /*0x550bf4*/;
    cpu.esp -= 4;
    // 0051b4e8  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051b4ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b4ed  e89e41fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0051b4f2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051b4f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b4f6  6880000040             -push 0x40000080
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741952 /*0x40000080*/;
    cpu.esp -= 4;
    // 0051b4fb  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0051b4fd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b4fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b4ff  68000000c0             -push 0xc0000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 3221225472 /*0xc0000000*/;
    cpu.esp -= 4;
    // 0051b504  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051b508  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b509  2eff1598445300         -call dword ptr cs:[0x534498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457048) /* 0x534498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b510  83f8ff                 +cmp eax, -1
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
    // 0051b513  74c2                   -je 0x51b4d7
    if (cpu.flags.zf)
    {
        goto L_0x0051b4d7;
    }
    // 0051b515  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051b517  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b519  e8d2fdffff             -call 0x51b2f0
    cpu.esp -= 4;
    sub_51b2f0(app, cpu);
    if (cpu.terminate) return;
    // 0051b51e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051b521  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b522  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b523  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b524  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b525  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_51b530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b530  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b531  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051b532  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b533  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051b535  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051b537  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b53e  750a                   -jne 0x51b54a
    if (!cpu.flags.zf)
    {
        goto L_0x0051b54a;
    }
    // 0051b540  e89bfdfcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b545  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b54a:
    // 0051b54a  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b54f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b550  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b556  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b558  e8d3faffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b55d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b55f  740b                   -je 0x51b56c
    if (cpu.flags.zf)
    {
        goto L_0x0051b56c;
    }
    // 0051b561  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b563  e898030000             -call 0x51b900
    cpu.esp -= 4;
    sub_51b900(app, cpu);
    if (cpu.terminate) return;
    // 0051b568  39f8                   +cmp eax, edi
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
    // 0051b56a  7d14                   -jge 0x51b580
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051b580;
    }
L_0x0051b56c:
    // 0051b56c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051b56e  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b573  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b574  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b57a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b57c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b57d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b57e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b57f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b580:
    // 0051b580  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051b582  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b584  e867000000             -call 0x51b5f0
    cpu.esp -= 4;
    sub_51b5f0(app, cpu);
    if (cpu.terminate) return;
    // 0051b589  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b58b  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b590  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b591  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b597  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b599  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b59a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b59b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b59c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51b5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b5a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051b5a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b5a2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051b5a4  e887faffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b5a9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0051b5ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b5ad  7424                   -je 0x51b5d3
    if (cpu.flags.zf)
    {
        goto L_0x0051b5d3;
    }
    // 0051b5af  030da0c17900           -add ecx, dword ptr [0x79c1a0]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */)));
L_0x0051b5b5:
    // 0051b5b5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b5b7  e844030000             -call 0x51b900
    cpu.esp -= 4;
    sub_51b900(app, cpu);
    if (cpu.terminate) return;
    // 0051b5bc  39d0                   +cmp eax, edx
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
    // 0051b5be  7d08                   -jge 0x51b5c8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051b5c8;
    }
    // 0051b5c0  3b0da0c17900           +cmp ecx, dword ptr [0x79c1a0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b5c6  7fed                   -jg 0x51b5b5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051b5b5;
    }
L_0x0051b5c8:
    // 0051b5c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b5ca  e831030000             -call 0x51b900
    cpu.esp -= 4;
    sub_51b900(app, cpu);
    if (cpu.terminate) return;
    // 0051b5cf  39d0                   +cmp eax, edx
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
    // 0051b5d1  7d05                   -jge 0x51b5d8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051b5d8;
    }
L_0x0051b5d3:
    // 0051b5d3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051b5d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b5d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b5d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b5d8:
    // 0051b5d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b5da  e811000000             -call 0x51b5f0
    cpu.esp -= 4;
    sub_51b5f0(app, cpu);
    if (cpu.terminate) return;
    // 0051b5df  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051b5e1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051b5e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b5e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b5e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_51b5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b5f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b5f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051b5f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b5f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051b5f4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051b5f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051b5f9  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0051b5fb  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0051b5fe  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0051b600  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0051b604  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b60b  750a                   -jne 0x51b617
    if (!cpu.flags.zf)
    {
        goto L_0x0051b617;
    }
    // 0051b60d  e8cefcfcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b612  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b617:
    // 0051b617  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b61c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b61d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b623  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b625  e806faffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b62a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b62c  0f84b7000000           -je 0x51b6e9
    if (cpu.flags.zf)
    {
        goto L_0x0051b6e9;
    }
    // 0051b632  8b04b5a0b1a000         -mov eax, dword ptr [esi*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4);
    // 0051b639  8b9034020000           -mov edx, dword ptr [eax + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 0051b63f  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0051b641  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b647  7e0b                   -jle 0x51b654
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051b654;
    }
    // 0051b649  bd00020000             -mov ebp, 0x200
    cpu.ebp = 512 /*0x200*/;
    // 0051b64e  2ba834020000           -sub ebp, dword ptr [eax + 0x234]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */)));
L_0x0051b654:
    // 0051b654  8b14b5a0b1a000         -mov edx, dword ptr [esi*4 + 0xa0b1a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4);
    // 0051b65b  8b8230020000           -mov eax, dword ptr [edx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(560) /* 0x230 */);
    // 0051b661  038234020000           -add eax, dword ptr [edx + 0x234]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */)));
    // 0051b667  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0051b66c  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0051b66f  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0051b671  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b677  7e0d                   -jle 0x51b686
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051b686;
    }
    // 0051b679  bf00020000             -mov edi, 0x200
    cpu.edi = 512 /*0x200*/;
    // 0051b67e  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0051b680  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0051b682  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
L_0x0051b686:
    // 0051b686  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051b688  7419                   -je 0x51b6a3
    if (cpu.flags.zf)
    {
        goto L_0x0051b6a3;
    }
    // 0051b68a  8b14b5a0b1a000         -mov edx, dword ptr [esi*4 + 0xa0b1a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4);
    // 0051b691  81c250020000           -add edx, 0x250
    (cpu.edx) += x86::reg32(x86::sreg32(592 /*0x250*/));
    // 0051b697  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0051b699  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051b69b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051b69e  e84deefcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
L_0x0051b6a3:
    // 0051b6a3  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051b6a7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051b6a9  7417                   -je 0x51b6c2
    if (cpu.flags.zf)
    {
        goto L_0x0051b6c2;
    }
    // 0051b6ab  8b14b5a0b1a000         -mov edx, dword ptr [esi*4 + 0xa0b1a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4);
    // 0051b6b2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051b6b5  81c250020000           -add edx, 0x250
    (cpu.edx) += x86::reg32(x86::sreg32(592 /*0x250*/));
    // 0051b6bb  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0051b6bd  e82eeefcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
L_0x0051b6c2:
    // 0051b6c2  8b04b5a0b1a000         -mov eax, dword ptr [esi*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4);
    // 0051b6c9  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051b6cd  8ba834020000           -mov ebp, dword ptr [eax + 0x234]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 0051b6d3  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0051b6d5  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051b6d7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051b6dc  89a834020000           -mov dword ptr [eax + 0x234], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */) = cpu.ebp;
    // 0051b6e2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b6e4  e887f4ffff             -call 0x51ab70
    cpu.esp -= 4;
    sub_51ab70(app, cpu);
    if (cpu.terminate) return;
L_0x0051b6e9:
    // 0051b6e9  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b6ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b6ef  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b6f5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051b6f9  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0051b6fb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051b6fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b6ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b700  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b701  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b702  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51b710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b710  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051b711  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b712  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051b713  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0051b716  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051b718  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051b71a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0051b71c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0051b71e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051b720  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b727  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b72e  750a                   -jne 0x51b73a
    if (!cpu.flags.zf)
    {
        goto L_0x0051b73a;
    }
    // 0051b730  e8abfbfcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b735  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b73a:
    // 0051b73a  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b73f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b740  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b746  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051b748  e8e3f8ffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b74d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b74f  0f849f000000           -je 0x51b7f4
    if (cpu.flags.zf)
    {
        goto L_0x0051b7f4;
    }
    // 0051b755  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051b757  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b758  8b04b5a0b1a000         -mov eax, dword ptr [esi*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4);
    // 0051b75f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051b762  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b763  2eff15f0445300         -call dword ptr cs:[0x5344f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457136) /* 0x5344f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b76a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b76c  7454                   -je 0x51b7c2
    if (cpu.flags.zf)
    {
        goto L_0x0051b7c2;
    }
    // 0051b76e  804c240801             -or byte ptr [esp + 8], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0051b773  6681642408fdb0         -and word ptr [esp + 8], 0xb0fd
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) &= x86::reg16(x86::sreg16(45309 /*0xb0fd*/));
    // 0051b77a  83ff10                 +cmp edi, 0x10
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
    // 0051b77d  7f07                   -jg 0x51b786
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051b786;
    }
    // 0051b77f  8b3cbdccab5600         -mov edi, dword ptr [edi*4 + 0x56abcc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5680076) /* 0x56abcc */ + cpu.edi * 4);
L_0x0051b786:
    // 0051b786  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0051b78a  0405                   -add al, 5
    (cpu.al) += x86::reg8(x86::sreg8(5 /*0x5*/));
    // 0051b78c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0051b790  88442412               -mov byte ptr [esp + 0x12], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(18) /* 0x12 */) = cpu.al;
    // 0051b794  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051b796  763f                   -jbe 0x51b7d7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051b7d7;
    }
    // 0051b798  83fb01                 +cmp ebx, 1
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
    // 0051b79b  753a                   -jne 0x51b7d7
    if (!cpu.flags.zf)
    {
        goto L_0x0051b7d7;
    }
    // 0051b79d  c644241402             -mov byte ptr [esp + 0x14], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = 2 /*0x2*/;
L_0x0051b7a2:
    // 0051b7a2  83fd01                 +cmp ebp, 1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b7a5  7338                   -jae 0x51b7df
    if (!cpu.flags.cf)
    {
        goto L_0x0051b7df;
    }
L_0x0051b7a7:
    // 0051b7a7  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0051b7a9  884c2413               -mov byte ptr [esp + 0x13], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = cpu.cl;
L_0x0051b7ad:
    // 0051b7ad  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051b7af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b7b0  8b04b5a0b1a000         -mov eax, dword ptr [esi*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4);
    // 0051b7b7  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051b7ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b7bb  2eff15c4455300         -call dword ptr cs:[0x5345c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457348) /* 0x5345c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051b7c2:
    // 0051b7c2  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b7c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b7c8  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b7ce  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0051b7d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b7d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b7d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b7d4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0051b7d7:
    // 0051b7d7  30f6                   +xor dh, dh
    cpu.clear_co();
    cpu.set_szp((cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh))));
    // 0051b7d9  88742414               -mov byte ptr [esp + 0x14], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dh;
    // 0051b7dd  ebc3                   -jmp 0x51b7a2
    goto L_0x0051b7a2;
L_0x0051b7df:
    // 0051b7df  7707                   -ja 0x51b7e8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051b7e8;
    }
    // 0051b7e1  c644241301             -mov byte ptr [esp + 0x13], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 1 /*0x1*/;
    // 0051b7e6  ebc5                   -jmp 0x51b7ad
    goto L_0x0051b7ad;
L_0x0051b7e8:
    // 0051b7e8  83fd03                 +cmp ebp, 3
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b7eb  75ba                   -jne 0x51b7a7
    if (!cpu.flags.zf)
    {
        goto L_0x0051b7a7;
    }
    // 0051b7ed  c644241302             -mov byte ptr [esp + 0x13], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 2 /*0x2*/;
    // 0051b7f2  ebb9                   -jmp 0x51b7ad
    goto L_0x0051b7ad;
L_0x0051b7f4:
    // 0051b7f4  b99c0b5500             -mov ecx, 0x550b9c
    cpu.ecx = 5573532 /*0x550b9c*/;
    // 0051b7f9  bb000c5500             -mov ebx, 0x550c00
    cpu.ebx = 5573632 /*0x550c00*/;
    // 0051b7fe  be56030000             -mov esi, 0x356
    cpu.esi = 854 /*0x356*/;
    // 0051b803  680c0c5500             -push 0x550c0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573644 /*0x550c0c*/;
    cpu.esp -= 4;
    // 0051b808  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0051b80e  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0051b814  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0051b81a  e8f157eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051b81f  83c404                 +add esp, 4
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
    // 0051b822  eb9e                   -jmp 0x51b7c2
    goto L_0x0051b7c2;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_51b830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b833  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b835  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b83c  750a                   -jne 0x51b848
    if (!cpu.flags.zf)
    {
        goto L_0x0051b848;
    }
    // 0051b83e  e89dfafcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b843  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b848:
    // 0051b848  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b84d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b84e  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b854  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b856  e8d5f7ffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b85b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b85d  741f                   -je 0x51b87e
    if (cpu.flags.zf)
    {
        goto L_0x0051b87e;
    }
    // 0051b85f  8b1c9da0b1a000         -mov ebx, dword ptr [ebx*4 + 0xa0b1a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.ebx * 4);
    // 0051b866  8b9b34020000           -mov ebx, dword ptr [ebx + 0x234]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0051b86c  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b871  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b872  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b878  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b87a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b87b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b87c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b87d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b87e:
    // 0051b87e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051b880  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b885  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b886  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b88c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b88e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b88f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b890  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b891  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_51b8a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b8a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b8a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b8a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b8a3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b8a5  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b8ac  750a                   -jne 0x51b8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0051b8b8;
    }
    // 0051b8ae  e82dfafcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b8b3  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b8b8:
    // 0051b8b8  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b8bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b8be  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b8c4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b8c6  e865f7ffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b8cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b8cd  741c                   -je 0x51b8eb
    if (cpu.flags.zf)
    {
        goto L_0x0051b8eb;
    }
    // 0051b8cf  8b1c9da0b1a000         -mov ebx, dword ptr [ebx*4 + 0xa0b1a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.ebx * 4);
    // 0051b8d6  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0051b8d9  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b8de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b8df  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b8e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b8e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b8e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b8e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b8ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b8eb:
    // 0051b8eb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051b8ed  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b8f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b8f3  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b8f9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b8fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b8fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b8fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b8fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51b900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051b901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b902  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051b903  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b905  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b90c  750a                   -jne 0x51b918
    if (!cpu.flags.zf)
    {
        goto L_0x0051b918;
    }
    // 0051b90e  e8cdf9fcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b913  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b918:
    // 0051b918  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b91d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b91e  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b924  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b926  e805f7ffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b92b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b92d  7428                   -je 0x51b957
    if (cpu.flags.zf)
    {
        goto L_0x0051b957;
    }
    // 0051b92f  8b1c9da0b1a000         -mov ebx, dword ptr [ebx*4 + 0xa0b1a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.ebx * 4);
    // 0051b936  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 0051b93b  8b8b34020000           -mov ecx, dword ptr [ebx + 0x234]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0051b941  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051b943  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051b945  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b94a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b94b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b951  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b953  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b954  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b955  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b956  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051b957:
    // 0051b957  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051b959  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b95e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b95f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b965  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051b967  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b968  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b969  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051b96a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_51b970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051b970  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051b971  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051b972  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051b973  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051b974  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051b977  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051b979  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051b97b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0051b97e  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0051b980  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0051b984  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b98b  750a                   -jne 0x51b997
    if (!cpu.flags.zf)
    {
        goto L_0x0051b997;
    }
    // 0051b98d  e84ef9fcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051b992  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051b997:
    // 0051b997  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051b99c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051b99d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051b9a3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051b9a5  e886f6ffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051b9aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051b9ac  0f847a000000           -je 0x51ba2c
    if (cpu.flags.zf)
    {
        goto L_0x0051ba2c;
    }
    // 0051b9b2  8b04bda0b1a000         -mov eax, dword ptr [edi*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.edi * 4);
    // 0051b9b9  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051b9bc  39de                   +cmp esi, ebx
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
    // 0051b9be  7e02                   -jle 0x51b9c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051b9c2;
    }
    // 0051b9c0  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x0051b9c2:
    // 0051b9c2  8b04bda0b1a000         -mov eax, dword ptr [edi*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.edi * 4);
    // 0051b9c9  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0051b9cc  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0051b9ce  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0051b9d0  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051b9d6  7e18                   -jle 0x51b9f0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051b9f0;
    }
    // 0051b9d8  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 0051b9dd  8b680c                 -mov ebp, dword ptr [eax + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0051b9e0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051b9e2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051b9e4  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0051b9e6  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0051b9e8  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0051b9ea  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0051b9ee  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x0051b9f0:
    // 0051b9f0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051b9f2  7419                   -je 0x51ba0d
    if (cpu.flags.zf)
    {
        goto L_0x0051ba0d;
    }
    // 0051b9f4  8b04bda0b1a000         -mov eax, dword ptr [edi*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.edi * 4);
    // 0051b9fb  8d502c                 -lea edx, [eax + 0x2c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0051b9fe  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0051ba01  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0051ba03  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051ba05  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051ba08  e8e3eafcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
L_0x0051ba0d:
    // 0051ba0d  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0051ba12  7418                   -je 0x51ba2c
    if (cpu.flags.zf)
    {
        goto L_0x0051ba2c;
    }
    // 0051ba14  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051ba17  8b04bda0b1a000         -mov eax, dword ptr [edi*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.edi * 4);
    // 0051ba1e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051ba22  83c02c                 -add eax, 0x2c
    (cpu.eax) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0051ba25  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0051ba27  e8c4eafcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
L_0x0051ba2c:
    // 0051ba2c  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051ba31  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ba32  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ba38  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051ba3c  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0051ba3e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051ba41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ba42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ba43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ba44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ba45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_51ba50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ba50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051ba51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051ba52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051ba53  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051ba55  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051ba57  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ba5e  750a                   -jne 0x51ba6a
    if (!cpu.flags.zf)
    {
        goto L_0x0051ba6a;
    }
    // 0051ba60  e87bf8fcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051ba65  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051ba6a:
    // 0051ba6a  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051ba6f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ba70  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ba76  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051ba78  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051ba7a  e8f1feffff             -call 0x51b970
    cpu.esp -= 4;
    sub_51b970(app, cpu);
    if (cpu.terminate) return;
    // 0051ba7f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051ba81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ba83  7512                   -jne 0x51ba97
    if (!cpu.flags.zf)
    {
        goto L_0x0051ba97;
    }
    // 0051ba85  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051ba8a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ba8b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ba91  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051ba93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ba94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ba95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ba96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051ba97:
    // 0051ba97  8b3cb5a0b1a000         -mov edi, dword ptr [esi*4 + 0xa0b1a0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4);
    // 0051ba9e  294710                 -sub dword ptr [edi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0051baa1  8b14b5a0b1a000         -mov edx, dword ptr [esi*4 + 0xa0b1a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4);
    // 0051baa8  03420c                 -add eax, dword ptr [edx + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0051baab  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0051bab0  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0051bab3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051bab8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051baba  e8b1f0ffff             -call 0x51ab70
    cpu.esp -= 4;
    sub_51ab70(app, cpu);
    if (cpu.terminate) return;
    // 0051babf  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051bac4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051bac5  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051bacb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051bacd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bace  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bacf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bad0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_51bae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051bae0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051bae1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051bae2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051bae3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051bae4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051bae6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051bae8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0051baea  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051baec  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051baf3  750a                   -jne 0x51baff
    if (!cpu.flags.zf)
    {
        goto L_0x0051baff;
    }
    // 0051baf5  e8e6f7fcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051bafa  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051baff:
    // 0051baff  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051bb04  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051bb05  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051bb0b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051bb0d  e81ef5ffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051bb12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051bb14  742a                   -je 0x51bb40
    if (cpu.flags.zf)
    {
        goto L_0x0051bb40;
    }
    // 0051bb16  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 0051bb1d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0051bb1f:
    // 0051bb1f  8b82a0b1a000           -mov eax, dword ptr [edx + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10531232) /* 0xa0b1a0 */);
    // 0051bb25  3b7010                 +cmp esi, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051bb28  7e09                   -jle 0x51bb33
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051bb33;
    }
    // 0051bb2a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051bb2c  e8af3dfcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 0051bb31  ebec                   -jmp 0x51bb1f
    goto L_0x0051bb1f;
L_0x0051bb33:
    // 0051bb33  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0051bb35  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051bb37  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051bb39  e812ffffff             -call 0x51ba50
    cpu.esp -= 4;
    sub_51ba50(app, cpu);
    if (cpu.terminate) return;
    // 0051bb3e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0051bb40:
    // 0051bb40  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051bb45  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051bb46  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051bb4c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051bb4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bb4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bb50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bb51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bb52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51bb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051bb60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051bb61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051bb62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051bb63  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051bb65  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051bb67  833dc8ab560000         +cmp dword ptr [0x56abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051bb6e  750a                   -jne 0x51bb7a
    if (!cpu.flags.zf)
    {
        goto L_0x0051bb7a;
    }
    // 0051bb70  e86bf7fcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051bb75  a3c8ab5600             -mov dword ptr [0x56abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */) = cpu.eax;
L_0x0051bb7a:
    // 0051bb7a  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051bb7f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051bb80  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051bb86  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bb88  e8a3f4ffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051bb8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051bb8f  740c                   -je 0x51bb9d
    if (cpu.flags.zf)
    {
        goto L_0x0051bb9d;
    }
    // 0051bb91  8b04b5a0b1a000         -mov eax, dword ptr [esi*4 + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531232) /* 0xa0b1a0 */ + cpu.esi * 4);
    // 0051bb98  3b7810                 +cmp edi, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051bb9b  7e14                   -jle 0x51bbb1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051bbb1;
    }
L_0x0051bb9d:
    // 0051bb9d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051bb9f  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051bba4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051bba5  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051bbab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051bbad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bbae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bbaf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bbb0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051bbb1:
    // 0051bbb1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051bbb3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bbb5  e896feffff             -call 0x51ba50
    cpu.esp -= 4;
    sub_51ba50(app, cpu);
    if (cpu.terminate) return;
    // 0051bbba  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051bbbc  a1c8ab5600             -mov eax, dword ptr [0x56abc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680072) /* 0x56abc8 */);
    // 0051bbc1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051bbc2  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051bbc8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051bbca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bbcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bbcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bbcd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51bbd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051bbd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051bbd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051bbd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051bbd3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051bbd5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0051bbd7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051bbd9  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051bbdf  7e32                   -jle 0x51bc13
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051bc13;
    }
    // 0051bbe1  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 0051bbe6  bd9c0b5500             -mov ebp, 0x550b9c
    cpu.ebp = 5573532 /*0x550b9c*/;
    // 0051bbeb  b8580c5500             -mov eax, 0x550c58
    cpu.eax = 5573720 /*0x550c58*/;
    // 0051bbf0  68680c5500             -push 0x550c68
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573736 /*0x550c68*/;
    cpu.esp -= 4;
    // 0051bbf5  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 0051bbfb  bd71040000             -mov ebp, 0x471
    cpu.ebp = 1137 /*0x471*/;
    // 0051bc00  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0051bc05  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0051bc0b  e80054eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051bc10  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0051bc13:
    // 0051bc13  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bc15  e816f4ffff             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 0051bc1a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051bc1c  7436                   -je 0x51bc54
    if (cpu.flags.zf)
    {
        goto L_0x0051bc54;
    }
    // 0051bc1e  8b1da0c17900           -mov ebx, dword ptr [0x79c1a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 0051bc24  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051bc26  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
L_0x0051bc2d:
    // 0051bc2d  8b81a0b1a000           -mov eax, dword ptr [ecx + 0xa0b1a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10531232) /* 0xa0b1a0 */);
    // 0051bc33  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051bc36  7e11                   -jle 0x51bc49
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051bc49;
    }
    // 0051bc38  3b1da0c17900           +cmp ebx, dword ptr [0x79c1a0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051bc3e  7e09                   -jle 0x51bc49
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051bc49;
    }
    // 0051bc40  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051bc42  e8993cfcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 0051bc47  ebe4                   -jmp 0x51bc2d
    goto L_0x0051bc2d;
L_0x0051bc49:
    // 0051bc49  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0051bc4b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bc4d  e8fefdffff             -call 0x51ba50
    cpu.esp -= 4;
    sub_51ba50(app, cpu);
    if (cpu.terminate) return;
    // 0051bc52  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0051bc54:
    // 0051bc54  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051bc56  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bc57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bc58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bc59  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0051bc5f  90                     -nop 
    ;
    // 0051bc60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51bc70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051bc70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051bc71  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051bc73  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 0051bc77  8a4003                 -mov al, byte ptr [eax + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0051bc7a  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0051bc7d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051bc7f  e8fc8afdff             -call 0x4f4780
    cpu.esp -= 4;
    sub_4f4780(app, cpu);
    if (cpu.terminate) return;
    // 0051bc84  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051bc86  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0051bc89  885103                 -mov byte ptr [ecx + 3], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.dl;
    // 0051bc8c  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0051bc8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bc90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_51bca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051bca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051bca1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051bca2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051bca4  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0051bca7  8a7803                 -mov bh, byte ptr [eax + 3]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0051bcaa  e8c1ffffff             -call 0x51bc70
    cpu.esp -= 4;
    sub_51bc70(app, cpu);
    if (cpu.terminate) return;
    // 0051bcaf  663b5902               +cmp bx, word ptr [ecx + 2]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0051bcb3  7508                   -jne 0x51bcbd
    if (!cpu.flags.zf)
    {
        goto L_0x0051bcbd;
    }
    // 0051bcb5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051bcba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bcbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bcbc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051bcbd:
    // 0051bcbd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051bcbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bcc0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bcc1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_51bcd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051bcd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051bcd1  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0051bcd3  8d5004                 -lea edx, [eax + 4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051bcd6  c600fe                 -mov byte ptr [eax], 0xfe
    app->getMemory<x86::reg8>(cpu.eax) = 254 /*0xfe*/;
    // 0051bcd9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0051bcdb  884801                 -mov byte ptr [eax + 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0051bcde  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bce0  e80be8fcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0051bce5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bce6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_51bcf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051bcf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051bcf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051bcf2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051bcf3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051bcf4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051bcf5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051bcf7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0051bcf9  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051bcfb  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051bcfe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051bd00  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051bd02  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051bd05  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051bd07  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051bd0a  ff550c                 -call dword ptr [ebp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051bd0d  39c8                   +cmp eax, ecx
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
    // 0051bd0f  7308                   -jae 0x51bd19
    if (!cpu.flags.cf)
    {
        goto L_0x0051bd19;
    }
    // 0051bd11  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051bd13  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051bd19:
    // 0051bd19  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051bd1b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bd1d  e84effffff             -call 0x51bc70
    cpu.esp -= 4;
    sub_51bc70(app, cpu);
    if (cpu.terminate) return;
    // 0051bd22  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051bd24  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051bd27  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051bd29  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0051bd2b  ff5518                 -call dword ptr [ebp + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051bd2e  39c8                   +cmp eax, ecx
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
    // 0051bd30  750d                   -jne 0x51bd3f
    if (!cpu.flags.zf)
    {
        goto L_0x0051bd3f;
    }
    // 0051bd32  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051bd37  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051bd39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd3e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051bd3f:
    // 0051bd3f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051bd41  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051bd43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51bd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051bd50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051bd51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051bd52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051bd53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051bd54  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051bd57  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051bd59  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0051bd5b  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0051bd5d  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051bd60  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bd62  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051bd64  ff570c                 -call dword ptr [edi + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051bd67  83f804                 +cmp eax, 4
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
    // 0051bd6a  730a                   -jae 0x51bd76
    if (!cpu.flags.cf)
    {
        goto L_0x0051bd76;
    }
    // 0051bd6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051bd6e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051bd71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bd75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051bd76:
    // 0051bd76  b4fe                   -mov ah, 0xfe
    cpu.ah = 254 /*0xfe*/;
    // 0051bd78  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0051bd7d  885c2401               -mov byte ptr [esp + 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0051bd81  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0051bd84  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051bd86  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0051bd8b  e8e0feffff             -call 0x51bc70
    cpu.esp -= 4;
    sub_51bc70(app, cpu);
    if (cpu.terminate) return;
    // 0051bd90  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0051bd93  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0051bd95  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bd97  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051bd9a  83f804                 +cmp eax, 4
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
    // 0051bd9d  750f                   -jne 0x51bdae
    if (!cpu.flags.zf)
    {
        goto L_0x0051bdae;
    }
    // 0051bd9f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051bda4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051bda6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051bda9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bdaa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bdab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bdac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bdad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051bdae:
    // 0051bdae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051bdb0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051bdb2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051bdb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bdb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bdb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bdb8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bdb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
