#pragma once
#include "Categorie.h"
class OrthopedieEtMobilite : public virtual Categorie
{
protected:
    float taille;
    string material;
    int poids_supporte;
public:
    OrthopedieEtMobilite();
    //OrthopedieEtMobilite( float, string, int , string = "Orthopedie Et Mobilite");
    OrthopedieEtMobilite(const OrthopedieEtMobilite&);

    friend ostream& operator<<(ostream&, OrthopedieEtMobilite&);
    friend istream& operator>>(istream&, OrthopedieEtMobilite&);
    //bool operator==(OrthopedieEtMobilite&);
    OrthopedieEtMobilite& operator=(OrthopedieEtMobilite&);
    void traiterPrix(float = 23.600);


    float getTaille() { return taille; };
    string getMateriau() { return material; };
    int getPoidsSupporte() { return poids_supporte; };
    void setTaille(float taille) { this->taille = taille; };
    void setMateriau(string material) { this->material = material; };
    void setPoidsSupporte(int poids) { this->poids_supporte = poids; };

    ~OrthopedieEtMobilite(void);
};

