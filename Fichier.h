#pragma once
#include <string> 
#include "Cellule.h"
using namespace std;

class Fichier {
    string path;

    public:
    Fichier(string path){}

    void stockerDonnees(vector<vector<Cellule*>> vect);
    string to_char(Cellule* c2);
    int* lireFichier();
};
