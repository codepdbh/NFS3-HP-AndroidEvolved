#include "voodoo2a.h"
#include <lib/thread.h>

namespace voodoo2a
{

/* align: skip  */
void sub_aa4200(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00aa4200:
    // 00aa4200  cc                     -int3 
    NFS2_ASSERT(false);
    // 00aa4201  ebfd                   -jmp 0xaa4200
    goto L_0x00aa4200;
}

/* align: skip 0x90 */
/* data blob: 909090000000000000000000 */
void sub_aa4210(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4210  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa4215  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa4220(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4222  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4223  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa4224  8b15342fab00           -mov edx, dword ptr [0xab2f34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218740) /* 0xab2f34 */);
    // 00aa422a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa422c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa422e  750a                   -jne 0xaa423a
    if (!cpu.flags.zf)
    {
        goto L_0x00aa423a;
    }
    // 00aa4230  c705342fab00804aaa00   -mov dword ptr [0xab2f34], 0xaa4a80
    app->getMemory<x86::reg32>(x86::reg32(11218740) /* 0xab2f34 */) = 11160192 /*0xaa4a80*/;
L_0x00aa423a:
    // 00aa423a  680422ab00             -push 0xab2204
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215364 /*0xab2204*/;
    cpu.esp -= 4;
    // 00aa423f  2eff15ec13ab00         -call dword ptr cs:[0xab13ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211756) /* 0xab13ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4246  a3502fab00             -mov dword ptr [0xab2f50], eax
    app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */) = cpu.eax;
    // 00aa424b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa424d  7507                   -jne 0xaa4256
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4256;
    }
    // 00aa424f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa4251  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4252  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4253  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4254  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4255  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa4256:
    // 00aa4256  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4257  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4258  681022ab00             -push 0xab2210
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215376 /*0xab2210*/;
    cpu.esp -= 4;
    // 00aa425d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa425e  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4265  682022ab00             -push 0xab2220
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215392 /*0xab2220*/;
    cpu.esp -= 4;
    // 00aa426a  8b1d502fab00           -mov ebx, dword ptr [0xab2f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4271  a31446ab00             -mov dword ptr [0xab4614], eax
    app->getMemory<x86::reg32>(x86::reg32(11224596) /* 0xab4614 */) = cpu.eax;
    // 00aa4276  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa427d  683822ab00             -push 0xab2238
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215416 /*0xab2238*/;
    cpu.esp -= 4;
    // 00aa4282  8b35502fab00           -mov esi, dword ptr [0xab2f50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4288  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4289  a31846ab00             -mov dword ptr [0xab4618], eax
    app->getMemory<x86::reg32>(x86::reg32(11224600) /* 0xab4618 */) = cpu.eax;
    // 00aa428e  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4295  684c22ab00             -push 0xab224c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215436 /*0xab224c*/;
    cpu.esp -= 4;
    // 00aa429a  8b3d502fab00           -mov edi, dword ptr [0xab2f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa42a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa42a1  a31c46ab00             -mov dword ptr [0xab461c], eax
    app->getMemory<x86::reg32>(x86::reg32(11224604) /* 0xab461c */) = cpu.eax;
    // 00aa42a6  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa42ad  686022ab00             -push 0xab2260
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215456 /*0xab2260*/;
    cpu.esp -= 4;
    // 00aa42b2  8b2d502fab00           -mov ebp, dword ptr [0xab2f50]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa42b8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa42b9  a32046ab00             -mov dword ptr [0xab4620], eax
    app->getMemory<x86::reg32>(x86::reg32(11224608) /* 0xab4620 */) = cpu.eax;
    // 00aa42be  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa42c5  687022ab00             -push 0xab2270
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215472 /*0xab2270*/;
    cpu.esp -= 4;
    // 00aa42ca  a32446ab00             -mov dword ptr [0xab4624], eax
    app->getMemory<x86::reg32>(x86::reg32(11224612) /* 0xab4624 */) = cpu.eax;
    // 00aa42cf  a1502fab00             -mov eax, dword ptr [0xab2f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa42d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa42d5  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa42dc  688422ab00             -push 0xab2284
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215492 /*0xab2284*/;
    cpu.esp -= 4;
    // 00aa42e1  8b15502fab00           -mov edx, dword ptr [0xab2f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa42e7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa42e8  a32846ab00             -mov dword ptr [0xab4628], eax
    app->getMemory<x86::reg32>(x86::reg32(11224616) /* 0xab4628 */) = cpu.eax;
    // 00aa42ed  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa42f4  689822ab00             -push 0xab2298
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215512 /*0xab2298*/;
    cpu.esp -= 4;
    // 00aa42f9  8b0d502fab00           -mov ecx, dword ptr [0xab2f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa42ff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4300  a32c46ab00             -mov dword ptr [0xab462c], eax
    app->getMemory<x86::reg32>(x86::reg32(11224620) /* 0xab462c */) = cpu.eax;
    // 00aa4305  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa430c  68b022ab00             -push 0xab22b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215536 /*0xab22b0*/;
    cpu.esp -= 4;
    // 00aa4311  8b1d502fab00           -mov ebx, dword ptr [0xab2f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4317  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4318  a33046ab00             -mov dword ptr [0xab4630], eax
    app->getMemory<x86::reg32>(x86::reg32(11224624) /* 0xab4630 */) = cpu.eax;
    // 00aa431d  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4324  68c422ab00             -push 0xab22c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215556 /*0xab22c4*/;
    cpu.esp -= 4;
    // 00aa4329  8b35502fab00           -mov esi, dword ptr [0xab2f50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa432f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4330  a33446ab00             -mov dword ptr [0xab4634], eax
    app->getMemory<x86::reg32>(x86::reg32(11224628) /* 0xab4634 */) = cpu.eax;
    // 00aa4335  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa433c  68e422ab00             -push 0xab22e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215588 /*0xab22e4*/;
    cpu.esp -= 4;
    // 00aa4341  8b3d502fab00           -mov edi, dword ptr [0xab2f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4347  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4348  a33846ab00             -mov dword ptr [0xab4638], eax
    app->getMemory<x86::reg32>(x86::reg32(11224632) /* 0xab4638 */) = cpu.eax;
    // 00aa434d  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4354  68fc22ab00             -push 0xab22fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215612 /*0xab22fc*/;
    cpu.esp -= 4;
    // 00aa4359  8b2d502fab00           -mov ebp, dword ptr [0xab2f50]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa435f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa4360  a33c46ab00             -mov dword ptr [0xab463c], eax
    app->getMemory<x86::reg32>(x86::reg32(11224636) /* 0xab463c */) = cpu.eax;
    // 00aa4365  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa436c  681023ab00             -push 0xab2310
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215632 /*0xab2310*/;
    cpu.esp -= 4;
    // 00aa4371  a34046ab00             -mov dword ptr [0xab4640], eax
    app->getMemory<x86::reg32>(x86::reg32(11224640) /* 0xab4640 */) = cpu.eax;
    // 00aa4376  a1502fab00             -mov eax, dword ptr [0xab2f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa437b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa437c  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4383  a34446ab00             -mov dword ptr [0xab4644], eax
    app->getMemory<x86::reg32>(x86::reg32(11224644) /* 0xab4644 */) = cpu.eax;
    // 00aa4388  682423ab00             -push 0xab2324
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215652 /*0xab2324*/;
    cpu.esp -= 4;
    // 00aa438d  8b15502fab00           -mov edx, dword ptr [0xab2f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4393  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4394  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa439b  683423ab00             -push 0xab2334
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215668 /*0xab2334*/;
    cpu.esp -= 4;
    // 00aa43a0  8b0d502fab00           -mov ecx, dword ptr [0xab2f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa43a6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa43a7  a34846ab00             -mov dword ptr [0xab4648], eax
    app->getMemory<x86::reg32>(x86::reg32(11224648) /* 0xab4648 */) = cpu.eax;
    // 00aa43ac  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa43b3  684423ab00             -push 0xab2344
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215684 /*0xab2344*/;
    cpu.esp -= 4;
    // 00aa43b8  8b1d502fab00           -mov ebx, dword ptr [0xab2f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa43be  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa43bf  a34c46ab00             -mov dword ptr [0xab464c], eax
    app->getMemory<x86::reg32>(x86::reg32(11224652) /* 0xab464c */) = cpu.eax;
    // 00aa43c4  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa43cb  685823ab00             -push 0xab2358
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215704 /*0xab2358*/;
    cpu.esp -= 4;
    // 00aa43d0  8b35502fab00           -mov esi, dword ptr [0xab2f50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa43d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa43d7  a35046ab00             -mov dword ptr [0xab4650], eax
    app->getMemory<x86::reg32>(x86::reg32(11224656) /* 0xab4650 */) = cpu.eax;
    // 00aa43dc  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa43e3  686823ab00             -push 0xab2368
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215720 /*0xab2368*/;
    cpu.esp -= 4;
    // 00aa43e8  8b3d502fab00           -mov edi, dword ptr [0xab2f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa43ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa43ef  a35446ab00             -mov dword ptr [0xab4654], eax
    app->getMemory<x86::reg32>(x86::reg32(11224660) /* 0xab4654 */) = cpu.eax;
    // 00aa43f4  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa43fb  687823ab00             -push 0xab2378
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215736 /*0xab2378*/;
    cpu.esp -= 4;
    // 00aa4400  8b2d502fab00           -mov ebp, dword ptr [0xab2f50]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4406  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa4407  a35846ab00             -mov dword ptr [0xab4658], eax
    app->getMemory<x86::reg32>(x86::reg32(11224664) /* 0xab4658 */) = cpu.eax;
    // 00aa440c  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4413  688c23ab00             -push 0xab238c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215756 /*0xab238c*/;
    cpu.esp -= 4;
    // 00aa4418  a35c46ab00             -mov dword ptr [0xab465c], eax
    app->getMemory<x86::reg32>(x86::reg32(11224668) /* 0xab465c */) = cpu.eax;
    // 00aa441d  a1502fab00             -mov eax, dword ptr [0xab2f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4422  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa4423  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa442a  68a023ab00             -push 0xab23a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215776 /*0xab23a0*/;
    cpu.esp -= 4;
    // 00aa442f  8b15502fab00           -mov edx, dword ptr [0xab2f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4435  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4436  a36046ab00             -mov dword ptr [0xab4660], eax
    app->getMemory<x86::reg32>(x86::reg32(11224672) /* 0xab4660 */) = cpu.eax;
    // 00aa443b  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4442  68b423ab00             -push 0xab23b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215796 /*0xab23b4*/;
    cpu.esp -= 4;
    // 00aa4447  8b0d502fab00           -mov ecx, dword ptr [0xab2f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa444d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa444e  a36446ab00             -mov dword ptr [0xab4664], eax
    app->getMemory<x86::reg32>(x86::reg32(11224676) /* 0xab4664 */) = cpu.eax;
    // 00aa4453  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa445a  68d023ab00             -push 0xab23d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215824 /*0xab23d0*/;
    cpu.esp -= 4;
    // 00aa445f  8b1d502fab00           -mov ebx, dword ptr [0xab2f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4465  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4466  a36846ab00             -mov dword ptr [0xab4668], eax
    app->getMemory<x86::reg32>(x86::reg32(11224680) /* 0xab4668 */) = cpu.eax;
    // 00aa446b  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4472  68e023ab00             -push 0xab23e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215840 /*0xab23e0*/;
    cpu.esp -= 4;
    // 00aa4477  8b35502fab00           -mov esi, dword ptr [0xab2f50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa447d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa447e  a36c46ab00             -mov dword ptr [0xab466c], eax
    app->getMemory<x86::reg32>(x86::reg32(11224684) /* 0xab466c */) = cpu.eax;
    // 00aa4483  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa448a  68f423ab00             -push 0xab23f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215860 /*0xab23f4*/;
    cpu.esp -= 4;
    // 00aa448f  8b3d502fab00           -mov edi, dword ptr [0xab2f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4495  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4496  a37046ab00             -mov dword ptr [0xab4670], eax
    app->getMemory<x86::reg32>(x86::reg32(11224688) /* 0xab4670 */) = cpu.eax;
    // 00aa449b  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa44a2  680424ab00             -push 0xab2404
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215876 /*0xab2404*/;
    cpu.esp -= 4;
    // 00aa44a7  8b2d502fab00           -mov ebp, dword ptr [0xab2f50]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa44ad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa44ae  a37446ab00             -mov dword ptr [0xab4674], eax
    app->getMemory<x86::reg32>(x86::reg32(11224692) /* 0xab4674 */) = cpu.eax;
    // 00aa44b3  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa44ba  a37846ab00             -mov dword ptr [0xab4678], eax
    app->getMemory<x86::reg32>(x86::reg32(11224696) /* 0xab4678 */) = cpu.eax;
    // 00aa44bf  681824ab00             -push 0xab2418
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215896 /*0xab2418*/;
    cpu.esp -= 4;
    // 00aa44c4  a1502fab00             -mov eax, dword ptr [0xab2f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa44c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa44ca  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa44d1  683024ab00             -push 0xab2430
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215920 /*0xab2430*/;
    cpu.esp -= 4;
    // 00aa44d6  8b15502fab00           -mov edx, dword ptr [0xab2f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa44dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa44dd  a37c46ab00             -mov dword ptr [0xab467c], eax
    app->getMemory<x86::reg32>(x86::reg32(11224700) /* 0xab467c */) = cpu.eax;
    // 00aa44e2  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa44e9  684824ab00             -push 0xab2448
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215944 /*0xab2448*/;
    cpu.esp -= 4;
    // 00aa44ee  8b0d502fab00           -mov ecx, dword ptr [0xab2f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa44f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa44f5  a38046ab00             -mov dword ptr [0xab4680], eax
    app->getMemory<x86::reg32>(x86::reg32(11224704) /* 0xab4680 */) = cpu.eax;
    // 00aa44fa  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4501  686424ab00             -push 0xab2464
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215972 /*0xab2464*/;
    cpu.esp -= 4;
    // 00aa4506  8b1d502fab00           -mov ebx, dword ptr [0xab2f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa450c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa450d  a38446ab00             -mov dword ptr [0xab4684], eax
    app->getMemory<x86::reg32>(x86::reg32(11224708) /* 0xab4684 */) = cpu.eax;
    // 00aa4512  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4519  687424ab00             -push 0xab2474
    app->getMemory<x86::reg32>(cpu.esp-4) = 11215988 /*0xab2474*/;
    cpu.esp -= 4;
    // 00aa451e  8b35502fab00           -mov esi, dword ptr [0xab2f50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4524  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4525  a38846ab00             -mov dword ptr [0xab4688], eax
    app->getMemory<x86::reg32>(x86::reg32(11224712) /* 0xab4688 */) = cpu.eax;
    // 00aa452a  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4531  688824ab00             -push 0xab2488
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216008 /*0xab2488*/;
    cpu.esp -= 4;
    // 00aa4536  8b3d502fab00           -mov edi, dword ptr [0xab2f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa453c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa453d  a38c46ab00             -mov dword ptr [0xab468c], eax
    app->getMemory<x86::reg32>(x86::reg32(11224716) /* 0xab468c */) = cpu.eax;
    // 00aa4542  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4549  689824ab00             -push 0xab2498
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216024 /*0xab2498*/;
    cpu.esp -= 4;
    // 00aa454e  8b2d502fab00           -mov ebp, dword ptr [0xab2f50]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4554  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa4555  a39046ab00             -mov dword ptr [0xab4690], eax
    app->getMemory<x86::reg32>(x86::reg32(11224720) /* 0xab4690 */) = cpu.eax;
    // 00aa455a  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4561  68a824ab00             -push 0xab24a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216040 /*0xab24a8*/;
    cpu.esp -= 4;
    // 00aa4566  a39446ab00             -mov dword ptr [0xab4694], eax
    app->getMemory<x86::reg32>(x86::reg32(11224724) /* 0xab4694 */) = cpu.eax;
    // 00aa456b  a1502fab00             -mov eax, dword ptr [0xab2f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4570  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa4571  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4578  68b824ab00             -push 0xab24b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216056 /*0xab24b8*/;
    cpu.esp -= 4;
    // 00aa457d  8b15502fab00           -mov edx, dword ptr [0xab2f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4583  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4584  a39846ab00             -mov dword ptr [0xab4698], eax
    app->getMemory<x86::reg32>(x86::reg32(11224728) /* 0xab4698 */) = cpu.eax;
    // 00aa4589  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4590  68c824ab00             -push 0xab24c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216072 /*0xab24c8*/;
    cpu.esp -= 4;
    // 00aa4595  8b0d502fab00           -mov ecx, dword ptr [0xab2f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa459b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa459c  a39c46ab00             -mov dword ptr [0xab469c], eax
    app->getMemory<x86::reg32>(x86::reg32(11224732) /* 0xab469c */) = cpu.eax;
    // 00aa45a1  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa45a8  68e024ab00             -push 0xab24e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216096 /*0xab24e0*/;
    cpu.esp -= 4;
    // 00aa45ad  8b1d502fab00           -mov ebx, dword ptr [0xab2f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa45b3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa45b4  a3a046ab00             -mov dword ptr [0xab46a0], eax
    app->getMemory<x86::reg32>(x86::reg32(11224736) /* 0xab46a0 */) = cpu.eax;
    // 00aa45b9  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa45c0  68f424ab00             -push 0xab24f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216116 /*0xab24f4*/;
    cpu.esp -= 4;
    // 00aa45c5  8b35502fab00           -mov esi, dword ptr [0xab2f50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa45cb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa45cc  a3a446ab00             -mov dword ptr [0xab46a4], eax
    app->getMemory<x86::reg32>(x86::reg32(11224740) /* 0xab46a4 */) = cpu.eax;
    // 00aa45d1  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa45d8  680825ab00             -push 0xab2508
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216136 /*0xab2508*/;
    cpu.esp -= 4;
    // 00aa45dd  8b3d502fab00           -mov edi, dword ptr [0xab2f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa45e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa45e4  a3a846ab00             -mov dword ptr [0xab46a8], eax
    app->getMemory<x86::reg32>(x86::reg32(11224744) /* 0xab46a8 */) = cpu.eax;
    // 00aa45e9  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa45f0  a3ac46ab00             -mov dword ptr [0xab46ac], eax
    app->getMemory<x86::reg32>(x86::reg32(11224748) /* 0xab46ac */) = cpu.eax;
    // 00aa45f5  681825ab00             -push 0xab2518
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216152 /*0xab2518*/;
    cpu.esp -= 4;
    // 00aa45fa  8b2d502fab00           -mov ebp, dword ptr [0xab2f50]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4600  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa4601  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4608  682825ab00             -push 0xab2528
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216168 /*0xab2528*/;
    cpu.esp -= 4;
    // 00aa460d  a3b046ab00             -mov dword ptr [0xab46b0], eax
    app->getMemory<x86::reg32>(x86::reg32(11224752) /* 0xab46b0 */) = cpu.eax;
    // 00aa4612  a1502fab00             -mov eax, dword ptr [0xab2f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4617  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa4618  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa461f  684425ab00             -push 0xab2544
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216196 /*0xab2544*/;
    cpu.esp -= 4;
    // 00aa4624  8b15502fab00           -mov edx, dword ptr [0xab2f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa462a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa462b  a3b446ab00             -mov dword ptr [0xab46b4], eax
    app->getMemory<x86::reg32>(x86::reg32(11224756) /* 0xab46b4 */) = cpu.eax;
    // 00aa4630  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4637  685825ab00             -push 0xab2558
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216216 /*0xab2558*/;
    cpu.esp -= 4;
    // 00aa463c  8b0d502fab00           -mov ecx, dword ptr [0xab2f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4642  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4643  a3b846ab00             -mov dword ptr [0xab46b8], eax
    app->getMemory<x86::reg32>(x86::reg32(11224760) /* 0xab46b8 */) = cpu.eax;
    // 00aa4648  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa464f  686c25ab00             -push 0xab256c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216236 /*0xab256c*/;
    cpu.esp -= 4;
    // 00aa4654  8b1d502fab00           -mov ebx, dword ptr [0xab2f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa465a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa465b  a3bc46ab00             -mov dword ptr [0xab46bc], eax
    app->getMemory<x86::reg32>(x86::reg32(11224764) /* 0xab46bc */) = cpu.eax;
    // 00aa4660  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4667  688025ab00             -push 0xab2580
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216256 /*0xab2580*/;
    cpu.esp -= 4;
    // 00aa466c  8b35502fab00           -mov esi, dword ptr [0xab2f50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4672  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4673  a3c046ab00             -mov dword ptr [0xab46c0], eax
    app->getMemory<x86::reg32>(x86::reg32(11224768) /* 0xab46c0 */) = cpu.eax;
    // 00aa4678  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa467f  689c25ab00             -push 0xab259c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216284 /*0xab259c*/;
    cpu.esp -= 4;
    // 00aa4684  8b3d502fab00           -mov edi, dword ptr [0xab2f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa468a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa468b  a3c446ab00             -mov dword ptr [0xab46c4], eax
    app->getMemory<x86::reg32>(x86::reg32(11224772) /* 0xab46c4 */) = cpu.eax;
    // 00aa4690  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4697  68b425ab00             -push 0xab25b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216308 /*0xab25b4*/;
    cpu.esp -= 4;
    // 00aa469c  8b2d502fab00           -mov ebp, dword ptr [0xab2f50]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa46a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa46a3  a3c846ab00             -mov dword ptr [0xab46c8], eax
    app->getMemory<x86::reg32>(x86::reg32(11224776) /* 0xab46c8 */) = cpu.eax;
    // 00aa46a8  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa46af  68c825ab00             -push 0xab25c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216328 /*0xab25c8*/;
    cpu.esp -= 4;
    // 00aa46b4  a3cc46ab00             -mov dword ptr [0xab46cc], eax
    app->getMemory<x86::reg32>(x86::reg32(11224780) /* 0xab46cc */) = cpu.eax;
    // 00aa46b9  a1502fab00             -mov eax, dword ptr [0xab2f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa46be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa46bf  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa46c6  68dc25ab00             -push 0xab25dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216348 /*0xab25dc*/;
    cpu.esp -= 4;
    // 00aa46cb  8b15502fab00           -mov edx, dword ptr [0xab2f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa46d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa46d2  a3d046ab00             -mov dword ptr [0xab46d0], eax
    app->getMemory<x86::reg32>(x86::reg32(11224784) /* 0xab46d0 */) = cpu.eax;
    // 00aa46d7  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa46de  68ec25ab00             -push 0xab25ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216364 /*0xab25ec*/;
    cpu.esp -= 4;
    // 00aa46e3  8b0d502fab00           -mov ecx, dword ptr [0xab2f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa46e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa46ea  a3d446ab00             -mov dword ptr [0xab46d4], eax
    app->getMemory<x86::reg32>(x86::reg32(11224788) /* 0xab46d4 */) = cpu.eax;
    // 00aa46ef  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa46f6  680026ab00             -push 0xab2600
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216384 /*0xab2600*/;
    cpu.esp -= 4;
    // 00aa46fb  8b1d502fab00           -mov ebx, dword ptr [0xab2f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4701  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4702  a3d846ab00             -mov dword ptr [0xab46d8], eax
    app->getMemory<x86::reg32>(x86::reg32(11224792) /* 0xab46d8 */) = cpu.eax;
    // 00aa4707  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa470e  681826ab00             -push 0xab2618
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216408 /*0xab2618*/;
    cpu.esp -= 4;
    // 00aa4713  8b35502fab00           -mov esi, dword ptr [0xab2f50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4719  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa471a  a3dc46ab00             -mov dword ptr [0xab46dc], eax
    app->getMemory<x86::reg32>(x86::reg32(11224796) /* 0xab46dc */) = cpu.eax;
    // 00aa471f  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4726  a3e046ab00             -mov dword ptr [0xab46e0], eax
    app->getMemory<x86::reg32>(x86::reg32(11224800) /* 0xab46e0 */) = cpu.eax;
    // 00aa472b  683026ab00             -push 0xab2630
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216432 /*0xab2630*/;
    cpu.esp -= 4;
    // 00aa4730  8b3d502fab00           -mov edi, dword ptr [0xab2f50]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4736  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4737  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa473e  684026ab00             -push 0xab2640
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216448 /*0xab2640*/;
    cpu.esp -= 4;
    // 00aa4743  8b2d502fab00           -mov ebp, dword ptr [0xab2f50]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4749  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa474a  a3e446ab00             -mov dword ptr [0xab46e4], eax
    app->getMemory<x86::reg32>(x86::reg32(11224804) /* 0xab46e4 */) = cpu.eax;
    // 00aa474f  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4756  684c26ab00             -push 0xab264c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216460 /*0xab264c*/;
    cpu.esp -= 4;
    // 00aa475b  a3e846ab00             -mov dword ptr [0xab46e8], eax
    app->getMemory<x86::reg32>(x86::reg32(11224808) /* 0xab46e8 */) = cpu.eax;
    // 00aa4760  a1502fab00             -mov eax, dword ptr [0xab2f50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4765  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa4766  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa476d  686426ab00             -push 0xab2664
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216484 /*0xab2664*/;
    cpu.esp -= 4;
    // 00aa4772  8b15502fab00           -mov edx, dword ptr [0xab2f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4778  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4779  a3ec46ab00             -mov dword ptr [0xab46ec], eax
    app->getMemory<x86::reg32>(x86::reg32(11224812) /* 0xab46ec */) = cpu.eax;
    // 00aa477e  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4785  687826ab00             -push 0xab2678
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216504 /*0xab2678*/;
    cpu.esp -= 4;
    // 00aa478a  8b0d502fab00           -mov ecx, dword ptr [0xab2f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4790  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4791  a3f046ab00             -mov dword ptr [0xab46f0], eax
    app->getMemory<x86::reg32>(x86::reg32(11224816) /* 0xab46f0 */) = cpu.eax;
    // 00aa4796  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa479d  689026ab00             -push 0xab2690
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216528 /*0xab2690*/;
    cpu.esp -= 4;
    // 00aa47a2  8b1d502fab00           -mov ebx, dword ptr [0xab2f50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa47a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa47a9  a3f446ab00             -mov dword ptr [0xab46f4], eax
    app->getMemory<x86::reg32>(x86::reg32(11224820) /* 0xab46f4 */) = cpu.eax;
    // 00aa47ae  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa47b5  68a826ab00             -push 0xab26a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216552 /*0xab26a8*/;
    cpu.esp -= 4;
    // 00aa47ba  8b35502fab00           -mov esi, dword ptr [0xab2f50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa47c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa47c1  a3f846ab00             -mov dword ptr [0xab46f8], eax
    app->getMemory<x86::reg32>(x86::reg32(11224824) /* 0xab46f8 */) = cpu.eax;
    // 00aa47c6  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa47cd  a3fc46ab00             -mov dword ptr [0xab46fc], eax
    app->getMemory<x86::reg32>(x86::reg32(11224828) /* 0xab46fc */) = cpu.eax;
    // 00aa47d2  a1a846ab00             -mov eax, dword ptr [0xab46a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11224744) /* 0xab46a8 */);
    // 00aa47d7  a31047ab00             -mov dword ptr [0xab4710], eax
    app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */) = cpu.eax;
    // 00aa47dc  a30c47ab00             -mov dword ptr [0xab470c], eax
    app->getMemory<x86::reg32>(x86::reg32(11224844) /* 0xab470c */) = cpu.eax;
    // 00aa47e1  a1ac46ab00             -mov eax, dword ptr [0xab46ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11224748) /* 0xab46ac */);
    // 00aa47e6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa47eb  a31046ab00             -mov dword ptr [0xab4610], eax
    app->getMemory<x86::reg32>(x86::reg32(11224592) /* 0xab4610 */) = cpu.eax;
    // 00aa47f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa47f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa47f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa47f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa47f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa47f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa47f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa47f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void sub_aa4800(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4802  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4803  8b15502fab00           -mov edx, dword ptr [0xab2f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */);
    // 00aa4809  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa480b  750c                   -jne 0xaa4819
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4819;
    }
    // 00aa480d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa480f  891d502fab00           -mov dword ptr [0xab2f50], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */) = cpu.ebx;
    // 00aa4815  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4816  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4817  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4818  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa4819:
    // 00aa4819  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa481a  2eff159013ab00         -call dword ptr cs:[0xab1390]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211664) /* 0xab1390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4821  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa4823  891d502fab00           -mov dword ptr [0xab2f50], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218768) /* 0xab2f50 */) = cpu.ebx;
    // 00aa4829  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa482a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa482b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa482c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa4830(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4830  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4831  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa4834  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa4836  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00aa4839  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aa483c  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00aa483f  dc05bc26ab00           -fadd qword ptr [0xab26bc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(11216572) /* 0xab26bc */));
    // 00aa4845  dd05c426ab00           -fld qword ptr [0xab26c4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(11216580) /* 0xab26c4 */)));
    // 00aa484b  e852300000             -call 0xaa78a2
    cpu.esp -= 4;
    sub_aa78a2(app, cpu);
    if (cpu.terminate) return;
    // 00aa4850  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa4852  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00aa4857  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00aa485a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa485c  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00aa485f  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00aa4862  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa4864  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa4867  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4868  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void sub_aa4870(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4870  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4871  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4872  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4873  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4874  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa4877  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aa4879  b83f000000             -mov eax, 0x3f
    cpu.eax = 63 /*0x3f*/;
    // 00aa487e  e8adffffff             -call 0xaa4830
    cpu.esp -= 4;
    sub_aa4830(app, cpu);
    if (cpu.terminate) return;
    // 00aa4883  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00aa4887  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00aa4889  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00aa488b  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00aa488d  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00aa488f  ddd2                   -fst st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    // 00aa4891  d9f8                   -fprem 
    cpu.fpu.st(0) = cpu.fpu.rem(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00aa4893  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00aa4895  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa4897  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00aa4899  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa489b  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00aa489d  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00aa489f  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00aa48a1  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00aa48a3  bf0000803f             -mov edi, 0x3f800000
    cpu.edi = 1065353216 /*0x3f800000*/;
    // 00aa48a8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa48aa  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00aa48ae:
    // 00aa48ae  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa48b0  e87bffffff             -call 0xaa4830
    cpu.esp -= 4;
    sub_aa4830(app, cpu);
    if (cpu.terminate) return;
    // 00aa48b5  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00aa48b9  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00aa48bb  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00aa48bd  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00aa48bf  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00aa48c1  ddd2                   -fst st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    // 00aa48c3  d9f8                   -fprem 
    cpu.fpu.st(0) = cpu.fpu.rem(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00aa48c5  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00aa48c7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa48c9  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00aa48cb  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa48cd  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00aa48cf  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00aa48d1  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00aa48d5  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa48d9  817c24040000803f       +cmp dword ptr [esp + 4], 0x3f800000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1065353216 /*0x3f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa48e1  7f3a                   -jg 0xaa491d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aa491d;
    }
    // 00aa48e3  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00aa48e5  d85c2404               +fcomp dword ptr [esp + 4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    cpu.fpu.pop();
    // 00aa48e9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aa48eb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa48ec  7606                   -jbe 0xaa48f4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa48f4;
    }
    // 00aa48ee  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aa48f0  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x00aa48f4:
    // 00aa48f4  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00aa48f8  d80dcc26ab00           -fmul dword ptr [0xab26cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11216588) /* 0xab26cc */));
    // 00aa48fe  41                     -inc ecx
    (cpu.ecx)++;
    // 00aa48ff  42                     -inc edx
    (cpu.edx)++;
    // 00aa4900  d9542404               -fst dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    // 00aa4904  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa4907  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00aa490a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa490b  8841ff                 -mov byte ptr [ecx - 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00aa490e  83fa40                 +cmp edx, 0x40
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4911  7c9b                   -jl 0xaa48ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa48ae;
    }
    // 00aa4913  83c40c                 +add esp, 0xc
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
    // 00aa4916  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4917  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4918  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4919  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa491a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aa491d:
    // 00aa491d  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00aa4921  ebd1                   -jmp 0xaa48f4
    goto L_0x00aa48f4;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_aa4930(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4931  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4932  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4933  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4935  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4937  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4939  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa493b  ff156846ab00           -call dword ptr [0xab4668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224680) /* 0xab4668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4941  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4943  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4945  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00aa4947  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00aa4949  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00aa494b  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00aa494d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa494f  ff15c046ab00           -call dword ptr [0xab46c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224768) /* 0xab46c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4955  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa4959  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa495a  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa495e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa495f  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa4963  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4964  ff150847ab00           -call dword ptr [0xab4708]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224840) /* 0xab4708 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa496a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa496c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa496e  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa4970  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa4972  ff156846ab00           -call dword ptr [0xab4668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224680) /* 0xab4668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4978  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa497a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa497c  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00aa497e  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00aa4980  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00aa4982  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00aa4984  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4986  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00aa498a  ff15c046ab00           -call dword ptr [0xab46c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224768) /* 0xab46c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4990  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4991  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa4995  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4996  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4997  ff150847ab00           -call dword ptr [0xab4708]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224840) /* 0xab4708 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa499d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa499e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa499f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa49a0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_aa49b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa49b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa49b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa49b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa49b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa49b5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa49b7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa49b9  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa49bb  ff156846ab00           -call dword ptr [0xab4668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224680) /* 0xab4668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa49c1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa49c3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa49c5  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00aa49c7  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00aa49c9  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00aa49cb  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00aa49cd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa49cf  ff15c046ab00           -call dword ptr [0xab46c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224768) /* 0xab46c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa49d5  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa49d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa49da  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa49de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa49df  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa49e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa49e4  ff150047ab00           -call dword ptr [0xab4700]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224832) /* 0xab4700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa49ea  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa49ec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa49ee  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa49f0  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa49f2  ff156846ab00           -call dword ptr [0xab4668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224680) /* 0xab4668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa49f8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa49fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa49fc  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00aa49fe  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00aa4a00  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00aa4a02  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00aa4a04  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4a06  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00aa4a0a  ff15c046ab00           -call dword ptr [0xab46c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224768) /* 0xab46c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4a10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4a11  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa4a15  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4a16  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4a17  ff150047ab00           -call dword ptr [0xab4700]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224832) /* 0xab4700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4a1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4a1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4a1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4a20  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_aa4a30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4a30  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_aa4a40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4a40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4a41  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa4a43  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa4a45  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa4a47  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa4a4b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4a4c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa4a50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4a51  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa4a55  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4a56  ff15e046ab00           -call dword ptr [0xab46e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224800) /* 0xab46e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4a5c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4a5d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void sub_aa4a60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4a60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4a61  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4a63  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa4a65  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa4a67  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa4a6b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4a6c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa4a70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4a71  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa4a75  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4a76  ff15e046ab00           -call dword ptr [0xab46e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224800) /* 0xab46e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4a7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4a7d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void sub_aa4a80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4a80  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa4a84  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4a85  68d026ab00             -push 0xab26d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 11216592 /*0xab26d0*/;
    cpu.esp -= 4;
    // 00aa4a8a  e8812f0000             -call 0xaa7a10
    cpu.esp -= 4;
    sub_aa7a10(app, cpu);
    if (cpu.terminate) return;
    // 00aa4a8f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aa4a92  b87a33ab00             -mov eax, 0xab337a
    cpu.eax = 11219834 /*0xab337a*/;
    // 00aa4a97  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa4a9b  e8a02f0000             -call 0xaa7a40
    cpu.esp -= 4;
    sub_aa7a40(app, cpu);
    if (cpu.terminate) return;
    // 00aa4aa0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa4aa2  7403                   -je 0xaa4aa7
    if (cpu.flags.zf)
    {
        goto L_0x00aa4aa7;
    }
    // 00aa4aa4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa4aa7:
    // 00aa4aa7  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00aa4aac  e8a32f0000             -call 0xaa7a54
    cpu.esp -= 4;
    sub_aa7a54(app, cpu);
    if (cpu.terminate) return;
    // 00aa4ab1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void sub_aa4ac0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4ac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4ac2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4ac3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4ac4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4ac5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa4ac6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa4ac9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aa4acc  b94030ab00             -mov ecx, 0xab3040
    cpu.ecx = 11219008 /*0xab3040*/;
    // 00aa4ad1  8b1d1c47ab00           -mov ebx, dword ptr [0xab471c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11224860) /* 0xab471c */);
    // 00aa4ad7  8b151847ab00           -mov edx, dword ptr [0xab4718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11224856) /* 0xab4718 */);
    // 00aa4add  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa4adf  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00aa4ae2  83fa01                 +cmp edx, 1
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
    // 00aa4ae5  0f8548010000           -jne 0xaa4c33
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4c33;
    }
    // 00aa4aeb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00aa4aed:
    // 00aa4aed  a3f82eab00             -mov dword ptr [0xab2ef8], eax
    app->getMemory<x86::reg32>(x86::reg32(11218680) /* 0xab2ef8 */) = cpu.eax;
    // 00aa4af2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4af4  7506                   -jne 0xaa4afc
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4afc;
    }
    // 00aa4af6  8b2d2847ab00           -mov ebp, dword ptr [0xab4728]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11224872) /* 0xab4728 */);
L_0x00aa4afc:
    // 00aa4afc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aa4afe  0f8536010000           -jne 0xaa4c3a
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4c3a;
    }
L_0x00aa4b04:
    // 00aa4b04  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00aa4b09:
    // 00aa4b09  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00aa4b0c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aa4b0e  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00aa4b11  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aa4b14  c1ff03                 -sar edi, 3
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (3 /*0x3*/ % 32));
    // 00aa4b17  0faff8                 -imul edi, eax
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00aa4b1a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aa4b1c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00aa4b1f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa4b21  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00aa4b23  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00aa4b26  8139c0030000           +cmp dword ptr [ecx], 0x3c0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(960 /*0x3c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4b2c  7507                   -jne 0xaa4b35
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4b35;
    }
    // 00aa4b2e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aa4b30  7503                   -jne 0xaa4b35
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4b35;
    }
    // 00aa4b32  896914                 -mov dword ptr [ecx + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebp;
L_0x00aa4b35:
    // 00aa4b35  813920030000           +cmp dword ptr [ecx], 0x320
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(800 /*0x320*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4b3b  7e10                   -jle 0xaa4b4d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa4b4d;
    }
    // 00aa4b3d  833df82eab0000         +cmp dword ptr [0xab2ef8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218680) /* 0xab2ef8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4b44  7407                   -je 0xaa4b4d
    if (cpu.flags.zf)
    {
        goto L_0x00aa4b4d;
    }
    // 00aa4b46  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00aa4b4d:
    // 00aa4b4d  83791000               +cmp dword ptr [ecx + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4b51  0f84ea000000           -je 0xaa4c41
    if (cpu.flags.zf)
    {
        goto L_0x00aa4c41;
    }
    // 00aa4b57  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00aa4b5a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa4b5c  0f8edf000000           -jle 0xaa4c41
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa4c41;
    }
    // 00aa4b62  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00aa4b65  8b7914                 -mov edi, dword ptr [ecx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00aa4b68  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00aa4b6b  83ff03                 +cmp edi, 3
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
    // 00aa4b6e  7e07                   -jle 0xaa4b77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa4b77;
    }
    // 00aa4b70  c7411403000000         -mov dword ptr [ecx + 0x14], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 3 /*0x3*/;
L_0x00aa4b77:
    // 00aa4b77  83791803               +cmp dword ptr [ecx + 0x18], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4b7b  7e07                   -jle 0xaa4b84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa4b84;
    }
    // 00aa4b7d  c7411803000000         -mov dword ptr [ecx + 0x18], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 3 /*0x3*/;
L_0x00aa4b84:
    // 00aa4b84  46                     -inc esi
    (cpu.esi)++;
    // 00aa4b85  83c128                 -add ecx, 0x28
    (cpu.ecx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00aa4b88  83fe10                 +cmp esi, 0x10
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
    // 00aa4b8b  0f8e78ffffff           -jle 0xaa4b09
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa4b09;
    }
    // 00aa4b91  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa4b94  a11847ab00             -mov eax, dword ptr [0xab4718]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11224856) /* 0xab4718 */);
    // 00aa4b99  89416c                 -mov dword ptr [ecx + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 00aa4b9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4b9e  754c                   -jne 0xaa4bec
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4bec;
    }
    // 00aa4ba0  a12047ab00             -mov eax, dword ptr [0xab4720]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11224864) /* 0xab4720 */);
    // 00aa4ba5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aa4ba7  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00aa4baa  83f901                 +cmp ecx, 1
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
    // 00aa4bad  750a                   -jne 0xaa4bb9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4bb9;
    }
    // 00aa4baf  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa4bb2  c7416c02000000         -mov dword ptr [ecx + 0x6c], 2
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = 2 /*0x2*/;
L_0x00aa4bb9:
    // 00aa4bb9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aa4bbb  c1f90c                 -sar ecx, 0xc
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (12 /*0xc*/ % 32));
    // 00aa4bbe  83f901                 +cmp ecx, 1
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
    // 00aa4bc1  750a                   -jne 0xaa4bcd
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4bcd;
    }
    // 00aa4bc3  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa4bc6  c7416c03000000         -mov dword ptr [ecx + 0x6c], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = 3 /*0x3*/;
L_0x00aa4bcd:
    // 00aa4bcd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4bcf  751b                   -jne 0xaa4bec
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4bec;
    }
    // 00aa4bd1  833d1c47ab0006         +cmp dword ptr [0xab471c], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11224860) /* 0xab471c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4bd8  7c12                   -jl 0xaa4bec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa4bec;
    }
    // 00aa4bda  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa4bdc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa4bdf  891d102fab00           -mov dword ptr [0xab2f10], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218704) /* 0xab2f10 */) = cpu.ebx;
    // 00aa4be5  c7406c03000000         -mov dword ptr [eax + 0x6c], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 3 /*0x3*/;
L_0x00aa4bec:
    // 00aa4bec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4bee  ff15d046ab00           -call dword ptr [0xab46d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224784) /* 0xab46d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4bf4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4bf6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa4bf8  ff15cc46ab00           -call dword ptr [0xab46cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224780) /* 0xab46cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4bfe  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4c00  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa4c02  ff15cc46ab00           -call dword ptr [0xab46cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224780) /* 0xab46cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4c08  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa4c0a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa4c0d  895870                 -mov dword ptr [eax + 0x70], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ebx;
    // 00aa4c10  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa4c12  7e0b                   -jle 0xaa4c1f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa4c1f;
    }
    // 00aa4c14  8d430f                 -lea eax, [ebx + 0xf]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 00aa4c17  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa4c1a  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00aa4c1c  894170                 -mov dword ptr [ecx + 0x70], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */) = cpu.eax;
L_0x00aa4c1f:
    // 00aa4c1f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa4c22  c7407401000000         -mov dword ptr [eax + 0x74], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = 1 /*0x1*/;
    // 00aa4c29  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa4c2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4c2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4c2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4c2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4c30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4c31  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4c32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa4c33:
    // 00aa4c33  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa4c35  e9b3feffff             -jmp 0xaa4aed
    goto L_0x00aa4aed;
L_0x00aa4c3a:
    // 00aa4c3a  01db                   +add ebx, ebx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa4c3c  e9c3feffff             -jmp 0xaa4b04
    goto L_0x00aa4b04;
L_0x00aa4c41:
    // 00aa4c41  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00aa4c48  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00aa4c4b  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00aa4c4e  e931ffffff             -jmp 0xaa4b84
    goto L_0x00aa4b84;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_aa4c60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4c60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4c61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4c62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4c63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa4c64  8b15542fab00           -mov edx, dword ptr [0xab2f54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218772) /* 0xab2f54 */);
    // 00aa4c6a  bd542fab00             -mov ebp, 0xab2f54
    cpu.ebp = 11218772 /*0xab2f54*/;
    // 00aa4c6f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa4c71  7407                   -je 0xaa4c7a
    if (cpu.flags.zf)
    {
        goto L_0x00aa4c7a;
    }
L_0x00aa4c73:
    // 00aa4c73  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aa4c75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4c76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4c77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4c78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4c79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa4c7a:
    // 00aa4c7a  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00aa4c7f  b958464433             -mov ecx, 0x33444658
    cpu.ecx = 860112472 /*0x33444658*/;
    // 00aa4c84  be68000000             -mov esi, 0x68
    cpu.esi = 104 /*0x68*/;
    // 00aa4c89  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aa4c8b  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00aa4c90  e81b2e0000             -call 0xaa7ab0
    cpu.esp -= 4;
    sub_aa7ab0(app, cpu);
    if (cpu.terminate) return;
    // 00aa4c95  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00aa4c9a  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 00aa4c9f  890d542fab00           -mov dword ptr [0xab2f54], ecx
    app->getMemory<x86::reg32>(x86::reg32(11218772) /* 0xab2f54 */) = cpu.ecx;
    // 00aa4ca5  89355c2fab00           -mov dword ptr [0xab2f5c], esi
    app->getMemory<x86::reg32>(x86::reg32(11218780) /* 0xab2f5c */) = cpu.esi;
    // 00aa4cab  893d642fab00           -mov dword ptr [0xab2f64], edi
    app->getMemory<x86::reg32>(x86::reg32(11218788) /* 0xab2f64 */) = cpu.edi;
    // 00aa4cb1  893d6c2fab00           -mov dword ptr [0xab2f6c], edi
    app->getMemory<x86::reg32>(x86::reg32(11218796) /* 0xab2f6c */) = cpu.edi;
    // 00aa4cb7  893d702fab00           -mov dword ptr [0xab2f70], edi
    app->getMemory<x86::reg32>(x86::reg32(11218800) /* 0xab2f70 */) = cpu.edi;
    // 00aa4cbd  893d782fab00           -mov dword ptr [0xab2f78], edi
    app->getMemory<x86::reg32>(x86::reg32(11218808) /* 0xab2f78 */) = cpu.edi;
    // 00aa4cc3  893d7c2fab00           -mov dword ptr [0xab2f7c], edi
    app->getMemory<x86::reg32>(x86::reg32(11218812) /* 0xab2f7c */) = cpu.edi;
    // 00aa4cc9  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00aa4cce  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00aa4cd3  bf1830ab00             -mov edi, 0xab3018
    cpu.edi = 11218968 /*0xab3018*/;
    // 00aa4cd8  891d582fab00           -mov dword ptr [0xab2f58], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218776) /* 0xab2f58 */) = cpu.ebx;
    // 00aa4cde  a3682fab00             -mov dword ptr [0xab2f68], eax
    app->getMemory<x86::reg32>(x86::reg32(11218792) /* 0xab2f68 */) = cpu.eax;
    // 00aa4ce3  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00aa4ce8  8a25602fab00           -mov ah, byte ptr [0xab2f60]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(11218784) /* 0xab2f60 */);
    // 00aa4cee  890d882fab00           -mov dword ptr [0xab2f88], ecx
    app->getMemory<x86::reg32>(x86::reg32(11218824) /* 0xab2f88 */) = cpu.ecx;
    // 00aa4cf4  8935902fab00           -mov dword ptr [0xab2f90], esi
    app->getMemory<x86::reg32>(x86::reg32(11218832) /* 0xab2f90 */) = cpu.esi;
    // 00aa4cfa  893d942fab00           -mov dword ptr [0xab2f94], edi
    app->getMemory<x86::reg32>(x86::reg32(11218836) /* 0xab2f94 */) = cpu.edi;
    // 00aa4d00  bed426ab00             -mov esi, 0xab26d4
    cpu.esi = 11216596 /*0xab26d4*/;
    // 00aa4d05  80cc0e                 -or ah, 0xe
    cpu.ah |= x86::reg8(x86::sreg8(14 /*0xe*/));
    // 00aa4d08  891d742fab00           -mov dword ptr [0xab2f74], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218804) /* 0xab2f74 */) = cpu.ebx;
    // 00aa4d0e  8d7d4c                 -lea edi, [ebp + 0x4c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(76) /* 0x4c */);
    // 00aa4d11  bb0030ab00             -mov ebx, 0xab3000
    cpu.ebx = 11218944 /*0xab3000*/;
    // 00aa4d16  8825602fab00           -mov byte ptr [0xab2f60], ah
    app->getMemory<x86::reg8>(x86::reg32(11218784) /* 0xab2f60 */) = cpu.ah;
    // 00aa4d1c  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00aa4d1e  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00aa4d23  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00aa4d26  891d8c2fab00           -mov dword ptr [0xab2f8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218828) /* 0xab2f8c */) = cpu.ebx;
    // 00aa4d2c  8815602fab00           -mov byte ptr [0xab2f60], dl
    app->getMemory<x86::reg8>(x86::reg32(11218784) /* 0xab2f60 */) = cpu.dl;
    // 00aa4d32  bad42fab00             -mov edx, 0xab2fd4
    cpu.edx = 11218900 /*0xab2fd4*/;
    // 00aa4d37  a3802fab00             -mov dword ptr [0xab2f80], eax
    app->getMemory<x86::reg32>(x86::reg32(11218816) /* 0xab2f80 */) = cpu.eax;
    // 00aa4d3c  8915842fab00           -mov dword ptr [0xab2f84], edx
    app->getMemory<x86::reg32>(x86::reg32(11218820) /* 0xab2f84 */) = cpu.edx;
    // 00aa4d42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00aa4d43:
    // 00aa4d43  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aa4d45  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00aa4d47  3c00                   +cmp al, 0
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
    // 00aa4d49  7410                   -je 0xaa4d5b
    if (cpu.flags.zf)
    {
        goto L_0x00aa4d5b;
    }
    // 00aa4d4b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00aa4d4e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa4d51  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00aa4d54  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa4d57  3c00                   +cmp al, 0
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
    // 00aa4d59  75e8                   -jne 0xaa4d43
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4d43;
    }
L_0x00aa4d5b:
    // 00aa4d5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4d5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa4d5e  8a35f42eab00           -mov dh, byte ptr [0xab2ef4]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(11218676) /* 0xab2ef4 */);
    // 00aa4d64  a3c02fab00             -mov dword ptr [0xab2fc0], eax
    app->getMemory<x86::reg32>(x86::reg32(11218880) /* 0xab2fc0 */) = cpu.eax;
    // 00aa4d69  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 00aa4d6c  0f856d000000           -jne 0xaa4ddf
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4ddf;
    }
    // 00aa4d72  e8a9f4ffff             -call 0xaa4220
    cpu.esp -= 4;
    sub_aa4220(app, cpu);
    if (cpu.terminate) return;
    // 00aa4d77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4d79  0f84f4feffff           -je 0xaa4c73
    if (cpu.flags.zf)
    {
        goto L_0x00aa4c73;
    }
    // 00aa4d7f  833d1446ab0000         +cmp dword ptr [0xab4614], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11224596) /* 0xab4614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4d86  744b                   -je 0xaa4dd3
    if (cpu.flags.zf)
    {
        goto L_0x00aa4dd3;
    }
    // 00aa4d88  833d1c46ab0000         +cmp dword ptr [0xab461c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11224604) /* 0xab461c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4d8f  7442                   -je 0xaa4dd3
    if (cpu.flags.zf)
    {
        goto L_0x00aa4dd3;
    }
    // 00aa4d91  833d1846ab0000         +cmp dword ptr [0xab4618], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11224600) /* 0xab4618 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4d98  7439                   -je 0xaa4dd3
    if (cpu.flags.zf)
    {
        goto L_0x00aa4dd3;
    }
    // 00aa4d9a  681447ab00             -push 0xab4714
    app->getMemory<x86::reg32>(cpu.esp-4) = 11224852 /*0xab4714*/;
    cpu.esp -= 4;
    // 00aa4d9f  ff151c46ab00           -call dword ptr [0xab461c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224604) /* 0xab461c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4da5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aa4da7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4da9  7406                   -je 0xaa4db1
    if (cpu.flags.zf)
    {
        goto L_0x00aa4db1;
    }
    // 00aa4dab  8b3d1447ab00           -mov edi, dword ptr [0xab4714]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11224852) /* 0xab4714 */);
L_0x00aa4db1:
    // 00aa4db1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aa4db3  7e1e                   -jle 0xaa4dd3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa4dd3;
    }
    // 00aa4db5  ff151446ab00           -call dword ptr [0xab4614]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224596) /* 0xab4614 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4dbb  681447ab00             -push 0xab4714
    app->getMemory<x86::reg32>(cpu.esp-4) = 11224852 /*0xab4714*/;
    cpu.esp -= 4;
    // 00aa4dc0  ff151846ab00           -call dword ptr [0xab4618]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224600) /* 0xab4618 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4dc6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aa4dc8  e8f3fcffff             -call 0xaa4ac0
    cpu.esp -= 4;
    sub_aa4ac0(app, cpu);
    if (cpu.terminate) return;
    // 00aa4dcd  ff152046ab00           -call dword ptr [0xab4620]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224608) /* 0xab4620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa4dd3:
    // 00aa4dd3  e828faffff             -call 0xaa4800
    cpu.esp -= 4;
    sub_aa4800(app, cpu);
    if (cpu.terminate) return;
    // 00aa4dd8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aa4dda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4ddb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4ddc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4ddd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4dde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa4ddf:
    // 00aa4ddf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aa4de1  e8dafcffff             -call 0xaa4ac0
    cpu.esp -= 4;
    sub_aa4ac0(app, cpu);
    if (cpu.terminate) return;
    // 00aa4de6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aa4de8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4de9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4dea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4deb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4dec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa4df0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4df1  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00aa4df4  b8e026ab00             -mov eax, 0xab26e0
    cpu.eax = 11216608 /*0xab26e0*/;
    // 00aa4df9  e8d22c0000             -call 0xaa7ad0
    cpu.esp -= 4;
    sub_aa7ad0(app, cpu);
    if (cpu.terminate) return;
    // 00aa4dfe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa4e00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4e02  0f85cb000000           -jne 0xaa4ed3
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4ed3;
    }
    // 00aa4e08  e813f4ffff             -call 0xaa4220
    cpu.esp -= 4;
    sub_aa4220(app, cpu);
    if (cpu.terminate) return;
    // 00aa4e0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4e0f  0f84b7000000           -je 0xaa4ecc
    if (cpu.flags.zf)
    {
        goto L_0x00aa4ecc;
    }
    // 00aa4e15  833d1446ab0000         +cmp dword ptr [0xab4614], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11224596) /* 0xab4614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4e1c  0f84a5000000           -je 0xaa4ec7
    if (cpu.flags.zf)
    {
        goto L_0x00aa4ec7;
    }
    // 00aa4e22  833d1c46ab0000         +cmp dword ptr [0xab461c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11224604) /* 0xab461c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4e29  0f8498000000           -je 0xaa4ec7
    if (cpu.flags.zf)
    {
        goto L_0x00aa4ec7;
    }
    // 00aa4e2f  833d1846ab0000         +cmp dword ptr [0xab4618], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11224600) /* 0xab4618 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4e36  0f848b000000           -je 0xaa4ec7
    if (cpu.flags.zf)
    {
        goto L_0x00aa4ec7;
    }
    // 00aa4e3c  681447ab00             -push 0xab4714
    app->getMemory<x86::reg32>(cpu.esp-4) = 11224852 /*0xab4714*/;
    cpu.esp -= 4;
    // 00aa4e41  ff151c46ab00           -call dword ptr [0xab461c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224604) /* 0xab461c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4e47  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa4e49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4e4b  7406                   -je 0xaa4e53
    if (cpu.flags.zf)
    {
        goto L_0x00aa4e53;
    }
    // 00aa4e4d  8b1d1447ab00           -mov ebx, dword ptr [0xab4714]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11224852) /* 0xab4714 */);
L_0x00aa4e53:
    // 00aa4e53  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa4e55  0f8e6c000000           -jle 0xaa4ec7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa4ec7;
    }
    // 00aa4e5b  ff151446ab00           -call dword ptr [0xab4614]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224596) /* 0xab4614 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4e61  681447ab00             -push 0xab4714
    app->getMemory<x86::reg32>(cpu.esp-4) = 11224852 /*0xab4714*/;
    cpu.esp -= 4;
    // 00aa4e66  ff151846ab00           -call dword ptr [0xab4618]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224600) /* 0xab4618 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4e6c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa4e6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4e70  744f                   -je 0xaa4ec1
    if (cpu.flags.zf)
    {
        goto L_0x00aa4ec1;
    }
    // 00aa4e72  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa4e74  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa4e75  ff15dc46ab00           -call dword ptr [0xab46dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224796) /* 0xab46dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4e7b  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00aa4e7e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa4e80  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00aa4e82  7414                   -je 0xaa4e98
    if (cpu.flags.zf)
    {
        goto L_0x00aa4e98;
    }
L_0x00aa4e84:
    // 00aa4e84  8a1404                 -mov dl, byte ptr [esp + eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 00aa4e87  fec2                   -inc dl
    (cpu.dl)++;
    // 00aa4e89  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aa4e8f  f6827835ab0020         +test byte ptr [edx + 0xab3578], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11220344) /* 0xab3578 */) & 32 /*0x20*/));
    // 00aa4e96  7444                   -je 0xaa4edc
    if (cpu.flags.zf)
    {
        goto L_0x00aa4edc;
    }
L_0x00aa4e98:
    // 00aa4e98  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00aa4e9a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00aa4e9c  baec26ab00             -mov edx, 0xab26ec
    cpu.edx = 11216620 /*0xab26ec*/;
    // 00aa4ea1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa4ea3  e8882c0000             -call 0xaa7b30
    cpu.esp -= 4;
    sub_aa7b30(app, cpu);
    if (cpu.terminate) return;
    // 00aa4ea8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4eaa  7c3b                   -jl 0xaa4ee7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa4ee7;
    }
    // 00aa4eac  baf426ab00             -mov edx, 0xab26f4
    cpu.edx = 11216628 /*0xab26f4*/;
    // 00aa4eb1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa4eb3  e8782c0000             -call 0xaa7b30
    cpu.esp -= 4;
    sub_aa7b30(app, cpu);
    if (cpu.terminate) return;
    // 00aa4eb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4eba  7e2f                   -jle 0xaa4eeb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa4eeb;
    }
    // 00aa4ebc  bb5f000000             -mov ebx, 0x5f
    cpu.ebx = 95 /*0x5f*/;
L_0x00aa4ec1:
    // 00aa4ec1  ff152046ab00           -call dword ptr [0xab4620]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224608) /* 0xab4620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa4ec7:
    // 00aa4ec7  e834f9ffff             -call 0xaa4800
    cpu.esp -= 4;
    sub_aa4800(app, cpu);
    if (cpu.terminate) return;
L_0x00aa4ecc:
    // 00aa4ecc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa4ece  83c450                 +add esp, 0x50
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
    // 00aa4ed1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4ed2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa4ed3:
    // 00aa4ed3  e8082d0000             -call 0xaa7be0
    cpu.esp -= 4;
    sub_aa7be0(app, cpu);
    if (cpu.terminate) return;
    // 00aa4ed8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa4eda  ebf0                   -jmp 0xaa4ecc
    goto L_0x00aa4ecc;
L_0x00aa4edc:
    // 00aa4edc  8a740401               -mov dh, byte ptr [esp + eax + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 00aa4ee0  40                     -inc eax
    (cpu.eax)++;
    // 00aa4ee1  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00aa4ee3  759f                   -jne 0xaa4e84
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4e84;
    }
    // 00aa4ee5  ebb1                   -jmp 0xaa4e98
    goto L_0x00aa4e98;
L_0x00aa4ee7:
    // 00aa4ee7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00aa4ee9  ebd6                   -jmp 0xaa4ec1
    goto L_0x00aa4ec1;
L_0x00aa4eeb:
    // 00aa4eeb  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 00aa4ef0  ff152046ab00           -call dword ptr [0xab4620]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224608) /* 0xab4620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4ef6  e805f9ffff             -call 0xaa4800
    cpu.esp -= 4;
    sub_aa4800(app, cpu);
    if (cpu.terminate) return;
    // 00aa4efb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa4efd  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00aa4f00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4f01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void sub_aa4f10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4f10  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa4f14  8b151447ab00           -mov edx, dword ptr [0xab4714]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11224852) /* 0xab4714 */);
    // 00aa4f1a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa4f1c  39d1                   +cmp ecx, edx
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
    // 00aa4f1e  7c03                   -jl 0xaa4f23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa4f23;
    }
    // 00aa4f20  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aa4f23:
    // 00aa4f23  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4f24  ff152446ab00           -call dword ptr [0xab4624]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224612) /* 0xab4624 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4f2a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa4f2f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void sub_aa4f40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4f40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa4f41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa4f42  e8b9010000             -call 0xaa5100
    cpu.esp -= 4;
    sub_aa5100(app, cpu);
    if (cpu.terminate) return;
    // 00aa4f47  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4f48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4f49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void sub_aa4f50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa4f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa4f51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4f52  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa4f55  8a25f42eab00           -mov ah, byte ptr [0xab2ef4]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(11218676) /* 0xab2ef4 */);
    // 00aa4f5b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa4f5d  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 00aa4f60  7547                   -jne 0xaa4fa9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4fa9;
    }
    // 00aa4f62  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa4f64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00aa4f66:
    // 00aa4f66  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aa4f69  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa4f6c  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00aa4f6f  40                     -inc eax
    (cpu.eax)++;
    // 00aa4f70  d99a0c42ab00           -fstp dword ptr [edx + 0xab420c]
    app->getMemory<float>(cpu.edx + x86::reg32(11223564) /* 0xab420c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa4f76  3d00010000             +cmp eax, 0x100
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4f7b  7ce9                   -jl 0xaa4f66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa4f66;
    }
    // 00aa4f7d  833d342fab0000         +cmp dword ptr [0xab2f34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218740) /* 0xab2f34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa4f84  742b                   -je 0xaa4fb1
    if (cpu.flags.zf)
    {
        goto L_0x00aa4fb1;
    }
L_0x00aa4f86:
    // 00aa4f86  8b35402fab00           -mov esi, dword ptr [0xab2f40]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218752) /* 0xab2f40 */);
    // 00aa4f8c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa4f8e  7510                   -jne 0xaa4fa0
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4fa0;
    }
    // 00aa4f90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4f91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4f92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4f93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa4f94  2eff156813ab00         -call dword ptr cs:[0xab1368]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211624) /* 0xab1368 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4f9b  a3402fab00             -mov dword ptr [0xab2f40], eax
    app->getMemory<x86::reg32>(x86::reg32(11218752) /* 0xab2f40 */) = cpu.eax;
L_0x00aa4fa0:
    // 00aa4fa0  e87bf2ffff             -call 0xaa4220
    cpu.esp -= 4;
    sub_aa4220(app, cpu);
    if (cpu.terminate) return;
    // 00aa4fa5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4fa7  7514                   -jne 0xaa4fbd
    if (!cpu.flags.zf)
    {
        goto L_0x00aa4fbd;
    }
L_0x00aa4fa9:
    // 00aa4fa9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa4fab  83c404                 +add esp, 4
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
    // 00aa4fae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4faf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa4fb0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa4fb1:
    // 00aa4fb1  c705342fab00804aaa00   -mov dword ptr [0xab2f34], 0xaa4a80
    app->getMemory<x86::reg32>(x86::reg32(11218740) /* 0xab2f34 */) = 11160192 /*0xaa4a80*/;
    // 00aa4fbb  ebc9                   -jmp 0xaa4f86
    goto L_0x00aa4f86;
L_0x00aa4fbd:
    // 00aa4fbd  ff151446ab00           -call dword ptr [0xab4614]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224596) /* 0xab4614 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4fc3  681447ab00             -push 0xab4714
    app->getMemory<x86::reg32>(cpu.esp-4) = 11224852 /*0xab4714*/;
    cpu.esp -= 4;
    // 00aa4fc8  ff151846ab00           -call dword ptr [0xab4618]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224600) /* 0xab4618 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa4fce  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa4fd0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4fd2  74d5                   -je 0xaa4fa9
    if (cpu.flags.zf)
    {
        goto L_0x00aa4fa9;
    }
    // 00aa4fd4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa4fd6  e835ffffff             -call 0xaa4f10
    cpu.esp -= 4;
    sub_aa4f10(app, cpu);
    if (cpu.terminate) return;
    // 00aa4fdb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa4fdd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa4fdf  74c8                   -je 0xaa4fa9
    if (cpu.flags.zf)
    {
        goto L_0x00aa4fa9;
    }
    // 00aa4fe1  b8542fab00             -mov eax, 0xab2f54
    cpu.eax = 11218772 /*0xab2f54*/;
    // 00aa4fe6  8b1d1447ab00           -mov ebx, dword ptr [0xab4714]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11224852) /* 0xab4714 */);
    // 00aa4fec  e8cffaffff             -call 0xaa4ac0
    cpu.esp -= 4;
    sub_aa4ac0(app, cpu);
    if (cpu.terminate) return;
    // 00aa4ff1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa4ff3  74b4                   -je 0xaa4fa9
    if (cpu.flags.zf)
    {
        goto L_0x00aa4fa9;
    }
    // 00aa4ff5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa4ff6  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00aa4ffb  b8404faa00             -mov eax, 0xaa4f40
    cpu.eax = 11161408 /*0xaa4f40*/;
    // 00aa5000  893df42eab00           -mov dword ptr [0xab2ef4], edi
    app->getMemory<x86::reg32>(x86::reg32(11218676) /* 0xab2ef4 */) = cpu.edi;
    // 00aa5006  e8352c0000             -call 0xaa7c40
    cpu.esp -= 4;
    sub_aa7c40(app, cpu);
    if (cpu.terminate) return;
    // 00aa500b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa500c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa500e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa5011  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5012  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5013  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void sub_aa5020(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa5020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5021  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa5022  8b15482fab00           -mov edx, dword ptr [0xab2f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218760) /* 0xab2f48 */);
    // 00aa5028  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa502a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa502c  7512                   -jne 0xaa5040
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5040;
    }
    // 00aa502e  833df82eab0000         +cmp dword ptr [0xab2ef8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218680) /* 0xab2ef8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5035  7509                   -jne 0xaa5040
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5040;
    }
    // 00aa5037  833d102fab0000         +cmp dword ptr [0xab2f10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218704) /* 0xab2f10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa503e  7505                   -jne 0xaa5045
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5045;
    }
L_0x00aa5040:
    // 00aa5040  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5042  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5043  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5044  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa5045:
    // 00aa5045  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5046  68482fab00             -push 0xab2f48
    app->getMemory<x86::reg32>(cpu.esp-4) = 11218760 /*0xab2f48*/;
    cpu.esp -= 4;
    // 00aa504b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa504c  e867bc0000             -call 0xab0cb8
    cpu.esp -= 4;
    sub_ab0cb8(app, cpu);
    if (cpu.terminate) return;
    // 00aa5051  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa5053  75eb                   -jne 0xaa5040
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5040;
    }
    // 00aa5055  833d442fab0000         +cmp dword ptr [0xab2f44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218756) /* 0xab2f44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa505c  7426                   -je 0xaa5084
    if (cpu.flags.zf)
    {
        goto L_0x00aa5084;
    }
    // 00aa505e  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
L_0x00aa5063:
    // 00aa5063  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa5064  8b2d082fab00           -mov ebp, dword ptr [0xab2f08]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218696) /* 0xab2f08 */);
    // 00aa506a  a1482fab00             -mov eax, dword ptr [0xab2f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218760) /* 0xab2f48 */);
    // 00aa506f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa5070  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa5072  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5073  ff5150                 -call dword ptr [ecx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5076  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa5078  7511                   -jne 0xaa508b
    if (!cpu.flags.zf)
    {
        goto L_0x00aa508b;
    }
    // 00aa507a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa507f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5081  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5082  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5083  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa5084:
    // 00aa5084  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 00aa5089  ebd8                   -jmp 0xaa5063
    goto L_0x00aa5063;
L_0x00aa508b:
    // 00aa508b  a1482fab00             -mov eax, dword ptr [0xab2f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218760) /* 0xab2f48 */);
    // 00aa5090  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5091  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa5093  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5096  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa5098  a3482fab00             -mov dword ptr [0xab2f48], eax
    app->getMemory<x86::reg32>(x86::reg32(11218760) /* 0xab2f48 */) = cpu.eax;
    // 00aa509d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa509f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa50a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa50a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void sub_aa50b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa50b0  8b15482fab00           -mov edx, dword ptr [0xab2f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218760) /* 0xab2f48 */);
    // 00aa50b6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa50b8  7506                   -jne 0xaa50c0
    if (!cpu.flags.zf)
    {
        goto L_0x00aa50c0;
    }
    // 00aa50ba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa50bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa50c0:
    // 00aa50c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa50c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa50c3  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aa50c5  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa50c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa50ca  890d482fab00           -mov dword ptr [0xab2f48], ecx
    app->getMemory<x86::reg32>(x86::reg32(11218760) /* 0xab2f48 */) = cpu.ecx;
    // 00aa50d0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa50d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_aa50e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa50e0  f605f42eab0002         +test byte ptr [0xab2ef4], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(11218676) /* 0xab2ef4 */) & 2 /*0x2*/));
    // 00aa50e7  7501                   -jne 0xaa50ea
    if (!cpu.flags.zf)
    {
        goto L_0x00aa50ea;
    }
    // 00aa50e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa50ea:
    // 00aa50ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa50eb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa50ec  ff152846ab00           -call dword ptr [0xab4628]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224616) /* 0xab4628 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa50f2  8025f42eab00fd         -and byte ptr [0xab2ef4], 0xfd
    app->getMemory<x86::reg8>(x86::reg32(11218676) /* 0xab2ef4 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 00aa50f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa50fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa50fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void sub_aa5100(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa5100  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5101  8b15f42eab00           -mov edx, dword ptr [0xab2ef4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218676) /* 0xab2ef4 */);
    // 00aa5107  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa510c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa510e  7450                   -je 0xaa5160
    if (cpu.flags.zf)
    {
        goto L_0x00aa5160;
    }
    // 00aa5110  f605f42eab0002         +test byte ptr [0xab2ef4], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(11218676) /* 0xab2ef4 */) & 2 /*0x2*/));
    // 00aa5117  754b                   -jne 0xaa5164
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5164;
    }
L_0x00aa5119:
    // 00aa5119  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa511a  833d3c2fab0000         +cmp dword ptr [0xab2f3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218748) /* 0xab2f3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5121  740a                   -je 0xaa512d
    if (cpu.flags.zf)
    {
        goto L_0x00aa512d;
    }
    // 00aa5123  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa5124  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aa5126  89353c2fab00           -mov dword ptr [0xab2f3c], esi
    app->getMemory<x86::reg32>(x86::reg32(11218748) /* 0xab2f3c */) = cpu.esi;
    // 00aa512c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aa512d:
    // 00aa512d  8b3d402fab00           -mov edi, dword ptr [0xab2f40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11218752) /* 0xab2f40 */);
    // 00aa5133  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aa5135  740f                   -je 0xaa5146
    if (cpu.flags.zf)
    {
        goto L_0x00aa5146;
    }
    // 00aa5137  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa5138  2eff156413ab00         -call dword ptr cs:[0xab1364]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211620) /* 0xab1364 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa513f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa5141  a3402fab00             -mov dword ptr [0xab2f40], eax
    app->getMemory<x86::reg32>(x86::reg32(11218752) /* 0xab2f40 */) = cpu.eax;
L_0x00aa5146:
    // 00aa5146  ff152046ab00           -call dword ptr [0xab4620]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224608) /* 0xab4620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa514c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aa514e  e8adf6ffff             -call 0xaa4800
    cpu.esp -= 4;
    sub_aa4800(app, cpu);
    if (cpu.terminate) return;
    // 00aa5153  8915342fab00           -mov dword ptr [0xab2f34], edx
    app->getMemory<x86::reg32>(x86::reg32(11218740) /* 0xab2f34 */) = cpu.edx;
    // 00aa5159  8915f42eab00           -mov dword ptr [0xab2ef4], edx
    app->getMemory<x86::reg32>(x86::reg32(11218676) /* 0xab2ef4 */) = cpu.edx;
    // 00aa515f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aa5160:
    // 00aa5160  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5162  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5163  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa5164:
    // 00aa5164  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5166  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5168  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa516a  e861020000             -call 0xaa53d0
    cpu.esp -= 4;
    sub_aa53d0(app, cpu);
    if (cpu.terminate) return;
    // 00aa516f  e83cffffff             -call 0xaa50b0
    cpu.esp -= 4;
    sub_aa50b0(app, cpu);
    if (cpu.terminate) return;
    // 00aa5174  eba3                   -jmp 0xaa5119
    goto L_0x00aa5119;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_aa5180(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa5180  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5181  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa5182  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa5183  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa5184  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa5188  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa518c  e84fffffff             -call 0xaa50e0
    cpu.esp -= 4;
    sub_aa50e0(app, cpu);
    if (cpu.terminate) return;
    // 00aa5191  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aa5193  0f8492010000           -je 0xaa532b
    if (cpu.flags.zf)
    {
        goto L_0x00aa532b;
    }
    // 00aa5199  833df82eab0000         +cmp dword ptr [0xab2ef8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218680) /* 0xab2ef8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa51a0  0f848e010000           -je 0xaa5334
    if (cpu.flags.zf)
    {
        goto L_0x00aa5334;
    }
    // 00aa51a6  833d442fab0000         +cmp dword ptr [0xab2f44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218756) /* 0xab2f44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa51ad  0f8481010000           -je 0xaa5334
    if (cpu.flags.zf)
    {
        goto L_0x00aa5334;
    }
    // 00aa51b3  bfff000000             -mov edi, 0xff
    cpu.edi = 255 /*0xff*/;
L_0x00aa51b8:
    // 00aa51b8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa51ba  7418                   -je 0xaa51d4
    if (cpu.flags.zf)
    {
        goto L_0x00aa51d4;
    }
    // 00aa51bc  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00aa51c0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00aa51c7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00aa51c9  3b2cc53030ab00         +cmp ebp, dword ptr [eax*8 + 0xab3030]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11218992) /* 0xab3030 */ + cpu.eax * 8)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa51d0  7e02                   -jle 0xaa51d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa51d4;
    }
    // 00aa51d2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00aa51d4:
    // 00aa51d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa51d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa51d6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa51d8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa51da  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa51dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa51dd  a1082fab00             -mov eax, dword ptr [0xab2f08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218696) /* 0xab2f08 */);
    // 00aa51e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa51e3  ff152c46ab00           -call dword ptr [0xab462c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224620) /* 0xab462c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa51e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa51eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa51ed  7528                   -jne 0xaa5217
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5217;
    }
    // 00aa51ef  81ffff000000           +cmp edi, 0xff
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
    // 00aa51f5  7520                   -jne 0xaa5217
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5217;
    }
    // 00aa51f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa51f8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa51f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa51fa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa51fb  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aa51ff  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5200  8b0485e832ab00         -mov eax, dword ptr [eax*4 + 0xab32e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11219688) /* 0xab32e8 */ + cpu.eax * 4);
    // 00aa5207  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5208  8b15082fab00           -mov edx, dword ptr [0xab2f08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218696) /* 0xab2f08 */);
    // 00aa520e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa520f  ff152c46ab00           -call dword ptr [0xab462c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224620) /* 0xab462c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5215  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00aa5217:
    // 00aa5217  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa5219  0f840c010000           -je 0xaa532b
    if (cpu.flags.zf)
    {
        goto L_0x00aa532b;
    }
    // 00aa521f  833df82eab0000         +cmp dword ptr [0xab2ef8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218680) /* 0xab2ef8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5226  0f8418010000           -je 0xaa5344
    if (cpu.flags.zf)
    {
        goto L_0x00aa5344;
    }
    // 00aa522c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00aa5230  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00aa5237  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00aa5239  8b14c51830ab00         -mov edx, dword ptr [eax*8 + 0xab3018]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218968) /* 0xab3018 */ + cpu.eax * 8);
    // 00aa5240  8b04c51c30ab00         -mov eax, dword ptr [eax*8 + 0xab301c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218972) /* 0xab301c */ + cpu.eax * 8);
    // 00aa5247  8915182fab00           -mov dword ptr [0xab2f18], edx
    app->getMemory<x86::reg32>(x86::reg32(11218712) /* 0xab2f18 */) = cpu.edx;
L_0x00aa524d:
    // 00aa524d  a31c2fab00             -mov dword ptr [0xab2f1c], eax
    app->getMemory<x86::reg32>(x86::reg32(11218716) /* 0xab2f1c */) = cpu.eax;
    // 00aa5252  e839040000             -call 0xaa5690
    cpu.esp -= 4;
    sub_aa5690(app, cpu);
    if (cpu.terminate) return;
    // 00aa5257  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00aa5259  ff153846ab00           -call dword ptr [0xab4638]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224632) /* 0xab4638 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa525f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5261  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5263  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5265  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5267  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5269  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa526b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa526d  ff15c046ab00           -call dword ptr [0xab46c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224768) /* 0xab46c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5273  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5275  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00aa5277  ff15e846ab00           -call dword ptr [0xab46e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224808) /* 0xab46e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa527d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa527f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5281  e80a070000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa5286  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5288  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa528a  e801070000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa528f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5291  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00aa5293  e8f8060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa5298  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa529a  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00aa529c  e8ef060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52a1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa52a3  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00aa52a5  e8e6060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52aa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa52ac  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 00aa52ae  e8dd060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa52b5  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00aa52b7  e8d4060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52bc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa52be  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00aa52c0  e8cb060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52c5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa52c7  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00aa52c9  e8c2060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52ce  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa52d0  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 00aa52d2  e8b9060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52d7  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00aa52d9  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00aa52db  e8b0060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52e0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa52e2  6a68                   -push 0x68
    app->getMemory<x86::reg32>(cpu.esp-4) = 104 /*0x68*/;
    cpu.esp -= 4;
    // 00aa52e4  e8a7060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52e9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa52eb  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00aa52ed  e89e060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52f2  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 00aa52f7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa52f8  6a65                   -push 0x65
    app->getMemory<x86::reg32>(cpu.esp-4) = 101 /*0x65*/;
    cpu.esp -= 4;
    // 00aa52fa  e891060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa52ff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5301  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00aa5303  e888060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa5308  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa530a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa530b  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00aa530d  e87e060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa5312  83fe01                 +cmp esi, 1
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
    // 00aa5315  7c43                   -jl 0xaa535a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa535a;
    }
    // 00aa5317  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00aa531c:
    // 00aa531c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa531d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa531f  e86c060000             -call 0xaa5990
    cpu.esp -= 4;
    sub_aa5990(app, cpu);
    if (cpu.terminate) return;
    // 00aa5324  800df42eab0002         +or byte ptr [0xab2ef4], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(11218676) /* 0xab2ef4 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
L_0x00aa532b:
    // 00aa532b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa532d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa532e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa532f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5330  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5331  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00aa5334:
    // 00aa5334  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00aa5338  8b3cbde832ab00         -mov edi, dword ptr [edi*4 + 0xab32e8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11219688) /* 0xab32e8 */ + cpu.edi * 4);
    // 00aa533f  e974feffff             -jmp 0xaa51b8
    goto L_0x00aa51b8;
L_0x00aa5344:
    // 00aa5344  ff15f046ab00           -call dword ptr [0xab46f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224816) /* 0xab46f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa534a  a3182fab00             -mov dword ptr [0xab2f18], eax
    app->getMemory<x86::reg32>(x86::reg32(11218712) /* 0xab2f18 */) = cpu.eax;
    // 00aa534f  ff15f446ab00           -call dword ptr [0xab46f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224820) /* 0xab46f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5355  e9f3feffff             -jmp 0xaa524d
    goto L_0x00aa524d;
L_0x00aa535a:
    // 00aa535a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa535c  ebbe                   -jmp 0xaa531c
    goto L_0x00aa531c;
}

/* align: skip 0x8b 0xc0 */
void sub_aa5360(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa5360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5361  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa5362  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa5366  833d3433ab0000         +cmp dword ptr [0xab3334], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11219764) /* 0xab3334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa536d  750a                   -jne 0xaa5379
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5379;
    }
L_0x00aa536f:
    // 00aa536f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa5374  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5375  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5376  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00aa5379:
    // 00aa5379  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa537b  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00aa537e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa537f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aa5384  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5385  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00aa5389  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa538a  e8f1fdffff             -call 0xaa5180
    cpu.esp -= 4;
    sub_aa5180(app, cpu);
    if (cpu.terminate) return;
    // 00aa538f  a3142fab00             -mov dword ptr [0xab2f14], eax
    app->getMemory<x86::reg32>(x86::reg32(11218708) /* 0xab2f14 */) = cpu.eax;
    // 00aa5394  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa5396  7527                   -jne 0xaa53bf
    if (!cpu.flags.zf)
    {
        goto L_0x00aa53bf;
    }
    // 00aa5398  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aa539d:
    // 00aa539d  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00aa53a1  8b35402fab00           -mov esi, dword ptr [0xab2f40]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218752) /* 0xab2f40 */);
    // 00aa53a7  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aa53a9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa53ab  74c2                   -je 0xaa536f
    if (cpu.flags.zf)
    {
        goto L_0x00aa536f;
    }
    // 00aa53ad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa53ae  2eff150414ab00         -call dword ptr cs:[0xab1404]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211780) /* 0xab1404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa53b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa53ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa53bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa53bc  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00aa53bf:
    // 00aa53bf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa53c1  ebda                   -jmp 0xaa539d
    goto L_0x00aa539d;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void sub_aa53d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa53d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa53d1  833d302fab0000         +cmp dword ptr [0xab2f30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218736) /* 0xab2f30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa53d8  0f85a1000000           -jne 0xaa547f
    if (!cpu.flags.zf)
    {
        goto L_0x00aa547f;
    }
L_0x00aa53de:
    // 00aa53de  e83dfcffff             -call 0xaa5020
    cpu.esp -= 4;
    sub_aa5020(app, cpu);
    if (cpu.terminate) return;
    // 00aa53e3  8b0d082fab00           -mov ecx, dword ptr [0xab2f08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218696) /* 0xab2f08 */);
    // 00aa53e9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa53eb  7408                   -je 0xaa53f5
    if (cpu.flags.zf)
    {
        goto L_0x00aa53f5;
    }
    // 00aa53ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa53ee  2eff155c13ab00         -call dword ptr cs:[0xab135c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211612) /* 0xab135c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa53f5:
    // 00aa53f5  833d3c2fab0000         +cmp dword ptr [0xab2f3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218748) /* 0xab2f3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa53fc  0f848d000000           -je 0xaa548f
    if (cpu.flags.zf)
    {
        goto L_0x00aa548f;
    }
    // 00aa5402  833d082fab0000         +cmp dword ptr [0xab2f08], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218696) /* 0xab2f08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5409  0f8480000000           -je 0xaa548f
    if (cpu.flags.zf)
    {
        goto L_0x00aa548f;
    }
    // 00aa540f  833d402fab0000         +cmp dword ptr [0xab2f40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218752) /* 0xab2f40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5416  7477                   -je 0xaa548f
    if (cpu.flags.zf)
    {
        goto L_0x00aa548f;
    }
    // 00aa5418  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa5419  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa541a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa541b  686053aa00             -push 0xaa5360
    app->getMemory<x86::reg32>(cpu.esp-4) = 11162464 /*0xaa5360*/;
    cpu.esp -= 4;
    // 00aa5420  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 00aa5425  ff153c2fab00           -call dword ptr [0xab2f3c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11218748) /* 0xab2f3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa542b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa542f  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa5433  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00aa5436  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00aa5438  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5439  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa543d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa543e  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 00aa5443  8b2d082fab00           -mov ebp, dword ptr [0xab2f08]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218696) /* 0xab2f08 */);
    // 00aa5449  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa544e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa544f  891d3433ab00           -mov dword ptr [0xab3334], ebx
    app->getMemory<x86::reg32>(x86::reg32(11219764) /* 0xab3334 */) = cpu.ebx;
    // 00aa5455  2eff155813ab00         -call dword ptr cs:[0xab1358]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211608) /* 0xab1358 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa545c  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00aa545e  a1402fab00             -mov eax, dword ptr [0xab2f40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218752) /* 0xab2f40 */);
    // 00aa5463  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5464  2eff153814ab00         -call dword ptr cs:[0xab1438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211832) /* 0xab1438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa546b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aa546d  a1142fab00             -mov eax, dword ptr [0xab2f14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218708) /* 0xab2f14 */);
    // 00aa5472  89153433ab00           -mov dword ptr [0xab3334], edx
    app->getMemory<x86::reg32>(x86::reg32(11219764) /* 0xab3334 */) = cpu.edx;
    // 00aa5478  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5479  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa547a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa547b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa547c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00aa547f:
    // 00aa547f  ff15302fab00           -call dword ptr [0xab2f30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11218736) /* 0xab2f30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5485  a3082fab00             -mov dword ptr [0xab2f08], eax
    app->getMemory<x86::reg32>(x86::reg32(11218696) /* 0xab2f08 */) = cpu.eax;
    // 00aa548a  e94fffffff             -jmp 0xaa53de
    goto L_0x00aa53de;
L_0x00aa548f:
    // 00aa548f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aa5493  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5494  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aa5498  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa5499  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aa549d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa549e  e8ddfcffff             -call 0xaa5180
    cpu.esp -= 4;
    sub_aa5180(app, cpu);
    if (cpu.terminate) return;
    // 00aa54a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa54a4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void sub_aa54b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa54b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa54b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa54b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa54b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa54b4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa54b7  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00aa54bb  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aa54bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa54c0  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00aa54c3  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa54c6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa54c7  2d0000803f             -sub eax, 0x3f800000
    (cpu.eax) -= x86::reg32(x86::sreg32(1065353216 /*0x3f800000*/));
    // 00aa54cc  c1f817                 -sar eax, 0x17
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (23 /*0x17*/ % 32));
    // 00aa54cf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa54d1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa54d3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aa54d5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aa54d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa54d8  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00aa54db  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa54de  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa54df  2d0000803f             -sub eax, 0x3f800000
    (cpu.eax) -= x86::reg32(x86::sreg32(1065353216 /*0x3f800000*/));
    // 00aa54e4  c1f817                 -sar eax, 0x17
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (23 /*0x17*/ % 32));
    // 00aa54e7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aa54e9  39c2                   +cmp edx, eax
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
    // 00aa54eb  7e02                   -jle 0xaa54ef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa54ef;
    }
    // 00aa54ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00aa54ef:
    // 00aa54ef  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00aa54f3  0fb6b83833ab00         -movzx edi, byte ptr [eax + 0xab3338]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11219768) /* 0xab3338 */));
    // 00aa54fa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa54fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa54fe  0f8cab000000           -jl 0xaa55af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa55af;
    }
L_0x00aa5504:
    // 00aa5504  8a803833ab00           -mov al, byte ptr [eax + 0xab3338]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11219768) /* 0xab3338 */);
    // 00aa550a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aa550f  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa5511  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00aa5515  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa5517  8a834433ab00           -mov al, byte ptr [ebx + 0xab3344]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11219780) /* 0xab3344 */);
    // 00aa551d  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aa5521  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00aa5525  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa5527  8a824833ab00           -mov al, byte ptr [edx + 0xab3348]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11219784) /* 0xab3348 */);
    // 00aa552d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa552e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aa5532  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa5533  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa5534  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aa5538  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5539  ff15c446ab00           -call dword ptr [0xab46c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224772) /* 0xab46c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa553f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5541  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa5543  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aa5545  ff15cc46ab00           -call dword ptr [0xab46cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224780) /* 0xab46cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa554b  8b15a847ab00           -mov edx, dword ptr [0xab47a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11225000) /* 0xab47a8 */);
    // 00aa5551  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa5553  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa5555  250000e0ff             -and eax, 0xffe00000
    cpu.eax &= x86::reg32(x86::sreg32(4292870144 /*0xffe00000*/));
    // 00aa555a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aa555d  031da847ab00           -add ebx, dword ptr [0xab47a8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11225000) /* 0xab47a8 */)));
    // 00aa5563  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5565  4b                     -dec ebx
    (cpu.ebx)--;
    // 00aa5566  ff15cc46ab00           -call dword ptr [0xab46cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224780) /* 0xab46cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa556c  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa556e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa5571  81e30000e0ff           -and ebx, 0xffe00000
    cpu.ebx &= x86::reg32(x86::sreg32(4292870144 /*0xffe00000*/));
    // 00aa5577  39d3                   +cmp ebx, edx
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
    // 00aa5579  740f                   -je 0xaa558a
    if (cpu.flags.zf)
    {
        goto L_0x00aa558a;
    }
    // 00aa557b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa557d  ff15cc46ab00           -call dword ptr [0xab46cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224780) /* 0xab46cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5583  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa5585  a3a847ab00             -mov dword ptr [0xab47a8], eax
    app->getMemory<x86::reg32>(x86::reg32(11225000) /* 0xab47a8 */) = cpu.eax;
L_0x00aa558a:
    // 00aa558a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa558c  ff15d046ab00           -call dword ptr [0xab46d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224784) /* 0xab46d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5592  83c00f                 -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00aa5595  8b0da847ab00           -mov ecx, dword ptr [0xab47a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11225000) /* 0xab47a8 */);
    // 00aa559b  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00aa559d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa559f  39e8                   +cmp eax, ebp
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
    // 00aa55a1  7d13                   -jge 0xaa55b6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aa55b6;
    }
L_0x00aa55a3:
    // 00aa55a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa55a5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa55a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa55a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa55aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa55ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa55ac  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00aa55af:
    // 00aa55af  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa55b1  e94effffff             -jmp 0xaa5504
    goto L_0x00aa5504;
L_0x00aa55b6:
    // 00aa55b6  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 00aa55bb  e8f0260000             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aa55c0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aa55c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa55c4  74dd                   -je 0xaa55a3
    if (cpu.flags.zf)
    {
        goto L_0x00aa55a3;
    }
    // 00aa55c6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa55ca  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00aa55cd  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa55cf  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa55d3  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aa55d7  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00aa55da  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa55dc  8a934833ab00           -mov dl, byte ptr [ebx + 0xab3348]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11219784) /* 0xab3348 */);
    // 00aa55e2  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00aa55e9  c7401803000000         -mov dword ptr [eax + 0x18], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 3 /*0x3*/;
    // 00aa55f0  8b1da847ab00           -mov ebx, dword ptr [0xab47a8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11225000) /* 0xab47a8 */);
    // 00aa55f6  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00aa55f9  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa55fb  8b15a847ab00           -mov edx, dword ptr [0xab47a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11225000) /* 0xab47a8 */);
    // 00aa5601  891da847ab00           -mov dword ptr [0xab47a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(11225000) /* 0xab47a8 */) = cpu.ebx;
    // 00aa5607  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00aa560a  8b15282fab00           -mov edx, dword ptr [0xab2f28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218728) /* 0xab2f28 */);
    // 00aa5610  a3282fab00             -mov dword ptr [0xab2f28], eax
    app->getMemory<x86::reg32>(x86::reg32(11218728) /* 0xab2f28 */) = cpu.eax;
    // 00aa5615  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00aa5618  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa561a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa561d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa561e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa561f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5620  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5621  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void sub_aa5630(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa5630  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5631  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa5632  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aa5636  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aa563a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa563c  750f                   -jne 0xaa564d
    if (!cpu.flags.zf)
    {
        goto L_0x00aa564d;
    }
    // 00aa563e  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00aa5642  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa5644  752a                   -jne 0xaa5670
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5670;
    }
    // 00aa5646  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5648  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5649  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa564a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00aa564d:
    // 00aa564d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa564e  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00aa5651  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa5652  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00aa5655  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa5656  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5658  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00aa565b  ff15c846ab00           -call dword ptr [0xab46c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224776) /* 0xab46c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5661  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00aa5665  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa5667  7507                   -jne 0xaa5670
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5670;
    }
    // 00aa5669  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa566b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa566c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa566d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00aa5670:
    // 00aa5670  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa5671  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa5673  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5675  ff153c46ab00           -call dword ptr [0xab463c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224636) /* 0xab463c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa567b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa567d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa567e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa567f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void sub_aa5690(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa5690  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5692  ff15cc46ab00           -call dword ptr [0xab46cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224780) /* 0xab46cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5698  8b15282fab00           -mov edx, dword ptr [0xab2f28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218728) /* 0xab2f28 */);
    // 00aa569e  a3a847ab00             -mov dword ptr [0xab47a8], eax
    app->getMemory<x86::reg32>(x86::reg32(11225000) /* 0xab47a8 */) = cpu.eax;
    // 00aa56a3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa56a5  7419                   -je 0xaa56c0
    if (cpu.flags.zf)
    {
        goto L_0x00aa56c0;
    }
L_0x00aa56a7:
    // 00aa56a7  a1282fab00             -mov eax, dword ptr [0xab2f28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218728) /* 0xab2f28 */);
    // 00aa56ac  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00aa56af  e8ec260000             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aa56b4  8915282fab00           -mov dword ptr [0xab2f28], edx
    app->getMemory<x86::reg32>(x86::reg32(11218728) /* 0xab2f28 */) = cpu.edx;
    // 00aa56ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa56bc  75e9                   -jne 0xaa56a7
    if (!cpu.flags.zf)
    {
        goto L_0x00aa56a7;
    }
    // 00aa56be  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00aa56c0:
    // 00aa56c0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa56c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_aa56d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa56d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa56d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa56d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa56d3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aa56d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa56d9  7514                   -jne 0xaa56ef
    if (!cpu.flags.zf)
    {
        goto L_0x00aa56ef;
    }
    // 00aa56db  833d5433ab0000         +cmp dword ptr [0xab3354], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11219796) /* 0xab3354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa56e2  755c                   -jne 0xaa5740
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5740;
    }
L_0x00aa56e4:
    // 00aa56e4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa56e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa56ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa56eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa56ec  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aa56ef:
    // 00aa56ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa56f0  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00aa56f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa56f4  8b6814                 -mov ebp, dword ptr [eax + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00aa56f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa56f8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa56fa  ff15d446ab00           -call dword ptr [0xab46d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224788) /* 0xab46d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5700  833d5433ab0001         +cmp dword ptr [0xab3354], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11219796) /* 0xab3354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5707  74db                   -je 0xaa56e4
    if (cpu.flags.zf)
    {
        goto L_0x00aa56e4;
    }
    // 00aa5709  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa570b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa570d  8b152c2fab00           -mov edx, dword ptr [0xab2f2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218732) /* 0xab2f2c */);
    // 00aa5713  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa5714  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5716  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00aa5718  ff156046ab00           -call dword ptr [0xab4660]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224672) /* 0xab4660 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa571e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5720  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5722  8b0d2c2fab00           -mov ecx, dword ptr [0xab2f2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218732) /* 0xab2f2c */);
    // 00aa5728  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa5729  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa572b  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00aa572d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5732  ff156446ab00           -call dword ptr [0xab4664]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224676) /* 0xab4664 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5738  891d5433ab00           -mov dword ptr [0xab3354], ebx
    app->getMemory<x86::reg32>(x86::reg32(11219796) /* 0xab3354 */) = cpu.ebx;
    // 00aa573e  eba4                   -jmp 0xaa56e4
    goto L_0x00aa56e4;
L_0x00aa5740:
    // 00aa5740  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa5741  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5742  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa5744  8b0d2c2fab00           -mov ecx, dword ptr [0xab2f2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11218732) /* 0xab2f2c */);
    // 00aa574a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa574b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa574c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa574e  ff156046ab00           -call dword ptr [0xab4660]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224672) /* 0xab4660 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5754  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5756  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa5758  8b1d2c2fab00           -mov ebx, dword ptr [0xab2f2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218732) /* 0xab2f2c */);
    // 00aa575e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa575f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5761  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5763  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aa5765  ff156446ab00           -call dword ptr [0xab4664]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224676) /* 0xab4664 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa576b  89355433ab00           -mov dword ptr [0xab3354], esi
    app->getMemory<x86::reg32>(x86::reg32(11219796) /* 0xab3354 */) = cpu.esi;
    // 00aa5771  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5772  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa5777  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5778  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5779  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa577a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa5780(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa5780  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa5784  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa5786  7505                   -jne 0xaa578d
    if (!cpu.flags.zf)
    {
        goto L_0x00aa578d;
    }
    // 00aa5788  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aa578d:
    // 00aa578d  48                     -dec eax
    (cpu.eax)--;
    // 00aa578e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa578f  a3042fab00             -mov dword ptr [0xab2f04], eax
    app->getMemory<x86::reg32>(x86::reg32(11218692) /* 0xab2f04 */) = cpu.eax;
    // 00aa5794  ff154046ab00           -call dword ptr [0xab4640]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224640) /* 0xab4640 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa579a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa579f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void sub_aa57b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa57b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa57b2  66a1002fab00           -mov ax, word ptr [0xab2f00]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(11218688) /* 0xab2f00 */);
    // 00aa57b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa57b9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa57bb  8b15fc2eab00           -mov edx, dword ptr [0xab2efc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218684) /* 0xab2efc */);
    // 00aa57c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa57c2  ff154446ab00           -call dword ptr [0xab4644]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224644) /* 0xab4644 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa57c8  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00aa57ce  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
    // 00aa57d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa57d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aa57d0;
    // 00aa57b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa57b2  66a1002fab00           -mov ax, word ptr [0xab2f00]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(11218688) /* 0xab2f00 */);
    // 00aa57b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa57b9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa57bb  8b15fc2eab00           -mov edx, dword ptr [0xab2efc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218684) /* 0xab2efc */);
    // 00aa57c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa57c2  ff154446ab00           -call dword ptr [0xab4644]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224644) /* 0xab4644 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa57c8  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00aa57ce  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
L_entry_0x00aa57d0:
    // 00aa57d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void sub_aa57e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa57e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa57e1  bb00093d00             -mov ebx, 0x3d0900
    cpu.ebx = 4000000 /*0x3d0900*/;
L_0x00aa57e6:
    // 00aa57e6  ff15f846ab00           -call dword ptr [0xab46f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224824) /* 0xab46f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa57ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa57ee  7403                   -je 0xaa57f3
    if (cpu.flags.zf)
    {
        goto L_0x00aa57f3;
    }
    // 00aa57f0  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa57f1  75f3                   -jne 0xaa57e6
    if (!cpu.flags.zf)
    {
        goto L_0x00aa57e6;
    }
L_0x00aa57f3:
    // 00aa57f3  8b150c2fab00           -mov edx, dword ptr [0xab2f0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218700) /* 0xab2f0c */);
    // 00aa57f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa57fa  ff154846ab00           -call dword ptr [0xab4648]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224648) /* 0xab4648 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5800  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5801  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00aa5807  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 00aa580d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00aa5810  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa5810(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aa5810;
    // 00aa57e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa57e1  bb00093d00             -mov ebx, 0x3d0900
    cpu.ebx = 4000000 /*0x3d0900*/;
L_0x00aa57e6:
    // 00aa57e6  ff15f846ab00           -call dword ptr [0xab46f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224824) /* 0xab46f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa57ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa57ee  7403                   -je 0xaa57f3
    if (cpu.flags.zf)
    {
        goto L_0x00aa57f3;
    }
    // 00aa57f0  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa57f1  75f3                   -jne 0xaa57e6
    if (!cpu.flags.zf)
    {
        goto L_0x00aa57e6;
    }
L_0x00aa57f3:
    // 00aa57f3  8b150c2fab00           -mov edx, dword ptr [0xab2f0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218700) /* 0xab2f0c */);
    // 00aa57f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa57fa  ff154846ab00           -call dword ptr [0xab4648]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224648) /* 0xab4648 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5800  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5801  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00aa5807  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 00aa580d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00aa5810:
    // 00aa5810  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void sub_aa5830(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00aa5830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5831  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa5835  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa5837  83f803                 +cmp eax, 3
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
    // 00aa583a  770d                   -ja 0xaa5849
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa5849;
    }
    // 00aa583c  ff24851458aa00         -jmp dword ptr [eax*4 + 0xaa5814]
    cpu.ip = app->getMemory<x86::reg32>(11163668 + cpu.eax * 4); goto dynamic_jump;
  case 0x00aa5843:
    // 00aa5843  ff155446ab00           -call dword ptr [0xab4654]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224660) /* 0xab4654 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa5849:
    // 00aa5849  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa584b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa584c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x00aa584f:
    // 00aa584f  ff155846ab00           -call dword ptr [0xab4658]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224664) /* 0xab4658 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5855  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa5857  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5859  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa585a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x00aa585d:
    // 00aa585d  bb00093d00             -mov ebx, 0x3d0900
    cpu.ebx = 4000000 /*0x3d0900*/;
L_0x00aa5862:
    // 00aa5862  ff155046ab00           -call dword ptr [0xab4650]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224656) /* 0xab4650 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5868  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa586a  7515                   -jne 0xaa5881
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5881;
    }
L_0x00aa586c:
    // 00aa586c  ff155046ab00           -call dword ptr [0xab4650]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224656) /* 0xab4650 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5872  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa5874  7503                   -jne 0xaa5879
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5879;
    }
    // 00aa5876  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa5877  75f3                   -jne 0xaa586c
    if (!cpu.flags.zf)
    {
        goto L_0x00aa586c;
    }
L_0x00aa5879:
    // 00aa5879  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00aa587b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa587d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa587e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aa5881:
    // 00aa5881  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa5882  75de                   -jne 0xaa5862
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5862;
    }
    // 00aa5884  ebe6                   -jmp 0xaa586c
    goto L_0x00aa586c;
  case 0x00aa5886:
    // 00aa5886  ff154c46ab00           -call dword ptr [0xab464c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224652) /* 0xab464c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa588c  c1e80c                 -shr eax, 0xc
    cpu.eax >>= 12 /*0xc*/ % 32;
    // 00aa588f  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 00aa5894  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00aa5899  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa589b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa589d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa589e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void sub_aa58b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa58b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa58b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa58b2  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa58b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa58b7  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa58bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa58bc  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa58c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa58c1  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa58c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa58c6  ff155c46ab00           -call dword ptr [0xab465c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224668) /* 0xab465c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa58cc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa58d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa58d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa58d3  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_aa58e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa58e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa58e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa58e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa58e3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa58e5  744d                   -je 0xaa5934
    if (cpu.flags.zf)
    {
        goto L_0x00aa5934;
    }
    // 00aa58e7  b9604aaa00             -mov ecx, 0xaa4a60
    cpu.ecx = 11160160 /*0xaa4a60*/;
    // 00aa58ec  be404aaa00             -mov esi, 0xaa4a40
    cpu.esi = 11160128 /*0xaa4a40*/;
    // 00aa58f1  8b1de446ab00           -mov ebx, dword ptr [0xab46e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11224804) /* 0xab46e4 */);
L_0x00aa58f7:
    // 00aa58f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa58f9  7449                   -je 0xaa5944
    if (cpu.flags.zf)
    {
        goto L_0x00aa5944;
    }
    // 00aa58fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa58fc  ba3049aa00             -mov edx, 0xaa4930
    cpu.edx = 11159856 /*0xaa4930*/;
    // 00aa5901  bfb049aa00             -mov edi, 0xaa49b0
    cpu.edi = 11159984 /*0xaa49b0*/;
    // 00aa5906  89151047ab00           -mov dword ptr [0xab4710], edx
    app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */) = cpu.edx;
    // 00aa590c  893d0c47ab00           -mov dword ptr [0xab470c], edi
    app->getMemory<x86::reg32>(x86::reg32(11224844) /* 0xab470c */) = cpu.edi;
    // 00aa5912  ba304aaa00             -mov edx, 0xaa4a30
    cpu.edx = 11160112 /*0xaa4a30*/;
    // 00aa5917  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aa5918:
    // 00aa5918  89151046ab00           -mov dword ptr [0xab4610], edx
    app->getMemory<x86::reg32>(x86::reg32(11224592) /* 0xab4610 */) = cpu.edx;
    // 00aa591e  89350847ab00           -mov dword ptr [0xab4708], esi
    app->getMemory<x86::reg32>(x86::reg32(11224840) /* 0xab4708 */) = cpu.esi;
    // 00aa5924  891d0447ab00           -mov dword ptr [0xab4704], ebx
    app->getMemory<x86::reg32>(x86::reg32(11224836) /* 0xab4704 */) = cpu.ebx;
    // 00aa592a  890d0047ab00           -mov dword ptr [0xab4700], ecx
    app->getMemory<x86::reg32>(x86::reg32(11224832) /* 0xab4700 */) = cpu.ecx;
    // 00aa5930  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5931  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5932  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5933  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa5934:
    // 00aa5934  8b35a846ab00           -mov esi, dword ptr [0xab46a8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11224744) /* 0xab46a8 */);
    // 00aa593a  8b1dac46ab00           -mov ebx, dword ptr [0xab46ac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11224748) /* 0xab46ac */);
    // 00aa5940  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00aa5942  ebb3                   -jmp 0xaa58f7
    goto L_0x00aa58f7;
L_0x00aa5944:
    // 00aa5944  89351047ab00           -mov dword ptr [0xab4710], esi
    app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */) = cpu.esi;
    // 00aa594a  890d0c47ab00           -mov dword ptr [0xab470c], ecx
    app->getMemory<x86::reg32>(x86::reg32(11224844) /* 0xab470c */) = cpu.ecx;
    // 00aa5950  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aa5952  ebc4                   -jmp 0xaa5918
    goto L_0x00aa5918;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void sub_aa5990(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00aa5990  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5991  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa5992  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa5993  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa5994  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aa5996  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00aa5999  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00aa599c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa599e  83f812                 +cmp eax, 0x12
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
    // 00aa59a1  7331                   -jae 0xaa59d4
    if (!cpu.flags.cf)
    {
        goto L_0x00aa59d4;
    }
    // 00aa59a3  83f808                 +cmp eax, 8
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
    // 00aa59a6  0f83c4010000           -jae 0xaa5b70
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5b70;
    }
    // 00aa59ac  83f804                 +cmp eax, 4
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
    // 00aa59af  0f83bc020000           -jae 0xaa5c71
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5c71;
    }
    // 00aa59b5  83f802                 +cmp eax, 2
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
    // 00aa59b8  0f835d030000           -jae 0xaa5d1b
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5d1b;
    }
    // 00aa59be  83f801                 +cmp eax, 1
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
    // 00aa59c1  0f849b030000           -je 0xaa5d62
    if (cpu.flags.zf)
    {
        goto L_0x00aa5d62;
    }
L_0x00aa59c7:
    // 00aa59c7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
  [[fallthrough]];
  case 0x00aa59c9:
L_0x00aa59c9:
    // 00aa59c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa59cb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa59cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa59ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa59cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa59d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa59d1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa59d4:
    // 00aa59d4  0f86c4060000           -jbe 0xaa609e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa609e;
    }
    // 00aa59da  83f865                 +cmp eax, 0x65
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa59dd  734a                   -jae 0xaa5a29
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5a29;
    }
    // 00aa59df  83f819                 +cmp eax, 0x19
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
    // 00aa59e2  0f83fe000000           -jae 0xaa5ae6
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5ae6;
    }
    // 00aa59e8  83f815                 +cmp eax, 0x15
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21 /*0x15*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa59eb  0f832b010000           -jae 0xaa5b1c
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5b1c;
    }
    // 00aa59f1  83f813                 +cmp eax, 0x13
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
    // 00aa59f4  75d1                   -jne 0xaa59c7
    if (!cpu.flags.zf)
    {
        goto L_0x00aa59c7;
    }
    // 00aa59f6  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa59f9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa59fb  0f856d060000           -jne 0xaa606e
    if (!cpu.flags.zf)
    {
        goto L_0x00aa606e;
    }
    // 00aa5a01  891d3c2fab00           -mov dword ptr [0xab2f3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218748) /* 0xab2f3c */) = cpu.ebx;
    // 00aa5a07  891d342fab00           -mov dword ptr [0xab2f34], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218740) /* 0xab2f34 */) = cpu.ebx;
    // 00aa5a0d  891d382fab00           -mov dword ptr [0xab2f38], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */) = cpu.ebx;
    // 00aa5a13  891d302fab00           -mov dword ptr [0xab2f30], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218736) /* 0xab2f30 */) = cpu.ebx;
    // 00aa5a19  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5a1e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5a20  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5a22  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a26  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5a29:
    // 00aa5a29  0f8658050000           -jbe 0xaa5f87
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa5f87;
    }
    // 00aa5a2f  83f869                 +cmp eax, 0x69
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5a32  733f                   -jae 0xaa5a73
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5a73;
    }
    // 00aa5a34  83f867                 +cmp eax, 0x67
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5a37  0f8216010000           -jb 0xaa5b53
    if (cpu.flags.cf)
    {
        goto L_0x00aa5b53;
    }
    // 00aa5a3d  0f865d050000           -jbe 0xaa5fa0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa5fa0;
    }
    // 00aa5a43  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5a46  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5a4b  83f803                 +cmp eax, 3
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
    // 00aa5a4e  0f8773ffffff           -ja 0xaa59c7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa59c7;
    }
    // 00aa5a54  ff24857859aa00         -jmp dword ptr [eax*4 + 0xaa5978]
    cpu.ip = app->getMemory<x86::reg32>(11164024 + cpu.eax * 4); goto dynamic_jump;
  case 0x00aa5a5b:
    // 00aa5a5b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5a5d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa5a5f  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00aa5a61  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5a62  ff156846ab00           -call dword ptr [0xab4668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224680) /* 0xab4668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5a68  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5a6a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5a6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a70  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5a73:
    // 00aa5a73  772a                   -ja 0xaa5a9f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa5a9f;
    }
    // 00aa5a75  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5a78  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa5a7a  0f84e2040000           -je 0xaa5f62
    if (cpu.flags.zf)
    {
        goto L_0x00aa5f62;
    }
    // 00aa5a80  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa5a82  ff159046ab00           -call dword ptr [0xab4690]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224720) /* 0xab4690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5a88  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa5a89  ff159446ab00           -call dword ptr [0xab4694]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224724) /* 0xab4694 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5a8f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5a94  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5a96  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5a98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5a9c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5a9f:
    // 00aa5a9f  83f86b                 +cmp eax, 0x6b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(107 /*0x6b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5aa2  0f826e040000           -jb 0xaa5f16
    if (cpu.flags.cf)
    {
        goto L_0x00aa5f16;
    }
    // 00aa5aa8  0f8622060000           -jbe 0xaa60d0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa60d0;
    }
    // 00aa5aae  83f86c                 +cmp eax, 0x6c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5ab1  0f8510ffffff           -jne 0xaa59c7
    if (!cpu.flags.zf)
    {
        goto L_0x00aa59c7;
    }
    // 00aa5ab7  833df82eab0000         +cmp dword ptr [0xab2ef8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218680) /* 0xab2ef8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5abe  0f8505ffffff           -jne 0xaa59c9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa59c9;
    }
    // 00aa5ac4  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5ac7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5acc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa5ace  0f8561020000           -jne 0xaa5d35
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5d35;
    }
    // 00aa5ad4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5ad5  ff15fc46ab00           -call dword ptr [0xab46fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224828) /* 0xab46fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5adb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5add  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5adf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ae0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ae1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ae2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ae3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5ae6:
    // 00aa5ae6  0f8616050000           -jbe 0xaa6002
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa6002;
    }
    // 00aa5aec  83f81b                 +cmp eax, 0x1b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5aef  0f8249050000           -jb 0xaa603e
    if (cpu.flags.cf)
    {
        goto L_0x00aa603e;
    }
    // 00aa5af5  0f865b050000           -jbe 0xaa6056
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa6056;
    }
    // 00aa5afb  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5afe  0f85c3feffff           -jne 0xaa59c7
    if (!cpu.flags.zf)
    {
        goto L_0x00aa59c7;
    }
    // 00aa5b04  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5b07  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5b0c  a3382fab00             -mov dword ptr [0xab2f38], eax
    app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */) = cpu.eax;
    // 00aa5b11  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5b13  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5b15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b19  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5b1c:
    // 00aa5b1c  772c                   -ja 0xaa5b4a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa5b4a;
    }
    // 00aa5b1e  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5b21  83fa08                 +cmp edx, 8
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
    // 00aa5b24  0f879ffeffff           -ja 0xaa59c9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa59c9;
    }
    // 00aa5b2a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa5b2c  ff24855459aa00         -jmp dword ptr [eax*4 + 0xaa5954]
    cpu.ip = app->getMemory<x86::reg32>(11163988 + cpu.eax * 4); goto dynamic_jump;
  case 0x00aa5b33:
L_0x00aa5b33:
    // 00aa5b33  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5b34  ff159046ab00           -call dword ptr [0xab4690]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224720) /* 0xab4690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5b3a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5b3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5b41  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5b43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b47  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5b4a:
    // 00aa5b4a  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5b4d  0f8574feffff           -jne 0xaa59c7
    if (!cpu.flags.zf)
    {
        goto L_0x00aa59c7;
    }
L_0x00aa5b53:
    // 00aa5b53  8b4516                 -mov eax, dword ptr [ebp + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(22) /* 0x16 */);
    // 00aa5b56  c1f810                 +sar eax, 0x10
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
    // 00aa5b59  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5b5a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5b5f  ff15b846ab00           -call dword ptr [0xab46b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224760) /* 0xab46b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5b65  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5b67  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5b69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5b6d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5b70:
    // 00aa5b70  0f8640050000           -jbe 0xaa60b6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa60b6;
    }
    // 00aa5b76  83f80c                 +cmp eax, 0xc
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
    // 00aa5b79  734b                   -jae 0xaa5bc6
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5bc6;
    }
    // 00aa5b7b  83f80a                 +cmp eax, 0xa
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
    // 00aa5b7e  0f8296040000           -jb 0xaa601a
    if (cpu.flags.cf)
    {
        goto L_0x00aa601a;
    }
    // 00aa5b84  0f874a020000           -ja 0xaa5dd4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa5dd4;
    }
    // 00aa5b8a  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5b8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa5b8f  0f84b5020000           -je 0xaa5e4a
    if (cpu.flags.zf)
    {
        goto L_0x00aa5e4a;
    }
    // 00aa5b95  83f801                 +cmp eax, 1
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
    // 00aa5b98  0f84cb020000           -je 0xaa5e69
    if (cpu.flags.zf)
    {
        goto L_0x00aa5e69;
    }
    // 00aa5b9e  83f802                 +cmp eax, 2
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
    // 00aa5ba1  0f8522feffff           -jne 0xaa59c9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa59c9;
    }
    // 00aa5ba7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5ba8  ff157846ab00           -call dword ptr [0xab4678]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224696) /* 0xab4678 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5bae  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa5bb0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5bb5  ff157c46ab00           -call dword ptr [0xab467c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224700) /* 0xab467c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5bbb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5bbd  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5bbf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5bc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5bc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5bc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5bc3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5bc6:
    // 00aa5bc6  0f8664030000           -jbe 0xaa5f30
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa5f30;
    }
    // 00aa5bcc  83f80e                 +cmp eax, 0xe
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5bcf  7339                   -jae 0xaa5c0a
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5c0a;
    }
    // 00aa5bd1  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5bd5  0f859e030000           -jne 0xaa5f79
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5f79;
    }
    // 00aa5bdb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aa5be0:
    // 00aa5be0  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5be3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5be4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa5be6  0f8594030000           -jne 0xaa5f80
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5f80;
    }
    // 00aa5bec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aa5bf1:
    // 00aa5bf1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5bf2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5bf4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5bf9  ff15d846ab00           -call dword ptr [0xab46d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224792) /* 0xab46d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5bff  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5c01  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5c03  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c06  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c07  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5c0a:
    // 00aa5c0a  7742                   -ja 0xaa5c4e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa5c4e;
    }
    // 00aa5c0c  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5c10  0f841dffffff           -je 0xaa5b33
    if (cpu.flags.zf)
    {
        goto L_0x00aa5b33;
    }
    // 00aa5c16  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa5c18  ff159046ab00           -call dword ptr [0xab4690]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224720) /* 0xab4690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5c1e  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5c21  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00aa5c24  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00aa5c27  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00aa5c29  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00aa5c2b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa5c2e  8d45bc                 -lea eax, [ebp - 0x44]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 00aa5c31  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa5c34  e837ecffff             -call 0xaa4870
    cpu.esp -= 4;
    sub_aa4870(app, cpu);
    if (cpu.terminate) return;
    // 00aa5c39  8d45bc                 -lea eax, [ebp - 0x44]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 00aa5c3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5c3d  ff159446ab00           -call dword ptr [0xab4694]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224724) /* 0xab4694 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5c43  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5c45  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5c47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c4b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5c4e:
    // 00aa5c4e  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5c51  0f8570fdffff           -jne 0xaa59c7
    if (!cpu.flags.zf)
    {
        goto L_0x00aa59c7;
    }
    // 00aa5c57  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5c5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa5c5b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5c60  ff158c46ab00           -call dword ptr [0xab468c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224716) /* 0xab468c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5c66  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5c68  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5c6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c6e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5c71:
    // 00aa5c71  7721                   -ja 0xaa5c94
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa5c94;
    }
    // 00aa5c73  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5c76  83f901                 +cmp ecx, 1
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
    // 00aa5c79  0f8309020000           -jae 0xaa5e88
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5e88;
    }
    // 00aa5c7f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa5c81  0f843e020000           -je 0xaa5ec5
    if (cpu.flags.zf)
    {
        goto L_0x00aa5ec5;
    }
    // 00aa5c87  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa5c89  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5c8b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5c8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5c91  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5c94:
    // 00aa5c94  83f806                 +cmp eax, 6
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
    // 00aa5c97  7326                   -jae 0xaa5cbf
    if (!cpu.flags.cf)
    {
        goto L_0x00aa5cbf;
    }
    // 00aa5c99  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5c9d  0f84f2000000           -je 0xaa5d95
    if (cpu.flags.zf)
    {
        goto L_0x00aa5d95;
    }
    // 00aa5ca3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00aa5ca8:
    // 00aa5ca8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5ca9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5cae  ff157446ab00           -call dword ptr [0xab4674]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224692) /* 0xab4674 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5cb4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5cb6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5cb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5cb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5cba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5cbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5cbc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5cbf:
    // 00aa5cbf  0f87b3000000           -ja 0xaa5d78
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa5d78;
    }
    // 00aa5cc5  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5cc9  0f84cd000000           -je 0xaa5d9c
    if (cpu.flags.zf)
    {
        goto L_0x00aa5d9c;
    }
    // 00aa5ccf  891d2c2fab00           -mov dword ptr [0xab2f2c], ebx
    app->getMemory<x86::reg32>(x86::reg32(11218732) /* 0xab2f2c */) = cpu.ebx;
L_0x00aa5cd5:
    // 00aa5cd5  8b0d5433ab00           -mov ecx, dword ptr [0xab3354]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11219796) /* 0xab3354 */);
    // 00aa5cdb  83f901                 +cmp ecx, 1
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
    // 00aa5cde  0f85c7000000           -jne 0xaa5dab
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5dab;
    }
    // 00aa5ce4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5ce6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa5ce7  8b3d2c2fab00           -mov edi, dword ptr [0xab2f2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11218732) /* 0xab2f2c */);
    // 00aa5ced  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa5cee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa5cef  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00aa5cf1  ff156046ab00           -call dword ptr [0xab4660]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224672) /* 0xab4660 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5cf7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5cf9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5cfb  a12c2fab00             -mov eax, dword ptr [0xab2f2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218732) /* 0xab2f2c */);
    // 00aa5d00  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5d01  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5d03  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
L_0x00aa5d05:
    // 00aa5d05  ff156446ab00           -call dword ptr [0xab4664]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224676) /* 0xab4664 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5d0b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5d10  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5d12  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5d14  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d15  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d18  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5d1b:
    // 00aa5d1b  762b                   -jbe 0xaa5d48
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa5d48;
    }
    // 00aa5d1d  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5d20  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5d25  a3fc2eab00             -mov dword ptr [0xab2efc], eax
    app->getMemory<x86::reg32>(x86::reg32(11218684) /* 0xab2efc */) = cpu.eax;
    // 00aa5d2a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5d2c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5d2e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d31  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d32  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5d35:
    // 00aa5d35  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa5d37  ff15fc46ab00           -call dword ptr [0xab46fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224828) /* 0xab46fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5d3d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5d3f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5d41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d45  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5d48:
    // 00aa5d48  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5d4b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa5d4c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5d51  ff156c46ab00           -call dword ptr [0xab466c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224684) /* 0xab466c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5d57  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5d59  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5d5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d5f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5d62:
    // 00aa5d62  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5d65  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5d66  e865f9ffff             -call 0xaa56d0
    cpu.esp -= 4;
    sub_aa56d0(app, cpu);
    if (cpu.terminate) return;
    // 00aa5d6b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa5d6d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5d6f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5d71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d75  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5d78:
    // 00aa5d78  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5d7b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5d7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5d7d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5d7f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5d84  ff157046ab00           -call dword ptr [0xab4670]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224688) /* 0xab4670 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5d8a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5d8c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5d8e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5d92  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5d95:
    // 00aa5d95  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa5d97  e90cffffff             -jmp 0xaa5ca8
    goto L_0x00aa5ca8;
L_0x00aa5d9c:
    // 00aa5d9c  c7052c2fab0001000000   -mov dword ptr [0xab2f2c], 1
    app->getMemory<x86::reg32>(x86::reg32(11218732) /* 0xab2f2c */) = 1 /*0x1*/;
    // 00aa5da6  e92affffff             -jmp 0xaa5cd5
    goto L_0x00aa5cd5;
L_0x00aa5dab:
    // 00aa5dab  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5dad  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa5daf  8b1d2c2fab00           -mov ebx, dword ptr [0xab2f2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11218732) /* 0xab2f2c */);
    // 00aa5db5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5db6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5db8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5dba  ff156046ab00           -call dword ptr [0xab4660]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224672) /* 0xab4660 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5dc0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5dc2  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa5dc4  8b352c2fab00           -mov esi, dword ptr [0xab2f2c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218732) /* 0xab2f2c */);
    // 00aa5dca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa5dcb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5dcd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5dcf  e931ffffff             -jmp 0xaa5d05
    goto L_0x00aa5d05;
L_0x00aa5dd4:
    // 00aa5dd4  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5dd7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa5dd9  83fa03                 +cmp edx, 3
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
    // 00aa5ddc  750a                   -jne 0xaa5de8
    if (!cpu.flags.zf)
    {
        goto L_0x00aa5de8;
    }
    // 00aa5dde  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00aa5de3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa5de5  894d18                 -mov dword ptr [ebp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x00aa5de8:
    // 00aa5de8  3b05242fab00           +cmp eax, dword ptr [0xab2f24]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11218724) /* 0xab2f24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa5dee  7427                   -je 0xaa5e17
    if (cpu.flags.zf)
    {
        goto L_0x00aa5e17;
    }
    // 00aa5df0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5df2  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa5df4  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00aa5df6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5df8  a3242fab00             -mov dword ptr [0xab2f24], eax
    app->getMemory<x86::reg32>(x86::reg32(11218724) /* 0xab2f24 */) = cpu.eax;
    // 00aa5dfd  ff156846ab00           -call dword ptr [0xab4668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224680) /* 0xab4668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5e03  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5e05  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5e07  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5e09  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5e0b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5e0d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5e0f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5e11  ff15c046ab00           -call dword ptr [0xab46c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224768) /* 0xab46c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa5e17:
    // 00aa5e17  8b15202fab00           -mov edx, dword ptr [0xab2f20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218720) /* 0xab2f20 */);
    // 00aa5e1d  a1242fab00             -mov eax, dword ptr [0xab2f24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218724) /* 0xab2f24 */);
    // 00aa5e22  e8b9faffff             -call 0xaa58e0
    cpu.esp -= 4;
    sub_aa58e0(app, cpu);
    if (cpu.terminate) return;
    // 00aa5e27  8b35242fab00           -mov esi, dword ptr [0xab2f24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218724) /* 0xab2f24 */);
    // 00aa5e2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa5e2e  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5e31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa5e32  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5e34  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5e39  ff15bc46ab00           -call dword ptr [0xab46bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224764) /* 0xab46bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5e3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5e41  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5e43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e47  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5e4a:
    // 00aa5e4a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5e4b  ff157846ab00           -call dword ptr [0xab4678]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224696) /* 0xab4678 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5e51  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00aa5e53  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5e58  ff157c46ab00           -call dword ptr [0xab467c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224700) /* 0xab467c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5e5e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5e60  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5e62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e66  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5e69:
    // 00aa5e69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa5e6a  ff157846ab00           -call dword ptr [0xab4678]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224696) /* 0xab4678 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5e70  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa5e72  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5e77  ff157c46ab00           -call dword ptr [0xab467c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224700) /* 0xab467c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5e7d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5e7f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5e81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5e85  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5e88:
    // 00aa5e88  765a                   -jbe 0xaa5ee4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa5ee4;
    }
    // 00aa5e8a  83f902                 +cmp ecx, 2
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
    // 00aa5e8d  0f8534fbffff           -jne 0xaa59c7
    if (!cpu.flags.zf)
    {
        goto L_0x00aa59c7;
    }
    // 00aa5e93  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa5e94  ff158046ab00           -call dword ptr [0xab4680]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224704) /* 0xab4680 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5e9a  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00aa5e9c  bfffff0000             -mov edi, 0xffff
    cpu.edi = 65535 /*0xffff*/;
    // 00aa5ea1  ff158446ab00           -call dword ptr [0xab4684]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224708) /* 0xab4684 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5ea7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5ea9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5eae  893d002fab00           -mov dword ptr [0xab2f00], edi
    app->getMemory<x86::reg32>(x86::reg32(11218688) /* 0xab2f00 */) = cpu.edi;
    // 00aa5eb4  ff158846ab00           -call dword ptr [0xab4688]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224712) /* 0xab4688 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5eba  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5ebc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5ebe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ebf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ec0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ec1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ec2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5ec5:
    // 00aa5ec5  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00aa5ec7  ff158446ab00           -call dword ptr [0xab4684]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224708) /* 0xab4684 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5ecd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5ece  ff158846ab00           -call dword ptr [0xab4688]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224712) /* 0xab4688 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5ed4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5ed9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5edb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5edd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ede  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5edf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ee0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ee1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5ee4:
    // 00aa5ee4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5ee6  ff158046ab00           -call dword ptr [0xab4680]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224704) /* 0xab4680 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5eec  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00aa5eee  ff158446ab00           -call dword ptr [0xab4684]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224708) /* 0xab4684 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5ef4  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 00aa5ef9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa5efb  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5f00  a3002fab00             -mov dword ptr [0xab2f00], eax
    app->getMemory<x86::reg32>(x86::reg32(11218688) /* 0xab2f00 */) = cpu.eax;
    // 00aa5f05  ff158846ab00           -call dword ptr [0xab4688]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224712) /* 0xab4688 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5f0b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5f0d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5f0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f13  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5f16:
    // 00aa5f16  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5f19  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5f1a  ff158846ab00           -call dword ptr [0xab4688]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224712) /* 0xab4688 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5f20  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5f25  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5f27  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5f29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f2d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5f30:
    // 00aa5f30  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5f33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa5f34  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5f39  ff153446ab00           -call dword ptr [0xab4634]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224628) /* 0xab4634 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5f3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5f41  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5f43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f47  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x00aa5f4a:
    // 00aa5f4a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa5f4c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5f51  ff159046ab00           -call dword ptr [0xab4690]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224720) /* 0xab4690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5f57  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5f59  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5f5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f5f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5f62:
    // 00aa5f62  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5f63  ff159046ab00           -call dword ptr [0xab4690]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224720) /* 0xab4690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5f69  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5f6e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5f70  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5f72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f76  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5f79:
    // 00aa5f79  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa5f7b  e960fcffff             -jmp 0xaa5be0
    goto L_0x00aa5be0;
L_0x00aa5f80:
    // 00aa5f80  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa5f82  e96afcffff             -jmp 0xaa5bf1
    goto L_0x00aa5bf1;
L_0x00aa5f87:
    // 00aa5f87  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00aa5f8a  ff15b446ab00           -call dword ptr [0xab46b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224756) /* 0xab46b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5f90  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5f95  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5f97  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5f99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5f9d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa5fa0:
    // 00aa5fa0  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa5fa3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa5fa8  a30c2fab00             -mov dword ptr [0xab2f0c], eax
    app->getMemory<x86::reg32>(x86::reg32(11218700) /* 0xab2f0c */) = cpu.eax;
    // 00aa5fad  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5faf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5fb1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fb2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fb3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fb5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x00aa5fb8:
    // 00aa5fb8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5fba  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa5fbc  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa5fbe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa5fbf  ff156846ab00           -call dword ptr [0xab4668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224680) /* 0xab4668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5fc5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5fc7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5fc9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fcc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fcd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x00aa5fd0:
    // 00aa5fd0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5fd2  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa5fd4  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00aa5fd6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5fd8  ff156846ab00           -call dword ptr [0xab4668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224680) /* 0xab4668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5fde  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5fe0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5fe2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fe3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fe4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fe5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fe6  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x00aa5fe9:
    // 00aa5fe9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5feb  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00aa5fed  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa5fef  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aa5ff1  ff156846ab00           -call dword ptr [0xab4668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224680) /* 0xab4668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa5ff7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa5ff9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa5ffb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ffc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ffd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5ffe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa5fff  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa6002:
    // 00aa6002  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa6005  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa600a  a3082fab00             -mov dword ptr [0xab2f08], eax
    app->getMemory<x86::reg32>(x86::reg32(11218696) /* 0xab2f08 */) = cpu.eax;
    // 00aa600f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa6011  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa6013  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6014  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6015  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6016  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6017  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa601a:
    // 00aa601a  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa601d  a3202fab00             -mov dword ptr [0xab2f20], eax
    app->getMemory<x86::reg32>(x86::reg32(11218720) /* 0xab2f20 */) = cpu.eax;
    // 00aa6022  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa6024  a1242fab00             -mov eax, dword ptr [0xab2f24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218724) /* 0xab2f24 */);
    // 00aa6029  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa602e  e8adf8ffff             -call 0xaa58e0
    cpu.esp -= 4;
    sub_aa58e0(app, cpu);
    if (cpu.terminate) return;
    // 00aa6033  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa6035  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa6037  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6038  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6039  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa603a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa603b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa603e:
    // 00aa603e  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa6041  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa6046  a3342fab00             -mov dword ptr [0xab2f34], eax
    app->getMemory<x86::reg32>(x86::reg32(11218740) /* 0xab2f34 */) = cpu.eax;
    // 00aa604b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa604d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa604f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6050  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6051  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6052  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6053  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa6056:
    // 00aa6056  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa6059  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa605e  a33c2fab00             -mov dword ptr [0xab2f3c], eax
    app->getMemory<x86::reg32>(x86::reg32(11218748) /* 0xab2f3c */) = cpu.eax;
    // 00aa6063  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa6065  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa6067  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6068  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6069  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa606a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa606b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa606e:
    // 00aa606e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00aa6071  a3302fab00             -mov dword ptr [0xab2f30], eax
    app->getMemory<x86::reg32>(x86::reg32(11218736) /* 0xab2f30 */) = cpu.eax;
    // 00aa6076  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aa6079  a33c2fab00             -mov dword ptr [0xab2f3c], eax
    app->getMemory<x86::reg32>(x86::reg32(11218748) /* 0xab2f3c */) = cpu.eax;
    // 00aa607e  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00aa6081  a3342fab00             -mov dword ptr [0xab2f34], eax
    app->getMemory<x86::reg32>(x86::reg32(11218740) /* 0xab2f34 */) = cpu.eax;
    // 00aa6086  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00aa6089  a3382fab00             -mov dword ptr [0xab2f38], eax
    app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */) = cpu.eax;
    // 00aa608e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa6093  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa6095  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa6097  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6098  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6099  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa609a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa609b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa609e:
    // 00aa609e  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa60a1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa60a6  a3442fab00             -mov dword ptr [0xab2f44], eax
    app->getMemory<x86::reg32>(x86::reg32(11218756) /* 0xab2f44 */) = cpu.eax;
    // 00aa60ab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa60ad  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa60af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60b3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa60b6:
    // 00aa60b6  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00aa60b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa60ba  ff15ec46ab00           -call dword ptr [0xab46ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224812) /* 0xab46ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa60c0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa60c5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa60c7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa60c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60cd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa60d0:
    // 00aa60d0  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa60d3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa60d8  a3102fab00             -mov dword ptr [0xab2f10], eax
    app->getMemory<x86::reg32>(x86::reg32(11218704) /* 0xab2f10 */) = cpu.eax;
    // 00aa60dd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa60df  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa60e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa60e5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void sub_aa60f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa60f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa60f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa60f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa60f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa60f4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00aa60f7  8b15382fab00           -mov edx, dword ptr [0xab2f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
    // 00aa60fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa60ff  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa6101  0f85a1000000           -jne 0xaa61a8
    if (!cpu.flags.zf)
    {
        goto L_0x00aa61a8;
    }
L_0x00aa6107:
    // 00aa6107  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa6109  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa610a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa610c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa610e  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 00aa6113  8b35042fab00           -mov esi, dword ptr [0xab2f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11218692) /* 0xab2f04 */);
    // 00aa6119  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa611a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00aa611f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa6121  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00aa6125  ff159846ab00           -call dword ptr [0xab4698]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224728) /* 0xab4698 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa612b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa612d  743e                   -je 0xaa616d
    if (cpu.flags.zf)
    {
        goto L_0x00aa616d;
    }
    // 00aa612f  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 00aa6134  e8771b0000             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aa6139  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa613b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa613d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa613f  742c                   -je 0xaa616d
    if (cpu.flags.zf)
    {
        goto L_0x00aa616d;
    }
    // 00aa6141  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa6145  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aa6147  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa614b  c7420804000000         -mov dword ptr [edx + 8], 4
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
    // 00aa6152  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00aa6155  a1182fab00             -mov eax, dword ptr [0xab2f18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218712) /* 0xab2f18 */);
    // 00aa615a  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00aa615d  a11c2fab00             -mov eax, dword ptr [0xab2f1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218716) /* 0xab2f1c */);
    // 00aa6162  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00aa6165  a1042fab00             -mov eax, dword ptr [0xab2f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218692) /* 0xab2f04 */);
    // 00aa616a  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00aa616d:
    // 00aa616d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa616f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6170  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa6172  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa6174  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 00aa6179  8b2d042fab00           -mov ebp, dword ptr [0xab2f04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11218692) /* 0xab2f04 */);
    // 00aa617f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa6180  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 00aa6185  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa6187  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00aa618b  ff159846ab00           -call dword ptr [0xab4698]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224728) /* 0xab4698 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6191  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa6193  7509                   -jne 0xaa619e
    if (!cpu.flags.zf)
    {
        goto L_0x00aa619e;
    }
    // 00aa6195  833d382fab0000         +cmp dword ptr [0xab2f38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa619c  7517                   -jne 0xaa61b5
    if (!cpu.flags.zf)
    {
        goto L_0x00aa61b5;
    }
L_0x00aa619e:
    // 00aa619e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa61a0  83c414                 +add esp, 0x14
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
    // 00aa61a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa61a8:
    // 00aa61a8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa61aa  ff15382fab00           -call dword ptr [0xab2f38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa61b0  e952ffffff             -jmp 0xaa6107
    goto L_0x00aa6107;
L_0x00aa61b5:
    // 00aa61b5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa61b6  ff15382fab00           -call dword ptr [0xab2f38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa61bc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa61be  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00aa61c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_aa61d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa61d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa61d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa61d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa61d3  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aa61d7  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00aa61dc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa61de  7508                   -jne 0xaa61e8
    if (!cpu.flags.zf)
    {
        goto L_0x00aa61e8;
    }
L_0x00aa61e0:
    // 00aa61e0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aa61e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa61e5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aa61e8:
    // 00aa61e8  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00aa61eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa61ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa61ed  ff159c46ab00           -call dword ptr [0xab469c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224732) /* 0xab469c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa61f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa61f4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa61f6  ff159c46ab00           -call dword ptr [0xab469c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224732) /* 0xab469c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa61fc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa61fe  e89d1b0000             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aa6203  833d382fab0000         +cmp dword ptr [0xab2f38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa620a  74d4                   -je 0xaa61e0
    if (cpu.flags.zf)
    {
        goto L_0x00aa61e0;
    }
    // 00aa620c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa620e  ff15382fab00           -call dword ptr [0xab2f38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6214  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aa6216  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6217  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6218  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6219  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void sub_aa6220(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa6220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa6221  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa6222  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa6223  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa6224  833d382fab0000         +cmp dword ptr [0xab2f38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa622b  7408                   -je 0xaa6235
    if (cpu.flags.zf)
    {
        goto L_0x00aa6235;
    }
    // 00aa622d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa622f  ff15382fab00           -call dword ptr [0xab2f38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa6235:
    // 00aa6235  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aa6239  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa623d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa623e  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6240  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa6241  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aa6245  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa6246  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aa624a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa624b  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aa624f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa6250  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aa6254  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa6255  a1042fab00             -mov eax, dword ptr [0xab2f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218692) /* 0xab2f04 */);
    // 00aa625a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa625b  ff15a446ab00           -call dword ptr [0xab46a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224740) /* 0xab46a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6261  8b15382fab00           -mov edx, dword ptr [0xab2f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
    // 00aa6267  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa6269  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa626b  7509                   -jne 0xaa6276
    if (!cpu.flags.zf)
    {
        goto L_0x00aa6276;
    }
    // 00aa626d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa626f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6270  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6271  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6272  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6273  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00aa6276:
    // 00aa6276  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa6278  ff15382fab00           -call dword ptr [0xab2f38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa627e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa6280  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6281  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6282  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6283  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6284  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void sub_aa6290(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa6290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa6291  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa6292  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa6293  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa6294  833d382fab0000         +cmp dword ptr [0xab2f38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa629b  7408                   -je 0xaa62a5
    if (cpu.flags.zf)
    {
        goto L_0x00aa62a5;
    }
    // 00aa629d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa629f  ff15382fab00           -call dword ptr [0xab2f38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa62a5:
    // 00aa62a5  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aa62a9  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa62ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa62ae  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa62b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa62b1  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aa62b5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa62b6  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aa62ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa62bb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa62bd  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00aa62c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa62c2  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00aa62c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa62c7  a1042fab00             -mov eax, dword ptr [0xab2f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218692) /* 0xab2f04 */);
    // 00aa62cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa62cd  ff15a046ab00           -call dword ptr [0xab46a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224736) /* 0xab46a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa62d3  8b15382fab00           -mov edx, dword ptr [0xab2f38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
    // 00aa62d9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa62db  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa62dd  7509                   -jne 0xaa62e8
    if (!cpu.flags.zf)
    {
        goto L_0x00aa62e8;
    }
    // 00aa62df  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa62e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa62e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa62e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa62e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa62e5  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00aa62e8:
    // 00aa62e8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa62ea  ff15382fab00           -call dword ptr [0xab2f38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11218744) /* 0xab2f38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa62f0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa62f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa62f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa62f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa62f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa62f6  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void sub_aa6300(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa6300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa6301  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00aa6307  8b9424f8000000         -mov edx, dword ptr [esp + 0xf8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    // 00aa630e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa6310  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6313  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6319  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa631c  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6322  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6324  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6327  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6329  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa632b  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa632e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6331  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6334  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6337  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6339  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa633b  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa633e  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6345  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6348  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa634b  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6352  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6355  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6358  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa635b  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa635e  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6365  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6368  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa636b  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6372  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6375  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6378  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa637b  8b9424fc000000         -mov edx, dword ptr [esp + 0xfc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 00aa6382  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa6386  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6389  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa638f  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6392  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6398  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa639a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa639d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa639f  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa63a1  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa63a4  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa63a7  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa63aa  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa63ad  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa63af  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa63b1  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa63b4  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa63bb  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa63be  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa63c1  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa63c8  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa63cb  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa63ce  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa63d1  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa63d4  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa63db  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa63de  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa63e1  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa63e8  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa63eb  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa63ee  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa63f1  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00aa63f8  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00aa63fc  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa63ff  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6405  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6408  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa640e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6410  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6413  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6415  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6417  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa641a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa641d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6420  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6423  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6425  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6427  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa642a  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6431  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6434  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6437  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa643e  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6441  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6444  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6447  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa644a  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6451  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6454  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6457  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa645e  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6461  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6464  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6467  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00aa646e  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00aa6475  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6478  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa647e  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6481  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6487  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6489  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa648c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa648e  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6490  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6493  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6496  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6499  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa649c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa649e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa64a0  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa64a3  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa64aa  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa64ad  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa64b0  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa64b7  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa64ba  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa64bd  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa64c0  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa64c3  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa64ca  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa64cd  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa64d0  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa64d7  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa64da  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa64dd  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa64e0  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00aa64e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa64e5  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aa64e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa64ea  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa64ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa64ef  ff150c47ab00           -call dword ptr [0xab470c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224844) /* 0xab470c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa64f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa64f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa64f8  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00aa64ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6500  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00aa6507  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6508  ff150c47ab00           -call dword ptr [0xab470c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224844) /* 0xab470c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa650e  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00aa6514  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6515  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void sub_aa6520(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa6520  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa6521  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa6522  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa6523  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00aa6529  8bac2400010000         -mov ebp, dword ptr [esp + 0x100]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00aa6530  8bbc2404010000         -mov edi, dword ptr [esp + 0x104]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00aa6537  8bb42408010000         -mov esi, dword ptr [esp + 0x108]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00aa653e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aa6540  0f8e1a020000           -jle 0xaa6760
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa6760;
    }
    // 00aa6546  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00aa6547:
    // 00aa6547  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00aa654a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00aa654d  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aa6551  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00aa6553  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6556  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa655c  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa655f  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6565  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6567  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa656a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa656c  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa656e  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6571  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6574  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6577  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa657a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa657c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa657e  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6581  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6588  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa658b  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa658e  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6595  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6598  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa659b  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa659e  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa65a1  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa65a8  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa65ab  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa65ae  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa65b5  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa65b8  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa65bb  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa65be  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00aa65c1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00aa65c4  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00aa65c8  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00aa65ca  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa65cd  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa65d3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa65d6  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa65dc  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa65de  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa65e1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa65e3  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa65e5  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa65e8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa65eb  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa65ee  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa65f1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa65f3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa65f5  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa65f8  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa65ff  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6602  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6605  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa660c  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa660f  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6612  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6615  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6618  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa661f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6622  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6625  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa662c  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa662f  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6632  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6635  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00aa6638  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00aa663b  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00aa6642  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00aa6644  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6647  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa664d  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6650  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6656  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6658  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa665b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa665d  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa665f  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6662  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6665  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6668  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa666b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa666d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa666f  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6672  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6679  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa667c  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa667f  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6686  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6689  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa668c  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa668f  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6692  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6699  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa669c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa669f  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa66a6  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa66a9  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa66ac  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa66af  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aa66b1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00aa66b4  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa66b8  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00aa66ba  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa66bd  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa66c3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa66c6  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa66cc  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa66ce  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa66d1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa66d3  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa66d5  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa66d8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa66db  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa66de  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa66e1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa66e3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa66e5  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa66e8  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa66ef  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa66f2  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa66f5  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa66fc  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa66ff  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6702  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6705  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6708  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa670f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6712  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6715  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa671c  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa671f  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6722  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6725  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00aa6729  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa672a  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00aa672e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa672f  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aa6733  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6734  ff150c47ab00           -call dword ptr [0xab470c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224844) /* 0xab470c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa673a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa673e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa673f  8d8424bc000000         -lea eax, [esp + 0xbc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00aa6746  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6747  8d842484000000         -lea eax, [esp + 0x84]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00aa674e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa674f  83c610                 +add esi, 0x10
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa6752  ff150c47ab00           -call dword ptr [0xab470c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224844) /* 0xab470c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6758  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa6759  0f85e8fdffff           -jne 0xaa6547
    if (!cpu.flags.zf)
    {
        goto L_0x00aa6547;
    }
    // 00aa675f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aa6760:
    // 00aa6760  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00aa6766  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6767  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6768  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6769  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void sub_aa6770(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa6770  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa6771  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00aa6777  8b9424bc000000         -mov edx, dword ptr [esp + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00aa677e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa6780  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6783  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6789  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa678c  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6792  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6794  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6797  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6799  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa679b  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa679e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa67a1  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa67a4  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa67a7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa67a9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa67ab  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa67ae  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa67b5  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa67b8  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa67bb  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa67c2  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa67c5  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa67c8  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa67cb  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa67ce  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa67d5  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa67d8  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa67db  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa67e2  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa67e5  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa67e8  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa67eb  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00aa67f2  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa67f6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa67f9  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa67ff  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6802  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6808  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa680a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa680d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa680f  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6811  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6814  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6817  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa681a  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa681d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa681f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6821  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6824  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa682b  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa682e  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6831  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6838  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa683b  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa683e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6841  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6844  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa684b  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa684e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6851  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6858  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa685b  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa685e  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6861  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00aa6868  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00aa686c  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa686f  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6875  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6878  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa687e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6880  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6883  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6885  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6887  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa688a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa688d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6890  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6893  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6895  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6897  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa689a  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa68a1  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa68a4  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa68a7  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa68ae  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa68b1  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa68b4  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa68b7  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa68ba  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa68c1  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa68c4  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa68c7  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa68ce  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa68d1  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa68d4  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa68d7  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00aa68db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa68dc  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aa68e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa68e1  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa68e5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa68e6  ff151047ab00           -call dword ptr [0xab4710]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa68ec  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00aa68f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa68f3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void sub_aa6900(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa6900  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa6901  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa6902  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa6903  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00aa6909  8bbc24c4000000         -mov edi, dword ptr [esp + 0xc4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00aa6910  8bac24c8000000         -mov ebp, dword ptr [esp + 0xc8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00aa6917  8bb424cc000000         -mov esi, dword ptr [esp + 0xcc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00aa691e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aa6920  0f8e85010000           -jle 0xaa6aab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa6aab;
    }
    // 00aa6926  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00aa6927:
    // 00aa6927  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00aa692a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00aa692d  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aa6931  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa6933  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6936  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa693c  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa693f  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6945  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6947  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa694a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa694c  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa694e  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6951  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6954  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6957  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa695a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa695c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa695e  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6961  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6968  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa696b  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa696e  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6975  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6978  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa697b  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa697e  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6981  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6988  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa698b  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa698e  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6995  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6998  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa699b  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa699e  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00aa69a1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00aa69a4  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00aa69a8  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa69aa  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa69ad  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa69b3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa69b6  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa69bc  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa69be  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa69c1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa69c3  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa69c5  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa69c8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa69cb  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa69ce  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa69d1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa69d3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa69d5  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa69d8  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa69df  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa69e2  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa69e5  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa69ec  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa69ef  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa69f2  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa69f5  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa69f8  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa69ff  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6a02  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6a05  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6a0c  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6a0f  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6a12  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6a15  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aa6a17  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00aa6a1a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa6a1e  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa6a20  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6a23  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6a29  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6a2c  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6a32  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6a34  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6a37  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6a39  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6a3b  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6a3e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6a41  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6a44  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6a47  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6a49  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6a4b  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6a4e  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6a55  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6a58  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6a5b  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6a62  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6a65  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6a68  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6a6b  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6a6e  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6a75  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6a78  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6a7b  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6a82  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6a85  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6a88  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6a8b  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00aa6a8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6a90  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00aa6a94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6a95  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aa6a99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6a9a  83c60c                 +add esi, 0xc
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa6a9d  ff151047ab00           -call dword ptr [0xab4710]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6aa3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa6aa4  0f857dfeffff           -jne 0xaa6927
    if (!cpu.flags.zf)
    {
        goto L_0x00aa6927;
    }
    // 00aa6aaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aa6aab:
    // 00aa6aab  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00aa6ab1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ab2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ab3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ab4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void sub_aa6ac0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa6ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa6ac1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa6ac2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa6ac3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa6ac4  81ecc4000000           -sub esp, 0xc4
    (cpu.esp) -= x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00aa6aca  8bb424d8000000         -mov esi, dword ptr [esp + 0xd8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(216) /* 0xd8 */);
    // 00aa6ad1  8b9424dc000000         -mov edx, dword ptr [esp + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00aa6ad8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa6ada  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6add  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6ae3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6ae6  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6aec  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6aee  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6af1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6af3  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6af5  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6af8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6afb  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6afe  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6b01  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6b03  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6b05  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6b08  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6b0f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6b12  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6b15  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6b1c  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6b1f  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6b22  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6b25  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6b28  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6b2f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6b32  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6b35  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6b3c  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6b3f  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6b42  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6b45  8b9424dc000000         -mov edx, dword ptr [esp + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00aa6b4c  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa6b50  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00aa6b53  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6b56  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6b5c  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6b5f  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6b65  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6b67  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6b6a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6b6c  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6b6e  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6b71  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6b74  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6b77  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6b7a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6b7c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6b7e  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6b81  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6b88  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6b8b  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6b8e  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6b95  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6b98  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6b9b  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6b9e  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6ba1  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6ba8  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6bab  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6bae  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6bb5  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6bb8  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6bbb  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6bbe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa6bc0  0f8ed9000000           -jle 0xaa6c9f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa6c9f;
    }
    // 00aa6bc6  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00aa6bcd  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00aa6bd0  898424c0000000         -mov dword ptr [esp + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00aa6bd7  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00aa6bde  8bbc24dc000000         -mov edi, dword ptr [esp + 0xdc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00aa6be5  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00aa6bea  8bac24dc000000         -mov ebp, dword ptr [esp + 0xdc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00aa6bf1  898424b8000000         -mov dword ptr [esp + 0xb8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 00aa6bf8  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00aa6bff  81c7a0000000           -add edi, 0xa0
    (cpu.edi) += x86::reg32(x86::sreg32(160 /*0xa0*/));
    // 00aa6c05  05e0000000             -add eax, 0xe0
    (cpu.eax) += x86::reg32(x86::sreg32(224 /*0xe0*/));
    // 00aa6c0a  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00aa6c0d  898424bc000000         -mov dword ptr [esp + 0xbc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = cpu.eax;
L_0x00aa6c14:
    // 00aa6c14  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00aa6c18  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00aa6c1a  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6c1d  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6c23  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6c26  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6c2c  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6c2e  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6c31  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6c33  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6c35  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6c38  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6c3b  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6c3e  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6c41  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6c43  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6c45  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6c48  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6c4f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6c52  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6c55  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6c5c  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6c5f  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6c62  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6c65  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6c68  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6c6f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6c72  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6c75  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6c7c  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6c7f  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6c82  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6c85  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00aa6c89  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6c8a  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aa6c8e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6c8f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa6c93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6c94  ff151047ab00           -call dword ptr [0xab4710]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6c9a  83fe02                 +cmp esi, 2
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
    // 00aa6c9d  7d0d                   -jge 0xaa6cac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aa6cac;
    }
L_0x00aa6c9f:
    // 00aa6c9f  81c4c4000000           -add esp, 0xc4
    (cpu.esp) += x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00aa6ca5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ca6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ca7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ca8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ca9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa6cac:
    // 00aa6cac  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00aa6cb3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa6cb5  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6cb8  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6cbe  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6cc1  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6cc7  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6cc9  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6ccc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6cce  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6cd0  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6cd3  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6cd6  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6cd9  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6cdc  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6cde  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6ce0  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6ce3  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6cea  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6ced  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6cf0  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6cf7  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6cfa  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6cfd  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6d00  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6d03  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6d0a  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6d0d  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6d10  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6d17  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6d1a  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6d1d  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6d20  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00aa6d24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6d25  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa6d29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6d2a  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00aa6d2e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6d2f  ff151047ab00           -call dword ptr [0xab4710]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6d35  83fe03                 +cmp esi, 3
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
    // 00aa6d38  0f8c61ffffff           -jl 0xaa6c9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa6c9f;
    }
    // 00aa6d3e  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00aa6d45  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa6d49  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6d4c  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6d52  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6d55  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6d5b  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6d5d  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6d60  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6d62  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6d64  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6d67  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6d6a  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6d6d  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6d70  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6d72  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6d74  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6d77  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6d7e  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6d81  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6d84  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6d8b  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6d8e  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6d91  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6d94  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6d97  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6d9e  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6da1  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6da4  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6dab  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6dae  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6db1  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6db4  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa6db8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6db9  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa6dbd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6dbe  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00aa6dc5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6dc6  ff151047ab00           -call dword ptr [0xab4710]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6dcc  83fe04                 +cmp esi, 4
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
    // 00aa6dcf  0f8ccafeffff           -jl 0xaa6c9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa6c9f;
    }
    // 00aa6dd5  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00aa6dd9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00aa6ddb  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6dde  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6de4  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6de7  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6ded  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6def  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6df2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6df4  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6df6  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6df9  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6dfc  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6dff  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6e02  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6e04  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6e06  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6e09  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6e10  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6e13  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6e16  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6e1d  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6e20  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6e23  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6e26  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6e29  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6e30  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6e33  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6e36  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6e3d  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6e40  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6e43  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6e46  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa6e4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6e4b  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00aa6e4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6e50  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa6e54  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6e55  ff151047ab00           -call dword ptr [0xab4710]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6e5b  83fe05                 +cmp esi, 5
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
    // 00aa6e5e  0f8c3bfeffff           -jl 0xaa6c9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa6c9f;
    }
    // 00aa6e64  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00aa6e6b  05c0000000             -add eax, 0xc0
    (cpu.eax) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00aa6e70  898424b4000000         -mov dword ptr [esp + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 00aa6e77  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa6e79  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa6e7b  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6e7e  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6e84  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6e87  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6e8d  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6e8f  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6e92  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6e94  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6e96  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6e99  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6e9c  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6e9f  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6ea2  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6ea4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6ea6  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6ea9  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6eb0  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6eb3  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6eb6  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6ebd  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6ec0  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6ec3  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6ec6  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6ec9  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6ed0  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6ed3  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6ed6  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6edd  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6ee0  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6ee3  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6ee6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa6ee8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6ee9  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00aa6eed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6eee  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00aa6ef2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6ef3  ff151047ab00           -call dword ptr [0xab4710]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6ef9  83fe06                 +cmp esi, 6
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa6efc  0f8c9dfdffff           -jl 0xaa6c9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa6c9f;
    }
    // 00aa6f02  8b9424bc000000         -mov edx, dword ptr [esp + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00aa6f09  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa6f0d  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa6f10  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa6f16  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa6f19  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa6f1f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa6f21  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa6f24  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa6f26  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6f28  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6f2b  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa6f2e  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa6f31  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa6f34  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa6f36  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa6f38  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa6f3b  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6f42  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa6f45  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa6f48  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6f4f  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa6f52  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6f55  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa6f58  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa6f5b  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6f62  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa6f65  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa6f68  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa6f6f  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa6f72  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6f75  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa6f78  81c5c0000000           -add ebp, 0xc0
    (cpu.ebp) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00aa6f7e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa6f80  81c7c0000000           -add edi, 0xc0
    (cpu.edi) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00aa6f86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6f87  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aa6f8b  8b9c24c0000000         -mov ebx, dword ptr [esp + 0xc0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00aa6f92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6f93  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00aa6f9a  81c3c0000000           -add ebx, 0xc0
    (cpu.ebx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00aa6fa0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa6fa1  83ee06                 -sub esi, 6
    (cpu.esi) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00aa6fa4  899c24c8000000         -mov dword ptr [esp + 0xc8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */) = cpu.ebx;
    // 00aa6fab  ff151047ab00           -call dword ptr [0xab4710]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa6fb1  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00aa6fb8  8b8c24b8000000         -mov ecx, dword ptr [esp + 0xb8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00aa6fbf  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00aa6fc6  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00aa6fcc  81c1c0000000           -add ecx, 0xc0
    (cpu.ecx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00aa6fd2  898424dc000000         -mov dword ptr [esp + 0xdc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */) = cpu.eax;
    // 00aa6fd9  899424c0000000         -mov dword ptr [esp + 0xc0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.edx;
    // 00aa6fe0  898c24b8000000         -mov dword ptr [esp + 0xb8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.ecx;
    // 00aa6fe7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa6fe9  0f8f25fcffff           -jg 0xaa6c14
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aa6c14;
    }
    // 00aa6fef  81c4c4000000           -add esp, 0xc4
    (cpu.esp) += x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00aa6ff5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ff6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ff7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ff8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa6ff9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void sub_aa7000(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7001  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7002  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7003  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa7004  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00aa700a  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00aa7011  8bac24cc000000         -mov ebp, dword ptr [esp + 0xcc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00aa7018  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa701a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00aa701c  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa701f  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa7025  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa7028  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa702e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa7030  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa7033  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa7035  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7037  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa703a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa703d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa7040  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa7043  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa7045  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7047  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa704a  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7051  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa7054  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa7057  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa705e  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa7061  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7064  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa7067  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa706a  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7071  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa7074  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa7077  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa707e  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa7081  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7084  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7087  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa708b  8d5520                 -lea edx, [ebp + 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00aa708e  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa7091  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa7097  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa709a  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa70a0  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa70a2  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa70a5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa70a7  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa70a9  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa70ac  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa70af  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa70b2  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa70b5  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa70b7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa70b9  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa70bc  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa70c3  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa70c6  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa70c9  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa70d0  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa70d3  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa70d6  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa70d9  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa70dc  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa70e3  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa70e6  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa70e9  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa70f0  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa70f3  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa70f6  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa70f9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aa70fb  0f8e91000000           -jle 0xaa7192
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa7192;
    }
    // 00aa7101  8d7560                 -lea esi, [ebp + 0x60]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(96) /* 0x60 */);
L_0x00aa7104:
    // 00aa7104  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00aa7107  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00aa710b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00aa710d  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa7110  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa7116  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa7119  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa711f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa7121  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa7124  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa7126  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7128  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa712b  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa712e  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa7131  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa7134  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa7136  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7138  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa713b  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7142  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa7145  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa7148  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa714f  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa7152  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7155  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa7158  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa715b  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7162  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa7165  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa7168  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa716f  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa7172  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7175  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7178  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00aa717c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa717d  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aa7181  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7182  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa7186  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7187  ff151047ab00           -call dword ptr [0xab4710]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa718d  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa7190  7d0d                   -jge 0xaa719f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aa719f;
    }
L_0x00aa7192:
    // 00aa7192  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00aa7198  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7199  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa719a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa719b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa719c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa719f:
    // 00aa719f  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa71a3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00aa71a5  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa71a8  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa71ae  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa71b1  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa71b7  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa71b9  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa71bc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa71be  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa71c0  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa71c3  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa71c6  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa71c9  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa71cc  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa71ce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa71d0  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa71d3  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa71da  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa71dd  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa71e0  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa71e7  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa71ea  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa71ed  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa71f0  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa71f3  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa71fa  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa71fd  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa7200  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7207  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa720a  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa720d  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7210  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa7214  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7215  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00aa7219  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa721a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa721e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa721f  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa7222  83c640                 -add esi, 0x40
    (cpu.esi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00aa7225  ff151047ab00           -call dword ptr [0xab4710]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224848) /* 0xab4710 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa722b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aa722d  0f8fd1feffff           -jg 0xaa7104
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aa7104;
    }
    // 00aa7233  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00aa7239  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa723a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa723b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa723c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa723d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void sub_aa7240(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7240  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7241  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00aa7244  8b942484000000         -mov edx, dword ptr [esp + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00aa724b  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa724f  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa7252  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa7258  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa725b  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa7261  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa7263  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa7266  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa7268  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa726a  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa726d  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa7270  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa7273  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa7276  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa7278  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa727a  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa727d  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7284  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa7287  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa728a  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7291  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa7294  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7297  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa729a  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa729d  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa72a4  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa72a7  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa72aa  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa72b1  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa72b4  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa72b7  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa72ba  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00aa72c1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa72c3  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa72c6  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa72cc  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa72cf  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa72d5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa72d7  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa72da  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa72dc  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa72de  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa72e1  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa72e4  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa72e7  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa72ea  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa72ec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa72ee  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa72f1  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa72f8  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa72fb  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa72fe  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7305  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa7308  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa730b  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa730e  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa7311  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7318  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa731b  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa731e  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7325  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa7328  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa732b  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa732e  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa7332  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7333  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa7337  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7338  ff151046ab00           -call dword ptr [0xab4610]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224592) /* 0xab4610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa733e  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00aa7341  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7342  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void sub_aa7350(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7350  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7351  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7352  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa7353  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00aa7356  8bbc2488000000         -mov edi, dword ptr [esp + 0x88]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00aa735d  8bac248c000000         -mov ebp, dword ptr [esp + 0x8c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00aa7364  8bb42490000000         -mov esi, dword ptr [esp + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00aa736b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aa736d  0f8e09010000           -jle 0xaa747c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa747c;
    }
    // 00aa7373  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00aa7374:
    // 00aa7374  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aa7376  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00aa7379  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa737d  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa737f  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa7382  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa7388  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa738b  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa7391  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa7393  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa7396  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa7398  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa739a  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa739d  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa73a0  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa73a3  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa73a6  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa73a8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa73aa  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa73ad  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa73b4  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa73b7  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa73ba  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa73c1  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa73c4  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa73c7  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa73ca  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa73cd  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa73d4  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa73d7  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa73da  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa73e1  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa73e4  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa73e7  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa73ea  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00aa73ed  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00aa73f0  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aa73f4  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa73f6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa73f9  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa73ff  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa7402  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa7408  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa740a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa740d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa740f  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7411  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7414  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa7417  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa741a  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa741d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa741f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7421  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa7424  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa742b  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa742e  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa7431  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7438  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa743b  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa743e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa7441  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa7444  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa744b  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa744e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa7451  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7458  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa745b  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa745e  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7461  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aa7465  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7466  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa746a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa746b  83c608                 +add esi, 8
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa746e  ff151046ab00           -call dword ptr [0xab4610]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224592) /* 0xab4610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7474  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa7475  0f85f9feffff           -jne 0xaa7374
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7374;
    }
    // 00aa747b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aa747c:
    // 00aa747c  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00aa747f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7480  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7481  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7482  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void sub_aa7490(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7490  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7491  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7492  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7493  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa7494  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00aa7497  8bac248c000000         -mov ebp, dword ptr [esp + 0x8c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00aa749e  8bbc2490000000         -mov edi, dword ptr [esp + 0x90]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00aa74a5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa74a7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00aa74a9  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa74ac  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa74b2  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa74b5  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa74bb  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa74bd  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa74c0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa74c2  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa74c4  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa74c7  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa74ca  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa74cd  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa74d0  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa74d2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa74d4  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa74d7  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa74de  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa74e1  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa74e4  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa74eb  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa74ee  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa74f1  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa74f4  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa74f7  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa74fe  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa7501  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa7504  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa750b  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa750e  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7511  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7514  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aa7516  0f8e89000000           -jle 0xaa75a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa75a5;
    }
    // 00aa751c  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00aa751f:
    // 00aa751f  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa7523  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00aa7525  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa7528  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa752e  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa7531  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa7537  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa7539  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa753c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa753e  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7540  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7543  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa7546  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa7549  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa754c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa754e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7550  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa7553  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa755a  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa755d  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa7560  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7567  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa756a  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa756d  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa7570  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa7573  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa757a  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa757d  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa7580  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7587  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa758a  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa758d  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7590  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aa7594  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7595  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa7599  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa759a  ff151046ab00           -call dword ptr [0xab4610]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224592) /* 0xab4610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa75a0  83fd02                 +cmp ebp, 2
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa75a3  7d0a                   -jge 0xaa75af
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aa75af;
    }
L_0x00aa75a5:
    // 00aa75a5  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00aa75a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa75a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa75aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa75ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa75ac  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa75af:
    // 00aa75af  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00aa75b2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa75b4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00aa75b6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa75b9  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa75bf  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa75c2  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa75c8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa75ca  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa75cd  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa75cf  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa75d1  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa75d4  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa75d7  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa75da  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa75dd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa75df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa75e1  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa75e4  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa75eb  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa75ee  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa75f1  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa75f8  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa75fb  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa75fe  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa7601  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa7604  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa760b  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa760e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa7611  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7618  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa761b  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa761e  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7621  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa7623  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7624  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aa7628  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7629  83c640                 -add esi, 0x40
    (cpu.esi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00aa762c  83ed02                 -sub ebp, 2
    (cpu.ebp) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa762f  ff151046ab00           -call dword ptr [0xab4610]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224592) /* 0xab4610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7635  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aa7637  0f8fe2feffff           -jg 0xaa751f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aa751f;
    }
    // 00aa763d  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00aa7640  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7641  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7642  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7643  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7644  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void sub_aa7650(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7651  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00aa7654  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00aa7658  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa765a  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa765d  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa7663  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa7666  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa766c  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa766e  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa7671  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa7673  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7675  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7678  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa767b  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa767e  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa7681  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa7683  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7685  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa7688  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa768f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa7692  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa7695  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa769c  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa769f  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa76a2  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa76a5  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa76a8  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa76af  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa76b2  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa76b5  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa76bc  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa76bf  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa76c2  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa76c5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa76c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa76c8  ff15b046ab00           -call dword ptr [0xab46b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224752) /* 0xab46b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa76ce  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00aa76d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa76d2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void sub_aa76e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa76e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa76e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa76e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa76e3  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00aa76e6  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00aa76ea  8b6c2450               -mov ebp, dword ptr [esp + 0x50]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00aa76ee  8b7c2454               -mov edi, dword ptr [esp + 0x54]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00aa76f2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa76f4  0f8e89000000           -jle 0xaa7783
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa7783;
    }
    // 00aa76fa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00aa76fb:
    // 00aa76fb  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00aa76fd  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00aa7700  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa7704  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa7706  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa7709  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa770f  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa7712  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa7718  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa771a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa771d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa771f  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7721  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7724  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa7727  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa772a  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa772d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa772f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7731  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa7734  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa773b  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa773e  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa7741  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7748  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa774b  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa774e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa7751  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa7754  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa775b  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa775e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa7761  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7768  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa776b  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa776e  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7771  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7772  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa7775  ff15b046ab00           -call dword ptr [0xab46b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224752) /* 0xab46b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa777b  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa777c  0f8579ffffff           -jne 0xaa76fb
    if (!cpu.flags.zf)
    {
        goto L_0x00aa76fb;
    }
    // 00aa7782  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aa7783:
    // 00aa7783  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00aa7786  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7787  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7788  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7789  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void sub_aa7790(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7790  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7791  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7792  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00aa7795  8b7c2448               -mov edi, dword ptr [esp + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00aa7799  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00aa779d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aa779f  0f8e80000000           -jle 0xaa7825
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa7825;
    }
    // 00aa77a5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00aa77a6:
    // 00aa77a6  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa77aa  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00aa77ac  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00aa77af  d80d5c33ab00           -fmul dword ptr [0xab335c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219804) /* 0xab335c */));
    // 00aa77b5  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00aa77b8  d80d5833ab00           -fmul dword ptr [0xab3358]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11219800) /* 0xab3358 */));
    // 00aa77be  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00aa77c0  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00aa77c3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa77c5  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa77c7  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa77ca  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa77cd  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00aa77d0  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00aa77d3  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00aa77d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa77d7  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00aa77da  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa77e1  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00aa77e4  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00aa77e7  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa77ee  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00aa77f1  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa77f4  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00aa77f7  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00aa77fa  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa7801  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00aa7804  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa7807  8b0c9d1042ab00         -mov ecx, dword ptr [ebx*4 + 0xab4210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11223568) /* 0xab4210 */ + cpu.ebx * 4);
    // 00aa780e  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00aa7811  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7814  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7817  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7818  83c620                 +add esi, 0x20
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa781b  ff15b046ab00           -call dword ptr [0xab46b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11224752) /* 0xab46b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7821  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa7822  7582                   -jne 0xaa77a6
    if (!cpu.flags.zf)
    {
        goto L_0x00aa77a6;
    }
    // 00aa7824  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aa7825:
    // 00aa7825  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00aa7828  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7829  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa782a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 */
void sub_aa782e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa782e  e99d060000             -jmp 0xaa7ed0
    return sub_aa7ed0(app, cpu);
}

/* align: skip  */
/* data blob: 0342aa00574154434f4d20432f432b2b33322052756e2d54696d652073797374656d2e2028632920436f7079726967687420627920574154434f4d20496e7465726e6174696f6e616c20436f72702e20313938382d313939342e20416c6c207269676874732072657365727665642e */
void sub_aa78a2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa78a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa78a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aa78a5  d9e4                   -ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 00aa78a7  83ec18                 +sub esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa78aa  9b                     -wait 
    /*nothing*/;
    // 00aa78ab  dd7df8                 -fnstsw word ptr [ebp - 8]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.fpu.status.word;
    // 00aa78ae  dd55e8                 +fst qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    // 00aa78b1  8a65f9                 -mov ah, byte ptr [ebp - 7]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 00aa78b4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa78b5  751a                   -jne 0xaa78d1
    if (!cpu.flags.zf)
    {
        goto L_0x00aa78d1;
    }
    // 00aa78b7  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
L_0x00aa78b9:
    // 00aa78b9  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa78bb  dd5df0                 -fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa78be  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00aa78c1  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00aa78c4  e8a1070000             -call 0xaa806a
    cpu.esp -= 4;
    sub_aa806a(app, cpu);
    if (cpu.terminate) return;
    // 00aa78c9  83ec08                 +sub esp, 8
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
    // 00aa78cc  e9f9000000             -jmp 0xaa79ca
    goto L_0x00aa79ca;
L_0x00aa78d1:
    // 00aa78d1  d9c1                   +fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 00aa78d3  d9fc                   +frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00aa78d5  d8da                   +fcomp st(2)
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(cpu.fpu.st(2)));
    cpu.fpu.pop();
    // 00aa78d7  9b                     -wait 
    /*nothing*/;
    // 00aa78d8  dd7dfa                 -fnstsw word ptr [ebp - 6]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = cpu.fpu.status.word;
    // 00aa78db  9b                     -wait 
    /*nothing*/;
    // 00aa78dc  8a65fb                 -mov ah, byte ptr [ebp - 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 00aa78df  733b                   -jae 0xaa791c
    if (!cpu.flags.cf)
    {
        goto L_0x00aa791c;
    }
    // 00aa78e1  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00aa78e3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa78e4  75d3                   -jne 0xaa78b9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa78b9;
    }
    // 00aa78e6  66b80200               -mov ax, 2
    cpu.ax = 2 /*0x2*/;
    // 00aa78ea  668945fc               -mov word ptr [ebp - 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
    // 00aa78ee  df45fc                 +fild word ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00aa78f1  d9c2                   +fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 00aa78f3  d9f8                   +fprem 
    cpu.fpu.st(0) = cpu.fpu.rem(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00aa78f5  9b                     -wait 
    /*nothing*/;
    // 00aa78f6  dd7dfc                 -fnstsw word ptr [ebp - 4]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.fpu.status.word;
    // 00aa78f9  9b                     -wait 
    /*nothing*/;
    // 00aa78fa  8a65fd                 -mov ah, byte ptr [ebp - 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */);
    // 00aa78fd  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa78fe  b400                   -mov ah, 0
    cpu.ah = 0 /*0x0*/;
    // 00aa7900  7a11                   -jp 0xaa7913
    if (cpu.flags.pf)
    {
        goto L_0x00aa7913;
    }
    // 00aa7902  d9e4                   +ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 00aa7904  9b                     -wait 
    /*nothing*/;
    // 00aa7905  dd7dfc                 -fnstsw word ptr [ebp - 4]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.fpu.status.word;
    // 00aa7908  9b                     -wait 
    /*nothing*/;
    // 00aa7909  8a65fd                 -mov ah, byte ptr [ebp - 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */);
    // 00aa790c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa790d  b400                   -mov ah, 0
    cpu.ah = 0 /*0x0*/;
    // 00aa790f  7402                   -je 0xaa7913
    if (cpu.flags.zf)
    {
        goto L_0x00aa7913;
    }
    // 00aa7911  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
L_0x00aa7913:
    // 00aa7913  8865f9                 -mov byte ptr [ebp - 7], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */) = cpu.ah;
    // 00aa7916  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7918  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa791a  eb08                   -jmp 0xaa7924
    goto L_0x00aa7924;
L_0x00aa791c:
    // 00aa791c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa791d  7405                   -je 0xaa7924
    if (cpu.flags.zf)
    {
        goto L_0x00aa7924;
    }
    // 00aa791f  e987000000             -jmp 0xaa79ab
    goto L_0x00aa79ab;
L_0x00aa7924:
    // 00aa7924  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 00aa7926  dd5df0                 -fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa7929  9b                     -wait 
    /*nothing*/;
    // 00aa792a  668b45f6               -mov ax, word ptr [ebp - 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00aa792e  6625f07f               -and ax, 0x7ff0
    cpu.ax &= x86::reg16(x86::sreg16(32752 /*0x7ff0*/));
    // 00aa7932  662df03f               -sub ax, 0x3ff0
    (cpu.ax) -= x86::reg16(x86::sreg16(16368 /*0x3ff0*/));
    // 00aa7936  663d0001               +cmp ax, 0x100
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(256 /*0x100*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aa793a  736f                   -jae 0xaa79ab
    if (!cpu.flags.cf)
    {
        goto L_0x00aa79ab;
    }
    // 00aa793c  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 00aa793e  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00aa7941  9b                     -wait 
    /*nothing*/;
    // 00aa7942  668b45fe               -mov ax, word ptr [ebp - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00aa7946  6609c0                 +or ax, ax
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(cpu.ax))));
    // 00aa7949  750b                   -jne 0xaa7956
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7956;
    }
    // 00aa794b  668b45fc               -mov ax, word ptr [ebp - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00aa794f  e881000000             -call 0xaa79d5
    cpu.esp -= 4;
    sub_aa79d5(app, cpu);
    if (cpu.terminate) return;
    // 00aa7954  eb2b                   -jmp 0xaa7981
    goto L_0x00aa7981;
L_0x00aa7956:
    // 00aa7956  6640                   +inc ax
    {
        x86::reg16& tmp = cpu.ax;
        cpu.flags.of = ~(1 & (tmp >> 15));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 15);
        cpu.set_szp(tmp);
    }
    // 00aa7958  7551                   -jne 0xaa79ab
    if (!cpu.flags.zf)
    {
        goto L_0x00aa79ab;
    }
    // 00aa795a  660b45fc               +or ax, word ptr [ebp - 4]
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */)))));
    // 00aa795e  744b                   -je 0xaa79ab
    if (cpu.flags.zf)
    {
        goto L_0x00aa79ab;
    }
    // 00aa7960  66f7d8                 -neg ax
    cpu.ax = ~cpu.ax + 1;
    // 00aa7963  e86d000000             -call 0xaa79d5
    cpu.esp -= 4;
    sub_aa79d5(app, cpu);
    if (cpu.terminate) return;
    // 00aa7968  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00aa796a  f6059036ab0001         +test byte ptr [0xab3690], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(11220624) /* 0xab3690 */) & 1 /*0x1*/));
    // 00aa7971  7504                   -jne 0xaa7977
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7977;
    }
    // 00aa7973  def1                   +fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00aa7975  eb0a                   -jmp 0xaa7981
    goto L_0x00aa7981;
L_0x00aa7977:
    // 00aa7977  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00aa797c  e8fe080000             -call 0xaa827f
    cpu.esp -= 4;
    sub_aa827f(app, cpu);
    if (cpu.terminate) return;
L_0x00aa7981:
    // 00aa7981  dd55f8                 -fst qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    // 00aa7984  9b                     -wait 
    /*nothing*/;
    // 00aa7985  668b45f8               -mov ax, word ptr [ebp - 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00aa7989  660b45fa               -or ax, word ptr [ebp - 6]
    cpu.ax |= x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */)));
    // 00aa798d  660b45fc               +or ax, word ptr [ebp - 4]
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */)))));
    // 00aa7991  7514                   -jne 0xaa79a7
    if (!cpu.flags.zf)
    {
        goto L_0x00aa79a7;
    }
    // 00aa7993  668b45fe               -mov ax, word ptr [ebp - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00aa7997  66d1e0                 -shl ax, 1
    cpu.ax <<= 1 /*0x1*/ % 32;
    // 00aa799a  663de0ff               +cmp ax, 0xffe0
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65504 /*0xffe0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aa799e  7507                   -jne 0xaa79a7
    if (!cpu.flags.zf)
    {
        goto L_0x00aa79a7;
    }
L_0x00aa79a0:
    // 00aa79a0  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 00aa79a2  e912ffffff             -jmp 0xaa78b9
    goto L_0x00aa78b9;
L_0x00aa79a7:
    // 00aa79a7  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa79a9  eb1f                   -jmp 0xaa79ca
    goto L_0x00aa79ca;
L_0x00aa79ab:
    // 00aa79ab  d9ed                   -fldln2 
    cpu.fpu.push(0.6931471805599453);
    // 00aa79ad  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00aa79af  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa79b1  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 00aa79b3  d9f1                   -fyl2x 
    cpu.fpu.st(1) = cpu.fpu.log2(cpu.fpu.st(0)) * cpu.fpu.st(1);
    cpu.fpu.pop();
    // 00aa79b5  b007                   -mov al, 7
    cpu.al = 7 /*0x7*/;
    // 00aa79b7  e840070000             -call 0xaa80fc
    cpu.esp -= 4;
    sub_aa80fc(app, cpu);
    if (cpu.terminate) return;
    // 00aa79bc  3c00                   +cmp al, 0
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
    // 00aa79be  75e0                   -jne 0xaa79a0
    if (!cpu.flags.zf)
    {
        goto L_0x00aa79a0;
    }
    // 00aa79c0  8a65f9                 -mov ah, byte ptr [ebp - 7]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 00aa79c3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa79c4  7302                   -jae 0xaa79c8
    if (!cpu.flags.cf)
    {
        goto L_0x00aa79c8;
    }
    // 00aa79c6  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00aa79c8:
    // 00aa79c8  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00aa79ca:
    // 00aa79ca  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa79cd  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00aa79d0  9b                     -wait 
    /*nothing*/;
    // 00aa79d1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa79d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa79d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa79d5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00aa79d5:
    // 00aa79d5  66d1e8                 +shr ax, 1
    {
        x86::reg16 tmp = 1 /*0x1*/ % 32;
        x86::reg16& op = cpu.ax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (16 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aa79d8  7604                   -jbe 0xaa79de
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa79de;
    }
    // 00aa79da  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 00aa79dc  ebf7                   -jmp 0xaa79d5
    goto L_0x00aa79d5;
L_0x00aa79de:
    // 00aa79de  7313                   -jae 0xaa79f3
    if (!cpu.flags.cf)
    {
        goto L_0x00aa79f3;
    }
    // 00aa79e0  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
L_0x00aa79e2:
    // 00aa79e2  740b                   -je 0xaa79ef
    if (cpu.flags.zf)
    {
        goto L_0x00aa79ef;
    }
    // 00aa79e4  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 00aa79e6  66d1e8                 +shr ax, 1
    {
        x86::reg16 tmp = 1 /*0x1*/ % 32;
        x86::reg16& op = cpu.ax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (16 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aa79e9  7302                   -jae 0xaa79ed
    if (!cpu.flags.cf)
    {
        goto L_0x00aa79ed;
    }
    // 00aa79eb  dcc9                   +fmul st(1), st(0)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
L_0x00aa79ed:
    // 00aa79ed  ebf3                   -jmp 0xaa79e2
    goto L_0x00aa79e2;
L_0x00aa79ef:
    // 00aa79ef  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa79f1  eb04                   -jmp 0xaa79f7
    goto L_0x00aa79f7;
L_0x00aa79f3:
    // 00aa79f3  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa79f5  d9e8                   -fld1 
    cpu.fpu.push(1.0);
L_0x00aa79f7:
    // 00aa79f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa79f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa79f8  dd44240c               -fld qword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa79fc  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00aa7a00  e89dfeffff             -call 0xaa78a2
    cpu.esp -= 4;
    sub_aa78a2(app, cpu);
    if (cpu.terminate) return;
    // 00aa7a05  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa7a10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7a10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7a11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa7a12  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa7a15  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00aa7a19  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00aa7a1b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aa7a1f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aa7a22  b87a33ab00             -mov eax, 0xab337a
    cpu.eax = 11219834 /*0xab337a*/;
    // 00aa7a27  e8780e0000             -call 0xaa88a4
    cpu.esp -= 4;
    sub_aa88a4(app, cpu);
    if (cpu.terminate) return;
    // 00aa7a2c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa7a2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7a30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7a31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa7a40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7a40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7a42  0f8538100000           -jne 0xaa8a80
    if (!cpu.flags.zf)
    {
        return sub_aa8a80(app, cpu);
    }
    // 00aa7a48  e853110000             -call 0xaa8ba0
    cpu.esp -= 4;
    sub_aa8ba0(app, cpu);
    if (cpu.terminate) return;
    // 00aa7a4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa7a4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa7a50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7a50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa7a54(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7a54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7a55  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa7a56  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa7a58  ff157035ab00           -call dword ptr [0xab3570]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220336) /* 0xab3570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7a5e  803d7048ab0000         +cmp byte ptr [0xab4870], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11225200) /* 0xab4870 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa7a65  750f                   -jne 0xaa7a76
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7a76;
    }
    // 00aa7a67  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00aa7a6c  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00aa7a71  e806150000             -call 0xaa8f7c
    cpu.esp -= 4;
    sub_aa8f7c(app, cpu);
    if (cpu.terminate) return;
L_0x00aa7a76:
    // 00aa7a76  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa7a78  e803000000             -call 0xaa7a80
    cpu.esp -= 4;
    sub_aa7a80(app, cpu);
    if (cpu.terminate) return;
    // 00aa7a7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7a7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7a7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa7a80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7a80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa7a81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa7a83  ff157035ab00           -call dword ptr [0xab3570]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220336) /* 0xab3570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7a89  ff157435ab00           -call dword ptr [0xab3574]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220340) /* 0xab3574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7a8f  833d3437ab0000         +cmp dword ptr [0xab3734], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11220788) /* 0xab3734 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa7a96  7406                   -je 0xaa7a9e
    if (cpu.flags.zf)
    {
        goto L_0x00aa7a9e;
    }
    // 00aa7a98  ff153437ab00           -call dword ptr [0xab3734]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220788) /* 0xab3734 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa7a9e:
    // 00aa7a9e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa7aa0  e9f7130000             -jmp 0xaa8e9c
    return sub_aa8e9c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa7ab0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7ab0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa7ab1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00aa7ab3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa7ab4  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 00aa7ab6  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00aa7ab9  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00aa7abb  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00aa7abe  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00aa7ac0  e80b150000             -call 0xaa8fd0
    cpu.esp -= 4;
    sub_aa8fd0(app, cpu);
    if (cpu.terminate) return;
    // 00aa7ac5  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ac6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ac7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa7ad0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7ad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7ad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa7ad2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa7ad3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7ad4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7ad5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa7ad6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aa7ad8  8b35a44eab00           -mov esi, dword ptr [0xab4ea4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */);
    // 00aa7ade  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa7ae0  743f                   -je 0xaa7b21
    if (cpu.flags.zf)
    {
        goto L_0x00aa7b21;
    }
    // 00aa7ae2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7ae4  743b                   -je 0xaa7b21
    if (cpu.flags.zf)
    {
        goto L_0x00aa7b21;
    }
    // 00aa7ae6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aa7ae8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aa7ae9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aa7aeb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aa7aed  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7aef  49                     -dec ecx
    (cpu.ecx)--;
    // 00aa7af0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa7af2  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 00aa7af4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aa7af6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa7af7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa7af8  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00aa7afa  eb1f                   -jmp 0xaa7b1b
    goto L_0x00aa7b1b;
L_0x00aa7afc:
    // 00aa7afc  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00aa7afe  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00aa7b00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa7b02  e879150000             -call 0xaa9080
    cpu.esp -= 4;
    sub_aa9080(app, cpu);
    if (cpu.terminate) return;
    // 00aa7b07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7b09  750d                   -jne 0xaa7b18
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7b18;
    }
    // 00aa7b0b  803c393d               +cmp byte ptr [ecx + edi], 0x3d
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
    // 00aa7b0f  7507                   -jne 0xaa7b18
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7b18;
    }
    // 00aa7b11  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00aa7b14  01c8                   +add eax, ecx
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
    // 00aa7b16  eb0b                   -jmp 0xaa7b23
    goto L_0x00aa7b23;
L_0x00aa7b18:
    // 00aa7b18  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00aa7b1b:
    // 00aa7b1b  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aa7b1d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7b1f  75db                   -jne 0xaa7afc
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7afc;
    }
L_0x00aa7b21:
    // 00aa7b21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00aa7b23:
    // 00aa7b23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7b24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7b25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7b26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7b27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7b28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7b29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa7b30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7b30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7b31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa7b32  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa7b34  39d0                   +cmp eax, edx
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
    // 00aa7b36  746c                   -je 0xaa7ba4
    if (cpu.flags.zf)
    {
        goto L_0x00aa7ba4;
    }
L_0x00aa7b38:
    // 00aa7b38  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aa7b3a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aa7b3c  39c1                   +cmp ecx, eax
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
    // 00aa7b3e  7569                   -jne 0xaa7ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7ba9;
    }
    // 00aa7b40  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aa7b42  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00aa7b47  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7b49  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00aa7b4e  7554                   -jne 0xaa7ba4
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7ba4;
    }
    // 00aa7b50  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00aa7b53  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00aa7b56  39c1                   +cmp ecx, eax
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
    // 00aa7b58  754f                   -jne 0xaa7ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7ba9;
    }
    // 00aa7b5a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aa7b5c  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00aa7b61  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7b63  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00aa7b68  753a                   -jne 0xaa7ba4
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7ba4;
    }
    // 00aa7b6a  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00aa7b6d  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aa7b70  39c1                   +cmp ecx, eax
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
    // 00aa7b72  7535                   -jne 0xaa7ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7ba9;
    }
    // 00aa7b74  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aa7b76  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00aa7b7b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7b7d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00aa7b82  7520                   -jne 0xaa7ba4
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7ba4;
    }
    // 00aa7b84  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00aa7b87  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa7b8a  39c1                   +cmp ecx, eax
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
    // 00aa7b8c  751b                   -jne 0xaa7ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7ba9;
    }
    // 00aa7b8e  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aa7b91  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aa7b94  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aa7b96  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00aa7b9b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7b9d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00aa7ba2  7494                   -je 0xaa7b38
    if (cpu.flags.zf)
    {
        goto L_0x00aa7b38;
    }
L_0x00aa7ba4:
    // 00aa7ba4  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa7ba6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ba7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ba8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa7ba9:
    // 00aa7ba9  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa7bab  751d                   -jne 0xaa7bca
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7bca;
    }
    // 00aa7bad  3c00                   +cmp al, 0
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
    // 00aa7baf  74f3                   -je 0xaa7ba4
    if (cpu.flags.zf)
    {
        goto L_0x00aa7ba4;
    }
    // 00aa7bb1  38ec                   +cmp ah, ch
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa7bb3  7515                   -jne 0xaa7bca
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7bca;
    }
    // 00aa7bb5  80fc00                 +cmp ah, 0
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa7bb8  74ea                   -je 0xaa7ba4
    if (cpu.flags.zf)
    {
        goto L_0x00aa7ba4;
    }
    // 00aa7bba  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00aa7bbd  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00aa7bc0  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa7bc2  7506                   -jne 0xaa7bca
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7bca;
    }
    // 00aa7bc4  3c00                   +cmp al, 0
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
    // 00aa7bc6  74dc                   -je 0xaa7ba4
    if (cpu.flags.zf)
    {
        goto L_0x00aa7ba4;
    }
    // 00aa7bc8  38ec                   +cmp ah, ch
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x00aa7bca:
    // 00aa7bca  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00aa7bcc  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aa7bce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7bcf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7bd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa7be0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7be0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7be1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa7be2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x00aa7be3:
    // 00aa7be3  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa7be5  fec2                   -inc dl
    (cpu.dl)++;
    // 00aa7be7  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aa7bed  f6827835ab0002         +test byte ptr [edx + 0xab3578], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11220344) /* 0xab3578 */) & 2 /*0x2*/));
    // 00aa7bf4  7403                   -je 0xaa7bf9
    if (cpu.flags.zf)
    {
        goto L_0x00aa7bf9;
    }
    // 00aa7bf6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aa7bf7  ebea                   -jmp 0xaa7be3
    goto L_0x00aa7be3;
L_0x00aa7bf9:
    // 00aa7bf9  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa7bfb  80f92b                 +cmp cl, 0x2b
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa7bfe  7405                   -je 0xaa7c05
    if (cpu.flags.zf)
    {
        goto L_0x00aa7c05;
    }
    // 00aa7c00  80f92d                 +cmp cl, 0x2d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa7c03  7501                   -jne 0xaa7c06
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7c06;
    }
L_0x00aa7c05:
    // 00aa7c05  40                     -inc eax
    (cpu.eax)++;
L_0x00aa7c06:
    // 00aa7c06  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00aa7c08:
    // 00aa7c08  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa7c0a  fec3                   -inc bl
    (cpu.bl)++;
    // 00aa7c0c  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aa7c12  f6837835ab0020         +test byte ptr [ebx + 0xab3578], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11220344) /* 0xab3578 */) & 32 /*0x20*/));
    // 00aa7c19  740f                   -je 0xaa7c2a
    if (cpu.flags.zf)
    {
        goto L_0x00aa7c2a;
    }
    // 00aa7c1b  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00aa7c1e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7c20  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa7c22  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7c24  40                     -inc eax
    (cpu.eax)++;
    // 00aa7c25  83ea30                 +sub edx, 0x30
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa7c28  ebde                   -jmp 0xaa7c08
    goto L_0x00aa7c08;
L_0x00aa7c2a:
    // 00aa7c2a  80f92d                 +cmp cl, 0x2d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa7c2d  7502                   -jne 0xaa7c31
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7c31;
    }
    // 00aa7c2f  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00aa7c31:
    // 00aa7c31  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa7c33  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7c34  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7c35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7c36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa7c40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7c40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa7c41  8b154048ab00           -mov edx, dword ptr [0xab4840]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11225152) /* 0xab4840 */);
    // 00aa7c47  83fa20                 +cmp edx, 0x20
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
    // 00aa7c4a  7d12                   -jge 0xaa7c5e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aa7c5e;
    }
    // 00aa7c4c  42                     -inc edx
    (cpu.edx)++;
    // 00aa7c4d  890495bc47ab00         -mov dword ptr [edx*4 + 0xab47bc], eax
    app->getMemory<x86::reg32>(x86::reg32(11225020) /* 0xab47bc */ + cpu.edx * 4) = cpu.eax;
    // 00aa7c54  89154048ab00           -mov dword ptr [0xab4840], edx
    app->getMemory<x86::reg32>(x86::reg32(11225152) /* 0xab4840 */) = cpu.edx;
    // 00aa7c5a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa7c5c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7c5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa7c5e:
    // 00aa7c5e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aa7c63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7c64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa7c68(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7c68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7c69  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa7c6a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aa7c6b  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00aa7c6d  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00aa7c6f  8b1d4048ab00           -mov ebx, dword ptr [0xab4840]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11225152) /* 0xab4840 */);
    // 00aa7c75  83fb21                 +cmp ebx, 0x21
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
    // 00aa7c78  7425                   -je 0xaa7c9f
    if (cpu.flags.zf)
    {
        goto L_0x00aa7c9f;
    }
    // 00aa7c7a  c7054048ab0021000000   -mov dword ptr [0xab4840], 0x21
    app->getMemory<x86::reg32>(x86::reg32(11225152) /* 0xab4840 */) = 33 /*0x21*/;
    // 00aa7c84  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa7c86  7417                   -je 0xaa7c9f
    if (cpu.flags.zf)
    {
        goto L_0x00aa7c9f;
    }
    // 00aa7c88  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
L_0x00aa7c8f:
    // 00aa7c8f  8b82bc47ab00           -mov eax, dword ptr [edx + 0xab47bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(11225020) /* 0xab47bc */);
    // 00aa7c95  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa7c98  4b                     -dec ebx
    (cpu.ebx)--;
    // 00aa7c99  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7c9b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa7c9d  75f0                   -jne 0xaa7c8f
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7c8f;
    }
L_0x00aa7c9f:
    // 00aa7c9f  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ca1  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ca3  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ca4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ca5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ca6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa7cb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7cb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7cb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa7cb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa7cb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7cb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7cb5  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aa7cb6  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00aa7cb8  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00aa7cba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa7cbb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa7cbe  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aa7cc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7cc2  7405                   -je 0xaa7cc9
    if (cpu.flags.zf)
    {
        goto L_0x00aa7cc9;
    }
    // 00aa7cc4  83f8d4                 +cmp eax, -0x2c
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
    // 00aa7cc7  7607                   -jbe 0xaa7cd0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa7cd0;
    }
L_0x00aa7cc9:
    // 00aa7cc9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa7ccb  e9be000000             -jmp 0xaa7d8e
    goto L_0x00aa7d8e;
L_0x00aa7cd0:
    // 00aa7cd0  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00aa7cd3  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00aa7cd6  83fd10                 +cmp ebp, 0x10
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
    // 00aa7cd9  7305                   -jae 0xaa7ce0
    if (!cpu.flags.cf)
    {
        goto L_0x00aa7ce0;
    }
    // 00aa7cdb  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x00aa7ce0:
    // 00aa7ce0  ff15c436ab00           -call dword ptr [0xab36c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220676) /* 0xab36c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7ce6  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00aa7ce8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa7cea  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00aa7ced:
    // 00aa7ced  3b2d8436ab00           +cmp ebp, dword ptr [0xab3684]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11220612) /* 0xab3684 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa7cf3  760c                   -jbe 0xaa7d01
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa7d01;
    }
    // 00aa7cf5  8b0d8036ab00           -mov ecx, dword ptr [0xab3680]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11220608) /* 0xab3680 */);
    // 00aa7cfb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7cfd  7510                   -jne 0xaa7d0f
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7d0f;
    }
    // 00aa7cff  eb02                   -jmp 0xaa7d03
    goto L_0x00aa7d03;
L_0x00aa7d01:
    // 00aa7d01  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00aa7d03:
    // 00aa7d03  890d8436ab00           -mov dword ptr [0xab3684], ecx
    app->getMemory<x86::reg32>(x86::reg32(11220612) /* 0xab3684 */) = cpu.ecx;
    // 00aa7d09  8b0d7c36ab00           -mov ecx, dword ptr [0xab367c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11220604) /* 0xab367c */);
L_0x00aa7d0f:
    // 00aa7d0f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7d11  743c                   -je 0xaa7d4f
    if (cpu.flags.zf)
    {
        goto L_0x00aa7d4f;
    }
    // 00aa7d13  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00aa7d16  890d8036ab00           -mov dword ptr [0xab3680], ecx
    app->getMemory<x86::reg32>(x86::reg32(11220608) /* 0xab3680 */) = cpu.ecx;
    // 00aa7d1c  39fe                   +cmp esi, edi
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
    // 00aa7d1e  721c                   -jb 0xaa7d3c
    if (cpu.flags.cf)
    {
        goto L_0x00aa7d3c;
    }
    // 00aa7d20  b87c36ab00             -mov eax, 0xab367c
    cpu.eax = 11220604 /*0xab367c*/;
    // 00aa7d25  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00aa7d27  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00aa7d2d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00aa7d2f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aa7d31  e8ca130000             -call 0xaa9100
    cpu.esp -= 4;
    sub_aa9100(app, cpu);
    if (cpu.terminate) return;
    // 00aa7d36  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa7d38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7d3a  7542                   -jne 0xaa7d7e
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7d7e;
    }
L_0x00aa7d3c:
    // 00aa7d3c  3b358436ab00           +cmp esi, dword ptr [0xab3684]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11220612) /* 0xab3684 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa7d42  7606                   -jbe 0xaa7d4a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa7d4a;
    }
    // 00aa7d44  89358436ab00           -mov dword ptr [0xab3684], esi
    app->getMemory<x86::reg32>(x86::reg32(11220612) /* 0xab3684 */) = cpu.esi;
L_0x00aa7d4a:
    // 00aa7d4a  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aa7d4d  ebc0                   -jmp 0xaa7d0f
    goto L_0x00aa7d0f;
L_0x00aa7d4f:
    // 00aa7d4f  803c2400               +cmp byte ptr [esp], 0
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
    // 00aa7d53  750b                   -jne 0xaa7d60
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7d60;
    }
    // 00aa7d55  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aa7d57  e8b8160000             -call 0xaa9414
    cpu.esp -= 4;
    sub_aa9414(app, cpu);
    if (cpu.terminate) return;
    // 00aa7d5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7d5e  7515                   -jne 0xaa7d75
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7d75;
    }
L_0x00aa7d60:
    // 00aa7d60  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aa7d62  e819170000             -call 0xaa9480
    cpu.esp -= 4;
    sub_aa9480(app, cpu);
    if (cpu.terminate) return;
    // 00aa7d67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7d69  7413                   -je 0xaa7d7e
    if (cpu.flags.zf)
    {
        goto L_0x00aa7d7e;
    }
    // 00aa7d6b  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00aa7d6d  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 00aa7d70  e978ffffff             -jmp 0xaa7ced
    goto L_0x00aa7ced;
L_0x00aa7d75:
    // 00aa7d75  c6042401               -mov byte ptr [esp], 1
    app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 00aa7d79  e96fffffff             -jmp 0xaa7ced
    goto L_0x00aa7ced;
L_0x00aa7d7e:
    // 00aa7d7e  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00aa7d80  882db04eab00           -mov byte ptr [0xab4eb0], ch
    app->getMemory<x86::reg8>(x86::reg32(11226800) /* 0xab4eb0 */) = cpu.ch;
    // 00aa7d86  ff15cc36ab00           -call dword ptr [0xab36cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220684) /* 0xab36cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7d8c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00aa7d8e:
    // 00aa7d8e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa7d91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7d92  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa7d94  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa7d96  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa7d97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7d98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7d99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7d9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7d9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7d9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_aa7da0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7da0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7da1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa7da2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa7da3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7da4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aa7da6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7da8  0f84f3000000           -je 0xaa7ea1
    if (cpu.flags.zf)
    {
        goto L_0x00aa7ea1;
    }
    // 00aa7dae  ff15c436ab00           -call dword ptr [0xab36c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220676) /* 0xab36c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7db4  8b0d5048ab00           -mov ecx, dword ptr [0xab4850]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11225168) /* 0xab4850 */);
    // 00aa7dba  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7dbc  7440                   -je 0xaa7dfe
    if (cpu.flags.zf)
    {
        goto L_0x00aa7dfe;
    }
    // 00aa7dbe  39f1                   +cmp ecx, esi
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
    // 00aa7dc0  770c                   -ja 0xaa7dce
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7dce;
    }
    // 00aa7dc2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aa7dc4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7dc6  39f0                   +cmp eax, esi
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
    // 00aa7dc8  0f878d000000           -ja 0xaa7e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e5b;
    }
L_0x00aa7dce:
    // 00aa7dce  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aa7dd0  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00aa7dd3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7dd5  7410                   -je 0xaa7de7
    if (cpu.flags.zf)
    {
        goto L_0x00aa7de7;
    }
    // 00aa7dd7  39f1                   +cmp ecx, esi
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
    // 00aa7dd9  770c                   -ja 0xaa7de7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7de7;
    }
    // 00aa7ddb  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aa7ddd  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7ddf  39f0                   +cmp eax, esi
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
    // 00aa7de1  0f8774000000           -ja 0xaa7e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e5b;
    }
L_0x00aa7de7:
    // 00aa7de7  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aa7dea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7dec  7410                   -je 0xaa7dfe
    if (cpu.flags.zf)
    {
        goto L_0x00aa7dfe;
    }
    // 00aa7dee  39f1                   +cmp ecx, esi
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
    // 00aa7df0  770c                   -ja 0xaa7dfe
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7dfe;
    }
    // 00aa7df2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aa7df4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7df6  39f0                   +cmp eax, esi
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
    // 00aa7df8  0f875d000000           -ja 0xaa7e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e5b;
    }
L_0x00aa7dfe:
    // 00aa7dfe  8b0d8036ab00           -mov ecx, dword ptr [0xab3680]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11220608) /* 0xab3680 */);
    // 00aa7e04  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7e06  7434                   -je 0xaa7e3c
    if (cpu.flags.zf)
    {
        goto L_0x00aa7e3c;
    }
    // 00aa7e08  39f1                   +cmp ecx, esi
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
    // 00aa7e0a  7708                   -ja 0xaa7e14
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e14;
    }
    // 00aa7e0c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aa7e0e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7e10  39f0                   +cmp eax, esi
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
    // 00aa7e12  7747                   -ja 0xaa7e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e5b;
    }
L_0x00aa7e14:
    // 00aa7e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aa7e16  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00aa7e19  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7e1b  740c                   -je 0xaa7e29
    if (cpu.flags.zf)
    {
        goto L_0x00aa7e29;
    }
    // 00aa7e1d  39f1                   +cmp ecx, esi
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
    // 00aa7e1f  7708                   -ja 0xaa7e29
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e29;
    }
    // 00aa7e21  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aa7e23  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7e25  39f0                   +cmp eax, esi
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
    // 00aa7e27  7732                   -ja 0xaa7e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e5b;
    }
L_0x00aa7e29:
    // 00aa7e29  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aa7e2c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7e2e  740c                   -je 0xaa7e3c
    if (cpu.flags.zf)
    {
        goto L_0x00aa7e3c;
    }
    // 00aa7e30  39f1                   +cmp ecx, esi
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
    // 00aa7e32  7708                   -ja 0xaa7e3c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e3c;
    }
    // 00aa7e34  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aa7e36  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7e38  39f0                   +cmp eax, esi
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
    // 00aa7e3a  771f                   -ja 0xaa7e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e5b;
    }
L_0x00aa7e3c:
    // 00aa7e3c  8b0d7c36ab00           -mov ecx, dword ptr [0xab367c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11220604) /* 0xab367c */);
    // 00aa7e42  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7e44  7455                   -je 0xaa7e9b
    if (cpu.flags.zf)
    {
        goto L_0x00aa7e9b;
    }
L_0x00aa7e46:
    // 00aa7e46  39f1                   +cmp ecx, esi
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
    // 00aa7e48  7708                   -ja 0xaa7e52
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e52;
    }
    // 00aa7e4a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aa7e4c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa7e4e  39f0                   +cmp eax, esi
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
    // 00aa7e50  7709                   -ja 0xaa7e5b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa7e5b;
    }
L_0x00aa7e52:
    // 00aa7e52  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aa7e55  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa7e57  75ed                   -jne 0xaa7e46
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7e46;
    }
    // 00aa7e59  eb40                   -jmp 0xaa7e9b
    goto L_0x00aa7e9b;
L_0x00aa7e5b:
    // 00aa7e5b  b87c36ab00             -mov eax, 0xab367c
    cpu.eax = 11220604 /*0xab367c*/;
    // 00aa7e60  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00aa7e62  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00aa7e68  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00aa7e6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa7e6c  e83f130000             -call 0xaa91b0
    cpu.esp -= 4;
    sub_aa91b0(app, cpu);
    if (cpu.terminate) return;
    // 00aa7e71  8b158036ab00           -mov edx, dword ptr [0xab3680]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11220608) /* 0xab3680 */);
    // 00aa7e77  890d5048ab00           -mov dword ptr [0xab4850], ecx
    app->getMemory<x86::reg32>(x86::reg32(11225168) /* 0xab4850 */) = cpu.ecx;
    // 00aa7e7d  39d1                   +cmp ecx, edx
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
    // 00aa7e7f  7312                   -jae 0xaa7e93
    if (!cpu.flags.cf)
    {
        goto L_0x00aa7e93;
    }
    // 00aa7e81  8b1d8436ab00           -mov ebx, dword ptr [0xab3684]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11220612) /* 0xab3684 */);
    // 00aa7e87  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00aa7e8a  39d8                   +cmp eax, ebx
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
    // 00aa7e8c  7605                   -jbe 0xaa7e93
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa7e93;
    }
    // 00aa7e8e  a38436ab00             -mov dword ptr [0xab3684], eax
    app->getMemory<x86::reg32>(x86::reg32(11220612) /* 0xab3684 */) = cpu.eax;
L_0x00aa7e93:
    // 00aa7e93  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00aa7e95  8825b04eab00           -mov byte ptr [0xab4eb0], ah
    app->getMemory<x86::reg8>(x86::reg32(11226800) /* 0xab4eb0 */) = cpu.ah;
L_0x00aa7e9b:
    // 00aa7e9b  ff15cc36ab00           -call dword ptr [0xab36cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220684) /* 0xab36cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa7ea1:
    // 00aa7ea1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ea2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ea3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ea4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ea5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa7eb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7eb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa7eb1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa7eb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa7ed0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00aa7ed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa7ed1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7ed2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7ed3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa7ed4  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00aa7ed8  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa7edc  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa7ee0  83ff03                 +cmp edi, 3
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
    // 00aa7ee3  0f8777010000           -ja 0xaa8060
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa8060;
    }
    // 00aa7ee9  2eff24bdc07eaa00       -jmp dword ptr cs:[edi*4 + 0xaa7ec0]
    cpu.ip = app->getMemory<x86::reg32>(11173568 + cpu.edi * 4); goto dynamic_jump;
  case 0x00aa7ef1:
    // 00aa7ef1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa7ef3  e8a0190000             -call 0xaa9898
    cpu.esp -= 4;
    sub_aa9898(app, cpu);
    if (cpu.terminate) return;
    // 00aa7ef8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7efa  0f8462010000           -je 0xaa8062
    if (cpu.flags.zf)
    {
        goto L_0x00aa8062;
    }
    // 00aa7f00  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa7f01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7f02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7f03  e808c3ffff             -call 0xaa4210
    cpu.esp -= 4;
    sub_aa4210(app, cpu);
    if (cpu.terminate) return;
    // 00aa7f08  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa7f0a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa7f0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f10  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00aa7f13:
    // 00aa7f13  8b156048ab00           -mov edx, dword ptr [0xab4860]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11225184) /* 0xab4860 */);
    // 00aa7f19  42                     -inc edx
    (cpu.edx)++;
    // 00aa7f1a  89156048ab00           -mov dword ptr [0xab4860], edx
    app->getMemory<x86::reg32>(x86::reg32(11225184) /* 0xab4860 */) = cpu.edx;
    // 00aa7f20  83fa01                 +cmp edx, 1
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
    // 00aa7f23  7e16                   -jle 0xaa7f3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa7f3b;
    }
    // 00aa7f25  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa7f27  e8e41b0000             -call 0xaa9b10
    cpu.esp -= 4;
    sub_aa9b10(app, cpu);
    if (cpu.terminate) return;
    // 00aa7f2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7f2e  740b                   -je 0xaa7f3b
    if (cpu.flags.zf)
    {
        goto L_0x00aa7f3b;
    }
    // 00aa7f30  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7f32  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa7f34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f38  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00aa7f3b:
    // 00aa7f3b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa7f40  e8e70f0000             -call 0xaa8f2c
    cpu.esp -= 4;
    sub_aa8f2c(app, cpu);
    if (cpu.terminate) return;
    // 00aa7f45  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00aa7f47  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa7f49  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa7f4e  e8c50c0000             -call 0xaa8c18
    cpu.esp -= 4;
    sub_aa8c18(app, cpu);
    if (cpu.terminate) return;
    // 00aa7f53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7f55  750b                   -jne 0xaa7f62
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7f62;
    }
    // 00aa7f57  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7f59  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa7f5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f5f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00aa7f62:
    // 00aa7f62  e8d1180000             -call 0xaa9838
    cpu.esp -= 4;
    sub_aa9838(app, cpu);
    if (cpu.terminate) return;
    // 00aa7f67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7f69  750b                   -jne 0xaa7f76
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7f76;
    }
    // 00aa7f6b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7f6d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa7f6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f73  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00aa7f76:
    // 00aa7f76  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa7f78  e81b190000             -call 0xaa9898
    cpu.esp -= 4;
    sub_aa9898(app, cpu);
    if (cpu.terminate) return;
    // 00aa7f7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7f7f  750b                   -jne 0xaa7f8c
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7f8c;
    }
    // 00aa7f81  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7f83  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa7f85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7f89  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00aa7f8c:
    // 00aa7f8c  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00aa7f91  e8960f0000             -call 0xaa8f2c
    cpu.esp -= 4;
    sub_aa8f2c(app, cpu);
    if (cpu.terminate) return;
    // 00aa7f96  e8d9190000             -call 0xaa9974
    cpu.esp -= 4;
    sub_aa9974(app, cpu);
    if (cpu.terminate) return;
    // 00aa7f9b  833da837ab0000         +cmp dword ptr [0xab37a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11220904) /* 0xab37a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa7fa2  7422                   -je 0xaa7fc6
    if (cpu.flags.zf)
    {
        goto L_0x00aa7fc6;
    }
    // 00aa7fa4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa7fa5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7fa6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7fa7  ff15a837ab00           -call dword ptr [0xab37a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220904) /* 0xab37a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7fad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7faf  7515                   -jne 0xaa7fc6
    if (!cpu.flags.zf)
    {
        goto L_0x00aa7fc6;
    }
    // 00aa7fb1  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00aa7fb6  e8c10f0000             -call 0xaa8f7c
    cpu.esp -= 4;
    sub_aa8f7c(app, cpu);
    if (cpu.terminate) return;
    // 00aa7fbb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa7fbd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa7fbf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7fc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7fc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7fc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7fc3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00aa7fc6:
    // 00aa7fc6  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00aa7fcb  e85c0f0000             -call 0xaa8f2c
    cpu.esp -= 4;
    sub_aa8f2c(app, cpu);
    if (cpu.terminate) return;
    // 00aa7fd0  e81b1c0000             -call 0xaa9bf0
    cpu.esp -= 4;
    sub_aa9bf0(app, cpu);
    if (cpu.terminate) return;
    // 00aa7fd5  ff15e836ab00           -call dword ptr [0xab36e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220712) /* 0xab36e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa7fdb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa7fdc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7fdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7fde  e82dc2ffff             -call 0xaa4210
    cpu.esp -= 4;
    sub_aa4210(app, cpu);
    if (cpu.terminate) return;
    // 00aa7fe3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa7fe5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa7fe7  7577                   -jne 0xaa8060
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8060;
    }
    // 00aa7fe9  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00aa7fee  e8890f0000             -call 0xaa8f7c
    cpu.esp -= 4;
    sub_aa8f7c(app, cpu);
    if (cpu.terminate) return;
    // 00aa7ff3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa7ff5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ff6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ff7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ff8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa7ff9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00aa7ffc:
    // 00aa7ffc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa7ffd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa7ffe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa7fff  e80cc2ffff             -call 0xaa4210
    cpu.esp -= 4;
    sub_aa4210(app, cpu);
    if (cpu.terminate) return;
    // 00aa8004  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa8006  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa800b  e8dc180000             -call 0xaa98ec
    cpu.esp -= 4;
    sub_aa98ec(app, cpu);
    if (cpu.terminate) return;
    // 00aa8010  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa8012  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8013  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8014  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8015  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8016  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00aa8019:
    // 00aa8019  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa801a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa801b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa801c  e8efc1ffff             -call 0xaa4210
    cpu.esp -= 4;
    sub_aa4210(app, cpu);
    if (cpu.terminate) return;
    // 00aa8021  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00aa8026  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa8028  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00aa802d  e84a0f0000             -call 0xaa8f7c
    cpu.esp -= 4;
    sub_aa8f7c(app, cpu);
    if (cpu.terminate) return;
    // 00aa8032  833da837ab0000         +cmp dword ptr [0xab37a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11220904) /* 0xab37a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8039  7409                   -je 0xaa8044
    if (cpu.flags.zf)
    {
        goto L_0x00aa8044;
    }
    // 00aa803b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa803c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa803d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa803e  ff15a837ab00           -call dword ptr [0xab37a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220904) /* 0xab37a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa8044:
    // 00aa8044  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00aa8049  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa804b  e82c0f0000             -call 0xaa8f7c
    cpu.esp -= 4;
    sub_aa8f7c(app, cpu);
    if (cpu.terminate) return;
    // 00aa8050  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa8055  e892180000             -call 0xaa98ec
    cpu.esp -= 4;
    sub_aa98ec(app, cpu);
    if (cpu.terminate) return;
    // 00aa805a  ff0d6048ab00           -dec dword ptr [0xab4860]
    (app->getMemory<x86::reg32>(x86::reg32(11225184) /* 0xab4860 */))--;
L_0x00aa8060:
    // 00aa8060  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00aa8062:
    // 00aa8062  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8063  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8064  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8065  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8066  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void sub_aa806a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa806a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa806b  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aa806d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa806e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa806f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8070  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa8071  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aa8074  8a6518                 -mov ah, byte ptr [ebp + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00aa8077  80fc01                 +cmp ah, 1
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa807a  772f                   -ja 0xaa80ab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa80ab;
    }
    // 00aa807c  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00aa807e  7524                   -jne 0xaa80a4
    if (!cpu.flags.zf)
    {
        goto L_0x00aa80a4;
    }
    // 00aa8080  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00aa8082  dc5d10                 +fcomp qword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 00aa8085  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aa8087  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa8088  730a                   -jae 0xaa8094
    if (!cpu.flags.cf)
    {
        goto L_0x00aa8094;
    }
    // 00aa808a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00aa808c  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00aa808f  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 00aa8092  eb4f                   -jmp 0xaa80e3
    goto L_0x00aa80e3;
L_0x00aa8094:
    // 00aa8094  7607                   -jbe 0xaa809d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa809d;
    }
    // 00aa8096  b847800000             -mov eax, 0x8047
    cpu.eax = 32839 /*0x8047*/;
    // 00aa809b  eb38                   -jmp 0xaa80d5
    goto L_0x00aa80d5;
L_0x00aa809d:
    // 00aa809d  b847400000             -mov eax, 0x4047
    cpu.eax = 16455 /*0x4047*/;
    // 00aa80a2  eb31                   -jmp 0xaa80d5
    goto L_0x00aa80d5;
L_0x00aa80a4:
    // 00aa80a4  b847200000             -mov eax, 0x2047
    cpu.eax = 8263 /*0x2047*/;
    // 00aa80a9  eb2a                   -jmp 0xaa80d5
    goto L_0x00aa80d5;
L_0x00aa80ab:
    // 00aa80ab  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00aa80ad  dc5d10                 +fcomp qword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 00aa80b0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aa80b2  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa80b3  720a                   -jb 0xaa80bf
    if (cpu.flags.cf)
    {
        goto L_0x00aa80bf;
    }
    // 00aa80b5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aa80b7  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 00aa80ba  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00aa80bd  eb24                   -jmp 0xaa80e3
    goto L_0x00aa80e3;
L_0x00aa80bf:
    // 00aa80bf  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00aa80c1  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 00aa80c4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aa80c6  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa80c7  7307                   -jae 0xaa80d0
    if (!cpu.flags.cf)
    {
        goto L_0x00aa80d0;
    }
    // 00aa80c9  b807810000             -mov eax, 0x8107
    cpu.eax = 33031 /*0x8107*/;
    // 00aa80ce  eb05                   -jmp 0xaa80d5
    goto L_0x00aa80d5;
L_0x00aa80d0:
    // 00aa80d0  b807110000             -mov eax, 0x1107
    cpu.eax = 4359 /*0x1107*/;
L_0x00aa80d5:
    // 00aa80d5  8d5d10                 -lea ebx, [ebp + 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00aa80d8  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00aa80db  e8a81b0000             -call 0xaa9c88
    cpu.esp -= 4;
    sub_aa9c88(app, cpu);
    if (cpu.terminate) return;
    // 00aa80e0  dd5de8                 -fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00aa80e3:
    // 00aa80e3  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00aa80e6  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00aa80e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa80ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa80eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa80ec  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa80ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa80ee  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 */
void sub_aa80f2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa80f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa80f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aa80f5  83ec10                 +sub esp, 0x10
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
    // 00aa80f8  eb31                   -jmp 0xaa812b
    return sub_aa812b(app, cpu);
}

/* align: skip  */
void sub_aa80fa(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa80fa  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
    // 00aa80fc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa80fd  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aa80ff  83ec10                 +sub esp, 0x10
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
    // 00aa8102  dc159436ab00           +fcom qword ptr [0xab3694]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(11220628) /* 0xab3694 */)));
    // 00aa8108  9b                     -wait 
    /*nothing*/;
    // 00aa8109  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00aa810c  9b                     -wait 
    /*nothing*/;
    // 00aa810d  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00aa8110  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa8111  7618                   -jbe 0xaa812b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa812b;
    }
    // 00aa8113  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa8115  740e                   -je 0xaa8125
    if (cpu.flags.zf)
    {
        goto L_0x00aa8125;
    }
    // 00aa8117  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa811a  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00aa811d  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00aa8120  e83e1c0000             -call 0xaa9d63
    cpu.esp -= 4;
    sub_aa9d63(app, cpu);
    if (cpu.terminate) return;
L_0x00aa8125:
    // 00aa8125  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00aa8127  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa8129  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa812a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa812b:
    // 00aa812b  dc159c36ab00           +fcom qword ptr [0xab369c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(11220636) /* 0xab369c */)));
    // 00aa8131  9b                     -wait 
    /*nothing*/;
    // 00aa8132  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00aa8135  9b                     -wait 
    /*nothing*/;
    // 00aa8136  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00aa8139  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa813a  7704                   -ja 0xaa8140
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa8140;
    }
    // 00aa813c  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00aa813e  eb14                   -jmp 0xaa8154
    goto L_0x00aa8154;
L_0x00aa8140:
    // 00aa8140  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00aa8142  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa8144  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa8146  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00aa8148  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa814a  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 00aa814c  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00aa814e  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00aa8150  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa8152  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x00aa8154:
    // 00aa8154  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8156  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00aa8158  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa815a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa815b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa80fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aa80fc;
    // 00aa80fa  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
L_entry_0x00aa80fc:
    // 00aa80fc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa80fd  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aa80ff  83ec10                 +sub esp, 0x10
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
    // 00aa8102  dc159436ab00           +fcom qword ptr [0xab3694]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(11220628) /* 0xab3694 */)));
    // 00aa8108  9b                     -wait 
    /*nothing*/;
    // 00aa8109  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00aa810c  9b                     -wait 
    /*nothing*/;
    // 00aa810d  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00aa8110  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa8111  7618                   -jbe 0xaa812b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa812b;
    }
    // 00aa8113  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa8115  740e                   -je 0xaa8125
    if (cpu.flags.zf)
    {
        goto L_0x00aa8125;
    }
    // 00aa8117  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa811a  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00aa811d  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00aa8120  e83e1c0000             -call 0xaa9d63
    cpu.esp -= 4;
    sub_aa9d63(app, cpu);
    if (cpu.terminate) return;
L_0x00aa8125:
    // 00aa8125  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00aa8127  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa8129  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa812a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa812b:
    // 00aa812b  dc159c36ab00           +fcom qword ptr [0xab369c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(11220636) /* 0xab369c */)));
    // 00aa8131  9b                     -wait 
    /*nothing*/;
    // 00aa8132  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00aa8135  9b                     -wait 
    /*nothing*/;
    // 00aa8136  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00aa8139  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa813a  7704                   -ja 0xaa8140
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa8140;
    }
    // 00aa813c  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00aa813e  eb14                   -jmp 0xaa8154
    goto L_0x00aa8154;
L_0x00aa8140:
    // 00aa8140  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00aa8142  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa8144  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa8146  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00aa8148  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa814a  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 00aa814c  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00aa814e  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00aa8150  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa8152  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x00aa8154:
    // 00aa8154  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8156  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00aa8158  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa815a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa815b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa812b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aa812b;
    // 00aa80fa  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
    // 00aa80fc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa80fd  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aa80ff  83ec10                 +sub esp, 0x10
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
    // 00aa8102  dc159436ab00           +fcom qword ptr [0xab3694]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(11220628) /* 0xab3694 */)));
    // 00aa8108  9b                     -wait 
    /*nothing*/;
    // 00aa8109  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00aa810c  9b                     -wait 
    /*nothing*/;
    // 00aa810d  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00aa8110  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa8111  7618                   -jbe 0xaa812b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa812b;
    }
    // 00aa8113  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa8115  740e                   -je 0xaa8125
    if (cpu.flags.zf)
    {
        goto L_0x00aa8125;
    }
    // 00aa8117  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa811a  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00aa811d  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00aa8120  e83e1c0000             -call 0xaa9d63
    cpu.esp -= 4;
    sub_aa9d63(app, cpu);
    if (cpu.terminate) return;
L_0x00aa8125:
    // 00aa8125  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00aa8127  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa8129  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa812a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa812b:
L_entry_0x00aa812b:
    // 00aa812b  dc159c36ab00           +fcom qword ptr [0xab369c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(11220636) /* 0xab369c */)));
    // 00aa8131  9b                     -wait 
    /*nothing*/;
    // 00aa8132  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 00aa8135  9b                     -wait 
    /*nothing*/;
    // 00aa8136  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00aa8139  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa813a  7704                   -ja 0xaa8140
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa8140;
    }
    // 00aa813c  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00aa813e  eb14                   -jmp 0xaa8154
    goto L_0x00aa8154;
L_0x00aa8140:
    // 00aa8140  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00aa8142  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa8144  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa8146  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00aa8148  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa814a  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 00aa814c  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00aa814e  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00aa8150  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa8152  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x00aa8154:
    // 00aa8154  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8156  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00aa8158  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00aa815a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa815b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa815c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa815c  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00aa8160  e895ffffff             -call 0xaa80fa
    cpu.esp -= 4;
    sub_aa80fa(app, cpu);
    if (cpu.terminate) return;
    // 00aa8165  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void sub_aa8168(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8168  db6c2410               -fld xword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00aa816c  db6c2404               -fld xword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(4) /* 0x4 */)));
L_0x00aa8170:
    // 00aa8170  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa8174  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa8176  0f8386000000           -jae 0xaa8202
    if (!cpu.flags.cf)
    {
        goto L_0x00aa8202;
    }
    // 00aa817c  350000000e             -xor eax, 0xe000000
    cpu.eax ^= x86::reg32(x86::sreg32(234881024 /*0xe000000*/));
    // 00aa8181  a90000000e             +test eax, 0xe000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 234881024 /*0xe000000*/));
    // 00aa8186  7403                   -je 0xaa818b
    if (cpu.flags.zf)
    {
        goto L_0x00aa818b;
    }
    // 00aa8188  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa818a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa818b:
    // 00aa818b  c1e81c                 -shr eax, 0x1c
    cpu.eax >>= 28 /*0x1c*/ % 32;
    // 00aa818e  80b8743dab0000         +cmp byte ptr [eax + 0xab3d74], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11222388) /* 0xab3d74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa8195  7503                   -jne 0xaa819a
    if (!cpu.flags.zf)
    {
        goto L_0x00aa819a;
    }
    // 00aa8197  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa8199  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa819a:
    // 00aa819a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aa819e  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 00aa81a3  7467                   -je 0xaa820c
    if (cpu.flags.zf)
    {
        goto L_0x00aa820c;
    }
    // 00aa81a5  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa81aa  7460                   -je 0xaa820c
    if (cpu.flags.zf)
    {
        goto L_0x00aa820c;
    }
    // 00aa81ac  d97c241c               -fnstcw word ptr [esp + 0x1c]
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.fpu.control.word;
    // 00aa81b0  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa81b4  0d3f030000             -or eax, 0x33f
    cpu.eax |= x86::reg32(x86::sreg32(831 /*0x33f*/));
    // 00aa81b9  25fff30000             -and eax, 0xf3ff
    cpu.eax &= x86::reg32(x86::sreg32(62463 /*0xf3ff*/));
    // 00aa81be  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00aa81c2  d96c2420               -fldcw word ptr [esp + 0x20]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00aa81c6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa81ca  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 00aa81cf  83f801                 +cmp eax, 1
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
    // 00aa81d2  7417                   -je 0xaa81eb
    if (cpu.flags.zf)
    {
        goto L_0x00aa81eb;
    }
    // 00aa81d4  d80d843dab00           -fmul dword ptr [0xab3d84]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11222404) /* 0xab3d84 */));
    // 00aa81da  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa81dc  d80d843dab00           -fmul dword ptr [0xab3d84]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11222404) /* 0xab3d84 */));
    // 00aa81e2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa81e4  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa81e8  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa81ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa81eb:
    // 00aa81eb  d80d883dab00           -fmul dword ptr [0xab3d88]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11222408) /* 0xab3d88 */));
    // 00aa81f1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa81f3  d80d883dab00           -fmul dword ptr [0xab3d88]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11222408) /* 0xab3d88 */));
    // 00aa81f9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa81fb  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa81ff  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa8201  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa8202:
    // 00aa8202  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa8206  0b442408               +or eax, dword ptr [esp + 8]
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)))));
    // 00aa820a  7503                   -jne 0xaa820f
    if (!cpu.flags.zf)
    {
        goto L_0x00aa820f;
    }
L_0x00aa820c:
    // 00aa820c  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa820e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa820f:
    // 00aa820f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aa8213  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 00aa8218  75f2                   -jne 0xaa820c
    if (!cpu.flags.zf)
    {
        goto L_0x00aa820c;
    }
    // 00aa821a  d97c241c               -fnstcw word ptr [esp + 0x1c]
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.fpu.control.word;
    // 00aa821e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa8222  0d3f030000             -or eax, 0x33f
    cpu.eax |= x86::reg32(x86::sreg32(831 /*0x33f*/));
    // 00aa8227  25fff30000             -and eax, 0xf3ff
    cpu.eax &= x86::reg32(x86::sreg32(62463 /*0xf3ff*/));
    // 00aa822c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00aa8230  d96c2420               -fldcw word ptr [esp + 0x20]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00aa8234  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aa8238  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 00aa823d  7411                   -je 0xaa8250
    if (cpu.flags.zf)
    {
        goto L_0x00aa8250;
    }
    // 00aa823f  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8244  7432                   -je 0xaa8278
    if (cpu.flags.zf)
    {
        goto L_0x00aa8278;
    }
    // 00aa8246  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00aa824a  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa824c  732a                   -jae 0xaa8278
    if (!cpu.flags.cf)
    {
        goto L_0x00aa8278;
    }
    // 00aa824e  eb08                   -jmp 0xaa8258
    goto L_0x00aa8258;
L_0x00aa8250:
    // 00aa8250  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00aa8254  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa8256  7220                   -jb 0xaa8278
    if (cpu.flags.cf)
    {
        goto L_0x00aa8278;
    }
L_0x00aa8258:
    // 00aa8258  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa825a  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa825c  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa825e  d80d8c3dab00           +fmul dword ptr [0xab3d8c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(11222412) /* 0xab3d8c */));
    // 00aa8264  db7c2404               +fstp xword ptr [esp + 4]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8268  db6c2410               +fld xword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00aa826c  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa826e  9b                     -wait 
    /*nothing*/;
    // 00aa826f  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa8273  e9f8feffff             -jmp 0xaa8170
    goto L_0x00aa8170;
L_0x00aa8278:
    // 00aa8278  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00aa827c  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa827e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa827f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00aa827f  83ec2c                 +sub esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa8282  ff2485903dab00         -jmp dword ptr [eax*4 + 0xab3d90]
    cpu.ip = app->getMemory<x86::reg32>(11222416 + cpu.eax * 4); goto dynamic_jump;
  case 0x00aa8289:
    // 00aa8289  d8f0                   -fdiv st(0)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(0));
    // 00aa828b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa828e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa828f:
    // 00aa828f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8292  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa8294:
    // 00aa8294  d8f8                   -fdivr st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0)) / cpu.fpu.st(0);
    // 00aa8296  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8299  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa829a:
    // 00aa829a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa829d  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa829f:
    // 00aa829f  d8f0                   -fdiv st(0)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(0));
    // 00aa82a1  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa82a4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa82a5:
    // 00aa82a5  def8                   -fdivp st(0)
    cpu.fpu.st(0) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aa82a7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa82aa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa82ab:
    // 00aa82ab  d8f8                   -fdivr st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0)) / cpu.fpu.st(0);
    // 00aa82ad  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa82b0  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa82b1:
    // 00aa82b1  def0                   -fdivrp st(0)
    cpu.fpu.st(0) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa82b3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa82b6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa82b7:
    // 00aa82b7  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa82bb  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa82bd  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa82c0  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa82c4  e89ffeffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa82c9  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa82cd  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa82cf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa82d2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa82d3:
    // 00aa82d3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa82d6  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa82d8:
    // 00aa82d8  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa82db  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa82df  e884feffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa82e4  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa82e8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa82ea  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa82ed  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa82ee:
    // 00aa82ee  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa82f1  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa82f3:
    // 00aa82f3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa82f5  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa82f9  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa82fb  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa82fe  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8302  e861feffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8307  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa830b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa830e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa830f:
    // 00aa830f  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8312  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8316  e84dfeffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa831b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa831e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa831f:
    // 00aa831f  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8323  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8326  e83dfeffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa832b  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa832f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8332  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8333:
    // 00aa8333  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8337  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa833a  e829feffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa833f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8342  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8343:
    // 00aa8343  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8347  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa8349  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa834b  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa834e  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8352  e811feffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8357  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa8359  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa835d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa835f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8362  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8363:
    // 00aa8363  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8366  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa8368:
    // 00aa8368  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa836b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa836d  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8371  e8f2fdffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8376  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa8378  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa837c  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa837e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8381  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8382:
    // 00aa8382  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8385  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa8387:
    // 00aa8387  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa8389  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa838d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa838f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa8391  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8394  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8398  e8cbfdffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa839d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa839f  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa83a3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa83a6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa83a7:
    // 00aa83a7  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa83aa  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa83ac  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa83b0  e8b3fdffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa83b5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa83b7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa83ba  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa83bb:
    // 00aa83bb  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa83bf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa83c1  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa83c4  e89ffdffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa83c9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa83cb  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa83cf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa83d2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa83d3:
    // 00aa83d3  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa83d7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa83d9  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa83dc  e887fdffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa83e1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa83e3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa83e6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa83e7:
    // 00aa83e7  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa83eb  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa83ed  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa83ef  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa83f2  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa83f6  e86dfdffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa83fb  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa83fd  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa8401  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa8403  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8406  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8407:
    // 00aa8407  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa840a  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa840c:
    // 00aa840c  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa840f  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa8411  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8415  e84efdffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa841a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa841c  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa8420  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa8422  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8425  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8426:
    // 00aa8426  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8429  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa842b:
    // 00aa842b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa842d  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8431  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa8433  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa8435  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8438  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa843c  e827fdffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8441  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa8443  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa8447  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa844a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa844b:
    // 00aa844b  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa844e  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa8450  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8454  e80ffdffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8459  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa845b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa845e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa845f:
    // 00aa845f  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8463  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa8465  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8468  e8fbfcffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa846d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa846f  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa8473  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8476  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8477:
    // 00aa8477  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa847b  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa847d  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8480  e8e3fcffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8485  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00aa8487  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa848a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa848b:
    // 00aa848b  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa848f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa8491  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa8493  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8496  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa849a  e8c9fcffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa849f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa84a1  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa84a5  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa84a7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa84aa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa84ab:
    // 00aa84ab  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa84ae  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa84b0:
    // 00aa84b0  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa84b3  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa84b5  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa84b9  e8aafcffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa84be  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa84c0  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa84c4  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa84c6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa84c9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa84ca:
    // 00aa84ca  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa84cd  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa84cf:
    // 00aa84cf  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa84d1  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa84d5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa84d7  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa84d9  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa84dc  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa84e0  e883fcffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa84e5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa84e7  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa84eb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa84ee  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa84ef:
    // 00aa84ef  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa84f2  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa84f4  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa84f8  e86bfcffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa84fd  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa84ff  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8502  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8503:
    // 00aa8503  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8507  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa8509  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa850c  e857fcffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8511  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa8513  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa8517  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa851a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa851b:
    // 00aa851b  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa851f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa8521  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8524  e83ffcffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8529  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00aa852b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa852e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa852f:
    // 00aa852f  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8533  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa8535  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa8537  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa853a  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa853e  e825fcffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8543  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa8545  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa8549  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa854b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa854e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa854f:
    // 00aa854f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8552  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa8554:
    // 00aa8554  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8557  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa8559  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa855d  e806fcffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8562  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa8564  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa8568  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa856a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa856d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa856e:
    // 00aa856e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8571  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa8573:
    // 00aa8573  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa8575  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8579  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa857b  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa857d  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8580  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8584  e8dffbffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8589  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa858b  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa858f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8592  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8593:
    // 00aa8593  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8596  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa8598  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa859c  e8c7fbffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa85a1  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa85a3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa85a6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa85a7:
    // 00aa85a7  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa85ab  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa85ad  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa85b0  e8b3fbffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa85b5  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa85b7  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa85bb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa85be  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa85bf:
    // 00aa85bf  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa85c3  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa85c5  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa85c8  e89bfbffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa85cd  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00aa85cf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa85d2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa85d3:
    // 00aa85d3  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa85d7  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa85d9  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa85db  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa85de  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa85e2  e881fbffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa85e7  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa85e9  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa85ed  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa85ef  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa85f2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa85f3:
    // 00aa85f3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa85f6  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa85f8:
    // 00aa85f8  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa85fb  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa85fd  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8601  e862fbffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8606  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa8608  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa860c  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa860e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8611  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8612:
    // 00aa8612  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8615  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa8617:
    // 00aa8617  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa8619  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa861d  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa861f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa8621  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8624  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8628  e83bfbffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa862d  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa862f  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa8633  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8636  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8637:
    // 00aa8637  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa863a  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa863c  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8640  e823fbffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8645  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa8647  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa864a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa864b:
    // 00aa864b  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa864f  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa8651  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8654  e80ffbffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8659  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa865b  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa865f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8662  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8663:
    // 00aa8663  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8667  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa8669  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa866c  e8f7faffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8671  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00aa8673  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8676  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8677:
    // 00aa8677  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa867b  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa867d  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa867f  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8682  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8686  e8ddfaffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa868b  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa868d  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa8691  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 00aa8693  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8696  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8697:
    // 00aa8697  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa869a  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa869c:
    // 00aa869c  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa869f  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa86a1  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa86a5  e8befaffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa86aa  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa86ac  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa86b0  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 00aa86b2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa86b5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa86b6:
    // 00aa86b6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa86b9  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00aa86bb:
    // 00aa86bb  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 00aa86bd  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa86c1  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa86c3  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aa86c5  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa86c8  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa86cc  e897faffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa86d1  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa86d3  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00aa86d7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa86da  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa86db:
    // 00aa86db  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa86de  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa86e0  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa86e4  e87ffaffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa86e9  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa86eb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa86ee  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa86ef:
    // 00aa86ef  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa86f3  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa86f5  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa86f8  e86bfaffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa86fd  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa86ff  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aa8703  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8706  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00aa8707:
    // 00aa8707  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa870b  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa870d  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8710  e853faffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8715  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00aa8717  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa871a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_aa871b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa871b  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa871e  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8721  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8725  e83efaffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa872a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa872d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa872e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa872e  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8731  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8735  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8738  e82bfaffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa873d  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8740  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa8741(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8741  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8744  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8748  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa874b  e818faffff             -call 0xaa8168
    cpu.esp -= 4;
    sub_aa8168(app, cpu);
    if (cpu.terminate) return;
    // 00aa8750  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa8753  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa8754(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8754  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa8755  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa8759  250000807f             -and eax, 0x7f800000
    cpu.eax &= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 00aa875e  3d0000807f             +cmp eax, 0x7f800000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8763  7433                   -je 0xaa8798
    if (cpu.flags.zf)
    {
        goto L_0x00aa8798;
    }
    // 00aa8765  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aa8767  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00aa876c  740d                   -je 0xaa877b
    if (cpu.flags.zf)
    {
        goto L_0x00aa877b;
    }
    // 00aa876e  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00aa8772  e8a4ffffff             -call 0xaa871b
    cpu.esp -= 4;
    sub_aa871b(app, cpu);
    if (cpu.terminate) return;
    // 00aa8777  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8778  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aa877b:
    // 00aa877b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa877d  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa8780  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8783  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00aa8787  e88fffffff             -call 0xaa871b
    cpu.esp -= 4;
    sub_aa871b(app, cpu);
    if (cpu.terminate) return;
    // 00aa878c  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00aa878f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa8791  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa8794  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8795  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aa8798:
    // 00aa8798  d8742408               -fdiv dword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00aa879c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa879d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_aa87a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa87a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa87a1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aa87a5  250000f07f             -and eax, 0x7ff00000
    cpu.eax &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00aa87aa  3d0000f07f             +cmp eax, 0x7ff00000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa87af  7433                   -je 0xaa87e4
    if (cpu.flags.zf)
    {
        goto L_0x00aa87e4;
    }
    // 00aa87b1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aa87b3  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00aa87b8  740d                   -je 0xaa87c7
    if (cpu.flags.zf)
    {
        goto L_0x00aa87c7;
    }
    // 00aa87ba  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00aa87be  e858ffffff             -call 0xaa871b
    cpu.esp -= 4;
    sub_aa871b(app, cpu);
    if (cpu.terminate) return;
    // 00aa87c3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa87c4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa87c7:
    // 00aa87c7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa87c9  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa87cc  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa87cf  dd442414               -fld qword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00aa87d3  e843ffffff             -call 0xaa871b
    cpu.esp -= 4;
    sub_aa871b(app, cpu);
    if (cpu.terminate) return;
    // 00aa87d8  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00aa87db  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa87dd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa87e0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa87e1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa87e4:
    // 00aa87e4  dc742408               -fdiv qword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00aa87e8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa87e9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void sub_aa87ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa87ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa87ed  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa87f1  250000807f             -and eax, 0x7f800000
    cpu.eax &= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 00aa87f6  3d0000807f             +cmp eax, 0x7f800000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa87fb  7433                   -je 0xaa8830
    if (cpu.flags.zf)
    {
        goto L_0x00aa8830;
    }
    // 00aa87fd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aa87ff  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00aa8804  740d                   -je 0xaa8813
    if (cpu.flags.zf)
    {
        goto L_0x00aa8813;
    }
    // 00aa8806  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00aa880a  e81fffffff             -call 0xaa872e
    cpu.esp -= 4;
    sub_aa872e(app, cpu);
    if (cpu.terminate) return;
    // 00aa880f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8810  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aa8813:
    // 00aa8813  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa8815  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa8818  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa881b  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00aa881f  e80affffff             -call 0xaa872e
    cpu.esp -= 4;
    sub_aa872e(app, cpu);
    if (cpu.terminate) return;
    // 00aa8824  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00aa8827  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa8829  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa882c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa882d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aa8830:
    // 00aa8830  d87c2408               -fdivr dword ptr [esp + 8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)) / cpu.fpu.st(0);
    // 00aa8834  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8835  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_aa8838(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8838  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa8839  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aa883d  250000f07f             -and eax, 0x7ff00000
    cpu.eax &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00aa8842  3d0000f07f             +cmp eax, 0x7ff00000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8847  7433                   -je 0xaa887c
    if (cpu.flags.zf)
    {
        goto L_0x00aa887c;
    }
    // 00aa8849  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aa884b  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00aa8850  740d                   -je 0xaa885f
    if (cpu.flags.zf)
    {
        goto L_0x00aa885f;
    }
    // 00aa8852  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00aa8856  e8d3feffff             -call 0xaa872e
    cpu.esp -= 4;
    sub_aa872e(app, cpu);
    if (cpu.terminate) return;
    // 00aa885b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa885c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa885f:
    // 00aa885f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa8861  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa8864  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa8867  dd442414               -fld qword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00aa886b  e8befeffff             -call 0xaa872e
    cpu.esp -= 4;
    sub_aa872e(app, cpu);
    if (cpu.terminate) return;
    // 00aa8870  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00aa8873  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00aa8875  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aa8878  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8879  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00aa887c:
    // 00aa887c  dc7c2408               -fdivr qword ptr [esp + 8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)) / cpu.fpu.st(0);
    // 00aa8880  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8881  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa8890(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8891  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa8893  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa8895  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aa8897  e844150000             -call 0xaa9de0
    cpu.esp -= 4;
    sub_aa9de0(app, cpu);
    if (cpu.terminate) return;
    // 00aa889c  ff4310                 -inc dword ptr [ebx + 0x10]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */))++;
    // 00aa889f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa88a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa88a4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa88a4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa88a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa88a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa88a7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa88a8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aa88aa  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00aa88ad  ff15ac36ab00           -call dword ptr [0xab36ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220652) /* 0xab36ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa88b3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00aa88b6  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00aa88b9  83f901                 +cmp ecx, 1
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
    // 00aa88bc  741b                   -je 0xaa88d9
    if (cpu.flags.zf)
    {
        goto L_0x00aa88d9;
    }
    // 00aa88be  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa88c0  7410                   -je 0xaa88d2
    if (cpu.flags.zf)
    {
        goto L_0x00aa88d2;
    }
    // 00aa88c2  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00aa88c5  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa88cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa88cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa88ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa88cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa88d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa88d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa88d2:
    // 00aa88d2  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00aa88d9:
    // 00aa88d9  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00aa88dc  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 00aa88df  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00aa88e2  88660c                 -mov byte ptr [esi + 0xc], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ah;
    // 00aa88e5  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00aa88e8  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa88eb  83e530                 -and ebp, 0x30
    cpu.ebp &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00aa88ee  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa88f0  7507                   -jne 0xaa88f9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa88f9;
    }
    // 00aa88f2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa88f4  e807160000             -call 0xaa9f00
    cpu.esp -= 4;
    sub_aa9f00(app, cpu);
    if (cpu.terminate) return;
L_0x00aa88f9:
    // 00aa88f9  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00aa88fc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00aa88fe  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00aa8901  7414                   -je 0xaa8917
    if (cpu.flags.zf)
    {
        goto L_0x00aa8917;
    }
    // 00aa8903  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00aa8905  80e5fa                 -and ch, 0xfa
    cpu.ch &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 00aa8908  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 00aa890a  886e0d                 -mov byte ptr [esi + 0xd], ch
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 00aa890d  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aa890f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00aa8914  88460d                 -mov byte ptr [esi + 0xd], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x00aa8917:
    // 00aa8917  b99088aa00             -mov ecx, 0xaa8890
    cpu.ecx = 11176080 /*0xaa8890*/;
    // 00aa891c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa891e  e86d160000             -call 0xaa9f90
    cpu.esp -= 4;
    sub_aa9f90(app, cpu);
    if (cpu.terminate) return;
    // 00aa8923  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa8925  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aa8927  7418                   -je 0xaa8941
    if (cpu.flags.zf)
    {
        goto L_0x00aa8941;
    }
    // 00aa8929  8a660d                 -mov ah, byte ptr [esi + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00aa892c  80e4fa                 -and ah, 0xfa
    cpu.ah &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 00aa892f  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 00aa8931  88660d                 -mov byte ptr [esi + 0xd], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00aa8934  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00aa8937  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa8939  885e0d                 -mov byte ptr [esi + 0xd], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 00aa893c  e83f010000             -call 0xaa8a80
    cpu.esp -= 4;
    sub_aa8a80(app, cpu);
    if (cpu.terminate) return;
L_0x00aa8941:
    // 00aa8941  f6460c20               +test byte ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 00aa8945  7405                   -je 0xaa894c
    if (cpu.flags.zf)
    {
        goto L_0x00aa894c;
    }
    // 00aa8947  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00aa894c:
    // 00aa894c  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00aa894f  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa8951  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00aa8954  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00aa8957  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa895d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa895f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8960  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8961  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8962  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8963  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa8970(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa8973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa8974  8a25a133ab00           -mov ah, byte ptr [0xab33a1]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(11219873) /* 0xab33a1 */);
    // 00aa897a  80e4f8                 -and ah, 0xf8
    cpu.ah &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00aa897d  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00aa897f  8825a133ab00           -mov byte ptr [0xab33a1], ah
    app->getMemory<x86::reg8>(x86::reg32(11219873) /* 0xab33a1 */) = cpu.ah;
    // 00aa8985  80ca04                 -or dl, 4
    cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00aa8988  8815a133ab00           -mov byte ptr [0xab33a1], dl
    app->getMemory<x86::reg8>(x86::reg32(11219873) /* 0xab33a1 */) = cpu.dl;
    // 00aa898e  8b156c33ab00           -mov edx, dword ptr [0xab336c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11219820) /* 0xab336c */);
    // 00aa8994  bb6033ab00             -mov ebx, 0xab3360
    cpu.ebx = 11219808 /*0xab3360*/;
    // 00aa8999  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa899b  7466                   -je 0xaa8a03
    if (cpu.flags.zf)
    {
        goto L_0x00aa8a03;
    }
L_0x00aa899d:
    // 00aa899d  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00aa89a2  e809f3ffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aa89a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa89a9  7521                   -jne 0xaa89cc
    if (!cpu.flags.zf)
    {
        goto L_0x00aa89cc;
    }
    // 00aa89ab  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00aa89b0  e8fbf2ffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aa89b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aa89b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa89b9  7513                   -jne 0xaa89ce
    if (!cpu.flags.zf)
    {
        goto L_0x00aa89ce;
    }
    // 00aa89bb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00aa89c0  b8f826ab00             -mov eax, 0xab26f8
    cpu.eax = 11216632 /*0xab26f8*/;
    // 00aa89c5  e832240000             -call 0xaaadfc
    cpu.esp -= 4;
    sub_aaadfc(app, cpu);
    if (cpu.terminate) return;
    // 00aa89ca  eb02                   -jmp 0xaa89ce
    goto L_0x00aa89ce;
L_0x00aa89cc:
    // 00aa89cc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00aa89ce:
    // 00aa89ce  a1b047ab00             -mov eax, dword ptr [0xab47b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11225008) /* 0xab47b0 */);
    // 00aa89d3  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00aa89d6  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00aa89d8  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00aa89db  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00aa89e2  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00aa89e5  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00aa89e9  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00aa89ec  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00aa89f3  890db047ab00           -mov dword ptr [0xab47b0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11225008) /* 0xab47b0 */) = cpu.ecx;
    // 00aa89f9  8b4b26                 -mov ecx, dword ptr [ebx + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(38) /* 0x26 */);
    // 00aa89fc  83c31a                 -add ebx, 0x1a
    (cpu.ebx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 00aa89ff  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa8a01  759a                   -jne 0xaa899d
    if (!cpu.flags.zf)
    {
        goto L_0x00aa899d;
    }
L_0x00aa8a03:
    // 00aa8a03  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aa8a05  8935b447ab00           -mov dword ptr [0xab47b4], esi
    app->getMemory<x86::reg32>(x86::reg32(11225012) /* 0xab47b4 */) = cpu.esi;
    // 00aa8a0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a0c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa8a10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8a10  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa8a12  e80d000000             -call 0xaa8a24
    cpu.esp -= 4;
    sub_aa8a24(app, cpu);
    if (cpu.terminate) return;
    // 00aa8a17  e904250000             -jmp 0xaaaf20
    return sub_aaaf20(app, cpu);
}

/* align: skip  */
void sub_aa8a1c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8a1c  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00aa8a21  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00aa8a24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8a25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8a26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa8a27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa8a28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa8a2a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00aa8a2d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa8a2f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00aa8a32  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00aa8a34  be6033ab00             -mov esi, 0xab3360
    cpu.esi = 11219808 /*0xab3360*/;
    // 00aa8a39  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8a3b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8a3d  a1b047ab00             -mov eax, dword ptr [0xab47b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11225008) /* 0xab47b0 */);
    // 00aa8a42  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa8a44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa8a46  742f                   -je 0xaa8a77
    if (cpu.flags.zf)
    {
        goto L_0x00aa8a77;
    }
L_0x00aa8a48:
    // 00aa8a48  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa8a4a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa8a4d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00aa8a52  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 00aa8a56  7513                   -jne 0xaa8a6b
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8a6b;
    }
    // 00aa8a58  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00aa8a5c  750d                   -jne 0xaa8a6b
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8a6b;
    }
    // 00aa8a5e  39f0                   +cmp eax, esi
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
    // 00aa8a60  720f                   -jb 0xaa8a71
    if (cpu.flags.cf)
    {
        goto L_0x00aa8a71;
    }
    // 00aa8a62  3dae33ab00             +cmp eax, 0xab33ae
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11219886 /*0xab33ae*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8a67  7302                   -jae 0xaa8a6b
    if (!cpu.flags.cf)
    {
        goto L_0x00aa8a6b;
    }
    // 00aa8a69  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00aa8a6b:
    // 00aa8a6b  e824250000             -call 0xaaaf94
    cpu.esp -= 4;
    sub_aaaf94(app, cpu);
    if (cpu.terminate) return;
    // 00aa8a70  43                     -inc ebx
    (cpu.ebx)++;
L_0x00aa8a71:
    // 00aa8a71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa8a73  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa8a75  75d1                   -jne 0xaa8a48
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8a48;
    }
L_0x00aa8a77:
    // 00aa8a77  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa8a79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa8a24(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aa8a24;
    // 00aa8a1c  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00aa8a21  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00aa8a24:
    // 00aa8a24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8a25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8a26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa8a27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa8a28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa8a2a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00aa8a2d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa8a2f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00aa8a32  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00aa8a34  be6033ab00             -mov esi, 0xab3360
    cpu.esi = 11219808 /*0xab3360*/;
    // 00aa8a39  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8a3b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8a3d  a1b047ab00             -mov eax, dword ptr [0xab47b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11225008) /* 0xab47b0 */);
    // 00aa8a42  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa8a44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa8a46  742f                   -je 0xaa8a77
    if (cpu.flags.zf)
    {
        goto L_0x00aa8a77;
    }
L_0x00aa8a48:
    // 00aa8a48  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa8a4a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa8a4d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00aa8a52  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 00aa8a56  7513                   -jne 0xaa8a6b
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8a6b;
    }
    // 00aa8a58  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00aa8a5c  750d                   -jne 0xaa8a6b
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8a6b;
    }
    // 00aa8a5e  39f0                   +cmp eax, esi
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
    // 00aa8a60  720f                   -jb 0xaa8a71
    if (cpu.flags.cf)
    {
        goto L_0x00aa8a71;
    }
    // 00aa8a62  3dae33ab00             +cmp eax, 0xab33ae
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11219886 /*0xab33ae*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8a67  7302                   -jae 0xaa8a6b
    if (!cpu.flags.cf)
    {
        goto L_0x00aa8a6b;
    }
    // 00aa8a69  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00aa8a6b:
    // 00aa8a6b  e824250000             -call 0xaaaf94
    cpu.esp -= 4;
    sub_aaaf94(app, cpu);
    if (cpu.terminate) return;
    // 00aa8a70  43                     -inc ebx
    (cpu.ebx)++;
L_0x00aa8a71:
    // 00aa8a71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa8a73  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa8a75  75d1                   -jne 0xaa8a48
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8a48;
    }
L_0x00aa8a77:
    // 00aa8a77  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa8a79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8a7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_aa8a80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8a80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8a81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8a82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa8a83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa8a84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa8a85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa8a86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aa8a88  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00aa8a8b  ff15ac36ab00           -call dword ptr [0xab36ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220652) /* 0xab36ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8a91  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00aa8a94  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa8a96  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00aa8a99  0f847a000000           -je 0xaa8b19
    if (cpu.flags.zf)
    {
        goto L_0x00aa8b19;
    }
    // 00aa8a9f  88e7                   -mov bh, ah
    cpu.bh = cpu.ah;
    // 00aa8aa1  80e7ef                 -and bh, 0xef
    cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00aa8aa4  8a410c                 -mov al, byte ptr [ecx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00aa8aa7  88790d                 -mov byte ptr [ecx + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 00aa8aaa  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00aa8aac  0f84a2000000           -je 0xaa8b54
    if (cpu.flags.zf)
    {
        goto L_0x00aa8b54;
    }
    // 00aa8ab2  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aa8ab5  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00aa8ab8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa8aba  0f8494000000           -je 0xaa8b54
    if (cpu.flags.zf)
    {
        goto L_0x00aa8b54;
    }
    // 00aa8ac0  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00aa8ac3  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00aa8ac5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa8ac7  0f8487000000           -je 0xaa8b54
    if (cpu.flags.zf)
    {
        goto L_0x00aa8b54;
    }
L_0x00aa8acd:
    // 00aa8acd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aa8acf  0f857f000000           -jne 0xaa8b54
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8b54;
    }
    // 00aa8ad5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00aa8ad7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00aa8ad9  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00aa8adc  e84f260000             -call 0xaab130
    cpu.esp -= 4;
    sub_aab130(app, cpu);
    if (cpu.terminate) return;
    // 00aa8ae1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa8ae3  83f8ff                 +cmp eax, -1
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
    // 00aa8ae6  750d                   -jne 0xaa8af5
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8af5;
    }
    // 00aa8ae8  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00aa8aeb  80cb20                 +or bl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00aa8aee  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aa8af0  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 00aa8af3  eb1c                   -jmp 0xaa8b11
    goto L_0x00aa8b11;
L_0x00aa8af5:
    // 00aa8af5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa8af7  7518                   -jne 0xaa8b11
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8b11;
    }
    // 00aa8af9  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00aa8afe  e81d270000             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aa8b03  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00aa8b06  80cc20                 -or ah, 0x20
    cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00aa8b09  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 00aa8b0e  88610c                 -mov byte ptr [ecx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x00aa8b11:
    // 00aa8b11  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00aa8b13  29d6                   +sub esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa8b15  75b6                   -jne 0xaa8acd
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8acd;
    }
    // 00aa8b17  eb3b                   -jmp 0xaa8b54
    goto L_0x00aa8b54;
L_0x00aa8b19:
    // 00aa8b19  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aa8b1c  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00aa8b20  7432                   -je 0xaa8b54
    if (cpu.flags.zf)
    {
        goto L_0x00aa8b54;
    }
    // 00aa8b22  80610cef               -and byte ptr [ecx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00aa8b26  f6410d20               +test byte ptr [ecx + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 00aa8b2a  7528                   -jne 0xaa8b54
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8b54;
    }
    // 00aa8b2c  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00aa8b2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa8b31  7411                   -je 0xaa8b44
    if (cpu.flags.zf)
    {
        goto L_0x00aa8b44;
    }
    // 00aa8b33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa8b35  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa8b3a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00aa8b3c  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00aa8b3f  e83c270000             -call 0xaab280
    cpu.esp -= 4;
    sub_aab280(app, cpu);
    if (cpu.terminate) return;
L_0x00aa8b44:
    // 00aa8b44  83f8ff                 +cmp eax, -1
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
    // 00aa8b47  750b                   -jne 0xaa8b54
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8b54;
    }
    // 00aa8b49  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00aa8b4c  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00aa8b4f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aa8b51  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
L_0x00aa8b54:
    // 00aa8b54  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aa8b57  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa8b5a  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00aa8b61  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00aa8b63  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aa8b65  7518                   -jne 0xaa8b7f
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8b7f;
    }
    // 00aa8b67  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aa8b6a  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 00aa8b6e  740f                   -je 0xaa8b7f
    if (cpu.flags.zf)
    {
        goto L_0x00aa8b7f;
    }
    // 00aa8b70  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00aa8b73  e888270000             -call 0xaab300
    cpu.esp -= 4;
    sub_aab300(app, cpu);
    if (cpu.terminate) return;
    // 00aa8b78  83f8ff                 +cmp eax, -1
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
    // 00aa8b7b  7502                   -jne 0xaa8b7f
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8b7f;
    }
    // 00aa8b7d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00aa8b7f:
    // 00aa8b7f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00aa8b82  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8b88  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aa8b8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8b8b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8b8c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8b8d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8b8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8b8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8b90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa8ba0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8ba0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aa8ba5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00aa8ba8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8ba9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8baa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa8bab  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aa8bad  ff15bc36ab00           -call dword ptr [0xab36bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220668) /* 0xab36bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8bb3  8b15b047ab00           -mov edx, dword ptr [0xab47b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11225008) /* 0xab47b0 */);
    // 00aa8bb9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa8bbb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa8bbd  741a                   -je 0xaa8bd9
    if (cpu.flags.zf)
    {
        goto L_0x00aa8bd9;
    }
L_0x00aa8bbf:
    // 00aa8bbf  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00aa8bc2  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 00aa8bc5  740c                   -je 0xaa8bd3
    if (cpu.flags.zf)
    {
        goto L_0x00aa8bd3;
    }
    // 00aa8bc7  43                     -inc ebx
    (cpu.ebx)++;
    // 00aa8bc8  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00aa8bcc  7405                   -je 0xaa8bd3
    if (cpu.flags.zf)
    {
        goto L_0x00aa8bd3;
    }
    // 00aa8bce  e8adfeffff             -call 0xaa8a80
    cpu.esp -= 4;
    sub_aa8a80(app, cpu);
    if (cpu.terminate) return;
L_0x00aa8bd3:
    // 00aa8bd3  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aa8bd5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa8bd7  75e6                   -jne 0xaa8bbf
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8bbf;
    }
L_0x00aa8bd9:
    // 00aa8bd9  ff15c036ab00           -call dword ptr [0xab36c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220672) /* 0xab36c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8bdf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa8be1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8be2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8be3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8be4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa8bf0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8bf0  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8bf6  05da000000             -add eax, 0xda
    (cpu.eax) += x86::reg32(x86::sreg32(218 /*0xda*/));
    // 00aa8bfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa8bfc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8bfc  a17c48ab00             -mov eax, dword ptr [0xab487c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11225212) /* 0xab487c */);
    // 00aa8c01  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00aa8c04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa8c04(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aa8c04;
    // 00aa8bfc  a17c48ab00             -mov eax, dword ptr [0xab487c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11225212) /* 0xab487c */);
    // 00aa8c01  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00aa8c04:
    // 00aa8c04  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
