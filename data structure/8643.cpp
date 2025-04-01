#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MySort(vector<int>& arr){
    for(int i = 0; i < arr.size() - 1; i++)
    {
        int idx = i;
        //int bol = 0;
        int cmin = arr[i];
        for(int u = i + 1; u < arr.size(); u++)
        {
            if(cmin > arr[u])
            {
                idx = u;
                cmin = arr[u];
                //bol = 1;
            }
        }
        //if(!bol) return;
        swap(arr[idx],arr[i]);
        for(int j = 0; j < arr.size(); j++) cout << arr[j] << ' ';
        cout << endl;
    }
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    MySort(arr);

    return 0;
}
