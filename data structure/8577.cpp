#include <stdio.h>
#include<stdlib.h>

#define MAXVAL 100

typedef struct
{
    int *elem;
    int length;
}list;

void head(list &L)
{
    int n;
    scanf("%d",&n);
    L.length = n;
    L.elem = new int[MAXVAL];
}

void insert(list&L)
{
    for(int i = 0; i < L.length; i++)
    {
        scanf("%d",&L.elem[i]);
    }
}

void link(list& L, list& C)
{
    for(int i = 0; i < L.length ; i++)
    {
        L.elem[i+L.length] = C.elem[i];
    }
    L.length +=C.length;
}

void sort(list &L)
{
    for(int i = 0 ; i < L.length ; i++)
    {
        for(int j = i + 1 ; j < L.length ; j++)
        {
            if(L.elem[i] > L.elem[j])
            {
                int tmp = L.elem[i];
                L.elem[i] = L.elem[j];
                L.elem[j] = tmp;
            }
        }
    }
}

int main()
{
    list A,B;

    head(A);
    insert(A);
    
    head(B);
    insert(B);

    sort(A);
    sort(B);

    printf("List A:");
    for(int i = 0 ; i < A.length ; i++)
    {
        printf("%d ",A.elem[i]);
    }

    printf("\nList B:");
    for(int i = 0 ; i < B.length ; i++)
    {
        printf("%d ",B.elem[i]);
    }

    link(A,B);

    sort(A);

    printf("\nList C:");
    for(int i = 0 ; i < A.length ; i++)
    {
        printf("%d ",A.elem[i]);
    }

    printf("\n");

    free(A.elem);

    return 0;
}
