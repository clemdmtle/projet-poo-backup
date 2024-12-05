#include <string>
#include <iostream>
#include <vector>;
#include "Fichier.cpp"
using namespace std;




class Grille {
    private:
    int nbColonnes, nbLignes;
    vector<vector <Cellule*>> Stock;
    vector<vector <Cellule*>> Transition;
    

    public:
    Grille(int nbColonnes, int nbLignes){
        this->nbColonnes=nbColonnes;
        this->nbLignes=nbLignes;
        Stock=vector<vector <Cellule*>>(nbLignes, vector <Cellule*>(nbColonnes, nullptr));
        Transition=vector<vector <Cellule*>>(nbLignes, vector <Cellule*>(nbColonnes, nullptr));

    }

    void setStock(int ligne, int colonne, int etatCellule, int etatPrecedent);
    void setTransition(int ligne, int colonne, int etatCellule, int etatPrecedent);
    int getNbLignes();
    int getNbColonnes();
    void setNbLignes(int nb);
    void setNbColonnes(int nb);
    Cellule* getStock(int ligne, int colonne);
    Cellule* getTransition(int ligne, int colonne);
    bool etatCellule(int l, int c);
    bool etatPrecedent(int l, int c);
};