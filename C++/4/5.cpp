#include <iostream>
using namespace std;

struct CandyBar
{
    string brand;
    double weight;
    int kl;
};

int main()
{
    CandyBar snack; // snack = {Mocha Munch,2.3,350};
    snack.brand = "Mocha Munch";
    snack.weight = 2.3;
    snack.kl = 350;
    cout << snack.brand << endl;
    cout << snack.weight << endl;
    cout << snack.kl << endl;
    return 0;
}
