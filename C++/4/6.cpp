#include <iostream>
using namespace std;

struct CandyBar
{
    string brand;
    double weight;
    int calory;
};

int main()
{
    CandyBar snack[3];
    snack[0] = {"q",1.1,1};
    snack[1] = {"w",2.2,2};
    snack[2] = {"e",3.3,3};
    for (int i = 0;i<3;++i)
    {
        cout<<"brand:"<<snack[i].brand<<endl;
        cout<<"weight:"<<snack[i].weight<<endl;
        cout<<"calory:"<<snack[i].calory<<endl;
    }
}
