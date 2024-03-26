#include "Piece.h"

const int xBoard = 385 + 20*3/4;
const int yBoard = 105 + 22*3/4;


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


void Piece::SetPosition( int x, int y )
{
  if( alive )
  {
    this->x = x - 30;
    this->y = y - 30;
    xpos = (x - xBoard) / 60;
    ypos = (y - yBoard) / 60;
  }
}


bool Piece::IsAlive()
{
  return alive;
}


void Piece::SetDead()
{
  alive = false;
  this->x = -1;
  this->y = -1;
}

void Piece::Revive()
{
  alive = true;
}
