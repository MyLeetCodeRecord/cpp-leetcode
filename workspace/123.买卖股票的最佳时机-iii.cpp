/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[0][i]: 第一股持有中, 到第i天能获得的最大余额
        // dp[1][i]: 已经卖出第一股, 暂时没有买入第二股, 到第i天能获得的最大余额
        // dp[2][i]: 第二股持有中, 到第i天能获得的最大余额
        // dp[3][i]: 已经卖出第二股, 到第i天能获得的最大余额
        vector<vector<int> > dp(4, vector<int>(prices.size(), 0));
        dp[0][0] = -prices[0];
        dp[1][0] = 0;
        dp[2][0] = -prices[0];
        dp[3][0] = 0;
        for(int i=1; i<prices.size(); i++){
            dp[0][i] = max(-prices[i], dp[0][i-1]);
            dp[1][i] = max(dp[0][i-1]+prices[i], dp[1][i-1]);
            dp[2][i] = max(dp[1][i-1]-prices[i], dp[2][i-1]);
            dp[3][i] = max(dp[2][i-1]+prices[i], dp[3][i-1]);
        }
        return max(dp[1].back(), dp[3].back());
    }
};
// @lc code=end

