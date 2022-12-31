/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        // 因为会溢出, 即使是long long
        vector<vector<uint64_t> > dp(m+1, vector<uint64_t>(n+1, 0));
        for(int i=0; i<=m; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n && j<=i; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

