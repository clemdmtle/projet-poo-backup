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
{ // Permet d'extraire nbcolonnes et nblignes
    vector<int> tab(2); // Initialise un vecteur avec deux éléments
    ifstream fichier(path.c_str(), ios::in); // Ouvre le fichier
    string strChiffre;

    if (fichier)
    {
        cout << "Fichier ouvert avec succès" << endl;

        for (int x = 0; x < 2; x++)
        {
            if (getline(fichier, strChiffre, ' '))
            {
                try
                {
                    tab[x] = stoi(strChiffre); // Convertit la chaîne en entier
                }
                catch (const invalid_argument &e)
                {
                    cerr << "Erreur : données invalides dans le fichier." << endl;
                    return {}; // Retourne un vecteur vide
                }
                catch (const out_of_range &e)
                {
                    cerr << "Erreur : valeur hors plage dans le fichier." << endl;
                    return {}; // Retourne un vecteur vide
                }
            }
            else
            {
                cerr << "Erreur : données insuffisantes dans le fichier." << endl;
                return {}; // Retourne un vecteur vide
            }
        }

        fichier.close(); // Ferme le fichier
    }
    else
    {
        cerr << "Erreur à l'ouverture du fichier" << endl;
        return {}; // Retourne un vecteur vide
    }

    return tab;
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