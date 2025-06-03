#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

int main() {
    int type;
    cin >> type;

    int n, m;
    cin >> n >> m;

    vector<string> nodeNames(n);
    map<string, int> nameToIndex;

    for (int i = 0; i < n; i++) {
        cin >> nodeNames[i];
        nameToIndex[nodeNames[i]] = i;
    }

    vector<vector<int>> graph(n);

    // 构建邻接表（头插法）
    for (int i = 0; i < m; i++) {
        string from, to;
        cin >> from >> to;
        int u = nameToIndex[from];
        int v = nameToIndex[to];

        graph[u].insert(graph[u].begin(), v);  // 头插法
        if (type == 2 || type == 3) {
            graph[v].insert(graph[v].begin(), u); // 无向图也插入反向边
        }

        if (type == 1 || type == 3) {
            int w; cin >> w; // 有权图，读取权值但不使用
        }
    }

    // 广度优先搜索 BFS
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << nodeNames[u] << " ";

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return 0;
}
