#include "ActualiserJeu.h"
#include "Cellule.cpp"
#include "CelluleActive.cpp"
#include "Grille.cpp"
#include "Fichier.cpp"


int count=0;

bool ActualiserJeu::changementEtat(int l, int c, Grille *g){
    if ((g->getStock(l,c)->getEtatCellule())==true){
        if (2<=count<=3){
            g->getTransition(l,c)->setEtatCellule(true);
        }else{
            g->getTransition(l,c)->setEtatCellule(false);
        }
    }else{
        if (count==3){
            g->getTransition(l,c)->setEtatCellule(true);
        }
    }
}

int ActualiserJeu::verifierVoisins(int l, int c, Grille *g){
    count=0;
    g->getStock(l, c)->setEtatPrecedent(g->etatCellule(l,c));

 
    for (c=-1; c<=1; c++){
        for (l=-1; l<=1; l++){
            if (c==0 && l==0){
                continue;
            }else{
                if (g->etatCellule(l,c)==true){
                count++;
                }
            }
        }
    }
    
    changementEtat(l, c);
}

void ActualiserJeu::actualiserGrille(Grille *g){

    for (int l=0; l<g->getNbLignes(); l++){
        for (int c=0; c<g->getNbColonnes(); c++){
            verifierVoisins(l, c);
        }
    }
    verifierEtatJeu();
}

bool ActualiserJeu::verifierEtatJeu(Grille *g){
    bool etatJeu=false;

    for (int i=0; i<g->getNbLignes(); i++){
        for (int j=0; j<g->getNbColonnes(); j++){
            if (g->etatCellule(i,j)!=g->etatPrecedent(i,j)){
                !etatJeu;
            }
        }
    }
    if (etatJeu==false){
        cout << "Le jeu est fini" << endl;
    } else {
        cout << "Le jeu peut continuer" << endl;
    }
}
