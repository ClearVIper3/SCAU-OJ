//arrobj.cpp -- functions with array objects
#include <iostream>
const int Seasons = 4;
struct data
{
    double arr[Seasons];
};
const char * Snames[] = {"Spring", "Summer", "Fall", "Winter"};

void fill(data * pa);
void show(data * da);
int main()
{
    data expenses;
    fill(&expenses);
    show(&expenses);
    return 0;
}

void fill(data * pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> pa->arr[i];
    }
}

void show(data * da)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << da->arr[i] << '\n';
        total += da->arr[i];
    }
    std::cout << "Total: $" << total << '\n';
}
