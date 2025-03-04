#pragma once
#include <iostream>

using namespace std;

class CompositionChimique {
protected:
    string nom;
    string formule;
    string origine;
    bool toxicite;
    float temperature_decomposition;

public:
    
    CompositionChimique();
    CompositionChimique(string , string , string , bool , float );
    CompositionChimique(const CompositionChimique& );


    friend ostream& operator<<(ostream& ,  CompositionChimique& );
    friend istream& operator>>(istream& , CompositionChimique& );
    bool operator==( CompositionChimique& ) ;


    string getNom()  { return nom; }
    string getFormule()  { return formule; }
    string getOrigine()  { return origine; }
    bool getToxicite()  { return toxicite; }
    float getTemperatureDecomposition()  { return temperature_decomposition; }


    void setNom( string& nom) { this->nom = nom; }
    void setFormule( string& formule) { this->formule = formule; }
    void setOrigine( string& origine) { this->origine = origine; }
    void setToxicite(bool toxicite) { this->toxicite = toxicite; }
    void setTemperatureDecomposition(float tempDecomp) { this->temperature_decomposition = tempDecomp; }
};
