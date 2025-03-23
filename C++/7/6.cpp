#include <iostream>
using namespace std;

int Fill_array(double ar[],int size);
void Show_array(double ar[],int real);
void Reverse_array(double a[],int real);

int main()
{
    int size;
    cin >> size;
    double ar[size];
    int real = Fill_array(ar,size);
    cout << "real: " << real;
    cout << endl;
    Show_array(ar,real);
    Reverse_array(ar,real);
    Show_array(ar,real);
    return 0;
}

int Fill_array(double ar[],int size)
{
    cout << "input double:\n" ;
    int i = 0;
    while (i < size && cin >> ar[i])
    {
        i++;
    }
    if(i < size) return i + 1;
    return i;
}

void Show_array(double ar[],int real)
{
    int i = 0;
    while (i < real)
    {
        cout << ar[i] << endl;
        i++;
    }
}

void Reverse_array(double a[],int real)
{
    for(double *p1 = a,*p2 = a + real - 1; p1 < p2; p1++,p2--)
    {
        double tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
    }
}
