/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, 0));
        int ans = 0;
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
            ans++;
            if(i!=n-1 && s[i]==s[i+1]){
                dp[i][i+1] = 2;
                ans++;
            }
        }
        for(int len=3; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                int j = i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

