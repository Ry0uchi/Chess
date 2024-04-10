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


void Piece::SetPosition( int x, int y )
{
  if( alive )
  {
    pos.X = x;
    pos.Y = y;
    Bpos.X = (int)(x - xBoard + 30) / 60;
    Bpos.Y = (int)(y - yBoard + 30) / 60;
  }
}


bool Piece::IsAlive()
{
  return alive;
}


void Piece::SetDead()
{
  alive = false;
  Bpos.X = -1;
  Bpos.Y = -1;
  pos.X = -100;
  pos.Y = -100;
}

void Piece::Revive()
{
  alive = true;
}
