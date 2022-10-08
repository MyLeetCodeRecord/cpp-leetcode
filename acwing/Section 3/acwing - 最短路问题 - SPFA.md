### 最短路问题
- 第一类: 单源最短路
  - 所有边权都是正数
      - 朴素Dijkstra算法(稠密图)  `O(n^2)`
      - 堆优化Dijkstra算法(稀疏图)  `O(mlogn)`
  - 存在负权边
      - **Bellman-Ford**  `O(nm)`, 允许有负权边, 但不能有负权环
      - SPFA  `O(m)`, 最坏`O(nm)`
- 第二类: 多源汇最短路
  - Floyd算法  `O(n^3)`


```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 100010;  // 稀疏图 => 邻接表
int n, m;
int h[N], e[N], nxt[N], w[N], idx=0;
int dist[N];    // dist[u]: 当前1->u的最短距离
bool st[N];     // st[u]: 标记u是否在queue中

void insert(int a, int b, int d){
    e[idx] = b;
    w[idx] = d;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int SPFA(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        st[cur] = false;
        for(int i=h[cur]; i!=-1; i=nxt[i]){
            int j = e[i];
            if(dist[j] > dist[cur] + w[i]){
                dist[j] = dist[cur] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    if(dist[n]<0x3f3f3f3f)
        printf("%d\n", dist[n]);
    else
        printf("impossible\n");
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        insert(a, b, d);
    }
    cout<<SPFA()<<endl;
    return 0;
}
```