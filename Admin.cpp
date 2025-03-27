#include "Admin.h"


Admin::Admin()
{
    role = "";
}
Admin::Admin(const Admin& other) : Personne(other), role(other.role) {}


ostream& operator<<(ostream& out, Admin& a)
{
    out << "Informations de la personne :" << endl;
    Personne* per = &a;
    out << *per << endl;
    out << "Rôle de l'administrateur = " << a.role << endl;
    return out;
}

istream& operator>>(istream& in, Admin& a)
{
    Personne* per = &a;
    in >> *per ;
    cout << "donner le role de l admin:" << endl;
    in >> a.role;
    return in;
}
bool Admin::operator==(Admin& a)
{
    if (!(role == a.role))
        return false;
    return true;
}
float Admin::calculerSalaire(float i)
{
    return 2800;
}
Admin::~Admin()
{
    
}
