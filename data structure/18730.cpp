#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

// 快速幂函数：计算 (base^exp) % MOD
ll power(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = result * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    ll n, m;
    cin >> n >> m;

    ll total = power(m, n);

    if (m == 1) {
        // m - 1 = 0，只有全相同方案才存在，全部发疯
        cout << total << endl;
        return 0;
    }

    ll good = m * power(m - 1, n - 1) % MOD;
    ll bad = (total - good + MOD) % MOD;  // 避免负数
    cout << bad << endl;

    return 0;
}

/*
1 1 1
1 1 2
2 1 1
2 2 1
2 2 2
1 2 2

*/
