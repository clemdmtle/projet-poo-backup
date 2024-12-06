#pragma once
#include <iostream>
#include "ActualiserJeu.cpp"
#include "Cellule.cpp"
#include "CelluleActive.cpp"
#include "CelluleObstacle.cpp"
#include "Fichier.cpp"
#include "Grille.cpp"
#include "Interface.cpp"
#include "InterfaceConsole.cpp"
#include "InterfaceGraphique.cpp"
#include "JeuDeLaVie.h"

using namespace std;

int nb, duree;
int cellObs;
int numLigne, numColonne, etatCellObs;

int main(){
    cout << "Combien d'itérations voulez-vous que le programme effectuer avant de s'arrêter?" << endl;
    cin >> nb;
    cout << "Quelle durée entre deux itérations voulez-vous instaurer (en secondes)?" << endl;
    cin >> duree;
    
    JeuDeLaVie *jdlv = new JeuDeLaVie(nb, duree);

    cout << "Combien de cellule obstacle voulez-vous rajouter?" << endl;
    cin >> cellObs;

    for (int i=0; i<cellObs; i++){
        cout << "Quelle ligne pour la cellule obstacle " + to_string(i) + "?" << endl;
        cin >> numLigne;
        cout << "Quelle colonne pour la cellule obstacle " + to_string(i) + "?" << endl;
        cin >> numColonne;
        cout << "Quel état pour la cellule obstacle " + to_string(i) + "?" << endl;
        cin >> etatCellObs;

        Cellule *c2=new CelluleObstacle(etatCellObs)

    }
}
