// kernel32 functions imported only by the NFS3 Modern Patch executable:
// process heap, private profile (.ini) files and PE resources.
#include <winapi/kernel32.h>
#include <lib/file.h>
#include <lib/memmap.h>
#include <SDL_log.h>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <map>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

namespace win32 { namespace kernel32
{

// ---- process heap --------------------------------------------------------
//
// The patch replaces the game's allocator with HeapAlloc, so this sees many
// small allocations. Guest MemMap blocks are 4 KB, so small requests are served
// from 1 MB chunks with power-of-two size classes; large ones get their own block.
// Every allocation is preceded by a 16-byte header: capacity, requested size.

static const HANDLE s_processHeap = 0x00c0ffee;
static const x86::reg32 HEADER = 16;
static const x86::reg32 HEAP_ZERO_MEMORY = 0x08;
static const x86::reg32 MIN_CLASS = 4;      // 16 bytes
static const x86::reg32 MAX_CLASS = 18;     // 256 KB
static const x86::reg32 CHUNK = 1024 * 1024;

static std::mutex s_heapLock;
static std::vector<x86::reg32> s_freeLists[MAX_CLASS + 1];
static x86::reg32 s_chunkNext = 0, s_chunkEnd = 0;

static x86::reg32 sizeClass(x86::reg32 bytes)
{
    x86::reg32 c = MIN_CLASS;
    while ((x86::reg32(1) << c) < bytes) ++c;
    return c;
}

static x86::reg32 heapAllocate(WinApplication* app, x86::reg32 bytes, bool zero)
{
    std::lock_guard<std::mutex> lock(s_heapLock);
    const x86::reg32 request = std::max<x86::reg32>(bytes, 1);
    x86::reg32 block = 0, capacity = 0;
    if (request > (x86::reg32(1) << MAX_CLASS))
    {
        capacity = (request + 15) & ~15u;
        MemMap* map = new MemMap(capacity + HEADER);
        block = map->getBlockStart();
    }
    else
    {
        const x86::reg32 c = sizeClass(request);
        capacity = x86::reg32(1) << c;
        if (!s_freeLists[c].empty())
        {
            block = s_freeLists[c].back();
            s_freeLists[c].pop_back();
        }
        else
        {
            if (s_chunkNext + capacity + HEADER > s_chunkEnd)
            {
                MemMap* map = new MemMap(CHUNK);
                s_chunkNext = map->getBlockStart();
                s_chunkEnd = s_chunkNext + CHUNK;
            }
            block = s_chunkNext;
            s_chunkNext += capacity + HEADER;
        }
    }
    app->getMemory<x86::reg32>(block) = capacity;
    app->getMemory<x86::reg32>(block + 4) = request;
    // Always hand out zeroed memory: before the patch every guest allocation
    // came from fresh, zeroed blocks, and the game relies on that in places.
    NFS2_USE(zero);
    memset(&app->getMemory<x86::reg8>(block + HEADER), 0, capacity);
    return block + HEADER;
}

static void heapRelease(WinApplication* app, x86::reg32 address)
{
    std::lock_guard<std::mutex> lock(s_heapLock);
    const x86::reg32 block = address - HEADER;
    const x86::reg32 capacity = app->getMemory<x86::reg32>(block);
    if (capacity > (x86::reg32(1) << MAX_CLASS))
        delete MemMap::findBlock(block);
    else
        s_freeLists[sizeClass(capacity)].push_back(block);
}

HANDLE GetProcessHeap(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return s_processHeap;
}

x86::reg32 HeapAlloc(WinApplication* app, x86::CPU& cpu,
                     HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes)
{
    NFS2_USE(cpu);
    NFS2_USE(hHeap);
    return heapAllocate(app, dwBytes, (dwFlags & HEAP_ZERO_MEMORY) != 0);
}

BOOL HeapFree(WinApplication* app, x86::CPU& cpu,
              HANDLE hHeap, DWORD dwFlags, Packed<void> lpMem)
{
    NFS2_USE(cpu);
    NFS2_USE(hHeap);
    NFS2_USE(dwFlags);
    if (lpMem) heapRelease(app, lpMem);
    return 1;
}

x86::reg32 HeapReAlloc(WinApplication* app, x86::CPU& cpu,
                       HANDLE hHeap, DWORD dwFlags, Packed<void> lpMem, SIZE_T dwBytes)
{
    NFS2_USE(cpu);
    NFS2_USE(hHeap);
    const bool zero = (dwFlags & HEAP_ZERO_MEMORY) != 0;
    if (!lpMem) return heapAllocate(app, dwBytes, zero);
    const x86::reg32 block = x86::reg32(lpMem) - HEADER;
    const x86::reg32 capacity = app->getMemory<x86::reg32>(block);
    const x86::reg32 old = app->getMemory<x86::reg32>(block + 4);
    if (dwBytes <= capacity)
    {
        if (zero && dwBytes > old) memset(&app->getMemory<x86::reg8>(lpMem + old), 0, dwBytes - old);
        app->getMemory<x86::reg32>(block + 4) = std::max<x86::reg32>(dwBytes, 1);
        return lpMem;
    }
    if (dwFlags & 0x10) return 0;  // HEAP_REALLOC_IN_PLACE_ONLY
    const x86::reg32 moved = heapAllocate(app, dwBytes, zero);
    memcpy(&app->getMemory<x86::reg8>(moved), &app->getMemory<x86::reg8>(lpMem), old);
    heapRelease(app, lpMem);
    return moved;
}

SIZE_T HeapSize(WinApplication* app, x86::CPU& cpu,
                HANDLE hHeap, DWORD dwFlags, Packed<const void> lpMem)
{
    NFS2_USE(cpu);
    NFS2_USE(hHeap);
    NFS2_USE(dwFlags);
    if (!lpMem) return SIZE_T(-1);
    return app->getMemory<x86::reg32>(x86::reg32(lpMem) - HEADER + 4);
}

// ---- private profile (.ini) files -----------------------------------------

namespace
{
struct IniSection
{
    std::string name;
    std::vector<std::pair<std::string, std::string>> entries;
};

std::string trim(const std::string& value)
{
    const char* space = " \t\r\n";
    const auto begin = value.find_first_not_of(space);
    if (begin == std::string::npos) return std::string();
    return value.substr(begin, value.find_last_not_of(space) - begin + 1);
}

bool sameText(const std::string& a, const char* b)
{
    const size_t length = strlen(b);
    if (a.size() != length) return false;
    for (size_t i = 0; i < length; ++i)
        if (tolower(static_cast<unsigned char>(a[i])) != tolower(static_cast<unsigned char>(b[i]))) return false;
    return true;
}

std::vector<IniSection> readIni(const char* fileName)
{
    std::vector<IniSection> sections;
    if (!fileName) return sections;
    // A bare file name lives next to the game, as in the Windows directory lookup.
    std::ifstream file(File::hostPath(fileName), std::ios::binary);
    if (!file)
    {
        SDL_Log("[NFS3][FILESYSTEM] ini not found: %s", fileName);
        return sections;
    }
    std::string line;
    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.empty() || line[0] == ';') continue;
        if (line[0] == '[')
        {
            const auto end = line.find(']');
            sections.push_back({trim(line.substr(1, end == std::string::npos ? std::string::npos : end - 1)), {}});
            continue;
        }
        if (sections.empty()) continue;
        const auto equals = line.find('=');
        if (equals == std::string::npos)
            sections.back().entries.push_back({line, std::string()});
        else
            sections.back().entries.push_back({trim(line.substr(0, equals)), trim(line.substr(equals + 1))});
    }
    return sections;
}

const IniSection* findSection(const std::vector<IniSection>& sections, const char* name)
{
    for (const auto& section : sections)
        if (sameText(section.name, name)) return &section;
    return nullptr;
}

/** Copies a list of strings as "a\0b\0\0", truncating like Windows does. */
DWORD copyList(const std::vector<std::string>& items, LPSTR out, DWORD size)
{
    if (!out || size < 2) return 0;
    DWORD used = 0;
    for (const auto& item : items)
    {
        if (used + item.size() + 2 > size)
        {
            // Truncated: copy what fits of this item and double-terminate.
            const DWORD room = size - used - 2;
            memcpy(out + used, item.data(), room);
            out[size - 2] = 0;
            out[size - 1] = 0;
            return size - 2;
        }
        memcpy(out + used, item.c_str(), item.size() + 1);
        used += DWORD(item.size()) + 1;
    }
    out[used] = 0;
    return used;
}
}

DWORD GetPrivateProfileStringA(WinApplication* app, x86::CPU& cpu,
                               LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault,
                               LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    const auto sections = readIni(lpFileName);
    if (!lpAppName)
    {
        std::vector<std::string> names;
        for (const auto& section : sections) names.push_back(section.name);
        return copyList(names, lpReturnedString, nSize);
    }
    const IniSection* section = findSection(sections, lpAppName);
    if (!lpKeyName)
    {
        std::vector<std::string> keys;
        if (section) for (const auto& entry : section->entries) keys.push_back(entry.first);
        return copyList(keys, lpReturnedString, nSize);
    }
    std::string value = trim(lpDefault ? lpDefault : "");
    if (section)
    {
        for (const auto& entry : section->entries)
        {
            if (!sameText(entry.first, lpKeyName)) continue;
            value = entry.second;
            if (value.size() >= 2 && (value[0] == '"' || value[0] == '\'') && value.back() == value[0])
                value = value.substr(1, value.size() - 2);
            break;
        }
    }
    if (!lpReturnedString || nSize == 0) return 0;
    const DWORD length = std::min<DWORD>(DWORD(value.size()), nSize - 1);
    memcpy(lpReturnedString, value.data(), length);
    lpReturnedString[length] = 0;
    return length;
}

UINT GetPrivateProfileIntA(WinApplication* app, x86::CPU& cpu,
                           LPCSTR lpAppName, LPCSTR lpKeyName, x86::sreg32 nDefault, LPCSTR lpFileName)
{
    char buffer[64];
    if (!GetPrivateProfileStringA(app, cpu, lpAppName, lpKeyName, "", buffer, sizeof(buffer), lpFileName))
        return UINT(nDefault);
    // Windows parses leading digits only and returns 0 for non-numeric text.
    return UINT(strtol(buffer, nullptr, 10));
}

DWORD GetPrivateProfileSectionA(WinApplication* app, x86::CPU& cpu,
                                LPCSTR lpAppName, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    const auto sections = readIni(lpFileName);
    std::vector<std::string> lines;
    if (const IniSection* section = lpAppName ? findSection(sections, lpAppName) : nullptr)
        for (const auto& entry : section->entries) lines.push_back(entry.first + "=" + entry.second);
    return copyList(lines, lpReturnedString, nSize);
}

// ---- resources ---------------------------------------------------------------

static x86::reg32 s_resourceSection = 0;
static const x86::reg32 IMAGE_BASE = 0x400000;

void setResourceSection(x86::reg32 address)
{
    s_resourceSection = address;
}

/** True when a resource directory entry's name matches an ID or a string. */
static bool matchesName(WinApplication* app, x86::reg32 entryName, x86::reg32 wanted)
{
    if (wanted < 0x10000)
        return !(entryName & 0x80000000u) && entryName == wanted;
    const char* text = &app->getMemory<char>(wanted);
    if (text[0] == '#')
        return !(entryName & 0x80000000u) && entryName == x86::reg32(strtoul(text + 1, nullptr, 10));
    if (!(entryName & 0x80000000u)) return false;
    const x86::reg32 string = s_resourceSection + (entryName & 0x7fffffffu);
    const x86::reg16 length = app->getMemory<x86::reg16>(string);
    if (strlen(text) != length) return false;
    for (x86::reg16 i = 0; i < length; ++i)
    {
        const x86::reg16 c = app->getMemory<x86::reg16>(string + 2 + 2 * i);
        if (c > 0x7f || toupper(c) != toupper(static_cast<unsigned char>(text[i]))) return false;
    }
    return true;
}

/** Finds a child of a resource directory; wanted == ~0 takes the first one. */
static x86::reg32 findEntry(WinApplication* app, x86::reg32 directory, x86::reg32 wanted)
{
    const x86::reg32 count = app->getMemory<x86::reg16>(directory + 12) + app->getMemory<x86::reg16>(directory + 14);
    for (x86::reg32 i = 0; i < count; ++i)
    {
        const x86::reg32 entry = directory + 16 + i * 8;
        if (wanted == ~0u || matchesName(app, app->getMemory<x86::reg32>(entry), wanted))
            return app->getMemory<x86::reg32>(entry + 4);
    }
    return ~0u;
}

HANDLE FindResourceA(WinApplication* app, x86::CPU& cpu,
                     HMODULE hModule, Packed<const char> lpName, Packed<const char> lpType)
{
    NFS2_USE(cpu);
    NFS2_USE(hModule);
    if (!s_resourceSection) return 0;
    // Type, then name, then the first language.
    x86::reg32 offset = findEntry(app, s_resourceSection, lpType);
    if (offset == ~0u || !(offset & 0x80000000u)) return 0;
    offset = findEntry(app, s_resourceSection + (offset & 0x7fffffffu), lpName);
    if (offset == ~0u || !(offset & 0x80000000u)) return 0;
    offset = findEntry(app, s_resourceSection + (offset & 0x7fffffffu), ~0u);
    if (offset == ~0u || (offset & 0x80000000u)) return 0;
    return s_resourceSection + offset;
}

HANDLE LoadResource(WinApplication* app, x86::CPU& cpu,
                    HMODULE hModule, HANDLE hResInfo)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hModule);
    return hResInfo;
}

x86::reg32 LockResource(WinApplication* app, x86::CPU& cpu,
                        HANDLE hResData)
{
    NFS2_USE(cpu);
    return hResData ? IMAGE_BASE + x86::reg32(app->getMemory<x86::reg32>(hResData)) : 0;
}

DWORD SizeofResource(WinApplication* app, x86::CPU& cpu,
                     HMODULE hModule, HANDLE hResInfo)
{
    NFS2_USE(cpu);
    NFS2_USE(hModule);
    return hResInfo ? x86::reg32(app->getMemory<x86::reg32>(hResInfo + 4)) : 0;
}

}}
