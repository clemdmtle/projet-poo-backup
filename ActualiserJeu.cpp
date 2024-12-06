#pragma once
#include "ActualiserJeu.h"
#include "Cellule.cpp"
#include "CelluleActive.cpp"
#include "Grille.cpp"
#include "Fichier.cpp"

void ActualiserJeu::changementEtat(int l, int c, Grille *g)
{
    int count = verifierVoisins(l, c, g);
    if ((g->getCelluleStock(l, c)->getEtatCellule()) == true)
    {
        if (count >= 2 && count <= 3)
        {
            g->getCelluleTransition(l, c)->setEtatCellule(true);
        }
        else
        {
            g->getCelluleTransition(l, c)->setEtatCellule(false);
        }
    }
    else
    {
        if (count == 3)
        {
            g->getCelluleTransition(l, c)->setEtatCellule(true);
        }
    }
}

int ActualiserJeu::verifierVoisins(int l, int c, Grille *g)
{
    int count = 0;
    g->getCelluleStock(l, c)->setEtatPrecedent(g->etatCellule(l, c));

    for (c = -1; c <= 1; c++)
    {
        for (l = -1; l <= 1; l++)
        {
            if (c == 0 && l == 0)
            {
                continue;
            }
            else
            {
                if (g->etatCellule(l, c) == true)
                {
                    count++;
                }
            }
        }
    }
    changementEtat(l, c, g);
    return count;
}

void ActualiserJeu::actualiserGrille(Grille *g)
{

    for (int l = 0; l < g->getNbLignes(); l++)
    {
        for (int c = 0; c < g->getNbColonnes(); c++)
        {
            verifierVoisins(l, c, g);
        }
    }
    verifierEtatJeu(g);
}

bool ActualiserJeu::verifierEtatJeu(Grille *g)
{
    bool etatJeu = false;

    for (int i = 0; i < g->getNbLignes(); i++)
    {
        for (int j = 0; j < g->getNbColonnes(); j++)
        {
            if (g->etatCellule(i, j) != g->etatPrecedent(i, j))
            {
                etatJeu = true;
            }
        }
    }
    if (etatJeu == false)
    {
        cout << "Le jeu est fini" << endl;
    }
    else
    {
        cout << "Le jeu peut continuer" << endl;
    }
    return etatJeu;
}
