#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    long long k;
    while (cin >> k && k)
    {
        for (long long y=k+1;y<=2*k;y++)
        {
            if(k*y%(y-k)==0)//保证x是整数
            {
                long long x=k*y/(y-k);
                cout<<"1/"<<k<<"=1/"<<x<<"+1/"<<y<<endl;
            }
        }
    }
    return 0;
}
