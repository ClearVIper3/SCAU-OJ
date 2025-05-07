#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

static bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int> > arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end(), cmp);

    priority_queue<int,vector<int>,greater<int> > pq;

    long long res = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        int vol = arr[i].second;
        int val = arr[i].first;
        pq.push(val);
        sum += val;
        while(pq.size() > vol)
            sum -= pq.top(),pq.pop();
        
        res = max(res, sum);
    }
    cout << res << endl;
    return 0;
}
