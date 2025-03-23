//最小答案
#include<stdio.h>

int main()
{
    int xn[4];  //int数字
    char a[3];  //char运算符

    scanf("%d%d%d%d",&xn[0],&xn[1],&xn[2],&xn[3]);      //输入数字
    scanf(" %c%c%c",&a[0],&a[1],&a[2]);                 //输入运算符


    for(int i=0;i<3;i++)            //冒泡算法 从小到大排列xn
    {
        for (int j=0;j<3-i;j++)
        {
            if (xn[j]>xn[j + 1])
            {
                int temp =xn[j];
                xn[j]=xn[j+1];
                xn[j+1]=temp;
            }
        }
    }

    int new3=0;                 //最终结果new3

    if(a[0]=='*')               //依次处理运算符
    {                           //优先*，优先小数相乘，大数相加
        int new1=xn[0]*xn[1];
        if(a[1]=='*')
        {
            if(new1>xn[3])
            {
                int new2=xn[2]*xn[3];
                if(a[2]=='*')
                {
                    new3=new2*new1;
                }
                else
                {
                    new3=new2+new1;
                }
            }
            else
            {
                int new2=new1*xn[2];
                if(a[2]=='*')
                {
                    new3=new2*xn[3];
                }
                else
                {
                    new3=new2+xn[3];
                }
            }
        }
        else
        {
            if(new1>xn[3])
            {
                int new2=new1+xn[2];
                if(a[2]=='*')
                {
                    new3=new2*xn[3];
                }
                else
                {
                    new3=new2+xn[3];
                }
            }
            else
            {
                int new2=xn[2]+xn[3];
                if(a[2]=='*')
                {
                    new3=new2*new1;
                }
                else
                {
                    new3=new2+new1;
                }
            }
        }
    }
    else
    {
        int new1=xn[2]+xn[3];
        if(a[1]=='+')
        {
            int new2=new1+xn[1];
            if(a[2]=='*')
            {
                new3=new2*xn[2];
            }
            else
            {
                new3=new2+xn[2];
            }
        }
        else
        {
            int new2=xn[1]*xn[2];
            if(a[2]=='*')
            {
                new3=new2*new1;
            }
            else
            {
                new3=new2+new1;
            }
        }
    }
    printf("%d",new3);              //打印结果
}
