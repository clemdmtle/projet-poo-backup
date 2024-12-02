#ifndef CELLULEOBSTACLE_H
#define CELLULEOBSTACLE_H
#include "Cellule.h"

class CelluleObstacle : public Cellule
{
public:
  CelluleObstacle(bool ec);
  bool changementEtat() override;
};

#endif CELLULEOBSTACLE_H