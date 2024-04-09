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

    Map(int arr[8][8]);
    ~Map();

        void LoadMap(int arr[8][8]);
        void DrawMap();
        void Update();
        void Delete();
        int GetLastMap();
        std::vector<Piece*>whitePieces;
        std::vector<Piece*>blackPieces;
        std::vector<GameObject*>whitePiecesRender;
        std::vector<GameObject*>blackPiecesRender;

        int map_[8][8];
        int last_map[8][8];


    private:
        SDL_Rect src, dest;
        bool isWhite = true;
        


};
