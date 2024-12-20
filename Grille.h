#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Fichier.h"
#include "Cellule.h"
#include "Interface.h"
class Interface;

class Grille
{
private:
    int nbColonnes, nbLignes;
    vector<vector<Cellule *>> Stock;
    vector<vector<Cellule *>> Transition;
    vector<Interface *> observers;

public:
    Grille();
    Grille(int nbLignes, int nbColonnes);
    void setStock(int ligne, int colonne, Cellule *c1);
    void setTransition(int ligne, int colonne, Cellule *c1);
    int getNbLignes();
    int getNbColonnes();
    void setNbLignes(int nb);
    void setNbColonnes(int nb);
    vector<vector<Cellule *>> getStock();
    Cellule *getCelluleStock(int ligne, int colonne);
    Cellule *getCelluleTransition(int ligne, int colonne);
    bool etatCellule(int l, int c);
    bool etatPrecedent(int l, int c);
    void addObservers(Interface *inter);
    void removeObservers(Interface *inter);
    void notify(Fichier *f);
};
