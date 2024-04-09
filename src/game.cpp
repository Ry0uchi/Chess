#include "TextureManager.h"
#include "game.hpp"
#include "GameObject.h"
#include "Map.h"
#include "EventManager.h"

const int CELL_SIZE = 60;

EventManager* m_Event;
GameObject* Board;
Map* m_Map;

SDL_Renderer* game::renderer = nullptr;

game::game()
{}

game::~game()
{}

void game::init ( const char * title, int xpos, int ypos, int width, int height, bool fullscreen )
{
    int flags = 0;
    if ( fullscreen )
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if ( SDL_Init ( SDL_INIT_EVERYTHING ) == 0)
    {
        std::cout << "Subsystem Initilized!\n";
        window = SDL_CreateWindow ( title, xpos, ypos, width, height, flags);
        if ( window )
        {
          std::cout << "Window Created\n";
        }
        renderer = SDL_CreateRenderer ( window, -1, 0 );
        if ( renderer )
        {
            SDL_SetRenderDrawColor ( renderer, 255, 255, 255, 255 );
          std::cout << "Renderer Created\n";
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }


    m_Event = new EventManager();
    Board = new GameObject("assets/Chess_Wood.png");
    m_Map = new Map(m_Map->last_map != nullptr ? m_Map->last_map : new int[8][8]);

}

void game::handleEvents()
{
    m_Event->Listen();
}

void game::update()
{
    if (m_Event->isKeyDown(SDL_SCANCODE_ESCAPE) || m_Event->isRunning(false))
    {
        isRunning = false;
    }
    else if(m_Event->MouseButtonDown(LEFT))
    {
        Vect2f pos = m_Event->GetMousePos();
        Vect2i Bpos = ((pos.X - xBoard) / CELL_SIZE, (pos.Y - yBoard) / CELL_SIZE);
        if(pos.X >= 0 && pos.X < 8 && pos.Y >= 0 && pos.Y < 8)
        {
            for(auto piece : m_Map->whitePieces)
            {
                if(piece->GetPos() == Bpos)
                {
                    piece->SetPosition(pos.X + 5, pos.Y + 5);
                }
            }
        }
    }
    Board->UpdateBoard(640-255, 360-255);
    m_Map->Update();
}
void game::render()
{
    SDL_RenderClear ( renderer );
    Board->Render();
    m_Map->DrawMap();
    //add stuff to render
    SDL_RenderPresent( renderer );
}
void game::clean()
{
    SDL_DestroyWindow ( window );
    SDL_DestroyRenderer ( renderer );
    m_Map->Delete();
    delete m_Event;
    SDL_Quit();
    std::cout << "Game Clean\n";
}

