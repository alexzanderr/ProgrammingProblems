#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student student;
struct student
{
    char nume[30];
    int varsta;
};

int compara(const void* unu, const void* doi)
{
    student *x = (student *) unu;
    student *y = (student *) doi;
    if (strcmp((*x).nume,(*y).nume) != 0)
        return -1;
    return (*x).varsta - (*y).varsta;
}
int main()
{

    struct student *v;
    int n;
    scanf("%d",&n);
    v = (struct student*) malloc (n * sizeof(struct student));
    for(int i=0; i<n; i++)
    {
        printf("nume = ");
        scanf("%s",v[i].nume);
        printf("varsta = ");
        scanf("%d",&v[i].varsta);
    }
    for(int i=0; i<n; i++)
        printf("%s - %d\n",v[i].nume, v[i].varsta);
    qsort(v,n,sizeof(student),compara);
    printf("\n");
    for(int i=0; i<n; i++)
        printf("%s - %d\n",v[i].nume, v[i].varsta);

    free(v);
    return 0;
}
