#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "retea.h"


persoana* adaugapersoana(persoana* p, int id, char nume[35], char ocupatie[35], int contor) {
	persoana* nou;
	nou = (persoana*)malloc(sizeof(persoana));
	nou->id = id;
	strcpy(nou->ocupatie, ocupatie);
	strcpy(nou->nume, nume);
	nou->contor = contor;
	nou->recomandari = (recomandari*)malloc(contor * sizeof(recomandari));
	nou->next = p;
	return nou;

}

void gaseste(persoana* p)
{
	printf("Profesionistii cu peste 10 recomandari:\n");
	persoana* nou = p;
	while (nou)
	{
		if (strcmp(nou->ocupatie, "IT") == 0 && nou->contor > 10)
		{
			printf("ID: %d, Nume: %s, Ocupatie: %s, Recomandari: %d\n", nou->id, nou->nume, nou->ocupatie, nou->contor);
		}

		nou = nou->next;
	}
}

void elibereazamemoria(persoana* p)
{
	while (p)
	{
		persoana* aux = p;
		p = p->next;
		free(aux->recomandari);
		free(aux);
	}
}

void initializeazaRecomandari(persoana* p, const char recomandari[][100], const int ids[], int nrRecomandari) {
	for (int i = 0; i < nrRecomandari; i++) {
		strcpy(p->recomandari[i].text, recomandari[i]);
		p->recomandari[i].id = ids[i];
	}
}

void adaugaconexiune(persoana* p, int id, char text[100], int idAutor)
{
	persoana* nou = p;
	while (nou && nou->id != id)
	{
		nou = nou->next;
	}

	if (!nou)
	{
		printf("Persoana cu ID-ul %d nu a fost gasita.\n", id);
		return;
	}

	nou->recomandari = (recomandari*)realloc(nou->recomandari, sizeof(nou->contor + 1) * sizeof(recomandari));
	nou->recomandari[nou->contor].id = idAutor;
	nou->contor++;
}