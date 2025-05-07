#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using Node = pair<ll, pii>;  // first = sum, second = {i, j}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // 小根堆，按 pair.first（sum）升序
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    // 初始状态：所有 A[i] + B[0]
    for(int i = 0; i < N; i++){
        pq.push({A[i] + B[0], {i, 0}});
    }

    vector<ll> ans;
    ans.reserve(N);
    for(int k = 0; k < N; k++){
        auto top = pq.top(); pq.pop();
        ll sum = top.first;
        int i = top.second.first;
        int j = top.second.second;
        ans.push_back(sum);
        /*
        是当前最小和 (i, j) 的“下一个最小候选”；

        它保证了最小扩展；
        
        堆自动维护全局最小，最终得到前 N 个组合。
        */
        // 推入 A[i] + B[j+1]
        if(j + 1 < N){
            pq.push({A[i] + B[j+1], {i, j+1}});
        }
    }

    // 输出
    for(int i = 0; i < N; i++){
        cout << ans[i] << (i+1 == N ? '\n' : ' ');
    }
    return 0;
}
