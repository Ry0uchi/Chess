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
        bool IsPathClear(const Vect2i&, const Vect2i&);
        bool IsPlaceClear(const Vect2i&, const bool&);
        bool IsPawnCrossed(const Vect2i&,const bool&);
        void NewGame();
        void SaveBoard();
        void LoadBoard(int prevGame[8][8]);
        std::vector<Piece*>whitePieces;
        std::vector<Piece*>blackPieces;
        GameObject* BackButton = new GameObject("assets/button.png");

    int Chess[8][8];


    private:
        SDL_Rect src, dest;
        bool isWhite = true;



};
