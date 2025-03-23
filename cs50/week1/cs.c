#include<cs50.h>
#include<stdio.h>

int main(void)
{
    const int b=4;
    for(int n=1 ;n<b; n++)
    {
        printf("hajimi?\n");
    }
    int a=5;
    if (a==5)
    {
        printf("hao de\n");
    }
    int x;
    do
    {
        x =get_int("duo da?\n");
    }
    while(x<0);
    for(int o=1;o<x;o++)
    {
        printf("ke yi!\n");
    }
}
