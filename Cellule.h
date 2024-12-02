#ifndef CELLULE_H
#define CELLULE_H

class Cellule
{
protected:
  bool etatCellule;

public:
  Cellule();
  Cellule(bool ec);
  bool getEtatCellule();
  void setEtatCellule(bool e);
  virtual bool changementEtat();
  virtual ~Cellule();
};

#endif CELLULE_H