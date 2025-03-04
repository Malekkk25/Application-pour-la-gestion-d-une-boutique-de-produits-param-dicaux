#include "CompositionChimique.h"


CompositionChimique::CompositionChimique(): nom(""), formule(""), origine(""), toxicite(false), temperature_decomposition(0.0) {}


CompositionChimique::CompositionChimique(string nom, string formule, string origine, bool toxicite, float tempDecomp): nom(nom), formule(formule), origine(origine), toxicite(toxicite),
temperature_decomposition(tempDecomp) {}


CompositionChimique::CompositionChimique(const CompositionChimique& comp): nom(comp.nom), formule(comp.formule), origine(comp.origine),
toxicite(comp.toxicite), temperature_decomposition(comp.temperature_decomposition) {}


ostream& operator<<(ostream& out, CompositionChimique& comp) {
    out << "Nom : " << comp.nom << endl;
    out << "Formule : " << comp.formule << endl;
    out << "Origine : " << comp.origine << endl;
    out << "Toxicite : " << comp.toxicite  << endl;
    out << "Temperature de Decomposition : " << comp.temperature_decomposition << "°C" << endl;
    return out;
}

istream& operator>>(istream& in, CompositionChimique& comp) {
    cout << "Entrez le nom : ";
    in >> comp.nom;
    cout << "Entrez la formule chimique : ";
    in >> comp.formule;
    cout << "Entrez l'origine : ";
    in >> comp.origine;
    cout << "La composition est-elle toxique ? (1 = Oui, 0 = Non) : ";
    in >> comp.toxicite;
    cout << "Entrez la température de décomposition (°C) : ";
    in >> comp.temperature_decomposition;
    return in;
}

// Opérateur d'égalité
bool CompositionChimique::operator==(const CompositionChimique& comp) const {
    return (nom == comp.nom &&
        formule == comp.formule &&
        origine == comp.origine &&
        toxicite == comp.toxicite &&
        temperature_decomposition == comp.temperature_decomposition);
}

// Méthode pour ajouter une composition chimique
void CompositionChimique::ajouterComposition(const CompositionChimique& comp) {
    cout << "Ajout de la composition chimique suivante :" << endl;
    cout << comp << endl;
}

// Getters
string CompositionChimique::getNom() const { return nom; }
string CompositionChimique::getFormule() const { return formule; }
string CompositionChimique::getOrigine() const { return origine; }
bool CompositionChimique::getToxicite() const { return toxicite; }
float CompositionChimique::getTemperatureDecomposition() const { return temperature_decomposition; }

// Setters
void CompositionChimique::setNom(const string& nom) { this->nom = nom; }
void CompositionChimique::setFormule(const string& formule) { this->formule = formule; }
void CompositionChimique::setOrigine(const string& origine) { this->origine = origine; }
void CompositionChimique::setToxicite(bool toxicite) { this->toxicite = toxicite; }
void CompositionChimique::setTemperatureDecomposition(float tempDecomp) { this->temperature_decomposition = tempDecomp; }
