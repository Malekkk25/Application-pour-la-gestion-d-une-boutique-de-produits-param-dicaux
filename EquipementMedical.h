#pragma once
#include "MaterielMedical.h"
#include"OrthopedieEtMobilite.h"
class EquipementMedical :public virtual  MaterielMedical,public virtual OrthopedieEtMobilite
{
protected:
    float poids;
    bool transportable;

public:

    EquipementMedical();
    EquipementMedical(string,string , float, string, int, float, bool, string = "Equipement Medical");
    EquipementMedical(MaterielMedical& , OrthopedieEtMobilite& , float , bool , string  = "Equipement Medical");

    EquipementMedical(const EquipementMedical& );

    void traiterPrix(float = 20);
    friend ostream& operator<<(ostream& out,  EquipementMedical& );
    friend istream& operator>>(istream& in, EquipementMedical& );

    bool operator==(EquipementMedical& em);
     ~EquipementMedical();
        



};

