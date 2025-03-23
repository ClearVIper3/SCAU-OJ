#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int man = (k - 1) % n + 1;    
    int woman = (k - 1) % m + 1;  

    cout << man << " " << woman << endl;
    return 0;
}
