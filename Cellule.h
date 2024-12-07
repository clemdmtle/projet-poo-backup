#ifndef CELLULE_H
#define CELLULE_H
#include <string> 
#include <iostream>
using namespace std;

class Cellule
{
protected:
  bool etatCellule;
  bool etatPrecedent;

public:
  Cellule();
  Cellule(bool ec);
  virtual bool getEtatCellule();
  virtual void setEtatCellule(bool e);
  virtual bool getEtatPrecedent();
  virtual void setEtatPrecedent(bool etatP);
  virtual string getType();
  virtual ~Cellule();
};

#endif //CELLULE_H