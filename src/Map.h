#pragma once

#include "game.hpp"
#include "GameObject.h"
#include "Piece.h"
#include "Pawn.h"
#include "../header/Rook.h"

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

        GameObject* PawnW = new GameObject("assets/w_pawn_png_1024px.png");
        GameObject* KnightW = new GameObject("assets/w_knight_png_1024px.png");
        GameObject* BishopW = new GameObject("assets/w_bishop_png_1024px.png");
        GameObject* RookW = new GameObject("assets/w_rook_png_1024px.png");
        GameObject* QueenW = new GameObject("assets/w_queen_png_1024px.png");
        GameObject* KingW = new GameObject("assets/w_king_png_1024px.png");
        GameObject* PawnB = new GameObject("assets/b_pawn_png_1024px.png");
        GameObject* KnightB = new GameObject("assets/b_knight_png_1024px.png");
        GameObject* BishopB = new GameObject("assets/b_bishop_png_1024px.png");
        GameObject* RookB = new GameObject("assets/b_rook_png_1024px.png");
        GameObject* QueenB = new GameObject("assets/b_queen_png_1024px.png");
        GameObject* KingB = new GameObject("assets/b_king_png_1024px.png");

        int map_[8][8];


};
