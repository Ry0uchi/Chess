
#include "Rook.h"

Rook::Rook( bool isWhite, Vect2f pos )
{
    this->name = PieceName::Rook;
    this->isWhite = isWhite;
    this->pos = pos;
    Bpos.X = static_cast<int>((pos.X - xBoard) / 60);
    Bpos.Y = static_cast<int>((pos.Y - yBoard) / 60);
    alive = true;
    value = 5;
}
Rook::~Rook()
{}

bool Rook::IsMovementPossible( Vect2i finalPos )
{
    if( finalPos.X >= 0 && finalPos.Y >= 0 && finalPos.X < 8 && finalPos.Y < 8 && alive )
    {
        int x_movement = abs(finalPos.X - Bpos.X);
        int y_movement = abs(Bpos.Y - finalPos.Y);

        if( (x_movement == 0 && y_movement != 0) || (x_movement != 0 && y_movement == 0) )
        {
            return true;
        }
    }
    return false;
}

