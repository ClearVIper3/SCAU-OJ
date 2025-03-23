#include <iostream>

int main()
{
    using namespace std;
    long long wp,ap;
    cout << "Enter the world's population: " ;
    cin >> wp;
    cout << "Enter the population of the US: ";
    cin >> ap;
    double average =(static_cast<double>(ap) / wp) * 100;
    cout << "The population of the US is " << average << "% of the world population." <<endl;
    return 0;
}
