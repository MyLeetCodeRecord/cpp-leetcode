/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i-1] < prices[i])
                ans += (prices[i]-prices[i-1]);
        }
        return ans;
    }
};
// @lc code=end

