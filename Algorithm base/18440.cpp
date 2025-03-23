#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void bfs(vector<vector<int> >& grid,int x,int y,int enx,int eny)
{
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(x,y),0));
    while(!q.empty())
    {
        pair<pair<int,int>,int> ff = q.front();
        pair<int,int> p = ff.first;
        int step = ff.second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = p.first + dir[i][0];
            int ny = p.second + dir[i][1];
            if(nx < 0)
                nx = grid.size() - 1;
            if(nx >= grid.size())
                nx = 0;
            if(ny < 0)
                ny = grid[0].size() - 1;
            if(ny >= grid[0].size())    
                ny = 0;
            if(nx == enx && ny == eny)
            {
                cout << step + 1 << endl;
                return;
            }
            if(grid[nx][ny] == 0)
            {
                grid[nx][ny] = 1;
                q.push(make_pair(make_pair(nx,ny),step + 1));
            }
        }
    }
    cout << "die" << endl;
    return;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,m;
        cin >> n >> m;
        vector<string> s(n);
        for(int i=0;i<n;i++)
                cin >> s[i];

        vector<vector<int> > grid(n,vector<int>(m,0));

        for(int i = 0; i < n; i++)
            for(int u = 0; u < m; u++)
                grid[i][u] = s[i][u] - '0';

        int stx,sty,enx,eny;
        cin >> stx >> sty >> enx >> eny;
        if(grid[stx][sty] == 1 || grid[enx][eny] == 1)
        {
            cout << "die" << endl;
            continue;
        }
        if(stx == enx && sty == eny)
        {
            cout << 0 << endl;
            continue;
        }
        bfs(grid,stx,sty,enx,eny);
    }
    return 0;
}
