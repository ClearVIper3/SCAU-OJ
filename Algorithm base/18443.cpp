#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

bool check(int x,int i)
{
    int a[10] = {0};
    while(x){
        if(x % 10 != 0 && a[x % 10])
            return false;
        a[x % 10]++;
        x /= 10;
    }
    while(i){
        if(i % 10 != 0 && a[i % 10])
            return false;
        a[i % 10]++;
        i /= 10;
    }
    return true;
}

string to(int x){
    string res = "";
    while(x){
        res += x % 10 + '0';
        x /= 10;
    }
    while(res.size() < 5)
        res += '0';
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n != 0){
        for(int i = 1; i * n <= 99999; i++){
            if(check(i * n,i))
                cout << to(i * n) << '/' << to(i) << '=' << n << endl;
        }
        cout << endl;
    }

    return 0;
}
