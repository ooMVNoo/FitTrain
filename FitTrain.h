#ifndef FITTRAIN_H
#define FITTRAIN_H
#include<iostream>
#include<vector>

using namespace std;


class FitTrain{

    public:

    bool val_in_tab(int val, vector<int>tab);//verifie qu'une valeur est dans un tableau
    vector<float> linearize(vector<vector<float>> tab); //transforme un tableau importé d'un CSV ( qui donne un vecteur de vecteur en vecteur 1D)
    virtual int linIndex(int i,int j)=0;//linearise l'index : 2D->1D [i][j]->[k=i*nb_colonne_tableau+j]


};



#endif
