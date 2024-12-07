#pragma once
#include <string>
#include "Cellule.h"
#include <vector>
using namespace std;

class Fichier
{
    string path;

public:
    Fichier(string path);
    void stockerDonnees(vector<vector<Cellule *>> vect);
    string to_char(Cellule *c2);
    vector<int> lireFichier();
};
