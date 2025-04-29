#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,res,val;
    cin >> n;
    multiset<int> st;
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        st.insert(val);

        auto idx = st.find(val);

        int l = -1;
        int r = -1;

        if(idx != st.begin()){
            auto pp = prev(idx);
            l = *pp;
        }
        auto nn = next(idx);
        if(nn != st.end())
            r = *nn;

        if(l != -1 && r != -1)
        {
            if(abs(l - val) >= abs(r - val))
                res = r;
            else
                res = l;
        }
        else if(l == -1 && r != -1)
            res = r;
        else if(l != -1 && r == -1)
            res = l;
        else
            res = val;
            
        cout << res << ' ';
    }

    return 0;
}
