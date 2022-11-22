#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010, M = N * 2;    // 注意这里是无向图, 要存双向两条边, 所以M一定要开大点
int h[N], e[M], nxt[M], idx=0;
bool visited[N];
int n;

// 头插法 a->b的有向边
void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}

int ans = N;    // 全局answer, 不要在这里初始化成n, 这里n还是0...

// 返回值: 以u为root的子树节点数量
int DFS(int u){
    visited[u] = true;
    int sum = 1;
    int res = 0;    // 删除u得到的三个连通块size的最大值
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        if(!visited[j]){
            int child_size = DFS(j);
            res = max(res, child_size);
            sum += child_size;
        }
    }
    res = max(res, n-sum);
    ans = min(ans, res);
    return sum;
}
int main(){
    memset(h, -1, sizeof h);    
    cin>>n;
    // n个节点的树有n-1条边
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    // 并没有真的"删除"一个节点
    // 而是在dfs到某一节点时, 借助它的"所有子树size"和"n-∑子树size"求得到ans
    // 所以不需要遍历所有
    DFS(1);
    cout<<ans<<endl;
    return 0;
}