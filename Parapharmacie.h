#ifndef PARAPHARMACIE_H
#define PARAPHARMACIE_H

#pragma once
#include<string>
#include <iostream>
#include<vector>
#include "Personne.h"
#include "Categorie.h"
class Parapharmacie
{
protected:
    string nom;
    string adresse;
    string telephone;
    vector <Personne*> personne;
    vector <Categorie*> cat;
public:
    Parapharmacie();
    Parapharmacie(const Parapharmacie&);
    friend ostream& operator<<(ostream&, Parapharmacie&);
    friend istream& operator>>(istream&, Parapharmacie&);
    bool operator==(Parapharmacie&);
    void ajouterPersonne(Personne*);

    void supprimerPersonne(Personne*);
    ~Parapharmacie();
};

#endif // PARAPHARMACIE_H
