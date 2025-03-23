#include <iostream>
using namespace std;

int input(double a[]);
void av(double a[],int size);
void output(double a[],int size);

int main()
{
    double a[10];
    int size = input(a);
    output(a,size);
    cout << endl;
    av(a,size);
}

int input(double a[])
{
    int i =0;
    while(i < 10 && cin >> a[i])
    {
        i++;
    }
    return i;
}

void output(double a[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " " ;
    }
}

void av(double a[],int size)
{
    double sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    cout << (double)(sum /size) << endl;
}
