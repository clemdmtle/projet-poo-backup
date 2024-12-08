#include <iostream>
#include "ActualiserJeu.h"
#include "CelluleActive.h"
#include "CelluleObstacle.h"
#include "Fichier.h"
#include "Grille.h"
#include "InterfaceConsole.h"
#include "InterfaceGraphique.h"
#include "JeuDeLaVie.h"
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;
using namespace this_thread;

int main()
{
    string path, contenu, aIgnorer;
    int nb, duree;
    int cellObs;
    int numLigne, numColonne, etatCellObs;
    bool etat = false;

    cout << "Veuillez donner le chemin du fichier contenant vos cellules" << endl;
    cin >> path;                      // récupère le fichier
    Fichier *f = new Fichier(path);   // créer un obj fichier
    vector<int> p = f->lireFichier(); // récupère le tableau avec nblignes et nbcolonnes

    int nbLignes = p[0];   // récupère nblignes
    int nbColonnes = p[1]; // récupère nbcolonnes
    cout << "nb lignes : " << nbLignes << endl;
    cout << "nb colonnes : " << nbColonnes << endl;

    Grille *g = new Grille(nbLignes, nbColonnes); // créer un obj grille

    Cellule *c1;

    ifstream fichier(path.c_str(), ios::in); // ouvre le fichier
    getline(fichier, aIgnorer);              // on saute la 1e ligne qui contient nblignes nbcolonnes
    for (int i = 0; i < nbLignes; i++)
    {
        for (int j = 0; j < nbColonnes; j++)
        {                                   // parcourt la grille
            getline(fichier, contenu, ' '); // lit chaque caractère
            if (contenu == "0")
            { // associe un état
                etat = etat;
            }
            else
            {
                etat = !etat;
            }
            c1 = new CelluleActive(etat); // créer un obj cellule
            g->setStock(i, j, c1);
            g->setTransition(i, j, c1);
        }
    }

    cout << "Combien d'itérations voulez-vous que le programme effectue avant de s'arrêter?" << endl;
    cin >> nb;
    cout << "Quelle durée entre deux itérations voulez-vous instaurer (en secondes)?" << endl;
    cin >> duree;

    JeuDeLaVie *jdlv = new JeuDeLaVie(nb, duree); // créer une partie

    cout << "Combien de cellule obstacle voulez-vous rajouter?" << endl; // demande les cellules obstacles
    cin >> cellObs;
    
    vector<pair<int, int>> obstacles;
    bool erreur=true;
    while (erreur==true){
        for (int i = 0; i < cellObs; i++){
            cout << "Quelle ligne pour la cellule obstacle " + to_string(i) + "?" << endl;
            cin >> numLigne;
            cout << "Quelle colonne pour la cellule obstacle " + to_string(i) + "?" << endl;
            cin >> numColonne;

            if (numLigne < 0 || numColonne < 0 || numLigne >= nbLignes || numColonne >= nbColonnes){
                cerr << "Vous n'êtes pas dans la bonne plage d'indices, veuillez recommencez." << endl;
            } else {
                erreur=false;
            }
            
            
            etatCellObs=g->etatCellule(numLigne, numColonne);

            c1 = new CelluleObstacle(etatCellObs); // change le type de la cellule en cellule obstacle
            g->setStock(numLigne, numColonne, c1);
            obstacles.push_back(make_pair(numLigne, numColonne));
        }
    }

    erreur=true;

    // Interface
    int choixInterface;
    cout << "Choississez votre type d'interface: " << endl << "(1)->Interface console" << endl << "(2)->Interface graphique" << endl; // l'utilisateur choisit le mode de fonctionnement
    cin >> choixInterface;
    while (erreur==true){
        if (choixInterface == 1)
        {
            InterfaceConsole *ic = new InterfaceConsole;
            g->addObservers(ic);
            erreur=false;
        }
        else if (choixInterface == 2)
        {
            int choixtC;
            cout << "Rentrez la taille que vous souhaitez pour vos cellule:" << endl;
            cin >> choixtC;

            InterfaceGraphique *ig = new InterfaceGraphique(choixtC);
            g->addObservers(ig);
            erreur=false;
        }
        else
        {
            cerr << "ERROR : nombre invalide " << endl;
        }
    }

    cout << "Grille de base : " << endl;
    g->notify(f);

    ActualiserJeu *actu = new ActualiserJeu;
    while (actu->verifierEtatJeu(g, jdlv) == true)
    { // relance le jeu tant qu'il n'est pas fini
        actu->actualiserGrille(g, jdlv, f);
        for (int i=0; i<obstacles.size(); i++){
            numLigne=obstacles[i].first;
            numColonne=obstacles[i].second;
            c1=new CelluleObstacle(etatCellObs);
            g->setStock(numLigne,numColonne,c1);
        }
        sleep_for(seconds(jdlv->getDureeIteration()));
    }

    for (int k = 0; k < g->getNbLignes(); k++){
        for (int l = 0; l < g->getNbColonnes(); l++){
            Cellule *stockCell = g->getCelluleStock(k, l);
            Cellule *transitionCell = g->getCelluleTransition(k, l);
        }
    }   
    delete f;
    delete jdlv;
    delete g;
    delete actu;
}
