/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;

    void backtrack(int n, int k, int sum, int startIndex){   // dfs时startIndex只能递增, 即child比parent大, 从而保证只使用一次
        if(path.size()==k){
            if(sum==n)
                ans.push_back(path);
            return ;
        }
        for(int i=startIndex; i<=9 && 9-i+1 >= k-path.size(); i++){ // 剪枝1: 对宽度进行剪枝, 剩余元素能凑够k个
            sum += i;
            // 剪枝2: 对深度进行剪枝, 放在backtrack前半部分判断也可以
            if(sum <= n){
                path.push_back(i);
                backtrack(n, k, sum, i+1);
                path.pop_back();
            }
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(n, k, 0, 1);
        return ans;
    }
};
// @lc code=end

