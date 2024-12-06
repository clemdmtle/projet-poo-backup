#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Fichier.h"
#include "Cellule.h"

using namespace std;

class Grille
{
private:
    int nbColonnes, nbLignes;
    vector<vector<Cellule *>> Stock;
    vector<vector<Cellule *>> Transition;

public:
    Grille();
    Grille(int nbColonnes, int nbLignes)
    {
        this->nbColonnes = nbColonnes;
        this->nbLignes = nbLignes;
        Stock = vector<vector<Cellule *>>(nbLignes, vector<Cellule *>(nbColonnes, nullptr));
        Transition = vector<vector<Cellule *>>(nbLignes, vector<Cellule *>(nbColonnes, nullptr));
    }

    void setStock(int ligne, int colonne, int etatCellule, int etatPrecedent);
    void setTransition(int ligne, int colonne, int etatCellule, int etatPrecedent);
    int getNbLignes();
    int getNbColonnes();
    void setNbLignes(int nb);
    void setNbColonnes(int nb);
    vector<vector<Cellule *>> getStock();
    Cellule *getCelluleStock(int ligne, int colonne);
    Cellule *getCelluleTransition(int ligne, int colonne);
    bool etatCellule(int l, int c);
    bool etatPrecedent(int l, int c);
};
