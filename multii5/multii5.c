#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct produse {
	int cod;
	struct produse* urm;
}produse;

typedef struct magazine {
	char nume[50];
	struct magazine* next;
	struct produse* urm;
}magazine;

magazine* adaugamagazine(magazine* m, char nume[50])
{
	magazine* nou;
	nou = (magazine*)malloc(sizeof(magazine));
	if (nou == NULL)
	{
		perror(NULL);
		exit(-1);
	}

	strcpy(nou->nume, nume);
	nou->urm = NULL;
	nou->next = m;
	return nou;
}

produse* adaugaproduse(produse* p, int cod)
{
	produse* nou;
	nou = (produse*)malloc(sizeof(produse));
	if (nou == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	nou->cod = cod;
	nou->urm = NULL;
	if (p == NULL || cod < p->cod)
	{
		nou->urm = p;
		return nou;
	}

	produse* curent = p;
	while (curent->urm != NULL && cod >=curent->urm->cod)
	{
		curent = curent->urm;
	}

	nou->urm = curent->urm;
	curent->urm = nou;
	return p;
}


void eliminareprodus(magazine* m, int cod)
{
	magazine* y = m;
	while (y)
	{
		produse* p = y->urm;
		while (p!=NULL && p->cod == cod)
		{
			produse* deSters = p;
			y->urm = p->urm;
			p = p->urm;
			free(deSters);
		}
		while (p)
		{
			while (p -> urm != NULL && p->urm->cod == cod)
			{
				produse* g;
				g = p->urm;
				p->urm = p->urm->urm;
				free(g);
			}
			p = p->urm;
		}
		printf("\n");
		y = y->next;
	}
}

void eliberarememorie(magazine* m)
{
	magazine* y = m;
	while (y)
	{
		magazine* t = y;
		produse* u = y->urm;
		while (u)
		{
			produse* g = u;
			u = u->urm;
			free(g);
		}
		y = y->next;
		free(t);
	}
}

void afisare(magazine* m)
{
	magazine* y = m;
	while (y)
	{
		printf("%s ", y->nume);
		produse* p = y->urm;
		while (p)
		{
			printf("%d ", p->cod);
			p = p->urm;
		}
		printf("\n");
		y = y->next;
	}
}


int main(void)
{
	FILE* f;
	if ((f = fopen("data.txt", "rt")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	magazine* m = NULL;
	char nume[50];
	int cod;

	for (int i = 0; i < 3; i++)
	{
		fscanf(f, "%s", nume);
		m = adaugamagazine(m, nume);
		for (int j = 0; j < 5; j++)
		{
			fscanf(f, "%d", &cod);
			m->urm = adaugaproduse(m->urm, cod);
		}
	}
	afisare(m);
	eliminareprodus(m, 5);
	afisare(m);
	eliberarememorie(m);
	fclose(f);
	return 0;
}