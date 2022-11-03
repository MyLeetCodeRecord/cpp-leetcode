##### 1. 石子合并
> `dp[i][j]`: 合并`i~j`堆石子
> 
> 状态转移: 找到使的`dp[i][j]`代价最小的分界点`k`, 因此遍历顺序应该是`len` -> `i`

```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 310;
int stones[N];
int prefixSum[N];
int dp[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &stones[i]);
        prefixSum[i] = prefixSum[i-1] + stones[i];
    }
    for(int len=2; len<=n; len++){
        for(int i=1; i+len-1<=n; i++){
            int j = i+len-1;
            dp[i][j] = 0x3f3f3f3f;
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+(prefixSum[j]-prefixSum[i-1]));
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
```


##### 2. 蒙德里安的梦想
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 12, M = 1<<N;
long long dp[N][M];
bool st[N];

int main(){
    int n, m;
    while(cin>>n>>m, n||m){
        // 预处理
        for(int i=0; i<(1<<n); i++){
            st[i] = true;
            int zeroCnt = 0;
            for(int j=0; j<n; j++){
                if(i>>j & 1){
                    if(zeroCnt & 1){
                        st[i] = false;
                        break;
                    }
                }
                else
                    zeroCnt++;
            }
            if(zeroCnt & 1)
                st[i] = false;
        }
        // 初始化
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        // 状态转移
        for(int i=1; i<=m; i++){
            for(int j=0; j<(1<<n); j++){
                for(int k=0; k<(1<<n); k++){
                    if((j & k)==0 && st[j|k]==true)
                        dp[i][j] += dp[i-1][k];
                }
            }
        }
        cout<<dp[m][0]<<endl;
    }
    return 0;
}
```


##### 3. 最短Hamilton路径
> `dp[state][j]`: 已经走过的节点存在`state`中, 目前位于节点`j`, 这一状态下的最短路径

```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20, M = 1<<N;
int g[N][N];
int dp[M][N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &g[i][j]);
        }
    }
    memset(dp, 0x3f3f, sizeof dp);
    dp[1][0] = 0;
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(i>>j & 1){
                for(int k=0; k<n; k++){
                    if(i>>k & 1){
                        int state_k = i-(1<<j);
                        dp[i][j] = min(dp[i][j], dp[state_k][k] + g[k][j]);
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1]<<endl;
    return 0;
}
```


##### 4. 没有上司的舞会 - 树状dp
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/* Step 1: 邻接表存储, 构建树
 * Step 2: 找到root 
 * Step 3: DFS构建dp[][0/1]
 */

const int N = 6010;
int h[N], e[N], nxt[N], idx=0;
int dp[N][2];
int happy[N];
bool has_father[N];
int n;

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
void DFS(int u){
    dp[u][0] = 0;
    dp[u][1] = happy[u];
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        DFS(j);
        dp[u][0] += max(dp[j][0], dp[j][1]);
        dp[u][1] += dp[j][0]; 
    }
}
int main(){
    // 1. 构建图
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &happy[i]);
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        has_father[a] = true;
        insert(b, a);
    }
    // 2. 找到root
    int root = 1;
    while(has_father[root]){
        root++;
    }
    // 3. DFS
    DFS(root);
    cout<<max(dp[root][0], dp[root][1])<<endl;
    return 0;
}
```