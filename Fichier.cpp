#include "Fichier.h"
#include <fstream>
#include <fstream>
#include <string>
#include <iostream>
#include "Cellule.cpp"
#include "Grille.cpp"
#include "CelluleActive.cpp"
using namespace std;

int a=0; 
string contenu = "";

void Fichier::stockerDonnees(){
    ofstream fichier;

    //sinon on ouvre en écriture à la suite
    fichier.open(path.c_str(), ios::out | ios::app);

    if (fichier) {
        //rentrer la grille
        fichier.close(); //on ferme le fichier
    }else {
        cerr << "Erreur à l'ouverture du fichier en écriture" << endl;
    }
}

void Fichier::lireFichier(){
    ifstream fichier(path.c_str(), ios::in); //ouvre le fichier
        string strChiffre;

        if(fichier){
            cout << "Fichier ouvert avec succès" << endl;
            while (getline(fichier, strChiffre, " ")){ //lit le contenu
                contenu = contenu + strChiffre; //stocke tout dans un tableau
                cout << contenu;
            }
            cout << endl;
            g->setNbLignes(stoi(contenu));
            contenu="";

            while (getline(fichier, strChiffre, " ")){ //lit le contenu
                contenu = contenu + strChiffre; //stocke tout dans un tableau
                cout << contenu;
            }
            cout << endl;
            g->setNbColonnes(stoi(contenu));
            contenu="";

            fichier.close(); //ferme le fichier
        }else{
            cerr << "Erreur à l'ouverture du fichier" << endl;
        }
}

Grille* Fichier::initGrille(){
    int nb, duree;


    Grille *g = new Grille (g->getNbColonnes(), g->getNbLignes());

    return g;
}

void Fichier::initCellule(){
    int etat=false;

    ifstream fichier(path.c_str(), ios::in); //ouvre le fichier
    for (int i=0; i<g->getNbLignes(); i++){
        for (int j=0; j<g->getNbColonnes(); j++){
            //rajouter du code pour sauter la 1e ligne
            getline(fichier, contenu);

            if (contenu=="0"){
                etat;
            } else {
                !etat;
            }
            CelluleActive *c1 = new CelluleActive(etat);
            g->Stock[i][j]=c1;
            g->Transition[i][j]=c1;
        }
    }
}

void Fichier::creerFichier(){
    string nom_fichier= "<" + path + ">" + "_out_" + to_string(a);
}