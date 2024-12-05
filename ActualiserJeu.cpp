#include "ActualiserJeu.h"
#include "Cellule.cpp"
#include "CelluleActive.cpp"
#include "Grille.cpp"
#include "Fichier.cpp"

Grille *g=new Grille(10, 10);

int count=0;
int nbLignes=g->getNbLignes();
int nbColonnes=g->getNbColonnes();

bool ActualiserJeu::changementEtat(int l, int c){
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

int ActualiserJeu::verifierVoisins(int l, int c){
    
    g->getStock(l, c)->setEtatPrecedent(etatCellule(l,c));

 
    for (c=-1; c=1; c++){
        for (l=-1; l=1; l++){
            if (c==0 && l==0){
                continue;
            }else{
                if (etatCellule(l,c)==true){
                count++;
                }
            }
        }
    }
    
    changementEtat(l, c);
}

void ActualiserJeu::actualiserGrille(){

    for (int l=0; l<nbLignes; l++){
        for (int c=0; c<nbColonnes; c++){
            verifierVoisins(l, c);
        }
    }
    verifierEtatJeu();
}

bool ActualiserJeu::verifierEtatJeu(){
    bool etatJeu=false;

    for (int i=0; i<nbLignes; i++){
        for (int j=0; j<g->getNbColonnes(); j++){
            if (etatCellule(i,j)!=etatPrecedent(i,j)){
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