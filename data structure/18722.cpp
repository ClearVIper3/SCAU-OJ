#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(k,vector<int> (3));
    for(int i = 0; i < k; i++)
        cin >> grid[i][0] >> grid[i][1] >> grid[i][2];

    vector<int> position(m,0);
    for(int i = 0; i < k; i++)
        position[grid[i][1]]++;

    for(int i = 1; i < m; i++)
        position[i] += position[i - 1];
    for (int i = m - 1; i > 0; i--)
        position[i] = position[i - 1];
    position[0] = 0;


    vector<vector<int>> res(k,vector<int> (3));

    for(int i = 0; i < k; i++)
    {
        int idx = position[grid[i][1]]++;
        res[idx][2] = grid[i][2];
        res[idx][0] = grid[i][1];
        res[idx][1] = grid[i][0];
    }

    for(int i = 0; i < k; i++)
        cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << endl;

    return 0;
}
