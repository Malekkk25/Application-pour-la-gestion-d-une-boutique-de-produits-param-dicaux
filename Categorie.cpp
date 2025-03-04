#include"Categorie.h"
#include <vector>
#include<iostream>
using namespace std;
Categorie::Categorie() {
	nomCat = "";
}

Categorie::Categorie(string nomCat) {
	this->nomCat = nomCat;
}

Categorie::Categorie(const Categorie& cat) {
	nomCat = cat.nomCat;
	
	for (int i = 0; i < cat.produits.size(); i++) {
		produits.push_back(new Produit(*cat.produits[i]));
	}
}

 ostream& operator<< (ostream& out, Categorie& cat) {
	 out << "La categorie est : " << cat.nomCat << endl;
	 out << "Liste des produits  :" << endl;
	 for (int i = 0; i < cat.produits.size(); i++) {
		 out << "Le produit " << i+1 << "est :" << *(cat.produits[i]) << endl;
	 }

	 return out;

}
 istream& operator>> (istream& in, Categorie& cat) {
	 cout << "Donnez le nom de la categorie : "<<endl;
	 in >> cat.nomCat;

	 char choix;
	 do {
		 Produit* p = new Produit(); 
		 in >> *p; 
		 cat.ajouterProduit(p); 

		 cout << "Voulez-vous ajouter un autre produit ? (o/n) : ";
		 in >> choix;
	 } while (choix == 'o' || choix == 'O');

	 return in;
 }



 bool Categorie::operator==( Categorie& cat)  {
	 if (nomCat != cat.nomCat) return false;
	 if (produits.size() != cat.produits.size()) return false;

	 for (int i = 0; i < produits.size(); i++) {
		 bool ok = false;
		 for (size_t j = 0; j < cat.produits.size(); j++) {
			 if (*produits[i] == *cat.produits[i]) {
				 ok = true;
				 break;
			 }
		 }
		 if (!ok) return false;
	 }
	 return true;
 }



void Categorie::ajouterProduit(Produit* p) {
	produits.push_back(p);
}

int Categorie::chercherProduit(Produit* p) {
	for (int i = 0; i < produits.size(); i++) {
		if (*(produits[i]) == *p) {
			return i; 
		}
	}
	return -1; 
}


void Categorie::supprimerProduit(Produit* p) {
	int pos = chercherProduit(p); 

	if (pos == -1) {
		cout << "Le produit n'est pas present dans cette categorie." << endl;
	}
	else {
		delete produits[pos]; 
		produits.erase(produits.begin() + pos);

	}
}



Produit Categorie::produitLePlusCher() {
	Produit max = *(produits[0]);
	for (int i = 0; i < produits.size(); i++) {
		if (produits[i]->getPrix() > max.getPrix())
			max = *(produits[i]);
	}
	return max;
}



Produit Categorie::produitLeMoinsCher() {
	Produit min = *(produits[0]);
	for (int i = 0; i < produits.size(); i++) {
		if (produits[i]->getPrix() <  min.getPrix())
			min = *(produits[i]);
	}
	return min;
}

Categorie::~Categorie() {
	for (int i = 0; i < produits.size(); i++) {
		delete produits[i];
	}
	produits.clear();
}

