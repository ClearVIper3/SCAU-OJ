#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(int argc,char*argv[])
{
    if(argc<2)
    {
        printf("Usage: runoff [candidate ...]  ");
        return 1;
    }
    int voters=get_int("Number of voters:");

    char*candidate1[3];
    char*candidate2[3];
    char*candidate3[3];

    candidate1[0]=get_string("Rank1:");
    if(strcmp(candidate1[0],argv[3])!=0&&strcmp(candidate1[0],argv[1])!=0&&strcmp(candidate1[0],argv[2])!=0)
    {
        printf("Invalid vote.\n");
        return 1;
    }
    candidate1[1]=get_string("Rank2:");
    if(strcmp(candidate1[1],argv[3])!=0&&strcmp(candidate1[1],argv[1])!=0&&strcmp(candidate1[1],argv[2])!=0)
    {
        printf("Invalid vote.\n");
        return 1;
    }
    candidate1[2]=get_string("Rank3:");
    if(strcmp(candidate1[2],argv[3])!=0&&strcmp(candidate1[2],argv[1])!=0&&strcmp(candidate1[2],argv[2])!=0)
    {
        printf("Invalid vote.\n");
        return 1;
    }
    printf("\n");
    candidate2[0]=get_string("Rank1:");
    if(strcmp(candidate2[0],argv[3])!=0&&strcmp(candidate2[0],argv[1])!=0&&strcmp(candidate2[0],argv[2])!=0)
    {
        printf("Invalid vote.\n");
        return 1;
    }
    candidate2[1]=get_string("Rank2:");
    if(strcmp(candidate2[1],argv[3])!=0&&strcmp(candidate2[1],argv[1])!=0&&strcmp(candidate2[1],argv[2])!=0)
    {
        printf("Invalid vote.\n");
        return 1;
    }
    candidate2[2]=get_string("Rank3:");
    if(strcmp(candidate2[2],argv[3])!=0&&strcmp(candidate2[2],argv[1])!=0&&strcmp(candidate2[2],argv[2])!=0)
    {
        printf("Invalid vote.\n");
        return 1;
    }
    printf("\n");
    candidate3[0]=get_string("Rank1:");
    if(strcmp(candidate3[0],argv[3])!=0&&strcmp(candidate3[0],argv[1])!=0&&strcmp(candidate3[0],argv[2])!=0)
    {
        printf("Invalid vote.\n");
        return 1;
    }
    candidate3[1]=get_string("Rank2:");
    if(strcmp(candidate3[1],argv[3])!=0&&strcmp(candidate3[1],argv[1])!=0&&strcmp(candidate3[1],argv[2])!=0)
    {
        printf("Invalid vote.\n");
        return 1;
    }
    candidate3[2]=get_string("Rank3:");
    if(strcmp(candidate3[2],argv[3])!=0&&strcmp(candidate3[2],argv[1])!=0&&strcmp(candidate3[2],argv[2])!=0)
    {
        printf("Invalid vote.\n");
        return 1;
    }
    printf("\n");

    int A[3];
    int B[3];
    int C[3];

    for(int i=0;i<3;i++)
    {
        A[i]=0;
        B[i]=0;
        C[i]=0;
    }

    for(int i=0;i<3;i++)
    {
        if(strcmp(candidate1[i],argv[1])==0)
        {
            A[i]++;
        }
        else if(strcmp(candidate1[i],argv[2])==0)
        {
            B[i]++;
        }
        else if(strcmp(candidate1[i],argv[3])==0)
        {
            C[i]++;
        }
    }

    for(int i=0;i<3;i++)
    {
        if(strcmp(candidate2[i],argv[1])==0)
        {
            A[i]++;
        }
        else if(strcmp(candidate2[i],argv[2])==0)
        {
            B[i]++;
        }
        else if(strcmp(candidate2[i],argv[3])==0)
        {
            C[i]++;
        }
    }

    for(int i=0;i<3;i++)
    {
        if(strcmp(candidate3[i],argv[1])==0)
        {
            A[i]++;
        }
        else if(strcmp(candidate3[i],argv[2])==0)
        {
            B[i]++;
        }
        else if(strcmp(candidate3[i],argv[3])==0)
        {
            C[i]++;
        }
    }

    if(A[0]==B[0])//add:same 3;
    {
        if(A[0]<C[0])
        {
            printf("Charlie");
        }
        else
        {
            if(A[1]==B[1])
            {
                if(A[2]>B[2])
                {
                    printf("Alice");
                }
                else if(A[2]<B[2])
                {
                    printf("Bob");
                }
            }
            else if(A[1]>B[1])
            {
                printf("Alice");
            }
            else if(A[1]<B[1])
            {
                printf("Bob");
            }
        }
    }
    else if(A[0]==C[0])
    {
        if(A[0]<B[0])
        {
            printf("Bob");
        }
        else
        {
            if(A[1]==C[1])
            {
                if(A[2]>C[2])
                {
                    printf("Alice");
                }
                else if(A[2]<C[2])
                {
                    printf("Charlie");
                }
            }
            else if(A[1]>C[1])
            {
                printf("Alice");
            }
            else if(A[1]<C[1])
            {
                printf("Charlie");
            }
        }
    }
    else if(B[0]==C[0])
    {
        if(B[0]<A[0])
        {
            printf("Alice");
        }
        else
        {
           if(C[1]==B[1])
            {
                if(C[2]>B[2])
                {
                    printf("Charlie");
                }
                else if(C[2]<B[2])
                {
                    printf("Bob");
                }
            }
            else if(C[1]>B[1])
            {
                printf("Charlie");
            }
            else if(C[1]<B[1])
            {
                printf("Bob");
            }
        }
    }
    else if(A[0]>B[0]&&A[0]>C[0])
    {
        printf("Alice");
    }
    else if(B[0]>A[0]&&B[0]>C[0])
    {
        printf("Bob");
    }
    else if(C[0]>A[0]&&C[0]>B[0])
    {
        printf("Charlie");
    }
    printf("\n");
}
