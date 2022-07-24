#### DP - 区间型

> `dp[i][k]`表示针对`s[:i]`分成**k个连续区间**, 此时能够得到的最优解
> 
> 子问题 => 搜索最后一个区间的起始位置, 将`dp[i][k]`分割成子问题`dp[j-1][k-1]`和`s[j:i]`
> 
> `s[j:i]`可能是通过函数实现, 或者根据记忆化搜索查到(比如`nums[i:j]`的最大值、区间累计和等)
> 
> ![区间型DP](/appendix/%E5%8C%BA%E9%97%B4%E5%9E%8BDP.png)
> 
> 最终的结果是`dp[N][K]`

> 这破 ** 题, 都 ** 列在那儿了, 就是 ** 不对, 真狗啊, ** 边界, ** 循环

##### [LC1278. 分割回文串Ⅲ](/workspace/1278.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2-iii.cpp)

> 题目描述: https://leetcode.cn/problems/palindrome-partitioning-iii
> 
> `dp[i][k]`: 将`s[:i]`分割成k个回文子串(区间)的最小改动
>
> 对于所有`k-1<=j<i`, `dp[i][k] = dp[j][k-1] + calcStep(s, j, i)`
> 
> 而`calcStep()`的计算可以通过`cost[i][j]`数组“记住”

```CPP
// CV
int palindromePartition(string s, int K) {
    int N = s.size();
    // 记忆化: 准备使 s[i:j] 成为回文串的最少修改次数
    vector<vector<int>> cost(N, vector<int>(N));
    for (int len=2; len<=N; len++) {
        for (int i = 0; i <= N-len; i++) {
            int j = i + len - 1;
            cost[i][j] = cost[i+1][j-1] + (s[i]!=s[j]);
        }
    }
    // dp[i][j]: 表示针对s[:i]分成k个连续区间, 此时能够得到的最优解
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k<=min(K, i); k++) {
            if (k == 1) {
                dp[i][1] = cost[0][i - 1];
            }
            else {
                for (int j=k-1; j<i; j++) {
                    dp[i][k] = min(dp[i][k], dp[j][k-1] + cost[j][i-1]);
                }
            }
        }
    }
    return dp[N][K];
}
```


##### [LC813. 最大平均值和的分组](/workspace/813.%E6%9C%80%E5%A4%A7%E5%B9%B3%E5%9D%87%E5%80%BC%E5%92%8C%E7%9A%84%E5%88%86%E7%BB%84.cpp)

> 题目描述: https://leetcode.cn/problems/largest-sum-of-averages/
> 
> 把`累加和`和`dp[i][k]`的循环写好花了十分钟, 试边界试了一个小时, 最后抄了个题解😓

```CPP
double largestSumOfAverages(vector<int>& nums, int K) {
    int N = nums.size();
    // 累计和
    vector<double> cumSum(N+1, 0.0);
    for(int i=1; i<=N; i++){
        cumSum[i] = cumSum[i-1] + nums[i-1];
    }
    // 区间dp[i][k]
    vector<vector<double> > dp(N+1, vector<double>(K+1, 0));
    dp[0][0] = 0;
    for(int i=1; i<=N; i++){
        dp[i][1] = cumSum[i] / i;
        for(int k=2; k<=min(K, i); k++){
            for(int j=k-1; j<i; j++){
                dp[i][k] = max(dp[i][k], dp[j][k-1]+(cumSum[i]-cumSum[j])/(i-j));
            }
            cout<<i<<" : "<<k<<" =>"<<dp[i][k]<<endl;
        }
    }
    double ans = 0.0;
    for(int k=1; k<=K; k++){
        ans = max(ans, dp[N][k]);
    }
    return ans;
}
```


##### [LC410. 分割数组的最大值](/workspace/410.%E5%88%86%E5%89%B2%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC.cpp)

> 题目描述: https://leetcode.cn/problems/split-array-largest-sum/
>
> 与前两题基本相同, 尤其是[LC813. 最大平均值和的分组](/workspace/813.%E6%9C%80%E5%A4%A7%E5%B9%B3%E5%9D%87%E5%80%BC%E5%92%8C%E7%9A%84%E5%88%86%E7%BB%84.cpp), 只不过`dp[i][k]`更新原则稍有不同

```CPP
int splitArray(vector<int>& nums, int K) {
    int N = nums.size();
    // 累计和
    vector<int> cumSum(N+1, 0);
    for(int i=1; i<=N; i++){
        cumSum[i] = cumSum[i-1] + nums[i-1];
    }
    // 区间dp[i][k]
    vector<vector<int> > dp(N+1, vector<int>(K+1, INT_MAX));
    for(int i=1; i<=N; i++){
        dp[i][1] = cumSum[i];
        for(int k=2; k<=min(K, i); k++){
            for(int j=k-1; j<i; j++){
                int curMaxSum = max(dp[j][k-1], cumSum[i]-cumSum[j]);
                dp[i][k] = min(dp[i][k], curMaxSum);
            }
        }
    }
    return dp[N][K];
}
```