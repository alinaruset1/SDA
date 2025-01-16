#include <stdio.h>
#include <stdlib.h>

typedef struct angajat {
	char nume[35];
	int salar;
	int bonus;
}angajat;

void afisare(angajat a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s---%d---%d\n", a[i].nume, a[i].salar, a[i].bonus);
	}
	printf("\n");
}


void swap(angajat* a, angajat* b)
{
	angajat aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int sortarebonus(angajat a[], int n)
{
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].bonus == 1)
		{
			if (index != i)
			{
				swap(&a[i], &a[index]);
			
			}
			index++;
		}
	}
	return index;

}

void quicksort(angajat a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	angajat pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && a[stanga].salar > pivot.salar)
			stanga++;
		while (dreapta >= prim && pivot.salar > a[dreapta].salar)
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


int main(void)
{
	FILE *f;
	if ((f = fopen("date.txt", "rt")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}

	angajat a[5];
	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s", a[i].nume);
		fscanf(f, "%d", &a[i].salar);
		fscanf(f, "%d", &a[i].bonus);
	}

	int x = sortarebonus(a, 5);
	afisare(a, 5);
	quicksort(a, x, 4);
	afisare(a, 5);
	return 0;
}