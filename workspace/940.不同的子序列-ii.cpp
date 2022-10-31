/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<vector<int> > dp(n+1, vector<int>(26, 0));
        for(int i=1; i<=n; i++){
            int cur = s[i-1] - 'a';
            for(int j=0; j<26; j++){
                if(cur != j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] += 1;
                    for(int k=0; k<26; k++){
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= 1000000007;
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            ans += dp[n][i];
            ans %= 1000000007;
        }
        return ans;
    }
};
// @lc code=end

