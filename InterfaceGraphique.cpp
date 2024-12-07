#include "InterfaceGraphique.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
using namespace sf;

InterfaceGraphique::InterfaceGraphique()
{
  tailleCellule = 10;
}

InterfaceGraphique::InterfaceGraphique(int tC)
    : tailleCellule(tC)
{
}

void InterfaceGraphique::affichageGrille(Grille *g, Fichier *f)
{
  // recuperer le stock via le getter
  const vector<vector<Cellule *>> &grilleAffichee = g->getStock();
  srand(time(0));

  RenderWindow fenetre(VideoMode(g->getNbLignes() * tailleCellule, g->getNbColonnes() * tailleCellule), "Jeu de la Vie");

  fenetre.clear();
  RectangleShape cellule(sf::Vector2f(tailleCellule - 1.0f, tailleCellule - 1.0f));
  for (int i = 0; i < g->getNbLignes(); i++)
  {
    for (int j = 0; j < g->getNbColonnes(); j++)
    {
      if (grilleAffichee[i][j]->getEtatCellule() == true)
      {
        cellule.setPosition(i * tailleCellule, j * tailleCellule);
        fenetre.draw(cellule);
      }
    }
  }
  fenetre.display();
}
