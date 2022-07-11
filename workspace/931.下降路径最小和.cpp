/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    // 同样可以压缩为两行的二维dp[2][n]
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int> > dp(n, vector<int>(n, INT_MIN));
        for(int j=0; j<n; j++)
            dp[0][j] = matrix[n-1][j];
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int minCost = dp[i-1][j];
                if(j!=0)
                    minCost = min(minCost, dp[i-1][j-1]);
                if(j!=n-1)
                    minCost = min(minCost, dp[i-1][j+1]);
                dp[i][j] = matrix[n-1-i][j] + minCost;
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};
// @lc code=end

