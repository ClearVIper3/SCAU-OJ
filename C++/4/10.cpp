#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<double,3> second;
    cout << "first: ";
    cin >> second[0];
    cout << "second: ";
    cin >> second[1];
    cout << "third: ";
    cin >> second[2];
    double ave = (second[0] + second[1] + second[2]) / 3;
    cout <<"average: " << ave << endl;
    return 0;
}
