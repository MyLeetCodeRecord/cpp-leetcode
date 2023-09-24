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
    void backtrack(int n, int leftL, int leftR){    // leftL, leftR表示剩余要分配的左/右括号数量
        if(leftL==0 && leftR==0){
            ans.push_back(path);
            return ;
        }
        if(leftL > 0){
            path += "(";
            backtrack(n, leftL-1, leftR);
            path = path.substr(0, path.size()-1);
        }
        if(leftR > leftL && leftR > 0){
            path += ")";
            backtrack(n, leftL, leftR-1);
            path = path.substr(0, path.size()-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n, n, n);
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

