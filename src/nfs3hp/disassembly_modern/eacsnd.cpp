#include "eacsnd.h"
#include <x86.h>
#include <winapi/wrapper.h>

namespace eacsnd
{

win32::Library s_library = win32::Library("eacsnd.dll");
win32::Library* s_registry = &(s_library
        .registerSymbol("_iSNDdirectcaps@4", &sub_a53c28)
        .registerSymbol("_iSNDdirectcreate3dbuf@28", &sub_a54f4c)
        .registerSymbol("_iSNDdirectplay3d@28", &sub_a55014)
        .registerSymbol("_iSNDdirectpos3d@12", &sub_a54e68)
        .registerSymbol("_iSNDdirectrate@8", &sub_a54f0c)
        .registerSymbol("_iSNDdirectrecordpacket@4", &sub_a54904)
        .registerSymbol("_iSNDdirectrecordstart@16", &sub_a548fc)
        .registerSymbol("_iSNDdirectrecordstop@0", &sub_a5490c)
        .registerSymbol("_iSNDdirectremovebuf@4", &sub_a54fc0)
        .registerSymbol("_iSNDdirectserve@0", &sub_a54b24)
        .registerSymbol("_iSNDdirectsetfunctions@32", &sub_a53bd8)
        .registerSymbol("_iSNDdirectstart@8", &sub_a5482c)
        .registerSymbol("_iSNDdirectstop@0", &sub_a5487c)
        .registerSymbol("_iSNDdirectstopbuf@4", &sub_a551b0)
        .registerSymbol("_iSNDdirectvol@8", &sub_a54e18)
        .registerSymbol("_iSNDdllversion@0", &sub_a53bc4)

    );
}
