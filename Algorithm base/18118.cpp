#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    ios_base::sync_with_stdio(false); // 关闭与C标准库的同步，加速输入
    cin.tie(nullptr); // 解除cin与cout的绑定，进一步加速
    while(cin >> n >> m && n != 0 && m != 0)
    {
        vector<int> hr(n);
        for(int i = 0; i < n; i++) cin >> hr[i];
        vector<int> pw(m);
        for(int i = 0; i < m; i++) cin >> pw[i];
        sort(pw.begin(),pw.end());
        sort(hr.begin(),hr.end());
        int idx = 0;
        int i = 0;
        int res = 0;
        while(idx < n && i < m)
        {
            while(i < m && hr[idx] > pw[i])
                i++;
            if(i >= m) break;
            res += pw[i];
            idx++;
            i++;
        }
        if(idx != n) cout << "Loowater is doomed!" << endl;
        else cout << res << endl;
    }
    return 0;
}
