#pragma once

#include "game.hpp"

class GameObject
{
public:
    GameObject( const char* texturesheet );
    ~GameObject();

    void UpdateBoard(int xpos, int ypos);
    void Render();
    void UpdateChessPiece(int xpos, int ypos);
    void UpdateButton(const int& xsrc, const int& ysrc, const int& xdect, const int& ydest);
    void UpdateIcon(const int& xsrc, const int& ysrc, const int& xdect, const int& ydest);
    void UpdateScreen();
    SDL_Rect GetDestRect() {
         return destRect; }
    SDL_bool PointInRect(const SDL_Point* p);

private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};
