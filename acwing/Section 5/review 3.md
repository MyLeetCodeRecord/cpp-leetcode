##### 1. 0-1背包

```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int w[N], v[N], C;
int dp[N];

int main(){
    int n;
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


##### 2. 完全背包
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


##### 3. 多重背包 - 朴素做法 - 展开为01背包
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int w[N], v[N], s[N];
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &w[i], &v[i], &s[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=w[i]; j<=C; j++){
            for(int k=0; k<=s[i]; k++){
                if(j >= k * w[i])
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
    // 二进制优化
    for(int i=0; i<n; i++){
        for(int k=1; k<s[i]; k*=2){
            s[i] -= k;
            goods.push_back({k*w[i], k*v[i]});
        }
        if(s[i] > 0){
            goods.push_back({s[i]*w[i], s[i]*v[i]});
        }
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
int w[N], v[N], s;  // 覆盖使用
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d", &s);
        for(int j=0; j<s; j++){
            scanf("%d %d", &w[j], &v[j]);
        }
        for(int j=C; j>=0; j--){
            for(int k=0; k<=s; k++){
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
int a[N][N];
int dp[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=n-1; i>=0; i--){
        for(int j=0; i+j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int j=0; j<n; j++){
        dp[0][j] = a[0][j];
    }
    for(int i=1; i<n; i++){
        for(int j=0; i+j<n; j++){
            dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
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
int dp[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        dp[i] = 1;
    }
    int ans = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i] > a[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
```


##### 8. 最长公共子序列
```CPP
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
string A, B;
int dp[N][N];

int main(){
    int len1, len2;
    cin>>len1>>len2;
    cin>>A>>B;
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
```


##### 9. 最短编辑距离
```CPP
#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
int len1, len2;
string A, B;
int dp[N][N];

int main(){
    cin>>len1>>A>>len2>>B;
    dp[0][0] = 0;
    for(int i=1; i<=len1; i++)
        dp[i][0] = i;
    for(int j=1; j<=len2; j++)
        dp[0][j] = j;
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    cout<<dp[len1][len2]<<endl;
    return 0;
}
```


##### 10. 石子合并
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 310;
int stones[N];
int prefixSum[N];   // 前缀和数组
int dp[N][N];       // 合并i~j区间的最小开销

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
                dp[i][j] = min(dp[i][j], (prefixSum[j]-prefixSum[i-1])+dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
```


##### 11. 整数划分 - 完全背包
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int dp[N];

int main(){
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            dp[j] += dp[j-i];
            dp[j] %= 1000000007;
        }
    }
    cout<<dp[n]<<endl;
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
long long dp[N][M];  // 行数=N; 列数=状态数M=2^N
bool st[N];          // 记录状态合法性

int main(){
    int n, m;
    while(cin>>n>>m, n||m){
        // 预处理, 检查所有状态合法性, 即有没有连续奇数个0
        for(int i=0; i<(1<<n); i++){
            st[i] = true;
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(i>>j & 1){       // 当前位为1, 说明可能有一段连续0结束了
                    if(cnt & 1){    // 如果前一段是奇数个1, 标记当前状态为非法, st[i]=false
                        st[i] = false;
                        break;
                    }
                }
                else
                    cnt++;
            }
            // 最后可能以0结尾, 没办法用1分割出这段连续0, 所以单独检查一下尾部连续0
            if(cnt & 1)
                st[i] = false;
        }
        // 状态初始化
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        // 状态转移
        for(int i=1; i<=m; i++){        // 一共N列, 转移要发生N次
            for(int j=0; j<(1<<n); j++){
                for(int k=0; k<(1<<n); k++){
                    if((j&k)==0 && st[j|k]==true)   // 检查状态 k 转移到状态 j 是否合法
                        dp[i][j] += dp[i-1][k];     // 合法则 + dp[i-1][k]
                }
            }
        }
        cout<<dp[m][0]<<endl;   // 最后多加一层 & 0状态, 表示没有前一列延伸出来的横条
    }
    return 0;
}
```


##### 13. 最短Hamilton路径
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20, M = 1<<N;
int weight[N][N];
int dp[M][N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &weight[i][j]);
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for(int i=1; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if((i>>j) & 1){
                for(int k=0; k<n; k++){
                    if((i>>k) & 1){   // 合法性: k在路径中
                        int state_k = i-(1<<j);
                        dp[i][j] = min(dp[i][j], dp[state_k][k]+weight[k][j]);
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1]<<endl;
    return 0;
}
```


##### 14. 没有上司的舞会
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 6010;
int h[N], e[N], nxt[N], idx=0;
int happy[N];
int dp[N][2];
bool has_father[N]; // 用于找根节点

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
void DFS(int u){
    dp[u][1] += happy[u];
    dp[u][0] = 0;
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        DFS(j);
        dp[u][0] += max(dp[j][0], dp[j][1]);
        dp[u][1] += dp[j][0];
    }
}
int main(){
    memset(h, -1, sizeof h);
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &happy[i]);
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(b, a);   // b是a的上司
        has_father[a] = true;
    }
    // 别怕, 只是想找到根节点...
    int root = 1;
    while(has_father[root])
        root++;
    DFS(root);
    cout<<max(dp[root][0], dp[root][1])<<endl;
    return 0;
}
```
