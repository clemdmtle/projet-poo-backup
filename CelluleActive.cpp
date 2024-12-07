#include "CelluleActive.h"

CelluleActive::CelluleActive(bool ec)
{
  this->etatCellule = ec;
  this->etatPrecedent = 0;
}

string CelluleActive::getType(){
  return "Active";
}