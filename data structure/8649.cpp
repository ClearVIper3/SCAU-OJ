#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

enum GraphKind { DG, DN, UDG, UDN }; // 有向图, 有向网, 无向图, 无向网

struct ArcNode {
    int adjvex; // 该弧所指向的顶点的位置
    int weight; // 网的权值
    ArcNode* nextarc; // 指向下一条弧的指针
    ArcNode(int a, int w) : adjvex(a), weight(w), nextarc(nullptr) {}
};

struct VNode {
    string data; // 顶点信息
    ArcNode* firstarc; // 指向第一条依附该顶点的弧的指针
    VNode() : firstarc(nullptr) {}
};

class ALGraph {
private:
    vector<VNode> vertices;
    int vexnum, arcnum;
    GraphKind kind;
    map<string, int> vertexIndex; // 顶点名称到索引的映射

public:
    ALGraph() : vexnum(0), arcnum(0), kind(DG) {}

    void CreateGraph() {
        int k;
        cin >> k;
        kind = static_cast<GraphKind>(k);

        cin >> vexnum >> arcnum;
        vertices.resize(vexnum);

        for (int i = 0; i < vexnum; ++i) {
            cin >> vertices[i].data;
            vertexIndex[vertices[i].data] = i;
        }

        string v1, v2;
        int weight;
        for (int k = 0; k < arcnum; ++k) {
            if (kind == DN || kind == UDN) {
                cin >> v1 >> v2 >> weight;
            } else {
                cin >> v1 >> v2;
                weight = 0; // 无权图，权值设为0或不使用
            }

            int i = vertexIndex[v1];
            int j = vertexIndex[v2];

            // 头插法插入边<i, j>
            ArcNode* arc = new ArcNode(j, weight);
            arc->nextarc = vertices[i].firstarc;
            vertices[i].firstarc = arc;

            // 如果是无向图或网，还需插入边<j, i>
            if (kind == UDG || kind == UDN) {
                ArcNode* arc2 = new ArcNode(i, weight);
                arc2->nextarc = vertices[j].firstarc;
                vertices[j].firstarc = arc2;
            }
        }
    }

    void BFSUtil(int v, vector<bool>& visited) {
        queue<int> q;
        q.push(v);
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            visited[p] = true;
            cout << vertices[p].data << " ";
            ArcNode* ptr = vertices[p].firstarc;
            while(ptr){
                int w = ptr -> adjvex;
                if(!visited[w])
                    q.push(w),visited[w] = true;
                ptr = ptr -> nextarc;
            }
        }
    }

    void BFSTraverse() {
        vector<bool> visited(vexnum, false);
        for (int i = 0; i < vexnum; ++i) {
            if (!visited[i]) {
                BFSUtil(i, visited);
            }
        }
    }

    ~ALGraph() {
        for (int i = 0; i < vexnum; ++i) {
            ArcNode* p = vertices[i].firstarc;
            while (p != nullptr) {
                ArcNode* temp = p;
                p = p->nextarc;
                delete temp;
            }
        }
    }
};

int main() {
    ALGraph G;
    G.CreateGraph();
    G.BFSTraverse();
    return 0;
}
