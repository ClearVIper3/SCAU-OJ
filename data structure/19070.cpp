#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void draw(int n,vector<vector<char>>& mp,int x,int y)
{
	if (n == 1) {
		mp[x][y] = 'X';
		return;
	}

	int d = pow(3, n - 2);

	draw(n - 1, mp, x, y);
	draw(n - 1, mp, x, y + 2 * d);
	draw(n - 1, mp, x + d, y + d);
	draw(n - 1, mp, x + 2 * d, y);
	draw(n - 1, mp, x + 2 * d, y + 2 * d);
}

int main()
{
    int n; cin >> n;
    int D = pow(3,n - 1);
    vector<vector<char>> mp(D + 1, vector<char>(D + 1,' '));

    draw(n,mp,0,0);
    for(int i = 0; i <= D; i++)
    {
        for(int u = 0; u <= D; u++)
            cout << mp[i][u];
        cout << endl;
    }
    return 0;
}
