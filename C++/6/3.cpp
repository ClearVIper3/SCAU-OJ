#include <iostream>
using namespace std;

int main()
{
    cout << "Please enter one of the following choices:\n"
    << "c) carnivore p) pianist\nt) tree g) game\nf\n" ;
    cout << "Please enter a c, p, t, or g: " ;
    char ch;
    cin >> ch;
    while(ch != 'f' && ch != 'c' && ch != 't' && ch != 'g' && ch != 'p' )
    {
        cout << "Please enter a c, p, t, or g: " ;
        cin >> ch;
    }
    switch (ch)
    {
        case 'c': cout << "A maple is a carnivore";
        break;
        case 'p': cout << "A maple is a pianist";
        break;
        case 't': cout << "A maple is a tree";
        break;
        case 'g': cout << "A maple is a game";
        break;
        case 'f': cout << "A maple is a \n";
        break;
    }
    return 0;
}
