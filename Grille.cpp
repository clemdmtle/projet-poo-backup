#include "Grille.h"

void Grille::actualiserGrille(){
    i=0;
    j=0;
    while (stock[i][j]){
        verifierVoisins(i, j);
        i++;
        j++;
    }
}

void Grille::afficherGrille(){

}

int Grille::verifierVoisins(int i, int j){
    for (int j=-1; j<1; j+=2){
        for (int i=-1; i<1; i++){
            if (stock[i][j]->getEtatCellule==true){
                count++;
            }
        }
    }
    changementEtat();
}

bool Grille::verifierEtatJeu(){

}