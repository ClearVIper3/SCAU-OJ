#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

static void solve()
{
    int n; cin >> n;
    map<int,vector<int>> mp;
    vector<int> ru(n + 1);
    for(int i = 1; i <= n; i++)
        for(int u = 1; u <= n; u++)
        {
            int op;
            cin >> op;
            if(op){
                mp[u].push_back(i);
                ru[i]++;
            }
        }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(ru[i] == 0)
            q.push(i);
    int res = 0;
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        res++;
        for(auto i : mp[x])
        {
            ru[i]--;
            if(ru[i] == 0)
                q.push(i);
        }
    }
    if(res == n) cout << 0 << endl;
    else cout << 1 << endl;
}



int main()
{
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
