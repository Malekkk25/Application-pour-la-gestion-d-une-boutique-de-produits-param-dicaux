#include "HygieneEtSoins.h"

HygieneEtSoins::HygieneEtSoins() :Categorie(), volume(0.0), indication_utilisation("") {}
/*HygieneEtSoins::HygieneEtSoins(string indication, float volume, string nom)
    : Categorie(nom), volume(volume), indication_utilisation(indication) {
}

HygieneEtSoins::HygieneEtSoins( float volume, string indication_utilisation, string nomCat)
    : Categorie(nomCat), volume(volume), indication_utilisation(indication_utilisation)
{}*/

HygieneEtSoins::HygieneEtSoins(const HygieneEtSoins& hs): Categorie(hs),volume(hs.volume),
indication_utilisation(hs.indication_utilisation) {

    for (int i = 0; i < hs.compositions.size(); i++)
    {
        CompositionChimique* c = new CompositionChimique(*hs.compositions[i]);
        compositions.push_back(c);
    }


}

ostream& operator<<(ostream& out, HygieneEtSoins& hs) {
    Categorie* cat = &hs;
    out << *cat << endl;
    out << "Volume : " << hs.getVolume() << " ml" << endl;
    out << "Indication d'utilisation : " << hs.getIndicationUtilisation() << endl;
    out << "Compositions chimiques contenues :" << endl;
    for (int i = 0; i < hs.getCompositions().size(); i++) {
        out << "Composition " << i + 1 << " :" << endl;
        out << *(hs.getCompositions()[i]) << endl;
    }
    return out;
}



istream& operator>>(istream& in, HygieneEtSoins& hs) {
    Categorie* cat = &hs;
    in >> *cat;

    hs.nomCat = "Hygiene Et Soins";
    cout << "Donnez le volume du produit (ml) : ";
    in >> hs.volume;
    cout << "Donnez l'indication d'utilisation : ";
    in >> hs.indication_utilisation;
    return in;
}


HygieneEtSoins& HygieneEtSoins::operator=(HygieneEtSoins& hs) {
    if (this != &hs) {
        Categorie* cat1 = this;
        Categorie* cat2 = &hs;

        *cat1 = *cat2;

        indication_utilisation = hs.indication_utilisation;
        volume = hs.volume;
        for (int i = 0; i < hs.compositions.size(); i++)
        {
            CompositionChimique* c = new CompositionChimique(*hs.compositions[i]);
            compositions.push_back(c);
        }
        
    }
    return *this;
}


void HygieneEtSoins::ajouterComposition(CompositionChimique* comp) {
    compositions.push_back(comp);}

void HygieneEtSoins::supprimerComposition(CompositionChimique* comp) {
    int pos = chercherComposition(comp);
    if (pos == -1) {
        cout << "La composition n'est pas presente dans cette categorie." << endl;
    }
    else {
        delete compositions[pos];
        compositions.erase(compositions.begin() + pos);}
}


int HygieneEtSoins::chercherComposition(CompositionChimique* comp) {
    for (int i = 0; i < compositions.size(); i++) {
        if (*(compositions[i]) == *comp) {
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