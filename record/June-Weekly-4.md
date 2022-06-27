#### Weekly 4

> 关于为什么打卡周赛以及每日一题
> 
> 一遍一遍刷dp, 刷dfs完成todo list, 虽然有些许成就感, 但有时候还是在原地转圈儿
> 
> 但是周赛里需要去定位问题, 发现和解决一些平时忽视的东西, 或者偶然发现一个很久没遇到过的知识点...这感觉抵消了一部分做不出题的痛苦...
> 
> 并且感受一下怎么刷过的简单明了的题目如何"变现"
> 
> 比如上周歪打正着的`完全背包`, 以及这周昨天做过、但是没看出来的[子数组最大和](../workspace/53.%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E7%BB%84%E5%92%8C.cpp)...
> 
> 勉强没掉太多分还是挺好的


##### [1. 判断矩阵是否是一个X矩阵](https://leetcode.cn/problems/check-if-matrix-is-x-matrix/)


##### [2. 统计放置房子的方式数](https://leetcode.cn/problems/count-number-of-ways-to-place-houses/)

> 先用`回溯`做了一下, 发现`n=1000`的用例超时, 但是发现答案满足`4, 9, 25, ...`, 也就是<kbd>Fibonacci数组的平方</kbd>
> 
> 周赛过程里被我做成了找规律的题...
> 
> 事实上, 单纯分析单层的递推公式, 然后平方即可
>  - 第一个位置放房子, dp[i] = dp[i-1]+dp[i-2]
>  - 两层放置方案相互独立, ans[i] = dp[i]*dp[i]
> 
> 注意对`1e9+7`取余, 别罚时

```CPP
int countHousePlacements(int n) {
    if(n==1)
        return 4;
    if(n==2)
        return 9;
    vector<int> dp(n+1);
    dp[1] = 2;
    dp[2] = 3;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 1000000007;
    }
    // 新学的...乘以1LL, 转long long
    return (1LL*dp[n]*dp[n])%1000000007;
}
```

##### [3. 拼接数组的最大分数](https://leetcode.cn/problems/maximum-score-of-spliced-array/)
> 是对两个数组的`diff`求[LC53. 最大子数组和](/workspace/53.%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E7%BB%84%E5%92%8C.cpp)
> 
> `nums2-nums1`所求得的最大子数组和与`cumSum1`相加, `nums1-nums2`所求得的最大子数组和与`cumSum2`相加
>
>![LC5229](/appendix/LC5229.png)

```CPP
int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int sum1 = 0, sum2 = 0;
    vector<int> diff1(n, 0);    // nums1-nums2
    vector<int> diff2(n, 0);    // nums2-nums1
    for(int i = 0; i < n; i++) {
        sum1 += nums1[i];
        sum2 += nums2[i];
        diff1[i] = nums1[i] - nums2[i];
        diff2[i] = nums2[i] - nums1[i];
    }
    return max(sum1 + maxSubArray(diff2), sum2 + maxSubArray(diff1));
}
// 最大子数组和
int maxSubArray(vector<int>& nums) {
    int ans = 0;
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for(int i = 1; i < nums.size(); i++){
        dp[i] = (dp[i-1]>0) ? dp[i-1]+nums[i] : nums[i];
        ans = max(ans, dp[i]);
    }
    return ans;
}
```
