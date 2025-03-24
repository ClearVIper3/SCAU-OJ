#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool bol = false;

void dfs(vector<vector<int>> a,int now,int l,int m,int s,int idx,int nm)
{
    if(nm < 0 || s < 0) return;
    if(now == l)
    {
        bol = true;
        return;
    }

    for(int i = idx; i < a.size(); i++)
        if(a[i][0] >= now && a[i][0] - now <= nm)
            dfs(a,now + a[i][0],l,m,s - a[i][1],i + 1,m);

    if (min(nm, l - now) > 0)
        dfs(a, now + min(nm, l - now), l, m, s, idx, 0);
}

int main()
{
    int n,l,m,s;
    cin >> n >> l >> m >> s;
    vector<vector<int>> a(n,vector<int> (2));
    for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    dfs(a,0,l,m,s,0,m);
    if(bol) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
