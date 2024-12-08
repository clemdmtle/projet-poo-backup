#pragma once
#include "Fichier.h"
#include "Grille.h"

class Grille;
class Fichier;

class Interface
{
public:
    Interface();
    virtual void affichageGrille(Grille *g, Fichier *f);
    ~Interface();
};