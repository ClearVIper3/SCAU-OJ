#include <iostream>
#include <map>
using namespace std;

map<int,int> mp;
int dfs(int n)
{
    if(mp[n] != 0) return mp[n];
    else if(n < 3) return 0;
    else if(n == 3) return 1;
    mp[n / 2] = dfs(n / 2);
    mp[n - (n / 2)] = dfs(n - (n / 2));
    return mp[n / 2] + mp[n - (n / 2)];
}

int main()
{
    int n;
    while(scanf("%d",&n) && n != 0)
    {
        mp[n] = dfs(n);
        printf("%d\n",mp[n]);
    }
    return 0;
}
