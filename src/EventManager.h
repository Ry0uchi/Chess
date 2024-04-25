#pragma once

#include "game.hpp"

enum MouseButtons
{
    LEFT = 1,
    MIDDLE = 2,
    RIGHT = 3
};

class EventManager
{
public:
    EventManager();
    virtual ~EventManager();

    void Listen();

    bool isRunning();

    bool isKeyDown(SDL_Scancode key);

    bool isSelected();

    void SetSelected(bool selected);

    void SetMousePrevPos() { m_MousePrevPos = m_MouseCurPos; }

    inline const Vect2f GetMousePos() { return m_MouseCurPos; }

    inline const Vect2f GetMousePrevPos() { return m_MousePrevPos; }

    inline bool MouseButtonDown(MouseButtons button) {
        return m_MouseButton[button];
    }
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
    bool selected = false;
    bool running = true;

    //keyboard
    const Uint8* m_KeyBoard;

    //mouse
    Vect2f m_MouseCurPos = {};
    Vect2f m_MousePrevPos = {};

    std::vector<bool> m_MouseButton;

};
