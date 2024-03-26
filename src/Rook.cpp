
#include "../header/Rook.h"

Rook::Rook( bool isWhite, int xpos, int ypos )
{
    this->name = PieceName::Rook;
    this->isWhite = isWhite;
    this->xpos = xpos;
    this->ypos = ypos;
    alive = true;
    value = 5;
}
Rook::~Rook()
{}

bool Rook::IsMovementPossible( int final_x, int final_y )
{
    if( final_x >= 0 && final_y >= 0 && final_x < 8 && final_y < 8 && alive )
    {
        int movement_x = abs(final_x - xpos);
        int movement_y = abs(final_y - ypos);

        if( ( movement_x == 0 || movement_y == 0 ) && movement_x != movement_y )
        {
            return true;
        }
    }

    return false;
}


