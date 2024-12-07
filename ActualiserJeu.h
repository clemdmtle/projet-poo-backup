#pragma once
#include "Fichier.h"

class ActualiserJeu {
    public:
    int verifierVoisins(int l, int c, Grille *g);
    bool verifierEtatJeu(Grille *g, JeuDeLaVie* jdlv);
    void actualiserGrille(Grille *g, JeuDeLaVie* jdlv);
    void changementEtat(int l, int c, Grille *g);
};