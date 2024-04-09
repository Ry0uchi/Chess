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

void Map::Map( int arr[8][8] )
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            map_[i][j] = arr[i][j];
        }
    }
};

Map::LoadMap( int map_[8][8] )
{
    LoadMap(Chess);
    Vect2f position;
    int wP = 0, bP = 0, wR = 8, bR = 8, wK = 10, bK = 10, wB = 12, bB = 12;
    for (auto row = 0; row < 8; ++row)
    {
        for (auto collumn = 0; collumn < 8; ++collumn)
        {
            position = (xBoard + collumn*60, yBoard + row*60);
            switch (map_[row][collumn])
            {
            case -6:
                whitePieces[wP] = new Pawn(true, position);
                whitePiecesRender[wP] = new GameObject("assets/w_pawn_png_1024px.png");
                wP++;
                break;
            case -5:
                whitePieces[wR] = new Rook(true, position);
                whitePiecesRender[wR] = new GameObject("assets/w_rook_png_1024px.png");
                wR++;
                break;
            case -4:   
                whitePieces[wK] = new Knight(true, position);
                whitePiecesRender[wK] = new GameObject("assets/w_knight_png_1024px.png");
                wK++;
                break;
            case -3:
                whitePieces[wB] = new Bishop(true, position);
                whitePiecesRender[wB] = new GameObject("assets/w_bishop_png_1024px.png");
                wB++;
                break;
            case -2:
                whitePieces[14] = new Queen(true, position);
                whitePiecesRender[14] = new GameObject("assets/w_queen_png_1024px.png");
                break;
            case -1:
                whitePieces[15] = new King(true, position);
                whitePiecesRender[15] = new GameObject("assets/w_king_png_1024px.png");
                break;
            case 6:
                blackPieces[bP] = new Pawn(false, position);
                blackPiecesRender[bP] = new GameObject("assets/b_pawn_png_1024px.png");
                bP++;
                break;
            case 5:
                blackPieces[bR] = new Rook(false, position);
                blackPiecesRender[bR] = new GameObject("assets/b_rook_png_1024px.png");
                bR++;
                break;
            case 4:
                blackPieces[bK] = new Knight(false, position);
                blackPiecesRender[bK] = new GameObject("assets/b_knight_png_1024px.png");
                bK++;
                break;
            case 3:
                blackPieces[bB] = new Bishop(false, position);
                blackPiecesRender[bB] = new GameObject("assets/b_bishop_png_1024px.png");
                bB++;
                break;
            case 2:
                blackPieces[14] = new Queen(false, position);
                blackPiecesRender[14] = new GameObject("assets/b_queen_png_1024px.png");
                break;
            case 1:
                blackPieces[15] = new King(false, position);
                blackPiecesRender[15] = new GameObject("assets/b_king_png_1024px.png");
                break;
            }
        }
    }
}


void Map::Update()
{
    for (int i = 0; i < 16; ++i)
    {
        whitePiecesRender[i]->UpdateChessPiece( whitePieces[i]->pos.X + 5, whitePieces[i]->pos.Y + 5 );
        //std::cout << "ok draw\n";
        blackPiecesRender[i]->UpdateChessPiece( blackPieces[i]->pos.X + 5, blackPieces[i]->pos.Y + 5 );
    }
}

int Map::GetLastMap()
{
    return last_map;
}

void Map::DrawMap()
{

    for (int i = 0; i < 16; ++i)
    {
        whitePiecesRender[i]->Render();
        blackPiecesRender[i]->Render();
        //std::cout << "Chess pieces drawn\n";
    }
}

void Map::Delete()
{
    whitePieces.clear();
    whitePieces.shrink_to_fit();
    blackPieces.clear();
    blackPieces.shrink_to_fit();
    whitePiecesRender.clear();
    whitePiecesRender.shrink_to_fit();
    blackPiecesRender.clear();
    blackPiecesRender.shrink_to_fit();
}
