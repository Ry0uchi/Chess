#include "EventManager.h"

EventManager::EventManager()
{
    // keyboard
    m_KeyBoard = SDL_GetKeyboardState(nullptr);

    // mouse
    m_MouseButton = {false, false, false};
}

EventManager::~EventManager()
{
    free((void*)m_KeyBoard);
}

void EventManager::Listen()
{
    m_MousePrevPos = m_MouseCurPos;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        std::cout<<"event ongoing\n";
        switch (event.type)
        {
        case SDL_QUIT: gameRunning = false; isRunning(gameRunning); break;
        case SDL_KEYDOWN:  KeyDown(); break;
        case SDL_KEYUP:  KeyUp(); break;
        case SDL_MOUSEMOTION:  MouseMotion(event); break;
        case SDL_MOUSEBUTTONDOWN:  MouseDown(event); break;
        case SDL_MOUSEBUTTONUP:  MouseUp(event); break;
        }
    }
}


bool EventManager::isRunning(bool gameRunning)
{
    return gameRunning;
}

// keyboard

bool EventManager::isKeyDown(SDL_Scancode key)
{
    return (m_KeyBoard[key] > 0);
}

void EventManager::KeyUp()
{
    m_KeyBoard = SDL_GetKeyboardState(nullptr);
}

void EventManager::KeyDown()
{
    m_KeyBoard = SDL_GetKeyboardState(nullptr);
}

// mouse

void EventManager::MouseMotion(SDL_Event& event)
{
    m_MouseCurPos.X = event.motion.x;
    m_MouseCurPos.Y = event.motion.y;
}

void EventManager::MouseUp(SDL_Event& event)
{
    m_MouseButton[event.button.button] = false;
}

void EventManager::MouseDown(SDL_Event& event)
{
    m_MouseButton[event.button.button] = true;
}

