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
        int SaveGame(int prevGame[8][8]);
        bool IsPathClear(Vect2i start, Vect2i end);
        bool IsPlaceClear(Vect2i pos, bool isWhite);
        void SaveBoard();
        std::vector<Piece*>whitePieces;
        std::vector<Piece*>blackPieces;

        int Chess[8][8] = 
        {
            { 5, 4, 3, 2, 1, 3, 4, 5 },
            { 6, 6, 6, 6, 6, 6, 6, 6 },
            { 0, 0, 0 ,0 ,0 ,0 ,0 ,0 },
            { 0, 0, 0 ,0 ,0 ,0 ,0 ,0 },
            { 0, 0, 0 ,0 ,0 ,0 ,0 ,0 },
            { 0, 0, 0 ,0 ,0 ,0 ,0 ,0 },
            {-6,-6,-6,-6,-6,-6,-6,-6 },
            {-5,-4,-3,-2,-1,-3,-4,-5 }
        };


    private:
        SDL_Rect src, dest;
        bool isWhite = true;



};
