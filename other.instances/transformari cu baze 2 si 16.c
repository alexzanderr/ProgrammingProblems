#include <stdio.h>
#include <stdlib.h>

void transformare_baza_10_baza_2_atentie_pare(int *);  ///declararea unei functii = antetul unei functii
void transformare_corecta(int *);
void transformare_corecta_cu_vectori(int, int*, int*);
void transformare_cu_vectori_hexa(int, int*, int*);
int main()
{
    int n = 717;
    ///  transformare_baza_10_baza_2_atentie_pare(&n);
    ///  transformare_corecta(&n);
    ///  transformare_corecta_cu_vectori(n,v,&dim);

    int v[100] = {0}, dim;
    transformare_cu_vectori_hexa(n,v,&dim);
    for(int i = dim-1; i>=0; i--)
    {
        switch(v[i])
        {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d",v[i]);
        }
    }

    return 0;
}
/* generare de numere aleatoare */
/* #include <time.h>
srand(time(0));
int inv = rand();*/

void transformare_baza_10_baza_2_atentie_pare(int *n) ///definire functie = antet + corp
{
    int inv = 0;
    while ((*n)!=0)
    {
        inv = inv * 10 + (*n)%2;
        (*n) = (*n)/2;
    }
    while(inv!=0)
    {
        (*n) = (*n) *10+inv%10;
        inv = inv /10;
    }
}

void transformare_corecta(int *n)
{
    int p = 1;
    int inv = 0;
    while ((*n)!=0)
    {
        inv = inv + ((*n)%2)*p;
        p = p * 10;
        (*n) = (*n)/2;
    }
    (*n) = inv;
}

void transformare_corecta_cu_vectori(int n, int*v, int *dim)
{
    *dim = 0;
    while(n)
    {
        v[*dim] = n%2;
        (*dim)++;
        n = n/2;
    }
}

void transformare_cu_vectori_hexa(int n, int*v, int *dim)
{
    *dim = 0;
    while(n)
    {
        v[*dim] = n%16;
        (*dim)++;
        n = n/16;
    }
}
