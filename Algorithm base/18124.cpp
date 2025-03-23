#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isv(const vector<string>& grid,int x,int y)
{
    for(int i = x - 1; i >= 0; i--)
        if(grid[i][y] == '1')
            return false;
    for(int i = y - 1; i >= 0; i--)
        if(grid[x][i] == '1')
            return false;

    for(int i = x - 1,u = y - 1; i >= 0 && u >= 0; i--,u--)
        if(grid[i][u] == '1')
            return false;
    for(int i = x - 1,u = y + 1; i >= 0 && u < grid[0].size(); i-- ,u++)
        if(grid[i][u] == '1')
            return false;
    return true;
}

void dfs(vector<string>& grid,int h,int n,int& res)
{
    if(h == n)
    {
        res++;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(isv(grid,h,i))
        {
            grid[h][i] = '1';
            dfs(grid,h + 1,n,res);
            grid[h][i] = '0';
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int res = 0;
        vector<string> grid(n, string(n, '0'));
        dfs(grid,0,n,res);
        cout << res << endl;
    }
    return 0;
}
