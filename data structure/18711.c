#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    char string[n];
    scanf("%s", string);

    int bol[26] = {0};
    char RS[n];
    int d = 0;

    for(int i = 0; i < n ; i++)
    {
        char c = string[i];
        if(bol[string[i] - 'a'] == 0)
        {
            RS[d] = c;
            bol[string[i] - 'a'] = 1;
            d++;
        }
    }

    RS[d] = '\0';

    for (int i = 0; i < d; i++)
    {
        for (int j = i + 1; j < d; j++)
        {
            if(RS[i]>RS[j])
            {
                char ch = RS[i];
                RS[i] = RS[j];
                RS[j] = ch;
            }
        }
    }
    printf("%s", RS);
    return 0;
}
