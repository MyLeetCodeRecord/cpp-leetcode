/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    // 二维dp预处理出所有子串是否为回文
    vector<vector<bool>> initSubstr(string s){
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            dp[i][i] = true;
            if(i != n-1)
                dp[i][i+1] = (s[i]==s[i+1]);
        }
        for(int len=3; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                int j = i+len-1;
                if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1];
            }
        }
        return dp;
    }
    // 再来一个dp, 维护「最少分割次数」
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> huiwen_dp = initSubstr(s);
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<n; i++){
            // 如果[0:i]是回文, 不需要分割
            if(huiwen_dp[0][i]==true){
                dp[i] = 0;
            }
            // 否则最多分割i次, 枚举每个使[j:i]是回文的分界点, 找到最小的dp[i]
            else{
                dp[i] = i;
                for(int j=1; j<=i; j++){
                    if(huiwen_dp[j][i]==true)
                        dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

