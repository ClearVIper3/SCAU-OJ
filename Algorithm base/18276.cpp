#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include <string.h>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

//地图
char map[105][105];
//传送地图
int wx[105][105];
int wy[105][105];
//定义步数
int step[105][105] = { 0 };

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, W;
    int bx, by, ex, ey;
    int flag;
    int addx[4] = { 1,-1,0,0 };
    int addy[4] = { 0,0,1,-1 };
    int nextx, nexty;
    int T;
    cin >> T;
    while (T--) {
        memset(step, 0, 105 * 105 * sizeof(int));
        memset(wx, 0, 105 * 105 * sizeof(int));
        memset(wy, 0, 105 * 105 * sizeof(int));
        cin >> N >> M;
        flag = 0;
        //输入地图
        for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> map[i][j];
        //传送次数
        cin >> W;
        for (int i = 0; i < W; i++) {
            int x, y, a, b;
            cin >> x >> y >> a >> b;
            //传送标记为#
            map[x][y] = '#';
            //存储传送位置x  y
            wx[x][y] = a;
            wy[x][y] = b;
        }
        //输入起点  终点
        cin >> bx >> by >> ex >> ey;
        queue<int> stepx, stepy;
        int lastx, lasty, nextx, nexty;
        int flag = 0;
        //入队起点终点
        stepx.push(bx);
        stepy.push(by);

        //如果队列不为空持续循环
        while (!stepx.empty()) {
            //如果找到出口  标记 退出
            if (stepx.front() == ex && stepy.front() == ey) {
                flag = 1;
                break;
            }           
            //如果当前队头为传送点  就处理好步数传送然后不要判定四个方向，传送完直接出队
            else if (map[stepx.front()][stepy.front()]=='#') {
                nextx = wx[stepx.front()][stepy.front()];
                nexty = wy[stepx.front()][stepy.front()];
                //标记如果有障碍   该格子已被走过     越界   则直接出队这个传送点
                if (map[nextx][nexty] == '1' || step[nextx][nexty] != 0 || nextx < 0 || nextx >= N || nexty < 0 || nexty >= M) {
                    stepx.pop();
                    stepy.pop();
                    continue;
                }
                //标记好步数  为传送点的步数+1
                step[nextx][nexty] = step[stepx.front()][stepy.front()] + 1;
                //入队传送出口
                stepx.push(nextx);
                stepy.push(nexty);
            }
            //如果不为终点  也不为传送点  那就是普通点
            else {
                //判定四个方位的情况
                for (int i = 0; i < 4; i++)
                {
                    int curx, cury;
                    curx = stepx.front() + addx[i];
                    cury = stepy.front() + addy[i];
                    //如果不能走了就进入下一次循环
                    if (map[curx][cury] == '1' || step[curx][cury] != 0 || curx < 0 || curx >= N || cury < 0 || cury >= M) {
                        continue;
                    }
                    //如果没问题  入队
                    stepx.push(curx);
                    stepy.push(cury);
                    //标记步数
                    step[curx][cury] = step[stepx.front()][stepy.front()] + 1;
                }
            }
            //当前队头出队
            stepx.pop();
            stepy.pop();
        }
        //判定
        if (flag)cout << step[stepx.front()][stepy.front()] << endl; else cout << "die" << endl;
    }
}
