#include "Fichier.h"
#include <fstream>
#include <fstream>
#include <string>
#include <iostream>
#include "Cellule.cpp"
#include "Grille.h"
#include "Grille.cpp"
#include "CelluleActive.cpp"
using namespace std;

int a=0; 
string contenu = "";

int* Fichier::lireFichier(){
    int tab[2];
    ifstream fichier(path.c_str(), ios::in); //ouvre le fichier
        string strChiffre;

    if(fichier){
        cout << "Fichier ouvert avec succès" << endl;
        for (int x=0; x<2; x++){
            getline(fichier, strChiffre, ' ');
            tab[x]=stoi(strChiffre);
        } 

        fichier.close(); //ferme le fichier
    }else{
        cerr << "Erreur à l'ouverture du fichier" << endl;
    }

    return tab;
}


void Fichier::stockerDonnees(vector<vector<Cellule*>> vect){
    ofstream fichierSortie;

    string nom_fichier= "<" + path + ">" + "_out_" + to_string(a); //on pose le nom du fichier
    //on ouvre en écriture
    fichierSortie.open(nom_fichier.c_str(), ios::out);

    if (fichierSortie) {
        for (auto ligne: vect){
            for (auto cell: ligne){
                fichierSortie << to_char(cell);
            }
        }
        fichierSortie.close(); //on ferme le fichier
        a++;
    }else {
        cerr << "Erreur à l'ouverture du fichier en écriture" << endl;
    }
}

string Fichier::to_char(Cellule* c2){
    string str;
    if (c2->getEtatCellule()==true){
        str="1";
    }else{
        str="0";
    }
    return str;
}