#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<string.h>

int main(int length,char*key[])
{
    string plaintext;

    if(length!=2)
    {
        printf("Usage:./substitution key");
        return 1;
    }

    if(strlen(key[1])!=26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    for(int i=0;key[1][i];i++)
    {
        if(!isalpha(key[1][i]))
            {
                printf("Usage:./substitution key");
                return 1;
            }
    }

        bool seen[26] = {false}; // 用于追踪字母是否已出现
    for (int i = 0; i < 26; i++)
    {
        // 检查是否为字母
        if (!isalpha(key[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        // 处理大小写并检查重复字符
        int index = tolower(key[1][i]) - 'a'; // 统一处理为小写
        if (seen[index])
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        seen[index] = true; // 标记该字母已经出现
    }

    plaintext=get_string("plaintext:");
    printf("ciphertext:");

    for(int u=0;plaintext[u];u++)
    {
        if(isupper(plaintext[u]))
        {
            printf("%c",toupper(key[1][plaintext[u]-'A']));
        }
        else if(islower(plaintext[u]))
        {
            printf("%c",tolower(key[1][plaintext[u]-'a']));
        }
        else
        {
            printf("%c",plaintext[u]);
        }
    }
    printf("\n");
    return 0;
}


