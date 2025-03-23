#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for(int u = 0; u < arr[i].size(); u++)
        {
            if(u >= 2 && arr[i][u] == arr[i][u - 1] && arr[i][u - 1] == arr[i][u - 2])
            {
                arr[i].erase(u,1);
                u -= 2;
            }
            if(u > 2 && arr[i][u] == arr[i][u - 1] && arr[i][u - 2] == arr[i][u - 3] && arr[i][u - 1] != arr[i][u - 2])
            {
                arr[i].erase(u,1);
                u -= 3;
            }
        }
    }
    for(int i = 0; i < n; i++) cout << arr[i] << endl;
    return 0;
}
