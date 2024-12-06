#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H
#include "Interface.h"


class InterfaceGraphique : public Interface
{
private:
  int tailleCellule;

public:
  InterfaceGraphique();
  InterfaceGraphique(int tC);
  void initialisationGrille(Grille *g) override;
  void affichageGrille(Grille *g) override;
};

#endif // INTERFACEGRAPHIQUE_H