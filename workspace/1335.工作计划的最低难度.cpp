/*
 * @lc app=leetcode.cn id=1335 lang=cpp
 *
 * [1335] 工作计划的最低难度
 */

// @lc code=start
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int N = jobDifficulty.size();
        // 记忆化搜索: 记住区间[i:j]内的最大难度
        vector<vector<int> > maxDifficulty(N+1, vector<int>(N+1, 0));
        for(int i=1; i<=N; i++){
            maxDifficulty[i][i] = jobDifficulty[i-1];
            for(int len=1; i+len<=N; len++){
                maxDifficulty[i][i+len] = max(maxDifficulty[i][i+len-1], jobDifficulty[i+len-1]);
            }
        }
        // 区间dp[i][k]
        vector<vector<int> > dp(N+1, vector<int>(d+1, INT_MAX));
        for(int i=1; i<=N; i++){
            dp[i][1] = maxDifficulty[1][i];
            for(int k=2; k<=min(d, i); k++){
                for(int j=k; j<=i; j++){
                    dp[i][k] = min(dp[i][k], dp[j-1][k-1] + maxDifficulty[j][i]);
                }
            }
        }
        return (dp[N][d]<INT_MAX) ? dp[N][d] : -1;
    }
};
// @lc code=end

