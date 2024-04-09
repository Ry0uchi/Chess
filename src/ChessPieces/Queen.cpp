#include "Queen.h"

Queen::Queen( bool isWhite, Vect2f pos)
{
    this->name = PieceName::Queen;
    this->isWhite = isWhite;
    this->pos = pos;
    Bpos.X = static_cast<int>((pos.X - xBoard) / 60);
    Bpos.Y = static_cast<int>((pos.Y - yBoard) / 60);
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
        return false;
    }
    return false;
}
