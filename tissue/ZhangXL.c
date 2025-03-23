#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void plane();
void neo();
void tp();
int fly(int piece);

int main()
{
    plane();
    tp();
    printf("\n");
    neo();
}

int fly(int piece)
{
    for(int o=0;o<piece*14;o++)
    {
        printf(" ");
    }
    return 0;
}

void plane()
{
    for(int i=0;i<8;i++)
    {
    fly(i);
    printf("         *\n");
    fly(i);
    printf("         ***\n");
    fly(i);
    printf("         *****\n");
    fly(i);
    printf("         *******\n");
    fly(i);
    printf("*****************************\n");
    fly(i);
    printf("         *****   *****          \\   \n");
    fly(i);
    printf("         *****   *****          /  \n");
    fly(i);
    printf("*****************************\n");
    fly(i);
    printf("         *******             \n");
    fly(i);
    printf("         *****               \n");
    fly(i);
    printf("         ***                  \n");
    fly(i);
    printf("         *                    \n");
    sleep(1);
    system("clear");
    }
}

void tp()
{
    fly(8);
    printf("         *\n");
    fly(8);
    printf("         ***\n");
    fly(8);
    printf("         *****\n");
    fly(8);
    printf("         *******\n");
    fly(8);
    printf("*****************************\n");
    fly(8);
    printf("         *****   *****          \\   \n");
    fly(8);
    printf("         *****   *****          /  \n");
    fly(8);
    printf("*****************************\n");
    fly(8);
    printf("         *******             \n");
    fly(8);
    printf("         *****               \n");
    fly(8);
    printf("         ***                  \n");
    fly(8);
    printf("         *                    \n");
}

void neo()
{
    fly(9);
    printf("士兵 少帅 士兵\n");
    sleep(2);
    printf("\033[1A\033[2K");
    printf("\n");
    fly(9);
    printf("士兵 少帅 士兵\n");
    sleep(2);
    printf("\033[1A\033[2K");
    printf("\n");
    fly(9);
    printf("士兵 少帅 士兵\n");
    sleep(2);
    printf("\033[1A\033[2K");
    printf("\n");
    fly(9);
    printf("士兵 少帅 士兵\n");
    sleep(2);
    printf("\033[1A\033[2K");
    printf("\n");
    fly(9);
    printf("士兵 少帅 士兵\n");
}
