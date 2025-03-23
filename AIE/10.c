//零元购
#include <stdio.h>

int main()
{
    int n, t;

    scanf("%d%d", &n, &t);      //输入零食种类数和购物袋容量

    int x[n];           //数量
    int v[n];           //体积
    int w[n];           //价格
    int value[n];       //性价比

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x[i], &v[i], &w[i]);//输入每种零食的信息
        value[i]=w[i]/v[i];
    }

    int cash=0; //记录最大花费
    int last_t=t; //剩余容量

    //性价比从大到小重新排列零食 Bubble sort
    for(int i=0;i<n-1;i++)
    {
        for(int u=0;u<n-i-1;u++)
        {
            if(value[u]<value[u+1])
            {
                int term1=x[u];
                int term2=v[u];
                int term3=w[u];
                x[u]=x[u+1];
                v[u]=v[u+1];
                w[u]=w[u+1];
                x[u+1]=term1;
                v[u+1]=term2;
                w[u+1]=term3;
            }
        }
    }

    for(int i=0;i<n;i++)    //计算最大金额 贪心算法
     {
        //计算当前零食能装的最大数量
        int maxbuy=last_t/v[i];     //int直接省略小数点
        //实际购买数量取数量与能装的最大数量中的较小者

        int realbuy;//真实购买量

        if(maxbuy<x[i])         //x零食数量
        {
            realbuy=maxbuy;    //不能装完此零食
        }
        else
        {
            realbuy=x[i];       //能装完此零食
        }

        // 更新剩余容量和总花费
        last_t-=realbuy*v[i];
        cash+=realbuy*w[i];

        if(last_t==0)      //剩余容量为0
        {
            break;
        }
    }

    printf("%d\n", cash);      //打印结果
    return 0;
}
