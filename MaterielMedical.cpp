#include "MaterielMedical.h"

MaterielMedical::MaterielMedical() : Categorie(), marque(""), norme_certification("") {}

MaterielMedical::MaterielMedical( string marque, string norme_certification ,string nomCat)
    : Categorie(nomCat) , marque(marque), norme_certification(norme_certification) {
   
}

MaterielMedical::MaterielMedical(const MaterielMedical& mat)
    : Categorie(mat),   
    marque(mat.marque),
    norme_certification(mat.norme_certification)
{
   
}





ostream& operator<<(ostream& out,  MaterielMedical& mat) {
    Categorie* cat = &mat;
    out << *cat << endl;
    out << "Marque : " << mat.marque << endl;
    out << "Norme de Certification : " << mat.norme_certification << endl;
    return out;
}



istream& operator>>(istream& in, MaterielMedical& mat) {
    Categorie* cat = &mat;
    in >> *cat ;
    cout << "Donnez la marque du materiel medical : ";
    in >> mat.marque;
    cout << "Donnez la norme de certification : ";
    in >> mat.norme_certification;
    return in;
}


bool MaterielMedical::operator==(MaterielMedical& mat) {
    return ((Categorie&)(*this) == (Categorie&)(mat) &&  
        marque == mat.marque &&
        norme_certification == mat.norme_certification);
}

void MaterielMedical::traiterPrix(float tva) {
    for (int i = 0; i < produits.size(); i++) {
        float n = produits[i]->getPrix() * (1 + tva / 100);
        produits[i]->setPrix(n);
    }

}


MaterielMedical::~MaterielMedical(void) {
   
}





