/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j]: 到(i, j)位置的路径数, 不需要错位
        vector<vector<int> > dp(m, vector<int>(n));
        dp[0][0] = 0;
        for(int j=1; j<n; j++)
            dp[0][j] = 1;
        for(int i=1; i<m; i++)
            dp[i][0] = 1;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

