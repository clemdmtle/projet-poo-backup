#include "Fichier.h"
#include <fstream>
#include <fstream>
#include <string>
#include <iostream>
#include "Cellule.h"
#include "Grille.h"
#include "CelluleActive.h"
#include "Cellule.cpp"
#include "Grille.h"
#include "Grille.cpp"
#include "CelluleActive.cpp"
using namespace std;

int a = 0;
string contenu = "";

void Fichier::stockerDonnees()
{
    ofstream fichier;

    // on ouvre en écriture à la suite
    fichier.open(path.c_str(), ios::out | ios::app);

    if (fichier)
    {
        // rentrer la grille
        fichier.close(); // on ferme le fichier
    }
    else
    {
        cerr << "Erreur à l'ouverture du fichier en écriture" << endl;
    }
}

void Fichier::lireFichier()
{
    ifstream fichier(path.c_str(), ios::in); // ouvre le fichier
    string strChiffre;
    Fichier::lireFichier()
    {
        int tab[2];
        ifstream fichier(path.c_str(), ios::in); // ouvre le fichier
        string strChiffre;

        if (fichier)
        {
            cout << "Fichier ouvert avec succès" << endl;
            while (getline(fichier, strChiffre, ' '))
            {                                   // lit le contenu
                contenu = contenu + strChiffre; // stocke tout dans un tableau
                cout << contenu;
            }
            cout << endl;
            int nbLignes = stoi(contenu);
            contenu = "";

            while (getline(fichier, strChiffre, ' '))
            {                                   // lit le contenu
                contenu = contenu + strChiffre; // stocke tout dans un tableau
                cout << contenu;
            }
            cout << endl;
            int nbColonnes = stoi(contenu);
            contenu = "";
            if (fichier)
            {
                cout << "Fichier ouvert avec succès" << endl;
                for (int x = 0; x < 2; x++)
                {
                    getline(fichier, strChiffre, ' ');
                    tab[x] = stoi(strChiffre);
                }

                fichier.close(); // ferme le fichier
            }
            else
            {
                cerr << "Erreur à l'ouverture du fichier" << endl;
            }
        }

        auto Fichier::initGrille()
        {
            Grille *Fichier::initGrille(int nbLignes, int nbColonnes)
            {
                int nb, duree;

                Grille *g = new Grille(nbLignes, nbColonnes);
                return g;
            }

            void Fichier::initCellule()
            {
                int etat = false;

                ifstream fichier(path.c_str(), ios::in); // ouvre le fichier
                for (int i = 0; i < g->getNbLignes(); i++)
                {
                    for (int j = 0; j < g->getNbColonnes(); j++)
                    {
                        // rajouter du code pour sauter la 1e ligne
                        getline(fichier, contenu);

                        if (contenu == "0")
                        {
                            etat;
                        }
                        else
                        {
                            !etat;
                            if (contenu == "0")
                            {
                                etat = etat;
                            }
                            else
                            {
                                etat = !etat;
                            }
                            CelluleActive *c1 = new CelluleActive(etat);
                            g->setStock(i, j) = c1;
                            g->setTransition(i, j) = c1;
                            g->setStock(i, j, c1);
                            g->setTransition(i, j, c1);
                        }
                    }
                }

                void Fichier::creerFichier()
                {
                    string nom_fichier = "<" + path + ">" + "_out_" + to_string(a);
                    void Fichier::stockerDonnees(vector<vector<Cellule *>> vect)
                    {
                        ofstream fichierSortie;

                        string nom_fichier = "<" + path + ">" + "_out_" + to_string(a); // on pose le nom du fichier
                        // on ouvre en écriture
                        fichierSortie.open(nom_fichier.c_str(), ios::out);

                        if (fichierSortie)
                        {
                            for (auto ligne : vect)
                            {
                                for (auto cell : ligne)
                                {
                                    fichierSortie << to_char(cell);
                                }
                            }
                            fichierSortie.close(); // on ferme le fichier
                        }
                        else
                        {
                            cerr << "Erreur à l'ouverture du fichier en écriture" << endl;
                        }
                    }

                    string Fichier::to_char(Cellule * c2)
                    {
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