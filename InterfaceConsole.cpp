#include "InterfaceConsole.h"

InterfaceConsole::InterfaceConsole() {}

void InterfaceConsole::affichageGrille(Grille *g, Fichier *f)
{
  for (int i = 0; i<g->getNbLignes(); i++){
    for (int j=0; j<g->getNbColonnes(); j++){
      cout << f->to_char(g->getCelluleStock(i,j)) << " ";
    }
    cout << endl;
  }
  f->stockerDonnees(g->getStock());
}
