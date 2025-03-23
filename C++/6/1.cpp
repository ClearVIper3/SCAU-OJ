#include <iostream>
using namespace std;
#include <cctype>

int main()
{
    char ch;
    while((ch = cin.get()) != '@')
    {
        if(islower(ch))
        {
            ch = toupper(ch);
            cout << ch;
        }
        else if(isupper(ch))
        {
            ch = tolower(ch);
            cout << ch;
        }
        else if(!(isdigit(ch)))
        {
            cout << ch;
        }
    }
    cout << endl;
    return 0;
}
