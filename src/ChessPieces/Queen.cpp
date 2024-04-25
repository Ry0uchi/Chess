#include "Queen.h"

Queen::Queen( bool isWhite, Vect2i Bpos)
{
    this->name = PieceName::Queen;
    this->isWhite = isWhite;
    this->Bpos = Bpos;
    image = new GameObject( isWhite ? "assets/w_queen_png_1024px.png" : "assets/b_queen_png_1024px.png" );
    alive = true;
    value = 9;
}
Queen::~Queen()
{}

bool Queen::IsMovementPossible( Vect2i finalPos )
{
    if( finalPos.X >= 0 && finalPos.Y >= 0 && finalPos.X < 8 && finalPos.Y < 8 && alive )
    {
        int x_movement = abs(finalPos.X - Bpos.X);
        int y_movement = abs(Bpos.Y - finalPos.Y);

        if( x_movement == y_movement )
        {
            return true;
        }
        else if((x_movement == 0 && y_movement != 0) || (y_movement == 0 && x_movement != 0))
        {
            return true;
        }
    }
    return false;
}
