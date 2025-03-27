#pragma once
#include "MaterielMedical.h"
#include"OrthopedieEtMobilite.h"
class EquipementMedical :public   MaterielMedical,public  OrthopedieEtMobilite
{
protected:
    float poids;
    bool transportable;

public:

    EquipementMedical();
    /*EquipementMedical(string, string, float, string, int, float, bool, string = "Equipement Medical");
    EquipementMedical(MaterielMedical& , OrthopedieEtMobilite& , float , bool , string  = "Equipement Medical");*/

    EquipementMedical(const EquipementMedical& );

    void traiterPrix(float = 20);
    friend ostream& operator<<(ostream& ,  EquipementMedical& );
    friend istream& operator>>(istream& , EquipementMedical& );

    //bool operator==(EquipementMedical& em);
    EquipementMedical& operator=(EquipementMedical& em);

     ~EquipementMedical();
        



};

