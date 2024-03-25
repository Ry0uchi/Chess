#include "SDL.h"
#include <iostream>
#include "game.hpp"

const int FPS = 90;
game *Game = nullptr;

int main(int argc, char* argv[])
{

    Game = new game();
    Game->init("Hanabi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
    while ( Game->running() )
    {
        Uint32 start = SDL_GetTicks();
        Uint32 end = SDL_GetTicks();
        Uint32 realTime = end - start;
        Uint32 delayTime = ( 1000 / FPS ) - realTime;
        if (delayTime > 0)
        {
            SDL_Delay( delayTime );
        }
        Game->handleEvents();
        Game->update();
        Game->render();
    }
    Game->clean();
    return 0;

}

