#include<stdio.h>
#include<cs50.h>

void zhuang(int z,int k);
int main(void)
{
    int h;
    do
    {
        h=get_int("Heights:");
    }
    while (h<1||h>8);

    for(int c=0;c<h;c++) //c:打印多少行（次）     k：多少空格     z:多少#     h：高度
    {
        zhuang(c+1,h-c-1);
    }
}

void zhuang(int z,int k)
{

    for(int o=0;o<k;o++)
    {
        printf(" ");
    }
    for(int u=0;u<z;u++)
    {
        printf("#");
    }
    printf("  ");
    for(int u=0;u<z;u++)
    {
        printf("#");
    }
    printf("\n");
}
submit50 cs50/problems/2024/x/mario/more
