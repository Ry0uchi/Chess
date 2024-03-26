#pragma once

#include "../src/Piece.h"

class Rook : public Piece
{
private:

    bool enemy_up = false;
    bool enemy_right = false;
    bool enemy_left = false;

public:
    Rook(bool, int, int );
    ~Rook();

    using Piece::GetName;
    using Piece::GetXpos;
    using Piece::GetYpos;

    bool IsMovementPossible(int, int);
};


