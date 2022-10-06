#### 有向图的拓扑序列 (BFS)
> 相关题目:
> - [LC207. 课程表](/workspace/207.%E8%AF%BE%E7%A8%8B%E8%A1%A8.cpp): 检查存在性, 即`ans.size()==n`
> 
> - [LC210. 课程表II](/workspace/210.%E8%AF%BE%E7%A8%8B%E8%A1%A8-ii.cpp): 返回可能的拓扑序列, 即`ans`本身
> 
> 补充: Leetcode中的邻接表
##### 1. 思路
> 有向图的拓扑序列是[`BFS`](/acwing/Section%203/4_%E5%9B%BE%E4%B8%AD%E7%82%B9%E7%9A%84%E5%B1%82%E6%AC%A1_BFS.cpp)的一个应用
> 
> - 有向无环图(`DAG`, 拓扑图)一定存在拓扑序列
> 
> - 起点一定是`indegree = 0`的点

> **`BFS`**
> 
> 入度为0的点 => 后续不会有边指向它 => 加入队列
>
> 出队顺序就是一个合法的拓扑序列

##### 2. 存储结构
> `h[N]`, `e[N]`, `nxt[N]`: **邻接表**存储图
> 
> `indegree[N]`: 需要记录`n`个点的出度, 遍历一条边后, 将终点的入度减1, 并且`indegree[i]`的初始化在insert时完成。
```CPP
int h[N], e[N], nxt[N], idx;    // 邻接表存储
int indegree[N];

memset(h, -1, sizeof h);
```

##### 3. 完整实现
```CPP
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[N], nxt[N], idx;    // 邻接表存储
int indegree[N];
vector<int> ans;    // 出队顺序就是拓扑序
int n, m;

// 有向图中插入a->b, 如果是无向图就插入a->b和b->a
void insert(int a, int b){
    indegree[b]++;
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
void TopoSeq(){
    queue<int> q;

    // queue的初始化: 加入入度为0的点
    for(int i=1; i<=n; i++){
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        ans.push_back(cur);     // 记录出队列顺序
        q.pop();
        for(int i=h[cur]; i!=-1; i=nxt[i]){
            int j = e[i];
            indegree[j]--;      // "删除"这条边
            if(indegree[j] == 0){
                q.push(j);
            }
        }
    }
}
int main(){
    memset(h, -1, sizeof h);    // !!! 邻接表实现: 别忘了
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
    }
    TopoSeq();
    if(ans.size()==n){
        for(int element: ans)
            printf("%d ", element);
        printf("\n");
    }
    else
        printf("-1");
    return 0;
}
```