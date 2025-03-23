#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> path;
vector<vector<int> > res;
void dfs(int n,int idx,vector<int> used)
{
    if(path.size() == n)
    {
        res.push_back(path);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(used[i] != 0) continue; 
        path.push_back(i);
        used[i] = 1;
        dfs(n,i+1,used);
        path.pop_back();
        used[i] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> used(n+1);
    dfs(n,1,used);
    
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
