#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    set<string> st;
    for(int len = 1; len <= s.size(); len++)
        for(int start = 0; start + len <= s.size(); start++)
            st.insert(s.substr(start,len));

    auto i = st.begin();
    i = next(i,k - 1);

    cout << *i << endl;

    return 0;
}
