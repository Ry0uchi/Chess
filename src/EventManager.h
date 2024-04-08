#pragma once

#include "game.hpp"

enum MouseButtons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class EventManager
{
public:
    EventManager();
    virtual ~EventManager();

    void Listen();

    bool isKeyDown(SDL_Scancode key);

    inline const Vect2f GetMousePos() { return m_MouseCurPos; }
    inline bool MouseButtonDown(MouseButtons button) { return m_MouseButton[button]; }
    inline const Vect2f GetMouseMotion() { return m_MouseCurPos - m_MousePrevPos; }

private:
    //keyboard events
    void KeyUp();
    void KeyDown();

    //mouse button events
    void MouseMotion(SDL_Event& event);
    void MouseUp(SDL_Event& event);
    void MouseDown(SDL_Event& event);

private:
    //keyboard
    const Uint8* m_KeyBoard;

    //mouse
    Vect2f m_MouseCurPos;
    Vect2f m_MousePrevPos;

    std::vector<bool> m_MouseButton;

    static EventManager* s_Instance;
};