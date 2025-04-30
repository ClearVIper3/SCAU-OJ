
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,val;
    cin >> n;
    vector<int> ash(n,0);
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> val,ash[val]++;

    for(int i = 0; i < n; i++)
    {
        int gap = n - a[i];
        for(int j = gap; j < 2 * n; j++)
        {
            if(ash[j % n] != 0)
            {
                a[i] = (a[i] + (j % n)) % n;
                ash[j % n]--;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
