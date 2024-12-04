#include <string>
#include <iostream>
using namespace std;

class Grille {
    private:
    Cellule** Transition[][];
    Cellule** Stock[][];
    int nbColonnes, nbLignes;

    public:
    Grille(int nbColonnes, int nbLignes){
        this->nbColonnes=nbColonnes;
        this->nbLignes=nbLignes;
        Stock[nbColonnes][nbLignes];
        Transition[nbColonnes][nbLignes];

    }

    void setStock(int ligne, int colonne, int etatCellule, int etatPrecedent);
    void setTransition(int ligne, int colonne, int etatCellule, int etatPrecedent);
    int getNbLignes();
    int getNbColonnes();
};