#### 树状DP

##### [Acwing285. 没有上司的舞会](https://www.acwing.com/problem/content/287/)
##### (1) 思路
> **状态表示**
> 
> 每个树🌲节点有两个状态, `0`表示不去, `1`表示去
>
> - `dp[u][0]`: 以`u`为根结点的子树中, **不选`u`**能达到的最大开心度
> 
> - `dp[u][1]`: 以`u`为根结点的子树中, **选择`u`**能达到的最大开心度

> **状态转移**
> 
> 转移应该是在父节点和它所有子节点之间发生的
> 
> 上司`i`不去` dp[i][0]` => 对于每个下属`j`, 下属可去`dp[j][0]` or 可不去`dp[j][1]`
> 
> 上司`i`去了` dp[i][1]` => 对于每个下属`j`, 下属不去`dp[j][0]`
>
> 并且`dp[i][0/1]`的转移应该是从底层向`root`, 是符合`DFS`的递归顺序的

```CPP
状态转移方程
dp[i][0] = sum{ max(dp[child][0], dp[child][1]) , for all children of i}
dp[i][1] = happy[i] + sum{ dp[child][0] }
```

##### (2) 实现

> 先复习一下[图的邻接表存储](/acwing/Section%203/acwing%20-%20%E5%9B%BE%E7%9A%84%E9%82%BB%E6%8E%A5%E8%A1%A8%E5%AD%98%E5%82%A8.md), 并注意边的方向是**上司指向下属**
>
> 并且要注意区分使用`idx`和`value`

```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/* 用邻接表存储图, 注意哪些下标使用idx, 哪些下标使用节点ID */

const int N = 6010;
int happy[N];
bool has_father[n+1];
int dp[N][2];

// 邻接表存储树
int h[N], e[N], nxt[N], idx=0;
void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
void DFS(int u){
    // 基础项
    dp[u][0] = 0;           // 不选当前
    dp[u][1] = happy[u];    // 选当前
    // 状态转移
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        DFS(j);
        dp[u][0] += max(dp[j][0], dp[j][1]);
        dp[u][1] += dp[j][0];
    }
}
int main(){
    memset(h, -1, sizeof h);
    int n;
    scanf("%d", &n);
    // 注意编号从1 ~ n
    for(int i=1; i<=n; i++){
        scanf("%d", &happy[i]);
    }
    // tree的边数=节点数-1
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(b, a);
        has_father[a] = true;
    }
    // 找到树的root
    int root = 1;
    while(has_father[root]){
        root++;
    }
    DFS(root);
    cout<<max(dp[root][0], dp[root][1])<<endl;
    return 0;
}
```