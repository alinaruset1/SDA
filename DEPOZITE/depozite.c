#include "depozite.h"
#include <stdio.h>
#include <stdlib.h>

depozite* adaugadepozit(depozite* d, char z[30])
{
    depozite* nou;
    nou = (depozite*)malloc(sizeof(depozite));
    nou->next = d;
    strcpy(nou->nume, z);
    nou->urm = NULL;
    return nou;
}

depozite* adaugapalet(depozite* p, int n)
{
    palet* nou;
    nou = (palet*)malloc(sizeof(palet));
    nou->urm = p->urm;
    nou->numar = n;
    return nou;
}

void afisare(depozite* p)
{
    depozite* y = p;
    while (y)
    {
        printf("%s ", y->nume);
        palet* u = y->urm;
        while (u)
        {
            printf("%d ", u->numar);
            u = u->urm;
        }
        printf("\n");
        y = y->next;
    }
}

void stergere(depozite* p, int n)
{
    depozite* y = p;
    while (y)
    {
        palet* u = y->urm;
        while (u->numar == n)
        {
            palet* deSters = u;
            y->urm = u->urm;
            u = u->urm;
            free(deSters);
        }
        while (u)
        {
            while (u->urm != NULL && u->urm->numar == n)
            {
                palet* g;
                g = u->urm;
                u->urm = u->urm->urm;
                free(g);
            }
            u = u->urm;
        }
        printf("\n");
        y = y->next;
    }
}

void eliberarememorie(depozite* p)
{
    depozite* y = p;
    while (p)
    {
        depozite* t = y;
        palet* u = y->urm;
        while (u)
        {
            palet* f = u;
            u = u->urm;
            free(f);
        }
        y = y->next;
        free(t);
    }
}



