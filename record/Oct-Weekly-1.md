#### Weekly 1

##### 1. [公因子的数目](https://leetcode.cn/problems/number-of-common-factors/): `math`, 枚举
> `a, b`的范围是`1~1000`, 完全可以暴力枚举
> 
> 看看考场上写的💩, 是被昨天的T1晃到了?
> 
> 求`公因子`, 你写因子求交集...
> 
> ![LC6192](/appendix/LC6192.png)

```CPP
int commonFactors(int a, int b){
    int ans = 1;
    for(int i=2; i<=min(a,b); i++){
        if(a%i==0 && b%i==0)
            ans++;
    }
    return ans;
}
```

##### 2. [沙漏的最大总和⏳](https://leetcode.cn/problems/maximum-sum-of-an-hourglass/): 枚举

> 枚举**所有左上角点**, 共`(m-2)*(n-2)`个, 然后找到九个格子的相对位置求和, 更新`maxAns`

```CPP
int getSum(vector<vector<int> >& grid, int r, int c){
    int sum = 0;
    sum += (grid[r][c] + grid[r][c+1] + grid[r][c+2]);
    sum += (grid[r+1][c+1]);
    sum += (grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2]);
    return sum;
}
// 1e6*9 => int可以cover, 150*150 => 可以暴力搜索
int maxSum(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();
    for(int r=0; r<=m-3; r++){
        for(int c=0; c<=n-3; c++){
            ans = max(ans, getSum(grid, r, c));
        }
    }
    return ans;
}
```


##### 3. [最小XOR](https://leetcode.cn/problems/minimize-xor/): `bit`
> 思路: 已知`1^1=0`, 并且1的数量是固定的(等于`num2`中1的数量)
> 
> `Case 1`: 如果`X`中1的数量等于或者比`num1`中少, 那么从`高位`开始, 将`num1`中的`高位1`尽可能"抹掉"
> 
> `Case 2`: 如果`X`中1的数量比`num1`中多, 则先将`高位1`抹掉, 然后从`低位0`开始补1, 注意不要和前一阶段新产生的0重复
> ß
> **Step 1**: 确定目标`X(num2)`中1的数量
> 
> **Step 2**: 从`num1`的高位开始分配`1`, 每次`cnt--`
> 
> **Step 3**: 如果`cnt>0`, 从低位0开始改为1, 每次`cnt--`
> 
> **Step 4**: 返回`X = (ans+num1)^num1`

```CPP
    int minimizeXor(int num1, int num2) {
        // Step1: num2 中 1 的个数
        int cnt = 0;
        while(num2!=0){
            if(num2 % 2==1)
                cnt++;
            num2 /= 2;
        }
        int ans = 0;
        // Step2: 从高位开始获取num1中的1 => "抹掉"
        for(int i=29; cnt>0 && i>=0; i--){
            if((num1>>i) & 1){
                ans -= (1<<i);  // 减
                cnt--;
            }
        }
        // Step3: cnt>0则从低位开始 => 改1
        for(int i=0; cnt>0 && i<=29; i++){
            if(!((num1>>i) & 1)){
                ans += (1<<i);  // 加
                cnt--;
            }
        }
        // num1+ans: 结果
        // num1 ^ X= 结果
        // X = 结果 ^ num1
        return (num1 + ans) ^ num1;
    }
```

##### 4. [对字母串可执行的最大删除数](https://leetcode.cn/problems/maximum-deletions-on-a-string/): `dp`+`字符串前缀哈希`
> 每次操作结束后, 剩下的还是一个子字符串, 进行同样的操作 => 子问题 => `dp`
> 
> `dp[i]`: 对s[i:]执行操作的最大删除次数 => i应该从后往前遍历操作的最大次数 => 答案为`dp[1]`
> 
> ![LC2430-3](/appendix/LC2430-3.png)
> 
> 比较是否相同 => `字符串前缀哈希`
> 
> ![LC2430-2](/appendix/LC2430-2.png)

```CPP
// 字符串前缀哈希
typedef unsigned long long ULL;

const int N = 4010, P = 131;
ULL h[N], p[N];

class Solution {
public:
    ULL getHash(int l, int r){
        return h[r] - h[l-1] * p[r-l+1];
    }
    int deleteString(string s) {
        // Step 1: 字符串前缀哈希
        int n = s.size();
        p[0] = 1;
        for(int i=1; i<=n; i++){
            p[i] = p[i-1]*P;
            h[i] = h[i-1]*P + s[i-1];
        }
        // Step 2: dp[], 从1开始
        // dp[i]: 对从i到末尾的字符串执行删除的最大删除次数, i应该从后往前遍历
        vector<int> dp(n+2);
        // i是左侧start, j是长度
        for(int i=n; i>0; i--){
            dp[i] = 1;  // 初始化为1, 表示最差情况一次删掉整个字符串
            for(int j=1; i+2*j-1 <= n; j++){
                if(getHash(i, i+j-1) == getHash(i+j, i+2*j-1)){
                    dp[i] = max(dp[i], dp[i+j] + 1); 
                }
            }
        }
        return dp[1];
    }
};
```