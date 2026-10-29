# Régression linéaire et logistique en C++

Implémentation de la régression linéaire et de la régression logistique par descente de gradient par mini-batch, sans dépendance externe.

## Structure

| Fichier | Rôle |
|---|---|
| `FitTrain.h/.cpp` | Classe abstraite : utilitaires communs (linéarisation d'un tableau 2D, recherche d'une valeur dans un tableau) |
| `LinReg.h/.cpp` | Régression linéaire ; entraînement avec perte MSE ou BCE |
| `LogReg.h/.cpp` | Régression logistique, dérivée de `LinReg` |
| `test.cpp` | Exemple d'utilisation |

## Fonctionnement

- Le jeu d'entraînement est un sous-ensemble aléatoire de `X`, défini par un pourcentage. Seuls les indices des lignes sont stockés.
- La taille du mini-batch dépend de la taille du jeu d'entraînement : entière jusqu'à 1 000 lignes, 64 jusqu'à 100 000, puis 256.
- Les poids sont initialisés aléatoirement, le biais à zéro.
- L'entraînement s'arrête lorsque la variation de la perte entre deux époques passe sous `1e-6`, ou après 1 000 époques.

## Utilisation

```cpp
#include "LinReg.h"

LinReg rg(X, Y, 0.01f, 60);   // données, cibles, learning rate, % d'entraînement
vector<float> w = rg.fit(MSE);
vector<float> y = rg.predict(Xp);
float b = rg.getB();
```

```cpp
#include "LogReg.h"

LogReg lg(X, Y, 0.01f, 60);   // l'entraînement (BCE) a lieu à la construction
vector<float> p = lg.logistic_proba(Xp);
vector<float> c = lg.logistic_prediction(Xp, 0.5f);
```

Les cibles de la régression logistique doivent valoir 0 ou 1.

## Compilation

```
g++ -o test test.cpp LinReg.cpp FitTrain.cpp
./test
```

Pour utiliser `LogReg`, ajouter `LogReg.cpp` à la liste des fichiers sources.
