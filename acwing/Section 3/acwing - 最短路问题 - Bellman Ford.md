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


#### 1. Bellman Ford算法

##### (1) 算法原理
> ![BF算法](/appendix/acwing-%E6%9C%80%E7%9F%AD%E8%B7%AF-BF%E7%AE%97%E6%B3%95.png)
> 
> 外层循环`n`次, 内层循环所有边`{a, b, w}`, 更新距离`dist[b] = min(dist[b], dist[a] + W_ab)`
>
> 显而易见, 算法复杂度为`O(nm)`
> 
> 对于存在**负权环路**的图, `BF算法`可能无法求得最短路径(**负权无环是可以的, 或者限制边的数量不超过K**)
> 
> 与`Dijkstra算法`相比, `BF算法`可以处理有负权边(但无环)的情况

```CPP
struct Edge{
    int a, b, w;
};
const int N = 510, M = 10010;
Edge edges[M];
int dist[N], backup[N];
```


##### (2) N次更新
> 防止用当前轮次新更新的`dist[e.a]`更新`dist[e.b]`

```CPP
for(int i=0; i<n; i++){
    memcpy(backup, dist, sizeof dist);
    for(int j=0; j<m; j++){
        auto e = edges[j];
        dist[e.b] = min(dist[e.b], backup[e.a]+e.w);
    }
}
```


##### `Bellman Ford`完整实现
```CPP
// Acwing853的场景是允许有负环, 但限制了最多K条边
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 10010;
struct Edge{
    int a, b, w;
};
Edge edges[M];
int dist[N], backup[N];

int n, m, k;

void BellmanFord(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 边数限制, K次循环
    for(int i=0; i<k;i++){
        // 备份, 避免串联
        memcpy(backup, dist, sizeof dist);
        // 遍历所有边
        for(int j=0; j<m; j++){
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], backup[e.a]+e.w);
        }
    }
    if(dist[n] > 0x3f3f3f3f - N*M)
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

