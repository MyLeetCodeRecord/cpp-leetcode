##### 1. 排列数字
```CPP
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
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
    vector<bool> visited(n, false);
    backtrack(n, visited);
    for(vector<int> path: ans){
        for(int i: path){
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
```

##### 2. N皇后
```CPP
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
vector<int> path;

bool isLegal(int row, int col){
    for(int i=0; i<row; i++){
        // 检查列(visited[]和列检查只需要一个)
        if(path[i]==col)
            return false;
        // 检查对角线
        if(abs(path[i]-col)==abs(i-row))
            return false;
    }
    return true;
}
void backtrack(int n, vector<bool> &visited){
    if(path.size()==n){
        ans.push_back(path);
        return ;
    }
    for(int i=0; i<n; i++){
        if(!visited[i] && isLegal(path.size(), i)){
            path.push_back(i);
            backtrack(n, visited);
            path.pop_back();
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    vector<bool> visited(n+1, false);
    backtrack(n, visited);
    for(vector<int> pth: ans){
        for(int i=0; i<pth.size(); i++){
            for(int j=0; j<n; j++){
                if(j==pth[i])
                    printf("Q");
                else
                    printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
```

##### 3. 走迷宫
```CPP
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int g[N][N];
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n, m;

int BFS(){
    queue<PII> q;
    q.push({0, 0});
    g[0][0] = -1;
    int layer = 0;
    while(!q.empty()){
        layer++;
        int _size = q.size();
        for(int i=0; i<_size; i++){
            PII cur = q.front();
            q.pop();
            for(int d=0; d<4; d++){
                int nextX = cur.first + direction[d][0];
                int nextY = cur.second + direction[d][1];
                if(nextX==n-1 && nextY==m-1){
                    return layer;
                }
                if(nextX>=0 && nextX<n && nextY>=0 && nextY<m && g[nextX][nextY]==0){
                    q.push({nextX, nextY});
                    g[nextX][nextY] = -1;
                }
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &g[i][j]);
        }
    }
    cout<<BFS()<<endl;
    return 0;
}
```

##### 4. 八数码
```CPP
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

string start = "";
string dest = "12345678x";
unordered_map<string, int> dist;    // 注意这道题不能直接用二维坐标对应的visited[][]来标记是否使用过, 因为交换可以发生在相同位置

int BFS(){
    dist[start] = 0;
    queue<string> q;
    q.push(start);
    while(!q.empty()){
        string cur = q.front();
        q.pop();
        if(cur == dest)
            return dist[cur];
        int k = cur.find('x');
        int x = k / 3;
        int y = k % 3;
        for(int i=0; i<4; i++){
            int nextX = x + direction[i][0];
            int nextY = y + direction[i][1];
            if(nextX>=0 && nextX<3 && nextY>=0 && nextY<3){
                string nextState = cur;
                swap(nextState[nextX*3+nextY], nextState[k]);
                // BFS还没有访问过
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
    start = "";
    dest = "12345678x";
    for(int i=0; i<9; i++){
        char ch;
        cin>>ch;
        start += ch;
    }
    cout<<BFS()<<endl;
    return 0;
}
```

##### 5. 树的重心
> 删除节点`node`后分成的几个连通块分别是: `node`的每个子树 & 其它所有节点组成的连通块(该连通块的`size = n - ∑size(subtree)`)
> 
> 因此这道题应该用`DFS`求得子树`size`, 并在过程中求当前节点划分的`child+1`个连通块的节点数最大值

```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int h[N], e[2*N], nxt[2*N], idx=0;
int n;

bool visited[N];    // 这里是按无向图存储的, 所以需要防止重复遍历

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}

int res = N;    // 全局答案

int DFS(int u){
    visited[u] = true;
    int ans = 0;
    int sum = 1;
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        // 没有访问过的才是子树, 否则是祖先
        if(!visited[j]){
            int child_size = DFS(j);
            ans = max(ans, child_size);
            sum += child_size;
        }
    }
    ans = max(ans, n-sum);
    res = min(res, ans);
    return sum;
}
int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    // n个节点的树有n-1条边
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    DFS(1);
    cout<<res<<endl;
    return 0;
}
```

##### 6. 图中点的层次
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010;
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
    int layer = 0;
    while(!q.empty()){
        // 如果不选择每次遍历完整层, 就用d[cur]+1来传递
        int _size = q.size();
        for(int a=0; a<_size; a++){
            int cur = q.front();
            for(int i=h[cur]; i!=-1; i=nxt[i]){
                int j = e[i];
                if(d[j]==-1){
                    q.push(j);
                    d[j] = layer;
                }
            }
        }
        layer++;
    }
    return d[n];
}
int main(){
    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);
    int n, m;
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
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int h[N], e[N], nxt[N], idx=0;
int indegree[N];
int n, m;

void insert(int a, int b){
    indegree[b]++;
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
vector<int> Topo_BFS(){
    vector<int> topo;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for(int i=h[cur]; i!=-1; i=nxt[i]){
            int j = e[i];
            indegree[j]--;
            if(indegree[j] == 0){
                q.push(j);
            }
        }
    }
    return topo;
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
    }
    vector<int> ans = Topo_BFS();
    if((int)ans.size()==n){
        for(int e: ans)
            printf("%d ", e);
        printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}
```