//玛恩纳小手不是很干净
#include<stdio.h>

int main()
{
    int n,m;                //n能偷红包量，m红包种类
    scanf("%d%d",&n,&m);    //输入n，m

    int a[m];               //红包种类
    int b[m];               //红包金额

    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a[i],&b[i]);      //输入红包个数及其里面金额数
    }

    //金额从大到小重新排列红包 bubble sort
    for(int i=0;i<m-1;i++)          //不是m的原因是防止数组越界，以及处理至m-1组时即结束
    {
        for(int u=0;u<m-i-1;u++)
        {
            if(b[u]<b[u+1])
            {
                int term1=a[u];
                int term2=b[u];
                a[u]=a[u+1];
                b[u]=b[u+1];
                a[u+1]=term1;
                b[u+1]=term2;
            }
        }
    }

    int cash=0;
    int point=0;
    int point1=0;

    for(int i=0;i<m;i++)
    {
        if(n>=a[i])         //可全部偷走的红包
        {
            n-=a[i];          //累减能偷红包个数
            cash+=a[i]*b[i]; //累加可完全偷走的红包金额
        }
        else            //可部分偷走的红包
        {
            point1=n;       //剩下能偷红包个数
            point=i;        //记录下当前红包下标
            break;
        }
    }

    cash+=point1*b[point];      //加上能部分偷走的红包金额

    printf("%d",cash);          //打印结果（总金额）
    return 0;
}
