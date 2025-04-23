#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long getSum(string s)
{
    long long res = 0;
    for(int i = 0; i < s.size(); i++)
        res = res * 10 + s[i] - '0';

    return res;
}
long long res = 77777777;
long long k;
string s = "";
void dfs(const vector<int>& arr,vector<bool>& vis)
{
    if(s.size() == arr.size() && res == 77777777 && getSum(s) % k == 0)
    {
        res = getSum(s);
        return;
    }

    for(int i = 0; i < arr.size() && res == 77777777; i++)
    {
        if(vis[i] || (s.size() == 0 && arr[i] == 0)) continue;
        vis[i] = true;
        s += '0' + arr[i];
        dfs(arr,vis);
        s.pop_back();
        vis[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n >> k;
    vector<int> arr(n);
    vector<bool> vis(n,false);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(n == 1 && arr[0] == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(arr.begin(),arr.end());
    dfs(arr,vis);
    if(res == 77777777)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}
