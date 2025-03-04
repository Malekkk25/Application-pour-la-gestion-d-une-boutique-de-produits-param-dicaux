#pragma once
#include "Categorie.h"
#include"CompositionChimique.h"
class HygieneEtSoins : public Categorie
{
protected:
    float volume;
    string indication_utilisation;
    vector<CompositionChimique*> compositions; 

public:
   
    HygieneEtSoins();
    HygieneEtSoins(string, float, string = "Hygiene Et Soins");
    HygieneEtSoins(Categorie  ,float , string , string  = "Hygiene Et Soins");
    HygieneEtSoins(const HygieneEtSoins& other);


    friend ostream& operator<<(ostream& ,  HygieneEtSoins& );
    friend istream& operator>>(istream& , HygieneEtSoins& );


    void ajouterComposition(CompositionChimique );
    void supprimerComposition(CompositionChimique);
    int chercherComposition(CompositionChimique) ;

   
    float getVolume() const { return volume; }
    string getIndicationUtilisation() const { return indication_utilisation; }
    vector<CompositionChimique*> getCompositions() const { return compositions; }

    void setVolume(float vol) { volume = vol; }
    void setIndicationUtilisation(const string& indication) { indication_utilisation = indication; }

    ~HygieneEtSoins(void);

};

