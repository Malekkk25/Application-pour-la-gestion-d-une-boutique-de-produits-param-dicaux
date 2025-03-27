#include "EmployeAdmin.h"
#include"Employe.h"
#include"Admin.h"

EmployeAdmin::EmployeAdmin()
{
    responsablites = "";
}

EmployeAdmin::EmployeAdmin(const EmployeAdmin& other) : Personne(other), Employe(other), Admin(other), date_promotion(other.date_promotion), responsablites(other.responsablites) {}









ostream& operator<<(ostream& out, EmployeAdmin& empa)
{
    out << "=== Informations de l'employe administratif ===" << endl;
    Employe* emp = &empa;
    out << *emp;
    out << "Rôle de l'administrateur = " << empa.role << endl;
    out << "Date de promotion = " << empa.date_promotion << endl;
    out << "Responsabilites = " << empa.responsablites << endl;
    return out;
}

istream& operator>>(istream& in, EmployeAdmin& empa)
{   
    Employe* mm = &empa;
    in >> *mm;
    cout << "donner le role de l admin:" << endl;
    in >> empa.role;
    cout << "donner la date de promotion de l employe:\t";
    in >> empa.date_promotion;
    cout << "donner les responsabilites de l employe:" << endl;
    in >> empa.responsablites;
    return in;
}

bool EmployeAdmin::operator==(EmployeAdmin& empa)
{
    if (!(date_promotion == empa.date_promotion))
        return false;
    if (responsablites != empa.responsablites)
        return false;
    return true;
}
float EmployeAdmin::calculerSalaire(float) {
    return Employe::calculerSalaire() + 900;
}

EmployeAdmin::~EmployeAdmin()
{
    
}
