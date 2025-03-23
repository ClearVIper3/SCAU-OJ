#include <iostream>

int main()
{
    using namespace std;

    int km,gl;
    double ave;
    cin >> km;
    cin >> gl;
    ave = static_cast<double>(gl) / km * 100;

    cout << ave << endl;
}
