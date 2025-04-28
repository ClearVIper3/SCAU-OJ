#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int mid,int k, const vector<int>& len)
{
    int go = 0;
    int idx = 0;
    for(int i = 0; i < k; i++)
    {
        go += mid;
        while(idx < len.size() && go >= len[idx])
            idx++;
        go = len[idx - 1];
    }
    if(idx >= len.size())
        return true;
    return false;
}

int main()
{
    int n,k;
    cin >> n >> k;

    vector<int> len(n);
    for(int i = 0; i < n; i++)
        cin >> len[i];
    
    int l = 1, r = len[n - 1];
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(!check(mid, k, len))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
