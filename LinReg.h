#ifndef LINREG_H
#define LINREG_H
#include<iostream>
#include<vector>

using namespace std;


class LinReg {

    private:

    //Attributs

    vector<vector<float>> X; //matrice des variables prédictrices   
    vector<float> Y; //Matrice de la variables cibles 
    vector<float> w; //vecteur des poids 
    vector<float> X_lin; //matrice des variables prédictrices linearisé
    vector<int> trainSetIndex; //vecteur representant les indices utiliser à l'entrainement
    vector<int> mBatch_index;
    vector<float> y_p;
    int col; //nombres de colonnes de X
    int lin; //nombres de lignes de X
    float lr;//learning rate
    float b;//biais
    int trainPercent;//taille du trainset en pourcent
    int mBatch_size;//taille du mini-batching
    int linTS;//nombre de ligne du ts

    //Methode

    vector<int> trainSet();//génere un trainSet aléatoire selon le trainPercent de l'utilisateur 
    vector<int> batch();//genere selon la taille du ts des "batch set"






    public:

    LinReg(vector<vector<float>> x, vector<float> y,float LR,int TP); //Constructeur 
    vector<float> linearize(vector<vector<float>> tab); //transforme un tableau importé d'un CSV ( qui donne un vecteur de vecteur en vecteur 1D)
    int linIndex(int i,int j);//linearise l'index : 2D->1D [i][j]->[k=i*col+j]
    vector<float> fit(); //Calcule les poids de la régression linéaire
    bool val_in_tab(int val, vector<int>tab);//verifie qu'une valeur est dans un tableau
    float predict(vector<float> xp);//predit selon une ligne la variable cible
    

};




#endif