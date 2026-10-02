#ifndef LIB_WINDOW_H_
#define LIB_WINDOW_H_

#include <lib/winapp.h>
#include <winapi/types.h>

struct SDL_Window;

namespace win32
{

class WindowClass : public GenericResource
{
    friend class Window;
public:
    WindowClass(x86::reg32 windowProc);
    ~WindowClass();

private:
    x86::reg32 m_wndProc;
};

class Window : public GenericResource
{
    friend class Renderer;
public:
    Window(const char* title, int x, int y, int w, int h);
    ~Window();

    static x86::reg32 getMessage(const x86::CPU& cpu, MSG* result, Window* window, x86::reg32 filterMin, x86::reg32 msgMax);
    static x86::reg32 postMessage(x86::reg32 hWnd, x86::reg32 message, x86::reg32 wParam, x86::reg32 lParam);
    static x86::reg32 getMessageHandler();
    static void setRenderSize(int width, int height);
    static void setDisplayAspect(float aspect);
    static int getRenderWidth();
    /** Lets Glide widen race resolutions to the screen's aspect (Modern Patch only). */
    static void setWideRenderAllowed(bool allowed);
    static const int MAX_RENDER_WIDTH = 3840, MAX_RENDER_HEIGHT = 2160;
    static void widenRenderSize(int& width, int& height);
    /** Size the GPU draws a Glide frame at (supersampling to the chosen height). */
    static void outputSize(int& width, int& height);
    static void setOutputHeight(int height);
    static void setFpsLimit(int fps);
    /** Waits to honour the FPS limit and measures the frame rate; call before a swap. */
    static void paceFrame();
    static int measuredFps();
    static void getViewport(int width, int height, float& left, float& top, float& scaleX, float& scaleY);
    static bool setCursorPosition(int x, int y);

private:
    SDL_Window*     m_window;
};

}

#endif
