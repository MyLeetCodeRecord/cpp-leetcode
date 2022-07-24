/*
 * @lc app=leetcode.cn id=1278 lang=cpp
 *
 * [1278] 分割回文串 III
 */

// @lc code=start
// cv
class Solution {
public:
    int palindromePartition(string& s, int K) {
        int N = s.size();
        // 记忆化: 准备使 s[i:j] 成为回文串的最少修改次数
        vector<vector<int>> cost(N, vector<int>(N));
        for (int len=2; len<=N; len++) {
            for (int i = 0; i <= N-len; i++) {
                int j = i + len - 1;
                cost[i][j] = cost[i+1][j-1] + (s[i]!=s[j]);
            }
        }
        // dp[i][j]: 表示针对s[:i]分成k个连续区间, 此时能够得到的最优解
        vector<vector<int>> dp(N+1, vector<int>(K+1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int k = 1; k<=min(K, i); k++) {
                if (k == 1) {
                    dp[i][1] = cost[0][i - 1];
                }
                else {
                    for (int j=k-1; j<i; j++) {
                        dp[i][k] = min(dp[i][k], dp[j][k-1] + cost[j][i-1]);
                    }
                }
            }
        }
        return dp[N][K];
    }
};
// @lc code=end

