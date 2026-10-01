#include <lib/gamepad.h>
#include <SDL_events.h>
#include <SDL_log.h>
#include <algorithm>


namespace win32
{

static x86::reg32 s_kbPoll = 3;

static GamepadState s_state;
static Gamepad* s_gp1;

void Input::poll()
{
    s_kbPoll = 3;
    SDL_JoystickUpdate();
}

void Gamepad::updateKeys()
{
    if (s_gp1)
    {
        SDL_JoystickUpdate();
        if (s_kbPoll == 0)
        {
            GamepadState state = s_gp1->getState();
            SDL_Event event;
            for (x86::reg32 axis = 0; axis < 10; ++axis)
            {
                if (state.axes[axis] != s_state.axes[axis])
                {
                    event.type = SDL_JOYAXISMOTION;
                    event.jaxis.which = 0;
                    event.jaxis.axis = axis;
                    event.jaxis.value = state.axes[axis];
                    SDL_PushEvent(&event);
                }
            }
            for (x86::reg32 button = 0; button < 64; ++button)
            {
                x86::reg64 bMask = 1ll << button;
                if ((s_state.buttons & bMask) != (state.buttons & bMask))
                {
                    event.type = state.buttons & bMask ? SDL_JOYBUTTONDOWN : SDL_JOYBUTTONUP;
                    event.jbutton.which = 0;
                    event.jbutton.button = button;
                    event.jbutton.state = state.buttons & bMask ? SDL_PRESSED : SDL_RELEASED;
                    SDL_PushEvent(&event);
                }
            }
            s_state = state;
        }
        else
        {
            SDL_Log("Ignoring event poll");
            SDL_Event event;
            for (x86::reg32 button = 0; button < 64; ++button)
            {
                x86::reg64 bMask = 1ll << button;
                if ((s_state.buttons & bMask))
                {
                    event.type = SDL_JOYBUTTONUP;
                    event.jbutton.which = 0;
                    event.jbutton.button = button;
                    event.jbutton.state = SDL_RELEASED;
                    SDL_PushEvent(&event);
                }
            }
            memset(&s_state, 0, sizeof(s_state));
            s_kbPoll--;
        }
    }
}

x86::reg32 Input::getButtonCount() const
{
    return 0;
}

x86::reg32 Input::getAxesCount() const
{
    return 0;
}

Gamepad::Gamepad(x86::reg32 gamepadIndex)
    :   m_joystick(nullptr), m_controller(nullptr)
{
    if(SDL_IsGameController(gamepadIndex)) {
        m_controller=SDL_GameControllerOpen(gamepadIndex);
        if(m_controller) m_joystick=SDL_GameControllerGetJoystick(m_controller);
    } else m_joystick=SDL_JoystickOpen(gamepadIndex);
    if(!m_joystick) SDL_LogError(SDL_LOG_CATEGORY_INPUT,"[NFS3][INPUT] Controller open: %s",SDL_GetError());
    SDL_JoystickEventState(0);
    if (!s_gp1)
        s_gp1 = this;
}

Gamepad::~Gamepad()
{
    if (s_gp1)
        s_gp1 = nullptr;
    if(m_controller) SDL_GameControllerClose(m_controller);
    else SDL_JoystickClose(m_joystick);
}

x86::reg32 Gamepad::getCount()
{
    return SDL_NumJoysticks();
}

x86::reg32 Gamepad::getButtonCount() const
{
    return m_controller ? 16 : (m_joystick ? std::max(0,SDL_JoystickNumButtons(m_joystick)) : 0);
}

x86::reg32 Gamepad::getAxesCount() const
{
    return m_controller ? 6 : (m_joystick ? std::max(0,SDL_JoystickNumAxes(m_joystick)) : 0);
}

GamepadState Gamepad::getState() const
{
    GamepadState result;
    memset(&result, 0, sizeof(result));
    if(m_controller) {
        const SDL_GameControllerButton buttons[]={SDL_CONTROLLER_BUTTON_A,SDL_CONTROLLER_BUTTON_B,
            SDL_CONTROLLER_BUTTON_X,SDL_CONTROLLER_BUTTON_Y,SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
            SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,SDL_CONTROLLER_BUTTON_BACK,SDL_CONTROLLER_BUTTON_START,
            SDL_CONTROLLER_BUTTON_LEFTSTICK,SDL_CONTROLLER_BUTTON_RIGHTSTICK};
        for(unsigned b=0;b<10;++b) if(SDL_GameControllerGetButton(m_controller,buttons[b])) result.buttons|=uint64_t(1)<<b;
        for(int a=0;a<6;++a) result.axes[a]=SDL_GameControllerGetAxis(m_controller,SDL_GameControllerAxis(a));
        if(SDL_GameControllerGetButton(m_controller,SDL_CONTROLLER_BUTTON_DPAD_LEFT)) result.axes[0]=-32767;
        if(SDL_GameControllerGetButton(m_controller,SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) result.axes[0]=32767;
        if(SDL_GameControllerGetButton(m_controller,SDL_CONTROLLER_BUTTON_DPAD_UP)) result.axes[1]=-32767;
        if(SDL_GameControllerGetButton(m_controller,SDL_CONTROLLER_BUTTON_DPAD_DOWN)) result.axes[1]=32767;
        return result;
    }
    for (x86::reg32 button = 0; button < std::min(getButtonCount(),64u); ++button)
    {
        result.buttons |= uint64_t(SDL_JoystickGetButton(m_joystick, button) ? 1 : 0) << button;
    }
    for (x86::reg32 axis = 0; axis < std::min(getAxesCount(),10u); ++axis)
    {
        result.axes[axis] = SDL_JoystickGetAxis(m_joystick, axis);
    }
    return result;
}


}

