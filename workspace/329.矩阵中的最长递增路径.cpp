/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
    int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int m, n;
public:
    int DFS(vector<vector<int>>& mat, vector<vector<int>>& dp, int r, int c){
        if(dp[r][c] != 0)
            return dp[r][c];
        int ans = 0;
        for(int i=0; i<4; i++){
            int nextX = r+directions[i][0];
            int nextY = c+directions[i][1];
            if(nextX>=0 && nextX<m && nextY>=0 && nextY<n && mat[nextX][nextY]>mat[r][c]){
                ans = max(ans, DFS(mat, dp, nextX, nextY)+1);
            }
        }
        dp[r][c] = ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, DFS(mat, dp, i, j)+1);
            }
        }
        return ans;
    }
};
// @lc code=end

