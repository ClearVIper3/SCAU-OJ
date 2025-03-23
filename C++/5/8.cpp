#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char word[10];
    int sum = 0;
    cin >> word;
    do
    {
        sum++;
        cin >> word;
    }while(strcmp(word,"done"));

    cout << "words: " << sum << endl;
    return 0;
}
