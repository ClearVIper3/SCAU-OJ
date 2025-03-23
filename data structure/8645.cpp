#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,vector<int>& harr,int st,int mid,int en)
{
    int i = st,j = mid + 1, k =st;
    while(i <= mid && j <= en)
    {
        if(arr[i] > arr[j])
            harr[k++] = arr[j++];
        else
            harr[k++] = arr[i++];
    }
    while(i != mid + 1) harr[k++] = arr[i++];
    while(j != en + 1) harr[k++] = arr[j++];
    for(int i = st;i <= en; i++)
        arr[i] = harr[i];
}

void mergesortIterative(vector<int>& arr)
{
    int n = arr.size();
    vector<int> temp(n); // 临时数组

    // 从长度为 1 的子数组开始，逐步增加子数组的长度
    for (int len = 1; len < n; len *= 2)
    {
        // 遍历数组，合并相邻的子数组
        for (int st = 0; st < n; st += 2 * len)
        {
            int mid = min(st + len - 1, n - 1); // 计算中间点
            int en = min(st + 2 * len - 1, n - 1); // 计算结束点

            // 合并 arr[st..mid] 和 arr[mid+1..en]
            merge(arr, temp, st, mid, en);
        }

        // 输出每次合并后的数组状态（调试用）
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    mergesortIterative(arr);
    return 0;
}
