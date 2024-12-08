#pragma once
#include "Fichier.h"
#include "Grille.h"
#include "JeuDeLaVie.h"

class ActualiserJeu {
    public:
    void verifierVoisins(int l, int c, Grille *g);
    bool verifierEtatJeu(Grille *g, JeuDeLaVie* jdlv);
    void actualiserGrille(Grille *g, JeuDeLaVie* jdlv, Fichier* f);
    void changementEtat(int l, int c, Grille *g);
};