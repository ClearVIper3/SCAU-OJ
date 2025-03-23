#include <iostream>
using namespace std;

double Fa(double x)
{
    return (1.8 * x) + 32.0;
}

int main()
{
    double ce;

    cout << "Please enter a Celsius value: ";
    cin >> ce;
    cout << ce <<"degrees Ceosius is " << Fa(ce) << " degrees Fahrenheit" << '.' << endl;
}
