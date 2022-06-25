/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dp[i]: 爬到第i层的最低花费
        vector<int> dp(cost.size()+1);
        dp[0] = 0;
        dp[1] = cost[0];
        for(int i=2; i<=cost.size(); i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i-1];
        }
        return min(dp[cost.size()], dp[cost.size()-1]);
    }
};
// @lc code=end

