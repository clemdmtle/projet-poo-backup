#include "CelluleObstacle.h"

CelluleObstacle::CelluleObstacle(bool ec)
{
  this->etatCellule = ec;
  etatPrecedent = false;
}

string CelluleObstacle::getType(){
  return "Obstacle";
}