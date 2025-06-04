#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr)
{
    int n = arr.size();
    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            int key = arr[i];
            int j = i - gap;
            while(j >= 0 && arr[j] > key){
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = key;
        }
        for(int u = 0; u < n; u++)
            cout << arr[u] << ' ';
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
