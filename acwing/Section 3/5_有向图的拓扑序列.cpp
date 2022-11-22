#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/* 有向图的拓扑序列是BFS的一个应用
 * - 有向无环图(拓扑图)一定存在拓扑序列
 * - 起点一定是入度 = 0的点
 * 宽度优先搜索 BFS
 * 入度为0的点 => 后续不会有边指向它 => 加入队列
 */

const int N = 100010;
int h[N], e[N], nxt[N], idx;
int indegree[N];
vector<int> ans;    // 出队顺序就是拓扑序
int n, m;

void insert(int a, int b){
    indegree[b]++;
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
void TopoSeq(){
    queue<int> q;
    // 初始化: 加入入度为0的点
    for(int i=1; i<=n; i++){
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        ans.push_back(cur);
        q.pop();
        for(int i=h[cur]; i!=-1; i=nxt[i]){
            int j = e[i];
            indegree[j]--;
            // 度为0的点入队
            if(indegree[j] == 0){
                q.push(j);
            }
        }
    }
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
    }
    TopoSeq();
    if(ans.size()==n){
        for(int element: ans){
            printf("%d ", element);
        }
        printf("\n");
    }
    else{
        printf("-1");
    }
    return 0;
}
