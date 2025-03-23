#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string word;
    int vowels = 0;
    int consonants = 0;
    int others = 0;
    cout << "Enter words (q to quit): \n";
    while (cin >> word && word != "q")
    {
        if(isalpha(word[0]))
        {
            switch(word[0])
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowels++;
                break;
            default:
                consonants++;
                break;
            }
        }
        else
        {
            others++;
        }
    }
    cout << vowels << " words beginning with vowels\n";
    cout << consonants << " words beginning with consonants\n";
    cout << others << " others" << endl;
    return 0;
}
