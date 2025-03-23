#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    int * a = new int [n+1];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max = 0;

    for(int i = 0; i < n; i++)
    {
        if(max < a[i])
        {
            max = a[i];
        }
    }

    int * day = new int [max+12];
    for(int i =1; i <= max + 12; i++)
    {
        day[i] = 0;
    }

    for(int i = 0 ; i < n; i++)
    {
        day[a[i]]++;
        day[a[i]+2]++;
        day[a[i]+6]++;
        day[a[i]+10]++;
    }

    int point = 0;

    for(int i = 1; i <= max + 12; i++)
    {
        if(k <= day[i])
        {
            point++;
        }
    }

    cout << point;

    delete [] day;
    delete [] a;
}
