#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    char first[20],last[20],name[40];
    cout << "Enter your first name: ";
    cin >> first;
    cout << "Enter your last name: ";
    cin >> last;
    cout << "Here's the information in a single string: ";
    strcpy(name,first);
    strcat(name,", ");
    strcat(name,last);
    cout << name;
}
