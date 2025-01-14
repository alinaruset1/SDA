#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gps.h"

int main(void)
{
	FILE* f;
	if ((f = fopen("date.txt", "rt")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}

	char nume[50];
	int cod;
	firme* p=NULL;
	for (int i = 0; i < 3; i++)
	{
		fscanf(f, "%s", nume);
		p = adaugafirme(p, nume);
		for (int j = 0; j < 5; j++)
		{
			fscanf(f, "%d", &cod);
			p->urm = adaugagps(p, cod);
		}
	}
	afisare(p);
	stergere(p, 1022);
	afisare(p);
	eliberarememorie(p);
	fclose(f);

}

