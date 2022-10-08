#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2010, M = 10010;

int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N];    // dist[u]: 当前1->u的最短距离
bool inQ[N];    // inQ[u]: 记录u是否在queue中, queue没有find()
int cnt[N];     // cnt[u]: 如果大于N等于N表示存在负环

void add(int a, int b, int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}
bool spfa(){
    queue<int> q;
    // 不再是求1->n的最短路, 而是全局有没有负环
    for (int i = 1; i <= n; i ++){
        inQ[i] = true;
        q.push(i);
    }
    while (q.size()){
        int t = q.front();
        q.pop();
        inQ[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n)
                    return true;
                if (!inQ[j]){
                    q.push(j);
                    inQ[j] = true;
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m -- ){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    if (spfa())
        puts("Yes");
    else
        puts("No");
    return 0;
}