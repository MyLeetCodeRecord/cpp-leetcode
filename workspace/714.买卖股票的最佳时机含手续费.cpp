/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    // 0 - 未持有
    // 1 - 持有
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int> > dp(2, vector<int>(prices.size()));
        dp[0][0] = 0;
        dp[1][0] = -prices[0]-fee;
        for(int i=1; i<prices.size(); i++){
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]+prices[i]);
            dp[1][i] = max(dp[1][i-1], dp[0][i-1]-prices[i]-fee);
        }
        return dp[0].back();
    }
};
// @lc code=end

