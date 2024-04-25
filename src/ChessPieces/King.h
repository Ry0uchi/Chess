#pragma once

#include "Piece.h"

class King : public Piece
{
private:

    bool enemy_up = false;
    bool enemy_down = false;
    bool enemy_right = false;
    bool enemy_left = false;
    bool enemy_diagonal_left = false;
    bool enemy_diagonal_right = false;

public:

    King(bool, Vect2i );
    ~King();

    using Piece::GetName;
    using Piece::GetPos;
    bool IsMovementPossible(Vect2i);
};