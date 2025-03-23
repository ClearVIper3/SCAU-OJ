#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    int res = 0;
    cin >> n;
    int a[200001] = {0};
    for(int i = 0; i < n; i++)
    {
        int digit;
        cin >> digit;
        if(!a[digit])
        {
            res++;
            a[digit] = 1;
        }
    }

    cout << res;
}
