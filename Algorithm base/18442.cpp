#include <iostream>
#include <algorithm>
using namespace std;

int dfs(int n,int s,int step)
{
    if(n == 3)
        return 777777;
    else if(n < 3)
        return s;
    return min(dfs(n - n / 2,s,step * 2),dfs(n / 2,s + step,step * 2));
}

int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        int q = dfs(n,1,1);
        if(q == 777777)
            cout << "0" << endl;
        else
            cout << q << endl;
    }

    return 0;
}
