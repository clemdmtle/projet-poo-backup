#include "Fichier.cpp"

class ActualiserJeu {
    public:
    int verifierVoisins(int l, int c, Grille *g);
    bool verifierEtatJeu(Grille *g);
    void actualiserGrille(Grille *g);
    bool changementEtat(int l, int c, Grille *g);
};