#pragma once

#include "game.hpp"
#include "Piece.h"

class Map
{
public:

    Map();
    ~Map();

    void LoadMap( int arr[8][8] );
    void DrawMap();
    void Delete();
    std::vector<Piece*>whitePieces;


private:
    SDL_Rect src, dest;

    SDL_Texture* PawnW;
    SDL_Texture* KnightW;
    SDL_Texture* BishopW;
    SDL_Texture* RookW;
    SDL_Texture* QueenW;
    SDL_Texture* KingW;

    SDL_Texture* PawnB;
    SDL_Texture* KnightB;
    SDL_Texture* BishopB;
    SDL_Texture* RookB;
    SDL_Texture* QueenB;
    SDL_Texture* KingB;

    int map_[8][8];


};
