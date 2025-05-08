#include <iostream>
#include <algorithm>
#include <cstring>

typedef long long ll;
using namespace std;

const ll INF = 1e18;

ll n, a[305];
ll dp[305][305][305]; // dp[l][r][root] 表示区间 [l..r] 作为某棵子树，且它的父节点为 root 时的最小代价

ll dfs(int l, int r, int root)
{
    if (l > r)
        return 0;
    if (dp[l][r][root] < INF)
        return dp[l][r][root];

    ll ans = INF;
    for (int i = l; i <= r; i++)
    {
        ll left = dfs(l, i - 1, i);
        ll right = dfs(i + 1, r, i);
        ans = min(ans, left + right + a[i] * a[root]);
    }
    return dp[l][r][root] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 初始化 dp 数组为 INF
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                dp[i][j][k] = INF;

    cout << dfs(1, n, 0) << "\n";
    return 0;
}
