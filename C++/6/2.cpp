#include <iostream>
#include <array>
#include <cctype>
using namespace std;

int main()
{
    array<double,  10> arr;
    int count = 0;
    double sum = 0;
    while (cin >> arr[count]&& count < 10)
    {
        sum += arr[count++];
    }
    cout << "length: " << count << endl;
    cout << "average: " << sum / count << endl;
    return 0;
}
