##### 1. 数字三角形

```CPP
const int N = 510;
int triangle[N][N];
int dp[N][N];       // 只依赖上一层, 但[j]的计算依赖[j]和[j+1], 所以不能压缩为一维

int main(){
    int n;
    scanf("%d", &n);
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n-i; j++){
            scanf("%d", &triangle[i][j]);
        }
    }
    for(int j=0; j<n; j++){
        dp[0][j] = triangle[0][j];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j+1])+triangle[i][j];
        }
    }
    cout<<dp[n-1][0]<<endl;
    return 0;
}
```

##### 2. 最长上升子序列

```CPP
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
    int ans = 0;
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

##### 3. 最长公共子序列

```CPP
const int N = 1010;
string s1, s2;
int dp[N][N];

int main(){
    int n, m;
    cin>>n>>m;
    cin>>s1>>s2;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
```

##### 4. 最短编辑距离

```CPP
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
string s1, s2;
int dp[N][N];

int main(){
    int n, m;
    cin>>n>>s1;
    cin>>m>>s2;
    for(int i=1; i<=n; i++)
        dp[i][0] = i;
    for(int j=1; j<=m; j++)
        dp[0][j] = j;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
```

##### 5. 编辑距离

```CPP
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int editDistance(string& s1, string& s2){
    int m = s1.size();
    int n = s2.size();
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++)
        dp[i][0] = i;
    for(int j=0; j<=n; j++)
        dp[0][j] = j;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }
    return dp[m][n];
}
int main(){
    int n, m;
    cin>>n>>m;
    string strList[n];
    for(int i=0; i<n; i++)
        cin>>strList[i];
    for(int i=0; i<m; i++){
        int ans = 0;
        string query;
        int threshold;
        cin>>query>>threshold;
        for(int j=0; j<n; j++){
            if(editDistance(strList[j], query) <= threshold)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
```

##### 6.石子合并

```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;
int dp[N][N];
int stones[N];
int prefixSum[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &stones[i]);
        prefixSum[i] = prefixSum[i-1] + stones[i];
    }
    for(int len=2; len<=n; len++){
        for(int i=1; i+len-1<=n; i++){  // 左端点
            int j = i+len-1;            // 右端点
            dp[i][j] = 0x3f3f3f3f;
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (prefixSum[j]-prefixSum[i-1]));
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
```

##### 7. 整数划分

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