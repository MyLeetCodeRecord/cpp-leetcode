### 最小生成树
- Prim(选点法)
  - 朴素版Prim  `O(n^2)`
  - 堆优化版Prim  `O(mlogn)`
- Kruskal(选边法)   `O(mlogm)`

> 最小生成树的场景: n座城市, 铺设公路使所有城市连通, 最短铺设距离是多少?

#### 2. Kruskal(选边法)

> 思想: 选`n-1`条最短边, 过程中保证不出现环路
> - 将`m`条边从小到大排序 ➡️ sort复杂度`O(mlogm)`
> - 枚举每条边`{a, b, w}`, 如果当前`a`和`b`不连通, 则将这条边加入最小生成树 ➡️ 并查集单次操作复杂度`O(1)`

```CPP
#include <cstdio>
#include <algorithm>
using namespace std;

struct Edge{
    int a, b, w;
    // 复习一下重载运算符
    bool operator< (const Edge& e){
        return w < e.w;
    }
};
const int N = 100010;
Edge edges[2*N];
int father[N];
int n, m;

// 并查集
void init(int n){
    for(int i=1; i<=n; i++)
        father[i] = i;
}
int find(int u){
    if(u!=father[u]){
        father[u] = find(father[u]);
    }
    return father[u];
}
void union2(int u, int v){
    int fu = find(u);
    int fv = find(v);
    father[fu] = fv;
}
bool inSame(int u, int v){
    int fu = find(u);
    int fv = find(v);
    return fu==fv;
}
int main(){
    scanf("%d %d", &n, &m);
    init(n);
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].w);
    }
    sort(edges, edges+m);
    int ans = 0;
    int cnt = 0;    // 并查集(最小生成树)内的边数
    for(int i=0; i<m; i++){
        Edge e = edges[i];
        // 如果目前这条边的两个端点目前还不连通
        if(inSame(e.a, e.b)==false){
            ans += e.w;
            union2(e.a, e.b);
            cnt++;
        }
    }
    // n个节点的树有n-1条边
    if(cnt < n-1)
        puts("impossible");
    else
        printf("%d\n", ans);
    return 0;
}
```