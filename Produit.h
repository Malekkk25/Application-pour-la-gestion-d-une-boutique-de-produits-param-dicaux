#pragma once
#include<string>
#include <iostream>
using namespace std;
class Produit
{
protected:
	string nom ;
	float prix;
	int qteStock;

public:
	Produit();
	Produit(string, float, int);
	Produit(const Produit&);

	friend ostream& operator<< (ostream&, Produit&);
	friend istream& operator>> (istream&, Produit&);

	bool operator==(Produit&);

	string getNom()  { return nom; }
	float getPrix()  { return prix; }
	int getQteStock() { return qteStock; }

	void setNom( string newNom) { nom = newNom; }
	void setPrix(float newPrix) { prix = newPrix; }
	void setQteStock(int newQteStock) { qteStock = newQteStock; }

	void modifierProduit(Produit);
	void ajouterQteStock(int);
	void diminuerQteStock(int);
	~Produit(void);

};

