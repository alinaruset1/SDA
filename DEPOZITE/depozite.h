#include <stdio.h>
#include <string.h>
#include <stdio.h>
#ifndef p1
#define p1

typedef struct palet {
    int numar;
    struct palet* urm;
}palet;

typedef struct depozite {
    char nume[50];
    struct depozite* next;
    struct palet* urm;
}depozite;

depozite* adaugadepozit(depozite* d, char z[30]);
depozite* adaugapalet(depozite* p, int n);
void afisare(depozite* p);
void stergere(depozite* p, int n);
void eliberarememorie(depozite* p);

#endif