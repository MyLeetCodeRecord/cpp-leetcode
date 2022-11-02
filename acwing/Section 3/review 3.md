##### 1. 树的重心
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[2*N], nxt[2*N], idx=0;
bool visited[N];
int n;
int ans = N;

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int DFS(int u){
    visited[u] = true;
    int cnt = 1;
    int res = 0;
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        if(!visited[j]){
            int child_size = DFS(j);
            res = max(res, child_size);
            cnt += child_size;
        }
    }
    res = max(res, n-cnt);  // 删掉i, 两个连通块节点数的更大值
    ans = min(ans, res);    // 更新全局最优解
    return cnt;
}
int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    DFS(1);
    cout<<ans<<endl;
    return 0;
}
```