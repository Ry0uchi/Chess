#include "Pawn.h"

Pawn::Pawn( bool isWhite, Vect2i Bpos)
{
    this->name = PieceName::Pawn;
    this->isWhite = isWhite;
    this->Bpos = Bpos;
    image = new GameObject( isWhite ? "assets/w_pawn_png_1024px.png" : "assets/b_pawn_png_1024px.png" );
    alive = true;
    value = 1;
}
Pawn::~Pawn()
{}

bool Pawn::IsMovementPossible(  Vect2i finalPos )
{
    if( finalPos.X >= 0 && finalPos.Y >= 0 && finalPos.X < 8 && finalPos.Y < 8 && alive )
    {
        int x_movement = abs(finalPos.X - Bpos.X);
        int y_movement = abs(Bpos.Y - finalPos.Y);

        if( y_movement == 1 )
        {
            if (x_movement == 0 || ( x_movement == 1 ) || ( x_movement == -1))
                return true;
        }
        if( (Bpos.Y == 6 && isWhite) || (Bpos.Y == 1 && !isWhite))
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
