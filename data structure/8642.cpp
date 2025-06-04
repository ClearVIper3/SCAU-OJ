#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int>& arr,int low,int high)
{
    if(low >= high) return;
    int left = low;
    int right = high;

    int key = arr[low];
    int hole = left;
    while(left != right)
    {
        while(key <= arr[right] && left != right)
            right--;
        arr[hole] = arr[right];
        hole = right;
        while(key >= arr[left] && left != right)
            left++;
        arr[hole] = arr[left];
        hole = left;
    }

    arr[hole] = key;

    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
    Sort(arr,low,hole - 1);
    Sort(arr,hole + 1,high);
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    Sort(arr,0,n - 1);

    return 0;
}
