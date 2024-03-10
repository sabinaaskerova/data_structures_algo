#include "clans.h"
#include "personne.h"

int main(){

    Personne p1 = per_mk(1, 32, 'h');
    
    Personne p2 = per_mk(2, 22, 'f');
   
    Personne p3 = per_mk(3, 17, 'h');
    Personne p4 = per_mk(4, 44, 'f');
    Personne p5 = per_mk(5, 80, 'h');
     
    Personne p6 = per_mk(6, 26, 'f');
    Personne p7 = per_mk(7, 18, 'h');
    Personne p8 = per_mk(8, 90, 'f');
    Personne p9 = per_mk(9, 58, 'h');
    Personne p10 = per_mk(10, 77, 'f');
    Personne p11 = per_mk(11, 37, 'h');

    

    Jeu j = jeu_vide();
    j = jeu_adj_joueur(j, p1);
    
    j = jeu_adj_joueur(j, p2);
   
    j = jeu_adj_joueur(j, p3);
    j = jeu_adj_joueur(j, p4);
    j = jeu_adj_joueur(j, p5);
    j = jeu_adj_joueur(j, p6);
    j = jeu_adj_joueur(j, p7);
    j = jeu_adj_joueur(j, p8);
    j = jeu_adj_joueur(j, p9);
    j = jeu_adj_joueur(j, p10);
    j = jeu_adj_joueur(j, p11);

    jeu_print_pop(j);
    jeu_print_clan(j, j.clans->next_clan->premier);

    j = jeu_fusion(j, j.clans, j.clans->next_clan);
    jeu_print_clan(j, j.clans->premier);
    jeu_print_clan(j, j.clans->next_clan->premier);

    j = jeu_sortie_joueur(j, p7); //marche quand tous les clans sont à une personne
    //et marche quand c'est la premiere personne dans la population
    jeu_print_pop(j);

    
    return 0;
}