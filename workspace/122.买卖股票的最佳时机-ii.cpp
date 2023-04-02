/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    // 不限次数, 所以其实每天买卖就可以了
    // int maxProfit(vector<int>& prices) {
    //     int ans = 0;
    //     for(int i=1; i<prices.size(); i++){
    //         if(prices[i-1] < prices[i])
    //             ans += (prices[i]-prices[i-1]);
    //     }
    //     return ans;
    // }
    // 下面是状态机dp做法
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
// @lc code=end

