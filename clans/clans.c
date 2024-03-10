#include "clans.h"


Jeu jeu_vide(){
    Jeu j;
    j.pop = MALLOC(Membre);
    j.clans = MALLOC(struct stClan);
    j.pop = NULL;
    j.clans = NULL;

    return j;
}


//donne l’adresse du chef d’un clan 
//à partir de l’adresse d’un membre du clan.
Membre * jeu_adresse_chef(Jeu j, Membre *mclan){
    Membre *chef = mclan;
    while(chef->next_comp != NULL){
        chef = chef->next_comp;
    }
    return chef;
}

void jeu_print_pop(Jeu j){ 
    Population m = j.pop;

    while(m != NULL){
        printf("%d |", m->per->id);
        m = m->next_pop;
    }
    printf("\n");
}


void jeu_print_clan(Jeu j, Membre *mclan){
    Membre *c = mclan;
    while(c != NULL){
        printf("%d |", c->per->id);
        c = c->next_comp;
    }
    printf("\n");
}

Jeu jeu_fusion(Jeu j, Clans clan1, Clans clan2){
    //Clans new = MALLOC(struct stClan);
    clan1->dernier->next_comp = clan2->premier;
    clan1->dernier = clan2->dernier;
    clan1->next_clan = clan2->next_clan;
    free(clan2);
    j.clans = clan1;

    return j;
}

//Quand on ajoute une personne dans le jeu, 
//elle constitue un clan à elle seule
Jeu jeu_adj_joueur(Jeu j, Personne p){
    //on cree un nouvel clan pour la nouvelle personne(seul membre est cette personne)

    Clans new = MALLOC(struct stClan);
    new->next_clan = NULL; //c'est le dernier clan donc le suivant est null
    new->premier = MALLOC(Membre); //le clan à un seul membre
    new->premier->per = p; 
    new->premier->next_comp = NULL; //pas de compagnon suivant
    new->premier->next_pop = NULL; //le nouveau membre est le dernier dans la population
    new->dernier = new->premier; //le nouvaeu membre est à la fois premier et dernier

    if(j.clans == NULL){
        j.clans = new;
    } else{
        //fait pointer le dernier clan vers le nouvel clan
        Clans c = j.clans;
        while(c->next_clan != NULL){
            c = c->next_clan;
        }
            c->next_clan = new;
            //j.clans = c;
    }

    //fait pointer la derniere personne de la population vers une nouvelle personne
    Population m = j.pop;
    if(j.pop == NULL){ //j.pop au lieu de m et ca a marche!!!!!
        j.pop = new->premier;

    } else{
        while(m->next_pop != NULL){
            m = m->next_pop;
        }
        m->next_pop = new->premier; 
    }
    return j;
}

//pré p appartient à j
Jeu jeu_sortie_joueur(Jeu j, Personne p){
    Clans c = j.clans;
    Population m = j.pop;
    
    
    while(c->next_clan != NULL){
        if(c->premier->next_comp == NULL){ //cas 1: un seul membre du clan

            if(c->premier->per == p){ //cas 1.1: ce seul membre du clan est celui qu'on sort du jeu
                
                if(j.pop->per == p){ //cas 1.1.1 c'est la premiere personne dans la population
                    Population next = j.pop->next_pop;
                    free(j.pop);
                    j.pop = next;
                    
                }else{ //cas 1.1.2 ce n'est pas la prémiere personne dasn la pop

                    while(m->next_pop->per != p && m->next_pop != NULL){
                        m = m->next_pop; //la personne précedente dans la liste de population
                    }
                    //pas obligé de vérifier si il a trouvé un joeur 
                    //car on est dans le cas ou on est sur que le joueur est dans la population

                    Population pop_apres = m->next_pop->next_pop; 
                    //m->next_pop == c->premier vrai
                    m->next_pop = pop_apres; //on change le pointeur vers une personne d'apres

                }
               
                Clans c2 = c->next_clan; //on sauvegared le clan d'apres
                free(c->premier); //on supprime le premier et le seul memebre du clan
                free(c); //on supprime le clan
                c = c2; //la nouvelle tete de la liste des clans est le clan suivant
            }
            //si le membre n'est pas dans ce clan:
            //on fait rien et on passe a un autre clan dans tour de boucle

        } else{ //cas 2: plusiers membres du clan
            
            if(j.pop->per == p){ //cas 1.1.1 c'est la premiere personne dans la population
                    Population next = j.pop->next_pop;
                    free(j.pop);
                    j.pop = next;
                    
            }else{
                Population tmp = c->premier;
                while( tmp->next_comp != NULL  && tmp->next_comp->per != p){
                tmp = tmp->next_comp; 
            } //boucle s'arrete sur le compagnon d'avant
            //c->premier est le compagnon d'avant du joueur qu'on cherche
            if(tmp->next_comp != NULL){
                if(tmp->next_comp->per == p){ //si on le trouve

                    while(m->next_pop->per != p && m->next_pop != NULL){
                        m = m->next_pop; //la personne précedente dans la liste de population
                    }
                    //pas obligé de vérifier si il a trouvé un joeur 
                    //car on est dans le cas ou on est sur que le joueur est dans la popiulation

                    Population pop_apres = m->next_pop->next_pop;
                    //m->next_pop == c->premier vrai
                    m->next_pop = pop_apres;
                    
                    Population comp_apres =tmp->next_comp->next_comp; //membre suivant
                    free(tmp->next_comp);
                   tmp->next_comp = comp_apres;
                
            } 
            }
            
            //si on trouve pas le joueur dans ce clan:
            // on fait rien et on passe au clan suivant au prochaine tour de boucle
            
            }
            

        }
        
        c = c->next_clan;
    }
    

    return j;
}

