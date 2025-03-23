#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n);

    for(int i = 0; i < n; i++) 
        if(s[i] == 'E') dp[i] = 1;
        else dp[i] = -1;

    int cur = 0;
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        cur += dp[i];
        res = max(res,cur);
        if(cur < 0) cur = 0;
    }

    cout << res << endl;
    return 0;
}
