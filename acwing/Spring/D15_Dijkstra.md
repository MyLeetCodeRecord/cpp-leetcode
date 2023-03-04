### Dijkstra


#### 1. [Acwing 1488. 最短距离](https://www.acwing.com/problem/content/1490/)- 带超级源点的Dijkstra

> 多个起点, 多个终点 => ➕一个超级源点的`Dijkstra`算法
>
> ![多源Dijkstra](/appendix/acwing-%E5%A4%9A%E6%BA%90Dijkstra.png)
>
> - 加一个超级源点`0`, 加指向`K`个起点(超市)的权值为0的有向边
> 
> - 节点数`10^5` => 堆优化的`Dijkstra`算法

```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int h[N], e[3*N], nxt[3*N], w[3*N], idx=0;
int dist[N];
bool st[N];
int n, m, k, q;

void insert(int a, int b, int weight){
    e[idx] = b;
    w[idx] = weight;
    nxt[idx] = h[a];
    h[a] = idx++;
}
void Dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        PII t = pq.top();
        pq.pop();
        int dis = t.first;
        int ver = t.second;
        if(st[ver] == true)
            continue;
        st[ver] = true;
        for(int i=h[ver]; i!=-1; i=nxt[i]){
            int j = e[i];
            if(!st[j] && dist[ver]+w[i] < dist[j]){
                dist[j] = dist[ver] + w[i];
                pq.push({dist[j], j});
            }
        }
    }
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        insert(a, b, c);
        insert(b, a, c);
    }
    scanf("%d", &k);
    int shop, query;
    for(int i=0; i<k; i++){
        scanf("%d", &shop);
        insert(0, shop, 0);
    }
    Dijkstra();
    scanf("%d", &q);
    for(int i=0; i<q; i++){
        scanf("%d", &query);
        cout<<dist[query]<<endl;
    }
    return 0;
}
```

#### 2. [Acwing849. Dijkstra求最短路I](/acwing/Section%203/6_%E6%9C%B4%E7%B4%A0Dijkstra%E6%B1%82%E6%9C%80%E7%9F%AD%E8%B7%AF.cpp)



#### 3. [Acwing850. Dijkstra求最短路II](/acwing/Section%203/6_%E6%9C%B4%E7%B4%A0Dijkstra%E6%B1%82%E6%9C%80%E7%9F%AD%E8%B7%AF.cpp)