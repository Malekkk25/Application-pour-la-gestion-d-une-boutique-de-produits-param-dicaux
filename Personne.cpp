#include "Personne.h"
#include <vector>
#include<iostream>
using namespace std;
Personne::Personne()
{
    nom = "";
    prenom = "";
    mdp = "";
    niveau_acces = 0;
    salaire = 0;
}

Personne::Personne(const Personne& other) : nom(other.nom), prenom(other.prenom), date_naiss(other.date_naiss), mdp(other.mdp), niveau_acces(other.niveau_acces), salaire(other.salaire) {
    for (size_t i = 0; i < other.vente.size(); i++)
        vente.push_back(new Vente(*other.vente[i]));
}

ostream& operator<<(ostream& out, Personne& p)
{
    out << "Nom = " << p.nom << endl;
    out << "Prenom = " << p.prenom << endl;
    out << "Date de naissance = " << p.date_naiss << endl;
    out << "Niveau d'accès = " << p.niveau_acces << endl;
    out << "Salaire = " << p.salaire << endl;
    out << "Liste des ventes :" << endl;
    for (int i = 0; i < p.vente.size(); i++) {
        out << "Vente " << i + 1 << " : " << endl;
        out << *p.vente[i] << endl;
    }
    return out;
}

istream& operator>>(istream& in, Personne& p)
{
    cout << "donner le nom et le prenom de l employe:\t";
    in >> p.nom >> p.prenom;
    cout << "donner le date de naissance:\t";
    in >> p.date_naiss;
    cout << "entrer le mot de passe:\t";
    in >> p.mdp;
    cout << "que est le niveau d acces de l employe?\t";
    in >> p.niveau_acces;
    return in;
}
bool Personne::operator==(Personne& p)
{
    if (nom == p.nom)
        return false;
    if (prenom == p.prenom)
        return false;
    if (date_naiss == p.date_naiss)
        return false;
    if (salaire == p.salaire)
        return false;
    for (int i = 0; i < p.vente.size(); i++)
    {
        if (*vente[i] == *p.vente[i])
            return false;
    }
    return true;
}
void Personne::ajouterVente(Vente* v)
{
    vente.push_back(v);
}

void Personne::supprimerVente(Vente* v)
{
    int i = 0, p = 0;
    do
    {
        if (*(vente[i]) == *v)
        {
            vente.erase(vente.begin() + i);
            p++;
        }
        i++;
    } while (i < vente.size());
    if (p == 0)
        cout << "vente inexistante";
}


Personne::~Personne()
{
    //dtor
}
