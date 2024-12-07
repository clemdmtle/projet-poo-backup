#pragma once
#include "Grille.h"

class Interface
{
public:
    Interface();
    virtual void affichageGrille(Grille *g, Fichier *f) = 0;
    virtual ~Interface();
};