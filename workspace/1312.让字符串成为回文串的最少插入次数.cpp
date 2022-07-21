/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    // 借助LCS
    int minInsertions(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return n - dp[n][n];
    }
    // 直接DP
    // int minInsertions(string s) {
    //     int n = s.size();
    //     vector<vector<int> > dp(n, vector<int>(n, 0));
    //     for(int i=n-1; i>=0; i--){
    //         for(int j=i+1; j<n; j++){
    //             if(s[i] == s[j]){
    //                 dp[i][j] = dp[i+1][j-1];
    //             }
    //             else{
    //                 dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
    //             }
    //         }
    //     }
    //     return dp[0][n-1];
    // }
};
// @lc code=end

