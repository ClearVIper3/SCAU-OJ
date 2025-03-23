#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<ctype.h>

int main(int length,char*key[])
{
    char ciphertext[100];

    if(length!=2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for(int u=0;key[1][u];u++)
        {
            if (!isdigit(key[1][u]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        }
        int ky=atoi(key[1]);

        if(ky<0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            string plaintext=get_string("plaintext:");

            for(int i=0;plaintext[i]!='\0';i++)
        {
            if(plaintext[i]>='A'&&plaintext[i]<='Z')
            {
                ciphertext[i]=(plaintext[i]+ky-'A')%26+'A';
            }
            else if(plaintext[i]>='a'&&plaintext[i]<='z')
            {
                ciphertext[i]=(plaintext[i]+ky-'a')%26+'a';
            }
            else
            {
                ciphertext[i]=plaintext[i];
            }
        }
        }
        printf("ciphertext:%s\n",ciphertext);
    }
    return 0;
}
