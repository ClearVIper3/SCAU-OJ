#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> path;
vector<vector<int> > res;
void dfs(int m,int k,int idx)
{
    if(path.size() == k)
    {
        res.push_back(path);
        return;
    }
    for(int i = idx; i <= m; i++)
    {
        path.push_back(i);
        dfs(m,k,i+1);
        path.pop_back();
    }
}

int main()
{
    int m,k;
    cin >> m >> k;

    dfs(m,k,1);
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
