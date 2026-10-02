#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x90 */
void Application::sub_533e94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533e94  90                     -nop 
    ;
    // 00533e95  90                     -nop 
    ;
    // 00533e96  90                     -nop 
    ;
    // 00533e97  90                     -nop 
    ;
    // 00533e98  90                     -nop 
    ;
    // 00533e99  90                     -nop 
    ;
    // 00533e9a  90                     -nop 
    ;
    // 00533e9b  90                     -nop 
    ;
    // 00533e9c  90                     -nop 
    ;
    // 00533e9d  90                     -nop 
    ;
    // 00533e9e  ff25d8465300           -jmp dword ptr [0x5346d8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457624), cpu);
}

/* align: skip  */
void Application::sub_533e9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00533e9e;
    // 00533e94  90                     -nop 
    ;
    // 00533e95  90                     -nop 
    ;
    // 00533e96  90                     -nop 
    ;
    // 00533e97  90                     -nop 
    ;
    // 00533e98  90                     -nop 
    ;
    // 00533e99  90                     -nop 
    ;
    // 00533e9a  90                     -nop 
    ;
    // 00533e9b  90                     -nop 
    ;
    // 00533e9c  90                     -nop 
    ;
    // 00533e9d  90                     -nop 
    ;
L_entry_0x00533e9e:
    // 00533e9e  ff25d8465300           -jmp dword ptr [0x5346d8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457624), cpu);
}

/* align: skip  */
void Application::sub_533ea4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ea4  ff25dc465300           -jmp dword ptr [0x5346dc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457628), cpu);
}

/* align: skip  */
void Application::sub_533eaa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533eaa  ff25e0465300           -jmp dword ptr [0x5346e0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457632), cpu);
}

/* align: skip  */
void Application::sub_533eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533eb0  ff25e4465300           -jmp dword ptr [0x5346e4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457636), cpu);
}

/* align: skip  */
void Application::sub_533eb6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533eb6  ff251c475300           -jmp dword ptr [0x53471c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457692), cpu);
}

/* align: skip  */
void Application::sub_533ebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ebc  ff2508475300           -jmp dword ptr [0x534708]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457672), cpu);
}

/* align: skip  */
void Application::sub_533ec2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ec2  ff2514475300           -jmp dword ptr [0x534714]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457684), cpu);
}

/* align: skip  */
void Application::sub_533ec8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ec8  ff250c475300           -jmp dword ptr [0x53470c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457676), cpu);
}

/* align: skip  */
void Application::sub_533ece(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ece  ff2510475300           -jmp dword ptr [0x534710]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457680), cpu);
}

/* align: skip  */
void Application::sub_533ed4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ed4  ff2520475300           -jmp dword ptr [0x534720]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457696), cpu);
}

/* align: skip  */
void Application::sub_533eda(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533eda  ff2518475300           -jmp dword ptr [0x534718]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457688), cpu);
}

/* align: skip  */
void Application::sub_533ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533ee0  ff25b8475300           -jmp dword ptr [0x5347b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5457848), cpu);
}

}
