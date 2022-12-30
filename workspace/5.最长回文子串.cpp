/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int dp[len][len];
        memset(dp, 0, sizeof(dp));
        // 初始化
        // ans记录最大长度, start记录一个可能的起始位置, 从而减少频繁substr()的开销
        int ans = 1;
        int start = 0;
        for(int i=0;i<len;i++){
            dp[i][i] = 1;
            if(i!=len-1 && s[i] == s[i+1]){
                dp[i][i+1] = 1;
                ans = 2;
                start = i;
            }
        }
        // 状态转移
        for(int L=3; L<=len; L++){
            for(int i=0;i<len-L+1;i++){
                if(s[i]==s[i+L-1] && dp[i+1][i+L-2]==1){
                    dp[i][i+L-1] = 1;
                    start = i;
                    ans = L;
                }
            }
        }
        return s.substr(start,ans);
    }
};
// @lc code=end

