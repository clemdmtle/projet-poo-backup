#include "Fichier.h"
#include <fstream>
#include <string>
#include <iostream>
#include "Cellule.cpp"
#include "Grille.cpp"
using namespace std;

int a=0; 

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
        string contenu = "";
        string strChiffre;

        if(fichier){
            cout << "Fichier ouvert avec succès" << endl;
            while (getline(fichier, strChiffre, " ")){ //lit le contenu
                contenu = contenu + strChiffre; //stocke tout dans un tableau
                cout << contenu;
            }
            cout << endl;
            setNbLignes(stoi(contenu));
            contenu="";

            while (getline(fichier, strChiffre, " ")){ //lit le contenu
                contenu = contenu + strChiffre; //stocke tout dans un tableau
                cout << contenu;
            }
            cout << endl;
            setNbColonnes(stoi(contenu));
            contenu="";

            fichier.close(); //ferme le fichier
        }else{
            cerr << "Erreur à l'ouverture du fichier" << endl;
        }
}

Cellule * stock[getNbLignes()][getNbColonnes()];

void Fichier::initGrille(){
    int nb, duree;

    cout << "Combien d'itérations voulez-vous que le programme effectuer avant de s'arrêter?" << endl;
    cin >> nb;
    setNbIteration(nb);
    cout << "Quelle durée entre deux itérations voulez-vous instaurer?" << endl;
    cin >> duree;
    setDureeIteration(duree);

    Grille *g = new Grille (g->getNbColonnes(), g->getNbLignes(), getNbIteration(), getDureeIteration());
}

void Fichier::initCellule(){
    ifstream fichier(path.c_str(), ios::in); //ouvre le fichier
    for (int i=0; i<getNbLignes(); i++){
        for (int j=0; j<getNbColonnes(); j++){
            //rajouter du code pour sauter la 1e ligne
            getline(fichier, contenu);

            if (contenu=="0"){
                ->setEtatCellule(false);
            } else {
                setEtatCellule(true);
            }
            setEtatPrecedent(false);
            celluleActive *c1 = new celluleActive(getEtatCellule(), getEtatPrecedent());
            Stock[i][j]=c1;
            Transition[i][j]=c1;
        }
    }
}

void Fichier::creerFichier(){
    string nom_fichier= "<" + path + ">" + "_out_" + a;

}