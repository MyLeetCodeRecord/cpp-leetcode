##### 0. 染色法判断二分图

```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[2*N], nxt[2*N], idx=0;
int color[N];

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
bool DFS(int u, int c){
    color[u] = c;
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        // 染色冲突
        if(color[j] == c)
            return false;
        // color[j]==0可以表示!visited
        if(color[j] == 0 && DFS(j, -c) == false)
            return false;
    }
    return true;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    bool bipartite = true;
    for(int i=1; i<=n; i++){
        if(color[i]==0){
            // 发生染色冲突
            if(DFS(i, 1)==false){
                bipartite = false;
                break;
            }
        }
    }
    if(bipartite)   
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
```


##### 1. 排列数字 - DFS

```CPP
#include <cstdio>
#include <vector>
using namespace std;

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
    vector<bool> visited(n+1, false);
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
        // 列
        if(path[i]==col)
            return false;
        // 对角线
        if(abs(path[i]-col)==row-i)
            return false;
    }
    return true;
}
void backtrack(int n, int cur){
    if(path.size()==n){
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
int g[N][N], n, m;
int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

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
                int nextX = cur.first + directions[d][0];
                int nextY = cur.second + directions[d][1];
                if(nextX==n-1 && nextY==m-1)
                    return layer;
                if(nextX>=0 && nextX<n && nextY>=0 && nextY<m && g[nextX][nextY]==0){
                    q.push({nextX, nextY});
                    g[nextX][nextY] = -1;   // 标记已访问会减少重复搜索, 并且可以避免没有答案的情况
                }
            }
        }
    }
    return layer;
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
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int direction[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

string st = "";
string ed = "12345678x";
unordered_map<string, int> dist;

int BFS(){
    queue<string> q;
    q.push(st);
    dist[st] = 0;
    int layer = 0;
    while(!q.empty()){
        layer++;
        int _size = q.size();
        for(int i=0; i<_size; i++){
            string cur = q.front();
            q.pop();
            if(cur == ed)
                return dist[cur];
            int pos = cur.find('x');
            int x = pos / 3;
            int y = pos % 3;
            for(int d=0; d<4; d++){
                int nextX = x + direction[d][0];
                int nextY = y + direction[d][1];
                if(nextX>=0 && nextX<3 && nextY>=0 && nextY<3){
                    string nextState = cur;
                    swap(nextState[x*3+y], nextState[nextX*3+nextY]);
                    if(dist.find(nextState)==dist.end()){
                        q.push(nextState);
                        dist[nextState] = layer;
                    }
                }
            }
        }
    }
    return -1;
}
int main(){
    for(int i=0; i<9; i++){
        char ch;
        cin>>ch;
        st += ch;
    }
    cout<<BFS()<<endl;
    return 0;
}
```


##### 5. 树的重心

```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;

const int N = 100010;
int h[N], e[2*N], nxt[2*N], idx=0;
bool visited[N];
int n;

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int ans = INT_MAX;
int DFS(int u){
    visited[u] = true;
    int cnt = 1;
    int maxChild = 0;
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        if(!visited[j]){
            int child_size = DFS(j);
            cnt += child_size;
            maxChild = max(maxChild, child_size);
        }
    }
    ans = min(ans, max(maxChild, n-cnt));
    return cnt;
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    // 可以把tree单纯看作无向图, 随便找一个点DFS
    DFS(1);
    cout<<ans<<endl;
    return 0;
}
```


##### 6. 图中点的层次

```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int h[N], e[N], nxt[N], idx=0;
int n, m;
bool visited[N];

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int BFS(){
    queue<int> q;
    q.push(1);
    if(n==1)
        return 0;
    int layer = 0;
    while(!q.empty()){
        layer++;
        int _size = q.size();
        for(int i=0; i<_size; i++){
            int cur = q.front();
            q.pop();
            for(int i=h[cur]; i!=-1; i=nxt[i]){
                int j = e[i];
                if(j == n)
                    return layer;
                if(!visited[j]){
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return -1;
}
int main(){
    memset(h, -1, sizeof h);
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


##### 7. 有向图的拓扑序列

```CPP
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[N], nxt[N], idx=0;
int indegree[N];
int n, m;

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
    indegree[b]++;
}
vector<int> TopoBFS(){
    vector<int> ans;
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
            if(indegree[j]==0)
                q.push(j);
        }
    }
    return ans;
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        insert(x, y);
    }
    vector<int> ans = TopoBFS();
    if((int)ans.size() == n){
        for(int i: ans)
            printf("%d ", i);
        printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}
```