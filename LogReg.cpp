#include "LogReg.h"
#include<vector>
#include<iostream>
#include<random>



LogReg::LogReg(vector<vector<float>> x, vector<float> y, float LR, int TP): LinReg(x, y, LR, TP){
    this->fit(BCE);

};

vector<float> LogReg::logistic_proba(vector<vector<float>> xp){
    vector<float> xp_score=predict(xp);

    vector<float> xp_proba;

    for(int i=0;i<xp_score.size();i++){
        xp_proba.push_back(1.0f/(1+exp(-xp_score[i])));
    };

    return xp_proba;
};

vector<float> LogReg::logistic_prediction(vector<vector<float>> xp,float seuil){
    vector<float> xp_proba=logistic_proba(xp);
    vector<float> xp_prediction;
    for(int i=0;i<xp_proba.size();i++){
        if(xp_proba[i]<seuil){
            xp_prediction.push_back(0);
        }
        else{
            xp_prediction.push_back(1);
        };
    };
    return xp_prediction;
};
