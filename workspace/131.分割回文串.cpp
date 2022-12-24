/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string> > ans;
    vector<string> path;
    void backtrack(string s, int cur){
        if(cur == s.size()){
            ans.push_back(path);
            return ;
        }
        for(int i=cur; i<s.size(); i++){
            string sub = s.substr(cur, i-cur+1);
            if(isHuiWen(sub)){
                path.push_back(sub);
                backtrack(s, i+1);
                path.pop_back();
            }
        }
    }
    bool isHuiWen(string s){
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return ans;
    }
};
// @lc code=end

