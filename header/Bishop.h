#pragma once

#include "../src/Piece.h"

class Bishop : public Piece
{
private:


public:
    Bishop(bool, int, int );
    ~Bishop();

    using Piece::GetName;
    using Piece::GetXpos;
    using Piece::GetYpos;

    bool IsMovementPossible(int, int);
};



