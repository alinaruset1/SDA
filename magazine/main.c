#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "p2.h"
#define date "date.txt"
#define date2 "date2.txt"
void problema2() {

}

int main(void)
{
	FILE* f = fopen(date2, "rt");
	if (f == NULL)
	{
		fprintf(stderr, "Cant open file ");
		return -1;
	}
	magazin* p = NULL;
	int n; char z[30];
	for (int j = 0; j < 3; j++)
	{
		fscanf(f, "%s", z);
		p = adaugamagazin(p, z);
		for (int i = 0; i < 5; i++)
		{
			fscanf(f, "%d", &n);
			p->urm = adaugaprodus(p, n);
		}
	}
	parcurgere2(p);
	sergere2(p, 10);
	parcurgere2(p);
	eliberarememorie2(p);
	fclose(f);
	_CrtDumpMemoryLeaks();
	return 0;
}