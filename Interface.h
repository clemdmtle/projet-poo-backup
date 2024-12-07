#pragma once
#include "Grille.h"
#include "Fichier.h"

class Interface
{
public:
    Interface();
    virtual void affichageGrille(Grille *g, Fichier* f);
    ~Interface();
};