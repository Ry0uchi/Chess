#include "Pawn.h"

Pawn::Pawn( bool isWhite, Vect2f pos)
{
    this->name = PieceName::Pawn;
    this->isWhite = isWhite;
    this->pos = pos;
    Bpos.X = static_cast<int>((pos.X - xBoard) / 60);
    Bpos.Y = static_cast<int>((pos.Y - yBoard) / 60);
    alive = true;
    value = 1;
}
Pawn::~Pawn()
{}

bool Pawn::IsMovementPossible(  Vect2i finalPos )
{
    if( finalPos.X >= 0 && finalPos.Y >= 0 && finalPos.X < 8 && finalPos.Y < 8 && alive )
    {
        int x_movement = finalPos.X - Bpos.X;
        int y_movement = Bpos.X - finalPos.Y;

        if( y_movement == 1 )
        {
            if (x_movement == 0 || ( x_movement == 1 && enemy_diagonal_right ) || ( x_movement == -1 && enemy_diagonal_right ))
                return true;
        }
        if( Bpos.Y == 1 )
        {
            if( y_movement == 2 && x_movement == 0 )
            {
            return true;
            }
        }
        return false;
    }
    return false;
}
