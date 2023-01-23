/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// @lc code=start
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        // dp[x] 表示 p 中以字符 x 结尾且在 s 中的子串的最长长度
        vector<int> dp(26, 0);
        dp[p[0]-'a'] = 1;
        int len = 1;
        for(int i=1; i<n; i++){
            if((p[i]+26-p[i-1]) % 26 == 1)
                len++;
            else
                len = 1;
            dp[p[i]-'a'] = max(dp[p[i]-'a'], len);
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            ans += dp[i];
        }
        return ans;
    }
};
// @lc code=end

