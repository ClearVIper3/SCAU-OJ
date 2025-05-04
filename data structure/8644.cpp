#include <iostream>
#include <vector>

using namespace std;

void show(const vector<int>& arr){
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void heap(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heap(arr, n, largest);
    }
}

void Sort(vector<int>& arr,int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);
    
    for(int i = n - 1; i >= 0; i--){
        show(arr);
        swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Sort(arr, n);

    return 0;
}
