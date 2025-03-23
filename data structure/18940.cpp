#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> prefix_num(n,0);
    int cmax = 0;
    for(int i = 1; i < n; i++)
    {
        int len = prefix_num[i - 1];
        while(len && s[len] != s[i]) len = prefix_num[len - 1];
        if(s[len] == s[i]) len++;
        prefix_num[i] = len;
        cmax = max(cmax,prefix_num[i]);
    }
    if(n % (n - prefix_num[n - 1]) == 0)
        cout << n / (n - prefix_num[n - 1]) << endl;
    else cout << 1 << endl;
    return 0;
}
