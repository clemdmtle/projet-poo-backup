#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H
#include "Interface.h"
#include "Grille.h"
#include "Fichier.h"

class InterfaceGraphique : public Interface{
private:
  int tailleCellule;

public:
  InterfaceGraphique();
  InterfaceGraphique(int tC);
  void affichageGrille(Grille* g, Fichier* f) override;
};

#endif // INTERFACEGRAPHIQUE_H