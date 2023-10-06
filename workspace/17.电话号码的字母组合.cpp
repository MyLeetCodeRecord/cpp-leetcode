/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> ans;
    string path;
    void backtrack(string digits, int cur){
        if(cur==digits.size()){
            ans.push_back(path);
            return ;
        }
        // 树的横向是当前数字digits[cur]对应的所有字符
        for(int i=0; i<dict[digits[cur]-'0'].size(); i++){
            path += dict[digits[cur]-'0'][i];
            backtrack(digits, cur+1);
            path = path.substr(0, path.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return ans;
        backtrack(digits, 0);
        return ans;
    }
};
// @lc code=end

