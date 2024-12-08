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

    Grille *g = new Grille(nbLignes, nbColonnes); // créer un obj grille

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
            CelluleActive *c1 = new CelluleActive(etat); // créer un obj cellule
            g->setStock(i, j, c1);
            g->setTransition(i, j, c1);
        }
    }

    cout << "Combien d'itérations voulez-vous que le programme effectuer avant de s'arrêter?" << endl;
    cin >> nb;
    cout << "Quelle durée entre deux itérations voulez-vous instaurer (en secondes)?" << endl;
    cin >> duree;

    JeuDeLaVie *jdlv = new JeuDeLaVie(nb, duree); // créer une partie

    cout << "Combien de cellule obstacle voulez-vous rajouter?" << endl; // demande les cellules obstacles
    cin >> cellObs;

    for (int i = 0; i < cellObs; i++)
    {
        cout << "Quelle ligne pour la cellule obstacle " + to_string(i) + "?" << endl;
        cin >> numLigne;
        cout << "Quelle colonne pour la cellule obstacle " + to_string(i) + "?" << endl;
        cin >> numColonne;
        cout << "Quel état pour la cellule obstacle " + to_string(i) + "?" << endl;
        cin >> etatCellObs;

        Cellule *c2 = new CelluleObstacle(etatCellObs); // change le type de la cellule en cellule obstacle
        g->setStock(numLigne, numColonne, c2);
    }

    // Interface
    int choixInterface;
    cout << "Choississez votre type d'interface: " << endl
         << "(1)->Interface console" << endl
         << "(2)->Interface graphique" << endl; // l'utilisateur choisit le mode de fonctionnement
    cin >> choixInterface;
    if (choixInterface == 1)
    {
        InterfaceConsole *ic = new InterfaceConsole;
        g->addObservers(ic);
    }
    else if (choixInterface == 2)
    {
        int choixtC;
        cout << "Rentrez la taille que vous souhaitez pour vos cellule:" << endl;
        cin >> choixtC;

        InterfaceGraphique *ig = new InterfaceGraphique(choixtC);
        g->addObservers(ig);
    }
    else
    {
        cerr << "ERROR : nombre invalide " << endl;
    }

    cout << "hey 1" << endl;
    ActualiserJeu *actu = new ActualiserJeu;
    cout << "hey 2" << endl;
    while (actu->verifierEtatJeu(g, jdlv) == true)
    { // relance le jeu tant qu'il n'est pas fini
        cout << "hey 6" << endl; 
        actu->actualiserGrille(g, jdlv, f);
        cout << "hey 3" << endl;
        sleep_for(seconds(jdlv->getDureeIteration()));
        cout << "hey 4" << endl;
    }

    cout << "hey 5" << endl;
    cout << "taille du tab" << g->getStock().size();

    cout << "taille du tab" << g->getStock().size();
    for (int k = 0; k < g->getNbLignes(); k++){
        for (int l = 0; l < g->getNbColonnes(); l++){
            Cellule *stockCell = g->getCelluleStock(k, l);
            Cellule *transitionCell = g->getCelluleTransition(k, l);
            
            if (stockCell == transitionCell && stockCell != nullptr)
            {
                delete stockCell;
                cout << "taille du tab" << g->getStock().size();
            }
            else
            {
                if (stockCell != nullptr) delete stockCell;
                if (transitionCell != nullptr) delete transitionCell;
                cout << "taille du tab" << g->getStock().size();
            }
        }
    }   
    delete f;
    delete jdlv;
    delete g;
    delete actu;

}
