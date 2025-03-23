#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<long double,101> arr;
    arr[0] = arr[1] = 1L;
    for (int i = 1; i < 101; i++)
    {
        arr[i] = i * arr[i-1];
    }
    for (int i = 1; i <= 100; i++)
    {
        cout << i << "! = " << arr[i] << endl;
    }
    return 0;
}
