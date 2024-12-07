#pragma once
#include "Interface.h"
#include "Grille.h"
#include "Fichier.h"

class InterfaceConsole : public Interface
{
private:
public:
    InterfaceConsole();
    void affichageGrille(Grille *g, Fichier* f) override;
};
