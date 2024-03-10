#include "personne.h"

//pré g == 'f' ou g == 'h'
Personne per_mk(Nat i, Nat a, Genre g){
    Personne p = MALLOC(Strper);
    p->age = a;
    p->id = i;
    p->genre = g;
    return p;
}

Nat per_id(Personne p){
    return p->id;
}


Nat per_age(Personne p){
    return p->age;
}

Genre per_genre(Personne p){
    return p->genre;
}

Genre h(){
    Genre homme = 'h';
    return homme;
}

Genre f(){
    Genre femme = 'f';
    return femme;
}

