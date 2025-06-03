#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<string> nodeNames;

void dfs(int u) {
    cout << nodeNames[u] << " ";
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int type;
    cin >> type;

    int n, m;
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n, false);

    nodeNames.resize(n);
    map<string, int> nameToIndex;

    // 读取顶点名称
    for (int i = 0; i < n; i++) {
        cin >> nodeNames[i];
        nameToIndex[nodeNames[i]] = i;
    }

    // 构建邻接表（头插法）
    for (int i = 0; i < m; i++) {
        string from, to;
        cin >> from >> to;
        int u = nameToIndex[from];
        int v = nameToIndex[to];

        // 头插法：后插入的边排在前面
        graph[u].insert(graph[u].begin(), v);

        if (type == 2 || type == 3) {
            graph[v].insert(graph[v].begin(), u);
        }

        if (type == 1 || type == 3) {
            int w; cin >> w; // 网有权值，跳过即可
        }
    }

    dfs(0); // 从输入的第一个点开始 DFS
    return 0;
}
