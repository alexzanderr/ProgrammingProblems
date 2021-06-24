#include <stdio.h>
#include <stdlib.h>
int compara(const void* unu, const void* doi)
{
    return *(int*)doi - *(int*)unu;
}
int main()
{
    int *v, n;
    scanf("%d",&n);
    v = (int*) malloc (n * sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d",&v[i]);
    for(int i=0; i<n; i++)
        printf("%d ",*(v+i));
    qsort(v,n,sizeof(int),compara);
    printf("\n");
    for(int i=0; i<n; i++)
        printf("%d ",*(v+i));

    free(v);
    return 0;
}
