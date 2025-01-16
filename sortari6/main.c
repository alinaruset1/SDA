#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct echipa {
	char nume[25];
	int puncte;
	int buget;
	char oras[25];
}echipa;

void afisare(echipa e[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s---%d---%d---%s\n", e[i].nume, e[i].puncte, e[i].buget, e[i].oras);

	}
	printf("\n");
}
void swap(echipa* a, echipa* b)
{
	echipa aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int sortare(echipa e[], int n)
{
	int index1 = 0, index2 = 4;
	for (int i = 0; i <=index2;)
	{
		if (e[i].puncte > 45)
		{
			if (i != index1)
			{
				swap(&e[i], &e[index1]);
			}
			index1++;
			i++;
			
		}
		else if (e[i].puncte < 20)
		{
			if (i != index2)
			{
				swap(&e[i], &e[index2]);
			}
			index2--;
		}
		else
		{
			i++;
		}
	}
}

void quicksort(echipa a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;

	swap(&a[prim], &a[(prim + ultim) / 2]);

	echipa pivot = a[prim];
	while (stanga <= dreapta)
	{
		while (stanga <= ultim && a[stanga].puncte> pivot.puncte)
			stanga++;
		while (dreapta >= prim && pivot.puncte> a[dreapta].puncte)
			dreapta--;
		if (stanga < dreapta)
			swap(&a[stanga++], &a[dreapta--]);
		else
			stanga++;
	}

	swap(&a[dreapta], &a[prim]);

	if (prim < dreapta - 1)
		quicksort(a, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(a, dreapta + 1, ultim);
}
void sortare_dupa_buget(echipa e[], int n)
{
	int start = -1, end = -1;

	for (int i = 0; i < n; i++) {
		if (e[i].buget > 100000) {
			if (start == -1) start = i;
			end = i;
		}
	}

	if (start != -1 && end != -1) {
		quicksort(e, start, end);
	}
}

int main(void)
{
	FILE* f;
	if ((f = fopen("date.txt", "rt")) == NULL)
	{
		perror("Eroare la deschiderea fisierului");
		exit(-1);
	}

	echipa a[5];
	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s", a[i].nume);
		fscanf(f, "%d", &a[i].puncte);
		fscanf(f, "%d", &a[i].buget);
		fscanf(f, "%s", a[i].oras);
	}
	sortare(a, 5);
	afisare(a, 5);

	sortare_dupa_buget(a, 5);
	afisare(a, 5);
	fclose(f);
	return 0;
}