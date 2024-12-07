#pragma once
#include "Fichier.h"
#include "Grille.cpp"

class Interface
{
public:
    Interface();
    virtual void affichageGrille(Grille *g, Fichier* f);
    ~Interface();
};