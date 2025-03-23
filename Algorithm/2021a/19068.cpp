#include <iostream>
#include <string>
using namespace std;

int main()
{
    int m,n;
    cin >> n >> m;
    cin.get();
    string str;
    getline(cin,str);
    for(int j = 0; j < n; j++)
    {
        while(m > 0 && str[j] != 'a')
        {
            m--;
            str[j]--;
        }
    }
    cout << str;
    return 0;
}
