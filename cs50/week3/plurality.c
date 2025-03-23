#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(int argc,char*argv[])
{
   if(argc<2)
    {
        printf("Usage:plurality [candidate ...]\n");
        return 1;
    }

    int voters=get_int("Number of voters:");

    int points[argc-1];

    for (int i = 0; i <argc-1; i++)
    {
        points[i] = 0;
    }

    for(int i=0;i<voters;i++)
    {
        bool vot=false;

        string name=get_string("Vote:");

        for(int u=0;u<argc-1;u++)
        {
            if(strcmp(name,argv[u+1])==0)
            {
                points[u]++;
                vot=true;
                break;
            }
        }
        if(!vot)
        {
            printf("Invalid vote.\n");
        }
    }

    int max=0;

    for(int i=0;i<argc-1;i++)
    {
        if(points[i]>max)
        {
            max=points[i];
        }
    }

    for(int i=0;i<argc-1;i++)
    {
        if(points[i]==max)
        {
            printf("%s\n",argv[i+1]);
        }
    }
    return 0;
}
