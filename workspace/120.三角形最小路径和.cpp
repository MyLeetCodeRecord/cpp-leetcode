/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 每次只用到下面一行, 因此可以将dp[][]的第一个维度减少到 2
        int n = triangle.size();
        if(n==1)
            return triangle[0][0];
        vector<vector<int> > dp(2, vector<int>(n, 0));
        for(int j=0; j<n; j++)
            dp[0][j] = triangle[n-1][j];
        for(int layer=1; layer<n; layer++){
            for(int j=0; j<n-layer; j++){
                dp[1][j] = triangle[n-1-layer][j] + min(dp[0][j], dp[0][j+1]);
            }
            dp[0] = dp[1];
        }
        return dp[1][0];
    }
};
// @lc code=end

