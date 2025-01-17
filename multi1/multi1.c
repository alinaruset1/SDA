#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct depozite {
	char nume[50];
	struct depozite* next;
	struct paleti* urm;
}depozite;

typedef struct paleti {
	int cod;
	struct paleti* urm;
}paleti;

depozite* adaugadepozit(depozite* d, char nume[35])
{
	depozite* nou;
	nou = (depozite*)malloc(sizeof(depozite));
	if (nou == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(nou->nume, nume);
	nou->next = d;
	nou->urm = NULL;
	return nou;
}

paleti* adaugapaleti(paleti* p, int cod)
{
	paleti* nou = (paleti*)malloc(sizeof(paleti));
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

	paleti* aux = p;
	while (aux->urm != NULL && cod >= aux->urm->cod)
	{
		aux = aux->urm;
	}

	nou->urm = aux->urm;
	aux->urm = nou;
	return p;
}

void eliminarepalet(depozite *d,int cod)
{
	depozite* y = d;
	while (y)
	{
		paleti* u = y->urm;
		while (u->cod == cod)
		{
			paleti* deSters = u;
			y->urm = u->urm;
			u = u->urm;
			free(deSters);
		}
		while (u)
		{
			while (u->urm != NULL && u->urm->cod == cod)
			{
				paleti* g;
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

void eliberarememorie(depozite* d)
{
	depozite* y = d;
	while (y)
	{
		depozite* t = y;
		paleti* u = y->urm;
		while (u)
		{
			paleti* f = u;
			u = u->urm;
			free(f);
		}
		y = y->next;
		free(t);
	}
}
void afisare(depozite* d)
{
	depozite* y = d;
	while (y)
	{
		paleti* p = y->urm;
		printf("%s ", y->nume);
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
	depozite* p = NULL;
	char nume[50];
	int cod;
	for (int i = 0; i < 3; i++)
	{
		fscanf(f, "%s", nume);
		p = adaugadepozit(p, nume);
		for (int j = 0; j < 5; j++)
		{
			fscanf(f, "%d", &cod);
			p->urm = adaugapaleti(p->urm, cod);
		}
	}
	afisare(p);
	eliminarepalet(p, 20);
	afisare(p);
	eliberarememorie(p);

	fclose(f);
}