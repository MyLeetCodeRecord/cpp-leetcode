#### 树状DP

##### [Acwing285. 没有上司的舞会](https://www.acwing.com/problem/content/287/)
##### (1) 思路
> 每个树🌲节点有两个状态, `0`表示不去, `1`表示去
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

> 先复习一下[图的邻接表存储](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/acwing/Section%203/acwing%20-%20%E5%9B%BE%E7%9A%84%E9%82%BB%E6%8E%A5%E8%A1%A8%E5%AD%98%E5%82%A8.md), 并注意边的方向是**上司指向下属**
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
int h[N], e[N], nxt[N], idx=0;
int dp[N][2];

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
void DFS(int root){
    // 基础项
    dp[root][0] = 0;
    dp[root][1] = happy[root];
    // 状态转移
    for(int i=h[root]; i!=-1; i=nxt[i]){
        int j = e[i];
        DFS(j);
        dp[root][0] += max(dp[j][0], dp[j][1]);
        dp[root][1] += dp[j][0];
    }
}
int main(){
    memset(h, -1, sizeof h);
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &happy[i]);
    bool has_father[n+1];
    memset(has_father, false, sizeof has_father);
    // tree的边数=节点数-1
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(b, a);
        has_father[a] = true;
    }
    int root = 1;
    while(has_father[root]){
        root++;
    }
    DFS(root);
    printf("%d\n", max(dp[root][0], dp[root][1]));
    return 0;
}
```