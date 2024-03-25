#include "Piece.h"

Piece::Piece()
{}

Piece::~Piece()
{}



PieceName Piece::GetName()
{
  return name;
}

int Piece::GetXpos()
{
  return xpos;
}

int Piece::GetYpos()
{
  return ypos;
}


bool Piece::IsMovementPossible( int final_xpos, int final_ypos )
{
  return false;
}


void Piece::SetPosition( int xpos, int ypos )
{
  if( alive )
  {
    this->xpos = xpos;
    this->ypos = ypos;
  }
}


bool Piece::IsAlive()
{
  return alive;
}


void Piece::SetDead()
{
  alive = false;
  this->xpos = -1;
  this->ypos = -1;
}

void Piece::Revive()
{
  alive = true;
}
