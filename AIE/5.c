//放逐
#include<stdio.h>
#include<string.h>      //strlen();strcpy();

#define MaxBit 101  // 最大支持100位(10^100)

int cmp(char a[],char b[]);     //(声明)比较两个数字的int函数，求最大值

int main()
{
    int n;
    scanf("%d",&n);     //被投人数

    if(!(n>=1&&n<=20))      //检查是否1<=n<=20
    {
        return 1;
    }

    char candidate[n][MaxBit];      //被投票的人的票数变量

    for(int i=0;i<n;i++)
    {
        scanf("%s",candidate[i]);       //输入各候选人的被投票数
    }

    char max[MaxBit]="0";               //最大票数char变量
    int num=0;                          //偷踢人的位次

    for(int i=0;i<n;i++)                //求最大值函数
    {
        if(cmp(candidate[i],max)>0)       //>0(返回了1)则说明检测到比max还大的数
        {
            strcpy(max,candidate[i]);       //把max赋值到更大数者
            num=i+1;                        //更新被踢人的位次
        }
    }

    printf("%d\n%s\n",num,max);             //打印结果
}

int cmp(char a[],char b[])      //比较两个数字的int函数，求最大值
{
    int length1=strlen(a);      //获取被比较数的位数
    int length2=strlen(b);

    if(length1>length2)          //位数更大(数字更长的)就更大
    {
        return 1;
    }
    else if(length1<length2)
    {
        return -1;
    }
    else                        //a==b，数位相同的时候
    {
        for(int i=0;i<length1;i++)      //逐位比较，一比较到具体位数更大的就结束函数
        {
            if(a[i]>b[i])
            {
                return 1;
            }
            else if(a[i]<b[i])
            {
                return -1;
            }
        }
    }
    return 0;
}
