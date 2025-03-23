#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Edge
{
    int begin, end, val;
}Edge;

int n = 10001;
vector<int> father(n + 1,0);

void init()
{
    for(int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
}

int find(int x)
{
    if(father[x] == x) return x;
    else return father[x] = find(father[x]);
}

void join(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    father[x] = y;
}

static bool cmp(Edge a, Edge b)
{
    return a.val < b.val;
}

int main()
{
    int v,e;
    cin >> v >> e;
    vector<Edge> edges(e);
    while(e--)
    {
        cin >> edges[e].begin >> edges[e].end >> edges[e].val;
    }

    sort(edges.begin(),edges.end(),cmp);
    init();

    int res = 0;
    
    for(int i = 0; i < edges.size(); i++)
    {
        int x = edges[i].begin;
        int y = edges[i].end;
        if(find(x) != find(y))
        {
            res += edges[i].val;
            join(x,y);
        }
    }

    cout << res << endl;

    return 0;
}
