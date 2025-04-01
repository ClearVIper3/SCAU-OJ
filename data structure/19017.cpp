#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

static void solve()
{
    string s;
    cin >> s;
    
    vector<int> nums;
    stringstream ss(s);
    string token;
    while (getline(ss, token, ',')) {
        nums.push_back(stoi(token));
    }

    int n = nums.size();
    map<int, vector<int>> mp;
    vector<int> ru(n, 0);

    // 构建邻接表和入度数组
    for (int i = 0; i < n; i++) {
        int a = nums[i];
        if (a != -1) { // -1 表示没有依赖
            mp[a].push_back(i);
            ru[i]++; // i 依赖 a，所以 i 的入度 +1
        }
    }

    // 确保邻接表的顺序
    for (auto &p : mp) {
        sort(p.second.begin(), p.second.end()); // 只在初始化时排序一次
    }

    // 拓扑排序 (使用最小堆保证最小编号先出)
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        if (ru[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        result.push_back(x);
        for (int i : mp[x]) {
            ru[i]--;
            if (ru[i] == 0) {
                pq.push(i);
            }
        }
    }

    // 输出格式调整
    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << ",";
        cout << result[i];
    }
    cout << endl;
}

int main()
{
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
