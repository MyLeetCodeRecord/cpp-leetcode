/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    vector<vector<bool> > _dp;
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
    vector<vector<string>> ans;
    vector<string> path;
    void backtrack(string s, int cur){
        if(cur == s.size()){
            ans.push_back(path);
            return ;
        }
        for(int i=cur; i<s.size(); i++){
            string sub = s.substr(cur, i-cur+1);
            // 虽然字符串长度不超过16, 但还是二维dp预处理一下比较好
            if(_dp[cur][i]==true){
                path.push_back(sub);
                backtrack(s, i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        _dp = initSubstr(s);
        backtrack(s, 0);
        return ans;
    }
};
// @lc code=end

