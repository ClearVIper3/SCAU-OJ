#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;
    string s;
    cin >> s;
    int a[26] = {0};
    for(int i = 0; i < s.size(); i++) a[s[i] - 'a']++;

    for(int i = 0; i < 26; i++) 
        if(a[i]) cout << (char)(i + 'a');
    return 0;
}
