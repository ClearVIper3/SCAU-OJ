#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int counts=0;
    long digit=0;
    long digit1=0;
    int sum1=0;
    int sum2=0;
    int sum=0;
    long num=get_long("Number:");

    digit1=num;
    while(num>0)
    {
        digit=num%10;
        if(counts%2==0)
        {
            sum1+=digit;
        }
        else
        {
            int doubled = digit * 2;
            if (doubled > 9)
        {
                sum2 += doubled - 9;
        }
            else
            {
                sum2 += doubled;
            }
        }
        counts++;
        num/=10;
    }
    sum=sum1+sum2;
    if(sum%10==0)
    {
        while(digit1>100)
        {
            digit1/=10;
        }
        if((digit1==51||digit1==52||digit1==53||digit1==54||digit1==55)&&counts==16)
        {
            printf("MASTERCARD\n");
        }
        else if((digit1==34||digit1==37)&&counts==15)
        {
            printf("AMEX\n");
        }
        else if((digit1/10==4)&&(counts==13||counts==16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
