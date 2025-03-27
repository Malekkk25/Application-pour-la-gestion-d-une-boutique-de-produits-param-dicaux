#include "Parapharmacie.h"
#include "Employe.h"
#include "Admin.h"
#include "EmployeAdmin.h"
Parapharmacie::Parapharmacie()
{
    nom = "";
    adresse = "";
    telephone = "";
}
Parapharmacie::Parapharmacie(const Parapharmacie& other) : nom(other.nom), adresse(other.adresse), telephone(other.telephone) {
    for (size_t i = 0; i < other.personne.size(); i++)
        personne.push_back(other.personne[i]);
}

ostream& operator<<(ostream& out, Parapharmacie& para)
{
    out << "Nom de la parapharmacie = " << para.nom << endl;
    out << "Adresse = " << para.adresse << endl;
    out << "Telephone = " << para.telephone << endl;
    out << "Les employes de la parapharmacie:" << endl;
    for (int i = 0; i < para.personne.size(); i++)
    {
        out << "Employe " << i + 1 << " : " << *(para.personne[i]) << endl;
    }
    return out;
}

istream& operator>>(istream& in, Parapharmacie& para)
{
    cout << "Donner le nom de la parapharmacie : ";
    in >> para.nom;
    cout << "Donner l'adresse : ";
    in >> para.adresse;
    cout << "Le numero de telephone : ";
    in >> para.telephone;
    char rep;
    do
    {

        cout << "Voulez-vous ajouter un Employe (E) ou un Admin (A) ou un employe et admin en meme temps (B) ? ";
        char type;
        in >> type;
        if (type == 'E' || type == 'e') {
            Employe *p = new Employe();
            in >> *p;
            para.personne.push_back(p);
            
        }
        else if (type == 'A' || type == 'a') {
            Admin *p = new Admin(); 
            in >> *p;
            para.personne.push_back(p);
        }
        else if (type == 'B' || type == 'b') {
           EmployeAdmin *p = new EmployeAdmin();
           in >> *p;
           para.personne.push_back(p);
        }
        else {
            cout << "Choix invalide ! Veuillez entrer 'E' pour Employe ou 'A' pour Admin ou 'B' pour Employe admin." << endl;
            continue;
        }
        cout << "Voulez-vous ajouter un autre employe ? (o/n) ";
        in >> rep;
    } while (rep == 'o' || rep == 'O');

    return in;
}
bool Parapharmacie::operator==(Parapharmacie& para)
{
    if (nom == para.nom)
        return false;
    if (adresse == para.adresse)
        return false;
    if (telephone == para.telephone)
        return false;
    for (int i = 0; i < para.personne.size(); i++)
    {
        if (*personne[i] == *para.personne[i])
            return false;
    }
    return true;
}

void Parapharmacie::ajouterPersonne(Personne* p)
{

}

Parapharmacie::~Parapharmacie()
{
    
}
