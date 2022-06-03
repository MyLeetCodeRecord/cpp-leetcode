/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string> > ans;
    vector<int> path;
    void backtrack(int n, vector<bool> used){
        if(path.size() == n){
            vector<string> p;
            for(int i=0; i<path.size(); i++){
                string line = "";
                for(int j=0; j<n; j++){
                    if(j==path[i])
                        line += "Q";
                    else
                        line += ".";
                }
                p.push_back(line);
            }
            ans.push_back(p);
            return ;
        }
        for(int i=0; i<n; i++){
            if(!used[i] && isLegal(i)){
                path.push_back(i);
                used[i] = true;
                backtrack(n, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    bool isLegal(int col){
        int row = path.size();
        for(int i=0; i<path.size(); i++){
            if(col == path[i])
                return false;
            if(abs(row-i) == abs(col-path[i]))
                return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> used(n, false);
        backtrack(n, used);
        return ans;
    }
};
// @lc code=end

