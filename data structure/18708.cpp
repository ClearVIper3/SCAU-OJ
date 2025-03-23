#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
    
    vector<int> dp(n + 1,0);
    int res = -99999;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i - 1],arr[i - 1]);
        res = max(res,dp[i]);
    }
    
    printf("%d",res);
    return 0;
}
