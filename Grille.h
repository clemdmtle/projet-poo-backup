#include <string>
#include <iostream>
using namespace std;




class Grille {
    private:
    int nbColonnes, nbLignes;
    Cellule*** Stock[nbLignes][nbColonnes];
    Cellule** Transition[nbLignes][nbColonnes];
    

    public:
    Grille(int nbColonnes, int nbLignes){
        this->nbColonnes=nbColonnes;
        this->nbLignes=nbLignes;
        Cellule** Stock[nbColonnes][nbLignes];
        Cellule** Transition[nbColonnes][nbLignes];

    }

    void setStock(int ligne, int colonne, int etatCellule, int etatPrecedent);
    void setTransition(int ligne, int colonne, int etatCellule, int etatPrecedent);
    int getNbLignes();
    int getNbColonnes();
    void setNbLignes(int nb);
    void setNbColonnes(int nb);
    Cellule* getStock(int ligne, int colonne);
    Cellule* getTransition(int ligne, int colonne);
    bool EtatCellule(int l, int c);
    bool EtatPrecedent(int l, int c);
};