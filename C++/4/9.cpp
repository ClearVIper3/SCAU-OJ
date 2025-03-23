#include <iostream>
using namespace std;
const int MAX = 20;

struct CandyBar{
    string brand;
    double weight;
    int calory;
};

int main()
{
    CandyBar * snack = new CandyBar [3]{
         {"q",1.1,1},
         {"w",2.2,2},
         {"e",3.3,3}
         };
    for (int i = 0;i<3;++i)
    {
        cout<<"brand:"<<snack[i].brand<<endl;
        cout<<"weight:"<<snack[i].weight<<endl;
        cout<<"calory:"<<snack[i].calory<<endl;
    }
    delete [] snack;
    return 0;
}
