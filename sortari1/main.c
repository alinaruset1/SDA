#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void quicksort(int a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	int pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && a[stanga] <pivot)
			stanga++;
		while (dreapta >= prim && pivot < a[dreapta])
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
int separareValoriNegativeDePozitive(int tablou[],int n) {
	int index = 0;

	// avem o functie de sortare valori negative(in prima parte a vectorului
	// si valori pozitive(in a doua parte a vectorului) si returnam indexul de unde incepe partea a doua a vectorului
	// pentru a apela quicksort pe acea parte a vectorului
	// O(n) -> n - dimensiunea tabloului
	for (int i = 0; i < n; i++) {
		if (tablou[i] < 0) {
			if (i != index) {
				swap(&tablou[i], &tablou[index]);
			}
			index++;
		}
	}

	return index;
}
void afisare(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


int main(void)
{
	int a[100] = {-1,3,-2,7,1,-4,9};
	afisare(a, 7);
	separareValoriNegativeDePozitive(a, 7);
	afisare(a, 7);
	quicksort(a, 0, 6);
	afisare(a, 7);
	
}