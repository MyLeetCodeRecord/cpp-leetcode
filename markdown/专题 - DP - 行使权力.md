#### DP-行使权力

> 行使权力的`dp`问题, 分析有多少种状态(比如未行使/已经行使一次等), 然后用`dp[k][n]`解决

##### [LC487. 最大连续1的个数Ⅱ](https://leetcode.cn/problems/max-consecutive-ones-ii/)

> ![LC487](/appendix/LC487-1.png)
> 
> 这题应该用`滑动窗口`, 但是用`dp`也可以做
> 
> ![LC487](/appendix/LC487-2.png)
>
> `dp[0][i]`: **以nums[i]结尾**并且**尚未行使翻转权力**的最长ones序列长度
> 
> `dp[1][i]`: **以nums[i]结尾**并且**已经行使翻转权力**的最长ones序列长度

```CPP
int findMaxConsecutiveOnes(vector<int>& nums) {
    vector<vector<int> > dp(2, vector<int>(nums.size(), 0));
    dp[0][0] = (nums[0]==1);
    dp[1][0] = (nums[0]==0);
    int ans = max(dp[0][i], dp[1][i]);
    for(int i=1; i<nums.size(); i++){
        if(nums[i] == 1){
            dp[0][i] = dp[0][i-1] + 1;
            dp[1][i] = dp[1][i-1] + 1;
        }
        else{
            dp[0][i] = 0;
            dp[1][i] = dp[0][i-1] + 1;
        }
        ans = max(dp[0][i], dp[1][i]);
    }
    return ans;
}
```

##### [LC1186. 删除一次得到子数组最大和](/workspace/1186.%E5%88%A0%E9%99%A4%E4%B8%80%E6%AC%A1%E5%BE%97%E5%88%B0%E5%AD%90%E6%95%B0%E7%BB%84%E6%9C%80%E5%A4%A7%E5%92%8C.cpp)

> [题目](https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/)
> 
> 很容易想到用上一题的思路来求解
> 
> `dp[0][i]`: **以nums[i]结尾**并且**尚未行使删除权力**的最长ones序列长度
> 
> `dp[1][i]`: **以nums[i]结尾**并且**已经行使删除权力**的最大

```CPP
int maximumSum(vector<int>& arr) {
    vector<vector<int> > dp(2, vector<int>(arr.size(), 0));
    dp[0][0] = arr[0];
    dp[1][0] = 0;
    int ans = max(dp[0][0], dp[1][0]);
    for(int i=1; i<arr.size(); i++){
        dp[0][i] = max(dp[0][i-1] + arr[i], arr[i]);
        dp[1][i] = max(dp[0][i-1], dp[1][i-1]+arr[i]);
        ans = max(ans, max(dp[0][i], dp[1][i]));
    }
    return ans;
}
```
