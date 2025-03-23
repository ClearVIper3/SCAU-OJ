#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<pair<int,int> > q;
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        q.push(make_pair(a,b));
    }
    double sum = 0;
    pair<int,int> p = q.front();
    q.pop();
    int sjt = p.first + p.second;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(sjt >= p.first)
            sum += sjt - p.first;
        else sjt = p.first;
        sjt += p.second;
    }
    double res = sum / n;
    printf("%.2lf",res);
    return 0;
}
