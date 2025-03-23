#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin >> m >> n;
    vector<vector<int>> sq(m,vector<int>(n));
    for(int i = 0 ; i < m; i++)
        for(int j = 0; j < n; j++) cin >> sq[i][j];
    vector<vector<int>> sum (m + 1,vector<int> (n + 1));
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            sum[i][j] = sq[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    int len = min(n,m);
    int res = 0;
    for(int i = 1; i <= len ; i++)
    {
        for(int j = 1; j + i - 1 <= m; j++)
        {
            for(int u = 1 ; u + i - 1 <= n; u++)
            {
                int cur = sum[j + i - 1][u + i - 1] - sum[j - 1][u + i - 1] - sum[j + i - 1][u - 1] + sum[j - 1][u - 1];
                if(cur == i * i) res = max(res,i);
            }
        }
    }
    cout << res;
    return 0;
}
