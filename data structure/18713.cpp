#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > res;
vector<int> path;
void dfs(int n,int pre)
{
    if(n == 0)
    {
        res.push_back(path);
        return;
    }
    for(int i = n; i >= 1; i--)
    {
        if(i > pre)
            continue;
        path.push_back(i);
        dfs(n - i,i);
        path.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    dfs(n,n);
    for(int i = 0; i < res.size(); i++)
    {
        cout << n << "=";
        for(int j = 0; j < res[i].size() - 1; j++)
            cout << res[i][j] << "+";
        cout << res[i][res[i].size() - 1] << endl;
    }
    return 0;
}
