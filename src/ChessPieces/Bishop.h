#pragma once

#include "Piece.h"

class Bishop : public Piece
{
private:


public:
    Bishop(bool, Vect2i);
    ~Bishop();

    using Piece::GetName;
    using Piece::GetPos;

    bool IsMovementPossible(Vect2i);
};



