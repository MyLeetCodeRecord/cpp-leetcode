/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        vector<vector<int> > dp(2*k, vector<int>(prices.size()));
        // 初始化
        for(int i=0; i<k; i++)
            dp[2*i][0] = -prices[0];
        for(int i=0; i<k; i++)
            dp[2*i+1][0] = 0;
        int ans = 0;
        for(int i=1; i<prices.size(); i++){
            for(int a=0; a<k; a++){
                if(a==0){
                    dp[0][i] = max(-prices[i], dp[0][i-1]);
                    dp[1][i] = max(dp[0][i-1]+prices[i], dp[1][i-1]);
                }
                else{
                    dp[2*a][i] = max(dp[2*a-1][i-1]-prices[i], dp[2*a][i-1]);
                    dp[2*a+1][i] = max(dp[2*a][i-1]+prices[i], dp[2*a+1][i-1]);
                }
                ans = max(ans, dp[2*a+1][i]);
            }
        }
        return ans;
    }
};
// @lc code=end

