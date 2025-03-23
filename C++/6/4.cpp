#include <iostream>
using namespace std;
const int strsize = 20;

struct bop {
    char fullname[strsize];  // real name
    char title[strsize];     // job title
    char bopname[strsize];   // secret BOP name
    int preference;          // 0 = fullname, 1 = title, 2 = bopname
};

int main()
{
    cout << "Benevolent Order of Programmers Report\n";
    cout << "a. display by name     b. display by title\nc. display by bopname d. display by preference\nq. quit\n";
    cout << "Enter your choice: ";
    char ch;
    cin >> ch;
    bop member[5]=
    {
        {"Wimp Macho","English Teacher","DEMON",0},
        {"Raki Rhodes","Junior Programmer","BOOM",1},
        {"Celia Laiter","Super Star","MIPS",2},
        {"Hoppy Hipman","Analyst Trainee","WATEE",1},
        {"Pat Hand","Police","LOOPY",2}
    };
    while (ch != 'q')
    {
        switch(ch)
        {
            case 'a':
                for(int i=0;i<5;i++)
                    cout<<member[i].fullname<<endl;
                break;
            case 'b':
                for(int i=0;i<5;i++)
                    cout<<member[i].title<<endl;
                break;
            case 'c':
                for(int i=0;i<5;i++)
                    cout<<member[i].bopname<<endl;
                break;
            case 'd':
                for(int i=0;i<5;i++)
                {
                    if(member[i].preference==0)
                        cout<<member[i].fullname<<endl;
                    else if(member[i].preference==1)
                        cout<<member[i].title<<endl;
                    else if(member[i].preference==2)
                        cout<<member[i].bopname<<endl;
                }
                break;
        }
        cout << "Next choice:";
        cin >> ch;
    }
    cout << "Bye!\n";
    return 0;
}
