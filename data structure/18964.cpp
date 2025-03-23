#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main()
{
    int n; cin >> n;
    vector<vector<int> > a(n, vector<int>(n,-1));

    int x = 0, y = 0;
    int d = 0;
    for(int i = 1; i <= n * n; i++)
    {
        a[x][y] = i;
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != -1)
        {
            d = (d + 1) % 4;
            nx = x + dir[d][0];
            ny = y + dir[d][1];
        }
        x = nx;
        y = ny;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        cout << endl;
    }
}
