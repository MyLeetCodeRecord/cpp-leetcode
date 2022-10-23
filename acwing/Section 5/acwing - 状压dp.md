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
> **状态转移**: `dp[i-1][k] -> f[i][j]`, for 所有能转移为`j`的状态`k`
> 
> **状态计算**: 
> - `dp[i][j] = ∑ dp[i-1][k]`
> - 初始值: `dp[0][0] = 1`
> - 目标值: `dp[M][0]`
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
> ![](/appendix/acwing-%E8%92%99%E5%BE%B7%E9%87%8C%E5%AE%89%E7%9A%84%E6%A2%A6%E6%83%B35.png)
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
        // 预处理, 检查所有状态合法性, 即有没有连续奇数个0
        for(int i=0; i<(1<<n); i++){
            st[i] = true;
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(i>>j & 1){
                    if(cnt & 1){
                        st[i] = false;
                        break;
                    }
                }
                else{
                    cnt++;
                }
            }
            if(cnt & 1)
                st[i] = false;
        }
        // 状态初始化
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        // 状态转移
        for(int i=1; i<=m; i++){
            for(int j=0; j<(1<<n); j++){
                for(int k=0; k<(1<<n); k++){
                    if((j&k)==0 && st[j|k]==true)
                        dp[i][j] += dp[i-1][k];
                }
            }
        }
        cout<<dp[m][0]<<endl;
    }
    return 0;
}
```