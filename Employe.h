#pragma once
#include "Conge.h"
#include "Personne.h"
class Employe : public  virtual Personne
{
protected:
    string poste;
    Date date_embauche;
    int heures_travail;
    vector<Conge*> conge;

public:
    Employe();
    Employe(const Employe&);

    friend ostream& operator<<(ostream&, Employe&);
    friend istream& operator>>(istream&, Employe&);
    bool operator==(Employe&);

    bool demanderConge(Date&, Date&);
    float calculerSalaire(float=5);
    virtual ~Employe();
};

