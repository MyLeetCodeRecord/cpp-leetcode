##### 1. 0-1背包
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int w[N], v[N];
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=C; j>=w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}
```

##### 2.完全背包
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int w[N], v[N];
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=w[i]; j<=C; j++){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}
```

##### 3. 多重背包 - 朴素解法
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/* 多重背包之朴素解法 —— 可以在0-1背包的基础上修改
 * foreach i in items:
 *     foreach j in C reverse:
 *         dp[j] = max(dp[j], dp[j-w[i]] + v[i], dp[j-2*w[i]] + 2*v[i] ... , dp[j-s[i]*w[i]] + s[i]*v[i] )
 * 相当于在0-1背包的最内层多加一层对num[i]的遍历
 */

const int N = 110;
int w[N], v[N], s[N];
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &w[i], &v[i], &s[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=C; j>=0; j--){
            for(int k=1; k<=s[i]; k++){
                if(j >= k*w[i])
                    dp[j] = max(dp[j], dp[j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}
```

##### 4. 多重背包 - 二进制优化
```CPP
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/* 多重背包之二进制优化 —— 将s[i]的 K 维压缩到 lgK 维
 * 一个数字n可以由"二进制数组"表示, 即{1,2,4, ...}
 * 那么最少需要的数字数量就是, 1+2+...+2^(x+1) >= n, 1+2+...+2^x < n   =>   x
 * 取前{1, 2, ... , 2^x} 以及 剩余部分n-sum(1, 2, ... , 2^x)
 * 一共(x+1+1)个数
 */

typedef pair<int, int> PII;

const int N = 1010, M = 2010;
int w[N], v[N], s[N];
int dp[M];

vector<PII> goods;

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &w[i], &v[i], &s[i]);
    }
    // 预处理成"二进制"物品列表
    for(int i=0; i<n; i++){
        for(int k=1; k<=s[i]; k*=2){
            s[i] -= k;
            goods.push_back({k*w[i], k*v[i]});
        }
        if(s[i]!=0)
            goods.push_back({s[i]*w[i], s[i]*v[i]});
    }
    // 0-1背包
    for(int i=0; i<(int)goods.size(); i++){
        for(int j=C; j>=goods[i].first; j--){
            dp[j] = max(dp[j], dp[j-goods[i].first]+goods[i].second);
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}
```

##### 5. 分组背包
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 110;
int w[N], v[N], s;
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d", &s);
        for(int k=0; k<s; k++){
            scanf("%d %d", &w[k], &v[k]);
        }
        for(int j=C; j>=0; j--){
            for(int k=0; k<s; k++){
                if(j>=w[k])
                    dp[j] = max(dp[j], dp[j-w[k]]+v[k]);
            }
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}
```

##### 6. 数字三角形
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 510;
int triangle[N][N];
int dp[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=n-1; i>=0; i--){
        for(int j=0; i+j<n; j++){
            scanf("%d", &triangle[i][j]);
        }
    }
    for(int j=0; j<n; i++){
        dp[0][j] = triangle[0][j];
    }
    for(int i=1; i<n; i++){
        for(int j=0; i+j<n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j]) + triangle[i][j];
        }
    }
    cout<<dp[n-1][0]<<endl;
    return 0;
}
```

##### 7. 最长上升子序列
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int a[N];
int dp[N];  // dp[i]: 严格以i结尾的最长上升子序列长度

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
```

##### 8. 最长上升子序列II
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int a[N];
int dp[N];

int main(){
    int n;
    scanf("%d", &n);
    int len = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        // 二分查找: 找到dp[]中比a[i]小的最大位置
        int l = 0;
        int r = len;
        while(l < r){
            int mid = (l+r+1)/2;
            if(dp[mid] < a[i])
                l = mid;
            else
                r = mid-1;
        }
        // 放到下一个位置, 如果需要则更新len
        len = max(len, l+1);
        dp[l+1] = a[i];
    }
    cout<<len<<endl;
    return 0;
}
```

##### 9. 最长公共子序列
```CPP
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
int dp[N][N];

int main(){
    string A, B;
    int len1, len2;
    cin>>len1>>len2;
    cin>>A>>B;
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[len1][len2]<<endl;
    return 0;
}
```

##### 10. 最短编辑距离
```CPP
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
int dp[N][N];

int main(){
    string A, B;
    int len1, len2;
    cin>>len1>>A;
    cin>>len2>>B;
    // 别忘了初始化
    for(int i=1; i<=len1; i++)
        dp[i][0] = i;
    for(int j=1; j<=len2; j++)
        dp[0][j] = j;
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(A[i-1]==B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
    }
    cout<<dp[len1][len2]<<endl;
    return 0;
}
```

##### 11. 石子合并
> `dp[i][j]`: 合并`i~j`堆石子的最小代价
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
            dp[i][j] = 0x3f3f3f3f;  // 先将dp[i][j]置为最大值
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+(prefixSum[j]-prefixSum[i-1]));
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
```

##### 12. 蒙德里安的梦想
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

##### 13. 最短Hamilton路径
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

##### 14. 没有上司的舞会 - 树状dp
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

##### 15. 滑雪
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;
int g[N][N];
int dp[N][N];
int r, c;

int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

// 记忆化搜索: 对于相同的子问题不重复求解
int dp_func(int x, int y){
    if(dp[x][y] != 0){
        return dp[x][y];
    }
    dp[x][y] = 1;    // !!!
    for(int d=0; d<4; d++){
        int nextX = x+directions[d][0];
        int nextY = y+directions[d][1];
        if(nextX>=0 && nextX<r && nextY>=0 && nextY<c){
            // 只能通往更低点 => 可以避免成环
            if(g[nextX][nextY] < g[x][y])
                dp[x][y] = max(dp[x][y], dp_func(nextX, nextY) + 1);
        }
    }
    return dp[x][y];
}
int main(){
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &g[i][j]);
        }
    }
    // 初始化dp数组, 区分遍历过和没遍历过
    memset(dp, 0, sizeof dp);
    // 枚举DFS的起点
    int ans = 1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            ans = max(ans, dp_func(i, j));
        }
    }
    cout<<ans<<endl;
    return 0;
}
```