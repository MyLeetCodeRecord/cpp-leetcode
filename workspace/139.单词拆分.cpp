/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    // 完全背包
    // - 容量 j 对应 s[:j]
    // - dp[j] 表示能够拼接出s[:j]
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        // 外层遍历容量, 内层遍历字典, 因为可能是"W1-W2-W1"
        for(int j=1; j<=s.size(); j++){
            for(int i=0; i<wordDict.size(); i++){
                if(j>=wordDict[i].size()){
                    int len = wordDict[i].size();
                    if(s.substr(j-len, len)==wordDict[i] && dp[j-len]==true)
                            dp[j] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

