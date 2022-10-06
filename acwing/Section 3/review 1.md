##### 1. 树的重心(DFS)
```CPP
const int N = 100010;
int n;
int h[N], e[2*N], nxt[2*N], idx=0;  // 要注意边的数量 M 的范围
bool visited[N];

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
        if(visited[j]==false){
            int childSize = DFS(j);
            res = max(res, childSize);
            sum += childSize;
        }
    }
    res = max(res, n-sum);
    ans = min(ans, res);
    return sum;
}
int main(){
    memset(h, -1, sizeof h);    // !!!
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);   // 无向图
    }
    DFS(1);
    cout<<ans<<endl;
    return 0;
}
```

##### 2. 图中点的层次(BFS最短路径长度)
```CPP
const int N = 100010;
int n, m;
int h[N], e[N], nxt[N], idx=0;
int d[N];

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int BFS(){
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
    memset(h, -1, sizeof h);    // !!!
    memset(d, -1, sizeof d);    // d[i]==-1可以表示未曾访问过, BFS结束后表示不可达
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
    }
    cout<<BFS()<<endl;
    return 0;
}
```

##### 3. 拓扑序列(BFS)
```CPP
const int N = 100010;
int n, m;
int h[N], e[N], nxt[N], idx = 0;
int indegree[N];    // 入度
vector<int> ans;    // 出队顺序就是拓扑序

void insert(int a, int b){
    indegree[b]++;
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
void Topo_BFS(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
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
    memset(h, -1, sizeof h);    // !!!
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
        printf("-1");
    return 0;
}
```
