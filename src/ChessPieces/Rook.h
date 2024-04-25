#pragma once

#include "Piece.h"

class Rook : public Piece
{
private:

    bool enemy_up = false;
    bool enemy_down = false;
    bool enemy_right = false;
    bool enemy_left = false;

public:
    Rook(bool, Vect2i);
    ~Rook();

    using Piece::GetName;
    using Piece::GetPos;

    bool IsMovementPossible(Vect2i);
};


