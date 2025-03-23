#include <iostream>
#include <cstring>
using namespace std;
template <class T>
T maxn(T [],int n);

template <> const char*(const char*ar[],int n);

int main()
{
    int ari[6]={1,2,3,4,6,5};
    double ard[4]={1.1,2.2,4.4,3.3};
    const char *ars[5]={
        "a",
        "bb",
        "ccc",
        "ddddd",
        "eeee"
    };
    cout<<"The max integer of array is:"<<maxn(ari,6)<<endl;
    cout<<"The max double of array is:"<<maxn(ard,4)<<endl;
    cout<<"The max string of array is:"<<maxn(ars,5)<<endl;
}

template <class T>
T maxn(T a[],int n)
{
    T max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(max < a[i]) max = a[i];
    }
    return max;
}
template <> void maxn (const char*ar[],int n)
{
    const char *maxs=ar[0];
    for( int i=1;i<n;i++)
    {
        if(strlen(maxs)<strlen(ar[i]))
        maxs=ar[i];
    }
    return maxs;
}
