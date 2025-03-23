#include<stdio.h>
#include<math.h>

int main(void)
{
    float a,b;
    float c=0;
    char d;
    scanf("%f%c%f",&a,&d,&b);
    c=a*a+b*b;
    if(fabs(c - 1) < 0.001)
    {
        printf("Y");
    }
    else
    {
        printf("N");
    }
}
