#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> ugly(1000001);
    ugly[0] = 1;
    int a = 0,b = 0,c = 0;
    for(int i = 1; i < 1000001; i++)
    {
        int num1 = ugly[a] * 2;
        int num2 = ugly[b] * 3;
        int num3 = ugly[c] * 5;
        ugly[i] = min(num1,min(num2,num3));
        if(ugly[i] == num1) a++;
        if(ugly[i] == num2) b++;
        if(ugly[i] == num3) c++;
    }

    for(int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        cout << ugly[n-1] << endl;
    }

    return 0;
}
