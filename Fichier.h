#pragma once
#include <string>
using namespace std;

class Fichier
{
private:
    string path;

public:
    Fichier(string path) {}

    void stockerDonnees();
    void creerFichier();
    void lireFichier();
    auto initGrille();
    void initCellule();
};