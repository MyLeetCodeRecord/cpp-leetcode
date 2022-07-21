/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(s.size(), 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

