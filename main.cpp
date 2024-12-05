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

int main(){
    cout << "Combien d'itérations voulez-vous que le programme effectuer avant de s'arrêter?" << endl;
    cin >> nb;
    cout << "Quelle durée entre deux itérations voulez-vous instaurer (en secondes)?" << endl;
    cin >> duree;
    
    JeuDeLaVie *jdlv = new JeuDeLaVie(nb, duree);
}
