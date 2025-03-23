#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int a;
    do
    {
        cin >> a;
        sum += a;
    }while(a != 0);

    cout << sum;
    return 0;
}
