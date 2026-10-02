#ifndef LIB_GAMEPAD_H_
#define LIB_GAMEPAD_H_

#include <lib/winapp.h>
#include <SDL_joystick.h>
#include <SDL_gamecontroller.h>


namespace win32
{

enum InputType
{
    InputType_Keyboard,
    InputType_Mouse,
    InputType_Gamepad
};

class Input : public GenericResource
{
public:
    virtual x86::reg32 getButtonCount() const;
    virtual x86::reg32 getAxesCount() const;
    static void poll();
};

class Keyboard : public Input
{
};

/** One buffered DirectInput mouse event: DIMOFS_* offset and its data. */
struct MouseEvent
{
    x86::reg32  offset;
    x86::reg32  data;
    x86::reg32  time;
};

/**
 * DirectInput mouse fed from SDL mouse and touch events.
 *
 * The game reads relative motion, but a touch is an absolute position. Each new
 * press first pushes the cursor far into the top-left corner, where the game
 * clamps it to (0, 0), and then moves it by the target position.
 */
class Mouse : public Input
{
public:
    static const x86::reg32 OFFSET_X = 0, OFFSET_Y = 4, OFFSET_Z = 8, OFFSET_BUTTON0 = 12;

    static void moveTo(int x, int y, bool snap);
    static void button(int index, bool down);
    static bool pop(MouseEvent& event);
    static void takeState(x86::sreg32& dx, x86::sreg32& dy, x86::reg8 buttons[4]);
};

struct GamepadState
{
    x86::reg64  buttons;
    x86::sreg16 axes[10];
    x86::reg8   hats[10];
};

class Gamepad : public Input
{
public:
    Gamepad(x86::reg32 gamepadIndex);
    ~Gamepad();

    virtual x86::reg32 getButtonCount() const;
    virtual x86::reg32 getAxesCount() const;

    static x86::reg32 getCount();

    GamepadState getState() const;
    static void updateKeys();
private:
    SDL_Joystick* m_joystick;
    SDL_GameController* m_controller;
};

}

#endif

