#include <iostream>
using namespace std;

void time(int a,int b)
{
    cout << "Time: " << a << ':' << b << endl;
}

int main()
{
    cout << "Enter the number of hours: " ;

    int h,m;

    cin >> h;
    cout << "Enter the number of minutes: " ;
    cin >> m;

    time(h,m);

    return 0;
}
