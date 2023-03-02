### BFS

#### 1. [Acwing1562. 微博转发](https://www.acwing.com/problem/content/1564/)

> 转发层数的限制即`BFS`的`layer`限制, 另外再练习一下邻接表存储

```CPP
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int h[N], e[N], nxt[N], idx = 0;
int n, l, k;

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int BFS(int st, int limit){
    int ans = 0;
    queue<int> q;
    q.push(st);
    vector<bool> visited(n+1, false);
    visited[st] = true;
    int layer = 0;
    while(!q.empty()){
        if(layer == limit)
            break;
        int _sz = q.size();
        for(int i=0; i<_sz; i++){
            int cur = q.front();
            q.pop();
            for(int j=h[cur]; j!=-1; j=nxt[j]){
                int id = e[j];
                if(!visited[id]){
                    visited[id] = true;
                    q.push(id);
                    ans++;
                }
            }
        }
        layer++;
    }
    return ans;
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &l);
    for(int b=1; b<=n; b++){
        int m, a;
        scanf("%d", &m);
        for(int j=0; j<m; j++){
            scanf("%d", &a);
            insert(a, b);
        }
    }
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        int q;
        scanf("%d", &q);
        printf("%d\n", BFS(q, l));
    }
    return 0;
}
```


#### 2. [Acwing844. 走迷宫](/acwing/Section%203/2_%E8%B5%B0%E8%BF%B7%E5%AE%AB.cpp)


#### 3. [Acwing845. 八数码](/acwing/Section%203/2_%E5%85%AB%E6%95%B0%E7%A0%81.cpp)