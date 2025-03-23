#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 1, sum;
    int next = a + b;
    int n;
    cin >> n;
    sum = next;
    switch(n)
    {
        case 1:sum = 1;
            break;
        case 2:sum = 2;
            break;
    }
    for (int i = 3; i <= n; i++)
    {
        sum += next;
        a = b;
        b = next;
        next = a + b;
    }
    cout << sum;
    return 0;
}
