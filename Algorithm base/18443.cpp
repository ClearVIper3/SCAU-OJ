#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(int x,int u)
{
    int a[10] = {0};
    while(x)
    {
        if(x % 10 != 0 && a[x % 10]) return false;
        a[x % 10]++;
        x /= 10;
    }
    while(u)
    {
        if(u % 10 != 0 && a[u % 10]) return false;
        a[u % 10]++;
        u /= 10;
    }
    return true;
}

string to(int i)
{
    string res = "";
    while(i)
    {
        res += i % 10 + '0';
        i /= 10;
    }
    reverse(res.begin(),res.end());
    return res;
}

void show(int i,int u,int n)
{
    string a = to(i);
    string b = to(u);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i = a.size(); i < 5; i++) a.push_back('0');
    for(int i = b.size(); i < 5; i++) b.push_back('0');
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    cout << a << '/' << b << '=' << n << endl;
}

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        for(int u = 1; u * n <= 99999; u++)
            if(cmp(u * n,u))
                show(u * n,u,n);
   
        cout << endl;
    }
}
