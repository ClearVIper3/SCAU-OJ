#include<stdio.h>
#include<cs50.h>
#include <ctype.h>

int main(void)
{
    string Player1=get_string("Player 1:");
    string Player2=get_string("Player 2:");


    int length1=0;
    int length2=0;
    int point1=0;
    int point2=0;

    for(int i=0;Player1[i]!='\0';i++)
    {
        Player1[i]=toupper(Player1[i]);
    }
    for(int u=0;Player2[u]!='\0';u++)
    {
        Player2[u]=toupper(Player2[u]);
    }

    while(Player1[length1]!='\0')
    {
        if(Player1[length1]=='A'||Player1[length1]=='E'
        ||Player1[length1]=='I'||Player1[length1]=='L'
        ||Player1[length1]=='N'||Player1[length1]=='O'
        ||Player1[length1]=='R'||Player1[length1]=='S'
        ||Player1[length1]=='T'||Player1[length1]=='U')
        {
            point1+=1;
            length1++;
        }
        else if(Player1[length1]=='D'||Player1[length1]=='G')
        {
            point1+=2;
            length1++;
        }
        else if(Player1[length1]=='B'||Player1[length1]=='C'
        ||Player1[length1]=='M'||Player1[length1]=='P')
        {
            point1+=3;
            length1++;
        }
        else if(Player1[length1]=='F'||Player1[length1]=='H'
        ||Player1[length1]=='V'||Player1[length1]=='W'
        ||Player1[length1]=='Y')
        {
            point1+=4;
            length1++;
        }
        else if(Player1[length1]=='K')
        {
            point1+=5;
            length1++;
        }
        else if(Player1[length1]=='J'||Player1[length1]=='X')
        {
            point1+=8;
            length1++;
        }
        else if(Player1[length1]=='Q'||Player1[length1]=='Z')
        {
            point1+=10;
            length1++;
        }
        else
        {
            length1++;
        }
    }
    while(Player2[length2]!='\0')
    {
        if(Player2[length2]=='A'||Player2[length2]=='E'
        ||Player2[length2]=='I'||Player2[length2]=='L'
        ||Player2[length2]=='N'||Player2[length2]=='O'
        ||Player2[length2]=='R'||Player2[length2]=='S'
        ||Player2[length2]=='T'||Player2[length2]=='U')
        {
            point2+=1;
            length2++;
        }
        else if(Player2[length2]=='D'||Player2[length2]=='G')
        {
            point2+=2;
            length2++;
        }
        else if(Player2[length2]=='B'||Player2[length2]=='C'
        ||Player2[length2]=='M'||Player2[length2]=='P')
        {
            point2+=3;
            length2++;
        }
        else if(Player2[length2]=='F'||Player2[length2]=='H'
        ||Player2[length2]=='V'||Player2[length2]=='W'
        ||Player2[length2]=='Y')
        {
            point2+=4;
            length2++;
        }
        else if(Player2[length2]=='K')
        {
            point2+=5;
            length2++;
        }
        else if(Player2[length2]=='J'||Player2[length2]=='X')
        {
            point2+=8;
            length2++;
        }
        else if(Player2[length2]=='Q'||Player2[length2]=='Z')
        {
            point2+=10;
            length2++;
        }
        else
        {
            length2++;
        }
    }
    if(point1>point2)
    {
        printf("Player 1 wins!");
    }
    else if(point1==point2)
    {
        printf("Tie!");
    }
    else if(point1<point2)
    {
        printf("Player 2 wins!");
    }
}
