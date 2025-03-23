#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> arr)
{
    for(int u = 0; u < arr.size(); u++)
    {
        cout << arr[u] << ' ';
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n - 1; i++)
    {
        int bol = 0;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                bol = 1;
                swap(arr[j + 1], arr[j]);
            }
        }
        if(bol) show(arr);
        else
        {
            show(arr);
            break;
        }
    }
    return 0;
}
