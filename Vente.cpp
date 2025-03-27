#include "Vente.h"
#include"Personne.h"
#include<string>
#include <iostream>
#include<vector>
using namespace std;
Vente::Vente()
{
    montant = 0;
    validepar="";
}
Vente::Vente(const Vente& other) {
    montant = other.montant;
    date_paiement = Date(other.date_paiement);
    validepar = other.validepar;

 
    for (Produit* p : other.produit) {
        produit.push_back(new Produit(*p)); 
    }
}


ostream& operator<<(ostream& out, Vente& v)
{
    out << v.date_paiement << endl;
    out << v.validepar;
    for (int i = 0; i < v.produit.size(); i++)
        out << *v.produit[i] << "\t";
    out << "montant a payer:\t";
    out << v.montant;
    return out;
}
istream& operator>>(istream& in, Vente& v)
{
    cout << "donner la date de la vente:\t";
    in >> v.date_paiement;
    cout << "vendeur responsable:\t";
    in >> v.validepar;

    char rep;
    float s = 0;
    do
    {
        Produit *pro = new Produit();
        in >> *pro;
        s += (pro->getPrix() * pro->getQteStock());
        v.produit.push_back(pro);
        cout << "voulez vous ajouter un autre produit?\t";
        in >> rep;
    } while (rep == 'o' || rep == 'O');
    v.montant = s;
    return in;
}
bool Vente::operator==(Vente& v)
{
    if (date_paiement == v.date_paiement)
        return false;
    if (validepar == v.validepar)
        return false;
    if (montant == v.montant)
        return false;
    for (int i = 0; i < produit.size(); i++)
    {
        if (*produit[i] == *v.produit[i])
            return false;
    }
    return true;
}
void Vente::ajouterProduit(Produit* p)
{
    produit.push_back(p);
}

void Vente::supprimerProduit(Produit*p)
{
    int i = 0, pos = 0;
    do
    {
        if (*(produit[i]) == *p)
        {
            produit.erase(produit.begin() + i);
            pos++;
        }
        i++;
    } while (i < produit.size());
    if (pos == 0)
        cout << "produit inexistant" << endl;
}

Vente::~Vente()
{
    //dtor
}
