#include <string> 

class Fichier {
    string path;

    public:
    Fichier(string path){}

    void stockerDonnees();
    void creerFichier();
    void lireFichier();
    void initGrille();
    void initCellule();
};