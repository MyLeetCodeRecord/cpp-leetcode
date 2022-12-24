/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    // 思路: 可以随便添加")", 只要保证"(">=")"
    vector<string> ans;
    string path;
    // left: path中的"("数量, need: 尚未配对的"("数量or需要的")"最大数量
    void backtrack(int n, int left, int need){
        if(path.size()==n*2){
            if(left==n)
                ans.push_back(path);
            return ;
        }
        string tmp = path;
        if(left <= n){      // 剪枝, 让left不要超过n个
            path += "(";
            backtrack(n, left+1, need+1);
            path = tmp;
        }
        if(need > 0){
            path += ")";
            backtrack(n, left, need-1);
            path = tmp;
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n, 0, 0);
        return ans;
    }
};
// @lc code=end

