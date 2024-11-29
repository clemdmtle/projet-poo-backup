#include <string>
#include <iostream>
using namespace std;

class Grille {
    int nbColonnes, nbLignes, nbIteration, dureeIteration, count;

    public:
    Grille(int nbColonnes, int nbLignes, int nbIteration, int dureeIteration){}

    void actualiserGrille();
    void afficherGrille();
    int verifierVoisins();
    bool verifierEtatJeu();
};