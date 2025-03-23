#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<long long> sum(n + 1); // 防止爆int
    sum[0] = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum[i + 1] = sum[i] + arr[i];
    }
    int T;
    cin >> T;
    while(T--)
    {
        int left,right;
        cin >> left >> right;

        cout << sum[right] - sum [left - 1] << endl;
    }

    return 0;
}
