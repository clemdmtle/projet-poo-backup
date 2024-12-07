#pragma once
#include "Cellule.h"

class CelluleActive : public Cellule{
public:
  CelluleActive(bool etatCellule);

  string getType();
};
