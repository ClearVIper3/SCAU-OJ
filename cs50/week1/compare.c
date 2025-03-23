#include<cs50.h>
#include<stdio.h>
int main(void)
{
    int a= get_int("what is a?");
    int b= get_int("what is b?");

    if (a < b)
        {
        printf("a xiao yv b!\n");
        }
    else if(a == b)
        {
        printf("a deng yv b!\n");
        }
    else if(a > b)
        {
        printf("a da yv b!\n");
        }
}
