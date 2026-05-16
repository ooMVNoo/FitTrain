#ifndef LOGREG_H
#define LOGREG_H
#include<iostream>
#include<vector>
#include "LinReg.h"

using namespace std;

class LogReg : public LinReg {
    public:
    vector<float> logistic_proba(vector<vector<float>> xp); //donne les probas pour une regression logistique pour un tableau d'entrées xp
    vector<float> logistic_prediction(vector<vector<float>> xp,float seuil); // classifioe un teableau d'entrée en 0,1 
};

#endif