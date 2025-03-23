//cin cout耗时700ms+
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n; 
    scanf("%d", &n); // 使用 scanf 读取输入
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &arr[i]); // 使用 scanf 读取数组元素
    
    int t;
    scanf("%d", &t); // 读取查询次数
    while(t--)
    {
        int key; 
        scanf("%d", &key); // 读取给定的key
        int l = 1, r = n;
        int res = n + 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(arr[mid] >= key)
            {
                res = mid;
                r = mid - 1; // 向左查找，保持最小符合条件的位置
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n", res); // 使用 printf 输出结果
    }
    return 0;
}
