#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "retea.h"

int main() {
    persoana* lista = NULL;
   lista=adaugapersoana(lista, 1, "Alice", "IT", 12);
    const char recomandari1[][100] = { "Foarte buna la proiecte", "Lucreaza rapid" };
    const int ids1[] = { 2, 3 };
    initializeazaRecomandari(lista, recomandari1, ids1, 2);

    lista=adaugapersoana(lista, 2, "Bob", "Marketing", 5);
    const char recomandari2[][100] = { "Excelent comunicator" };
    const int ids2[] = { 1 };
    initializeazaRecomandari(lista, recomandari2, ids2, 1);

    lista=adaugapersoana(lista, 3, "Charlie", "IT", 15);
    const char recomandari3[][100] = { "Expert in baze de date", "Colaborator de incredere", "Rezolva probleme complexe" };
    const int ids3[] = { 1, 2, 4 };
    initializeazaRecomandari(lista, recomandari3, ids3, 3);

    gaseste(lista);

    elibereazamemoria(lista);

    return 0;
}
