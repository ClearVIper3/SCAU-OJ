#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> arr,int idx,int sum)
{
    if(idx == arr.size()) return;
    cout << sum + arr[idx] << endl;
    dfs(arr,idx + 1, sum + arr[idx]);
    dfs(arr,idx + 1, sum);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    dfs(arr,0,0);
    return 0;
}
