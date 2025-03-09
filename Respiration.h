#pragma once
#include "MaterielMedical.h"
class Respiration : public MaterielMedical
{
protected:
    string type_respiratoire;
    float debit_maximal;
    float niveau_bruit;

public:
    Respiration();
    Respiration( string, string, string, float, float , string = "Respiration");
    Respiration(MaterielMedical& , string , float , float , string  = "Respiration");
    Respiration(const Respiration& resp);

    friend ostream& operator<<(ostream& ,  Respiration& );
    friend istream& operator>>(istream& , Respiration& );

  
    bool operator==( Respiration& resp) ;

    void traiterPrix(float=20);

    string getTypeRespiratoire() const { return type_respiratoire; }
    float getDebitMaximal() const { return debit_maximal; }
    float getNiveauBruit() const { return niveau_bruit; }


    void setTypeRespiratoire(const string& type) { type_respiratoire = type; }
    void setDebitMaximal(float debit) { debit_maximal = debit; }
    void setNiveauBruit(float bruit) { niveau_bruit = bruit; }
    ~Respiration();

};

