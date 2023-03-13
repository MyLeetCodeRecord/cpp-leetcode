### 最小生成树
- Prim(选点法)
  - 朴素版Prim  `O(n^2)`
  - 堆优化版Prim  `O(mlogn)`
- Kruskal(选边法)   `O(mlogm)`

> 最小生成树的场景: n座城市, 铺设公路使所有城市连通, 最短铺设距离是多少?

#### 1. 朴素Prim(选点法)

> 思想: 每次选一个距离「集合」最近的点`t`, 用`t`更新其它点到「集合」的距离
>
> 「集合」指当前已经加入生成树的点的集合
> 
> ![Prim](/appendix/Prim.png)
>
> ![Prim-2](/appendix/Prim-2.png)

```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

int Prim(){
    memset(dist, 0x3f, sizeof dist);
    int ans = 0;
    for(int i=0; i<n; i++){
        // 选一个到「集合」最近的点 t
        int t = -1;
        for(int j=1; j<=n; j++){
            if(!st[j] && (t==-1 || dist[j]<dist[t]))
                t = j;
        }
        // 不连通则提前返回, 注意第一个点除外(i==0)
        if(i!=0 && dist[t]==0x3f3f3f3f)
            return 0x3f3f3f3f;
        // dist[t]即为 t 加入集合(生成树)所使用的边
        if(i!=0)
            ans += dist[t];
        for(int j=1; j<=n; j++){
            dist[j] = min(dist[j], g[t][j]);
        }
        st[t] = true;
    }
    return ans;
}
int main(){
    scanf("%d %d", &n, &m);
    memset(g, 0x3f, sizeof g);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int ans = Prim();
    if(ans == 0x3f3f3f3f)
        puts("impossible");
    else
        printf("%d\n", ans);
    return 0;
}
```