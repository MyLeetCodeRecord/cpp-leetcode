#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/* Dijkstra 邻接矩阵 */
const int INF = 1e6;
const int N = 510;
int n, m;
int g[N][N];
int dist[N];    // dist[u]: 当前1->u的最短距离
bool st[N];     // st[i]:标记结点i是否已经确定

int Dijkstra(){
    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    for(int i=0; i<n; i++){         // 迭代n次
        int t = -1;
        for(int u=1; u<=n; u++){    // 找当前dist[][]最小
            if(!st[u] && (t==-1 || dist[u]<dist[t])){
                t = u;
            }
        }
        st[t] = true;
        // 用当前最短距离的t, 更新其它not set的结点dist
        for(int u=1; u<=n; u++){
            if(g[t][u] < INF && dist[t] + g[t][u] < dist[u]){
                dist[u] = dist[t]+g[t][u];
            }
        }
    }
    if(dist[n] >= INF)
        return -1;
    return dist[n];
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++){
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        g[a][b] = min(g[a][b], d);  // 解决重边: 如果有多条边, 保留最短的
    }
    cout<<Dijkstra()<<endl;
    return 0;
}