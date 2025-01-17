#include <stdio.h>
#include <string.h>
int v[3];
int n = 6;
int solutii = 0;
char* culori[] = { "alb", "galben", "rosu", "verde","albastru","negru" };
//1 alb 2galben 3rosu 4verde 5albastru 6negru
int valid(int k)
{
	for (int i = 0; i <k; i++)
	{
		if (v[i] == v[k])
		{
			return 0;
		}
	}
	if(k==1)
	if (strcmp(culori[v[k]],"galben")!=0 && strcmp(culori[v[k]],"verde")!=0)
	{
		return 0;
	}
	return 1;
}

int solutie(int k)
{
	return k == 2;
}

void afisare() {
	printf("Steag: ");
	for (int i = 0; i < 3; i++) {
		printf("%s ", culori[v[i]]);
	}
	printf("\n");
}

void back(int k) {
	for (int i = 0; i < n; i++) { // Iterăm prin toate culorile
		v[k] = i; // Selectăm o culoare
		if (valid(k)) {
			if (solutie(k)) {
				afisare();
				solutii++;
			}
			else {
				back(k + 1); // Continuăm cu poziția următoare
			}
		}
	}
}

int main() {
	printf("Toate combinatiile de steaguri:\n");
	back(0); // Pornim generarea de la poziția 0
	return 0;
}