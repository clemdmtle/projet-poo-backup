#include "Interface.h"

Interface::Interface()
{
  cellSize = 4;
  gridHeight = gridWidth = 80;
}

Interface::Interface(int cS, int gH, int gW)
    : cellSize(cS), gridHeight(gH), gridWidth(gW) {}

void Interface::initializeGrid()
{
}

void Interface::renderGrid()
{
}