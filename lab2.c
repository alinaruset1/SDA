#include <stdio.h>
#define MAX_SIZE 100
#include <stdlib.h>
#include <math.h>
//Exercitiul 1
void p1()
{
    int n;
    printf("Introdu nr. n: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        printf("%d ", i);
    }
}

//Exercitiul 2 varianta 1
void p2()
{
    int n;
    printf("Introdu nr. n: ");
    scanf("%d", &n);
    int termen;
    int a=0, b=1;
    printf("%d %d ", a,b);
    while(n!=2)
    {
        termen = a+b;
        a=b;
        b=termen;
        printf("%d ", termen);
        n--;
    }
}


//Exercitiul 2 varianta 2
void p3()
{
    int n;
    printf("Introdu nr n: ");
    scanf("%d", &n);
    int t1=0, t2=1;
    int nextTermen;
    printf("%d %d ", t1,t2);
    for(int i=3; i<=n; i++)
    {
        nextTermen=t1+t2;
        t1=t2;
        t2=nextTermen;
        printf("%d ", nextTermen);
    }
}

//Exercitiul 3 varianta 1

void p4()
{
    int a,b,r;
    printf("Introduceti numerele: ");
    scanf("%d %d", &a, &b);
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    printf("cmmdc este %d", a);
}

//Exercitiul 3 varianta 2

void p5()
{
    int a,b;
    printf("Introduceti numerele: ");
    scanf("%d %d", &a, &b);
    while(a!=b)
    {
        if(a>b) 
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    printf("cmmdc este %d ", a);
}


//Tipuri de date abstracte

//Exercitiul 1

typedef struct{
    int *elem;
    int size;
}Multime;

Multime *creeazaMultime(){
    Multime *multime;
    if((multime=(Multime*)malloc(sizeof(Multime)))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    multime->elem=(int*)malloc(MAX_SIZE*sizeof(int));
    if(multime->elem==NULL)
    {
        perror(NULL);
        free(multime);
        exit(-1);
    }
    multime->size=0;
    return multime;
}

int apartine(Multime *multime, int elem)
{
    for(int i=0; i<multime->size; i++)
    {
        if(multime->elem[i]==elem)
        {
            return 1;
        }
    }
    return 0;
}

void adauga(Multime *multime, int element)
{
    if(apartine(multime, element)==0)
    {
        if(multime->size<MAX_SIZE)
        {
        multime->elem[multime->size]=element;
        multime->size++;
        }   
        else
        {
            printf("Multimea e plina.\n");
        }
    }
}

void sterge(Multime *multime, int element)
{
    for(int i=0; i<multime->size; i++)
    {
        if(multime->elem[i]==element)
        {
            for(int j=i; j<multime->size-1; j++)
            {
                multime->elem[j]=multime->elem[j+1];
            }
            multime->size--;
        }
    }
}

Multime *reuniune(Multime *a, Multime *b)
{
    Multime *rezultat = creeazaMultime();
    for(int i=0; i<a->size;i++)
    {
        adauga(rezultat, a->elem[i]);
    }

    for(int i=0; i<b->size; i++)
    {
        adauga(rezultat, b->elem[i]);
    }
    return rezultat;
}

Multime *intersectie(Multime *a, Multime *b)
{
    Multime *rezultat= creeazaMultime();
    for(int i=0; i<a->size; i++)
    {
        if(apartine(b, a->elem[i]))
        {
            adauga(rezultat, a->elem[i]);
        }
    }
    return rezultat;
}

Multime *diferenta(Multime *a, Multime *b)
{
    Multime *rezultat=creeazaMultime();
    for(int i=0; i<a->size; i++)
    {
        if(apartine(b, a->elem[i])==0)
        {
            adauga(rezultat, a->elem[i]);
        }
    }
    return rezultat;
}

void afiseaza(Multime *multime)
{
    printf("{ ");
    for(int i=0; i<multime->size; i++)
    {
        printf("%d ", multime->elem[i]);
    }
    printf("}\n");
}

void eliberare(Multime *multime)
{
    free(multime->elem);
    free(multime);
}

void p6()
{
    Multime* multime1 = creeazaMultime();
    Multime* multime2 = creeazaMultime();

    adauga(multime1, 1);
    adauga(multime1, 2);
    adauga(multime1, 3);

    adauga(multime2, 3);
    adauga(multime2, 4);
    adauga(multime2, 5);

    printf("Multimea 1: ");
    afiseaza(multime1);

    printf("Multimea 2: ");
    afiseaza(multime2);

    Multime* reuniuneRez = reuniune(multime1, multime2);
    printf("Reuniunea: ");
    afiseaza(reuniuneRez);

    Multime* intersectieRez = intersectie(multime1, multime2);
    printf("Intersectia: ");
    afiseaza(intersectieRez);

    Multime* diferentaRez = diferenta(multime1, multime2);
    printf("Diferenta: ");
    afiseaza(diferentaRez);


    eliberare(multime1);
    eliberare(multime2);
    eliberare(reuniuneRez);
    eliberare(intersectieRez);
    eliberare(diferentaRez);

}


//Exercitiul 2

typedef struct{
    double real;
    double imag;
}Complex;

Complex creareComplex(double real, double imag)
{
    Complex c;
    c.real=real;
    c.imag=imag;
    return c;
}

void afiseazaComplex(Complex c)
{
    if(c.imag>0)
    printf("%.2f + %.2fi\n", c.real,c.imag);
    else
    printf("%.2f %.2fi\n", c.real,c.imag);
}

Complex adunare(Complex a, Complex b)
{
    Complex rez;
    rez.real=a.real+b.real;
    rez.imag=a.imag+b.imag;
    return rez;
}

Complex scadere(Complex a, Complex b)
{
    Complex rez;
    rez.real=a.real-b.real;
    rez.imag=a.imag-b.imag;
    return rez;
}

Complex inmultire(Complex a, Complex b)
{
    Complex rez;
    rez.real=a.real*b.real - a.imag*b.imag;
    rez.imag=a.real*b.imag + a.imag*b.real;
    return rez;
}

double modulComplex(Complex nr)
{
    return sqrt(nr.real*nr.real+nr.imag*nr.imag);
}

void p7()
{
    Complex c1=creareComplex(3.0,4.0);
    Complex c2=creareComplex(1.0,2.0);

    printf("Numarul complex 1 este : ");
    afiseazaComplex(c1);

    printf("Numarul complex 2 este : ");
    afiseazaComplex(c2);

    Complex sum=adunare(c1,c2);
    printf("Suma : ");
    afiseazaComplex(sum);

    Complex diferenta=scadere(c1,c2);
    printf("Diferenta : ");
    afiseazaComplex(diferenta);

    Complex produs=inmultire(c1,c2);
    printf("produsul: ");
    afiseazaComplex(produs);

    double modul=modulComplex(c1);
    printf("Modulul lui c1: %.2f\n", modul);

}

int main(void)
{
    //p1();
    //p2();
    p7();
    return 0;
}