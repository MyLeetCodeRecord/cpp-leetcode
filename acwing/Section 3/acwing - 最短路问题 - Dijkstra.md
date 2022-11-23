### 最短路问题
- 第一类: 单源最短路
  - 所有边权都是正数, **不能有负权边**
      - 朴素Dijkstra算法(稠密图)  `O(n^2)`
      - 堆优化Dijkstra算法(稀疏图)  `O(mlogn)`
  - 存在负权边
      - **Bellman-Ford**  `O(nm)`, 允许有负权边, 但不能有负权环
      - SPFA  `O(m)`, 最坏`O(nm)`
- 第二类: 多源汇最短路
  - Floyd算法  `O(n^3)`


#### 1. 朴素Dijkstra算法
##### (1) 存储结构

```CPP
const int N = 510;
int n, m;
int g[N][N];    // 稠密图 => 邻接矩阵
int dist[N];    // dist[u]: 当前1->u的最短距离
bool st[N];     // st[i]:标记节点i是否已经确定
```

##### (2) 初始化
> 读取邻接矩阵`g[a][b]`时要注意解决重边, 即取最小值, `g[a][b] = min(g[a][b], d)`
> 
```CPP
// 邻接矩阵的构建
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
```

```CPP
// dist[]的初始化
memset(dist, INF, sizeof dist);
dist[1] = 0;
```

##### (3) N次更新

```CPP
void Dijkstra(){
    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    for(int i=0; i<n; i++){     // 迭代 n 次, 每次set一个节点
        int t = -1
        for(int u=1; u<=n; u++){
            // t <- 还没最终确定的(set[t]=false), 距离最近的点
            if(!st[u] && (t==-1 || dist[u]<dist[t])){
                t = u;
            }
        }
        st[t] = true;
        // 用 t 更新其它点的"更短"距离
        for(int u=1; u<=n; u++){
            if(g[t][u] < INF && dist[t] + g[t][u] < dist[u]){
                dist[u] = dist[t]+g[t][u];
            }
        }
    }
    if(dist[n] >= INF)  // 不存在到n的路径
        return -1;
    return dist[n];
}
```

##### `朴素Dijkstra`-[Acwing849. Dijkstra求最短路](/acwing/Section%203/6_%E6%9C%B4%E7%B4%A0Dijkstra%E6%B1%82%E6%9C%80%E7%9F%AD%E8%B7%AF.cpp)完整实现

```CPP
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
        // 用当前最短 t 更新其它not set的结点dist
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
```


#### 2. 堆优化Dijkstra算法
> 稀疏图 => 邻接表
> 
> 用`heap`(`priority_queue`)优化"找到当前最近的点"这一步, 复杂度从`O(n)`变为`O(logn)`
> 
> 整体复杂度`O(mlogn)`

##### `堆优化Dijkstra`-[Acwing850. Dijkstra求最短路II](/acwing/Section%203/6_%E5%A0%86%E4%BC%98%E5%8C%96Dijkstra%E6%B1%82%E6%9C%80%E7%9F%AD%E8%B7%AF.cpp)完整实现

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