#include<cs50.h>
#include<stdio.h>

int main(void)
{
    char c = get_char("ni tong yi ma?\n");
    if (c == 'b')
        printf("bu yao!\n");
    else if(c == 'h')
        printf("hao de!\n");
}
