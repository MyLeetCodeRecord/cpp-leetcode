#### 染色法判定二分图
##### 1. [二分图的特性](https://baike.baidu.com/item/%E4%BA%8C%E5%88%86%E5%9B%BE/9089095?fr=aladdin)
> - 无向图中, 顶点可分割为两个互不相交的子集`(A,B)`, 并且图中的每条边`(i，j)`所关联的两个顶点`i`和`j`分别属于这两个不同的顶点集
> - 无向图为二分图的**充分必要条件**是, 图G至少有两个顶点, 图中所有回路的长度均为偶数
> 
> ![二分图](/appendix/acwing-%E4%BA%8C%E5%88%86%E5%9B%BE.png)


##### 2. 染色法
> 没有奇数环, 每个点不会既是红色又是蓝色
```CPP
bool DFS(int u, int c){

}
```

> 对于可能含多个连通块的图, 枚举每个未染色节点, 对它所在连通块DFS染色
```CPP
for(int i=1; i<=n; i++){
    if(i未染色){
        if(DFS(i, 红)==false)
            return false;
    }
}
```

##### 完整实现
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[2*N], nxt[2*N], idx=0;
int color[N];

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
bool DFS(int u, int c){
    color[u] = c;
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        // 染色冲突
        if(color[j] == c)
            return false;
        // color[j]==0可以表示!visited
        if(color[j] == 0 && DFS(j, -c) == false)
            return false;
    }
    return true;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    bool bipartite = true;
    for(int i=1; i<=n; i++){
        if(color[i]==0){
            // 发生染色冲突
            if(DFS(i, 1)==false){
                bipartite = false;
                break;
            }
        }
    }
    if(bipartite)   
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
```