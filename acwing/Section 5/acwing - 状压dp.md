#### 状态压缩DP

##### 1. 蒙德里安的梦想
> 题目: https://www.acwing.com/problem/content/293/

##### (1) 思路
> 核心思路: 先放横向的, 再放纵向 (也可以调换过来)
> 
> **总方案数 = 只放横向方块(并且剩余纵向位置合法)的方案数量**
> 
> **纵向合法**: 列方向看, 每一列中所有连续的空闲位置数量都为偶数
> 
> ![蒙德里安的梦想](/appendix/acwing-%E8%92%99%E5%BE%B7%E9%87%8C%E5%AE%89%E7%9A%84%E6%A2%A6%E6%83%B3.png)

###### (2) 状态表示和状态转移方程
> `dp[i][j]`: 摆放第i列, 状态为j的方案数。`i`的取值为行数, `j`的取值为`2^列数`
> 
> 状态`j`中`0`和`1`的含义:
> - 1表示由伸出来的横向方块所覆盖
> - 0表示其它状态
> 
> (bilibili视频和yxc讲的i是错开一位的, 不过没关系, 1和0的状态互斥就可以)
> 
> **状态转移**: `dp[i-1][k] -> dp[i][j]`, for 所有能转移为`j`的状态`k`
> 
> **状态计算**: 
> - `dp[i][j] = ∑ dp[i-1][k]`
> - 初始值: `dp[0][0] = 1`
> - 目标值: `dp[M][0]`
> 
> **状态`k`转换为状态`j`的规则**
> - `k & j == 0`
> - `st[j|k]==true`
> 
> ![蒙德里安的梦想](/appendix/acwing-%E8%92%99%E5%BE%B7%E9%87%8C%E5%AE%89%E7%9A%84%E6%A2%A6%E6%83%B32.png)

###### (3) 实现
> **Step 1**: 预处理, 判断合并列(两个状态按位与)的状态 i 是否合法
> 
> 如果合并列的某行是 1, 表示它是由第 i-1 列的横向方块延伸出来的
> 
> 如果合并列不存在连续的奇数个 0, 即为合法状态

```CPP
// 2^n种状态 => i
for(int i=0; i< (1<<n); i++){
    st[i] = true;
    int zeroCnt = 0;    // 记录连续 0 的个数
    // 遍历 i 的每一个位置(数量 = 行数n), 这里其实是从下往上遍历的, 也就是从状态 i 的低bit位开始
    for(int j=0; j<n; j++){
        if(i>>j & 1 == 1){      // 如果状态 i 的第 j 位 = 1
            if(cnt % 2 == 1){   // 判断上面一段连续 0 的个数是否为奇数个, e.g. 1000是不合法的
                st[i] = false;
                break;
            }
        }
        else
            cnt++;  // 继续累加连续 0 的个数
    }
    if(cnt & 1)
        st[i] = false;  // 处理高位 0 的个数, e.g. 0100, 奇数个"前导零"是不合法的
}
```

> **Step 2**: 状态计算
> 
> - 初始值: `dp[0][0] = 1`
> 
> - 第`i-1`列状态`k` => 第`i`列状态`j`的合法性判断
>   - 条件1: 不出现重叠的1
>   - 条件2: 不出现连续的奇数个0
> 
> - 状态转移: `dp[i-1][k] -> f[i][j]`, for 合法的`k`
> 
> (右图的数字应该往左挪一列)
> 
> ![蒙德里安的梦想](/appendix/acwing-%E8%92%99%E5%BE%B7%E9%87%8C%E5%AE%89%E7%9A%84%E6%A2%A6%E6%83%B34.png)

```CPP
memset(dp, 0, sizeof dp);
dp[0][0] = 1;
for(int i=1; i<=m; i++){  // 枚举列
    for(int j=0; j<i<<n; j++){  // 枚举第 i 列状态
        for(int k=0; k<1<<n; k++){  // 枚举第 i-1 列状态
            // 状态j和状态k兼容判断
            if((j & k) == 0             // 条件1: 不出现重叠的 1
                && st[j|k] == true)     // 条件2: 不出现连续的奇数个0
                dp[i][j] += dp[i-1][k];
        }
    }
}
cout<<dp[m][0]<<endl;
```


###### (4) 完整实现
> ![蒙德里安的梦想](/appendix/acwing-%E8%92%99%E5%BE%B7%E9%87%8C%E5%AE%89%E7%9A%84%E6%A2%A6%E6%83%B35.png)
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
                else{
                    cnt++;
                }
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


##### 2. 最短Hamilton路径

> 什么时候用`状压dp`?
> 
> - 一个很小的`N`, 可以用`N`个二进制位, 分别唯一地表示 => `M = 1<<N`个状态
> 
> - `dp`数组维度一般是`[N][M]`或者`[M][N]`

> **状态表示**: 关注两个问题 => `dp`的两个维度
> - 哪些点被遍历过 => 本题中, `N`个要访问的节点 => 用每个二进制位唯一地表示一个节点 => `M = 1<<N`个状态, 可以分别表示`M`条可能的路径(长度不限,  不是包含所有节点)
>   - 路线1: `0->1->2->3` cost=18
>   - 路线2: `0->2->3->1` cost=20
>   - 只有路线1有意义, 但后续路径不需要关注具体怎么走的, 只需要关注已经走过了哪些
> - 当前停留在哪一个点

> **状态转移**
> 
> 枚举能到达`j`的相邻点`k`, `dp[state_j][j]=dp[state_k][k] + weight[k][j]`
> 
> 其中, `state_k`比`state_j`少一个节点`k`

```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20, M = 1<<N;
int dp[M][N];
int g[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &g[i][j]);
        }
    }
    // 初始化 (从0出发)
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    // 状态转移
    for(int i=0; i<(1<<n); i++){    // 枚举状态
        for(int j=0; j<n; j++){     // 枚举终止节点
            // 检查终止节点是不是在状态i中存在, 否则跳过
            if(i>>j & 1){
                for(int k=0; k<n; k++){
                    // 检查 state_k 到state_j的合法性
                    if(i>>k & 1){
                        dp[i][j] = min(dp[i][j], dp[i-(1<<j)][k]+g[k][j]);
                    }
                }
            }
        }
    }
    // 终点设在(n-1), 并且结束时状态应该为所有节点都在路径中state=1111...1111
    cout<<dp[(1<<n)-1][n-1]<<endl;
    return 0;
}
```