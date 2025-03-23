#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string a,b;
    cin >> a;
    cin >> b;
    int res = 0;

    vector<vector<int>> dp(a.size() + 1,vector<int> (b.size() + 1,0));

    for(int i = 1; i <= a.size(); i++)
        for(int u = 1; u <= b.size(); u++)
        {
            if(a[i - 1] == b[u - 1])
                dp[i][u] = dp[i - 1][u - 1] + 1;
            else
                dp[i][u] = max(dp[i - 1][u],dp[i][u - 1]);
            res = max(res,dp[i][u]);
        }
    cout << res << endl;
    return 0;
}
