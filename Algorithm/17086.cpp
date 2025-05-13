#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;cin >> s;
    vector<int> str(n);
    for(int i = 0; i < n; i++)
        str[i] = s[i] - '0';

    sort(str.begin(),str.end());
    int time = 1;
    do{
        cout << time++ << ' ';
        for(int i = 0; i < n; i++)
            cout << str[i];
        cout << endl;
    }while(next_permutation(str.begin(),str.end()));
  return 0;
}
