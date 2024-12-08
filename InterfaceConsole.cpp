#include "InterfaceConsole.h"

InterfaceConsole::InterfaceConsole() {}

void InterfaceConsole::affichageGrille(Grille *g, Fichier *f)
{
  cout << "Début de l'affichage" << endl;
  for (int i = 0; i<g->getNbLignes(); i++){
    for (int j=0; j<g->getNbColonnes(); j++){
      cout << f->to_char(g->getCelluleStock(i,j)) << " ";
    }
    cout << endl;
  }
  f->stockerDonnees(g->getStock());
  cout << "Fin de l'affichage" << endl;
}
