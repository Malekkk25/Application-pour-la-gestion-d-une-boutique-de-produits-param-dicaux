#include "HygieneEtSoins.h"



HygieneEtSoins::HygieneEtSoins() :Categorie(), volume(0.0), indication_utilisation("") {}


HygieneEtSoins::HygieneEtSoins(string indication, float volume, string nom)
    : Categorie(nom), volume(volume), indication_utilisation(indication) {
}


HygieneEtSoins::HygieneEtSoins( float volume, string indication_utilisation, string nomCat)
    : Categorie(nomCat), volume(volume), indication_utilisation(indication_utilisation)
{
   
}

HygieneEtSoins::HygieneEtSoins(const HygieneEtSoins& hygSoi): Categorie(hygSoi),volume(hygSoi.volume),
indication_utilisation(hygSoi.indication_utilisation),compositions(hygSoi.compositions) {}


ostream& operator<<(ostream& out,  HygieneEtSoins& hs) {
    Categorie* cat = &hs;
    out << *cat << endl;
    out << "Volume : " << hs.volume << " ml" << endl;
    out << "Indication d'utilisation : " << hs.indication_utilisation << endl;
    out << "Compositions chimiques contenues :" << endl;

    for (int i = 0; i < hs.compositions.size(); i++) {
        out << "Composition " << i + 1 << " : " << endl;
        out << hs.compositions[i] << endl;
    }
    return out;
}


istream& operator>>(istream& in, HygieneEtSoins& hs) {
    Categorie* cat = &hs;
    in >> *cat;
    cout << "Donnez le volume du produit (ml) : ";
    in >> hs.volume;
    cout << "Donnez l'indication d'utilisation : ";
    in >> hs.indication_utilisation;
    return in;
}





void HygieneEtSoins::ajouterComposition(CompositionChimique comp) {
    compositions.push_back(&comp);
    
}


void HygieneEtSoins::supprimerComposition(CompositionChimique comp) {
    int pos = chercherComposition(comp);

    if (pos == -1) {
        cout << "La composition n'est pas presente dans cette categorie." << endl;
    }
    else {
        delete compositions[pos];
        compositions.erase(compositions.begin() + pos);

    }
}


int HygieneEtSoins::chercherComposition(CompositionChimique comp) {
    for (int i = 0; i < compositions.size(); i++) {
        if (*(compositions[i]) == comp) {
            return i; 
        }
    }
    return -1; 
}
void HygieneEtSoins::traiterPrix(float tva) {
    for (int i = 0; i < produits.size(); i++) {
        float n = produits[i]->getPrix() * (1 + tva / 100);
        produits[i]->setPrix(n);
    }

}
HygieneEtSoins::~HygieneEtSoins() {
    for (int i = 0; i < compositions.size(); ++i) {
        delete compositions[i];

    }
}
