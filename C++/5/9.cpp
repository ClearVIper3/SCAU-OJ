#include <iostream>
using namespace std;

int main()
{
    string words;
    cout << "Enter words (to stop, type the word done):\n";
    cin >> words;
    int n = 0;
    while (words != "done")
    {
        cin >> words;
        n++;
    }

    cout << "words: " << n << endl;
    return 0;
}
