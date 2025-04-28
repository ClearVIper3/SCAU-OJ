#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int check(int mid,int m,int n)
{
    for(int i = 0; i < n; i++){
        m -= mid;
        mid = (mid + 1) / 2;
    }
    return m;
}

int main()
{
    int n,m;
    cin >> n >> m;

    int l = 1;
    int r = m;
    int mid;
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(check(mid,m,n) >= 0)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << r << endl;
    return 0;
}
