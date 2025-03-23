#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int month[13] = {0};
    string m[13] = {"0","January","February","March","April","May","June","July","August","September","October","November","December"};
    for (int i = 1; i <= 12; i++)
    {
        cout<<"Please enter the sales volume of C++ for FOOLS in "<<m[i]<<endl;
        cin >> month[i];
        sum += month[i];
    }

    cout<<"The sales volume of C++ for FOOLS in this year was "<<sum<<endl;
    return 0;
}
