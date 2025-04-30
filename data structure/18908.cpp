#include <iostream>
#include <string>
typedef unsigned long long ll;
using namespace std;
const ll p = 131;
ll pw[1000005] = {1},hx[1000005];
string s;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,m,l1,r1,l2,r2;
    for(i = 1; i <= 1000000; i++)
        pw[i] = pw[i - 1] * p;
    cin >> s;
    for(i = 0; i < s.size(); i++)
        hx[i + 1] = hx[i] * p + s[i] - 'a';

    int k;cin >> k;
    while(k--){
        cin >> l1 >> r1 >> l2 >> r2;
        if(hx[r1] - hx[l1 - 1] * pw[r1 - l1 + 1] == hx[r2] - hx[l2 - 1] * pw[r2 - l2 + 1])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
