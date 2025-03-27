#pragma once
#include<string>
#include <iostream>
#include<vector>
#include "Date.h"
#include "Vente.h"

using namespace std;

class Personne
{
protected:
    string nom;
    string prenom;
    Date date_naiss;
    string mdp;
    int niveau_acces;
    float salaire;
    vector <Vente*> vente;
public:
    Personne();
    Personne(const Personne&);
    friend ostream& operator<<(ostream&, Personne&);
    friend istream& operator>>(istream&, Personne&);
    bool operator==(Personne&);
    void setNom(string n) { nom = n; }
    string getNom() { return nom; }
    void ajouterVente(Vente*);
    void supprimerVente(Vente*);
    void setSalaire(float s) { salaire = s; }
    virtual float calculerSalaire(float=0) = 0;
     ~Personne();
};

