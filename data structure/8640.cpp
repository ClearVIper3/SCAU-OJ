#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr)
{
    int n = arr.size();
    int gap = n;
    while(gap > 1)
    {
        gap /= 2;
        for(int i = 0; i < n - gap; i++)
        {
            int end = i;
            int tmp = arr[end + gap];
            while(end >= 0)
            {
                if(arr[end] > tmp)
                {
                    arr[end + gap] = arr[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            arr[end + gap] = tmp;
        }
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    shellSort(arr);
    return 0;
}
