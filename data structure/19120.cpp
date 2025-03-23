#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

void bfs(vector<string>& grid,int x,int y)
{
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        if(grid[p.first][p.second] == '!')
            continue;
        for(int i = 0; i < 8; i++)
        {
            int nx = p.first + dir[i][0];
            int ny = p.second + dir[i][1];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size())
            {
                if(grid[nx][ny] == '*')
                {
                    grid[nx][ny] = '!';
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}
int main()
{
    int n,m,x;
    cin >> n >> m >> x;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    
    while(x--)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == '@')
                    bfs(grid,i,j);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == '!')
                    grid[i][j] = '@';
    }

    int res = 0;
    for(int i = 0; i < n; i++)
        for(int u = 0; u < m; u++)
            if(grid[i][u] == '@')
                res++;
    cout << res << endl;
    return 0;
}
