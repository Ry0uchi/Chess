#include "Bishop.h"

Bishop::Bishop( bool isWhite, Vect2i Bpos )
{
    this->name = PieceName::Bishop;
    this->isWhite = isWhite;
    this->Bpos = Bpos;
    alive = true;
    image = new GameObject( isWhite ? "assets/w_bishop_png_1024px.png" : "assets/b_bishop_png_1024px.png" );
    value = 3;
}
Bishop::~Bishop()
{}

bool Bishop::IsMovementPossible( Vect2i finalPos )
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


