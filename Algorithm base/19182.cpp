#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N+1);
    vector<int> s(N+1);
    vector<vector<int>> dp(N+1,vector<int>(N+1));
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    s[1] = arr[1];
    for(int i = 2; i <= N; i++)
    {
        s[i] = s[i-1] + arr[i];
    }
    for(int len = 2; len <= N; len++)
    {
        for(int i = 1; i + len - 1 <= N; i++)
        {
            int j = i + len - 1;
            dp[i][j] = 1e8;
            for(int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + s[j] - s[i - 1]);
            }
        }
    }
    cout << dp[1][N] << endl;
    return 0;
}
