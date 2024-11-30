#ifndef CELLULEACTIVE_H
#define CELLULEACTIVE_H
#include "Cellule.h"

class CelluleActive : public Cellule
{
private:
  bool etatPrecedent;

public:
  CelluleActive(bool etatCellule);
  bool getEtatPrecedent();
  void setEtatPrecedent(bool e);
  bool changementEtat() override;
};

#endif CELLULEACTIVE_H