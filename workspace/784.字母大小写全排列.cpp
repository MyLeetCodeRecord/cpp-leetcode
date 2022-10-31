/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string path;
    void backtrack(string& s, int cur){
        if(cur==s.size()){
            ans.push_back(path);
            return ;
        }
        if(isdigit(s[cur])){
            path.push_back(s[cur]);
            backtrack(s, cur+1);
            path.pop_back();
        }
        else{
            // 改变大小写
            path.push_back(s[cur]^32);
            backtrack(s, cur+1);
            path.pop_back();
            // 不改变大小写
            path.push_back(s[cur]);
            backtrack(s, cur+1);
            path.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        backtrack(s, 0);
        return ans;
    }
};
// @lc code=end

