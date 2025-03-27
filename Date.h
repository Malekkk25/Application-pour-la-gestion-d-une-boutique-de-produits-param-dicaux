
#pragma once
#include<string>
#include <iostream>
#include<vector>
using namespace std;

class Date
{
private:
    int jour;
    int mois;
    int annee;

public:
    Date();
    Date(const Date& );
    friend ostream& operator<<(ostream&, Date&);
    friend istream& operator>>(istream&, Date&);
    bool operator==(Date&);
    int duree(Date&);
    int setjour(int j) { return jour = j; }
    int setmois(int m) { return mois = m; }
    int setannee(int a) { return annee = a; }
    int getannee() { return annee; }
};


