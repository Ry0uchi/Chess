#include "../header/Bishop.h"

Bishop::Bishop( bool isWhite, int xpos, int ypos )
{
    this->name = PieceName::Bishop;
    this->isWhite = isWhite;
    this->xpos = xpos;
    this->ypos = ypos;
    alive = true;
    value = 3;
}
Bishop::~Bishop()
{}

bool Bishop::IsMovementPossible( int final_x, int final_y )
{
    if( final_x >= 0 && final_y >= 0 && final_x < 8 && final_y < 8 && alive )
    {
        int movement_x = abs(final_x - xpos);
        int movement_y = abs(final_y - ypos);

        if(movement_x == movement_y && movement_x > 0)
        {
            return true;
        }
    }

    return false;
}


