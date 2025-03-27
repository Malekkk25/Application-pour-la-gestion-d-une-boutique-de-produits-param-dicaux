#ifndef EMPLOYEADMIN_H
#define EMPLOYEADMIN_H
#pragma once
#include"Employe.h"
#include"Admin.h"

class EmployeAdmin : public virtual Employe, public virtual Admin
{
protected:
    Date date_promotion;
    string responsablites;
public:
    EmployeAdmin();
    EmployeAdmin(const EmployeAdmin&);
    friend ostream& operator<<(ostream&, EmployeAdmin&);
    friend istream& operator>>(istream&, EmployeAdmin&);
    float calculerSalaire(float=10) override;

    bool operator==(EmployeAdmin&);
     ~EmployeAdmin();




};

#endif // EMPLOYEADMIN_H
