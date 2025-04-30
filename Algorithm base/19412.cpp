#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> path;
vector<vector<int>> res;
void dfs(const vector<int>& arr,vector<bool>& vis)
{
    if(path.size() == arr.size())
    {
        res.push_back(path);
        return;
    }

    for(int i = 0; i < arr.size(); i++)
    {
        if(vis[i])
            continue;
        path.push_back(arr[i]);
        vis[i] = true;
        dfs(arr,vis);
        path.pop_back();
        vis[i] = false;
    }
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    vector<bool> vis(n,false);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(),arr.end());

    dfs(arr,vis);

    for(int i = 0; i < res.size(); i++)
    {
        for(int u = 0; u < res[i].size(); u++)
            cout << res[i][u] << ' ';
        cout << endl;
    }
    return 0;
}
