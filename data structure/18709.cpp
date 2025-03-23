#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[n+1], t[n+1];
    t[0] = 0;  // 初始化t数组的第一个元素为0
    
    // 输入奶牛颜色信息，并计算前缀黑色奶牛的数量
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 2) {
            t[i] = t[i-1] + 1;  // 黑色奶牛数量加1
        } else {
            t[i] = t[i-1];  // 白色奶牛数量不变
        }
    }

    int ans = n;  // 初始化最小值为n，即最坏情况
    for (int i = 0; i <= n; ++i) {
        // 分割点i之前的奶牛变为白色，i之后的奶牛变为黑色
        int cost = t[i] + (n - i - (t[n] - t[i]));
        ans = min(ans, cost);  // 更新最小操作次数
    }
    
    cout << ans << endl;  // 输出最少魔法棒挥舞次数
    return 0;
}
