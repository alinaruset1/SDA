#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gps.h"

firme* adaugafirme(firme* f, char z[50])
{
	firme* nou;
	nou = (firme*)malloc(sizeof(firme));
	nou->next = f;
	strcpy(nou->nume, z);
	nou->urm = NULL;
	return nou;
}

gps* adaugagps(firme* f, int cod)
{
	gps* nou;
	nou = (gps*)malloc(sizeof(gps));
	nou->urm = f->urm;
	//f->urm = nou->urm;
	nou->cod = cod;
	return nou;
}

void stergere(firme* f, int cod)
{
	firme* y = f;
	while (y)
	{
		gps* aux = y->urm;
		while (aux->cod==cod)
		{
			gps* deSters = aux;
			y->urm = aux->urm;
			aux = aux->urm;
			free(deSters);
		}

		while (aux)
		{
			while (aux->urm != NULL && aux->urm->cod == cod)
			{
				gps* g;
				g = aux->urm;
				aux->urm = aux->urm->urm;
				free(g);

			}
			aux = aux -> urm;
		}
		printf("\n");
		y = y->next;
	}
}

void afisare(firme* f)
{
	firme* y = f;
	while (y)
	{
		printf("%s ", y->nume);

		gps* u = y->urm;
		while (u)
		{
			printf("%d ", u->cod);
			u = u->urm;
		}
		printf("\n");
		y = y->next;
	}
}

void eliberarememorie(firme* f)
{
	firme* y = f;
	while (y)
	{
		firme* t = y;
		gps* u = y->urm;
		while (u)
		{
			gps* p = u;
			u = u->urm;
			free(p);
		}
		y = y->next;
		free(t);
	}
	
}