#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        int i = 0;
        int j = n - 1;
        while(i < j)
        {
            while(arr[i] < 0 && i < j) i++;
            while(arr[j] > 0 && i < j) j--;
            swap(arr[i],arr[j]);
        }
        for(int i = 0; i < n; i++) cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}
