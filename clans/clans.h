#include "personne.h"

#ifndef CLANS_H
#define CLANS_H

typedef struct stPer { 
        Personne per ; // les données de la personne
        struct stPer *next_comp; // le compagnon suivant dans le clan
        struct stPer *next_pop; // la personne suiv. dans la population
} *Population, Membre; // plusieurs noms pour la lisibilité



typedef struct stClan { 
        Membre * premier ; // début de la liste du clan
        Membre * dernier ; // le dernier est le représentant
        struct stClan *next_clan; // chaînage
} *Clans;



typedef struct { 
        Population pop; // liste de la population entière
        Clans clans; // liste des clans
} Jeu;

Jeu jeu_vide();

Membre * jeu_adresse_chef(Jeu j, Membre *mclan);

void jeu_print_pop(Jeu j);

void jeu_print_clan(Jeu j, Membre *mclan);

Jeu jeu_fusion(Jeu j, Clans clan1, Clans clan2);

Jeu jeu_adj_joueur(Jeu j, Personne p);

//pré p appartient à j
Jeu jeu_sortie_joueur(Jeu j, Personne p);

#endif