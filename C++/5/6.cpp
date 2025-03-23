#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int month[4][13] = {0};
    string m[13] = {"0","January","February","March","April","May","June","July","August","September","October","November","December"};
    for (int y = 1; y <= 3; y++)
    {
        for (int i = 1; i <= 12;i++)
        {
            cout<<"Please enter the sales volume of C++ for FOOLS in "<<m[i]<<endl;
            cin >> month[y][i];
            sum += month[y][i];
        }
    }

    cout<<"The sales volume of C++ for FOOLS in 3 years was "<<sum<<endl;
    return 0;
}
