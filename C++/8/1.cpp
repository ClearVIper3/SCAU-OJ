#include <iostream>
#include <string>
using namespace std;
void str(string s,int n = 0);
int count = 0;
int main()
{
    str(s);
    int num;
    cin >> num;
    str(s,num);
    return 0;
}


void str(string s,int n)
{
    count++;
    if(n == 0) n = 1;
    else n = count;
    for (int i = 0; i < n;i++)
    {
        cout << s;
    }
}
