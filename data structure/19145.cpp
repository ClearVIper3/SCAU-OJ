#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    int n;cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    int res = 0;
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        while(mp[arr[i]] != 0)
        {
            mp[arr[idx]]--;
            idx++;
        }
        mp[arr[i]]++;
        res = max(res,i - idx + 1);
    }
    cout << res << endl;

    return 0;    
}
