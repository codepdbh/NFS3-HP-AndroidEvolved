#include <atomic>
#include <lib/gamepad.h>
#include <lib/window.h>
#include <lib/thread.h>
#include <SDL_video.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_log.h>
#include <cstring>
#include <algorithm>

#define WM_KEYDOWN  0x0100
#define WM_KEYUP    0x0101
#define WM_CHAR     0x0102
#define WM_CHAR_SDL 0xC000

namespace win32
{


static const x86::reg32 WM_QUIT = 0x0012;
static const x86::reg32 WM_USER = 0x0400;
static const x86::reg32 WM_USER_END = 0xC000;
static WindowClass* s_class;
static int s_renderWidth = 640, s_renderHeight = 480;

void Window::setRenderSize(int width, int height) {
    s_renderWidth = width; s_renderHeight = height;
}

// <0: keep the game's own aspect, 0: fill the whole screen, >0: stretch up to this aspect.
static std::atomic<float> s_displayAspect{-1.f};

void Window::setDisplayAspect(float aspect) { s_displayAspect.store(aspect); }

int Window::getRenderWidth() { return s_renderWidth; }

static bool s_wideRenderAllowed = false;

void Window::setWideRenderAllowed(bool allowed) { s_wideRenderAllowed = allowed; }

/**
 * The Modern Patch adapts field of view and HUD to whatever grSstScreenWidth and
 * grSstScreenHeight report, as it does with nGlide's desktop resolution. Race
 * modes are rendered at the display's own resolution (or its height at 16:9);
 * 640x480 is left alone because the front end is laid out for it.
 */
void Window::widenRenderSize(int& width, int& height) {
    if(!s_wideRenderAllowed || (width==640 && height==480)) return;
    const float aspect=s_displayAspect.load();
    if(aspect<0) return;  // original 4:3 picture
    SDL_DisplayMode mode;
    if(SDL_GetDesktopDisplayMode(0,&mode)!=0 || mode.w<=0 || mode.h<=0) return;
    const int screenWidth=std::max(mode.w,mode.h), screenHeight=std::min(mode.w,mode.h);
    height=std::min(screenHeight, MAX_RENDER_HEIGHT);
    width=aspect==0 ? screenWidth*height/screenHeight : int(height*aspect+0.5f);
    width=std::min(width & ~1, MAX_RENDER_WIDTH);
}

void Window::getViewport(int width, int height, float& left, float& top, float& scaleX, float& scaleY) {
    const float aspect=s_displayAspect.load();
    float target=aspect<0 ? float(s_renderWidth)/s_renderHeight : aspect==0 ? float(width)/height : aspect;
    float w=float(width), h=float(height);
    if(w/h>target) w=h*target; else h=w/target;
    scaleX=w/s_renderWidth; scaleY=h/s_renderHeight;
    left=(width-w)/2; top=(height-h)/2;
}

static void mouseViewport(SDL_Window* window, float& scaleX, float& scaleY, float& left, float& top) {
    int width=0,height=0; SDL_GetWindowSize(window,&width,&height);
    if(width<=0||height<=0) { scaleX=scaleY=0; return; }
    Window::getViewport(width,height,left,top,scaleX,scaleY);
}

/**
 * NFS3 reads the mouse through DirectInput, often in loops that do not pump
 * window messages (e.g. waiting for a button release), so the DirectInput mouse
 * is fed straight from SDL as events arrive rather than from the message queue.
 */
static int SDLCALL feedDirectInputMouse(void*, SDL_Event* event) {
    const bool motion=event->type==SDL_MOUSEMOTION;
    if(!motion && event->type!=SDL_MOUSEBUTTONDOWN && event->type!=SDL_MOUSEBUTTONUP) return 1;
    SDL_Window* target=SDL_GetWindowFromID(motion ? event->motion.windowID : event->button.windowID);
    if(!target) return 1;
    float scaleX,scaleY,left,top; mouseViewport(target,scaleX,scaleY,left,top);
    if(scaleX<=0||scaleY<=0) return 1;
    const int px=motion ? event->motion.x : event->button.x;
    const int py=motion ? event->motion.y : event->button.y;
    const int x=std::clamp(int((px-left)/scaleX),0,s_renderWidth-1);
    const int y=std::clamp(int((py-top)/scaleY),0,s_renderHeight-1);
    if(motion) { Mouse::moveTo(x,y,false); return 1; }
    const bool down=event->type==SDL_MOUSEBUTTONDOWN;
    // A finger lands anywhere, so re-anchor the cursor on every touch.
    if(down) Mouse::moveTo(x,y,event->button.which==SDL_TOUCH_MOUSEID);
    const int b=event->button.button;
    if(b==SDL_BUTTON_LEFT) Mouse::button(0,down);
    else if(b==SDL_BUTTON_RIGHT) Mouse::button(1,down);
    else if(b==SDL_BUTTON_MIDDLE) Mouse::button(2,down);
    return 1;
}

bool Window::setCursorPosition(int x, int y) {
    SDL_Window* window=SDL_GetMouseFocus(); if(!window) return false;
    float scaleX,scaleY,left,top; mouseViewport(window,scaleX,scaleY,left,top);
    SDL_WarpMouseInWindow(window,int(left+x*scaleX),int(top+y*scaleY)); return true;
}

static const x86::reg8 s_scancodeTable[100] =
{
    0x00, 0x00, 0x00, 0x00, 0x1E, 0x30, 0x2E, 0x20, 0x12, 0x21,
    0x22, 0x23, 0x17, 0x24, 0x25, 0x26, 0x32, 0x31, 0x18, 0x19,
    0x10, 0x13, 0x1F, 0x14, 0x16, 0x2F, 0x11, 0x2D, 0x15, 0x2C,
    0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
    0x1C, 0x01, 0x0E, 0x0F, 0x39, 0x0C, 0x0D, 0x1A, 0x1B, 0x2B,
    0x00, 0x27, 0x28, 0x29, 0x33, 0x34, 0x35, 0x3A, 0x3B, 0x3C,
    0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x57, 0x58,
    0x37, 0x46, 0x59, 0x52, 0x47, 0x49, 0x53, 0x4F, 0x51, 0x4D,
    0x4B, 0x50, 0x48, 0x45, 0x35, 0x37, 0x4A, 0x4E, 0x1C, 0x4F,
    0x50, 0x51, 0x4B, 0x4C, 0x4D, 0x47, 0x48, 0x49, 0x52, 0x53
};


WindowClass::WindowClass(x86::reg32 windowProc)
    :   m_wndProc(windowProc)
{
    s_class = this;
}

WindowClass::~WindowClass()
{
}

Window::Window(const char *title, int x, int y, int w, int h)
    :   m_window(SDL_CreateWindow(title, x+5, y+30, w, h, SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL
#ifdef __ANDROID__
        |SDL_WINDOW_FULLSCREEN_DESKTOP
#endif
        ))
{
    if (!m_window)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return;
    }
    static bool s_mouseWatch = false;
    if (!s_mouseWatch)
    {
        SDL_AddEventWatch(feedDirectInputMouse, nullptr);
        s_mouseWatch = true;
    }
}

Window::~Window()
{
}

x86::reg32 Window::getMessage(const x86::CPU& cpu, MSG* result, Window *window, x86::reg32 filterMin, x86::reg32 msgMax)
{
    NFS2_USE(window);
    NFS2_USE(filterMin);
    NFS2_USE(msgMax);
    static LPARAM s_lastLParam;
    memset(result, 0, sizeof(MSG));
    SDL_Event event;
    for (;;)
    {
        if (SDL_WaitEvent(&event))
        {
            if (cpu.terminate)
                return 0;
            switch (event.type)
            {
            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                {
                    const bool motion=event.type==SDL_MOUSEMOTION;
                    SDL_Window* target=SDL_GetWindowFromID(motion ? event.motion.windowID : event.button.windowID);
                    if(!target) break;
                    float scaleX,scaleY,left,top; mouseViewport(target,scaleX,scaleY,left,top);
                    if(scaleX<=0||scaleY<=0) break;
                    const int px=motion ? event.motion.x : event.button.x;
                    const int py=motion ? event.motion.y : event.button.y;
                    // Ignore touches in the pillarboxes; the game uses its own cursor.
                    if(px<left || py<top || px>=left+s_renderWidth*scaleX || py>=top+s_renderHeight*scaleY) break;
                    const int x=std::clamp(int((px-left)/scaleX),0,s_renderWidth-1);
                    const int y=std::clamp(int((py-top)/scaleY),0,s_renderHeight-1);
                    result->message=0x0200; // WM_MOUSEMOVE
                    if(!motion) {
                        if(event.button.button==SDL_BUTTON_LEFT) result->message=event.type==SDL_MOUSEBUTTONDOWN ? 0x0201 : 0x0202;
                        else if(event.button.button==SDL_BUTTON_RIGHT) result->message=event.type==SDL_MOUSEBUTTONDOWN ? 0x0204 : 0x0205;
                        else break;
                    }
                    const Uint32 buttons=motion ? event.motion.state : SDL_GetMouseState(nullptr,nullptr);
                    result->wParam=((buttons&SDL_BUTTON_LMASK)?1u:0u)|((buttons&SDL_BUTTON_RMASK)?2u:0u);
                    result->lParam=(x&0xffff)|((y&0xffff)<<16);
                    result->hWindow=window ? window->getResourceIndex() : 0;
                    return 1;
                }
            case SDL_QUIT:
                result->message = WM_QUIT;
                return 0;
            case SDL_USEREVENT:
            case SDL_USEREVENT + 1:
                result->message = x86::reg32(event.user.code);
                result->wParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data1));
                result->lParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data2));
                result->hWindow = event.user.windowID;
                return result->message != WM_QUIT;
            case SDL_USEREVENT + 2:
                {
                    const x86::reg32 tid = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data1));
                    if (tid == Thread::currentThreadId())
                    {
                        SDL_Log("Requesting kill of window thread %x", Thread::currentThreadId());
                        return 0;
                    }
                }
                break;
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                {
                    SDL_Scancode scancode = event.key.keysym.scancode;
                    SDL_Keycode sym = event.key.keysym.sym;

                    BOOL isWMChar = false;

                    result->lParam = 1;

                    switch (sym)
                    {
                        case SDLK_LSHIFT:
                        case SDLK_RSHIFT:
                            result->wParam = 0x10;
                            break;
                        case SDLK_PAGEDOWN:
                            result->wParam = 0x21;
                            break;
                        case SDLK_PAGEUP:
                            result->wParam = 0x22;
                            break;
                        case SDLK_END:
                            result->wParam = 0x23;
                            break;
                        case SDLK_HOME:
                            result->wParam = 0x24;
                            break;
                        case SDLK_LEFT:
                            result->wParam = 0x25;
                            break;
                        case SDLK_UP:
                            result->wParam = 0x26;
                            break;
                        case SDLK_RIGHT:
                            result->wParam = 0x27;
                            break;
                        case SDLK_DOWN:
                            result->wParam = 0x28;
                            break;
                        case SDLK_INSERT:
                            result->wParam = 0x2D;
                            break;
                        case SDLK_DELETE:
                            result->wParam = 0x2E;
                            break;
                        case SDLK_KP_0:
                            result->wParam = 0x60;
                            break;
                        case SDLK_KP_1:
                            result->wParam = 0x61;
                            break;
                        case SDLK_KP_2:
                            result->wParam = 0x62;
                            break;
                        case SDLK_KP_3:
                            result->wParam = 0x63;
                            break;
                        case SDLK_KP_4:
                            result->wParam = 0x64;
                            break;
                        case SDLK_KP_5:
                            result->wParam = 0x65;
                            break;
                        case SDLK_KP_6:
                            result->wParam = 0x66;
                            break;
                        case SDLK_KP_7:
                            result->wParam = 0x67;
                            break;
                        case SDLK_KP_8:
                            result->wParam = 0x68;
                            break;
                        case SDLK_KP_9:
                            result->wParam = 0x69;
                            break;
                        case SDLK_KP_MULTIPLY:
                            result->wParam = 0x6A;
                            break;
                        case SDLK_KP_PLUS:
                            result->wParam = 0x6B;
                            break;
                        case SDLK_KP_MINUS:
                            result->wParam = 0x6D;
                            break;
                        case SDLK_KP_PERIOD:
                            result->wParam = 0x6E;
                            break;
                        case SDLK_KP_DIVIDE:
                            result->wParam = 0x6F;
                            break;
                        case SDLK_EQUALS:
                            result->wParam = 0xBB;
                            break;
                        case SDLK_MINUS:
                            result->wParam = 0xBD;
                            break;
                        case SDLK_PERIOD:
                            result->wParam = 0xBE;
                            break;
                        case SDLK_BACKQUOTE:
                            result->wParam = 0xC0;
                            break;
                        case SDLK_QUOTE:
                            result->wParam = 0xDE;
                            break;
                        case SDLK_KP_ENTER:
                            sym = SDLK_RETURN;
                        [[fallthrough]];
                        default:
                            if (!(sym & 0x40000000))
                            {
                                isWMChar = sym >= SDLK_BACKSPACE && sym < SDLK_SPACE;
                                result->wParam = DWORD(sym);
                            }
                    }

                    if (result->lParam == 1 && scancode < 100)
                        result->lParam |= s_scancodeTable[scancode] << 16;
                    s_lastLParam = result->lParam;

                    SDL_Event event2;
                    event2.type = WM_CHAR_SDL;
                    if (event.type == SDL_KEYUP)
                        result->message = WM_KEYUP;
                    else if (event.type == SDL_KEYDOWN)
                    {
                        result->message = WM_KEYDOWN;
                        if (isWMChar)
                        {
                            event2.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(result->wParam));
                            event2.user.data2 = reinterpret_cast<void*>(static_cast<intptr_t>(result->lParam));
                            SDL_PushEvent(&event2);
                        }
                    }

                    if (sym >= SDLK_a && sym <= SDLK_z)
                        result->wParam = sym & ~0x20;
                }
                return 1;
            case SDL_JOYBUTTONDOWN:
            case SDL_JOYBUTTONUP:
                {
                    if (event.jbutton.which == 0)
                    {
                        if (event.jbutton.button == 7)
                        {
                            /* simulate Enter */
                            result->wParam = DWORD(SDLK_RETURN);
                            result->lParam = 1 | s_scancodeTable[SDL_SCANCODE_RETURN] << 16;
                        }
                        else if (event.jbutton.button == 6)
                        {
                            /* simulate Escape */
                            result->wParam = DWORD(SDLK_ESCAPE);
                            result->lParam = 1 | s_scancodeTable[SDL_SCANCODE_ESCAPE] << 16;
                        }
                        else
                        {
                            /* simulate Space */
                            result->wParam = DWORD(SDLK_SPACE);
                            result->lParam = 1 | s_scancodeTable[SDL_SCANCODE_SPACE] << 16;
                        }
                        result->message = event.jbutton.state == SDL_PRESSED ? WM_KEYDOWN : WM_KEYUP;
                        result->hWindow = event.user.windowID;

                        if (event.jbutton.state == SDL_PRESSED)
                        {
                            SDL_Event event2;
                            event2.type = WM_CHAR_SDL;
                            event2.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(result->wParam));
                            event2.user.data2 = reinterpret_cast<void*>(static_cast<intptr_t>(result->lParam));
                            SDL_PushEvent(&event2);
                        }

                        return 1;
                    }
                    SDL_Log("Joy button event: %d[%d] = %s", event.jbutton.which, event.jbutton.button, event.jbutton.state == SDL_PRESSED ? "Down" : "Up");
                }
                break;
            case SDL_JOYAXISMOTION:
                if (event.jaxis.which == 0)
                {
                    if (event.jaxis.axis == 0)
                    {
                        static x86::sreg16 s_prevAxisValue = 0;
                        SDL_Log("Joy axis event: %d[%d] = %d -> %d", event.jaxis.which, event.jaxis.axis, s_prevAxisValue, event.jaxis.value);
                        if ((s_prevAxisValue > 30000) && (event.jaxis.value < 30000))
                        {
                            SDL_Event kevent;
                            kevent.type = SDL_KEYUP;
                            kevent.key.keysym.sym = SDLK_RIGHT;
                            kevent.key.keysym.scancode = SDL_SCANCODE_RIGHT;
                            SDL_PushEvent(&kevent);
                        }
                        if ((s_prevAxisValue < -30000) && (event.jaxis.value > -30000))
                        {
                            SDL_Event kevent;
                            kevent.type = SDL_KEYUP;
                            kevent.key.keysym.sym = SDLK_LEFT;
                            kevent.key.keysym.scancode = SDL_SCANCODE_LEFT;
                            SDL_PushEvent(&kevent);
                        }
                        if ((s_prevAxisValue < 30000) && (event.jaxis.value > 30000))
                        {
                            SDL_Event kevent;
                            kevent.type = SDL_KEYDOWN;
                            kevent.key.keysym.sym = SDLK_RIGHT;
                            kevent.key.keysym.scancode = SDL_SCANCODE_RIGHT;
                            SDL_PushEvent(&kevent);
                        }
                        if ((s_prevAxisValue > -30000) && (event.jaxis.value < -30000))
                        {
                            SDL_Event kevent;
                            kevent.type = SDL_KEYDOWN;
                            kevent.key.keysym.sym = SDLK_LEFT;
                            kevent.key.keysym.scancode = SDL_SCANCODE_LEFT;
                            SDL_PushEvent(&kevent);
                        }
                        s_prevAxisValue = event.jaxis.value;
                        break;
                    }
                    if (event.jaxis.axis == 1)
                    {
                        static x86::sreg16 s_prevAxisValue = 0;
                        SDL_Log("Joy axis event: %d[%d] = %d -> %d", event.jaxis.which, event.jaxis.axis, s_prevAxisValue, event.jaxis.value);
                        if ((s_prevAxisValue > 30000) && (event.jaxis.value < 30000))
                        {
                            SDL_Event kevent;
                            kevent.type = SDL_KEYUP;
                            kevent.key.keysym.sym = SDLK_DOWN;
                            kevent.key.keysym.scancode = SDL_SCANCODE_DOWN;
                            SDL_PushEvent(&kevent);
                        }
                        if ((s_prevAxisValue < -30000) && (event.jaxis.value > -30000))
                        {
                            SDL_Event kevent;
                            kevent.type = SDL_KEYUP;
                            kevent.key.keysym.sym = SDLK_UP;
                            kevent.key.keysym.scancode = SDL_SCANCODE_UP;
                            SDL_PushEvent(&kevent);
                        }
                        if ((s_prevAxisValue < 30000) && (event.jaxis.value > 30000))
                        {
                            SDL_Event kevent;
                            kevent.type = SDL_KEYDOWN;
                            kevent.key.keysym.sym = SDLK_DOWN;
                            kevent.key.keysym.scancode = SDL_SCANCODE_DOWN;
                            SDL_PushEvent(&kevent);
                        }
                        if ((s_prevAxisValue > -30000) && (event.jaxis.value < -30000))
                        {
                            SDL_Event kevent;
                            kevent.type = SDL_KEYDOWN;
                            kevent.key.keysym.sym = SDLK_UP;
                            kevent.key.keysym.scancode = SDL_SCANCODE_UP;
                            SDL_PushEvent(&kevent);
                        }
                        s_prevAxisValue = event.jaxis.value;
                        break;
                    }
                }
                break;
            case SDL_JOYHATMOTION:
                if (event.jhat.which == 0 && event.jhat.hat == 0)
                {
                    static x86::reg32 s_prevHatButtons = 0;
                    x86::reg32 hatButtons = event.jhat.value;
                    SDL_Event event;
                    if ((s_prevHatButtons & SDL_HAT_LEFT) != (hatButtons & SDL_HAT_LEFT))
                    {
                        event.type = hatButtons & SDL_HAT_LEFT ? SDL_KEYDOWN : SDL_KEYUP;
                        event.key.keysym.sym = SDLK_LEFT;
                        event.key.keysym.scancode = SDL_SCANCODE_LEFT;
                        SDL_PushEvent(&event);
                    }
                    if ((s_prevHatButtons & SDL_HAT_RIGHT) != (hatButtons & SDL_HAT_RIGHT))
                    {
                        event.type = hatButtons & SDL_HAT_RIGHT ? SDL_KEYDOWN : SDL_KEYUP;
                        event.key.keysym.sym = SDLK_RIGHT;
                        event.key.keysym.scancode = SDL_SCANCODE_RIGHT;
                        SDL_PushEvent(&event);
                    }
                    if ((s_prevHatButtons & SDL_HAT_UP) != (hatButtons & SDL_HAT_UP))
                    {
                        event.type = hatButtons & SDL_HAT_UP ? SDL_KEYDOWN : SDL_KEYUP;
                        event.key.keysym.sym = SDLK_UP;
                        event.key.keysym.scancode = SDL_SCANCODE_UP;
                        SDL_PushEvent(&event);
                    }
                    if ((s_prevHatButtons & SDL_HAT_DOWN) != (hatButtons & SDL_HAT_DOWN))
                    {
                        event.type = hatButtons & SDL_HAT_DOWN ? SDL_KEYDOWN : SDL_KEYUP;
                        event.key.keysym.sym = SDLK_DOWN;
                        event.key.keysym.scancode = SDL_SCANCODE_DOWN;
                        SDL_PushEvent(&event);
                    }
                    break;
                }
                break;
            case SDL_TEXTINPUT:
                {
                    result->message = WM_CHAR;
                    result->wParam = event.text.text[0];
                    result->lParam = s_lastLParam;
                }
                return 1;
            case WM_CHAR_SDL:
                result->message = WM_CHAR;
                result->wParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data1));
                result->lParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data2));
                return 1;
            default:
                // Swallows message
                SDL_Log("Ignoring event type 0x%x\n", event.type);
                break;
            }
        }
    }
}

x86::reg32 Window::postMessage(x86::reg32 hWnd, x86::reg32 message, x86::reg32 wParam, x86::reg32 lParam)
{
    SDL_Event event;
    if (message >= WM_USER && message < WM_USER_END)
    {
        event.type = SDL_USEREVENT;
    }
    else
    {
        event.type = SDL_USEREVENT + 1;
    }
    event.user.code = int(message);
    event.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(wParam));
    event.user.data2 = reinterpret_cast<void*>(static_cast<intptr_t>(lParam));
    event.user.windowID = hWnd;
    SDL_PushEvent(&event);
    return 1;
}

x86::reg32 Window::getMessageHandler()
{
    return s_class->m_wndProc;
}

}

#ifdef __ANDROID__
#include <jni.h>
extern "C" JNIEXPORT void JNICALL
Java_com_nfsrecompiled_nfs3hp_NFS3Activity_nativeSetDisplayAspect(JNIEnv*, jclass, jfloat aspect)
{
    win32::Window::setDisplayAspect(aspect);
}

/** Width of the game's current video mode; the front end always runs at 640x480. */
extern "C" JNIEXPORT jint JNICALL
Java_com_nfsrecompiled_nfs3hp_NFS3Activity_nativeGetRenderWidth(JNIEnv*, jclass)
{
    return win32::Window::getRenderWidth();
}
#endif
