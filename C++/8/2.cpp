#include <iostream>
#include <cstring>
using namespace std;

struct CandyBar{
    char * band;
    float weight;
    int cal;
}

int main()
{
    int b;
    float c;
    char * d;
    cin >> b >> c;
    cin.get(d)
    cin.get();

}

void show(const CandyBar & a)
{
    cout << a.band << endl;
    cout << a.weight << endl;
    cout << a.cal << endl;
}

void hakimi(CandyBar & ar,char * s,double b,int i) // const char *
{
    strcpy(ar.band,s);
    ar.weight = b;
    ar.cal = i;
}
