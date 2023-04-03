#### 区间DP

> 灵神: https://www.bilibili.com/video/BV1Gs4y1E7EU

##### [LC516. 最长回文子序列](/workspace/516.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E5%BA%8F%E5%88%97.cpp)
> **朴素思路**: 求`s`和`reverse_s`的最长公共子序列
>
> **区间dp**
> 
> ![LC516](/workspace/516.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E5%BA%8F%E5%88%97.cpp)

```CPP
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=n-1; i>=0; i--){
        dp[i][i] = 1;
        for(int j=i+1; j<n; j++){
            if(s[i]==s[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}
```

##### []()