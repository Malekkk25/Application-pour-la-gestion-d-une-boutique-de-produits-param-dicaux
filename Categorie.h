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
	Categorie(string);
	Categorie(const Categorie&);

	friend ostream& operator<< (ostream&,  Categorie&);
	friend istream& operator>> (istream&, Categorie&);	


	bool operator==(Categorie&);


	string getNomCat()  { return nomCat; }
	vector<Produit*> getProduits()  { return produits; }

	void setNomCat(const string& nom) { nomCat = nom; }

	int chercherProduit(Produit *p);
	void ajouterProduit(Produit *p);
	void supprimerProduit(Produit *p);
	Produit produitLePlusCher();
	Produit produitLeMoinsCher();

	virtual void traiterPrix(float)=0;

	virtual ~Categorie(void);

};

