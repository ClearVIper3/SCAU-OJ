#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int cash;
    int q=0;
    int w=0;
    int e=0;
    int points=0;
    do
    {
        cash=get_int("Change owed:");
    }
    while (cash<0);
    if(cash>=25)
    {
        do
        {
            cash-=25;
            points++;
        }
        while(cash>=25);
    }
    q=cash;
    if(q>=10)
    {
        do
        {
            q-=10;
            points++;
        }
        while(q>=10);
    }
    w=q;
    if(w>=5)
    {
        do
        {
            w-=5;
            points++;
        }
        while(w>=5);
    }
    e=w;
    if(e>=1)
    {
        do
        {
            e-=1;
            points++;
        }
        while(e>=1);
    }
    printf("%d\n",points);
}
