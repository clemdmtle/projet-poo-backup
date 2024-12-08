#include "ActualiserJeu.h"
#include "Cellule.h"
#include "CelluleActive.h"
#include "Grille.h"
#include "Fichier.h"
#include "JeuDeLaVie.h"

int b=0;
int count = 0;

void ActualiserJeu::changementEtat(int l, int c, Grille *g){
    if ((g->getCelluleStock(l, c)->getEtatCellule()) == true){  //si la cellule est vivante
        if (count == 2 || count == 3){ //et que le compteur est égal à 2 ou 3
            g->getCelluleTransition(l, c)->setEtatCellule(true); //la cellule reste vivante
        }else{
            g->getCelluleTransition(l, c)->setEtatCellule(false); //sinon elle meurt
        }
    }else{
        if (count == 3){ //si la cellule est morte et que le compteur est à 3
            g->getCelluleTransition(l, c)->setEtatCellule(true); //elle devient vivante
        }
    }
    count=0;
}

void ActualiserJeu::verifierVoisins(int l, int c, Grille *g){
    g->getCelluleStock(l, c)->setEtatPrecedent(g->etatCellule(l, c)); //on modifie l'etatP pour qu'il soit égal à l'état actuel
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (i == 0 && j == 0 || g->getCelluleStock(l,c)->getType()=="Obstacle"){ //si c'est la cellule concernée ou si la cellule est obstacle on saute
                continue;
            }else{
                if (g->etatCellule(i, j) == true){ //si la cellule est vivante
                    count++; //count+1
                }
            }
        }
    }
    changementEtat(l, c, g); //on appelle changementEtat    
}

void ActualiserJeu::actualiserGrille(Grille *g, JeuDeLaVie* jdlv, Fichier* f){
    for (int l = 0; l < g->getNbLignes(); l++){
        for (int c = 0; c < g->getNbColonnes(); c++){ //on parcourt chaque cellule
            verifierVoisins(l, c, g); //on vérifie ses voisins
        }
    }
    b++; //on ajoute à b(pr compter le nb d'itérations)

    for (int i=0; i<g->getNbLignes(); i++){ //copie la matrice transition dans la matrice stock
        for (int j=0; j<g->getNbColonnes(); j++){
            g->setStock(i,j,(g->getCelluleTransition(i,j)));
        }
    }
    cout << "Affichage de la cellule à l'itération " << b << " : " << endl << endl;
    g->notify(f);
    verifierEtatJeu(g, jdlv); //on regarde si le jeu est fini ou non
}

bool ActualiserJeu::verifierEtatJeu(Grille *g, JeuDeLaVie* jdlv){
    bool etatJeu = false;

    for (int i = 0; i < g->getNbLignes(); i++){
        for (int j = 0; j < g->getNbColonnes(); j++){
            if (g->etatCellule(i, j) != g->etatPrecedent(i, j)){ //si la grille a changé entre 2 itérations
                etatJeu = true; //le jeu n'est pas fini
            }
        }
    }
    if (b==0 || b==1){
        cout << "Le jeu peut continuer" << endl;
        etatJeu=true;
    }else if (etatJeu == false || b==jdlv->getNbIteration()){
        cout << "Le jeu est fini" << endl;
        etatJeu=false;
    }else if (etatJeu==true){
        cout << "Le jeu peut continuer" << endl;        
    }
    return etatJeu;
}
