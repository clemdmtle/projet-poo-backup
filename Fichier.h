#pragma once
#include <string> 

class Fichier {
    string path;

    public:
    Fichier(string path){}

    void stockerDonnees(vector<vector<Cellule*>> vect);
    string to_char(Cellule* c2);
    int* lireFichier();
};
