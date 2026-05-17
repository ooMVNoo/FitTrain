# FitTrain

Deux modèles de régression (linéaire et logistique) codés à la main en C++.  
Pas de dépendances externes, juste `vector` et `cmath`.

## Classes

### `FitTrain`

Classe de base utilitaire. Propose :
- `val_in_tab(int val, vector<int> tab)` : teste si une valeur est dans un tableau.
- `linearize(vector<vector<float>> tab)` : transforme une matrice en vecteur 1D.

Elle est abstraite (méthode `linIndex` virtuelle pure) : vous ne l’instanciez pas directement.

### `LinReg`

Régression linéaire classique.  
Constructeur :  
`LinReg(vector<vector<float>> X, vector<float> Y, float learningRate, int trainPercent)`  

Principales méthodes :
- `fit(LossType LT)` : entraîne le modèle. `LossType` peut être `MSE` (erreur quadratique) ou `BCE` (entropie croisée – utile pour la logistique). Retourne `vector<float>` des poids (le biais est stocké séparément, mais accessible dans l’attribut `b`).
- `predict(vector<vector<float>> Xp)` : retourne les prédictions (valeurs linéaires brutes pour `MSE`, logits pour `BCE`).

### `LogReg`

Hérite de `LinReg`. Ajoute deux méthodes pratiques pour la classification binaire :
- `logistic_proba(vector<vector<float>> Xp)` : retourne les probabilités (après sigmoïde).
- `logistic_prediction(vector<vector<float>> Xp, float seuil)` : retourne 0/1 selon le seuil (défaut 0.5).

## Compilation

Exemple avec `clang++` :

```bash
clang++ -std=c++17 -o mon_prog FitTrain.cpp LinReg.cpp LogReg.cpp votre_fichier_main.cpp

## Idée de base 

Afin de démontrer ma compréhension des bases du Machine learning et de ma maitrise du C++ je vais réaliser une bibliothèques de machine learning dans ce language,

On sait que C++ est sensible au niveau de l’allocation de mémoire, nos choix seront donc justifié nottament les Tableaux : afin d’être contigu et gagner en memoire on transformera notre matrice en vector , on « linéarise » donc notre matrice en codant [i][j]->[i*col+j]

On crée notre methode fit avec la méthode de la descente de gradient :

-1 ere étape : mini Batch 

On entraine notre algorithme sur des échantillons du train set (mini batch) 

J’ai compris qu’Afin d’optimiser la memoire on va seulement travailler donc sur un X linéarisé et le trainset sera un tableau des indices des lignes en faisant parties, j’étais parti sur recréer un tableau entier mais j’ai compris que ce n’était pas nécessaire et que ca nous épargnerais des ressources.


Le code s’articulera en 2 boucle : Une pour les miniBatch et qui traversera le Dataset et l'autres pour chaque Epoch

On utilisera la methode de descente de gradient :  on utilisera MSE. MSE<=> L=1/n Σeps(i)^2 en calculant le gradient a la main 

Un epoch s’arrete quand le delta du Loss devient negligeable (dl<1e-6)



