#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct Edge{
    int a, b, w;
};

const int N = 510, M = 10010;
int n, m, k;
Edge edges[M];
int dist[N], backup[N];

void bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 题目限制了边数, 来应对负环, 没有负环可以执行N次
    for(int i=0; i<k; i++){
        memcpy(backup, dist, sizeof dist);
        for(int j=0; j<m; j++){
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], backup[e.a]+e.w);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        printf("%d\n", dist[n]);
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }
    bellman_ford();
    return 0;
}