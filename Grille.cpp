#include "Grille.h"

void Grille::setStock(int ligne, int colonne, Cellule *c)
{
    Stock[ligne][colonne] = c;
}

void Grille::setTransition(int ligne, int colonne, Cellule *c)
{
    Transition[ligne][colonne] = c;
}

vector<vector<Cellule *>> Grille::getStock()
{
    return Stock;
}

Cellule *Grille::getCelluleStock(int ligne, int colonne)
{
    return Stock[ligne][colonne];
}

Cellule *Grille::getCelluleTransition(int ligne, int colonne)
{
    return Transition[ligne][colonne];
}

int Grille::getNbLignes()
{
    return nbLignes;
}

int Grille::getNbColonnes()
{
    return nbColonnes;
}

void Grille::setNbLignes(int nb)
{
    nbLignes = nb;
}

void Grille::setNbColonnes(int nb)
{
    nbColonnes = nb;
}

bool Grille::etatCellule(int l, int c)
{
    l = (l + nbLignes) % nbLignes;
    c = (c + nbColonnes) % nbColonnes;
    bool etat = Stock[l][c]->getEtatCellule();
    return etat;
}

bool Grille::etatPrecedent(int l, int c)
{
    l = (l + nbLignes) % nbLignes;
    c = (c + nbColonnes) % nbColonnes;
    bool etat = Stock[l][c]->getEtatPrecedent();
    return etat;
}