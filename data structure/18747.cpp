#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<int> time(n + 1);
    time[1] = 0;  // 起点到起点的时间是 0

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v : adj[u]) {
            time[v.first] = max(time[v.first], time[u] + v.second);
            indegree[v.first]--;
            if (indegree[v.first] == 0) {
                q.push(v.first);
            }
        }
    }

    cout << time[n] << endl;

    return 0;
}
