#pragma once
#include<string>
#include <iostream>
#include<vector>
#include "Produit.h"
using namespace std;
class Categorie
{
protected:
	string nomCat;
	vector<Produit*> produits;

public:
	Categorie();
	Categorie(const Categorie&);


	friend ostream& operator<< (ostream&,  Categorie&);
	friend istream& operator>> (istream&, Categorie&);	


	Categorie& operator=(const Categorie&);


	int chercherProduit(Produit*);
	void ajouterProduit(Produit*);
	void supprimerProduit(Produit*);
	Produit produitLePlusCher();
	Produit produitLeMoinsCher();

	virtual void traiterPrix(float) = 0;

	string getNomCat()  { return nomCat; }
	vector<Produit*> getProduits()  { return produits; }
	void setNomCat(const string& nom) { nomCat = nom; }



	~Categorie(void);
};

