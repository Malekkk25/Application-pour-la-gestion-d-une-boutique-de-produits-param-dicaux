#pragma once
#include "Personne.h"

class Admin :
    public virtual Personne
{
    protected:
        string role;
    public:
        Admin();
        Admin(const Admin&);
        friend ostream& operator<<(ostream&, Admin&);
        friend istream& operator>>(istream&, Admin&);
        bool operator==(Admin&);
        float calculerSalaire(float=7);
        ~Admin();

 
};

