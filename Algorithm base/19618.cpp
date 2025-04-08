#include <stdio.h>
#include <queue>
using namespace std;
typedef struct{
    int r; // row
    int c; // column
    int s; // step
}LOC;
int sr,sc,dr,dc;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char d[100][100];
void solve(){
    int m,n,i,nr,nc;
    queue<LOC> q;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++) scanf("%s",d[i]);
    scanf("%d%d%d%d",&sr,&sc,&dr,&dc);
    LOC first={sr,sc,0};
    q.push(first);
    d[sr][sc] = '1';
    while(!q.empty())
    {
        LOC temp = q.front(); q.pop();
        if(temp.r == dr && temp.c == dc)
        {
            printf("%d\n",temp.s);
            return;
        }
        for(int i = 0; i < 4; i++)
        {
            int x = temp.r + dir[i][0];
            int y = temp.c + dir[i][1];
            if(x < 0 || y < 0 || x >= m || y >= n || d[x][y] == '1') continue;
            LOC go = {x,y,temp.s + 1};
            q.push(go);
            d[x][y] = '1';
        }
    }
    printf("die\n");

}
int main(){
    int n;
    scanf("%d",&n);
    while(n--) solve();
}
