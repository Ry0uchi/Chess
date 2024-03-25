#ifndef game_hpp
#define game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <stdio.h>
#include <vector>

class game
{
public:
    game();
    ~game();

    void init ( const char * title, int xpos, int ypos, int width, int height, bool fullscreen );
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; };

    static SDL_Renderer* renderer;

private:
    bool isRunning;
    int cnt = 0;
    SDL_Window *window;
};

#endif /* game_hppp */


