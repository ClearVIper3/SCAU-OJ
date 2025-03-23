#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void dfs(int a,int b, int r,const vector<int>& arr,int idx,int& res)
{
    if(idx == arr.size())
    {
        if(a == b)
            res = min(res, r);
        return;
    }
    dfs(a + arr[idx], b, r, arr, idx + 1,res);
    dfs(a, b + arr[idx], r, arr, idx + 1,res);
    dfs(a, b, r + arr[idx], arr, idx + 1,res);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            res += arr[i];
        }
        dfs(0, 0, 0, arr, 0,res);
        cout << res << endl;
    }
    return 0;
}
