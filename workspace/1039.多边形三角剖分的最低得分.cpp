/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */

// @lc code=start
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int dp[n][n];
        // 状态转移中用到的dp[i][k]和dp[k][j], 间距最小为1, 因此初始化dp[i][i+1]=0即可
        memset(dp, 0x3f, sizeof dp);
        for(int i=0; i<n-1; i++){
            dp[i][i+1] = 0;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                for(int k=i+1; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+values[i]*values[j]*values[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

