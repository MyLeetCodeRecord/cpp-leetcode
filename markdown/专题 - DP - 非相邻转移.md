#### DP-非相邻转移

> 很多题目, 如[DP-行使权力]()这类问题, `dp[i](or dp[x][i])`只与`dp[i-1]`有关, 可以称之为**相邻转移**
> 
> 这个专题讨论**非相邻转移**

##### [LC300. 最长递增子序列](/workspace/300.%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97.cpp)

> 题目描述: https://leetcode.cn/problems/longest-increasing-subsequence/
> 
> `dp[i]`: 严格以`s[i]`结尾的、最长的LIS长度
> 对于`dp[i]`的构造, 与**i前面所有j<i**有关

```CPP
for(int i=1; i<nums.size(); i++){
    // 不一定是从i-1处获得, 而可能来源于所有 j<i
    for(int j=0; j<i; j++){
        if(nums[i] > nums[j]){
            dp[i] = max(dp[i], dp[j]+1);
        }
    }
    ans = max(ans, dp[i]);
}
```


##### [LC673. 最长递增子序列的个数](/workspace/673.%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E4%B8%AA%E6%95%B0.cpp)

> 题目描述: https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
> 
> [L300. 最长连续子序列](/workspace/300.%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97.cpp)的进阶版
> 
> 需要额外一个`cnt[i]`数组, 来记录**严格以i结尾的长度为dp[i]的子序列数目**
>
> `cnt[i]`的定义决定了, 它的最大值不是最终ans, 而是`dp[i]==maxLen`的位置i所对应的`cnt[i]`求和得到ans

```CPP
int findNumberOfLIS(vector<int>& nums) {
    int ans = 1;
    vector<int> dp(nums.size(), 1);
    vector<int> cnt(nums.size(), 1);    // 注意cnt[i]记录的是严格以i结尾的LIS长度对应的序列数
    for(int i=1; i<nums.size(); i++){
        for(int j=0; j<i; j++){
            if(nums[i] > nums[j]){
                if(dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if(dp[j]+1 == dp[i]){
                    cnt[i] += cnt[j];
                }
            }
        }
    }
    // cnt[i]最大值并非最终ans, 而是要找所有dp[i]==maxLen的cnt[i]之和
    int maxLen = 0;
    for(int i=0; i<nums.size(); i++){
        if(dp[i] > maxLen){
            ans = cnt[i];
            maxLen = dp[i];
        }
        else if(dp[i] == maxLen){
            ans += cnt[i];
        }
    }
    return ans;
}
```