#ifndef LINREG_H
#define LINREG_H
#include<iostream>
#include<vector>
#include "FitTrain.h"

using namespace std;

enum LossType{MSE,BCE};


class LinReg : public FitTrain {
    private:

    //Attributs

    vector<vector<float>> X; //matrice des variables prédictrices   
    vector<float> Y; //Matrice de la variables cibles 
    vector<float> w; //vecteur des poids 
    vector<float> X_lin; //matrice des variables prédictrices linearisé
    vector<int> trainSetIndex; //vecteur representant les indices utiliser à l'entrainement
    vector<int> mBatch_index; //Vecteur des indices qui vont etre Batché
    vector<float> y_p; //vecteur des y prédit
    int col; //nombres de colonnes de X
    int lin; //nombres de lignes de X
    float lr;//learning rate
    float b;//biais
    int trainPercent;//taille du trainset en pourcent
    int mBatch_size;//taille du mini-batching
    int linTS;//nombre de ligne du ts

    //Methode
    
    vector<int> trainSet();//génere un trainSet aléatoire 
    vector<int> batch();//genere selon la taille du ts des "batch set"

    public:

    LinReg(vector<vector<float>> x, vector<float> y,float LR,int TP); //Constructeur 

    int linIndex(int i,int j);//linearise l'index : 2D->1D [i][j]->[k=i*col+j]
    
    vector<float> fit(LossType LT); //Calcule les poids de la régression linéaire
    vector<float> predict(vector<vector<float>> xp);//predit selon un vecteur de variable predictrice la variable cible

    float getB();
    

};




#endif
