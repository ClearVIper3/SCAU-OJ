#include <iostream>
using namespace std;
const int MAX = 20;

struct pizza{
    char name[MAX];
    double l;
    int weight;
};

int main()
{
    pizza pz;
    cout<<"What's the name of pizza company:";
    cin.getline(pz.name,MAX);// 使用 cin 的方法读取一行数据就只能搭配 char 数组了
    cout<<"What's the diameter of pizza:";
    cin>>pz.l;
    cout<<"What's the weight of pizza:";
    cin>>pz.weight;
    cout<<"company:"<<pz.name<<endl;
    cout<<"diameter:"<<pz.l<<" cm"<<endl;
    cout<<"weight:"<<pz.weight<<" kg"<<endl;
    return 0;
}
