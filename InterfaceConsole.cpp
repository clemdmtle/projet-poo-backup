#include "InterfaceConsole.h"

InterfaceConsole::InterfaceConsole(){}


void InterfaceConsole::affichageGrille(Grille *g, Fichier* f){
    for (auto ligne: g->getStock()){
        for (auto cell: ligne){
            cout << cell; //parcourt chaque cellule et appelle to_char
        }
    }
    f->stockerDonnees(g->getStock());

}
