/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    
    void backtrack(int n, int k, int startIndex){
        if(path.size()==k){
            ans.push_back(path);
            return ;
        }
        // 树的横向
        for(int i=startIndex; i<=n && n-i+1 >= k-path.size(); i++){   // 剪枝: 如果i后面不够凑k个元素
            path.push_back(i);
            backtrack(n, k, i+1);   // 树的纵向(k)
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return ans;
    }
};
// @lc code=end

