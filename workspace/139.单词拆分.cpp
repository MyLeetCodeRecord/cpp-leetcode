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
        vector<int> dp(s.size()+1, false);
        dp[0] = true;
        for(int j=1; j<=s.size(); j++){
            for(int i=0; i<wordDict.size(); i++){
                if(j>=wordDict[i].size()){
                    string tmp = s.substr(j-wordDict[i].size(), wordDict[i].size());
                    if(tmp == wordDict[i] && dp[j-wordDict[i].size()]){
                        cout<<tmp<<endl;
                        dp[j] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

