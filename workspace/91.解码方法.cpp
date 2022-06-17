/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    /* dp[i]: s[0:i]解码结果的总数
        * case 1: s[i] & s[i-1:i]都可以决定字母
        *      dp[i] = dp[i-1] + dp[i-2]
        * case 2: s[i] == 0
        *      dp[i] = dp[i-2]
        * case 3: s[i]可以决定字母
        *      dp[i] = dp[i-1]
        */
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0')
            return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i=0; i<s.size(); i++){
            // 单个字母映射为字母
            dp[i+1] = (s[i]=='0') ? 0 : dp[i];
            // 两个字母映射为字母
            if(i>0 && (s[i-1]=='1'|| (s[i-1]=='2'&&s[i]<='6'))){
                dp[i+1] += dp[i-1];
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

