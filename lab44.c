#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 200
#define CHUNK 1000
#define ARRAY_SIZE 100

typedef struct
{
    char titlu[1000];
    uint16_t an;
    uint16_t durata;
    char categorie[100];
    int premiat;  // 1 pentru "Da", 0 pentru "Nu"
} Film;

void printfFilm(Film *film)
{
    printf("%d - %s - %s - %d min - %s\n", film->an, film->titlu, film->categorie, film->durata, film->premiat ? "Premiat" : "Nepremiat");
}

void swapFilm(Film *a, Film *b)
{
    Film aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int processLine(char *linie, Film *film)
{
    char *p;
    int i;
    if ((p = strtok(linie, "\t")) == NULL)
    {
        return 1;
    }
    for (i = 0; i < 5; i++)
    {
        switch (i)
        {
        case 0:
            film->an = strtol(p, NULL, 10); 
            break;
        case 1:
            film->durata = strtol(p, NULL, 10); 
            break;
        case 2:
            strcpy(film->titlu, p); 
            break;
        case 3:
            strcpy(film->categorie, p); 
            break;
        case 4:
            film->premiat = (strcmp(p, "Da") == 0) ? 1 : 0; 
            break;
        }
        if ((p = strtok(NULL, "\t")) == NULL)
        {
            return 1;
        }
    }
    return 0;
}


void f2(Film *filme, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(filme[i].titlu, filme[j].titlu) > 0)
            {
                swapFilm(&filme[i], &filme[j]);
            }
        }
    }
}


void f1(Film *filme, int size)
{
    int i = 0, j = size - 1;
    while (i < j)
    {
        while (filme[i].premiat && i < j)
            i++;
        while (!filme[j].premiat && i < j)
            j--;
        if (i < j)
            swapFilm(&filme[i], &filme[j]);
    }
}


void quicksort(Film *filme, int left, int right)
{
    if (left < right)
    {
        int pivot = filme[right].an;
        int i = left - 1;
        for (int j = left; j < right; j++)
        {
            if (filme[j].an < pivot)
            {
                i++;
                swapFilm(&filme[i], &filme[j]);
            }
        }
        swapFilm(&filme[i + 1], &filme[right]);
        quicksort(filme, left, i);
        quicksort(filme, i + 2, right);
    }
}

void p1()
{
    FILE *f;
    Film *filme = NULL, aux;
    int index = 0, current_size = 0;
    char linie[LINE_SIZE];

    if ((f = fopen("Filme.txt", "r")) == NULL)
    {
        perror("Eroare la deschiderea fisierului!");
        exit(-1);
    }


    if (fgets(linie, LINE_SIZE, f) == NULL)
    {
        perror("Eroare la citirea din fisier!");
        exit(-1);
    }

    while (fgets(linie, LINE_SIZE, f) != NULL)
    {
        if (processLine(linie, &aux) == 0)
        {
            if (index == current_size)
            {
                current_size = current_size + CHUNK;
                if ((filme = realloc(filme, current_size * sizeof(Film))) == NULL)
                {
                    perror("Eroare la realocarea memoriei!");
                    exit(-2);
                }
            }
            filme[index++] = aux;
        }
    }

    current_size = index;

    printf("Filmele ordonate alfabetic dupa titlu:\n");
    f2(filme, current_size);
    for (index = 0; index < current_size; index++)
    {
        printfFilm(&filme[index]);
    }

    printf("\nFilmele premiate urmate de cele nepremiate:\n");
    f1(filme, current_size);
    for (index = 0; index < current_size; index++)
    {
        printfFilm(&filme[index]);
    }

    printf("\nFilmele ordonate crescator dupa anul aparitiei:\n");
    quicksort(filme, 0, current_size - 1);
    for (index = 0; index < current_size; index++)
    {
        printfFilm(&filme[index]);
    }

    if (fclose(f) != 0)
    {
        perror("Eroare la inchiderea fisierului!");
        exit(-1);
    }
}

int main(void)
{
    p1();
    return 0;
}
