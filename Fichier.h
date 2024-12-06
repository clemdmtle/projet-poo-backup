#pragma once
#include <string>
using namespace std;

class Fichier
{
private:
    string path;

public:
    Fichier(string path) {}

    void stockerDonnees(vector <Cellule*> vect);
    void creerFichier();
    void lireFichier();
    auto initGrille(int nbLignes, int nbColonnes);
    void initCellule();
};