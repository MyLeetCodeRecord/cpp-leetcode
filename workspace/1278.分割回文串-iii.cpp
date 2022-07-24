/*
 * @lc app=leetcode.cn id=1278 lang=cpp
 *
 * [1278] 分割回文串 III
 */

// @lc code=start
class Solution {
public:
    int palindromePartition(string& s, int K) {
        int N = s.size();
        // 记忆化: 准备使 s[i:j] 成为回文串的最少修改次数
        vector<vector<int> > cost(N+1, vector<int>(N+1, 0));
        for (int len=2; len<=N; len++) {
            for (int i=1; i+len-1<=N; i++) {
                int j = i+len-1;
                cost[i][j] = cost[i+1][j-1] + (s[i-1]!=s[j-1]);
            }
        }
        // dp[i][k]: 表示针对s[:i]分成k个连续区间, 此时能够得到的最优解
        vector<vector<int> > dp(N+1, vector<int>(K+1, INT_MAX));
        dp[0][0] = 0;
        for (int i=1; i<=N; i++) {
            dp[i][1] = cost[1][i];
            for (int k = 2; k<=min(K, i); k++) {
                for (int j=k; j<=i; j++) {
                    dp[i][k] = min(dp[i][k], dp[j-1][k-1] + cost[j][i]);
                }
            }
        }
        return dp[N][K];
    }
};
// @lc code=end

