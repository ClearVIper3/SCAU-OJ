#include <iostream>
using namespace std;

int main()
{
    cout << "What is your first name? " ;
    string a;
    getline(cin, a);
    cout << "What is your last name? " ;
    string b;
    cin >> b;
    cout << "What letter grade do you deserve? " ;
    char c;
    cin >> c;
    cout << "What is your age? " ;？
    int d;
    cin >> d;
    cout << "Name:" << b << ',' << a << endl ;
    cout << "Grade: " << (char)(c + 1) << endl ;
    cout << "Age: " << d << endl;
}
