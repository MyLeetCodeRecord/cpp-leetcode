##### 1. 朴素Dijkstra
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;

const int N = 510, M = 100010;
int g[N][N];
int d[N];
bool st[N];

int Dijkstra(int n){
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for(int i=0; i<n; i++){   // 更新n轮
        int t = -1;
        for(int u=1; u<=n; u++){
            if(!st[u] && (t==-1 || d[u] < d[t])){
                t = u;
            }
        }
        // cout<<t<<" "<<d[t]<<endl;
        st[t] = true;
        // 用 t 更新其它unset的节点dist
        for(int v=1; v<=n; v++){
            if(g[t][v]<0x3f3f3f3f && !st[v] && d[v] > g[t][v]+d[t]){
                d[v] = g[t][v] + d[t];
            }
        }
    }
    if(d[n] < 0x3f3f3f3f)
        return d[n];
    return -1;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j)
                g[i][j] = 0;
            else
                g[i][j] = 0x3f3f3f3f;
        }
    }
    for(int i=0; i<m; i++){
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        g[a][b] = min(g[a][b], d);      // 避免重边
    }
    cout<<Dijkstra(n)<<endl;
    return 0;
}
```

##### 2. 堆优化的Dijkstra
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 150010;
int h[N], e[N], w[N], nxt[N], idx=0;
int d[N];
bool st[N];
int n, m;

void insert(int a, int b, int d){
    e[idx] = b;
    nxt[idx] = h[a];
    w[idx] = d;
    h[a] = idx++;
}
int Dijkstra(){
    priority_queue<PII, vector<PII>, greater<PII>> pq;  // 小顶堆, 维护当前最小dist[]及其编号
    pq.push({0, 1});    // 1号节点, 距离是0, 编号是1

    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    while(!pq.empty()){
        PII cur = pq.top();
        pq.pop();
        if(st[cur.second])
            continue;
        st[cur.second] = true;
        for(int i=h[cur.second]; i!=-1; i=nxt[i]){
            int j = e[i];
            if(d[j] > cur.first + w[i]){
                d[j] = cur.first + w[i];
                pq.push({d[j], j});     // 并不是更新, 而是冗余存储
            }
        }
    }
    if(d[n] == 0x3f3f3f3f)
        return -1;
    return d[n];
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        insert(a, b, d);
    }
    cout<<Dijkstra()<<endl;
    return 0;
}
```

##### 3. 有边数限制的最短路 —— Bellman-Ford算法
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct Edge{
    int a, b, w;
};

const int N = 510, M = 10010;
int n, m, k;
Edge edges[M];
int dist[N], backup[N];

void BellmanFord(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // K次循环
    for(int i=0; i<k; i++){
        memcpy(backup, dist, sizeof dist);
        // 遍历所有边
        for(int j=0; j<m; j++){
            Edge e = edges[j];
            dist[e.b] = min(dist[e.b], backup[e.a] + e.w);
        }
    }
    if(dist[n]>0x3f3f3f3f - N * M)
        puts("impossible");
    else
        printf("%d", dist[n]);
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<m; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    BellmanFord();
    return 0;
}
```