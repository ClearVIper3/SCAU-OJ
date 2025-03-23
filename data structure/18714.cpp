#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
bool res = false;
void dfs(vector<vector<int> >& grid,int x,int y)
{
    if(x == grid.size() - 1 && y == grid[0].size() - 1)
    {
        res = true;
        return;
    }
    grid[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0)
            dfs(grid,nx,ny);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int> > grid(n, vector<int>(m));  

    for(int i = 0; i < n; i++)
        for(int u = 0; u < m; u++)
            grid[i][u] = a[i][u] - '0';

    dfs(grid,0,0);

    if(res) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}
