#include "Knight.h"

Knight::Knight( bool isWhite, Vect2i Bpos )
{
    this->name = PieceName::Knight;
    this->isWhite = isWhite;
    this->Bpos = Bpos;
    image = new GameObject( isWhite ? "assets/w_knight_png_1024px.png" : "assets/b_knight_png_1024px.png" );
    alive = true;
    value = 3;
}
Knight::~Knight()
{}

bool Knight::IsMovementPossible( Vect2i finalPos )
{
    if( finalPos.X >= 0 && finalPos.Y >= 0 && finalPos.X < 8 && finalPos.Y < 8 && alive )
    {
        int x_movement = abs(finalPos.X - Bpos.X);
        int y_movement = abs(Bpos.Y - finalPos.Y);

        if( (x_movement == 2 && y_movement == 1) || (x_movement == 1 && y_movement == 2) )
        {
            std::cout<<"Knight Movement Possible\n";
            return true;
        }
    }
    std::cout<<"Knight Movement Not Possible\n";
    return false;
}
