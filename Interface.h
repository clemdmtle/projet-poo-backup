#ifndef INTERFACE_H
#define INTERFACE_H

class Interface
{
private:
    int cellSize, gridHeight, gridWidth;

public:
    Interface();
    Interface(int cS, int gH, int gW);
    void initializeGrid();
    void renderGrid();
};

#endif INTERFACE_H