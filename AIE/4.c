//算命
#include<stdio.h>
#include<stdlib.h>  //atoi();

int main()
{
    int n;
    scanf("%d",&n);             //输入n

    char x[1000][5];            //x储备1到1000的数（char字符串）

    for(int i=0;i<1000;i++)
    {
        sprintf(x[i], "%d", i);     //stdio.h
    }

    int xn[1001];         //atoi将char转化为int
    int tr_num=0;

    for(int i=0;i<1000;i++)                     //找出1到1000中所有的噩兆数，并存为xn
    {
        for(int u=0;u<4;u++)
        {
            if(x[i][u]=='4'||x[i][u]=='7')
            {
                if(i>=1&&i<10)                  //个位数的噩兆数
                {
                    tr_num++;
                    xn[tr_num]=atoi(x[i]);
                    break;
                }
                if(i>=10&&i<100)                //两位数的噩兆数
                {
                    if(x[i][u+1]=='4'||x[i][u+1]=='7')
                    {
                        tr_num++;
                        xn[tr_num]=atoi(x[i]);
                        break;
                    }
                }
                else if(i>=100&&i<=999)             //三位数的噩兆数
                {
                    if(x[i][u+2]=='4'||x[i][u+2]=='7')
                    {
                        tr_num++;
                        xn[tr_num]=atoi(x[i]);
                        break;
                    }
                }
            }
        }
    }

    for(int i=1;i<tr_num;i++)           //判断是否为噩兆数，是则打印 YES
    {
        if(n==xn[i]||n%xn[i]==0)        //直接是噩兆数||能被噩兆数整除
        {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");             //不是噩兆数则打印 NO
    return 0;
}
