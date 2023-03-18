/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string path;
    vector<string> dict;
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
        dict.resize(10);
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        backtrack(digits, 0);
        return ans;
    }
};
// @lc code=end

