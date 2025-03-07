#include "Respiration.h"

Respiration::Respiration() : MaterielMedical(), type_respiratoire(""), debit_maximal(0.0), niveau_bruit(0.0) {}

Respiration::Respiration( string marque, string norme_certification, string type_respiratoire, float debit_maximal, float niveau_bruit , string nomCategorie) :MaterielMedical(nomCategorie, marque, norme_certification),
type_respiratoire(type_respiratoire), debit_maximal(debit_maximal), niveau_bruit(niveau_bruit) {}


Respiration::Respiration(const Respiration& resp): MaterielMedical(resp),
type_respiratoire(resp.type_respiratoire),debit_maximal(resp.debit_maximal),niveau_bruit(resp.niveau_bruit) {}


ostream& operator<<(ostream& out,  Respiration& res) {
    MaterielMedical* mat = &res;
    out << *mat;
    out << "Type Respiratoire : " << res.type_respiratoire << endl;
    out << "Debit Maximal : " << res.debit_maximal << " L/min" << endl;
    out << "Niveau de Bruit : " << res.niveau_bruit << " dB" << endl;
    return out;
}


istream& operator>>(istream& in, Respiration& res) {
    MaterielMedical* mat = &res;
    in >> *mat;
    cout << "Donnez le type respiratoire : ";
    in >> res.type_respiratoire;
    cout << "Donnez le debit maximal (L/min) : ";
    in >> res.debit_maximal;
    cout << "Donnez le niveau de bruit (dB) : ";
    in >> res.niveau_bruit;
    return in;
}

bool Respiration::operator==( Respiration& resp)  {
    return ((MaterielMedical&)(*this) == (MaterielMedical&)(resp)) &&
        type_respiratoire == resp.type_respiratoire &&
        debit_maximal == resp.debit_maximal &&
        niveau_bruit == resp.niveau_bruit;
}

void Respiration::traiterPrix(float tva) {
    for (int i = 0; i < produits.size(); i++) {
        float n = produits[i]->getPrix() * (1 + tva / 100); 
        produits[i]->setPrix(n); 
    }

}

Respiration::~Respiration() {}