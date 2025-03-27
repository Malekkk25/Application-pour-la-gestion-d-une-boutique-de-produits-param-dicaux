#include "OrthopedieEtMobilite.h"

OrthopedieEtMobilite::OrthopedieEtMobilite() : Categorie(), taille(0.0), material(""), poids_supporte(0) {}
/*OrthopedieEtMobilite::OrthopedieEtMobilite(float taille, string material, int poids_supporte, string nomCat)
    : Categorie(nomCat), taille(taille), material(material), poids_supporte(poids_supporte){}*/

OrthopedieEtMobilite::OrthopedieEtMobilite(const OrthopedieEtMobilite& ortho): Categorie(ortho), 
taille(ortho.taille), material(ortho.material), poids_supporte(ortho.poids_supporte) {}

ostream& operator<<(ostream& out, OrthopedieEtMobilite& ortho) {
    Categorie* cat = &ortho;
    out << *cat << endl;
    out << "Taille : " << ortho.taille << " m" << endl;
    out << "Material : " << ortho.material << endl;
    out << "Poids supporte : " << ortho.poids_supporte << " kg" << endl;
    return out;}

istream& operator>>(istream& in, OrthopedieEtMobilite& ortho) {
    Categorie* cat = &ortho;
    in >> *cat;

    ortho.nomCat = "Orthopedie Et Mobilite";
    cout << "Donnez la taille : ";
    in >> ortho.taille;
    cout << "Donnez le material : ";
    in >> ortho.material;
    cout << "Donnez le poids supporte : ";
    in >> ortho.poids_supporte;
    return in;}


/*bool OrthopedieEtMobilite::operator==(OrthopedieEtMobilite& ortho) {
    return ((Categorie&)(*this) == (Categorie&)(ortho) &&
        taille == ortho.taille &&
        material == ortho.material &&
        poids_supporte == ortho.poids_supporte);}*/


OrthopedieEtMobilite& OrthopedieEtMobilite::operator=(OrthopedieEtMobilite& ortho) {
    if (this != &ortho) {
        Categorie* cat1 = this;
        Categorie* cat2 = &ortho;

        *cat1 = *cat2;

         taille=ortho.taille;
         material=ortho.material;
         poids_supporte=ortho.poids_supporte;
    }
    return *this;
}

void OrthopedieEtMobilite::traiterPrix(float tva) {
    for (int i = 0; i < produits.size(); i++) {
        float n = produits[i]->getPrix() * (1 + tva / 100);
        produits[i]->setPrix(n);
    }
}

OrthopedieEtMobilite::~OrthopedieEtMobilite(void) {}


