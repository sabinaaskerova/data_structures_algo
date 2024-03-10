#include "base.h"

#ifndef PERSONNE_H
#define PERSONNE_H
typedef char Genre;

typedef struct strper{
    Genre genre;
    Nat id;
    Nat age;

} Strper, *Personne;



//pré g == 'f' ou g == 'h'
Personne per_mk(Nat i, Nat a, Genre g);

Nat per_id(Personne p);

Nat per_age(Personne p);

Genre per_genre(Personne p);

Genre h();

Genre f();


#endif