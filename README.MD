#Fit train		

Afin de démontrer ma compréhension des bases du Machine learning et de ma maitrise du C++ je vais réaliser une bibliothèques de machine learning dans ce language,

On sait que C++ est sensible au niveau de l’allocation de mémoire, nos choix seront donc justifié nottament les Tableaux : afin d’être contigu et gagner en memoire on transformera notre matrice en vector , on « linéarise » donc notre matrice en codant [i][j]->[i*col+j]

On crée notre methode fit avec la méthode de la descente de gradient :

-1 ere étape : mini Batch 

On entraine notre algorithme sur des échantillons du train set (mini batch) 

J’ai compris qu’Afin d’optimiser la memoire on va seulement travailler donc sur un X linéarisé et le trainset sera un tableau des indices des lignes en faisant parties, j’étais parti sur recréer un tableau entier mais j’ai compris que ce n’était pas nécessaire et que ca nous épargnerais des ressources.


Le code s’articulera en 2 boucle : Une pour les miniBatch et qui traversera le Dataset et l'autres pour chaque Epocj

On utilisera la methode de descente de gradient :  on utilisera MSE. MSE<=> L=1/n Σeps(i)^2 en calculant le gradient a la main 

Un epoch s’arrete quand le delta du Loss devient negligeable (dl<1e-6)



