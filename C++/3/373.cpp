#include <iostream>
using namespace std;

int main()
{
    double degree,min,second;

    cout << "Enter a latitude in degrees, minutes, and seconds:\n" ;
    cout << "First, enter the degrees: " ;
    cin >> degree;
    cout << "Next, enter the minutes of arc: " ;
    cin >> min;
    cout << "Finally, enter the seconds of arc:" ;
    cin >> second;
    cout << degree << " degrees, " << min << " minutes, " << second << " seconds = " << (degree + (min + (second) / 60) / 60) << " degrees\n" ;
}
