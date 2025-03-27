#include "Employe.h"
#include "Conge.h"
#include"Date.h"
#include<string>
#pragma once

#include <iostream>
using namespace std;
Employe::Employe()
{
    poste = "";
    date_embauche.setjour(0);
    date_embauche.setmois(0);
    date_embauche.setannee(0);
    heures_travail = 0;
}

Employe::Employe(const Employe& other) : Personne(other), poste(other.poste), date_embauche(other.date_embauche), heures_travail(other.heures_travail) {
    for (size_t i = 0; i < other.conge.size(); i++)
        conge.push_back(new Conge(*other.conge[i]));
}

ostream& operator<<(ostream& out, Employe& e)
{
    out << "Informations de la personne :" << endl;
    Personne* per = &e;
    out << *per << endl;
    out << "Poste = " << e.poste << endl;
    out << "Date d'embauche = " << e.date_embauche << endl;
    out << "Heures de travail = " << e.heures_travail << endl;
    out << "Liste des conges :" << endl;
    for (int i = 0; i < e.conge.size(); i++)
        out << "Conge " << i + 1 << " : " << *e.conge[i] << endl;
    return out;
}

istream& operator>>(istream& in, Employe& e)
{
    Conge* c;
    char rep;
    Personne* per = &e;
    in >> *per;
    cout << "Donner le poste de l'employe : ";
    in >> e.poste;
    cout << "Donner la date d'embauche de l'employe : ";
    in >> e.date_embauche;
    cout << "Donner le volume horaire de travail de l'employe : ";
    in >> e.heures_travail;

    cout << "Voulez-vous ajouter des conges pour cet employe ? (o/n) : ";
    in >> rep;

    while (rep == 'o' || rep == 'O') {
        c = new Conge;
        in >> *c;
        e.conge.push_back(c);
        cout << "Voulez-vous ajouter un autre conge ? (o/n) : ";
        in >> rep;
    }

    return in;
}

bool Employe::operator==(Employe& e)
{
    if (!(poste == e.poste))
        return false;
    if (!(date_embauche == e.date_embauche))
        return false;
    if (heures_travail == e.heures_travail)
        return false;
    for (int i = 0; i < e.conge.size(); i++)
    {
        if (!(*conge[i] == *e.conge[i]))
            return false;
    }
    return true;
}
bool Employe::demanderConge(Date& dd, Date& df)
{
    int anne, dureetot;
    cout << "donner l anne actuelle:\t";
    cin >> anne;
    dureetot = dd.duree(df);
    for (int i = 0; i < conge.size(); i++)
    {
        if (conge[i]->getdate_debut().getannee() == anne)
            dureetot += conge[i]->getduree();
    }
    return (dureetot <= 30);


}

float Employe::calculerSalaire(float i)
{
    if (niveau_acces == 1)
        salaire = (5 * heures_travail) * 30;
    if (niveau_acces == 2)
        salaire = (7 * heures_travail) * 30;
    if (niveau_acces == 3)
        salaire = (10 * heures_travail) * 30;
    return salaire;
}

Employe::~Employe()
{
}
