#pragma once
class JeuDeLaVie {
    private:
    int nbIteration, dureeIteration;
    int count;

    public:
    JeuDeLaVie(int nbIteration, int dureeIteration){
        this->nbIteration=nbIteration;
        this->dureeIteration=dureeIteration;
    }

    int getNbIteration();
    void setNbIteration(int nb);
    int getDureeIteration();
    void setDureeIteration(int nb);
};