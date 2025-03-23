#include <iostream>
using namespace std;
void av(double x,double y);

int main()
{
    double n,m;
    while (cin >> n >> m)
    {
        if (n == 0 || m == 0) break;
        av(n,m);
    }
    return 0;
}

void av(double x,double y)
{
    cout << 2.0 * x * y/(x + y) << endl;
}
