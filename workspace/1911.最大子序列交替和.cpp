/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 *
 * [1911] 最大子序列交替和
 */

// @lc code=start
class Solution {
public:
    // LC122. 买卖股票的最佳时机II
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // 0: 奇数位(+) ; 1: 偶数位(-)
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        dp[0][0] = dp[0][1] = 0;
        for(int i=1; i<=n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + nums[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - nums[i-1]);
        }
        return dp[n][0];
    }
};
// @lc code=end

