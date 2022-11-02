#### 合并石子

> 从最后一步分析, 一定是两堆合并, 每一堆都是连续的, 依次类推, 每一堆又可以看作是**相同的子问题**
> 
> `dp[i][j]`: 表示将`i~j`合并成一堆的方案集合中, 最小的代价
> 
> `dp`的构建顺序应该是按长度`len`从小到大
> 
> 计算`dp[i][j]`的方式应该是枚举中间分界点的`k`
> 
> `dp[i][j] = min{ (prefixSum[j]-prefixSum[i-1]) + min(dp[i:k] + dp[k+1:j]) }`, `k∈[i, j-1]`
>
> ![合并石子](/appendix/acwing-%E5%90%88%E5%B9%B6%E7%9F%B3%E5%AD%90.png)

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