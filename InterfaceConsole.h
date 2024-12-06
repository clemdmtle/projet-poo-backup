#pragma once
#include "Interface.h"

class InterfaceConsole : public Interface
{
private:
public:
    InterfaceConsole();
    void initialisationGrille(Grille *g) override;
    void affichageGrille(Grille *g) override;
};
