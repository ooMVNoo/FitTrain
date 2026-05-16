#include "LinReg.h"
#include<vector>
#include<iostream>
#include<random>

LinReg::LinReg(vector<vector<float>> x, vector<float> y,float LR,int TP):X(x),Y(y),lr(LR),trainPercent(TP){
    col= X[0].size();
    lin=X.size();
    X_lin=linearize(X);
    b=0;
    trainSetIndex=trainSet();
    linTS = trainSetIndex.size();

    if(linTS<=1000){
        mBatch_size=linTS;
    } else if(linTS>1000 && linTS<100000){
        mBatch_size=64;
    } else{
        mBatch_size=256;
    };

};



vector<int> LinReg::trainSet(){

    //J’ai compris qu’Afin d’optimiser la memoire on va seulement travailler donc sur  X  et le trainset sera un tableau des indices des lignes en faisant parties, j’étais parti sur recréer un tableau entier mais j’ai compris que ce n’était pas nécessaire et que ca nous épargnerais des ressources.

    while((trainSetIndex.size()*100)/lin<trainPercent){
        int i=rand()%lin ;
        while(val_in_tab(i,trainSetIndex)==true){
            i=rand()%lin ;
        };
        trainSetIndex.push_back(i);
    };

    return trainSetIndex;

};

vector<int> LinReg::batch(){
    for(int i=0;i<mBatch_size;i++){ //remplissage de mBatchIndex
                    int k = rand() % trainSetIndex.size();
                    while(val_in_tab(trainSetIndex[k], mBatch_index)){
                        k = rand() % trainSetIndex.size();
                    };
                    mBatch_index.push_back(trainSetIndex[k]);
                    trainSetIndex.erase(trainSetIndex.begin()+k);

            };
            return mBatch_index;
};

vector<float> LinReg::fit(){

    vector<int> tscopy=trainSetIndex;
    w.clear();

    //1ère étape : split train/test 
    

    //On initialise aléatoirement les poids et le biais

    for(int c=0;c<col;c++){
            w.push_back(float(rand()%10)*0.1);
        };


    //EPOCH: Boucle 

    vector<float> L;
    int nb_epoch=0;
    float dL;

    while((L.size()<2 || abs(dL) > 1e-6) && nb_epoch<=1000){

        if (L.size()>=2){
            dL = L[L.size()-1] - L[L.size()-2];
        }

        //BATCH: Boucle 
    
        vector<float> L_of_a_batch;

        while(trainSetIndex.size()>=mBatch_size){

            

            mBatch_index.clear();
            //1)initialisation de mBatchIndex et on vide en parallele trainSetIndex

            batch();
            

            //BATCH: la on trouve les poids 

            //2)On calcule les variable cible

            for(int i =0;i<mBatch_size;i++){
                float yi=b;
                for(int j=0;j<col;j++){
                    yi+=w[j]*X_lin[linIndex(mBatch_index[i],j)];
                };
                y_p.push_back(yi);
            };
                     
            //3)calcul epsilon et L

            vector<float> eps;

            for(int i=0;i<mBatch_size;i++){
                eps.push_back(Y[mBatch_index[i]]-y_p[i]);
            };
            float l=0;
            for(int i=0;i<mBatch_size;i++){
                l+=((float(1)/float(mBatch_size))*(eps[i])*(eps[i]));
            };

            L_of_a_batch.push_back(l);


            //4)calcul gradient de la fonction de cout : on utilisera MSE. MSE<=> L=1/n Σeps(i)^2 en calculant le gradient a la main(je derive d((yi-ypi)^2)=2 ( d/da (yi-ypi)) (y-yi) et d/da (yi-ypi) = somme de ( -xi1) donc et (yi-ypi) lui c'est eps i) j'obtient grad(L)=(1/n Σ -2x11eps1 ,...)

            vector<float> grad;
            
            for(int j=0;j<col;j++){
                float dldw=0;
                
                for(int i=0;i<mBatch_size;i++){
                    dldw=dldw-(2*X_lin[linIndex(mBatch_index[i],j)]*eps[i]);
                    
                };
                grad.push_back((1.0f/float(mBatch_size))*dldw);
            };

            float dldb = 0.0f;

            for(int i=0; i<mBatch_size; i++){
                dldb += -2.0f * eps[i];
            };
            dldb *= (1.0f / float(mBatch_size));

            //5)calcul w=pn+1=pn-lr*gradL et biais

            for(int k=0;k<w.size();k++){

                w[k]=w[k]-lr*grad[k];
                
            };

            b=b-lr*dldb;
        };
        float avgLofepoch=0;
        for(int n=0;n<L_of_a_batch.size();n++){
            avgLofepoch+=(1.0f/L_of_a_batch.size())*L_of_a_batch[n];
        }
        L.push_back(avgLofepoch);

        trainSetIndex=tscopy;

        nb_epoch++;

    };

    
    w.push_back(b);
    return w;

};

vector<float> LinReg::predict(vector<vector<float>> xp){

    vector<float> y;
    
    for(int i=0;i<xp.size();i++){

        float yp=0;

        for(int j=0;j<col;j++){
            yp+=w[j]*linearize(xp)[linIndex(i,j)];
        }

        y.push_back(yp+b);

    };
    return(y);
};

int LinReg::linIndex(int i,int j){
    return i*col+j;
};



    