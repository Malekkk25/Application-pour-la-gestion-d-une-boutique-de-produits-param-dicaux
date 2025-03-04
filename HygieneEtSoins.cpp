#include "HygieneEtSoins.h"



HygieneEtSoins::HygieneEtSoins() : volume(0.0), indication_utilisation("") {}


HygieneEtSoins::HygieneEtSoins(float volume, string indication): volume(volume), indication_utilisation(indication) {}


HygieneEtSoins::HygieneEtSoins(const HygieneEtSoins& hygSoi)
: volume(hygSoi.volume), indication_utilisation(hygSoi.indication_utilisation),compositions(hygSoi.compositions) {}


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