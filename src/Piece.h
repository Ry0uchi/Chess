#pragma once

enum class PieceName {Empty , Pawn , Knight , Bishop , Rook , Queen , King};

class Piece
{
public:
    Piece();
    ~Piece();
    PieceName name = PieceName::Empty;
    bool isWhite = false;
    bool alive = false;
    int xpos = -1;
    int ypos = -1;
    int value = -1;

    PieceName GetName();

    int GetXpos();
    int GetYpos();

    virtual bool IsMovementPossible(int, int);

    void SetPosition(int, int);

    bool IsAlive();
    void Revive();
    void SetDead();
};
