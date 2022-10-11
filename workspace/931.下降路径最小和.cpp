/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 为了让matrix和dp有直接对应关系
        reverse(matrix.begin(), matrix.end());
        vector<vector<int> > dp(n, vector<int>(n, INT_MAX));
        // 初始化最底层
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                if(j != 0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                    
                dp[i][j] = min(dp[i][j], dp[i-1][j]);

                if(j != n-1)
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                dp[i][j] += matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};
// @lc code=end

