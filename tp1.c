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
#define LONG_NOM_VILLE 100
#define LONG_TABLEAU_VILLE  25000
#define LONG_TABLEAU_PAYS   300
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
    
    if (argc != 2 )
    {
        printf("Le nombre d'arguments entrer est inferieur ou superieur a 2\n");
        return 1;
    }
    
    if (n < 1 || n >5000) {
        printf("Le nombre entrer n'est pas valide\n");
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


