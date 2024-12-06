#include "CelluleActive.h"

CelluleActive::CelluleActive(bool ec)
{
  this->etatCellule = ec;
  this->etatPrecedent = 0;
}
bool CelluleActive::getEtatPrecedent()
{
  return etatPrecedent;
}

void CelluleActive::setEtatPrecedent(bool ep)
{
  etatPrecedent = ep;
}
