#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char nume[35];
	int varsta;
	int premii;
}student;

void swap(student* a, student* b)
{
	student aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int sortareA(student s[], int n)
{
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i].premii == 1)
		{
			if (i != index)
			{
				swap(&s[i], &s[index]);
			}
			index++;
		}
	}
	return index;
}

void quicksort(student a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	student pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && strcmp(a[stanga].nume,pivot.nume)<0)
			stanga++;
		while (dreapta >= prim && strcmp(pivot.nume,a[dreapta].nume)<0)
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


void afisare(student s[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s----%d---%d\n", s[i].nume, s[i].varsta, s[i].premii);
	}
	printf("\n");
}

int main(void)
{
	FILE* f;
	if ((f = fopen("date.txt", "rt")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	student s[5];

	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s", s[i].nume);
		fscanf(f, "%d", &s[i].varsta);
		fscanf(f, "%d", &s[i].premii);
	}

	int x = sortareA(s, 5);
	afisare(s,5);

	quicksort(s, 0, x);
	afisare(s, 5);



}