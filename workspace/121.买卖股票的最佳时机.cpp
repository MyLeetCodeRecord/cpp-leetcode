/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    // 121: 最多只能持有一只股票
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<int> dp(prices.size(), 0);
        dp[0] = prices[0];
        for(int i=1; i<prices.size(); i++){
            dp[i] = min(dp[i-1], prices[i]);
            ans = max(ans, prices[i] - dp[i]);
        }
        return ans;
    }
};
// @lc code=end

