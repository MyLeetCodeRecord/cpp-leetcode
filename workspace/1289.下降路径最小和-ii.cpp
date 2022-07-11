/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int> > dp(n, vector<int>(n, INT_MIN));
        for(int j=0; j<n; j++)
            dp[0][j] = grid[0][j];
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int minCost = INT_MAX;
                for(int p=0; p<n; p++){
                    if(p!=j){
                        minCost = min(minCost, dp[i-1][p]);
                    }
                }
                dp[i][j] = grid[i][j] + minCost;
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

