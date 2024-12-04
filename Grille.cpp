#include "Grille.h"

void setStock(int ligne, int colonne, int etatCellule, int etatPrecedent){
    Stock[ligne][colonne].setEtatCellule(etatCellule);
    Stock[ligne][colonne].setEtatPrecedent(etatPrecedent);
}

void setTransition(int ligne, int colonne, int etatCellule, int etatPrecedent){
    Transition[ligne][colonne].setEtatCellule(etatCellule);
    Transition[ligne][colonne].setEtatPrecedent(etatPrecedent);
}

int getNbLignes(){
    return nbLignes;
}

int getNbColonnes(){
    return nbColonnes;
}