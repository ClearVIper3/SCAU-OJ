#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    multiset<int> S;
    for (int i = 0, v; i < n; i++) {
        cin >> v;
        S.insert(v);
    }

    for (int i = 0; i < n; i++) {
        int need = (n - a[i]) % n;
        auto it = S.lower_bound(need);
        if (it == S.end()) 
            it = S.begin();
        a[i] = (a[i] + *it) % n;
        S.erase(it);
    }

    for (int x : a)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
