//启蒙
#include<stdio.h>

int gcd(int a,int b);//公约数
int lcm(int a, int b) ;//公倍数
int main()
{
    int a;
    scanf("%d",&a); //获取第一批CASE数量a
    int num1[a][2];//定义 第一批CASE的两个整数，a为行（行数量）。

    for(int i=0;i<a;i++)
    {
        scanf("%d %d",&num1[i][0],&num1[i][1]);//输入第一批CASE的两个整数
    }

    int num2[10][2];//第二批CASE
    int n=0;
    while(n<10)
    {
        scanf("%d %d",&num2[n][0],&num2[n][1]);//输入第二批CASE的两个整数
        if(num2[n][0]==0&&num2[n][1]==0)//检测到0 0就停止输入
        {
            break;
        }
        n++;
    }

    int num3[][2];//第三批CASE
    int m=0;
    while(m<10)
    {
        if(scanf("%d %d", &num3[m][0], &num3[m][1])==2)//检测是否输入与整数无关内容
        {
            m++;
        }
        else
        {
            break;  //检测输入完毕，跳出循环输入（如输入一个字母则跳出循环）
        }
    }

    int result1[a];
    int result2[n];
    int result3[m];
    //打印结果
    for(int i=0;i<a;i++)
    {
        result1[i]=lcm(num1[i][0],num1[i][1]);
        printf("%d \n",result1[i]);
    }
    printf("group 1 done\n");

    for(int i=0;i<n;i++)
    {
        result2[i]=lcm(num2[i][0],num2[i][1]);
        printf("%d \n",result2[i]);
    }
    printf("group 2 done\n");

    for(int i=0;i<m;i++)
    {
        result3[i]=lcm(num3[i][0],num3[i][1]);
        printf("%d \n",result3[i]);
    }
    printf("group 3 done\n");
}

// 计算最大公约数
int gcd(int a,int b)
{
    while (b!=0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 计算最小公倍数
int lcm(int a,int b)
{
    return(a*b)/gcd(a, b);
}
