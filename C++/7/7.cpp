// arrfun3.cpp -- array functions and const
#include <iostream>
const int Max = 5;

// function prototypes
double * fill_array(double ar[], int limit);
void show_array(const double[],double*);
void revalue(double,double[],double*);

int main()
{
    using namespace std;
    double properties[Max];

    double * p = fill_array(properties, Max);
    show_array(properties, p);
    if (p!=&properties[0])
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, p);
        show_array(properties, p);
    }
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}

double * fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    double * p;
    for (p = ar; p < ar + limit - 1; p++)
    {
        int i = 0;
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; input process terminated.\n";
           break;
        }
        else if (temp < 0)     // signal to terminate
            break;
        *p = temp;
        i++;
    }
    return p;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], double*ps)
{
    using namespace std;
    const double * p = &ar[0];
    for (int i = 0; p != ps + 1; p++,i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double r, double ar[], double*ps)
{
    double *p = &ar[0];
    for (int i = 0; p != ps+1; p++,i++)
        ar[i] *= r;
}



