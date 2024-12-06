#pragma once
#include <iostream>
#include "ActualiserJeu.h"
#include "CelluleActive.h"
#include "CelluleObstacle.h"
#include "Fichier.h"
#include "Grille.h"
#include "InterfaceConsole.h"
#include "InterfaceGraphique.h"
#include "JeuDeLaVie.h"

using namespace std;

int nb, duree;
int cellObs;
int numLigne, numColonne, etatCellObs;

int main()
{
    cout << "Combien d'itérations voulez-vous que le programme effectuer avant de s'arrêter?" << endl;
    cin >> nb;
    cout << "Quelle durée entre deux itérations voulez-vous instaurer (en secondes)?" << endl;
    cin >> duree;

    JeuDeLaVie *jdlv = new JeuDeLaVie(nb, duree);

    cout << "Combien de cellule obstacle voulez-vous rajouter?" << endl;
    cin >> cellObs;

    for (int i = 0; i < cellObs; i++)
    {
        cout << "Quelle ligne pour la cellule obstacle " + to_string(i) + "?" << endl;
        cin >> numLigne;
        cout << "Quelle colonne pour la cellule obstacle " + to_string(i) + "?" << endl;
        cin >> numColonne;
        cout << "Quel état pour la cellule obstacle " + to_string(i) + "?" << endl;
        cin >> etatCellObs;

        Cellule *c2 = new CelluleObstacle(etatCellObs);
    }

    // Interface
    int choixInterface;
    cout << "Choississez votre type d'interface: " << endl
         << "(1)->Interface console" << endl
         << "(2)->Interface graphique" << endl;
    cin >> choixInterface;
    if (choixInterface == 1)
    {
        InterfaceConsole ic;
        ic.affichageGrille(g);
    }
    else if (choixInterface == 2)
    {
        int choixtC;
        cout << "Rentrez la taille que vous souhaitez pour vos cellule:" << endl;
        cin >> choixtC;

        InterfaceGraphique ig(choixtC);
        ig.affichageGrille(g);
    }
    else
    {
        cerr << "ERROR : nombre invalide " << endl;
    }
}
