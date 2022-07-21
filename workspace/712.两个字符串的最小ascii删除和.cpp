/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++)
            dp[i][0] += dp[i-1][0] + s1[i-1];
        for(int j=1; j<=n; j++)
            dp[0][j] += dp[0][j-1] + s2[j-1];
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                    // 因为dp[i-1][j]和dp[i][j-1]一定大于等于dp[i-1][j-1](计算顺序可以保证这一点)
                    // dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]));
                else
                    dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

