#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
string solve(const string &s,int& i)
{
    string res = "";
    while(i < s.size() && s[i] != ']')
    {
        if(s[i] >= 'A' && s[i] <= 'Z') res += s[i++];
        else
        {
            i++;
            int sum = 0;
            while(isdigit(s[i]))
                sum = sum * 10 + s[i++] - '0';
            i++;//'|'
            string add = solve(s,i);
            i++;//']'
            while(sum--)
                res += add;
        }
    }
    return res;
}
 
int main()
{
    string s;
    cin >> s;
    int idx = 0;
    cout << solve(s,idx) << endl;
    return 0;
}
