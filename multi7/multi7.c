#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct zbor {
	char nume[35];
	struct zbor* next;
	struct pasager* urm;
}zbor;

typedef struct pasager {
	int cod;
	struct pasager* urm;
}pasager;

zbor* adaugazbor(zbor* z, char nume[35])
{
	zbor* nou;
	nou = (zbor*)malloc(sizeof(zbor));
	if (nou == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(nou->nume, nume);
	nou->urm = NULL;
	nou->next = z;
	return nou;
}

pasager* adaugapasager(pasager* p, int cod)
{
	pasager* nou;
	nou = (pasager*)malloc(sizeof(pasager));
	if (nou == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	nou->cod = cod;
	nou->urm = NULL;
	if (p == NULL || cod <= p->cod)
	{
		nou->urm = p;
		return nou;
	}

	pasager* aux = p;
	while (aux->urm != NULL && cod >= aux->urm->cod)
	{
		aux = aux->urm;
	}
	nou->urm = aux->urm;
	aux->urm = nou;
	return p;

}

void afisare(zbor* z)
{
	zbor* y = z;
	while (y)
	{
		printf("%s ", y->nume);
		pasager* p = y->urm;
		while (p)
		{
			printf("%d ", p->cod);
			p = p->urm;
		}
		printf("\n");
		y = y->next;
	}
}

void eliberarememorie(zbor* z)
{
	zbor* y = z;
	while (y)
	{
		zbor* t = y;
		pasager* u = y->urm;
		while (u)
		{
			pasager* p = u;
			u = u->urm;
			free(p);
		}
		y = y->next;
		free(t);
	}
}

void eliminarepasager(zbor* z, int cod)
{
	zbor* y = z;
	while (y)
	{
		pasager* u = y->urm;
		while (u->cod==cod)
		{
			pasager* deSters = u;
			y->urm = u->urm;
			u = u->urm;
			free(deSters);
		}

		while (u)
		{
			while (u->urm != NULL && u->urm->cod == cod)
			{
				pasager* g;
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

int main(void)
{

	FILE* f;
	if ((f = fopen("data.txt", "rt")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}

	char nume[35];
	zbor* z = NULL;
	int cod;
	for (int i = 0; i < 3; i++)
	{
		fscanf(f, "%s", nume);
		z = adaugazbor(z, nume);
		for (int j = 0; j < 5; j++)
		{
			fscanf(f, "%d", &cod);
			z->urm = adaugapasager(z->urm, cod);
		}
	}

	afisare(z);
	eliminarepasager(z, 20);
	afisare(z);
	return 0;
}