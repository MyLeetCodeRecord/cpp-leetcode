/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    // 回溯法
    vector<string> ans;
    string path;
    void backtrack(int n, int cur, int left, int right){
        if(cur == 2*n){
            if(left == right)
                ans.push_back(path);
            return ;
        }
        string tmp = path;
        if(left < n){
            path += "(";
            backtrack(n, cur+1, left+1, right);
            path = tmp;
        }
        if(left>right){
            path += ")";
            backtrack(n, cur+1, left, right+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n, 0, 0, 0);
        return ans;
    }
    /* 
    // DFS
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0)
            return {""};
        if(n==1)
            return {"()"};
        for(int l=0; l<=n-1; l++){
            int r = n - l - 1;
            vector<string> left = generateParenthesis(l);
            vector<string> right = generateParenthesis(r);
            for(string str_L: left){
                str_L = "(" + str_L + ")";
                for(string str_R: right){
                    ans.push_back(str_L+str_R);
                }
            }
        }
        return ans;
    }
    */

};
// @lc code=end

