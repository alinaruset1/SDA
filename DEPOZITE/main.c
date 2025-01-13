#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "depozite.h"
#define date "date.txt"

void problema1() {
	FILE* f = fopen(date, "rt");
	if (f == NULL)
	{
		fprintf(stderr, "Cant open file ");
		//return -1;
		exit(-1);
	}
	depozite* p = NULL;
	int n; char z[30];
	for (int j = 0; j < 3; j++)
	{
		fscanf(f, "%s", z);
		p = adaugadepozit(p, z);
		for (int i = 0; i < 5; i++)
		{
			fscanf(f, "%d", &n);
			p->urm = adaugapalet(p, n);
		}
	}
	afisare(p);
	stergere(p, 20);
	afisare(p);
	eliberarememorie(p);
	fclose(f);
}
int main(void)
{
	problema1();
}