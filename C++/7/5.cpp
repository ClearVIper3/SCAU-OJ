#include <iostream>
using namespace std;
int recursion(int n);

int main()
{
    int n;
    cin >> n;
    int sum = recursion(n);
    cout << sum;
    return 0;
}

int recursion(int n)
{
    if(n == 0) return 1;
    return n*recursion(n - 1);
}
