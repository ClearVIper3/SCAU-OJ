#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,val;
    cin >> n;

    set<set<int>> sst;

    while(n--)
    {
        set<int> st;
        for(int i = 0; i < 6; i++)
            cin >> val,st.insert(val);

        if(sst.count(st)){
            cout << "Twin snowflakes found.";
            return 0;
        }
        sst.insert(st);
    }
    cout << "No two snowflakes are alike.";
    return 0;
}
