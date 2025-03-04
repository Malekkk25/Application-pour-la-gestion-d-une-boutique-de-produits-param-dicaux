#include "Produit.h"


Produit::Produit() {
	nom = "";
	prix = 0;
	qteStock = 0;
}


Produit::Produit(string nom, float prix, int qteStock) {

	this->nom = nom;
	this->prix=prix;
	this->qteStock = qteStock;
}


Produit::Produit(const Produit& p) {
	nom = p.nom;
	prix = p.prix;
	qteStock = p.qteStock;
}


istream& operator>> (istream& in, Produit& p) {
	cout << "Veuillez saisir le libelle du produit : " << endl;
	in >> p.nom;
	cout << "Veuillez saisir le prix du produit : " << endl;
	in >> p.prix;
	cout << "Veuillez saisir la quantite du stock du produit : " << endl;
	in >> p.qteStock;

	return in;
}

ostream& operator<<(ostream& out, Produit& p) {
	out << "Le libelle du produit : " << p.nom<<endl;
	out << "Le prix du produit : " << p.prix<<endl;
	out << "La quantite du stock du produit : " << p.qteStock << endl;
	return out;
}


bool Produit::operator==(Produit& p) {
	if (nom == p.nom && prix == p.prix && qteStock == p.qteStock)
		return true;
	else return false;

}

void Produit::modifierProduit(Produit p) {
	if (!(p == *this)) {
		nom = p.nom;
		prix = p.prix;
		qteStock = p.qteStock;

	}
		
}
void Produit::ajouterQteStock(int q) {
	qteStock += q;
}
void Produit::diminuerQteStock(int q) {
	qteStock -= q;
}
Produit::~Produit(void) {

}
