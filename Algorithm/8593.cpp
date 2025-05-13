#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int res = 0;
    int l = n - 1,r = n - 1;
    while(l >= 0)
    {
        while(l >= 0 && arr[l] <= abs(arr[r]))
            l--;
        //cout << l << ' ' << r << endl;
        r--;
        res = max(res,r - l + 1);
    }
    cout << res << endl;
    return 0;
}
