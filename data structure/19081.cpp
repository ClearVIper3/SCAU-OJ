#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct trr{
    int val = 777;
    int left = 777,right = 777;
}node;

int res = 0;
void dfs(vector<node>& nod,vector<int>& child_sum,int now)
{
    if(now == 777)
        return;

    dfs(nod,child_sum,nod[now].left);
    dfs(nod,child_sum,nod[now].right);

    if(nod[now].left != 777)
        child_sum[now]++;
    if(nod[now].right != 777)
        child_sum[now]++;

    if(child_sum[now] == 2 && child_sum[nod[now].left] == 0 && child_sum[nod[now].right] == 0)
        res++;
}

int main()
{
    int m,n;
    cin >> m >> n;

    vector<node> nod(m + 1);

    for(int i = 1; i <= m; i++)
        nod[i].val = i;

    for(int i = 0; i < n; i++)
    {
        int id1,id2;
        string turn;
        cin >> id1 >> turn >> id2;

        if(turn == "left")
            nod[id1].left = id2;
        else
            nod[id1].right = id2;
    }

    vector<int> child_sum(m + 1);

    dfs(nod,child_sum,1);

    cout << res << endl;

    return 0;
}
