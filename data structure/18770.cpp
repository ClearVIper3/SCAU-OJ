#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> cpy(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        cpy[i] = arr[i];
    }
    sort(cpy.begin(),cpy.end());

    int idx = N - 1;
    int res = -99;

    for(int i = 0; i < N; i++)
    {
        if(arr[i] == cpy[idx]) idx--;
        else
        {
            res = max(res,cpy[idx] - arr[i]);
        }
    }

    cout << res;
    return 0;
}
