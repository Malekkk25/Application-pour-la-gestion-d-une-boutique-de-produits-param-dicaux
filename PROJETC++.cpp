#include "Respiration.h"
#include <iostream>

using namespace std;

int main() {
    // Création d'objets Respiration
    Respiration res1("Soins Intensifs", "Philips", "ISO 9001", "Oxygénothérapie", 60.0, 45.0);
    Respiration res2("Soins ", "Philips", "ISO 9001", "Oxygénothérapie", 60.0, 45.0);
    Respiration res3("Chirurgie", "GE Healthcare", "CE", "Ventilation Assistée", 80.0, 55.0);

    // Affichage des objets
    cout << "Appareil Respiratoire 1 :" << endl << res1 << endl;
    cout << "Appareil Respiratoire 2 :" << endl << res2 << endl;
    cout << "Appareil Respiratoire 3 :" << endl << res3 << endl;

    // Test de l'opérateur ==
    if (res1 == res2) {
        cout << "res1 et res2 sont identiques." << endl;
    }
    else {
        cout << "res1 et res2 sont différents." << endl;
    }

    if (res1 == res3) {
        cout << "res1 et res3 sont identiques." << endl;
    }
    else {
        cout << "res1 et res3 sont différents." << endl;
    }

    // Saisie d'un nouvel appareil respiratoire
    Respiration resUser;
    cout << "\nEntrez un nouvel appareil respiratoire :" << endl;
    cin >> resUser;

    // Affichage après saisie
    cout << "Appareil Respiratoire saisi :" << endl << resUser << endl;

    // Test des Getters et Setters
    cout << "\nModification de resUser via Setters..." << endl;
    resUser.setTypeRespiratoire("Assistance Respiratoire");
    resUser.setDebitMaximal(75.0);
    resUser.setNiveauBruit(48.0);

    cout << "Type Respiratoire mis à jour : " << resUser.getTypeRespiratoire() << endl;
    cout << "Débit Maximal mis à jour : " << resUser.getDebitMaximal() << " L/min" << endl;
    cout << "Niveau de Bruit mis à jour : " << resUser.getNiveauBruit() << " dB" << endl;

    return 0;
}
