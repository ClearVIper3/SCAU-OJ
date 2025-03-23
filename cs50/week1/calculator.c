#include<cs50.h>
#include<stdio.h>

void meow(int b);
int main(void)
{
    meow(8);
}
void meow(int b)
{
    for(int a = 0; a<b ;a++)
    {
        printf("meow\n");
    }
}
