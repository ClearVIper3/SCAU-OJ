#include <iostream>
using namespace std;

int main()
{
    double r,c,p,BMI;
    cout << "Your r:" ;
    cin >> r;
    cout << "Your c:" ;
    cin >> c;
    cout << "Your pound:" ;
    cin >> p;

    double h = (r * 12 + c) * 0.0254;
    double z = p / 2.2;

    BMI = z / (h*h);

    cout << "Your BMI:" << BMI << endl;
}
