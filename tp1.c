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

int main(int argc, const char * argv[]) {
    if (argc != 2 )
    {
        printf("Le nombre d'arguments entrer est inferieur ou superieur a 2\n");
        return 1;
    }
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

