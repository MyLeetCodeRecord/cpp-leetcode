/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 *
 * [1092] 最短公共超序列
 */

// @lc code=start
class Solution {
public:
    // 借助LCS构建最短超序列
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(), m=str2.size();
        // 求LCS
        vector<vector<string>> dp(n+1,vector<string>(m+1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+str1[i-1];
                else
                    dp[i][j]=(dp[i-1][j].size()>dp[i][j-1].size()?dp[i-1][j]:dp[i][j-1]);
            }
        }
        string lcs=dp[n][m];
        // 构建目的字符串
        string ans;
        int i=0, j=0;
        // 按照同一个字符串内的字符相对于LCS的顺序构建目的字符串
        for(char ch: lcs){
            // 加入不在LCS中的字符串
            while(i<n && str1[i]!=ch)
                ans += str1[i++];
            while(j<m && str2[j]!=ch)
                ans += str2[j++];
            // 加入LCS中的字符串
            ans += ch;
            i++;
            j++;
        }
        // 加上剩余字符串
        return ans + str1.substr(i) + str2.substr(j);
    }
    /*
    // 正向思路: 用求LCS类似的方式求超序列 - 超时
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int> > dp(str1.size()+1, vector<int>(str2.size()+1, INT_MAX));
        vector<vector<string>> ans(str1.size()+1, vector<string>(str2.size()+1, ""));
        dp[0][0] = 0;
        ans[0][0] = "";
        for(int j=1; j<=str2.size(); j++){
            dp[0][j] = j;
            ans[0][j] += str2.substr(0, j);
        }
        for(int i=1; i<=str1.size(); i++){
            dp[i][0] = i;
            ans[i][0] += str1.substr(0, i);
        }
        for(int i=1; i<=str1.size(); i++){
            for(int j=1; j<=str2.size(); j++){
                if(str1[i-1]==str2[j-1]){
                    ans[i][j] = ans[i-1][j-1] + str1[i-1];
                }
                else{
                    if(ans[i-1][j].size() < ans[i][j-1].size())
                        ans[i][j] = ans[i-1][j] + str1[i-1];
                    else
                        ans[i][j] = ans[i][j-1] + str2[j-1];
                }
            }
        }
        return ans[str1.size()][str2.size()];
    }
    */
};
// @lc code=end

