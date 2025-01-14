#include <stdio.h>
#include <stdlib.h>

typedef struct gps {
	int cod;
	struct gps* urm;
}gps;

typedef struct firme {
	char nume[50];
	struct firme* next;
	struct gps* urm;
}firme;


firme* adaugafirme(firme* f, char z[50]);
gps* adaugagps(firme* f, int cod);
void stergere(firme* f, int cod);
void afisare(firme* f);
void eliberarememorie(firme* p);
