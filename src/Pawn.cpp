#include "Pawn.h"

Pawn::Pawn( bool isWhite, int xpos, int ypos )
{
    this->name = PieceName::Pawn;
    this->isWhite = isWhite;
    this->xpos = xpos;
    this->ypos = ypos;
    alive = true;
    value = 1;
}
Pawn::~Pawn()
{}

bool Pawn::IsMovementPossible( int final_xpos, int final_ypos )
{
    if( final_xpos >= 0 && final_ypos >= 0 && final_xpos < 8 && final_ypos < 8 && alive )
    {
        int x_movement = final_xpos - xpos;
        int y_movement = ypos - final_ypos;

        if( y_movement == 1 )
        {
            if (x_movement == 0 || ( x_movement == 1 && enemy_diagonal_right ) || ( x_movement == -1 && enemy_diagonal_right ))
                return true;
        }
        if( ypos == 1 )
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
