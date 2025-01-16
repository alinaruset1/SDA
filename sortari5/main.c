#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct film {
	char nume[35];
	int an;
	int premii;
}film;

void swap(film* a, film* b)
{
	film aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void quicksort(film a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	film pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && strcmp(a[stanga].nume,pivot.nume)>0)
			stanga++;
		while (dreapta >= prim && strcmp(pivot.nume,a[dreapta].nume)>0)
			dreapta--;
		if (stanga < dreapta)
			swap(&a[stanga++], &a[dreapta--]);
		else
			stanga++;
	}
	//mutare pivot la locul sau final
	swap(&a[dreapta], &a[prim]);
	//apelurile recursive
	if (prim < dreapta - 1)
		quicksort(a, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(a, dreapta + 1, ultim);
}


int sortareA(film f[], int n)
{
	int index = 0;
	for (int i = 0; i <5; i++)
	{
		if (f[i].premii == 1)
		{
			if (i != index)
			{
				swap(&f[i], &f[index]);
			}
			index++;
		}
	}
	return index;
}

void afisare(film f[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s---%d---%d\n", f[i].nume, f[i].an, f[i].premii);
	}
	printf("\n");
}

int main()
{
	FILE* f;
	if ((f = fopen("date.txt", "rt")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}

	film film[5];

	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s", film[i].nume);
		fscanf(f, "%d", &film[i].an);
		fscanf(f, "%d", &film[i].premii);
	}
	int x=sortareA(film, 5);
	afisare(film, 5);

	quicksort(film, 0, x-1);
	afisare(film, 5);

	return 0;
}