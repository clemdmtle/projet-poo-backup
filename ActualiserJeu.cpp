#pragma once
#include "ActualiserJeu.h"
#include "Cellule.cpp"
#include "CelluleActive.cpp"
#include "Grille.cpp"
#include "Fichier.cpp"
#include "JeuDeLaVie.cpp"

int b=0;

void ActualiserJeu::changementEtat(int l, int c, Grille *g){
    int count = verifierVoisins(l, c, g);
    if ((g->getCelluleStock(l, c)->getEtatCellule()) == true){  //si la cellule est vivante
        if (count == 2 && count == 3){ //et que le compteur est égal à 2 ou 3
            g->getCelluleTransition(l, c)->setEtatCellule(true); //la cellule reste vivante
        }else{
            g->getCelluleTransition(l, c)->setEtatCellule(false); //sinon elle meurt
        }
    }else{
        if (count == 3){ //si la cellule est morte et que le compteur est à 3
            g->getCelluleTransition(l, c)->setEtatCellule(true); //elle devient vivante
        }
    }
}

int ActualiserJeu::verifierVoisins(int l, int c, Grille *g){
    int count = 0;
    g->getCelluleStock(l, c)->setEtatPrecedent(g->etatCellule(l, c)); //on modifie l'etatP pour qu'il soit égal à l'état actuel

    for (c = -1; c <= 1; c++){
        for (l = -1; l <= 1; l++){
            if (c == 0 && l == 0 || g->getCelluleStock(l,c)->getType()=="Obstacle"){ //si c'est la cellule concernée ou si la cellule est obstacle on saute
                continue;
            }else{
                if (g->etatCellule(l, c) == true){ //si la cellule est vivante
                    count++; //count+1
                }
            }
        }
    }
    changementEtat(l, c, g); //on appelle changementEtat
    return count;
}

void ActualiserJeu::actualiserGrille(Grille *g, JeuDeLaVie* jdlv){
    for (int l = 0; l < g->getNbLignes(); l++){
        for (int c = 0; c < g->getNbColonnes(); c++){ //on parcourt chaque cellule
            verifierVoisins(l, c, g); //on vérifie ses voisins
            b++; //on ajoute à b(pr compter le nb d'itérations)
        }
    }

    for (int i=0; i<g->getNbLignes(); i++){ //copie la matrice transition dans la matrice stock
        for (int j=0; j<g->getNbColonnes(); j++){
            g->setStock(i,j,(g->getCelluleTransition(i,j)));
        }
    }
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
    if (etatJeu == false || b<=jdlv->getNbIteration()){ //si la grille n'a pas changé ou si le nb d'itérations est dépassé
        cout << "Le jeu est fini" << endl; //le jeu est fini
    }else{
        cout << "Le jeu peut continuer" << endl;
    }
    return etatJeu;
}
