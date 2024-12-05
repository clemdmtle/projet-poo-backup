#include "Grille.h"

void Grille::setStock(int ligne, int colonne, int etatCellule, int etatPrecedent){
    Stock[ligne][colonne].setEtatCellule(etatCellule);
    Stock[ligne][colonne].setEtatPrecedent(etatPrecedent);
}

void Grille::setTransition(int ligne, int colonne, int etatCellule, int etatPrecedent){
    Transition[ligne][colonne].setEtatCellule(etatCellule);
    Transition[ligne][colonne].setEtatPrecedent(etatPrecedent);
}

Cellule* Grille::getStock(int ligne, int colonne){
    return Stock[ligne][colonne];
}

Cellule* Grille::getTransition(int ligne, int colonne){
    return Transition[ligne][colonne];
}

int Grille::getNbLignes(){
    return nbLignes;
}

int Grille::getNbColonnes(){
    return nbColonnes;
}

void Grille::setNbLignes(int nb){
    nbLignes=nb;
}

void Grille::setNbColonnes(int nb){
    nbColonnes=nb;
}