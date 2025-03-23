#include<stdio.h>
#include<cs50.h>

int main(void)
{
    string essay=get_string("Text:");
    float letters=0;
    float words=1;
    float sentences=0;
    int o=0;
    float L=0;
    float S=0;
    float index=0;

    for(int i=0;essay[i]!='\0';i++)
    {
        if((essay[i]>='A'&&essay[i]<='Z')||(essay[i]>='a'&&essay[i]<='z'))
        {
            letters++;
        }
        else
        {
            if(essay[i]==' '|| essay[i] == '\n'||essay[i]=='\'')
            {
                words++;
            }
            else if(essay[i]=='.'||essay[i]=='?'||essay[i]=='!'||essay[o]=='\"')
            {
                sentences++;
            }
        }
        o=i-1;
    }

    if(essay[o]=='.'||essay[o]=='?'||essay[o]=='!'||essay[o]=='"')
    {
        words++;
    }

    L=(letters/words)*100;
    S=(sentences/words)*100;
    index=0.0588*L-0.296*S-15.8;
printf("%f",index);
    if(index<=1)
    {
        printf("Before Grade 1");
    }
    else if(index<=2||index<3)
    {
        printf("Grade 2");
    }
    else if(index<=3)
    {
        printf("Grade 3");
    }
    else if(index<=4)
    {
        printf("Grade 4");
    }
    else if(index<=5)
    {
        printf("Grade 5");
    }
    else if(index<=6)
    {
        printf("Grade 6");
    }
    else if(index<=7)
    {
        printf("Grade 7");
    }
    else if(index<=8)
    {
        printf("Grade 8");
    }
    else if(index<=9)
    {
        printf("Grade 9");
    }
    else if(index<=10)
    {
        printf("Grade 10");
    }
    else if(index<=11)
    {
        printf("Grade 11");
    }
    else if(index<=12)
    {
        printf("Grade 12");
    }
    else if(index<=13)
    {
        printf("Grade 13");
    }
    else if(index<=14)
    {
        printf("Grade 14");
    }
    else if(index<=15)
    {
        printf("Grade 15");
    }
    else if(index>15)
    {
        printf("Grade 16+");
    }
    printf("\n");
}
