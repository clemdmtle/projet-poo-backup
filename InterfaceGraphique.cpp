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


void InterfaceGraphique::affichageGrille(Grille* g, Fichier* f) {
    sf::RenderWindow window(sf::VideoMode(g->getNbLignes() * tailleCellule, g->getNbColonnes() * tailleCellule), "Game of Life");

    // Crée une instance de sf::RectangleShape avant les boucles pour éviter de la recréer à chaque itération
    sf::RectangleShape cell(sf::Vector2f(tailleCellule - 1.0f, tailleCellule - 1.0f));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Ferme la fenêtre si l'utilisateur clique sur la croix
            }
        }

        window.clear();  // Vide la fenêtre avant de redessiner

        // Parcourt chaque cellule de la grille
        for (int x = 0; x < g->getNbLignes(); ++x) {
            for (int y = 0; y < g->getNbColonnes(); ++y) {
                if (g->etatCellule(x, y)) {  // Si la cellule est vivante
                    cell.setPosition(x * tailleCellule, y * tailleCellule);
                    window.draw(cell);  // Dessine la cellule sur la fenêtre
                }
            }
        }

        window.display();  // Affiche le contenu de la fenêtre
    }
}
