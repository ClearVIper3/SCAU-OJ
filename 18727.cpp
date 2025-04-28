#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    int n,c;
    cin >> n >> c;
    vector<int> arr(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++)
        cin >> arr[i],mp[arr[i]]++;;

    int res = 0;
    for(int i = 0; i < n; i++)
        res += mp[abs(arr[i] + c)];

    cout << res << endl;
    return 0;    
}
