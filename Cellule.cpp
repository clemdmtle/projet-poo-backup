#include "Cellule.h"

Cellule::Cellule()
{
    etatCellule = 1;
}

Cellule::Cellule(bool ec)
{
    this->etatCellule = ec;
}

bool Cellule::getEtatCellule()
{
    return etatCellule;
}

void Cellule::setEtatCellule(bool e)
{
    etatCellule = e;
}
Cellule::~Cellule()
{
}