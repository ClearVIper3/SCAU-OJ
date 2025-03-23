#include <iostream>
#include <vector>
using namespace std;

struct car
{
    string company;
    int years;
};

int main()
{
    int n;
    cout << "How many cars do you wish to catalog? ";
    cin >> n;
    cin.get();
    vector<car> c(n+1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Car #" << i << ": \n";
        cout << "Please enter the make: ";
        getline(cin,c[i-1].company);
        cout << "Please enter the year made: ";
        cin >> c[i-1].years;
        cin.get();
    }
    cout << "Here is your collection:\n";
    for (int i = 1; i <=n; i++)
    {
        cout << c[i-1].years;
        cout << ' ' << c[i-1].company << endl;
    }
}
