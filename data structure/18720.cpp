#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool bol = false;
void bfs(vector<vector<int> >& grid,int x,int y,vector<vector<int> >& dp)
{
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		pair<int,int> p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = p.first + dir[i][0];
			int ny = p.second + dir[i][1];
			if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 1)
				continue;

			if(nx == grid.size() - 1 && ny == grid[0].size() - 1) 
			{
				dp[nx][ny] = dp[p.first][p.second] + 1;
				bol = true;
				return;
			}

			if(grid[nx][ny] == 0)
			{
				q.push(make_pair(nx,ny));
				dp[nx][ny] = dp[p.first][p.second] + 1;
				grid[nx][ny] = 1;
			}
		}
	}
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<string> gd(n);
	vector<vector<int> > grid(n,vector<int>(m,0));
	for(int i = 0; i < n; i++)
		cin >> gd[i];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			grid[i][j] = gd[i][j] - '0';

	vector<vector<int> > dp(n,vector<int>(m,0));

	bfs(grid,0,0,dp);

	if(bol)
	{
		cout << dp[n - 1][m - 1] << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}
