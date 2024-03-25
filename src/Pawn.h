
#include "Piece.h"

class Pawn : public Piece
{
private:

    bool enemy_diagonal_left = false;
    bool enemy_diagonal_right = false;

public:
    Pawn(bool, int, int );
    ~Pawn();

    using Piece::GetName;
    using Piece::GetXpos;
    using Piece::GetYpos;

    bool IsMovementPossible(int, int);
};

