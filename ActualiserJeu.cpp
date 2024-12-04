#include "ActualiserJeu.h"
#include "Cellule.cpp"
#include "CelluleActive.cpp"

bool ActualiserJeu::changementEtat(){
    if (getEtatCellule(Stock[i][j])==true){
        if (2<=count<=3){
            Transition[l][c].setEtatCellule(true);
        }else{
            Transition[l][c].setEtatCellule(false);
        }
    }else{
        if (count==3){
            Transition.[l][c]setEtatCellule(true);
        }
    }
}

int ActualiserJeu::verifierVoisins(int l, int c){
    setEtatPrecedent(getEtatCellule);

    if (l==0 && c==0){
        for (l=0; l=1; l++){
            if (Stock[l][c+1].getEtatCellule()==true){
                count++;
            }
        }
        if (Stock[l+1][c].getEtatCellule()==true){
            count++;
        }
    }else if(l==g->getNbLignes() && c==0){
        for (l=0; l=1; l++){
            if (Stock[l][c-1].getEtatCellule()==true){
                count++;
            }
        }
        if (Stock[l+1][c].getEtatCellule()==true){
            count++;
        }
    }else if (l==0 && c==g->getNbColonnes()){
        for (l=-1; l=0; l++){
            if (Stock[i][j+1].getEtatCellule()==true){
                count++;
            }
        }
        if (Stock[l-1][c].getEtatCellule()==true){
            count++;
        }
    }else if (l==g->getNbLignes() && c==g->getNbColonnes()){
        for (c=-1; c=0; c++){
            if (Stock[l-1][c].getEtatCellule()==true){
                count++;
            }
        }
        if (Stock[l][c-1].getEtatCellule()==true){
            count++;
        }
    }else{
        for (c=-1; c=1; c+2){
            for (l=-1; l=1; l++){
                if (Stock[l][c].getEtatCellule()==true){
                    count++;
                }
            }
        }
        for (l=-1; l=1; l+2){
            if(Stock[l][0].getEtatCellule()==true){
                count++;
            }
        }
    }
    changementEtat();
}

void ActualiserJeu::actualiserGrille(){
    for (l=0; l<getNbLignes(); l++){
        for (c=0; c<getNbColonnes(); c++){
            verifierVoisins(l, c);
        }
    }
    verifierEtatJeu();
}

bool ActualiserJeu::verifierEtatJeu(){
    bool etatJeu=false;

    for (int i=0; i<getNbLignes(); i++){
        for (int j=0; j<getNbColonnes(); j++){
            if (Stock[i][j].getEtatCellule()!=Stock[i][j].getEtatPrecedent()){
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
