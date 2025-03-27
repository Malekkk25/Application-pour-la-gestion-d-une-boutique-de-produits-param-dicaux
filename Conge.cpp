#include "Conge.h"
#include"Date.h"
#pragma once
#include<string>
#include <iostream>
#include<vector>
using namespace std;

Conge::Conge()
{
    date_debut.setjour(0);
    date_debut.setannee(0);
    date_debut.setmois(0);
    date_fin.setmois(0);
    date_fin.setannee(0);
    date_fin.setjour(0);
    duree = date_debut.duree(date_fin);
    statut = "";
}
ostream& operator<<(ostream& out, Conge& emp)
{
    out << "conge du:\t" << emp.date_debut << "au\t" << emp.date_fin << endl;
    out << "duree du conge:\t" << emp.duree << endl;
    out << "statut du conge:\t" << emp.statut << endl;
    return out;
}
istream& operator>>(istream& in, Conge& co)
{
    cout << "donner la date du debut du conge:\t";
    in >> co.date_debut;
    cout << "donner la date de fin du conge:\t";
    in >> co.date_fin;
    co.duree = co.date_debut.duree(co.date_fin);
    cout << "donner le statut du conge:\t";
    in >> co.statut;
    return in;
}

bool Conge::operator==(Conge& co)
{
    if (date_debut == co.date_debut)
        return false;
    if (date_fin == co.date_fin)
        return false;
    if (statut == co.statut)
        return false;
    return true;
}
Conge::~Conge()
{
    //destr
}
