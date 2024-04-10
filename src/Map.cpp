#include "Map.h"
#include "TextureManager.h"

int Chess[8][8] = {
    { 5, 4, 3, 2, 1, 3, 4, 5 },
    { 6, 6, 6, 6, 6, 6, 6, 6 },
    { 0, 0, 0 ,0 ,0 ,0 ,0 ,0 },
    { 0, 0, 0 ,0 ,0 ,0 ,0 ,0 },
    { 0, 0, 0 ,0 ,0 ,0 ,0 ,0 },
    { 0, 0, 0 ,0 ,0 ,0 ,0 ,0 },
    {-6,-6,-6,-6,-6,-6,-6,-6 },
    {-5,-4,-3,-2,-1,-3,-4,-5 }
};

void Map::LoadMap()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            map_[i][j] = Chess[i][j];
        }
    }
};

Map::Map()
{
    Vect2f position = {};
    std::cout<<isWhite<<"\n";
    //white pieces:
        //Pawn
    for (int i = 0; i < 8; ++i)
    {
        position = {xBoard + i*60, isWhite ? yBoard + 60*6 : yBoard};
        whitePieces.push_back(new Pawn(true, position));
    }

        //Rook
    position = {xBoard, isWhite ? yBoard + 60*7 : yBoard};
    whitePieces.push_back(new Rook(true, position));
    position = {xBoard + 60*7, isWhite ? yBoard + 60*7 : yBoard};
    whitePieces.push_back(new Rook(true, position));

        //Knight
    position = {xBoard + 60, isWhite ? yBoard + 60*7 : yBoard};
    whitePieces.push_back(new Knight(true, position));
    position = {xBoard + 60*6, isWhite ? yBoard + 60*7 : yBoard};
    whitePieces.push_back(new Knight(true, position));

        //Bishop
    position = {xBoard + 60*2, isWhite ? yBoard + 60*7 : yBoard};
    whitePieces.push_back(new Bishop(true, position));
    position = {xBoard + 60*5, isWhite ? yBoard + 60*7 : yBoard};
    whitePieces.push_back(new Bishop(true, position));

        //Queen
    position = {xBoard + 60*3, isWhite ? yBoard + 60*7 : yBoard};
    whitePieces.push_back(new Queen(true, position));

        //King
    position = {xBoard + 60*4, isWhite ? yBoard + 60*7 : yBoard};
    whitePieces.push_back(new King(true, position));
    //Black pieces:
        //Pawn
    for (int i = 0; i < 8; ++i)
    {
        position = {xBoard + i*60, isWhite ? yBoard + 60 : yBoard + 60*6};
        blackPieces.push_back(new Pawn(false, position));
    }

        //Rook
    position = {xBoard, isWhite ? yBoard : yBoard + 60*7};
    blackPieces.push_back(new Rook(false, position));
    position = {xBoard + 60*7, isWhite ? yBoard : yBoard + 60*7};
    blackPieces.push_back(new Rook(false, position));

        //Knight
    position = {xBoard + 60, isWhite ? yBoard : yBoard + 60*7};
    blackPieces.push_back(new Knight(false, position));
    position = {xBoard + 60*6, isWhite ? yBoard : yBoard + 60*7};
    blackPieces.push_back(new Knight(false, position));

            //Bishop
    position = {xBoard + 60*2, isWhite ? yBoard : yBoard + 60*7};
    blackPieces.push_back(new Bishop(false, position));
    position = {xBoard + 60*5, isWhite ? yBoard : yBoard + 60*7};
    blackPieces.push_back(new Bishop(false, position));

            //Queen
    position = {xBoard + 60*3, isWhite ? yBoard : yBoard + 60*7};
    blackPieces.push_back(new Queen(false, position));

                //King
    position = {xBoard + 60*4, isWhite ? yBoard : yBoard + 60*7};
    blackPieces.push_back(new King(false, position));
}


void Map::Update()
{
    for (int i = 0; i < 16; ++i)
    {
        whitePieces[i]->image->UpdateChessPiece( whitePieces[i]->pos.X + 5, whitePieces[i]->pos.Y + 5 );
        //std::cout << "ok draw\n";
        blackPieces[i]->image->UpdateChessPiece( blackPieces[i]->pos.X + 5, blackPieces[i]->pos.Y + 5 );
    }
}

void Map::DrawMap()
{

    for (int i = 0; i < 16; ++i)
    {
        whitePieces[i]->image->Render();
        blackPieces[i]->image->Render();
        //std::cout << "Chess pieces drawn\n";
    }
}

void Map::Delete()
{
    whitePieces.clear();
    whitePieces.shrink_to_fit();
    blackPieces.clear();
    blackPieces.shrink_to_fit();
}
