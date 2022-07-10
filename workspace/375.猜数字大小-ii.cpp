/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
public:
    int DFS(int l, int r, vector<vector<int> >& dp){
        if(l>=r)
            return 0;
        if(dp[l][r] != 0)
            return dp[l][r];
        int ans = INT_MAX;
        // guess: 猜的数字
        for(int guess=l; guess<=r; guess++){
            int cost = guess + max(DFS(l, guess-1, dp), DFS(guess+1, r, dp));
            ans = min(ans, cost);
        }
        dp[l][r] = ans;
        return ans;
    }
    // 最大的最小cost
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n+1, vector<int>(n+1,0));
        return DFS(1, n, dp);
    }
};
// @lc code=end

