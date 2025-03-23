#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;

    return true;
}

int main()
{
    string s;
    cin >> s;
    int i;
    for(i = s.size() - 1; i >= 0; i--)
        if(!isPalindrome(s.substr(i, s.size() - i)))
            break;
        
    string sub = s.substr(0, i + 1);
    reverse(sub.begin(), sub.end());
    cout << s + sub << endl;
    return 0;
}
