#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > grid(n + 1); // 存储课程依赖关系的邻接表
    vector<int> r(n + 1, 0); // 存储课程的入度

    // 读入课程关系
    while (m--) {
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b); // 课程b依赖课程a
        r[b]++; // b的入度加1
    }

    // 使用优先队列来保证优先选择编号小的课程
    priority_queue<int, vector<int>, greater<int> > q;
    
    // 将所有入度为0的课程加入队列
    for (int i = 1; i <= n; i++) {
        if (r[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;

    while (!q.empty()) {
        int cur = q.top(); // 获取当前可以学习的课程
        q.pop();
        result.push_back(cur);

        // 对所有依赖当前课程的课程，入度减1
        for (int i = 0; i < grid[cur].size(); i++) {
            int next = grid[cur][i];
            r[next]--;
            if (r[next] == 0) {
                q.push(next); // 如果入度为0，加入队列
            }
        }
    }

    // 如果结果中课程数量不等于n，说明存在环，无法排序
    if (result.size() != n) {
        cout << "There exists a cycle." << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
