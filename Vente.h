#include"Date.h"
#pragma once
#include<string>
#include <iostream>
#include<vector>
#include"Produit.h"

using namespace std;
class Vente
{
protected:
    float montant;
    Date date_paiement;
    string validepar;
    vector<Produit*> produit;
public:
    Vente();
    Vente(const Vente& );
    friend ostream& operator<<(ostream&, Vente&);
    friend istream& operator>>(istream&, Vente&);
    bool operator==(Vente&);
    void ajouterProduit(Produit*);
    void supprimerProduit(Produit*);
    float calculerMontant();
    void ValiderPaiement();
     ~Vente();


};


