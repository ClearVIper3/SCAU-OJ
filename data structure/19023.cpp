#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int check(int mid,int m,const vector<int>& high)
{
    for(int i = 0; i < high.size(); i++)
        if(mid < high[i])
            m -= (high[i] - mid);

    return m;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    int r = 0;
    cin >> n >> m;
    vector<int> high(n);
    for(int i = 0; i < n; i++)
        cin >> high[i],r = max(r,high[i]);

    int l = 1;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(check(mid,m,high) <= 0)
            l = mid + 1;
        else
            r = mid - 1;

    }
    cout << r << endl;
    return 0;
}
