/*
 * @lc app=leetcode.cn id=522 lang=cpp
 *
 * [522] 最长特殊序列 II
 */

// @lc code=start
class Solution {
public:
    // 最长公共子序列模板
    bool isLCS(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n]==text1.size();
    }
    bool static cmp(string l, string b){
        return l.size() > b.size();
    }
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        for(int i=0; i<strs.size(); i++){
            // flag=true表示能够strs[i]不是其它字符串的子序列
            bool flag = true;
            for(int j=0; j<strs.size(); j++){
                if(i == j)
                    continue;
                // 如果strs[i]是任意strs[j]的子序列, 将flag标记为false
                if(isLCS(strs[i], strs[j]) == true){
                    flag = false;
                    break;
                }
            }
            if (flag && ans<(int)strs[i].size())    // 转int是必要的...
                ans = strs[i].size();
        }
        return ans;
    }
};
// @lc code=end

