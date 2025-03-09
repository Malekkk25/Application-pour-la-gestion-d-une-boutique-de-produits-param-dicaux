#pragma once
#include "Categorie.h"
class MaterielMedical : public virtual Categorie
{
protected:
    string marque;
    string norme_certification;

public:
    MaterielMedical();
    MaterielMedical(string , string, string = "Materiel Medical");
    MaterielMedical(const MaterielMedical& );

    friend ostream& operator<<(ostream& , MaterielMedical& );
    friend istream& operator>>(istream& ,MaterielMedical& );

 
    bool operator==(MaterielMedical& ) ;

    void traiterPrix(float=30);

    string getMarque() { return marque; };
    string getNormeCertification() {return norme_certification;};


    void setMarque(string& marque) {this->marque = marque;};
    void setNormeCertification(string norme_certification) {this->norme_certification = norme_certification;};

    ~MaterielMedical(void);
};

