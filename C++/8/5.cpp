#include <iostream>
using namespace std;

template <class T>
T max5(T a[]);

int main()
{
    int x[5] = {1,2,3,4,5};
    double y[5] = {1.1,2.2,3,4,5.5};
    cout<<"max in a[5]: "<<max5(x)<<endl
    <<"max in b[5]: "<<max5(y)<<endl;
    return 0;
}

template <class T>
T max5(T a[])
{
    T max = a[0];
    for(int i = 0; i < 5; i++)
    {
        if(max < a[i])  max = a[i];
    }
    return max;
}
