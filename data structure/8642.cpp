#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int>& arr,int low,int high)
{
    if(low >= high) return;
    int i = low;
    int j = high;

    int key = arr[low];
    int tmp;
    while(i != j)
    {
        while(key <= arr[j] && i != j)
            j--;
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
        while(key >= arr[i] && i != j)
            i++;
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    arr[i] = tmp;

    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
    Sort(arr,low,i - 1);
    Sort(arr,i + 1,high);
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    Sort(arr,0,n - 1);

    return 0;
}
