#include "Piece.h"

Piece::Piece()
{}

Piece::~Piece()
{}



PieceName Piece::GetName()
{
  return name;
}

Vect2i Piece::GetPos()
{
  return Bpos;
}


bool Piece::IsMovementPossible( Vect2i FinalPos )
{
  return false;
}


void Piece::SetPosition( Vect2i Bpos)
{
  if( alive )
  {
    this->Bpos = Bpos;
  }
}


bool Piece::IsAlive()
{
  return alive;
}


void Piece::SetDead()
{
  alive = false;
  Bpos.X = -100;
  Bpos.Y = -100;
  image->UpdateChessPiece(-100, -100);
}

void Piece::Revive()
{
  alive = true;
}
