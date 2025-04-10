#include <iostream>

using namespace std;

bool check(int n,int x)
{
    if(n < 3) return false;
    else if(n == 3) return true;
    if(x % 2) 
        return check(n - n / 2,(x + 1) / 2);
    else return check(n / 2,x / 2);
}

int main()
{
    int n,x;
    while(cin >> n >> x && n != 0 && x != 0)
        if(check(n,x)) cout << 'Y' << endl;
        else cout << 'N' << endl;

    return 0;
}
