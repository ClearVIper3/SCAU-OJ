#include <iostream>
using namespace std;

int calculate (int x)
{
    return x * 220;
}

int main()
{
    int length;
    cin >> length;
    cout << calculate(length);
    cout << endl;
}
