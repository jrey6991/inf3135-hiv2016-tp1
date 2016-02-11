//
//  main.c
//  TP1
//
//  Created by Joy-Rey Babagbeto on 2016-01-22.
//  Copyright © 2016 Joy-Rey Babagbeto. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE_BUFFER 5000
#define LONG_NOM_PAYS 100
#define LONG_CODE_PAYS 3
#define LONG_NOM_VILLE 100
#define LONG_TABLEAU_VILLE  25000
#define LONG_TABLEAU_PAYS   300
#define DELIMITER "\t"
#define RANG "Rang"
#define NOM "Nom"
#define PAYS "Pays"
#define POPULATION "Population"

typedef struct Pays {
    char nom[LONG_NOM_PAYS];   // Le nom ASCII
    char code[LONG_CODE_PAYS]; // Le code de deux lettres
} Pays;

typedef struct Ville {
    char nom[LONG_NOM_VILLE]; // Le nom ASCII
    long population;          // La population
    struct Pays pays;         // Le pays de la ville
} Ville;

FILE* ouvrirFichier(char*);
int fermerFichier(FILE*);
Pays traiterPays(char*);
Ville traiterVille( char*, Pays*);
Pays rechercherPays(char*, Pays*);
void echanger(Ville*, int, int);
void quickSort(Ville*, int, int);
void afficherResultats(Ville*, int);

int main(int argc, const char * argv[]) {
    
    FILE* cities;
    FILE* country;
    char buffer[TAILLE_BUFFER];
    char* ptr;
    Pays lepays;
    Pays tabPays[LONG_TABLEAU_PAYS];
    Ville laville;
    Ville tabVille[LONG_TABLEAU_VILLE];
    int i = 0;
    long n;
    
    if (argc != 2 )
    {
        printf("Le nombre d'arguments entrer est inferieur ou superieur a 2\n");
        return 1;
    }
    
    cities = ouvrirFichier("./cities15000.txt");
    country = ouvrirFichier("./country.txt");
    
    while (fgets(buffer, TAILLE_BUFFER, country)) {
        if (buffer[0] == '#') {
            continue;
        }else{
            lepays = traiterPays(buffer);
            tabPays[i] = lepays;
            i++;
        }
    }
    i = 0;
    while (fgets(buffer, TAILLE_BUFFER, cities))
    {
        laville = traiterVille(buffer, tabPays);
        tabVille[i] = laville;
        i++;
    }
    
    n = strtol(argv[1], &ptr, 10);
    
    if (n < 1 || n >5000) {
        printf("Le nombre entrer n'est pas valide\n");
        return 1;
    }
    
    quickSort(tabVille, 0, LONG_TABLEAU_VILLE - 1);
    afficherResultats(tabVille, n);
    fermerFichier(cities);
    fermerFichier(country);
    return 0;
}

FILE* ouvrirFichier(char* fichier)
{
    return fopen(fichier, "r");
}

int fermerFichier(FILE *fichierp)
{
    return fclose(fichierp);
}

Pays traiterPays(char* ligne){
    char *token;
    int cpt = 0;
    Pays unPays;
    while ((token = strsep(&ligne, DELIMITER)) != NULL) {
        if (cpt == 0) {
            strcpy(unPays.code, token);
        } else if (cpt == 4){
            strcpy(unPays.nom, token);
        }
        cpt++;
    }
    return unPays;
}

Ville traiterVille(char *ligne, Pays* tab){
    char *token;
    char* ptr;
    int cpt = 0;
    Ville uneVille;
    Pays unPays;
    while ((token = strsep(&ligne, DELIMITER)) != NULL) {
        if (cpt == 14) {
            uneVille.population = strtol(token, &ptr, 10);
        }else if (cpt == 2) {
            strcpy(uneVille.nom, token);
            
        } else if (cpt == 8) {
            
            unPays = rechercherPays(token, tab);
            strcpy(uneVille.pays.code, unPays.code);
            strcpy(uneVille.pays.nom, unPays.nom);
            
        }
        cpt++;
    }
    return uneVille;
}

Pays rechercherPays(char* code, Pays* tableau){
    int i;
    Pays pays;
    for (i = 0; i < LONG_TABLEAU_PAYS; i++) {
        if (strcmp(code, tableau[i].code) == 0) {
            strcpy(pays.code, tableau[i].code);
            strcpy(pays.nom, tableau[i].nom);
        }
    }
    return pays;
}

void echanger(Ville* tableau, int a, int b)
{
    Ville temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
    
}

void quickSort(Ville* tableau, int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const long pivot = tableau[debut].population;
    
    
    if(debut >= fin)
        return;
    
    
    while(1)
    {
        do droite--; while(tableau[droite].population < pivot);
        do gauche++; while(tableau[gauche].population > pivot);
        
        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }
    
    
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}

void afficherResultats(Ville* tab, int nombre){
    int i = 0;
    int rang = 1;
    printf("%4s %-50s %-50s %10s\n", RANG, NOM, PAYS, POPULATION);
    printf("%4s %-50s %-50s %10s\n", "----", "---", "----", "----------");
    for (i = 0; i< nombre; i++) {
        printf("%4d %-50s %-50s %10.0ld\n", rang, tab[i].nom, tab[i].pays.nom, tab[i].population);
        
        rang++;
    }
}
