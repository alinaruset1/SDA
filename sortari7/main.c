#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 7
typedef struct agenda {
	char nume[25];
	char telefon[10];
	int an;
	int venit;
}agenda;

void afisare(agenda v[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%s---%s---%d---%d\n", v[i].nume, v[i].telefon, v[i].an, v[i].venit);
	}
	printf("\n");
}
void swap(agenda* a, agenda* b)
{
    agenda aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int sortarelafinal(agenda a[])
{
    int index = n-1,contor=0;
    for (int i = 0; i <= index; i++)
    {
        if (a[i].venit < 2000)
        {
            if (i != index)
            {
                swap(&a[i], &a[index]);
                
            }
            index--;
            contor++;
            if (contor == 2)
                break;
        }
    }
    return index;
}

void quicksort(agenda a[], int prim, int ultim)
{
    int stanga = prim + 1;
    int dreapta = ultim;
   
    swap(&a[prim], &a[(prim + ultim) / 2]);
    
    agenda pivot = a[prim];
    while (stanga <= dreapta) 
    {
        while (stanga <= ultim && strcmp(a[stanga].nume, pivot.nume) < 0)
            stanga++;
        while (dreapta >= prim && strcmp(pivot.nume, a[dreapta].nume) < 0)
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

void sortareB(agenda a[])
{
    int stanga = -1, dreapta = -1;
    for (int i = 0; i < n; i++)
    {
        int varsta = 2025 - a[i].an;
        if (varsta >= 20 && varsta <= 30)
        {
            if(stanga==-1)
            stanga = i;
            dreapta = i;
        }
    }
    if (stanga != 1 && dreapta != -1)
    {
        quicksort(a, stanga, dreapta);
    }
}


int main(void)
{
    FILE* f;
    if ((f = fopen("date.txt", "rt")) == NULL)
    {
        perror("Eroare la deschiderea fișierului");
        exit(-1);
    }

    agenda a[7];
    for (int i = 0; i < 7; i++)
    {
        fscanf(f, "%s", a[i].nume);
        fscanf(f, "%s", a[i].telefon);
        fscanf(f, "%d", &a[i].an);
        fscanf(f, "%d", &a[i].venit);
    }

    fclose(f);

    sortarelafinal(a);
    afisare(a);

    sortareB(a);
    afisare(a);

    return 0;
}