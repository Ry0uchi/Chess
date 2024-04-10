#pragma once

#include "game.hpp"
#include "GameObject.h"
#include "ChessPieces/Piece.h"
#include "ChessPieces/Pawn.h"
#include "ChessPieces/Knight.h"
#include "ChessPieces/Bishop.h"
#include "ChessPieces/Queen.h"
#include "ChessPieces/King.h"
#include "ChessPieces/Rook.h"

class Map
{
public:

    Map();
    ~Map();

        void LoadMap();
        void DrawMap();
        void Update();
        void Delete();
        std::vector<Piece*>whitePieces;
        std::vector<Piece*>blackPieces;

        int map_[8][8];


    private:
        SDL_Rect src, dest;
        bool isWhite = true;



};
