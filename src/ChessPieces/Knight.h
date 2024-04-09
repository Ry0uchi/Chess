#pragma once

#include "Piece.h"

class Knight : public Piece
{
private:

public:
    Knight(bool, Vect2f);
    ~Knight();

    using Piece::GetName;
    using Piece::GetPos;

    bool IsMovementPossible(Vect2i);
};


