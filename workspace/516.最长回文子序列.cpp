/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    // 「子序列」可以不连续
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // dp[i][j]: s[i:j]中, 最大回文子序列长度
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
            if(i != n-1){
                if(s[i]==s[i+1]){
                    dp[i][i+1] = 2;
                }
                else
                    dp[i][i+1] = 1;
            }
        }
        for(int len=3; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                int j = i+len-1;
                if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

