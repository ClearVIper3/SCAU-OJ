#include <iostream>
using namespace std;

int main()
{
    double D = 100, C = 100 ,p = 0;
    do
    {
        D += 10;
        C *= 1.05;
        ++p;
    }while(D >= C);

    cout << "Years: " << p << endl;
    cout << "D: " << (double)D - 100 << endl;
    cout << "C: " << (double)C - 100 << endl;

    return 0;
}
