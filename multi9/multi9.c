#include <stdio.h>
#include <stdlib.h>

typedef struct conferinta {
	int id;
	char data[50];
	char nume[50];
	struct conferinta* next;
	struct student* urm;
}conferinta;

typedef struct student {
	char nume[50];
	char email[50];
	struct student* urm;
}student;

conferinta* adaugaconferinta(conferinta *c, int id, char data[50], char nume[50])
{
	conferinta* nou;
	nou = (conferinta*)malloc(sizeof(conferinta));
	if (nou == NULL)
	{
		perror(NULL);
		exit(-1);
	}

	strcpy(nou->nume, nume);
	strcpy(nou->data, data);
	nou->id = id;
	nou->next = c;
	nou->urm = NULL;
	return nou;
}

student* adaugastudent(student* s, char nume[50], char email[50])
{
	student* nou;
	nou = (student*)malloc(sizeof(student));
	if (nou == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(nou->nume, nume);
	strcpy(nou->email, email);
	student* aux = s;
	if (s == NULL || strcmp(nume, s->nume) < 0)
	{
		nou->urm = s;
		return nou;
	}

	while (aux->urm != NULL && strcmp(nume, aux->urm->nume) > 0)
	{
		aux = aux->urm;
	}

	nou->urm = aux->urm;
	aux->urm = nou;
	return s;
}

void modificare_email(conferinta *c,int id, char nume[50], char email[50])
{
	while (c != NULL && c->id != id)
	{
		c = c->next;
	}
	if (c == NULL)
	{
		perror(NULL);
		exit(-1);
	}

	student* s = c->urm;
	while (s!= NULL && strcmp(s->nume, nume) != 0)
	{
		s = s->urm;
	}

	if (s == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(s->email, email);

}

void afisare(conferinta* c)
{
	conferinta* y = c;
	while (y)
	{
		printf("%d---%s---%s    \n", y->id, y->data, y->nume);
		student* s = y->urm;
		while (s)
		{
			printf("%s--%s   ", s->nume, s->email);
			s = s->urm;
		}
		printf("\n");
		y = y->next;
	}
	printf("\n");
}

int main()
{
	FILE* f;
	if ((f = fopen("data.txt", "rt")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	conferinta* p = NULL;
	char nume[50];
	int id;
	char data[50], email[50];
	for (int i = 0; i < 3; i++)
	{
		fscanf(f, "%d", &id);
		fscanf(f, "%s", &data);
		fscanf(f, "%s", nume);
		p = adaugaconferinta(p, id, data,nume);
		for (int j = 0; j < 5; j++)
		{
			fscanf(f, "%s", nume);
			fscanf(f, "%s", email);
			p->urm = adaugastudent(p->urm, nume,email);
		}
	}
	afisare(p);
	modificare_email(p,1,"Alina", "alinamarianicoleta");
	afisare(p);
}