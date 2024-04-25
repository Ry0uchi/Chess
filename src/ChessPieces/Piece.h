#pragma once
#include <math.h>
#include "../Vect2D.h"
#include "../GameObject.h"

enum class PieceName {Empty , Pawn , Knight , Bishop , Rook , Queen , King};

const int xBoard = 385 + 20*3/4;
const int yBoard = 105 + 22*3/4;

class Piece
{
public:
    Piece();
    ~Piece();
    PieceName name = PieceName::Empty;
    bool isWhite = false;
    bool alive = false;
    Vect2i Bpos;
    int value = -1;
    GameObject* image;
    bool isChoose = false;


    PieceName GetName();

    Vect2i GetPos();

    virtual bool IsMovementPossible(Vect2i);

    void SetPosition(Vect2i);

    bool IsAlive();
    void Revive();
    void SetDead();
};
