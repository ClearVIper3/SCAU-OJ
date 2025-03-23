#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int num = 0;
    for(int i = n; i <= m; i++)
    {
        num += i;
    }
    cout << num;
    return 0;
}
