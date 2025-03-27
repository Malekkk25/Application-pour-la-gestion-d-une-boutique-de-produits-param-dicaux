#include "EquipementMedical.h"
#include "OrthopedieEtMobilite.h"
EquipementMedical::EquipementMedical() :MaterielMedical(), OrthopedieEtMobilite(), poids(0.0), transportable(false) {}
/*EquipementMedical::EquipementMedical(string marque, string norme, float taille, string materiau, int poids_supporte, float poids, bool transportable, string nom)
    : MaterielMedical(norme,marque, nom), OrthopedieEtMobilite(taille, materiau, poids_supporte,nom), poids(poids), transportable(transportable) {
}
EquipementMedical::EquipementMedical(MaterielMedical& materiel, OrthopedieEtMobilite& ortho, float poids, bool transportable, string nomCat)
    : MaterielMedical(materiel), OrthopedieEtMobilite(ortho), poids(poids), transportable(transportable)
{
    this->setNomCat(nomCat);  
}*/  
EquipementMedical::EquipementMedical(const EquipementMedical& autre)
    : MaterielMedical(autre), OrthopedieEtMobilite(autre), Categorie(autre),
    poids(autre.poids), transportable(autre.transportable)
{}



void EquipementMedical::traiterPrix(float tva) {
    for (int i = 0; i < produits.size(); i++) {
        float n = produits[i]->getPrix() * (1 + tva / 100);
        produits[i]->setPrix(n);
    }

}



ostream& operator<<(ostream& out,  EquipementMedical& em) {
   
    MaterielMedical* mm = &em;
    out << *mm;  
    em.nomCat = "Equipement Medical";
    out << "Taille : " << em.taille << " m" << endl;
    out << "Material : " << em.material << endl;
    out << "Poids supporte : " << em.poids_supporte << " kg" << endl;
    out << "Poids : " << em.poids << " kg\n";
    out << "Transportable : " << em.transportable  << endl;
    return out;
}

istream& operator>>(istream& in, EquipementMedical& em) {
    
    MaterielMedical* mm = &em;
    in >> *mm; 

    em.nomCat = "Equipement Medical";
    cout << "Donnez la taille : ";
    in >> em.taille;
    cout << "Donnez le material : ";
    in >> em.material;
    cout << "Donnez le poids supporte : ";
    in >> em.poids_supporte;
    cout << "Donnez le poids de l'equipement (kg) : ";
    in >> em.poids;
    cout << "L'equipement est-il transportable ? (1: Oui, 0: Non) : ";
    in >> em.transportable;
    return in;
}





/*bool EquipementMedical::operator==(EquipementMedical& em) {

    if (!(MaterielMedical::operator==(static_cast<MaterielMedical&>(em)))) {
        return false;
    }
    if (!(OrthopedieEtMobilite::operator==(static_cast<OrthopedieEtMobilite&>(em)))) {
        return false;
    }
    return (poids == em.poids) &&
        (transportable == em.transportable);
}*/

EquipementMedical& EquipementMedical::operator=(EquipementMedical& em) {
    if (this != &em) {
        MaterielMedical* cat1 = this;
        MaterielMedical* cat2 = &em;

        *cat1 = *cat2;

        taille = em.taille;
        material = em.material;
        poids_supporte = em.poids_supporte;
        poids = em.poids;
        transportable = em.transportable;
    }
    return *this;
}



EquipementMedical::~EquipementMedical() {
  
}






