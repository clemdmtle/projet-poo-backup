#pragma once
#include "Cellule.h"

class CelluleActive : public Cellule
{
private:
  bool etatPrecedent;

public:
  CelluleActive(bool etatCellule);
  bool getEtatPrecedent();
  void setEtatPrecedent(bool e);
};
