#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool bfs(vector<vector<int> > grid,int x,int y)
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
			if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
				return false;
			if(grid[nx][ny] == 0)
			{
				q.push(make_pair(nx,ny));
				grid[nx][ny] = 2;
			}
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int> > grid(n, vector<int> (n,0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> grid[i][j];
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(grid[i][j] == 0 && bfs(grid,i,j))
				grid[i][j] = 2;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
	return 0;
}
