#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char text[100];
	int id;
}recomandari;

typedef struct persoana
{
	int id;
	char nume[35];
	char ocupatie[35];
	int contor;
	recomandari* recomandari;
	struct persoana* next;

}persoana;

persoana* adaugapersoana(persoana* p, int id, char nume[35], char ocupatie[35], int contor);
void gaseste(persoana* p);
void elibereazamemoria(persoana* p);
void initializeazaRecomandari(persoana* p, const char recomandari[][100], const int ids[], int nrRecomandari);



