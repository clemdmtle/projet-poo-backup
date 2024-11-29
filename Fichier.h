#include <String> 

class Fichier {
    string path;

    public:
    Fichier(string path){}

    void stockerDonnees();
    void lireFichier();
    void initGrille();
    void initCellule();
};