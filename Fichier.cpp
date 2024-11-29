#include "Fichier.h"
#include <fstream>

void Fichier::stockerDonnees(){

}

void Fichier::lireFichier(){
    ifstream fichier(path.c_str(), ios::in); //ouvre le fichier
        string contenu;
        int i=0;

        if(fichier){
            cout << "Fichier ouvert avec succès" << endl;
            while (getline(fichier, contenu) && i<100){ //lit le contenu
                tab[i] = contenu; //stocke tout dans un tableau
                cout << contenu;
                i++;
            }
            cout << endl;
            fichier.close(); //ferme le fichier
        }else{
            cerr << "Erreur à l'ouverture du fichier" << endl;
        }
}

void Fichier::initGrille(){

}

void Fichier::initCellule(){

}