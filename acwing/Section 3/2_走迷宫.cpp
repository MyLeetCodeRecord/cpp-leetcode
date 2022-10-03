#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

/* BFS最短路径长度 
 * - 为什么用BFS而不是DFS?  因为要求最短路径长度, 而不是可达性, 可达性的话BFS/DFS都可以
 * - 为什么设置d[][]?      因为d[][]=-1可以表示不可达, d[][]一旦被赋其它值, 后续BFS不会找到”更短“; 
 *                       用一个记录层数的变量也可以, 需要每次要清空整层(每次while中清空queue)
 */

typedef pair<int, int> PII;  // 用坐标(x,y)表示Node

const int N = 110;
int g[N][N];
int d[N][N];
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int n, m;

int BFS(){
    queue<PII> q;
    q.push({0, 0});
    memset(d, -1, sizeof d);
    d[0][0] = 0;    // 起点距离设为0
    while(!q.empty()){
        PII cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nextX = cur.first + direction[i][0];
            int nextY = cur.second + direction[i][1];
            if(nextX>=0 && nextX<n && nextY>=0 && nextY<m 
                        && g[nextX][nextY]==0 && d[nextX][nextY]==-1){  // 这里的d[nextX][nextY]==-1是一种防止循环访问的检查
                d[nextX][nextY] = d[cur.first][cur.second] + 1;
                q.push({nextX, nextY});
            }
        }
    }
    return d[n-1][m-1];
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &g[i][j]);
        }
    }
    cout<<BFS()<<endl;
    return 0;
}