#include "EventManager.h"

EventManager::EventManager()
{}

EventManager::~EventManager()
{}

void EventManager::Listen()
{
    m_MousePrevPos = m_MouseCurPos;
    
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:  break;
        case SDL_KEYDOWN:  KeyDown(); break;
        case SDL_KEYUP:  KeyUp(); break;
        case SDL_MOUSEMOTION:  MouseMotion(event); break;
        case SDL_MOUSEBUTTONDOWN:  MouseDown(event); break;
        case SDL_MOUSEBUTTONUP:  MouseUp(event); break;
        }
    }
}

// keyboard

bool EventManager::isKeyDown(SDL_Scancode key)
{}

void EventManager::KeyUp()
{}

void EventManager::KeyDown()
{}

// mouse

void EventManager::MouseMotion(SDL_Event& event)
{
    m_MouseCurPos.x = event.motion.x;
    m_MouseCurPos.y = event.motion.y;
}

void EventManager::MouseUp(SDL_Event& event)
{
    m_MouseButton[event.button.button] = false;
}

void EventManager::MouseDown(SDL_Event& event)
{
    m_MouseButton[event.button.button] = true;
}

