#### 图的邻接表存储

> - 树是**无环连通图**
> 
> - 无向图只需要存储两条表(两个方向)

##### 1. 存储结构
> 与[链表法哈希](/acwing/Section%202/acwing%20-%20%E5%93%88%E5%B8%8C%E8%A1%A8.md)的存储方式一致
>  
> `h[N]`: 一个节点(`a`)的所有出边组织成一个链表, 作为h[]的一个元素`h[a]`
> 
> `e[N]`, `nxt[N]`: 和`h[N]`共同存储edges。值为节点下标, 但数量上和节点没有明确的对应关系, 反而`idx=#edges`
> 
> `idx`: 作为新加入edge的索引下标, `最终数量=#edges`

```CPP
const int N = 100010;
int h[N], e[N], nxt[N], idx;  // h[N]: N个链表头
bool visited[N];

// 初始化
memset(h, -1, sizeof h);
```

##### 2. 加入有向边
> 与[模拟散列表](/acwing/Section%202/9_%E6%A8%A1%E6%8B%9F%E6%95%A3%E5%88%97%E8%A1%A8.cpp)的`insert(int x)`基本一致, 那里的hash值`h`就是这里的`a`
```CPP
void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];    // 头插法: b插到a的<出边链表>的头部
    h[a] = idx++;       // 更新h[a]指向新的链表头的位置 idx
}
```

##### 3. DFS
> 对于当前节点`u`, 遍历`u`的所有**出边**, 即遍历`h[u]`
> 
> 注意`i=h[u]`以及后续的`i=nxt[i]`索引到的是`idx`, 要在`e[i]`中找到节点真实值

```CPP
void DFS(int u){
    visited[u] = true;
    // ......
    for(int i=h[u]; i!=-1; i=nxt[i]){   // 遍历u的所有出边
        // 注意这里i只是指针, 不是真正的节点值, 而h[]中是用节点值索引的
        int j = e[i];
        if(!visited[j])
            DFS(j);
    }
}
```

##### 4. 完整实现
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/* 邻接表 
 * h[N]: 一个节点(a)的所有出边组织成一个链表, 作为h[]的一个元素h[a]
 * e[N], nxt[N]: 和h[N]共同存储edges。值为节点下标, 但数量上和节点没有明确的对应关系, 反而idx = #edges
 * idx: 作为edge的下标, 最终数量 = #edges
 */
const int N = 100010;
int h[N], e[N], nxt[N], idx;  // h[N]: N个链表头
bool visited[N];

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];  // 头插法: b插到a的链表头
    h[a] = idx++;
}
void DFS(int cur){
    visited[cur] = true;
    cout<<cur<<endl;
    for(int i=h[cur]; i!=-1; i=nxt[i]){ // 遍历u的所有出边
        int j = e[i];
        if(!visited[j])
            dfs(j);
    }
}
int main(){
    memset(h, -1, sizeof h);
    dfs(j);
    return 0;
}
```