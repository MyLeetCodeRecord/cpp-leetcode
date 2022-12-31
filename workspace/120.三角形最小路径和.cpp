/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        reverse(triangle.begin(), triangle.end());
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j=0; j<n; j++){
            dp[0][j] = triangle[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n-i; j++){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + triangle[i][j];
            }
        }
        return dp[n-1][0];
    }
};
// @lc code=end

