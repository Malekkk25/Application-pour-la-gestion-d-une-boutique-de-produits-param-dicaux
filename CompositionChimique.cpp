#include "CompositionChimique.h"


CompositionChimique::CompositionChimique(): nom(""), formule(""), origine(""), toxicite(false), temperature_decomposition(0.0) {}
/*CompositionChimique::CompositionChimique(string nom, string formule, string origine, bool toxicite, float tempDecomp) : nom(nom), formule(formule),
origine(origine), toxicite(toxicite),
temperature_decomposition(tempDecomp) {}*/

CompositionChimique::CompositionChimique(const CompositionChimique& comp): nom(comp.nom), formule(comp.formule), origine(comp.origine),
toxicite(comp.toxicite), temperature_decomposition(comp.temperature_decomposition) {}

ostream& operator<<(ostream& out, CompositionChimique& comp) {
    out << "Nom : " << comp.nom << endl;
    out << "Formule : " << comp.formule << endl;
    out << "Origine : " << comp.origine << endl;
    out << "Toxicite : " << comp.toxicite  << endl;
    out << "Temperature de Decomposition : " << comp.temperature_decomposition << "°C" << endl;
    return out;}

istream& operator>>(istream& in, CompositionChimique& comp) {
    cout << "Donnez le nom : ";
    in >> comp.nom;
    cout << "Donnez la formule chimique : ";
    in >> comp.formule;
    cout << "Donnez l'origine : ";
    in >> comp.origine;
    cout << "La composition est-elle toxique ? (1 = Oui, 0 = Non) : ";
    in >> comp.toxicite;
    cout << "Donnez la temperature de decomposition (°C) : ";
    in >> comp.temperature_decomposition;
    return in;}


bool CompositionChimique::operator==(CompositionChimique& comp) {
    return (nom == comp.nom &&
        formule == comp.formule &&
        origine == comp.origine &&
        toxicite == comp.toxicite &&
        temperature_decomposition == comp.temperature_decomposition);
}

CompositionChimique& CompositionChimique::operator=(const CompositionChimique& cs) {
    if (this != &cs) { 
        nom = cs.nom;
        formule = cs.formule;
        origine = cs.origine;
        toxicite = cs.toxicite;
        temperature_decomposition = cs.temperature_decomposition;
    }
    return *this;
}






