
#include "Piece.h"

class Pawn : public Piece
{
private:

    bool enemy_diagonal_left = false;
    bool enemy_diagonal_right = false;

public:
    Pawn(bool, Vect2i);
    ~Pawn();

    using Piece::GetName;
    using Piece::GetPos;

    bool IsMovementPossible(Vect2i);
};

