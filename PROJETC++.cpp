#include <iostream>
#include "Categorie.h"
#include "Produit.h"
#include "MaterielMedical.h"
#include "OrthopedieEtMobilite.h"
#include "Respiration.h"
#include "EquipementMedical.h"
using namespace std;

int main() {
    EquipementMedical equip1;
    cin >> equip1;  // Demander à l'utilisateur de saisir les informations

    cout << "Equipement Medical créé: " << endl;
    cout << equip1 << endl;  // Afficher les informations saisies

    // Test de la recopie
    EquipementMedical equip2 = equip1;  // Constructeur de recopie
    cout << "Equipement Medical après recopie: " << endl;
    cout << equip2 << endl;

    // Comparaison de deux objets EquipementMedical
    if (equip1 == equip2) {
        cout << "Les deux équipements médicaux sont identiques." << endl;
    }
    else {
        cout << "Les deux équipements médicaux sont différents." << endl;
    }

    return 0;
}
