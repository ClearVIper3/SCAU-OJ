#include <iostream>

int main()
{
    using namespace std;
    string first,last,name;
    cout << "Enter your first name: ";
    cin >> first;
    cout << "Enter your last name: ";
    cin >> last;
    cout << "Here's the information in a single string: ";
    name = first + ", " + last;
    cout << name << endl;
    return 0;
}
