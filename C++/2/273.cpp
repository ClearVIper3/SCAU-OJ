#include <iostream>

using namespace std;

void first(void)
{
    cout << "Three blind mice\n" ;
}

void next(void)
{
    cout << "See how they run\n";
}

int main()
{
    first();
    first();
    next();
    next();

    return 0;
}
