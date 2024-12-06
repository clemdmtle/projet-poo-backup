#pragma once
#include "Grille.h"

void Grille::setStock(int ligne, int colonne, int etatCellule, int etatPrecedent){
    Stock[ligne][colonne]->setEtatCellule(etatCellule);
    Stock[ligne][colonne]->setEtatPrecedent(etatPrecedent);
}

void Grille::setTransition(int ligne, int colonne, int etatCellule, int etatPrecedent){
    Transition[ligne][colonne]->setEtatCellule(etatCellule);
    Transition[ligne][colonne]->setEtatPrecedent(etatPrecedent);
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

bool Grille::etatCellule(int l, int c){
    l=(l+nbLignes)%nbLignes;
    c=(c+nbColonnes)%nbColonnes;
    bool etat=getStock(l,c)->getEtatCellule();
}

bool Grille::etatPrecedent(int l, int c){
    l=(l+nbLignes)%nbLignes;
    c=(c+nbColonnes)%nbColonnes;
    bool etat=getStock(l,c)->getEtatPrecedent();
}