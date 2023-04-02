/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    // 同LC188
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
        for(int j=0; j<=k; j++){
            dp[0][j][1] = -k*100010;  // n=0时状态1为不可能状态
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i-1]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i-1]);
            }
        }
        return dp[n][k][0];
    }
};
// @lc code=end

