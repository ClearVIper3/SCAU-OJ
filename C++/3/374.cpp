#include <iostream>
using namespace std;

int main()
{
    long second;
    cout << "Enter the number of seconds: " ;
    cin >> second;
    long day = second /24 /60 /60;
    long hours = second %(24 * 60 * 60)/60 /60;
    long mins = second %(60 * 60) /60;
    long seconds = second %60;


    cout << second << " seconds = " << day << " days, " << hours << "hours, " << mins << " minutes, " << seconds << " seconds";
}
