#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
void kmp()
{
    string text,pattern;
    cin >> text;
    cin >> pattern;
    string s = pattern + '#' + text;
    int n = s.size();
    vector<int> lps(n,0);
    for(int i = 1; i < n; i++)
    {
        int j = lps[i-1];
        while(j && s[i] != s[j])
            j = lps[j-1];
        if(s[i] == s[j])
            j++;
        lps[i] = j;
        if(lps[i] == pattern.size())
        {
            cout << i - 2 * pattern.size() + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        kmp();
    }
    return 0;
}
