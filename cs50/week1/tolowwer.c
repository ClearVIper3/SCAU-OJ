#include<stdio.h>
#include<cs50.h>

int main()
{
    string a=get_string("input:");
    int length=0;
    while(a[length]!=0)
    {
        length++;
    }
    for(int i=0;i<length;i++)
    {
        if(a[i]>'a'&&a[i]<'z')
        {
            printf("%c",a[i]);
        }
        else
        {
            printf("%c",a[i]+32);
        }
    }
    printf("\n%d\n",length);
}
