#include <iostream>
using namespace std;

const int MAX_N = 20;
int n;
int ring[MAX_N];  // 存储当前排列
bool used[MAX_N + 1];  // 标记数字是否已使用

// 判断是否是素数
bool is_prime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

// 回溯搜索素数环
bool dfs(int idx) {
    if (idx == n) {  // 终止条件
        if (is_prime(ring[n - 1] + ring[0])) {  // 首尾也要是素数
            return true;
        }
        return false;
    }

    for (int i = 2; i <= n; i++) {  // 1 已固定，从 2 开始
        if (!used[i] && is_prime(ring[idx - 1] + i)) {
            used[i] = true;
            ring[idx] = i;
            if (dfs(idx + 1)) return true;
            used[i] = false;  // 回溯
        }
    }
    return false;
}

int main() {
    cin >> n;
    if (n % 2 == 1) {  // 只有偶数 n 才可能构成素数环（n=2 除外）
        cout << -1 << endl;
        return 0;
    }

    ring[0] = 1;  // 题目要求 1 在开头
    used[1] = true;

    if (dfs(1)) {
        for (int i = 0; i < n; i++) {
            cout << ring[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
