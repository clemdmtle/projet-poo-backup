#pragma once
#include "Fichier.h"

class ActualiserJeu {
    public:
    int verifierVoisins(int l, int c, Grille *g);
    bool verifierEtatJeu(Grille *g);
    void actualiserGrille(Grille *g);
    void changementEtat(int l, int c, Grille *g);
};