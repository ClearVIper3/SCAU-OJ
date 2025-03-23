#include <iostream>
using namespace std;

double add(double x, double y);
double calculate(double, double,double(*q)(double,double));
double x(double x, double y);
double c(double x, double y);

int main()
{
    double n,m;
    double (*p[3])(double ,double) ={add,x,c};
    while (cin >> n >> m){
        for(int i = 0; i < 3; i++){
            cout << i << ": " << calculate(n,m,p[i]) << endl;
        }
    }
}


double add(double x, double y)
{
       return x + y;
}

double calculate(double x, double y, double (*q)(double,double))
{
    return q(x,y);
}

double x(double x, double y)
{
       return x * y;
}

double c(double x, double y)
{
       return x / y;
}
