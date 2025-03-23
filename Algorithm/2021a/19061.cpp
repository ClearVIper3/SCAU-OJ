#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int T;
    int result;
    cin >> T;
    cin.get();
    vector<string> s(T);
    for(int i = 0; i < T; i++) getline(cin,s[i]);
    for(int i = 0; i < T; i++)
    {
        int bol = 1;
        result = 0;
        for(int j = 0; j < s[i].size(); j++)
        {
            int a1;
            if(bol == 1 && s[i][j] == '+')
            {
                a1 = j;
                bol = 0;
                string c;
                for(int u = 0; u < j; u++)
                {
                    c += s[i][u];
                }
                result += stoi(c);
            }
            else if(s[i][j] == '+')
            {
                string c;
                for(int u = a1 + 1; u < j; u++)
                {
                    c += s[i][u];
                }
                result += stoi(c);
                a1 = j;
            }
            else if(j == s[i].size() - 1)
            {
                string c;
                for(int u = a1 + 1; u < s[i].size(); u++)
                {
                    c += s[i][u];
                }
                result += stoi(c);
            }
        }
        cout << result << endl;
    }
    return 0;
}
