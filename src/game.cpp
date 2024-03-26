#include "TextureManager.h"
#include "game.hpp"
#include "GameObject.h"
#include "Map.h"

const int CELL_SIZE = 60;
const int xBoard = 385 + 20*3/4;
const int yBoard = 105 + 22*3/4;


GameObject* Board;
Map* map_;

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



    Board = new GameObject ( "assets/Chess_Wood.png", 640-255, 360-255 );
    map_ = new Map();

}

void game::handleEvents()
{

    SDL_Event event;
    SDL_PollEvent ( &event );
    switch ( event.type )
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int mouseX, mouseY;
            SDL_GetMouseState( &mouseX, &mouseY );
            std::cout << "Mouse!\n";
            //Chess movement
            for ( Piece* piece : map_->whitePieces )
            {
                std::cout << piece->xpos << " " << piece->ypos << " " << &piece << std::endl;
                if ( mouseX >= piece->x && mouseX < piece->x + 60 &&
                    mouseY >= piece->y && mouseY < piece->y  + 60 )
                {
                    piece->SetPosition( mouseX - xBoard, mouseY - yBoard );
                    std::cout << "Chess Movement Dectected\n" << piece->xpos << " " << piece->ypos << "\n";
                    break;
                }
            }
            break;
    }
}

void game::update()
{
    Board->UpdateBoard();
}
void game::render()
{
    SDL_RenderClear ( renderer );
    Board->Render();
    map_->DrawMap();
    //add stuff to render
    SDL_RenderPresent( renderer );
}
void game::clean()
{
    SDL_DestroyWindow ( window );
    SDL_DestroyRenderer ( renderer );
    map_->Delete();
    SDL_Quit();
    std::cout << "Game Clean\n";
}

