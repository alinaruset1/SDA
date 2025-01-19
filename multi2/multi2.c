#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct firma {
	char nume[50];
	struct firma* next;
	struct gps* urm;
}firma;

typedef struct gps {
	int cod;
	struct gps* urm;
}gps;

firma* adaugafirma(firma* f, char nume[50])
{
	firma* nou;
	nou = (firma*)malloc(sizeof(firma));
	if (nou == NULL)
	{
		perror(NULL);
		exit(-1);
	}

	strcpy(nou->nume, nume);
	nou->next = f;
	nou->urm = NULL;
	return nou;

}

gps* adaugagps(gps* p, int cod)
{
	gps* nou;
	nou = (gps*)malloc(sizeof(gps));
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


	gps* curent = p;
	while (curent->urm != NULL && cod >= curent->urm->cod)
	{
		curent = curent->urm;

	}

	nou->urm = curent->urm;
	curent->urm = nou;
	return p;

}

void afisare(firma* f)
{
	firma* y = f;
	while (y)
	{
		gps* u = y->urm;
		printf("%s ", y->nume);
		while (u)
		{
			printf("%d ", u->cod);
			u = u->urm;
		}
		printf("\n");
		y = y->next;
	}
}

void eliminaregps(firma *f, int cod)
{
	firma* y = f;
	while (y)
	{
		gps* u = y->urm;
		while (u->cod == cod)
		{
			gps* deSters = u;
			y->urm = u->urm;
			u = u->urm;
			free(deSters);
		}
		while (u)
		{
			while (u->urm != NULL && u->urm->cod == cod)
			{
				gps* g;
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

	char nume[50];
	int cod;
	firma* p=NULL;
	for (int i = 0; i < 3; i++)
	{
		fscanf(f, "%s", nume);
		p = adaugafirma(p, nume);
		for (int j = 0; j < 5; j++)
		{
			fscanf(f, "%d", &cod);
			p->urm = adaugagps(p->urm, cod);
		}
	}
	afisare(p);
	eliminaregps(p,20);
	afisare(p);
	fclose(f);
}