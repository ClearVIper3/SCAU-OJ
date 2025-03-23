#include <iostream>
using namespace std;

double z(double x)
{
    return 63240 * x;
}

int main()
{
    cout << "Enter the number of light year: " ;
    double L ;

    cin >> L;
    cout << L << " light years = " << z(L) << " astronomical units" ;
    cout << endl;

    return 0;
}
