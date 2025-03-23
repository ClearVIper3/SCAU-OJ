#include <iostream>
#include <algorithm>
using namespace std;
 
// 计算最小公倍数
long long lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}
 
int main() {
    int n;
    cin >> n;
 
    // 处理第1批测试数据
    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
    cout << "group 1 done" << endl;
 
    // 处理第2批测试数据
    while (true) {
        long long a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        cout << lcm(a, b) << endl;
    }
    cout << "group 2 done" << endl;
 
    // 处理第3批测试数据
    while (true) {
        long long a, b;
        if (!(cin >> a >> b)) break;
        cout << lcm(a, b) << endl;
    }
    cout << "group 3 done" << endl;
 
    return 0;
}
