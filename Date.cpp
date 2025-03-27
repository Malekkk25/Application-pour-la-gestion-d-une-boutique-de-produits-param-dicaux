#include "Date.h"
#pragma once
#include<string>
#include <iostream>
#include<vector>
using namespace std;

Date::Date()
{
    jour = 0;
    mois = 0;
    annee = 0;
}
Date::Date(const Date& other) {
    jour = other.jour;
    mois = other.mois;
    annee = other.annee;
}

ostream& operator<<(ostream& out, Date& d)
{
    out << d.jour << "/" << d.mois << "/" << d.annee;
    return out;
}

istream& operator>>(istream& in, Date& d)
{
    in >> d.jour >> d.mois >> d.annee;
    return in;
}

bool Date::operator==(Date& d)
{
    if (jour != d.jour)
        return false;
    if (mois != d.mois)
        return false;
    if (annee != d.annee)
        return false;
    return true;
}
int Date::duree(Date& d)
{
    if (mois < d.mois)
    {
        switch (d.mois)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return d.jour + 31 - jour;
        case 4: case 6: case 9: case 11:
            return d.jour + 30 - jour;
        case 2:
        {
            if (annee % 4 == 0)
                return d.jour + 29 - jour;
            else
                return d.jour + 28 - jour;
        }
        }
    }
    else
        return d.jour - jour;
}

