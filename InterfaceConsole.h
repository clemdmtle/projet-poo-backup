#pragma once
#include "Interface.h"

class InterfaceConsole : public Interface
{
private:
public:
    InterfaceConsole();
    void affichageGrille(Grille *g, Fichier* f) override;
};
