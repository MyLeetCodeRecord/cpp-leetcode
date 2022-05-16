/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // (0, 0) or (m-1, n-1)有障碍物 => 不存在路径
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
            return 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        // 对于第0行和第0列进行初始化, 如果
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            if(obstacleGrid[i][0]==1)
                break;
            dp[i][0] = 1;
        }
        for(int j=0; j<n; j++){
            if(obstacleGrid[0][j]==1)
                break;
            dp[0][j] = 1;
        }
        // 状态转移方程
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]!=1)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

