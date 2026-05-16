#include "FitTrain.h"
#include<vector>
#include<iostream>
#include<random>

using namespace std;

bool FitTrain::val_in_tab(int val, vector<int>tab){
        for(int i=0;i<tab.size();i++){
            if(tab[i]==val){
                return true;
            };
        };
        return false;
    };

vector<float> FitTrain::linearize(vector<vector<float>> tab){
    int col=tab[0].size();
    vector<float> linearizeTab;
    for(int i=0;i<tab.size();i++){
        for(int j=0;j<tab[i].size();j++){
            linearizeTab.push_back(tab[i][j]);   
        };
    };
    return linearizeTab;
};