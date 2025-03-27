#ifndef CONGE_H
#define CONGE_H
#include"Date.h"
#pragma once
#include<string>
#include <iostream>
#include<vector>
using namespace std;

class Conge
{
protected:
    Date date_debut;
    Date date_fin;
    string statut;
    int duree;
public:
    Conge();
    friend ostream& operator<<(ostream&, Conge&);
    friend istream& operator>>(istream&, Conge&);
    bool operator==(Conge&);
    Date getdate_debut() { return date_debut; }
    int getduree() { return duree; }
    virtual ~Conge();



};

#endif // CONGE_H
