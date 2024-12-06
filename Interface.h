#pragma once
#include "Grille.h"

class Interface
{
public:
    Interface();
    virtual void initialisationGrille(Grille *g);
    virtual void affichageGrille(Grille *g);
    ~Interface();
};