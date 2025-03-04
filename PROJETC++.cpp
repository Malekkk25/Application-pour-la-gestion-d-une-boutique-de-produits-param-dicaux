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
    cin >> equip1;  // Demander � l'utilisateur de saisir les informations

    cout << "Equipement Medical cr��: " << endl;
    cout << equip1 << endl;  // Afficher les informations saisies

    // Test de la recopie
    EquipementMedical equip2 = equip1;  // Constructeur de recopie
    cout << "Equipement Medical apr�s recopie: " << endl;
    cout << equip2 << endl;

    // Comparaison de deux objets EquipementMedical
    if (equip1 == equip2) {
        cout << "Les deux �quipements m�dicaux sont identiques." << endl;
    }
    else {
        cout << "Les deux �quipements m�dicaux sont diff�rents." << endl;
    }

    return 0;
}
