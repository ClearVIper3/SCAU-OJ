
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct user{
    char name[21];
    int ac,time;
    int rk;
};

static bool cmp(user a,user b){
    if(a.ac == b.ac)
        if(a.time == b.time)
            return a.rk < b.rk;
        else
            return a.time < b.time;
    else
        return a.ac > b.ac;
}

int main()
{
    int n;
    cin >> n;
    vector<user> users(n);
    for(int i = 0; i < n; i++)
    {
            scanf("%d %d %s",&users[i].ac,&users[i].time,users[i].name);
            users[i].rk = i;
    }
    sort(users.begin(),users.end(),cmp);

    for(int i = 0; i < n; i++)
        cout << users[i].name << endl;
    return 0;
}
