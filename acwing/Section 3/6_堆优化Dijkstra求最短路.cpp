#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

/* Dijkstra - 稀疏图 - 邻接表 */
typedef pair<int, int> PII;  // {距离, 结点编号}, 从而令优先队列使用距离排序

const int N = 150010;  // 稀疏图 => 邻接表
int n, m;
int h[N], e[N], nxt[N], w[N], idx=0;
int dist[N];    // dist[u]: 当前1->u的最短距离
bool st[N];

void insert(int a, int b, int d){
    e[idx] = b;
    w[idx] = d;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int Dijkstra(){
    memset(dist, 0x3f, sizeof dist);    // memset: 将每个字节替换为某个数值
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    pq.push({0, 1});

    while(!pq.empty()){
        int t = pq.top().second;
        pq.pop();
        if(st[t] == true)   // 冗余存储, 可能有过期边
            continue;
        st[t] = true;
        for(int i=h[t]; i!=-1; i=nxt[i]){
            int j = e[i];
            if(!st[j] && dist[t]+w[i] < dist[j]){
                dist[j] = dist[t] + w[i];
                pq.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        insert(a, b, d);
    }
    cout<<Dijkstra()<<endl;
    return 0;
}