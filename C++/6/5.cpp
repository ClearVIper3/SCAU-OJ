#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    double n;
    cin >> n;
    while (!cin.fail() && n > 0)
    {
        double tvarps = 0;
            if (n > 35000)
            {
                tvarps += (n - 35000) * 0.2;
                n = 35000;
            }
            if (n >= 15001 && n <= 35000)
            {
                tvarps += (n - 15000) * 0.15;
                n = 15000;
            }
            if (n >= 5001 && n <= 15000)
            {
                tvarps += (n - 5000) * 0.10;
            }
        cout << "obtain fee: " << tvarps << endl;
        cout << "next: ";
        cin >> n;
    }
    return 0;
}
