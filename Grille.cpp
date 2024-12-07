#include "Grille.h"
#include <algorithm>
#include "Interface.h"

Grille::Grille()
{
    nbColonnes = 40;
    nbLignes = 40;
    Stock = vector<vector<Cellule *>>(nbLignes, vector<Cellule *>(nbColonnes, nullptr));
    Transition = vector<vector<Cellule *>>(nbLignes, vector<Cellule *>(nbColonnes, nullptr));
}

Grille::Grille(int nbColonnes, int nbLignes)
{
    this->nbColonnes = nbColonnes;
    this->nbLignes = nbLignes;
    Stock = vector<vector<Cellule *>>(nbLignes, vector<Cellule *>(nbColonnes, nullptr));
    Transition = vector<vector<Cellule *>>(nbLignes, vector<Cellule *>(nbColonnes, nullptr));
}

void Grille::setStock(int ligne, int colonne, Cellule *c)
{ // permet de changer la cellule dans le vecteur stock
    Stock[ligne][colonne] = c;
}

void Grille::setTransition(int ligne, int colonne, Cellule *c)
{ // change la cellule dans le vecteur transition
    Transition[ligne][colonne] = c;
}

vector<vector<Cellule *>> Grille::getStock()
{ // retourne le tab stock
    return Stock;
}

Cellule *Grille::getCelluleStock(int ligne, int colonne)
{ // donne un objet cellule à un index du vecteur
    return Stock[ligne][colonne];
}

Cellule *Grille::getCelluleTransition(int ligne, int colonne)
{ // pareil pour transition
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
{                                  // donne l'état d'une cellule à un index du vecteur
    l = (l + nbLignes) % nbLignes; // les modulos permettent de rendre la grille torique
    c = (c + nbColonnes) % nbColonnes;
    bool etat = Stock[l][c]->getEtatCellule();
    return etat;
}

bool Grille::etatPrecedent(int l, int c)
{ // donne l'étatP d'une cellule à un index du vecteur
    l = (l + nbLignes) % nbLignes;
    c = (c + nbColonnes) % nbColonnes;
    bool etat = Stock[l][c]->getEtatPrecedent();
    return etat;
}

void Grille::addObservers(Interface *inter)
{
    observers.push_back(inter);
}

void Grille::removeObservers(Interface *inter)
{
    observers.erase(remove(observers.begin(), observers.end(), inter), observers.end());
}
void Grille::notify(Fichier *f)
{
    for (Interface *inter : observers)
    {
        inter->affichageGrille(this, f);
    }
}