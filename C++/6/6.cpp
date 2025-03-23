#include <iostream>
#include <string>

using namespace std;
struct donate
{
    string name;
    double money;
};

int main()
{
    int arrsize;
    cout << "How many: ";
    cin >> arrsize;
    donate * person = new donate [arrsize];
    int i = 0;
    cout << "Patrons \n";

    while (1)
    {
        string str;
        cout << "Name: ";
        getline(cin,person[i].name);
        cin.get();
        if(str == "done" || i >= arrsize) break;
        person[i].name = str;
        cout << "money: ";
        cin >> person[i].money;
        i++;
    }

    int p = 0 ;
    cout << "Grand Patrons: " << endl;
    for (int j = 0;j < i; j++)
    {
        if(person[j].money >= 10000)
        {
            p = 1;
            cout << person[i].name << ' ' << person[i].money << endl;
        }
    }
    if (p == 0)
    {
        cout << "none";
        p = 0;
    }

    cout << "\nPatrons: " << endl;
    for (int j = 0; j < i; j ++)
    {
        if(person[j].money < 10000)
        {
            cout << person[j].name << ' ' << person[j].money << endl;
            p = 1;
        }
    }
    if (p == 0) cout << "none";
    delete [] person;
    return 0;
}
