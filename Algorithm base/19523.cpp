#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    int n;
    while(cin >> n && n != 0)
    {
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        vector<int> dp(n + 1, 1);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(arr[i - 1] > arr[j - 1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;
        for(int i = 0; i <= n; i++)
            res = max(res, dp[i]);
        cout << res << endl;
    }
    return 0;
}
