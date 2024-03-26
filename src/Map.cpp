#include "Map.h"
#include "TextureManager.h"

const int xBoard = 385 + 20*3/4;
const int yBoard = 105 + 22*3/4;

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

Map::Map()
{
    //white pieces
    PawnW = TextureManager::LoadTexture( "assets/w_pawn_png_1024px.png" );
    if( PawnW == NULL ) std::cout << "Can't load Texture";
    RookW = TextureManager::LoadTexture( "assets/w_rook_png_1024px.png" );
    if( RookW == NULL ) std::cout << "Can't load Texture";
    KnightW = TextureManager::LoadTexture( "assets/w_knight_png_1024px.png" );
    if( KnightW == NULL ) std::cout << "Can't load Texture";
    BishopW = TextureManager::LoadTexture( "assets/w_bishop_png_1024px.png" );
    if( BishopW == NULL ) std::cout << "Can't load Texture";
    QueenW = TextureManager::LoadTexture( "assets/w_queen_png_1024px.png" );
    if( QueenW == NULL ) std::cout << "Can't load Texture";
    KingW = TextureManager::LoadTexture( "assets/w_king_png_1024px.png" );
    if( KingW == NULL ) std::cout << "Can't load Texture";


    //black pieces
    PawnB = TextureManager::LoadTexture( "assets/b_pawn_png_1024px.png" );
    if( PawnB == NULL ) std::cout << "Can't load Texture";
    RookB = TextureManager::LoadTexture( "assets/b_rook_png_1024px.png" );
    if( RookB == NULL ) std::cout << "Can't load Texture";
    KnightB = TextureManager::LoadTexture( "assets/b_knight_png_1024px.png" );
    if( KnightB == NULL ) std::cout << "Can't load Texture";
    BishopB = TextureManager::LoadTexture( "assets/b_bishop_png_1024px.png" );
    if( BishopB == NULL ) std::cout << "Can't load Texture";
    QueenB = TextureManager::LoadTexture( "assets/b_queen_png_1024px.png" );
    if( QueenB == NULL ) std::cout << "Can't load Texture";
    KingB = TextureManager::LoadTexture( "assets/b_king_png_1024px.png" );
    if( KingB == NULL ) std::cout << "Can't load Texture";
    LoadMap( Chess );

    src.x = 0;
    src.y = 0;
    src.h = 1125;
    src.w = 1125;

    dest.w = 50;
    dest.h = 50;
    dest.x = xBoard;
    dest.y = yBoard;


    int type = 0;
    for( int row = 0; row < 8; ++row )
   {
       for( int colum = 0; colum < 8; ++colum )
       {
           type = map_[row][colum];
           dest.x = colum * 60 + xBoard + 5;
           dest.y = row * 60 + yBoard + 5;

           switch( type )
           {
            case -6:
                whitePieces.push_back(new Pawn( true, dest.x - 5, dest.y - 5 ));
                break;
            case -5:
                whitePieces.push_back(new Rook( true, (dest.x - xBoard - 5) / 60 , (dest.y - yBoard - 5) / 60 ));
                break;
            /*case -4:
                TextureManager::Draw( KnightW, src, dest );
                break;
            case -3:
                TextureManager::Draw( BishopW, src, dest );
                break;
            case -2:
                TextureManager::Draw( QueenW, src, dest );
                break;
            case -1:
                TextureManager::Draw( KingW, src, dest );
                break;
            case 6:
                TextureManager::Draw( PawnB, src, dest );
                break;
            case 5:
                TextureManager::Draw( RookB, src, dest );
                break;
            case 4:
                TextureManager::Draw( KnightB, src, dest );
                break;
            case 3:
                TextureManager::Draw( BishopB, src, dest );
                break;
            case 2:
                TextureManager::Draw( QueenB, src, dest );
                break;
            case 1:
                TextureManager::Draw( KingB, src, dest );
                break;*/
           }

       }
   }
}

void Map::LoadMap( int arr[8][8] )
{
   for( int row = 0; row < 8; ++row )
   {
       for( int colum = 0; colum < 8; ++colum )
       {
           map_[row][colum] = arr[row][colum];
       }
   }
}

void Map::DrawMap()
{

    for (int i = 0; i < 8; ++i)
    {
        dest.x = whitePieces[i]->x + 5;
        dest.y = whitePieces[i]->y + 5;
        TextureManager::Draw( PawnW, src ,dest );
    }
    for (int i = 8; i < 10; ++i)
    {
        dest.x = whitePieces[i]->xpos* 60 + 5 + xBoard;
        dest.y = whitePieces[i]->ypos* 60 + 5 + yBoard;
        TextureManager::Draw( RookW, src ,dest );
    }
}

void Map::Delete()
{
    whitePieces.clear();
    whitePieces.shrink_to_fit();
}
