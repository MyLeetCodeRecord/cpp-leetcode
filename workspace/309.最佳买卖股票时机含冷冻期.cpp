/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    // 0-持有股票
    // 1-刚卖出股票
    // 2-卖出股票一天以上
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(3, vector<int>(prices.size()));
        dp[0][0] = -prices[0];
        dp[1][0] = 0;
        dp[2][0] = 0;
        for(int i=1; i<prices.size(); i++){
            dp[0][i] = max(dp[0][i-1], dp[2][i-1] - prices[i]);
            dp[1][i] = dp[0][i-1] + prices[i];
            dp[2][i] = max(dp[2][i-1], dp[1][i-1]);
        }
        return max(dp[1].back(), dp[2].back());
    }
};
// @lc code=end

