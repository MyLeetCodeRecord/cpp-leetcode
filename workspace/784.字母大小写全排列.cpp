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
    void backtrack(string s, vector<int> &pos, int cur){
        if(cur == pos.size()){
            ans.push_back(path);
            return ;
        }
        path[pos[cur]] = tolower(s[pos[cur]]);
        backtrack(s, pos, cur+1);
        path[pos[cur]] = toupper(s[pos[cur]]);
        backtrack(s, pos, cur+1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<int> pos;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9')
                continue;
            pos.push_back(i);
        }
        path = s;
        backtrack(s, pos, 0);
        return ans;
    }
};
// @lc code=end

