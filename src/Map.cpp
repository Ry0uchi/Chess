#include "Map.h"
#include "TextureManager.h"



Map::Map()
{
    BackButton->UpdateIcon(600, 30, xBoard - 70, yBoard);
    

    int initChess[8][8] = 
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
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Chess[i][j] = initChess[j][i];
        }
    }
}

Map::~Map()
{
    Delete();
}

void Map::LoadMap()
{
    whitePieces.clear();
    blackPieces.clear();
    whitePieces.shrink_to_fit();
    blackPieces.shrink_to_fit();
    Vect2i Bpos = {};
    int tmp = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            tmp = Chess[i][j];
            Bpos.X = i;
            Bpos.Y = j;
            switch(tmp){
                //white pieces
            case -6:
                whitePieces.push_back(new Pawn(true, Bpos));
                break;
            case -5:
                whitePieces.push_back(new Rook(true, Bpos));
                break;
            case -4:
                whitePieces.push_back(new Knight(true, Bpos));
                break;
            case -3:
                whitePieces.push_back(new Bishop(true, Bpos));
                break;
            case -2:
                whitePieces.push_back(new Queen(true, Bpos));
                break;
            case -1:
                whitePieces.push_back(new King(true, Bpos));
                break;
                //black pieces
            case 6:
                blackPieces.push_back(new Pawn(false, Bpos));
                break;
            case 5:
                blackPieces.push_back(new Rook(false, Bpos));
                break;
            case 4: 
                blackPieces.push_back(new Knight(false, Bpos));
                break;
            case 3: 
                blackPieces.push_back(new Bishop(false, Bpos));
                break;  
            case 2: 
                blackPieces.push_back(new Queen(false, Bpos));
                break;
            case 1:
                blackPieces.push_back(new King(false, Bpos));
                break;
            }

        }
    }
    for (auto piece : whitePieces)
    {
        piece->image->UpdateChessPiece( piece->Bpos.X*60 + xBoard + 5, piece->Bpos.Y*60 + yBoard + 5 );
    }
    for (auto piece : blackPieces)
    {
        piece->image->UpdateChessPiece( piece->Bpos.X*60 + xBoard + 5, piece->Bpos.Y*60 + yBoard + 5 );
    }
}

bool Map::IsPathClear(const Vect2i& start, const Vect2i& end)
{
    int Bx = end.X - start.X;
    int By = end.Y - start.Y;
    if (Bx == 0)
    {
        if (By < 0)
        {
            for (int i = start.Y - 1; i > end.Y; --i)
            {
                if (Chess[start.X][i] != 0)
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = start.Y + 1; i < end.Y; ++i)
            {
                if (Chess[start.X][i] != 0)
                {
                    return false;
                }
            }
        }
    }
    else if (By == 0)
    {
        if (Bx < 0)
        {
            for (int i = start.X - 1; i > end.X; --i)
            {
                if (Chess[i][start.Y] != 0)
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = start.X + 1; i < end.X; ++i)
            {
                if(Chess[i][start.Y] != 0)
                {
                    return false;
                }
            }
        }
    }
    else if (abs(Bx) == abs(By))
    {
        if (Bx < 0 && By < 0)
        {
            for (int i = 1; i < abs(Bx); ++i)
            {
                if(Chess[start.X - i][start.Y - i] != 0)
                {
                    return false;
                }
            }
        }
        else if (Bx < 0 && By > 0)
        {
            for (int i = 1; i < abs(Bx); ++i)
            {
                if(Chess[start.X - i][start.Y + i] != 0)
                {
                    return false;
                }
            }
        }
        else if (Bx > 0 && By < 0)
        {
            for (int i = 1; i < abs(Bx); ++i)
            {
                if(Chess[start.X + i][start.Y - i] != 0)
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 1; i < abs(Bx); ++i)
            {
                if(Chess[start.X + i][start.Y + i] != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;

}

bool Map::IsPlaceClear (const Vect2i& pos, const bool& isWhite)
{
    if (isWhite)
    {
        if(Chess[pos.X][pos.Y] < 0)
        {
            return false;
        }
    }
    else
    {
        if(Chess[pos.X][pos.Y] > 0)
        {
            return false;
        }
    }
    return true;
}

void Map::Update()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Chess[i][j] = 0;
        }
    }
    for(auto piece : whitePieces)
    {
        if(piece->IsAlive())
        {
            switch(piece->name)
            {
                case PieceName::Pawn:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = -6;
                    break;
                case PieceName::Rook:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = -5;
                    break;
                case PieceName::Knight:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = -4;
                    break;
                case PieceName::Bishop:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = -3;
                    break;
                case PieceName::Queen:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = -2;
                    break;
                case PieceName::King:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = -1;
                    break;
            }
        }
    }
    for(auto piece : blackPieces)
    {
        if(piece->IsAlive())
        {
            switch(piece->name)
            {
                case PieceName::Pawn:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = 6;
                    break;
                case PieceName::Rook:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = 5;
                    break;
                case PieceName::Knight:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = 4;
                    break;
                case PieceName::Bishop:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = 3;
                    break;
                case PieceName::Queen:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = 2;
                    break;
                case PieceName::King:
                    Chess[piece->Bpos.X][piece->Bpos.Y] = 1;
                    break;
            }
        }
    }
}

void Map::DrawMap()
{

    for (auto piece : whitePieces)
    {
        piece->image->Render();
    }
    for (auto piece : blackPieces)
    {
        piece->image->Render();
    }
    BackButton->Render();
}

int Map::SaveGame(int prevGame[8][8])
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            prevGame[i][j] = Chess[i][j];
        }
    }
    return prevGame[8][8];
}

void Map::LoadBoard(int prevGame[8][8])
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Chess[i][j] = prevGame[i][j];
        }
    }
    LoadMap();
}

void Map::NewGame()
{
    int initChess[8][8] = 
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
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Chess[i][j] = initChess[j][i];
        }
    }
    LoadMap();
}

void Map::Delete()
{
    whitePieces.clear();
    whitePieces.shrink_to_fit();
    blackPieces.clear();
    blackPieces.shrink_to_fit();
}

bool Map::IsPawnCrossed(const Vect2i& Bpos, const bool& isWhite)
{
    if(isWhite && (Chess[Bpos.X+1][Bpos.Y+1] > 0 || Chess[Bpos.X-1][Bpos.Y+1] > 0))
    {
        return true;
    }
    else if(!isWhite && (Chess[Bpos.X+1][Bpos.Y-1] < 0 || Chess[Bpos.X-1][Bpos.Y-1] < 0))
    {
        return true;
    }
    return false;
}