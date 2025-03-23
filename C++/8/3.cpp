#include <iostream>
#include <cctype>
using namespace std;
void turn (string &s);

int main()
{
    string s;
    cout << "Enter a string (q to quit): ";
    getline(cin,s);
    while(s != "q" && s != "Q")
    {
        turn (s);
        cout << "Next string (q to quit): ";
        getline(cin,s);
    }
    cout << "Bye.";
    return 0;
}

void turn (string &s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        s[i] = toupper(s[i]);
        i++;
    }
    cout << s << endl;
}
