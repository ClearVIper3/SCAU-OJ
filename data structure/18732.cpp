//Floyd algorithm
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1,vector<int> (n + 1,10001));
    while(m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        grid[u][v] = w;
        grid[v][u] = w;
    }

    vector<vector<int>> des = grid;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int u = 1; u <= n; u++)
                if(des[j][u] > des[j][i] + des[i][u])
                    des[j][u] = des[j][i] + des[i][u];

    if(des[1][n] != 10001) cout << des[1][n] << endl;
    else cout << -1 << endl;
    return 0;
}
