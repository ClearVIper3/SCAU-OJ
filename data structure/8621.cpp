#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> s(n);
    for(ll i = 0; i < n; i++) cin >> s[i];

    ll key; cin >> key;

    ll low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(s[mid] == key)
        {
            cout << "The element position is " << mid << ".";
            return 0;
        }
        else if(s[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    cout << "The element is not exist.";
    return 0;
}
