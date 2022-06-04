/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string path;
    
    void backtrack(int left, int right) {   // left, right是剩下的左、右括号个数
        // return条件1: 左、右括号都分配结束
        if(left==0 && right==0){
            ans.push_back(path);
            return ;
        }
        // return条件2: 左侧字符串已经不合法, 提前返回
        if(left > right)
            return ;
        // 左括号随意分配
        if(left > 0){
            path += "(";
            backtrack(left-1, right);
            path = path.substr(0, path.size()-1);
        }
        // 右括号当right剩余更多时, 可以分配
        if(right > left){
            path += ")";
            backtrack(left, right-1);
            path = path.substr(0, path.size()-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n, n);
        return ans;
    }
};

// @lc code=end

