#include "Fichier.h"
#include <fstream>
#include <fstream>
#include <string>
#include <iostream>
#include "Cellule.h"
#include "Grille.h"
#include "CelluleActive.h"
using namespace std;

int a = 0;
string contenu = "";
Fichier::Fichier(string path)
{
    this->path = path;
}

vector<int> Fichier::lireFichier()
{ // permet d'extraire nbcolonnes et nblignes
    
    ifstream fichier(path.c_str(), ios::in); // ouvre le fichier
    string nbLignes, nbColonnes;

    if (fichier)
    {
        cout << "Fichier ouvert avec succès" << endl;
        getline(fichier, nbLignes, ' ');
        getline(fichier, nbColonnes, ' ');
        vector<int> tab={stoi(nbLignes), stoi(nbColonnes)};
         // change le string en int

        fichier.close(); // ferme le fichier
        return tab;
    }
    else
    {
        cerr << "Erreur à l'ouverture du fichier" << endl;
    }
    return {};
}

void Fichier::stockerDonnees(vector<vector<Cellule *>> vect)
{ // permet de stocker une grille dans un fichier
    ofstream fichierSortie;

    string nom_fichier = "<" + path + ">" + "_out_" + to_string(a); // on pose le nom du fichier
    fichierSortie.open(nom_fichier.c_str(), ios::out);              // on ouvre en écriture

    if (fichierSortie)
    {
        for (auto ligne : vect)
        {
            for (auto cell : ligne)
            {
                fichierSortie << to_char(cell); // parcourt chaque cellule et appelle to_char
            }
        }
        fichierSortie.close(); // on ferme le fichier
        a++;
    }
    else
    {
        cerr << "Erreur à l'ouverture du fichier en écriture" << endl;
    }
}

string Fichier::to_char(Cellule *c2)
{ // pour changer un bool en string (pour l'état d'une cellule)
    string str;
    if (c2->getEtatCellule() == true)
    {
        str = "1";
    }
    else
    {
        str = "0";
    }
    return str;
}