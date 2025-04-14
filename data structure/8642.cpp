#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int>& arr,int low,int high)
{
    if(low >= high) return;
    int i = low;
    int j = high;

    int key = arr[low];
    int hole = i;
    while(i != j)
    {
        while(key <= arr[j] && i != j)
            j--;
        arr[hole] = arr[j];
        hole = j;
        while(key >= arr[i] && i != j)
            i++;
        arr[hole] = arr[i];
        hole = i;
    }

    arr[hole] = key;

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
