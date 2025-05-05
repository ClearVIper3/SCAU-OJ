#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void show(const vector<string>& arr){
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void miniSort(vector<string>& arr,int i){
    vector<int> bucket(10,0);
    vector<string> tmp(arr.size());
    for(int j = 0; j < arr.size(); j++)
        bucket[stoi(arr[j]) / i % 10]++;
    
    for(int j = 1; j < 10; j++)
        bucket[j] += bucket[j - 1];
    
    for(int j = arr.size() - 1; j >= 0; j--)
        tmp[--bucket[stoi(arr[j]) / i % 10]] = arr[j];
    
    for(int j = 0; j < arr.size(); j++)
        arr[j] = tmp[j];
    show(arr);
}

void Sort(vector<string>& arr,int maxx){
    for(int i = 1; maxx / i > 0; i *= 10)
        miniSort(arr,i);
}

int main()
{
    int n;
    cin >> n;
    int cmax = 0;
    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        cmax = max(cmax,stoi(arr[i]));
    }

    Sort(arr,cmax);

    return 0;
}
