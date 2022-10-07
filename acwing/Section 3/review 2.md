#### DFS / backtrack
##### 1. 排列数字
```CPP
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > ans;
vector<int> path;

void backtrack(int n, vector<bool> &visited){
    if(path.size()==n){
        ans.push_back(path);
        return ;
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            path.push_back(i);
            backtrack(n, visited);
            visited[i] = false;
            path.pop_back();
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    vector<bool> visited(n+1, false);   // 注意对齐
    backtrack(n, visited);
    for(vector<int> pth: ans){
        for(int x: pth){
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}
```

##### 2. n皇后问题
```CPP
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
vector<int> path;
int n;
bool isLegal(int row, int col){
    for(int i=0; i<path.size(); i++){
        if(path[i]==col)
            return false;
        if(row-i == abs(path[i]-col))
            return false;
    }
    return true;
}
void backtrack(int n, int cur){
    if(path.size() == n){
        ans.push_back(path);
        return ;
    }
    for(int i=0; i<n; i++){
        if(isLegal(cur, i)){
            path.push_back(i);
            backtrack(n, cur+1);
            path.pop_back();
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    backtrack(n, 0);
    for(vector<int> pth: ans){
        // 输出一个方案
        for(int i=0; i<pth.size(); i++){
            // 输出一行
            for(int j=0; j<n; j++){
                if(j!=pth[i])
                    printf(".");
                else
                    printf("Q");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
```

#### BFS
##### 3. 走迷宫
```CPP
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int g[N][N];
int d[N][N];
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n, m;

int BFS(){
    queue<PII> q;
    q.push({0, 0}); // 别忘了初始化起点
    d[0][0] = 0;
    while(!q.empty()){
        PII cur = q.front();
        int curX = cur.first;
        int curY = cur.second;
        q.pop();
        for(int i=0; i<4; i++){
            int nextX = curX + direction[i][0];
            int nextY = curY + direction[i][1];
            if(nextX>=0 && nextX<n && nextY>=0 && nextY<m 
                && g[nextX][nextY]==0 && d[nextX][nextY]==-1){
                d[nextX][nextY] = d[curX][curY] + 1;
                q.push({nextX, nextY});
            }
        }
    }
    return d[n-1][m-1];
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &g[i][j]);
        }
    }
    memset(d, -1, sizeof d);
    cout<<BFS()<<endl;
    return 0;
}
```

##### 4. 八数码
```CPP
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;

unordered_map<string, int> dist;
int direction[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

int BFS(string start, string dest){
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        string cur = q.front();
        q.pop();
        if(cur==dest)
            return dist[dest];
        int k = cur.find('x');
        int x = k / 3;
        int y = k % 3;
        for(int i=0; i<4; i++){
            int nextX = x + direction[i][0];
            int nextY = y + direction[i][1];
            if(nextX>=0 && nextX<3 && nextY>=0 && nextY<3){
                string nextState = cur;
                swap(nextState[nextX*3+nextY], nextState[k]);
                if(dist.find(nextState) == dist.end()){
                    dist[nextState] = dist[cur] + 1;
                    q.push(nextState);
                }
            }
        }
    }
    return -1;
}
int main(){
    string start = "";
    string dest = "12345678x";
    for(int i=0; i<9; i++){
        char ch;
        cin>>ch;
        start += ch;
    }
    cout<<BFS(start, dest)<<endl;
    return 0;
}
```

##### 5. 树的重心 (DFS)
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int n;
int h[N], e[2*N], nxt[2*N], idx=0;
bool visited[N];    // DFS需要存双向边, 遍历顺序可能存在重复访问

int ans = N;

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int DFS(int u){
    visited[u] = true;
    int sum = 1;
    int res = 0;
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        if(!visited[j]){
            int child_size = DFS(j);
            res = max(res, child_size);
            sum += child_size;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);   // DFS需要存双向图
    }
    DFS(1);
    cout<<ans<<endl;
    return 0;
}
```

##### 6. 图中点的层次
```CPP
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], nxt[N], idx=0;
int d[N];

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int BFS(int n){
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=h[cur]; i!=-1; i=nxt[i]){
            int j = e[i];
            if(d[j] == -1){
                d[j] = d[cur] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}
int main(){
    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
    }
    cout<<BFS(n)<<endl;
    return 0;
}
```

##### 7. 拓扑序列
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], nxt[N], idx=0;
int indegree[N];

vector<int> ans;

void insert(int a, int b){
    indegree[b]++;
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
void Topo_BFS(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(int i=h[cur]; i!=-1; i=nxt[i]){
            int j = e[i];
            indegree[j]--;
            if(indegree[j]==0){
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
    Topo_BFS();
    if(ans.size()==n){
        for(int element: ans)
            printf("%d ", element);
        printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}
```

##### 8. 朴素Dijkstra
> 朴素Dijkstra算法适合`稠密图`, 因此用邻接矩阵存储
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1e6;
const int N = 510;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int Dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 循环n次
    for(int i=0; i<n; i++){
        int t = -1;
        for(int u=1; u<=n; u++){
            if(!st[u] && (t==-1 || dist[u] < dist[t])){
                t = u;
            }
        }
        st[t] = true;
        for(int u=1; u<=n; u++){
            if(!st[u] && g[t][u]<INF && dist[u] > dist[t] + g[t][u]){
                dist[u] = dist[t] + g[t][u];
            }
        }
    }
    return (dist[n] < INF) ? dist[n] : -1;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++){
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        g[a][b] = min(g[a][b], d);  // 如果有重边, 只保留最短的一条
    }
    cout<<Dijkstra()<<endl;
    return 0;
}
```

##### 9. 堆优化Dijkstra算法
> 堆优化Dijkstra算法适合`稀疏图`, 所以用邻接表方式存储
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 150010;
int n, m;
int h[N], e[2*N], nxt[2*N], idx=0;
int w[N];
int dist[N];
bool st[N];

void insert(int a, int b, int d){
    w[idx] = d;
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int Dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    pq.push({0, 1});
    
    while(!pq.empty()){
        PII cur = pq.top();
        pq.pop();
        int curDist = cur.first;
        int curNode = cur.second;
        if(st[curNode] == true)
            continue;
        st[curNode] = true;
        for(int i=h[curNode]; i!=-1; i=nxt[i]){
            int j = e[i];
            if(curDist + w[i] < dist[j]){
                dist[j] = curDist + w[i];
                pq.push({dist[j], j});
            }
        }
    }
    return (dist[n] < 0x3f3f3f3f) ? dist[n] : -1;
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
```