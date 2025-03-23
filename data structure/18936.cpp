#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,m,c;
	cin >> n >> m >> c;
	vector<vector<int>> arr(n,vector<int>(c + 1,0));
	for(int u = 0; u < n; u++)
	{
		int sz;
		cin >> sz;
		for(int i = 0; i < sz; i++)
		{
			int v;
			cin >> v;
			arr[u][v] = 1;
		}
	}
	int res = 0;
	vector<bool> vis(c + 1,false);
	for(int i = 0; i < n; i++)
	{
		int a[c + 1] = {0};
		for(int j = 0; j < m; j++)
			for(int k = 1; k <= c; k++)
			{
				if(arr[(i + j) % n][k] == 1) a[k]++;
				if(a[k] > 1 && !vis[k])
				{
					vis[k] = true;
					res++;
				}
			}
	}
	cout << res << endl;
	return 0;
}
