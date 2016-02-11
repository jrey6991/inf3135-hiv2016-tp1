# Travail pratique 1

## Description

Le projet consiste à afficher les n premières villes les plus habitées au monde. Ces n villes sont tirées de deux fichiers qui contiennent respectivement les informations qui leurs sont reliées et celles relatives à leurs pays respectifs. Le programme affiche donc dans l'ordre les villes les plus peulpées associées à leur pays respectifs et leur population.

Contexte : Construction et maintenance de logiciels, INF3135, Université du Québec À Montréal(UQAM)

## Auteur

Joy-Rey Babagbeto (BABJ21119609)

## Fonctionnement

Pour compiler le programme il faut effectuer la commande <make> qui produit l'exécutable. Ensuite pour charger les fichiers il faut effectuer la commande <make database>. On peux alors lancer le programme en effectuant la commande ./tp1 n, n étant le nombre de villes que l'on veut afficher. Voici quelques examples d'utilisation:

Compilation:

make

gcc -c tp1.c
gcc -o tp1 tp1.o

Chargement de fichiers:

make database

curl http://download.geonames.org/export/dump/countryInfo.txt -o "country.txt"
% Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
Dload  Upload   Total   Spent    Left  Speed
100 31415  100 31415    0     0  50074      0 --:--:-- --:--:-- --:--:-- 50103
curl -o cities.zip http://download.geonames.org/export/dump/cities15000.zip
% Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
Dload  Upload   Total   Spent    Left  Speed
100 1918k  100 1918k    0     0  1036k      0  0:00:01  0:00:01 --:--:-- 1036k
unzip cities.zip
Archive:  cities.zip
inflating: cities15000.txt 

Exemple 1:

./tp1

Le nombre d'arguments entrer est inferieur ou superieur a 2

Exemple 2:

./tp1 10 n

Le nombre d'arguments entrer est inferieur ou superieur a 2

Exemple 3:

./tp1 0

Le nombre entrer n'est pas valide

Exemple 4:

./tp1 10
Rang  Nom                                                Pays                                               Population
----  ---                                                ----                                               ----------
   1  Shanghai                                           China                                                22315474
   2  Buenos Aires                                       Argentina                                            13076300
   3  Mumbai                                             India                                                12691836
   4  Mexico City                                        Mexico                                               12294193
   5  Beijing                                            China                                                11716620
   6  Karachi                                            Pakistan                                             11624219
   7  Istanbul                                           Turkey                                               11174257
   8  Tianjin                                            China                                                11090314
   9  Guangzhou                                          China                                                11071424
  10  Delhi                                              India                                                10927986

## Contenu du projet

Le fichier cities15000 contient environ 24500 villes, une ville par ligne avec tous ses détails (population, nom, code du pays, etc .....)

Le fichier countryInfo contient environ 360 pays, un pays par ligne avec tous ses détails (nom, code, nom de la capitale, etc ....)

## Références

Structures Pays et Ville : http://thales.math.uqam.ca/~blondin/fr/inf3135-tp1

Tri (methodes echanger et quicksort) : https://openclassrooms.com/courses/le-tri-rapide-qsort

## Statut

La totalité du projet est complèté, aucun bogue.