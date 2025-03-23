#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 1; i < n; i++)
    {
        int key = arr[i];

        int low = 0;
        int high = i - 1;
        int mid = low + (high - low) / 2;;

        while(low <= high)
        {
            if(arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            mid = low + (high - low) / 2;
        }
        for(int j = i - 1; j >= mid; j--) arr[j + 1] = arr[j];
        arr[mid] = key;

        show(arr);
    }
    return 0;
}
