#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> s;
    
    vector<int> in(n);
    vector<int> out(n);

    for(int i = 0; i < n; i++) cin >> in[i];
    for(int i = 0; i < n; i++) cin >> out[i];

    int idx = 0;

    for(int i = 0; i < n; i++)
    {
        s.push(in[i]);
        while(!s.empty() && s.top() == out[idx])
        {
            s.pop();
            idx++;
        }
    }

    if(!s.empty()) cout << "no" << endl;
    else cout << "yes" << endl;
    return 0;
}
