#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    set<int> vis;
    for(int i = 0; i < n; i++) vis.insert(i);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    vector<int> ans(n);
    int res = 0;
    for(int i = 0; i < n; i++)
        if(vis.count(arr[i] % n))
            res++,ans[arr[i] % n] = arr[i],vis.erase(arr[i] % n);
        else{
            int idx = arr[i] % n;
            set<int>::iterator it = vis.lower_bound(idx);
            if(it == vis.end()) it = vis.begin();
            ans[*it] = arr[i];
            vis.erase(*it);
        }
    printf("%d\n", res);
    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
