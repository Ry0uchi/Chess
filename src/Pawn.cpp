#include "Pawn.h"
const int xBoard = 385 + 20*3/4;
const int yBoard = 105 + 22*3/4;

Pawn::Pawn( bool isWhite, int x, int y )
{
    this->name = PieceName::Pawn;
    this->isWhite = isWhite;
    this->x = x;
    this->y = y;
    xpos = (x - 5 - xBoard) / 60;
    ypos = (y - 5 - yBoard) / 60;
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
