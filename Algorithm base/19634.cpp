#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int m; cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a; cin >> a;
        auto it = lower_bound(arr.begin(),arr.end(),a);
        //cout << *(it - 1) << endl;
        int idx = it - arr.begin();
        arr.insert(arr.begin() + idx,a);
        int len = arr.size();
        if(len % 2)
            cout << arr[len / 2] << endl;
        else
            cout << (arr[len / 2 - 1] + arr[len / 2]) / 2.0 << endl;
    }
    return 0;
}
