#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> path;
vector<vector<int>> res;
void dfs(const vector<int>& arr,vector<bool>& vis)
{
    if(path.size() == arr.size()){
        res.push_back(path);
        return;
    }

    for(int i = 0; i < arr.size(); i++)
    {
        if(vis[i] || arr[i] % 2 == 1 && !path.empty() && path.back() % 2 == 1 || i > 0 && arr[i] == arr[i - 1] && !vis[i - 1])
            continue;

        vis[i] = true;
        path.push_back(arr[i]);
        dfs(arr,vis);
        vis[i] = false;
        path.pop_back();
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
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
